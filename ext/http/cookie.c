
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
#include "kernel/operators.h"

/**
 * Phalcon\Http\Cookie
 *
 * Provide OO wrappers to
 */


/**
 * Phalcon\Http\Cookie initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Cookie){

	PHALCON_REGISTER_CLASS(Phalcon\\Http, Cookie, http_cookie, phalcon_http_cookie_method_entry, 0);

	zend_declare_property_bool(phalcon_http_cookie_ce, SL("_readed"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_value"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_expire"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_path"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_cookie_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Http\Cookie constructor
 */
PHP_METHOD(Phalcon_Http_Cookie, __construct){

	zval *name, *value = NULL, *expire = NULL, *path = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zzz", &name, &value, &expire, &path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!value) {
		PHALCON_INIT_NVAR(value);
	}
	
	if (!expire) {
		PHALCON_INIT_NVAR(expire);
		ZVAL_LONG(expire, 0);
	}
	
	if (!path) {
		PHALCON_INIT_NVAR(path);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_name"), name TSRMLS_CC);
	if (Z_TYPE_P(value) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_value"), value TSRMLS_CC);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_expire"), expire TSRMLS_CC);
	if (Z_TYPE_P(path) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_path"), path TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Http_Cookie, setDI){

	zval *dependency_injector;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Http_Cookie, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

PHP_METHOD(Phalcon_Http_Cookie, get){


	
}

/**
 * Sets the cookie's value
 *
 * @param string $value
 * @return Phalcon\Http\CookieInterface
 */
PHP_METHOD(Phalcon_Http_Cookie, setValue){

	zval *value;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &value) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_value"), value TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_readed"), 1 TSRMLS_CC);
	
	RETURN_CTORW(this_ptr);
}

PHP_METHOD(Phalcon_Http_Cookie, setExpiration){

	zval *expire;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &expire) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_expire"), expire TSRMLS_CC);
	
}

PHP_METHOD(Phalcon_Http_Cookie, getValue){

	zval *readed;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(readed);
	phalcon_read_property(&readed, this_ptr, SL("_readed"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(readed)) {
	}
	
	PHALCON_MM_RESTORE();
}

