def isIsomorphic(s: str, t: str) -> bool:
    if len(s) != len(t):
        return False

    mapping_s = {}
    mapping_t = {}

    for char_s, char_t in zip(s, t):
        if char_s in mapping_s:
            if mapping_s[char_s] != char_t:
                return False
        else:
            if char_t in mapping_t:
                return False
            mapping_s[char_s] = char_t
            mapping_t[char_t] = char_s

    return True
