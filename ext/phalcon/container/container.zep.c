
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
/**
 * @phpstan-import-type container_aliases from ContainerTypes
 * @phpstan-import-type container_instance_lifetimes from ContainerTypes
 * @phpstan-import-type container_instances from ContainerTypes
 * @phpstan-import-type container_parameters from ContainerTypes
 * @phpstan-import-type container_processors from ContainerTypes
 * @phpstan-import-type container_service_names from ContainerTypes
 * @phpstan-import-type container_service_tags from ContainerTypes
 * @phpstan-import-type container_services from ContainerTypes
 * @phpstan-import-type container_tagged_services from ContainerTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Container_Container)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Container, Container, phalcon, container_container, phalcon_container_container_method_entry, 0);

	/**
	 * @phpstan-var container_aliases
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_container_container_ce, SL("aliases"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 1);
		zephir_declare_typed_property(phalcon_container_container_ce, SL("autowire"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @phpstan-var container_instance_lifetimes
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_container_container_ce, SL("instanceLifetimes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var container_instances
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_container_container_ce, SL("instances"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var container_parameters
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_container_container_ce, SL("parameters"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var container_processors
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_container_container_ce, SL("processors"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_container_container_ce, SL("resolver"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Container\\Resolver\\Resolver"));
	}

	/**
	 * @phpstan-var container_services
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_container_container_ce, SL("services"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var container_service_tags
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_container_container_ce, SL("tags"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	zend_class_implements(phalcon_container_container_ce, 1, phalcon_contracts_container_service_collection_ce);
	zend_class_implements(phalcon_container_container_ce, 1, phalcon_contracts_container_service_enumerable_ce);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("resolver", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("processors", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_container_resolver_resolver_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 523, &_0);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 524, &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Bind an interface to a concrete class
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
	zephir_create_closure_ex(return_value, this_ptr, phalcon_9__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_9__closure_ce, ZEND_STRL("serviceName"), &serviceName);
	RETURN_MM();
}

/**
 * Resolve to a closure on a new()
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
	zephir_create_closure_ex(return_value, this_ptr, phalcon_10__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_10__closure_ce, ZEND_STRL("serviceName"), &serviceName);
	RETURN_MM();
}

/**
 * Extends the definition
 *
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("instances", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("services", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(name_param)
		Z_PARAM_ZVAL(callableObject)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &name_param, &callableObject);
	zephir_get_strval(&name, name_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvealias", NULL, 474, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 525, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_1, &name)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_container_exceptions_cannotextendresolved_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 475, &name);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Container/Container.zep", 156);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 526, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_3, &name))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_container_exceptions_servicenotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 476, &name);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Container/Container.zep", 160);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_1, 526, PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &name, PH_NOISY | PH_READONLY, "phalcon/Container/Container.zep", 163);
	ZEPHIR_CALL_METHOD(NULL, &_6, "addextender", NULL, 0, callableObject);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Resolve and return an element registerd in the container
 *
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("parameters", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("instances", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvealias", NULL, 474, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 527, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_1, &name)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolveparameter", NULL, 477, &name);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 525, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_2, &name)) {
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_1, 525, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$4, &_3$$4, &name, PH_NOISY | PH_READONLY, "phalcon/Container/Container.zep", 180);
		RETURN_CTOR(&_4$$4);
	}
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolve", NULL, 478, &name, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return an alias
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("aliases", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&alias);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 528, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&alias, &_0, &name_zv, 0)) {
		RETURN_CCTOR(&alias);
	}
	RETURN_MM_STRING("");
}

/**
 * Return services by tag
 *
 * @phpstan-return container_tagged_services
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("tags", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(tag)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tag_zv);
	ZVAL_STR_COPY(&tag_zv, tag);
	zephir_memory_observe(&names);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 529, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&names, &_0, &tag_zv, 0))) {
		ZEPHIR_INIT_NVAR(&names);
		array_init(&names);
	}
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&names, 0, "phalcon/Container/Container.zep", 219);
	if (Z_TYPE_P(&names) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&names), _1)
		{
			ZEPHIR_INIT_NVAR(&serviceName);
			ZVAL_COPY(&serviceName, _1);
			ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "get", &_3, 0, &serviceName);
			zephir_check_call_status();
			zephir_array_append(&result, &_2$$4, PH_SEPARATE, "phalcon/Container/Container.zep", 216);
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
				zephir_array_append(&result, &_6$$5, PH_SEPARATE, "phalcon/Container/Container.zep", 216);
		}
	}
	ZEPHIR_INIT_NVAR(&serviceName);
	RETURN_CCTOR(&result);
}

/**
 * Return the service definition
 *
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("services", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 526, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_0, &name_zv))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_container_exceptions_servicenotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 476, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Container/Container.zep", 230);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 526, PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Container/Container.zep", 233);
	RETURN_CTOR(&_3);
}

/**
 * Return a stored instance
 *
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("instances", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 525, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_0, &name_zv))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_container_exceptions_instancenotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 479, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Container/Container.zep", 244);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 525, PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Container/Container.zep", 247);
	RETURN_CTOR(&_3);
}

/**
 * Return a parameter
 *
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("parameters", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 527, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_0, &name_zv))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_container_exceptions_parameternotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 480, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Container/Container.zep", 258);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolveparameter", NULL, 477, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return the resolver
 */
