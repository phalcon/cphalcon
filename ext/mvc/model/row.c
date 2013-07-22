
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/exception.h"

/**
 * Phalcon\Mvc\Model\Row
 *
 * This component allows Phalcon\Mvc\Model to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 */


/**
 * Phalcon\Mvc\Model\Row initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Row){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Row, mvc_model_row, phalcon_mvc_model_row_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_row_ce TSRMLS_CC, 2, zend_ce_arrayaccess, phalcon_mvc_model_resultinterface_ce);

	return SUCCESS;
}

/**
 * Set the current object's state
 *
 * @param int $dirtyState
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, setDirtyState){

	zval *dirty_state;

	phalcon_fetch_params(0, 1, 0, &dirty_state);
	
	RETURN_FALSE;
}

/**
 * Checks whether offset exists in the row
 *
 * @param int $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetExists){

	zval *index;

	phalcon_fetch_params(0, 1, 0, &index);
	
	if (phalcon_isset_property_zval(this_ptr, index TSRMLS_CC)) {
		RETURN_TRUE;
	}
	RETURN_FALSE;
}

/**
 * Gets a record in a specific position of the row
 *
 * @param int $index
 * @return string|\Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetGet){

	zval *index, *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &index);
	
	if (phalcon_isset_property_zval(this_ptr, index TSRMLS_CC)) {
		PHALCON_OBS_VAR(value);
		phalcon_read_property_zval(&value, this_ptr, index, PH_NOISY_CC);
		RETURN_CCTOR(value);
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The index does not exist in the row");
	return;
}

/**
 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int $index
 * @param Phalcon\Mvc\ModelInterface $value
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetSet){

	zval *index, *value;

	phalcon_fetch_params(0, 2, 0, &index, &value);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Row is an immutable ArrayAccess object");
	return;
}

/**
 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int $offset
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetUnset){

	zval *offset;

	phalcon_fetch_params(0, 1, 0, &offset);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Row is an immutable ArrayAccess object");
	return;
}

