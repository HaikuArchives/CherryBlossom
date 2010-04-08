/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *		Bryce Groff <brycegroff@gmail.com>
 */

#ifndef PLAY_LIST_VIEW_H_
#define PLAY_LIST_VIEW_H_

#include <ListView.h>
#include <Message.h>
#include <View.h>


class PlayListView : public BView {
public:
					PlayListView(BRect frame, const char* name,
								BMessage* selectionMessage = NULL,
								BHandler* target = NULL);
					~PlayListView();

	virtual void	MessageReceived(BMessage*);
private:
	BListView*		fListView;
};

#endif
