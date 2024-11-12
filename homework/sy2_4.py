import math
def dis(p, q):
    return math.sqrt((p[0] - q[0]) ** 2 + (p[1] - q[1]) ** 2)

def closest_pair(points):
    if len(points) == 1:
        return float('inf')

    if len(points) == 2:
        return dis(points[0], points[1])
    
    sorted_points = sorted(points, key=lambda x: x[0])

    mid = len(sorted_points) // 2
    left_points = sorted_points[:mid]
    right_points = sorted_points[mid:]

    midleft = closest_pair(left_points)
    midright = closest_pair(right_points)

    mid_dist = min(midleft, midright)
    
    # mid range search y
    mid_x = sorted_points[mid][0]
    mid_search_range = [point for point in sorted_points if abs(point[0] - mid_x) < mid_dist]
    mid_search_range.sort(key=lambda x: x[1])

    for i in range(len(mid_search_range)):
        for j in range(i + 1, len(mid_search_range)):
            if mid_search_range[j][1] - mid_search_range[i][1] >= mid_dist:
                break

            mid_dist = min(mid_dist, dis(mid_search_range[i], mid_search_range[j]))

    return mid_dist

# test
points = [(2, 3), (12, 30), (40, 50), (5, 1), (12, 10), (3, 4)]
print(closest_pair(points))
