/* \file Lab5_2.c
	  \Basil Gaji
	  \date 02/24/2019
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(void){

    const char* notes[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    char input_note[4];
    int result, root, third, fifth;

    printf("*** Chord Guide ***\n");
    printf("Enter the root note: ");
    scanf("%s", input_note);
    while(getchar()!='\n'){}
    
    int i;
    while (true){
        for (i = 0; i <= 11; i++){
            result = strcmp(notes[i], input_note);
            //printf("%d\n", result);
            //printf("%s\n", input_note);
            if (result == 0){
                break;
            }
        }
        if (result == 0){
            break;
        }    
            
        printf("Invalid input! Enter again: ");
        scanf("%s", input_note);
        while(getchar()!='\n'){}
       
    }
    root = i;
    third = (i + 4)%12;
    fifth =(i + 7)%12;
    
        
        printf("The notes for this chord are: %s %s %s\n", *(notes + root), *(notes+ third), *(notes + fifth));
        return 0;
}


