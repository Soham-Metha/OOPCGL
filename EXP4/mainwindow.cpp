#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QColorDialog>
#include <QImage>
#include <QPixmap>

QImage img(500, 500, QImage::Format_RGB888);
QColor color = Qt::white;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    start = true;
    count = 0;
    img.fill(Qt::white);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    if (count > 2) {
        // Fill polygon after the user is done defining vertices
        fillPolygon();
        start = true;
        count = 0; // Reset vertex count for next polygon
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (!start) return;
    int p = event->pos().x();
    int q = event->pos().y();
    a[count] = p;
    b[count] = q;
    if (event->button() == Qt::RightButton) {
        if (count > 2) {
            DDALine(a[count - 1], b[count - 1], a[0], b[0]);
            start = false;
        }
    } else {
        if (count > 0) {
            DDALine(a[count], b[count], a[count - 1], b[count - 1]);
        }
        count++;
    }
}

void MainWindow::DDALine(int srcX, int srcY, int destX, int destY) {
    float dx, dy, len, xinc, yinc, x, y;
    dx = destX - srcX;
    dy = destY - srcY;
    len = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    xinc = dx / len;
    yinc = dy / len;
    x = srcX + 0.5;
    y = srcY + 0.5;
    int i = 0;
    while (i <= len) {
        img.setPixel(int(x), int(y), qRgb(color.red(), color.green(), color.blue()));
        x += xinc;
        y += yinc;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::fillPolygon() {
    // Scanline fill algorithm
    int minY = 500, maxY = 0;
    for (int i = 0; i < count; i++) {
        if (b[i] < minY) minY = b[i];
        if (b[i] > maxY) maxY = b[i];
    }

    for (int y = minY; y <= maxY; y++) {
        QVector<int> xIntersections;
        for (int i = 0; i < count; i++) {
            int j = (i + 1) % count;
            if ((b[i] <= y && b[j] > y) || (b[i] > y && b[j] <= y)) {
                int x = a[i] + (y - b[i]) * (a[j] - a[i]) / (b[j] - b[i]);
                xIntersections.append(x);
            }
        }
        std::sort(xIntersections.begin(), xIntersections.end());
        for (int i = 0; i < xIntersections.size(); i += 2) {
            for (int x = xIntersections[i]; x < xIntersections[i + 1]; x++) {
                img.setPixel(x, y, qRgb(color.red(), color.green(), color.blue()));
            }
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked() {
    color = QColorDialog::getColor();
}
