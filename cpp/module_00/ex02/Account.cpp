# include "./Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


int		Account::getNbAccounts() {

	return Account::_nbAccounts;
}

int		Account::getTotalAmount() {

	return Account::_totalAmount;
}

int		Account::getNbDeposits() {

	return Account::_totalNbDeposits;
}

int		Account::getNbWithdrawals() {

	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos() {

	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ) : _accountIndex(Account::_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {

	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account( void ) {

	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {

	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	if (withdrawal > this->_amount) {

		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		return false;
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void ) const {

	return this->_amount;
}

void	Account::displayStatus( void ) const {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {

	time_t		t;
	struct tm	*tm;

	t = time(NULL);
	tm = localtime(&t);

	std::cout << "[" << tm->tm_year + 1900 << tm->tm_mon + 1 << tm->tm_mday << "_" << tm->tm_hour << tm->tm_min << tm->tm_sec << "] ";
}
