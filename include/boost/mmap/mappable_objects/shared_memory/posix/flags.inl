////////////////////////////////////////////////////////////////////////////////
///
/// \file posix/flags.inl
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
#include "flags.hpp"
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

BOOST_IMPL_INLINE
shared_memory<posix> BOOST_CC_REG shared_memory<posix>::create
(
    access_privileges               <posix>             const ap,
    named_object_construction_policy<posix>::value_type const nocp,
    system_hints                           ::value_type const system_hint
) noexcept
{
    return { system_hint, ap, nocp };
}

//------------------------------------------------------------------------------
} // flags
//------------------------------------------------------------------------------
} // mmap
//------------------------------------------------------------------------------
} // boost
//------------------------------------------------------------------------------