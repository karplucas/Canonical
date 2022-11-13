cmake_minimum_required(VERSION 3.0.0)
project(ubuntufetcher VERSION 0.1.0)

include(CTest)
enable_testing()

if (WIN32)
    cmake_policy(SET CMP0074 NEW)
    set(CURL_SRC_DIR "C:/lib/curl-7.86.0_2")
    set(CURL_INCLUDE_DIR ${CURL_SRC_DIR}/include)
    set(CURL_LIBRARY ${CURL_SRC_DIR}/lib/libcurl.dll.a )
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    add_definitions(-DCURL_STATICLIB)
endif (WIN32)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

SET(TARGET_H
    ./HTTPDownloader.hpp  
   )

# Local source files here
SET(TARGET_SRC
    HTTPDownloader.cpp
    main.cpp
    )

add_executable(ubuntufetcher ${TARGET_SRC} )
target_link_libraries(ubuntufetcher ${CURL_LIBRARY})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
