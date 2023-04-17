class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        max_candy = -1
        
        for candy in candies:
            if candy > max_candy:
                max_candy = candy
                
        results = []
        
        for candy in candies:
            if candy + extraCandies >= max_candy:
                results.append(True)
            else:
                results.append(False)
                
        return results