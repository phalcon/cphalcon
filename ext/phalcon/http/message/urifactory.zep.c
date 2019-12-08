
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */
/**
 * PSR-17 UriFactory
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_UriFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, UriFactory, phalcon, http_message_urifactory, phalcon_http_message_urifactory_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(phalcon_http_message_urifactory_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\urifactoryinterface")));
	return SUCCESS;

}

/**
 * Returns a Locator object with all the helpers defined in anonynous
 * functions
 */
PHP_METHOD(Phalcon_Http_Message_UriFactory, createUri) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_EMPTY_STRING(&uri);
	}
	}


	object_init_ex(return_value, phalcon_http_message_uri_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 101, &uri);
	zephir_check_call_status();
	RETURN_MM();

}

