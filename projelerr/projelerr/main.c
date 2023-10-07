#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

//Musterilerin nosunu, adını, soyadını ve bakiyesini struct yapıda tanımladık
struct musteri{
    int no;
    char ad[20];
    char soyad[20];
    int bakiye;
};

int main(void){
    //Boş müşteriler için struct yapıda main de tanımladık
    struct musteri bosMusteri = {0,"","",0};
    
    FILE *ptr;
    int i;
    
    //100 Müşterilik yer ayrrıldı
    if((ptr = fopen("/Users/ebrurazi/Desktop/MusteriKayitlari.txt","w")) != NULL){
        for (i=0;i<100;i++) {
            //Dosyayı yazmak için
            fwrite(&bosMusteri,sizeof(struct musteri),1,ptr);
        }
   }

    fclose(ptr);
    printf("100 müşteri kaydı için gerekli yer tahsis edildi\n");

    //5 adet Müşteri kaydı için
    if((ptr = fopen("/Users/ebrurazi/Desktop/MusteriKayitlari.txt","r+")) != NULL){
        printf("5 adet müşteri bilgilerini giriniz : \n");
        for (i=0;i<5;i++) {
            printf("%d. musterinin no, ad, soyad, bakiye : ",i+1);
            scanf("%d%s%s%d",&bosMusteri.no,bosMusteri.ad,bosMusteri.soyad,&bosMusteri.bakiye);
            fseek(ptr,(bosMusteri.no-1)*sizeof(struct musteri),SEEK_SET);//Kayıt yapılacak yerin kooordinatlarını belirledik
            
            fwrite(&bosMusteri,sizeof(struct musteri),1,ptr);//Yazma işlemini yaptık
        }
    }
    fclose(ptr);
    printf("Müşteri kayıt işlemi tamamlandı \n");
    
    //Kayıtlı müşterileri okuma
    if((ptr = fopen("/Users/ebrurazi/Desktop/MusteriKayitlari.txt","r")) != NULL){
        
        printf("Kayıtlı müşteri bilgileri : \n");
        printf("%s\t%s\t\t%s\t\t%s\n","NO","Ad","SOYAD","BAKİYE");
        
        while (!feof(ptr)) {
            
            fread(&bosMusteri,sizeof(struct musteri),1,ptr);//Okuma işlemini yaptık
            if (bosMusteri.no != 0)//Nosu 0'ları yazmaz
            printf("%d\t%s\t%s\t%d\n",bosMusteri.no,bosMusteri.ad,bosMusteri.soyad,bosMusteri.bakiye);
        }
    }
    fclose(ptr);
    printf("Kayıtlı müşteri bilgileri listeleme işlemi tamamlandı\n");
    printf("\n");
    return 0;
}
