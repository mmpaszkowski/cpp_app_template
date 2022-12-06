set (MAIN_SOURCE "main.cpp")

add_executable(${APP_PROJECT_NAME} ${MAIN_SOURCE} ${APP_SOURCES} ${APP_HEADERS})

target_link_libraries(${APP_PROJECT_NAME} PUBLIC
    cpp_static_lib_template::cpp_static_lib_template fmt::fmt)

if (${ENABLE_WARNINGS})
    target_set_warnings(TARGET ${APP_PROJECT_NAME} ENABLE ON AS_ERROR OFF)
endif()

add_target_static_analyers(${APP_PROJECT_NAME})
