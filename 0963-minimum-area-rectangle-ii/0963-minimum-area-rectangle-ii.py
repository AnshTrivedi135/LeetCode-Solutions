import collections
import math

class Solution:
    def minAreaFreeRect(self, points):
        diagonals = collections.defaultdict(list)
        n = len(points)
        
        for i in range(n):
            p1_x, p1_y = points[i]
            for j in range(i + 1, n):
                p2_x, p2_y = points[j]
                
                center_x = (p1_x + p2_x) / 2.0
                center_y = (p1_y + p2_y) / 2.0
                dist_sq = (p1_x - p2_x) ** 2 + (p1_y - p2_y) ** 2
                
                diagonals[(center_x, center_y, dist_sq)].append(((p1_x, p1_y), (p2_x, p2_y)))
        
        min_area = float('inf')
        
        for pair_list in diagonals.values():
            if len(pair_list) < 2:
                continue
                
            for k in range(len(pair_list)):
                (p1_x, p1_y), _ = pair_list[k]
                for m in range(k + 1, len(pair_list)):
                    (p3_x, p3_y), (p4_x, p4_y) = pair_list[m]
                    
                    side1 = math.sqrt((p1_x - p3_x) ** 2 + (p1_y - p3_y) ** 2)
                    side2 = math.sqrt((p1_x - p4_x) ** 2 + (p1_y - p4_y) ** 2)
                    
                    area = side1 * side2
                    min_area = min(min_area, area)
        
        return min_area if min_area != float('inf') else 0.0