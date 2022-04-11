cmake_minimum_required(VERSION 3.13)

project(Shapes)

# set compiler flags
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_subdirectory(src)

target_link_libraries(
    ${PROJECT_NAME}
    drawerlib
    mathfunctionslib
    pointlib
    ishapelib
    angularshapelib
    squarelib
    starlib
    rectanglelib
    trianglelib
    circlelib
)