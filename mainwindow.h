#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include "drivernew.h"
#include "daba.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:


private slots:
    void on_on_sort_triggered();

    void on_off_sort_triggered();

    void on_save_triggered();

    void on_new_2_triggered();

    void on_actionBase_triggered();



    void on_next_triggered();

    void on_previous_triggered();



public slots:
void add(QString fnam,QString nam,QString part,QString phon,QString bDay,QString bMon,QString bYear,QString nat,QString pSer,QString pNum,QString issu,QString pDay,QString pMon,QString pYear,QString regi,QString cMod, QString cNum,QString tNum);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
