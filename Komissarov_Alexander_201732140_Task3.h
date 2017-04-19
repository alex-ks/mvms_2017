#pragma once
#include "task3.h"

namespace mvms_2017
{
    class Komissarov_Alexander_201732140_Task3 : public Task3
    {
    private:

    public:
        Komissarov_Alexander_201732140_Task3();
        Komissarov_Alexander_201732140_Task3(bool verbose);

        int variant() override;
        std::string getFirstName() override;
        std::string getSecondName() override;

        cv::Mat adaptiveBinary(cv::Mat grayimage, int filter_size, int c);
    };
}
