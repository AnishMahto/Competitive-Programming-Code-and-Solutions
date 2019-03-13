#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int posO, negO, posA, negA, posB, negB, posAB, negAB;
	int posOp, negOp, posAp, negAp, posBp, negBp, posABp, negABp, patients = 0;
	cin >> negO >> posO >> negA >> posA >> negB >> posB >> negAB >> posAB;
	cin >> negOp >> posOp >> negAp >> posAp >> negBp >> posBp >> negABp >> posABp;
	
	if (negO >= negOp) {
	    negO -= negOp;
	    patients += negOp;
	    negOp = 0;
	} else {
	    patients += negO;
	    negOp -= negO;
	    negO = 0;
	}
	
	if (posO >= posOp) {
	    posO -= posOp;
	    patients += posOp;
	    posOp = 0;
	} else {
	    patients += posO;
	    posOp -= posO;
	    posO = 0;
	    if (negO >= posOp) {
	        negO -= posOp;
	        patients += posOp;
	        posOp = 0;
	    } else {
	        posOp -= negO;
	        patients += negO;
	        negO = 0;
	    }
	}
	
	if (negA >= negAp) {
	    negA -= negAp;
	    patients += negAp;
	    negAp = 0;
	} else {
	    patients += negA;
	    negAp -= negA;
	    negA = 0;
	    if (negO >= negAp) {
	        negO -= negAp;
	        patients += negAp;
	        negAp = 0;
	    } else {
	        patients += negO;
	        negAp -= negO;
	        negO = 0;
	    }
	}
	
	if (posA >= posAp) {
	    posA -= posAp;
	    patients += posAp;
	    posAp = 0;
	} else {
	    patients += posA;
	    posAp -= posA;
	    posA = 0;
	    if (posO >= posAp) {
	        posO -= posAp;
	        patients += posAp;
	        posAp = 0;
	    } else {
	        patients += posO;
	        posAp -= posO;
	        posO = 0;
	    }
	    if (negO >= posAp) {
	        negO -= posAp;
	        patients += posAp;
	        posAp = 0;
	    } else {
	        patients += negO;
	        posAp -= negO;
	        negO = 0;
	    }
	    if (negA >= posAp) {
	        negA -= posAp;
	        patients += posAp;
	        posAp = 0;
	    } else {
	        patients += negA;
	        posAp -= negA;
	        negA = 0;
	    }
	}
	
	if (negB >= negBp) {
	    negB -= negBp;
	    patients += negBp;
	    negBp = 0;
	} else {
	    patients += negB;
	    negBp -= negB;
	    negB = 0;
	    if (negO >= negBp) {
	        negO -= negBp;
	        patients += negBp;
	        negBp = 0;
	    } else {
	        patients += negO;
	        negBp -= negO;
	        negO = 0;
	    }
	}
	
	if (posB >= posBp) {
	    posB -= posBp;
	    patients += posBp;
	    posBp = 0;
	} else {
	    patients += posB;
	    posBp -= posB;
	    posB = 0;
	    if (posO >= posBp) {
	        posO -= posBp;
	        patients += posBp;
	        posBp = 0;
	    } else {
	        patients += posO;
	        posBp -= posO;
	        posO = 0;
	    }
	    if (negO >= posBp) {
	        negO -= posBp;
	        patients += posBp;
	        posBp = 0;
	    } else {
	        patients += negO;
	        posBp -= negO;
	        negO = 0;
	    }
	    if (negB >= posBp) {
	        negB -= posBp;
	        patients += posBp;
	        posBp = 0;
	    } else {
	        patients += negB;
	        posBp -= negB;
	        negB = 0;
	    }
	}
	
	if (negAB >= negABp) {
	    negAB -= negABp;
	    patients += negABp;
	    negABp = 0;
	} else {
	    patients += negAB;
	    negABp -= negAB;
	    negAB = 0;
	    if (negO >= negABp) {
	        negO -= negABp;
	        patients += negABp;
	        negABp = 0;
	    } else {
	        patients += negO;
	        negABp -= negO;
	        negO = 0;
	    }
	    if (negA >= negABp) {
	        negA -= negABp;
	        patients += negABp;
	        negABp = 0;
	    } else {
	        patients += negA;
	        negABp -= negA;
	        negA = 0;
	    }
	    if (negB >= negABp) {
	        negB -= negABp;
	        patients += negABp;
	        negABp = 0;
	    } else {
	        patients += negB;
	        negABp -= negB;
	        negB = 0;
	    }
	    
	}
	
	if (posAB >= posABp) {
	    posAB -= posABp;
	    patients += posABp;
	    posABp = 0;
	} else {
	    patients += posAB;
	    posABp -= posAB;
	    posAB = 0;
	    if (negAB >= posABp) {
	        negAB -= posABp;
	        patients += posABp;
	        posABp = 0;
	    } else {
	        patients += negAB;
	        posABp -= negAB;
	        negAB = 0;
	    }
	    if (posO >= posABp) {
	        posO -= posABp;
	        patients += posABp;
	        posABp = 0;
	    } else {
	        patients += posO;
	        posABp -= posO;
	        posO = 0;
	    }
	    if (negO >= posABp) {
	        negO -= posABp;
	        patients += posABp;
	        posABp = 0;
	    } else {
	        patients += negO;
	        posABp -= negO;
	        negO = 0;
	    }
	    if (posA >= posABp) {
	        posA -= posABp;
	        patients += posABp;
	        posABp = 0;
	    } else {
	        patients += posA;
	        posABp -= posA;
	        posA = 0;
	    }
	    if (negA >= posABp) {
	        negA -= posABp;
	        patients += posABp;
	        posABp = 0;
	    } else {
	        patients += negA;
	        posABp -= negA;
	        negA = 0;
	    }
	    if (posB >= posABp) {
	        posB -= posABp;
	        patients += posABp;
	        posABp = 0;
	    } else {
	        patients += posB;
	        posABp -= posB;
	        posB = 0;
	    }
	    if (negB >= posABp) {
	        negB -= posABp;
	        patients += posABp;
	        posABp = 0;
	    } else {
	        patients += negB;
	        posABp -= negB;
	        negB = 0;
	    }
	    
	}
	
	cout << patients << endl;
	return 0;
}
