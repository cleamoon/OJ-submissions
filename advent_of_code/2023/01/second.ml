let file = "input.txt"

exception Found of int

let () =
  let sum = ref 0 in
  let ic = open_in file in
  let words = [| "zero"; "one"; "two"; "three"; "four"; "five"; "six"; "seven"; "eight"; "nine" |] in
  let digits = [| "0"; "1"; "2"; "3"; "4"; "5"; "6"; "7"; "8"; "9" |] in
  try 
    while true do
      let line = input_line ic in
      let line_length = String.length line in
      try
        for j = 0 to line_length do
          for i = 0 to 9 do
            let word = words.(i) in
            let word_length = String.length word in
            if word_length + j < line_length && String.sub line j word_length = word then
              raise (Found i)
            done;
          for i = 0 to 9 do
            let digit = digits.(i) in
            if String.sub line j 1 = digit then
              raise (Found i)
          done;
        done;
      with 
      | Found i -> sum := !sum + i * 10;

      try
        for j = line_length downto 0 do
          for i = 0 to 9 do
            let word = words.(i) in
            let word_length = String.length word in
            if j - word_length >= 0 && String.sub line (j - word_length) word_length = word then
              raise (Found i)
          done;
          for i = 0 to 9 do
            let digit = digits.(i) in
            if j >= 0 && String.sub line (j - 1) 1 = digit then
              raise (Found i)
          done;
        done;
      with
      | Found i -> sum := !sum + i;

    done;
  with
  | End_of_file -> 
    string_of_int sum.contents |> print_endline;
    close_in ic
  | e -> 
    close_in_noerr ic; 
    raise e

