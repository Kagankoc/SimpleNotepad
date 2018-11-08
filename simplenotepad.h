#ifndef SIMPLENOTEPAD_H
#define SIMPLENOTEPAD_H

#include <QMainWindow>
#include <QFile>

namespace Ui {
class SimpleNotepad;
}

class SimpleNotepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimpleNotepad(QWidget *parent = nullptr);
    ~SimpleNotepad();

private slots:
    void on_actionNew_File_triggered();

    void on_actionOpen_File_triggered();

    void on_actionSave_File_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionAbout_triggered();

    void on_actionUndo_triggered();

    void on_actionChange_BackGround_triggered();

    void on_actionChange_Fonts_triggered();

private:
    Ui::SimpleNotepad *ui;
    QString file_path;
};

#endif // SIMPLENOTEPAD_H
