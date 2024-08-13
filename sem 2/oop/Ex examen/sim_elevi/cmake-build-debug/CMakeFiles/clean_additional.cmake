# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\sim_elevi_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\sim_elevi_autogen.dir\\ParseCache.txt"
  "sim_elevi_autogen"
  )
endif()
