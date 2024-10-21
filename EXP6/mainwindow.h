#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void dda(float x1,float y1,float x2,float y2, int flag);
    void mousePressEvent(QMouseEvent *event);
    void boundary(int flag);
    void clear_boundary();
    int compute_code(double x,double y);
    void cohenSutherlandClip(double x1,double y1,double x2,double y2);

private:
    Ui::MainWindow *ui;
    float VerticesX[100];
    float VerticesY[100];
    int numVertices = 0;

    const int INSIDE = 0;
    const int LEFT = 1;
    const int RIGHT = 2;
    const int BOTTOM = 4;
    const int TOP = 8;

    const int x_min = 100;
    const int y_min = 100;
    const int x_max = 200;
    const int y_max = 200;
};
#endif // MAINWINDOW_H
