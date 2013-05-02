#!/usr/bin/env sh
# generated from catkin/cmake/templates/env.sh.in

if [ $# -eq 0 ] ; then
  /bin/echo "Entering environment at '/nishome/gcerna/ros/rosbuild_ws/taskallocator/build/devel', type 'exit' to leave"
  . "/nishome/gcerna/ros/rosbuild_ws/taskallocator/build/devel/setup.sh"
  "$SHELL" -i
  /bin/echo "Exiting environment at '/nishome/gcerna/ros/rosbuild_ws/taskallocator/build/devel'"
else
  . "/nishome/gcerna/ros/rosbuild_ws/taskallocator/build/devel/setup.sh"
  exec "$@"
fi
