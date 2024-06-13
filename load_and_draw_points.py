import matplotlib.pyplot as plt
import re

def read_points_from_file(file_path):
    with open(file_path, 'r') as file:
        data = file.read().strip()
        
    points = re.findall(r'\[(\d+),(\d+)\]', data)
    points = [(int(x), int(y)) for x, y in points]
    
    return points

points = read_points_from_file('tests/1_in.txt')
hull = read_points_from_file('out.txt')

x_points, y_points = zip(*points)
x_hull, y_hull = zip(*hull)

plt.figure()
plt.scatter(x_points, y_points, color='blue', label='Points')
plt.plot(x_hull, y_hull, color='red', label='Polygon')
plt.show()
