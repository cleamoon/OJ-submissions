function validStrings(n: number): string[] {
  let ans = ["0", "1"]
  for (let i = 0; i < n - 1; i++) {
      let tmp = []
      ans.forEach(e => {
          if (e[i] === "1") {
              tmp.push(`${e}0`)
          }
          tmp.push(`${e}1`)
      })
      ans = tmp;
  }
  return ans
};