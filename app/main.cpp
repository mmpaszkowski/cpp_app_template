#include <filesystem>
#include <fstream>
#include <iostream>

#include <cpp_static_lib_template/library.h>
#include "../include/cpp_app_template/library.h"

int main(int argc, char **argv)
{
    lib::hello();
    app::hello();

    return 0;
}
