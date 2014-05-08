
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
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, setUserAgent, arginfo_phalcon_http_client_adapterinterface_setuseragent)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, setAuthentication, arginfo_phalcon_http_client_adapterinterface_setauthentication)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, setHeader, arginfo_phalcon_http_client_adapterinterface_setheader)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, setHeaders, arginfo_phalcon_http_client_adapterinterface_setheaders)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, setData, arginfo_phalcon_http_client_adapterinterface_setdata)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, setFile, arginfo_phalcon_http_client_adapterinterface_setfile)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, get, arginfo_phalcon_http_client_adapterinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, head, arginfo_phalcon_http_client_adapterinterface_head)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, post, arginfo_phalcon_http_client_adapterinterface_post)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, put, arginfo_phalcon_http_client_adapterinterface_put)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, delete, arginfo_phalcon_http_client_adapterinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, setUri, arginfo_phalcon_http_client_adapterinterface_seturi)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, setBaseUri, arginfo_phalcon_http_client_adapterinterface_setbaseuri)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, setMethod, arginfo_phalcon_http_client_adapterinterface_setmethod)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, setTimeOut, arginfo_phalcon_http_client_adapterinterface_settimeout)
	PHP_ABSTRACT_ME(Phalcon_Http_Client_Adapterinterface, send, NULL)
	PHP_FE_END
};


/**
 * Phalcon\Http\Client\AdapterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Client_AdapterInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Http\\Client, AdapterInterface, http_client_adapterinterface, phalcon_http_client_adapterinterface_method_entry);

	return SUCCESS;
}

PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, setUserAgent);
PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, setAuthentication);
PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, setHeader);
PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, setHeaders);
PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, setData);
PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, setFile);
PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, get);
PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, head);
PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, post);
PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, put);
PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, delete);
PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, setUri);
PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, setBaseUri);
PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, setMethod);
PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, setTimeOut);
PHALCON_DOC_METHOD(Phalcon_Http_Client_Adapterinterface, send);
