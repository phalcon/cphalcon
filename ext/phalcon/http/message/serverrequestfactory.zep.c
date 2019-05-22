
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
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_ServerRequestFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, ServerRequestFactory, phalcon, http_message_serverrequestfactory, phalcon_http_message_serverrequestfactory_method_entry, 0);

	zend_class_implements(phalcon_http_message_serverrequestfactory_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\serverrequestfactoryinterface")));
	return SUCCESS;

}

/**
 * Create a new server request.
 *
 * Note that server parameters are taken precisely as given - no parsing/processing
 * of the given values is performed. In particular, no attempt is made to
 * determine the HTTP method or URI, which must be provided explicitly.
 */
PHP_METHOD(Phalcon_Http_Message_ServerRequestFactory, createServerRequest) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval serverParams;
	zval *method_param = NULL, *uri, uri_sub, *serverParams_param = NULL;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&serverParams);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &method_param, &uri, &serverParams_param);

	zephir_get_strval(&method, method_param);
	if (!serverParams_param) {
		ZEPHIR_INIT_VAR(&serverParams);
		array_init(&serverParams);
	} else {
		zephir_get_arrval(&serverParams, serverParams_param);
	}


	object_init_ex(return_value, phalcon_http_message_serverrequest_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 303, &method, uri, &serverParams);
	zephir_check_call_status();
	RETURN_MM();

}

