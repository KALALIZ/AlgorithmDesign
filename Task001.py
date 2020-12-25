#Silalak Kaewjanpet 610510670
import math 
 
class Point(): 
    def __init__(self, x, y): 
        self.x = x 
        self.y = y 
  
def dist(p1, p2): 
    return math.sqrt((p1.x - p2.x) * 
                     (p1.x - p2.x) +
                     (p1.y - p2.y) * 
                     (p1.y - p2.y))  
  
def bruteForce(P, N): 
    min_val = float('inf')  
    for i in range(N): 
        for j in range(i + 1, N): 
            if dist(P[i], P[j]) < min_val: 
                min_val = dist(P[i], P[j]) 
  
    return min_val 
  
def stripClosest(strip, size, d): 
      
   
    min_val = d  
  
    strip.sort(key = lambda point: point.y)  
  
    
    for i in range(size): 
        j = i + 1
        while j < size and (strip[j].y - 
                            strip[i].y) < min_val: 
            min_val = dist(strip[i], strip[j]) 
            j += 1
  
    return min_val  
  

def closestUtil(P, N): 
    
    if N <= 3:  
        return bruteForce(P, N)  
    
    mid = N // 2
    midPoint = P[mid] 
  
    dl = closestUtil(P[:mid], mid) 
    dr = closestUtil(P[mid:], N - mid)  
  
    d = min(dl, dr) 
  
    strip = []  
    for i in range(N):

        if abs(P[i].x - midPoint.x) < d:  
            strip.append(P[i]) 

    return min(d, stripClosest(strip, len(strip), d)) 
  
def closest(P, N): 

    P.sort(key = lambda point: point.x)
  
    return closestUtil(P, N) 
  

P = []
N = int(input())
for i in range(N):
    x, y = map(int,input().split())
    P.append(Point(x,y)) 
if closest(P, N) < 10000:
    print("%.4f"%(closest(P, N)))
else:
    print("INFINITY")

 