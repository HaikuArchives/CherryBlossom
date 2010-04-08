/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *		Bryce Groff <brycegroff@gmail.com>
 */
 
#include "MusicView.h"

#include <Box.h>
#include <GroupLayout.h>
#include <LayoutBuilder.h>
#include <View.h>

MusicView::MusicView(BRect frame, const char* name)
	: BView(frame, name,  B_FOLLOW_ALL, B_WILL_DRAW | B_NAVIGABLE
	| B_FRAME_EVENTS | B_FULL_UPDATE_ON_RESIZE)
{
	_Init();
}


MusicView::~MusicView()
{
	
}

// #pragma mark - Private Methods

void
MusicView::_Init()
{
	fArtistView = new BBox(BRect(0,0,1,1));
	fAlbumView = new BBox(BRect(0,0,1,1));
	fGenreView = new BBox(BRect(0,0,1,1));

	_CreateGUI();
}


void
MusicView::_CreateGUI()
{
	SetLayout(new BGroupLayout(B_HORIZONTAL));
	BGridLayout* rootLayout = new BGridLayout();
	BView* rootView = new BView("root view", 0, rootLayout);
	AddChild(rootView);
	
	// add the main view
	BGridLayout* mainLayout = new BGridLayout();
	BView* mainView = new BView("main view", 0, mainLayout);

	BSplitView* delimiterGroup = new BSplitView(B_HORIZONTAL);
	delimiterGroup->SetName("Delimiters");
	BLayoutBuilder::Split<>(delimiterGroup)
		.Add(fArtistView)
		.Add(fAlbumView)
		.Add(fGenreView);

	BSplitView* containerGroup = new BSplitView(B_VERTICAL);
	containerGroup->SetName("Container");
	BLayoutBuilder::Split<>(containerGroup)
		.Add(delimiterGroup)
		.Add(new BBox(BRect(0,0,1,1)));

	mainLayout->AddView(containerGroup);

	rootLayout->AddView(mainView, 0, 0);
	
	//rootLayout->AddView(new BBox(BRect(0,0,1,1)), 0, 1);
}
