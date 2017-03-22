#include "Komissarov_Alexander_201732140_Task1.h"

int main(int argc, char *argv[])
{
    try
	{
		mvms_2017::Komissarov_Alexander_201732140_Task1 task1;
		auto pict = cv::imread("pict.png");
		auto size = pict.size();
		cv::imshow("Pict", task1.drawTriangle("pict.png", 20, 20, size.height - 21, 20, 20, size.width - 21));
		cv::waitKey(0);
    }
	catch(std::exception ex)
	{
        std::cout << ex.what() << std::endl;
		system("pause");
    }

    return 0;
}
