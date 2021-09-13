#include "header.h" 

void startKata(char query[]){
    indeks = 0;                     //memulai indeks dengan nilai 0
    panjangKata = 0;                //memulai panjang kata dengan nilai 0

    while (query[indeks] == ' ')    //membuat perulangan jika terdapat spasi pada kalimat
    {
        indeks++;                   //nilai indeks akan selalu bertambah seiring adanya spasi
    }

    while(query[indeks] != ' ' && eopKata(query) == 0) {    //membuat perulangan untuk menelusuri huruf dalam sebuah kata
        currentKata[panjangKata] = query[indeks];           //memasukan kata ke variabel ckata dari kalimat
        indeks++;                                           //nilai indeks naik agar dapat berpindah ke huruf berikutnya
        panjangKata++;                                      //nilai panjang kata naik agar dapat mengisi tempat berikutnya
    }

    currentKata[panjangKata] = '\0';    //nilai dari akhir ckata adalah \0 
}

void resetKata() {                      
    panjangKata = 0;                    //menjadikan panjang kata menjadi 0
    currentKata[panjangKata] = '\0';    //membuat nilai ckata menjadi \0 artinya bahwa nilai tersebut kosong
}

void incKata(char query[]){
    panjangKata = 0;                //membuat nilai panjang kata menjadi 0
    while(query[indeks] == ' ') {   //perulangan untuk menelusuri setiap spasi
        indeks++;                   //nilai indeks akan selalu bertambah
    }

    while (query[indeks] != ' ' && eopKata(query) == 0) //membuat perulangan untuk menelusuri setiap huruf dalam sebuah kata
    {
        currentKata[panjangKata] = query[indeks];       //memasukan kata dari kalimat kedalam variabel ckata
        indeks++;                                       //nilai indeks akan selalu bertambah
        panjangKata++;                                  //nilai panjang kata akan selalu bertambah
    }

    currentKata[panjangKata] = '\0';    //menjadikan nilai akhir dari ckata \0
}

char *getCurrentKata() {
    return currentKata;     //mengembalikan nilai dari ckata
}

int getPanjangKata() {
    return panjangKata;     //mengembalikan nilai dari panjang kata
}

int eopKata(char query[]) {
    if(query[indeks] == ';'){  //membuat kondisi jika bertemu dengan titik sebagai akhir dari kalimat     
        return 1;              //mengembalikan nilai 1 
    }else{                     //kondisi jika kalimat belum berakhir 
        return 0;              //mengembalikan nilai 0 
    }
}

//pengecekan untuk DML INSERT UPDATE
int checkInsertUpdate(char query[]) {
    startKata(query);
    if(DMLCheck(query) == 1){       //kondisi disaat query kata-1 berisi INSERT
        incKata(query);
        if(DMLCheck(query) == 2){   //kondisi disaat query kata-2 berisi UPDATE
            return 1;               //mengembalikan nilai 1
        }
    }
    return 0;                       //salah mengembalikan nilai 2
}

//Menyalin nilai dari query ke bungkusan tipe data terstruktur
void DMLData(char query[], tabel *data, char table[], char DMLQuery[]) {
    int countLen = 0;   //sebagai penghitung untuk memasukan nilai

    startKata(query);
    while(eopKata(query) == 0){     //kondisi disaat perulangan belum mencapai akhir
        //kondisi untuk memasukan nilai dari query ke tipe data terstruktur
        if(strcmp(getCurrentKata(), DMLQuery) != 0 && strcmp(getCurrentKata(), table) != 0 && strcmp(getCurrentKata(), "UPDATE") != 0){
            if(countLen == 0) {
                strcpy(data->id, getCurrentKata());
            }else if(countLen == 1){
                strcpy(data->data1, getCurrentKata());
            }else if(countLen == 2){
                strcpy(data->data2, getCurrentKata());
            }else if(countLen == 3){
                strcpy(data->data3, getCurrentKata());
            }
            countLen++;
        }

        incKata(query);
    }

    strcpy(data->data4, getCurrentKata());
}

//mengecek DML dari query 
int DMLCheck(char perintah[]) {
    if(strcmp(getCurrentKata(), "INSERT") == 0){
        return 1;
    }else if(strcmp(getCurrentKata(), "UPDATE") == 0){
        return 2;
    }else if(strcmp(getCurrentKata(), "DELETE") == 0){
        return 3;
    }else if(strcmp(getCurrentKata(), "SELECT") == 0){
        return 4;
    }else{
        return 0;
    }
}

//mengecek tabel yang ada pada query
int tableCheck(char perintah[]) {
    if(strcmp(getCurrentKata(), "tAnggota") == 0){
        return 1;
    }else if(strcmp(getCurrentKata(), "tBuku") == 0){
        return 2;
    }else if(strcmp(getCurrentKata(), "tPinjam") == 0){
        return 3;
    }else {
        return 0;
    }
}

