#include "AppTF.h"

void AppTF::StartApp()
{
	AppNote();
	AppLogo();
	AppDesc();
}

void AppTF::AppNote()
{
	Universal u;

	u.MASH_LOG("[IMPORTANT]: Please do not resize this wwindow");

	u.SV(2);
}

void AppTF::AppLogo()
{
	Universal u;

	u.SH(40);
	u.MASH_LOG("----------------------------------------");
	u.SH(40);
	u.MASH_LOG("|                                      |");
	u.SH(40);
	u.MASH_LOG("|              WELCOME TO              |");
	u.SH(40);
	u.MASH_LOG("|                                      |");
	u.SH(40);
	u.MASH_LOG("|                LIFE :                |");
	u.SH(40);
	u.MASH_LOG("|               THE GAME               |");
	u.SH(40);
	u.MASH_LOG("|                                      |");
	u.SH(40);
	u.MASH_LOG("|                                      |");
	u.SH(40);
	u.MASH_LOG("|               Made  By               |");
	u.SH(40);
	u.MASH_LOG("|              Dev Mashup              |");
	u.SH(40);
	u.MASH_LOG("|______________________________________|");

	u.SV();
}

void AppTF::AppDesc()
{
	Universal u;

	u.MASH_LOG("Please add a description");

	u.SV();
}
