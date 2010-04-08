/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *		Bryce Groff <brycegroff@gmail.com>
 */

#include "CherryBlossom.h"
#include "CherryBlossomWindow.h"

#include <Application.h>
#include <Locale.h>

#include <stdio.h>
#include <stdlib.h>


CherryBlossom::CherryBlossom()
	: BApplication("application/x-vnd.CherryBlossom")
{
	fMainWindow = new CherryBlossomWindow();
}

CherryBlossom::~CherryBlossom()
{
}

bool
CherryBlossom::QuitRequested()
{
	if (fMainWindow->Lock()) {
		fMainWindow->Quit();
		fMainWindow = NULL;
	}

	return true;
}

void
CherryBlossom::ReadyToRun()
{
	be_locale->GetAppCatalog(&fCatalog);
	
	if (fMainWindow)
		fMainWindow->Show();
}

int
main(int argc, char* argv[])
{
	CherryBlossom app;
	app.Run();
	
	return EXIT_SUCCESS;
}
