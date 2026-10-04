# Simple-IOS-Developer-Kits

### Tutorial

- InOut:
```C
#include "InOut.h"

int main(void) {
    char name[64];
    
    in("your name? ", name, sizeof name);     // input
    
    out("Hello %s!\n", name);                 // print (output)
    return 0;
}
```

-