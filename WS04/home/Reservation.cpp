//----------------------------------------------
// Name:               Jihee Kim
// Seneca Student ID:  141389189
// Seneca email:       JKIM541@myseneca.ca
// Date of completion: 02/05/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//----------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iomanip>
#include "Reservation.h"

using namespace std;
namespace sdds
{		
        Reservation::Reservation()
                    : m_reservationId{}
                    , m_reservationName{}
                    , m_email{}
                    , m_numPeople{}
                    , m_day{}
                    , m_hour{}
        {
        }

		Reservation::Reservation(const string& res) {
            string str = res;
            size_t pos{}, last{ size_t(-1) };
            string temp[6]{ {} };
            size_t count{};
            pos = str.find(' ');
            while (pos != (size_t)(-1)) {
                str.erase(pos, 1);
                pos = str.find(' ');
            }
            for (size_t i = 0; i < str.length(); i++) {
                if (str[i] == ',' || str[i] == ':') {
                    pos = str.find(str[i]);
                    temp[count++] = str.substr(last + 1, pos - last - 1);
                    last = pos;
                    str[i] = '*';
                }
            }
            temp[count] = str.substr(pos + 1);
            strcpy(m_reservationId, temp[0].c_str());
            m_reservationName = temp[1];
            m_email = temp[2];
            m_numPeople = stoi(temp[3]);
            m_day = stoi(temp[4]);
            m_hour = stoi(temp[5]);
		}

        Reservation& Reservation::operator=(const Reservation& res) {
            strcpy(m_reservationId, res.m_reservationId);
            m_reservationName = res.m_reservationName;
            m_email = res.m_email;
            m_numPeople = res.m_numPeople;
            m_day = res.m_day;
            m_hour = res.m_hour;
            return *this;
        }

		ostream& operator<<(ostream& os, const Reservation& res) {
            string email = " <" + res.m_email + ">";
			os << "Reservation " << res.m_reservationId << ": "
			<< setw(10) << right << res.m_reservationName << " "
			<< left << setw(20) << email
			<< right << "     ";
			if (res.m_hour >= 6 && res.m_hour <= 9) os << "Breakfast";
			else if (res.m_hour >= 11 && res.m_hour <= 15) os << "Lunch";
			else if (res.m_hour >= 17 && res.m_hour <= 21) os << "Dinner";
			else  os << "Drinks";
			os << " on day " << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_numPeople << " people." << endl;
			return os;
		}
}

