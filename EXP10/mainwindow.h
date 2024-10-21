#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    float VerticesX[1000];
    float VerticesY[1000];
    int numVertices = 0;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void dda(float x1,float y1,float x2,float y2);
    void moveto(int x,int y);
    void move(int j,int h,int &x,int &y);

    void hilbert(int r,int d,int l,int u,int i,int h,int &x,int &y);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
