#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QLCDNumber>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createUi();
    createConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createUi()
{
    lLCD = new QLCDNumber(this);

    lPushButton = new QPushButton(this);
    lPushButton->setText("Equals");

    leftLineEdit = new QLineEdit(this);
    rightLineEdit = new QLineEdit(this);

    labelPlus = new QLabel(this);
    labelPlus->setText("+");

    labelEquals = new QLabel(this);
    labelEquals->setText("=");

    QGridLayout *lGrid = new QGridLayout(this);
    lGrid->addWidget(leftLineEdit,0,0);
    lGrid->addWidget(labelPlus,0,1);
    lGrid->addWidget(rightLineEdit,0,2);
    lGrid->addWidget(labelEquals,0,3);
    lGrid->addWidget(lLCD,0,4);
    lGrid->addWidget(lPushButton,1,4);



    centralWidget()->setLayout(lGrid);
    resize(300,200);
}

void MainWindow::createConnections()
{
    connect(lPushButton,SIGNAL(clicked()), this, SLOT(count()));
}

void MainWindow::count()
{

    bool ok1;
    bool ok2;
    int dec1 = leftLineEdit->text().toInt(&ok1, 10);
    int dec2 = rightLineEdit->text().toInt(&ok2, 10);

    if( ok1 & ok2 )
        lLCD->display(dec1 + dec2);
    else
        QMessageBox::information(this,"Alert", "Fill in numbers","OK");
}
