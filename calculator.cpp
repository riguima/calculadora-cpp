#include "calculator.h"
#include "./ui_calculator.h"
#include <string>
#include <regex>
#include <iostream>

using namespace std;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::on_zero_clicked()
{
    if(ui->input->text() != ""){
        ui->input->setText(ui->input->text() + "0");
    }
}
void Calculator::on_one_clicked()
{
    ui->input->setText(ui->input->text() + "1");
}


void Calculator::on_two_clicked()
{
    ui->input->setText(ui->input->text() + "2");
}


void Calculator::on_three_clicked()
{
    ui->input->setText(ui->input->text() + "3");
}


void Calculator::on_four_clicked()
{
    ui->input->setText(ui->input->text() + "4");
}


void Calculator::on_five_clicked()
{
    ui->input->setText(ui->input->text() + "5");
}


void Calculator::on_six_clicked()
{
    ui->input->setText(ui->input->text() + "6");
}


void Calculator::on_seven_clicked()
{
    ui->input->setText(ui->input->text() + "7");
}


void Calculator::on_eight_clicked()
{
    ui->input->setText(ui->input->text() + "8");
}


void Calculator::on_nine_clicked()
{
    ui->input->setText(ui->input->text() + "9");
}


void Calculator::on_clear_clicked()
{
    ui->input->setText("");
}


void Calculator::on_multiplication_clicked()
{
    if(ui->input->text() != "" && ui->input->text().back() != " "){
        ui->input->setText(ui->input->text() + " * ");
    }
}


void Calculator::on_minus_clicked()
{
    if(ui->input->text() != "" && ui->input->text().back() != " "){
        ui->input->setText(ui->input->text() + " - ");
    }
}


void Calculator::on_plus_clicked()
{
    if(ui->input->text() != "" && ui->input->text().back() != " "){
        ui->input->setText(ui->input->text() + " + ");
    }
}


void Calculator::on_divide_clicked()
{
    if(ui->input->text() != "" && ui->input->text().back() != " "){
        ui->input->setText(ui->input->text() + " / ");
    }
}


string get_signal(string expression){
    if(expression.find('*') != string::npos && expression.find('*') < expression.find('/')){
        return "*";
    }else if(expression.find('/') != string::npos && expression.find('/') < expression.find('*')){
        return "/";
    }else if(expression.find('+') != string::npos && expression.find('+') < expression.find('-')){
        return "+";
    }else if(expression.find('-') != string::npos && expression.find('-') < expression.find('+')){
        return "-";
    }
    return "";
}


float calculate_matches(string match_1, string match_2, string signal){
    if(signal == "*"){
        return stof(match_1) * stof(match_2);
    }else if(signal == "/"){
        return stof(match_1) / stof(match_2);
    }else if(signal == "+"){
        return stof(match_1) + stof(match_2);
    }else{
        return stof(match_1) - stof(match_2);
    }
}


void Calculator::on_equal_clicked()
{
    float result;
    string expression = ui->input->text().toStdString();
    string match_1, match_2 = "";
    smatch matches;
    string signal, reg;
    while(true){
        signal = get_signal(expression);
        if(signal == ""){
            break;
        }
        if(signal == "*" || signal == "+"){
            reg = "([0-9]+(\\.[0-9]+)?) \\" + signal + " ([0-9]+(\\.[0-9]+)?)";
        }else{
            reg = "([0-9]+(\\.[0-9]+)?) " + signal + " ([0-9]+(\\.[0-9]+)?)";
        }
        regex_search(expression, matches, regex(reg));
        for(size_t i=0; i<matches.size(); i++){
            if(matches.str(i)[0] != '.' && matches.str(i).find(signal) == string::npos && matches.str(i) != ""){
                if(match_1 == ""){
                    match_1 = matches.str(i);
                }else{
                    match_2 = matches.str(i);
                }
            }
        }
        result = calculate_matches(match_1, match_2, signal);
        expression = expression.replace(expression.find(matches.str()), matches.str().length(), to_string(result));
        match_1 = match_2 = "";
    }
    ui->input->setText(QString::fromStdString(expression));
}
