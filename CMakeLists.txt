cmake_minimum_required(VERSION 3.28)
 
project(LotteryCpp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(PROJECT_SOURCE_DIR src)

add_subdirectory(${LotteryCpp_SOURCE_DIR}/LotteryCpp)
add_subdirectory(${LotteryCpp_SOURCE_DIR}/SString)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 1.11.0) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)
target_link_libraries(LotteryCpp PUBLIC cpr::cpr)
