/*
    Copyright 2007-2008 Andreas Pokorny, Christian Henning
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
*/

/*************************************************************************************************/

#ifndef BOOST_GIL_EXTENSION_IO_DETAIL_PATH_SPEC_HPP
#define BOOST_GIL_EXTENSION_IO_DETAIL_PATH_SPEC_HPP

////////////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief
/// \author Andreas Pokorny, Christian Henning \n
///
/// \date   2007-2008 \n
///
////////////////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <malloc.h>
#include <string>

#include <boost/mpl/bool_fwd.hpp>

#ifdef BOOST_GIL_IO_ADD_FS_PATH_SUPPORT
#define BOOST_FILESYSTEM_VERSION 3
#include <boost/filesystem/path.hpp>
#endif // BOOST_GIL_IO_ADD_FS_PATH_SUPPORT

namespace boost{ namespace gil{ namespace detail{

template<typename P> struct is_supported_path_spec       : mpl::false_ {};
template<> struct is_supported_path_spec< std::string >  : mpl::true_ {};
template<> struct is_supported_path_spec< const std::string >  : mpl::true_ {};
template<> struct is_supported_path_spec< std::wstring > : mpl::true_ {};
template<> struct is_supported_path_spec< const std::wstring > : mpl::true_ {};
template<> struct is_supported_path_spec< const char* >  : mpl::true_ {};
template<> struct is_supported_path_spec< char* >        : mpl::true_ {};
template<> struct is_supported_path_spec< const wchar_t* >  : mpl::true_ {};
template<> struct is_supported_path_spec< wchar_t* >        : mpl::true_ {};

template<int i> struct is_supported_path_spec<const char [i]> : mpl::true_ {};
template<int i> struct is_supported_path_spec<char [i]> : mpl::true_ {};
template<int i> struct is_supported_path_spec<const wchar_t [i]> : mpl::true_ {};
template<int i> struct is_supported_path_spec<wchar_t [i]> : mpl::true_ {};

#ifdef BOOST_GIL_IO_ADD_FS_PATH_SUPPORT
template<> struct is_supported_path_spec< filesystem::path > : mpl::true_ {};
template<> struct is_supported_path_spec< const filesystem::path > : mpl::true_ {};
#endif // BOOST_GIL_IO_ADD_FS_PATH_SUPPORT


///
/// convert_to_string
///

inline std::string convert_to_string( std::string const& obj)
{
   return obj;
}

inline std::string convert_to_string( std::wstring const& s )
{
	std::size_t len = wcslen( s.c_str() );
	char* c = reinterpret_cast<char*>( alloca( len ));
	wcstombs( c, s.c_str(), len );

    return std::string( c, c + len );
}

inline std::string convert_to_string( const char* str )
{
    return std::string( str );
}

inline std::string convert_to_string( char* str )
{
    return std::string( str );
}

#ifdef BOOST_GIL_IO_ADD_FS_PATH_SUPPORT
inline std::string convert_to_string( const filesystem::path& path )
{
    return convert_to_string( path.string() );
}
#endif // BOOST_GIL_IO_ADD_FS_PATH_SUPPORT

///
/// convert_to_native_string
///

inline const char* convert_to_native_string( char* str )
{
    return str;
}

inline const char* convert_to_native_string( const char* str )
{
    return str;
}

inline const char* convert_to_native_string( const std::string& str )
{
   return str.c_str();
}

inline const char* convert_to_native_string( const wchar_t* str )
{
    std::size_t len = wcslen( str ) + 1;
    char* c = new char[len];
    wcstombs( c, str, len );

    return c;
}

inline const char* convert_to_native_string( const std::wstring& str )
{
    std::size_t len = wcslen( str.c_str() ) + 1;
    char* c = new char[len];
    wcstombs( c, str.c_str(), len );

    return c;
}

#ifdef BOOST_GIL_IO_ADD_FS_PATH_SUPPORT
inline const char* convert_to_native_string( const filesystem::path& path )
{
    ///@todo this leaks
    return convert_to_native_string( path.wstring() );
}
#endif // BOOST_GIL_IO_ADD_FS_PATH_SUPPORT

} // namespace detail
} // namespace gil
} // namespace boost

#endif // BOOST_GIL_EXTENSION_IO_DETAIL_PATH_SPEC_HPP
