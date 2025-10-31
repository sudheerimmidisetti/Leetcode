class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        lst = []
        st = set()

        st.update(nums)
        for x in st:
            cnt = nums.count(x)
            if cnt > 1:
                lst.append(x)
                if len(lst) == 2:
                    break
        
        return lst