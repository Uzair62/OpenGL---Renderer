#pragma once
#include "cph.h"
#include "ClayPOT/macros.h"

enum EventType
{
	none = 0,
	WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
	AppTick, AppUpdate, AppRender,
	KeyPressed, KeyReleased, KeyTyped,
	MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

enum EventCategory
{
	None = 0,
	EventCategoryApplication = 1 << 0,
	EventCategoryInput = 1 << 1,
	EventCategoryKeyboard = 1 << 2,
	EventCategoryMouse = 1 << 3,
	EventCategoryMouseButton = 1 << 4
};


#define EVENT_CLASS_TYPE(type) EventType static GetStaticType() {return EventType::type;}\
                               virtual EventType GetEventType() const override {return GetStaticType();}\
                               const char* GetName() const override {return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


namespace cp
{
	class CP_API Event
	{

		friend class Dispatcher;
		
		public:
		virtual ~Event() = default;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual EventType GetEventType() const = 0;
		inline bool Handled() { return e_Handled; }
		

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	private:

		bool e_Handled;
		
	};

	class CP_API Dispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
		public:
			Dispatcher(Event& event) : cp_Event(event)
			{
			}
			template<typename T>
			bool dispatch(EventFn<T> func)
			{
				if (cp_Event.GetEventType() == T::GetStaticType())
				{
					cp_Event.e_Handled = func(*(T*)&cp_Event);
					return true;
				}
				return false;
			}
		private:
			Event& cp_Event;
	};
}