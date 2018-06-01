#! /usr/bin/ruby -w

print("Gauss elimination with maximal column pivoting algorithm for linear equations.\n");

# Use Matrix lib
require "matrix"
# add method []= to class Matrix.
# modify an assigned element.
class Matrix
    def []=(i, j, x)
        @rows[i][j] = x;
    end
end

# the lowest limit
ZERO_LIMIT = 1e-8;
# linear equations: AX = B
# equation count
N = 4;
# x count
M = 4;

mat_A = Matrix[
    [1, 0, 2, 1],
    [0, 4, 0, -1],
    [2, 0, 4, 1],
    [1, -1, 1, 0]];
mat_B = Matrix.column_vector([1, 1, 1, 0]);

# [row, col]: the left-upper element of the sub-matrix which needs to be eliminated
row = 0;
col = 0;
while((row < N) && (col < M))
    # select the maximum in the column
    max_index = row;
    max = mat_A[row, col].abs;
    row.upto(N - 1) {|i|
        if(mat_A[i, col].abs > max)
            max = mat_A[i, col].abs;
            max_index = i;
        end
    }
    # check the column, clear if the total parameter column are zero
    if(max < ZERO_LIMIT)
        row.upto(N - 1) {|i|
            mat_A[i, col] = 0;
        }
    # elimination of the sub matrix
    else
        ratio = 1.0 / mat_A[max_index, col];
        # adjust the max head value to 1
        mat_A[max_index, col] = 1.0;
        (col + 1).upto(M - 1) {|j|
            mat_A[max_index, j] *= ratio;
        }
        mat_B[max_index, 0] *= ratio;
        if(max_index != row)
            # swap the line to the first
            M.times {|j|
                temp = mat_A[row, j];
                mat_A[row, j] = mat_A[max_index, j];
                mat_A[max_index, j] = temp;
            }
            temp = mat_B[row, 0];
            mat_B[row, 0] = mat_B[max_index, 0];
            mat_B[max_index, 0] = temp;
        end
        # clear head elements of all the following lines
        (row + 1).upto(N - 1) {|i|
            ratio = mat_A[i, col];
            mat_A[i, col] = 0.0;
            # sub the line
            (col + 1).upto(M - 1) {|j|
                mat_A[i, j] -= mat_A[row, j] * ratio;
            }
            mat_B[i, 0] -= mat_B[row, 0] * ratio;
        }
        row += 1;
    end
    col += 1;
end

N.times {|i|
    print("#{mat_A.row(i)} = #{mat_B[i, 0]}, \n");
}
