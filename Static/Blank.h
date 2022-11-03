#pragma once
// need to compile something for the lib, this static lib is useless as tempaltes are always in .h's and are not compiled untill used
// so a static lib won't contain them there, but i linked this project like this. it's late, too lazy to fix

class Blank
{
	Blank();

	int rng;
};