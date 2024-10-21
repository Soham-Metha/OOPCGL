#include "mainwindow.h"
#include "./ui_mainwindow.h"
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
    img.fill(Qt::white);
    ui->label->setPixmap(QPixmap::fromImage(img));
    while(numVertices>0){
        VerticesX[numVertices] = 0;
        VerticesY[numVertices] = 0;
        numVertices--;
    }
    int n,x1,y1;
    int x0=50,y0=150,x,y,h=10,r=2,d=3,l=4,u=1;
    x = x0;
    y = y0;
    n = ui->textEdit->toPlainText().toInt();
    moveto(x,y);
    hilbert(r,d,l,u,n,h,x,y);

    for (int i = 0; i < numVertices-1; ++i) {
        dda(VerticesX[i],VerticesY[i],VerticesX[i+1],VerticesY[i+1]);
    }
}
void MainWindow::moveto(int x,int y){
    VerticesX[numVertices] = x;
    VerticesY[numVertices] = y;
    numVertices++;
}
void MainWindow::move(int j,int h,int &x,int &y)
{
    if(j==1)
        y-=h;
    else if(j==2)
        x+=h;
    else if(j==3)
        y+=h;
    else if(j==4)
        x-=h;
    moveto(x,y);
}

void MainWindow::hilbert(int r,int d,int l,int u,int i,int h,int &x,int &y)
{
    if(i>0)
    {
        i--;
        hilbert(d,r,u,l,i,h,x,y);
        move(r,h,x,y);
        hilbert(r,d,l,u,i,h,x,y);
        move(d,h,x,y);
        hilbert(r,d,l,u,i,h,x,y);
        move(l,h,x,y);
        hilbert(u,l,d,r,i,h,x,y);
    }
}
void MainWindow::dda(float x1, float y1, float x2, float y2)
{
    float xinc,yinc,dx,dy,length,x,y;

    dx = x2 - x1;
    dy = y2 - y1;

    if(abs(dx) > abs(dy))
    {
        length = abs(dx);
    }
    else
    {
        length = abs(dy);
    }

    xinc = dx/length;
    yinc = dy/length;

    int i = 1;

    x = x1;
    y = y1;

    while(i <= length)
    {
        img.setPixel(x,y,qRgb(255,0,0));
        x += xinc;
        y += yinc;
        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}
