#include    <stdio.h>
#include    "cube_rotate.c"

unsigned char record[64 * 32];   //as cube data
unsigned char stack_rotate[32];   //stack to save 6-branch searching tree
int depth_limit = 12; //stack status and limit
int sp = 0; //stack top pointer

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
    int error = 0;

    for(i = 0; i < 6 * 9; i ++)
        if(cube1[i] != cube2[i]){
            printf("Error on %d!\n", i);
            error ++;
        }
    if(error == 0)
        return 1;
    else
        return 0;
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
    for(i = 0; i < 64; i ++)
        record[i] = i;
    rotate(5, record, record + 64);
    rotate(5, record + 64, record + 128);
    rotate(5, record + 128, record + 192);
    print_cube(record + 192);

    rotate(11, record, record + 256);
    if(cube_equal(record + 192, record + 256))
        printf("rotate equal\n");

    return 0;
}

