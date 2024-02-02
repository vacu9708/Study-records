#include "Chaining.h"

int main(void)
{
    HashTable* HT = CHT_CreateHashTable(12289);

    CHT_Set(HT, "MSFT", "Microsoft Corporation");
    CHT_Set(HT, "JAVA", "Sun Microsystems");
    CHT_Set(HT, "REDH", "Red Hat Linux");
    CHT_Set(HT, "APAC", "Apache Org");
    CHT_Set(HT, "ZYMZZ", "Unisys Ops Check");

    printf("Key:%s, Value:%s\n", "MSFT", CHT_Get(HT, "MSFT"));
    printf("Key:%s, Value:%s\n", "JAVA", CHT_Get(HT, "JAVA"));
    printf("Key:%s, Value:%s\n", "REDH", CHT_Get(HT, "REDH"));
    printf("Key:%s, Value:%s\n", "APAC", CHT_Get(HT, "APAC"));
    printf("Key:%s, Value:%s\n", "ZYMZZ", CHT_Get(HT, "ZYMZZ"));

    CHT_DestroyHashTable(HT);

    return 0;
}