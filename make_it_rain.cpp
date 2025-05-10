#include <iostream>
#include <memory>

#include "file_contents.hpp"

class SomeClass {
public:
    SomeClass() {
        std::cout << "SomeClass constructed\n";
    }

    void doThing() {
        std::cout << "Doing something\n";
    }

    ~SomeClass() {
        std::cout << "SomeClass destructed\n";
    }
};

class OwnerClass {
public:
    OwnerClass() : some(std::make_unique<SomeClass>()) {
        std::cout << "OwnerClass constructed\n";
    }

    ~OwnerClass() {
        std::cout << "OwnerClass destructed\n";
    }

    void useIt() {
        some->doThing();
    }

private:
    std::unique_ptr<SomeClass> some;
};



int main(int argc, char **argv) {
    OwnerClass owner;
    owner.useIt();
    std::unique_ptr<FileContents> file; // will be nullptr
    for(int i = 0; i < 10; ++i) {
      file = std::make_unique<FileContents>("file_contents.cpp");
    }

    if(file) {
      std::cout << file->filename() << ": " << file->contents() << std::endl;
    }
}
