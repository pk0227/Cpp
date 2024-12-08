/*

terminate called after throwing an instance of 'std::invalid_argument'
  what():  Invalid argument: value is zero
Program terminated with signal: SIGSEGV

*/

#include <iostream>
#include <stdexcept>

class classA
{
    public:
        void close(int value)
        {   
            if (value == 0) {
                throw std::invalid_argument("Ianvalid argument: value is zero");
            } else if (value == 1) {
                throw std::out_of_range("Out of range: value is one");
            } else if (value == 2) {
                throw std::runtime_error("Runtime error: value is two");
            } else {
                throw 42; // Throwing an unknown exception (int)
            }
        }
};

class base
{
    public:
        base()
        {
            std::cout << "cons--base called." << std::endl;
        }
        void greet()
        {
            std::cout << "Hi All." << std::endl;
        }
        virtual ~base()
        {
            std::cout << "des--base called." << std::endl;
        }
};

class derived : public base
{
    private:
        classA a;
    public:
        derived()
        {
            std::cout << "cons--derived called." << std::endl;
        }
        virtual ~derived()
        {
            a.close(0);
            std::cout << "des--derived called." << std::endl;
        }
};

void testFunction() {
    base *bp = new derived;
    std::cout << "==================>" << std::endl;
    delete bp;
}

int main(int argc, char **argv)
{

    try {
        testFunction();
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught an invalid_argument exception: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught an out_of_range exception: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Caught a runtime_error exception: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Caught an unknown exception" << std::endl;
    }
    
    
    return 0;
}