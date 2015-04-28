#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QCheckBox>
#include<QPushButton>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QLabel>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel *lLabel = new QLabel(this);
    lLabel->setText("Activate");

    QCheckBox *lCheckBox = new QCheckBox(this);
    lCheckBox->setChecked(true);
    QPushButton *lPushButton = new QPushButton(this);
    lPushButton->setText("Alert");

    lLineEdit = new QLineEdit(this);
    lLineEdit->setText("Fill in text");

    QHBoxLayout *lHbox1 = new QHBoxLayout(this);
    lHbox1->addWidget(lLabel);
    lHbox1->addWidget(lCheckBox);
    lHbox1->addStretch();

    QHBoxLayout *lHbox2 = new QHBoxLayout(this);
    lHbox2->addWidget(lLineEdit);
    lHbox2->addWidget(lPushButton);
    lHbox2->addStretch();

    QVBoxLayout *lVbox = new QVBoxLayout(this);

    lVbox->addStretch();
    lVbox->addLayout(lHbox1);
    lVbox->addLayout(lHbox2);
    lVbox->addStretch();

    centralWidget()->setLayout(lVbox);

    connect(lCheckBox, SIGNAL(toggled(bool)), lLineEdit, SLOT(setEnabled(bool)));
    connect(lCheckBox, SIGNAL(toggled(bool)), lPushButton, SLOT(setEnabled(bool)));
    connect(lPushButton, SIGNAL(clicked(bool)), this, SLOT(alert(bool)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::alert(bool)
{
    QMessageBox::information(this,"Message Box",MainWindow::lLineEdit->text(),"OK");
}
