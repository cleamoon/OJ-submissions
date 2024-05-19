let file = "input.txt"

let isDigit = function
  | '0'..'9' -> true
  | _ -> false

let stringToList str =
  List.init (String.length str) (String.get str)

let charOptionToInt = function
  | Some c -> int_of_char c - int_of_char '0'
  | None -> 0

let () =
  let sum = ref 0 in
  let ic = open_in file in
  try 
    while true do
      let line = input_line ic in
      let chlist = stringToList line in
      let firstDigit = List.find_opt isDigit chlist in
      let lastDigit = List.find_opt isDigit (List.rev chlist) in
      sum := !sum + (charOptionToInt  firstDigit) * 10 + (charOptionToInt lastDigit)
    done;
  with
  | End_of_file -> 
    string_of_int sum.contents |> print_endline;
    close_in ic
  | e -> 
    close_in_noerr ic; 
    raise e

