#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *lButton = new QPushButton(this);
    lButton->setText("Close");
    lButton->setGeometry(lButton->x(),lButton->y(),50, 100);

    QHBoxLayout *Hbox = new QHBoxLayout(this);
    Hbox->addStretch();
    Hbox->addWidget(lButton);
    Hbox->addStretch();
    centralWidget()->setLayout(Hbox);
    resize(200,200);

    connect(lButton, SIGNAL(clicked()), this, SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
