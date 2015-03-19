
#include <cstdio>
#include <cstdlib>
#include <memory>


void reverse(char *input, size_t size, char *destination, size_t length);

void break_fn(char *input, size_t size, char *destination, size_t length)
{
    destination[length] = 0;
};

void continue_fn(char *input, size_t size, char *destination, size_t length)
{
    char nextChar = *(input + size);
    
    reverse(input, size, destination, length);
    
    input[length - size - 1] = nextChar;
}

typedef void(*ReverseFnType)(char *input, size_t size, char *destination, size_t length);

void reverse(char *input, size_t size, char *destination, size_t length)
{
    ReverseFnType fns[2] = { continue_fn, break_fn };
    fns[(length - size) / length](input, size - 1, destination, length);
}

#define STRING_SIZE(Str) (sizeof(Str) - 1)

int main(int argc, char* argv[])
{
    char reversed[128] = { 1 };
    std::memset(&reversed, 1, sizeof(reversed));

    const char *input = "test";
    char *buffer = new char[strlen(input)];
    strcpy(buffer, input);

    reverse(buffer, strlen(buffer), reversed, strlen(buffer));
    
    std::printf("result: '%s'\n", reversed);

    return 0;
}
