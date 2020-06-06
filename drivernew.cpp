#include "drivernew.h"
#include "ui_drivernew.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

DriverNew::DriverNew(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DriverNew)
{
    ui->setupUi(this);
setAttribute(Qt::WA_DeleteOnClose);
}

DriverNew::~DriverNew()
{
    delete ui;
}

void DriverNew::on_pushButton_clicked()
{
   emit sendText(ui->fname->text(),ui->name->text(),ui->patronymic->text(),ui->phonenumber->text(),ui->bDay->text(),ui->bMon->text(),ui->bYear->text(),ui->national->text(),ui->passSerial->text(),ui->passNumber->text(),ui->issue->toPlainText(),ui->pDay->text(),ui->pMon->text(),ui->pYear->text(),ui->registr->toPlainText(),ui->carModel->text(),ui->carNumber->text(),ui->trailerNumber->text());
DriverNew::close();
}
