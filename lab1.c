// <p class="head" id="two"><b><u><i>Directors</u></b></p>
// <ol>
//   <li> Jon Favreau
//     <ul>
//     <li>Iron Man(2008)</li>
//     <li>Iron Man2(2010)</li>
//   </ul>
// </li>
// <br>
//   <li>Shane Black <ul>
//     <li>Iron Man3(2013)</li>
//   </ul></li>
//   <br>
//   <li>Louis Leterrier <ul>
//     <li>The Incredible Hulk(2008)</li>
//   </ul></li>
//   <br>
//   <li>Kenneth Branagh <ul>
//     <li>Thor(2011)</li>
//   </ul></li>
//   <br>
//   <li id="three">Alan Taylor <ul>
//     <li>Thor: The Dark World(2013)</li>
//   </ul></li>
//   <br>
//   <li>Taika Waititi <ul>
//     <li>Thor: Ragnarok(2017)</li>
//     <li>Thor: Love and Thunder(2022)</li>
//   </ul></li><br>
// <li>Joe Johnston <ul>
//   <li>Captain America: The First Avenger (2011)</li>
// </ul></li><br>
// <li>Joss Whedon <ul>
//   <li>The Avengers (2012)</li>
//   <li>Avengers: Age of Ultron (2015)</li>
// </ul></li><br>
// </ol>
//
//
//   </div>
#include <stdio.h>
#include <stdlib.h>
typedef struct players{
  char name[25];
  char team[20];
  int matchs;
  int runs;
}ipl;
void read(ipl *play,int n);
void max(ipl play[];int n);
void match(ipl play[],int n);
int main()
{
  int n;
  printf("Enter no of players records\n" );
  scanf("%d\n",&n );
  ipl play[n];
  read(play,n);
  max(play,n);
  match(play,n);
  return 0;
}
void read(ipl *play,int n)
{
  for(int i=0;i<n;i++)
  {
    printf("Enter player name,team name,no of matches played and runs scored\n");
    scanf("%s\n",(play+i)->name );
    fflush(stdout);
    scanf("%s\n",(play+i)->team );
    fflush(stdout);
    scanf("%d\n",&(play+i)->matchs);
    scanf("%d\n",&(play+i)->runs);
  }
}
void max(ipl play[];int n)
{
  int pos=0;
  int maxi=play[0].runs;
  for(int i=1;i<n;i++)
  {
    if(maxi<play[i].runs)
    {
      pos=i;
      maxi=play[i].runs;
    }
  }
  printf("Player Name:%s\nTeam Name:%s\nMatches:%d\nRuns Scared:%d\n",play[pos].name,play[pos].team,play[pos].matchs,play[pos].runs);
}
void match(ipl play[],int n)
{
  for (int i=0;  i <n;  i++) {
    printf("Player Name:%s\nTeam Name:%s\nMatches:%d\nRuns Scared:%d\n",play[i].name,play[i].team,play[i].matchs,play[i].runs);
  }
}
