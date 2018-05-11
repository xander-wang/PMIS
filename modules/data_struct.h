//basic data structure definition - data_struct.h

struct pdata
{
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
};
