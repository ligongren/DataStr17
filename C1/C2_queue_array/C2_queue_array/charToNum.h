#pragma once

#define numPou	0

#define numPlus	3
#define numSub	4

#define numMul	7
#define numDiv	8

#define numLef	10
#define numRig	-1

int charToNum(char x)
{
	switch (x)
	{
	default:
		return -1;
	case '#':
		return numPou;
		break;
	case '+':
		return numPlus;
		break;
	case '-':
		return numSub;
		break;
	case '*':
		return numMul;
		break;
	case '/':
		return numDiv;
		break;
	case '(':
		return numLef;
		break;
	case ')':
		return numRig;
		break;
	}
	return 0;
}