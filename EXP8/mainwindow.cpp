#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <math.h>
#define SIN(x) sin(s * 3.1415 / 180)
#define COS(x) cos(s * 3.1415 / 180)
QImage img(500,500,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DDALine(0,250,500,250);
    DDALine(250,0,250,500);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int x1,y1,x2,y2,tx,ty;
    float sx,sy,theta;
    x1 = ui->textEdit_2->toPlainText().toInt();
    y1 = ui->textEdit->toPlainText().toInt();
    x2 = ui->textEdit_4->toPlainText().toInt();
    y2 = ui->textEdit_3->toPlainText().toInt();
    tx = ui->textEdit_5->toPlainText().toInt();
    ty = ui->textEdit_6->toPlainText().toInt();
    sx = ui->textEdit_7->toPlainText().toFloat();
    sy = ui->textEdit_8->toPlainText().toFloat();
    theta = ui->textEdit_9->toPlainText().toFloat() / 180  * 3.14;

    sx = std::min(2.0f,sx);
    sy = std::min(2.0f,sy);

    int x[] = {x1,x2,x2,x1};
    int y[] = {y1,y1,y2,y2};

    int xtr[] = {x1+tx,x2+tx,x2+tx,x1+tx};
    int ytr[] = {y1+ty,y1+ty,y2+ty,y2+ty};

    int xsc[] = {int(x1*sx),int(x2*sx),int(x2*sx),int(x1*sx)};
    int ysc[] = {int(y1*sy),int(y1*sy),int(y2*sy),int(y2*sy)};

    DrawRect(x,y);
    DrawRect(xtr,ytr);
    DrawRect(xsc,ysc);
    Rotator(x,y,0,0,theta,4);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::Rotator(int x[], int y[], int x_pivot, int y_pivot,float theta, int ln){
    int i = 0;
    int x_out[ln],y_out[ln];
    while (i<ln){
        int tmpx = x[i] - x_pivot;
        int tmpy = y[i] - y_pivot;
        x_out[i] = int(x_pivot + (tmpx * cos(theta) - tmpy*sin(theta)));
        y_out[i] = int(y_pivot + (tmpx * sin(theta) + tmpy*cos(theta)));
        i++;
    }
    DrawRect(x_out,y_out);
}
void MainWindow::DrawRect(int x[4],int y[4]){
    DDALine(x[0]+250,(-1*y[0])+250,x[1]+250,(-1*y[1])+250);
    DDALine(x[1]+250,(-1*y[1])+250,x[2]+250,(-1*y[2])+250);
    DDALine(x[2]+250,(-1*y[2])+250,x[3]+250,(-1*y[3])+250);
    DDALine(x[3]+250,(-1*y[3])+250,x[0]+250,(-1*y[0])+250);
}

void MainWindow::DDALine(int srcX,int srcY,int destX,int destY){
    float dx,dy,len,xinc,yinc;
    dx = destX-srcX;
    dy = destY-srcY;
    len = (abs(dx)>abs(dy))? abs(dx):abs(dy);
    xinc = dx/len;
    yinc = dy/len;
    int i=0;
    while(i<len){
        srcX+=xinc;
        srcY+=yinc;
        img.setPixel(srcX,srcY,qRgb(255,255,255));
        i++;
    }

}
