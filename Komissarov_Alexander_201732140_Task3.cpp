#include "Komissarov_Alexander_201732140_Task3.h"
#include <stdexcept>
#include <vector>

namespace mvms_2017
{
    template <typename TValue>
    inline TValue getPixel(const cv::Mat &image, int x, int y)
    {
        return image.at<TValue>(y, x);
    }

    template <typename TValue>
    inline void setPixel(cv::Mat &image, int x, int y, TValue value)
    {
        image.at<TValue>(y, x) = value;
    }

    template <typename F>
    static auto calcAdaptiveThreshold(const cv::Mat &image, int filter_size, int x, int y, F filter)
    {
        auto size = image.size();
        std::vector<uchar> area;

        for (int i = 0; i < filter_size; ++i)
        {
            for (int j = 0; j < filter_size; ++j)
            {
                int dx = i - filter_size / 2;
                int dy = j - filter_size / 2;
                if (x + dx < 0 || x + dx >= size.width ||
                    y + dy < 0 || y + dy >= size.height)
                    continue;
                area.push_back(getPixel<uchar>(image, x + dx, y + dy));
            }
        }

        return filter(std::move(area));
    }

    cv::Mat Komissarov_Alexander_201732140_Task3::adaptiveBinary(cv::Mat grayimage, int filter_size, int c)
    {
        auto size = grayimage.size();
        auto result = cv::Mat(size, grayimage.type());

        for (int x = 0; x < size.width; ++x)
        {
            for (int y = 0; y < size.height; ++y)
            {
                auto value = getPixel<uchar>(grayimage, x, y);
                auto threshold = calcAdaptiveThreshold(grayimage, filter_size, x, y, [](std::vector<uchar> &&v)
                {
                    float sum = 0;
                    for (auto &val : v)
                        sum += val;
                    return sum / v.size();
                });
                setPixel<uchar>(result, x, y, value > threshold - c ? 255 : 0);
            }
        }

        return result;
    }

    Komissarov_Alexander_201732140_Task3::Komissarov_Alexander_201732140_Task3() : Task3(true) { }

    Komissarov_Alexander_201732140_Task3::Komissarov_Alexander_201732140_Task3(bool verbose) : Task3(verbose) { }

    int Komissarov_Alexander_201732140_Task3::variant()
    {
        return 201732140;
    }

    std::string Komissarov_Alexander_201732140_Task3::getFirstName()
    {
        return "Александр";
    }

    std::string Komissarov_Alexander_201732140_Task3::getSecondName()
    {
        return "Комиссаров";
    }
}
