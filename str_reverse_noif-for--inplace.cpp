
#include <cstdio>
#include <cstdlib>
#include <memory>

//
// TODO: Fix empty string case
//


void reverse(char *input, size_t size, size_t length);

void break_fn(char *input, size_t size, size_t length)
{
};

void continue_fn(char *input, size_t size, size_t length)
{
    char nextChar = *(input + size);
    
    reverse(input, size, length);
    
    input[length - size - 1] = nextChar;
}

typedef void(*ReverseFnType)(char *input, size_t size,  size_t length);

void reverse(char *input, size_t size, size_t length)
{
    ReverseFnType fns[2] = { continue_fn, break_fn };
    fns[(length - size) / length](input, size - 1, length);
}

#define STRING_SIZE(Str) (sizeof(Str) - 1)

int main(int argc, char* argv[])
{
    const char *input = "test";
    char *buffer = new char[strlen(input)];
    strcpy(buffer, input);

    reverse(buffer, strlen(buffer), strlen(buffer));
    
    std::printf("result: '%s'\n", buffer);

	return 0;
}
