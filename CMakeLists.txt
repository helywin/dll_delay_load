cmake_minimum_required(VERSION 3.15)
project(dll_delay_load)

set(CMAKE_CXX_STANDARD 14)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    message("=== Debug Mode ===")
    set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/debug)
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/debug)
else (CMAKE_BUILD_TYPE MATCHES Release)
    message("=== Release Mode ===")
    set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/release)
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/release)
endif ()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

if (MSVC)
    set(DEFINES_DEBUG "-D_WINDOWS -DWIN32 -D_ENABLE_EXTENDED_ALIGNED_STORAGE -DWIN64 /wd4100")
    set(CMAKE_CXX_FLAGS_DEBUG "/analyze /utf-8 /sdl /EHsc /D_DEBUG -nologo -Zc:wchar_t -FS -Zc:strictStrings -Zi -MDd -W3 -w44456 -w44457 -w44458 ${DEFINES_DEBUG}")
    set(CMAKE_C_FLAGS_DEBUG "/analyze /utf-8 /sdl /D_DEBUG -nologo -Zc:wchar_t -FS -Zc:rvalueCast -Zc:inline -Zc:strictStrings -Zc:throwingNew -Zc:referenceBinding -Zc:__cplusplus /FS -Zi -MDd -W3 -w34100 -w34189 -w44996 -w44456 -w44457 -w44458 -wd4577 -wd4467 -EHsc ${DEFINES_DEBUG}")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "/NOLOGO /DYNAMICBASE /NXCOMPAT /INCREMENTAL:NO /DEBUG /IGNORE:4099")
    set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "/NOLOGO /DYNAMICBASE /NXCOMPAT /DEBUG /DLL /SUBSYSTEM:WINDOWS /IGNORE:4099")

    # release模式下生成pdb用于调试
    set(DEFINES_RELEASE "-D_WINDOWS -DWIN32 -D_ENABLE_EXTENDED_ALIGNED_STORAGE -DWIN64")
    set(CMAKE_C_FLAGS_RELEASE "/utf-8 /sdl -nologo -Zc:wchar_t -FS -Zi -Zc:strictStrings -O2 -MD -W3 -w44456 -w44457 -w44458 ${DEFINES_RELEASE}")
    set(CMAKE_CXX_FLAGS_RELEASE "/utf-8 /sdl -nologo -Zc:wchar_t -FS -Zi -Zc:rvalueCast -Zc:inline -Zc:strictStrings -Zc:throwingNew -Zc:referenceBinding -Zc:__cplusplus -O2 -MD -W3 -w34100 -w34189 -w44996 -w44456 -w44457 -w44458 -wd4577 -wd4467 -EHsc ${DEFINES_RELEASE}")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/NOLOGO /DYNAMICBASE /NXCOMPAT /INCREMENTAL:NO /DEBUG /OPT:REF /OPT:ICF")# /NODEFAULTLIB:MSVCRT /NODEFAULTLIB:LIBC
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/NOLOGO /DYNAMICBASE /NXCOMPAT /INCREMENTAL:NO /DLL /SUBSYSTEM:WINDOWS /DEBUG /OPT:REF /OPT:ICF")
else ()
    message(FATAL_ERROR "platform not supported")
endif ()


add_library(MyDll SHARED
        MyDll.cpp MyDll.hpp MyDll_Export.hpp)
target_compile_definitions(MyDll PRIVATE -DMYDLL_EXPORT)

add_executable(ordinary ordinary.cpp)
target_link_libraries(ordinary PRIVATE MyDll)

add_executable(delay delay.cpp)
target_link_libraries(delay PRIVATE MyDll delayimp)
target_link_options(delay PRIVATE /DELAYLOAD:MyDll.dll)

add_custom_target(deploy)
add_dependencies(deploy ordinary delay)
add_custom_command(TARGET move POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/bin
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/bin/ordinary
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/bin/delay
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/bin/delay/dlls
        COMMAND ${CMAKE_COMMAND} -E copy ${EXECUTABLE_OUTPUT_PATH}/ordinary.exe ${CMAKE_SOURCE_DIR}/bin/ordinary/ordinary.exe
        COMMAND ${CMAKE_COMMAND} -E copy ${EXECUTABLE_OUTPUT_PATH}/MyDll.dll ${CMAKE_SOURCE_DIR}/bin/ordinary/MyDll.dll
        COMMAND ${CMAKE_COMMAND} -E copy ${EXECUTABLE_OUTPUT_PATH}/delay.exe ${CMAKE_SOURCE_DIR}/bin/delay/delay.exe
        COMMAND ${CMAKE_COMMAND} -E copy ${EXECUTABLE_OUTPUT_PATH}/MyDll.dll ${CMAKE_SOURCE_DIR}/bin/delay/dlls/MyDll.dll
        )


