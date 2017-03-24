#include "Komissarov_Alexander_201732140_Task1.h"
#include <stdexcept>
#include <utility>

namespace mvms_2017
{
	void setRgb(cv::Mat &image, int x, int y, int value)
	{
		static int mask = 0xFF;
		image.at<cv::Vec3b>(y, x)[2] = (value >> 16) & mask;
		image.at<cv::Vec3b>(y, x)[1] = (value >> 8) & mask;
		image.at<cv::Vec3b>(y, x)[0] = value & mask;
	}

	int signum(int x)
	{
		return x != 0 ? x / std::abs(x) : 0;
	}

	void Komissarov_Alexander_201732140_Task1::drawLine(cv::Mat &image, Point p1, Point p2) const
	{
		int delta_x = std::abs(p1.x - p2.x), delta_y = std::abs(p1.y - p2.y);
		
		if (delta_x > delta_y)
		{
			Point start = p1.x < p2.x ? p1 : p2;
			Point end = p1.x >= p2.x ? p1 : p2;
			int error = 0, sign = signum(end.y - start.y);
			int y = start.y;
			for (int x = start.x; x <= end.x; ++x)
			{
				setRgb(image, x, y, line_color);
				error += delta_y; // здесь и далее домножено на delta_x
				if (2 * error >= delta_x)
				{
					y += sign;
					error -= delta_x;
				}
			}
		}
		else
		{
			Point start = p1.y < p2.y ? p1 : p2;
			Point end = p1.y >= p2.y ? p1 : p2;
			int error = 0, sign = signum(end.x - start.x);
			int x = start.x;
			for (int y = start.y; y <= end.y; ++y)
			{
				setRgb(image, x, y, line_color);
				error += delta_x; // здесь и далее домножено на delta_y
				if (2 * error >= delta_y)
				{
					x += sign;
					error -= delta_y;
				}
			}
		}
	}

	Komissarov_Alexander_201732140_Task1::Komissarov_Alexander_201732140_Task1()
		: Komissarov_Alexander_201732140_Task1(true)
	{
	
	}

	Komissarov_Alexander_201732140_Task1::Komissarov_Alexander_201732140_Task1(bool verbose) 
		: Task1(verbose)
	{
	
	}

	int Komissarov_Alexander_201732140_Task1::variant()
	{
		return 201732140;
	}

	std::string Komissarov_Alexander_201732140_Task1::getFirstName()
	{
		return "Александр";
	}

	std::string Komissarov_Alexander_201732140_Task1::getSecondName()
	{
		return "Комиссаров";
	}

	cv::Mat Komissarov_Alexander_201732140_Task1::drawTriangle(std::string filename, 
															   float x1, 
															   float y1, 
															   float x2, 
															   float y2, 
															   float x3, 
															   float y3)
	{
		auto image = cv::imread(filename);
		drawLine(image, { x1, y1 }, { x2, y2 });
		drawLine(image, { x1, y1 }, { x3, y3 });
		drawLine(image, { x2, y2 }, { x3, y3 });
		return std::move(image);
	}
}
