FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/taskallocator/msg"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "../msg_gen/cpp/include/taskallocator/Task.h"
  "../msg_gen/cpp/include/taskallocator/Bid.h"
  "../msg_gen/cpp/include/taskallocator/Request.h"
  "../msg_gen/cpp/include/taskallocator/Instruction.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
