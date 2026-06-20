
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, which is a
 * Composer dependency, and from service-interop and resolver-interop. The
 * latter two are copied and re-implemented here: service-interop is not yet
 * published on Packagist, and resolver-interop requires PHP 8.4 (this project
 * targets PHP 8.1). Once both packages become available and compatible, the
 * copies will be replaced with the actual Composer dependencies.
 *
 * @link    https://github.com/capsulephp/di
 * @license https://github.com/capsulephp/di/blob/3.x/LICENSE.md
 *
 * @link    https://github.com/ioc-interop/interface
 * @license https://github.com/ioc-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/service-interop/interface
 * @license https://github.com/service-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/resolver-interop/interface/tree/1.x
 * @license https://github.com/resolver-interop/interface/blob/1.x/LICENSE.md
 */
ZEPHIR_INIT_CLASS(Phalcon_Container_Definition_ServiceDefinition)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Container\\Definition, ServiceDefinition, phalcon, container_definition_servicedefinition, phalcon_container_definition_servicedefinition_method_entry, 0);

	/**
	 * @phpstan-var array<array-key, mixed>
	 * @var array
	 */
	zend_declare_property_null(phalcon_container_definition_servicedefinition_ce, SL("arguments"), ZEND_ACC_PROTECTED);
	/**
	 * @var object | null
	 */
	zend_declare_property_null(phalcon_container_definition_servicedefinition_ce, SL("container"), ZEND_ACC_PROTECTED);
	/**
	 * @var string | null
	 */
	zend_declare_property_null(phalcon_container_definition_servicedefinition_ce, SL("className"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_container_definition_servicedefinition_ce, SL("constructorArgs"), ZEND_ACC_PROTECTED);
	/**
	 * @var array<array-key, callable>
	 */
	zend_declare_property_null(phalcon_container_definition_servicedefinition_ce, SL("extenders"), ZEND_ACC_PROTECTED);
	/**
	 * @var callable | null
	 */
	zend_declare_property_null(phalcon_container_definition_servicedefinition_ce, SL("factory"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_container_definition_servicedefinition_ce, SL("frozen"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_container_definition_servicedefinition_ce, SL("isCacheable"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_container_definition_servicedefinition_ce, SL("lifetime"), "SCOPED", ZEND_ACC_PROTECTED);
	/**
	 *  @var mixed
	 */
	zend_declare_property_null(phalcon_container_definition_servicedefinition_ce, SL("raw"), ZEND_ACC_PROTECTED);
	/**
	 *  @var string
	 */
	zend_declare_property_null(phalcon_container_definition_servicedefinition_ce, SL("serviceName"), ZEND_ACC_PROTECTED);
	/**
	 * @phpstan-var array<array-key, string>
	 * @var array
	 */
	zend_declare_property_null(phalcon_container_definition_servicedefinition_ce, SL("tags"), ZEND_ACC_PROTECTED);
	/**
	 *  @var string
	 */
	zend_declare_property_null(phalcon_container_definition_servicedefinition_ce, SL("type"), ZEND_ACC_PROTECTED);
	phalcon_container_definition_servicedefinition_ce->create_object = zephir_init_properties_Phalcon_Container_Definition_ServiceDefinition;

	return SUCCESS;
}

PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, __construct)
{
	zval serviceName_zv, type_zv, *raw = NULL, raw_sub, __$null;
	zend_string *serviceName = NULL, *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName_zv);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&raw_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(serviceName)
		Z_PARAM_STR(type)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(raw)
	ZEND_PARSE_PARAMETERS_END();
	if (ZEND_NUM_ARGS() > 2) {
		raw = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR(&serviceName_zv, serviceName);
	ZVAL_STR(&type_zv, type);
	if (!raw) {
		raw = &raw_sub;
		raw = &__$null;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("serviceName"), &serviceName_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("raw"), raw);
}

/**
 * Adds an extender
 *
 * @param callable $extender
 *
 * @return static
 * @throws FrozenDefinition
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, addExtender)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *extender, extender_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extender_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(extender)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &extender);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkfrozen", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("extenders"), extender);
	RETURN_THIS();
}

/**
 * Adds a tag
 *
 * @param string $tag
 *
 * @return static
 * @throws FrozenDefinition
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, addTag)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tag_zv, __$true, _0, _1, _2, _4, _5$$4, _6$$4;
	zend_string *tag = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(tag)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tag_zv);
	ZVAL_STR_COPY(&tag_zv, tag);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkfrozen", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("tags"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "in_array", NULL, 79, &tag_zv, &_0, &__$true);
	zephir_check_call_status();
	if (!zephir_is_true(&_1)) {
		zephir_update_property_array_append(this_ptr, SL("tags"), &tag_zv);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	_3 = Z_TYPE_P(&_2) != IS_NULL;
	if (_3) {
		zephir_read_property(&_4, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		_3 = (zephir_method_exists_ex(&_4, ZEND_STRL("settag")) == SUCCESS);
	}
	if (_3) {
		zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "settag", NULL, 0, &tag_zv, &_6$$4);
		zephir_check_call_status();
	}
	RETURN_THIS();
}

/**
 * Builds a service and returns the instance back
 *
 * @param object $container
 *
 * @return object
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, buildService)
{
	zend_bool _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, args, className, extender, factory, instance, reflection, _0, _5, *_6, _8, _1$$3, _2$$4, _3$$4, _4$$4, _7$$5, _10$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&extender);
	ZVAL_UNDEF(&factory);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(container)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &container);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasfactory", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("factory"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&factory, &_1$$3);
		ZEPHIR_CALL_ZVAL_FUNCTION(&instance, &factory, NULL, 0, container);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("className"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_3$$4) != IS_NULL) {
			ZEPHIR_OBS_NVAR(&_2$$4);
			zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("className"), PH_NOISY_CC);
		} else {
			ZEPHIR_OBS_NVAR(&_2$$4);
			zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC);
		}
		ZEPHIR_CPY_WRT(&className, &_2$$4);
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("constructorArgs"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&args, this_ptr, "resolveargs", NULL, 388, container, &_4$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&reflection);
		object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
		ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 266, &className);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&instance, &reflection, "newinstanceargs", NULL, 389, &args);
		zephir_check_call_status();
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("extenders"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_5, 0, "phalcon/Container/Definition/ServiceDefinition.zep", 177);
	if (Z_TYPE_P(&_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5), _6)
		{
			ZEPHIR_INIT_NVAR(&extender);
			ZVAL_COPY(&extender, _6);
			ZEPHIR_CALL_ZVAL_FUNCTION(&_7$$5, &extender, NULL, 0, &instance, container);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&instance, &_7$$5);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_5, "rewind", NULL, 0);
		zephir_check_call_status();
		_9 = 1;
		while (1) {
			if (_9) {
				_9 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_5, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_8, &_5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&extender, &_5, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_ZVAL_FUNCTION(&_10$$6, &extender, NULL, 0, &instance, container);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&instance, &_10$$6);
		}
	}
	ZEPHIR_INIT_NVAR(&extender);
	RETURN_CCTOR(&instance);
}

/**
 * Freezes the container
 *
 * @param object $container
 *
 * @return void
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, freeze)
{
	zend_bool _2, _3, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, __$true, __$false, className, constructor, params, reflection, _0, _1, _4, _5, _7, _8$$4, _9$$4, _10$$5, _11$$5, _12$$5, _13$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&constructor);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(container)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &container);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("frozen"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
	_2 = ZEPHIR_IS_STRING_IDENTICAL(&_1, "string");
	if (_2) {
		_2 = (zephir_method_exists_ex(container, ZEND_STRL("isautowireenabled")) == SUCCESS);
	}
	_3 = _2;
	if (_3) {
		ZEPHIR_CALL_METHOD(&_4, container, "isautowireenabled", NULL, 0);
		zephir_check_call_status();
		_3 = zephir_is_true(&_4);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_8$$4);
		zephir_read_property(&_9$$4, this_ptr, ZEND_STRL("className"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_9$$4) != IS_NULL) {
			ZEPHIR_OBS_NVAR(&_8$$4);
			zephir_read_property(&_8$$4, this_ptr, ZEND_STRL("className"), PH_NOISY_CC);
		} else {
			ZEPHIR_OBS_NVAR(&_8$$4);
			zephir_read_property(&_8$$4, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC);
		}
		ZEPHIR_CPY_WRT(&className, &_8$$4);
		ZEPHIR_INIT_VAR(&reflection);
		object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
		ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 266, &className);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&constructor, &reflection, "getconstructor", NULL, 390);
		zephir_check_call_status();
		if (Z_TYPE_P(&constructor) != IS_NULL) {
			ZEPHIR_CALL_METHOD(&params, &constructor, "getparameters", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&params);
			array_init(&params);
		}
		if ((zephir_method_exists_ex(container, ZEND_STRL("getresolver")) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_10$$5, container, "getresolver", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_11$$5, &_10$$5, "resolveparameters", NULL, 0, container, &params, &_12$$5);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("constructorArgs"), &_11$$5);
		}
	} else {
		zephir_read_property(&_5, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		_6 = ZEPHIR_IS_STRING_IDENTICAL(&_5, "string");
		if (_6) {
			zephir_memory_observe(&_7);
			zephir_read_property(&_7, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC);
			_6 = !(ZEPHIR_IS_EMPTY(&_7));
		}
		if (_6) {
			zephir_read_property(&_13$$6, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval(this_ptr, ZEND_STRL("constructorArgs"), &_13$$6);
		}
	}
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("frozen"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("frozen"), &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the arguments
 *
 * @return array
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, getArguments)
{

	RETURN_MEMBER_TYPED(getThis(), "arguments", IS_ARRAY);
}

/**
 * Returns the class
 *
 * @return string
 * @throws NoClassSet
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, getClass)
{
	zval _0, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("className"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_container_exceptions_noclassset_ce);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 391, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Container/Definition/ServiceDefinition.zep", 239);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_MEMBER_TYPED(getThis(), "className", IS_STRING);
}

/**
 * Returns the constructor arguments
 *
 * @return array
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, getConstructorArgs)
{

	RETURN_MEMBER_TYPED(getThis(), "constructorArgs", IS_ARRAY);
}

/**
 * Returns the extenders
 *
 * @return array<array-key, callable>
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, getExtenders)
{

	RETURN_MEMBER_TYPED(getThis(), "extenders", IS_ARRAY);
}

/**
 * Returns the factory
 *
 * @return callable
 * @throws NoFactorySet
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, getFactory)
{
	zval _0, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("factory"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_container_exceptions_nofactoryset_ce);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 392, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Container/Definition/ServiceDefinition.zep", 274);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_MEMBER(getThis(), "factory");
}

/**
 * Returns the lifetime
 *
 * @return string
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, getLifetime)
{

	RETURN_MEMBER_TYPED(getThis(), "lifetime", IS_STRING);
}

/**
 * Returns the name of the service
 *
 * @return string
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, getServiceName)
{

	RETURN_MEMBER_TYPED(getThis(), "serviceName", IS_STRING);
}

/**
 * Returns the tags
 *
 * @return array<array-key, string>
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, getTags)
{

	RETURN_MEMBER_TYPED(getThis(), "tags", IS_ARRAY);
}

/**
 * Returns the type
 *
 * @return string
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, getType)
{

	RETURN_MEMBER_TYPED(getThis(), "type", IS_STRING);
}

/**
 * Does it have a class
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, hasClass)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("className"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(Z_TYPE_P(&_0) != IS_NULL);
}

/**
 * Do we have extenders
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, hasExtenders)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("extenders"), PH_NOISY_CC);
	RETURN_MM_BOOL(!(ZEPHIR_IS_EMPTY(&_0)));
}

/**
 * Does it have a factory
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, hasFactory)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("factory"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(Z_TYPE_P(&_0) != IS_NULL);
}

/**
 * Is it cacheable
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, isCacheable)
{
	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("isCacheable"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_is_true(&_0);
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("frozen"), PH_NOISY_CC | PH_READONLY);
		_1 = zephir_is_true(&_2);
	}
	RETURN_BOOL(_1);
}

/**
 * Is it frozen
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, isFrozen)
{

	RETURN_MEMBER(getThis(), "frozen");
}

/**
 * Set an argument
 *
 * @param int|string $param
 * @param mixed      $value
 *
 * @return static
 * @throws FrozenDefinition
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, setArgument)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *param, param_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(param)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &param, &value);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkfrozen", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("arguments"), param, value);
	RETURN_THIS();
}

/**
 * Set the container
 *
 * @param object $container
 *
 * @return static
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, setContainer)
{
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(container)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &container);
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	RETURN_THISW();
}

/**
 * Set a class
 *
 * @param string $className
 *
 * @return static
 * @throws FrozenDefinition
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, setClass)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv;
	zend_string *className = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkfrozen", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("className"), &className_zv);
	RETURN_THIS();
}

/**
 * Set extenders
 *
 * @param array<array-key, callable> $extenders
 *
 * @return static
 * @throws FrozenDefinition
 * @throws InvalidExtender
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, setExtenders)
{
	zval _5$$4, _11$$6;
	zend_bool _8;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *extenders_param = NULL, extender, key, *_0, _7, _3$$4, _4$$4, _9$$6, _10$$6;
	zval extenders;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extenders);
	ZVAL_UNDEF(&extender);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_11$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(extenders, extenders_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &extenders_param);
	zephir_get_arrval(&extenders, extenders_param);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkfrozen", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&extenders, 0, "phalcon/Container/Definition/ServiceDefinition.zep", 438);
	if (Z_TYPE_P(&extenders) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&extenders), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&extender);
			ZVAL_COPY(&extender, _0);
			if (!(zephir_is_callable(&extender))) {
				ZEPHIR_INIT_NVAR(&_3$$4);
				object_init_ex(&_3$$4, phalcon_container_exceptions_invalidextender_ce);
				zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC | PH_READONLY);
				zephir_cast_to_string(&_5$$4, &key);
				ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", &_6, 393, &_4$$4, &_5$$4);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$4, "phalcon/Container/Definition/ServiceDefinition.zep", 434);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &extenders, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &extenders, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, &extenders, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &extenders, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&extender, &extenders, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_is_callable(&extender))) {
					ZEPHIR_INIT_NVAR(&_9$$6);
					object_init_ex(&_9$$6, phalcon_container_exceptions_invalidextender_ce);
					zephir_read_property(&_10$$6, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC | PH_READONLY);
					zephir_cast_to_string(&_11$$6, &key);
					ZEPHIR_CALL_METHOD(NULL, &_9$$6, "__construct", &_6, 393, &_10$$6, &_11$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$6, "phalcon/Container/Definition/ServiceDefinition.zep", 434);
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&extender);
	ZEPHIR_INIT_NVAR(&key);
	zephir_update_property_zval(this_ptr, ZEND_STRL("extenders"), &extenders);
	RETURN_THIS();
}

/**
 * Set a factory
 *
 * @param callable $factory
 *
 * @return static
 * @throws FrozenDefinition
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, setFactory)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *factory, factory_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(factory)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &factory);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkfrozen", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("factory"), factory);
	RETURN_THIS();
}

/**
 * Set cachable
 * @param bool $isCacheable
 *
 * @return static
 * @throws FrozenDefinition
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, setIsCacheable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *isCacheable_param = NULL, __$true, __$false;
	zend_bool isCacheable;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(isCacheable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &isCacheable_param);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkfrozen", NULL, 0);
	zephir_check_call_status();
	if (isCacheable) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isCacheable"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isCacheable"), &__$false);
	}
	RETURN_THIS();
}

/**
 * Set lifetime
 *
 * @param string $lifetime
 *
 * @return static
 * @throws FrozenDefinition
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, setLifetime)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval lifetime_zv;
	zend_string *lifetime = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&lifetime_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(lifetime)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&lifetime_zv);
	ZVAL_STR_COPY(&lifetime_zv, lifetime);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkfrozen", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("lifetime"), &lifetime_zv);
	RETURN_THIS();
}

/**
 * Unset class
 *
 * @return static
 * @throws FrozenDefinition
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, unsetClass)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkfrozen", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("className"), &__$null);
	RETURN_THIS();
}

/**
 * Unset extenders
 *
 * @return static
 * @throws FrozenDefinition
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, unsetExtenders)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkfrozen", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("extenders"), &_0);
	RETURN_THIS();
}

/**
 * Unset the factory
 *
 * @return static
 * @throws FrozenDefinition
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, unsetFactory)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkfrozen", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("factory"), &__$null);
	RETURN_THIS();
}

/**
 * Check if frozen
 *
 * @return void
 * @throws FrozenDefinition
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, checkFrozen)
{
	zval _0, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("frozen"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_container_exceptions_frozendefinition_ce);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 394, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Container/Definition/ServiceDefinition.zep", 541);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Resolve arguments
 *
 * @param object $container
 * @param array  $args
 *
 * @return array
 */
PHP_METHOD(Phalcon_Container_Definition_ServiceDefinition, resolveArgs)
{
	zend_bool _6, _3$$3, _7$$6;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *container, container_sub, *args_param = NULL, resolved, key, argument, *_0, _5, _4$$4, _8$$7;

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&args);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(container)
		ZEPHIR_Z_PARAM_ARRAY(args, args_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &container, &args_param);
	zephir_get_arrval(&args, args_param);
	ZEPHIR_INIT_VAR(&resolved);
	array_init(&resolved);
	zephir_is_iterable(&args, 0, "phalcon/Container/Definition/ServiceDefinition.zep", 567);
	if (Z_TYPE_P(&args) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&args), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&argument);
			ZVAL_COPY(&argument, _0);
			_3$$3 = Z_TYPE_P(&argument) == IS_OBJECT;
			if (_3$$3) {
				_3$$3 = (zephir_method_exists_ex(&argument, ZEND_STRL("resolve")) == SUCCESS);
			}
			if (_3$$3) {
				ZEPHIR_CALL_METHOD(&_4$$4, &argument, "resolve", NULL, 0, container);
				zephir_check_call_status();
				zephir_array_update_zval(&resolved, &key, &_4$$4, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&resolved, &key, &argument, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &args, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &args, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &args, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &args, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&argument, &args, "current", NULL, 0);
			zephir_check_call_status();
				_7$$6 = Z_TYPE_P(&argument) == IS_OBJECT;
				if (_7$$6) {
					_7$$6 = (zephir_method_exists_ex(&argument, ZEND_STRL("resolve")) == SUCCESS);
				}
				if (_7$$6) {
					ZEPHIR_CALL_METHOD(&_8$$7, &argument, "resolve", NULL, 0, container);
					zephir_check_call_status();
					zephir_array_update_zval(&resolved, &key, &_8$$7, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&resolved, &key, &argument, PH_COPY | PH_SEPARATE);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&argument);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&resolved);
}

zend_object *zephir_init_properties_Phalcon_Container_Definition_ServiceDefinition(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("tags"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("tags"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("extenders"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("extenders"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("constructorArgs"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("constructorArgs"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("arguments"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

