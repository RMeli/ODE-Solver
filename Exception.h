#include <exception>

class Unsolved : std::exception
{
public:
    const char* what() const noexcept
    {
        return "Unsolved ODE.";
    }
};