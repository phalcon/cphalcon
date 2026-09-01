
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


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
 * Value object describing a redirect. An Action sets it on the payload; the
 * RedirectResponder turns it into a `Location` header and status code.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_Redirect)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Responder, Redirect, phalcon, adr_responder_redirect, phalcon_adr_responder_redirect_method_entry, 0);

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_adr_responder_redirect_ce, SL("external"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 302);
		zephir_declare_typed_property(phalcon_adr_responder_redirect_ce, SL("status"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_adr_responder_redirect_ce, SL("url"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Responder_Redirect, __construct)
{
	zend_bool external;
	zend_long status;
	zval url_zv, *status_param = NULL, *external_param = NULL, __$true, __$false, _0;
	zend_string *url = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("url", 3, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("status", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("external", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(url)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(status)
		Z_PARAM_BOOL(external)
	ZEND_PARSE_PARAMETERS_END();
	if (ZEND_NUM_ARGS() > 1) {
		status_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		external_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR(&url_zv, url);
	if (!status_param) {
		status = 302;
	} else {
		}
	if (!external_param) {
		external = 0;
	} else {
		}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 363, &url_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, status);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 364, &_0);
	if (external) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 365, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 365, &__$false);
	}
}

/**
 * Whether the target is an explicit external redirect. Internal (the
 * default) redirects refuse an absolute or protocol-relative target so a
 * request-derived value cannot become an open redirect (CWE-601).
 */
PHP_METHOD(Phalcon_ADR_Responder_Redirect, external)
{

	RETURN_MEMBER(getThis(), "external");
}

PHP_METHOD(Phalcon_ADR_Responder_Redirect, permanent)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval url_zv, _0;
	zend_string *url = NULL;

	ZVAL_UNDEF(&url_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(url)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&url_zv);
	ZVAL_STR_COPY(&url_zv, url);
	object_init_ex(return_value, phalcon_adr_responder_redirect_ce);
	ZVAL_LONG(&_0, 301);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 335, &url_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Responder_Redirect, seeOther)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval url_zv, _0;
	zend_string *url = NULL;

	ZVAL_UNDEF(&url_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(url)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&url_zv);
	ZVAL_STR_COPY(&url_zv, url);
	object_init_ex(return_value, phalcon_adr_responder_redirect_ce);
	ZVAL_LONG(&_0, 303);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 335, &url_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Responder_Redirect, temporary)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval url_zv, _0;
	zend_string *url = NULL;

	ZVAL_UNDEF(&url_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(url)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&url_zv);
	ZVAL_STR_COPY(&url_zv, url);
	object_init_ex(return_value, phalcon_adr_responder_redirect_ce);
	ZVAL_LONG(&_0, 302);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 335, &url_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Responder_Redirect, status)
{

	RETURN_MEMBER_TYPED(getThis(), "status", IS_LONG);
}

PHP_METHOD(Phalcon_ADR_Responder_Redirect, url)
{

	RETURN_MEMBER_TYPED(getThis(), "url", IS_STRING);
}

