class TrieNode:
    def __init__(self, val: str=None):
        self.val = val
        self.children = {}
        self.end = False
    
    # def addChild(self, c: str, t: "TrieNode"):
    #     self.children

class WordDictionary:
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode(c)
            cur = cur.children[c]
        cur.end = True

    def _search(self, word: str, idx: int, cur: TrieNode) -> bool:
        if idx >= len(word):
            return cur.end

        c = word[idx]
        if c != ".":
            nxt = cur.children.get(c, None)
            if nxt is None:
                return False
            
            return self._search(word, idx+1, nxt)
        
        else:
            for childKey in cur.children:
                if self._search(word, idx+1, cur.children[childKey]):
                    return True
            
            return False


        # for i in range(start_idx, len(word)):
        #     c = word[i]

        #     if c != ".":
        #         nxt = cur.children.get(c, None)
        #         if nxt is None:
        #             return False
        #         else:
        #             cur = nxt
        #     else:
        #         flag = False
        #         for charChild in cur.children:
        #             if self._search

    def search(self, word: str) -> bool:
        return self._search(word, 0, self.root)


                
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)