//mendapatkan nilai dari FILE anggota
tabel2D getAnggotaFile() {
    FILE *anggota;      //sebagai variabel untuk file 
    tabel2D TAnggota;   //sebagai variabel tipe data dari tipe struct 2d anggota
    
    anggota = fopen("Anggota.dat", "r");    //menginisialisasi nilai dari FILE anggota ke tipe data

    //menyalin data dari FILE ke tipe data tipe struct2d anggota
    fscanf(anggota, "%s %s %s %s %s\n", TAnggota.id[0], TAnggota.data1[0],TAnggota.data2[0],TAnggota.data3[0],TAnggota.data4[0]);

    //menyalin data dari FILE ke tipe data tipe struct2d anggota
    while(strcmp(TAnggota.id[indeksAnggota], "####") != 0 ) {
        indeksAnggota++;
        fscanf(anggota, "%s %s %s %s %s\n", TAnggota.id[indeksAnggota], TAnggota.data1[indeksAnggota],TAnggota.data2[indeksAnggota],TAnggota.data3[indeksAnggota],TAnggota.data4[indeksAnggota]);
    }

    //sebagai perintah menutup FILE anggota
    fclose(anggota);
    //mengembalikan nilai tipe struct anggota
    return TAnggota;
}

//mendapatkan nilai dari file buku
tabel2D getBukuFile() {
    FILE *buku;    //sebagai variabel untuk file           
    tabel2D TBuku; //sebagai variabel tipe data dari tipe struct 2d buku     
    
    buku = fopen("Buku.dat", "r");  //menginisialisasi nilai dari FILE buku ke tipe data
    //menyalin data dari FILE ke tipe data tipe struct2d buku
    fscanf(buku, "%s %s %s %s %s\n", TBuku.id[0], TBuku.data1[0],TBuku.data2[0],TBuku.data3[0],TBuku.data4[0]);
    //menyalin data dari FILE ke tipe data tipe struct2d buku    
    while(strcmp(TBuku.id[indeksBuku], "####")!= 0 ) {
        indeksBuku++;
        fscanf(buku, "%s %s %s %s %s\n", TBuku.id[indeksBuku], TBuku.data1[indeksBuku],TBuku.data2[indeksBuku],TBuku.data3[indeksBuku],TBuku.data4[indeksBuku]);
    }
    //sebagai perintah menutup FILE buku
    fclose(buku);
    //mengembalikan nilai tipe struct buku    
    return TBuku;
}

//mendapatkan nilai dari file pinjam
tabel2D getPinjamFile() {
    FILE *pinjam;      //sebagai variabel untuk file    
    tabel2D TPinjam;   //sebagai variabel tipe data dari tipe struct 2d pinjam      
    
    pinjam = fopen("Pinjam.dat", "r");  //menginisialisasi nilai dari FILE pinjam ke tipe data
    //menyalin data dari FILE ke tipe data tipe struct2d pinjam
    fscanf(pinjam, "%s %s %s %s %s\n", TPinjam.id[0], TPinjam.data1[0],TPinjam.data2[0],TPinjam.data3[0],TPinjam.data4[0]);
    //menyalin data dari FILE ke tipe data tipe struct2d pinjam    
    while(strcmp(TPinjam.id[indeksPinjam], "####")!= 0 ) {
        indeksPinjam++;
        fscanf(pinjam, "%s %s %s %s %s\n", TPinjam.id[indeksPinjam], TPinjam.data1[indeksPinjam],TPinjam.data2[indeksPinjam],TPinjam.data3[indeksPinjam],TPinjam.data4[indeksPinjam]);
    }
    //sebagai perintah menutup FILE pinjam
    fclose(pinjam);
    //mengembalikan nilai tipe struct pinjam    
    return TPinjam;
}

//menyalin data dari tipe data tersturktur 2d menuju ke tipe data terstruktur biasa
void salinData(tabel2D tempData, tabel *data, int indeksData){
    //penyalinan data dari tipe data 2d ke tipe data tabel
    strcpy(data->id, tempData.id[indeksData]);
    strcpy(data->data1, tempData.data1[indeksData]);
    strcpy(data->data2, tempData.data2[indeksData]);
    strcpy(data->data3, tempData.data3[indeksData]);
    strcpy(data->data4, tempData.data4[indeksData]);
}

//menyalin data pada setiap tabel
void salinProgram(tabel tanggota[], tabel tbuku[], tabel tpinjam[]){
    int i;
    tabel2D tempTAnggota, tempTBuku, tempTPinjam;   //sebagai nilai sementara dari tipe data2d dari setiap tabel
    //nilai indeks dari setiap tabel bernilai 0
    indeksAnggota = 0;
    indeksBuku = 0;
    indeksPinjam = 0;
    //menyimpan nilai dari fungsi pada setiap masing2 tabel
    tempTAnggota = getAnggotaFile();
    tempTBuku = getBukuFile();
    tempTPinjam = getPinjamFile();
    //perulangan untuk proses pemindahan data dari tipe struct 2d ke tipe struct tabel 
    for(i=0; i<indeksAnggota; i++){
        salinData(tempTAnggota, &tanggota[i], i);
    }
    //perulangan untuk proses pemindahan data dari tipe struct 2d ke tipe struct tabel 
    for(i=0; i<indeksBuku; i++){
        salinData(tempTBuku, &tbuku[i], i);
    }
    //perulangan untuk proses pemindahan data dari tipe struct 2d ke tipe struct tabel 
    for(i=0; i<indeksPinjam; i++){
        salinData(tempTPinjam, &tpinjam[i], i);
    }
}

//mencari id/no pada tabel
int sequentialSearch(int indeksData, char idData[], tabel data[]){
    int i=0;
    int ketemu = 0; //nilai awal untuk dijadikan sebagai pengecekan
    while(i < indeksData && ketemu == 0){       //kondisi untuk perulangan 
        if(strcmp(data[i].id, idData) == 0){    //kondisi disaat nilai yang dicari ketemu
            ketemu = 1;
        }else {
            i++;
        }
    }

    if(ketemu == 1){        //kondisi disaat nilai yang dicari ketemu
        indeksSearch = i;   //menjadikan nilai indeks search = i
        return 1;
    }else{
        return 0;
    }
}

