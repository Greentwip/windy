/*
    Copyright 2007-2008 Christian Henning, Andreas Pokorny, Lubomir Bourdev
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
*/

/*************************************************************************************************/

#ifndef BOOST_GIL_EXTENSION_IO_TIFF_IO_HPP
#define BOOST_GIL_EXTENSION_IO_TIFF_IO_HPP

////////////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief
/// \author Christian Henning, Andreas Pokorny, Lubomir Bourdev \n
///
/// \date   2007-2008 \n
///
////////////////////////////////////////////////////////////////////////////////////////

#include <boost/mpl/not.hpp>
#include <boost/type_traits/is_same.hpp>

#include <boost/gil/channel.hpp>
#include <boost/gil/color_base.hpp>

namespace boost{ namespace gil {

// Read support

// TIFF virtually supports everything 
struct tiff_read_support : read_support_true
{};


// Write support

struct tiff_write_support : write_support_true
{};


template< typename Pixel >
struct is_read_supported< Pixel
                        , tiff_tag
                        > 
    : mpl::bool_< tiff_read_support::is_supported > {};

template< typename Pixel >
struct is_write_supported< Pixel
                         , tiff_tag
                         > 
    : mpl::bool_< tiff_write_support::is_supported >
{};

} // namespace gil
} // namespace boost

#endif // BOOST_GIL_EXTENSION_IO_TIFF_IO_HPP
