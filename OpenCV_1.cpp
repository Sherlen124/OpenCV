#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;


int main()
{
    Mat original_image = imread("image.jpg");          // Вывод оригинального изображения  
    if (original_image.empty())                        // Проверка на наличие сбоя
    {
        cout << "Could not open or find the image" << endl;
        cin.get();                                     // дождитесь любого нажатия клавиши
        return -1;
    }
    namedWindow("Original_Picture");                   // Создание окна
    imshow("Original_Picture", original_image);        // Показ изображения внутри окна
    waitKey(0);                                        // Ожидание нажатия любой клавиши

    Mat gray_image;                                    // Вывод ЧБ изображения
    cvtColor(original_image, gray_image, COLOR_RGB2GRAY);
    namedWindow("Gray_Picture");
    imshow("Gray_Picture", gray_image);
    imwrite("Gray_Picture.jpg", gray_image);
    waitKey(0);

    Mat blured;                                        // Вывод изображения размытие по Гауссу
    GaussianBlur(original_image, blured, Size(51, 51), 0);
    namedWindow("GaussianBlur_Picture");
    imshow("GaussianBlur_Picture", blured);
    imwrite("GaussianBlur_Picture.jpg", blured);
    waitKey(0);

    Mat Сanny, edge, draw;                             // Выделение контуров на изображении
    cvtColor(original_image, Сanny, COLOR_RGB2GRAY);
    Canny(Сanny, edge, 20, 100, 3);
    edge.convertTo(draw, CV_8U);
    namedWindow("Сanny_Picture");
    imshow("Сanny_Picture", draw);
    imwrite("Сanny_Picture.jpg", draw);
    waitKey(0);

    Mat negative;                                      // Вывод инвертного/негативного изображения
    bitwise_not(original_image, negative);
    namedWindow("Negative_Picture");
    imshow("Negative_Picture", negative);
    imwrite("Negative_Picture.jpg", negative);
    waitKey(0);

    Mat enlarged;                                      // Вывод увеличенного изображения
    pyrUp(original_image, enlarged);
    namedWindow("Enlarged_Picture");
    imshow("Enlarged_Picture", enlarged);
    imwrite("Enlarged_Picture.jpg", enlarged);
    waitKey(0);

    Mat hsv;                                           // Трансформация цветового пространства (HSV) - изменение оттенка
    cvtColor(original_image, hsv, COLOR_BGR2HSV);
    namedWindow("HSV_Picture");
    imshow("HSV_Picture", hsv);
    imwrite("HSV_Picture.jpg", hsv);
    waitKey(0);

    destroyAllWindows();                               // Удаление всех окон
    return 0;

}