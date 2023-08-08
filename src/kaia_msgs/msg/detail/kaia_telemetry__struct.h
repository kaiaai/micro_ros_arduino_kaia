// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kaia_msgs:msg/KaiaTelemetry.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "kaia_msgs/msg/kaia_telemetry.h"


#ifndef KAIA_MSGS__MSG__DETAIL__KAIA_TELEMETRY__STRUCT_H_
#define KAIA_MSGS__MSG__DETAIL__KAIA_TELEMETRY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'joint_pos'
// Member 'joint_vel'
// Member 'lds'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/KaiaTelemetry in the package kaia_msgs.
typedef struct kaia_msgs__msg__KaiaTelemetry
{
  builtin_interfaces__msg__Time stamp;
  uint32_t seq;
  float odom_pos_x;
  float odom_pos_y;
  float odom_pos_yaw;
  float odom_vel_x;
  float odom_vel_yaw;
  rosidl_runtime_c__float__Sequence joint_pos;
  rosidl_runtime_c__float__Sequence joint_vel;
  rosidl_runtime_c__uint8__Sequence lds;
} kaia_msgs__msg__KaiaTelemetry;

// Struct for a sequence of kaia_msgs__msg__KaiaTelemetry.
typedef struct kaia_msgs__msg__KaiaTelemetry__Sequence
{
  kaia_msgs__msg__KaiaTelemetry * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kaia_msgs__msg__KaiaTelemetry__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KAIA_MSGS__MSG__DETAIL__KAIA_TELEMETRY__STRUCT_H_
