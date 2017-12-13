#! /usr/bin/ruby -w

print("Gauss elimination with maximal column pivoting algorithm for linear equations.\n");

# the lowest limit
ZERO = 1e-8;
# linear equations: AX = B
# equation count
N = 3;
# x count
M = 3;

mat_A = [[1, 1, 1],
         [1, -1, 1],
         [1, -1, 0]];
mat_B = [1, 1, 0];

# [row, col]: the left-upper element of the sub-matrix which needs to be eliminated
row = 0;
col = 0;
while(row < N)
    max_index = row;
    max = mat_A[row][col].abs;
    (N - row).times {|i|
        if(mat_A[i + row][col].abs > max)
            max = mat_A[i + row][col];
            max_index = i;
        end
    }
    if(max_index != row)
        ratio = mat_A[max_index][col];
        M.times {|j|
            temp = mat_A[row][j];
            mat_A[row][j] = mat_A[max_index][j];
            mat_A[max_index][j] = temp;
        }
    end
    row += 1;
end

print mat_A, "\n";
print mat_B, "\n";
