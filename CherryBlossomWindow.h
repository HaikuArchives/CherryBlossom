/*
 * Copyright (c) 2010, Bryce Groff.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *		Bryce Groff <brycegroff@gmail.com>
 */
 
#ifndef _CHERRY_BLOSSOM_WINDOW_H_
#define _CHERRY_BLOSSOM_WINDOW_H_

#include <Menu.h>
#include <MenuItem.h>
#include <Window.h>
#include <View.h>
 
class CherryBlossomWindow : public BWindow
{
public:
					CherryBlossomWindow();
	virtual			~CherryBlossomWindow();
	
	virtual void	MessageReceived(BMessage* message);
	virtual bool	QuitRequested();

private:
	void			_Init();
	void			_CreateGUI();
	BMenu*			_CreateMainMenu();

	BView*			fMainView;
	BView*			fPlaylistView;
	BView*			fMusicView;

	BMenu*			fFileMenu;
	BMenuItem*		fNewPlaylistMI;
	BMenuItem*		fQuitMI;

};

#endif
