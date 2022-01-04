            #include <stdio.h>
            #include <stdbool.h>
            #include <string.h>
            #include <ctype.h>
            #define MAX_GAME 50
            int select;
            int menu()
            {
                printf("\n");
                printf("\n\t\t\t\t MENU\n\t\t\t\t ______________________________________________");
                printf("\n\t\t\t\t| [1] PUBULATE VIDEO GAME                      |");
                printf("\n\t\t\t\t| _____________________________________________|");
                printf("\n\t\t\t\t| [2] EDIT INVENTORY                           |");
                printf("\n\t\t\t\t| _____________________________________________|");
                printf("\n\t\t\t\t| [3] SERACH INVENTORY                         |");
                printf("\n\t\t\t\t| _____________________________________________|");
                printf("\n\t\t\t\t| [4] DISPLAY INVENTORY                        |");
                printf("\n\t\t\t\t| _____________________________________________|");
                printf("\n\t\t\t\t| [5] EXIT FROM SYSTEM                         |\n\t\t\t\t________________________________________________\n\t\t\t\t\t\t\t\t");
            printf("\n\t\t\t\tPLEASE CHOOSE YOUR ACTION FROM ABOVE:\n\n");
            scanf("%d",&select);
            return select;
            }

            struct Game {
              int SKU_number;
              char game_name[50];
              int Digital;
              char Selling_Price[10];
              char Modes[50];
              char Platform[50];
              int Metacritic_Rating;
              char ESRB_Rating[50];
              char Type[50];
              char Studio[50];
            } inventory[MAX_GAME];

            int k = 1;   /* number of parts currently stored */
            int search_game(int num, int rate);
            int search_name(char gamename[50]);
            int find_game(int number);
            void Add(void);
            void search(void);
            void update(void);
            void print(void);

            /************  MAIN Function ***************/

            int main(void)
            {
              int E;

              for (;;) {
                menu();
                while (getchar() != '\n');
                switch (select) {
                  case 1: add();
                            break;
                  case 3: search();
                            break;
                  case 2: edit();
                            break;
                  case 4: display();
                            break;
                  case 5 : return 0;
                  default: printf("Hey! You are entering wrong input!!\n");
                }
                printf("\n");
              }
            }

            /****** find Game Function******************/

            int find_game(int sk_num)
            {
              int i;

              for (i = 0; i <= k; i++)
                if (inventory[i].SKU_number == sk_num){
                  return i;
                }
              return -1;
            }

            int search_game(int num, int rate)
            {
              int i;

              for (i = 0; i <= k; i++)
                if (inventory[i].SKU_number == num && inventory[i].Metacritic_Rating == rate){
                  return i;
                }
              return -1;
            }

            int search_name(char gamename[50])
             {
              int i;
              for (i = 0; i <= k; i++)
                if (strcmp(inventory[i].game_name,gamename)){
                  return i;
                }
              return -1;
             }

            /************************ Insert **********************************/

            void add(void)
            {
              int game_number,E,ac,es,mr,pl;
              char game_name;
              if (k == MAX_GAME) {
                printf("Database is full; can't add more parts.\n");
                return;
              }
              printf("Enter Game number: ");
              scanf("%d", &game_number);
              if (find_game(game_number) >= 0) {
                printf("Part already exists.\n");
                return;
              }
              inventory[k].SKU_number = game_number;
              printf("Enter game name:");
              scanf("%s",&inventory[k].game_name);

                       /***********************/

                printf("\n");
                printf("\n\t\t\t\t         Movie Types\n\t_______________________________________________________________________________________________");
                printf("\n\t|[1]idle    [2]role-playing    [3]simulation    [4]sports   [5]strategy    [6]other  [7]action|");
                printf("\n\t|_____________________________________________________________________________________________|\n\n");

             for (;;) {
               while (getchar() != '\n');
               printf("Please chose one the above type of the movie:");
               scanf("%d",&ac);
               switch (ac) {
                  case 1: strcpy(inventory[k].Type, "idle");
                            break;
                  case 2: strcpy(inventory[k].Type, "role-playing");
                            break;
                  case 3: strcpy(inventory[k].Type, "simulation");
                            break;
                  case 4: strcpy(inventory[k].Type,"sports");
                            break;
                  case 5: strcpy(inventory[k].Type,"strategy");
                            break;
                  case 6: strcpy(inventory[k].Type, "other");
                            break;
                  case 7: strcpy(inventory[k].Type, "action");
                            break;
                  default: printf("Hey! No such an Action!!\n");
                }
                if (ac>=1 && ac<=7) break;
             }

             /***********************/

             printf("\n");
                printf("\n\t\t\t\t    ESRB Rating \n\t___________________________________________________");
                printf("\n\t|[1]E    [2]E10+    [3]T    [4]M   [5]A    [6]RP  |");
                printf("\n\t|_________________________________________________|\n\n");

             for (;;) {
               while (getchar() != '\n');
               printf("Please chose one the above ESRB Rating of the movie:");
               scanf("%d",&es);
               switch (es) {
                  case 1: strcpy(inventory[k].ESRB_Rating, "E");
                            break;
                  case 2: strcpy(inventory[k].ESRB_Rating, "E10+");
                            break;
                  case 3: strcpy(inventory[k].ESRB_Rating, "T");
                            break;
                  case 4: strcpy(inventory[k].ESRB_Rating, "M");
                            break;
                  case 5: strcpy(inventory[k].ESRB_Rating,  "A");
                            break;
                  case 6: strcpy(inventory[k].ESRB_Rating,  "RP");
                            break;

                  default: printf("Hey! No such an Action!!\n");
                }
                if (es>=1 && es<=6) break;
            }

             /***********************/
                printf("\n");
                printf("\n\t\t Metacritic Rating must be out of 100  \n\t___________________________________________________\n\n");
                for(;;){
                    while (getchar() != '\n');
                    printf("Enter Game Metacritic Rating: ");
                    scanf("%d", &mr);
                    if (mr>=1 && mr<=100){
                     inventory[k].Metacritic_Rating=mr;
                     break;
                    } else printf("Wrong Input!! Try again!\n");
                }

             /***********************/
               printf("\n");
                printf("\n\t\t\t\t         Movie Platform\n\t____________________________________________________________________________________________________");
                printf("\n\t|[1]PS [2]Xbox [3]Nintendo  [4]Switch [5]PC  [6]Mobile  [7]Streaming-Google [8]Streaming-Amazon Luna|");
                printf("\n\t|___________________________________________________________________________________________________|\n\n");

             for (;;) {
               while (getchar() != '\n');
               printf("Please chose one the above platform of the movie:");
               scanf("%d",&pl);
               switch (pl) {
                  case 1: strcpy(inventory[k].Platform, "PS");
                            break;
                  case 2: strcpy(inventory[k].Platform, "Xbox");
                            break;
                  case 3: strcpy(inventory[k].Platform, "Nintendo");
                            break;
                  case 4: strcpy(inventory[k].Platform, "Switch");
                            break;
                  case 5: strcpy(inventory[k].Platform, "PC");
                            break;
                  case 6: strcpy(inventory[k].Platform, "Mobile");
                            break;
                  case 7: strcpy(inventory[k].Platform, "Streaming-Google");
                            break;
                  case 8: strcpy(inventory[k].Platform, "Streaming-Amazon Luna");
                            break;

                  default: printf("Hey! No such a Platform!!\n");
                }
                if (pl>=1 && pl<=8) break;
             }

    /***********************/
                int md;
                char mt1[50];

                printf("\n");
                printf("\n\t\t\t\t       Movie Modes Player Type\n\t____________________________________________________________________________________________________");
                printf("\n\t|[1]single   [2]coop   [3]competitive    [4]All |");
                printf("\n\t|___________________________________________________________________________________________________|\n\n");

             for (;;) {
               while (getchar() != '\n');
               printf("Please chose one the above Modes Playing Type of the movie:");
               scanf("%d",&md);
               switch (md) {
                  case 1: strcpy(mt1,"single,");
                            break;
                  case 2: strcpy(mt1,"coop,");
                            break;
                  case 3: strcpy(mt1,"competitive,");
                            break;
                  case 4: strcpy(mt1,"single,coop,competitive,");
                            break;
                  default: printf("Hey! No such a Modes Player Type!!\n");
                }
                if (md>=1 && md<=4) break;
             }
                                     /**********************/
                int md2;
                char mt2[50];

                printf("\n");
                printf("\n\t\t\t\t       Movie Modes Player Platform\n\t____________________________________________________________________________________________________");
                printf("\n\t|[1]local   [2]cloud    [3]All |");
                printf("\n\t|___________________________________________________________________________________________________|\n\n");

             for (;;) {
               while (getchar() != '\n');
               printf("Please chose one the above Modes Playing Type of the movie:");
               scanf("%d",&md2);
               switch (md2) {
                  case 1: strcpy(mt2, "local");
                            break;
                  case 2: strcpy(mt2,  "cloud");
                            break;
                  case 3: strcpy(mt2, "local,cloud");
                            break;
                  default: printf("Hey! No such a Modes Player Type!!\n");
                }
                if (md2>=1 && md2<=3) break;
             }
              strcpy(inventory[k].Modes, strcat(mt1,mt2));

    /***********************/
                char se[10];
                char s1[10];
                int check;
                printf("\n");
                printf("\n\t\t What is the selling Price? digit 0 means free! \n\t___________________________________________________\n\n");
                for(;;){
                    while (getchar() != '\n');
                    printf("Enter Game selling price: ");
                    scanf("%s", &se);
                    check=isdigit(se[0]);
                    if (check){
                        strcpy(inventory[k].Selling_Price,se);
                       break;
                          } else printf("Wrong Input!! Try again!\n");
                       }


    /***********************/

                int dg;
                printf("\n");
                printf("\n\t\t  Movie digitalization ([1] Downloadable  [2]disc based  \n\t___________________________________________________\n\n");
                for(;;){
                    while (getchar() != '\n');
                    printf("Enter Game Digital format: ");
                    scanf("%d", &dg);
                    if (dg>=1 && dg<=2){
                     inventory[k].Digital=dg;
                     printf("%d, ", inventory[k].Digital);
                     break;
                    } else printf("Wrong Input!! Try again!\n");
                }
              k++;
            }

    /************************** search ********************************/

            void search(void)
            {

               int op;
               int i, sku_num,rate;
               char gname[50];
               char cad[5]="$";

                printf("\n");
                printf("\n\t\t\t\t       Search by which Criteria options\n\t____________________________________________________________________________________________________");
                printf("\n\t|[1]By Game Id  [2]by Game name    [3]by game Id & Metacritic_Rating |");
                printf("\n\t|___________________________________________________________________________________________________|\n\n");

             for (;;) {
               printf("Please chose one the above search type of the options:");
               scanf("%d",&op);
               switch (op) {
                  case 1:

                      {
                          printf("Enter Game ID: ");
                          scanf("%d", &sku_num);
                          i = find_game(sku_num);
                          char cad[5]="$";
                            if (i > 0) {
                                printf("Game name: %s\n", inventory[i].game_name);
                                printf("Game ID: %d\n", inventory[i].SKU_number);
                                printf("Game Platform: %s\n", inventory[i].Platform);
                                printf("Game Modes: %s\n", inventory[i].Modes);
                                printf("Game Selling price: %s\n", strcat(cad,inventory[i].Selling_Price));
                                printf("Game Type: %s\n", inventory[i].Type);

                              } else
                                printf("Game not found!\n");
                             }

                            break;
                 case 2:
                             {
                          printf("Enter Game name: ");
                          scanf("%d", &gname);
                          i = search_name(gname);
                            if (i > 0) {
                                printf("Game name: %s\n", inventory[i].game_name);
                                printf("Game ID: %d\n", inventory[i].SKU_number);
                                printf("Game Platform: %s\n", inventory[i].Platform);
                                printf("Game Modes: %s\n", inventory[i].Modes);
                                printf("Game Selling price: %s\n", strcat(cad,inventory[i].Selling_Price));
                                printf("Game Type: %s\n", inventory[i].Type);
                              } else
                                printf("Game not found!\n");
                             }
                            break;
                  case 3: {
                          printf("Enter Game number: ");
                          scanf("%d", &sku_num);
                          printf("Enter  Metacritic_Rating number: ");
                          scanf("%d", &rate);
                          i = search_game(sku_num,rate);
                            if (i > 0) {
                                printf("Game ID: %d\n", inventory[i].SKU_number);
                                printf("Game name: %s\n", inventory[i].game_name);
                                printf("Game Platform: %s\n", inventory[i].Platform);
                                printf("Game Modes: %s\n", inventory[i].Modes);
                                printf("Game Selling price: %s\n", strcat(cad,inventory[i].Selling_Price));
                                printf("Game Type: %s\n", inventory[i].Type);
                              } else
                                printf("Game not found!\n");
                          }
                            break;
                  default: printf("Hey! No such a Modes Player Type!!\n");
                }
                if (op>=1 && op<=3) break;
             }

            }

