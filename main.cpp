#include "Komissarov_Alexander_201732140_Task1.h"
#include "Komissarov_Alexander_201732140_Task2.h"

int main(int argc, char *argv[])
{
    try
	{
		mvms_2017::Komissarov_Alexander_201732140_Task1 task1;
		mvms_2017::Komissarov_Alexander_201732140_Task2 task2;
		auto pict = cv::imread("pict3.png");
		
		auto size = pict.size();
		/*cv::Point p1(20, 20), p2(size.width - 21, 20), p3(20, size.height - 21);
		auto pict_with_t = task1.drawTriangle("pict3.png", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
		cv::imshow("Pict", pict_with_t);*/

		//auto conv_pict = task2.convolution(pict, { { { 0, -1, 0 }, { -1, 4, -1 }, { 0, -1, 0 } } });
		//cv::imshow("Pict", task2.sobel(pict, 0));
		
		/*cv::imwrite("dx.png", task2.sobel(pict, 0));
		cv::imwrite("dy.png", task2.sobel(pict, 1));*/

		cv::Mat dy = task2.sobel(pict, 1);
		/*cv::Mat dy;
		cv::Sobel(pict, dy, CV_16S, 0, 1);*/
		dy.convertTo(dy, CV_8U);
		cv::imshow("Pict", dy);

		cv::waitKey(0);
    }
	catch(std::exception ex)
	{
        std::cout << ex.what() << std::endl;
		system("pause");
    }

    return 0;
}
