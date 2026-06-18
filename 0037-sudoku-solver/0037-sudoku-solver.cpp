// class Solution {
// public:

//     /*
//     =======================================================================
//                             SAFETY CHECK FUNCTION
//     =======================================================================

//     Is function ka kaam:

//         "Kya hum current cell (row,col) par
//          digit 'val' place kar sakte hain?"

//     Sudoku ke 3 rules hote hain:

//     1. Same row me same digit dobara nahi aa sakti
//     2. Same column me same digit dobara nahi aa sakti
//     3. Same 3x3 box me same digit dobara nahi aa sakti

//     Agar teeno conditions satisfy ho jaye:

//         return true

//     warna:

//         return false

//     Example:

//         5 3 . | . 7 . | . . .
//         6 . . | 1 9 5 | . . .
//         . 9 8 | . . . | . 6 .
//         ------+-------+------
//         8 . . | . 6 . | . . 3
//         4 . . | 8 . 3 | . . 1
//         7 . . | . 2 . | . . 6
//         ------+-------+------
//         . 6 . | . . . | 2 8 .
//         . . . | 4 1 9 | . . 5
//         . . . | . 8 . | . 7 9

//     Agar hum kisi cell me '5' place karna chahte hain,
//     to pehle check karenge ki row, column aur box me
//     pehle se '5' to nahi hai.
//     =======================================================================
//     */

//     bool is_safe(vector<vector<char>>& board,
//                  int row,
//                  int col,
//                  int n,
//                  char val)
//     {

//         /*
//         ---------------------------------------------------------------
//         RULE 1 : ROW CHECK
//         ---------------------------------------------------------------

//         Current row ko scan karo.

//         Example:

//             5 3 . . 7 . . . .

//         Agar hum phir se 5 place karne ki koshish karein:

//             5 3 . . 7 . . . 5

//         to Sudoku rule break ho jayega.

//         Isliye poori row check karni padegi.
//         */

//         for (int i = 0; i < n; i++) {

//             if (board[row][i] == val)
//                 return false;
//         }


//         /*
//         ---------------------------------------------------------------
//         RULE 2 : COLUMN CHECK
//         ---------------------------------------------------------------

//         Current column scan karo.

//         Example:

//             5
//             .
//             .
//             .
//             .
//             5

//         Same column me same digit allowed nahi hai.
//         */

//         for (int i = 0; i < n; i++) {

//             if (board[i][col] == val)
//                 return false;
//         }


//         /*
//         ---------------------------------------------------------------
//         RULE 3 : 3x3 BOX CHECK
//         ---------------------------------------------------------------

//         Sudoku board me total 9 boxes hote hain.

//             ---------------------
//             | Box | Box | Box |
//             ---------------------
//             | Box | Box | Box |
//             ---------------------
//             | Box | Box | Box |
//             ---------------------

//         Hume pehle pata karna hoga ki current cell
//         kis box ke andar hai.

//         Example:

//             row = 5
//             col = 7

//         row/3 = 1
//         col/3 = 2

//         startRow = 1*3 = 3
//         startCol = 2*3 = 6

//         Iska matlab:

//             Current box starts from

//                 (3,6)

//         aur end hoga

//                 (5,8)

//         Yahi poora 3x3 block scan karenge.
//         */

//         int startRow = (row / 3) * 3;
//         int startCol = (col / 3) * 3;


//         /*
//         Current 3x3 box ke har cell ko check karo.
//         */

//         for (int i = startRow; i < startRow + 3; i++) {

//             for (int j = startCol; j < startCol + 3; j++) {

//                 if (board[i][j] == val)
//                     return false;
//             }
//         }


//         /*
//         Agar yahan tak pahunch gaye:

//             row safe
//             column safe
//             box safe

//         To digit place ki ja sakti hai.
//         */

//         return true;
//     }



//     /*
//     =======================================================================
//                         BACKTRACKING FUNCTION
//     =======================================================================

//     Ye poore Sudoku solver ka HEART hai.

//     Approach:

//     STEP 1:
//         Koi empty cell dhoondo

//     STEP 2:
//         1 se 9 tak har digit try karo

//     STEP 3:
//         Agar safe hai to temporarily place karo

//     STEP 4:
//         Remaining board solve karne ki koshish karo

//     STEP 5:
//         Agar future me problem aa jaye,
//         to digit hata do (BACKTRACK)

