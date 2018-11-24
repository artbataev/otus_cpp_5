cmake_minimum_required(VERSION 3.8)

if ($ENV{TRAVIS_BUILD_NUMBER})
    set(PROJECT_VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ()
    set(PROJECT_VERSION 0.0.1)
endif ()

project(editor VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(editor src/main.cpp
        src/canvas_primitives.cpp include/canvas_primitives.h
        src/model.cpp include/model.h
        src/view.cpp include/view.h
        src/controller.cpp include/controller.h)

install(TARGETS editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT artbataev@gmail.com)

include(CPack)
