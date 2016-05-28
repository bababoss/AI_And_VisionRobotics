#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <time.h>

using namespace cv;
using namespace std;

void CallBackFunc(int event, int x, int y, int flags, void* userdata);

Mat frame;
Mat imgGRAY;



  //wiringPiSetup () ;
  //pinMode (0, OUTPUT) ;
  
  //pinMode(GPIO1, OUTPUT);


int main()
{
    time_t start, end;

    VideoCapture cap(0); // open the video camera no. 0

    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the video cam" << endl;
        return -1;
    }
   
   //cap.set(CV_CAP_PROP_FPS , 30);
   //cap.set(CV_CAP_PROP_CONVERT_RGB , false);
   //cap.set(CV_CAP_PROP_FRAME_WIDTH, 320); 
   //cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240); 
   
   double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video


    //cout << "Frame size : " << dWidth << " x " << dHeight << endl;

    namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

    while (1)
    {
        //Mat frame;
        time(&start);
        bool bSuccess = cap.read(frame); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }
        //Mat imgGRAY;
        cvtColor(frame, imgGRAY, COLOR_BGR2GRAY); //Convert the captured frame from BGR to HSV
	
	//Mat imgThresholded;
		
	
        imshow("MyVideo",imgGRAY ); //show the frame in "MyVideo" window
        //set the callback function for any mouse event
         setMouseCallback("MyVideo", CallBackFunc, NULL);

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
       {
            cout << "esc key is pressed by user" << endl;
            break; 
       }
       time(&end);
       double seconds = difftime(end,start);
       cout <<"algorithum time = "<<seconds<<endl; 
    }
    return 0;

}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == EVENT_LBUTTONDOWN )
     {
          cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if  ( event == EVENT_RBUTTONDOWN )
     {
          cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if  ( event == EVENT_MBUTTONDOWN )
     {
          cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if ( event == EVENT_MOUSEMOVE )
     {
          cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;

     }
}