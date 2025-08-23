const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

const times = []
const distances = []