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

