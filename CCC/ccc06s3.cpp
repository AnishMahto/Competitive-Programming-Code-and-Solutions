#include <iostream>
#include <algorithm>
using namespace std;

float wireSlope, wireB, rx, ry, jx, jy;

bool sameX (float prevX, float posX, float prevY, float posY) {
    if (min (posX, prevX) > max (rx, jx) || min (posY, prevY) > max (ry, jy)) {
        return false;
    }
    float intersect = wireSlope*prevX + wireB;
    if ( ( intersect > max (prevY, posY) || intersect < min (prevY, posY) ) || ( intersect > max (ry, jy) || intersect < min (jy, ry) ) ) {
        return false;
    }
    return true;
}

bool sameY (float prevX, float posX, float prevY, float posY) {
    if (min (posX, prevX) > max (rx, jx) || min (posY, prevY) > max (ry, jy)) {
        return false;
    }
    float intersect = (prevY - wireB)/wireSlope;
    if ( ( intersect > max (prevX, posX) || intersect < min (prevX, posX) ) || (intersect > max (rx, jx) || intersect < min (rx, jx) ) ) {
        return false;
    }
    return true;
}

bool solve (float prevX, float posX, float prevY, float posY) {
    if (min (posX, prevX) > max (rx, jx) || min (posY, prevY) > max (ry, jy)) {
        return false;
    }
    float tempSlope = (posY - prevY)/(posX - prevX);
    float tempB = posY - tempSlope*posX;
    if (tempSlope == wireSlope && tempB != wireB) {
        return false;
    } else {
        float intersect = (tempB - wireB)/(wireSlope - tempSlope);
        if ( ( intersect > max (prevX, posX) || intersect < min (prevX, posX) ) || (intersect > max (rx, jx) || intersect < min (rx, jx) ) ) {
            return false;
        }
    }
    return true;
}

int main() {
	// your code goes here
	int buildings, points, collisions = 0;
	float posX, posY, prevX, prevY, startX, startY;
	cin >> rx >> ry >> jx >> jy >> buildings;
	if (jx > rx) {
	    wireSlope = (jy - ry)/(jx - rx);
	} else {
	    wireSlope = (ry - jy)/(rx - jx);
	}
	wireB = ry - wireSlope*rx;
	////////////////////////////////////
	
	bool collide = false;
	
	for (int b = 1; b <= buildings; b++) {
	    cin >> points >> posX >> posY;
	    startX = posX;
	    startY = posY;
	    collide = false;
	    
	    for (int a = 0; a < points - 1; a++) {
	        prevX = posX; prevY = posY;
	        cin >> posX >> posY;
	        if (rx == jx && collide == false) {
	            if (min (prevX, posX) <= rx && max (prevX, posX) >= rx && (min (posY, prevY) <= min(jy, ry) || max (posY, prevY) <= max(ry, jy))) {
	                collide = true;
	                collisions++;
	            }
	        } else if (collide == false) {
	            if (posX == prevX) {
	                collide = sameX (prevX, posX, prevY, posY);
	            } else if (posY == prevY) {
	                collide = sameY (prevX, posX, prevY, posY);
	            } else {
	                collide = solve (prevX, posX, prevY, posY);
	            }
	            if (collide) collisions++;
	        }
	        
	    }
	}
	
	cout << collisions << endl;
	
	return 0;
}
