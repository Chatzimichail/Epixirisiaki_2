#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


main(){

    problem();


}

problem() {
    FILE *fp;
    int A[3][3],B,C[13],i=0,minMax,d=5,v,j=0,apo[5],D[10];
    char str1[5],str2[5],pap[5],symb[5],tempM[3],tempP[3];
    FILE *fp1;

    fp1 = fopen("problima.txt","w");
    if (fp1==0)
        printf("to arxeio den brethike!!\n");
    else
        //printf("to arxeio brethike.\n");


    fp=fopen("askisi_1.txt", "r");

     if (fp==0)
        printf("to arxeio den brethike!!\n");
    else
        printf("to arxeio brethike.\n");

    B=fgetc(fp);
    B=fgetc(fp);
    if (B==73 || B==105){
        //printf("to prolima ine min\n");
        minMax=1;
    }
    else{
        minMax=0;
        printf("to prolima ine max\n");
    }
    rewind(fp);
    d=fscanf(fp," %s" , &str1);
    //printf("%s ine %d.\n" , str1,d);
    d=fscanf(fp," %d %d %d ",&C[i],&C[i+1],&C[i+2]);
    //printf("%d %d %d",C[i],C[i+1],C[i+2]);
    d=fscanf(fp," %s" , &str2);
    //printf("\n%s \n" , str2);
    i=3;
    d=5;
    do{
        d=fscanf(fp," %d %d %d %c %d ",&C[i],&C[i+1],&C[i+2],&pap[j],&apo[j]);
        if (d==0) break;
        //printf("%d %d %d %c %d \n",C[i],C[i+1],C[i+2],pap[j],apo[j]);
        i=i+3;
        j++;
    }while(d==5);
    i=0;
    while(d!=EOF){
        d=fgetc(fp);
        if(d==60){
            symb[i]='<';
            i++;
        }
        else if (d==62){
            symb[i]='>';
            i++;
        }
        else if (d==101 || d==69){
            // o arothmos 101 kai 69 ston pinaka asccii einai to agliko e apo to eleytheres
            symb[i]='0';
            i++;
        }
    }

    if(minMax == 0){
        fprintf(fp1,"Min  ");
        C[0]=C[0]*(-1);
        C[1]=C[1]*(-1);
        C[2]=C[2]*(-1);
    }
    else{
        fprintf(fp1,"Max  ");
    }

    for(i=0;i<3;i++)
        fprintf(fp1,"%dx ",apo[i]);

    fprintf(fp1,"\ns.t.  ");


        for(i=0;i<3;i++){
        if (symb[i]=='0'){
            tempP[i]='=';
        }
        else if (symb[i]=='>'){
            tempP[i]='<';
        }
        else if (symb[i]=='<'){
            tempP[i]='>';
        }

        if (pap[i]=='='){
            tempM[i]='e';
        }
        else if (pap[i]=='>'){
            tempM[i]='>';
        }
        else if (pap[i]=='<'){
            tempM[i]='<';
        }
    }


    j=0;
    for(i=3;i<6;i++){
        fprintf(fp1,"\n%dx %dx %dx ",C[i],C[i+3],C[i+6]);
        fprintf(fp1,"%c %d",tempP[j],C[j]);
        j++;
    }
    fprintf(fp1,"\n");
    for (i=0;i<3;i++){
        if(tempM[i]=='e'){
            fprintf(fp1,"x eleftheri");
        }

        else fprintf(fp1," x%c0",tempM[i]);
    }
    printf("To problima lithike!");

    fclose(fp);
    fclose(fp1);


}
