FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/taskallocator/msg"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/taskallocator/msg/__init__.py"
  "../src/taskallocator/msg/_Bid.py"
  "../src/taskallocator/msg/_Request.py"
  "../src/taskallocator/msg/_Instruction.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
