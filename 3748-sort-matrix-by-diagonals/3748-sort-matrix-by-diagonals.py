class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        for i in range(len(grid)):
            for j in range(len(grid[i]) - 1):
                for k in range(len(grid) - 1):
                    if j < k and grid[j][k] > grid[j + 1][k + 1]:
                        grid[j][k], grid[j + 1][k + 1] = grid[j + 1][k + 1], grid[j][k]
                    if j >= k and grid[j][k] < grid[j + 1][k + 1]:
                        grid[j][k], grid[j + 1][k + 1] = grid[j + 1][k + 1], grid[j][k]

        return grid
