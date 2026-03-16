# Source CMakeLists.txt

add_executable(stratum_bin
    main.cpp
)

target_include_directories(stratum_bin PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(stratum_bin PRIVATE
    ${STRATUM_LIB}
)
