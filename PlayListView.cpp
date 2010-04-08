/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *		Bryce Groff <brycegroff@gmail.com>
 */

#include "PlayListView.h"

#include <GridLayoutBuilder.h>
#include <GroupLayout.h>
#include <GroupLayoutBuilder.h>
#include <ListView.h>
#include <View.h>

#include <stdio.h>

PlayListView::PlayListView(BRect frame, const char* name,
	BMessage* selectionMessage, BHandler* target)
	: BView(frame, name, B_FOLLOW_ALL, B_WILL_DRAW | B_NAVIGABLE
	| B_FRAME_EVENTS | B_FULL_UPDATE_ON_RESIZE)
{
	//SetTarget(target);
	fListView = new BListView(frame, "Playlist");
	
	SetLayout(new BGroupLayout(B_HORIZONTAL));
	BGridLayout* layout = new BGridLayout();
	BView* rootView = new BView("root view", 0, layout);
	AddChild(rootView);
	rootView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	
	fListView->AddItem(new BStringItem("Library"));
	
	layout->AddView(fListView);
}

PlayListView::~PlayListView()
{
}

void
PlayListView::MessageReceived(BMessage* message)
{
	//printf("Message received in playlistview \n");
}