//Data telah ada pada tabel 
void dataExist() {
    printf("\nData is already exist!\n");
}
//penulisan query yang salah
void errorAlert() {
    printf("\nError! Wrong Syntax, Please Try Again!\n\n");
}
//data dari id/no tidak dapat ditemukan
void DatanotFoundAlert() {
    printf("\nData Is Not Found!\n");
}
//tabel tidak dapat ditemukan
void tableNotFoundAlert() {
    printf("\nTable Is Not Found!\n");
}
//penulisan kolom pada query melebihi kapasita char yang tersedia
void errorLenQuery(int row) {
    printf("\nColumn Count Doesn't Match Value Count at row %d!\n", row);
}
//Program keluar
void exitAlert() {
    printf("\nThanks, Good Bye!\n\n");
}
//pengecekan untuk titik koma pada query
int CheckError(char query[], int len) {
    int i;
    startKata(query);
    for(i=0; i<len; i++){
        incKata(query);
        if(i == len-1){
            if(eopKata(query) == 0){    //kondisi saat titik koma tidak ditemukan
                return 0;
            }else{                      //kondisi saat titik koma ditemukan
                return 1;
            }
        }
    }
}

//pengecekan panjang pada setiap kolom kata di query
int checkLenQuery(char query[]) {
    startKata(query);
    while(DMLCheck(query) == 1 || DMLCheck(query) == 2 ){
        incKata(query);
    }
    incKata(query);
    int i;
    if(strlen(getCurrentKata()) > 10){      //pengecekan untuk id/no kolom tidak boleh > 10 char
        errorLenQuery(1);
        return 0;
    }
    for(i=2; i<6; i++) {
        incKata(query);
        if(strlen(getCurrentKata()) > 20){  //pengecekan untuk data kolom tidak boleh > 20 char
            errorLenQuery(i);
            return 0;
        }
    }

    return 1;
}

//pengecekan pada penulisan query
int checkQuery(char query[]) {
    int i = 0;
    startKata(query);
    if(strcmp(getCurrentKata(), "exit") == 0) {     //kondisi jika penulisan query = exit
        return 1;
    } 
    if(DMLCheck(query) == 1 || DMLCheck(query) == 2){  //kondisi saat penulisan query insert / update
        incKata(query);
        if(DMLCheck(query) != 2){               //kondisi pada kata ke-2 bukan UPDATE
            if(CheckError(query, 6) == 0){      //kondisi jika tidak ditemukan titik koma
                return 0;
            }else{
                return 1;
            }
        }else {     //kondisi saat penulisan query ke-2 adalah UPDATE
            if(CheckError(query, 7) == 0){      //kondisi jika tidak ditemukan titik koma
                return 0;
            }else{
                return 1;
            }
        }
    }else if(DMLCheck(query) == 3) {            //kondisi saat penulisan query ke-1 adalah DELETE
        if(CheckError(query, 2) == 0){          //kondisi jika tidak ditemukan titik koma
            return 0;
        }else {
            return 1;
        }
    }else if(DMLCheck(query) == 4) {            //kondisi saat penulisan query ke-1 adalah SELECT
        incKata(query);
        if(selectAllTable(query) == 1){         //kondisi saat penulisan query adalah SELECT semua tabel
            return 1;
        }
        startKata(query);
        incKata(query);
        if(tableCheck(query) == 0){             //kondisi saat tabel tidak ditemukan
            return 0;
        }else{
            return 1;
        }

    }
    return 0;
}

//menampilkan semua tabel 
void showAllTable(tabel tanggota[], tabel tbuku[], tabel tpinjam[]) {
    int i;
    char tempAnggota[50];           //nilai sementara dari data anggota
    char tempBuku[50];              //nilai sementara dari data buku
    int tempIndex1, tempIndex2;     //nilai sementara dari indeks anggota, buku
    judulSemuaTabel(tbuku, tanggota, tpinjam);  //memanggil tampilan judul
    for(i=0; i<indeksPinjam; i++) {
        //data yang ditampilkan yaitu data yang berasal dari tabel pinjam 
        if(sequentialSearch(indeksAnggota, tpinjam[i].data1, tanggota) == 1) {
            tempIndex1 = indeksSearch;      //mendaptkan data dari tabel anggota
            if(sequentialSearch(indeksBuku, tpinjam[i].data2, tbuku) == 1){
                tempIndex2 = indeksSearch;  //mendapatkan data dari tabel buku
                //menampilkan nilai dari tabel anggota
                getMaxLen(tanggota, indeksAnggota);
                getLenJudul("Id_Anggota", "Nama", "Jenis_Kelamin", "Kota", "No_Telp");
                tampilData(tanggota, tempIndex1,3 );
                //menampilkan nilai dari tabel buku
                getMaxLen(tbuku, indeksBuku);
                getLenJudul("No_Buku", "Judul", "Pengarang", "Jenis_Buku", "Tahun_Terbit");
                tampilData(tbuku, tempIndex2, 3); 
                //menampilkan nilai dari tabel pinjam
                getMaxLen(tpinjam, indeksPinjam);
                getLenJudul("No_Pinjam", "", "", "Tgl_Pinjam", "Tgl_Kemabli");
                tampilData(tpinjam, i, 1);
                printf("|\n");
            }
        }
    }
    BatasSemuaTabel(tbuku, tanggota, tpinjam);
}

