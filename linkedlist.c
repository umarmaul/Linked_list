#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vehicle {
    char regNumber[20];
    char brand[20];
    char model[20];
    struct Vehicle* prev;
    struct Vehicle* next;
};

struct Vehicle* head = NULL;

struct Vehicle* createVehicle(const char* regNumber, const char* brand, const char* model) {
    struct Vehicle* newVehicle = (struct Vehicle*)malloc(sizeof(struct Vehicle));
    strcpy(newVehicle->regNumber, regNumber);
    strcpy(newVehicle->brand, brand);
    strcpy(newVehicle->model, model);
    newVehicle->prev = NULL;
    newVehicle->next = NULL;
    return newVehicle;
}

void insertVehicle(const char* regNumber, const char* brand, const char* model) {
    struct Vehicle* newVehicle = createVehicle(regNumber, brand, model);
    if (head == NULL) {
        head = newVehicle;
    } else {
        struct Vehicle* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newVehicle;
        newVehicle->prev = current;
    }
    printf("Vehicle with registration number %s has been added.\n", regNumber);
}

void deleteVehicle(const char* regNumber) {
    struct Vehicle* current = head;
    while (current != NULL) {
        if (strcmp(current->regNumber, regNumber) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            printf("Vehicle with registration number %s has been deleted.\n", regNumber);
            return;
        }
        current = current->next;
    }
    printf("Vehicle with registration number %s not found.\n", regNumber);
}

void searchVehicle(const char* regNumber) {
    struct Vehicle* current = head;
    while (current != NULL) {
        if (strcmp(current->regNumber, regNumber) == 0) {
            printf("Vehicle found:\n");
            printf("Registration Number: %s\n", current->regNumber);
            printf("Brand: %s\n", current->brand);
            printf("Model: %s\n", current->model);
            return;
        }
        current = current->next;
    }
    printf("Vehicle with registration number %s not found.\n", regNumber);
}

void displayAllVehicles() {
    struct Vehicle* current = head;
    if (current == NULL) {
        printf("No vehicles available.\n");
        return;
    }
    printf("All vehicles:\n");
    while (current != NULL) {
        printf("Registration Number: %s\n", current->regNumber);
        printf("Brand: %s\n", current->brand);
        printf("Model: %s\n", current->model);
        printf("------------------------\n");
        current = current->next;
    }
}

void freeMemory() {
    struct Vehicle* current = head;
    while (current != NULL) {
        struct Vehicle* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

int main() {
    char regNumber[20];
    char brand[20];
    char model[20];
    
    insertVehicle("AB1234", "Toyota", "Camry");
    insertVehicle("CD5678", "Honda", "Civic");
 	insertVehicle("EF9012", "Ford", "Mustang");
 	insertVehicle("GH3456", "BMW", "X5");
 
 	displayAllVehicles();

 	printf("Enter registration number: ");
    scanf("%s", regNumber);
    searchVehicle(regNumber);
    
 	deleteVehicle(regNumber);

 	displayAllVehicles();

 	freeMemory();

 	return 0;
}

//pov jadi yg jual

/*
pertama tampilin dulu awalnya misal ada 4 mobil
ke menu yang ada 4 tadi

menunya ada: (pake loop)
//insert buat masukin mobil baru
//search untuk mencari keterangan kendaraan yg diinginkan
//display all untuk melihat kendaraan yang tersedia
//delete kalo ada yg beli mobil itu

tambahin tahun untuk setiap mobil
untuk menu search buat agar user bisa memilih search berdasarkan plat atau brand atau model atau tahun
untuk menu delete by registration number
*/
