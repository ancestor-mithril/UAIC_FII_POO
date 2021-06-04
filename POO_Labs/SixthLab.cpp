#include "SixthLab.h"

#include <algorithm>
#include <iostream>
#include <vector>

sixth_lab::Car::Car() : Car(100, 10, 100)
{
}

sixth_lab::Car::Car(const int fuelCapacity, const int fuelConsumption, const int speed) : _fuelCapacity(fuelCapacity), _fuelConsumption(fuelConsumption), _speed(speed)
{
}

sixth_lab::Dacia::Dacia() : Car(101, 11, 61)
{
}

int sixth_lab::Dacia::FuelCapacity()
{
	return _fuelCapacity - 3;
}

int sixth_lab::Dacia::FuelConsumption()
{
	return _fuelConsumption + 1;
}

int sixth_lab::Dacia::AverageSpeed(const Weather weather)
{
	return _speed / static_cast<int>(weather) - 1;
}

std::string sixth_lab::Dacia::Name()
{
	return "Dacia";
}

sixth_lab::Toyota::Toyota() : Car(102, 10, 63)
{
}

int sixth_lab::Toyota::FuelCapacity()
{
	return _fuelCapacity - 1;
}

int sixth_lab::Toyota::FuelConsumption()
{
	return _fuelConsumption + 2;
}

int sixth_lab::Toyota::AverageSpeed(const Weather weather)
{
	return _speed / static_cast<int>(weather) - 10;
}

std::string sixth_lab::Toyota::Name()
{
	return "Toyota";
}

sixth_lab::Mercedes::Mercedes() : Car(100, 9, 65)
{
}

int sixth_lab::Mercedes::FuelCapacity()
{
	return _fuelCapacity + 4;
}

int sixth_lab::Mercedes::FuelConsumption()
{
	return _fuelConsumption + 3;
}

int sixth_lab::Mercedes::AverageSpeed(const Weather weather)
{
	return _speed / static_cast<int>(weather) + 2;
}

std::string sixth_lab::Mercedes::Name()
{
	return "Mercedes";
}

sixth_lab::Ford::Ford() : Car(105, 25, 15)
{
}

int sixth_lab::Ford::FuelCapacity()
{
	return _fuelCapacity + 14;
}

int sixth_lab::Ford::FuelConsumption()
{
	return _fuelConsumption - 3;
}

int sixth_lab::Ford::AverageSpeed(const Weather weather)
{
	return _speed / static_cast<int>(weather) + 16;
}

std::string sixth_lab::Ford::Name()
{
	return "Ford";
}

sixth_lab::Mazda::Mazda() : Car(10, 2, 1)
{
}

int sixth_lab::Mazda::FuelCapacity()
{
	return _fuelCapacity + 140;
}

int sixth_lab::Mazda::FuelConsumption()
{
	return _fuelConsumption + 3;
}

int sixth_lab::Mazda::AverageSpeed(const Weather weather)
{
	return _speed / static_cast<int>(weather) + 16;
}

std::string sixth_lab::Mazda::Name()
{
	return "Mazda";
}

void sixth_lab::Circuit::sortFinalRanks()
{
	std::sort(_finalRanks.begin(), _finalRanks.end(), [](const std::pair<int, Car*> p1, const std::pair<int, Car*> p2)
		{
			return p1.first < p2.first;
		}
	);
}

void sixth_lab::Circuit::SetLength(int i)
{
	_length = i;
}

void sixth_lab::Circuit::SetWeather(Weather weather)
{
	_weather = weather;
}

void sixth_lab::Circuit::AddCar(Car* car)
{
	_cars.push_back(car);
}

void sixth_lab::Circuit::Race()
{
	std::vector<int> timeScore;
	
	for (auto car : _cars)
	{
		if (const auto time = _length / car->AverageSpeed(_weather); time * car->FuelConsumption() <= car->FuelCapacity())
		{
			timeScore.push_back(time);
			_finalRanks.emplace_back(std::make_pair(time, car));
		}
		else
		{
			_dropouts.push_back(car);
		}
	}
	sortFinalRanks();
}

void sixth_lab::Circuit::ShowFinalRanks()
{
	std::cout << "Final Ranks: " << std::endl;
	
	for (auto [time, car] : _finalRanks)
	{
		std::cout << car->Name() << " -> time record: " << time << std::endl;
	}
	
	std::cout << std::endl;
}

void sixth_lab::Circuit::ShowWhoDidNotFinis()
{
	std::cout << "Cars which did not finish: " << std::endl;
	
	for (auto car : _dropouts)
	{
		std::cout << car->Name() << ", ";
	}
	
	std::cout << std::endl;
}
