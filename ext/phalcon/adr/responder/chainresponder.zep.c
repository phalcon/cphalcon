
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


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
 * Composes single-purpose responders. Each link receives the request, the
 * response threaded so far, and the payload, and returns the response.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_ChainResponder)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Responder, ChainResponder, phalcon, adr_responder_chainresponder, phalcon_adr_responder_chainresponder_method_entry, 0);

	/**
	 * @var Responder[]
	 */
	zend_declare_property_null(phalcon_adr_responder_chainresponder_ce, SL("links"), ZEND_ACC_PROTECTED);
	phalcon_adr_responder_chainresponder_ce->create_object = zephir_init_properties_Phalcon_ADR_Responder_ChainResponder;

	zend_class_implements(phalcon_adr_responder_chainresponder_ce, 1, phalcon_contracts_adr_responder_responder_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Responder_ChainResponder, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *links_param = NULL;
	zval links;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&links);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("links", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(links, links_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &links_param);
	if (!links_param) {
		ZEPHIR_INIT_VAR(&links);
		array_init(&links);
	} else {
		zephir_get_arrval(&links, links_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 91, &links);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_ADR_Responder_ChainResponder, __invoke)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *response = NULL, response_sub, *payload, payload_sub, link, _0, *_1, _3, _2$$3, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&payload_sub);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("links", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_http_requestinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(response, phalcon_http_responseinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(payload, phalcon_contracts_adr_payload_payload_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &request, &response, &payload);
	ZEPHIR_SEPARATE_PARAM(response);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 91, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/ADR/Responder/ChainResponder.zep", 48);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&link);
			ZVAL_COPY(&link, _1);
			ZEPHIR_CALL_METHOD(&_2$$3, &link, "__invoke", NULL, 0, request, response, payload);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(response, &_2$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&link, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$4, &link, "__invoke", NULL, 0, request, response, payload);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(response, &_5$$4);
		}
	}
	ZEPHIR_INIT_NVAR(&link);
	RETVAL_ZVAL(response, 1, 0);
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Responder_ChainResponder, with)
{
	zval links;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *link, link_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&link_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&links);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("links", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(link, phalcon_contracts_adr_responder_responder_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &link);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 91, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&links, &_0);
	zephir_array_append(&links, link, PH_SEPARATE, "phalcon/ADR/Responder/ChainResponder.zep", 56);
	object_init_ex(return_value, phalcon_adr_responder_chainresponder_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 80, &links);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_ADR_Responder_ChainResponder(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("links"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("links"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

