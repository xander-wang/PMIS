//key-based sort - sort.c

//key:
//keymap references:
/*
ID				0
sn				1
name			2
unit			3
stock_units		4		
sales_units		5
remaining_units	6
stock_price		7
sales_price		8
profit		    9
expiration_date	10
*/

//option:
//sort asc/desc:
/*
asc             0           <
desc            1           >
*/

void Sort(int key, int option)
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
    struct pdata t;

    //reset file pointer:
    rewind(fp);

    //get data from file, load data to struct:
    while (!feof(fp))
        for (i = 0; i < l; i++)
            fscanf(fp, "%d\t%d\t%s\t%s\t%d\t%d\t%d\t%lf\t%lf\t%lf\t%d\n", &data[i].ID, &data[i].sn, data[i].name, data[i].unit, &data[i].stock_units, &data[i].sales_units, &data[i].remaining_units, &data[i].stock_price, &data[i].sales_price, &data[i].profit, &data[i].expiration_date);
    fclose(fp);

    //sorting:
    if (option == 0)
    {
        switch (key)
        {
        case 0:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].ID < data[index].ID)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 1:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].sn < data[index].sn)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 2:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].name < data[index].name)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 3:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].unit < data[index].unit)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 4:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].stock_units < data[index].stock_units)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 5:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].sales_units < data[index].sales_units)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 6:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].remaining_units < data[index].remaining_units)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 7:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].stock_price < data[index].stock_price)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 8:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].sales_price < data[index].sales_price)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 9:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].profit < data[index].profit)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 10:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].expiration_date < data[index].expiration_date)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;
        }
    }
    else
    {
        switch (key)
        {
        case 0:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].ID > data[index].ID)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 1:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].sn > data[index].sn)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 2:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].name > data[index].name)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 3:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].unit > data[index].unit)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 4:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].stock_units > data[index].stock_units)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 5:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].sales_units > data[index].sales_units)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 6:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].remaining_units > data[index].remaining_units)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 7:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].stock_price > data[index].stock_price)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 8:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].sales_price > data[index].sales_price)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 9:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].profit > data[index].profit)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;

        case 10:
        {
            for (i = 0; i < l - 1; i++)
            {
                index = i;
                for (s = i + 1; s < l; s++)
                    if (data[s].expiration_date > data[index].expiration_date)
                        index = s;
                t = data[index];
                data[index] = data[i];
                data[i] = t;
            }
        }
        break;
        }
    }
    printf("\nSorting Result:\n");
    printf("ID\tsn\t\tname\t\tunit\tstock units\tsales units\tremaining units\tstock price\tsales price\tprofit\t\texpiration date\n");
    for (i = 0; i < l; i++)
        printf("%d\t%d\t\t%s\t\t%s\t%d\t\t%d\t\t%d\t\t%lf\t%lf\t%lf\t%d\n", data[i].ID, data[i].sn, data[i].name, data[i].unit, data[i].stock_units, data[i].sales_units, data[i].remaining_units, data[i].stock_price, data[i].sales_price, data[i].profit, data[i].expiration_date);
}