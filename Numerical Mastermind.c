// S11B, Yeohan, 119 CCPROG1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Initialized the Functions. Details of Functions are detailed below

void Design_a();
void Design_b();
void Design_c();
void CheckScore (int nVal, int *w, int *player_score_right, int *player_score_miss, int guess, int *gdigit);
void FourDigitGenerator(int *w, int Digit);
void Tutorial();
void Configuration(int *g, int *p, int *q);
void Credits();
void Game(int Guess_count, int Player_count, int Digit);



//Design_a(), Design_b(), and Design_c(), are just for design of the game.


int main() // Main Menu
{
	int guess = 10;
	int count = 2;
	int digit = 4;
	//Default value of guess is 10, player is 2, required digit is 4. 
	//The menu will hold as a bridge for passing values between functions.
	
	char main_options = 0;        //Switch case
	
	int main_options_quit = 0;   // When a user returns, the menu will not end right away.
	int main_options_quit_b = 0; // The outside while-loop that executes the function until condition is unsatisfied.
	
	do 
		{
			
			printf("\n\n\n\n\n\n\n\n\n");
			Design_a();
			Design_c();
			printf("By Yeohan Lorenzo M. Norona of 119					\n");
			Design_a();
			printf("\n[A] Start Game\n");
			printf("\n[B] Settings \n");
			printf("\n[C] Tutorial \n");
			printf("\n[D] Credits \n");
			printf("\n[E] Exit Game \n");
					
			do //While loop if user enters invalid input other than A or a, B or b, C or c, D or d, E or e
				{	
					fflush(stdin);
					printf("\nType: ");
					scanf("%c", &main_options);
					printf("\n\n");
					printf("\n\n");
					switch (main_options)
					{
					 case 'a' : 
					 case 'A' : 
							    Game(guess, count, digit); 
							    main_options_quit = 1;
								break;
				
					 case 'b' : 
					 case 'B' : 
							    Configuration(&guess, &count, &digit); 
							    main_options_quit = 1;
								break;
				
					 case 'c' : 
					 case 'C' : 
					 			main_options_quit = 1;
					            Tutorial(); 
								break;
					 case 'd' :
					 case 'D' : 
								main_options_quit = 1;
								Credits();
								break;
				     case 'e' :
					 case 'E' : 
								main_options_quit = 1;
								main_options_quit_b = 1;
								break;
					
					 default : 
								fflush(stdin);
								printf("Invalid Input! Type again! \n");
								printf("\n\n");
					 			break;
					} 
				
				} while (main_options_quit != 1); 
		
		
		
		} while (main_options_quit_b != 1); //Final condition that will totally end the loop
		
	return 0;  
} 

