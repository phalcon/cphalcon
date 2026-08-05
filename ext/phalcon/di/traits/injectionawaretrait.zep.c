
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This abstract class offers common access to the DI in a class
 *
 * Class AbstractInjectionAware
 *
 * @package Phalcon\Di
 *
 * @property object $container
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_Traits_InjectionAwareTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Di\\Traits, InjectionAwareTrait, phalcon, di_traits_injectionawaretrait, phalcon_di_traits_injectionawaretrait_method_entry);

	/**
	 * Dependency Injector
	 *
	 * @var object|null
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_di_traits_injectionawaretrait_ce, SL("container"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Di\\DiInterface"));
	}

	return SUCCESS;
}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Di_Traits_InjectionAwareTrait, getDI)
{

	RETURN_MEMBER(getThis(), "container");
}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Di_Traits_InjectionAwareTrait, setDI)
{
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &container);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 665, container);
}

/**
 * @param string $exceptionClass
 *
 * @return void
 */
PHP_METHOD(Phalcon_Di_Traits_InjectionAwareTrait, checkContainer)
{
	zval _4$$3;
	zend_class_entry *_3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval exceptionClass_zv, message_zv, *code_param = NULL, _0, _1$$3, _2$$3, _5$$3;
	zend_string *exceptionClass = NULL, *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exceptionClass_zv);
	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_4$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(exceptionClass)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(code)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		code_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&exceptionClass_zv);
	ZVAL_STR_COPY(&exceptionClass_zv, exceptionClass);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	if (!code_param) {
		code = 0;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 665, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fetch_safe_class(&_2$$3, &exceptionClass_zv);
		_3$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_2$$3), Z_STRLEN_P(&_2$$3), ZEND_FETCH_CLASS_AUTO);
		if(!_3$$3) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_1$$3, _3$$3);
		ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&_1$$3);
		zephir_check_call_status();
		if (zephir_has_constructor(&_1$$3)) {
			ZEPHIR_INIT_VAR(&_4$$3);
			ZEPHIR_CONCAT_SV(&_4$$3, "A dependency injection container is required to access ", &message_zv);
			ZVAL_LONG(&_5$$3, code);
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &_4$$3, &_5$$3);
			zephir_check_call_status();
		}

		zephir_throw_exception_debug(&_1$$3, "phalcon/Di/Traits/InjectionAwareTrait.zep", 64);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

