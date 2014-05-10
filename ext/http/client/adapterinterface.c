
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

#include "http/client/adapterinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_http_client_adapterinterface_ce;

static const zend_function_entry phalcon_http_client_adapterinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, setUserAgent, arginfo_phalcon_http_client_adapterinterface_setuseragent)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, setAuth, arginfo_phalcon_http_client_adapterinterface_setauth)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, setHeader, arginfo_phalcon_http_client_adapterinterface_setheader)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, setHeaders, arginfo_phalcon_http_client_adapterinterface_setheaders)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, setData, arginfo_phalcon_http_client_adapterinterface_setdata)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, setFile, arginfo_phalcon_http_client_adapterinterface_setfile)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, get, arginfo_phalcon_http_client_adapterinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, head, arginfo_phalcon_http_client_adapterinterface_head)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, post, arginfo_phalcon_http_client_adapterinterface_post)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, put, arginfo_phalcon_http_client_adapterinterface_put)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, delete, arginfo_phalcon_http_client_adapterinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, setUri, arginfo_phalcon_http_client_adapterinterface_seturi)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, setBaseUri, arginfo_phalcon_http_client_adapterinterface_setbaseuri)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, setMethod, arginfo_phalcon_http_client_adapterinterface_setmethod)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, setTimeOut, arginfo_phalcon_http_client_adapterinterface_settimeout)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_AdapterInterface, send, NULL)
	PHP_FE_END
};


/**
 * Phalcon\Http\Client\AdapterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Client_AdapterInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Http\\Client, AdapterInterface, http_client_adapterinterface, phalcon_http_client_adapterinterface_method_entry);

	return SUCCESS;
}

PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, setUserAgent);
PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, setAuth);
PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, setHeader);
PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, setHeaders);
PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, setData);
PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, setFile);
PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, get);
PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, head);
PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, post);
PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, put);
PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, delete);
PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, setUri);
PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, setBaseUri);
PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, setMethod);
PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, setTimeOut);
PHALCON_DOC_METHOD(Phalcon_Http_Client_AdapterInterface, send);
