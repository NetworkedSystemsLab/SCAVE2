find_package(Threads)
set(Target tachometer.out)
set(Sources
	../jetsonTX2/jetsonTX2.cpp
	../timer/timer.cpp
	tachometer.cpp
	main.cpp)

add_executable(${Target} ${Sources})
target_link_libraries(${Target} ${CMAKE_THREAD_LIBS_INIT})
