
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Container_Container)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Container, Container, phalcon, container_container, phalcon_container_container_method_entry, 0);

	/**
	 * @var array<string, string>
	 */
	zend_declare_property_null(phalcon_container_container_ce, SL("aliases"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_container_container_ce, SL("autowire"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var array<string, string>
	 */
	zend_declare_property_null(phalcon_container_container_ce, SL("instanceLifetimes"), ZEND_ACC_PROTECTED);
	/**
	 * @var array<string, object>
	 */
	zend_declare_property_null(phalcon_container_container_ce, SL("instances"), ZEND_ACC_PROTECTED);
	/**
	 * @var array<string, mixed>
	 */
	zend_declare_property_null(phalcon_container_container_ce, SL("parameters"), ZEND_ACC_PROTECTED);
	/**
	 * @var array<string, Processor>
	 */
	zend_declare_property_null(phalcon_container_container_ce, SL("processors"), ZEND_ACC_PROTECTED);
	/**
	 * @var Resolver
	 */
	zend_declare_property_null(phalcon_container_container_ce, SL("resolver"), ZEND_ACC_PROTECTED);
	/**
	 * @var array<string, ServiceDefinition>
	 */
	zend_declare_property_null(phalcon_container_container_ce, SL("services"), ZEND_ACC_PROTECTED);
	/**
	 * @var array<string, list<string>>
	 */
	zend_declare_property_null(phalcon_container_container_ce, SL("tags"), ZEND_ACC_PROTECTED);
	phalcon_container_container_ce->create_object = zephir_init_properties_Phalcon_Container_Container;

	zend_class_implements(phalcon_container_container_ce, 1, phalcon_contracts_container_service_collection_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Container_Container, __construct)
{
	zval _1;
	zval _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_container_resolver_resolver_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("resolver"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_container_definition_processor_objectprocessor_ce);
	if (zephir_has_constructor(&_2)) {
		ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_container_definition_processor_closureprocessor_ce);
	if (zephir_has_constructor(&_2)) {
		ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_container_definition_processor_stringprocessor_ce);
	if (zephir_has_constructor(&_2)) {
		ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_array_fast_append(&_1, &_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("processors"), &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Bind an interface to a concrete class
 *
 * @param string $interface
 * @param string $concrete
 *
 * @return ServiceDefinition
 */
PHP_METHOD(Phalcon_Container_Container, bind)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval interfaceName_zv, concrete_zv;
	zend_string *interfaceName = NULL, *concrete = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&interfaceName_zv);
	ZVAL_UNDEF(&concrete_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(interfaceName)
		Z_PARAM_STR(concrete)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&interfaceName_zv);
	ZVAL_STR_COPY(&interfaceName_zv, interfaceName);
	zephir_memory_observe(&concrete_zv);
	ZVAL_STR_COPY(&concrete_zv, concrete);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &interfaceName_zv, &concrete_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolve to a closure on a get()
 *
 * @param string $name
 *
 * @return Closure
 */
PHP_METHOD(Phalcon_Container_Container, callableGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, serviceName;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&serviceName);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CPY_WRT(&serviceName, &name_zv);
	zephir_create_closure_ex(return_value, this_ptr, phalcon_7__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_7__closure_ce, ZEND_STRL("serviceName"), &serviceName);
	RETURN_MM();
}

/**
 * Resolve to a closure on a new()
 * @param string $name
 *
 * @return Closure
 */
PHP_METHOD(Phalcon_Container_Container, callableNew)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, serviceName;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&serviceName);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CPY_WRT(&serviceName, &name_zv);
	zephir_create_closure_ex(return_value, this_ptr, phalcon_8__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_8__closure_ce, ZEND_STRL("serviceName"), &serviceName);
	RETURN_MM();
}

/**
 * Extends the definition
 *
 * @param string   $name
 * @param callable $callable
 *
 * @return void
 * @throws CannotExtendResolved
 * @throws ServiceNotFound
 */
PHP_METHOD(Phalcon_Container_Container, extend)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *callableObject, callableObject_sub, _0, _1, _3, _5, _6, _2$$3, _4$$4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&callableObject_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(name_param)
		Z_PARAM_ZVAL(callableObject)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &name_param, &callableObject);
	zephir_get_strval(&name, name_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvealias", NULL, 385, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_1, &name)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_container_exceptions_cannotextendresolved_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 386, &name);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Container/Container.zep", 165);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_3, &name))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_container_exceptions_servicenotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 387, &name);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Container/Container.zep", 169);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &name, PH_NOISY | PH_READONLY, "phalcon/Container/Container.zep", 172);
	ZEPHIR_CALL_METHOD(NULL, &_6, "addextender", NULL, 0, callableObject);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Resolve and return an element registerd in the container
 *
 * @param string $name
 *
 * @return mixed
 * @throws ServiceNotFound
 */
