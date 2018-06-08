// Generated by gencpp from file dji_sdk/MissionHpActionRequest.msg
// DO NOT EDIT!


#ifndef DJI_SDK_MESSAGE_MISSIONHPACTIONREQUEST_H
#define DJI_SDK_MESSAGE_MISSIONHPACTIONREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace dji_sdk
{
template <class ContainerAllocator>
struct MissionHpActionRequest_
{
  typedef MissionHpActionRequest_<ContainerAllocator> Type;

  MissionHpActionRequest_()
    : action(0)  {
    }
  MissionHpActionRequest_(const ContainerAllocator& _alloc)
    : action(0)  {
  (void)_alloc;
    }



   typedef uint8_t _action_type;
  _action_type action;


    enum { ACTION_START = 0u };
     enum { ACTION_STOP = 1u };
     enum { ACTION_PAUSE = 2u };
     enum { ACTION_RESUME = 3u };
 

  typedef boost::shared_ptr< ::dji_sdk::MissionHpActionRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dji_sdk::MissionHpActionRequest_<ContainerAllocator> const> ConstPtr;

}; // struct MissionHpActionRequest_

typedef ::dji_sdk::MissionHpActionRequest_<std::allocator<void> > MissionHpActionRequest;

typedef boost::shared_ptr< ::dji_sdk::MissionHpActionRequest > MissionHpActionRequestPtr;
typedef boost::shared_ptr< ::dji_sdk::MissionHpActionRequest const> MissionHpActionRequestConstPtr;

// constants requiring out of line definition

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dji_sdk::MissionHpActionRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dji_sdk::MissionHpActionRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dji_sdk

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'dji_sdk': ['/home/ubuntu/catkin_ws/src/dji_sdk/dji_sdk/msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::MissionHpActionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::MissionHpActionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::MissionHpActionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::MissionHpActionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::MissionHpActionRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::MissionHpActionRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dji_sdk::MissionHpActionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9a315a349430cf3517f19b4b74966b6c";
  }

  static const char* value(const ::dji_sdk::MissionHpActionRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9a315a349430cf35ULL;
  static const uint64_t static_value2 = 0x17f19b4b74966b6cULL;
};

template<class ContainerAllocator>
struct DataType< ::dji_sdk::MissionHpActionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dji_sdk/MissionHpActionRequest";
  }

  static const char* value(const ::dji_sdk::MissionHpActionRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dji_sdk::MissionHpActionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
uint8 ACTION_START  = 0\n\
uint8 ACTION_STOP   = 1\n\
uint8 ACTION_PAUSE  = 2\n\
uint8 ACTION_RESUME = 3\n\
\n\
\n\
uint8 action\n\
";
  }

  static const char* value(const ::dji_sdk::MissionHpActionRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dji_sdk::MissionHpActionRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.action);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MissionHpActionRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dji_sdk::MissionHpActionRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dji_sdk::MissionHpActionRequest_<ContainerAllocator>& v)
  {
    s << indent << "action: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.action);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DJI_SDK_MESSAGE_MISSIONHPACTIONREQUEST_H
