#include "main.h"

#define pi 3.1415926
#define MAX 0
void Clark_Change(double U_a, double U_b) //克拉克变化
{
    double U_alpha = U_a;
    double U_beta = (U_a + 2*U_b)/(sqrt(3));
    printf("输入的U_a是%f，U_b是%f，输出的U_alpha是%f，U_beta是%f。\n", U_a, U_b, U_alpha, U_beta);
}

void Opposite_Clark_Change(double U_alpha, double U_beta)//反克拉克变化
{
    double U_a = U_alpha;
    double U_b = (sqrt(3)*U_beta - U_alpha)/2;
    double U_c = (- U_alpha - (sqrt(3))*U_beta)/2;
    printf("输入的U_alpha是%f，U_beta是%f，输出的U_a是%f，U_b是%f，U_c是%f。\n", U_alpha, U_beta, U_a, U_b, U_c);
}

void Park_Change(double U_alpha, double U_beta, double theta)//帕克变化
{
    double U_d = U_alpha * cos(theta) + U_beta * sin(theta);
    double U_q = -U_alpha * sin(theta) + U_beta * cos(theta);
    printf("输入的U_alpha是%f，U_beta是%f，theta是%f，输出的U_d是%f，U_q是%f。\n", U_alpha, U_beta, theta, U_d, U_q);
}

void Opposite_Park_Change(double U_d, double U_q, double theta)//反帕克变化
{
    double U_alpha = U_d * cos(theta) - U_q * sin(theta);
    double U_beta = U_d * sin(theta) + U_q * cos(theta);
    printf("输入的U_d是%f，U_q是%f，theta是%f，输出的U_alpha是%f，U_beta是%f。\n", U_d, U_q, theta, U_alpha, U_beta);
}

int main(int argc, char const *argv[])
{
    Clark_Change(4095,4095*cos(1));
    Park_Change(4095.537943, 4919.360412,1);
    return 0;
}