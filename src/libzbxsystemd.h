#ifndef LIBZBXSVC_H
#define LIBZBXSVC_H

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

// string builder
#include "sb.h"

// Zabbix source headers
#define HAVE_TIME_H 1
#include <sysinc.h>
#include <module.h>
#include <common.h>
#include <log.h>
#include <zbxjson.h>
#include <version.h>

// d-bus headers
#include <dbus/dbus.h>

#ifndef ZBX_MODULE_API_VERSION
#define ZBX_MODULE_API_VERSION  ZBX_MODULE_API_VERSION_ONE
#endif

#define LOG_PREFIX              "[systemd] "

// timeout set by host agent
int timeout;

// D-Bus api
#define DBUS_PROPERTIES_INTERFACE     "org.freedesktop.DBus.Properties"

int               dbus_check_error(DBusMessage*);
DBusMessage       *dbus_exchange_message(DBusMessage *msg);
DBusMessageIter   *dbus_get_property(
                                const char*,
                                const char*,
                                const char*,
                                const char*);

int dbus_marshall_property(
                AGENT_RESULT*,
                const char*,
                const char*,
                const char*,
                const char*);

// systemd api
#define SYSTEMD_SERVICE               "org.freedesktop.systemd1"
#define SYSTEMD_ROOT_NODE             "/org/freedesktop/systemd1"
#define SYSTEMD_MANAGER_INTERFACE     "org.freedesktop.systemd1.Manager"
#define SYSTEMD_UNIT_INTERFACE        "org.freedesktop.systemd1.Unit"

DBusConnection *conn;

int systemd_connect();
int systemd_get_unit(char *s, size_t n, const char* unit);


#endif
