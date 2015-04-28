#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLineEdit>
#include <QMainWindow>

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
    QLineEdit *lLineEdit;
    Ui::MainWindow *ui;


private slots:
    void alert(bool);


};

#endif // MAINWINDOW_H
