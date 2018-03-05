#include <fstream>
#include <string>

#include "../tofunction/tofunction.h"

#define PI 3.141592653589

struct AnswerGSA
{
    double minX;
    double minY;
};

double f(ToFunction&, double);
void methodFSA(std::string, double, double, double, double&, double&);

int main (int argc, char* argv[])
{
    //  Task #0 "x^2"
    {
        AnswerGSA answer;
        answer.minX = 0;
        answer.minY = 0;

        std::ofstream answer_stream("../answers/answer_00.answ", std::ios::out | std::ios::binary);

        answer_stream << answer.minX << std::endl;
        answer_stream << answer.minY << std::endl;

        answer_stream.close();
    }
    //  Task #1 "sin(x)"
    {
        AnswerGSA answer;
        answer.minX = 3 * PI / 2;
        answer.minY = -1;

        std::ofstream answer_stream("../answers/answer_01.answ", std::ios::out | std::ios::binary);

        answer_stream << answer.minX << std::endl;
        answer_stream << answer.minY << std::endl;

        answer_stream.close();
    }

    //  Task #2 "(x/4)*cos(x)"
    {
        AnswerGSA answer;
        answer.minX = 9 * PI;
        answer.minY = -7.06858347057703478;

        std::ofstream answer_stream("../answers/answer_02.answ", std::ios::out | std::ios::binary);

        answer_stream << answer.minX << std::endl;
        answer_stream << answer.minY << std::endl;

        answer_stream.close();
    }
    //  Task #3 "(x*sin((x^(0.5)))+cos(x)*x)/4"
    {
        AnswerGSA answer;
        methodFSA("(x*sin((x^(0.5)))+cos(x)*x)/4", 28.0, 28.5, 0.00001, answer.minX, answer.minY);
        /* answer.minX = 28.27; // need a full search
        answer.minY = -12.88; */

        std::ofstream answer_stream("../answers/answer_03.answ", std::ios::out | std::ios::binary);

        answer_stream << answer.minX << std::endl;
        answer_stream << answer.minY << std::endl;

        answer_stream.close();
    }
    //  Task #4 "(2^x)*sin(x)"
    {
        AnswerGSA answer;
        methodFSA("(2^x)*sin(x)", 17.8, 18, 0.00001, answer.minX, answer.minY);
        /* answer.minX = 17.88; // need a full search
        answer.minY = -19892; */

        std::ofstream answer_stream("../answers/answer_04.answ", std::ios::out | std::ios::binary);

        answer_stream << answer.minX << std::endl;
        answer_stream << answer.minY << std::endl;

        answer_stream.close();
    }

    return 0;
}

double f(ToFunction& toFunc, double x)
{
    toFunc.Calculate(x);
}

void methodFSA(std::string func, double a, double b, double step, double& minX, double& minY)
{
    ToFunction toFunc(func);
    int num_x = (b - a) / step + 1;
    double* x_array = new double[num_x];

    double current_x = a;
    double current_y;
    minY = f(toFunc, a);
    while (current_x <= b + step) {
        current_y = f(toFunc, current_x);
        if (current_y < minY) {
            minY = current_y;
            minX = current_x;
        }
        current_x += step;
    }

    delete[] x_array;
}
