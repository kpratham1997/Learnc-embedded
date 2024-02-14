#include <stdio.h>
#include <assert.h>

int main() {
    int x = 5;
    assert(x == 10); // This assertion will fail

    printf("This line will not be executed due to the failed assertion.\n");

    return 0;
}
