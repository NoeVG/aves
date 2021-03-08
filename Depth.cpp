#include <opencv2/opencv.hpp>

//Include the librealsense C++ header file
#include <librealsense/rs.hpp>
#include <cstdio>


#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) try{
    cout<<"Hello again C++"<<endl;

    /* Create a context object. This object owns
    the handles to all connected realsense devices. */
    rs::context ctx;
    printf("There are %d connected RealSense devices.\n", ctx.get_device_count());
    if(ctx.get_device_count() == 0) return EXIT_FAILURE;


    /* This tutorial will access only a single device,
     but it is trivial to extend to multiple devices
    */
    rs::device * dev = ctx.get_device(0);
    printf("\n Using device 0, an %s\n", dev->get_name());
    printf("    Serial number: %s\n", dev->get_serial());
    printf("    Firmware version: %s\n", dev->get_firmware_version());



    // Configure depth to run at VGA resolution at 60 frames per second

    dev->enable_stream(rs::stream::color, 640, 480, rs::format::bgr8, 60);
    dev->enable_stream(rs::stream::depth, 640, 480, rs::format::z16, 60);


    dev->start();

    // Determine depth value corresponding to one meter = 1.0f
    const uint16_t one_meter = static_cast<uint16_t>( 1.5f / dev->get_depth_scale() );

    float scale = dev->get_depth_scale();

    // Create Mat to opencv

    Mat rgb(Size(640, 480), CV_8UC3, (void*)dev->get_frame_data(rs::stream::color));
    Mat depth = Mat::zeros(Size(640, 480), CV_16U );;
    Mat depth_box = Mat::zeros(Size(640, 480), CV_16U );;

    Mat depth_(Size(640, 480), CV_8UC1);
    Mat depth_Box(Size(640, 480), CV_8UC1);
    for (int i = 0; i < 30;i++)
      dev->wait_for_frames();

    while(true){
        /* This call waits until a new coherent set of frames is available on a device
         Calls to get_frame_data(...) and get_frame_timestamp(...) on a device will
          return stable values until wait_for_frames(...) is called
        */

        dev->wait_for_frames();

        cout<<"Scale value: "<<scale<<endl;
        cout<<"One meter: "<<one_meter<<endl;

        //rgb.data = (unsigned char*)dev->get_frame_data(rs::stream::color);
        //depth.data = (unsigned char*)dev->get_frame_data(rs::stream::depth);
        rgb.data = (unsigned char*)dev->get_frame_data(rs::stream::color);
        const uint16_t * depth_frame = reinterpret_cast<const uint16_t *>(dev->get_frame_data(rs::stream::depth));

        for(int r=0; r<depth.rows; r++){
          for(int c=0; c<depth.cols; c++){
            int depthPixel = *depth_frame++;
            if( (depthPixel) < one_meter){
              depth_box.at<uint16_t>(r,c) = depthPixel;
            }
            depth.at<uint16_t>(r,c) = depthPixel;
          }
        }

        depth_Box = depth_box.clone();
        depth_Box.convertTo(depth_Box, CV_8UC3,16/256.0 );
        cv::normalize(depth_Box, depth_Box,100, 255,cv::NORM_MINMAX);
        cv::equalizeHist( depth_Box, depth_Box );

        depth_ = depth.clone();
        depth_.convertTo(depth_, CV_8UC3,16/256.0 );
        /*
        cv::normalize(depth_, depth_,150, 255,cv::NORM_MINMAX);
        cv::equalizeHist( depth_, depth_ );
        */

        /*
        depth.data = (unsigned char*)dev->get_frame_data(rs::stream::depth);
        depth_ = depth.clone();
        depth_.convertTo(depth_, CV_8UC3,16/256.0 ); // convert the image data to float type
        cv::normalize(depth_, depth_,0, 255,cv::NORM_MINMAX);
        */
        cv::normalize(depth_Box, depth_Box,110, 254,cv::NORM_MINMAX);
        //cv::normalize(depth_Box, depth_Box,180, 255,cv::NORM_MINMAX);

        GaussianBlur(depth_Box, depth_Box, Size(3,3), 8);
        cv::medianBlur(depth_Box, depth_Box, 5);


        imshow("RGB image", rgb);
        imshow("Depth_ image", depth_);
        imshow("Depth_Face ", depth_Box);

        if(waitKey(1)==27)
          return EXIT_SUCCESS;
      }
  return EXIT_SUCCESS;
}catch(const rs::error & e)
{
    /* Method calls against librealsense
       objects may throw exceptions of type rs::error */
    printf("rs::error was thrown when calling %s(%s):\n", e.get_failed_function().c_str(), e.get_failed_args().c_str());
    printf("    %s\n", e.what());
    return EXIT_FAILURE;
}
