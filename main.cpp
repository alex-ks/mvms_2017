#include "Komissarov_Alexander_201732140_Task1.h"
#include "Komissarov_Alexander_201732140_Task2.h"
#include "Komissarov_Alexander_201732140_Task3.h"
#include "Komissarov_Alexander_201732140_Task4.h"

int main(int argc, char *argv[])
{
    try
	{
		mvms_2017::Komissarov_Alexander_201732140_Task1 task1;
		mvms_2017::Komissarov_Alexander_201732140_Task2 task2;
        mvms_2017::Komissarov_Alexander_201732140_Task3 task3;
        mvms_2017::Komissarov_Alexander_201732140_Task4 task4;
		auto pict = cv::imread("pict3.png");
		auto size = pict.size();

        cv::cvtColor(pict, pict, cv::COLOR_RGB2GRAY);

        auto result = task4.brief(pict, 
                                  { {50, 50}, {70, 70}, {120, 160} }, 
                                  { { {-1, -1}, {1, 1} }, { {-1, 1}, {1, -1} } });

		cv::imshow("Pict", pict);
        cv::Mat blurred;
        cv::GaussianBlur(pict, blurred, { 3, 3 }, 0);
        cv::imshow("Blurred", blurred);

		cv::waitKey(0);
    }
    catch (std::exception ex)
	{
        std::cout << ex.what() << std::endl;
		system("pause");
    }

    return 0;
}
