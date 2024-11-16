#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graphview.h>

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
    ~MainWindow();
    GraphView* graph = nullptr;

private slots:
    void on_addVertexButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
