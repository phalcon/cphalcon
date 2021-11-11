
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
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
 * PSR-17 RequestFactory
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_RequestFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, RequestFactory, phalcon, http_message_requestfactory, phalcon_http_message_requestfactory_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(phalcon_http_message_requestfactory_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\requestfactoryinterface")));
	return SUCCESS;
}

/**
 * Create a new request.
 *
 * @param string                   $method
 * @param UriInterface|string|null $uri
 *
 * @return RequestInterface
 */
PHP_METHOD(Phalcon_Http_Message_RequestFactory, createRequest)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *uri, uri_sub;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		Z_PARAM_ZVAL(uri)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &uri);
	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
	}


	object_init_ex(return_value, phalcon_http_message_request_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 310, &method, uri);
	zephir_check_call_status();
	RETURN_MM();
}

