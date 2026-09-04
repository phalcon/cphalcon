
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
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
/**
 * @phpstan-import-type container_csv_values from ContainerTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_CsEnv)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Container\\Resolver\\Lazy, CsEnv, phalcon, container_resolver_lazy_csenv, phalcon_container_resolver_lazy_env_ce, phalcon_container_resolver_lazy_csenv_method_entry, 0);

	return SUCCESS;
}

/**
 * Resolve the getEnv() from keys as a comma separated list
 *
 * @phpstan-return container_csv_values
 * @throws EnvNotDefined
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_CsEnv, resolve)
{
	zend_bool _13$$3;
	zend_string *_9$$3;
	zend_ulong _8$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ioc, ioc_sub, values, result, key, value, _0, _1, _2, _3, _4, *_5$$3, _6$$3, *_7$$3, _12$$3, _10$$4, _14$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_14$$5);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("vartype", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(ioc)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &ioc);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getenv", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ",");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\"");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "\\");
	ZEPHIR_CALL_FUNCTION(&values, "str_getcsv", NULL, 499, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 550, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_4) != IS_NULL) {
		ZEPHIR_INIT_VAR(&result);
		array_init(&result);
		if (Z_TYPE_P(&values) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_6$$3);
			zephir_string_to_char_array(&_6$$3, &values);
			_5$$3 = &_6$$3;
		} else {
			_5$$3 = &values;
		}
		zephir_is_iterable(_5$$3, 0, "phalcon/Container/Resolver/Lazy/CsEnv.zep", 62);
		if (Z_TYPE_P(_5$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_5$$3), _8$$3, _9$$3, _7$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_9$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _9$$3);
				} else {
					ZVAL_LONG(&key, _8$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _7$$3);
				zephir_read_property_cached(&_10$$4, this_ptr, _zephir_prop_0, 550, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_MAKE_REF(&value);
				ZEPHIR_CALL_FUNCTION(NULL, "settype", &_11, 17, &value, &_10$$4);
				ZEPHIR_UNREF(&value);
				zephir_check_call_status();
				zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _5$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_13$$3 = 1;
			while (1) {
				if (_13$$3) {
					_13$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _5$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_12$$3, _5$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_12$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, _5$$3, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, _5$$3, "current", NULL, 0);
				zephir_check_call_status();
					zephir_read_property_cached(&_14$$5, this_ptr, _zephir_prop_0, 550, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_MAKE_REF(&value);
					ZEPHIR_CALL_FUNCTION(NULL, "settype", &_11, 17, &value, &_14$$5);
					ZEPHIR_UNREF(&value);
					zephir_check_call_status();
					zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZEPHIR_CPY_WRT(&values, &result);
	}
	RETURN_CCTOR(&values);
}

