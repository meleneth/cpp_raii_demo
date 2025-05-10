#pragma once

#include <string>

class FileContents {
public:
    explicit FileContents(const std::string& filename);

    const std::string& filename() const;
    const std::string& contents() const;
    ~FileContents();

private:
    std::string filename_;
    std::string contents_;
};

