#pragma once

#include <memory>
#include <KeplerEngine/System/System.h>

namespace KE
{
	class GameObject;

	class Component
	{
	public:

		virtual ~Component() = default;

	protected:

		virtual void Init() = 0;
		virtual void OnBegin() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnDisplay() = 0;

		bool m_Begin;
		std::weak_ptr<GameObject> m_ParentObject;
		friend class GameObject;
		friend class System;

	};
}