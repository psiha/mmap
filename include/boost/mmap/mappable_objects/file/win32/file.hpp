////////////////////////////////////////////////////////////////////////////////
///
/// \file win32/file.hpp
/// --------------------
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
#ifndef file_hpp__FB482005_18D9_4E3B_9193_A13DBFE88F45
#define file_hpp__FB482005_18D9_4E3B_9193_A13DBFE88F45
#pragma once
//------------------------------------------------------------------------------
#include "boost/mmap/flags/win32/opening.hpp"
#include "boost/mmap/implementations.hpp"
#include "boost/mmap/mapping/mapping.hpp"
#include "boost/mmap/mappable_objects/file/handle.hpp"
#include "boost/mmap/error/error.hpp"

#include <cstddef>
//------------------------------------------------------------------------------
namespace boost
{
//------------------------------------------------------------------------------
namespace mmap
{
//------------------------------------------------------------------------------

template <typename Impl  > struct opening;
template <typename Impl  > struct mapping;
template <class    Handle> struct is_resizable;

template <> struct is_resizable<file_handle<win32>> : std::true_type {};

file_handle<win32> BOOST_CC_REG create_file( char    const * file_name, flags::opening<win32> ) noexcept;
file_handle<win32> BOOST_CC_REG create_file( wchar_t const * file_name, flags::opening<win32> ) noexcept;
bool               BOOST_CC_REG delete_file( char    const * file_name, win32                 ) noexcept;
bool               BOOST_CC_REG delete_file( wchar_t const * file_name, win32                 ) noexcept;


bool        BOOST_CC_REG set_size( file_handle<win32>::reference, std::size_t desired_size ) noexcept;
std::size_t BOOST_CC_REG get_size( file_handle<win32>::reference                           ) noexcept;

// https://msdn.microsoft.com/en-us/library/ms810613.aspx Managing Memory-Mapped Files

mapping<win32> BOOST_CC_REG create_mapping
(
    handle<win32>::reference,
    flags::access_privileges<win32>::object,
    flags::access_privileges<win32>::child_process,
    flags::mapping          <win32>::share_mode,
    std::size_t size
) noexcept;

//------------------------------------------------------------------------------
} // namespace mmap
//------------------------------------------------------------------------------
} // namespace boost
//------------------------------------------------------------------------------

#ifdef BOOST_MMAP_HEADER_ONLY
    #include "file.inl"
#endif // BOOST_MMAP_HEADER_ONLY

#endif // file_hpp