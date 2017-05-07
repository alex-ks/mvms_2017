#include "Komissarov_Alexander_201732140_Task4.h"
#include <cmath>

namespace mvms_2017
{
    using std::vector;
    using std::pair;

    static const int BYTE_SIZE = 8;

    cv::Mat Komissarov_Alexander_201732140_Task4::brief(cv::Mat grayimage, 
                                                        vector<cv::Point2i> pts, 
                                                        vector<pair<cv::Point2i, cv::Point2i>> pattern)
    {
        cv::Mat blurred;
        cv::GaussianBlur(grayimage, blurred, cv::Size(3, 3), 0);
        auto size = blurred.size();

        auto column_count = pattern.size() % BYTE_SIZE == 0 ? 
                            pattern.size() / BYTE_SIZE : 
                            pattern.size() / BYTE_SIZE + 1;
        auto rest = pattern.size() % BYTE_SIZE;

        cv::Mat result(pts.size(), column_count, CV_8U);
        uchar byte = 0;
        
        for (int i = 0; i < pts.size(); ++i)
        {
            for (int j = 0; j < pattern.size(); ++j)
            {
                auto p1 = pts[i] + pattern[j].first;
                auto p2 = pts[i] + pattern[j].second;

                if (!(0 <= p1.x && p1.x < size.width
                    && 0 <= p1.y && p1.y < size.height))
                    p1 = pts[i];

                if (!(0 <= p2.x && p2.x < size.width
                    && 0 <= p2.y && p2.y < size.height))
                    p2 = pts[i];

                if (blurred.at<uchar>(p1) < blurred.at<uchar>(p2))
                    byte = (byte << 1) + 1;
                else
                    byte <<= 1;

                if (j % BYTE_SIZE == BYTE_SIZE - 1)
                    result.at<uchar>(i, j / BYTE_SIZE) = byte;
            }

            if (rest != 0)
                result.at<uchar>(i, column_count - 1) = byte << (BYTE_SIZE - rest);
        }

        return std::move(result);
    }

    Komissarov_Alexander_201732140_Task4::Komissarov_Alexander_201732140_Task4() : Task4(true) { }

    Komissarov_Alexander_201732140_Task4::Komissarov_Alexander_201732140_Task4(bool verbose) : Task4(verbose) { }

    int Komissarov_Alexander_201732140_Task4::variant()
    {
        return 201732140;
    }

    std::string Komissarov_Alexander_201732140_Task4::getFirstName()
    {
        return "Александр";
    }

    std::string Komissarov_Alexander_201732140_Task4::getSecondName()
    {
        return "Комиссаров";
    }
}
