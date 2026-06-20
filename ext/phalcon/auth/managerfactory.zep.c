
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"


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

	/**
	 * @var AccessLocator
	 */
	zend_declare_property_null(phalcon_auth_managerfactory_ce, SL("accessLocator"), ZEND_ACC_PROTECTED);
	/**
	 * @var AdapterLocator
	 */
	zend_declare_property_null(phalcon_auth_managerfactory_ce, SL("adapterLocator"), ZEND_ACC_PROTECTED);
	/**
	 * @var Collection|DiInterface
	 */
	zend_declare_property_null(phalcon_auth_managerfactory_ce, SL("container"), ZEND_ACC_PROTECTED);
	/**
	 * @var GuardLocator
	 */
	zend_declare_property_null(phalcon_auth_managerfactory_ce, SL("guardLocator"), ZEND_ACC_PROTECTED);
	/**
	 * @var Security
	 */
	zend_declare_property_null(phalcon_auth_managerfactory_ce, SL("hasher"), ZEND_ACC_PROTECTED);
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
	ZEPHIR_CALL_CE_STATIC(NULL, phalcon_auth_internal_containerresolver_ce, "ensurecontainer", NULL, 0, container);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hasher"), hasher);
	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(adapterLocator) != IS_NULL) {
		ZEPHIR_CPY_WRT(&_0, adapterLocator);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		object_init_ex(&_0, phalcon_auth_adapter_adapterlocator_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 332, container);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("adapterLocator"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	if (Z_TYPE_P(guardLocator) != IS_NULL) {
		ZEPHIR_CPY_WRT(&_1, guardLocator);
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		object_init_ex(&_1, phalcon_auth_guard_guardlocator_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 332, container);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("guardLocator"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	if (Z_TYPE_P(accessLocator) != IS_NULL) {
		ZEPHIR_CPY_WRT(&_2, accessLocator);
	} else {
		ZEPHIR_INIT_NVAR(&_2);
		object_init_ex(&_2, phalcon_auth_access_accesslocator_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 332, container);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("accessLocator"), &_2);
	ZEPHIR_MM_RESTORE();
}

/**
 * @phpstan-param AuthConfig|ConfigInterface $config
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_ManagerFactory, load)
{
	zval _19$$5, _33$$6;
	zend_string *_6;
	zend_ulong _5;
	zend_bool _0, _1, _24;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL, *_15 = NULL, *_18 = NULL, *_22 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, accessList, adapter, gconf, guard, guards, manager, name, _3, *_4, _23, _2$$4, _7$$5, _8$$5, _10$$5, _11$$5, _13$$5, _14$$5, _16$$5, _17$$5, _20$$5, _21$$5, _25$$6, _26$$6, _27$$6, _28$$6, _29$$6, _30$$6, _31$$6, _32$$6, _34$$6, _35$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&gconf);
	ZVAL_UNDEF(&guard);
	ZVAL_UNDEF(&guards);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_29$$6);
	ZVAL_UNDEF(&_30$$6);
	ZVAL_UNDEF(&_31$$6);
	ZVAL_UNDEF(&_32$$6);
	ZVAL_UNDEF(&_34$$6);
	ZVAL_UNDEF(&_35$$6);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_33$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_SEPARATE_PARAM(config);
	_0 = Z_TYPE_P(config) != IS_ARRAY;
	if (_0) {
		_0 = !((zephir_instance_of_ev(config, phalcon_config_configinterface_ce)));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_ce_type_error, "The parameter must be an array or instance of ConfigInterface", "phalcon/Auth/ManagerFactory.zep", 128);
		return;
	}
	_1 = Z_TYPE_P(config) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(config, phalcon_config_configinterface_ce);
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2$$4, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_2$$4);
	}
	ZEPHIR_INIT_VAR(&manager);
	object_init_ex(&manager, phalcon_auth_manager_ce);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("accessLocator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &manager, "__construct", NULL, 333, &_3);
	zephir_check_call_status();
	if (zephir_array_isset_value_string(config, SL("guards"))) {
		zephir_memory_observe(&guards);
		zephir_array_fetch_string(&guards, config, SL("guards"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 141);
	} else {
		ZEPHIR_INIT_NVAR(&guards);
		array_init(&guards);
	}
	zephir_is_iterable(&guards, 0, "phalcon/Auth/ManagerFactory.zep", 162);
	if (Z_TYPE_P(&guards) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&guards), _5, _6, _4)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&name, _6);
			} else {
				ZVAL_LONG(&name, _5);
			}
			ZEPHIR_INIT_NVAR(&gconf);
			ZVAL_COPY(&gconf, _4);
			zephir_read_property(&_7$$5, this_ptr, ZEND_STRL("adapterLocator"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_10$$5);
			ZEPHIR_CONCAT_SVS(&_10$$5, "guard '", &name, "'");
			ZEPHIR_INIT_NVAR(&_11$$5);
			ZVAL_STRING(&_11$$5, "adapter");
			ZEPHIR_CALL_CE_STATIC(&_8$$5, phalcon_auth_internal_options_ce, "requirearray", &_9, 0, &gconf, &_11$$5, &_10$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&adapter, this_ptr, "buildadapter", &_12, 0, &_7$$5, &_8$$5);
			zephir_check_call_status();
			zephir_read_property(&_13$$5, this_ptr, ZEND_STRL("guardLocator"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_16$$5);
			ZEPHIR_CONCAT_SVS(&_16$$5, "guard '", &name, "'");
			ZEPHIR_INIT_NVAR(&_11$$5);
			ZVAL_STRING(&_11$$5, "type");
			ZEPHIR_CALL_CE_STATIC(&_14$$5, phalcon_auth_internal_options_ce, "requirestring", &_15, 0, &gconf, &_11$$5, &_16$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_17$$5);
			if (zephir_array_isset_value_string(&gconf, SL("options"))) {
				ZEPHIR_OBS_NVAR(&_17$$5);
				zephir_array_fetch_string(&_17$$5, &gconf, SL("options"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 152);
			} else {
				ZEPHIR_INIT_NVAR(&_17$$5);
				array_init(&_17$$5);
			}
			ZEPHIR_CALL_METHOD(&guard, this_ptr, "buildguard", &_18, 0, &_13$$5, &_14$$5, &adapter, &_17$$5);
			zephir_check_call_status();
			zephir_cast_to_string(&_19$$5, &name);
			ZEPHIR_INIT_NVAR(&_20$$5);
			if (zephir_array_isset_value_string(&gconf, SL("default"))) {
				ZEPHIR_OBS_NVAR(&_20$$5);
				zephir_array_fetch_string(&_20$$5, &gconf, SL("default"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 158);
			} else {
				ZEPHIR_INIT_NVAR(&_20$$5);
				ZVAL_BOOL(&_20$$5, 0);
			}
			ZVAL_BOOL(&_21$$5, zephir_get_boolval(&_20$$5));
			ZEPHIR_CALL_METHOD(NULL, &manager, "addguard", &_22, 334, &_19$$5, &guard, &_21$$5);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &guards, "rewind", NULL, 0);
		zephir_check_call_status();
		_24 = 1;
		while (1) {
			if (_24) {
				_24 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &guards, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_23, &guards, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &guards, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&gconf, &guards, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_25$$6, this_ptr, ZEND_STRL("adapterLocator"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_27$$6);
				ZEPHIR_CONCAT_SVS(&_27$$6, "guard '", &name, "'");
				ZEPHIR_INIT_NVAR(&_28$$6);
				ZVAL_STRING(&_28$$6, "adapter");
				ZEPHIR_CALL_CE_STATIC(&_26$$6, phalcon_auth_internal_options_ce, "requirearray", &_9, 0, &gconf, &_28$$6, &_27$$6);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&adapter, this_ptr, "buildadapter", &_12, 0, &_25$$6, &_26$$6);
				zephir_check_call_status();
				zephir_read_property(&_29$$6, this_ptr, ZEND_STRL("guardLocator"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_31$$6);
				ZEPHIR_CONCAT_SVS(&_31$$6, "guard '", &name, "'");
				ZEPHIR_INIT_NVAR(&_28$$6);
				ZVAL_STRING(&_28$$6, "type");
				ZEPHIR_CALL_CE_STATIC(&_30$$6, phalcon_auth_internal_options_ce, "requirestring", &_15, 0, &gconf, &_28$$6, &_31$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_32$$6);
				if (zephir_array_isset_value_string(&gconf, SL("options"))) {
					ZEPHIR_OBS_NVAR(&_32$$6);
					zephir_array_fetch_string(&_32$$6, &gconf, SL("options"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 152);
				} else {
					ZEPHIR_INIT_NVAR(&_32$$6);
					array_init(&_32$$6);
				}
				ZEPHIR_CALL_METHOD(&guard, this_ptr, "buildguard", &_18, 0, &_29$$6, &_30$$6, &adapter, &_32$$6);
				zephir_check_call_status();
				zephir_cast_to_string(&_33$$6, &name);
				ZEPHIR_INIT_NVAR(&_34$$6);
				if (zephir_array_isset_value_string(&gconf, SL("default"))) {
					ZEPHIR_OBS_NVAR(&_34$$6);
					zephir_array_fetch_string(&_34$$6, &gconf, SL("default"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 158);
				} else {
					ZEPHIR_INIT_NVAR(&_34$$6);
					ZVAL_BOOL(&_34$$6, 0);
				}
				ZVAL_BOOL(&_35$$6, zephir_get_boolval(&_34$$6));
				ZEPHIR_CALL_METHOD(NULL, &manager, "addguard", &_22, 334, &_33$$6, &guard, &_35$$6);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&gconf);
	ZEPHIR_INIT_NVAR(&name);
	if (zephir_array_isset_value_string(config, SL("access"))) {
		zephir_memory_observe(&accessList);
		zephir_array_fetch_string(&accessList, config, SL("access"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 162);
	} else {
		ZEPHIR_INIT_NVAR(&accessList);
		array_init(&accessList);
	}
	if (!(ZEPHIR_IS_EMPTY(&accessList))) {
		ZEPHIR_CALL_METHOD(NULL, &manager, "addaccesslist", NULL, 335, &accessList);
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
	zend_class_entry *_8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval cfg;
	zval *locator, locator_sub, *cfg_param = NULL, className, name, _0, _1, _2, _6, _7, _3$$3, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&locator_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&cfg);
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
		object_init_ex(&_3$$3, phalcon_auth_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Unknown auth adapter '%s'");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "sprintf", NULL, 133, &_4$$3, &name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 8, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Auth/ManagerFactory.zep", 182);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&className, locator, "getclass", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, ZEND_STRL("hasher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_7);
	if (zephir_array_isset_value_string(&cfg, SL("options"))) {
		ZEPHIR_OBS_NVAR(&_7);
		zephir_array_fetch_string(&_7, &cfg, SL("options"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 189);
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		array_init(&_7);
	}
	_8 = zephir_fetch_class(&className);
	ZEPHIR_RETURN_CALL_CE_STATIC(_8, "fromoptions", NULL, 0, &_6, &_7);
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
	zend_class_entry *_5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zend_string *type = NULL;
	zval *locator, locator_sub, type_zv, *adapter, adapter_sub, *options_param = NULL, className, _0, _4, _1$$3, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&locator_sub);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&adapter_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&options);
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
		object_init_ex(&_1$$3, phalcon_auth_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Unknown auth guard '%s'");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 133, &_2$$3, &type_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Auth/ManagerFactory.zep", 207);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&className, locator, "getclass", NULL, 0, &type_zv);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	_5 = zephir_fetch_class(&className);
	ZEPHIR_RETURN_CALL_CE_STATIC(_5, "fromoptions", NULL, 0, adapter, &_4, &options);
	zephir_check_call_status();
	RETURN_MM();
}

