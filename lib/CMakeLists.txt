# Library CMakeLists.txt

add_library(${STRATUM_LIB} STATIC
    math_utils.cpp
)

target_include_directories(${STRATUM_LIB} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
