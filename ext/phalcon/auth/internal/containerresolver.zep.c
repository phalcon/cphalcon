
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Internal single source of truth for resolving services from either the
 * new Phalcon\Container\Container or the legacy Phalcon\Di\Di. Not part of
 * the public API.
 *
 * Intent is Container-first; the legacy Di is supported "with provisions":
 * definitions must be pre-registered (no autowiring), the one exception
 * being the fresh path, which lets Di build an unregistered but existing
 * class via its class builder.
 *
 * All legacy-Di failures are normalized to Phalcon\Container\Exceptions so
 * callers and userland catch a single exception family.
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Internal_ContainerResolver)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Internal, ContainerResolver, phalcon, auth_internal_containerresolver, phalcon_auth_internal_containerresolver_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;
}

/**
 * Validates that the value is a supported container.
 *
 * @throws \TypeError
 */
PHP_METHOD(Phalcon_Auth_Internal_ContainerResolver, ensureContainer)
{
	zend_bool _0;
	zval *container, container_sub;

	ZVAL_UNDEF(&container_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(container)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &container);
	_0 = !((zephir_instance_of_ev(container, phalcon_contracts_container_service_collection_ce)));
	if (_0) {
		_0 = !((zephir_instance_of_ev(container, phalcon_di_diinterface_ce)));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zend_ce_type_error, "The parameter must be an instance of Collection or DiInterface", "phalcon/Auth/Internal/ContainerResolver.zep", 43);
		return;
	}
}

/**
 * Resolves a fresh instance: new() on the Container (bypasses the
 * instance cache); get() on the legacy Di (fresh for unregistered or
 * non-shared services). On Di, an unregistered but existing class is
 * still built via the class builder.
 *
 * @throws ContainerException
 */
PHP_METHOD(Phalcon_Auth_Internal_ContainerResolver, resolveFresh)
{
	zval _2$$4, _6$$5, _9$$7;
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *name = NULL;
	zval *container, container_sub, name_zv, e, _3, _7, _0$$3, _1$$4, _5$$5, _8$$7, _10$$7;

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$7);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(container)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	container = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_SELF(NULL, "ensurecontainer", NULL, 0, container);
	zephir_check_call_status();
	if (zephir_instance_of_ev(container, phalcon_contracts_container_service_collection_ce)) {
		ZEPHIR_CALL_METHOD(&_0$$3, container, "has", NULL, 0, &name_zv);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0$$3)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_container_exceptions_exception_ce);
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_CONCAT_SVS(&_2$$4, "Cannot resolve a fresh '", &name_zv, "': it is not bound in the container");
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 8, &_2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Auth/Internal/ContainerResolver.zep", 66);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_RETURN_CALL_METHOD(container, "new", NULL, 0, &name_zv);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_3, container, "has", NULL, 0, &name_zv);
	zephir_check_call_status();
	_4 = !ZEPHIR_IS_TRUE_IDENTICAL(&_3);
	if (_4) {
		_4 = !(zephir_class_exists(&name_zv, 1));
	}
	if (_4) {
		ZEPHIR_INIT_VAR(&_5$$5);
		object_init_ex(&_5$$5, phalcon_container_exceptions_exception_ce);
		ZEPHIR_INIT_VAR(&_6$$5);
		ZEPHIR_CONCAT_SVS(&_6$$5, "Cannot resolve a fresh '", &name_zv, "': it is not registered in the Di and is not an existing class");
		ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", NULL, 8, &_6$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$5, "phalcon/Auth/Internal/ContainerResolver.zep", 76);
		ZEPHIR_MM_RESTORE();
		return;
	}

	/* try_start_1: */

		ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &name_zv);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_7);
		ZVAL_OBJ(&_7, EG(exception));
		Z_ADDREF_P(&_7);
		if (zephir_instance_of_ev(&_7, phalcon_di_exception_ce)) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_7);
			ZEPHIR_INIT_VAR(&_8$$7);
			object_init_ex(&_8$$7, phalcon_container_exceptions_exception_ce);
			ZEPHIR_INIT_VAR(&_9$$7);
			ZEPHIR_CONCAT_SVS(&_9$$7, "Failed to resolve '", &name_zv, "' from the Di container");
			ZVAL_LONG(&_10$$7, 0);
			ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", NULL, 8, &_9$$7, &_10$$7, &e);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_8$$7, "phalcon/Auth/Internal/ContainerResolver.zep", 86);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
}

