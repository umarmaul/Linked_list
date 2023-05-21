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

void searchVehiclebyPlat(char* platNomor) {
    struct Vehicle* current = head;
    while (current != NULL) {
        if (strcmp(current->platNomor, platNomor) == 0) {
            printf("Data mobil ditemukan untuk plat nomor %s:\n", platNomor);
            printf("Plat nomor: %s\n", current->platNomor);
            printf("Merk: %s\n", current->merk);
            printf("Model: %s\n", current->model);
            printf("Tahun: %s\n", current->tahun);
            printf("Harga: %s\n", current->harga);
            printf("\n\n");
            return;
        }
        current = current->next;
    }
    printf("Mobil dengan plat nomor %s tidak ditemukan.\n", platNomor);
}

void searchVehiclebyMerk(char* merk) {
    struct Vehicle* current = head;
    while (current != NULL) {
        if (strcmp(current->merk, merk) == 0) {
            printf("Data mobil ditemukan untuk merk %s:\n", merk);
            printf("Plat nomor: %s\n", current->platNomor);
            printf("Merk: %s\n", current->merk);
            printf("Model: %s\n", current->model);
            printf("Tahun: %s\n", current->tahun);
            printf("Harga: %s\n", current->harga);
            printf("\n\n");
            return;
        }
        current = current->next;
    }
    printf("Mobil dengan merk %s tidak ditemukan.\n", merk);
}

void searchVehiclebyModel(char* model) {
    struct Vehicle* current = head;
    while (current != NULL) {
        if (strcmp(current->model, model) == 0) {
            printf("Data mobil ditemukan untuk model %s:\n", model);
            printf("Plat nomor: %s\n", current->platNomor);
            printf("Merk: %s\n", current->merk);
            printf("Model: %s\n", current->model);
            printf("Tahun: %s\n", current->tahun);
            printf("Harga: %s\n", current->harga);
            printf("\n\n");
            return;
        }
        current = current->next;
    }
    printf("Mobil dengan model %s tidak ditemukan.\n", model);
}

void searchVehiclebyTahun(char* tahun) {
    struct Vehicle* current = head;
    while (current != NULL) {
        if (strcmp(current->tahun, tahun) == 0) {
            printf("Data mobil ditemukan untuk tahun %s:\n", tahun);
            printf("Plat nomor: %s\n", current->platNomor);
            printf("Merk: %s\n", current->merk);
            printf("Model: %s\n", current->model);
            printf("Tahun: %s\n", current->tahun);
            printf("Harga: %s\n", current->harga);
            printf("\n\n");
            return;
        }
        current = current->next;
    }
    printf("Mobil dengan tahun %s tidak ditemukan.\n", tahun);
}

void searchVehiclebyHarga(char* harga) {
    struct Vehicle* current = head;
    while (current != NULL) {
        if (strcmp(current->harga, harga) == 0) {
            printf("Data mobil ditemukan untuk harga:\n", harga);
            printf("Plat nomor: %s\n", current->platNomor);
            printf("Merk: %s\n", current->merk);
            printf("Model: %s\n", current->model);
            printf("Tahun: %s\n", current->tahun);
            printf("Harga: %s\n", current->harga);
            printf("\n\n");
            return;
        }
        current = current->next;
    }
    printf("Mobil dengan harga %s tidak ditemukan.\n", harga);
}

void displayAllVehicles() {
    struct Vehicle* current = head;
    if (current == NULL) {
        printf("Tidak ada mobil yang tersedia.\n\n");
        return;
    }
    printf("Berikut daftar mobil yang tersedia:\n\n");
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

        system("pause");
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
                displayAllVehicles();

                system("pause");
                system("cls");
                break;
            
            case 3: //cari mobil berdasarkan kategori
                printf("=== Menu Cari Data Mobil ===\n\n");

                int pilih;
                printf("Ingin mencari berdasarkan:\n");
                printf("1. Plat nomor\n");
                printf("2. Merk\n");
                printf("3. Model\n");
                printf("4. Tahun\n");
                printf("5. Harga\n\n");
                printf("Pilihan: ");
                scanf("%d", &pilih);

                switch(pilih){
                    case 1:
                        printf("masukkan plat nomor: ");
                        scanf("%s\n", platNomor);
                        searchVehiclebyPlat(platNomor);

                        break;
        
                    case 2:
                        printf("masukkan merk: ");
                        scanf("%s\n", merk);
                        searchVehiclebyMerk(merk);

                        break;

                    case 3:
                        printf("masukkan model: ");
                        scanf("%s\n", model);
                        searchVehiclebyPlat(model);

                        break;

                    case 4:
                        printf("masukkan tahun: ");
                        scanf("%s\n", tahun);
                        searchVehiclebyPlat(tahun);

                        break;

                    case 5:
                        printf("masukkan harga: ");
                        scanf("%s\n", harga);
                        searchVehiclebyPlat(harga);

                        break;

                    default:
                        printf("input tidak valid, silahkan ulangi");
                        break;
                }

                system("pause");
                system("cls");
                break;
           
            case 4: //hapus data mobil
                char hapusPlatNomor[20];
                printf("Masukan plat nomor untuk data mobil yang akan dihapus: ");
                scanf("%s", hapusPlatNomor);

                deleteVehicle(hapusPlatNomor);

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

 	freeMemory();

    printf("\n\n");

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
