/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *		Bryce Groff <brycegroff@gmail.com>
 */

#include "AlbumView.h"
#include "ArtistView.h"
#include "CherryBlossomView.h"
#include "GenreView.h"
#include "InfoView.h"
#include "PlayListView.h"
#include "SearchView.h"
#include "SongView.h"

#include <View.h>

CherryBlossomView::CherryBlossomView()
	: BView("MainView", B_WILL_DRAW | B_SUPPORTS_LAYOUT
	| B_FULL_UPDATE_ON_RESIZE)
{
}

CherryBlossomView::~CherryBlossomView()
{
}
