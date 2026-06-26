
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
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class FilterFactory
 *
 * @package Phalcon\Filter
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_FilterFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter, FilterFactory, phalcon, filter_filterfactory, phalcon_filter_filterfactory_method_entry, 0);

	return SUCCESS;
}

/**
 * Returns a Locator object with all the helpers defined in anonymous
 * functions
 *
 * @return FilterInterface
 */
PHP_METHOD(Phalcon_Filter_FilterFactory, newInstance)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_filter_filter_ce);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getservices", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the available adapters
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Filter_FilterFactory, getServices)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_filter_filter_ce, "getdefaultmapper", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

