// Generated by gencpp from file dji_sdk/MissionWaypointTask.msg
// DO NOT EDIT!


#ifndef DJI_SDK_MESSAGE_MISSIONWAYPOINTTASK_H
#define DJI_SDK_MESSAGE_MISSIONWAYPOINTTASK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <dji_sdk/MissionWaypoint.h>

namespace dji_sdk
{
template <class ContainerAllocator>
struct MissionWaypointTask_
{
  typedef MissionWaypointTask_<ContainerAllocator> Type;

  MissionWaypointTask_()
    : velocity_range(0.0)
    , idle_velocity(0.0)
    , action_on_finish(0)
    , mission_exec_times(0)
    , yaw_mode(0)
    , trace_mode(0)
    , action_on_rc_lost(0)
    , gimbal_pitch_mode(0)
    , mission_waypoint()  {
    }
  MissionWaypointTask_(const ContainerAllocator& _alloc)
    : velocity_range(0.0)
    , idle_velocity(0.0)
    , action_on_finish(0)
    , mission_exec_times(0)
    , yaw_mode(0)
    , trace_mode(0)
    , action_on_rc_lost(0)
    , gimbal_pitch_mode(0)
    , mission_waypoint(_alloc)  {
  (void)_alloc;
    }



   typedef float _velocity_range_type;
  _velocity_range_type velocity_range;

   typedef float _idle_velocity_type;
  _idle_velocity_type idle_velocity;

   typedef uint8_t _action_on_finish_type;
  _action_on_finish_type action_on_finish;

   typedef uint8_t _mission_exec_times_type;
  _mission_exec_times_type mission_exec_times;

   typedef uint8_t _yaw_mode_type;
  _yaw_mode_type yaw_mode;

   typedef uint8_t _trace_mode_type;
  _trace_mode_type trace_mode;

   typedef uint8_t _action_on_rc_lost_type;
  _action_on_rc_lost_type action_on_rc_lost;

   typedef uint8_t _gimbal_pitch_mode_type;
  _gimbal_pitch_mode_type gimbal_pitch_mode;

   typedef std::vector< ::dji_sdk::MissionWaypoint_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::dji_sdk::MissionWaypoint_<ContainerAllocator> >::other >  _mission_waypoint_type;
  _mission_waypoint_type mission_waypoint;


    enum { FINISH_NO_ACTION = 0u };
     enum { FINISH_RETURN_TO_HOME = 1u };
     enum { FINISH_AUTO_LANDING = 2u };
     enum { FINISH_RETURN_TO_POINT = 3u };
     enum { FINISH_NO_EXIT = 4u };
     enum { YAW_MODE_AUTO = 0u };
     enum { YAW_MODE_LOCK = 1u };
     enum { YAW_MODE_RC = 2u };
     enum { YAW_MODE_WAYPOINT = 3u };
     enum { TRACE_POINT = 0u };
     enum { TRACE_COORDINATED = 1u };
     enum { ACTION_FREE = 0u };
     enum { ACTION_AUTO = 1u };
     enum { GIMBAL_PITCH_FREE = 0u };
     enum { GIMBAL_PITCH_AUTO = 1u };
 

  typedef boost::shared_ptr< ::dji_sdk::MissionWaypointTask_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dji_sdk::MissionWaypointTask_<ContainerAllocator> const> ConstPtr;

}; // struct MissionWaypointTask_

typedef ::dji_sdk::MissionWaypointTask_<std::allocator<void> > MissionWaypointTask;

typedef boost::shared_ptr< ::dji_sdk::MissionWaypointTask > MissionWaypointTaskPtr;
typedef boost::shared_ptr< ::dji_sdk::MissionWaypointTask const> MissionWaypointTaskConstPtr;

// constants requiring out of line definition

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dji_sdk::MissionWaypointTask_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dji_sdk::MissionWaypointTask_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dji_sdk

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'dji_sdk': ['/home/ubuntu/catkin_ws/src/dji_sdk/dji_sdk/msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::MissionWaypointTask_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::MissionWaypointTask_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::MissionWaypointTask_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::MissionWaypointTask_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::MissionWaypointTask_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::MissionWaypointTask_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dji_sdk::MissionWaypointTask_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c869e0f592c937d8202723285e6957d0";
  }

