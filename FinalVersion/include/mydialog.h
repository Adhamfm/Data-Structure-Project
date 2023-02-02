#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>
//#include<QPrinter>
//#include<QPrintDialog>
#include"Graph.h"

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = nullptr);
    ~MyDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyDialog *ui;
    QString currentfile ="";
};

#endif // MYDIALOG_H
