#include "Komissarov_Alexander_201732140_Task1.h"
#include "Komissarov_Alexander_201732140_Task2.h"
#include "Komissarov_Alexander_201732140_Task3.h"

int main(int argc, char *argv[])
{
    try
	{
		mvms_2017::Komissarov_Alexander_201732140_Task1 task1;
		mvms_2017::Komissarov_Alexander_201732140_Task2 task2;
        mvms_2017::Komissarov_Alexander_201732140_Task3 task3;
		auto pict = cv::imread("pict3.png");
		auto size = pict.size();

        cv::cvtColor(pict, pict, cv::COLOR_RGB2GRAY);

        cv::Mat reference;
        cv::adaptiveThreshold(pict, reference, 255, CV_ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 5, 7);
        cv::imshow("Reference", reference);
		
        auto result = task3.adaptiveBinary(pict, 5, 7);

		cv::imshow("Pict", result);

		cv::waitKey(0);
    }
    catch (std::exception ex)
	{
        std::cout << ex.what() << std::endl;
		system("pause");
    }

    return 0;
}
