// Generated by gencpp from file dji_sdk/Gimbal.msg
// DO NOT EDIT!


#ifndef DJI_SDK_MESSAGE_GIMBAL_H
#define DJI_SDK_MESSAGE_GIMBAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace dji_sdk
{
template <class ContainerAllocator>
struct Gimbal_
{
  typedef Gimbal_<ContainerAllocator> Type;

  Gimbal_()
    : header()
    , ts(0)
    , mode(0)
    , yaw(0.0)
    , pitch(0.0)
    , roll(0.0)  {
    }
  Gimbal_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , ts(0)
    , mode(0)
    , yaw(0.0)
    , pitch(0.0)
    , roll(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int32_t _ts_type;
  _ts_type ts;

   typedef uint8_t _mode_type;
  _mode_type mode;

   typedef float _yaw_type;
  _yaw_type yaw;

   typedef float _pitch_type;
  _pitch_type pitch;

   typedef float _roll_type;
  _roll_type roll;




  typedef boost::shared_ptr< ::dji_sdk::Gimbal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dji_sdk::Gimbal_<ContainerAllocator> const> ConstPtr;

}; // struct Gimbal_

typedef ::dji_sdk::Gimbal_<std::allocator<void> > Gimbal;

typedef boost::shared_ptr< ::dji_sdk::Gimbal > GimbalPtr;
typedef boost::shared_ptr< ::dji_sdk::Gimbal const> GimbalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dji_sdk::Gimbal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dji_sdk::Gimbal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dji_sdk

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'dji_sdk': ['/home/ubuntu/catkin_ws/src/dji_sdk/dji_sdk/msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::Gimbal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::Gimbal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::Gimbal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::Gimbal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::Gimbal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::Gimbal_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dji_sdk::Gimbal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e914fc54aeccbeb342557d4bb7efa016";
  }

  static const char* value(const ::dji_sdk::Gimbal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe914fc54aeccbeb3ULL;
  static const uint64_t static_value2 = 0x42557d4bb7efa016ULL;
};

template<class ContainerAllocator>
struct DataType< ::dji_sdk::Gimbal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dji_sdk/Gimbal";
  }

  static const char* value(const ::dji_sdk::Gimbal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dji_sdk::Gimbal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
# ts is the time it takes to achieve the desired angle,\n\
# so the shorter the time, the faster the gimbal rotates.\n\
int32 ts        # sec\n\
\n\
# Mode is 1 byte size:\n\
# Bit #:      | Set to 0:                             | Set to 1:\n\
# ----------- | ------------------------------------- | -------------------------------------\n\
# bit 0       | Incremental control,                  | Absolute control,\n\
#             | the angle reference is the            | the angle reference is\n\
#             | current Gimbal location               | related to configuration in DJI Go App\n\
# bit 1       | Gimbal will follow the command in Yaw | Gimbal will maintain position in Yaw\n\
# bit 2       | Roll invalid bit, the same as bit[1]  | Roll invalid bit, the same as bit[1]\n\
# bit 3       |Pitch invalid bit, the same as bit[1]  | Pitch invalid bit, the same as bit[1]\n\
# bit [4:7]   | bit [4:7]: reserved, set to be 0      |\n\
uint8 mode\n\
float32 yaw     # rads\n\
float32 pitch   # rads\n\
float32 roll    # rads\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::dji_sdk::Gimbal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dji_sdk::Gimbal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.ts);
      stream.next(m.mode);
      stream.next(m.yaw);
      stream.next(m.pitch);
      stream.next(m.roll);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Gimbal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dji_sdk::Gimbal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dji_sdk::Gimbal_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "ts: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ts);
    s << indent << "mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.mode);
    s << indent << "yaw: ";
    Printer<float>::stream(s, indent + "  ", v.yaw);
    s << indent << "pitch: ";
    Printer<float>::stream(s, indent + "  ", v.pitch);
    s << indent << "roll: ";
    Printer<float>::stream(s, indent + "  ", v.roll);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DJI_SDK_MESSAGE_GIMBAL_H
