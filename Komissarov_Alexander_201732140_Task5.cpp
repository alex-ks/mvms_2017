#include "Komissarov_Alexander_201732140_Task5.h"
#include <stdexcept>
#include <cassert>

namespace mvms_2017
{
    inline float get_component(cv::Point3f point, int i)
    {
        switch (i)
        {
        case 0:
            return point.x;
        case 1:
            return point.y;
        case 2:
            return point.z;
        case 3:
            return 1;
        default:
            assert(false && "Index out of range");
            return -1;
        }
    }

    cv::Mat Komissarov_Alexander_201732140_Task5::getProjectionMatrix(std::vector<cv::Point2i> img_pts, std::vector<cv::Point3f> real_pts)
    {
        const int count = 6;
        cv::Mat left = cv::Mat(count * 2, count * 2, CV_32F);
        for (int i = 0; i < count; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                left.at<float>(2 * i, j) = 0;
                left.at<float>(2 * i, j + 4) = -get_component(real_pts[i], j);
                left.at<float>(2 * i, j + 8) = img_pts[i].y * get_component(real_pts[i], j);
                left.at<float>(2 * i + 1, j) = get_component(real_pts[i], j);
                left.at<float>(2 * i + 1, j + 4) = 0;
                left.at<float>(2 * i + 1, j + 8) = -img_pts[i].x * get_component(real_pts[i], j);
            }
        }

        cv::Mat result;
        cv::SVD::solveZ(left, result);
        result = result.reshape(0, 3);

        auto point = real_pts.back();
        cv::Mat scale = result.row(2) * (cv::Mat_<float>(4, 1) << point.x, point.y, point.z, 1);
        return result / scale.at<float>(0, 0);
    }

    Komissarov_Alexander_201732140_Task5::Komissarov_Alexander_201732140_Task5() : Task5(true) { }

    Komissarov_Alexander_201732140_Task5::Komissarov_Alexander_201732140_Task5(bool verbose) : Task5(verbose) { }

    int Komissarov_Alexander_201732140_Task5::variant()
    {
        return 201732140;
    }

    std::string Komissarov_Alexander_201732140_Task5::getFirstName()
    {
        return "Александр";
    }

    std::string Komissarov_Alexander_201732140_Task5::getSecondName()
    {
        return "Комиссаров";
    }
}