//     Ye process recursively repeat hota rahega.
//     =======================================================================
//     */

//     bool sudoku(vector<vector<char>>& board, int n)
//     {

//         /*
//         ---------------------------------------------------------------
//         EMPTY CELL SEARCH
//         ---------------------------------------------------------------

//         Sudoku me next decision kya hoga?

//         Answer:

//             Next empty cell.

//         Isliye poora board scan karenge.

//         Jahan '.' milega,
//         wahi hamara current decision point hoga.
//         */

//         for (int row = 0; row < n; row++) {

//             for (int col = 0; col < n; col++) {

//                 /*
//                 Empty cell mil gaya.
//                 */

//                 if (board[row][col] == '.') {


//                     /*
//                     ---------------------------------------------------
//                     TRY ALL POSSIBLE DIGITS
//                     ---------------------------------------------------

//                     Sudoku me sirf 1-9 digits allowed hain.

//                     Har digit try karenge.

//                     Example:

//                         Try 1
//                         Try 2
//                         Try 3
//                         ...
//                         Try 9
//                     */

//                     for (char val = '1'; val <= '9'; val++) {


//                         /*
//                         Check karo:

//                         Kya current digit safe hai?
//                         */

//                         if (is_safe(board,
//                                     row,
//                                     col,
//                                     n,
//                                     val))
//                         {

//                             /*
//                             ==========================================
//                             STEP 1 : CHOOSE
//                             ==========================================

//                             Hum assume kar rahe hain ki
//                             ye digit solution ka part ho sakti hai.

//                             Isliye board me place kar do.
//                             */

//                             board[row][col] = val;


//                             /*
//                             ==========================================
//                             STEP 2 : EXPLORE
//                             ==========================================

//                             Ab remaining Sudoku solve karo.

//                             Agar future me complete board solve ho gaya
//                             to true return kar denge.
//                             */

//                             if (sudoku(board, n))
//                                 return true;


//                             /*
//                             ==========================================
//                             STEP 3 : UNDO
//                             ==========================================

//                             Agar recursion fail ho gaya.

//                             Matlab:

//                                 Ye digit galat choice thi.

//                             To board ko wapas original state me lao.

//                             Isi process ko BACKTRACKING kehte hain.
//                             */

//                             board[row][col] = '.';
//                         }
//                     }


//                     /*
//                     ---------------------------------------------------
//                     IMPORTANT CASE
//                     ---------------------------------------------------

//                     Humne 1 se 9 tak sab try kar liya.

//                     Koi bhi digit fit nahi hui.

//                     Matlab:

//                         Current path impossible hai.

//                     Previous recursive call ko bata do:

//                         "Bhai galat direction me aa gaye."

//                     Return false.
//                     */

//                     return false;
//                 }
//             }
//         }


//         /*
//         ---------------------------------------------------------------
//         BASE CASE
//         ---------------------------------------------------------------

//         Agar poora board scan ho gaya
//         aur ek bhi '.' nahi mila.

//         Matlab:

//             Sare cells fill ho chuke hain.

//         Aur kyunki har placement safe thi,

//         Sudoku successfully solve ho gaya.

//         Return true.
//         */

//         return true;
//     }



//     /*
//     =======================================================================
//                             DRIVER FUNCTION
//     =======================================================================

//     LeetCode isi function ko call karta hai.

//     Iska kaam:

//         1. Board receive karna
//         2. Sudoku solver start karna

//     Final solved board automatically
//     original board me update ho jayega.

//     Kyun?

//     Kyunki board reference (&) se pass ho raha hai.
//     =======================================================================
//     */

//     void solveSudoku(vector<vector<char>>& board)
//     {
//         int n = 9;

//         /*
//         Backtracking process start.
//         */

//         sudoku(board, n);
//     }
// };

class Solution {
public:
    bool is_safe(vector<vector<char>>& board, int row, int col, int n, char val) {
        for (int i = 0; i < n; i++) {
            if (board[row][i] == val)
                return false;
        }

        for (int i = 0; i < n; i++) {
            if (board[i][col] == val)
                return false;
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == val)
                    return false;
            }
        }

        return true;
    }

    bool sudoku(vector<vector<char>>& board, int n) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (is_safe(board, row, col, n, val)) {
                            board[row][col] = val;

                            if (sudoku(board, n))
                                return true;

                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n = 9;
        sudoku(board, n);
    }
};