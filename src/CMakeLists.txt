# Source CMakeLists.txt

add_executable(stratum
    main.cpp
)

target_include_directories(stratum PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(stratum PRIVATE
    math_utils
)
