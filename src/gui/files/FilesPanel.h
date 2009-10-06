/***********************************************************************

This file is part of the FullAnalyze project source files.

FullAnalyze is a software for handling, visualizing and processing lidar 
data (waveforms and point clouds).


Homepage: 

	http://fullanalyze.sourceforge.net
	
Copyright:
	
	Institut Geographique National & CEMAGREF (2009)

Author: 

	Adrien Chauve
	


    FullAnalyze is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FullAnalyze is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public 
    License along with FullAnalyze.  If not, see <http://www.gnu.org/licenses/>.
 
***********************************************************************/

#ifndef __FilesPanel__
#define __FilesPanel__



#include "wxFB/FilesPanelBuilder.h"

class FilesPanel : public FilesPanelBuilder
{
	public:
		FilesPanel( wxWindow* parent );

		std::string getFullwaveSelectedItemName() const;
		std::string getLidarSelectedItemName() const;
		std::string getImagesSelectedItemName() const;

		void parseAllFiles();

	private:
		void initPopupMenu();

		void parseLidarFiles();
#ifdef BUILD_FULLWAVE
		void parseFullwaveFiles();
#endif
		void parseImageFiles();



		std::string getSelectedItemName() const;


		/////Events
		DECLARE_EVENT_TABLE();
		///Dir picker ctrls
		void OnDirChangeLidar(wxFileDirPickerEvent& event);
		void OnDirChangeFullwave(wxFileDirPickerEvent& event);
		void OnDirChangeImages(wxFileDirPickerEvent& event);
		///Popup menu display
		void OnPopupMenu(wxTreeEvent& event);


		void OnClickPopupMenu(wxCommandEvent &event);


		wxTreeItemId m_root;
		wxTreeItemId m_rootImages;
		wxTreeItemId m_rootLidar;
		wxTreeItemId m_rootFullwave;

		wxMenu *m_popupMenuLidar;
		wxMenu *m_popupMenuFullwave;
		wxMenu *m_popupMenuImages;

};

#endif // __FilesPanel__
