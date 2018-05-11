//basic data input module - input.c

void Input(void)
{
    FILE *fp;
    if ((fp = fopen("data.dat", "r+")) == NULL)
    {
	printf("Failed to open database.\n");
	return;
    }
    int i, n, l = 0;
    char buf[1000];
    while (fgets(buf, 1000, fp))
	l++;
    printf("How many items:");
    scanf("%d", &n);
    struct pdata data[n];
    for (i = 0; i < n; i++)
    {
	printf("Item %d\n", i + 1);
	data[i].ID = l + 1;
	l++;
	printf("\tSerial Number>>>"), scanf("%d", &data[i].sn);
	printf("\tName>>>"), scanf("%s", data[i].name);
	printf("\tUnit>>>"), scanf("%s", data[i].unit);
	printf("\tStock Units>>>"), scanf("%d", &data[i].stock_units);
	printf("\tSales Units>>>"), scanf("%d", &data[i].sales_units);
	data[i].remaining_units = data[i].stock_units - data[i].sales_units;
	printf("\tStock Price>>>"), scanf("%lf", &data[i].stock_price);
	printf("\tSales Price>>>"), scanf("%lf", &data[i].sales_price);
	data[i].profit = data[i].sales_price - data[i].stock_price;
	printf("\tExpiration Date>>>"), scanf("%d", &data[i].expiration_date), printf("\n");
	fprintf(fp, "%d\t%d\t%s\t%s\t%d\t%d\t%d\t%lf\t%lf\t%lf\t%d\n", data[i].ID, data[i].sn, data[i].name, data[i].unit, data[i].stock_units, data[i].sales_units, data[i].remaining_units, data[i].stock_price, data[i].sales_price, data[i].profit, data[i].expiration_date);
    }
    fclose(fp);
}
