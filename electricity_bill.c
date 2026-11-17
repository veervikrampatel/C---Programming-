
#include <stdio.h>

int main()
{
    int consumerNumbers[5] = {1001, 1002, 1003, 1004, 1005};

    char customerNames[5][30] = {
        "Veer Patel",
        "Ravi Sharma",
        "Manoj Singh",
        "Aman Verma",
        "Rahul Gupta"
    };

    int choice, consumer, units;
    int i, found, paymentStatus;

    float bill, fixedCharge = 50;
    float lateFee, total;

    do
    {
        printf("\n===== ELECTRICITY BILL MANAGEMENT =====\n");
        printf("1. Generate New Bill\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            return 1;

        if (choice == 1)
        {
            found = 0;
            lateFee = 0;

            printf("\nEnter Consumer Number: ");
            if (scanf("%d", &consumer) != 1)
                return 1;

            for (i = 0; i < 5; i++)
            {
                if (consumerNumbers[i] == consumer)
                {
                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                printf("\nConsumer Number Not Found!\n");
                continue;
            }

            printf("\nCustomer Found!\n");
            printf("Customer Name: %s\n", customerNames[i]);

            printf("\nEnter Electricity Units: ");
            if (scanf("%d", &units) != 1)
                return 1;

            if (consumer <= 0 || units < 0)
            {
                printf("Invalid Customer Details!\n");
                continue;
            }

            if (units <= 100)
                bill = units * 3;
            else if (units <= 200)
                bill = 300 + (units - 100) * 5;
            else
                bill = 800 + (units - 200) * 7;

            printf("\nPayment Overdue? (1 = Yes, 0 = No): ");
            if (scanf("%d", &paymentStatus) != 1)
                return 1;

            if (paymentStatus == 1)
                lateFee = 100;
            else if (paymentStatus != 0)
            {
                printf("Invalid Payment Status!\n");
                continue;
            }

            total = bill + fixedCharge + lateFee;

            printf("\n======= FINAL BILL RECEIPT =======\n");
            printf("Customer Name  : %s\n", customerNames[i]);
            printf("Consumer Number: %d\n", consumer);
            printf("Units Consumed : %d\n", units);
            printf("----------------------------------\n");
            printf("Energy Charge  : Rs. %.2f\n", bill);
            printf("Fixed Charge   : Rs. %.2f\n", fixedCharge);
            printf("Late Fee       : Rs. %.2f\n", lateFee);
            printf("----------------------------------\n");
            printf("Total Amount   : Rs. %.2f\n", total);
            printf("==================================\n");
        }
        else if (choice != 2)
        {
            printf("\nInvalid Menu Choice!\n");
        }

    } while (choice != 2);

    printf("\nThank You for Using the System!\n");

    return 0;
}
