#include "AppTF.h"
#include "AppD.h"
#include "AppO.h"

int main() {	
	AppTF aTF;
	AppD aD;
	AppO aO;

	aTF.StartApp();
	aD.CreateData();
	aO.ConApp();
}