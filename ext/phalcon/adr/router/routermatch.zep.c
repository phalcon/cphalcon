
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
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 *
 * Implementation of this file has also been heavily influenced by Autoroute.
 *
 * @link    https://pmjones.io/adr/
 *
 * @link    https://github.com/pmjones/AutoRoute
 * @license https://github.com/pmjones/AutoRoute/blob/2.x/LICENSE.md
 */
/**
 * Immutable result of a successful route match.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Router_RouterMatch)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Router, RouterMatch, phalcon, adr_router_routermatch, phalcon_adr_router_routermatch_method_entry, ZEND_ACC_FINAL_CLASS);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_adr_router_routermatch_ce, SL("action"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_adr_router_routermatch_ce, SL("attributes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_adr_router_routermatch_ce, SL("middleware"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_adr_router_routermatch_ce, SL("name"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	zend_class_implements(phalcon_adr_router_routermatch_ce, 1, phalcon_contracts_adr_router_routermatch_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Router_RouterMatch, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval attributes, middleware;
	zval action_zv, *attributes_param = NULL, *middleware_param = NULL, name_zv;
	zend_string *action = NULL, *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&action_zv);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&middleware);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("action", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("attributes", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("middleware", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("name", 4, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(action)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		ZEPHIR_Z_PARAM_ARRAY(middleware, middleware_param)
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		attributes_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		middleware_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&action_zv);
	ZVAL_STR_COPY(&action_zv, action);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!middleware_param) {
		ZEPHIR_INIT_VAR(&middleware);
		array_init(&middleware);
	} else {
		zephir_get_arrval(&middleware, middleware_param);
	}
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 370, &action_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 371, &attributes);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 372, &middleware);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 373, &name_zv);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_ADR_Router_RouterMatch, getAction)
{

	RETURN_MEMBER_TYPED(getThis(), "action", IS_STRING);
}

PHP_METHOD(Phalcon_ADR_Router_RouterMatch, getAttributes)
{

	RETURN_MEMBER_TYPED(getThis(), "attributes", IS_ARRAY);
}

PHP_METHOD(Phalcon_ADR_Router_RouterMatch, getMiddleware)
{

	RETURN_MEMBER_TYPED(getThis(), "middleware", IS_ARRAY);
}

PHP_METHOD(Phalcon_ADR_Router_RouterMatch, getName)
{

	RETURN_MEMBER(getThis(), "name");
}

