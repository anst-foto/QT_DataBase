#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "MessageBox.h"
#include "database.h"
#include "AccountModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_Clear_clicked();

    void on_button_LogIn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
