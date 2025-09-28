function stringToNumberList(str: string): number[] {
  return str.split('.').map(s => Number(s))
}

function compareVersion(version1: string, version2: string): number {
  const number_l1 = stringToNumberList(version1)
  const number_l2 = stringToNumberList(version2)
  const l1 = number_l1.length
  const l2 = number_l2.length
  if (l1 > l2) {
      for(let i = 0; i < l1 - l2; i++) {
          number_l2.push(0)
      }
  }
  if (l1 < l2) {
      for(let i = 0; i < l2 - l1; i++) {
          number_l1.push(0)
      }
  }
  for(let i = 0; i < Math.max(l1, l2); i++) {
      const n1 = number_l1[i]
      const n2 = number_l2[i]
      if (n1 > n2) return 1
      else if (n1 < n2) return -1
  }
  return 0;
};