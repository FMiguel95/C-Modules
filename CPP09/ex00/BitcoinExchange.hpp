/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:02:14 by fernacar          #+#    #+#             */
/*   Updated: 2024/05/08 19:19:16 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <iostream>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);
	~BitcoinExchange();
	BitcoinExchange& operator =(const BitcoinExchange& src);

	bool getHasDatabase() const;
	void DisplayResult(char* inputArg) const;
	
private:
	std::map<std::string,float> _priceHistory;
	bool _hasDatabase;

	bool ValidateDate(const std::string& dateStr) const;
	float GetPrice(const std::string& dateStr) const;
	bool ValidateValue(const std::string& amountStr) const;
};

#endif
