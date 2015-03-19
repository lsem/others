#include <cstdio>
#include <cstdlib>
#include <memory>
#include <malloc.h>
#include <cstring>

//
// TODO: Fix empty string case (using the same technique for branching)
//


namespace implementation {

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

    typedef void(*ReverseFnType)(char *input, size_t size, size_t length);

    void reverse(char *input, size_t size, size_t length)
    {
        ReverseFnType fns[2] = { continue_fn, break_fn };
        fns[(length - size) / length](input, size - 1, length);
    }

}

void reverse_inplace(char *inputstr, size_t size)
{
    implementation::reverse(inputstr, size, size);
}

int main(int argc, char* argv[])
{
    const char *input = "test";

    char *buffer = (char*) _alloca(strlen(input));
    strcpy(buffer, input);

    reverse_inplace(buffer, strlen(buffer));
    
    std::printf("result: '%s'\n", buffer);

	return 0;
}
