#include "mainwindow.h"
#include "ui_mainwindow.h"

QImage img(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //int x1,x2,y1,y2;
    //x1=ui->textEdit->toPlainText().toInt();
    //y1=ui->textEdit_2->toPlainText().toInt();
    //x2=ui->textEdit_3->toPlainText().toInt();
    //y2=ui->textEdit_4->toPlainText().toInt();
    //DDA(x1,y1,x2,y2);
    DDALine(100,100,100,400);
    DDALine(100,100,400,100);
    DDALine(100,400,400,400);
    DDALine(400,100,400,400);

    DDALine(250,100,400,250);
    DDALine(100,250,250,100);
    DDALine(400,250,250,400);
    DDALine(100,250,250,400);
    bresenhamCirc(250,250,105);

    ui->label->setPixmap(QPixmap::fromImage(img));
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
void MainWindow::drawCirc(int xc,int yc,int x,int y){
    img.setPixel(xc+x,yc+y,qRgb(255,255,255));
    img.setPixel(xc-x,yc+y,qRgb(255,255,255));
    img.setPixel(xc+x,yc-y,qRgb(255,255,255));
    img.setPixel(xc-x,yc-y,qRgb(255,255,255));
    img.setPixel(xc+y,yc+x,qRgb(255,255,255));
    img.setPixel(xc-y,yc+x,qRgb(255,255,255));
    img.setPixel(xc+y,yc-x,qRgb(255,255,255));
    img.setPixel(xc-y,yc-x,qRgb(255,255,255));
}

void MainWindow::bresenhamCirc(int xc,int yc,int r){
    int x = 0,y = r;
    int d = 3 - 2*r;
    drawCirc(xc,yc,x,y);
    while (y>=x){
        if(d>0){
            y--;
            d += 4*(x-y) +10;
        }
        else
            d += 4*x +6;
        x++;
        drawCirc(xc,yc,x,y);
    }
}
