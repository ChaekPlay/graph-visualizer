#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <graphview.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graph = new GraphView(this);
    graph->setDragMode(QGraphicsView::RubberBandDrag);
    graph->setOptimizationFlags(QGraphicsView::DontSavePainterState);
    graph->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    graph->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    graph->setInteractive(true);
    graph->setRenderHint(QPainter::Antialiasing);
    ui->visualizationWidget->layout()->addWidget(graph);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addVertexButton_clicked()
{
    graph->addVertex();
}


void MainWindow::on_addEdgeButton_clicked()
{
    QMessageBox msg;
    if(graph->getScene()->selectedItems().length() != 2) {
        msg.setText("Необходимо выбрать 2 вершины на графе с помощью клавиши Ctrl или, выделив одну вершину, сделать двойной щелчок по второй вершине");
        msg.exec();
        return;
    }
    Vertex* vertex1 = dynamic_cast<Vertex*>(graph->getScene()->selectedItems()[0]);
    Vertex* vertex2 = dynamic_cast<Vertex*>(graph->getScene()->selectedItems()[1]);
    if(!vertex1 || !vertex2) {
        msg.setText("Необходимо выбрать 2 вершины на графе с помощью клавиши Ctrl");
        msg.exec();
        return;
    }
    if(graph->edgeExists(vertex1, vertex2))
    {
        msg.setText("Ребро между вершинами уже существует");
        msg.exec();
        return;
    }
    SetNumberDialog dialog;
    dialog.setText("Введите длину ребра:");
    int code = dialog.exec(); //=("Введите длину ребра");
    if (code == QDialog::Accepted) {
        int value = dialog.getValue();
        graph->addEdge(vertex1, vertex2, value);
    }
}


void MainWindow::on_removeEdgeButton_clicked()
{
    QMessageBox msg;
    if(graph->getScene()->selectedItems().length() != 2) {
        msg.setText("Необходимо выбрать 2 вершины на графе с помощью клавиши Ctrl");
        msg.exec();
        return;
    }
    Vertex* vertex1 = dynamic_cast<Vertex*>(graph->getScene()->selectedItems()[0]);
    Vertex* vertex2 = dynamic_cast<Vertex*>(graph->getScene()->selectedItems()[1]);
    if(!vertex1 || !vertex2) {
        msg.setText("Необходимо выбрать 2 вершины на графе с помощью клавиши Ctrl");
        msg.exec();
        return;
    }
    if(!graph->edgeExists(vertex1, vertex2))
    {
        msg.setText("Ребра между вершинами не существует");
        msg.exec();
        return;
    }
    Edge* edge = graph->findEdge(vertex1, vertex2);
    if(edge)
        graph->deleteEdge(edge);
}


void MainWindow::on_removeVertexButton_clicked()
{
    graph->deleteSelectedItems();
}


void MainWindow::on_resetGraphButton_clicked()
{
    graph->clear();
}


void MainWindow::on_startPathFindingButton_clicked()
{
    QMessageBox msg;
    if(graph->getScene()->selectedItems().length() != 2) {
        msg.setText("Необходимо выбрать 2 вершины на графе с помощью клавиши Ctrl");
        msg.exec();
        return;
    }
    Vertex* vertex1 = dynamic_cast<Vertex*>(graph->getScene()->selectedItems()[0]);
    Vertex* vertex2 = dynamic_cast<Vertex*>(graph->getScene()->selectedItems()[1]);
    if(!vertex1 || !vertex2) {
        msg.setText("Необходимо выбрать 2 вершины на графе с помощью клавиши Ctrl");
        msg.exec();
        return;
    }
    graph->dijkstraAlgorithm(vertex1, vertex2);
}


void MainWindow::on_editEdgeLength_clicked()
{
    QMessageBox msg;
    if(graph->getScene()->selectedItems().length() != 2) {
        msg.setText("Необходимо выбрать 2 вершины на графе с помощью клавиши Ctrl");
        msg.exec();
        return;
    }
    Vertex* vertex1 = dynamic_cast<Vertex*>(graph->getScene()->selectedItems()[0]);
    Vertex* vertex2 = dynamic_cast<Vertex*>(graph->getScene()->selectedItems()[1]);
    if(!vertex1 || !vertex2) {
        msg.setText("Необходимо выбрать 2 вершины на графе с помощью клавиши Ctrl");
        msg.exec();
        return;
    }
    if(!graph->edgeExists(vertex1, vertex2))
    {
        msg.setText("Ребра между вершинами не существует");
        msg.exec();
        return;
    }
    Edge* edge = graph->findEdge(vertex1, vertex2);
    SetNumberDialog dialog;
    dialog.setText("Введите длину ребра:");
    dialog.setValue(edge->getLength());
    int code = dialog.exec();
    if (code == QDialog::Accepted) {
        int value = dialog.getValue();
        edge->setLength(value);
    }
}

