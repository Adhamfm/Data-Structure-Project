#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "minify.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<QFileDialog>
#include <QMessageBox>
#include "XMLtoJSON.h"
#include "Compress.h"
#include "decompress.h"
#include "format.h"
#include "mydialog.h"
#include "ui_mydialog.h"
#include "validatexml.h"
using namespace std;

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


void MainWindow::on_pushButton_6_clicked()         //Minify button
{
    QString file = QFileInfo(currentfile).absoluteFilePath();
    string input =file.toStdString();
    minify(input,"Demo.xml");
    QFile x("Demo.xml");
           if(!x.open(QIODevice::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,"Warning" , "Cannot Open File : " + x.errorString());
           }
           QTextStream inx(&x);
           QString textx = inx.readAll();
           ui->plainTextEdit->setPlainText(textx);
           x.close();
}


void MainWindow::on_pushButton_clicked()           //Compress button
{
    QString s1 = QFileDialog::getOpenFileName(this, "Open a file", "directoryToOpen","All Files (*)");
    string cs =s1.toStdString();
    compress(cs);
}


void MainWindow::on_pushButton_2_clicked()          //Decompress button
{
    QString s2 = QFileDialog::getOpenFileName(this, "Open a file", "directoryToOpen","All Files (*)");
    string ds =s2.toStdString();
    decompress(ds);
}


void MainWindow::on_pushButton_3_clicked()          //Formatting button
{
    QString file = QFileInfo(currentfile).absoluteFilePath();
    string input =file.toStdString();
    format(input,"Demo.xml");
    QFile x("Demo.xml");
           if(!x.open(QIODevice::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,"Warning" , "Cannot Open File : " + x.errorString());
           }
           QTextStream inx(&x);
           QString textx = inx.readAll();

           ui->plainTextEdit->setPlainText(textx);
           x.close();


}


void MainWindow::on_pushButton_4_clicked()          //Convert to JSON
{

    QString file = QFileInfo(currentfile).absoluteFilePath();
    string input =file.toStdString();
    XML2JSON(input,"Demo.json","Dummy.txt");
    QFile x("Demo.json");
           if(!x.open(QIODevice::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,"Warning" , "Cannot Open File : " + x.errorString());
           }
           QTextStream inx(&x);
           QString textx = inx.readAll();
           ui->plainTextEdit->setPlainText(textx);
           x.close();
}


void MainWindow::on_pushButton_5_clicked()          //Graph Visualize
{
    MyDialog* m =new MyDialog(this);


    m->show();
}




void MainWindow::on_pushButton_7_clicked()          //Opening file
{
    QString filter = "All Files (*.*) ;; XML Files (*.xml)";
    QString filename = QFileDialog :: getOpenFileName(this,"Open File","C://",filter);
    QFile file(filename);
    currentfile =filename;
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this,"Warning" , "Cannot Open File : " + file.errorString());
        }
    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);

    file.close();
}





void MainWindow::on_pushButton_8_clicked()     //Validate button
{
    QString s1 = QFileDialog::getOpenFileName(this, "Open a file", "directoryToOpen","All Files (*)");
    string input = s1.toStdString();
    validatexml* k = new validatexml();
    k -> intergration(input, "Demo.txt");
    QFile x(s1);
           if(!x.open(QIODevice::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,"Warning" , "Cannot Open File : " + x.errorString());
           }
           QTextStream inx(&x);
           QString textx = inx.readAll();
           ui->plainTextEdit->setPlainText(textx);
           x.close();
           delete k;

}

