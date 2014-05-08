
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_HTTP_CLIENT_ADAPTERINTERFACE_H
#define PHALCON_HTTP_CLIENT_ADAPTERINTERFACE_H

#include "php_phalcon.h"

extern zend_class_entry *phalcon_http_client_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Client_Adapterinterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapterinterface_setuseragent, 0, 0, 1)
	ZEND_ARG_INFO(0, useragent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapterinterface_setauthentication, 0, 0, 2)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, authtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapterinterface_setheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapterinterface_setheaders, 0, 0, 1)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapterinterface_setdata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapterinterface_setfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapterinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapterinterface_head, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapterinterface_post, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapterinterface_put, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapterinterface_delete, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapterinterface_setbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapterinterface_seturi, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapterinterface_settimeout, 0, 0, 1)
	ZEND_ARG_INFO(0, time)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapterinterface_setmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

#endif /* PHALCON_HTTP_CLIENT_ADAPTERINTERFACE_H */
