find_package(Threads)
set(Target serial.out)
set(Sources
	serial.cpp
	main.cpp)

add_executable(${Target} ${Sources})
target_link_libraries(${Target} ${CMAKE_THREAD_LIBS_INIT})
