#include "Komissarov_Alexander_201732140_Task4.h"

namespace mvms_2017
{
    using std::vector;
    using std::pair;

    cv::Mat Komissarov_Alexander_201732140_Task4::brief(cv::Mat grayimage, 
                                                        vector<cv::Point2i> pts, 
                                                        vector<pair<cv::Point2i, cv::Point2i>> pattern)
    {
        cv::Mat blurred;
        cv::GaussianBlur(grayimage, blurred, cv::Size(3, 3), 0);
        auto size = blurred.size();

        cv::Mat result(pts.size(), pattern.size(), CV_8U);
        
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
                    result.at<uchar>(i, j) = 1;
                else
                    result.at<uchar>(i, j) = 0;
            }
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
