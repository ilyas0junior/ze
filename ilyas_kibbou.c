#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold client information
typedef struct {
    int client_id;
    char passport_number[11];
    char last_name[26];
    char first_name[26];
    char birth_date[11];
    char origin_country[51];
} ClientInfo;

// Define a structure to hold booking information
typedef struct {
    char reservation_id[51];
    int client_id;
    char start_date[11];
    char end_date[11];
    int room_number;
    int nights_count;
    float amount_paid;
} BookingInfo;

// Function to display client information
void displayClient(ClientInfo *client) {
    printf("Client ID: %d\n", client->client_id);
    printf("Passport No: %s\n", client->passport_number);
    printf("Name: %s %s\n", client->first_name, client->last_name);
    printf("Birth Date: %s\n", client->birth_date);
    printf("Country: %s\n", client->origin_country);
}

// Function to display booking information
void displayBooking(BookingInfo *booking) {
    printf("Reservation ID: %s\n", booking->reservation_id);
    printf("Client ID: %d\n", booking->client_id);
    printf("Start Date: %s\n", booking->start_date);
    printf("End Date: %s\n", booking->end_date);
    printf("Room No: %d\n", booking->room_number);
    printf("Nights: %d\n", booking->nights_count);
    printf("Amount: %.2f\n", booking->amount_paid);
}

int main() {
    // Initialize an array of clients
    ClientInfo clientList[3] = {
        {17852, "E000265", "Smith", "John", "1990-12-05", "Germany"},
        {2389, "FN26301", "Doe", "Jane", "1986-04-27", "USA"},
        {56723, "SU85623", "Brown", "Charlie", "1996-09-02", "USA"}
    };

    // Initialize an array of bookings
    BookingInfo bookingList[3] = {
        {"RES_001523", 17852, "2022-06-18", "2022-06-24", 14, 6, 1710.00},
        {"RES_045238", 2389, "2022-07-02", "2022-07-06", 11, 4, 480.00},
        {"RES_368952", 56723, "2022-07-11", "2022-07-20", 13, 9, 2430.00}
    };

    // Display each client's information
    for (int i = 0; i < 3; i++) {
        displayClient(&clientList[i]);
        printf("\n");
    }

    // Display each booking's information
    for (int i = 0; i < 3; i++) {
        displayBooking(&bookingList[i]);
        printf("\n");
    }

    return 0;
}
