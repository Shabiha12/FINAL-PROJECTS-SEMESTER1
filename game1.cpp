#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
//function prototype
char getCharAtxy(short int x, short int y);
void header();
void printMaze();
void printMaze2();
void enemy1();
void eraseEnemy1();
void enemy2();
void eraseEnemy2();
void moveEnemy1();
void Player();
void movePlayerleft();
void movePlayerright();
void moveEnemy2();
void moveEnemy3();
void eraseEnemy3();
void enemy3();
void gotoxy(int x, int y);
void moveEnemy(string direction);
string changeDirection(string direction);
void createBullet(int x, int y);
void moveBullet();
void movePlayerdown();
void movePlayerup();
bool isBulletCollision(int bulletX, int bulletY, int enemyX, int enemyY);
bool isBulletCollision(int bulletX, int bulletY, int enemyX, int enemyY, int& enemyHealth);
string changedirectionE1 ();
string changedirectionE2 ();
string changedirectionE3 ();
void gotoxy(int x,int y);
void selection();
void conditions();
void Level();
void game();
//global variables
int enemy1Health = 100;
int enemy2Health = 100;
int enemy3Health = 100;
int score = 0;
int level;
int eX = 2;
int eY = 2;
int x = 40;
int y = 3;
int pX = 2;
int pY = 29;
int a = 11;
int b = 10;
int bulletX;
int bulletY;
int playerX; 
int playerY;
int prevBulletX, prevBulletY;
int bulletspeed;
string directionE1 = "right";
string directionE2 = "down" ;
string directionE3 = "down";
//function to change the direction of enemy1
string changedirectionE1 ();
//main function
int main()
{
    system("cls");//clear the console screen
    header();// function of header
    Sleep(100);//pause for short duration
    system("cls");//clear the console screen
    printMaze();//function of maze
    enemy1();//function of enemy1
    enemy2();//function of enemy2
    enemy3();//function of enemy3

    Player();//player function
    while (true)
    {   //conditions
        if (GetAsyncKeyState(VK_LEFT))//for player move left side
    {
        movePlayerleft();
    }
    else if (GetAsyncKeyState(VK_RIGHT))//for player move right side
    {
        movePlayerright();
    }
    else if (GetAsyncKeyState(VK_DOWN))//for player move downward
    {
        movePlayerdown();
    }
    else if (GetAsyncKeyState(VK_UP))  // for player move upward
    {
        movePlayerup();
    }
        moveEnemy1();//move enemy1 function
        changedirectionE1();//changed direction of enemy1
        moveEnemy2();//function of moving of enemy2
        changedirectionE2();//changed direction of enemy2
        moveEnemy3();//function of moving of enemy3
        changedirectionE3();//changed direction of enemy3
        //conditions for bullet create and moving on up,down,right and left
        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {           
            createBullet(pX+1, pY);
        }

    if(GetAsyncKeyState(VK_LEFT))
    {
        createBullet(pX-1,pY);
    }
    if(GetAsyncKeyState(VK_RIGHT))
    {
        createBullet(pX+1,pY);
    }
    if(GetAsyncKeyState(VK_UP))
    {
        createBullet(pX,pY-1);
    }
    if(GetAsyncKeyState(VK_DOWN))
    {
        createBullet(pX,pY+1);
    }
    moveBullet();
//conditions for bulletcolloision for increases the score
if (isBulletCollision(bulletX, bulletY, eX, eY) ||
    isBulletCollision(bulletX, bulletY, x, y) ||
    isBulletCollision(bulletX, bulletY, a, b))
{
    score += 1;
    gotoxy(100,20);
    cout<<"Score" <<score;
}
//condition for enemy1health decreases by hit the bullet 
if (isBulletCollision(bulletX, bulletY, eX, eY, enemy1Health))
{
    if (enemy1Health > 0)  
    {
        enemy1Health -= 1;
        gotoxy(100, 21);
        cout << "ENEMY1:" << enemy1Health;

        if (enemy1Health == 0)
        {
            eraseEnemy1();
        }
        
        score += 1;
    }
}
//condition for enemy2health decreases by hit the bullet
if (isBulletCollision(bulletX, bulletY, x, y, enemy2Health))
{
    if (enemy2Health > 0)  
    {
        enemy2Health -= 1;
        gotoxy(100, 22);
        cout << "ENEMY2:" << enemy2Health;

        if (enemy2Health == 0)
        {
            eraseEnemy2();
        }
        
        score += 1;
    }
}
//conditions for enemy3health decreases by hit the bullet
if (isBulletCollision(bulletX, bulletY, a, b, enemy3Health))
{
    if (enemy3Health > 0)  
    {
        enemy3Health -= 1;
        gotoxy(100, 23);
        cout << "ENEMY3:" << enemy3Health;

        if (enemy3Health == 0)
        {
            eraseEnemy3();
        }
        
        score += 1;
    }
}

gotoxy(100, 20);
cout<<"SCORE:"<<score <<endl; 
    }
}
//function of create the bullet on console
void createBullet(int playerX, int playerY)
{
    // Update bullet position based on player movement
    bulletX = playerX + 4;
    bulletY = playerY - 1;

    // Clear previous bullet position
    gotoxy(prevBulletX, prevBulletY);
    cout << " ";
    // Draw the bullet at the new position
    gotoxy(bulletX, bulletY);
    cout << "^";

    prevBulletX = bulletX;
    prevBulletY = bulletY;
}

