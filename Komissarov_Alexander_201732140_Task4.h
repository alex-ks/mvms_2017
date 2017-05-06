#pragma once
#include "task4.h"

namespace mvms_2017
{
    class Komissarov_Alexander_201732140_Task4 : public Task4
    {
    public:
        Komissarov_Alexander_201732140_Task4();
        Komissarov_Alexander_201732140_Task4(bool verbose);

        int variant() override;
        std::string getFirstName() override;
        std::string getSecondName() override;

        cv::Mat brief(cv::Mat grayimage, 
                      std::vector<cv::Point2i> pts, 
                      std::vector<std::pair<cv::Point2i, cv::Point2i>> pattern);
    };
}
