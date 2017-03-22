#pragma once
#include "task1.h"

namespace mvms_2017
{
	struct Point
	{
		float x, y;
	};

	class Komissarov_Alexander_201732140_Task1 : public Task1
	{
	private:
		int line_color = 0xFFFFFFFF;
		void drawLine(cv::Mat &image, Point p1, Point p2) const;

	public:
		Komissarov_Alexander_201732140_Task1();
		Komissarov_Alexander_201732140_Task1(bool verbose);

		int variant() override;
		std::string getFirstName() override;
		std::string getSecondName() override;

		cv::Mat drawTriangle(std::string filename, 
							 float x1, 
							 float y1, 
							 float x2, 
							 float y2, 
							 float x3, 
							 float y3) override;
	};
}
