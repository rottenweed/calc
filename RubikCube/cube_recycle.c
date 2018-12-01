#include    <stdio.h>
#include    "cube_rotate.c"

unsigned char record[64 * 100];   //as cube data
unsigned char stack_rotate[100];   //stack to save 6-branch searching tree
int depth_limit = 100; //stack status and limit
int sp = 0; //stack top pointer

int cube_equal(unsigned char *cube1, unsigned char *cube2)
{
    int i;

    for(i = 0; i < 6 * 9; i ++)
        if(cube1[i] != cube2[i])
            return 0;
    return 1;
}

int push_cube(unsigned char rotate_type)
{
    unsigned char *cube_source;

    if(sp < depth_limit) {
        if(sp > 0)
            cube_source = record + (sp - 1) * 64;
        else
            cube_source = cube_start;
        rotate(rotate_type, cube_source, record + sp * 64);
        stack_rotate[sp] = rotate_type;
        sp ++;
        return 0;
    }
    else
        return 1;
}

unsigned char pop_cube(void)
{
    if(sp > 0) {
        sp --;
        return stack_rotate[sp];
    }
    else
        return 0xff;
}

int main(void)
{
    int i;
    unsigned char rotate_type;
    long path_no = 0;
    long count_l = 0;
    long count_h = 0;

    printf("Search for Rubik's cube.\n");

    //Initiate the start cube from file.
    for(i = 0; i < 6 * 9; i ++) {
        cube_start[i] = i;
    }

    depth_limit = 8;
    rotate_type = 0;
    //Deep-at-first search.
    while(sp < depth_limit)
    {
        push_cube(rotate_type);
        count_l ++;
        if(count_l == 100000000) {
            printf("Count_l meets 100,000,000. Count_h: %ld\n", count_h);
            count_l = 0;
            count_h ++;
        }
        if(cube_equal(cube_start, record + (sp - 1) * 64)) {
            printf("\nEqual when sp = %d!\n", sp);
            printf("Path %ld: ", path_no ++);
            for(i = 0; i < sp; i ++)
                printf("%d, ", stack_rotate[i]);
            printf("\n");
            //At a recycle path end, return.
            rotate_type = pop_cube();
            while((sp > 0) && (rotate_type >= 11))
                //Return to the last depth
                rotate_type = pop_cube();
            if((sp == 0) && (rotate_type >= 11))
                //End research
                break;
            else    //Search in the horizontal direction.
                rotate_type ++;
        }
        //At the deepest layer, return.
        else if(sp == depth_limit) {
            rotate_type = pop_cube();
            while((sp > 0) && (rotate_type >= 11))
                //Return to the last depth
                rotate_type = pop_cube();
            if((sp == 0) && (rotate_type >= 11))
                //End research
                break;
            else    //Search in the horizontal direction.
                rotate_type ++;
        }
        //To a deeper layer, start from 0.
        else
            rotate_type = 0;
    }

    printf("Total search: %ld %ld\n", count_h, count_l);
    return 0;
}

