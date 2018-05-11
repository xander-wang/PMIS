//PMIS main - main.c

#include <stdio.h>
#include "modules/data_struct.h"
#include "modules/input.c"
#include "modules/output.c"
#include "modules/sort.c"
#include "modules/locator.c"

int main(void)
{
    //declerations:
    int main_option, sort_option, key_option, sn;
    struct pdata data[10000];

    //interactive shell:
    printf("\nWelcome to PMIS - Version 1.0.0.\n");
loop:
    printf("\nFunction Selection Menu:\n[1]Data Entering\n[2]Data Viewer\n[3]Data Sorting\n[4]Data Locator\n[5]Exit PMIS v1.0.0\n\n");
    printf(">>>");
    scanf("%d", &main_option);
    switch (main_option)
    {
    case 1:
    {
        Input();
        goto loop;
    }
    break;
    case 2:
    {
        Output();
        goto loop;
    }
    break;
    case 3:
    {
        printf("\nPMIS Data Sorting Tool v1.0.0\nPlease choose a key to sort:\n[0]ID\n[1]Serial Number\n[2]Name\n[3]Unit\n[4]Stock Units\n[5]Sales Units\n[6]Remaining Units\n[7]Stock Price\n[8]Sales Price\n[9]Profit\n[10]Expiration Date\n\n>>>");
        scanf("%d", &key_option);
        if (key_option < 0 || key_option > 10)
            goto loop;
        printf("\nWhich way to sort:\n[0]Ascending(0-1)\n[1]Descending(1-0)\n\n>>>");
        scanf("%d", &sort_option);
        if (sort_option < 0 || sort_option > 1)
            goto loop;
        Sort(key_option, sort_option);
        goto loop;
    }
    break;
    case 4:
    {
        printf("\nPMIS Data Locator v1.0.0\nPlease enter Serial Number to continue:\n>>>");
        scanf("%d", &sn);
        Locator(sn);
        goto loop;
    }
    break;
    case 5:
    {
        printf("\nExiting PMIS......\n");
        return 0;
    }
    break;
    default:
    {
        printf("\nWrong Command.\n");
        goto loop;
    }
    break;
    }
}
