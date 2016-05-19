#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>


int check_valid(char c, char b, char a ){
	if(c == 'x' || b == 'x' || c == 'x'){
		if(c != a || a != b || c != b || b!= c){
			return 1;
		}
	}
	if(a == 'x' && b == 'x' && c == 'x'){
		printf("\n\n\n\n\n\n\n\nYou have entered three consecutive 'x'.\nNOTE THAT THE BOAT STAYS STILL IF UNOCCUPIED.\n\n\n\n\n\n\n\n\n\n");
		return 0;
	}
	if(((a != 'a' && a != 'A' && a != 'b' && a != 'B' && a != 'c' && a != 'C' && a != 'd' && a != 'D' && a != 'e' && a != 'E' && a != 'x' ) || (b != 'a' && b != 'A' && b != 'b' && b != 'B' && b != 'c' && b != 'C' && b != 'd' && b != 'D' && b != 'e' && b != 'E' && b != 'x') || (c != 'a' && c != 'A' && c != 'b' && c != 'B' && c != 'c' && c != 'C' && c != 'd' && c != 'D' && c != 'e' && c != 'E' && c != 'x')))
	{
	    printf("\n\n\n\n\n\n\n\nOnly enter letters from A / a to E / e and x (for unoccupied space/spaces in the boat).\nCapital letters for males and small letters for females.\n\n\n\n\n\n\n\n\n\n\n ");
	    return 0;
	    }
	else{ if(c != a && a != b && c != b && b!= c){
		return 1;
          }
          else{
            printf("\n\n\n\n\n\n\nDividing your input into groups of three, you'll see that you entered two or more of the same letters in one group.\n...Clones are not allowed in this puzzle :)\n\n\n\n\n\n\n\n\n\n\n");
          }

          }

	return 0 ;
}