PHP_METHOD(Phalcon_Container_Container, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1, _2, _5, _3$$4, _4$$4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvealias", NULL, 385, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_1, &name)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolveparameter", NULL, 388, &name);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_2, &name)) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$4, &_3$$4, &name, PH_NOISY | PH_READONLY, "phalcon/Container/Container.zep", 192);
		RETURN_CTOR(&_4$$4);
	}
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolve", NULL, 389, &name, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return an alias
 *
 * @param string $name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Container_Container, getAlias)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, alias, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&alias);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&alias, &_0, &name_zv, 0)) {
		RETURN_CCTOR(&alias);
	}
	RETURN_MM_STRING("");
}

/**
 * Return services by tag
 *
 * @param string $tag
 *
 * @return list<mixed>
 */
PHP_METHOD(Phalcon_Container_Container, getByTag)
{
	zend_bool _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tag_zv, names, result, serviceName, _0, *_1, _4, _2$$4, _6$$5;
	zend_string *tag = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag_zv);
	ZVAL_UNDEF(&names);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(tag)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tag_zv);
	ZVAL_STR_COPY(&tag_zv, tag);
	zephir_memory_observe(&names);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("tags"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&names, &_0, &tag_zv, 0))) {
		ZEPHIR_INIT_NVAR(&names);
		array_init(&names);
	}
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&names, 0, "phalcon/Container/Container.zep", 237);
	if (Z_TYPE_P(&names) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&names), _1)
		{
			ZEPHIR_INIT_NVAR(&serviceName);
			ZVAL_COPY(&serviceName, _1);
			ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "get", &_3, 0, &serviceName);
			zephir_check_call_status();
			zephir_array_append(&result, &_2$$4, PH_SEPARATE, "phalcon/Container/Container.zep", 234);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &names, "rewind", NULL, 0);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &names, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_4, &names, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&serviceName, &names, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "get", &_3, 0, &serviceName);
				zephir_check_call_status();
				zephir_array_append(&result, &_6$$5, PH_SEPARATE, "phalcon/Container/Container.zep", 234);
		}
	}
	ZEPHIR_INIT_NVAR(&serviceName);
	RETURN_CCTOR(&result);
}

/**
 * Return the service definition
 *
 * @param string $name
 *
 * @return ServiceDefinition
 * @throws ServiceNotFound
 */
PHP_METHOD(Phalcon_Container_Container, getDefinition)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _2, _3, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_0, &name_zv))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_container_exceptions_servicenotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 387, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Container/Container.zep", 251);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Container/Container.zep", 254);
	RETURN_CTOR(&_3);
}

/**
 * Return a stored instance
 *
 * @param string $name
 *
 * @return object
 * @throws InstanceNotFound
 */
PHP_METHOD(Phalcon_Container_Container, getInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _2, _3, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_0, &name_zv))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_container_exceptions_instancenotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 390, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Container/Container.zep", 268);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Container/Container.zep", 271);
	RETURN_CTOR(&_3);
}

/**
 * Return a parameter
 *
 * @param string $name
 *
 * @return mixed
 * @throws ParameterNotFound
 */
PHP_METHOD(Phalcon_Container_Container, getParameter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_0, &name_zv))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_container_exceptions_parameternotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 391, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Container/Container.zep", 285);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolveparameter", NULL, 388, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return the resolver
 *
 * @return Resolver
 */
PHP_METHOD(Phalcon_Container_Container, getResolver)
{

	RETURN_MEMBER(getThis(), "resolver");
}

/**
 * Resolve an return a service
 *
 * @param string $serviceName
 *
 * @return object
 * @throws ServiceNotFound
 * @throws ServiceNotRegistered
 */
