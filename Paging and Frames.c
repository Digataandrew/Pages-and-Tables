#include<stdio.h>
//Requires C99 Complier to run. Uses VLA (Variable Length Array)
//Can be run on online compiler that has C99
int main()
{

    int p_mem = 0; //Create Physical Memory
    printf("Input size of physical memory in megabytes: \n");
    scanf("%d", &p_mem);

    int l_mem = 0; //Create Logical memory
    printf("Input size of logical memory in megabytes: \n");
    scanf("%d", &l_mem);

    int p_size = 0; //Create Page Size
    printf("Input size of pages: \n");
    scanf("%d", &p_size);

    int num_pages = 0; //# of pages
    num_pages = l_mem / p_size; //equation for # of pages

    int num_frames = 0; //# of frames
    num_frames = p_mem / p_size; //equation for # of frames

    int p_array[num_pages];   //Array for the pages
    int f_array[p_mem];       //Array for the frames
    int l_array[l_mem];       //Array for all data
    int temp_n;               //What Part of Frame number it is on
    int temp_p;               //What Part of Logical memory it is on
    int temp_array[num_pages];//array with location of start of each page
    int counter = 0;            //counter to print frame table

    for (int i = 0; i < l_mem; i++)  //put in all logical memory
    {
        printf("Insert data[%d] for l_mem: \n", i); //Assign Data to each
                                                  // logic mem
        scanf("%d", &l_array[i]);
    }

    for (int i = 0; i < num_pages; i++) //Inputs page table array
    {
        printf("Page to frame data [%d] assigned: \n", i); //Assigns which page
                                                       //goes to which frame
        scanf("%d", &p_array[i]);
    }
    printf("\n");
    printf("Page Table\n");

    for (int i = 0; i < num_pages; i++)   //Prints  the Page Table
    {
        printf("%d: %d\n", i, p_array[i]);
    }
    printf("\n");

    printf("Frame Table\n");

    for (int i = 0; i < num_pages; i++) //fill temp array with location of where
                                 //each page starts
    {
        temp_array[i] = p_array[i] * p_size; //equation to get where each page
                                          //starts
    }

    for (int i = 0; i < p_mem; i++) //Fill Frame Array with 0 making it empty
    {
        f_array[i] = 0;
    }
    for (int i = 0; i < num_pages; i++)// does incrementation as many times as
                                  //there are frames to get all of logical
                                  //memory
    {
        temp_n = temp_array[i]; //temp n= data of page table = location
                                  //of frames
        temp_p = i * p_size;
        for (int j = 0; j < p_size; j++) //starts at frame location then
                                    //increments page size to get full
                                    //page in correct spot
        {
            f_array[temp_n] = l_array[temp_p];
            temp_p = temp_p + 1;
            temp_n = temp_n + 1;
        }

    }

    for (int i = 0; i < num_frames; i++) //Print out Frames Array
    {
        printf("Page %d\n", i);
        for (int j = 0; j < p_size; j++)
        {
            printf("%d: %d\n", counter, f_array[counter]);
            counter++;
        }
        printf("------\n");
    }
}
