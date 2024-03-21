//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// WARNING: This test was generated by generate_feature_test_macro_components.py
// and should not be edited manually.
//
// clang-format off

// <span>

// Test the feature test macros defined by <span>

/*  Constant                           Value
    __cpp_lib_span                     202002L [C++20]
    __cpp_lib_span_at                  202311L [C++26]
    __cpp_lib_span_initializer_list    202311L [C++26]
*/

#include <span>
#include "test_macros.h"

#if TEST_STD_VER < 14

# ifdef __cpp_lib_span
#   error "__cpp_lib_span should not be defined before c++20"
# endif

# ifdef __cpp_lib_span_at
#   error "__cpp_lib_span_at should not be defined before c++26"
# endif

# ifdef __cpp_lib_span_initializer_list
#   error "__cpp_lib_span_initializer_list should not be defined before c++26"
# endif

#elif TEST_STD_VER == 14

# ifdef __cpp_lib_span
#   error "__cpp_lib_span should not be defined before c++20"
# endif

# ifdef __cpp_lib_span_at
#   error "__cpp_lib_span_at should not be defined before c++26"
# endif

# ifdef __cpp_lib_span_initializer_list
#   error "__cpp_lib_span_initializer_list should not be defined before c++26"
# endif

#elif TEST_STD_VER == 17

# ifdef __cpp_lib_span
#   error "__cpp_lib_span should not be defined before c++20"
# endif

# ifdef __cpp_lib_span_at
#   error "__cpp_lib_span_at should not be defined before c++26"
# endif

# ifdef __cpp_lib_span_initializer_list
#   error "__cpp_lib_span_initializer_list should not be defined before c++26"
# endif

#elif TEST_STD_VER == 20

# ifndef __cpp_lib_span
#   error "__cpp_lib_span should be defined in c++20"
# endif
# if __cpp_lib_span != 202002L
#   error "__cpp_lib_span should have the value 202002L in c++20"
# endif

# ifdef __cpp_lib_span_at
#   error "__cpp_lib_span_at should not be defined before c++26"
# endif

# ifdef __cpp_lib_span_initializer_list
#   error "__cpp_lib_span_initializer_list should not be defined before c++26"
# endif

#elif TEST_STD_VER == 23

# ifndef __cpp_lib_span
#   error "__cpp_lib_span should be defined in c++23"
# endif
# if __cpp_lib_span != 202002L
#   error "__cpp_lib_span should have the value 202002L in c++23"
# endif

# ifdef __cpp_lib_span_at
#   error "__cpp_lib_span_at should not be defined before c++26"
# endif

# ifdef __cpp_lib_span_initializer_list
#   error "__cpp_lib_span_initializer_list should not be defined before c++26"
# endif

#elif TEST_STD_VER > 23

# ifndef __cpp_lib_span
#   error "__cpp_lib_span should be defined in c++26"
# endif
# if __cpp_lib_span != 202002L
#   error "__cpp_lib_span should have the value 202002L in c++26"
# endif

# ifndef __cpp_lib_span_at
#   error "__cpp_lib_span_at should be defined in c++26"
# endif
# if __cpp_lib_span_at != 202311L
#   error "__cpp_lib_span_at should have the value 202311L in c++26"
# endif

# ifndef __cpp_lib_span_initializer_list
#   error "__cpp_lib_span_initializer_list should be defined in c++26"
# endif
# if __cpp_lib_span_initializer_list != 202311L
#   error "__cpp_lib_span_initializer_list should have the value 202311L in c++26"
# endif

#endif // TEST_STD_VER > 23

