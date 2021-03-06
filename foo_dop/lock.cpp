#include "stdafx.h"

#include "lock.h"

class app_close_blocker_impl_t : public app_close_blocker
{
	virtual bool query()
	{
		return !in_ipod_sync::is_busy();
	}
};

bool in_ipod_sync::g_busy = false;

service_factory_single_t<app_close_blocker_impl_t> g_app_close_blocker_impl;