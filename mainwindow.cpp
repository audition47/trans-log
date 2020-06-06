#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTableWidgetItem>
#include <QKeyEvent>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextCodec>
#include "xlsxdocument.h"
#include "xlsxdocument_p.h"
#include <QtCore>
#include <QDebug>
#include "xlsxformat.h"
#include "xlsxconditionalformatting.h"
#include "xlsxcellrange.h"



QTXLSX_USE_NAMESPACE


using namespace QXlsx;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_on_sort_triggered()
{
    ui->tableWidget->setSortingEnabled(true);
}

void MainWindow::on_off_sort_triggered()
{
    ui->tableWidget->setSortingEnabled(false);
}

void writeHorizontalAlignCell(Document &xlsx, int row, int column, const QString &text, Format::HorizontalAlignment AlignHJustify)
{
   Format format;
   format.setHorizontalAlignment(AlignHJustify);
   format.setBorderStyle(Format::BorderThin);
   xlsx.write(row,column, text, format);
}


void MainWindow::on_save_triggered()
{


 QString fr= QFileDialog::getSaveFileName(this,tr("Save"),"c:/",tr("(*.xlsx)"));


QXlsx::Document xlsx("Test.xlsx");

for (int i=0;i<(ui->tableView->model()->rowCount());i++){

           for (int j=1;j<(ui->tableView->model()->columnCount());j++){
               QString check = ui->tableView->model()->data(ui->tableView->model()->index(i,j)).toString();
                    xlsx.setColumnWidth(j,20);
                    writeHorizontalAlignCell(xlsx, i+10,j, check, Format::AlignHJustify);


           }
}
xlsx.saveAs(fr);
}


void MainWindow::on_new_2_triggered()
{
    DriverNew *dr = new DriverNew();
    dr->show();
    connect(dr,SIGNAL(sendText(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString)), this, SLOT(add(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString)));



}

void MainWindow::add(QString fnam,QString nam,QString part,QString phon,QString bDay,QString bMon,QString bYear,QString nat,QString pSer,QString pNum,QString issu,QString pDay,QString pMon,QString pYear,QString regi,QString cMod, QString cNum,QString tNum)
{

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setColumnCount(14);
    QTableWidgetItem *ifnam = new QTableWidgetItem;
                ifnam->setText(fnam);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, ifnam);
    QTableWidgetItem *inam = new QTableWidgetItem;
                inam->setText(nam);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, inam);
    QTableWidgetItem *ipar = new QTableWidgetItem;
                ipar->setText(part);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, ipar);
    QTableWidgetItem *ipho = new QTableWidgetItem;
                ipho->setText(phon);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, ipho);
    QTableWidgetItem *ibir = new QTableWidgetItem;
                ibir->setText(bDay+"."+bMon+"."+bYear);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, ibir);
    QTableWidgetItem *inat = new QTableWidgetItem;
                inat->setText(nat);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 5, inat);
    QTableWidgetItem *ipser = new QTableWidgetItem;
                ipser->setText(pSer);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 6, ipser);
    QTableWidgetItem *ipnum = new QTableWidgetItem;
                ipnum->setText(pNum);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 7, ipnum);
    QTableWidgetItem *iiss = new QTableWidgetItem;
                iiss->setText(issu);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 8, iiss);
    QTableWidgetItem *ipday = new QTableWidgetItem;
                ipday->setText(pDay+"."+pMon+"."+pYear);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 9, ipday);
    QTableWidgetItem *ireg = new QTableWidgetItem;
                ireg->setText(regi);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 10, ireg);
    QTableWidgetItem *icmod = new QTableWidgetItem;
                icmod->setText(cMod);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 11, icmod);
    QTableWidgetItem *icnum = new QTableWidgetItem;
                icnum->setText(cNum);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 12, icnum);
    QTableWidgetItem *itnum = new QTableWidgetItem;
                itnum->setText(tNum);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 13, itnum);
                ui->tableWidget->resizeRowsToContents();
                ui->tableWidget->setEditTriggers(0);

daba myD;
                myD.Insert(fnam,nam,part,phon,bDay,bMon,bYear,nat,pSer,pNum,issu,pDay,pMon,pYear,regi,cMod,cNum,tNum);
                QSqlTableModel *model = new QSqlTableModel();
                model->setTable("drivers");
                model->select();
                model->setEditStrategy(QSqlTableModel::OnFieldChange);

                ui->tableView->setModel(model);
                ui->tableView->sortByColumn(2);
                ui->tableView->show();

}

void MainWindow::on_actionBase_triggered()
{
daba myD;

QSqlTableModel *model = new QSqlTableModel();
model->setTable("drivers");
model->select();
model->setEditStrategy(QSqlTableModel::OnFieldChange);

ui->tableView->setModel(model);
ui->tableView->show();
}


void MainWindow::on_next_triggered()
{
    ui->stackedWidget->setCurrentIndex((ui->stackedWidget->currentIndex())+1);
}

void MainWindow::on_previous_triggered()
{
    ui->stackedWidget->setCurrentIndex((ui->stackedWidget->currentIndex())-1);
}




