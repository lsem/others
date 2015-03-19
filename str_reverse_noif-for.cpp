
#include <cstdio>
#include <cstdlib>
#include <memory>

//
// TODO: Fix empty string case
//


void reverse(const char *input, size_t size, char *destination, size_t length);

void break_fn(const char *input, size_t size, char *destination, size_t length)
{
    destination[length] = 0;
};

void continue_fn(const char *input, size_t size, char *destination, size_t length)
{
    char nextChar = *(input + size);
    destination[length - size - 1] = nextChar;
    reverse(input, size, destination, length);
}

typedef void(*ReverseFnType)(const char *input, size_t size, char *destination, size_t length);

void reverse(const char *input, size_t size, char *destination, size_t length)
{
    ReverseFnType fns[2] = { continue_fn, break_fn };
    fns[(length - size) / length](input, size - 1, destination, length);
}

#define STRING_SIZE(Str) (sizeof(Str) - 1)

int main(int argc, char* argv[])
{
    char reversed[128] = { 1 };
    std::memset(&reversed, 1, sizeof(reversed));

    reverse("test", STRING_SIZE("test"), reversed, STRING_SIZE("test"));
    
    std::printf("result: '%s'\n", reversed);

	return 0;
}
