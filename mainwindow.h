#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool printLog(QString,int = 1000);
    bool isDigits(QString);
private slots:
    
    void on_pushButton_Num_1_clicked();
    
    void on_pushButton_Op_clear_clicked();

    void on_pushButton_Num_2_clicked();

    void on_pushButton_Op_plus_clicked();

    void on_pushButton_Op_minus_clicked();

    void on_pushButton_Op_multiply_clicked();

    void on_pushButton_Op_divide_clicked();

    void on_pushButton_Num_3_clicked();

    void on_pushButton_Num_4_clicked();

    void on_pushButton_Num_5_clicked();

    void on_pushButton_Num_6_clicked();

    void on_pushButton_Num_7_clicked();

    void on_pushButton_Num_8_clicked();

    void on_pushButton_Num_9_clicked();

    void on_pushButton_Num_0_clicked();

    void on_pushButton_Op_back_clicked();

    void on_pushButton_Op_equal_clicked();

    void on_pushButton_Op_bracket_left_clicked();

    void on_pushButton_Op_bracket_right_clicked();

    void on_pushButton_Op_dot_clicked();

    void on_testButton_clicked();

private:

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
