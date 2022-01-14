// Copyright 2017 The CRC32C Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef CRC32C_CRC32C_CONFIG_H_
#define CRC32C_CRC32C_CONFIG_H_

// Define to 1 if building for a big-endian platform.
#define BYTE_ORDER_BIG_ENDIAN 0

//@dyu
#if defined(_MSC_VER)
#define HAVE_BUILTIN_PREFETCH 0
#else
// Define to 1 if the compiler has the __builtin_prefetch intrinsic.
#define HAVE_BUILTIN_PREFETCH 1
#endif

//@dyu
#if defined(__aarch64__) || defined(_M_ARM64)
#define HAVE_MM_PREFETCH 0
#else
// Define to 1 if targeting X86 and the compiler has the _mm_prefetch intrinsic.
#define HAVE_MM_PREFETCH 1
#endif

//@dyu TODO: enable
// Define to 1 if targeting X86 and the compiler has the _mm_crc32_u{8,32,64}
// intrinsics.
#define HAVE_SSE42 0

//@dyu TODO remove suffix? -> !defined(__APPLE__)
#if !defined(HAVE_ARM64_CRC32C)
#if (defined(__aarch64__) || defined(_M_ARM64)) && defined(__APPLE__)
// Define to 1 if targeting ARM and the compiler has the __crc32c{b,h,w,d} and
// the vmull_p64 intrinsics.
#define HAVE_ARM64_CRC32C 1
#else
#define HAVE_ARM64_CRC32C 0
#endif
#endif

//@dyu TODO newer linux distributions have this
// Define to 1 if the system libraries have the getauxval function in the
// <sys/auxv.h> header. Should be true on Linux and Android API level 20+.
#define HAVE_STRONG_GETAUXVAL 0

//@dyu
#if defined(__clang__) || defined(_MSC_VER)
#define HAVE_WEAK_GETAUXVAL 0
#else
// Define to 1 if the compiler supports defining getauxval as a weak symbol.
// Should be true for any compiler that supports __attribute__((weak)).
#define HAVE_WEAK_GETAUXVAL 1
#endif

//@dyu
// Define to 1 if CRC32C tests have been built with Google Logging.
#define CRC32C_TESTS_BUILT_WITH_GLOG 0

#endif  // CRC32C_CRC32C_CONFIG_H_