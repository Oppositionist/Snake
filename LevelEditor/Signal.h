#pragma once
#include <map>
#include<functional>

namespace csystem
{
	template <typename... Args>
	class Signal
	{
	public:
		Signal() : _currentId(0) {}

		// copy creates new signal
		Signal(Signal const& other) : _currentId(0) {}

		// connects a member function of a given object to this Signal
		template <typename F, typename... A>
		int ConnectMember(F&& f, A&& ... a) const 
		{
			int slotId = _currentId;
			_slots.insert({ slotId, std::bind(f, a...) });
			_currentId++;
			return slotId;
		}

		// connects a std::function to the signal. The returned
		// value can be used to disconnect the function again
		int Connect(std::function<void(Args...)> const& slot) const 
		{
			int slotId = _currentId;
			_slots.insert(std::make_pair(slotId, slot));
			_currentId++;
			return slotId;
		}

		// disconnects a previously connected function
		void Disconnect(int id) const {
			_slots.erase(id);
		}

		// disconnects all previously connected functions
		void DisconnectAll() const {
			_slots.clear();
		}


		// calls all connected functions
		void Emit(Args... p)
		{
			for (auto it : _slots) 
			{
				it.second(p...);
			}
		}
		
		// assignment creates new Signal 
		Signal& operator+=(std::function<void(Args...)> const& slot)
		{
			this->Connect(slot);
			return *this;
		}


		//// assignment creates new Signal
		//Signal& operator+=(const Signal& left, std::function<void(T1, T2)> const& slot)
		//{
		//	left.Connect(slot);
		//	return left;
		//}


	private:
		mutable std::map<int, std::function<void(Args...)>> _slots;
		mutable int _currentId;
	};

};

