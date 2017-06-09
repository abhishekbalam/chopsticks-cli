#include<stdio.h>
#include<conio.h>
//#include<iostream.h>
#include<windows.h>
#include<stdlib.h>
#include "chopstics.h"
int main(void)
{
intro();
rules();
names();
turns(l1,r1,l2,r2);
}
void key(){
	getch();
	}
void intro(){
	system("cls");
	printf("Welcome to Abhishek's C Chopsticks.\n");
	key();
	system("cls");
	printf("About:\nI have tried it to make it as close to the original one as possible.\nThe rest you gonna have to make up with your imagination.\nPress ENTER to read the rules.");
	key();
	}
void rules(){
	system("cls");
	printf("The instructions :\n");
	printf("1)Press 1 or 2 to enter your choice throughout the game.\n");
	printf("2)All moves are irreversible.\n");
	printf("3)DIVISION is allowed only if\n the sum of the digits in both hands is even.\n");
	printf("4)DIVISION results in equal number of digits in each hand.\n");
	printf("5)Partial TRANSFER of digits is not allowed..\n");
	printf("6)Be careful to not enter anything other than what is asked.\n");
	printf("7)Enter only first names.\n");
	printf("8)Have fun!\n");

	printf("Press ENTER to begin");
	key();
	}
void names(){
	system("cls");
	printf("Player 1 enter your name:\n");
	gets(Player1);
	system("cls");
	printf("Player 2 enter your name:\n");
	gets(Player2);
	system("cls");
	}
void turns(int l1,int r1,int l2, int r2){
            void check();
            check();
            player1();
            key();
            check();
            player2();
            key();
            check();
            return turns(l1,r1,l2,r2);
            }
void pHeader(){
	system("cls");
	printf("\t\t%s",Player1);
	printf("\t\t\t\t\t");
	printf("%s",Player2);
	printf("\n\t\t");
	printf("L1\tR1\t\t\t\tL2\tR2");
	printf("\n\t\t");
	printf("%d\t%d\t\t\t\t%d\t%d",l1,r1,l2,r2);
	printf("\n");
	}
void player1(){
	int combo;
	char move;
	pHeader();
	printf("\n");
	printf("%s",Player1);
	printf(" Choose your move\n");
	printf("1)TAP the other player.\n2)TRANSFER your digits to one hand .\n3)DIVIDE your digits.\n");
	scanf("%c",&move);
	switch(move){
		case '1':tap1();
			break;
		case '2':trans1();
			break;
		case '3':combo=(l1+r1)%2;
			if(combo==1){
				printf("\n\aSum is odd,cant divide.Press ENTER to Choose a different move.\n");
				key();
				player1();
				}
			else{
				divide1();}
				break;
		default:player1();

		};
}
void tap1(){
	pHeader();
	char tap;
	printf("Choose with which hand you want to tap.\n");
	printf("1)Left hand.\n2)Right hand.\n");
	scanf("%c",&tap);
	switch(tap){
		case '1':Tap1a();
			break;
		case '2':Tap2a();
			break;
        default :tap1();

		};
	}
void Tap1a(){
	pHeader();
	char tap1;
	printf("Choose which hand you want to tap TO.\n");
	printf("1)Left hand.\n2)Right hand.\n");
	scanf("%c",&tap1);
	switch(tap1){
		case '1':l2=l1+l2;
			if(l2>=5){
			l2=l2-5;
			}
			pHeader();
			break;
		case '2':r2=l1+r2;
			if(r2>=5){
			r2=r2-5;
			}
			pHeader();
			break;
        default :Tap1a();

		};
	//key();
	}
void Tap2a(){
	pHeader();
	char tap1;
	printf("Choose which hand you want to tap TO.\n");
	printf("1)Left hand.\n2)Right hand.\n");
	scanf("%c",&tap1);
	switch(tap1){
		case '1':l2=r1+l2;
			if(l2>=5){
			l2=l2-5;
			}
			pHeader();
			break;
		case '2':r2=r1+r2;
			if(r2>=5){
			r2=r2-5;
			}
			pHeader();
			break;
        default: Tap2a();

		};
	//key();
	}
