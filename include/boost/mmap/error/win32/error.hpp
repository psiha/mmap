////////////////////////////////////////////////////////////////////////////////
///
/// \file win32/error.hpp
/// ---------------------
///
/// Copyright (c) Domagoj Saric 2010 - 2015.
///
/// Use, modification and distribution is subject to the
/// Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)
///
/// For more information, see http://www.boost.org
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef error_hpp__C987B8F7_BA90_41F7_B025_98AFE271C6A9
#define error_hpp__C987B8F7_BA90_41F7_B025_98AFE271C6A9
#pragma once
//------------------------------------------------------------------------------
#include "boost/err/win32.hpp"
//------------------------------------------------------------------------------
namespace boost
{
//------------------------------------------------------------------------------
namespace mmap
{
//------------------------------------------------------------------------------

template <typename Impl> struct error;

struct win32;

template <> struct error<win32> : err::last_win32_error {};

//------------------------------------------------------------------------------
} // namespace mmap
//------------------------------------------------------------------------------
} // namespace boost
//------------------------------------------------------------------------------
#endif // errno_hpp