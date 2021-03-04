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
    DataBase db("C:\\Programming\\Temp\\test_users.sqlite");

    db.Connect();

    QString login = ui->input_Login->text();
    QString password = ui->input_Password->text();

    AccountModel account = db.CheckAccount(login, password);

    if (account.id != 0) {
        MessageBoxInfo("Вы успешно авторизовались");

        QString msg = account.login + " " + account.password;
        ui->statusbar->showMessage(msg);
    } else {
        MessageBoxWarning("Вам не удалось авторизоваться");
    }

    db.Disconnect();
}
