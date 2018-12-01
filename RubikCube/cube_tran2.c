#include <stdio.h>

unsigned char record[64 * 32];   //as cube data
unsigned char stack_rotate[32];   //stack to save 6-branch searching tree
int depth_limit = 12; //stack status and limit
int sp = 0; //stack top pointer

unsigned char cube_start[6 * 9] = {
    'y', 'y', 'y', //top, z+
    'y', 'y', 'y',
    'y', 'y', 'y',
    'r', 'r', 'r', //hor0, x+
    'r', 'r', 'r',
    'r', 'r', 'r',
    'g', 'g', 'g', //hor1, y+
    'g', 'g', 'g',
    'g', 'g', 'g',
    'o', 'o', 'o', //hor2
    'o', 'o', 'o',
    'o', 'o', 'o',
    'b', 'b', 'b', //hor3
    'b', 'b', 'b',
    'b', 'b', 'b',
    'w', 'w', 'w', //bottom
    'w', 'w', 'w',
    'w', 'w', 'w'
};

void rotate(unsigned char rotate_type, unsigned char *cube_in, unsigned char *cube_out)
{
    int i;

    switch(rotate_type) {
        case 0: //x = -1
            for(i = 0; i < 6 * 9; i ++)
                cube_out[i] = cube_in[i];
            cube_out[0 * 9 + 0] = cube_in[2 * 9 + 2];
            cube_out[0 * 9 + 1] = cube_in[2 * 9 + 5];
            cube_out[0 * 9 + 2] = cube_in[2 * 9 + 8];
            cube_out[2 * 9 + 2] = cube_in[5 * 9 + 8];
            cube_out[2 * 9 + 5] = cube_in[5 * 9 + 7];
            cube_out[2 * 9 + 8] = cube_in[5 * 9 + 6];
            cube_out[5 * 9 + 8] = cube_in[4 * 9 + 6];
            cube_out[5 * 9 + 7] = cube_in[4 * 9 + 3];
            cube_out[5 * 9 + 6] = cube_in[4 * 9 + 0];
            cube_out[4 * 9 + 6] = cube_in[0 * 9 + 0];
            cube_out[4 * 9 + 3] = cube_in[0 * 9 + 1];
            cube_out[4 * 9 + 0] = cube_in[0 * 9 + 2];
            //rotate a layer
            cube_out[3 * 9 + 0] = cube_in[3 * 9 + 6];
            cube_out[3 * 9 + 3] = cube_in[3 * 9 + 7];
            cube_out[3 * 9 + 6] = cube_in[3 * 9 + 8];
            cube_out[3 * 9 + 7] = cube_in[3 * 9 + 5];
            cube_out[3 * 9 + 8] = cube_in[3 * 9 + 2];
            cube_out[3 * 9 + 5] = cube_in[3 * 9 + 1];
            cube_out[3 * 9 + 2] = cube_in[3 * 9 + 0];
            cube_out[3 * 9 + 1] = cube_in[3 * 9 + 3];
            break;
        case 1: //x = 1
            for(i = 0; i < 6 * 9; i ++)
                cube_out[i] = cube_in[i];
            cube_out[0 * 9 + 6] = cube_in[2 * 9 + 0];
            cube_out[0 * 9 + 7] = cube_in[2 * 9 + 3];
            cube_out[0 * 9 + 8] = cube_in[2 * 9 + 6];
            cube_out[2 * 9 + 0] = cube_in[5 * 9 + 2];
            cube_out[2 * 9 + 3] = cube_in[5 * 9 + 1];
            cube_out[2 * 9 + 6] = cube_in[5 * 9 + 0];
            cube_out[5 * 9 + 2] = cube_in[4 * 9 + 8];
            cube_out[5 * 9 + 1] = cube_in[4 * 9 + 5];
            cube_out[5 * 9 + 0] = cube_in[4 * 9 + 2];
            cube_out[4 * 9 + 8] = cube_in[0 * 9 + 6];
            cube_out[4 * 9 + 5] = cube_in[0 * 9 + 7];
            cube_out[4 * 9 + 2] = cube_in[0 * 9 + 8];
            //rotate a layer
            cube_out[1 * 9 + 0] = cube_in[1 * 9 + 2];
            cube_out[1 * 9 + 3] = cube_in[1 * 9 + 1];
            cube_out[1 * 9 + 6] = cube_in[1 * 9 + 0];
            cube_out[1 * 9 + 7] = cube_in[1 * 9 + 3];
            cube_out[1 * 9 + 8] = cube_in[1 * 9 + 6];
            cube_out[1 * 9 + 5] = cube_in[1 * 9 + 7];
            cube_out[1 * 9 + 2] = cube_in[1 * 9 + 8];
            cube_out[1 * 9 + 1] = cube_in[1 * 9 + 5];
            break;
        case 2: //y = -1
            for(i = 0; i < 6 * 9; i ++)
                cube_out[i] = cube_in[i];
            cube_out[0 * 9 + 6] = cube_in[3 * 9 + 2];
            cube_out[0 * 9 + 3] = cube_in[3 * 9 + 5];
            cube_out[0 * 9 + 0] = cube_in[3 * 9 + 8];
            cube_out[3 * 9 + 2] = cube_in[5 * 9 + 6];
            cube_out[3 * 9 + 5] = cube_in[5 * 9 + 3];
            cube_out[3 * 9 + 8] = cube_in[5 * 9 + 0];
            cube_out[5 * 9 + 6] = cube_in[1 * 9 + 6];
            cube_out[5 * 9 + 3] = cube_in[1 * 9 + 3];
            cube_out[5 * 9 + 0] = cube_in[1 * 9 + 0];
            cube_out[1 * 9 + 6] = cube_in[0 * 9 + 6];
            cube_out[1 * 9 + 3] = cube_in[0 * 9 + 3];
            cube_out[1 * 9 + 0] = cube_in[0 * 9 + 0];
            //rotate a layer
            cube_out[4 * 9 + 0] = cube_in[4 * 9 + 6];
            cube_out[4 * 9 + 3] = cube_in[4 * 9 + 7];
            cube_out[4 * 9 + 6] = cube_in[4 * 9 + 8];
            cube_out[4 * 9 + 7] = cube_in[4 * 9 + 5];
            cube_out[4 * 9 + 8] = cube_in[4 * 9 + 2];
            cube_out[4 * 9 + 5] = cube_in[4 * 9 + 1];
            cube_out[4 * 9 + 2] = cube_in[4 * 9 + 0];
            cube_out[4 * 9 + 1] = cube_in[4 * 9 + 3];
            break;
        case 3: //y = 1
            for(i = 0; i < 6 * 9; i ++)
                cube_out[i] = cube_in[i];
            cube_out[0 * 9 + 8] = cube_in[3 * 9 + 0];
            cube_out[0 * 9 + 5] = cube_in[3 * 9 + 3];
            cube_out[0 * 9 + 2] = cube_in[3 * 9 + 6];
            cube_out[3 * 9 + 0] = cube_in[5 * 9 + 8];
            cube_out[3 * 9 + 3] = cube_in[5 * 9 + 5];
            cube_out[3 * 9 + 6] = cube_in[5 * 9 + 2];
            cube_out[5 * 9 + 8] = cube_in[1 * 9 + 8];
            cube_out[5 * 9 + 5] = cube_in[1 * 9 + 5];
            cube_out[5 * 9 + 2] = cube_in[1 * 9 + 2];
            cube_out[1 * 9 + 8] = cube_in[0 * 9 + 8];
            cube_out[1 * 9 + 5] = cube_in[0 * 9 + 5];
            cube_out[1 * 9 + 2] = cube_in[0 * 9 + 2];
            //rotate a layer
            cube_out[2 * 9 + 0] = cube_in[2 * 9 + 2];
            cube_out[2 * 9 + 3] = cube_in[2 * 9 + 1];
            cube_out[2 * 9 + 6] = cube_in[2 * 9 + 0];
            cube_out[2 * 9 + 7] = cube_in[2 * 9 + 3];
            cube_out[2 * 9 + 8] = cube_in[2 * 9 + 6];
            cube_out[2 * 9 + 5] = cube_in[2 * 9 + 7];
            cube_out[2 * 9 + 2] = cube_in[2 * 9 + 8];
            cube_out[2 * 9 + 1] = cube_in[2 * 9 + 5];
            break;
        case 4: //z = -1
            for(i = 0; i < 6 * 9; i ++)
                cube_out[i] = cube_in[i];
            cube_out[1 * 9 + 8] = cube_in[4 * 9 + 8];
            cube_out[1 * 9 + 7] = cube_in[4 * 9 + 7];
            cube_out[1 * 9 + 6] = cube_in[4 * 9 + 6];
            cube_out[4 * 9 + 8] = cube_in[3 * 9 + 8];
            cube_out[4 * 9 + 7] = cube_in[3 * 9 + 7];
            cube_out[4 * 9 + 6] = cube_in[3 * 9 + 6];
            cube_out[3 * 9 + 8] = cube_in[2 * 9 + 8];
            cube_out[3 * 9 + 7] = cube_in[2 * 9 + 7];
            cube_out[3 * 9 + 6] = cube_in[2 * 9 + 6];
            cube_out[2 * 9 + 8] = cube_in[1 * 9 + 8];
            cube_out[2 * 9 + 7] = cube_in[1 * 9 + 7];
            cube_out[2 * 9 + 6] = cube_in[1 * 9 + 6];
            //rotate a layer
            cube_out[5 * 9 + 0] = cube_in[5 * 9 + 6];
            cube_out[5 * 9 + 3] = cube_in[5 * 9 + 7];
            cube_out[5 * 9 + 6] = cube_in[5 * 9 + 8];
            cube_out[5 * 9 + 7] = cube_in[5 * 9 + 5];
            cube_out[5 * 9 + 8] = cube_in[5 * 9 + 2];
            cube_out[5 * 9 + 5] = cube_in[5 * 9 + 1];
            cube_out[5 * 9 + 2] = cube_in[5 * 9 + 0];
            cube_out[5 * 9 + 1] = cube_in[5 * 9 + 3];
            break;
        case 5: //z = 1
            for(i = 0; i < 6 * 9; i ++)
                cube_out[i] = cube_in[i];
            cube_out[1 * 9 + 2] = cube_in[4 * 9 + 2];
            cube_out[1 * 9 + 1] = cube_in[4 * 9 + 1];
            cube_out[1 * 9 + 0] = cube_in[4 * 9 + 0];
            cube_out[4 * 9 + 2] = cube_in[3 * 9 + 2];
            cube_out[4 * 9 + 1] = cube_in[3 * 9 + 1];
            cube_out[4 * 9 + 0] = cube_in[3 * 9 + 0];
            cube_out[3 * 9 + 2] = cube_in[2 * 9 + 2];
            cube_out[3 * 9 + 1] = cube_in[2 * 9 + 1];
            cube_out[3 * 9 + 0] = cube_in[2 * 9 + 0];
            cube_out[2 * 9 + 2] = cube_in[1 * 9 + 2];
            cube_out[2 * 9 + 1] = cube_in[1 * 9 + 1];
            cube_out[2 * 9 + 0] = cube_in[1 * 9 + 0];
            //rotate a layer
            cube_out[0 * 9 + 0] = cube_in[0 * 9 + 2];
            cube_out[0 * 9 + 3] = cube_in[0 * 9 + 1];
            cube_out[0 * 9 + 6] = cube_in[0 * 9 + 0];
            cube_out[0 * 9 + 7] = cube_in[0 * 9 + 3];
            cube_out[0 * 9 + 8] = cube_in[0 * 9 + 6];
            cube_out[0 * 9 + 5] = cube_in[0 * 9 + 7];
            cube_out[0 * 9 + 2] = cube_in[0 * 9 + 8];
            cube_out[0 * 9 + 1] = cube_in[0 * 9 + 5];
            break;
        default:
            break;
    }
}

