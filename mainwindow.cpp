#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Insert_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_Copy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_Cut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_NewFile_triggered()
{
    ui->textEdit->clear();

}


void MainWindow::on_OpenFile_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Открыть файл");
    QFile file(filename);
    currFile = filename;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Ошибка", "Файл не открыт");
        return;
    }
    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_SaveFile_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Сохранить как");
    QFile file(filename);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"Ошибка", "Файл не сохранён");
        return;
    }
    currFile = filename;
    setWindowTitle(filename);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

