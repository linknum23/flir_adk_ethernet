#ifndef FLIR_BOSON_ETHERNET_TIMESYNCHRONIZER_H
#define FLIR_BOSON_ETHERNET_TIMESYNCHRONIZER_H

// C++ Includes
#include <string>

// Linux system includes
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <asm/types.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/videodev2.h>

// ROS Includes
#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include <std_msgs/Time.h>

using namespace std;

namespace flir_boson_ethernet 
{

class TimeSynchronizer : public nodelet::Nodelet
{
  public:
    TimeSynchronizer();
    ~TimeSynchronizer();

  private:
    virtual void onInit();
    void publishTime(const ros::TimerEvent& evt);

    ros::NodeHandle _nh, _pnh;
    ros::Timer _timer;
    float _frameRate;
    ros::Publisher _publisher;
};

}


#endif