
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */
/**
 * Single entry-point factory that builds a fully wired Phalcon\Auth\Manager
 * from a config tree. Framework-shared services (RequestInterface,
 * CookiesInterface, SessionManagerInterface) are resolved from the injected
 * container so the manager wires against the real application singletons,
 * not separately constructed copies.
 *
 *  [
 *      'guards' => [
 *          'web' => [
 *              'type'    => 'session',
 *              'default' => true,
 *              'adapter' => [
 *                  'name'    => 'model',
 *                  'options' => [
 *                      'model' => User::class
 *                  ],
 *              ],
 *              'options' => [],
 *          ],
 *          'api' => [
 *              'type'    => 'token',
 *              'adapter' => [
 *                  'name'    => 'model',
 *                  'options' => [
 *                      'model' => User::class
 *                  ]
 *              ],
 *              'options' => [
 *                  'inputKey'   => 'api_token',
 *                  'storageKey' => 'api_token'
 *              ],
 *          ],
 *      ],
 *      'access' => [
 *          'auth'  => \Phalcon\Auth\Access\Auth::class,
 *          'guest' => \Phalcon\Auth\Access\Guest::class,
 *      ],
 *  ]
 *
 * @phpstan-type GuardConfig array{
 *     type: string,
 *     default?: bool,
 *     adapter: array{name: string, options?: array<string, mixed>},
 *     options?: array<string, mixed>,
 * }
 *
 * @phpstan-type AuthConfig array{
 *     guards?: array<string, GuardConfig>,
 *     access?: array<string, class-string<Access>>,
 * }
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_ManagerFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth, ManagerFactory, phalcon, auth_managerfactory, phalcon_auth_managerfactory_method_entry, 0);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_auth_managerfactory_ce, SL("accessLocator"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Auth\\Access\\AccessLocator"));
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_auth_managerfactory_ce, SL("adapterLocator"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Auth\\Adapter\\AdapterLocator"));
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		const char *_zut[] = { "Phalcon\\Contracts\\Container\\Service\\Collection", "Phalcon\\Di\\DiInterface" };
		zephir_declare_typed_property_union(phalcon_auth_managerfactory_ce, SL("container"), &_zc0, ZEND_ACC_PROTECTED, 0, _zut, 2);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_auth_managerfactory_ce, SL("guardLocator"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Auth\\Guard\\GuardLocator"));
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_auth_managerfactory_ce, SL("hasher"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Encryption\\Security"));
	}

	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_ManagerFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *hasher, hasher_sub, *container, container_sub, *adapterLocator = NULL, adapterLocator_sub, *guardLocator = NULL, guardLocator_sub, *accessLocator = NULL, accessLocator_sub, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hasher_sub);
	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&adapterLocator_sub);
	ZVAL_UNDEF(&guardLocator_sub);
	ZVAL_UNDEF(&accessLocator_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("hasher", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("adapterLocator", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("guardLocator", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("accessLocator", 13, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 5)
		Z_PARAM_OBJECT_OF_CLASS(hasher, phalcon_encryption_security_ce)
		Z_PARAM_ZVAL(container)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(adapterLocator, phalcon_auth_adapter_adapterlocator_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(guardLocator, phalcon_auth_guard_guardlocator_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(accessLocator, phalcon_auth_access_accesslocator_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 3, &hasher, &container, &adapterLocator, &guardLocator, &accessLocator);
	if (!adapterLocator) {
		adapterLocator = &adapterLocator_sub;
		adapterLocator = &__$null;
	}
	if (!guardLocator) {
		guardLocator = &guardLocator_sub;
		guardLocator = &__$null;
	}
	if (!accessLocator) {
		accessLocator = &accessLocator_sub;
		accessLocator = &__$null;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 460, container);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 461, hasher);
	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(adapterLocator) != IS_NULL) {
		ZEPHIR_CPY_WRT(&_0, adapterLocator);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		object_init_ex(&_0, phalcon_auth_adapter_adapterlocator_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 421, container);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 462, &_0);
	ZEPHIR_INIT_VAR(&_1);
	if (Z_TYPE_P(guardLocator) != IS_NULL) {
		ZEPHIR_CPY_WRT(&_1, guardLocator);
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		object_init_ex(&_1, phalcon_auth_guard_guardlocator_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 421, container);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 463, &_1);
	ZEPHIR_INIT_VAR(&_2);
	if (Z_TYPE_P(accessLocator) != IS_NULL) {
		ZEPHIR_CPY_WRT(&_2, accessLocator);
	} else {
		ZEPHIR_INIT_NVAR(&_2);
		object_init_ex(&_2, phalcon_auth_access_accesslocator_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 421, container);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 464, &_2);
	ZEPHIR_MM_RESTORE();
}

/**
 * @phpstan-param AuthConfig|ConfigInterface $config
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_ManagerFactory, load)
{
	zval _18$$4, _32$$5;
	zend_string *_5;
	zend_ulong _4;
	zend_bool _0, _23;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL, *_14 = NULL, *_17 = NULL, *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, accessList, adapter, gconf, guard, guards, manager, name, _2, *_3, _22, _1$$3, _6$$4, _7$$4, _9$$4, _10$$4, _12$$4, _13$$4, _15$$4, _16$$4, _19$$4, _20$$4, _24$$5, _25$$5, _26$$5, _27$$5, _28$$5, _29$$5, _30$$5, _31$$5, _33$$5, _34$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&gconf);
	ZVAL_UNDEF(&guard);
	ZVAL_UNDEF(&guards);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_27$$5);
	ZVAL_UNDEF(&_28$$5);
	ZVAL_UNDEF(&_29$$5);
	ZVAL_UNDEF(&_30$$5);
	ZVAL_UNDEF(&_31$$5);
	ZVAL_UNDEF(&_33$$5);
	ZVAL_UNDEF(&_34$$5);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_32$$5);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("accessLocator", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("adapterLocator", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("guardLocator", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_SEPARATE_PARAM(config);
	_0 = Z_TYPE_P(config) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(config, phalcon_config_configinterface_ce);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1$$3, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_1$$3);
	}
	ZEPHIR_INIT_VAR(&manager);
	object_init_ex(&manager, phalcon_auth_manager_ce);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 464, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &manager, "__construct", NULL, 422, &_2);
	zephir_check_call_status();
	if (zephir_array_isset_value_string(config, SL("guards"))) {
		zephir_memory_observe(&guards);
		zephir_array_fetch_string(&guards, config, SL("guards"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 121);
	} else {
		ZEPHIR_INIT_NVAR(&guards);
		array_init(&guards);
	}
	zephir_is_iterable(&guards, 0, "phalcon/Auth/ManagerFactory.zep", 142);
	if (Z_TYPE_P(&guards) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&guards), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&name, _5);
			} else {
				ZVAL_LONG(&name, _4);
			}
			ZEPHIR_INIT_NVAR(&gconf);
			ZVAL_COPY(&gconf, _3);
			zephir_read_property_cached(&_6$$4, this_ptr, _zephir_prop_1, 462, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_9$$4);
			ZEPHIR_CONCAT_SVS(&_9$$4, "guard '", &name, "'");
			ZEPHIR_INIT_NVAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "adapter");
			ZEPHIR_CALL_CE_STATIC(&_7$$4, phalcon_auth_internal_options_ce, "requirearray", &_8, 0, &gconf, &_10$$4, &_9$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&adapter, this_ptr, "buildadapter", &_11, 0, &_6$$4, &_7$$4);
			zephir_check_call_status();
			zephir_read_property_cached(&_12$$4, this_ptr, _zephir_prop_2, 463, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_15$$4);
			ZEPHIR_CONCAT_SVS(&_15$$4, "guard '", &name, "'");
			ZEPHIR_INIT_NVAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "type");
			ZEPHIR_CALL_CE_STATIC(&_13$$4, phalcon_auth_internal_options_ce, "requirestring", &_14, 0, &gconf, &_10$$4, &_15$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_16$$4);
			if (zephir_array_isset_value_string(&gconf, SL("options"))) {
				ZEPHIR_OBS_NVAR(&_16$$4);
				zephir_array_fetch_string(&_16$$4, &gconf, SL("options"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 132);
			} else {
				ZEPHIR_INIT_NVAR(&_16$$4);
				array_init(&_16$$4);
			}
			ZEPHIR_CALL_METHOD(&guard, this_ptr, "buildguard", &_17, 0, &_12$$4, &_13$$4, &adapter, &_16$$4);
			zephir_check_call_status();
			zephir_cast_to_string(&_18$$4, &name);
			ZEPHIR_INIT_NVAR(&_19$$4);
			if (zephir_array_isset_value_string(&gconf, SL("default"))) {
				ZEPHIR_OBS_NVAR(&_19$$4);
				zephir_array_fetch_string(&_19$$4, &gconf, SL("default"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 138);
			} else {
				ZEPHIR_INIT_NVAR(&_19$$4);
				ZVAL_BOOL(&_19$$4, 0);
			}
			ZVAL_BOOL(&_20$$4, zephir_get_boolval(&_19$$4));
			ZEPHIR_CALL_METHOD(NULL, &manager, "addguard", &_21, 423, &_18$$4, &guard, &_20$$4);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &guards, "rewind", NULL, 0);
		zephir_check_call_status();
		_23 = 1;
		while (1) {
			if (_23) {
				_23 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &guards, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_22, &guards, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_22)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &guards, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&gconf, &guards, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property_cached(&_24$$5, this_ptr, _zephir_prop_1, 462, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_26$$5);
				ZEPHIR_CONCAT_SVS(&_26$$5, "guard '", &name, "'");
				ZEPHIR_INIT_NVAR(&_27$$5);
				ZVAL_STRING(&_27$$5, "adapter");
				ZEPHIR_CALL_CE_STATIC(&_25$$5, phalcon_auth_internal_options_ce, "requirearray", &_8, 0, &gconf, &_27$$5, &_26$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&adapter, this_ptr, "buildadapter", &_11, 0, &_24$$5, &_25$$5);
				zephir_check_call_status();
				zephir_read_property_cached(&_28$$5, this_ptr, _zephir_prop_2, 463, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_30$$5);
				ZEPHIR_CONCAT_SVS(&_30$$5, "guard '", &name, "'");
				ZEPHIR_INIT_NVAR(&_27$$5);
				ZVAL_STRING(&_27$$5, "type");
				ZEPHIR_CALL_CE_STATIC(&_29$$5, phalcon_auth_internal_options_ce, "requirestring", &_14, 0, &gconf, &_27$$5, &_30$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_31$$5);
				if (zephir_array_isset_value_string(&gconf, SL("options"))) {
					ZEPHIR_OBS_NVAR(&_31$$5);
					zephir_array_fetch_string(&_31$$5, &gconf, SL("options"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 132);
				} else {
					ZEPHIR_INIT_NVAR(&_31$$5);
					array_init(&_31$$5);
				}
				ZEPHIR_CALL_METHOD(&guard, this_ptr, "buildguard", &_17, 0, &_28$$5, &_29$$5, &adapter, &_31$$5);
				zephir_check_call_status();
				zephir_cast_to_string(&_32$$5, &name);
				ZEPHIR_INIT_NVAR(&_33$$5);
				if (zephir_array_isset_value_string(&gconf, SL("default"))) {
					ZEPHIR_OBS_NVAR(&_33$$5);
					zephir_array_fetch_string(&_33$$5, &gconf, SL("default"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 138);
				} else {
					ZEPHIR_INIT_NVAR(&_33$$5);
					ZVAL_BOOL(&_33$$5, 0);
				}
				ZVAL_BOOL(&_34$$5, zephir_get_boolval(&_33$$5));
				ZEPHIR_CALL_METHOD(NULL, &manager, "addguard", &_21, 423, &_32$$5, &guard, &_34$$5);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&gconf);
	ZEPHIR_INIT_NVAR(&name);
	if (zephir_array_isset_value_string(config, SL("access"))) {
		zephir_memory_observe(&accessList);
		zephir_array_fetch_string(&accessList, config, SL("access"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 142);
	} else {
		ZEPHIR_INIT_NVAR(&accessList);
		array_init(&accessList);
	}
	if (!(ZEPHIR_IS_EMPTY(&accessList))) {
		ZEPHIR_CALL_METHOD(NULL, &manager, "addaccesslist", NULL, 424, &accessList);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&manager);
}

/**
 * @param array{name: string, options?: array<string, mixed>} $cfg
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_ManagerFactory, buildAdapter)
{
	zend_class_entry *_6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval cfg;
	zval *locator, locator_sub, *cfg_param = NULL, className, name, _0, _1, _2, _4, _5, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&locator_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&cfg);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("hasher", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(locator, phalcon_auth_adapter_adapterlocator_ce)
		ZEPHIR_Z_PARAM_ARRAY(cfg, cfg_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &locator, &cfg_param);
	zephir_get_arrval(&cfg, cfg_param);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "name");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "adapter");
	ZEPHIR_CALL_CE_STATIC(&name, phalcon_auth_internal_options_ce, "requirestring", NULL, 0, &cfg, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, locator, "has", NULL, 0, &name);
	zephir_check_call_status();
	if (!zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_auth_exceptions_unknownadapter_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 425, &name);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Auth/ManagerFactory.zep", 162);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&className, locator, "getclass", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 461, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	if (zephir_array_isset_value_string(&cfg, SL("options"))) {
		ZEPHIR_OBS_NVAR(&_5);
		zephir_array_fetch_string(&_5, &cfg, SL("options"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 169);
	} else {
		ZEPHIR_INIT_NVAR(&_5);
		array_init(&_5);
	}
	_6 = zephir_fetch_class(&className);
	ZEPHIR_RETURN_CALL_CE_STATIC(_6, "fromoptions", NULL, 0, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param array<string, mixed> $options
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_ManagerFactory, buildGuard)
{
	zend_class_entry *_3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zend_string *type = NULL;
	zval *locator, locator_sub, type_zv, *adapter, adapter_sub, *options_param = NULL, className, _0, _2, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&locator_sub);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&adapter_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(locator, phalcon_auth_guard_guardlocator_ce)
		Z_PARAM_STR(type)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_contracts_auth_adapter_adapter_ce)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	locator = ZEND_CALL_ARG(execute_data, 1);
	adapter = ZEND_CALL_ARG(execute_data, 3);
	options_param = ZEND_CALL_ARG(execute_data, 4);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	zephir_get_arrval(&options, options_param);
	ZEPHIR_CALL_METHOD(&_0, locator, "has", NULL, 0, &type_zv);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_auth_exceptions_unknownguard_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 426, &type_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Auth/ManagerFactory.zep", 187);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&className, locator, "getclass", NULL, 0, &type_zv);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 460, PH_NOISY_CC | PH_READONLY);
	_3 = zephir_fetch_class(&className);
	ZEPHIR_RETURN_CALL_CE_STATIC(_3, "fromoptions", NULL, 0, adapter, &_2, &options);
	zephir_check_call_status();
	RETURN_MM();
}

