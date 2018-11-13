#include <stdio.h>

unsigned char cube_start[6][9] = {
                        {'w', 'w', 'w', //top, z+
                        'w', 'w', 'w',
                        'w', 'w', 'w'},
                        {'r', 'r', 'r', //hor0, x+
                        'r', 'r', 'r',
                        'r', 'r', 'r'},
                        {'b', 'b', 'b', //hor1, y+
                        'b', 'b', 'b',
                        'b', 'b', 'b'},
                        {'o', 'o', 'o', //hor2
                        'o', 'o', 'o',
                        'o', 'o', 'o'},
                        {'g', 'g', 'g', //hor3
                        'g', 'g', 'g',
                        'g', 'g', 'g'},
                        {'y', 'y', 'y', //bottom
                        'y', 'y', 'y',
                        'y', 'y', 'y'}
};

void rotate(unsigned char rotate_type, unsigned char *cube)
{
    unsigned char temp[9];
/*
    switch(rotate_type) {
        case 0: //x = -1
            temp[0] = cube[0][0]; temp[1] = cube[0][1]; temp[2] = cube[0][2];
            cube[0][0] = cube[2][2]; cube[0][1] = cube[2][5]; cube[0][2] = cube[2][8];
            cube[2][2] = cube[5][8]; cube[2][5] = cube[5][7]; cube[2][8] = cube[5][6];
            cube[5][8] = cube[4][6]; cube[5][7] = cube[4][3]; cube[5][6] = cube[4][0];
            cube[4][6] = temp[0]; cube[4][3] = temp[1]; cube[4][0] = temp[2];
            //rotate a layer
            temp[0] = cube[3][0]; temp[1] = cube[3][1]; temp[2] = cube[3][2];
            temp[3] = cube[3][3]; temp[4] = cube[3][4]; temp[5] = cube[3][5];
            temp[6] = cube[3][6]; temp[7] = cube[3][7]; temp[8] = cube[3][8];
            cube[3][0] = temp[6]; cube[3][3] = temp[7];
            cube[3][6] = temp[8]; cube[3][7] = temp[5];
            cube[3][8] = temp[2]; cube[3][5] = temp[1];
            cube[3][2] = temp[0]; cube[3][1] = temp[3];
            break;
        case 1: //x = 1
            temp[0] = cube[0][6]; temp[1] = cube[0][7]; temp[2] = cube[0][8];
            cube[0][6] = cube[2][0]; cube[0][7] = cube[2][3]; cube[0][8] = cube[2][6];
            cube[2][0] = cube[5][2]; cube[2][3] = cube[5][1]; cube[2][6] = cube[5][0];
            cube[5][2] = cube[4][8]; cube[5][1] = cube[4][5]; cube[5][0] = cube[4][2];
            cube[4][8] = temp[0]; cube[4][5] = temp[1]; cube[4][2] = temp[2];
            //rotate a layer
            temp[0] = cube[1][0]; temp[1] = cube[1][1]; temp[2] = cube[1][2];
            temp[3] = cube[1][3]; temp[4] = cube[1][4]; temp[5] = cube[1][5];
            temp[6] = cube[1][6]; temp[7] = cube[1][7]; temp[8] = cube[1][8];
            cube[1][0] = temp[2]; cube[1][3] = temp[1];
            cube[1][6] = temp[0]; cube[1][7] = temp[3];
            cube[1][8] = temp[6]; cube[1][5] = temp[7];
            cube[1][2] = temp[8]; cube[1][1] = temp[5];
            break;
        case 2: //y = -1
            temp[0] = cube[0][6]; temp[1] = cube[0][3]; temp[2] = cube[0][0];
            cube[0][6] = cube[3][2]; cube[0][3] = cube[3][5]; cube[0][0] = cube[3][8];
            cube[3][2] = cube[5][6]; cube[3][5] = cube[5][3]; cube[3][8] = cube[5][0];
            cube[5][6] = cube[1][6]; cube[5][3] = cube[1][3]; cube[5][0] = cube[1][0];
            cube[1][6] = temp[0]; cube[1][3] = temp[1]; cube[1][0] = temp[2];
            //rotate a layer
            temp[0] = cube[4][0]; temp[1] = cube[4][1]; temp[2] = cube[4][2];
            temp[3] = cube[4][3]; temp[4] = cube[4][4]; temp[5] = cube[4][5];
            temp[6] = cube[4][6]; temp[7] = cube[4][7]; temp[8] = cube[4][8];
            cube[4][0] = temp[6]; cube[4][3] = temp[7];
            cube[4][6] = temp[8]; cube[4][7] = temp[5];
            cube[4][8] = temp[2]; cube[4][5] = temp[1];
            cube[4][2] = temp[0]; cube[4][1] = temp[3];
            break;
        case 3: //y = 1
            temp[0] = cube[0][8]; temp[1] = cube[0][5]; temp[2] = cube[0][2];
            cube[0][8] = cube[3][0]; cube[0][5] = cube[3][3]; cube[0][2] = cube[3][6];
            cube[3][0] = cube[5][8]; cube[3][3] = cube[5][5]; cube[3][6] = cube[5][2];
            cube[5][8] = cube[1][8]; cube[5][5] = cube[1][5]; cube[5][2] = cube[1][2];
            cube[1][8] = temp[0]; cube[1][5] = temp[1]; cube[1][2] = temp[2];
            //rotate a layer
            temp[0] = cube[2][0]; temp[1] = cube[2][1]; temp[2] = cube[2][2];
            temp[3] = cube[2][3]; temp[4] = cube[2][4]; temp[5] = cube[2][5];
            temp[6] = cube[2][6]; temp[7] = cube[2][7]; temp[8] = cube[2][8];
            cube[2][0] = temp[2]; cube[2][3] = temp[1];
            cube[2][6] = temp[0]; cube[2][7] = temp[3];
            cube[2][8] = temp[6]; cube[2][5] = temp[7];
            cube[2][2] = temp[8]; cube[2][1] = temp[5];
            break;
        case 4: //z = -1
            temp[0] = cube[1][8]; temp[1] = cube[1][7]; temp[2] = cube[1][6];
            cube[1][8] = cube[4][8]; cube[1][7] = cube[4][7]; cube[1][6] = cube[4][6];
            cube[4][8] = cube[3][8]; cube[4][7] = cube[3][7]; cube[4][6] = cube[3][6];
            cube[3][8] = cube[2][8]; cube[3][7] = cube[2][7]; cube[3][6] = cube[2][6];
            cube[2][8] = temp[0]; cube[2][7] = temp[1]; cube[2][6] = temp[2];
            //rotate a layer
            temp[0] = cube[5][0]; temp[1] = cube[5][1]; temp[2] = cube[5][2];
            temp[3] = cube[5][3]; temp[4] = cube[5][4]; temp[5] = cube[5][5];
            temp[6] = cube[5][6]; temp[7] = cube[5][7]; temp[8] = cube[5][8];
            cube[5][0] = temp[6]; cube[5][3] = temp[7];
            cube[5][6] = temp[8]; cube[5][7] = temp[5];
            cube[5][8] = temp[2]; cube[5][5] = temp[1];
            cube[5][2] = temp[0]; cube[5][1] = temp[3];
            break;
        case 5: //z = 1
            temp[0] = cube[1][2]; temp[1] = cube[1][1]; temp[2] = cube[1][0];
            cube[1][2] = cube[4][2]; cube[1][1] = cube[4][1]; cube[1][0] = cube[4][0];
            cube[4][2] = cube[3][2]; cube[4][1] = cube[3][1]; cube[4][0] = cube[3][0];
            cube[3][2] = cube[2][2]; cube[3][1] = cube[2][1]; cube[3][0] = cube[2][0];
            cube[2][2] = temp[0]; cube[2][1] = temp[1]; cube[2][0] = temp[2];
            //rotate a layer
            temp[0] = cube[0][0]; temp[1] = cube[0][1]; temp[2] = cube[0][2];
            temp[3] = cube[0][3]; temp[4] = cube[0][4]; temp[5] = cube[0][5];
            temp[6] = cube[0][6]; temp[7] = cube[0][7]; temp[8] = cube[0][8];
            cube[0][0] = temp[2]; cube[0][3] = temp[1];
            cube[0][6] = temp[0]; cube[0][7] = temp[3];
            cube[0][8] = temp[6]; cube[0][5] = temp[7];
            cube[0][2] = temp[8]; cube[0][1] = temp[5];
            break;
        default:
            break;
    }*/
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

int equal_start(unsigned char *cube)
{
    int i, j;

    for(i = 0; i < 6; i ++)
        for(j = 0; j < 9; j ++) {
            if(cube[i * 9 + j] != cube_start[i][j])
                return 0;
        }
    return 1;
}

int main(void)
{
    unsigned char c0, c1, c2;
    FILE *file_cube_start;
    int i, j;
    unsigned char stack_rotate[1000];   //stack to save 6-branch searching tree
    unsigned char depth, depth_limit;
    unsigned char record[64];   //as cube data

    printf("Search for Rubik's cube.\n");

    //Initiate the start cube from file.
    file_cube_start = fopen("start.txt", "r");
    for(i = 0; i < 6; i ++) {
        for(j = 0; j < 3; j ++) {
            fscanf(file_cube_start, "%c %c %c\n", &c0, &c1, &c2);
            cube_start[i][j * 3] = c0;
            cube_start[i][j * 3 + 1] = c1;
            cube_start[i][j * 3 + 2] = c2;
        }
        if(i != 5)
            fscanf(file_cube_start, "\n");
    }
    //Save the start value.
    for(i = 0; i < 6; i ++)
        for(j = 0; j < 9; j ++)
            record[i * 9 + j] = cube_start[i][j];
    print_cube(record);

//    rotate(0, record);
//    printf("%d\n", equal_start());

    fclose(file_cube_start);
    return 0;
}

