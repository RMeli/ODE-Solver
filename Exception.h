#include <exception>
#include <functional>

class Unsolved : public std::exception
{
public:
    const char* what() const noexcept
    {
        return "Unsolved ODE.";
    }
};

class Undefined : public std::bad_function_call
{
public:
    const char* what() const noexcept
    {
        return "Undefined equation to solve.";
    }
};