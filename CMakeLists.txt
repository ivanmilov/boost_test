project(boost_test)
cmake_minimum_required(VERSION 2.8)

set(Boost_USE_STATIC_LIBS       OFF) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost COMPONENTS thread REQUIRED)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

add_library(
	${PROJECT_NAME}_lib
	STATIC

	main.cpp
)

target_link_libraries(
	${PROJECT_NAME}_lib
	${Boost_LIBRARIES}
	pthread
)

add_executable(
	${PROJECT_NAME}

	main.cpp
)

target_link_libraries(
	${PROJECT_NAME}

	${PROJECT_NAME}_lib
)


#aux_source_directory(. SRC_LIST)
#add_executable(${PROJECT_NAME} ${SRC_LIST})
#target_link_libraries(
#	${PROJECT_NAME}
#	${Boost_LIBRARIES}
#)

