/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7 (P2)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 17th March 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H
#include <list>
#include <string>
#include <vector>
namespace seneca {
	struct Song {
		std::string m_title;
		std::string m_artist;
		std::string m_album;
		double m_price;
		size_t m_releaseYear;
		size_t m_length;
	};

	class SongCollection {
		std::vector<Song> m_songs;
	public:
		SongCollection(std::string filename);
		void display(std::ostream& out) const;
		void sort(const std::string& field);
		void cleanAlbum();
		bool inCollection(const std::string& artistName) const;
		std::list<Song> getSongsForArtist(const std::string& artistName) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif