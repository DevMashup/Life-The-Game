#include <iostream>

#include "Universal/Universal.h"

void Universal::MASH_LOG(MASH_ccharp msg)
{
	MASH_cout << msg << MASH_endl;
}

void Universal::SH()
{
	MASH_cout << " ";
}

void Universal::SH(MASH_uint num)
{
	if (num == 1) {
		SH();
	}
	else if (num > 109 && num < 120) {
		MASH_LOG("[WARNING]");
	}
	else if (num > 119) {
		MASH_LOG("[ERROR]");
	}
	else {
		for (MASH_uint i = 0; i < num; i++) {
			SH();
		}
	}
}

void Universal::SV()
{
	MASH_LOG("");
}

void Universal::SV(MASH_uint num)
{
	if (num == 1) {
		SV();
	}
	else {
		for (MASH_uint i = 0; i < num; i++) {
			SV();
		}
	}
}