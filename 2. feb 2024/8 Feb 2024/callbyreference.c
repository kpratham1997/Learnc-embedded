#include <stdio.h>

// B() now uses a reference parameter -- a pointer to
// the value of interest. B() uses a dereference (*) on the
// reference parameter to get at the value of interest.
void B(int* worthRef) {       // reference parameter
    *worthRef = *worthRef + 1; // use * to get at value of interest // T2
}

void A() {
    int netWorth;
    netWorth = 55; // T1 -- the value of interest is local to A()

    B(&netWorth);  // Pass a pointer to the value of interest.
                   // In this case using &.
    // T3 -- B() has used its pointer to change the value of interest

    printf("Net Worth after calling B(): %d\n", netWorth);
}

int main() {
    A();
    return 0;
}
