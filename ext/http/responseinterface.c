
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Http\ResponseInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_ResponseInterface){

	PHALCON_REGISTER_CLASS(Phalcon\\Http, ResponseInterface, http_responseinterface, phalcon_http_responseinterface_method_entry, ZEND_ACC_INTERFACE);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Http_ResponseInterface, setStatusCode){ }

PHP_METHOD(Phalcon_Http_ResponseInterface, getHeaders){ }

PHP_METHOD(Phalcon_Http_ResponseInterface, setHeader){ }

PHP_METHOD(Phalcon_Http_ResponseInterface, setRawHeader){ }

PHP_METHOD(Phalcon_Http_ResponseInterface, resetHeaders){ }

PHP_METHOD(Phalcon_Http_ResponseInterface, setExpires){ }

PHP_METHOD(Phalcon_Http_ResponseInterface, setNotModified){ }

PHP_METHOD(Phalcon_Http_ResponseInterface, setContentType){ }

PHP_METHOD(Phalcon_Http_ResponseInterface, redirect){ }

PHP_METHOD(Phalcon_Http_ResponseInterface, setContent){ }

PHP_METHOD(Phalcon_Http_ResponseInterface, appendContent){ }

PHP_METHOD(Phalcon_Http_ResponseInterface, getContent){ }

PHP_METHOD(Phalcon_Http_ResponseInterface, sendHeaders){ }

PHP_METHOD(Phalcon_Http_ResponseInterface, send){ }

