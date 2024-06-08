CMAKE_MINIMUM_REQUIRED (VERSION 3.28)

PROJECT (_RefractorCommons_ LANGUAGES C)

SET (CMAKE_C_STANDARD 90)

FILE (GLOB_RECURSE _RC_SOURCES_
    commons/*.c
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