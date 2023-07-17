#include <stdio.h>
#include <string.h>

// Define structure for hotel
struct Hotel
{
    char name[50];
    char address[100];
    int grade;
    int numOfRooms;
    float roomCharges;
};

// Function to print hotel names in a particular grade
void printHotelsByGrade(const struct Hotel hotels[], int numHotels, int grade)
{
    printf("Hotels in Grade %d:\n", grade);
    for (int i = 0; i < numHotels; i++)
    {
        if (hotels[i].grade == grade)
        {
            printf("- %s\n", hotels[i].name);
        }
    }
}

// Function to print hotel names with room charges less than a specified value
void printHotelsByRoomCharges(const struct Hotel hotels[], int numHotels, float maxRoomCharges)
{
    printf("Hotels with Room Charges less than %.2f:\n", maxRoomCharges);
    for (int i = 0; i < numHotels; i++)
    {
        if (hotels[i].roomCharges < maxRoomCharges)
        {
            printf("- %s\n", hotels[i].name);
        }
    }
}

int main()
{
    // Define an array of hotels
    struct Hotel hotels[3] = {
        {"Hotel A", "Address A", 4, 50, 100.0},
        {"Hotel B", "Address B", 3, 30, 80.0},
        {"Hotel C", "Address C", 4, 40, 120.0}};

    int numHotels = sizeof(hotels) / sizeof(hotels[0]);

    // Print hotel names in a particular grade
    int gradeToPrint = 4;
    printHotelsByGrade(hotels, numHotels, gradeToPrint);

    // Print hotel names with room charges less than a specified value
    float maxRoomChargesToPrint = 110.0;
    printHotelsByRoomCharges(hotels, numHotels, maxRoomChargesToPrint);

    return 0;
}
