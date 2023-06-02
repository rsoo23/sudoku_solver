# Sudoku Solver

This problem is from the 42 school piscine rush01 (old version). This project includes the use of a backtracking algorithm that solves a grid of an unsolved sudoku puzzle.
 
Version 1: Recursion<br />
Version 2: Iteration + Recursion (Not Norm Friendly: >25 lines in one function)<br />
Version 3: Iteration (Optimized: no recursion, all functions <25 lines, no memory leaks)<br />

## How to use:
1. Clone the repository
```bash
git clone https://github.com/rsoo23/sudoku_solver.git sudoku_solver
```
2. Make the executable
```bash
make
```
3. Input the arguments (. represents empty spaces) (format: 9 strings with 9 characters each)
```bash
./solver "" "" ...
```
## Examples (By Difficulty)
Sources: <br />
    - easy to evil from: https://sudoku.com<br />
    - highest rated, not fun from: https://sandiway.arizona.edu/sudoku/examples.html
1. Easy:
```
./solver "2..69.8.1" ".....36.." ".138.254." "7.5.8.396" "83.4....." "1.6..5..." "37.9.6.1." ".291.8..." "56.3...2."
```
2. Medium:
```
./solver ".3567...." "4..8295.." ".8...3.6." ".2...58.7" "8..2.6..5" "3.17...2." ".4.9...7." "..2487..6" "....5249."
```
3. Hard:
```
./solver ".1.7....." "..2....78" ".34....61" ".....29.." "....3125." "...5..6.." "9.6..7..2" ".7......." ".28.9...."
```
4. Expert:
```
./solver "3.......7" "918......" "6.....5.3" ".....5.42" ".8...6..." "..4.3...." "...91..3." "......1.." "..68..9.."
```
5. Evil:
```
./solver "..53...2." "9..4..1.5" "....1..7." ".......1." ".8.9....." "..7.4.6.3" "..3.6.5.4" "........2" "7....3..."
```
6. Not fun:
```
./solver ".2......." "...6....3" ".74.8...." ".....3..2" ".8..4..1." "6..5....." "....1.78." "5....9..." ".......4."
```
7. Highest rated:
```
./solver "...6..4.." "7....36.." "....91.8." "........." ".5.18...3" "...3.6.45" ".4.2...6." "9.3......" ".2....1.."
```
8. Random:
```
./solver "9........" "........." "........." "........." "........." "........." "........." "........." "........9"
```

## Results:
Definition of passed: produces a grid that adhere to the rules of sudoku

|Sudoku Difficulty | Ver 1     | Ver 2  | Ver 3  |
|------------------|-----------|--------|--------|
| easy             | passed    | passed | passed |
| medium           | passed    | passed | passed |
| hard             | passed    | passed | passed |
| expert           | passed    | passed | passed |
| evil             | seg fault | passed | passed |
| not fun          | seg fault | passed | passed |
| highest rated    | seg fault | passed | passed |
| random           | passed    | passed | passed |
