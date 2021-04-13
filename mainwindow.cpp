#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStack"
#include "QQueue"
#include "algorithm"
#include "qdebug.h"
#include "QTime"

//mainwindow构造函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString input="0";
    QString output="0";
    ui->textEdit_Input->setText(input);
    ui->textEdit_Output->setText(output);

}
//析构函数
MainWindow::~MainWindow()
{
    delete ui;
}

//一些辅助使用的函数

//延时
void sleep(int msec)
{
QTime dieTime = QTime::currentTime().addMSecs(msec);
while( QTime::currentTime() < dieTime )
QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
//日志输出至output
bool MainWindow::printLog(QString a,int t)
{
//    ui->textEdit_Output->setText(a);
    ui->textEdit_Output->append(a);
    sleep(t);
    return true;
}

//检测字符串末尾的运算符并删去
inline void endsWithOpsDel(QString& input,bool flag_minus=0){
    if(flag_minus){
        while(input.endsWith('+')||input.endsWith('-')||
                input.endsWith('*')||input.endsWith('/')||
                input.endsWith('.')){
            input.chop(1);
        }
    }else {
        while(input.endsWith('+')||input.endsWith('-')||
                input.endsWith('*')||input.endsWith('/')||
                input.endsWith('.')||input.endsWith('(')){
            input.chop(1);
        }
    }

}

//判断0或空字符串并reset
inline void zeroReset(QString& input){
    if(input.isEmpty()||input=='0'){
        input = "";
    }
}
//字符串是否全为数字
bool MainWindow::isDigits(QString st){
    if((st[0]>='0'&&st[0]<='9')||((st[0]=='-'&&st.length()!=1))){
//        printLog("is digits No1 number");
    }
    else {
//        printLog("is digits No1 no num");
        return false;
    }
    for (int i = 1; i < st.length(); ++i) {
//        printLog("is digits for:"+QString::number(i));
        if ((st[i]>'9'||st[i]<'0')&&st[i]!='.'){
//            printLog("is digits return false");
            return false;
        }

    }
//    printLog("is digits return true");
    return true;
}

//优先级
int priority(QCharRef ch){
    if(ch==')')
        return 0;
    if(ch>='0'&&ch<='9')
        return 1;
    if(ch=='+'||ch=='-')
        return 2;
    if(ch=='*'||ch=='/')
        return 3;
    else
        return -1;
}
int priority(QChar ch){
    if(ch==')')
        return 0;
    if(ch>='0'&&ch<='9')
        return 1;
    if(ch=='+'||ch=='-')
        return 2;
    if(ch=='*'||ch=='/')
        return 3;
    else
        return -1;
}

//数字Num按钮函数
void MainWindow::on_pushButton_Num_1_clicked()
{
    QString input;
    input = ui->textEdit_Input->toPlainText();
    zeroReset(input);
    input.append('1');
    ui->textEdit_Input->setText(input);
}


void MainWindow::on_pushButton_Num_2_clicked()
{
    QString input;
    input = ui->textEdit_Input->toPlainText();
    zeroReset(input);
    input.append('2');
    ui->textEdit_Input->setText(input);
}


void MainWindow::on_pushButton_Num_3_clicked()
{
    QString input;
    input = ui->textEdit_Input->toPlainText();
    zeroReset(input);
    input.append('3');
    ui->textEdit_Input->setText(input);
}

void MainWindow::on_pushButton_Num_4_clicked()
{
    QString input;
    input = ui->textEdit_Input->toPlainText();
    zeroReset(input);
    input.append('4');
    ui->textEdit_Input->setText(input);
}

void MainWindow::on_pushButton_Num_5_clicked()
{
    QString input;
    input = ui->textEdit_Input->toPlainText();
    zeroReset(input);
    input.append('5');
    ui->textEdit_Input->setText(input);
}

void MainWindow::on_pushButton_Num_6_clicked()
{
    QString input;
    input = ui->textEdit_Input->toPlainText();
    zeroReset(input);
    input.append('6');
    ui->textEdit_Input->setText(input);
}

void MainWindow::on_pushButton_Num_7_clicked()
{
    QString input;
    input = ui->textEdit_Input->toPlainText();
    zeroReset(input);
    input.append('7');
    ui->textEdit_Input->setText(input);
}

void MainWindow::on_pushButton_Num_8_clicked()
{
    QString input;
    input = ui->textEdit_Input->toPlainText();
    zeroReset(input);
    input.append('8');
    ui->textEdit_Input->setText(input);
}

void MainWindow::on_pushButton_Num_9_clicked()
{
    QString input;
    input = ui->textEdit_Input->toPlainText();
    zeroReset(input);
    input.append('9');
    ui->textEdit_Input->setText(input);
}

void MainWindow::on_pushButton_Num_0_clicked()
{
    QString input;
    input = ui->textEdit_Input->toPlainText();
    zeroReset(input);
    input.append('0');
    ui->textEdit_Input->setText(input);
}


//运算(op)功能函数
//清0
void MainWindow::on_pushButton_Op_clear_clicked()
{
    ui->textEdit_Input->setText("0");
    ui->textEdit_Output->setText("0");
}
//加
void MainWindow::on_pushButton_Op_plus_clicked()
{
    QString input;
    input = ui->textEdit_Input->toPlainText();
    endsWithOpsDel(input);
    input.append('+');
    ui->textEdit_Input->setText(input);
}
//减
void MainWindow::on_pushButton_Op_minus_clicked()
{
    QString input;
    input = ui->textEdit_Input->toPlainText();
    endsWithOpsDel(input,1);
    if(input=="0")
        input="";
    input.append('-');
    ui->textEdit_Input->setText(input);
}
//乘
void MainWindow::on_pushButton_Op_multiply_clicked()
{
    QString input;
    input = ui->textEdit_Input->toPlainText();
    endsWithOpsDel(input);
    input.append('*');
    ui->textEdit_Input->setText(input);
}
//除
void MainWindow::on_pushButton_Op_divide_clicked()
{
    QString input;
    input = ui->textEdit_Input->toPlainText();
    endsWithOpsDel(input);
    input.append('/');
    ui->textEdit_Input->setText(input);
}


//退格
void MainWindow::on_pushButton_Op_back_clicked()
{
    QString input = ui->textEdit_Input->toPlainText();
    input.chop(1);
    ui->textEdit_Input->setText(input);
}


//左括号
void MainWindow::on_pushButton_Op_bracket_left_clicked()
{
    QString input = ui->textEdit_Input->toPlainText();
    if(input.endsWith('+')||input.endsWith('-')||
            input.endsWith('*')||input.endsWith('/')||
            input.endsWith('(')){
        //左括号前面可以有以上运算符 除此之外报告至output
    }else {
//        ui->textEdit_Output->setText("提示:运算不合理");
        return;
    }
    input.append('(');
    ui->textEdit_Input->setText(input);

}
//右括号
void MainWindow::on_pushButton_Op_bracket_right_clicked()
{
    QString input = ui->textEdit_Input->toPlainText();
    if(input.endsWith('+')||input.endsWith('-')||
            input.endsWith('*')||input.endsWith('/')||
            input.endsWith('(')||input.endsWith('.')){
        //右括号左边不可包含以上字符
//        ui->textEdit_Output->setText("提示:运算不合理");
        return;
    }
    input.append(')');
    ui->textEdit_Input->setText(input);
}

//小数点
void MainWindow::on_pushButton_Op_dot_clicked()
{
    QString input = ui->textEdit_Input->toPlainText();
    if(input.endsWith('+')||input.endsWith('-')||
            input.endsWith('*')||input.endsWith('/')||
            input.endsWith('(')||input.endsWith('.')){
        //小数点前面不可包含以上字符
//        ui->textEdit_Output->setText("提示:运算不合理");
        return;
    }
    input.append('.');
    ui->textEdit_Input->setText(input);
}

//等号 核心代码 从input框中取出待运算的字符串 运算后输出至output
void MainWindow::on_pushButton_Op_equal_clicked()
{
    QString input = ui->textEdit_Input->toPlainText();
    QStack <QChar> op;
    QStack <QString> postTemp;
//    QString p;
    int numIdxStart=-1;
    //中缀转为后缀表达式计算
    for (int i = 0; i < input.length(); ++i) {
        //数字开始  记录下标
        if(priority(input[i])==1&&numIdxStart==-1){
            numIdxStart=i;
        }else if(priority(input[i])==1){
            //数字
        }else {
            //此处input[i]为运算符
            //目前为止的是数字 push入后缀栈 此if防止连续运算符出现导致的bug
            if(numIdxStart!=-1){
                QString n = input.mid(numIdxStart,i-numIdxStart);
                postTemp.push(n);
            }
            numIdxStart = -1;
            if(op.isEmpty()){
                op.push(input[i]);
            }else if(priority(input[i])==1){
                op.push(input[i]);
            }else if(input[i]=='('){
                op.push(input[i]);
            }else if(priority(input[i])>=priority(op.top())){
                op.push(input[i]);
            }else if(input[i]==')'){
                //遇到右括号则弹栈中运算符直到遇到左括号
                while(op.top()!='(')
                    postTemp.push(op.pop());
                op.pop();
            }else if(priority(input[i])<priority(op.top())){
                //若当前运算符优先级小于栈中 则弹 直到运算符高于等于栈中元素
                //并将当前运算符push入栈
                while(!op.isEmpty()&&priority(input[i])<=priority(op.top()))
                    postTemp.push(op.pop());
                op.push(input[i]);
            }else{
                printLog("else");
            }
        }
    } //end for
    //将最后的数字push入栈
    if(numIdxStart!=-1)
        postTemp.push(input.mid(numIdxStart));
    //将op栈里残存的运算符push入栈
    while(!op.isEmpty()){
        postTemp.push(op.pop());
    }
    QVector<QString> post;
    while(!postTemp.isEmpty()){
//        p = postTemp.top() + p;
        post.append(postTemp.pop());
    }
//    //post为后缀表达式vector(反向） 不是字符串是因为有多位数的运算 字符串仍需分析数字的位数
//    //post不带括号 每个元素为一个操作符（数字或运算符）
//    printLog("p:"+p);

    QStack <double> ans;
    for (int i = post.length()-1; i >= 0; --i) {
        printLog("for:"+QString::number(i)+" post[i]:"+post[i],1000);
        if(isDigits(post[i])){
            ans.push(post[i].toDouble());
            continue;
        }
        double a = ans.pop();
        double b = ans.pop();
        double c=66666;
        if(post[i]=='+'){
            c = b + a;
        }else if(post[i]=='-'){
            c = b - a;
        }else if(post[i]=='*'){
            c = b * a;
        }else if(post[i]=='/'){
            c = b / a;
        }else {
            printLog("shit");
        }
        ans.push(c);
    }
//    printLog("sleep",100000);
    ui->textEdit_Output->setText(QString::number(ans.pop()));


//    printLog("postfix:"+p,1000);
//    QStack<double> num;
//    for (int i = post.length()-1; i>0; --i) {
//        printLog("for:"+QString::number(i),400);
//        if(printLog("isDigits:"+post[i])&&isDigits(post[i])){
//            num.push(post[i].toDouble());
//        }else{
//            if(post[i]=='+'){
//                try {
//                    double ans = num.pop()+num.pop();
//                    num.push(ans);
//                } catch (...) {
//                    printLog("'error in +'",1000);
//                }

//            }else if(post[i]=='-'){
//                try {
//                    double a = num.pop();
//                    double b = num.pop();
//                    double ans = b - a;
//                    num.push(ans);
//                } catch (...) {
//                    printLog("error in -",1000);
//                }
//            }else if(post[i]=='*'){
//                try {
//                    printLog("*");
//                    double ans = num.pop()*num.pop();
//                    num.push(ans);
//                } catch (...) {
//                    printLog("error in *",1000);
//                }
//            }else if(post[i]=='/'){
//                try {
//                    printLog("/");
//                    double a = num.pop();
//                    double b = num.pop();
//                    double ans = b / a;
//                    num.push(ans);
//                } catch (...) {
//                    printLog("error in /",1000);
//                }
//            }else{
//                printLog("else");
//            }
//        }
//    }
//    QString output = QString::number(num.pop());
//    ui->textEdit_Output->setText(output);
}

//测试用的button 现已移除
void MainWindow::on_testButton_clicked()
{
    QString in = ui->textEdit_Input->toPlainText();
    if(isDigits(in))
        ui->textEdit_Output->setText("YES");
    else
        ui->textEdit_Output->setText("NO");
}
