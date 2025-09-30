// Copyright 2025 Abdelkader Benajiba

#include "Account.hpp"

#include <ctime>

// Static member definitions
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) {}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
  _nbAccounts++;
  _totalAmount += _amount;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created"
            << std::endl;
}

Account::~Account(void) {
  _nbAccounts--;
  _totalAmount -= _amount;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
            << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t now = std::time(0);
  char buf[32];
  if (std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]",
                    std::localtime(&now))) {
    std::cout << buf << " ";
  } else {
    std::cout << "[00000000_000000] ";
  }
}

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }
int Account::checkAmount(void) const { return _amount; }

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  _nbDeposits++;
  _totalNbDeposits++;
  _totalAmount += deposit;
  _amount += deposit;
  std::cout << "index:" << _accountIndex << ";p_amount:" << (_amount - deposit)
            << ";deposit:" << deposit << ";amount:" << _amount
            << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  if (_amount >= withdrawal) {
    _displayTimestamp();
    _totalNbWithdrawals++;
    _nbWithdrawals++;
    _amount -= withdrawal;
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << (_amount + withdrawal)
              << ";withdrawal:" << withdrawal << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
  }
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
            << ";p_amount:" << (_amount + withdrawal) << ";withdrawal:refused"
            << std::endl;
  return false;
}
