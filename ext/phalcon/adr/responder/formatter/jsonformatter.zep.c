
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * Renders a payload as JSON.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_Formatter_JsonFormatter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Responder\\Formatter, JsonFormatter, phalcon, adr_responder_formatter_jsonformatter, phalcon_adr_responder_formatter_jsonformatter_method_entry, 0);

	zend_class_implements(phalcon_adr_responder_formatter_jsonformatter_ce, 1, phalcon_contracts_adr_responder_formatter_formatter_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Responder_Formatter_JsonFormatter, accepts)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval acceptHeader_zv, _0, _1, _3, _4;
	zend_string *acceptHeader = NULL;

	ZVAL_UNDEF(&acceptHeader_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(acceptHeader)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&acceptHeader_zv);
	ZVAL_STR_COPY(&acceptHeader_zv, acceptHeader);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "application/json");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &acceptHeader_zv, &_0, 0 );
	_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_1);
	if (!(_2)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "+json");
		ZEPHIR_INIT_VAR(&_4);
		zephir_fast_strpos(&_4, &acceptHeader_zv, &_3, 0 );
		_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_4);
	}
	RETURN_MM_BOOL(_2);
}

PHP_METHOD(Phalcon_ADR_Responder_Formatter_JsonFormatter, contentType)
{

	RETURN_STRING("application/json");
}

PHP_METHOD(Phalcon_ADR_Responder_Formatter_JsonFormatter, format)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *payload, payload_sub, content, _0;

	ZVAL_UNDEF(&payload_sub);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(payload, zephir_get_internal_ce(SL("phalcon\\contracts\\adr\\payload\\payload")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &payload);
	ZEPHIR_CALL_METHOD(&content, payload, "getresult", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&content) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&content, payload, "getmessages", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_json_encode(&_0, &content, 0 );
	zephir_cast_to_string(&_1, &_0);
	RETURN_CTOR(&_1);
}

