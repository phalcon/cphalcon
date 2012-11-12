
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"

/**
 * Phalcon\Http\Response\Headers
 *
 * This class is a bag to manage the response headers
 *
 */


/**
 * Phalcon\Http\Response\Cookies initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Response_Cookies){

	PHALCON_REGISTER_CLASS(Phalcon\\Http\\Response, Cookies, http_response_cookies, phalcon_http_response_cookies_method_entry, 0);

	zend_declare_property_null(phalcon_http_response_cookies_ce, SL("_cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Http\Response\Cookies constructor
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, __construct){


	phalcon_update_property_empty_array(phalcon_http_response_cookies_ce, this_ptr, SL("_cookies") TSRMLS_CC);
	
}

/**
 * Sets a header to be sent at the end of the request
 *
 * @param string $name
 * @param string $value
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, set){


	
}

/**
 * Gets a header value from the internal bag
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, get){


	
}

/**
 * Reset set cookies
 *
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, reset){

	zval *empty_array;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	phalcon_update_property_zval(this_ptr, SL("_cookies"), empty_array TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

