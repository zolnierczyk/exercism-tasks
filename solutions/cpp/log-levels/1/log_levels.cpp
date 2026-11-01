#include <string>

namespace log_line {
std::string message(std::string line) {
    auto index = line.find("]: ");
    if (index != 0)
    {
        return line.substr(index + 3);
    }
    return {};
}

std::string log_level(std::string line) {
    if (line.size() > 1 )
    {
        auto index = line.find("]");
        if (index != 0)
        {
            return line.substr(1, index - 1);    
        }
    }
    return {};
}

std::string reformat(std::string line) {
    std::string lvl = log_level(line);
    std::string msg = message(line);

    return msg + " (" + lvl + ")";
}
}  // namespace log_line
