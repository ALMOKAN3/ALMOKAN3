#include <iostream>
using namespace std;

const int size = 9;
char array1[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int array2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int x1, o1;
void print();
void printXO();
void returnvaluesarray1();

int main() {

    int Exit;
    cout << "Write 1 to play \n";
    cout << "Write -1 to end play \n";
    cin >> Exit;

    while(Exit != -1)
    {
      if(Exit == 1)
      {
        returnvaluesarray1();
        printXO();
        print();
        cout << "The play end \n";
        cout << "Write 1 to play \n";
        cout << "Write -1 to end play \n";
        cin >> Exit;
        if (Exit == 1)
          continue;
        else if (Exit == -1)
          break;
        else
        {
        cout << "Write a number again \n";
        cin >> Exit;
        continue;
      }
      }
      else
      {
        cout << "Write a number again \n";
        cin >> Exit;
        continue;
      }
    }
  cout << "The play end \n";

  return 0;
}

void print()
{

  for (int i = 0; i < 9; i++){
    cout << "\t " << array1[i];
    if (array2[i] == 3 || array2[i] == 6 || array2[i] == 9){
      cout << " ";
    }
    else{
      cout << "\t | ";
    }
    if (i == 2 || i == 5){
      cout << "\n -------------------------------------------------- \n";
    }
  }
  cout << endl;

}

void returnvaluesarray1()
{

  array1[0] = {'1'};
  array1[1] = {'2'};
  array1[2] = {'3'};
  array1[3] = {'4'};
  array1[4] = {'5'};
  array1[5] = {'6'};
  array1[6] = {'7'};
  array1[7] = {'8'};
  array1[8] = {'9'};

}

void swap(char, int);
void CheckselectionX(char x2);
void CheckselectionO(char o2);
bool checkup(int);
bool winnercheck();

void printXO()
{

  int i = 0;
  char x = 'X', o = 'O';
  for ( ; i < 9; i++)
  {
    print();
    if (winnercheck() == false)
    {
      if (i % 2 == 0)
      {
        cout << "It is role 'X' select a number \n";
        cin >> x1;
        if (x1 != 0)
        {
          while (checkup(x1))
          {
            cout << "The place is full. Rewrite \n";
            cin >> x1;
            continue;
          }
          CheckselectionX(x);
        }
        else
        {
          returnvaluesarray1();
          i = -1;
          continue;
        }
      }
      else
      {
        cout << "It is role 'O' select a number \n";
        cin >> o1;
        if (o1 != 0)
        {
          while (checkup(o1))
          {
            cout << "The place is full. Rewrite \n";
            cin >> o1;
            continue;
          }
          CheckselectionO(o);
        }
        else
        {
          returnvaluesarray1();
          i = -1;
          continue;
        }
      }
      if (winnercheck() == true)
      {
        break;
      }
    }
  }

}

void swap(char a, int b)
{

  for (int i = 0; i <= 8; i++)
  {
    if (array2[i] == b)
       array1[i] = a;
    else
    continue;
  }

}

bool checkup(int xo)
{

  
  for (int i = 0; i < 9; i++){
      if (array1[xo - 1] == 'X' || array1[xo - 1] == 'O')
        return true;
  }
  if (xo < 1 || xo > 9)
    return true;

  return false;

}

bool winnercheck()
{

  while(true)
  {
    if (array1[0] == 'X' && array1[1] == 'X' && array1[2] == 'X')
    {
      cout << "'X' is winner \n";
      return true;
    }
    if (array1[3] == 'X' && array1[4] == 'X' && array1[5] == 'X')
    {
      cout << "'X' is winner \n";
      return true;
    }
    if (array1[6] == 'X' && array1[7] == 'X' && array1[8] == 'X')
    {
      cout << "'X' is winner \n";
      return true;
    }
    if (array1[0] == 'X' && array1[3] == 'X' && array1[6] == 'X')
    {
      cout << "'X' is winner \n";
      return true;
    }
    if (array1[1] == 'X' && array1[4] == 'X' && array1[7] == 'X')
    {
      cout << "'X' is winner \n";
      return true;
    }
    if (array1[2] == 'X' && array1[5] == 'X' && array1[8] == 'X')
    {
      cout << "'X' is winner \n";
      return true;
    }
    if (array1[0] == 'X' && array1[4] == 'X' && array1[8] == 'X')
    {
      cout << "'X' is winner \n";
      return true;
    }
    if (array1[2] == 'X' && array1[4] == 'X' && array1[6] == 'X')
    {
      cout << "'X' is winner \n";
      return true;
    }
    if (array1[0] == 'O' && array1[1] == 'O' && array1[2] == 'O')
    {
      cout << "'O' is winner \n";
      return true;
    }
    if (array1[3] == 'O' && array1[4] == 'O' && array1[5] == 'O')
    {
      cout << "'O' is winner \n";
      return true;
    }
    if (array1[6] == 'O' && array1[7] == 'O' && array1[8] == 'O')
    {
      cout << "'O' is winner \n";
      return true;
    }
    if (array1[0] == 'O' && array1[3] == 'O' && array1[6] == 'O')
    {
      cout << "'O' is winner \n";
      return true;
    }
    if (array1[1] == 'O' && array1[4] == 'O' && array1[7] == 'O')
    {
      cout << "'O' is winner \n";
      return true;
    }
    if (array1[2] == 'O' && array1[5] == 'O' && array1[8] == 'O')
    {
      cout << "'O' is winner \n";
      return true;
    }
    if (array1[0] == 'O' && array1[4] == 'O' && array1[8] == 'O')
    {
      cout << "'O' is winner \n";
      return true;
    }
    if (array1[2] == 'O' && array1[4] == 'O' && array1[6] == 'O')
    {
      cout << "'O' is winner \n";
      return true;
    }
    return false;
  }

}

void CheckselectionX(char x2)
{
   
  for (int i = 0; i < 9; i++){
    if(x1 == i)
      swap(x2, x1);
  }

}

void CheckselectionO(char o2)
{
  
  for (int i = 0; i < 9; i++){
    if(o1 == i)
      swap(o2, o1);
  }

}
