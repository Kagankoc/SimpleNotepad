#include "simplenotepad.h"
#include "ui_simplenotepad.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFont>
#include <QFontDialog>
#include <QColorDialog>

SimpleNotepad::SimpleNotepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimpleNotepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

}

SimpleNotepad::~SimpleNotepad()
{
    delete ui;
}

void SimpleNotepad::on_actionNew_File_triggered()
{

        file_path="";
        ui->textEdit->setText("");

}

void SimpleNotepad::on_actionOpen_File_triggered()
{
        QString fileName=QFileDialog::getOpenFileName(this,"Open The File");
        QFile file(fileName);
        file_path=fileName;
        if(!file.open(QFile::ReadOnly| QFile::Text))
        {
            QMessageBox::warning(this,"...","file did not open");
            return;
        }
        QTextStream ts(&file);
        ui->textEdit->setText(ts.readAll());
        file.close();

}

void SimpleNotepad::on_actionSave_File_triggered()
{
    if(file_path=="")
    {
        SimpleNotepad::on_actionSave_As_triggered();
        return;
    }
    QFile file(file_path);
    if(!file.open(QFile::WriteOnly| QFile::Text))
    {
        QMessageBox::warning(this,"...","file did not open");
        return;
    }
    QTextStream ts(&file);
    ts<<ui->textEdit->toPlainText();
    file.flush();
    file.close();
}

void SimpleNotepad::on_actionSave_As_triggered()
{
    QString fileName=QFileDialog::getSaveFileName(this,"Open The File");
    QFile file(fileName);
    file_path=fileName;
    if(!file.open(QFile::WriteOnly| QFile::Text))
    {
        QMessageBox::warning(this,"...","file did not open");
        return;
    }
    QTextStream ts(&file);
    ts<<ui->textEdit->toPlainText();
    file.flush();
    file.close();

}

void SimpleNotepad::on_actionExit_triggered()
{
   QCoreApplication::quit();
}

void SimpleNotepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void SimpleNotepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void SimpleNotepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void SimpleNotepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void SimpleNotepad::on_actionAbout_triggered()
{
    QString aboutText="";
    aboutText +="Author : Cemsu Kağan KOÇ \n";
    aboutText +="Date : 08.11.2018 \n";
    aboutText +=" (C) SimpleNotepad (R)\n";

    QMessageBox::about(this,"About Simple Notepad",aboutText);
}

void SimpleNotepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void SimpleNotepad::on_actionChange_BackGround_triggered()
{
    ui->textEdit->setTextBackgroundColor(QColorDialog::getColor());
}

void SimpleNotepad::on_actionChange_Fonts_triggered()
{

  QFontDialog fontDialog(this);
  bool ok;

  QFont selected=fontDialog.getFont(&ok,this);


  ui->textEdit->setFont(selected);

}
