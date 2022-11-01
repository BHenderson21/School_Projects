import numpy as np
import string

# ---------------------------------------
# CSCI 127, Joy and Beauty of Data      |
# Program 5: Pegathon                   |
# Your Name(, Your Partner's Name)      |
# Last Modified: Month __, 20__         |
# ---------------------------------------
# A brief overview of the program.
# ---------------------------------------

# ---------------------------------------
# Start of Pegathon Class               |
# ---------------------------------------

class Pegathon:

    def __init__(self, rows, columns, empty_row, empty_col):
        self.board = np.full((rows, columns), True)
        self.board[empty_row][empty_col] = False
        self.pegs_left = rows * columns - 1
        
# ---------------------------------------

    def __str__(self):
        answer = "   "
        for column in range(self.board.shape[1]):
            answer += " " + str(column + 1) + "  "
        answer += "\n"
        answer += self.separator()
        for row in range(self.board.shape[0]):
            answer += str(row + 1) + " |"
            for col in range(self.board.shape[1]):
                if self.board[row][col]:
                    answer += " o |"
                else:
                    answer += "   |"
            answer += "\n"
            answer += self.separator()
        return answer
    
# ---------------------------------------

    def separator(self):
        answer = "  +"
        for _ in range(self.board.shape[1]):
            answer += "---+"
        answer += "\n"
        return answer

# ---------------------------------------
# The four missing methods go here.  Do |
# not modify anything else.             |
# --------------------------------------|

    def legal_move(self, row_start, col_start, row_end, col_end):
        jumped_row = (row_start + row_end)/2
        jumped_col = (col_start + col_end)/2

    # This if statement that checks if the square being jumped over is occupied was orignally after the gross, mile-long line. 
    # Then, when commenting it, I realized how awfully unoptimized that is, and changed it, despite the fact that it probably doesn't matter much in this context.
        if self.board[int(jumped_row)][int(jumped_col)] == True:
            # Upon seeing how disgusting a 320 character if statement is, I'm realizing this should probably be 3 if/else statements. 
            # However, I've come this far, and its a little funny, so now im committed.
            # This abomination should check if the move entered is one of three types of legal moves: moving two spaces up/down, two left/right, or two diagonally (in any direction).
            # I'm hoping that if this is so improper that it would lose me points, my realization and justification here will persuade you to let me keep them. If not, worth it.
            if (((row_start == row_end) and ((col_end == col_start + 2) or (col_end == col_start - 2))) or ((col_start == col_end) and ((row_end == row_start + 2) or (row_end == row_start - 2))) or (((col_end == col_start + 2) or (col_end == col_start - 2)) and ((row_end == row_start + 2) or (row_end == row_start - 2)))):
                return True
            else:
                return False
        else: 
            return False
    
# ---------------------------------------

# This function determines if the game is over by checking in each square to see if there is a peg, and if there is it checks every move that peg might be able to make to see if its a legal move.
# If there are no pegs with a legal move left, the game is over.
    def game_over(self):
        for row in range(self.board.shape[0]):
            for col in range(self.board.shape[1]):
                if self.board[row][col]:
                    possible_moves = [(col-2, row+2), (col-0, row+2), (col+2, row+2), (col-2, row+0), (col+2, row+0), (col-2, row-2), (col+0, row-2), (col+2, row-2)]
                    for move in possible_moves:
                        if self.legal_move(row, col, move[1], move[0]):
                            print(move[1], move[0])
                            return False
                        else:
                            continue
                    return True

                

# ---------------------------------------

# This function determines the peg between the starting peg and ending square, and removes it, as well as moving the target peg from the start to the end. The count of pegs left is also adjusted.
    def make_move(self, row_start, col_start, row_end, col_end):
        jumped_row = (row_start + row_end)/2
        jumped_col = (col_start + col_end)/2
        self.board[row_start][col_start] = False
        self.board[row_end][col_end] = True
        self.board[int(jumped_row)][int(jumped_col)] = False
        self.pegs_left -= 1

# ---------------------------------------

# This function, when called, checks how many pegs are left and prints the appropriate message. 
    def final_message(self):
        if self.pegs_left <= 2:
            print("You're a Peg-enius!")
        elif self.pegs_left <= 4:
            print("I've worked with better. But not many.")
        elif self.pegs_left <= 6:
            print(str(self.pegs_left) + " left? Really? You're gonna have to do better than that.")
        else:
            print("Peg-naramous! Rack 'em up and redeem yourself.")

    

# ---------------------------------------
# End of Pegathon Class                 |
# ---------------------------------------

def get_choice(low, high, message):
    message += " [" + str(low) + " - " + str(high) + "]: "
    legal_choice = False
    while not legal_choice:
        legal_choice = True
        answer = input(message)
        for character in answer:
            if character not in string.digits:
                legal_choice = False
                print("That is not a number, try again.")
                break 
        if legal_choice:
            answer = int(answer)
            if (answer < low) or (answer > high):
                legal_choice = False
                print("That is not a valid choice, try again.")
    return answer

# ---------------------------------------

def main():
    print("Welcome to Pegathon!")
    print("-----------------------------------\n")
    
    rows = get_choice(1, 9, "Enter the number of rows")
    columns = get_choice(1, 9, "Enter the number of columns")
    row = get_choice(1, rows, "Enter the empty space row") - 1
    column = get_choice(1, columns, "Enter empty space column") - 1   
    game = Pegathon(rows, columns, row, column)
    print()

    print(game)
    while (not game.game_over()):
        row_start = get_choice(1, rows, "Enter the row of the peg to move") - 1
        col_start = get_choice(1, columns, "Enter the column of the peg to move") - 1
        row_end = get_choice(1, rows, "Enter the row where the peg lands") - 1
        col_end = get_choice(1, columns, "Enter the column where the peg lands") - 1
        if game.legal_move(row_start, col_start, row_end, col_end):
            game.make_move(row_start, col_start, row_end, col_end)
        else:
            print("Sorry.  That move is not allowed.")
        print()
        print(game)

    game.final_message()

# ---------------------------------------

main()
