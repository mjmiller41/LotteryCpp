include_directories(${LotteryCpp_SOURCE_DIR}/LotteryCpp/inc)
include_directories(${LotteryCpp_SOURCE_DIR}/Timestamp/inc)
include_directories(${LotteryCpp_SOURCE_DIR}/Utils/inc)

link_directories(${LotteryCpp_SOURCE_DIR}/Timestamp/src)
link_directories(${LotteryCpp_SOURCE_DIR}/Utils/src)

message(STATUS "LotteryCPP_SOURCE_DIR: ${LotteryCpp_SOURCE_DIR}")
foreach(dir ${INCLUDE_DIRECTORIES})
    message(STATUS "  ${dir}")
endforeach()

add_executable(LotteryCpp
  main.cpp
  api.cpp
  mega_millions.cpp
  history.cpp
  drawing.cpp
  exceptions.cpp
)

target_link_libraries(LotteryCpp PUBLIC Timestamp Utils)
