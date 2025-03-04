// Copyright (C) Explorer++ Project
// SPDX-License-Identifier: GPL-3.0-only
// See LICENSE in the top level directory

#pragma once

#include "Config.h"
#include "CoreInterface.h"
#include "SignalWrapper.h"
#include "TabContainer.h"

class Navigation
{
public:

	Navigation(std::shared_ptr<Config> config, IExplorerplusplus *expp);
	~Navigation();

	void OnBrowseBack();
	void OnBrowseForward();
	void OnNavigateHome();
	void OnNavigateUp();
	void OnGotoFolder(int FolderCSIDL);

	HRESULT BrowseFolderInCurrentTab(const TCHAR *szPath, UINT wFlags);
	HRESULT BrowseFolder(Tab &tab, const TCHAR *szPath, UINT wFlags);
	HRESULT BrowseFolderInCurrentTab(LPCITEMIDLIST pidlDirectory, UINT wFlags);
	HRESULT BrowseFolder(Tab &tab, LPCITEMIDLIST pidlDirectory, UINT wFlags);
	void PlayNavigationSound() const;

	void OpenDirectoryInNewWindow(LPCITEMIDLIST pidlDirectory);

	SignalWrapper<Navigation, void(const Tab &tab)> navigationCompletedSignal;

private:

	void OnTabCreated(int tabId, BOOL switchToNewTab);

	std::shared_ptr<Config> m_config;
	IExplorerplusplus *m_expp;
	TabContainer *m_tabContainer;
};