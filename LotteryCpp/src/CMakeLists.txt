include_directories(${LotteryCpp_SOURCE_DIR}/LotteryCpp/inc)
include_directories(${LotteryCpp_SOURCE_DIR}/SString/inc)
include_directories(${LotteryCpp_SOURCE_DIR}/Timestamp/inc)

link_directories(${LotteryCpp_SOURCE_DIR}/SString/src)
link_directories(${LotteryCpp_SOURCE_DIR}/Timestamp/src)

message(STATUS "LotteryCPP_SOURCE_DIR: ${LotteryCpp_SOURCE_DIR}")
foreach(dir ${INCLUDE_DIRECTORIES})
    message(STATUS "  ${dir}")
endforeach()

add_executable(LotteryCpp
  main.cpp
  api.cpp
  data_table.cpp
)

target_link_libraries(LotteryCpp PUBLIC SString)
