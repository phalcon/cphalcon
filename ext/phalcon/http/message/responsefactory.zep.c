
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_ResponseFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, ResponseFactory, phalcon, http_message_responsefactory, phalcon_http_message_responsefactory_method_entry, 0);

	zend_class_implements(phalcon_http_message_responsefactory_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\responsefactoryinterface")));
	return SUCCESS;

}

/**
 * Create a new response.
 *
 * @param int $code The HTTP status code. Defaults to 200.
 * @param string $reasonPhrase The reason phrase to associate with the status code
 *     in the generated response. If none is provided, implementations MAY use
 *     the defaults as suggested in the HTTP specification.
 */
PHP_METHOD(Phalcon_Http_Message_ResponseFactory, createResponse) {

	zval reasonPhrase;
	zval *code_param = NULL, *reasonPhrase_param = NULL, factory, newInstance, _0;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&reasonPhrase);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &code_param, &reasonPhrase_param);

	if (!code_param) {
		code = 200;
	} else {
		code = zephir_get_intval(code_param);
	}
	if (!reasonPhrase_param) {
		ZEPHIR_INIT_VAR(&reasonPhrase);
		ZVAL_STRING(&reasonPhrase, "");
	} else {
		zephir_get_strval(&reasonPhrase, reasonPhrase_param);
	}


	ZEPHIR_INIT_VAR(&factory);
	object_init_ex(&factory, phalcon_http_message_response_ce);
	ZEPHIR_CALL_METHOD(NULL, &factory, "__construct", NULL, 236);
	zephir_check_call_status();
	ZVAL_LONG(&_0, code);
	ZEPHIR_CALL_METHOD(&newInstance, &factory, "withstatus", NULL, 237, &_0, &reasonPhrase);
	zephir_check_call_status();
	RETURN_CCTOR(&newInstance);

}

