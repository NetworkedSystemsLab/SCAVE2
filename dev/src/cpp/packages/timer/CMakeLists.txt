find_package(Threads)
set(Target timer.out)
set(Sources
	timer.cpp
	main.cpp)

add_executable(${Target} ${Sources})
target_link_libraries(${Target} ${CMAKE_THREAD_LIBS_INIT})
