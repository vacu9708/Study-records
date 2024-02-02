#include "OpenAddressing.h"

int main(void)
{
    HashTable* HT = OAHT_CreateHashTable(10);

    OAHT_Set(&HT, "MSFT", "Microsoft Corporation");
    OAHT_Set(&HT, "JAVA", "Sun Microsystems");
    OAHT_Set(&HT, "REDH", "Red Hat Linux");
    OAHT_Set(&HT, "APAC", "Apache Org");
    OAHT_Set(&HT, "ZYMZZ", "Unisys Ops Check");

    printf("Key(MSFT) : %s\n", OAHT_Get(HT, "MSFT"));
    printf("Key(JAVA) : %s\n", OAHT_Get(HT, "JAVA"));
    printf("Key(REDH) : %s\n", OAHT_Get(HT, "REDH"));
    printf("Key(APAC) : %s\n", OAHT_Get(HT, "APAC"));
    printf("Key(ZYMZZ) : %s\n", OAHT_Get(HT, "ZYMZZ"));

    OAHT_DestroyHashTable(HT);

    return 0;
}