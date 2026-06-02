
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
ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_CsEnv)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Container\\Resolver\\Lazy, CsEnv, phalcon, container_resolver_lazy_csenv, phalcon_container_resolver_lazy_env_ce, phalcon_container_resolver_lazy_csenv_method_entry, 0);

	return SUCCESS;
}

/**
 * Resolve the getEnv() from keys as a comma separated list
 *
 * @param object $container
 *
 * @return array
 * @throws EnvNotDefined
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_CsEnv, resolve)
{
	zend_bool _11$$3;
	zend_string *_7$$3;
	zend_ulong _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, values, result, key, value, _0, _1, _2, _3, _4, *_5$$3, _10$$3, _8$$4, _12$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_12$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(container)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &container);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getenv", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ",");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\"");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "\\");
	ZEPHIR_CALL_FUNCTION(&values, "str_getcsv", NULL, 350, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("vartype"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_4) != IS_NULL) {
		ZEPHIR_INIT_VAR(&result);
		array_init(&result);
		zephir_is_iterable(&values, 0, "phalcon/Container/Resolver/Lazy/CsEnv.zep", 60);
		if (Z_TYPE_P(&values) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&values), _6$$3, _7$$3, _5$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_7$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _7$$3);
				} else {
					ZVAL_LONG(&key, _6$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _5$$3);
				zephir_read_property(&_8$$4, this_ptr, ZEND_STRL("vartype"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_MAKE_REF(&value);
				ZEPHIR_CALL_FUNCTION(NULL, "settype", &_9, 13, &value, &_8$$4);
				ZEPHIR_UNREF(&value);
				zephir_check_call_status();
				zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
			zephir_check_call_status();
			_11$$3 = 1;
			while (1) {
				if (_11$$3) {
					_11$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_10$$3, &values, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &values, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
				zephir_check_call_status();
					zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("vartype"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_MAKE_REF(&value);
					ZEPHIR_CALL_FUNCTION(NULL, "settype", &_9, 13, &value, &_12$$5);
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

