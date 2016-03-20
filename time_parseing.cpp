#include <stdio.h>
#include <string>

using namespace std;

int main(std::string currTime)
{
	int i;
	int pos;
	
	//For testing
	currTime = "2016-03-20 07:36:22";
	
	std::string arr[]
	arr[0] = " INFO 2016-03-20 07:36:22,378 [BombGenerator] Generator settings: Time: 300, NumStrikes: 3, FrontFaceOnly: True3 Pools:[Wires] Count: 1[BigButton] Count: 1[Keypad] Count: 1";
	arr[1] = "DEBUG 2016-03-20 07:53:27,940 [Assets.Scripts.Pacing.PaceMaker] Round start! Mission: The First Bomb Pacing Enabled: False";
	arr[2] = "DEBUG 2016-03-20 07:38:06,115 [Bomb] Strike! 1 / 3 strikes";
	arr[3] = "DEBUG 2016-03-20 07:38:06,958 [Bomb] Strike! 2 / 3 strikes";
	arr[4] = " INFO 2016-03-20 07:38:16,121 [Bomb] Boom";
	
	for(i = 0,i++,i<5)
	{
		pos = arr[i].find(currTime);
		
	
	return(0);
}
