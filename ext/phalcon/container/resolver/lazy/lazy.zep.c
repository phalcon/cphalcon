
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_Lazy)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Container\\Resolver\\Lazy, Lazy, phalcon, container_resolver_lazy_lazy, phalcon_container_resolver_lazy_lazy_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phalcon_container_resolver_lazy_lazy_ce, 1, phalcon_contracts_container_resolver_resolvable_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_Lazy, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ioc, ioc_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(ioc)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &ioc);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolve", NULL, 0, ioc);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_Lazy, resolve)
{
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_Lazy, resolveArgument)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ioc, ioc_sub, *argument, argument_sub;

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&argument_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(ioc)
		Z_PARAM_ZVAL(argument)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &ioc, &argument);
	_0 = Z_TYPE_P(argument) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(argument, phalcon_container_resolver_lazy_lazy_ce);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(argument, "resolve", NULL, 0, ioc);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(argument, 1, 0);
	RETURN_MM();
}

/**
 * @param object                  $ioc
 * @param array<array-key, mixed> $arguments
 *
 * @return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_Lazy, resolveArguments)
{
	zend_bool _6;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments;
	zval *ioc, ioc_sub, *arguments_param = NULL, resolved, key, argument, *_0, _5, _3$$3, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&arguments);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(ioc)
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &ioc, &arguments_param);
	zephir_get_arrval(&arguments, arguments_param);
	ZEPHIR_INIT_VAR(&resolved);
	array_init(&resolved);
	zephir_is_iterable(&arguments, 0, "phalcon/Container/Resolver/Lazy/Lazy.zep", 69);
	if (Z_TYPE_P(&arguments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&arguments), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&argument);
			ZVAL_COPY(&argument, _0);
			ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "resolveargument", &_4, 0, ioc, &argument);
			zephir_check_call_status();
			zephir_array_update_zval(&resolved, &key, &_3$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &arguments, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &arguments, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &arguments, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &arguments, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&argument, &arguments, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "resolveargument", &_4, 0, ioc, &argument);
				zephir_check_call_status();
				zephir_array_update_zval(&resolved, &key, &_7$$4, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&argument);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&resolved);
}

