cmake_minimum_required (VERSION 2.6)

project (lib_parse_enum)

set(ROOT_PATH ".")

include_directories(
	${ROOT_PATH}
)

add_executable(test_parse_enum 
	${ROOT_PATH}/main.c
	${ROOT_PATH}/lib_parse_enum.c
)

target_link_libraries(test_parse_enum m)
