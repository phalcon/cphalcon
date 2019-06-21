
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
* (c) Phalcon Team <team@phalconphp.com>
*
* For the full copyright and license information, please view the LICENSE.txt
* file that was distributed with this source code.
*/
/**
 * Phalcon\Collection\ReadCollection
 *
 * Phalcon\Collection\ReadCollection is a read only Collection object
 */
ZEPHIR_INIT_CLASS(Phalcon_Collection_ReadCollection) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Collection, ReadCollection, phalcon, collection_readcollection, phalcon_collection_collection_ce, phalcon_collection_readcollection_method_entry, 0);

	return SUCCESS;

}

/**
 * Delete the element from the collection
 *
 * @param string $element
 * @param bool   $insensitive
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Collection_ReadCollection, remove) {

	zval *element_param = NULL;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);

	zephir_get_strval(&element, element_param);


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_collection_exception_ce, "The object is read only", "phalcon/Collection/ReadCollection.zep", 33);
	return;

}

/**
 * Set an element in the collection
 *
 * @param string $element
 * @param mixed  $value
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Collection_ReadCollection, set) {

	zval *element_param = NULL, *value, value_sub;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element_param, &value);

	zephir_get_strval(&element, element_param);


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_collection_exception_ce, "The object is read only", "phalcon/Collection/ReadCollection.zep", 46);
	return;

}

