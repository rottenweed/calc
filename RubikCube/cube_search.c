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
    unsigned char temp[3];
    switch(rotate_type) {
        case 0: //x = -1
            temp[0] = top[0]; temp[1] = top[1]; temp[2] = top[2];
            top[0] = hor1[2]; top[1] = hor1[5]; top[2] = hor1[8];
            hor1[2] = bottom[8]; hor1[5] = bottom[7]; hor1[8] = bottom[6];
            bottom[8] = hor3[6]; bottom[7] = hor3[3]; bottom[6] = hor3[0];
            hor3[6] = temp[0]; hor3[3] = temp[1]; hor3[0] = temp[2];
            break;
        case 1: //x = 1
            temp[0] = top[6]; temp[1] = top[7]; temp[2] = top[8];
            top[6] = hor1[0]; top[7] = hor1[3]; top[8] = hor1[6];
            hor1[0] = bottom[2]; hor1[3] = bottom[1]; hor1[6] = bottom[0];
            bottom[2] = hor3[8]; bottom[1] = hor3[5]; bottom[0] = hor3[2];
            hor3[8] = temp[0]; hor3[5] = temp[1]; hor3[2] = temp[2];
            break;
        case 2: //y = -1
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
    printf("Search for Rubik's cube.\n");

    rotate(1);
    print_cube();

    return 0;
}

