/*
- Name: Karl Merhi
- Student number: 150828168
- Seneca email: kmerhi1@myseneca.ca
- File: CustomerOrder.h
- Project: MS1
- Date of completion: 11/29/2021

I confirm that I am the only author of this file
and the content was created entirely by me.
*/

#include <string>
#include "Station.h"
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

namespace sdds {

	class CustomerOrder
	{
		struct Item
		{
			std::string m_itemName;
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};

		std::string m_name;
		std::string m_product;
		size_t m_cntItem;
		Item** m_listItem;
		static size_t m_widthField;
	public:
		CustomerOrder();
		CustomerOrder(const std::string&);
		CustomerOrder(CustomerOrder&);
		CustomerOrder& operator=(CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&&) noexcept;
		CustomerOrder& operator=(CustomerOrder&&) noexcept;
		~CustomerOrder();
		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif // !SDDS_CUSTOMERORDER_H
