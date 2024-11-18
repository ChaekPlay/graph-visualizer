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

    // TODO: проверка на тип
    Vertex* vertex1 = dynamic_cast<Vertex*>(graph->getScene()->selectedItems()[0]);
    Vertex* vertex2 = dynamic_cast<Vertex*>(graph->getScene()->selectedItems()[1]);
    // WARNING: возможно вылетает, надо тестить
    if(graph->edgeExists(vertex1, vertex2))
    {
        msg.setText("Ребро между вершинами уже существует");
        msg.exec();
        return;
    }
    msg.setText("Введите длину ребра");
    QSpinBox* lengthSpinBox = new QSpinBox();
    lengthSpinBox->setRange(0, 1000);
    msg.layout()->addWidget(lengthSpinBox);
    msg.exec();
    graph->addEdge(vertex1, vertex2, lengthSpinBox->value());
}


void MainWindow::on_removeEdgeButton_clicked()
{
    QMessageBox msg;
    if(graph->getScene()->selectedItems().length() != 2) {
        msg.setText("Необходимо выбрать 2 вершины на графе с помощью клавиши Ctrl");
        msg.exec();
        return;
    }
    // TODO: проверка на тип
    Vertex* vertex1 = dynamic_cast<Vertex*>(graph->getScene()->selectedItems()[0]);
    Vertex* vertex2 = dynamic_cast<Vertex*>(graph->getScene()->selectedItems()[1]);
    Edge* edge = graph->findEdge(vertex1, vertex2);
    if(edge)
        graph->deleteEdge(edge);
}


void MainWindow::on_removeVertexButton_clicked()
{
    QMessageBox msg;
    if(graph->getScene()->selectedItems().length() != 1) {
        msg.setText("Необходимо выбрать только 1 вершину");
        msg.exec();
        return;
    }
    Vertex* vertex = dynamic_cast<Vertex*>(graph->getScene()->selectedItems()[0]);
    graph->deleteVertex(vertex);
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
    // TODO: проверка на тип
    Vertex* vertex1 = dynamic_cast<Vertex*>(graph->getScene()->selectedItems()[0]);
    Vertex* vertex2 = dynamic_cast<Vertex*>(graph->getScene()->selectedItems()[1]);
    graph->dijkstraAlgorithm(vertex1, vertex2);
}

