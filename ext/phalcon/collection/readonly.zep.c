
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
#include "kernel/exception.h"
#include "kernel/operators.h"
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
 * Phalcon\Collection\ReadOnly is a read only Collection object
 */
ZEPHIR_INIT_CLASS(Phalcon_Collection_ReadOnly) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Collection, ReadOnly, phalcon, collection_readonly, phalcon_collection_ce, phalcon_collection_readonly_method_entry, 0);

	return SUCCESS;

}

/**
 * Delete the element from the collection
 */
PHP_METHOD(Phalcon_Collection_ReadOnly, remove) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *element_param = NULL;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);

	zephir_get_strval(&element, element_param);


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_collection_exception_ce, "The object is read only", "phalcon/Collection/ReadOnly.zep", 25);
	return;

}

/**
 * Set an element in the collection
 */
PHP_METHOD(Phalcon_Collection_ReadOnly, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *element_param = NULL, *value, value_sub;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(element)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element_param, &value);

	zephir_get_strval(&element, element_param);


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_collection_exception_ce, "The object is read only", "phalcon/Collection/ReadOnly.zep", 33);
	return;

}