/***************** edit: Prompts the user to enter a part number *********/

            void edit(void)
            {
                int Ed;

                printf("\n");
                printf("\n\t\t\t\t         Edit Fields\n\t________________________________________________");
                printf("\n\t|[1]ID  [2]Name  [3]Selling price  [4]Main Menu|");
                printf("\n\t|______________________________________________|\n\n");

             for (;;) {

               int Game_ID, SKU_search, modify_int;
               char modify_char[20];
               printf("Please chose one the above field of the movie to edit:");
               scanf("%d",&Ed);
               switch (Ed) {
                  case 1:
                           {
                              printf("Enter Game SKU_number you want to modify: ");
                              scanf("%d", &SKU_search);
                              Game_ID = find_game(SKU_search);
                              if (Game_ID >= 0) {
                                printf("Enter the SKU_number to modify in game : ");
                                scanf("%d", &modify_int);
                                inventory[Game_ID].SKU_number=modify_int;
                              } else
                                printf("Game not found!!\n");
                           }
                            break;
                  case 2:
                      {
                            printf("Enter Game SKU_number you want to modify: ");
                            scanf("%d", &SKU_search);
                            Game_ID = find_game(SKU_search);
                            if (Game_ID >= 0) {
                                printf("Enter the SKU_number to modify in game: ");
                                scanf("%s", &inventory[Game_ID].game_name);
                            } else
                                printf("Game not found!!\n");
                       }
                            break;
                  case 3:
                           {
                              char sel[20];
                              printf("Enter Game SKU_number you want to modify: ");
                              scanf("%d", &SKU_search);
                              Game_ID = find_game(SKU_search);
                              if (Game_ID >= 0) {
                                printf("Enter the Selling Price to modify in game: ");
                                scanf("%s", &inventory[Game_ID].Selling_Price);
                            } else
                                printf("Game not found!!\n");
                          }
                            break;
                  case 4: return 0;

                  default: printf("Hey! No such an Action!!\n");
                }
                if (Ed>=1 && Ed<=4) break;
             }

            }

/*********Display: show list of teh all movie games*******************************/

            void display(void)
            {
              int i;
              char dig[20];
              char cad[10]="$";
              printf("Sku_number         Game Name           Type          Digital          selling price          ESRB_Rating          Platform     Metacritic_Rating     Modes   "
                     "\n");
              for (i = 0; i < k; i++)
              {
               if (inventory[i].Digital==1) strcpy(dig, "Downloadable");
                   else strcpy(dig, "disc based ");

                printf("%10d   %17s %15s %15s  %17s %23s %15s  %15d  %25s \n", inventory[i].SKU_number,
                      inventory[i].game_name, inventory[i].Type ,dig,strcat(inventory[i].Selling_Price, cad),
                      inventory[i].ESRB_Rating,inventory[i].Platform,
                      inventory[i].Metacritic_Rating,inventory[i].Modes);
              }
           }


           /*********************    THANK YOU MICHELLE  PLEASE HELP ME TO ENTER TO CONCORDIA UNIVERSITY  ******************************