PHP_METHOD(Phalcon_Container_Container, getService)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval serviceName_zv, result, _0$$3;
	zend_string *serviceName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName_zv);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(serviceName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&serviceName_zv);
	ZVAL_STR_COPY(&serviceName_zv, serviceName);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "get", NULL, 0, &serviceName_zv);
	zephir_check_call_status();
	if (!(Z_TYPE_P(&result) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_container_exceptions_servicenotregistered_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 392, &serviceName_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Container/Container.zep", 317);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&result);
}

/**
 * Does the container have a particular service
 *
 * @param string $name
 *
 * @return bool
 * @throws CircularAliasFound
 */
PHP_METHOD(Phalcon_Container_Container, has)
{
	zend_bool _2, _4, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1, _3, _5, _6, _8, _9;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvealias", NULL, 385, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	_2 = zephir_array_key_exists(&_1, &name);
	if (!(_2)) {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
		_2 = zephir_array_key_exists(&_3, &name);
	}
	_4 = _2;
	if (!(_4)) {
		zephir_read_property(&_5, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
		_4 = zephir_array_key_exists(&_5, &name);
	}
	if (_4) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("autowire"), PH_NOISY_CC | PH_READONLY);
	_7 = zephir_is_true(&_6);
	if (_7) {
		zephir_read_property(&_8, this_ptr, ZEND_STRL("resolver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_9, &_8, "isresolvableclass", NULL, 0, &name);
		zephir_check_call_status();
		_7 = zephir_is_true(&_9);
	}
	RETURN_MM_BOOL(_7);
}

/**
 * Does the service have an alias
 *
 * @param string $name
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Container_Container, hasAlias)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_key_exists(&_0, &name_zv));
}

/**
 * Does the service have a definition
 *
 * @param string $name
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Container_Container, hasDefinition)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_key_exists(&_0, &name_zv));
}

/**
 * Does the service have an instance
 *
 * @param string $name
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Container_Container, hasInstance)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_key_exists(&_0, &name_zv));
}

/**
 * Does the service have a parameter
 *
 * @param string $name
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Container_Container, hasParameter)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_key_exists(&_0, &name_zv));
}

/**
 * Does the container have a particular service
 *
 * @param string $serviceName
 *
 * @return bool
 * @throws CircularAliasFound
 */
PHP_METHOD(Phalcon_Container_Container, hasService)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval serviceName_zv;
	zend_string *serviceName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(serviceName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&serviceName_zv);
	ZVAL_STR_COPY(&serviceName_zv, serviceName);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &serviceName_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Is AutoWiring enabled
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Container_Container, isAutowireEnabled)
{

	RETURN_MEMBER(getThis(), "autowire");
}

/**
 * Resolve and return a new service
 *
 * @param string $name
 *
 * @return mixed
 * @throws CircularAliasFound
 * @throws ReflectionException
 * @throws ServiceNotFound
 */
PHP_METHOD(Phalcon_Container_Container, new)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvealias", NULL, 385, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	ZVAL_BOOL(&_1, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolve", NULL, 389, &name, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return a new service definition
 *
 * @param string $name
 *
 * @return ServiceDefinition
 */
PHP_METHOD(Phalcon_Container_Container, newDefinition)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	object_init_ex(return_value, phalcon_container_definition_servicedefinition_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "string");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 393, &name_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set a service
 *
 * @param string $name
 * @param mixed  $definition
 *
 * @return ServiceDefinition
 * @throws NoProcessorFound
 */
PHP_METHOD(Phalcon_Container_Container, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, *definition, definition_sub, processor, def;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&processor);
	ZVAL_UNDEF(&def);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(definition)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&processor, this_ptr, "findprocessor", NULL, 394, definition);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&def, &processor, "process", NULL, 0, &name_zv, definition, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &def, "setcontainer", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("services"), &name_zv, &def);
	RETURN_CCTOR(&def);
}

/**
 * Set an alias
 *
 * @param string $name
 * @param string $alias
 *
 * @return static
 * @throws CircularAliasFound
 */
PHP_METHOD(Phalcon_Container_Container, setAlias)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, alias_zv;
	zend_string *name = NULL, *alias = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&alias_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_STR(alias)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "detectcircularalias", NULL, 395, &alias_zv, &name_zv);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("aliases"), &alias_zv, &name_zv);
	RETURN_THIS();
}

