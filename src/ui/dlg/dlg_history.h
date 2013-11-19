/*
** Taiga, a lightweight client for MyAnimeList
** Copyright (C) 2010-2012, Eren Okka
** 
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
** 
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DLG_HISTORY_H
#define DLG_HISTORY_H

#include "base/std.h"
#include "win32/win_control.h"
#include "win32/win_dialog.h"

// =============================================================================

class HistoryDialog : public win32::Dialog {
public:
  HistoryDialog() {}
  virtual ~HistoryDialog() {}

  INT_PTR DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
  BOOL OnInitDialog();
  LRESULT OnNotify(int idCtrl, LPNMHDR pnmh);
  void OnSize(UINT uMsg, UINT nType, SIZE size);
  BOOL PreTranslateMessage(MSG* pMsg);

public:
  void RefreshList();
  bool MoveItems(int pos);
  bool RemoveItems();

private:
  win32::ListView list_;
};

extern class HistoryDialog HistoryDialog;

#endif // DLG_HISTORY_H