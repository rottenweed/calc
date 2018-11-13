#include <stdio.h>

unsigned char top[] = {'w', 'w', 'w',   //z
                        'w', 'w', 'w',
                        'w', 'w', 'w'};
unsigned char hor0[] = {'r', 'r', 'r',  //x
                        'r', 'r', 'r',
                        'r', 'r', 'r'};
unsigned char hor1[] = {'b', 'b', 'b',  //y
                        'b', 'b', 'b',
                        'b', 'b', 'b'};
unsigned char hor2[] = {'o', 'o', 'o',
                        'o', 'o', 'o',
                        'o', 'o', 'o'};
unsigned char hor3[] = {'g', 'g', 'g',
                        'g', 'g', 'g',
                        'g', 'g', 'g'};
unsigned char bottom[] = {'y', 'y', 'y',
                        'y', 'y', 'y',
                        'y', 'y', 'y'};

void rotate(unsigned char rotate_type)
{
    unsigned char temp[9];
    switch(rotate_type) {
        case 0: //x = -1
            temp[0] = top[0]; temp[1] = top[1]; temp[2] = top[2];
            top[0] = hor1[2]; top[1] = hor1[5]; top[2] = hor1[8];
            hor1[2] = bottom[8]; hor1[5] = bottom[7]; hor1[8] = bottom[6];
            bottom[8] = hor3[6]; bottom[7] = hor3[3]; bottom[6] = hor3[0];
            hor3[6] = temp[0]; hor3[3] = temp[1]; hor3[0] = temp[2];
            //rotate a layer
            temp[0] = hor2[0]; temp[1] = hor2[1]; temp[2] = hor2[2];
            temp[3] = hor2[3]; temp[4] = hor2[4]; temp[5] = hor2[5];
            temp[6] = hor2[6]; temp[7] = hor2[7]; temp[8] = hor2[8];
            hor2[0] = temp[6]; hor2[3] = temp[7];
            hor2[6] = temp[8]; hor2[7] = temp[5];
            hor2[8] = temp[2]; hor2[5] = temp[1];
            hor2[2] = temp[0]; hor2[1] = temp[3];
            break;
        case 1: //x = 1
            temp[0] = top[6]; temp[1] = top[7]; temp[2] = top[8];
            top[6] = hor1[0]; top[7] = hor1[3]; top[8] = hor1[6];
            hor1[0] = bottom[2]; hor1[3] = bottom[1]; hor1[6] = bottom[0];
            bottom[2] = hor3[8]; bottom[1] = hor3[5]; bottom[0] = hor3[2];
            hor3[8] = temp[0]; hor3[5] = temp[1]; hor3[2] = temp[2];
            //rotate a layer
            temp[0] = hor0[0]; temp[1] = hor0[1]; temp[2] = hor0[2];
            temp[3] = hor0[3]; temp[4] = hor0[4]; temp[5] = hor0[5];
            temp[6] = hor0[6]; temp[7] = hor0[7]; temp[8] = hor0[8];
            hor0[0] = temp[2]; hor0[3] = temp[1];
            hor0[6] = temp[0]; hor0[7] = temp[3];
            hor0[8] = temp[6]; hor0[5] = temp[7];
            hor0[2] = temp[8]; hor0[1] = temp[5];
            break;
        case 2: //y = -1
            temp[0] = top[6]; temp[1] = top[3]; temp[2] = top[0];
            top[6] = hor2[2]; top[3] = hor2[5]; top[0] = hor2[8];
            hor2[2] = bottom[6]; hor2[5] = bottom[3]; hor2[8] = bottom[0];
            bottom[6] = hor0[6]; bottom[3] = hor0[3]; bottom[0] = hor0[0];
            hor0[6] = temp[0]; hor0[3] = temp[1]; hor0[0] = temp[2];
            //rotate a layer
            temp[0] = hor3[0]; temp[1] = hor3[1]; temp[2] = hor3[2];
            temp[3] = hor3[3]; temp[4] = hor3[4]; temp[5] = hor3[5];
            temp[6] = hor3[6]; temp[7] = hor3[7]; temp[8] = hor3[8];
            hor3[0] = temp[6]; hor3[3] = temp[7];
            hor3[6] = temp[8]; hor3[7] = temp[5];
            hor3[8] = temp[2]; hor3[5] = temp[1];
            hor3[2] = temp[0]; hor3[1] = temp[3];
            break;
        case 3: //y = 1
            temp[0] = top[8]; temp[1] = top[5]; temp[2] = top[2];
            top[8] = hor2[0]; top[5] = hor2[3]; top[2] = hor2[6];
            hor2[0] = bottom[8]; hor2[3] = bottom[5]; hor2[6] = bottom[2];
            bottom[8] = hor0[8]; bottom[5] = hor0[5]; bottom[2] = hor0[2];
            hor0[8] = temp[0]; hor0[5] = temp[1]; hor0[2] = temp[2];
            //rotate a layer
            temp[0] = hor1[0]; temp[1] = hor1[1]; temp[2] = hor1[2];
            temp[3] = hor1[3]; temp[4] = hor1[4]; temp[5] = hor1[5];
            temp[6] = hor1[6]; temp[7] = hor1[7]; temp[8] = hor1[8];
            hor1[0] = temp[2]; hor1[3] = temp[1];
            hor1[6] = temp[0]; hor1[7] = temp[3];
            hor1[8] = temp[6]; hor1[5] = temp[7];
            hor1[2] = temp[8]; hor1[1] = temp[5];
            break;
        case 4: //z = -1
            temp[0] = hor0[8]; temp[1] = hor0[7]; temp[2] = hor0[6];
            hor0[8] = hor3[8]; hor0[7] = hor3[7]; hor0[6] = hor3[6];
            hor3[8] = hor2[8]; hor3[7] = hor2[7]; hor3[6] = hor2[6];
            hor2[8] = hor1[8]; hor2[7] = hor1[7]; hor2[6] = hor1[6];
            hor1[8] = temp[0]; hor1[7] = temp[1]; hor1[6] = temp[2];
            //rotate a layer
            temp[0] = bottom[0]; temp[1] = bottom[1]; temp[2] = bottom[2];
            temp[3] = bottom[3]; temp[4] = bottom[4]; temp[5] = bottom[5];
            temp[6] = bottom[6]; temp[7] = bottom[7]; temp[8] = bottom[8];
            bottom[0] = temp[6]; bottom[3] = temp[7];
            bottom[6] = temp[8]; bottom[7] = temp[5];
            bottom[8] = temp[2]; bottom[5] = temp[1];
            bottom[2] = temp[0]; bottom[1] = temp[3];
            break;
        case 5: //z = 1
            temp[0] = hor0[2]; temp[1] = hor0[1]; temp[2] = hor0[0];
            hor0[2] = hor3[2]; hor0[1] = hor3[1]; hor0[0] = hor3[0];
            hor3[2] = hor2[2]; hor3[1] = hor2[1]; hor3[0] = hor2[0];
            hor2[2] = hor1[2]; hor2[1] = hor1[1]; hor2[0] = hor1[0];
            hor1[2] = temp[0]; hor1[1] = temp[1]; hor1[0] = temp[2];
            //rotate a layer
            temp[0] = top[0]; temp[1] = top[1]; temp[2] = top[2];
            temp[3] = top[3]; temp[4] = top[4]; temp[5] = top[5];
            temp[6] = top[6]; temp[7] = top[7]; temp[8] = top[8];
            top[0] = temp[2]; top[3] = temp[1];
            top[6] = temp[0]; top[7] = temp[3];
            top[8] = temp[6]; top[5] = temp[7];
            top[2] = temp[8]; top[1] = temp[5];
            break;
        default:
            break;
    }
}

