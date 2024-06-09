CMAKE_MINIMUM_REQUIRED (VERSION 3.28)

PROJECT (_RefractorCommons_ LANGUAGES CXX)

SET (CMAKE_CXX_STANDARD 20)

FILE (GLOB_RECURSE _RC_SOURCES_
    commons/*.cpp
    commons/*.h
    commons/*.inl
)

ADD_LIBRARY (rcommons OBJECT ${_RC_SOURCES_})

TARGET_INCLUDE_DIRECTORIES (rcommons PUBLIC commons)

ADD_EXECUTABLE(avx_test a_test.cpp)

TARGET_LINK_LIBRARIES(avx_test PUBLIC rcommons)

# link-time / whole-program optimization
#IF (MSVC)
#    ADD_COMPILE_OPTIONS (/GL /arch:AVX)
#    ADD_LINK_OPTIONS    (/LTCG)
#ELSE ()
    SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native --static")
#ENDIF ()