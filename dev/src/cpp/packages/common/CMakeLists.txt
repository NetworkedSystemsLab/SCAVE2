find_package(Threads)
set(Target common.out)
set(Sources
	main.cpp)

add_executable(${Target} ${Sources})
target_link_libraries(${Target} ${CMAKE_THREAD_LIBS_INIT})
