//data locator module - locator.c
//locate specific item based on provided 'Serial Number'

void Locator(int sn)
{
    //load data from file to struct for sorting:
    int i, s, index, l = 0;
    FILE *fp;
    char buf[1000];
    if ((fp = fopen("data.dat", "r+")) == NULL)
    {
        printf("Failed to open database.\n");
        return;
    }

    //get lines in data.dat:
    while (fgets(buf, 1000, fp))
        l++;

    //internal struct declearation:
    struct pdata data[l];

    //reset file pointer:
    rewind(fp);

    //get data from file, load data to struct:
    while (!feof(fp))
        for (i = 0; i < l; i++)
            fscanf(fp, "%d\t%d\t%s\t%s\t%d\t%d\t%d\t%lf\t%lf\t%lf\t%d\n", &data[i].ID, &data[i].sn, data[i].name, data[i].unit, &data[i].stock_units, &data[i].sales_units, &data[i].remaining_units, &data[i].stock_price, &data[i].sales_price, &data[i].profit, &data[i].expiration_date);
    fclose(fp);

    //Locator:
    for (i = 0; i < l; i++)
        if (sn == data[i].sn)
        {
            printf("\nID\tsn\t\tname\t\tunit\tstock units\tsales units\tremaining units\tstock price\tsales price\tprofit\t\texpiration date\n");
            printf("%d\t%d\t\t%s\t\t%s\t%d\t\t%d\t\t%d\t\t%lf\t%lf\t%lf\t%d\n", data[i].ID, data[i].sn, data[i].name, data[i].unit, data[i].stock_units, data[i].sales_units, data[i].remaining_units, data[i].stock_price, data[i].sales_price, data[i].profit, data[i].expiration_date);
            return;
        }
    printf("\nNo matching item.");
    return;
}