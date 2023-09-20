#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// typedef struct node {
//   char *artist;
//   char *songName;
//   char *genre;
//   struct node *next;
// }Node;

typedef struct linkedlist{
    Node*head;
}Linkedlist;

void initList(Linkedlist *list) {
    list->head = NULL;
}

// See below the main function for descriptions of what these functions do

// void inputStringFromUser(char *prompt, char *s, int arraySize);
// void songNameDuplicate(char *songName);
// void songNameFound(char *songName);
// void songNameNotFound(char *songName);
// void songNameDeleted(char *songName);
// void artistFound(char *artist);
// void artistNotFound(char *artist);
// void printMusicLibraryEmpty(void);
// void printMusicLibraryTitle(void);

// const int MAX_LENGTH = 1024;

Node *createNode(char *songName,char *artist,char *genre){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> songName = (char*)malloc((strlen(songName)+1)*sizeof(char));
    newNode -> artist = (char*)malloc((strlen(artist)+1)*sizeof(char));
    newNode -> genre = (char*)malloc((strlen(genre)+1)*sizeof(char));

    if (newNode != NULL) {
        strcpy(newNode -> songName,songName);
        strcpy(newNode -> artist,artist);
        strcpy(newNode -> genre,genre);
        newNode->next = NULL;
    }
    return newNode;
}

void insertNewNode(Linkedlist*list, char *song,char*artist,char*genre){
  Node*insert = createNode(song,artist,genre);
  Node*nextOne = list->head;
  if(nextOne==NULL||strcmp(song,nextOne -> songName)<0){
    if(insert!=NULL){
      insert -> next = nextOne;
      list -> head = insert;
      return;
    }
  }
  while(nextOne->next!=NULL&&strcmp(nextOne->next->songName,song)<0){
    nextOne=nextOne->next;
  }
  if(insert!=NULL){
    insert->next=nextOne->next;
    nextOne->next=insert;
  }
}

bool songInlist(Linkedlist *list, char* song){
    bool find=false;
    if(list->head==NULL){
        find=false;
    }
    Node *insert=list->head;
    while(insert!=NULL){
        if(strcmp(insert->songName,song)==0){
          find=true;
        }
        insert=insert->next;
    }
    return find;
}

void deleteSong(Linkedlist* list,char *song){
  if(list->head==NULL){
    return;
  }
  Node*current=list->head;
  Node *nextOne=current->next;
  if(strcmp(current->songName,song)==0){
    songNameDeleted(current->songName);
    free(current->songName);
    free(current->artist);
    free(current->genre);
    list->head=nextOne;
    return;    
  }

  bool find=false;

  //Node*current=head;

  while(current->next!=NULL&&!find){
    if(strcmp(current->next->songName,song)==0){
      find=true;
    }
    else{
      find=false;
      current=current->next;
    }
  }
  if(find&&current->next!=NULL){
    Node*nextNext=current->next;
    songNameDeleted(nextNext->songName);
    free(nextNext->songName);
    free(nextNext->artist);
    free(nextNext->genre);
    current->next=nextNext->next;
  }
}

void searchSong(Linkedlist*list,char* song){
  Node*current;
  current=list->head;
  if(current==NULL){
    return;
  }
  while(current!=NULL){
    if(strcmp(current->songName,song)==0){
      songNameFound(song);
      printf("\n%s\n",current->songName);
      printf("%s\n",current->artist);
      printf("%s\n",current->genre);
      return;
    }
    current=current->next;
  }
  songNameNotFound(song);
}

void printList(Linkedlist*list){
  Node*current;
  current=list->head;
  printMusicLibraryTitle();
  if(current==NULL){
    return;
  }
  while(current!=NULL){
    printf("\n%s\n",current->songName);
    printf("%s\n",current->artist);
    printf("%s\n",current->genre);
    current=current->next;
  }
}

void deleteAll(Linkedlist*list){
  Node*current=list->head;
  Node*remainInlist;
  while(current!=NULL){
    songNameDeleted(current->songName);
    remainInlist=current->next;
    free(current->songName);
    free(current->artist);
    free(current->genre);
    current=remainInlist;
  }
  printMusicLibraryEmpty();
}

bool isEmpty(Linkedlist* list){
  if(list->head==NULL){
    return true;
  }
  return false;
}

// void inputStringFromUser(char *prompt, char *s, int maxStrLength) {
//   int i = 0;
//   char c;

//   printf("%s --> ", prompt);
//   while (i < maxStrLength && (c = getchar()) != '\n')
//     s[i++] = c;
//   s[i] = '\0';
// }

// void songNameDuplicate(char *songName) {
//   printf("\nA song with the name '%s' is already in the music library.\n"
//          "No new song entered.\n",
//          songName);
// }

// void songNameFound(char *songName) {
//   printf("\nThe song name '%s' was found in the music library.\n", songName);
// }

// void songNameNotFound(char *songName) {
//   printf("\nThe song name '%s' was not found in the music library.\n",
//          songName);
// }

// void songNameDeleted(char *songName) {
//   printf("\nDeleting a song with name '%s' from the music library.\n",
//          songName);
// }

// void printMusicLibraryEmpty(void) { 
//   printf("\nThe music library is empty.\n"); 
// }

// void printMusicLibraryTitle(void) { 
//   printf("\nMy Personal Music Library: \n"); 
// }


int main(void) {
  
    char*songName=(char*)malloc(MAX_LENGTH*sizeof(char));
    char*artist=(char*)malloc(MAX_LENGTH*sizeof(char));
    char*genre=(char*)malloc(MAX_LENGTH*sizeof(char));

    Linkedlist list;
    //Node*current=list->head;
    
    printf("Personal Music Library.\n\n");
    printf("%s", "Commands are I (insert), D (delete), S (search by song name),\n"
               "P (print), Q (quit).\n");

    char response;
    char input[MAX_LENGTH + 1];
    do {
        inputStringFromUser("\nCommand", input, MAX_LENGTH);
        response = toupper(input[0]);

        if (response == 'I') {
            char*promotName="Song name";
            char*promotArtist="Artist";
            char*promotGenre="Genre";

            inputStringFromUser(promotName,songName,MAX_LENGTH);
            inputStringFromUser(promotArtist,artist,MAX_LENGTH);
            inputStringFromUser(promotGenre,genre,MAX_LENGTH);

            if(!songInlist(&list,songName)){
                insertNewNode(&list, songName, artist, genre);
            }
            else{
                songNameDuplicate(songName);
            }
        }
        else if (response == 'D') {

          char *prompt = "\nEnter the name of the song to be deleted";
          inputStringFromUser(prompt,songName,MAX_LENGTH);
          if(songInlist(&list,songName)){
            deleteSong(&list,songName);
          }
          else{
            songNameNotFound(songName);
          }
        } else if (response == 'S'){
        char *prompt = "\nEnter the name of the song to search for";
        inputStringFromUser(prompt,songName,MAX_LENGTH);
        searchSong(&list,songName);

        }else if(response == 'P') {
          if(!isEmpty(&list)){
            printList(&list);
          }else{
            printMusicLibraryEmpty();
          }

        }else if(response == 'Q') {
          ;

        }else{
        printf("\nInvalid command.\n");
        }
    } while (response != 'Q');

      deleteAll(&list);
      //printList(&list);

  return 0;
}
