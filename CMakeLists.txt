cmake_minimum_required(VERSION 3.19)
project(libroothide)

set(CMAKE_CXX_STANDARD 11)

link_directories(.)


add_executable(
        symredirect

        symredirect.cpp
)

add_executable(
        ismacho

        ismacho.cpp
)

add_library(
        roothideinit
        SHARED
        init.c
        common.c
)
add_library(
        roothide
        SHARED
        jbroot.c
        jbroot.cpp
        jbroot.m
        cache.c
        common.c
)

add_library(
        vroot
        SHARED
        vroot.c
        vroot_mktemp.c
        vroot.cpp
        vroot_rootfs.c
        vroot_exec.c
        vroot_dlfcn.c
        common.c
        debug.m
)

add_library(
        vrootapi
        SHARED
        vrootapi.c
)

add_executable(
        updatelink
        updatelink.c
)

add_executable(
        jbrand
        cmdtool.c
)