/**
 * Resolves the first candidate service name that the container can
 * provide, as a shared instance. Used for framework services (request,
 * cookies, session) whose container key may vary between application
 * setups.
 *
 * @param list<string> $candidates
 *
 * @throws ContainerException
 */
PHP_METHOD(Phalcon_Auth_Internal_ContainerResolver, requireService)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *context = NULL;
	zval candidates;
	zval *container, container_sub, *candidates_param = NULL, context_zv, name, *_0, _3, _6, _7, _8, _1$$3, _5$$5;

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&context_zv);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&candidates);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(container)
		ZEPHIR_Z_PARAM_ARRAY(candidates, candidates_param)
		Z_PARAM_STR(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	container = ZEND_CALL_ARG(execute_data, 1);
	candidates_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_get_arrval(&candidates, candidates_param);
	zephir_memory_observe(&context_zv);
	ZVAL_STR_COPY(&context_zv, context);
	ZEPHIR_CALL_SELF(NULL, "ensurecontainer", NULL, 0, container);
	zephir_check_call_status();
	zephir_is_iterable(&candidates, 0, "phalcon/Auth/Internal/ContainerResolver.zep", 112);
	if (Z_TYPE_P(&candidates) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&candidates), _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			ZVAL_COPY(&name, _0);
			ZEPHIR_CALL_METHOD(&_1$$3, container, "has", NULL, 0, &name);
			zephir_check_call_status();
			if (zephir_is_true(&_1$$3)) {
				ZEPHIR_RETURN_CALL_SELF("resolveshared", &_2, 351, container, &name);
				zephir_check_call_status();
				RETURN_MM();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &candidates, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &candidates, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &candidates, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &candidates, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$5, container, "has", NULL, 0, &name);
				zephir_check_call_status();
				if (zephir_is_true(&_5$$5)) {
					ZEPHIR_RETURN_CALL_SELF("resolveshared", &_2, 351, container, &name);
					zephir_check_call_status();
					RETURN_MM();
				}
		}
	}
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_INIT_VAR(&_6);
	object_init_ex(&_6, phalcon_container_exceptions_exception_ce);
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_join_str(&_7, SL(", "), &candidates);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_SVSSV(&_8, "Auth ", &context_zv, " requires service. None of the following are ", "bound in the container: ", &_7);
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 8, &_8);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_6, "phalcon/Auth/Internal/ContainerResolver.zep", 115);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Builds the ordered candidate list for a framework service:
 * an explicit override from options['services'][key] if present,
 * otherwise the interface FQN followed by the conventional short name.
 *
 * @param array<string, mixed> $options
 *
 * @return list<string>
 */
PHP_METHOD(Phalcon_Auth_Internal_ContainerResolver, serviceCandidates)
{
	zend_bool _0$$3, _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *key = NULL, *fqn = NULL, *shortName = NULL;
	zval *options_param = NULL, key_zv, fqn_zv, shortName_zv, services, override;
	zval options;

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&fqn_zv);
	ZVAL_UNDEF(&shortName_zv);
	ZVAL_UNDEF(&services);
	ZVAL_UNDEF(&override);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
		Z_PARAM_STR(key)
		Z_PARAM_STR(fqn)
		Z_PARAM_STR(shortName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	options_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&options, options_param);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	zephir_memory_observe(&fqn_zv);
	ZVAL_STR_COPY(&fqn_zv, fqn);
	zephir_memory_observe(&shortName_zv);
	ZVAL_STR_COPY(&shortName_zv, shortName);
	zephir_memory_observe(&services);
	if (zephir_array_isset_string_fetch(&services, &options, SL("services"), 0)) {
		_0$$3 = Z_TYPE_P(&services) == IS_ARRAY;
		if (_0$$3) {
			zephir_memory_observe(&override);
			_0$$3 = zephir_array_isset_fetch(&override, &services, &key_zv, 0);
		}
		if (_0$$3) {
			_1$$4 = Z_TYPE_P(&override) == IS_STRING;
			if (_1$$4) {
				_1$$4 = !ZEPHIR_IS_STRING_IDENTICAL(&override, "");
			}
			if (_1$$4) {
				zephir_create_array(return_value, 1, 0);
				zephir_array_fast_append(return_value, &override);
				RETURN_MM();
			}
		}
	}
	zephir_create_array(return_value, 2, 0);
	zephir_array_fast_append(return_value, &fqn_zv);
	zephir_array_fast_append(return_value, &shortName_zv);
	RETURN_MM();
}

