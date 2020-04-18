# Kevin Chan
# March 31, 2020

def midpoint(xd1,yd1, xd2, yd2, x_car, y_car):

    #Find midpoint between xd, yd

    y_center = (yd2 + yd1)/2
    x_center = (xd2 + xd1)/2

    m = y_car - y_center / (x_car - x_center)

    return m

