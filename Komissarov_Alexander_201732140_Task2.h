#pragma once
#include <array>
#include "task2.h"

namespace mvms_2017
{
	struct Rgb
	{
		short red, green, blue;
		Rgb(short r, short g, short b);
	};

	class Komissarov_Alexander_201732140_Task2 : public Task2
	{
	private:
		static const std::array<std::array<short, 3>, 3> DX, DY;

	public:
		using Kernel = std::array<std::array<short, 3>, 3>;

		Komissarov_Alexander_201732140_Task2();
		Komissarov_Alexander_201732140_Task2(bool verbose);

		int variant() override;
		std::string getFirstName() override;
		std::string getSecondName() override;
		
		cv::Mat sobel(cv::Mat image, int dir);
		cv::Mat convolution(cv::Mat image, const Kernel &kernel) const;

	private:
		Rgb convolution(cv::Mat image, const Kernel &kernel, int x, int y) const;
	};
}
