/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *		Bryce Groff <brycegroff@gmail.com>
 */

#include "CherryBlossom.h"

#include <Application.h>

#include <stdio.h>

CherryBlossom::CherryBlossom()
	: BApplication("application/x-vnd.CherryBlossom")
{
}

CherryBlossom::~CherryBlossom()
{
}

bool CherryBlossom::QuitRequested()
{
	printf("Hello World\n");
	return true;
}

int main(int argc, char* argv[])
{
	CherryBlossom app;
	app.Run();
}
