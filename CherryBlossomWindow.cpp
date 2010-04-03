/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *		Bryce Groff <brycegroff@gmail.com>
 */
 
#include "CherryBlossomWindow.h"

#include <Application.h>
#include <Catalog.h>
#include <MenuItem.h>
#include <MenuBar.h>
#include <Menu.h>
#include <Window.h>
#include <View.h>

#include <stdio.h>
#include <stdlib.h>

#define TR_CONTEXT "MainWindow"

enum {
	MSG_QUIT					= 'quit',
	MSG_NEW_PLAYLIST			= 'nwpl',
};

CherryBlossomWindow::CherryBlossomWindow()
	: BWindow(BRect(30, 30, 900, 600), "Cherry Blossom",
		B_TITLED_WINDOW, B_AUTO_UPDATE_SIZE_LIMITS | B_NOT_ZOOMABLE)
{
	BMenuBar* menuBar = new BMenuBar(Bounds(), "root menu");
	
	fFileMenu = new BMenu("File");
	fNewPlayListMI = new BMenuItem("New Playlist",
		new BMessage(MSG_NEW_PLAYLIST), 'N');
	fQuitMI = new BMenuItem("Quit", new BMessage(MSG_QUIT), 'Q');
	
	fFileMenu->AddItem(fNewPlayListMI);
	fFileMenu->AddSeparatorItem();
	fFileMenu->AddItem(fQuitMI);
	menuBar->AddItem(fFileMenu);
	
	AddChild(menuBar);
}


CherryBlossomWindow::~CherryBlossomWindow()
{
}

void
CherryBlossomWindow::MessageReceived(BMessage* message)
{
	switch (message->what) {
		case MSG_QUIT:
			QuitRequested();
			break;
		case MSG_NEW_PLAYLIST:
			printf("New Play List\n");
			break;
		default:
			BWindow::MessageReceived(message);
			break;
	}
}

bool
CherryBlossomWindow::QuitRequested()
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	Hide();
	return false;
}
