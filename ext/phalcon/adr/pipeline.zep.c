
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
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
 * Self-recursive middleware runner. It is itself a Handler: it carries an index
 * and hands a new Pipeline (advanced by one) forward as the `next` handler, so
 * `next` is always a real Handler - no anonymous classes or callables.
 *
 * When the middleware is exhausted it invokes the terminal handler (the Action).
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Pipeline)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR, Pipeline, phalcon, adr_pipeline, phalcon_adr_pipeline_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var int
	 */
	zend_declare_property_null(phalcon_adr_pipeline_ce, SL("index"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_adr_pipeline_ce, SL("middleware"), ZEND_ACC_PROTECTED);
	/**
	 * @var Handler
	 */
	zend_declare_property_null(phalcon_adr_pipeline_ce, SL("terminal"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_adr_pipeline_ce, 1, phalcon_contracts_adr_handler_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Pipeline, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long index;
	zval *middleware_param = NULL, *terminal, terminal_sub, *index_param = NULL, _0;
	zval middleware;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&middleware);
	ZVAL_UNDEF(&terminal_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("middleware", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("terminal", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("index", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		ZEPHIR_Z_PARAM_ARRAY(middleware, middleware_param)
		Z_PARAM_OBJECT_OF_CLASS(terminal, phalcon_contracts_adr_handler_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &middleware_param, &terminal, &index_param);
	zephir_get_arrval(&middleware, middleware_param);
	if (!index_param) {
		index = 0;
	} else {
		}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 350, &middleware);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 351, terminal);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, index);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 352, &_0);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_ADR_Pipeline, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, mw, next, _0, _1, _3, _4, _5, _6, _7, _8, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&mw);
	ZVAL_UNDEF(&next);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("index", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("middleware", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("terminal", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_contracts_http_attributerequest_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &request);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 352, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 350, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GE_LONG(&_0, zephir_fast_count_int(&_1))) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_2, 351, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_2$$3, "__invoke", NULL, 0, request);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 350, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&mw);
	zephir_memory_observe(&_4);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 352, PH_NOISY_CC);
	zephir_array_fetch(&mw, &_3, &_4, PH_NOISY, "phalcon/ADR/Pipeline.zep", 59);
	ZEPHIR_INIT_VAR(&next);
	object_init_ex(&next, phalcon_adr_pipeline_ce);
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_1, 350, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_2, 351, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_7, this_ptr, _zephir_prop_0, 352, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_8, (zephir_get_numberval(&_7) + 1));
	ZEPHIR_CALL_METHOD(NULL, &next, "__construct", NULL, 307, &_5, &_6, &_8);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&mw, "__invoke", NULL, 0, request, &next);
	zephir_check_call_status();
	RETURN_MM();
}