/**
 * Set AutoWire
 *
 * @param bool $enabled
 *
 * @return static
 */
PHP_METHOD(Phalcon_Container_Container, setAutowire)
{
	zval *enabled_param = NULL, __$true, __$false;
	zend_bool enabled;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(enabled)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &enabled_param);
	if (enabled) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("autowire"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("autowire"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Set a definition
 *
 * @param string            $name
 * @param ServiceDefinition $definition
 *
 * @return static
 */
PHP_METHOD(Phalcon_Container_Container, setDefinition)
{
	zval name_zv, *definition, definition_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJECT_OF_CLASS(definition, phalcon_container_definition_servicedefinition_ce)
	ZEND_PARSE_PARAMETERS_END();
	definition = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("services"), &name_zv, definition);
	RETURN_THISW();
}

/**
 * Set an instance
 *
 * @param string $name
 * @param object $instance
 * @param string $lifetime
 *
 * @return static
 */
PHP_METHOD(Phalcon_Container_Container, setInstance)
{
	zval name_zv, *instance, instance_sub, lifetime_zv;
	zend_string *name = NULL, *lifetime = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&instance_sub);
	ZVAL_UNDEF(&lifetime_zv);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(name)
		Z_PARAM_OBJECT(instance)
		Z_PARAM_STR(lifetime)
	ZEND_PARSE_PARAMETERS_END();
	instance = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	ZVAL_STR(&lifetime_zv, lifetime);
	zephir_update_property_array(this_ptr, SL("instances"), &name_zv, instance);
	zephir_update_property_array(this_ptr, SL("instanceLifetimes"), &name_zv, &lifetime_zv);
	RETURN_THISW();
}

/**
 * Set a parameter
 *
 * @param string $name
 * @param mixed  $value
 *
 * @return static
 */
PHP_METHOD(Phalcon_Container_Container, setParameter)
{
	zval name_zv, *value, value_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	value = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("parameters"), &name_zv, value);
	RETURN_THISW();
}

/**
 * Register a tag with a service
 *
 * @param string $tag
 * @param string $serviceName
 *
 * @return void
 */
PHP_METHOD(Phalcon_Container_Container, setTag)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tag_zv, serviceName_zv, __$true, _0, _2, _3, _4, _1$$3;
	zend_string *tag = NULL, *serviceName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag_zv);
	ZVAL_UNDEF(&serviceName_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(tag)
		Z_PARAM_STR(serviceName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tag_zv);
	ZVAL_STR_COPY(&tag_zv, tag);
	zephir_memory_observe(&serviceName_zv);
	ZVAL_STR_COPY(&serviceName_zv, serviceName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("tags"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_0, &tag_zv))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_property_array(this_ptr, SL("tags"), &tag_zv, &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("tags"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &tag_zv, PH_NOISY | PH_READONLY, "phalcon/Container/Container.zep", 561);
	ZEPHIR_CALL_FUNCTION(&_4, "in_array", NULL, 87, &serviceName_zv, &_3, &__$true);
	zephir_check_call_status();
	if (!zephir_is_true(&_4)) {
		zephir_update_property_array_multi(this_ptr, SL("tags"), &serviceName_zv, SL("za"), 2, &tag_zv);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Remove an alias
 *
 * @param string $name
 *
 * @return void
 */
PHP_METHOD(Phalcon_Container_Container, unsetAlias)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_unset_property_array(this_ptr, ZEND_STRL("aliases"), &name_zv);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name_zv, PH_SEPARATE);
}

/**
 * Remove a definition
 *
 * @param string $name
 *
 * @return void
 */
PHP_METHOD(Phalcon_Container_Container, unsetDefinition)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_unset_property_array(this_ptr, ZEND_STRL("services"), &name_zv);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name_zv, PH_SEPARATE);
}

/**
 * Remove an instance
 *
 * @param string $name
 *
 * @return void
 */
PHP_METHOD(Phalcon_Container_Container, unsetInstance)
{
	zval name_zv, _0, _1;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_unset_property_array(this_ptr, ZEND_STRL("instances"), &name_zv);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name_zv, PH_SEPARATE);
	zephir_unset_property_array(this_ptr, ZEND_STRL("instanceLifetimes"), &name_zv);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("instanceLifetimes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_1, &name_zv, PH_SEPARATE);
}

