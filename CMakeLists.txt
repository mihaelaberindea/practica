cmake_minimum_required(VERSION 3.10.0)

project(practica)

### Local Variables ###

set(SOURCES
    Main.cpp    
)

set(HEADERS 
    include/Vector.h
    include/List.h
    include/ListNode.hpp
	include/Queue.hpp
	include/PriorityQueue.hpp
	include/Task.hpp
	include/VectorIteraror.hpp
    include/ListIterator.hpp
    include/SynchronizedPriorityQueque.hpp
    include/TaskArgument.hpp
	include/TaskResult.hpp
	include/TaskScheduler.hpp
	include/Functional.hpp
)

set(INCLUDE_DIRECTORIES
    PUBLIC include/
)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -Wall -Wextra -Wpedantic -Werror -fsanitize=address -g")

### Main Target ###

add_executable(Release ${SOURCES})
target_include_directories(Release ${INCLUDE_DIRECTORIES})
target_compile_options(Release PRIVATE -std=c++2a -O3 -Wall -Wextra -Wpedantic -Werror -lpthread)
target_link_libraries(Release -lpthread)

add_executable(DEBUG ${SOURCES})
target_compile_options(DEBUG PUBLIC -std=c++2a -Wall -Wextra -Wpedantic -Werror -Og -g -pthread)
target_include_directories(DEBUG ${INCLUDE_DIRECTORIES})
target_link_libraries(DEBUG PRIVATE -lpthread)


### Test Targets ###

# add_executable(vector_test_target VectorTest.cpp)
# target_include_directories(vector_test_target ${INCLUDE_DIRECTORIES})
# target_compile_options(vector_test_target PUBLIC -fprofile-instr-generate -fcoverage-mapping)
# target_link_libraries(vector_test_target PRIVATE -fprofile-instr-generate -fcoverage-mapping )

# add_test(vector_unit_test vector_test_target)

# enable_testing()


### Custom Targets ###

 #add_custom_target(format
  #  COMMAND cd ${CMAKE_CURRENT_SOURCE_DIR} && clang-format -style=file -i ${SOURCES} ${HEADERS}
#)

#add_custom_target(run_tests
#    COMMAND "cd" ${CMAKE_CURRENT_SOURCE_DIR}/build "&&" "make" "test"
#)
#add_dependencies(run_tests vector_test_target)

#set(GENERATE_COVERAGE_DATA_COMMAND llvm-profdata-10 merge -sparse default.profraw -o default.profdata)
#set(SHOW_COVERAGE_REPORT llvm-cov-10 report ./vector_test_target -instr-profile=default.profdata)

#add_custom_target(generate_coverage
 #   COMMAND "cd" ${CMAKE_CURRENT_SOURCE_DIR}/build && ${GENERATE_COVERAGE_DATA_COMMAND} && ${SHOW_COVERAGE_REPORT}
#)