void print_cube(void)
{
    int i;

    printf("Top layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%c", top[i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
    printf("Horizon0 layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%c", hor0[i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
    printf("Horizon1 layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%c", hor1[i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
    printf("Horizon2 layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%c", hor2[i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
    printf("Horizon3 layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%c", hor3[i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
    printf("Bottom layer:\n");
    for(i = 0; i < 9; i ++) {
        printf("%c", bottom[i]);
        if((i % 3) == 2)
            printf("\n");
        else
            printf(" ");
    }
}

int main(void)
{
    unsigned char c0, c1, c2;
    FILE *cube_start;
    int i;

    printf("Search for Rubik's cube.\n");

    cube_start = fopen("start.txt", "r");
    for(i = 0; i < 3; i ++) {
        fscanf(cube_start, "%c %c %c\n", &c0, &c1, &c2);
        top[i * 3] = c0;
        top[i * 3 + 1] = c1;
        top[i * 3 + 2] = c2;
    }
    fscanf(cube_start, "\n");
    for(i = 0; i < 3; i ++) {
        fscanf(cube_start, "%c %c %c\n", &c0, &c1, &c2);
        hor0[i * 3] = c0;
        hor0[i * 3 + 1] = c1;
        hor0[i * 3 + 2] = c2;
    }
    fscanf(cube_start, "\n");
    for(i = 0; i < 3; i ++) {
        fscanf(cube_start, "%c %c %c\n", &c0, &c1, &c2);
        hor1[i * 3] = c0;
        hor1[i * 3 + 1] = c1;
        hor1[i * 3 + 2] = c2;
    }
    fscanf(cube_start, "\n");
    for(i = 0; i < 3; i ++) {
        fscanf(cube_start, "%c %c %c\n", &c0, &c1, &c2);
        hor2[i * 3] = c0;
        hor2[i * 3 + 1] = c1;
        hor2[i * 3 + 2] = c2;
    }
    fscanf(cube_start, "\n");
    for(i = 0; i < 3; i ++) {
        fscanf(cube_start, "%c %c %c\n", &c0, &c1, &c2);
        hor3[i * 3] = c0;
        hor3[i * 3 + 1] = c1;
        hor3[i * 3 + 2] = c2;
    }
    fscanf(cube_start, "\n");
    for(i = 0; i < 3; i ++) {
        fscanf(cube_start, "%c %c %c\n", &c0, &c1, &c2);
        bottom[i * 3] = c0;
        bottom[i * 3 + 1] = c1;
        bottom[i * 3 + 2] = c2;
    }

    print_cube();
    rotate(4);
    rotate(5);
    print_cube();

    fclose(cube_start);
    return 0;
}

