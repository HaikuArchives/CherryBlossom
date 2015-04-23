/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *		Bryce Groff <brycegroff@gmail.com>
 */

#ifndef MUSIC_VIEW_H_
#define MUSIC_VIEW_H_

#include <View.h>

class MusicView : public BView {
public:
						MusicView(BRect frame, const char* name);
	virtual				~MusicView();

private:
	void				_Init();
	void				_CreateGUI();

	BView*				fArtistView;
	BView*				fAlbumView;
	BView*				fGenreView;
};

#endif
