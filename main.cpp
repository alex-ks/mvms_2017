#include "Komissarov_Alexander_201732140_Task1.h"

int main(int argc, char *argv[])
{
    try
	{
		mvms_2017::Komissarov_Alexander_201732140_Task1 task1;
		auto pict = cv::imread("pict3.png");
		auto size = pict.size();
		cv::Point p1(20, 20), p2(size.width - 21, 20), p3(20, size.height - 21);
		auto pict_with_t = task1.drawTriangle("pict3.png", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
		cv::line(pict_with_t, p1, p2, cv::COLORMAP_OCEAN);
		cv::line(pict_with_t, p1, p3, cv::COLORMAP_OCEAN);
		cv::line(pict_with_t, p3, p2, cv::COLORMAP_OCEAN);
		cv::imshow("Pict", pict_with_t);
		cv::waitKey(0);
    }
	catch(std::exception ex)
	{
        std::cout << ex.what() << std::endl;
		system("pause");
    }

    return 0;
}
