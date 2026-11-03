#include <string>
#include <string_view>
#include <algorithm>

namespace log_line {
std::string message(std::string_view line) {
    auto index = line.find("]: ");
    if (index != std::string_view::npos)
    {
        return std::string{line.substr(index + 3)};
    }
    return std::string{line};
}

std::string log_level(std::string_view line) {
    if (line.size() > 1 )
    {
        auto index = line.find("]");
        if (index != std::string_view::npos)
        {
            return std::string{line.substr(1, index - 1)};    
        }
    }
    return {};
}

std::string reformat(std::string_view line) {
    std::string lvl = log_level(line);
    std::string msg = message(line);

    std::transform(lvl.begin(), lvl.end(), lvl.begin(), 
        [](unsigned char c) { return std::toupper(c); });

    return msg + " (" + lvl + ")";
}
}  // namespace log_line
