#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WORNINGS



void menu();
void service();
void record();
void service_adding();
void payment();
void search();
void print_payment();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int opt;
    do {
        printf("\nMenu Options\n1. Display Service\n2. Write records\n3. Edit service\n4. Payment changing\n5. Searching customers\n6. Payment printing\n7. Exit\nPlease select an option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1: service();
            break;
        case 2: record();
            break;
        case 3: service_adding;
            break;
        case 4: payment();
            break;
        case 5: search();
            break;
        case 6: print_payment();
            break;
        case 7: exit(0);
        default: printf("Invalid input");
            break;
        }
    } while (opt != 7);
}

void service()
{
    printf("\t\t\t\t\t\t\t\tTypes of Services\n");
    printf("number\t" "Service Type\t\t\t\t\t\t\t" "Needed days\t" "Normal Fee\t" "Urgent Fee\t\n");
    printf("1\t" "Remove virus, malware or spyware\t\t\t" "2\t\t" "30 RM\t\t" "50 RM\n");
    printf("2\t" "Troubleshot and fix computer running slow\t" "2\t\t" "40 RM\t\t" "70 RM\n");
    printf("3\t" "Laptop screen replacement\t\t\t\t\t" "3\t\t" "380 RM\t\t" "430 RM\n");
    printf("4\t" "Laptop keyboard replacement\t\t\t\t\t" "2\t\t" "160 RM\t\t" "200 RM\n");
    printf("5\t" "Laptop battery replacement\t\t\t\t\t" "2\t\t" "180 RM\t\t" "210 RM\n");
    printf("6\t" "Operating System Format and Installation\t" "2\t\t" "50 RM\t\t" "80 RM\n");
    printf("7\t" "Data backup and recoveryt\t\t\t\t\t" "2\t\t" "100 RM\t\t" "150 RM\n");
    printf("8\t" "Internet connectivity issues\t\t\t\t" "1\t\t" "50 RM\t\t" "75 RM\n\n\n");
}

void record()
{
    int id;
    char name[30];
    char date[10];
    int service_number;
    int fee;
    int payment_made;
    int time_takes;
    int unpaid_payment;
    int i;

    FILE* fp;
    fp = fopen("visit.txt", "a");

    if (fp == NULL)
    {
        printf("Can not open the file!");
        exit(0);
    }

    for (i = 0; i <= 2; i++)
    {
        while (getchar() != '\n');
        printf("Enter customer id: ");
        scanf("%d", &id);
        fprintf(fp, "%d\n", id);

        printf("Enter customer name: ");
        scanf("%s", name);
        fprintf(fp, "%s\n", name);

        printf("Enter date (formate dd/mm/yy): ");
        scanf("%s", date);
        fprintf(fp, "%s\n", date);

        printf("Enter service needed number: ");
        scanf("%d", &service_number);
        fprintf(fp, "%d\n", service_number);

        printf("Enter working speed: ");
        scanf("%d", &time_takes);
        fprintf(fp, "%d\n", time_takes);

        printf("Enter fee: ");
        scanf("%d", &fee);
        fprintf(fp, "%d\n", fee);

        printf("Enter payment_made: ");
        scanf("%d", &payment_made);
        fprintf(fp, "%d\n", payment_made);

        printf("Enter unpaid payment: ");
        scanf("%d", &unpaid_payment);
        fprintf(fp, "%d\n", unpaid_payment);
    }

    fclose(fp);
}
void service_adding()
{
    int id=0;
    int new_id=0;
    char name[30];
    char date[10];
    int service_number=0;
    int new_service_number=0;
    int fee;
    int payment_made;
    int time_takes;
    int unpaid_payment;
    int i;

    FILE* fp1, * fp2;

    fp1 = fopen("visit.txt", "r");
    if (fp1 == NULL)
    {
        printf("Can not open the file!");
        exit(0);
    }

    fp2 = fopen("temp.txt", "a");
    if (fp2 == NULL)
    {
        printf("Can not open the file!");
        exit(0);
    }

    for (i = 0; i <=2; i++)
    {
        while (getchar() != '\n');
        printf("\n Please enter id of the customer to edit: ");
        scanf("%d", &new_id);
        printf("\n Please enter service need id of the customer to edit: ");
        scanf("%d", &new_service_number);
    }

    while (!feof(fp1))
    {
        fscanf(fp1, "%d\n", &id);
        fgets(name, 30, fp1);
        fgets(date, 10, fp1);
        fscanf(fp1, "%d\n", &service_number);
        fscanf(fp1, "%d\n", &time_takes);
        fscanf(fp1, "%d\n", &fee);
        fscanf(fp1, "%d\n", &payment_made);
        fscanf(fp1, "%d\n", &unpaid_payment);

        if (id == new_id)
        {
            service_number = new_service_number;
        }
        fprintf(fp2, "%d\n", id);
        fprintf(fp2, "%s", name);
        fprintf(fp2, "%s", date);
        fprintf(fp2, "%d\n", service_number);
        fprintf(fp2, "%d\n", time_takes);
        fprintf(fp2, "%d\n", fee);
        fprintf(fp2, "%d\n", payment_made);
        fprintf(fp2, "%d\n", unpaid_payment);
    }

    fclose(fp1);
    fclose(fp2);

    remove("visit.txt");
    rename("temp.txt", "visit.txt");
    printf("Updated\n");
}

