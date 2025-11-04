class Solution:
    def getSubArrays(self, arr, k):
        subArrays = []

        for i in range(len(arr) - k + 1):
            subArrays.append(arr[i : i + k])

        return subArrays

    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        res = []
        lst = self.getSubArrays(nums, k)

        for i in lst:
            sumX = 0
            d = {}

            for j in i:
                if j in d:
                    d[j] += 1
                else:
                    d[j] = 1
            sortedD = sorted(
                d.items(), key=lambda item: (item[1], item[0]), reverse=True
            )

            X = x
            for val, key in sortedD:
                if X > 0:
                    sumX += val * key
                    X -= 1
                if X == 0:
                    break

            res.append(sumX)

        return res
