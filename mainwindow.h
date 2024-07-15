#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Insert_triggered();

    void on_Copy_triggered();

    void on_Cut_triggered();

    void on_NewFile_triggered();

    void on_OpenFile_triggered();

    void on_SaveFile_triggered();

private:
    QString currFile;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
