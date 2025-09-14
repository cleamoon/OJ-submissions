function earliestTime(tasks: number[][]): number {
  let min = Infinity
  tasks.forEach((t) => {
      const time = t[0] + t[1]
      min = min < time ? min : time
  })
  return min
};