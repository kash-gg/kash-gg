class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        st = []

        for n in num:
            while st and k > 0 and st[-1] > n:
                st.pop()
                k -= 1

            # Prevent leading zeros
            if st or n != '0':
                st.append(n)

        # If k removals are still left
        if k:
            st = st[:-k]

        return ''.join(st) or '0'