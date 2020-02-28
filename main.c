#include <stdio.h>
#include <stdlib.h>

int partisayisi=0;
int mvsay(int sehirsec[partisayisi][5],int partisayisi,int mvkont,int oy[partisayisi][2]);
int guncelle(int genelsec[partisayisi][5],int sehirsec[partisayisi][5],int partisayisi);
int bubblesort(int sehirsec[partisayisi][5],int partisayisi);
int birincibul(int sehirsec[partisayisi][5],int partisayisi);
int ikincibul(int sehirsec[partisayisi][5],int partisayisi,int birinciad);
void ulkesonuc(int genelsec[partisayisi][5],int partisayisi,int topgeclioy,int topmvsayisi);
void ulkesonuc(int genelsec[partisayisi][5],int partisayisi,int topgeclioy,int topmvsayisi)
{
        printf("------Turkiye Geneli------\n\n");
        printf("Milletvekili Kontenjani: %d\n",topmvsayisi);
        printf("Gecerli Oy Sayisi      : %d\n\n\n",topgeclioy);
        printf("\t\t     Oy Sayisi \t Oy Yuzdesi \t Mv Sayisi \t Mv Yuzdesi \n");
        printf("\t\t     ----------\t ---------- \t --------- \t ---------- \n");
        int m;
        float oyuzde=0.00;
        float mvyuzde=0.00;
        for(m=0;m<partisayisi;m++)
        {
            oyuzde=((float)genelsec[m][1]/(float)topgeclioy)*100;
            mvyuzde=((float)genelsec[m][2]/(float)topmvsayisi)*100;
            printf("%c Partisi \t\t %d \t\t %.2f \t\t %d \t\t %.2f  \n\n\n",genelsec[m][0],genelsec[m][1],oyuzde,genelsec[m][2],mvyuzde,genelsec[m][3],genelsec[m][4]);
        }
        int iktidar=birincibul(genelsec,partisayisi);
        int muhalefet=ikincibul(genelsec,partisayisi,genelsec[iktidar][0]);

        printf("Iktidar Partisi: %c Partisi\n",genelsec[iktidar][0]);
        printf("Ana Muhalefet Partisi: %c  Partisi\n",genelsec[muhalefet][0]);
}
void sehirsonuc(int sehirsec[partisayisi][5],int partisayisi,int topgeclioy)
{
        printf("\t\t     Oy Sayisi \t Oy Yuzdesi \t Mv Sayisi\n");
        printf("\t\t     --------- \t ---------- \t ---------\n");
        int m;
        float oyuzde=0.00;
        for(m=0;m<partisayisi;m++)
        {
            oyuzde=((float)sehirsec[m][1]/(float)topgeclioy)*100;
            printf("%c Partisi \t\t %d \t\t %.2f \t\t %d \n",sehirsec[m][0],sehirsec[m][1],oyuzde,sehirsec[m][2]);
        }
        printf("Devam etmek icin bir tusa basiniz...\n");
}
int main()
{
    int plakod;
    int mvkont;
    printf("Parti Sayisi Giriniz: ");
    scanf("%d",&partisayisi);
    int genelsec[partisayisi][5];
    int oy[partisayisi][2];
    int sehirsec[partisayisi][5];

    int i,j,k=65,l=65;
    for(i=0;i<partisayisi;i++){
        oy[i][0]=0;
        oy[i][1]=0;
        genelsec[i][0]=k++;
        sehirsec[i][0]=l++;

        for(j=1;j<5;j++){
            genelsec[i][j]=0;
            sehirsec[i][j]=0;
        }
    }
    int ulkegeclioy=0;
    int topmvsayisi=0;

    while(1>0)
    {
        printf("Il Plaka Kodu Giriniz: ");
        scanf("%d",&plakod);

        int tempgenelsec;
        if(plakod==0)
        {
            ulkesonuc(genelsec,partisayisi,ulkegeclioy,topmvsayisi);
            break;
        }
        int sehirgeclioy=0;
        printf("Millet Vekili Kontenjani Giriniz: ");
        scanf("%d",&mvkont);
        topmvsayisi+=mvkont;
        int i;
        int partiad=65;
        for(i=0;i<=partisayisi-1;i++)
        {
            oy[i][0]=partiad;
            printf("%c Partisinin Aldigi Oy Sayisi: ",partiad++);
            scanf("%d",&oy[i][1]);
            genelsec[i][1]+=oy[i][1];
            sehirgeclioy+=oy[i][1];
            ulkegeclioy+=oy[i][1];
            sehirsec[i][1]+=oy[i][1];
        }
        printf("\n");
        printf("Il Plaka Kodu: %d \n",plakod);
        printf("Millet Vekili Kontenjan: %d \n",mvkont);
        printf("Gecerli Oy: %d \n",sehirgeclioy);

        int tempsehirsec= mvsay(sehirsec,partisayisi,mvkont,oy);
        sehirsonuc(sehirsec,partisayisi,sehirgeclioy);
        tempgenelsec=guncelle(genelsec,sehirsec,partisayisi);
    }
   return 0;
}
    int guncelle(int arraybir[partisayisi][5],int arrayiki[partisayisi][5],int partisayisi)
    {
    int i,j, swapval=0;
    for(i=0;i<partisayisi;i++){
        for(j=0;j<partisayisi;j++){
            if(arraybir[i][0]==arrayiki[j][0]){
                    swapval=arrayiki[j][2];
                    arraybir[i][2]+=swapval;
                    swapval=arrayiki[j][3];
                    arraybir[i][3]+=swapval;
                    swapval=arrayiki[j][4];
                    arraybir[i][4]+=swapval;

                    arrayiki[j][1]=0;
                    arrayiki[j][2]=0;
                    arrayiki[j][3]=0;
                    arrayiki[j][4]=0;
            }
        }
    }
    return arraybir;
}
int mvsay(int sehirsec[partisayisi][5],int partisayisi,int mvkont,int oy[partisayisi][2])
{
        int sortarray=bubblesort(sehirsec,partisayisi);
        int i,j;
        int birinciparti;
        for(i=0;i<mvkont;i++){
            sehirsec[0][2]++;
            sehirsec[0][1]=sehirsec[0][1]/2;
            sehirsec=bubblesort(sehirsec,partisayisi);
        }

        birinciparti=birincibul(sehirsec,partisayisi);
        sehirsec[birinciparti][3]++;
        for(i=0;i<partisayisi;i++)
        {
            if(sehirsec[i][2]==0){
               sehirsec[i][4]++;
            }
        }
        int oyval=0;
        for(i=0;i<partisayisi;i++){
            for(j=0;j<partisayisi;j++){
                if(sehirsec[i][0]==oy[j][0]){
                    oyval=oy[j][1];
                    sehirsec[i][1]=oyval;
                }
            }
        }

        sehirsec=bubblesort(sehirsec,partisayisi);
        return sehirsec;
}
int birincibul(int sehirsec[partisayisi][5],int partisayisi)
{
    int i,j;
    int enfazlaparti=0;
    int enfazlamv=sehirsec[0][2];
    int enfazlaoy=sehirsec[0][1];
    for(i=1;i<partisayisi;i++)
    {
        if(enfazlamv<sehirsec[i][2])
        {
            enfazlamv=sehirsec[i][2];
            enfazlaoy=sehirsec[i][1];
            enfazlaparti=i;
        }
        if(enfazlamv==sehirsec[i][2] && enfazlaoy<sehirsec[i][1])
        {
            enfazlamv=sehirsec[i][2];
            enfazlaoy=sehirsec[i][1];
            enfazlaparti=i;
        }
    }
    return enfazlaparti;
}
int ikincibul(int sehirsec[partisayisi][5],int partisayisi,int birinciad)
{
    int i,j,k;
    int enfazlaparti=0;
    int enfazlamv=0;
    int enfazlaoy=0;
    for(k=0;k<partisayisi;k++){
        if(sehirsec[k][0]!=birinciad)
        {
        enfazlamv=sehirsec[k][2];
        enfazlaoy=sehirsec[k][1];
        enfazlaparti=k;
        break;
        }
    }
    for(i=0;i<partisayisi;i++)
    {
        if(sehirsec[i][0]!=birinciad && i!=k)
        {
             if(enfazlamv<sehirsec[i][2])
        {
            enfazlamv=sehirsec[i][2];
            enfazlaoy=sehirsec[i][1];
            enfazlaparti=i;
        }
        if(enfazlamv==sehirsec[i][2] && enfazlaoy<sehirsec[i][1])
        {
            enfazlamv=sehirsec[i][2];
            enfazlaoy=sehirsec[i][1];
            enfazlaparti=i;
        }
        }

    }
    return enfazlaparti;
}
int bubblesort(int sehirsec[partisayisi][5],int partisayisi)
{
     int i,j,swapoy,swapmvsay,swapbir,swapsifir,swapparti;
    for(i=0;i<partisayisi-1;i++){
        for(j=0;j<partisayisi-i-1;j++)
        {
            if (sehirsec[j][1]<sehirsec[j+1][1])
            {
                swapparti=sehirsec[j+1][0];
                swapoy=sehirsec[j+1][1];
                swapmvsay=sehirsec[j+1][2];
                swapbir=sehirsec[j+1][3];
                swapsifir=sehirsec[j+1][4];

                sehirsec[j+1][0]=sehirsec[j][0];
                sehirsec[j+1][1]=sehirsec[j][1];
                sehirsec[j+1][2]=sehirsec[j][2];
                sehirsec[j+1][3]=sehirsec[j][3];
                sehirsec[j+1][4]=sehirsec[j][4];

                sehirsec[j][0]=swapparti;
                sehirsec[j][1]=swapoy;
                sehirsec[j][2]=swapmvsay;
                sehirsec[j][3]=swapbir;
                sehirsec[j][4]=swapsifir;
            }
        }
}
return sehirsec;

}
