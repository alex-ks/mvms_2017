#include "Komissarov_Alexander_201732140_Task1.h"
#include <stdexcept>

namespace mvms_2017
{
	Komissarov_Alexander_201732140_Task1::Komissarov_Alexander_201732140_Task1() 
		: Komissarov_Alexander_201732140_Task1(true)
	{
	
	}

	Komissarov_Alexander_201732140_Task1::Komissarov_Alexander_201732140_Task1(bool verbose) 
		: Komissarov_Alexander_201732140_Task1(verbose)
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

	cv::Mat Komissarov_Alexander_201732140_Task1::drawTriangle(std::string filename, float x1, float y1, float x2, float y2, float x3, float y3)
	{
		throw std::runtime_error("Not implemented");
	}
}
