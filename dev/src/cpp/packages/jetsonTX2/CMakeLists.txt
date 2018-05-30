find_package(Threads)
set(Target jetsonTX2.out)
set(Sources
	jetsonTX2.cpp
	main.cpp)

add_executable(${Target} ${Sources})
target_link_libraries(${Target} ${CMAKE_THREAD_LIBS_INIT})
