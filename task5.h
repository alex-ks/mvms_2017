#ifndef TASK5_H
#define TASK5_H

#include "commun_task.h"
/*!
 * Пространство имен, соответсвующее этому году
 */
namespace mvms_2017
{
class Task5 : public Commun_Task
{
public:
    Task5(bool verbose);
    //
    /*!
     * \brief getProjectionMatrix По 6 парам точек написать алгоритм вычисления матрицы проекции
     * \param img_pts точки на плоскости изображения
     * \param real_pts точки в 3Д пространстве в С.К. камеры
     * \return матрица проекции
     */
    virtual cv::Mat getProjectionMatrix(std::vector<cv::Point2i> img_pts,std::vector<cv::Point3f> real_pts);

    /*!
     * \brief calibrateCamera Калибровка камеры методами OpenCV на вход серия изображений шахматной доски, на выход координаты камеры в С.К. доски. Нарисовать оси С.К. доски на изображении.
     * \param images калибровочные изображения
     * \param w количество узлов доски по ширине
     * \param h количество узло доски по высоте
     * \param step шаг
     * \param test проверочное изображение доски на котором надо нарисовать систему координат
     * \return тестовое изображение с нарисованной С.К.
     */
    cv::Mat calibrateCamera(std::vector<cv::Mat> images,int w,int h,float step,cv::Mat test);
    /*!
     * \brief raysIntersection Алгоритм нахождения пересечения двух лучей в 3Д пространстве
     * \param pt1 точка 1
     * \param ray1 луч 1
     * \param pt2 точка 2
     * \param ray2 луч 2
     * \return точка пересечения
     */
    cv::Point3f raysIntersection(cv::Point3f pt1,cv::Point3f ray1,cv::Point3f pt2,cv::Point3f ray2);

    /*!
     * \brief correctLensDistorsions Алгоритм коррекции дисторсии линзы по коэффициентам r2,r4, k1, k2
     * \param image изображение
     * \param r2 коэфициент
     * \param r4 коэфициент
     * \param k1 коэфициент
     * \param k2 коэфициент
     * \return изображение после корректировки действия линз
     */
    cv::Mat correctLensDistorsions(cv::Mat image,double r2,double r4,double k1,double k2);
    //
    /*!
     * \brief getTransform Реализовать переход между двумя системами координат R1,t1 и R2,t2, чтобы определить точку, заданную в системе координат 1 в точку в системе координат 2
     * \param R1 матрица поворота 1ой камеры в С.К. О
     * \param t1 вектор смещения 1ой камеры
     * \param R2 матрица поворота 2ой камеры в С.К. О
     * \param t2 вектор смещения 2ой камеры
     * \return Матрица преобразования 3x4
     */
    cv::Mat getTransform(cv::Mat R1,cv::Mat t1,cv::Mat R2,cv::Mat t2);

    /*!
     * \brief calcOpticalFlow Вычислить оптический поток между двумя кадрами методами opencv, построить фундаментальную матрицу для данных двух кадров. (функциями opencv)
     * \param image1 Первое изображение
     * \param image2 Второе изображение
     * \param mindistance минимальное растояние между двумя точками
     * \return пары точек связанных уравнением оптического потока
     */
    std::vector<std::pair<cv::Point2i,cv::Point2i> > calcOpticalFlow(cv::Mat image1,cv::Mat image2,float mindistance);
};
}

#endif // TASK5_H
