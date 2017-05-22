#include "Komissarov_Alexander_201732140_Task1.h"
#include "Komissarov_Alexander_201732140_Task2.h"
#include "Komissarov_Alexander_201732140_Task3.h"
#include "Komissarov_Alexander_201732140_Task4.h"
#include "Komissarov_Alexander_201732140_Task5.h"

#include <iostream>

static void print_mat(cv::Mat matrix)
{
    auto size = matrix.size();
    for (int row = 0; row < size.height; ++row)
    {
        for (int column = 0; column < size.width; ++column)
        {
            std::cout << matrix.at<float>(row, column) << ' ';
        }
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[])
{
    try
	{
		mvms_2017::Komissarov_Alexander_201732140_Task1 task1;
		mvms_2017::Komissarov_Alexander_201732140_Task2 task2;
        mvms_2017::Komissarov_Alexander_201732140_Task3 task3;
        mvms_2017::Komissarov_Alexander_201732140_Task4 task4;
        mvms_2017::Komissarov_Alexander_201732140_Task5 task5;
		auto pict = cv::imread("pict3.png");
		auto size = pict.size();

        auto result = task5.getProjectionMatrix({ {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6} },
                                                { {-3.f / 7 * 2 - 3, -3.f / 7 * 2 - 3, 9}, 
                                                  {-2.f / 7 * 3 - 2, -2.f / 7 * 3 - 2, 10}, 
                                                  {-1.f / 7 * 4 - 1, -1.f / 7 * 4 - 1,11},
                                                  {1.f / 7 * 5 + 1,1.f / 7 * 5 + 1, 12}, 
                                                  {2.f / 7 * 6 + 2, 2.f / 7 * 6 + 2, 13}, 
                                                  {6, 6, 14} });
        cv::Mat X(cv::Matx<float, 4, 1>(6, 6, 14, 1));
        cv::Mat projected = result * X;

        std::cout << "Mat" << std::endl;
        print_mat(result);
        std::cout << "X" << std::endl;
        print_mat(X);
        std::cout << "x" << std::endl;
        print_mat(projected);

        //cv::imshow("Blurred", pict);
        
		//cv::waitKey(0);
        system("pause");
    }
    catch (const std::exception &ex)
	{
        std::cout << ex.what() << std::endl;
		system("pause");
    }

    return 0;
}
