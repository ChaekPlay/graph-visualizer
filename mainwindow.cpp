#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <graphscene.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Graph graph({Vertex(1), Vertex(2), Vertex(3)},{Edge(1, 2, 5), Edge(2,3,1)});
    GraphScene* scene = new GraphScene();
    scene->setGraph(graph);
    scene->drawGraph();
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
