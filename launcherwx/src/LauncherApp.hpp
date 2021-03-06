/******************************************************************************/
// Game Launcher for KeeperFX - free implementation of Dungeon Keeper.
/******************************************************************************/
/** @file LauncherApp.hpp
 *     Header file for LauncherApp.cpp.
 * @par Purpose:
 *     Application class.
 * @par Comment:
 *     None.
 * @author   KeeperFX Team
 * @date     25 May 2011 - 07 Jun 2011
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#ifndef LAUNCHERAPP_HPP_
#define LAUNCHERAPP_HPP_
#include <wx/wx.h>
#include "wxImageFrame.hpp"

class wxImagePanel;
class LauncherFrame;
class FilelistChecker;
class CommandOptions;
class GameSettings;

// ----------------------------------------------------------------------------
// private classes
// ----------------------------------------------------------------------------

// Define a new application type, each program should derive a class from wxApp
class LauncherApp : public wxApp
{
    wxImagePanel * drawPane;
    LauncherFrame * frame;

public:
    // override base class virtuals
    // ----------------------------

    // this one is called on application startup and is a good place for the app
    // initialization (doing it here and not in the ctor allows to have an error
    // return: if OnInit() returns false, the application terminates)
    virtual bool OnInit();
};

// Define a new frame type: this is going to be our main frame
class LauncherFrame : public wxImageFrame
{
    wxButton * quitButton;
    wxButton * startButton;
    wxButton * installButton;
    wxButton * configButton;
    wxButton * optionsButton;
    wxButton * readmeButton;
    wxButton * logfileButton;
    wxTextCtrl * msgTextCtrl;

    wxLog *logTarget;
    wxPoint  moveDelta;

    wxString installSrcDir;
    wxString fxWorkDir;

    FilelistChecker * flCheck;

    CommandOptions * cmdOpts;

public:
    // ctor(s)/dtor(s)
    LauncherFrame(const wxString& title);
    ~LauncherFrame();

    // event handlers (these functions should _not_ be virtual)
    void onShow(wxShowEvent& event);
    void onQuit(wxCommandEvent& event);
    void onAbout(wxCommandEvent& event);
    void onLeftDown(wxMouseEvent& event);
    void onLeftUp(wxMouseEvent& event);
    void onMouseMove(wxMouseEvent& event);
    void onRunGame(wxCommandEvent& event);
    void onInstall(wxCommandEvent& event);
    void onOptions(wxCommandEvent& event);
    void onSettings(wxCommandEvent& event);
    void onReadme(wxCommandEvent& event);
    void onLogfile(wxCommandEvent& event);

    // Own utility functions
    void recheckBasicFiles(void);
    std::wstring getSystemStartCommand(void);

private:
    // any class wishing to process wxWidgets events must use this macro
    DECLARE_EVENT_TABLE()
};

// ----------------------------------------------------------------------------
// constants
// ----------------------------------------------------------------------------

// IDs for the controls and the menu commands
enum
{
	Event_Quit = wxID_EXIT,
	Event_Settings = wxID_PROPERTIES,
    Event_Options = wxID_PREFERENCES,
	Event_Install = wxID_SETUP,
	Event_RunGame = wxID_OPEN,
    Event_Readme = wxID_HELP,
    Event_Logfile = wxID_INDEX,

    // it is important for the id corresponding to the "About" command to have
    // this standard value as otherwise it won't be handled properly under Mac
    // (where it is special and put into the "Apple" menu)
	Event_About = wxID_ABOUT
};
#endif