void print_cube(unsigned char *cube)
{
    int i;

    printf("Top layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%02d", cube[0 * 9 + i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
    printf("Horizon0 layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%02d", cube[1 * 9 + i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
    printf("Horizon1 layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%02d", cube[2 * 9 + i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
    printf("Horizon2 layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%02d", cube[3 * 9 + i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
    printf("Horizon3 layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%02d", cube[4 * 9 + i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
    printf("Bottom layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%02d", cube[5 * 9 + i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
}

int cube_equal(unsigned char *cube1, unsigned char *cube2)
{
    int i;

    for(i = 0; i < 6 * 9; i ++)
        if(cube1[i] != cube2[i])
            return 0;
    return 1;
}

int cube_2row(unsigned  char *cube1, unsigned char *cube2)
{
    int i;

    for(i = 9 + 3; i < 9 + 9; i ++) //check hor0
        if(cube1[i] != cube2[i])
            return 0;
    for(i = 9 * 2 + 3; i < 9 * 2 + 9; i ++) //check hor1
        if(cube1[i] != cube2[i])
            return 0;
    for(i = 9 * 3 + 3; i < 9 * 3 + 9; i ++) //check hor2
        if(cube1[i] != cube2[i])
            return 0;
    for(i = 9 * 4 + 3; i < 9 * 4 + 9; i ++) //check hor3
        if(cube1[i] != cube2[i])
            return 0;
    for(i = 9 * 5; i < 9 * 5 + 9; i ++) //check bottom
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
    long count_l = 0;
    long count_h = 0;
    int tran_count = 1;

    printf("Search for transfer in Rubik's cube.\n");
    printf("Keep the bottom and the lowest row.\n");

    //Initiate the start cube.
    for(i = 0; i < 6 * 9; i ++) {
        cube_start[i] = i;
    }
    print_cube(cube_start);

    depth_limit = 14;
    rotate_type = 0;
    //Deep-at-first search.
    while(sp < depth_limit)
    {
        int sp_last = sp;
        push_cube(rotate_type);
        count_l ++;
        if(count_l == 100000000) {
            printf("Count_l meets 100,000,000. Count_h: %ld\n", count_h);
            count_l = 0;
            count_h ++;
        }
        if(cube_equal(cube_start, record + sp_last * 64)) {
            //At a recycle path end same as the start, return.
            rotate_type = pop_cube();
            while((sp > 0) && (rotate_type >= 5))
                //Return to the last depth
                rotate_type = pop_cube();
            if((sp == 0) && (rotate_type >= 5))
                //End research
                rotate_type = 0xff;
            else {  //Search in the horizontal direction.
                if(rotate_type == 3)    //Don't use rotate_type 4, fix the bottom layer
                    rotate_type = 5;
                else
                    rotate_type ++;
            }
        }
        //Meet 2-row.
        else if(cube_2row(cube_start, record + sp_last * 64)) {
            printf("\nTran case: %d, when sp = %d!\n", tran_count, sp);
            tran_count ++;
            for(i = 0; i < sp; i ++)
                printf("%d, ", stack_rotate[i]);
            printf("\n");
            //print_cube(record + sp_last * 64);
            //Return, to search the next transform.
            rotate_type = pop_cube();
            while((sp > 0) && (rotate_type >= 5))
                //Return to the last depth
                rotate_type = pop_cube();
            if((sp == 0) && (rotate_type >= 5))
                //End research
                rotate_type = 0xff;
            else {  //Search in the horizontal direction.
                if(rotate_type == 3)    //Don't use rotate_type 4, fix the bottom layer
                    rotate_type = 5;
                else
                    rotate_type ++;
            }
        }
        //check recycle between two middle cube
        else if(sp > 0) {
            for(i = 0; i < sp_last - 1; i ++) {
                if(cube_equal(record + i * 64, record + sp_last * 64)) {
                    rotate_type = pop_cube();
                    while((sp > 0) && (rotate_type >= 5))
                        //Return to the last depth
                        rotate_type = pop_cube();
                    if((sp == 0) && (rotate_type >= 5)) {
                        //End research
                        rotate_type = 0xff;
                    }
                    else {  //Search in the horizontal direction.
                        if(rotate_type == 3)    //Don't use rotate_type 4, fix the bottom layer
                            rotate_type = 5;
                        else
                            rotate_type ++;
                    }
                    break;
                }
            }
        }

        //All the search is end.
        if(rotate_type > 5)
            break;

        //To a deeper layer, check.
        if(sp > sp_last) {
            //At the deepest layer, return.
            if(sp == depth_limit) {
                rotate_type = pop_cube();
                while((sp > 0) && (rotate_type >= 5))
                    //Return to the last depth
                    rotate_type = pop_cube();
                if((sp == 0) && (rotate_type >= 5)) {
                    //End research
                    rotate_type = 0xff;
                    break;
                }
                else {  //Search in the horizontal direction.
                    if(rotate_type == 3)    //Don't use rotate_type 4, fix the bottom layer
                        rotate_type = 5;
                    else
                        rotate_type ++;
                }
            }
            //To a deeper layer, start from 0.
            else
                rotate_type = 0;
        }
    }

    printf("Exit %d, %d\n", sp, rotate_type);
    printf("%ld: %ld\n", count_h, count_l);
    for(i = 0; i < sp; i ++)
        printf("%d, ", stack_rotate[i]);
    printf("\n");
    return 0;
}

