#ifndef windy_filesystem
#define windy_filesystem

#include <string>
#include <vector>

namespace windy {
	class path {
	public:
		static std::string file_name(const std::string& input) {
			std::vector<std::string> tokens;

			std::string buffer;
			for (auto character : input) {

				if (character == '\\') {
					tokens.push_back(buffer);
					buffer.clear();
				}
				else {
					buffer.push_back(character);
				}
			}

			tokens.push_back(buffer);

			auto back = tokens.back();

			return back;
		}

		static std::string raw_name(const std::string& input)
		{
			auto name = path::file_name(input);

			return std::string(name.begin(), name.end() - 4);
		}

		static std::string extension(const std::string& input) {
			auto name = path::file_name(input);

			return std::string(name.end() - 4, name.end());
		}
	};

}


#endif