#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Vehicle {
    char platNomor[20];
    char merk[20];
    char model[20];
    char tahun[20];
    char harga[50];
    struct Vehicle* prev;
    struct Vehicle* next;
};

struct Vehicle* head = NULL;

struct Vehicle* createVehicle(char* platNomor, char* merk, char* model, char* tahun, char* harga) {
    struct Vehicle* newVehicle = (struct Vehicle*)malloc(sizeof(struct Vehicle));
    strcpy(newVehicle->platNomor, platNomor);
    strcpy(newVehicle->merk, merk);
    strcpy(newVehicle->model, model);
    strcpy(newVehicle->tahun, tahun);
    strcpy(newVehicle->harga, harga);
    newVehicle->prev = NULL;
    newVehicle->next = NULL;
    return newVehicle;
}

void insertVehicle(char* platNomor, char* merk, char* model, char* tahun, char* harga) {
    struct Vehicle* newVehicle = createVehicle(platNomor, merk, model, tahun, harga);
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
    printf("\nData mobil dengan plat nomor %s sudah ditambahkan.\n", platNomor);
}

void deleteVehicle(char* platNomor) {
    struct Vehicle* current = head;
    while (current != NULL) {
        if (strcmp(current->platNomor, platNomor) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            printf("Data mobil dengan plat nomro %s sudah dihapus.\n", platNomor);
            return;
        }
        current = current->next;
    }
    printf("Mobil dengan plat nomor %s tidak ditemuka.\n", platNomor);
}

void searchVehicle(char* platNomor) {
    struct Vehicle* current = head;
    while (current != NULL) {
        if (strcmp(current->platNomor, platNomor) == 0) {
            printf("Data mobil ditemukan:\n");
            printf("Plat nomor: %s\n", current->platNomor);
            printf("Merk: %s\n", current->merk);
            printf("Model: %s\n", current->model);
            printf("Tahun: %s\n", current->tahun);
            printf("Harga: %s\n", current->harga);
            return;
        }
        current = current->next;
    }
    printf("Mobil dengan plat nomro %s tidak ditemukan.\n", platNomor);
}

void displayAllVehicles() {
    struct Vehicle* current = head;
    if (current == NULL) {
        printf("Tidak ada mobil yang tersedia.\n");
        return;
    }
    printf("Berikut daftar mobil yang tersedia:\n");
    while (current != NULL) {
        printf("Plat nomor: %s\n", current->platNomor);
        printf("Merk: %s\n", current->merk);
        printf("Model: %s\n", current->model);
        printf("Tahun: %s\n", current->tahun);
        printf("Harga: %s\n", current->harga);
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
    char platNomor[20];
    char merk[20];
    char model[20];
    char tahun[20];
    char harga[50];
    
    int i, menu;

    for(i = 0; i < 45; i++){
        	printf("=");
		}
        printf("\n\tAplikasi Data Mobil Bekas\n");
        printf("\n\tKelompok 8:\n");
        printf("\tDaniel Valerian\t- 2106728295 \n\tElvina Sunardi\t- 2106706413 \n\tUmar Maulana\t- 2106631034\n");
        for(i = 0; i < 45; i++){
        	printf("=");
		}
    printf("\n\n");
    system("pause");
    system("cls");

    //Menu looping
	do {
        // Menampilkan menu pilihan
        for(i = 0; i < 45; i++){
        	printf("=");
		}
        printf("\n\tMenu Aplikasi Penjualan Mobil Bekas\n");
        for(i = 0; i < 45; i++){
        	printf("=");
		}
        printf("\n1. Tambah mobil\n");
        printf("2. Lihat daftar mobil\n");
        printf("3. Cari mobil berdasarkan kategori\n");
        printf("4. Hapus data mobil\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);
        
        system("cls");

        switch(menu){
            case 1: //menu tambah mobil
                char platNomorBaru[20];
                char merkBaru[20];
                char modelBaru[20];
                char tahunBaru[20];
                char hargaBaru[50];
                
                printf("=== Menu Tambah Mobil ===\n\n");
                printf("Masukkan plat nomor: ");
                scanf("%s", platNomorBaru);
                printf("Masukkan merk: ");
                scanf("%s", merkBaru);
                printf("Masukkan model: ");
                scanf("%s", modelBaru);
                printf("Masukkan tahun: ");
                scanf("%s", tahunBaru);
                printf("Masukkan harga (format: .. juta): ");
                scanf("%s", hargaBaru);
                
                insertVehicle(platNomorBaru, merkBaru, modelBaru, tahunBaru, hargaBaru);
                
                system("pause");
                system("cls");
                break;

            case 2: //menu lihat daftar mobil
                
                system("pause");
                system("cls");
                break;
            
            case 3: //cari mobil berdasarkan kategori
                
                system("pause");
                system("cls");
                break;
           
            case 4: //hapus data mobil
                
                system("pause");
                system("cls");
                break;
            
            case 5: //keluar
                printf("Keluar program.\n\n");
                printf("Loading");
                for(i = 0; i < 3; i++){
                    printf(". ");
                    sleep(1);
                }
                break;
            
            default:
                printf("Menu tidak valid\n\n");
                system("pause");
                system("cls");
                break;
        }
    }while(menu != 5);

    printf("\n\n");

    insertVehicle("ABCDE", "Toyota", "Camry", "2019", "200 juta");
    insertVehicle("CD5678", "Honda", "Civic", "2020", "150 juta");
 	insertVehicle("EF9012", "Ford", "Mustang", "2015", "300 juta");
 	insertVehicle("GH3456", "BMW", "X5", "2018", "400 juta");
 
 	displayAllVehicles();
    
    searchVehicle(platNomor);
    
 	deleteVehicle(platNomor);

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
