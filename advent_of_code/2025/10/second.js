const fs = require('node:fs')
const { Worker } = require('worker_threads')
const path = require('path')

const input = fs.readFileSync('./input.txt', 'utf8')
const allLines = input.split('\n')

// Remove trailing empty lines or handle them gently
const lines = allLines.filter(l => l.length > 0)

const numThreads = 8
const chunkSize = Math.ceil(lines.length / numThreads)
const workers = []

let completedWorkers = 0
let totalAns = 0

console.log(`Starting processing with ${numThreads} threads for ${lines.length} lines.`)

for (let i = 0; i < numThreads; i++) {
  const start = i * chunkSize
  const end = Math.min((i + 1) * chunkSize, lines.length)
  const chunk = lines.slice(start, end)

  if (chunk.length === 0) continue

  const worker = new Worker(path.resolve(__dirname, './worker.js'), {
    workerData: {
      lines: chunk
    }
  })

  workers.push(worker)

  worker.on('message', (msg) => {
    // console.log(`Worker ${i} finished with result: ${msg}`)
    totalAns += msg
  })

  worker.on('error', (err) => {
    console.error(`Worker ${i} error:`, err)
  })

  worker.on('exit', (code) => {
    if (code !== 0)
      console.error(new Error(`Worker ${i} stopped with exit code ${code}`))

    completedWorkers++
    if (completedWorkers === workers.length) {
      console.log(totalAns)
    }
  })
}