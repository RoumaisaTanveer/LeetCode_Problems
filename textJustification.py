class Solution:
    def fullJustify(self, words, maxWidth):
        res = []
        i = 0
        n = len(words)

        while i < n:
            line_len = len(words[i])
            j = i + 1
            while j < n and line_len + 1 + len(words[j]) <= maxWidth:
                line_len += 1 + len(words[j])
                j += 1

            num_words = j - i
            total_chars = sum(len(word) for word in words[i:j])
            total_spaces = maxWidth - total_chars

            if j == n or num_words == 1:
                line = ' '.join(words[i:j])
                line += ' ' * (maxWidth - len(line))
            else:
                spaces_between_words = total_spaces // (num_words - 1)
                extra_spaces = total_spaces % (num_words - 1)

                line = ""
                for k in range(i, j - 1):
                    line += words[k]
                    line += ' ' * (spaces_between_words + (1 if k - i < extra_spaces else 0))
                line += words[j - 1]

            res.append(line)
            i = j

        return res
