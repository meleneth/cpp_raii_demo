#include <iostream>
#include <memory>

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
}
