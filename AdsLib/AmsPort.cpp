
#include "AmsPort.h"
#include <cstring>

AmsPort::AmsPort()
	: tmms(DEFAULT_TIMEOUT),
	port(0)
{}

void AmsPort::AddNotification(NotificationId hash)
{
	std::lock_guard<std::mutex> lock(mutex);
	notifications.insert(hash);
}

void AmsPort::Close()
{
	std::lock_guard<std::mutex> lock(mutex);
	notifications.clear();
	port = 0;
}

void AmsPort::DelNotification(NotificationId hash)
{
	std::lock_guard<std::mutex> lock(mutex);
	notifications.erase(hash);
}

const std::set<NotificationId>& AmsPort::GetNotifications() const
{
	return notifications;
}

bool AmsPort::IsOpen() const
{
	return port;
}

uint16_t AmsPort::Open(uint16_t __port)
{
	port = __port;
	return port;
}