PHP_METHOD(Phalcon_Container_Container, getResolver)
{

	RETURN_MEMBER(getThis(), "resolver");
}

/**
 * Resolve an return a service
 *
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 481, &serviceName_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Container/Container.zep", 285);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&result);
}

/**
 * Returns the names of every registered service definition. Names that
 * only exist as an alias, a pre-set instance or a parameter are not
 * included.
 *
 * @phpstan-return container_service_names
 */
PHP_METHOD(Phalcon_Container_Container, getServiceNames)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("services", 8, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 526, PH_NOISY_CC | PH_READONLY);
	zephir_array_keys(return_value, &_0);
	return;
}

/**
 * Does the container have a particular service
 *
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("parameters", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("instances", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("services", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("autowire", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("resolver", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvealias", NULL, 474, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 527, PH_NOISY_CC | PH_READONLY);
	_2 = zephir_array_key_exists(&_1, &name);
	if (!(_2)) {
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 525, PH_NOISY_CC | PH_READONLY);
		_2 = zephir_array_key_exists(&_3, &name);
	}
	_4 = _2;
	if (!(_4)) {
		zephir_read_property_cached(&_5, this_ptr, _zephir_prop_2, 526, PH_NOISY_CC | PH_READONLY);
		_4 = zephir_array_key_exists(&_5, &name);
	}
	if (_4) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_3, 530, PH_NOISY_CC | PH_READONLY);
	_7 = zephir_is_true(&_6);
	if (_7) {
		zephir_read_property_cached(&_8, this_ptr, _zephir_prop_4, 523, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_9, &_8, "isresolvableclass", NULL, 0, &name);
		zephir_check_call_status();
		_7 = zephir_is_true(&_9);
	}
	RETURN_MM_BOOL(_7);
}

/**
 * Does the service have an alias
 */
PHP_METHOD(Phalcon_Container_Container, hasAlias)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("aliases", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 528, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_key_exists(&_0, &name_zv));
}

/**
 * Does the service have a definition
 */
PHP_METHOD(Phalcon_Container_Container, hasDefinition)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("services", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 526, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_key_exists(&_0, &name_zv));
}

/**
 * Does the service have an instance
 */
PHP_METHOD(Phalcon_Container_Container, hasInstance)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("instances", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 525, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_key_exists(&_0, &name_zv));
}

/**
 * Does the service have a parameter
 */
PHP_METHOD(Phalcon_Container_Container, hasParameter)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("parameters", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 527, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_key_exists(&_0, &name_zv));
}

/**
 * Does the container have a particular service
 *
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
 */
PHP_METHOD(Phalcon_Container_Container, isAutowireEnabled)
{

	RETURN_MEMBER(getThis(), "autowire");
}

/**
 * Resolve and return a new service
 *
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvealias", NULL, 474, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	ZVAL_BOOL(&_1, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolve", NULL, 478, &name, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return a new service definition
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
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 482, &name_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set a service
 *
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
	ZEPHIR_CALL_METHOD(&processor, this_ptr, "findprocessor", NULL, 483, definition);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "detectcircularalias", NULL, 484, &alias_zv, &name_zv);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("aliases"), &alias_zv, &name_zv);
	RETURN_THIS();
}

/**
 * Set AutoWire
 */
PHP_METHOD(Phalcon_Container_Container, setAutowire)
{
	zval *enabled_param = NULL, __$true, __$false;
	zend_bool enabled;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("autowire", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(enabled)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &enabled_param);
	if (enabled) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 530, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 530, &__$false);
	}
	RETURN_THISW();
}

/**
 * Set a definition
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
		Z_PARAM_OBJECT_OF_CLASS(definition, zephir_get_internal_ce(SL("phalcon\\container\\definition\\servicedefinition")))
	ZEND_PARSE_PARAMETERS_END();
	definition = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("services"), &name_zv, definition);
	RETURN_THISW();
}

/**
 * Set an instance
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("tags", 4, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 529, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_0, &tag_zv))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_property_array(this_ptr, SL("tags"), &tag_zv, &_1$$3);
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 529, PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &tag_zv, PH_NOISY | PH_READONLY, "phalcon/Container/Container.zep", 476);
	ZEPHIR_CALL_FUNCTION(&_4, "in_array", NULL, 89, &serviceName_zv, &_3, &__$true);
	zephir_check_call_status();
	if (!zephir_is_true(&_4)) {
		zephir_update_property_array_multi(this_ptr, SL("tags"), &serviceName_zv, SL("za"), 2, &tag_zv);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Remove an alias
 */
