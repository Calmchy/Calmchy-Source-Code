# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QT-Banking-System_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QT-Banking-System_autogen.dir/ParseCache.txt"
  "QT-Banking-System_autogen"
  )
endif()
