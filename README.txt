This project reads in a text file of dictionary words and inserts them into a hash
table using chaining and then spell checks a text file by reading each word in the text file and looking each
word up in the hash table that represents the dictionary. All words not found in the dictionary (hash table)
are considered misspelled. A word is formally defined via code presented below in a supplied C++
function getword(). The case (upper- or lower-case) does not matter when comparing words. The program
prints the list of misspelled words with a title indicating that the misspelled words are to appear.