void Game(int Guess_count, int Player_count, int Digit) // The very game
{
	int guess, player_score_right = 0, player_score_miss;                  
	int digit_checker;                                       // Count number of digits entered by user.
	int attempted_guesses = 1;
 	int Guess_holder = Guess_count;                          // Show guesses made in draw later

	                        				                 // initialized d for a for-loop .
						 									 // initialized result for digit position of guess number equal to respective random number.
											              	 // initialized guess  for input of guessed number.
											              	 
	int loop_ctr = 0;											 // A counter that will help in giving the remaining number of guesses left for each user.		              	 
	int guesses_ctr = 0;                                         // How many guesses were made.									              	 
	int extra_loop;									 		//loop for design							              	 
	int i = 219; 		         			                 // PURPOSE: For design. Number respective to its of an Ascii character.
	
	int SetNumber = 1;         				                 // Set Number is the Current Player.
	
	if (Guess_count < 1) 							         // In order to avoid error, if player set guess count in the settings to 0, it'll be back to default.
			Guess_count = 10;
		
	if (Player_count < 1)          							 // In order to avoid error, if player set player count in the settings to 0, it'll be back to default.
			Player_count = 2;
	
	if (Digit < 1)                 							 // In order to avoid error, if player set player count in the settings to 0, it'll be back to default.
			Digit = 4;
	
	
	int secret; 
	
	FourDigitGenerator(&secret, Digit);							 // Get the secret number.
	
	Design_a();                                 
	                       						
	printf("NUMBER OF PLAYERS: %d\n", Player_count);
	printf("NUMBER OF GUESSES: %d\n", Guess_holder);
	
		for (Guess_count = Guess_count * Player_count; Guess_count > 0; Guess_count--) 			// For loop of the remaining guesses 
			{
				loop_ctr++;
				guesses_ctr++;
						
				Design_a();   	       // Aesthetic purposes
				Design_b();            // Aesthetic purposes	
				
				if (SetNumber == 0)    // If last player ends his / her turn
						SetNumber++;
				
				int CTR = 1;           // A counter if user enters -1 for secret number, it will not interrupt the game
				
					if (Guess_count < 10)  //if statement just to adjust for design of text
						printf("\nENTRY %d\t\t\t\t\t\t%c            Number of Guesses left for PLAYER %d: %d \n" , Guess_count, i, SetNumber, Guess_holder); 
						
					else
						printf("\nENTRY %d\t\t\t\t\t%c            Number of Guesses left for PLAYER %d: %d \n" , Guess_count, i, SetNumber, Guess_holder);  
						
				printf("Player %d will now guess %d digits", SetNumber, Digit);
				
				printf("\t\t%c            \n", i);
				
				if (loop_ctr == Player_count)      //Check guess for each player
					{
						Guess_holder--;
						loop_ctr = 0;
					}

					do 
						{
							printf("Guess:  "); 									         
							if (scanf("%d", &guess) == 1)  // Check if user entered an integer or another data type
								{ 	
									fflush(stdin);							
									printf("\t\t\t\t\t\t%c            \n", i);
							
									CheckScore(Digit, &secret, &player_score_right, &player_score_miss, guess, &digit_checker ); //Function: For loop to check both correct digits and matching digits
							
									if (guess == -1)       // Reveal secret number w/o interruption
										{
											fflush(stdin);
											printf("Secret number is %d \t\t\t\t%c\n", secret, i);
										}
								
									else if (guess == -2)  // End game
										{
											Guess_count = 0;
											CTR = 0;
										}
				
									else if (digit_checker != Digit)    // User's guess digits not equal to required digits needed
										{
											fflush(stdin);
											printf("Invalid Input! You did %d digits \t\t%c  \nNumber of Digits Required:  %d\t\t\t%c  \n\n",digit_checker, i, Digit, i);
										}
			
									else 
										CTR = 0;                        // If user did not enter -1, -2, or any lacking digits
								}
							else 
								{
									printf("You did not type an integer. \t\t\t%c\n\n", i);
									fflush(stdin);
								}
						} while (CTR != 0);
							
					fflush(stdin);
				
			 	if (guess == secret) //Win
					{	
							for (extra_loop = 10; extra_loop >= 0; extra_loop--)
							Design_a();
					
						printf("[ WIN SECTION ]\n");
						printf("\nSecret number is %d \n", secret);
						printf("\t\t\t\t\t\t%c    [Player %d has guessed it perfectly, and won the game!]\n ", i, SetNumber);
						printf("\t\t\t\t\t\t%c    [Player %d\'s score is %d!]\n ", i, SetNumber, player_score_right);
						printf("\nTotal guesses made for player %d: %d \n",	SetNumber, attempted_guesses);
						printf("\t\t\t\t\t\t%c          ", i);
						Guess_count = 0;	
					}	
	
				else if (guess != -2 && Guess_count != 1)                 // Score of tried entry
					{
						printf("\t\t\t\t\t\t%c         [Right Position, Right Digit is %d]\n ", i, player_score_right);
						printf("\t\t\t\t\t\t%c         [Wrong Position, Right Digit is %d]\n ", i, player_score_miss);
						printf("\t\t\t\t\t\t%c         [Player %d\'s score is %d! Next player!]\n ", i, SetNumber, player_score_right + player_score_miss);
						printf("\t\t\t\t\t\t%c          ", i);
					}
	
				else if ((guess != secret && Guess_count == 1) || guess == -2)               // Draw Screen
					{
			
					for (extra_loop = 10; extra_loop >= 0; extra_loop--)
							Design_a();
						
						printf("[ DRAW SECTION ]\n");
						printf("\nSecret number is %d \n", secret);
						printf("\nGame has ended with no more guesses! Going back to Main Menu! \n");
					}
					
					
			if (guesses_ctr == Player_count) //To check the number of rounds after the last player has ended his or turn. Will be served as attempted guess for each player.
					{
						guesses_ctr = 0;
						attempted_guesses++;
					}		
			if (Guess_count != 0)
				{
					SetNumber = (SetNumber + 1) % (Player_count + 1); 	// To alter players
					Design_a();		
				}
			} 
	 		
			char EndGameOption;
			int EndGameOptionQuit = 0;
			
			
			
			
			printf("\n[A] Return to Main Menu. \n");
			fflush(stdin);
				do 
					{
						printf("Type: ");
						scanf("%c", &EndGameOption);
						switch (EndGameOption)
						
							{
								case 'a':
								case 'A':
											EndGameOptionQuit++;
											fflush(stdin);
											break;
								
								default: 
											fflush(stdin);
											printf("\n\nInvalid Input! \n");
							}
							
					} while (EndGameOptionQuit != 1 );
		
}

