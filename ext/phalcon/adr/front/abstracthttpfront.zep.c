
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
#include "kernel/memory.h"
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
 * Boots a container, builds the Application, handles the request and emits the
 * response. Userland front controllers override `loadEnvironment()`,
 * `registerProviders()` and optionally `getApplication()`; bootstrap is
 * `exit((new AppFront(dirname(__DIR__)))->run());`.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Front_AbstractHttpFront)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Front, AbstractHttpFront, phalcon, adr_front_abstracthttpfront, phalcon_adr_front_abstracthttpfront_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var Container|null
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_adr_front_abstracthttpfront_ce, SL("container"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Container\\Container"));
	}

	/**
	 * @var string
	 */
	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_adr_front_abstracthttpfront_ce, SL("projectRoot"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	zend_class_implements(phalcon_adr_front_abstracthttpfront_ce, 1, phalcon_contracts_front_frontcontroller_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, __construct)
{
	zval projectRoot_zv;
	zend_string *projectRoot = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&projectRoot_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("projectRoot", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(projectRoot)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&projectRoot_zv, projectRoot);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 247, &projectRoot_zv);
}

/**
 * Builds the container, loads the environment and registers the providers,
 * returning the container for consumers that need it before (or instead
 * of) `run()`. The container is built once and cached, so calling `boot()`
 * and then `run()` reuses the same instance.
 */
PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, boot)
{
	zval _0, _1$$3, _2$$3, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 248, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "buildcontainer", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 248, &_1$$3);
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 248, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadenvironment", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 248, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerproviders", NULL, 0, &_3$$3);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "container");
}

/**
 * @return int<0,254>
 */
PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, run)
{
	zval application, container, exception, request, response, _2, _0$$3, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&application);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&container, this_ptr, "boot", NULL, 218);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "Phalcon\\Contracts\\Http\\AttributeRequest");
		ZEPHIR_CALL_METHOD(&request, &container, "get", NULL, 0, &_0$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&application, this_ptr, "getapplication", NULL, 0, &container);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&response, &application, "handle", NULL, 0, &request);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "Phalcon\\Contracts\\ADR\\Emitter\\Emitter");
		ZEPHIR_CALL_METHOD(&_1$$3, &container, "get", NULL, 0, &_0$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "emit", NULL, 0, &response);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM_LONG(0);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_OBJ(&_2, EG(exception));
		Z_ADDREF_P(&_2);
		if (zephir_is_instance_of(&_2, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&exception, &_2);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "handlebooterror", NULL, 0, &exception);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	RETURN_MM_LONG(0);
}

PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, buildContainer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_container_container_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 219);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds the Application the front will hand the request to. Override to
 * configure it (`setBaseNamespace()`/`secureWith()`) or to wire a different
 * `Phalcon\Contracts\ADR\Application` implementation.
 */
PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, getApplication)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub;

	ZVAL_UNDEF(&container_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_container_container_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &container);
	object_init_ex(return_value, phalcon_adr_application_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 220, container);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, handleBootError)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, _1, _2$$3, _3$$3;

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &exception);
	zephir_cast_to_string(&_0, exception);
	ZEPHIR_CALL_FUNCTION(NULL, "error_log", NULL, 221, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "headers_sent", NULL, 222);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZVAL_LONG(&_2$$3, 500);
		ZEPHIR_CALL_FUNCTION(NULL, "http_response_code", NULL, 223, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Content-Type: text/plain; charset=utf-8");
		ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 224, &_3$$3);
		zephir_check_call_status();
		php_printf("%s", "Internal Server Error\n");
	}
	RETURN_MM_LONG(1);
}

PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, loadEnvironment)
{
	zval *container, container_sub;

	ZVAL_UNDEF(&container_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_container_container_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &container);
}

PHP_METHOD(Phalcon_ADR_Front_AbstractHttpFront, registerProviders)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, _0;

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_container_container_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &container);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_adr_container_adrprovider_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(NULL, &_0, "provide", NULL, 225, container);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

