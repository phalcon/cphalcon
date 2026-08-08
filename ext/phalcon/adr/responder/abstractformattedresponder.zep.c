
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
#include "kernel/array.h"
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
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * Base for content-type responders: composes Status, Redirect and Format
 * responders into a chain. Subclasses bind the formatter(s).
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_AbstractFormattedResponder)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\ADR\\Responder, AbstractFormattedResponder, phalcon, adr_responder_abstractformattedresponder, phalcon_adr_responder_chainresponder_ce, phalcon_adr_responder_abstractformattedresponder_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Responder_AbstractFormattedResponder, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *formatters_param = NULL, _1;
	zval formatters, _0;

	ZVAL_UNDEF(&formatters);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(formatters, formatters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &formatters_param);
	if (!formatters_param) {
		ZEPHIR_INIT_VAR(&formatters);
		array_init(&formatters);
	} else {
		zephir_get_arrval(&formatters, formatters_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_adr_responder_statusresponder_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 152);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_adr_responder_redirectresponder_ce);
	if (zephir_has_constructor(&_1)) {
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_adr_responder_formatresponder_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 153, &formatters);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_PARENT(NULL, phalcon_adr_responder_abstractformattedresponder_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

