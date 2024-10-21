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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void DDALine(int,int,int,int);
    void drawCirc(int,int,int,int);
    void bresenhamCirc(int,int,int);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
