class Solution:
    def distance(self, point: List[int]) -> int:
        return point[0] ** 2 + point[1] ** 2

    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        arr = []
        for i, point in enumerate(points):
            arr.append((i, self.distance(point)))
    
        arr.sort(key=lambda x: x[1])

        res = []
        for i in range(k):
            res.append(points[arr[i][0]])
        
        return res
