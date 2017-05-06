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

        cv::Mat result(pts.size(), pattern.size(), CV_8U);
        
        for (int i = 0; i < pts.size(); ++i)
        {
            for (int j = 0; j < pattern.size(); ++j)
            {
                auto p1 = pts[i] + pattern[j].first;
                auto p2 = pts[i] + pattern[j].second;

                if (!(0 <= p1.x && p1.x < pts.size()
                    && 0 <= p1.y && p1.y < pattern.size()))
                    p1 = pts[i];

                if (!(0 <= p2.x && p2.x < pts.size()
                    && 0 <= p2.y && p2.y < pattern.size()))
                    p2 = pts[i];

                if (blurred.at<uchar>(pts[i] + pattern[j].first) < blurred.at<uchar>(pts[i] + pattern[j].second))
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
