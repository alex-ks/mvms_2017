#pragma once
#include "task5.h"

namespace mvms_2017
{
    class Komissarov_Alexander_201732140_Task5 : public Task5
    {
    public:
        Komissarov_Alexander_201732140_Task5();
        Komissarov_Alexander_201732140_Task5(bool verbose);

        cv::Mat getProjectionMatrix(std::vector<cv::Point2i> img_pts, std::vector<cv::Point3f> real_pts);

        int variant() override;
        std::string getFirstName() override;
        std::string getSecondName() override;
    };
}
