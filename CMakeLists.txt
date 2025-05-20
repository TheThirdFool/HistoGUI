cmake_minimum_required(VERSION 3.10)
project(HistoGUI)

if (APPLE)	
	message("Using APPLE")
	find_package(X11 REQUIRED)
	include_directories(${X11_INCLUDE_DIR})
	link_directories(${X11_LIBRARIES})
	#set(CMAKE_CXX_STANDARD 17)

	add_executable(fit Fitting.cxx)
	target_link_libraries(fit ${X11_LIBRARIES})

	add_executable(ex Example.cxx)
	target_link_libraries(ex ${X11_LIBRARIES})	
	
# Linux compile
elseif (UNIX)
	message("Using LINUX")
	add_executable(fit Fitting.cxx)
	target_link_libraries(fit PRIVATE -lX11)
	target_compile_options(fit PRIVATE -fno-stack-protector)
	
	add_executable(ex Example.cxx)
	target_link_libraries(ex PRIVATE -lX11)
	target_compile_options(ex PRIVATE -fno-stack-protector)
endif ()

