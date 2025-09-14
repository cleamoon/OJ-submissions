function maxFreqSum(s: string): number {
  const VOWEL = ['a', 'e', 'i', 'o', 'u']
  const mapV = {}
  const mapC = {}
  let maxV = 0
  let maxC = 0
  s.split('').forEach(c => {
      if (VOWEL.includes(c)) {
          if (mapV[c]) mapV[c] += 1
          else mapV[c] = 1
          maxV = maxV > mapV[c] ? maxV : mapV[c]
      } else {
          if (mapC[c]) mapC[c] += 1
          else mapC[c] = 1
          maxC = maxC > mapC[c] ? maxC : mapC[c]
      }
  })
  return maxV + maxC
};