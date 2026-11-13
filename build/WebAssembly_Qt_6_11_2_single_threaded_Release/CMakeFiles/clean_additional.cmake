# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/appBaterieSimulation_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appBaterieSimulation_autogen.dir/ParseCache.txt"
  "appBaterieSimulation_autogen"
  )
endif()
