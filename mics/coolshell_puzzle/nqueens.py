from hashlib import sha1

PASSWORD = "zWp8LGn01wxJ7"
TARGET_KEY = "e48d316ed573d3273931e19f9ac9f9e6039a4242"

solutions = []


def nine_queens_solutions(board_arr=[], row=0):
    if row == 9:
        solutions.append(board_arr)
        return
    for col in range(9):
        if is_valid(board_arr, row, col):
            new_board_arr = board_arr.copy()
            new_board_arr.append(col)
            solutions_for_row = nine_queens_solutions(new_board_arr, row + 1)
            if solutions_for_row:
                return solutions_for_row
    return None


def is_valid(board_arr, row, col):
    for i in range(row):
        if board_arr[i] == col or abs(board_arr[i] - col) == abs(i - row):
            return False
    return True


nine_queens_solutions()

nq_sol_strings = ["".join(str(c + 1) for c in sol) for sol in solutions]

for s in nq_sol_strings:
    key = sha1((PASSWORD + s + "\n").encode()).hexdigest()
    if key == TARGET_KEY:
        print(s)
        break
