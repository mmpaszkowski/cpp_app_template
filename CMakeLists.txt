cmake_minimum_required(VERSION 3.16)

# PROJECT
project(cpp_app_template VERSION 0.0.1 LANGUAGES CXX)

# GLOBAL CMAKE VARIABLES
set(CMAKE_CXX_STANDARD              17)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)

# MAIN_PROJECT CHECK
set(APP_MAIN_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(APP_MAIN_PROJECT ON)
endif()

# OPTIONS
option(APP_ENABLE_WARNINGS              "Enable to add warnings to a target." ${APP_MAIN_PROJECT})
option(APP_ENABLE_TESTING               "Enable a Unit Testing build."        ${APP_MAIN_PROJECT})
option(APP_ENABLE_COVERAGE              "Enable a Code Coverage build."       ${APP_MAIN_PROJECT})

option(APP_ENABLE_CLANG_TIDY            "Enable to add clang tidy."           OFF) # Have to be fixed
option(APP_ENABLE_CLANG_FORMAT          "Enable to add clang-format."         ${APP_MAIN_PROJECT})
option(APP_ENABLE_CPPCHECK              "Enable to add cppcheck."             ${APP_MAIN_PROJECT})

# CMAKE MODULES
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
include(ConfigSafeGuards)
include(Warnings)
include(AddGitSubmodule)
include(FetchContent)
include(Tools)
include(LTO)

# EXTERNAL LIBRARIES
FetchContent_Declare(
        cpp_static_lib_template
        GIT_REPOSITORY https://github.com/mmpaszkowski/cpp_static_lib_template
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(cpp_static_lib_template)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 9.1.0
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(fmt)

# SUBDIRECTORIES
add_subdirectory(configured)
add_subdirectory(src)
add_subdirectory(app)

# TESTS
if (APP_ENABLE_TESTING)
    include(CTest)
    if (APP_ENABLE_COVERAGE)
        include(CodeCoverage)
        append_coverage_compiler_flags()
    endif()
    add_subdirectory(tests)
endif()

# INSTALL TARGETS
install(TARGETS ${PROJECT_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)