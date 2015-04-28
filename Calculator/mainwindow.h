#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createUi();
    void createConnections();

private:
    Ui::MainWindow *ui;
    QLCDNumber *lLCD;
    QPushButton *lPushButton;
    QLineEdit *leftLineEdit;
    QLineEdit *rightLineEdit;
    QLabel *labelPlus;
    QLabel *labelEquals;

private slots:
    void count();

};

#endif // MAINWINDOW_H
