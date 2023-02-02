#include "mydialog.h"
#include "ui_mydialog.h"
using namespace std;
MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_pushButton_clicked()
{
    QString filter = "All Files (*.*) ;; XML Files (*.xml)";
    QString filename = QFileDialog :: getOpenFileName(this,"Open File","C://",filter);
    QFile file(filename);
    currentfile =filename;
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this,"Warning" , "Cannot Open File : " + file.errorString());
        }
    QString file1 = QFileInfo(currentfile).absoluteFilePath();
    QString dir1 = QFileInfo(currentfile).absolutePath();
    string input =file1.toStdString();

    QDir::setCurrent(dir1);
    string filenameIn =input;
    string filenameOut ="output.dot";

    vectorextract(filenameIn,filenameOut);
    system("dot -Tpng -O output.dot");

    QPixmap p("output.dot.png");
    ui->label->setPixmap(p);
}