void Design_a() //Fixed Ceiling / Floor design
{
	int i = 223;
	int d;
	printf("\n");
	for (d = 118; d > 0; d--)
		printf("%c", i);

	printf("\n");
}


void Design_b() //Fixed Column design
{
	int i = 219;
	int d;
	
	for (d = 6; d > 0; d--)
	{
		printf("\n");
		printf("\t\t\t\t\t\t");
		printf("%c", i);
	}
}


void Tutorial() //If user is not familiar with the game
{
	printf("TUTORIAL OF NUMERICAL MASTERMIND");
	Design_a();
	int i = 219;
	char tutorial_option;
	int tutorial_option_quit = 0;
	printf("The players take turn in guessing the secret code.\t\t\t\t\t\t\t     %c\n", i);
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t     %c\n", i);
	printf("Each guess is in the form of one four-digit integer.\t\t\t\t\t\t\t     %c\n", i); 
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t     %c\n", i);
	printf("The guess entries of each player is displayed in the guess column of the game screen. \t\t\t     %c\n", i);
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t     %c\n", i);
	printf("After the player enters his guess, the computer gives a score to this entry. \t\t\t\t     %c\n", i); 
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t     %c\n", i);
	printf("The player\'s score is added with a point if its number is an element of the secret four-digit number \t     %c\n", i);
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t     %c\n", i);
	printf("Meaning, having a score of 4 does not guarantee a win yet. \t\t\t\t\t\t     %c\n", i);
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t     %c\n", i);
	printf("It means you have all the correct numbers, you just got to position them correctly \t\t\t     %c\n", i);
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t     %c\n", i);
	printf("Do not press any other character than the given set of letters in respect to each option \t\t     %c \n", i);
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t     %c\n", i);
	printf("To Reveal Secret Number During Game, type \"-1\".  \t\t\t\t\t\t\t     %c\n", i);
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t     %c\n", i);
	printf("To End Game type \"-2\".  \t\t\t\t\t\t\t\t\t             %c  \n", i);
	printf(" \t\t\t\t\t\t\t\t\t\t\t\t             %c", i);
	Design_a();
	printf("\n[A] - Return to Main Menu \n");
	
do //While loop if user enters invalid input other than A or a.
	{	
		fflush(stdin);
		printf("\nType: ");
		scanf("%c", &tutorial_option);
		switch (tutorial_option)
			{
				case 'a':
				case 'A': 
						tutorial_option_quit = 1;
						break;
				default:
						printf("Invalid Input! \n");
						
			}
	} while (tutorial_option_quit != 1);
}