PHP_METHOD(Phalcon_Container_Container, unsetAlias)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("aliases", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_unset_property_array(this_ptr, ZEND_STRL("aliases"), &name_zv);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 528, PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name_zv, PH_SEPARATE);
}

/**
 * Remove a definition
 */
PHP_METHOD(Phalcon_Container_Container, unsetDefinition)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("services", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_unset_property_array(this_ptr, ZEND_STRL("services"), &name_zv);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 526, PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name_zv, PH_SEPARATE);
}

/**
 * Remove an instance
 */
PHP_METHOD(Phalcon_Container_Container, unsetInstance)
{
	zval name_zv, _0, _1;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("instances", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("instanceLifetimes", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_unset_property_array(this_ptr, ZEND_STRL("instances"), &name_zv);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 525, PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name_zv, PH_SEPARATE);
	zephir_unset_property_array(this_ptr, ZEND_STRL("instanceLifetimes"), &name_zv);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 531, PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_1, &name_zv, PH_SEPARATE);
}

/**
 * Remove instances based on lifetime
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("instanceLifetimes", 17, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("instances", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(lifetime)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&lifetime_zv);
	ZVAL_STR_COPY(&lifetime_zv, lifetime);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 531, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Container/Container.zep", 519);
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
				zephir_read_property_cached(&_4$$4, this_ptr, _zephir_prop_1, 525, PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_4$$4, &name, PH_SEPARATE);
				zephir_unset_property_array(this_ptr, ZEND_STRL("instanceLifetimes"), &name);
				zephir_read_property_cached(&_5$$4, this_ptr, _zephir_prop_0, 531, PH_NOISY_CC | PH_READONLY);
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
					zephir_read_property_cached(&_8$$6, this_ptr, _zephir_prop_1, 525, PH_NOISY_CC | PH_READONLY);
					zephir_array_unset(&_8$$6, &name, PH_SEPARATE);
					zephir_unset_property_array(this_ptr, ZEND_STRL("instanceLifetimes"), &name);
					zephir_read_property_cached(&_9$$6, this_ptr, _zephir_prop_0, 531, PH_NOISY_CC | PH_READONLY);
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
 */
PHP_METHOD(Phalcon_Container_Container, unsetParameter)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("parameters", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_unset_property_array(this_ptr, ZEND_STRL("parameters"), &name_zv);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 527, PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name_zv, PH_SEPARATE);
}

/**
 * Detect circular aliases
 *
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("aliases", 7, 1);
	}

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
			ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", &_1, 485, &alias_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_0$$4, "phalcon/Container/Container.zep", 543);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (zephir_array_key_exists(&seen, &current)) {
			break;
		}
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 528, PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_key_exists(&_2$$3, &current))) {
			break;
		}
		zephir_array_update_zval(&seen, &current, &__$true, PH_COPY | PH_SEPARATE);
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 528, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$3, &_3$$3, &current, PH_NOISY | PH_READONLY, "phalcon/Container/Container.zep", 555);
		ZEPHIR_CPY_WRT(&current, &_4$$3);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Locate a processor
 *
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("processors", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(definition)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &definition);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 524, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Container/Container.zep", 574);
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
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 486);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_6, "phalcon/Container/Container.zep", 574);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Resolve the service
 *
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("services", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("autowire", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_BOOL(cache)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	cache_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 526, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_0, &name_zv))) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 530, PH_NOISY_CC | PH_READONLY);
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
			ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 476, &name_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$5, "phalcon/Container/Container.zep", 591);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 526, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&definition);
	zephir_array_fetch(&definition, &_4, &name_zv, PH_NOISY, "phalcon/Container/Container.zep", 595);
	ZEPHIR_CALL_METHOD(NULL, &definition, "freeze", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&instance, &definition, "buildservice", NULL, 0, this_ptr);
	zephir_check_call_status();
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("aliases", 7, 1);
	}

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
		zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 528, PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_key_exists(&_0, &current))) {
			break;
		}
		if (zephir_array_key_exists(&seen, &current)) {
			ZEPHIR_INIT_NVAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_container_exceptions_circularaliasfound_ce);
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", &_2, 485, &name_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Container/Container.zep", 633);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&seen, &current, &__$true, PH_COPY | PH_SEPARATE);
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 528, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$3, &_3$$3, &current, PH_NOISY | PH_READONLY, "phalcon/Container/Container.zep", 637);
		ZEPHIR_CPY_WRT(&current, &_4$$3);
	}
	RETURN_CCTOR(&current);
}

/**
 * Resolve a paramater
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("parameters", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 527, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&value);
	zephir_array_fetch(&value, &_0, &name_zv, PH_NOISY, "phalcon/Container/Container.zep", 650);
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