//menampilkan semua data dalam bentuk tabel teratur
void tampilSemuaData(tabel tanggota[], tabel tbuku[], tabel tpinjam[]){
    int i;
    getMaxLen(tanggota, indeksAnggota);  
    getLenJudul("Id_Anggota", "Nama", "Jenis_Kelamin", "Kota", "No_Telp");
    for(i=0; i<indeksPinjam; i++) {     //perulangan untuk menampilkan data sesuai dengan indeks pinjam 
        tampilData(tanggota, i, 3);
    }
}

//menentukan kombinasi untuk menampilkan semua data
int selectAllTable(char query[]) {
    int i,j,k;
    //nilai-nilai untuk dijadikan sebagai bagian dari operasi kombinasi tampilan semua tabel
    char kata[5][50];
    strcpy(kata[0], "tAnggota");
    strcpy(kata[1], "tBuku");
    strcpy(kata[2], "tPinjam"); 
    int num[3] = {0,1,2};
    //perulangan untuk menentukan agar kombinasi dari ketiga tabel dapat terpenuhi saat dipanggil 
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++){
            for(k=0; k<3; k++) {
                if(i != j && j != k && k != i) {
                    startKata(query);
                    incKata(query);
                    if(strcmp(getCurrentKata(query), kata[num[i]]) == 0) {
                        incKata(query);
                        if(strcmp(getCurrentKata(query), kata[num[j]]) == 0) {
                            incKata(query);
                            if(strcmp(getCurrentKata(query), kata[num[k]]) == 0) {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

//prosedur untuk menghapus record pada tabel 
void DMLDelete(int indeksData, tabel data[]) {
    int i;
    for(i=indeksSearch; i<indeksData-1; i++) {  //perulangan untuk membuat nilai dari record yang terpilih menjadi tidak ada
        deleteData(&data[i], &data[i+1]);
    }
}

//prosedur untuk proses dari pertukaran nilai agar nilai yang dihapus tidak ada
void deleteData(tabel *data1, tabel *data2) {
    strcpy(data1->id, data2->id);
    strcpy(data1->data1, data2->data1);
    strcpy(data1->data2, data2->data2);
    strcpy(data1->data3, data2->data3);
    strcpy(data1->data4, data2->data4);
}

//untuk menuliskan data terbaru pada FILE
void currentData(tabel data[], int indeksTabel, char namaFile[]) {
    int i;
    FILE *dataFile;     //nilai yang digunakan untuk FILE 
    char name[50];      //nilai yang digunakan untuk namaFILE
    sprintf(name, "%s.dat", namaFile);  //penyalinan nama file
    dataFile = fopen(name, "w");        //membuka file tabel

    for(i=0; i<indeksTabel; i++){       //perulangan untuk melakukan penulisan di FILE
        fprintf(dataFile, "%s %s %s %s %s\n", data[i].id, data[i].data1, data[i].data2, data[i].data3, data[i].data4);
    }
    //melakukan penulisan di file
    fprintf(dataFile, "%s %s %s %s %s\n", "####", "####", "####", "####", "####");
    //menutup FILE
    fclose(dataFile);
}

//prosedur untuk mendapatkan nilai maksimal dari setiap kolom pada query
void getMaxLen(tabel data[], int indeksData) {
    //membuat nilai maks awal = 0
    maksId = 0;
    maksData1 = 0;
    maksData2 = 0;
    maksData3 = 0;
    maksData4 = 0;
    //perulangan untuk mencari nilai maksimal yang ada pada tipe struct 
    for(int i=0; i<indeksData; i++) {
        if(maksId < strlen(data[i].id)) {
            maksId = strlen(data[i].id);       
        }
        if(maksData1 < strlen(data[i].data1)) {
            maksData1 = strlen(data[i].data1);
        }
        if(maksData2 < strlen(data[i].data2)) {
            maksData2 = strlen(data[i].data2);
        }
        if(maksData3 < strlen(data[i].data3)) {
            maksData3 = strlen(data[i].data3);
        }
        if(maksData4 < strlen(data[i].data4)) {
            maksData4 = strlen(data[i].data4);
        }
    }
}

//prosedur untuk batas strip pada tabel
void stripTabel(int len) {
    int i;
    for(i=0; i<len+2; i++) {
        printf("-");
    }
}

//prosedur untuk batas strip pada semua tabel heading 
void BatasSemuaTabel(tabel tbuku[], tabel tanggota[], tabel tpinjam[]) {
    getMaxLen(tanggota, indeksAnggota);
    getLenJudul("Id_Anggota", "Nama", "Jenis_Kelamin", "Kota", "No_Telp");
    batasTabel(1);
    getMaxLen(tbuku, indeksBuku);
    getLenJudul("No_Buku", "Judul", "Pengarang", "Jenis_Buku", "Tahun_Terbit");
    batasTabel(1);
    getMaxLen(tpinjam, indeksPinjam);
    getLenJudul("No_Pinjam", "", "", "Tgl_Pinjam", "Tgl_Kemabli");
    batasTabelPinjam(3);
}

//prosedur untuk mendapatkan panjang maks dari judul dengan data
void getLenJudul(char jId[], char jData1[], char jData2[], char jData3[], char jData4[]) {
    if(strlen(jId) > maksId) {
        maksId = strlen(jId);
    }
    if(strlen(jData1) > maksData1) {
        maksData1 = strlen(jData1);
    }
    if(strlen(jData2) > maksData2) {
        maksData2 = strlen(jData2);
    }
    if(strlen(jData3) > maksData3) {
        maksData3 = strlen(jData3);
    }
    if(strlen(jData4) > maksData4) {
        maksData4 = strlen(jData4);
    }
}

//untuk menampilkan semua heading tabel
void judulSemuaTabel(tabel tbuku[], tabel tanggota[], tabel tpinjam[]) {
    BatasSemuaTabel(tbuku, tanggota, tpinjam);

    //heading pada tabel anggota
    getMaxLen(tanggota, indeksAnggota);
    getLenJudul("Id_Anggota", "Nama", "Jenis_Kelamin", "Kota", "No_Telp");
    containtJudulTable("Id_Anggota", "Nama", "Jenis_Kelamin", "Kota", "No_Telp", 3);
    //heading pada tabel buku
    getMaxLen(tbuku, indeksBuku);
    getLenJudul("No_Buku", "Judul", "Pengarang", "Jenis_Buku", "Tahun_Terbit");
    containtJudulTable("No_Buku", "Judul", "Pengarang", "Jenis_Buku", "Tahun_Terbit", 3);
    //heading pada tabel pinjam
    getMaxLen(tpinjam, indeksPinjam);
    getLenJudul("No_Pinjam", "", "", "Tgl_Pinjam", "Tgl_Kemabli");
    containtJudulTable("No_Pinjam", "", "", "Tgl_Pinjam", "Tgl_Kemabli", 1);
    printf("\n");

    BatasSemuaTabel(tbuku, tanggota, tpinjam);
}

//prosedur untuk menampilkan nilai data dari setiap kolom berupa tabel
void containtJudulTable(char jId[], char jData1[], char jData2[], char jData3[], char jData4[], int tabel) {
    printf("|");
    containtTabel (maksId, jId);
    if(tabel == 3){
        printf("|");
        containtTabel(maksData1, jData1);
        printf("|");
        containtTabel(maksData2, jData2);
    }
    printf("|");
    containtTabel(maksData3, jData3);
    printf("|");
    containtTabel(maksData4, jData4);
}

//prosedur untuk menampilkan nilai data dari setiap kolom
void containtTabel(int len, char containt[]) {
    printf("%s", containt);
    int i;
    for(i=0; i<len-strlen(containt)+2; i++) {
        printf(" ");
    }
}

//prosedur untuk menampilkan batasan dari tabel pinjam
void batasTabelPinjam(int batas) {
    printf("+");
    stripTabel(maksId);
    printf("+");
    stripTabel(maksData3);
    printf("+");
    stripTabel(maksData4);
    if(batas == 3){
        printf("+");
        printf("\n");
    }
}

//prosedur untuk menampilkan batasa dari setiap tabel
void batasTabel(int batas) {
    printf("+");
    stripTabel(maksId);
    printf("+");
    stripTabel(maksData1);
    printf("+");
    stripTabel(maksData2);
    printf("+");
    stripTabel(maksData3);
    printf("+");
    stripTabel(maksData4);
    if(batas == 3){
        printf("+");
        printf("\n");
    }
}

//prosedur untuk menampilkan judul pada suatu file berupa tabel
void judulTabel(char jId[], char jData1[], char jData2[], char jData3[], char jData4[]) {
    int i;
    getLenJudul(jId, jData1, jData2, jData3, jData4);
    batasTabel(3);
    containtJudulTable(jId, jData1, jData2, jData3, jData4,3 );
    printf("|");
    printf("\n");
    batasTabel(3);
}

//prosedur untuk menampilakan data pada suatu file berupa tabel
void tampilData(tabel data[], int i, int tabel) {
    printf("|");
    containtTabel(maksId, data[i].id);
    if(tabel == 3){
        printf("|");
        containtTabel(maksData1, data[i].data1);
        printf("|");
        containtTabel(maksData2, data[i].data2);
    }
    printf("|");
    containtTabel(maksData3, data[i].data3);
    printf("|");
    containtTabel(maksData4, data[i].data4);
}

//prosedur untuk menampilkan data pada suatu file berupa tabel
void tampilTData(tabel data[], int indeksData) {
    int i; 

    for(i=0; i<indeksData; i++) {
        tampilData(data, i, 3);
        printf("|\n");
    }
    batasTabel(3);
}

//prosedur untuk menampilkan tampilan awal dari program 
void welcome() {
    printf("Selamat Datang di DBMS Terjemahan Azar\nVersi 1.0\n");
    printf("\n");
    printf("dbms Azar > ");
}

//menu utama yang berisi alur hampir keseluruhan program 
void mainProgram(char query[], tabel tanggota[], tabel tbuku[], tabel tpinjam[]) {
    int tempIndexSearch;
    if(checkInsertUpdate(query) == 1){      //kondisi saat query INSERT UPDATE
        incKata(query);
        if(tableCheck(query) == 1){         //kondisi jika tabel anggota memenuhi
            if(checkLenQuery(query) == 1) { //kondisi jika panjang dari setiap kolom memenuhi
                startKata(query);
                incKata(query);
                incKata(query);
                incKata(query);
                //kondisi saat id/no tidak ditemukan maka nilai akan di tambahkan 
                if(sequentialSearch(indeksAnggota, getCurrentKata(), tanggota) == 0){
                    DMLData(query, &tanggota[indeksAnggota], "tAnggota", "INSERT");
                    indeksAnggota++;
                    currentData(tanggota, indeksAnggota, "Anggota");
                }
                //kondisi untuk nilai akan diperbarui
                else {
                    DMLData(query, &tanggota[indeksSearch], "tAnggota", "INSERT");
                    currentData(tanggota, indeksAnggota, "Anggota");
                }
                getMaxLen(tanggota, indeksAnggota);
                judulTabel("Id_Anggota", "Nama", "Kota", "Jenis_Kelamin", "No_Telp");
                tampilTData(tanggota, indeksAnggota);
            }
        }else if(tableCheck(query) == 2){   //kondisi jika tabel buku 
            if(checkLenQuery(query) == 1){  //kondisi jika panjang dari setiap kolom memenuhi
                startKata(query);
                incKata(query);
                incKata(query);
                incKata(query);
                //kondisi saat id/no tidak ditemukan maka nilai akan ditambahkan 
                if(sequentialSearch(indeksBuku, getCurrentKata(), tbuku) == 0){
                    DMLData(query, &tbuku[indeksBuku], "tBuku", "INSERT");
                    indeksBuku++;
                    currentData(tbuku, indeksBuku, "Buku");
                }
                //kondisi untuk nilai akan diperbaharui
                else {
                    DMLData(query, &tbuku[indeksSearch], "tBuku", "INSERT");
                    currentData(tbuku, indeksBuku, "Buku");
                }
                getMaxLen(tbuku, indeksBuku);
                judulTabel("No_Buku", "Judul", "Pengarang", "Jenis_Buku", "Tahun_Terbit");
                tampilTData(tbuku, indeksBuku);
            }
        }else if(tableCheck(query) == 3) {  //kondisi jika tabel pinjam
            if(checkLenQuery(query) == 1) { //kondisi jika panjang dari setiap kolom memenuhi
                startKata(query);
                incKata(query);
                incKata(query);
                incKata(query);
                if(sequentialSearch(indeksPinjam, getCurrentKata(), tpinjam) == 0){         //kondisi jika no pinjam tidak ditemukan
                    incKata(query);
                    if(sequentialSearch(indeksAnggota, getCurrentKata(), tanggota) == 0){   //kondisi jika id anggota tidak ditemukan
                        DatanotFoundAlert();
                    }else{      //kondisi jikaid anggota ditemukan
                        incKata(query);
                        if(sequentialSearch(indeksBuku, getCurrentKata(), tbuku) == 0){     //kondisi jika no buku tidak ditemukan
                            DatanotFoundAlert();
                        }else{  //kondisi jika no buku ditemukan
                            DMLData(query, &tpinjam[indeksPinjam], "tPinjam", "INSERT");
                            indeksPinjam++;
                            currentData(tpinjam, indeksPinjam, "Pinjam");
                        }
                    }
                }else {     //kondisi jika no pinjam ditemukan
                    tempIndexSearch = indeksSearch;
                    incKata(query);
                    if(sequentialSearch(indeksAnggota, getCurrentKata(), tanggota) == 0){   //kondisi jika id anggota tidak ditemukan
                        DatanotFoundAlert();
                    }else{      //kondisi jika id anggota ditemukan
                        incKata(query);
                        if(sequentialSearch(indeksBuku, getCurrentKata(), tbuku) == 0){     //kondisi jika no buku tidak ditemukan
                            DatanotFoundAlert();
                        }else{  //kondisi jika no buku ditemukan
                            DMLData(query, &tpinjam[tempIndexSearch], "tPinjam", "INSERT");
                            currentData(tpinjam, indeksPinjam, "Pinjam");                            
                        }
                    }
                }
                getMaxLen(tpinjam, indeksPinjam);
                judulTabel("No_Pinjam", "Id_Anggota", "No_Buku", "Tgl_Pinjam", "Tgl_Kembali");
                tampilTData(tpinjam, indeksPinjam);
            }
        }else {     //kondisi jika tabel tidak ditemukan
            tableNotFoundAlert();
        }
    }else{      //kondisi jika query DML bukan INSERT UPDATE
        startKata(query);
        if(DMLCheck(query) == 1){       //kondisi jika kata ke-1 merupakan INSERT
            incKata(query);
            if(tableCheck(query) == 1){     //kondisi jika tabel anggota
                if(checkLenQuery(query) == 1) {     //kondisi jika panjang kata pada setiap kolom memenuhi
                    startKata(query);
                    incKata(query);
                    incKata(query);
                    if(sequentialSearch(indeksAnggota, getCurrentKata(), tanggota) == 0){       //kondisi jika id anggota tidak ditemukan
                        DMLData(query, &tanggota[indeksAnggota], "tAnggota", "INSERT");
                        indeksAnggota++;
                        getMaxLen(tanggota, indeksAnggota);
                        judulTabel("Id_Anggota", "Nama", "Kota", "Jenis_Kelamin", "No_Telp");
                        tampilTData(tanggota, indeksAnggota);
                        currentData(tanggota, indeksAnggota, "Anggota");
                    }else {     //kondisi jika id anggota ditemukan 
                        dataExist();
                    }
                }
            }else if(tableCheck(query) == 2){       //kondisi jika tabel buku
                if(checkLenQuery(query) == 1) {     //kondisi jika panjang kata pada setiap kolom memenuhi
                    startKata(query);
                    incKata(query);
                    incKata(query);
                    if(sequentialSearch(indeksBuku, getCurrentKata(), tbuku) == 0){     //kondisi jika no buku tidak ditemukan
                        DMLData(query, &tbuku[indeksBuku], "tBuku", "INSERT");
                        indeksBuku++;
                        getMaxLen(tbuku, indeksBuku);
                        judulTabel("No_Buku", "Judul", "Pengarang", "Jenis_Buku", "Tahun_Terbit");
                        tampilTData(tbuku, indeksBuku);
                        currentData(tbuku, indeksBuku, "Buku");
                    }else {     //kondisi jika id anggota ditemukan
                        dataExist();
                    }
                }
            }else if(tableCheck(query) == 3) {      //kondisi jika tabel pinjam
                if(checkLenQuery(query) == 1) {     //kondisi jika panjang akta pada setiap kolom memenuhi 
                    startKata(query);
                    incKata(query);
                    incKata(query);
                    if(sequentialSearch(indeksPinjam, getCurrentKata(), tpinjam) == 0){         //kondisi jika no pinjam tidak ditemukan
                        incKata(query);
                        if(sequentialSearch(indeksAnggota, getCurrentKata(), tanggota) == 0){   //kondisi jika id anggota tidak ditemukan
                            DatanotFoundAlert();
                        }else if(sequentialSearch(indeksAnggota, getCurrentKata(), tanggota) == 1){ //kondisi jika id anggota ditemukan
                            incKata(query);
                            if(sequentialSearch(indeksBuku, getCurrentKata(), tbuku) == 0){     //kondisi jika no buku tidak ditemukan
                                DatanotFoundAlert();
                            }else{  //kondisi jika no buku ditemukan 
                                DMLData(query, &tpinjam[indeksPinjam], "tPinjam", "INSERT");
                                indeksPinjam++;
                                getMaxLen(tpinjam, indeksPinjam);
                                judulTabel("No_Pinjam", "Id_Anggota", "No_Buku", "Tgl_Pinjam", "Tgl_Kembali");
                                tampilTData(tpinjam, indeksPinjam);
                                currentData(tpinjam, indeksPinjam, "Pinjam");
                            }
                        }                    
                    }else { //kondisi jika no pinjam ditemukan
                        dataExist();
                    }
                }
            }else { //kondisi jika tabel tidak ditemukan 
                tableNotFoundAlert();
            }
        }else if(DMLCheck(query) == 0) {    //kondisi jika DML tidak ditemukan
            errorAlert();
        }else if(DMLCheck(query) == 2) {    //kondisi jika DML = UPDATE
            incKata(query);
            if(tableCheck(query) == 1) {    //kondisi jika tabel anggota
                if(checkLenQuery(query) == 1){  //kondisi jika kata pada kolom memenuhi syarat
                    startKata(query);
                    incKata(query);
                    incKata(query);
                    if(sequentialSearch(indeksAnggota, getCurrentKata(), tanggota) == 1){       //kondisi jika id naggota ditemukan
                        DMLData(query, &tanggota[indeksSearch], "tAnggota", "UPDATE");
                        getMaxLen(tanggota, indeksAnggota);
                        judulTabel("Id_Anggota", "Nama", "Kota", "Jenis_Kelamin", "No_Telp");
                        tampilTData(tanggota, indeksAnggota);
                        currentData(tanggota, indeksAnggota, "Anggota");
                    }else { //kondisi jika id anggota tidak ditemukan
                        DatanotFoundAlert();
                    }
                }
            }else if(tableCheck(query) == 2) {  //kondisi jika tabel buku 
                if(checkLenQuery(query) == 1){  //kondisi jika kata pada kolom memenuhi syarat
                    startKata(query);
                    incKata(query);    
                    incKata(query);
                    if(sequentialSearch(indeksBuku, getCurrentKata(), tbuku) == 1){ //kondisi jika no buku ditemukan
                        DMLData(query, &tbuku[indeksSearch], "tBuku", "UPDATE");
                        getMaxLen(tbuku, indeksBuku);
                        judulTabel("No_Buku", "Judul", "Pengarang", "Jenis_Buku", "Tahun_Terbit");
                        tampilTData(tbuku, indeksBuku);
                        currentData(tbuku, indeksBuku, "Buku");
                    }else { //kondisi jika no buku tidak ditemukan
                        DatanotFoundAlert();
                    }
                }
            }else if(tableCheck(query) == 3) {  //kondisi jika tabel pinjam
                if(checkLenQuery(query) == 1){  //kondisi jika kata pada kolom memenuhi syarat
                    startKata(query);
                    incKata(query);
                    incKata(query);
                    if(sequentialSearch(indeksPinjam, getCurrentKata(), tpinjam) == 1){ //kondisi jika no pinjam ditemukan
                        tempIndexSearch = indeksSearch;
                        incKata(query);
                        if(sequentialSearch(indeksAnggota, getCurrentKata(), tanggota) == 0){   //kondisi jika id anggota tidak ditemukan
                            DatanotFoundAlert();
                        }else if(sequentialSearch(indeksAnggota, getCurrentKata(), tanggota) == 1){ //kondisi jika id anggota ditemukan
                            incKata(query);
                            if(sequentialSearch(indeksBuku, getCurrentKata(), tbuku) == 0){     //kondisi jika no buku tidak ditemukan
                                DatanotFoundAlert();
                            }else{  //kondisi jika no buku ditemukan 
                                DMLData(query, &tpinjam[tempIndexSearch], "tPinjam", "UPDATE");
                                getMaxLen(tpinjam, indeksPinjam);
                                judulTabel("No_Pinjam", "Id_Anggota", "No_Buku", "Tgl_Pinjam", "Tgl_Kembali");
                                tampilTData(tpinjam, indeksPinjam);
                                currentData(tpinjam, indeksPinjam, "Pinjam");   
                            }
                        }
                    }else { //kondisi jika no pinjam tidak ditemukan
                        DatanotFoundAlert();
                    }
                }
            }else { //kondisi jika tabel tidak ditemukan
                tableNotFoundAlert();
            }
        }else if(DMLCheck(query) == 3) {    //kondisi jika DML = DELETE
            incKata(query);
            if(tableCheck(query) == 1){     //kondisi tabel anggota
                incKata(query);
                if(sequentialSearch(indeksAnggota, getCurrentKata(), tanggota) == 1) {  //kondisi jika id anggota ditemukan
                    if(eopKata(query) == 0){    //kondisi jika query tidak memiliki titik koma
                        errorAlert();
                    }else{  //kondisi jika query memiliki titik koma
                        printf("afwefawe\n");
                        DMLDelete(indeksAnggota, tanggota);
                        getMaxLen(tanggota, indeksAnggota);
                        judulTabel("Id_Anggota", "Nama", "Kota", "Jenis_Kelamin", "No_Telp");
                        tampilTData(tanggota, indeksAnggota-1);
                        currentData(tanggota, indeksAnggota-1, "Anggota");
                    }
                }else{  //kondisi jika id anggota tidak ditemukan
                    DatanotFoundAlert();
                }
            }else if(tableCheck(query) == 2){   //kondisi tabel buku
                incKata(query);
                if(sequentialSearch(indeksBuku, getCurrentKata(), tbuku) == 1) {    //kondisi jika no buku ditemukan
                    if(eopKata(query) == 0){    //kondisi jika query tidak memiliki titik koma
                        errorAlert();
                    }else{  //konidisi jika query memiliki titik koma
                        DMLDelete(indeksBuku, tbuku);
                        getMaxLen(tbuku, indeksBuku);
                        judulTabel("No_Buku", "Judul", "Pengarang", "Jenis_Buku", "Tahun_Terbit");
                        tampilTData(tbuku, indeksBuku-1);
                        currentData(tbuku, indeksBuku-1, "Buku");
                    }
                }else { //kondisi jika no buku tidak ditemukan
                    DatanotFoundAlert();
                }
            }else if(tableCheck(query) == 3){   //kondisi tabel pinjam
                incKata(query);
                if(sequentialSearch(indeksPinjam, getCurrentKata(), tpinjam) == 1) {    //kondisi jika no pinjam ditemukan
                    if(eopKata(query) == 0){    //kondisi jika query tidak memiliki titik koma
                        errorAlert();
                    }else{  //kondisi jika query memiliki titik koma
                        DMLDelete(indeksPinjam, tpinjam);
                        getMaxLen(tpinjam, indeksPinjam);
                        judulTabel("No_Pinjam", "Id_Anggota", "No_Buku", "Tgl_Pinjam", "Tgl_Kembali");
                        tampilTData(tpinjam, indeksPinjam-1);
                        currentData(tpinjam, indeksPinjam-1, "Pinjam");
                    }
                }else{  //kondisi jika no pinjam tidak ditemukan
                    DatanotFoundAlert();
                }
            }else{  //kondisi jika tabel tidak sesuai
                tableNotFoundAlert();
            }
        }else if(DMLCheck(query) == 4) {    //kondisi DML = SELECT
            if(selectAllTable(query) == 1) {    //kondisi untuk menampilkan seluruh tabel
                showAllTable(tanggota, tbuku, tpinjam);
            }else{  //kondisi untuk menampilkan satu persatu tabel
                startKata(query);
                incKata(query);
                if(tableCheck(query) == 1){     //menampilkan tabel anggota
                    if(eopKata(query) == 0){    //jika titik koma tidak ada
                        errorAlert();
                    }else{  //jika titik koma ada
                        getMaxLen(tanggota, indeksAnggota);
                        judulTabel("Id_Anggota", "Nama", "Kota", "Jenis_Kelamin", "No_Telp");
                        tampilTData(tanggota, indeksAnggota);
                        currentData(tanggota, indeksAnggota, "Anggota");
                    }
                }else if(tableCheck(query) == 2) {  //menampilkan tabel buku
                    if(eopKata(query) == 0){    //jika titik koma tidak ada
                        errorAlert();
                    }else{  //jika titik koma ada
                        getMaxLen(tbuku, indeksBuku);
                        judulTabel("No_Buku", "Judul", "Pengarang", "Jenis_Buku", "Tahun_Terbit");
                        tampilTData(tbuku, indeksBuku);
                        currentData(tbuku, indeksBuku, "Buku");
                    }
                }else if(tableCheck(query) == 3) {  //menampilkan tabel pinjam
                    if(eopKata(query) == 0) {   //tidak memiliki titik koma
                        errorAlert();
                    }else { //memiliki titik koma
                        getMaxLen(tpinjam, indeksPinjam);
                        judulTabel("No_Pinjam", "Id_Anggota", "No_Buku", "Tgl_Pinjam", "Tgl_Kembali");
                        tampilTData(tpinjam, indeksPinjam);
                        currentData(tpinjam, indeksPinjam, "Pinjam");
                    }
                }else{   //kondisi tabel tidak ditemukan
                    tableNotFoundAlert();
                }
            }
        }
    } 
}