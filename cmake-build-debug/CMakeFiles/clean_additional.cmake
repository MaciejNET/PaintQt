# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/PoProj_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/PoProj_autogen.dir/ParseCache.txt"
  "PoProj_autogen"
  )
endif()
