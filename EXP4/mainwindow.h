#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void DDALine(int,int,int,int);
    void mousePressEvent(QMouseEvent *e);
    void on_pushButton_2_clicked();

private:
    void fillPolygon(); // New method to fill the polygon

    Ui::MainWindow *ui;
    int count;
    bool start;
    int a[100], b[100]; // Arrays to store vertex coordinates
    int xi[20]; // Array for x-intersections in the scanline fill algorithm
    float slope[20]; // Array to store slopes for line segments
    QColor color; // Color for filling the polygon

    // Variables used in the scanline algorithm
    int temp, k, m, n;
    float dx, dy;
};

#endif // MAINWINDOW_H
