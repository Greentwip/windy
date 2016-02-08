#ifndef windy_tmx_parser
#define windy_tmx_parser

#include <map>
#include <string>
#include <vector>

#include "boost/gil/image.hpp"
#include "boost/gil/typedefs.hpp"

namespace windy{
	class tmx_converter;
}

class windy::tmx_converter{
public:
	bool lookup(const boost::gil::image_view<boost::gil::rgba8c_planar_loc_t>& a,
				unsigned long long& index);

	//int resize_texture(const std::vector<std::string>& args);
	int run(const std::vector<std::string>& args);

private:
	std::map<std::string, unsigned long long> computed_hashes;
};

#endif
