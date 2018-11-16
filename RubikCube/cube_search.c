#include <stdio.h>

unsigned char cube_start[6 * 9] = {
    'w', 'w', 'w', //top, z+
    'w', 'w', 'w',
    'w', 'w', 'w',
    'r', 'r', 'r', //hor0, x+
    'r', 'r', 'r',
    'r', 'r', 'r',
    'b', 'b', 'b', //hor1, y+
    'b', 'b', 'b',
    'b', 'b', 'b',
    'o', 'o', 'o', //hor2
    'o', 'o', 'o',
    'o', 'o', 'o',
    'g', 'g', 'g', //hor3
    'g', 'g', 'g',
    'g', 'g', 'g',
    'y', 'y', 'y', //bottom
    'y', 'y', 'y',
    'y', 'y', 'y'
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
        printf("%c", cube[0 * 9 + i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
    printf("Horizon0 layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%c", cube[1 * 9 + i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
    printf("Horizon1 layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%c", cube[2 * 9 + i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
    printf("Horizon2 layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%c", cube[3 * 9 + i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
    printf("Horizon3 layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%c", cube[4 * 9 + i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
    printf("Bottom layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%c", cube[5 * 9 + i]);
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

int main(void)
{
    unsigned char c0, c1, c2;
    FILE *file_cube_start;
    int i, j;
    unsigned char stack_rotate[1000];   //stack to save 6-branch searching tree
    unsigned char depth, depth_limit;
    unsigned char record[64 * 1000];   //as cube data

    printf("Search for Rubik's cube.\n");

    //Initiate the start cube from file.
    file_cube_start = fopen("start.txt", "r");
    for(i = 0; i < 6; i ++) {
        for(j = 0; j < 3; j ++) {
            fscanf(file_cube_start, "%c %c %c\n", &c0, &c1, &c2);
            cube_start[i * 9 + j * 3] = c0;
            cube_start[i * 9 + j * 3 + 1] = c1;
            cube_start[i * 9 + j * 3 + 2] = c2;
        }
        if(i != 5)
            fscanf(file_cube_start, "\n");
    }
    fclose(file_cube_start);
    print_cube(cube_start);

    rotate(0, cube_start, record);
    rotate(1, record, record + 64);
    rotate(2, record + 64 * 1, record + 64 * 2);
    rotate(3, record + 64 * 2, record + 64 * 3);
    rotate(4, record + 64 * 3, record + 64 * 4);
    rotate(5, record + 64 * 4, record + 64 * 5);
    //printf("%d\n", cube_equal(cube_start, record + 64 * 3));
    print_cube(record + 64 * 5);

    return 0;
}

