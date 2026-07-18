
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * Shared middleware accumulator for Route and Group: stores a list of middleware
 * class names, appended to and read back as an array.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Router_Traits_HasMiddleware)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\ADR\\Router\\Traits, HasMiddleware, phalcon, adr_router_traits_hasmiddleware, phalcon_adr_router_traits_hasmiddleware_method_entry);

	/**
	 * @var array
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_property_array(phalcon_adr_router_traits_hasmiddleware_ce, SL("middleware"), &_zc0, ZEND_ACC_PROTECTED);
	}

	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Router_Traits_HasMiddleware, getMiddleware)
{

	RETURN_MEMBER_TYPED(getThis(), "middleware", IS_ARRAY);
}

PHP_METHOD(Phalcon_ADR_Router_Traits_HasMiddleware, pushMiddleware)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *classes_param = NULL, item, *_0, _1;
	zval classes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(classes, classes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &classes_param);
	zephir_get_arrval(&classes, classes_param);
	zephir_is_iterable(&classes, 0, "phalcon/ADR/Router/Traits/HasMiddleware.zep", 39);
	if (Z_TYPE_P(&classes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&classes), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			zephir_update_property_array_append(this_ptr, SL("middleware"), &item);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &classes, "rewind", NULL, 0);
		zephir_check_call_status();
		_2 = 1;
		while (1) {
			if (_2) {
				_2 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &classes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_1, &classes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &classes, "current", NULL, 0);
			zephir_check_call_status();
				zephir_update_property_array_append(this_ptr, SL("middleware"), &item);
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();
}

