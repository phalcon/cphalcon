
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Mvc\Model\Row
 *
 * This component allows Phalcon\Mvc\Model to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Row) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Row, phalcon, mvc_model_row, phalcon_mvc_model_row_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_row_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_mvc_model_row_ce TSRMLS_CC, 1, phalcon_mvc_model_resultinterface_ce);

	return SUCCESS;

}

/**
 * Set the current object's state
 *
 * @param int dirtyState
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, setDirtyState) {

	zval *dirtyState_param = NULL;
	int dirtyState;

	zephir_fetch_params(0, 1, 0, &dirtyState_param);

		dirtyState = zephir_get_intval(dirtyState_param);


	RETURN_BOOL(0);

}

/**
 * Checks whether offset exists in the row
 *
 * @param string|int $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetExists) {

	zval *index;

	zephir_fetch_params(0, 1, 0, &index);



	RETURN_BOOL(0 == 0);

}

/**
 * Gets a record in a specific position of the row
 *
 * @param string|int index
 * @return string|Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetGet) {

	zval *index, *value;

	zephir_fetch_params(0, 1, 0, &index);



	if ((0 == 1)) {
		RETURN_CTORW(value);
	}
	ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "The index does not exist in the row");
	return;

}

/**
 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param string|int index
 * @param Phalcon\Mvc\ModelInterface value
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetSet) {

	zval *index, *value;

	zephir_fetch_params(0, 2, 0, &index, &value);



	ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Row is an immutable ArrayAccess object");
	return;

}

/**
 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param string|int offset
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetUnset) {

	zval *offset_param = NULL;
	int offset;

	zephir_fetch_params(0, 1, 0, &offset_param);

		offset = zephir_get_intval(offset_param);


	ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Row is an immutable ArrayAccess object");
	return;

}

/**
 * Returns the instance as an array representation
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, toArray) {

	ZEPHIR_MM_GROW();

	zephir_call_func_p1(return_value, "get_object_vars", this_ptr);
	RETURN_MM();

}