/**
 * Convenience composition of serviceCandidates() + requireService():
 * resolves the first bound candidate for a framework service whose
 * container key may vary, using the options override or the
 * [interface FQN, conventional short name] fallback.
 *
 * @param array<string, mixed> $options
 *
 * @throws ContainerException
 */
PHP_METHOD(Phalcon_Auth_Internal_ContainerResolver, resolveCandidate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *key = NULL, *fqn = NULL, *shortName = NULL, *context = NULL;
	zval options;
	zval *container, container_sub, *options_param = NULL, key_zv, fqn_zv, shortName_zv, context_zv, _0;

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&fqn_zv);
	ZVAL_UNDEF(&shortName_zv);
	ZVAL_UNDEF(&context_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_ZVAL(container)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
		Z_PARAM_STR(key)
		Z_PARAM_STR(fqn)
		Z_PARAM_STR(shortName)
		Z_PARAM_STR(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	container = ZEND_CALL_ARG(execute_data, 1);
	options_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_get_arrval(&options, options_param);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	zephir_memory_observe(&fqn_zv);
	ZVAL_STR_COPY(&fqn_zv, fqn);
	zephir_memory_observe(&shortName_zv);
	ZVAL_STR_COPY(&shortName_zv, shortName);
	zephir_memory_observe(&context_zv);
	ZVAL_STR_COPY(&context_zv, context);
	ZEPHIR_CALL_SELF(&_0, "servicecandidates", NULL, 0, &options, &key_zv, &fqn_zv, &shortName_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_SELF("requireservice", NULL, 0, container, &_0, &context_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolves a shared instance: get() on the Container; getShared() on the
 * legacy Di. Legacy-Di failures are normalized to a Container exception
 * with the original chained as the cause.
 *
 * @throws ContainerException
 */
PHP_METHOD(Phalcon_Auth_Internal_ContainerResolver, resolveShared)
{
	zval _2$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *name = NULL;
	zval *container, container_sub, name_zv, e, _0, _1$$5, _3$$5;

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_2$$5);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(container)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	container = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (zephir_instance_of_ev(container, phalcon_contracts_container_service_collection_ce)) {
		ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &name_zv);
		zephir_check_call_status();
		RETURN_MM();
	}

	/* try_start_1: */

		ZEPHIR_RETURN_CALL_METHOD(container, "getshared", NULL, 0, &name_zv);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_0);
		ZVAL_OBJ(&_0, EG(exception));
		Z_ADDREF_P(&_0);
		if (zephir_instance_of_ev(&_0, phalcon_di_exception_ce)) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_0);
			ZEPHIR_INIT_VAR(&_1$$5);
			object_init_ex(&_1$$5, phalcon_container_exceptions_exception_ce);
			ZEPHIR_INIT_VAR(&_2$$5);
			ZEPHIR_CONCAT_SVS(&_2$$5, "Failed to resolve '", &name_zv, "' from the Di container");
			ZVAL_LONG(&_3$$5, 0);
			ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 8, &_2$$5, &_3$$5, &e);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$5, "phalcon/Auth/Internal/ContainerResolver.zep", 193);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
}

