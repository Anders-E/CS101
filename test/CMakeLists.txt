add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

# "keeps your CACHE cleaner"
mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

# IDE folder support
set_target_properties(gtest PROPERTIES FOLDER extern)
set_target_properties(gtest_main PROPERTIES FOLDER extern)
set_target_properties(gmock PROPERTIES FOLDER extern)
set_target_properties(gmock_main PROPERTIES FOLDER extern)

macro(package_add_test_with_libraries TESTNAME FILES LIBRARIES)
    add_executable(${TESTNAME} ${FILES})
    target_compile_features(${TESTNAME} PUBLIC cxx_std_17)
    target_link_libraries(${TESTNAME} gtest gtest_main ${LIBRARIES})
    gtest_discover_tests(${TESTNAME})
endmacro()

package_add_test_with_libraries(sorting_test algorithms/sorting_test.cpp sorting)
package_add_test_with_libraries(stack_test data_structures/stack_test.cpp stack)
package_add_test_with_libraries(linked_list_test data_structures/linked_list_test.cpp linked_list)
package_add_test_with_libraries(queue_test data_structures/queue_test.cpp queue)
