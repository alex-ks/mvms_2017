#include "Komissarov_Alexander_201732140_Task2.h"

#include <stdexcept>

namespace mvms_2017
{
	const std::array<std::array<short, 3>, 3> Komissarov_Alexander_201732140_Task2::DX =
	{{
		{ -1, -2, -1 },
		{  0,  0,  0 },
		{  1,  2,  1 }
	}};

	const std::array<std::array<short, 3>, 3> Komissarov_Alexander_201732140_Task2::DY =
	{{
		{ -1, 0, 1 },
		{ -2, 0, 2 },
		{ -1, 0, 1 }
	}};

	inline unsigned char saturate(int value)
	{
		return value > 0 ? (value < 256 ? value : 255) : 0;
	}

	Rgb::Rgb(short r, short g, short b) : red(r), green(g), blue(b) { }

	template <typename TValue>
	Rgb getRgb(const cv::Mat &image, int x, int y)
	{
		return Rgb
		{
			image.at<cv::Vec<TValue, 3>>(y, x)[2],
			image.at<cv::Vec<TValue, 3>>(y, x)[1],
			image.at<cv::Vec<TValue, 3>>(y, x)[0]
		};
	}

	template <typename TValue>
	void setRgb(cv::Mat &image, int x, int y, Rgb value)
	{
		image.at<cv::Vec<TValue, 3>>(y, x)[2] = value.red;
		image.at<cv::Vec<TValue, 3>>(y, x)[1] = value.green;
		image.at<cv::Vec<TValue, 3>>(y, x)[0] = value.blue;
	}

	Rgb Komissarov_Alexander_201732140_Task2::convolution(cv::Mat image, 
														  const Kernel &kernel, 
														  int x, 
														  int y) const
	{
		int rsum, gsum, bsum;
		rsum = gsum = bsum = 0;

		for (int i = 0; i < kernel[0].size(); ++i)
		{
			for (int j = 0; j < kernel.size(); ++j)
			{
				int dx = i - kernel[0].size() / 2;
				int dy = j - kernel.size() / 2;
				auto value = getRgb<uchar>(image, x + dx, y + dy);
				rsum += value.red * kernel[i][j];
				gsum += value.green * kernel[i][j];
				bsum += value.blue * kernel[i][j];
			}
		}

		return Rgb(rsum, gsum, bsum);
	}

	cv::Mat Komissarov_Alexander_201732140_Task2::convolution(cv::Mat image, 
															  const Kernel &kernel) const
	{
		auto size = image.size();
		size.width -= kernel[0].size() - 1;
		size.height -= kernel.size() - 1;

		cv::Mat result(size, CV_16SC3);

		for (int x = 0; x < size.width; ++x)
		{
			for (int y = 0; y < size.height; ++y)
			{
				auto rgb = convolution(image, kernel, x + kernel[0].size() / 2, y + kernel.size() / 2);
				setRgb<short>(result, x, y, rgb);
			}
		}

		return result;
	}

	cv::Mat Komissarov_Alexander_201732140_Task2::sobel(cv::Mat image, int dir)
	{
		auto &kernel = dir == 0 ? DX : DY;
		return convolution(image, kernel);
	}

	Komissarov_Alexander_201732140_Task2::Komissarov_Alexander_201732140_Task2() : Task2(true) { }

	Komissarov_Alexander_201732140_Task2::Komissarov_Alexander_201732140_Task2(bool verbose) : Task2(verbose) { }

	int Komissarov_Alexander_201732140_Task2::variant()
	{
		return 201732140;
	}

	std::string Komissarov_Alexander_201732140_Task2::getFirstName()
	{
		return "Александр";
	}

	std::string Komissarov_Alexander_201732140_Task2::getSecondName()
	{
		return "Комиссаров";
	}
}