#pragma once

#define numPou	0

#define numPlus	1
#define numSub	2

#define numMul	5
#define numDiv	6

#define numLef	10
#define numRig	11

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
}