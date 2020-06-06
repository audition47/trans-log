#include "daba.h"
#include <QMessageBox>
#include <QFile>



QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
daba::daba()
{
            db.setDatabaseName("MyDB.db");
            db.open();


}

void daba::Insert(QString fnam,QString nam,QString part,QString phon,QString bDay,QString bMon,QString bYear,QString nat,QString pSer,QString pNum,QString issu,QString pDay,QString pMon,QString pYear,QString regi,QString cMod, QString cNum,QString tNum)
{
    QSqlQuery query;
    if(db.tables().empty()){
        query.exec("CREATE TABLE drivers (id INTEGER PRIMARY KEY AUTOINCREMENT,fnam TEXT, nam TEXT, part TEXT,phon TEXT,bDay TEXT,bMon TEXT,bYear TEXT,nat TEXT,pSer TEXT,pNum TEXT,issu TEXT,pDay TEXT,pMon TEXT,pYear TEXT,regi TEXT,cMod TEXT, cNum TEXT,tNum TEXT)");
    }


    query.prepare("INSERT INTO drivers (fnam, nam, part,phon,bDay,bMon,bYear,nat,pSer,pNum,issu,pDay,pMon,pYear,regi,cMod, cNum,tNum) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(nam);
    query.addBindValue(fnam);
    query.addBindValue(part);
    query.addBindValue(phon);
    query.addBindValue(bDay);
    query.addBindValue(bMon);
    query.addBindValue(bYear);
    query.addBindValue(nat);
    query.addBindValue(pSer);
    query.addBindValue(pNum);
    query.addBindValue(issu);
    query.addBindValue(pDay);
    query.addBindValue(pMon);
    query.addBindValue(pYear);
    query.addBindValue(regi);
    query.addBindValue(cMod);
    query.addBindValue(cNum);
    query.addBindValue(tNum);




    if (!query.exec()) {
        QMessageBox::warning(0,"Error", query.lastError().text());

    }

}


