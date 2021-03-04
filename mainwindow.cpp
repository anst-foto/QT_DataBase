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

    if  (db.open()) {
        ui->statusbar->showMessage("Подключились к БД");

        QString login = ui->input_Login->text();
        QString password = ui->input_Password->text();

        QString sql = "SELECT * FROM table_account WHERE login = '" + login + "' AND password = '" + password + "'";
        QSqlQuery query;
        query.exec(sql);

        if (query.next()) {
            MessageBoxInfo("Вы успешно авторизовались");
        } else {
            MessageBoxWarning("Неправильно указан логин или пароль");
        }

    } else {
        ui->statusbar->showMessage("Не подключились к БД");
    }
    db.close();
}
