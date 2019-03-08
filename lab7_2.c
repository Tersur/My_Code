#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char *argv[]){
    char ch;
    FILE *fp, *fp1;
    unsigned long count = 0, count1 = 0;

    if (argc<3){
        printf("Usage: filename textfile1 textfile2\ntextfile1: file to be read\ntextfile2: file to be written\n");
        return 0;
    }
    else if(argc>3){
        printf("Usage: filename textfile1 textfile2\ntextfile1: file to be read\ntextfile2: file to be written\n");
        return 0;
    }

    fp = fopen(argv[1], "r");
    fp1 = fopen(argv[2], "w");
    if ((fp) == NULL){
        printf("Can't open file1\n");
        return 0;
    }
    if ((fp1) == NULL){
        printf("Can't open file2\n");
        return 0;
    }
    
    printf("In %s\n", argv[1]);
    printf("\n");
    while((ch = fgetc(fp))!=EOF){
        putc(ch, stdout);
        fputc(ch, fp1);
        if(isalpha(ch)){
            count++;
        }
        count1++;
    }
    printf("\n");

    fclose(fp);
    fclose(fp1);
    fp1 = fopen(argv[2], "r");
    printf("\n");
    printf("In %s\n", argv[2]);
    printf("\n");
    while((ch = fgetc(fp1))!= EOF){
        putc(ch, stdout);
    }
    printf("\n");

    printf("The number of words in the file %s is %lu\nThe number of characters in the file %s is %lu\n", argv[1], count, argv[1], count1);
    fclose(fp1);

    return 1;
}