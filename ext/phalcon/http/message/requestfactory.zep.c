
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
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_RequestFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, RequestFactory, phalcon, http_message_requestfactory, phalcon_http_message_requestfactory_method_entry, 0);

	zend_class_implements(phalcon_http_message_requestfactory_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\requestfactoryinterface")));
	return SUCCESS;

}

/**
 * Create a new request.
 */
PHP_METHOD(Phalcon_Http_Message_RequestFactory, createRequest) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *uri, uri_sub;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &uri);

	zephir_get_strval(&method, method_param);


	object_init_ex(return_value, phalcon_http_message_request_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 227, &method, uri);
	zephir_check_call_status();
	RETURN_MM();

}

