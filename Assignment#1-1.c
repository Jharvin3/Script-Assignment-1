#include <stdio.h>
#include <stdlib.h>

struct present {
char *present_name;
float price;
};

//Function to delete the array when called
struct present* delete_present_list(struct present* present_list, int num){
    //Checking if the present_list is NULL
    if(present_list == NULL){
    return NULL;
}

//Loop through the array and freeing the present_name
for(int i = 0; i < num; i++){
    free(present_list[i].present_name);
}

//Freeing the array itself
free(present_list);

//To show the array is now empty
return NULL;
}


int main(){
    int num_presents = 5; //Number of presents
    struct present *present_list = (struct present*)malloc(num_presents *sizeof(struct present)); //Allocating memory

    if(present_list == NULL){
        printf("Memory allocation for present_list failed\n");
        return 1;
    }

    //Initializing the present_list with data 
    for(int i = 0; i < num_presents; i++){
        present_list[i].present_name = (char*)malloc(15 * sizeof(char)); //Allocating memory for the present_name

        if(present_list[i].present_name == NULL){
            printf("Memory allocation for present_name failed\n");
            return 1;
        }
    }

    //Printing the list of presents
    printf("List of presents: \n");
    for(int i = 0; i < num_presents; i++){
        printf("Presents: %s\n", present_list[i].present_name);
    }
    
    //Deleting the presents list
    present_list = delete_present_list(present_list, num_presents);

    //Checking to see if the list was deleted correctly
    if(present_list == NULL){
        printf("Present List has been deleted\n");
    }

    return 0;
}