int main(){

	char ans[100];                      // m n and o are the checking trios
 	int length = 0, i = 0,check = 1, j = 0, k = 0, blocker = 3,l = 0, m = 0, n = 0, o = 0, angry = 0,p = 0,last = 0;  // k is temp value of i during crossing back to initial side.. blocker works like a counter..
 	char original[10]= {'A','B','C','D','E','a','b','c','d','e'};

  printf("A BOAT FOR THREE\n\n");
  printf("\tDuring certain local floods, five married couples found themselves surrounded by water and had to escape from their unpleasant position in a boat that would only hold three persons at a time. Every husband was so jealous that he would not allow his wife to be in the boat or on either bank with another man (or with other men) unless he, himself, present. Show the quickest way of getting these five men and their wives across into safety.\n\n");
  printf("INSTRUCTIONS:\n\tUse the letters A, B, C, D, and E to represent the men and their respective wives as a, b, c, d, and e. Each crossing requires three persons. If there are less than three people in the boat during a crossing, use x to fill in the missing people. Remember that each crossing requires at least one person because if not, the boat stays still.\n\n");
  printf("Enter your answer here (e.g. cdedexbdebxxABCBxxDEb): ");
    // checking validity of input................................................................................................................................................
	do {
		scanf("%s", ans);

		length = strlen(ans);

		for (i = 0; i < length; i = i + 3){
			check = check_valid(ans[i], ans[i + 1], ans[i + 2]);

			if (!check){
				break;
			}
		}
		//printf("%d",length);
		if (!check){
			printf("Your answer is not valid. Please try again: ");
		}
	} while (!check);
	printf("Congraulations! your answer is valid.\n\n");

	//checking the answer..........................................................................................................................................................

	for( i = 2; i < length; i = i + 3){
		if (i % 2 == 0) {    //even //odd
			for( j = 0; j != 10; j++){        // crossing to the other side
                if(ans[i] == original[j]){
                    original[j] = '0';
                }
                if(ans[i - 1] == original[j] ){
                    original[j] = '0';
                }
                if(ans[i - 2] == original[j]){
                    original[j] = '0';
                }
            }

            for(j = 0; j != 10; j++){
                printf("%c",original[j]);
            }
            printf("\n\n");
        }
		else {     // odd // even
            //  crossing back to the initial side
            k = i; l = i;
            while(blocker != 0){
                  if (ans[k] == 'x'){
                    k--;
                    blocker = blocker - 1;
                    if(ans[k] == 'x'){
                        k--;
                        blocker = blocker - 1;
                    }
                  }
                  if(ans[k] == 65)
                    original[0] = ans[k];
                  if(ans[k] == 66)
                    original[1] = ans[k];
                  if(ans[k] == 67)
                    original[2] = ans[k];
                  if(ans[k] == 68)
                    original[3] = ans[k];
                  if(ans[k] == 69)
                    original[4] = ans[k];
                  if(ans[k] == 97)
                    original[5] = ans[k];
                  if(ans[k] == 98)
                    original[6] = ans[k];
                  if(ans[k] == 99)
                    original[7] = ans[k];
                  if(ans[k] == 100)
                    original[8] = ans[k];
                  if(ans[k] == 101)
                    original[9] = ans[k];
                  blocker = blocker - 1;
                  k = k - 1;
            }

            for(j = 0; j != 10; j++){
                printf("%c",original[j]);
            }
            printf("\n\n");
		}
        // correction..........................................................................


            for(m = 0; m != 10;m++ ){
                 if(original[m] == 65 ){
                    if(angry != 0)
                            break;
                    if(original[5] == 97){
                            p = 1;
                        }
                   // printf("%d\n",p);
                   // printf("%d",original[1]);
                    if(p == 0){
                            if(original[0] == 48)
                                angry = 1;
                            if(original[1] == 48)
                                angry = angry + 1;
                            if(original[3] == 48)
                                angry = 1;
                            if(original[4] == 48)
                                angry = 1;
                            }
                    //printf("%d\n",angry);
                    }
                 p = 0;
                 if(original[m] == 66 ){
                    if(angry != 0)
                            break;
                    if(original[6] == 98){
                            p = 1;
                        }
                   // printf("%d\n",p);
                   // printf("%d",original[1]);
                    if(p == 0){
                            if(original[0] == 48)
                                angry = 2;
                            if(original[1] == 48)
                                angry = angry + 2;
                            if(original[3] == 48)
                                angry = 2;
                            if(original[4] == 48)
                                angry = 2;
                            }
                    //printf("%d\n",angry);
                    }

                p = 0;
                if(original[m] == 67 ){
                    if(angry != 0)
                            break;

                    if(original[7] == 99){
                            p = 1;
                    }

                   // printf("%d\n",p);
                    //printf("%d",original[1]);
                    if(p == 0){
                            if(original[0] == 48)
                                angry = 3;
                            if(original[1] == 48)
                                angry = angry + 3;
                            if(original[3] == 48)
                                angry = 3;
                            if(original[4] == 48)
                                angry = 3;
                            }

                    }
                    p = 0;
                    if(original[m] == 68 ){
                    if(angry != 0)
                            break;
                        if(original[8] == 100){
                            p = 1;
                        }
                   // printf("%d\n",p);
                   // printf("%d",original[1]);
                    if(p == 0){
                            if(original[0] == 48)
                                angry = 4;
                            if(original[1] == 48)
                                angry = angry + 4;
                            if(original[3] == 48)
                                angry = 4;
                            if(original[4] == 48)
                                angry = 4;
                            }
                    //printf("%d\n",angry);
                    }
                    p = 0;
                    if(original[m] == 69 ){
                    if(angry != 0)
                            break;
                    if(original[9] == 101){
                            p = 1;
                        }
                   // printf("%d\n",p);
                   // printf("%d",original[1]);
                    if(p == 0){
                            if(original[0] == 48)
                                angry = 5;
                            if(original[1] == 48)
                                angry = angry + 5;
                            if(original[3] == 48)
                                angry = 5;
                            if(original[4] == 48)
                                angry = 5;
                            }
                    //printf("%d\n",angry);
                    }
                }
        if(angry == 1)
            printf("\nA is angry \n\n"); //break;
        if(angry == 2)
             printf("\nB is angry \n\n"); //break;
        if(angry == 3)
             printf("\nC is angry \n\n"); //break;
        if(angry == 4)
             printf("\nD is angry \n\n"); //break;
        if(angry == 5)
             printf("\nE is angry \n\n"); //break;

        }
       // printf("\n\n%d\n\n",angry);
       for(j = 0; j != 10; j++){
         if(original[j] != 48)
            last = 1;
       } //printf("\n%d", last);
        if(last == 0)
             printf("\nCongratulations ! You solved the puzzle\n\n");
	return 0;
}
