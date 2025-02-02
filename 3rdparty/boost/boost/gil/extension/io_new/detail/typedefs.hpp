/*
    Copyright 2007-2008 Christian Henning
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
*/

/*************************************************************************************************/

#ifndef BOOST_GIL_EXTENSION_IO_BASE_HPP
#define BOOST_GIL_EXTENSION_IO_BASE_HPP

////////////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief
/// \author Christian Henning \n
///
/// \date   2007-2008 \n
///
////////////////////////////////////////////////////////////////////////////////////////

#include <vector>

#include <boost/type_traits/is_base_of.hpp>

#include <boost/gil/image.hpp>
#include <boost/gil/utilities.hpp>

#ifdef BOOST_GIL_IO_ENABLE_GRAY_ALPHA
#include <boost/gil/extension/toolbox/gray_alpha.hpp>
#endif // BOOST_GIL_IO_ENABLE_GRAY_ALPHA

namespace boost { namespace gil { 

struct double_zero { static double apply() { return 0.0; } };
struct double_one  { static double apply() { return 1.0; } };

typedef scoped_channel_value< double, double_zero, double_one > bits64f;

typedef unsigned char byte_t;
typedef std::vector< byte_t > byte_vector_t;

typedef point2< std::ptrdiff_t > point_t;

} // namespace gil
} // namespace boost

namespace boost { 

template<> struct is_floating_point< gil::bits32f > : mpl::true_ {};
template<> struct is_floating_point< gil::bits64f > : mpl::true_ {};

} // namespace boost

namespace boost { namespace gil {

///@todo We should use boost::preprocessor here.

typedef bit_aligned_image1_type< 1, gray_layout_t >::type gray1_image_t;
typedef bit_aligned_image1_type< 2, gray_layout_t >::type gray2_image_t;
typedef bit_aligned_image1_type< 4, gray_layout_t >::type gray4_image_t;

typedef pixel< double, gray_layout_t       > gray64f_pixel_t;
#ifdef BOOST_GIL_IO_ENABLE_GRAY_ALPHA
typedef pixel< double, gray_alpha_layout_t > gray_alpha64f_pixel_t;
#endif // BOOST_GIL_IO_ENABLE_GRAY_ALPHA
typedef pixel< double, rgb_layout_t        > rgb64f_pixel_t;
typedef pixel< double, rgba_layout_t       > rgba64f_pixel_t;

typedef image< gray64f_pixel_t      , false > gray64f_image_t;

#ifdef BOOST_GIL_IO_ENABLE_GRAY_ALPHA
typedef image< gray_alpha32f_pixel_t, false > gray_alpha32f_image_t;
typedef image< gray_alpha32f_pixel_t, true  > gray_alpha32f_planar_image_t;
typedef image< gray_alpha64f_pixel_t, false > gray_alpha64f_image_t;
typedef image< gray_alpha64f_pixel_t, true  > gray_alpha64f_planar_image_t;
#endif // BOOST_GIL_IO_ENABLE_GRAY_ALPHA
typedef image< rgb64f_pixel_t       , false > rgb64f_image_t;
typedef image< rgb64f_pixel_t       , true  > rgb64f_planar_image_t;
typedef image< rgba64f_pixel_t      , false > rgba64f_image_t;
typedef image< rgba64f_pixel_t      , true  > rgba64f_planar_image_t;

} // namespace gil
} // namespace boost

#endif // BOOST_GIL_EXTENSION_IO_BASE_HPP