//function of movement of bullet by pressing 'w' key 
void moveBullet()
{
    if (_kbhit())
    {
        char key = _getch();

        gotoxy(prevBulletX, prevBulletY);
        cout << " ";

        switch (key)
        {
            case 'w':
                if (!isBulletCollision(bulletX, bulletY - 1, eX, eY) &&
                    !isBulletCollision(bulletX, bulletY - 1, x, y) &&
                    !isBulletCollision(bulletX, bulletY - 1, a, b))
                {
                    bulletY--;  // Move upward
                }
                break;

            // Add cases for other movement keys if needed

           // default:
                break;
        }

        gotoxy(bulletX, bulletY);
        cout << "^";

        prevBulletX = bulletX;
        prevBulletY = bulletY;
    }

    Sleep(100);//pause for short duration 
    if(enemy1Health==0 && enemy2Health==0 && enemy3Health==0)
    {
       exit(0);
    }
}
//printMaze function in which player and enemies move
void printMaze()
{
    system("Color 05");
    cout<<"##################################################################################################################"<<endl;
    cout<<"##################################################################################################################"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##                                                                                                              ##"<<endl;
    cout<<"##################################################################################################################"<<endl;
    cout<<"##################################################################################################################"<<endl;   
}
//printMaze2 function for second level
void printMaze2()
{
    system("Color 05");//for colour
    cout<<"##################################################################################################################"<<endl;
    cout<<"##################################################################################################################"<<endl;
    cout<<"##                                                                                                               ##"<<endl;
    cout<<"##                                                                                                               ##"<<endl;
    cout<<"##                                                                                                               ##"<<endl;
    cout<<"##      ##                                                                                                       ##"<<endl;
    cout<<"##      ###################                                                                                      ##"<<endl;
    cout<<"##      ##                                                                           ##############################"<<endl;
    cout<<"##      ##                                                                                                       ##"<<endl;
    cout<<"##                                                                                                               ##"<<endl;
    cout<<"##                                                                                                               ##"<<endl;
    cout<<"##                                                                                                               ##"<<endl;
    cout<<"##                                                                            ##                                 ##"<<endl;
    cout<<"##                                                                            ##                                 ##"<<endl;
    cout<<"##                                                                            ##                                 ##"<<endl;
    cout<<"##                                                               ###############                                 ##"<<endl;
    cout<<"##                                                                            ##                                 ##"<<endl;
    cout<<"##                                                                            ##                                 ##"<<endl;
    cout<<"##                                                                            ##                                 ##"<<endl;
    cout<<"##  ##                                                                                                           ##"<<endl;
    cout<<"##  ##                                                                                                           ##"<<endl;
    cout<<"##  ##                                                                                                           ##"<<endl;
    cout<<"##  ##                                                                                                           ##"<<endl;
    cout<<"##  ##                                                                                                           ##"<<endl;
    cout<<"##  ##                                                                                                           ##"<<endl;
    cout<<"##  ##                                                                                                           ##"<<endl;
    cout<<"#######################################                                                                          ##"<<endl;
    cout<<"##                                                                                                               ##"<<endl;
    cout<<"##                                                                                         #                     ##"<<endl;
    cout<<"##                                                                                         #                     ##"<<endl;
    cout<<"##                                                                                         #                     ##"<<endl;
    cout<<"##                                                                                         #                     ##"<<endl;
    cout<<"##                                                                                         #                     ##"<<endl;
    cout<<"##                                                                                         #                     ##"<<endl;
    cout<<"##                                                                                         #                     ##"<<endl;
    cout<<"###################################################################################################################"<<endl;
    cout<<"###################################################################################################################"<<endl;

   
}
// Function to display Enemy 1 on the game screen
void enemy1()
{
        // Set the cursor position and display the visual representation of Enemy 1
    gotoxy(eX, eY);
    cout << "( __ )";
    gotoxy(eX, eY + 1);
    cout << "|o  o|";
    gotoxy(eX, eY + 2);
    cout << "||||||";
}
// Function to erase the enemy1
void eraseEnemy1()
{
    gotoxy(eX, eY);
    cout << "      ";
    gotoxy(eX, eY + 1);
    cout << "      ";
    gotoxy(eX, eY + 2);
    cout << "      ";
}
 // Check the current direction of Enemy 1 and update its position 
