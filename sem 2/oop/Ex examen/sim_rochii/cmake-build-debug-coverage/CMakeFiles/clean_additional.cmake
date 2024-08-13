# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\sim_rochii_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\sim_rochii_autogen.dir\\ParseCache.txt"
  "sim_rochii_autogen"
  )
endif()
