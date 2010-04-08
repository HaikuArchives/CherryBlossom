/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *		Bryce Groff <brycegroff@gmail.com>
 */

#ifndef CHERRY_BLOSSOM_H_
#define CHERRY_BLOSSOM_H_

#include <Application.h>
#include <Catalog.h>
#include <Window.h>

class CherryBlossom : public BApplication {
public:
					CherryBlossom();
					~CherryBlossom();

	virtual void	ReadyToRun();
	virtual bool	QuitRequested();
private:
	BWindow*		fMainWindow;
	BCatalog		fCatalog;
};

#endif
