#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
void getContours(Mat mask, Mat img,int color) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(mask, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	 
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		//cout << area << endl;

		if (area > 2000) 
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			//cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);
		
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 0), 2);
			putText(img, color?"green":"red", { 650,80 }, FONT_HERSHEY_PLAIN,6, Scalar(255, 0, 0), 5);
		}
	}
}
int main() {
	int hminr = 160, sminr = 130, vminr = 199;
	int hmaxr = 179, smaxr = 201, vmaxr = 255;
	int hming = 65, sming = 203, vming = 152;
	int hmaxg = 89, smaxg = 255, vmaxg = 210;

	string path = "../resources/TrafficLight.mp4";
	VideoCapture cap(path);
	Mat img;//=imread(path);
	// namedWindow("Trackbars", (640, 200));
	// createTrackbar("Hue Min", "Trackbars", &hming, 179);
	// createTrackbar("Hue Max", "Trackbars", &hmaxg, 179);
	// createTrackbar("Sat Min", "Trackbars", &sming, 255);
	// createTrackbar("Sat Max", "Trackbars", &smaxg, 255);
	// createTrackbar("Val Min", "Trackbars", &vming, 255);
	// createTrackbar("Val Max", "Trackbars", &vmaxg, 255);
	string filename="result.avi";
	int fourcc = VideoWriter::fourcc('X','V','I','D');
	int frame_width=static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
	int frame_height=static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));
	double fps=25.0;
	VideoWriter out(filename,fourcc,fps,Size(frame_width,frame_height),true);
	while (true) {

		cap.read(img);
		if(img.empty())break;
		Mat imgHSV, maskred,maskgreen;
		cvtColor(img, imgHSV, COLOR_BGR2HSV);
		
		
		Scalar lowerr(hminr, sminr, vminr);
		Scalar upperr(hmaxr, smaxr, vmaxr);
		Scalar lowerg(hming, sming, vming);
		Scalar upperg(hmaxg, smaxg, vmaxg);
		inRange(imgHSV, lowerr, upperr, maskred);
		inRange(imgHSV, lowerg, upperg, maskgreen);
		//imshow("Image", img);
		//imshow("Image HSV", imgHSV);
		
		getContours(maskred, img,0);
		getContours(maskgreen, img,1);
		out<<img;
		imshow("Image", img);
		//imshow("Image Mask", maskred);
		imshow("Image Mask", maskgreen);
		waitKey(100);
	}
	

}
