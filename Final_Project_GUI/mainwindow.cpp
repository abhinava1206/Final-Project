#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <string>
#include "RLE.h"
#include "LZW.h"
#include <fstream>

std::string process(std::string s)
{
    std::string::size_type pos = s.find('.');
    if (pos != std::string::npos)
    {
        return s.substr(0, pos);
    }
    else
    {
        return s;
    }
}

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

void MainWindow::on_pushButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Select File to compress", "Desktop");
    QMessageBox::information(this, "..", "compressing...");
    std::string file_name_1 = file_name.toUtf8().constData();
    std::string output_file_name = process(file_name_1) + ".rle";
    std::ifstream in; std::ofstream out;
    in.open(file_name_1);
    out.open(output_file_name);
    rle a;
    a.compress(in, out);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString extension = ui->lineEdit->text();
    QString file_name_ = QFileDialog::getOpenFileName(this,"Select File to decompress", "Desktop");
    QMessageBox::information(this, "..", "decompressing...");
    std::string file_name_2 = file_name_.toUtf8().constData();
    std::string file_extension = extension.toUtf8().constData();
    std::ifstream in1; std::ofstream out1;
    std::string output_file_name_2 = process(file_name_2) + "2" + file_extension;
    in1.open(file_name_2);
    out1.open(output_file_name_2);
    rle b;
    b.decompress(in1, out1);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Select File to compress", "Desktop");
    QMessageBox::information(this, "..", "compressing...");
    std::string file_name_1 = file_name.toUtf8().constData();
    std::string output_file_name = process(file_name_1) + ".lzw";
    std::ifstream in; std::ofstream out;
    in.open(file_name_1);
    out.open(output_file_name, std::ios::binary);
    lzw c;
    c.compress(in, out);
}



void MainWindow::on_pushButton_4_clicked()
{
    QString extension = ui->lineEdit_2->text();
    QString file_name_ = QFileDialog::getOpenFileName(this,"Select File to decompress", "Desktop");
    QMessageBox::information(this, "..", "decompressing...");
    std::string file_name_2 = file_name_.toUtf8().constData();
    std::string file_extension = extension.toUtf8().constData();
    std::ifstream in1; std::ofstream out1;
    std::string output_file_name_2 = process(file_name_2) + "3" + file_extension;
    in1.open(file_name_2, std::ios::binary);
    out1.open(output_file_name_2);
    lzw d;
    d.decompress(in1, out1);
}
