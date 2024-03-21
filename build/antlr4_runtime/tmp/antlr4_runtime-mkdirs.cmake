# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/001ys/Desktop/wsp/lang/build/antlr4_runtime/src/antlr4_runtime"
  "C:/Users/001ys/Desktop/wsp/lang/build/antlr4_runtime/src/antlr4_runtime-build"
  "C:/Users/001ys/Desktop/wsp/lang/build/antlr4_runtime"
  "C:/Users/001ys/Desktop/wsp/lang/build/antlr4_runtime/tmp"
  "C:/Users/001ys/Desktop/wsp/lang/build/antlr4_runtime/src/antlr4_runtime-stamp"
  "C:/Users/001ys/Desktop/wsp/lang/build"
  "C:/Users/001ys/Desktop/wsp/lang/build/antlr4_runtime/src/antlr4_runtime-stamp"
)

set(configSubDirs Debug;Release;MinSizeRel;RelWithDebInfo)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/001ys/Desktop/wsp/lang/build/antlr4_runtime/src/antlr4_runtime-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/001ys/Desktop/wsp/lang/build/antlr4_runtime/src/antlr4_runtime-stamp${cfgdir}") # cfgdir has leading slash
endif()