void trans1(){
	pHeader();
	char sw;
	printf("Choose which hand to transfer to.\n");
	printf("1)Left Hand\n2)Right Hand\n");
	scanf("%c",&sw);
	switch(sw){
		case '1':l1=r1+l1;
			if(l1>=5){
			l1=l1-5;
			}
			r1=0;
			pHeader();
			break;
		case '2':r1=r1+l1;
			if(r1>=5){
			r1=r1-5;
			}
			l1=0;
			pHeader();
			break;
        default: trans1();
		   };
	   }
void divide1(){
	pHeader();
	printf("Press enter to divide");
	key();
	l1=(l1+r1)/2;
	r1=l1;
	pHeader();
	}

void player2(){
	int combo;
	char move;
	pHeader();
	printf("\n");
	printf("%s",Player2);
	printf(" Choose your move\n");
	printf("1)TAP the other player.\n2)TRANSFER your digits to one hand .\n3)DIVIDE your digits.\n");
	scanf("%c",&move);
	switch(move){
		case '1':tap2();
			break;
		case '2':tran2();
			break;
		case '3':combo=(l2+r2)%2;
			if(combo==1){
				printf("\n\aSum is odd,cant divide.Press ENTER to Choose a different move.\n");
				key();
				player2();
				}
			else{
				divide2();
				}
			break;
		default:player2();

		};
}
void tap2(){
	pHeader();
	char tap;
	printf("Choose with which hand you want to tap.\n");
	printf("1)Left hand.\n2)Right hand.\n");
	scanf("%c",&tap);
	switch(tap){
		case '1':Tap1b();
			break;
		case '2':Tap2b();
			break;
        default: tap2();
		};
	}
void Tap1b(){
	pHeader();
	char tap1;
	printf("Choose which hand you want to tap TO.\n");
	printf("1)Left hand.\n2)Right hand.\n");
	scanf("%c",&tap1);
	switch(tap1){
		case '1':l1=l2+l1;
			if(l1>=5){
			l1=l1-5;
			}
			pHeader();
			break;
		case '2':r1=l2+r1;
			if(r1>=5){
			r1=r1-5;
			}
			pHeader();
			break;
        default: Tap1b();
		};
	//key();
	}
void Tap2b(){
	pHeader();
	char tap;
	printf("Choose which hand you want to tap TO.\n");
	printf("1)Left hand.\n2)Right hand.\n");
	scanf("%c",&tap);
	switch(tap){
		case '1':l1=r2+l1;
			if(l1>=5){
			l1=l1-5;
			}
			pHeader();
			break;
		case '2':r1=r2+r1;
			if(r1>=5){
			r1=r1-5;
			}
			pHeader();
			break;
        default: Tap2b();

		};
	key();
	}
void tran2(){
	pHeader();
	char w;
	printf("Choose which hand to transfer to.\n");
	printf("1)Left Hand\n2)Right Hand\n");
	scanf("%c",&w);
	switch(w){
		case '1':l2=r2+l2;
			if(l2>=5){
			l2=l2-5;
			}
			r2=0;
			pHeader();
			break;
		case '2':r2=r2+l2;
			if(r2>=5){
			r2=r2-5;
			}
			l2=0;
			pHeader();
			break;
        default: tran2();
		   };
        }
void divide2(){
	pHeader();
	printf("Press enter to divide");
	key();
	l2=(l2+r2)/2;
	r2=l2;
	pHeader();
	}

void check(){
                if((l1==0)&&(r1==0)){
                    system("cls");
                    printf("\t\t\t%s",Player2);
                    printf("\tWON!!\n");
                    printf("\t\t\t\tCongrats!!\n\n\n");
                    key();
                    printf("\n\t\tThanks For Playin My Game.\n\t\tTell me if you like it. :)\n\n\n\n\n\n");
                    exit(0);
                        }
                    if((l2==0)&&(r2==0)){
                    system("cls");
                    printf("\t\t\t%s",Player1);
                    printf("\tWON!!\n\n\n");
                    printf("\t\t\t\tCongrats!!\n\n");
                    key();
                    printf("\n\tThanks For Playin My Game.\n\tTell me if you like it. :)\n\n\n\n\n\n");
                    exit(0);
                        }

                    }

