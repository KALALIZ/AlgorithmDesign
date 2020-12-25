#Silalak Kaewjanpet 610510670

def PutThingsIntoToTheBag(things,W):
    weight = W
    count = len(things)
    price = 0
    for i in range(count):
      
        if (weight == 0 or i == count):
            break
        elif (weight >= things[i][1]):
            price += things[i][0]
            weight -= things[i][1]
        else:
            price += (things[i][0]/things[i][1])*weight
            weight -= weight

    return price


def main():
    things = []
    N, W = map(int,input().split())
    num = list(map(int, input().split()))
    things = list(zip(num[::2], num[1::2]))
    things.sort(key = lambda x: x[0] / x[1])
    things.reverse()
    print("%.2f"% PutThingsIntoToTheBag(things,W))
    
if __name__ == "__main__":
    main()

