/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *		Bryce Groff <brycegroff@gmail.com>
 */
 
#include "CherryBlossomWindow.h"
#include "PlayListView.h"

#include <Application.h>
#include <Box.h>
#include <Catalog.h>
#include <GridLayout.h>
#include <GroupLayout.h>
#include <GroupView.h>
#include <LayoutBuilder.h>
#include <MenuItem.h>
#include <MenuBar.h>
#include <Menu.h>
#include <SplitView.h>
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
	_Init();
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
			be_app->PostMessage(MSG_NEW_PLAYLIST);
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


void
CherryBlossomWindow::_Init()
{
	fPlaylistView = new PlayListView(BRect(0,0,100,100),
		"play list view", NULL, this);
	fMusicView = new PlayListView(BRect(0,0,100,100),
		"play list view", NULL, this);
	_CreateGUI();
}


void
CherryBlossomWindow::_CreateGUI()
{
	SetLayout(new BGroupLayout(B_HORIZONTAL));
	
	BGridLayout* rootLayout = new BGridLayout();
	BView* rootView = new BView("root view", 0, rootLayout);
	AddChild(rootView);
	rootView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	rootView->SetExplicitMinSize(BSize(800, 500));

	BGroupView* topView = new BGroupView(B_VERTICAL);
	rootLayout->AddView(topView, 0, 0);
	topView->SetExplicitMaxSize(BSize(B_SIZE_UNLIMITED, 80));

	// add the menu, as well as the controller
	topView->AddChild(_CreateMainMenu());	
	topView->AddChild(new BBox(BRect(0,0,1,1)));
	
	// add the main view
	BGridLayout* mainLayout = new BGridLayout();
	BView* mainView = new BView("main view", 0, mainLayout);
	

	BSplitView* threadGroup = new BSplitView(B_HORIZONTAL);
	threadGroup->SetName("Threads");
	mainLayout->AddView(threadGroup);
	BLayoutBuilder::Split<>(threadGroup)
		.Add(fPlaylistView)
		.Add(fMusicView);


	fPlaylistView->SetExplicitMaxSize(BSize(250, B_SIZE_UNLIMITED));

	rootLayout->AddView(mainView, 0, 1);
}

BMenu* CherryBlossomWindow::_CreateMainMenu()
{
	BMenuBar* menuBar = new BMenuBar(Bounds(), "root menu");
	
	fFileMenu = new BMenu("File");
	fNewPlaylistMI = new BMenuItem("New Playlist",
		new BMessage(MSG_NEW_PLAYLIST), 'N');
	fQuitMI = new BMenuItem("Quit", new BMessage(MSG_QUIT), 'Q');
	
	fFileMenu->AddItem(fNewPlaylistMI);
	fFileMenu->AddSeparatorItem();
	fFileMenu->AddItem(fQuitMI);
	menuBar->AddItem(fFileMenu);
	
	return menuBar;
}