void Configuration(int *g, int *p, int *q) //Settings if user wants to change number of guesses or number of players.
{
	Design_a();
	int g_a, p_a, q_a;
	g_a = *g; //g_a is to provide the value for guess, so that the user can see what the current values are, even when changed.
	p_a = *p; //p_a is to provide the value for players, ... ^
	q_a = *q; //q_a is to provide the value for digits,  ... ^
		
	
	char game_config_option;
	int game_config_system_quit = 0;
	int game_config_system_quit_b = 0;
	do 
		{	
			fflush(stdin);
			printf("\n[A] Change Number of Players: %d \n", p_a);
			printf("\n[B] Change Number of Guesses: %d \n", g_a);
			printf("\n[C] Change Number of Digits: %d \n",  q_a);
			printf("\n[D] Return to Main Menu\n");
			Design_a();
			do 
				{
					
				printf("\nType: ");
				scanf("%c", &game_config_option);
				switch (game_config_option)
					{
				      case 'a' : 
				      case 'A' :   
								fflush(stdin);
								printf("Number of Players: ");
								scanf("%d", &p_a);
								*p = p_a;
								game_config_system_quit = 1;
								break;
					  case 'b' : 
				      case 'B' :
								fflush(stdin);
								printf("Number of Guesses: ");
								scanf("%d", &g_a);
								*g = g_a;
								game_config_system_quit = 1;
								break;		
			          case 'c' : 
				      case 'C' :
								fflush(stdin);
								printf("Number of Digits: ");
								scanf("%d", &q_a);
								*q = q_a;
								game_config_system_quit = 1;
							 	 break;
					  case 'd' : 
				      case 'D' :
								 fflush(stdin);
								 game_config_system_quit = 1;
								 game_config_system_quit_b = 1;
							 	 break;
					   default : 
								 fflush(stdin);
								 printf("Invalid Input! \n");
					} 
				} while (game_config_system_quit != 1);
		game_config_system_quit = 0;
		
	} while (game_config_system_quit_b != 1);
}


void CheckScore (int nVal, int *w, int *player_score_right, int *player_score_miss, int guess, int *gdigit)  // Check Score            
{	
	// nVal is Number Of Digits of the secret
	// *w is secret
	// player_score is the score 
	// guess is the player's guess
	// *gdigit is the number of digits of the guess

	if (guess == -1 || guess == -2) 
		return;
	
		int count_guess_digit = guess, g_digit_ctr = 0;
	
		while (count_guess_digit != 0)
			{
				g_digit_ctr++;
				count_guess_digit /= 10;
			}
			
	if (g_digit_ctr < nVal)
		{
			*gdigit = g_digit_ctr;
			return;
		}
	
	*gdigit = g_digit_ctr;
	
	
	// Above here is to check if user inputted unnecessary answer from the previous function
	// Below is the true checking of score
	
	
  int player_miss = 0, player_right = 0;	   
  int in_s = *w, in_g = guess;
  int m = 1, n = 1;
  int sum_s, sum_g, new_s = 0, new_g = 0;
  int ctr = 0, ctr_2 = 0;
  int i;
  int new_sum_g = 0;
  int new_g_new = 0;
  int y = 0;
  int lock_ctr = 0;
	
			for (i = 1; i <= nVal;  i++)                  // 1. This For-Loop Will First Check Matching Positions
				{
					if (in_s%10 == in_g%10) 
						{	
							in_s /= 10; 	
							in_g /= 10;
							player_right++;
						}
					else                                  // 2. In this Else section, it'll serve as a container 
						{                                 // for digits that did not match correct positions 
							ctr++;                        // and both new_s & new_g will be the remaining digits 
							sum_s = in_s % 10;            // of secret and guess respectively.
							sum_g = in_g % 10;            
							in_s /= 10;
							in_g /= 10;
							new_s = new_s + sum_s * n; 
							new_g = new_g + sum_g * n;
							n*= 10;			
						}
				}
				                                        // 2.1. At the end of the for-loop, the data contained in the previous Else 
				                                        // will be used here below.
				
				
			while (new_s > 0) 							  // 3. This While-Loop Will Check Correct Digits, Wrong Positions
				{	
													      // SIDE NOTE: This first If-loop of the While-Loop is usually activated last.
													      
					if (ctr_2 == 1 && lock_ctr == 1)      // 4. This If section will only be activated if new_g (latest digit) 
						{                                 // has not matched any new_s (left over secret digits)
							lock_ctr--;											
							new_g = new_g_new;			  // 5. The new_g (latest guess digit) will get the new_g_new (other guess digits)
							new_g_new = 0;                // The new_g_new is basically the other guess digits who are still unmatched
							m = 1;                        // even after trying to match every remaining new_s (left over secret digits)
							new_s /= 10;                  // 6. The new_s will move to its next digit after none of the new_g matches it
						}
					else
						{
							ctr_2 = 0;
							if (new_s%10 == new_g%10)     // 7. Basically, matching every guess digit for every secret digit
								{								
									player_miss++;
									new_s /= 10;  
									new_g /= 10;  
									y = new_g;            // 8. The ' y ' variable will serve as a counting digits 
									                      // from either If's new_g or Else's new_g
									new_g = new_g * m + new_g_new;   
									new_g_new = 0;           
									m = 1;    									
								}
							else
								{			   
									new_sum_g = new_g % 10;  // 8. New_Sum_G is getting the failed-to-match digit
									new_g_new = new_g_new + new_sum_g * m; // 9. New_G_New is a container of multiple digit
									y = new_g;               // Refer to 7. 
									new_g /= 10; 	
									m *= 10;             
										if (new_g == 0)      // 9. This will unlock number 4. if the last digit of new_g (guess)
											lock_ctr++;		 // has not matched any new_s (secret)
								}		
						
							while (y > 0)                    // 10. Counting Digits to help in unlock number 4.   
								{                            // if new_g is the last digit
									y /= 10;
									ctr_2++;
								}
							}
					}
		*player_score_right = player_right;          // Total misses and Total right.
		*player_score_miss = player_miss;         // Total misses and Total right.
		
	}
	