  static const char* value(const ::dji_sdk::MissionWaypointTask_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc869e0f592c937d8ULL;
  static const uint64_t static_value2 = 0x202723285e6957d0ULL;
};

template<class ContainerAllocator>
struct DataType< ::dji_sdk::MissionWaypointTask_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dji_sdk/MissionWaypointTask";
  }

  static const char* value(const ::dji_sdk::MissionWaypointTask_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dji_sdk::MissionWaypointTask_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# constant for action_on_finish\n\
uint8 FINISH_NO_ACTION       = 0  # no action\n\
uint8 FINISH_RETURN_TO_HOME  = 1  # return to home\n\
uint8 FINISH_AUTO_LANDING    = 2  # auto landing\n\
uint8 FINISH_RETURN_TO_POINT = 3  # return to point 0\n\
uint8 FINISH_NO_EXIT         = 4  # infinite mode， no exit\n\
\n\
# constant for yaw_mode\n\
uint8 YAW_MODE_AUTO     = 0       # auto mode (point to next waypoint)\n\
uint8 YAW_MODE_LOCK     = 1       # lock as an initial value\n\
uint8 YAW_MODE_RC       = 2       # controlled by RC\n\
uint8 YAW_MODE_WAYPOINT = 3       # use waypoint's yaw(tgt_yaw)\n\
\n\
# constant for trace_mode\n\
uint8 TRACE_POINT       = 0       # point to point, after reaching the target waypoint hover, complete waypt action (if any), then fly to the next waypt\n\
uint8 TRACE_COORDINATED = 1       # 1: Coordinated turn mode, smooth transition between waypts, no waypts task\n\
\n\
# constants for action_on_rc_lost\n\
uint8 ACTION_FREE       = 0       # exit waypoint and failsafe\n\
uint8 ACTION_AUTO       = 1       # continue the waypoint\n\
\n\
# constants for gimbal_pitch_mode\n\
uint8 GIMBAL_PITCH_FREE = 0       # free mode, no control on gimbal\n\
uint8 GIMBAL_PITCH_AUTO = 1       # auto mode, Smooth transition between waypoints on gimbal\n\
\n\
float32 velocity_range    # Maximum speed joystick input(2~15m)\n\
float32 idle_velocity     # Cruising Speed (without joystick input, no more than vel_cmd_range)\n\
uint8 action_on_finish    # See constants above for possible actions\n\
uint8 mission_exec_times  # 1: once ; 2: twice\n\
uint8 yaw_mode            # see constants above for possible yaw modes\n\
uint8 trace_mode          # see constants above for possible trace modes\n\
uint8 action_on_rc_lost   # see constants above for possible actions\n\
uint8 gimbal_pitch_mode   # see constants above for pissible gimbal modes\n\
MissionWaypoint[] mission_waypoint  # a vector of waypoints\n\
\n\
\n\
================================================================================\n\
MSG: dji_sdk/MissionWaypoint\n\
float64 latitude          # degree\n\
float64 longitude         # degree\n\
float32 altitude          # relative altitude from takeoff point\n\
float32 damping_distance  # Bend length (effective coordinated turn mode only)\n\
int16 target_yaw          # Yaw (degree)\n\
int16 target_gimbal_pitch # Gimbal pitch\n\
uint8 turn_mode           # 0: clockwise, 1: counter-clockwise\n\
uint8 has_action          # 0: no, 1: yes\n\
uint16 action_time_limit\n\
MissionWaypointAction waypoint_action\n\
\n\
================================================================================\n\
MSG: dji_sdk/MissionWaypointAction\n\
# action_repeat\n\
# lower 4 bit: Total number of actions\n\
# hight 4 bit: Total running times\n\
uint8 action_repeat\n\
uint8[16] command_list\n\
uint16[16] command_parameter\n\
";
  }

  static const char* value(const ::dji_sdk::MissionWaypointTask_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dji_sdk::MissionWaypointTask_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.velocity_range);
      stream.next(m.idle_velocity);
      stream.next(m.action_on_finish);
      stream.next(m.mission_exec_times);
      stream.next(m.yaw_mode);
      stream.next(m.trace_mode);
      stream.next(m.action_on_rc_lost);
      stream.next(m.gimbal_pitch_mode);
      stream.next(m.mission_waypoint);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MissionWaypointTask_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dji_sdk::MissionWaypointTask_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dji_sdk::MissionWaypointTask_<ContainerAllocator>& v)
  {
    s << indent << "velocity_range: ";
    Printer<float>::stream(s, indent + "  ", v.velocity_range);
    s << indent << "idle_velocity: ";
    Printer<float>::stream(s, indent + "  ", v.idle_velocity);
    s << indent << "action_on_finish: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.action_on_finish);
    s << indent << "mission_exec_times: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.mission_exec_times);
    s << indent << "yaw_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.yaw_mode);
    s << indent << "trace_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.trace_mode);
    s << indent << "action_on_rc_lost: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.action_on_rc_lost);
    s << indent << "gimbal_pitch_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gimbal_pitch_mode);
    s << indent << "mission_waypoint[]" << std::endl;
    for (size_t i = 0; i < v.mission_waypoint.size(); ++i)
    {
      s << indent << "  mission_waypoint[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::dji_sdk::MissionWaypoint_<ContainerAllocator> >::stream(s, indent + "    ", v.mission_waypoint[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // DJI_SDK_MESSAGE_MISSIONWAYPOINTTASK_H
