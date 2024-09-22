project(UnitTestRunner VERSION 0.1)

set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)
include(CTest)

#Declaring that we want 'catch2', a testing framework.
#Instructions on how to find it would appear under CMake/findcatch2.cmake
find_package(catch2 REQUIRED)

add_executable(UnitTestRunner Tests.cpp)

target_link_libraries(UnitTestRunner PRIVATE
        Catch2WithMain
        CopyOnWrite)

catch_discover_tests(UnitTestRunner)