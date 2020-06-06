#ifndef DRIVERNEW_H
#define DRIVERNEW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class DriverNew;
}

class DriverNew : public QMainWindow
{
    Q_OBJECT


public:
    explicit DriverNew(QWidget *parent = nullptr);
    ~DriverNew();

signals:
    void sendText(QString fnam,QString nam,QString part,QString phon,QString bDay,QString bMon,QString bYear,QString nat,QString pSer,QString pNum,QString issu,QString pDay,QString pMon,QString pYear,QString regi,QString cMod, QString cNum,QString tNum);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DriverNew *ui;
};

#endif // DRIVERNEW_H
