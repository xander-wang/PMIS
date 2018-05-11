//basic data output module - output.c

void Output(void)
{
    FILE *fp;
    int ID;
    int sn;
    char name[50];
    char unit[10];
    int stock_units;
    int sales_units;
    int remaining_units;
    double stock_price;
    double sales_price;
    double profit;
    int expiration_date;
    if ((fp = fopen("data.dat", "r+")) == NULL)
    {
        printf("Failed to open database.\n");
        return;
    }
    printf("ID\tsn\t\tname\t\tunit\tstock units\tsales units\tremaining units\tstock price\tsales price\tprofit\t\texpiration date\n");
    while (!feof(fp))
    {
        fscanf(fp, "%d\t%d\t%s\t%s\t%d\t%d\t%d\t%lf\t%lf\t%lf\t%d\n", &ID, &sn, name, unit, &stock_units, &sales_units, &remaining_units, &stock_price, &sales_price, &profit, &expiration_date);
        printf("%d\t%d\t\t%s\t\t%s\t%d\t\t%d\t\t%d\t\t%lf\t%lf\t%lf\t%d\n", ID, sn, name, unit, stock_units, sales_units, remaining_units, stock_price, sales_price, profit, expiration_date);
    }
    printf(">>>>%d Record(s) In Total\n", ID);
    fclose(fp);
}