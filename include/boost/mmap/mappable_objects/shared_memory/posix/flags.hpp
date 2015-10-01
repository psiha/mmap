////////////////////////////////////////////////////////////////////////////////
///
/// \file shared_memory/posix/flags.hpp
/// -----------------------------------
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
#ifndef flags_hpp__F9CD9C91_1F07_4107_A422_0D814F0FE487
#define flags_hpp__F9CD9C91_1F07_4107_A422_0D814F0FE487
#pragma once
//------------------------------------------------------------------------------
#include "boost/mmap/detail/posix.hpp"
#include "boost/mmap/implementations.hpp"
#include "boost/mmap/flags/posix/mapping.hpp"
//------------------------------------------------------------------------------
namespace boost
{
//------------------------------------------------------------------------------
namespace mmap
{
//------------------------------------------------------------------------------
namespace flags
{
//------------------------------------------------------------------------------

template <typename Impl> struct shared_memory;

typedef int flags_t;

template <>
struct shared_memory<posix>
{
    struct system_hints
    {
        enum value_type
        {
            default_                   = 0,
            only_reserve_address_space = MAP_NORESERVE
        };
        value_type value;
    };

    static shared_memory<posix> BOOST_CC_REG create
    (
        access_privileges               <posix>,
        named_object_construction_policy<posix>::value_type,
        system_hints                           ::value_type
    ) noexcept;

    operator mapping<posix> () const noexcept
    {
        auto flags( mapping<posix>::create( ap.object_access, viewing<posix>::share_mode::shared ) );
        flags.flags |= hints.value;
        return static_cast<mapping<posix> &>( flags );
    }

    system_hints                            hints;
    access_privileges               <posix> ap;
    named_object_construction_policy<posix> nocp;
}; // struct shared_memory<posix>

//------------------------------------------------------------------------------
} // namespace flags
//------------------------------------------------------------------------------
} // namespace mmap
//------------------------------------------------------------------------------
} // namespace boost
//------------------------------------------------------------------------------

#ifdef BOOST_MMAP_HEADER_ONLY
    #include "flags.inl"
#endif

#endif // flags.hpp