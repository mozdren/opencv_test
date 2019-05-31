cmake_minimum_required(VERSION 3.14)

project( test_opencv )

# dependencies

set( OpenCV_DIR ../opencv/bin/install )
find_package( OpenCV REQUIRED )

# executables and linked libraries

add_executable( test_opencv main.cpp )
target_link_libraries( test_opencv ${OpenCV_LIBS} )

# Required Resources

file( GLOB OPENCV_DLLS
  "../opencv/bin/install/x86/vc15/bin/*.dll"
)
file( COPY ${OPENCV_DLLS} DESTINATION "Release/" )
file( COPY ${OPENCV_DLLS} DESTINATION "Debug/" )

set( OPENCV_DLL_DIR ../opencv/bin/install/x86/vc15/bin/ )
file( COPY "resources/lenna.png" DESTINATION "Release/" )
file( COPY "resources/lenna.png" DESTINATION "Debug/" )

set( VS_STARTUP_PROJECT test_opencv )
set_property( TARGET test_opencv PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "$(Configuration)" )