void moveEnemy1()
{
    
    if (directionE1=="right"){
    eraseEnemy1();// Erase the current position of Enemy 1
    eX=eX+1;
    enemy1();}
    else if (directionE1=="left")
    {
        eraseEnemy1();
    eX=eX-1; // Move Enemy 1 to the left
    enemy1(); // Redraw Enemy 1 in its new position
    }
}
// Function to display Enemy 2 on the game screen
void enemy2()
{
    // Set the cursor position and display the visual representation of Enemy 2
    gotoxy(x, y);
    cout << "( __ )";
    gotoxy(x, y + 1);
    cout << "|o  o|";
    gotoxy(x, y + 2);
    cout << "||||||";
}
// Function to erase the enemy1
void eraseEnemy2()
{
    gotoxy(x, y);
    cout << "       ";
    gotoxy(x, y + 1);
    cout << "       ";
    gotoxy(x, y + 2);
    cout << "       ";
}
// Function of the player
void Player()
{
   
    gotoxy(pX, pY);
    cout << "    /\\     " << endl;
    gotoxy(pX, pY + 1);
    cout << " __/~~\\__  " << endl;
    gotoxy(pX, pY + 2);
    cout << "/  |  |  \\ " << endl;
    gotoxy(pX, pY + 3);
    cout << " ===. .=== " << endl;
    gotoxy(pX, pY + 4);
    cout << "  ||||||   " << endl;
}
// Function to erase the player
void erasePlayer()
{
    gotoxy(pX, pY);
    cout << "           " << endl;
    gotoxy(pX, pY + 1);
    cout << "           " << endl;
    gotoxy(pX, pY + 2);
    cout << "           " << endl;
    gotoxy(pX, pY + 3);
    cout << "           " << endl;
    gotoxy(pX, pY + 4);
    cout << "           " << endl;
}
// Function to move the player character to the right
void movePlayerright()
{
    if (getCharAtxy(pX + 11, pY) != '#' && getCharAtxy(pX + 11, pY + 4) != '#')
    {
        erasePlayer();
        pX = pX + 1; // Move the player character to the right
        Player();
    }
}
// Function to move the player character to the left
void movePlayerleft()
{
    if (getCharAtxy(pX - 1, pY) != '#' && getCharAtxy(pX - 1, pY + 4) != '#')
    {
        erasePlayer();
        pX = pX - 1; // Move the player character to the left
        Player();
    }
}
// Function to move the player character to the up
void movePlayerup()
{
    if (getCharAtxy(pX, pY - 1) != '#' && getCharAtxy(pX + 10, pY - 1) != '#')
    {
        erasePlayer();
        pY = pY - 1; // Move the player character to the up
        Player();
    }
}
// Function to move the player character to the down
void movePlayerdown()
{
    if (getCharAtxy(pX, pY + 5) != '#' && getCharAtxy(pX + 10, pY + 5) != '#')
    {
        erasePlayer();
        pY = pY + 1; // Move the player character to the down
        Player();
    }
}
// Function to get the character at a specified console position (x, y)
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coorBufSize;
    coorBufSize.X = 1;
    coorBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coorBufSize, xy, &rect) ? ci.Char.AsciiChar
                                                                                           : ' ';
}
// Function to move Enemy 2 in the specified direction
void moveEnemy2()
{
    // Erase the current position of Enemy 2
    eraseEnemy2();

    if (directionE2 == "down")
    {
        y += 1;
      
    }
    else if (directionE2 == "up")
    {
        y -= 1;
      
    }
// Redraw Enemy 2 in its new position
    enemy2();
}
// Function to display Enemy 3 on the game screen
void enemy3()
{
    system("Color 04");
    gotoxy(a, b);
    cout << "( __ )";
    gotoxy(a, b + 1);
    cout << "|o  o|";
    gotoxy(a, b + 2);
    cout << "||||||";
}
// Function to erase the player
void eraseEnemy3()
{
    gotoxy(a, b);
    cout << "       ";
    gotoxy(a, b + 1);
    cout << "       ";
    gotoxy(a, b + 2);
    cout << "       ";
}
// Function to move Enemy 3 in the specified direction
void moveEnemy3()
{
      // Erase the current position of Enemy 3
    eraseEnemy3();

    if (directionE3 == "down")
    {
         // Move Enemy 3 vertically down
        a += 3;
         // Move Enemy 3 diagonally down
        b += 1;
       
    }
    else if (directionE3 == "up")
    {
         // Move Enemy 3 vertically up
        a -= 3;
         // Move Enemy 3 diagonally down
        b -= 1;
       
    }
    enemy3();
}
// Function to change the direction of Enemy 1 
string changedirectionE1 ()

