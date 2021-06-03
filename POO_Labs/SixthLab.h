#pragma once
#include <string>
#include <vector>

namespace sixth_lab
{
	enum class Weather
	{
		Sunny = 1,
		Rain = 2,
		Snow = 3
	};

	class Car
	{
	protected:
		int _fuelCapacity;
		int _fuelConsumption;
		int _speed;
	public:
		Car();
		Car(int fuelCapacity, int fuelConsumption, int speed);
		Car(const Car& other) = default;
		Car(Car&& other) = default;
		Car& operator=(const Car& other) = default;
		Car& operator=(Car&& other) = default;
		virtual ~Car() = default;

		virtual int FuelCapacity() = 0;
		virtual int FuelConsumption() = 0;
		virtual int AverageSpeed(Weather) = 0;
		virtual std::string Name() = 0;
	};

	class Dacia final : public  Car
	{
	public:
		Dacia();
		Dacia(const Dacia& other) = default;
		Dacia(Dacia&& other) = default;
		Dacia& operator=(const Dacia& other) = default;
		Dacia& operator=(Dacia&& other) = default;
		~Dacia() override = default;

		int FuelCapacity() override;
		int FuelConsumption() override;
		int AverageSpeed(Weather weather) override;
		std::string Name() override;
	};

	class Toyota final : public  Car
	{
	public:
		Toyota();
		Toyota(const Toyota& other) = default;
		Toyota(Toyota&& other) = default;
		Toyota& operator=(const Toyota& other) = default;
		Toyota& operator=(Toyota&& other) = default;
		~Toyota() override = default;

		int FuelCapacity() override;
		int FuelConsumption() override;
		int AverageSpeed(Weather) override;
		std::string Name() override;
	};

	class Mercedes final : public  Car
	{
	public:
		Mercedes();
		Mercedes(const Mercedes& other) = default;
		Mercedes(Mercedes&& other) = default;
		Mercedes& operator=(const Mercedes& other) = default;
		Mercedes& operator=(Mercedes&& other) = default;
		~Mercedes() override = default;

		int FuelCapacity() override;
		int FuelConsumption() override;
		int AverageSpeed(Weather) override;
		std::string Name() override;
	};

	class Ford final : public  Car
	{
	public:
		Ford();
		Ford(const Ford& other) = default;
		Ford(Ford&& other) = default;
		Ford& operator=(const Ford& other) = default;
		Ford& operator=(Ford&& other) = default;
		~Ford() override = default;

		int FuelCapacity() override;
		int FuelConsumption() override;
		int AverageSpeed(Weather) override;
		std::string Name() override;
	};

	class Mazda final : public  Car
	{
	public:
		Mazda();
		Mazda(const Mazda& other) = default;
		Mazda(Mazda&& other) = default;
		Mazda& operator=(const Mazda& other) = default;
		Mazda& operator=(Mazda&& other) = default;
		~Mazda() override = default;

		int FuelCapacity() override;
		int FuelConsumption() override;
		int AverageSpeed(Weather) override;
		std::string Name() override;
	};

	class Circuit
	{
		Weather _weather = Weather::Sunny;
		int _length = 0;
		std::vector<Car*> _cars;
		std::vector<std::pair<int, Car*>> _finalRanks;
		std::vector<Car*> _dropouts;

		void sortFinalRanks();
	public:
		void SetLength(int i);
		void SetWeather(Weather weather);
		void AddCar(Car*);
		void Race();
		void ShowFinalRanks();
		void ShowWhoDidNotFinis();
	};
}

