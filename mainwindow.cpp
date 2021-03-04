#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_Clear_clicked()
{
    ui->input_Login->clear();
    ui->input_Password->clear();
}

void MainWindow::on_button_LogIn_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\Programming\\Temp\\test_users.sqlite");
    db.open();

    if  (db.isOpen()) {
        ui->statusbar->showMessage("Подключились к БД");
    } else {
        ui->statusbar->showMessage("Не подключились к БД");
    }
}
