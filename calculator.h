#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void on_zero_clicked();

    void on_one_clicked();

    void on_two_clicked();

    void on_three_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

    void on_clear_clicked();

    void on_multiplication_clicked();

    void on_minus_clicked();

    void on_plus_clicked();

    void on_divide_clicked();

    void on_equal_clicked();

private:
    Ui::Calculator *ui;
};
#endif // CALCULATOR_H