/**
 * Remove instances based on lifetime
 *
 * @param string $lifetime
 *
 * @return void
 */
PHP_METHOD(Phalcon_Container_Container, unsetInstances)
{
	zend_bool _7;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval lifetime_zv, name, instanceLifetime, _0, *_1, _6, _4$$4, _5$$4, _8$$6, _9$$6;
	zend_string *lifetime = NULL, *_3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&lifetime_zv);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&instanceLifetime);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(lifetime)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&lifetime_zv);
	ZVAL_STR_COPY(&lifetime_zv, lifetime);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("instanceLifetimes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Container/Container.zep", 620);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&instanceLifetime);
			ZVAL_COPY(&instanceLifetime, _1);
			if (ZEPHIR_IS_IDENTICAL(&instanceLifetime, &lifetime_zv)) {
				zephir_unset_property_array(this_ptr, ZEND_STRL("instances"), &name);
				zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_4$$4, &name, PH_SEPARATE);
				zephir_unset_property_array(this_ptr, ZEND_STRL("instanceLifetimes"), &name);
				zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("instanceLifetimes"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_5$$4, &name, PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&instanceLifetime, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_IDENTICAL(&instanceLifetime, &lifetime_zv)) {
					zephir_unset_property_array(this_ptr, ZEND_STRL("instances"), &name);
					zephir_read_property(&_8$$6, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
					zephir_array_unset(&_8$$6, &name, PH_SEPARATE);
					zephir_unset_property_array(this_ptr, ZEND_STRL("instanceLifetimes"), &name);
					zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("instanceLifetimes"), PH_NOISY_CC | PH_READONLY);
					zephir_array_unset(&_9$$6, &name, PH_SEPARATE);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&instanceLifetime);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();
}

/**
 * Remove a parameter
 *
 * @param string $name
 *
 * @return void
 */
PHP_METHOD(Phalcon_Container_Container, unsetParameter)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_unset_property_array(this_ptr, ZEND_STRL("parameters"), &name_zv);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name_zv, PH_SEPARATE);
}

/**
 * Detect circular aliases
 *
 * @param string $alias
 * @param string $target
 *
 * @return void
 * @throws CircularAliasFound
 */
PHP_METHOD(Phalcon_Container_Container, detectCircularAlias)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval alias_zv, target_zv, __$true, current, seen, _0$$4, _2$$3, _3$$3, _4$$3;
	zend_string *alias = NULL, *target = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_zv);
	ZVAL_UNDEF(&target_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&seen);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(alias)
		Z_PARAM_STR(target)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
	zephir_memory_observe(&target_zv);
	ZVAL_STR_COPY(&target_zv, target);
	ZEPHIR_CPY_WRT(&current, &target_zv);
	ZEPHIR_INIT_VAR(&seen);
	array_init(&seen);
	while (1) {
		if (!(1)) {
			break;
		}
		if (ZEPHIR_IS_IDENTICAL(&current, &alias_zv)) {
			ZEPHIR_INIT_NVAR(&_0$$4);
			object_init_ex(&_0$$4, phalcon_container_exceptions_circularaliasfound_ce);
			ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", &_1, 396, &alias_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_0$$4, "phalcon/Container/Container.zep", 652);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (zephir_array_key_exists(&seen, &current)) {
			break;
		}
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_key_exists(&_2$$3, &current))) {
			break;
		}
		zephir_array_update_zval(&seen, &current, &__$true, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$3, &_3$$3, &current, PH_NOISY | PH_READONLY, "phalcon/Container/Container.zep", 664);
		ZEPHIR_CPY_WRT(&current, &_4$$3);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Locate a processor
 *
 * @param mixed $definition
 *
 * @return Processor
 * @throws NoProcessorFound
 */
