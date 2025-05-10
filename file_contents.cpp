#include "file_contents.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

FileContents::FileContents(const std::string& filename) : filename_(filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    contents_ = buffer.str();
}

const std::string& FileContents::filename() const {
    return filename_;
}

const std::string& FileContents::contents() const {
    return contents_;
}


