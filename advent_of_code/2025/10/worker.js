const { parentPort, workerData } = require('worker_threads');

const lines = workerData.lines;
let ans = 0;

for (let i = 0; i < lines.length; i++) {
    const line = lines[i];
    if (line.length === 0) continue;

    const strInBracket = line.match(/\[(.*?)\]/)?.[1];
    const strInParents = [...line.matchAll(/\((.*?)\)/g)].map(m => m[1]);
    const strInRoundBracket = line.match(/\{(.*?)\}/)?.[1];

    // Logic from original script, simplified logs or removed for performance/clarity in threaded env
    // console.log('bracket: ', strInBracket)
    // console.log('parent: ', strInParents)
    // console.log('round bracket: ', strInRoundBracket)

    if (!strInBracket || !strInRoundBracket) continue; // Basic safety

    const target = strInBracket.split('').map(e => e === '#' ? 1 : 0).join('');
    const switches = strInParents.map(str => str.split(',').map(Number));
    const junct = strInRoundBracket.split(',').map(Number);

    // console.log('target: ', target)
    // console.log('switches: ', switches)
    // console.log('junct: ', junct)

    let min = 1000000;
    const switchLength = switches.length;

    const dp = (pos = 0, res = 0) => {
        if (pos === switchLength) {
            if (junct.every(j => j === 0)) {
                if (res < min) {
                    // console.log('min: ', res)
                    min = res;
                }
                return res;
            }
            return;
        }
        const s = switches[pos];
        let t = 0;
        while (true) {
            // Optimization: checking bounds if necessary, but using original logic
            if (s.some(e => junct[e] < t)) return;
            s.map(e => junct[e] -= t);

            dp(pos + 1, res + t);

            s.map(e => junct[e] += t);
            t += 1;
        }
    }

    dp();
    if (min !== 1000000) {
        ans += min;
    }
}

parentPort.postMessage(ans);
