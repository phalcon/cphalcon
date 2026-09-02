
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
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
 * Sets the response HTTP status code from the payload status, via StatusMapper.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_StatusResponder)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Responder, StatusResponder, phalcon, adr_responder_statusresponder, phalcon_adr_responder_statusresponder_method_entry, 0);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_adr_responder_statusresponder_ce, SL("mapper"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\ADR\\Responder\\StatusMapper"));
	}

	zend_class_implements(phalcon_adr_responder_statusresponder_ce, 1, phalcon_contracts_adr_responder_responder_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Responder_StatusResponder, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mapper = NULL, mapper_sub, __$null, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mapper_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("mapper", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(mapper, zephir_get_internal_ce(SL("phalcon\\adr\\responder\\statusmapper")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &mapper);
	if (!mapper) {
		mapper = &mapper_sub;
		mapper = &__$null;
	}
	if (Z_TYPE_P(mapper) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_adr_responder_statusmapper_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 336);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 367, &_0$$3);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 367, mapper);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_ADR_Responder_StatusResponder, __invoke)
{
	zval _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *response, response_sub, *payload, payload_sub, status, _0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&payload_sub);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("mapper", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("phalcon\\http\\requestinterface")))
		Z_PARAM_OBJECT_OF_CLASS(response, zephir_get_internal_ce(SL("phalcon\\http\\responseinterface")))
		Z_PARAM_OBJECT_OF_CLASS(payload, zephir_get_internal_ce(SL("phalcon\\contracts\\adr\\payload\\payload")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &request, &response, &payload);
	ZEPHIR_CALL_METHOD(&status, payload, "getstatus", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&status) != IS_NULL) {
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 367, PH_NOISY_CC | PH_READONLY);
		zephir_cast_to_string(&_2$$3, &status);
		ZEPHIR_CALL_METHOD(&_1$$3, &_0$$3, "tohttpcode", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, response, "setstatuscode", NULL, 0, &_1$$3);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(response, 1, 0);
	RETURN_MM();
}

