cmake_minimum_required(VERSION 3.4)
project("HelloWorldJNI")

find_package(Java REQUIRED)
find_package(JNI REQUIRED)
include(UseJava)

set(VERSION 1.0.0)

# compile option
set(CMAKE_JAVA_COMPILE_FLAGS "-source" "1.8" "-target" "1.8")
set(CMAKE_CXX_STANDARD 14)
set(OPTFLAGS -O2 -z noexecstack)
set(DEBUG -gdwarf-2)

add_compile_options(${OPTFLAGS} ${DEBUG} ${WARNINGS})
add_compile_options(-D_GLIBCXX_USE_CXX11_ABI=0)

include_directories(/usr/lib/jvm/java-1.8.0-openjdk/include)
include_directories(/usr/lib/jvm/java-1.8.0-openjdk/include/linux)
include_directories(./include)

#file(GLOB_RECURSE SOURCE_FILES ./*.cpp)

add_executable(daysOfWeek daysOfWeek.cpp)

target_link_libraries(daysOfWeek ${JNI_LIBRARIES})

#install(TARGETS ${LIBRARY_NAME}
#	ARCHIVE DESTINATION lib
#	LIBRARY DESTINATION lib
#)
#install(DIRECTORY include/ 
#    DESTINATION include 
#    COMPONENT headers 
#    FILES_MATCHING PATTERN "*.h"
#)
