enable_testing()

foreach(test_file bizdays finance objects toolbox)
    add_executable(numcpptests-${test_file} tests/${test_file}.cpp)
    target_link_libraries(numcpptests-${test_file} numcpp)
    add_test(NAME ${test_file} COMMAND numcpptests-${test_file})
endforeach()

