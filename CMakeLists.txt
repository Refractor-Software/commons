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

# link-time / whole-program optimization
IF (MSVC)
    ADD_COMPILE_OPTIONS ("/GL")
    ADD_COMPILE_OPTIONS ("/arch:AVX")
    ADD_LINK_OPTIONS    ("/LTCG")
ELSE ()
    ADD_COMPILE_OPTIONS ("-flto")
    ADD_COMPILE_OPTIONS ("-mavx")
ENDIF ()