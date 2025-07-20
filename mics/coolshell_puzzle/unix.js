const sub = "pvwdgazxubqfsnrhocitlkeymj"

const ori = 'Wxgcg txgcg ui p ixgff, txgcg ui p epm. I gyhgwt mrl lig txg ixgff wrsspnd tr irfkg txui hcrvfgs, nre, hfgpig tcm liunz txg crt13 ra "ixgff" tr gntgc ngyt fgkgf.'

ori.toLowerCase().split('').forEach(c => {
    if (c.charCodeAt(0) >= 'a'.charCodeAt(0) && c.charCodeAt(0) <= 'z'.charCodeAt(0)) {
      const index = sub.indexOf(c)
        process.stdout.write(String.fromCharCode(index + 'a'.charCodeAt(0)))
    } else {
        process.stdout.write(c)
    }
})