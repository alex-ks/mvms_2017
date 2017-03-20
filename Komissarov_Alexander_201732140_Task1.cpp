#include "Komissarov_Alexander_201732140_Task1.h"
#include <stdexcept>
#include <utility>

namespace mvms_2017
{
	void Komissarov_Alexander_201732140_Task1::drawLine(cv::Mat &image, float x1, float y1, float x2, float y2) const
	{
		throw std::runtime_error("Not implemented");
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
		return "Комиссаров";
	}

	std::string Komissarov_Alexander_201732140_Task1::getSecondName()
	{
		return "Александр";
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
		drawLine(image, x1, y1, x2, y2);
		drawLine(image, x1, y1, x3, y3);
		drawLine(image, x2, y2, x3, y3);
		return std::move(image);
	}
}
