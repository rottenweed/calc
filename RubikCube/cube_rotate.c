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
        case 6: //x = -1
            for(i = 0; i < 6 * 9; i ++)
                cube_out[i] = cube_in[i];
            cube_out[0 * 9 + 0] = cube_in[4 * 9 + 6];
            cube_out[0 * 9 + 1] = cube_in[4 * 9 + 3];
            cube_out[0 * 9 + 2] = cube_in[4 * 9 + 0];
            cube_out[2 * 9 + 2] = cube_in[0 * 9 + 0];
            cube_out[2 * 9 + 5] = cube_in[0 * 9 + 1];
            cube_out[2 * 9 + 8] = cube_in[0 * 9 + 2];
            cube_out[5 * 9 + 8] = cube_in[2 * 9 + 2];
            cube_out[5 * 9 + 7] = cube_in[2 * 9 + 5];
            cube_out[5 * 9 + 6] = cube_in[2 * 9 + 8];
            cube_out[4 * 9 + 6] = cube_in[5 * 9 + 8];
            cube_out[4 * 9 + 3] = cube_in[5 * 9 + 7];
            cube_out[4 * 9 + 0] = cube_in[5 * 9 + 6];
            //rotate a layer
            cube_out[3 * 9 + 0] = cube_in[3 * 9 + 2];
            cube_out[3 * 9 + 3] = cube_in[3 * 9 + 1];
            cube_out[3 * 9 + 6] = cube_in[3 * 9 + 0];
            cube_out[3 * 9 + 7] = cube_in[3 * 9 + 3];
            cube_out[3 * 9 + 8] = cube_in[3 * 9 + 6];
            cube_out[3 * 9 + 5] = cube_in[3 * 9 + 7];
            cube_out[3 * 9 + 2] = cube_in[3 * 9 + 8];
            cube_out[3 * 9 + 1] = cube_in[3 * 9 + 5];
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
        case 7: //x = 1
            for(i = 0; i < 6 * 9; i ++)
                cube_out[i] = cube_in[i];
            cube_out[0 * 9 + 6] = cube_in[4 * 9 + 8];
            cube_out[0 * 9 + 7] = cube_in[4 * 9 + 5];
            cube_out[0 * 9 + 8] = cube_in[4 * 9 + 2];
            cube_out[2 * 9 + 0] = cube_in[0 * 9 + 6];
            cube_out[2 * 9 + 3] = cube_in[0 * 9 + 7];
            cube_out[2 * 9 + 6] = cube_in[0 * 9 + 8];
            cube_out[5 * 9 + 2] = cube_in[2 * 9 + 0];
            cube_out[5 * 9 + 1] = cube_in[2 * 9 + 3];
            cube_out[5 * 9 + 0] = cube_in[2 * 9 + 6];
            cube_out[4 * 9 + 8] = cube_in[5 * 9 + 2];
            cube_out[4 * 9 + 5] = cube_in[5 * 9 + 1];
            cube_out[4 * 9 + 2] = cube_in[5 * 9 + 0];
            //rotate a layer
            cube_out[1 * 9 + 0] = cube_in[1 * 9 + 6];
            cube_out[1 * 9 + 3] = cube_in[1 * 9 + 7];
            cube_out[1 * 9 + 6] = cube_in[1 * 9 + 8];
            cube_out[1 * 9 + 7] = cube_in[1 * 9 + 5];
            cube_out[1 * 9 + 8] = cube_in[1 * 9 + 2];
            cube_out[1 * 9 + 5] = cube_in[1 * 9 + 1];
            cube_out[1 * 9 + 2] = cube_in[1 * 9 + 0];
            cube_out[1 * 9 + 1] = cube_in[1 * 9 + 3];
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
        case 8: //y = -1
            for(i = 0; i < 6 * 9; i ++)
                cube_out[i] = cube_in[i];
            cube_out[0 * 9 + 6] = cube_in[1 * 9 + 6];
            cube_out[0 * 9 + 3] = cube_in[1 * 9 + 3];
            cube_out[0 * 9 + 0] = cube_in[1 * 9 + 0];
            cube_out[3 * 9 + 2] = cube_in[0 * 9 + 6];
            cube_out[3 * 9 + 5] = cube_in[0 * 9 + 3];
            cube_out[3 * 9 + 8] = cube_in[0 * 9 + 0];
            cube_out[5 * 9 + 6] = cube_in[3 * 9 + 2];
            cube_out[5 * 9 + 3] = cube_in[3 * 9 + 5];
            cube_out[5 * 9 + 0] = cube_in[3 * 9 + 8];
            cube_out[1 * 9 + 6] = cube_in[5 * 9 + 6];
            cube_out[1 * 9 + 3] = cube_in[5 * 9 + 3];
            cube_out[1 * 9 + 0] = cube_in[5 * 9 + 0];
            //rotate a layer
            cube_out[4 * 9 + 0] = cube_in[4 * 9 + 2];
            cube_out[4 * 9 + 3] = cube_in[4 * 9 + 1];
            cube_out[4 * 9 + 6] = cube_in[4 * 9 + 0];
            cube_out[4 * 9 + 7] = cube_in[4 * 9 + 3];
            cube_out[4 * 9 + 8] = cube_in[4 * 9 + 6];
            cube_out[4 * 9 + 5] = cube_in[4 * 9 + 7];
            cube_out[4 * 9 + 2] = cube_in[4 * 9 + 8];
            cube_out[4 * 9 + 1] = cube_in[4 * 9 + 5];
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
        case 9: //y = 1
            for(i = 0; i < 6 * 9; i ++)
                cube_out[i] = cube_in[i];
            cube_out[0 * 9 + 8] = cube_in[1 * 9 + 8];
            cube_out[0 * 9 + 5] = cube_in[1 * 9 + 5];
            cube_out[0 * 9 + 2] = cube_in[1 * 9 + 2];
            cube_out[3 * 9 + 0] = cube_in[0 * 9 + 8];
            cube_out[3 * 9 + 3] = cube_in[0 * 9 + 5];
            cube_out[3 * 9 + 6] = cube_in[0 * 9 + 2];
            cube_out[5 * 9 + 8] = cube_in[3 * 9 + 0];
            cube_out[5 * 9 + 5] = cube_in[3 * 9 + 3];
            cube_out[5 * 9 + 2] = cube_in[3 * 9 + 6];
            cube_out[1 * 9 + 8] = cube_in[5 * 9 + 8];
            cube_out[1 * 9 + 5] = cube_in[5 * 9 + 5];
            cube_out[1 * 9 + 2] = cube_in[5 * 9 + 2];
            //rotate a layer
            cube_out[2 * 9 + 0] = cube_in[2 * 9 + 6];
            cube_out[2 * 9 + 3] = cube_in[2 * 9 + 7];
            cube_out[2 * 9 + 6] = cube_in[2 * 9 + 8];
            cube_out[2 * 9 + 7] = cube_in[2 * 9 + 5];
            cube_out[2 * 9 + 8] = cube_in[2 * 9 + 2];
            cube_out[2 * 9 + 5] = cube_in[2 * 9 + 1];
            cube_out[2 * 9 + 2] = cube_in[2 * 9 + 0];
            cube_out[2 * 9 + 1] = cube_in[2 * 9 + 3];
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
        case 10: //z = -1
            for(i = 0; i < 6 * 9; i ++)
                cube_out[i] = cube_in[i];
            cube_out[1 * 9 + 8] = cube_in[2 * 9 + 8];
            cube_out[1 * 9 + 7] = cube_in[2 * 9 + 7];
            cube_out[1 * 9 + 6] = cube_in[2 * 9 + 6];
            cube_out[4 * 9 + 8] = cube_in[1 * 9 + 8];
            cube_out[4 * 9 + 7] = cube_in[1 * 9 + 7];
            cube_out[4 * 9 + 6] = cube_in[1 * 9 + 6];
            cube_out[3 * 9 + 8] = cube_in[4 * 9 + 8];
            cube_out[3 * 9 + 7] = cube_in[4 * 9 + 7];
            cube_out[3 * 9 + 6] = cube_in[4 * 9 + 6];
            cube_out[2 * 9 + 8] = cube_in[3 * 9 + 8];
            cube_out[2 * 9 + 7] = cube_in[3 * 9 + 7];
            cube_out[2 * 9 + 6] = cube_in[3 * 9 + 6];
            //rotate a layer
            cube_out[5 * 9 + 0] = cube_in[5 * 9 + 2];
            cube_out[5 * 9 + 3] = cube_in[5 * 9 + 1];
            cube_out[5 * 9 + 6] = cube_in[5 * 9 + 0];
            cube_out[5 * 9 + 7] = cube_in[5 * 9 + 3];
            cube_out[5 * 9 + 8] = cube_in[5 * 9 + 6];
            cube_out[5 * 9 + 5] = cube_in[5 * 9 + 7];
            cube_out[5 * 9 + 2] = cube_in[5 * 9 + 8];
            cube_out[5 * 9 + 1] = cube_in[5 * 9 + 5];
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
        case 11: //z = 1
            for(i = 0; i < 6 * 9; i ++)
                cube_out[i] = cube_in[i];
            cube_out[1 * 9 + 2] = cube_in[2 * 9 + 2];
            cube_out[1 * 9 + 1] = cube_in[2 * 9 + 1];
            cube_out[1 * 9 + 0] = cube_in[2 * 9 + 0];
            cube_out[4 * 9 + 2] = cube_in[1 * 9 + 2];
            cube_out[4 * 9 + 1] = cube_in[1 * 9 + 1];
            cube_out[4 * 9 + 0] = cube_in[1 * 9 + 0];
            cube_out[3 * 9 + 2] = cube_in[4 * 9 + 2];
            cube_out[3 * 9 + 1] = cube_in[4 * 9 + 1];
            cube_out[3 * 9 + 0] = cube_in[4 * 9 + 0];
            cube_out[2 * 9 + 2] = cube_in[3 * 9 + 2];
            cube_out[2 * 9 + 1] = cube_in[3 * 9 + 1];
            cube_out[2 * 9 + 0] = cube_in[3 * 9 + 0];
            //rotate a layer
            cube_out[0 * 9 + 0] = cube_in[0 * 9 + 6];
            cube_out[0 * 9 + 3] = cube_in[0 * 9 + 7];
            cube_out[0 * 9 + 6] = cube_in[0 * 9 + 8];
            cube_out[0 * 9 + 7] = cube_in[0 * 9 + 5];
            cube_out[0 * 9 + 8] = cube_in[0 * 9 + 2];
            cube_out[0 * 9 + 5] = cube_in[0 * 9 + 1];
            cube_out[0 * 9 + 2] = cube_in[0 * 9 + 0];
            cube_out[0 * 9 + 1] = cube_in[0 * 9 + 3];
            break;
        default:
            break;
    }
}