{
    if (getCharAtxy(eX+6,eY)!=' ')        // If there is an obstacle, change the direction to "left"
    {
        directionE1 = "left";
    }
    else if (getCharAtxy(eX-1,eY)!=' ')
    {
        directionE1 = "right";        // If there is an obstacle, change the direction to "right"
    }
    return directionE1;
}
// Function to change the direction of Enemy 2
string changedirectionE2 ()


{
    if (getCharAtxy(x,y+3)!=' ')     // If there is an obstacle, change the direction to "up"
    {
        directionE2 = "up";
    }
    else if (getCharAtxy(x,y-1)!=' ')
    {
        directionE2 = "down";        // If there is an obstacle, change the direction to "down"
    }
    return directionE2;
}
// Function to change the direction of Enemy 3 
string changedirectionE3 ()

{
        // Check if there is an obstacle above or below Enemy 3
    if (getCharAtxy(a+6,b)!=' '||getCharAtxy(a,b+3)!=' ')
    {
        directionE3="up";  // If there is an obstacle, change the direction to "up"
    }
    else if (getCharAtxy(a-1,b)!=' '||getCharAtxy(a,b-1)!=' ')
    {
        directionE3 ="down";  // If there is an obstacle, change the direction to "down"
    }
    return directionE3; // Return the updated direction of Enemy 3
}
//header and instructions:
void header()
{
     system("Color 05");
cout<<"                                           .__                   __                                  "<<endl;
cout<<"            _________________    ____  ____     _____|  |__   ____   _____/  |_  ___________         "<<endl;
cout<<"            /  ___/\\___\\__ \\ _/ ___//__\\   /  ___/  | \\ /  _\\ /  _\\   _\\/ __\\_  __\\        "<<endl;
cout<<"            \\__\\ |  |_> > __ \\  \\\\  ___/   \\__\\|   Y  (  <_> |  <_> )  | \\ ___/|  |\\/       "<<endl;
cout<<"            /____  >|   __ ____  /\\__  >___  > /____  >___| /\\___/\\____/|__|  \\__  >__|          "<<endl;
cout<<"               \\/ |__|      \\/    \\/   \\/      \\/    \\/                      \\/               "<<endl;
cout<<endl<<endl;
cout<<"                                        INSTRUCTIONS:                                                "<<endl;
cout<<"                                      1.PLAYER(used keyboard keys):                                   "<<endl;
cout<<"                                          up,dowm,right,left                                         "<<endl;
cout<<"                                      2.Create Bullet:                                               "<<endl;
cout<<"                                          to press space bar                                         "<<endl;
cout<<"                                      3.Move bullet:                                                 "<<endl;
cout<<"                                          to press 'w'                                               "<<endl;
system("pause");
selection();

}
bool isBulletCollision(int bulletX, int bulletY, int enemyX, int enemyY)
{
    // Check for collisions with enemies
    if (bulletX >= enemyX && bulletX < enemyX + 6 && bulletY >= enemyY && bulletY < enemyY + 3)
    {
        // Handle enemy collision logic
        // ...
        return true;
    }

    // Check for collisions with maze walls or hurdles
    if (getCharAtxy(bulletX, bulletY) != ' ')
    {
        // Handle wall or hurdle collision logic (move bullet against it)
        return true;
    }

    return false;
}
// Function to check if a bullet has collided with an enemy
bool isBulletCollision(int bulletX, int bulletY, int enemyX, int enemyY, int& enemyHealth)
{
     // Check if the bullet's position overlaps with the enemy's position
    return (bulletX >= enemyX &&  bulletX < enemyX + 6 && bulletY >= enemyY && bulletY < enemyY + 3);
    
}
// Function to set the cursor position to the specified (x, y) coordinates on the console
void gotoxy(int x,int y)
{
COORD coordinates;
coordinates.X = x;
coordinates.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
} 
// Function to display level selection menu and read user input
void selection()
{
       
    cout<<"LEVEL1:"<<endl;
    cout<<"LEVEL2:"<<endl;
    cin>>level;
    conditions();
} 
// Function to check conditions based on the selected game level
void conditions(){
    if(level==1)
    {
        printMaze();
    }
    
    if(level==2)
    {
       Level();
    }
}
   void Level()
   {
    system("cls");//clear the screen
    printMaze2();//function of maze
    enemy1();//function of enemy1
    enemy2();//function of enemy2
    enemy3();//function of enemy3
//conditions for player
    Player();
    while (true)
    {
        if (GetAsyncKeyState(VK_LEFT))
    {
        movePlayerleft();
    }
    else if (GetAsyncKeyState(VK_RIGHT))
    {
        movePlayerright();
    }
    else if (GetAsyncKeyState(VK_DOWN))
    {
        movePlayerdown();
    }
    else if (GetAsyncKeyState(VK_UP))  // Check VK_UP here
    {
        movePlayerup();
    }
        moveEnemy1();
        changedirectionE1();
        moveEnemy2();
        changedirectionE2();
        moveEnemy3();
        changedirectionE3();
        //conditions of create bullet function for moving
        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {           
            createBullet(pX+1, pY);
        }

    if(GetAsyncKeyState(VK_LEFT))
    {
        createBullet(pX-1,pY);
    }
    if(GetAsyncKeyState(VK_RIGHT))
    {
        createBullet(pX+1,pY);
    }
    if(GetAsyncKeyState(VK_UP))
    {
        createBullet(pX,pY-1);
    }
    if(GetAsyncKeyState(VK_DOWN))
    {
        createBullet(pX,pY+1);
    }
    moveBullet();
//conditions of bulletcolloision to increase score
if (isBulletCollision(bulletX, bulletY, eX, eY) ||
    isBulletCollision(bulletX, bulletY, x, y) ||
    isBulletCollision(bulletX, bulletY, a, b))
{
    score += 4;
    gotoxy(100,20);
    cout<<"Score" <<score;
}
//condition for decrease the health of enemy1
if (isBulletCollision(bulletX, bulletY, eX, eY, enemy1Health))
{
    if (enemy1Health > 0)  
    {
        enemy1Health -= 1;
        gotoxy(100, 21);
        cout << "ENEMY1:" << enemy1Health;

        if (enemy1Health == 0)
        {
            eraseEnemy1();
        }
        
        score += 1;
    }
}
//condition for decrease the health of enemy2
if (isBulletCollision(bulletX, bulletY, x, y, enemy2Health))
{
    if (enemy2Health > 0)  
    {
        enemy2Health -= 1;
        gotoxy(100, 22);
        cout << "ENEMY2:" << enemy2Health;

        if (enemy2Health == 0)
        {
            eraseEnemy2();
        }
        
        score += 1;
    }
}
//condition for decrease the health of enemy3
if (isBulletCollision(bulletX, bulletY, a, b, enemy3Health))
{
    if (enemy3Health > 0)  
    {
        enemy3Health -= 1;
        gotoxy(100, 23);
        cout << "ENEMY3:" << enemy3Health;

        if (enemy3Health == 0)
        {
            eraseEnemy3();
        }
        
        score += 1;
    }
}


gotoxy(100, 20);
cout<<"SCORE:"<<score <<endl; 
    }

createBullet(playerX,playerY);//create bullet function
moveBullet();//function of movingbullet
   }
   

   
   