void FourDigitGenerator(int *w, int Digit) // Generator of Secret by number of digits
{
	int i, nGen, x = 1; 
	*w = 0;             //srand and time is utilized to prove that the random numbers will not be the same every time the program is executed.
	srand(time(0)); 
	for (i = 1; i <= Digit; i++)          //It will loop depending on the number of digits
		{ 
			nGen = rand() % 9 + 1;             
			nGen = nGen * x;                       
			x *= 10;                
			*w += nGen;                   //To add up the other digits
		}
}


void Credits() // Acknowledge maker
{
	// For validity and acknowledgement of creator of MP
	char tutorial_option;
	int tutorial_option_quit = 0;
	Design_a();
	printf("This MP was made by Yeohan ID 119\n\n");
	printf("First Made Machine Project. \n\nTotal Hours Worked for MP: 50 - 70 Hours\n\n");
	Design_a();
	
	printf("\n[A] - Return to Main Menu \n");
	
	do //While loop if user enters invalid input other than A or a.
		{	
			fflush(stdin);
			printf("Type: ");
			scanf("%c", &tutorial_option);
			switch (tutorial_option)
				{
					case 'a':
					case 'A': 
							printf("\n\n");
							tutorial_option_quit = 1;
							break;
					default:
							printf("Invalid Input! \n");
							printf("\n\n");
							
				}
		} while (tutorial_option_quit != 1);
}

void Design_c()  //Design for title
{
	printf("___        __ __        __ ____            ____ ___________  _________  ======== ========        /\\        ||\n");
			printf("||\\\\       || ||        || ||\\\\            //|| ||-------||  ||\\      |    | |   ||             /  \\       ||  \n");
			printf("|| \\\\      || ||        || || \\\\          // || ||-------||  || \\     |    | |   ||            /    \\      ||   \n");
			printf("||  \\\\     || ||        || ||  \\\\        //  || ||_______    ||  \\____|    | |   ||           /      \\     ||    \n");
			printf("||   \\\\    || ||	|| ||   \\\\      //   || ||_______||  ||   \\ 	   | |   ||          /========\\    ||  \n");
			printf("||    \\\\   || ||	|| ||    \\\\    //    || ||           ||    \\       | |   ||         /          \\   ||       \n");   
			printf("||     \\\\  || ||        || ||     \\\\  //     || ||-------||  ||     \\	   | |   ||	   /            \\  ||\n");
			printf("||      \\\\ || ||________|| ||      \\\\//      || ||-------||  ||      \\  ======== ======== /              \\ ||========		\n");
			printf("Mastermind. Mastermind. Mastermind. Mastermind. Mastermind. Mastermind. \n\n");
			
}
