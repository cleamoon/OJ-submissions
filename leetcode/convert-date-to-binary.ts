function conv(str: string): string {
    let num = parseInt(str);
    let bin: number[] = []
    while(num != 0) {
        bin.push(num % 2);
        num = Math.floor(num / 2);
    }
    bin = bin.reverse();
    return bin.join('')
}

function convertDateToBinary(date: string): string {
    const parts = date.split('-');
    const ret = conv(parts[0]) + '-' + conv(parts[1]) + '-' + conv(parts[2])
    return ret
};