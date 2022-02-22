cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set up some build requirements for Windows.
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# We need to import this globally in order for OpenSSL to be available
# to our dependant libraries such as couchbase-cxx-client.
include_directories(${CMAKE_JS_INC})

project (staticsrepro)

file(GLOB SOURCE_FILES "*.cpp")
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC})

add_definitions(-DNAPI_VERSION=6)
target_include_directories(${PROJECT_NAME}
  PRIVATE ${CMAKE_JS_INC}
          "${CMAKE_SOURCE_DIR}/node_modules/node-addon-api")
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

target_link_libraries(${PROJECT_NAME}
  ${CMAKE_JS_LIB}
)
