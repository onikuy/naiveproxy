//==----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11, c++14, c++17
// UNSUPPORTED: no-localization
// UNSUPPORTED: libcpp-has-no-experimental-syncstream

// <syncstream>

// template <class charT, class traits, class Allocator>
// class basic_osyncstream;

// explicit basic_osyncstream(streambuf_type* os);

#include <cassert>
#include <concepts>
#include <syncstream>
#include <sstream>

#include "test_macros.h"
#include "constexpr_char_traits.h"
#include "test_allocator.h"

template <class CharT>
void test() {
  {
    using OS = std::basic_osyncstream<CharT>;
    using W  = std::basic_stringbuf<CharT>;

    static_assert(!std::convertible_to<std::basic_syncbuf<CharT>*, OS>);
    static_assert(std::constructible_from<OS, std::basic_syncbuf<CharT>*>);

    {
      OS os{nullptr};
      assert(os.get_wrapped() == nullptr);
      assert(os.rdbuf()->get_wrapped() == nullptr);
      assert(os.rdbuf()->get_allocator() == std::allocator<CharT>());
    }
    {
      W w;
#if defined(_LIBCPP_VERSION) && !defined(TEST_HAS_NO_THREADS)
      assert(std::__wrapped_streambuf_mutex::__instance().__get_count(&w) == 0);
#endif
      {
        OS os{&w};
#if defined(_LIBCPP_VERSION) && !defined(TEST_HAS_NO_THREADS)
        assert(std::__wrapped_streambuf_mutex::__instance().__get_count(&w) == 1);
#endif
        assert(os.get_wrapped() == &w);
        assert(os.rdbuf()->get_wrapped() == &w);
        assert(os.rdbuf()->get_allocator() == std::allocator<CharT>());
      }
#if defined(_LIBCPP_VERSION) && !defined(TEST_HAS_NO_THREADS)
      assert(std::__wrapped_streambuf_mutex::__instance().__get_count(&w) == 0);
#endif
    }
  }

  {
    using OS = std::basic_osyncstream<CharT, constexpr_char_traits<CharT>>;
    using W  = std::basic_stringbuf<CharT, constexpr_char_traits<CharT>>;

    static_assert(!std::convertible_to<std::basic_syncbuf<CharT, constexpr_char_traits<CharT>>*, OS>);
    static_assert(std::constructible_from<OS, std::basic_syncbuf<CharT, constexpr_char_traits<CharT>>*>);

    {
      OS os{nullptr};
      assert(os.get_wrapped() == nullptr);
      assert(os.rdbuf()->get_wrapped() == nullptr);
      assert(os.rdbuf()->get_allocator() == std::allocator<CharT>());
    }
    {
      W w;
#if defined(_LIBCPP_VERSION) && !defined(TEST_HAS_NO_THREADS)
      assert(std::__wrapped_streambuf_mutex::__instance().__get_count(&w) == 0);
#endif
      {
        OS os{&w};
#if defined(_LIBCPP_VERSION) && !defined(TEST_HAS_NO_THREADS)
        assert(std::__wrapped_streambuf_mutex::__instance().__get_count(&w) == 1);
#endif
        assert(os.get_wrapped() == &w);
        assert(os.rdbuf()->get_wrapped() == &w);
        assert(os.rdbuf()->get_allocator() == std::allocator<CharT>());
      }
#if defined(_LIBCPP_VERSION) && !defined(TEST_HAS_NO_THREADS)
      assert(std::__wrapped_streambuf_mutex::__instance().__get_count(&w) == 0);
#endif
    }
  }

  {
    using OS = std::basic_osyncstream<CharT, constexpr_char_traits<CharT>, test_allocator<CharT>>;
    using W  = std::basic_stringbuf<CharT, constexpr_char_traits<CharT>, test_allocator<CharT>>;

    static_assert(
        !std::convertible_to<std::basic_syncbuf<CharT, constexpr_char_traits<CharT>, test_allocator<CharT>>*, OS>);
    static_assert(
        std::constructible_from<OS, std::basic_syncbuf<CharT, constexpr_char_traits<CharT>, test_allocator<CharT>>*>);

    {
      OS os{nullptr};
      assert(os.get_wrapped() == nullptr);
      assert(os.rdbuf()->get_wrapped() == nullptr);
      assert(os.rdbuf()->get_allocator() == test_allocator<CharT>());
    }
    {
      W w;
#if defined(_LIBCPP_VERSION) && !defined(TEST_HAS_NO_THREADS)
      assert(std::__wrapped_streambuf_mutex::__instance().__get_count(&w) == 0);
#endif
      {
        OS os{&w};
#if defined(_LIBCPP_VERSION) && !defined(TEST_HAS_NO_THREADS)
        assert(std::__wrapped_streambuf_mutex::__instance().__get_count(&w) == 1);
#endif
        assert(os.get_wrapped() == &w);
        assert(os.rdbuf()->get_wrapped() == &w);
        assert(os.rdbuf()->get_allocator() == test_allocator<CharT>());
      }
#if defined(_LIBCPP_VERSION) && !defined(TEST_HAS_NO_THREADS)
      assert(std::__wrapped_streambuf_mutex::__instance().__get_count(&w) == 0);
#endif
    }
  }
}

int main(int, char**) {
  test<char>();
#ifndef TEST_HAS_NO_WIDE_CHARACTERS
  test<wchar_t>();
#endif

  return 0;
}
