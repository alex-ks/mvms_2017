#include "Komissarov_Alexander_201732140_Task5.h"

#include <iostream>

using std::cout;
using std::endl;

static void print_mat(cv::Mat matrix)
{
    auto size = matrix.size();
    for (int row = 0; row < size.height; ++row)
    {
        for (int column = 0; column < size.width; ++column)
        {
            std::cout << matrix.at<float>(row, column) << ' ';
        }
        std::cout << std::endl;
    }
}

cv::Mat projectPoints(cv::Mat camera_mat, std::vector<cv::Point3f> &real_points, bool verbose = false)
{
    cv::Mat world_points(real_points.size(), 3, CV_32FC1, real_points.data());
    cv::hconcat(world_points, cv::Mat::ones(real_points.size(), 1, CV_32FC1), world_points);
    
    if (verbose)
    {
        cout << "World points" << endl;
        print_mat(cv::Mat(world_points));
    }

    return (camera_mat * world_points.t()).t();
}

template <typename T>
std::vector<cv::Point_<T>> matToPoints(cv::Mat projected)
{
    std::vector<cv::Point_<T>> img_points;

    for (int i = 0; i < projected.rows; ++i)
    {
        img_points.push_back(
        { 
            (T)(projected.at<float>(i, 0) / projected.at<float>(i, 2)), 
            (T)(projected.at<float>(i, 1) / projected.at<float>(i, 2))
        });
    }

    return std::move(img_points);
}

template <typename T>
void printPoints(const std::vector<cv::Point_<T>> &img_points)
{
    for (auto point : img_points)
    {
        cout << "{ x: " << point.x << ", y: " << point.y << " }" << endl;
    }
}

int main(int argc, char *argv[])
{
    try
	{
        mvms_2017::Komissarov_Alexander_201732140_Task5 task5;
		auto pict = cv::imread("pict3.png");
		auto size = pict.size();

        std::vector<cv::Point3f> real_points = { {1, 1, 1}, {1, 2, 0}, {-1, 0, 0}, {2, 1, 2}, {-1, -1, 5}, {2, 2, 6} };
        cv::Mat camera_mat(cv::Matx<float, 3, 4>
        { 
            1, 0, 0.1f, 0, 
            0, 1, 0, 0,
            0, 0, 0, 1
        });
        cout << "Camera mat" << endl;
        print_mat(cv::Mat(camera_mat));

        auto projected = projectPoints(camera_mat, real_points);
        cout << "Projected" << endl;
        print_mat(cv::Mat(projected));

        auto img_points = matToPoints<int>(projected);

        cout << "Image points" << endl;
        printPoints(img_points);

        auto result = task5.getProjectionMatrix(img_points, real_points);

        cv::Mat diff;
        cv::absdiff(camera_mat, result, diff);

        if (cv::sum(diff)[0] < 1.)
            cout << "True" << endl;
        else
            cout << "False" << endl;

        cout << "Rebuilt camera mat" << endl;
        print_mat(result);

        auto projected_again = projectPoints(result, real_points);
        cout << "Projected again mat" << endl;
        print_mat(projected_again);
        auto img_points2 = matToPoints<int>(projected_again);
        printPoints(img_points2);
        system("pause");
    }
    catch (const std::exception &ex)
	{
        std::cout << ex.what() << std::endl;
		system("pause");
    }

    return 0;
}