void payment()
{
    int id;
    int new_id;
    char name[30];
    char date[10];
    int service_number;
    int fee;
    int payment_made;
    int time_takes;
    int unpaid_payment;
    int added_payment;
    int i;

    FILE* fp1, * fp2;

    fp1 = fopen("visit.txt", "r");
    if (fp1 == NULL)
    {
        printf("Can not open the file!");
        exit(0);
    }

    fp2 = fopen("payments_changes.txt", "a");
    if (fp2 == NULL)
    {
        printf("Can not open the file!");
        exit(0);
    }

    for (i = 0; i <= 1; i++)
    {
        while (getchar() != '\n');
        printf("\n Please enter id of the customer to edit: ");
        scanf("%d", &new_id);
        printf("\n Please enter added payment: ");
        scanf("%d", &added_payment);
    }

    while (!feof(fp1))
    {
        fscanf(fp1, "%d\n", &id);
        fgets(name, 20, fp1);
        fgets(date, 10, fp1);
        fscanf(fp1, "%d\n", &service_number);
        fscanf(fp1, "%d\n", &time_takes);
        fscanf(fp1, "%d\n", &fee);
        fscanf(fp1, "%d\n", &payment_made);
        fscanf(fp1, "%d\n", &unpaid_payment);

        if (id == new_id)
        {
            unpaid_payment = added_payment;
        }
        fprintf(fp2, "%d\n", id);
        fprintf(fp2, "%s", name);
        fprintf(fp2, "%s", date);
        fprintf(fp2, "%d\n", service_number);
        fprintf(fp2, "%d\n", time_takes);
        fprintf(fp2, "%d\n", fee);
        fprintf(fp2, "%d\n", payment_made);
        fprintf(fp2, "%d\n", unpaid_payment);

    }

    fclose(fp1);
    fclose(fp2);

    remove("visit.txt");
    rename("payments_changes.txt", "visit.txt");
    printf("Updated \n");
}

void search()
{
    int id;
    int new_id = 0;
    char name[30];
    char search_by_name[30];
    char date[10];
    int service_number;
    int fee;
    int payment_made;
    int time_takes;
    int unpaid_payment;
    int i;

    FILE* fp1, * fp2;

    fp1 = fopen("visit.txt", "r");
    if (fp1 == NULL)
    {
        printf("Can not open the file!");
        exit(0);
    }

    fp2 = fopen("search.txt", "a");
    if (fp2 == NULL)
    {
        printf("Can not open the file!");
        exit(0);
    }
    for (i = 0; i <= 1; i++)
    {
        while (getchar() != '\n');
        printf("\n Enter a name of the customer: ");
        scanf("%s", search_by_name);
    }

    while (!feof(fp1))
    {
        fscanf(fp1, "%d\n", &id);
        fgets(name, 20, fp1);
        fgets(date, 10, fp1);
        fscanf(fp1, "%d\n", &service_number);
        fscanf(fp1, "%d\n", &time_takes);
        fscanf(fp1, "%d\n", &fee);
        fscanf(fp1, "%d\n", &payment_made);
        fscanf(fp1, "%d\n", &unpaid_payment);

        if (strcmp(name, search_by_name) != 0)
        {
            printf("No records. Please enter another name: ");
        }
        fprintf(fp2, "%d\n", id);
        fprintf(fp2, "%s", name);
        fprintf(fp2, "%s", date);
        fprintf(fp2, "%d\n", service_number);
        fprintf(fp2, "%d\n", time_takes);
        fprintf(fp2, "%d\n", fee);
        fprintf(fp2, "%d\n", payment_made);
        fprintf(fp2, "%d\n", unpaid_payment);
    }

    fclose(fp1);
    fclose(fp2);

    printf("Updated \n");
}

void print_payment()
{
    int id;
    int new_id = 0;
    char name[30];
    char date[10];
    int service_number;
    int fee;
    int payment_made;
    int time_takes;
    int unpaid_payment;
    int i;

    FILE* fp1, *fp2;

    fp1 = fopen("visit.txt", "r");
    if (fp1 == NULL)
    {
        printf("Can not open the file!");
        exit(0);
    }

    fp2 = fopen("print.txt", "a");
    if (fp2 == NULL)
    {
        printf("Can not open the file!");
        exit(0);
    }
    for (i = 0; i <= 1; i++)
    {
        while (getchar() != '\n');
        printf("\n Please enter an id of the customer: ");
        scanf("%d", &id);
    }

    while (!feof(fp1))
    {
        fscanf(fp1, "%d\n", &id);
        fgets(name, 20, fp1);
        fgets(date, 10, fp1);
        fscanf(fp1, "%d\n", &service_number);
        fscanf(fp1, "%d\n", &time_takes);
        fscanf(fp1, "%d\n", &fee);
        fscanf(fp1, "%d\n", &payment_made);
        fscanf(fp1, "%d\n", &unpaid_payment);

        if (id == new_id)
        {
            printf("%d", payment_made);
            printf("%d", unpaid_payment);
        }
        fprintf(fp2, "%d\n", id);
        fprintf(fp2, "%s", name);
        fprintf(fp2, "%s", date);
        fprintf(fp2, "%d\n", service_number);
        fprintf(fp2, "%d\n", time_takes);
        fprintf(fp2, "%d\n", fee);
        fprintf(fp2, "%d\n", payment_made);
        fprintf(fp2, "%d\n", unpaid_payment);
    }

    fclose(fp1);
    fclose(fp2);

    printf("Updated \n");
}
