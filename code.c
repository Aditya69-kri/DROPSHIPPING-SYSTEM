#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct supplier
{
    char name[100], product[500], add[1000];
    long pno;
    int orderno, quantity;
    float weight, cost, sale;
} s;
struct costumer
{
    char name1[100];
    char product1[500];
    char add1[1000];
    char pno1[100];
    int quantity1;
} s1;
/*decleration of functions for inserting, displaying,searching and deleting the records of the costumer*/
void insert_record1();
void display_record1();
void search_record1();
void delete_record1();
// structure to store the data of costumer like name, address, phone number,etc. of the costumer.
int main()
{
    char ans;
    printf("ENTER TO SEE CUSTOMER (C) OR SUPPLIER (S) DATA??");
    scanf("%c", &ans);
    while (ans == 'C' || ans == 'c')
    {
        char ans;
        printf("ENTER TO SEE CUSTOMER (C) OR SUPPLIER (S) DATA??");
        scanf("%c", &ans);
        struct costumer s1;
        printf("________________________________________________DROPSHIPPING SYSTEM_______________________________________________________");
        printf("\n");
        printf("\n");
        // password to make the record secure
        int pass;
        printf("\n");
        printf("Enter the password to access your record : ");
        scanf("%d", &pass);
        int y = 1234;
        if (pass == y)
        {
            long int size = sizeof(s1);
            int ch, c;
            printf("\n");
            printf("Press 1 to access the record or press 0 to exit!!!!!!!!!");
            printf("\n");
            scanf("%d", &c);
            if (c == 0)
            {
                printf("\n");
                printf("<<<<<<<Exiting from the record>>>>>>>>>");
                return 0;
            }
            // Use of do while loop to take the choice of user at least once.
            do
            {
                printf("\n1.INSERT\n");
                printf("2.DISPLAY\n");
                printf("3.SEARCH\n");
                printf("4.DELETE\n");
                printf("5.EXIT\n");
                printf("\n");
                printf("Enter your choice=");
                scanf("%d", &ch);
                switch (ch)
                {
                // calling the functions to ask the user to choice
                case 1:
                    printf("\n");
                    insert_record1();
                    break;
                case 2:
                    printf("\n");
                    display_record1();
                    break;
                case 3:
                    printf("\n");
                    search_record1();
                    break;
                case 4:
                    printf("\n");
                    delete_record1();
                    break;
                case 5:
                    printf("\n");
                    printf("<<<<<<<Exiting from the record>>>>>>>>>");
                    return 0;
                default:
                    printf("\n");
                    printf("Incompitable input ");
                    return 0;
                }
                printf("\n");
                printf("Press any key to continue.");
                printf("\n");
                continue;
            } while (c == 1);
            // Decrement of c to stop the do while loop from 1 to 0.
            c--;
        }
        else
        {
            printf("\n");
            printf(".............................    WRONG   PASSWORD   .............................");
            printf("\n");
        }
    }
    if (ans == 's' || ans == 'S')
    {
        // a structure supplier with instace as s
        struct supplier s;
        long int size = sizeof(s);
        int cho;
        printf("\n1.INSERT\n");
        printf("2.DISPLAY\n");
        printf("3.SEARCH\n");
        printf("4.DELETE\n");
        printf("5.EXIT\n");
        printf("\n");
        int c;
        printf("________________________________________________DROPSHIPPING SYSTEM_______________________________________________________");
        printf("\n");
        printf("\n");
        printf("\nWANTS TO PERFORM Y(1)/N(0)=");
        // c=Enter 1 if want to continue and 0 if want to end the program
        scanf("%d", &c);
        printf("\n1.INSERT\n");
        printf("2.DISPLAY\n");
        printf("3.SEARCH\n");
        printf("4.DELETE\n");
        printf("5.CALCULATE PROFIT OF EVERY CUSTOMER\n");
        printf("6.MODIFY RECORD\n");
        printf("\n");
        printf("\n");
        while (c == 1)
        {
            printf("Enter your choice=");
            scanf("%d", &cho);
            printf("\n1.INSERT\n");
            printf("2.DISPLAY\n");
            printf("3.SEARCH\n");
            printf("4.DELETE\n");
            printf("5.CALCULATE PROFIT OF EVERY CUSTOMER\n");
            printf("6.MODIFY RECORD\n");
            printf("7.Exit");
            printf("\n");
            switch (cho)
            {
            case 1:
                insert_records();
                break;
            case 2:
                display_records();
                break;
            case 3:
                search_records();
                break;
            case 4:
                delete_records();
                break;
            case 5:
                profit();
                break;
            case 6:
                modify();
                break;
            default:
                printf("Thank You....PROGRAMME IS OVER.......");
                break;
            }
            printf("\n");
            printf("WANTS TO PERFORM Y(1)/N(0)=");
            scanf("%d", &c);
            printf("\n\n");
        }
        return 0;
    }
}
// definitions of the above functions
void insert_record1()
{
    // function to add the costumer record
    // making a copy of structure costumer as s1
    struct costumer s1;
    FILE *ptr;
    // use of file handling in binary format to store our costumer data with high security.
    ptr = fopen("sdf5.txt", "ab");
    if (ptr == NULL)
    {
        printf("\n");
        printf("Error-No file found....");
        return;
    }
    printf("***********************************Costumer new data*****************************************\n");
    printf("\n");
    fflush(stdin);
    printf("Enter costumer name:");
    gets(s1.name1);
    fflush(stdin);
    printf("\n");
    printf("Enter product name:");
    gets(s1.product1);
    fflush(stdin);
    printf("\n");
    printf("Enter costumer address:");
    gets(s1.add1);
    fflush(stdin);
    printf("\n");
    printf("Enter costumer conatct number i.e. 10 digit number:");
    gets(s1.pno1);
    fflush(stdin);
    printf("\n");
    printf("Enter quantity of the product:");
    scanf("%d", &s1.quantity1);
    fflush(stdin);
    printf("\n");
    fwrite(&s1, sizeof(s1), 1, ptr);
    printf("\n");
    printf("..................................RECORD ADDED SUCCESSFULLY......................................");
    printf("\n");
    printf("\n");
    fclose(ptr);
}
void display_record1()
{
    struct costumer s1;
    // Function to display record of all the costumers
    long size = sizeof(s1);
    FILE *ptr;
    ptr = fopen("sdf5.txt", "rb");
    if (ptr == NULL)
    {
        printf("\n");
        printf("Cannot open the file.");
        printf("\n");
        return;
    }

    printf("\n************************************************Costumer records*******************************************************\n");
    printf("COSTUMER\t  ");
    printf("PRODUCT\t ");
    printf("ADDRESS\t  ");
    printf("CONTACT\t ");
    printf("QUANTITY ");
    printf("\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    while (1)
    {
        fread(&s1, size, 1, ptr);
        if (feof(ptr))
        {
            break;
        }
        printf("%s\t\t ", s1.name1);
        printf("%s\t    ", s1.product1);
        printf("%s\t  ", s1.add1);
        printf("%ld\t    ", s1.pno1);
        printf("%d\t ", s1.quantity1);
        printf("\n");
        printf("-------------------------------------------------------------------------------------------------------------------------\n");
    }

    fclose(ptr);
}
void search_record1()
{
    // function for searching the costumer data
    struct costumer s1;
    long size = sizeof(s1);
    FILE *ptr;
    ptr = fopen("sdf5.txt", "rb");
    char namesearch[100];
    printf("Enter name of costumer to be searched:");
    fflush(stdin);
    gets(namesearch);
    int f = 0;
    while ((fread(&s1, size, 1, ptr) == 1))
    {
        if (strcmp(namesearch, s1.name1) == 0)
        {
            f = 1;
            printf("\n");
            printf(".................................................RECORD FOUND.....................................................");
            printf("\n");
            printf("\n");
            printf("-------------------------------------------------------------------------------------------------------------------------\n");
            printf("COSTUMER    PRODUCT     ADDRESS    CONTACT    QUANTITY \n");
            printf("-------------------------------------------------------------------------------------------------------------------------\n");
            printf("\n");
            printf("%s\t   ", s1.name1);
            printf("%s     ", s1.product1);
            printf(" %s      ", s1.add1);
            printf("%ld    ", s1.pno1);
            printf("%d\t", s1.quantity1);
            printf("\n");
            printf("-------------------------------------------------------------------------------------------------------------------------\n");
            printf("\n");
        }
    }
    if (f == 0)
    {
        printf("\n");
        printf(".........................RECORD NOT FOUND............................");
        printf("\n");
    }
    fclose(ptr);
}
void delete_record1()
{
    // function for deleting the record of the costumer
    char ndelete[20];
    FILE *ptr, *fp;
    struct costumer s1;
    int flag = 0;
    printf("Enter name of costumer to be deleted:");
    fflush(stdin);
    gets(ndelete);
    ptr = fopen("sdf5.txt", "rb+");
    if (ptr == NULL)
    {
        printf("Cannot open the file.");
    }
    fp = fopen("sdf2.txt", "wb+");
    if (fp == NULL)
    {
        printf("Cannot open the file.");
    }
    while (fread(&s1, sizeof(s1), 1, ptr) == 1)
    {
        if (strcmp(ndelete, s1.name1) != 0)
        {
            fwrite(&s1, sizeof(s1), 1, fp);
            flag = 1;
        }
    }
    printf("\n");
    printf("********RECORD DELETED SUCCESSFULLY*********");
    printf("\n");
    if (flag == 0)
    {
        printf("<<<<<<<<<<<NO RECORD FOUND>>>>>>>>>>>>");
        printf("\n");
    }
    fclose(ptr);
    fclose(fp);
    remove("sdf5.txt");
    rename("sdf2.txt", "sdf5.txt");
    printf("\n");
    printf("RECORD UPDATED");
    printf("\n");
    printf("\n");
}
void insert_records()
{
    struct supplier s;
    FILE *ptr;
    ptr = fopen("sdf.txt", "ab");
    if (ptr == NULL)
    {
        printf("Error-No file found....");
        return;
    }
    int n;
    printf("Enter number of data you want to enter:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("*************************************Supplier new data****************************************\n");
        printf("\n");
        s.orderno = i;
        fflush(stdin);
        printf("\n");
        printf("Enter weight in grams:");
        scanf("%f", &s.weight);
        fflush(stdin);
        printf("\n");
        printf("Enter product name:");
        gets(s.product);
        fflush(stdin);
        printf("\n");
        printf("Enter supplier name:");
        gets(s.name);
        fflush(stdin);
        printf("\n");
        printf("Enter supplier address:");
        gets(s.add);
        fflush(stdin);
        printf("\n");
        printf("Enter supplier conatct number i.e. 10 digit number:");
        scanf("%ld", &s.pno);
        fflush(stdin);
        printf("\n");
        printf("Enter actual price:");
        scanf("%f", &s.cost);
        fflush(stdin);
        printf("\n");
        printf("Enter sale price:");
        scanf("%f", &s.sale);
        fflush(stdin);
        printf("\n");
        printf("Enter quantity:");
        scanf("%d", &s.quantity);
        fflush(stdin);
        printf("\n");
        fwrite(&s, sizeof(s), 1, ptr);
    }
    printf("\n.........................................RECORD ADDED SUCCESSFULLY..................................................\n");
    fclose(ptr);
}
void display_records()
{
    system("cls");
    struct supplier s;
    long size = sizeof(s);
    FILE *ptr;
    ptr = fopen("sdf.txt", "rb");
    if (ptr == NULL)
    {
        printf("\n");
        printf("Cannot open the file.\n");
        return;
    }

    printf("\n*************************************************Supplier records********************************************************\n");
    printf("ORDERNO\t  PRODUCT\t  SUPPLIER\t  ADDRESS\t  CONTACT\t COST_PRICE\tSALE_PRICE\tQUANTITY   WEIGHT\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    while (1)
    {
        fread(&s, size, 1, ptr);
        if (feof(ptr))
        {

            break;
        }
        printf("%d\t  %s\t  %s\t  %s\t  %ld\t  %.2f\t  %.2f\t  %d\t   %.2f\n", s.orderno, s.product, s.name, s.add, s.pno, s.cost, s.sale, s.quantity, s.weight);
    }

    fclose(ptr);
}

void search_records()
{
    system("cls");
    int ord;
    struct supplier s;
    long size = sizeof(s);
    FILE *ptr;
    ptr = fopen("sdf.txt", "rb");
    char namesearch[100];
    printf("Enter order number to be searched:");
    fflush(stdin);
    scanf("%d", &ord);
    int f = 0;
    while ((fread(&s, size, 1, ptr) == 1))
    {
        if (ord == s.orderno)
        {
            f = 1;
            printf("\n.........................RECORD FOUND............................\n");
            printf("\n");
            printf("ORDER_NO  PRODUCT  SUPPLIER  ADDRESS  CONTACT   COST_PRICE  SALE_RICE  QUANTITY  WEIGHT\n");
            printf("\n");
            printf("%d\t  %s   %s    %s  %ld   %.2f   %.2f\t  %d\t %.2f\n", s.orderno, s.product, s.name, s.add, s.pno, s.cost, s.sale, s.quantity, s.weight);
            printf("\n");
        }
    }
    if (f == 0)
    {
        printf("\nRECORD NOT FOUND");
        printf("\n");
    }
    fclose(ptr);
}
void delete_records()
{
    system("cls");
    char namedelete[20];
    FILE *ptr, *fp;
    struct supplier s;
    int flag = 0;
    printf("Enter name of supplier to be deleted:");
    fflush(stdin);
    gets(namedelete);
    ptr = fopen("sdf.txt", "rb+");
    if (ptr == NULL)
    {
        printf("Cannot open the file.");
    }
    fp = fopen("sdf1.txt", "wb+");
    if (fp == NULL)
    {
        printf("Cannot open the file.");
    }
    while (fread(&s, sizeof(s), 1, ptr) == 1)
    {
        if (strcmp(namedelete, s.name) != 0)
        {
            fwrite(&s, sizeof(s), 1, fp);
            flag = 1;
        }
    }
    printf("\n*********RECORD DELETED SUCCESSFULLY**********\n");
    if (flag == 0)
    {
        printf("<<<<<<<<<<<NO RECORD FOUND>>>>>>>>>>>>");
        printf("\n");
    }
    fclose(ptr);
    fclose(fp);
    remove("sdf.txt");
    rename("sdf1.txt", "sdf.txt");
    printf("\nRECORD UPDATED");
    printf("\n");
    printf("\n");
}
void profit()
{
    system("cls");
    struct supplier s;
    FILE *ptr;
    ptr = fopen("sdf.txt", "rb");
    if (ptr == NULL)
    {
        printf("\nCannot open the file.\n");
        return;
    }
    printf("\n*******************************************************Supplier records*****************************************************************\n");
    printf("ORDERNO\t  PRODUCT\t  SUPPLIER\t  ADDRESS\t  CONTACT\t COST_PRICE\tSALE_PRICE\tQUANTITY   WEIGHT\t PROFIT\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
    float sum = 0;
    while (1)
    {
        float profit;
        fread(&s, sizeof(s), 1, ptr);
        if (feof(ptr))
        {
            break;
        }
        profit = ((s.sale - s.cost) * s.weight * s.quantity) / 1000;
        printf("%d\t  %s\t  %s\t  %s\t  %ld\t  %.2f\t  %.2f\t  %d\t   %.2f\t %.2f\n", s.orderno, s.product, s.name, s.add, s.pno, s.cost, s.sale, s.quantity, s.weight, profit);
        sum = sum + profit;
    }
    printf("\n");
    printf("\n");
    printf("TOTAL PROFIT IS RS.%.2f.", sum);
    printf("\n");
    printf("\n");
    printf("\n");
    fclose(ptr);
}
void modify()
{
    FILE *ptr;
    struct supplier s;
    ptr = fopen("sdf.txt", "ab+");
    int flag = 0;
    int cho;
    char mo[30];
    printf("Enter 1 to modify....");
    scanf("%d", &cho);
    fflush(stdin);
    printf("\n");
    if (ptr == NULL)
    {
        printf("\nCannot open the file.\n");
        return;
    }
    else
    {
        printf("Enter name of costumer to be modified:");
        fflush(stdin);
        gets(mo);
        // scanf("%d",&mo);
        while (cho == 1)
        {
            while ((fread(&s, sizeof(s), 1, ptr) > 0) && flag == 0)
            {
                if (mo == s.name)
                {
                    flag = 1;
                    fflush(stdin);
                    printf("Enter weight in grams:");
                    scanf("%f", &s.weight);
                    fflush(stdin);
                    printf("\n");
                    printf("Enter product name:");
                    gets(s.product);
                    fflush(stdin);
                    printf("\n");
                    printf("Enter supplier name:");
                    gets(s.name);
                    fflush(stdin);
                    printf("\n");
                    printf("Enter supplier address:");
                    gets(s.add);
                    fflush(stdin);
                    printf("\n");
                    printf("Enter supplier conatct number i.e. 10 digit number:");
                    scanf("%ld", &s.pno);
                    fflush(stdin);
                    printf("\n");
                    printf("Enter actual price:");
                    scanf("%f", &s.cost);
                    fflush(stdin);
                    printf("\n");
                    printf("Enter sale price:");
                    scanf("%f", &s.sale);
                    fflush(stdin);
                    printf("\n");
                    printf("Enter quantity:");
                    scanf("%d", &s.quantity);
                    fflush(stdin);
                    printf("\n");
                    // fseek(ptr,sizeof(s),1);
                    fwrite(&s, sizeof(s), 1, ptr);
                }
                printf("\n.........................................RECORD UPDATED SUCCESSFULLY..................................................\n");
            }
        }
        if (flag == 0)
            printf("Something went wrong.....");
    }
    fclose(ptr);
}
