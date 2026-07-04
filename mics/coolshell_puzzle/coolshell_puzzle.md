# first

Run the string with a brainfuck online.

# welcome

One of the answer is

$$
a_n = a_{n-1} * a_{n-2}
$$

Another is 42.

Their product is the final answer. 

# 81648

Use Dvorak/Qwerty Keyboard Layout converter to get the code. 
The code is a classic korn shell one that just print the answer. (Obfuscated C Code)[https://faehnri.ch/have-fun/]

# unix

Scan the qr code to get the substitution map. Then sub it to get the word puzzle. 

# furyy

There are lots of strings in the source code. Find those that suits those ones in the example. 

# variables

Just replace the url with the responses in a shell script.

# tree

Reconstruct the tree. The reconstruction method is based on:
* The last element of postorder is always the root
* After split the inorder array by the root, assume:
    * The number of nodes in the left subtree is A and The number of nodes in the right subtree is B.
    * Then we can split the postorder array to first A nodes and last B nodes.
    * The first A nodes are the nodes in the left subtree and the last B nodes are the nodes in the right subtree. 
* Recurse this process

With the reconstructed tree, find the deepest path recursively. 

The code for reconstruction and finding the deepest path is in the `tree.py` file. 

Then run the following command: 

```shell
echo 'U2FsdGVkX1+gxunKbemS2193vhGGQ1Y8pc5gPegMAcg=' | openssl enc -aes-128-cbc -a -d -pass pass:THE_STRING_YOU_GET_FROM_THE_DEEPEST_PATH -md md5
```

Note that the `-md md5` part is necessary for newer version of OpenSSL. 

# nqueens

TBC