PHP_METHOD(Phalcon_Container_Container, findProcessor)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *definition, definition_sub, processor, _0, *_1, _3, _6, _2$$3, _5$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&processor);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(definition)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &definition);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("processors"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Container/Container.zep", 686);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&processor);
			ZVAL_COPY(&processor, _1);
			ZEPHIR_CALL_METHOD(&_2$$3, &processor, "canprocess", NULL, 0, definition);
			zephir_check_call_status();
			if (zephir_is_true(&_2$$3)) {
				RETURN_CCTOR(&processor);
			}
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
			ZEPHIR_CALL_METHOD(&processor, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$5, &processor, "canprocess", NULL, 0, definition);
				zephir_check_call_status();
				if (zephir_is_true(&_5$$5)) {
					RETURN_CCTOR(&processor);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&processor);
	ZEPHIR_INIT_VAR(&_6);
	object_init_ex(&_6, phalcon_container_exceptions_noprocessorfound_ce);
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 397);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_6, "phalcon/Container/Container.zep", 686);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Resolve the service
 *
 * @param string $name
 * @param bool   $cache
 *
 * @return mixed
 * @throws ServiceNotFound
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Container_Container, resolve)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cache, _5, _2$$3;
	zval name_zv, *cache_param = NULL, definition, instance, lifetime, _0, _4, _1$$3, _3$$5;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&lifetime);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$5);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_BOOL(cache)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	cache_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_0, &name_zv))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("autowire"), PH_NOISY_CC | PH_READONLY);
		_2$$3 = zephir_is_true(&_1$$3);
		if (_2$$3) {
			_2$$3 = zephir_class_exists(&name_zv, 1);
		}
		if (_2$$3) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &name_zv, &name_zv);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_3$$5);
			object_init_ex(&_3$$5, phalcon_container_exceptions_servicenotfound_ce);
			ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 387, &name_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$5, "phalcon/Container/Container.zep", 707);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&definition);
	zephir_array_fetch(&definition, &_4, &name_zv, PH_NOISY, "phalcon/Container/Container.zep", 711);
	ZEPHIR_CALL_METHOD(NULL, &definition, "freeze", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&instance, &definition, "buildservice", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (zephir_instance_of_ev(&instance, phalcon_di_injectionawareinterface_ce)) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "setdi", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&lifetime, &definition, "getlifetime", NULL, 0);
	zephir_check_call_status();
	_5 = cache;
	if (_5) {
		_5 = !ZEPHIR_IS_STRING_IDENTICAL(&lifetime, "TRANSIENT");
	}
	if (_5) {
		zephir_update_property_array(this_ptr, SL("instances"), &name_zv, &instance);
		zephir_update_property_array(this_ptr, SL("instanceLifetimes"), &name_zv, &lifetime);
	}
	RETURN_CCTOR(&instance);
}

/**
 * Resolve an alias
 *
 * @param string $name
 *
 * @return string
 * @throws CircularAliasFound
 */
PHP_METHOD(Phalcon_Container_Container, resolveAlias)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, __$true, seen, current, _0, _1$$4, _3$$3, _4$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&seen);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_INIT_VAR(&seen);
	array_init(&seen);
	ZEPHIR_CPY_WRT(&current, &name_zv);
	while (1) {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_key_exists(&_0, &current))) {
			break;
		}
		if (zephir_array_key_exists(&seen, &current)) {
			ZEPHIR_INIT_NVAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_container_exceptions_circularaliasfound_ce);
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", &_2, 396, &name_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Container/Container.zep", 747);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&seen, &current, &__$true, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$3, &_3$$3, &current, PH_NOISY | PH_READONLY, "phalcon/Container/Container.zep", 751);
		ZEPHIR_CPY_WRT(&current, &_4$$3);
	}
	RETURN_CCTOR(&current);
}

/**
 * Resolve a paramater
 *
 * @param string $name
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Container_Container, resolveParameter)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, value, resolved, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&value);
	zephir_array_fetch(&value, &_0, &name_zv, PH_NOISY, "phalcon/Container/Container.zep", 768);
	_1 = Z_TYPE_P(&value) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(&value, phalcon_container_resolver_lazy_lazy_ce);
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&resolved, &value, "resolve", NULL, 0, this_ptr);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("parameters"), &name_zv, &resolved);
		RETURN_CCTOR(&resolved);
	}
	RETURN_CCTOR(&value);
}

zend_object *zephir_init_properties_Phalcon_Container_Container(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _10, _12, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	

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
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("services"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("processors"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("processors"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("parameters"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("instances"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("instanceLifetimes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("instanceLifetimes"), &_11$$8);
		}
		zephir_read_property_ex(&_12, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$9);
			array_init(&_13$$9);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("aliases"), &_13$$9);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

