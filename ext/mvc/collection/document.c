
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
 * Phalcon\Mvc\Collection\Document
 *
 * This component allows Phalcon\Mvc\Collection to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 */


/**
 * Phalcon\Mvc\Collection\Document initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_Document){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Collection, Document, mvc_collection_document, phalcon_mvc_collection_document_method_entry, 0);

	zend_class_implements(phalcon_mvc_collection_document_ce TSRMLS_CC, 1, zend_ce_arrayaccess);

	return SUCCESS;
}

/**
 * Checks whether offset exists in the row
 *
 * @param int $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetExists){

	zval *index;

	phalcon_fetch_params(0, 1, 0, &index);
	
	if (phalcon_isset_property_zval(this_ptr, index TSRMLS_CC)) {
		RETURN_TRUE;
	}
	RETURN_FALSE;
}

/**
 * Returns the value of a field using the ArrayAccess interfase
 *
 * @param string $index
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetGet){

	zval *index, *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &index);
	
	if (phalcon_isset_property_zval(this_ptr, index TSRMLS_CC)) {
		PHALCON_OBS_VAR(value);
		phalcon_read_property_zval(&value, this_ptr, index, PH_NOISY_CC);
		RETURN_CCTOR(value);
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "The index does not exist in the row");
	return;
}

/**
 * Change a value using the ArrayAccess interface
 *
 * @param string $index
 * @param mixed $value
 * @param Phalcon\Mvc\ModelInterface $value
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetSet){

	zval *index, *value;

	phalcon_fetch_params(0, 2, 0, &index, &value);
	
	phalcon_update_property_zval_zval(this_ptr, index, value TSRMLS_CC);
	
}

/**
 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param string $offset
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetUnset){

	zval *offset;

	phalcon_fetch_params(0, 1, 0, &offset);
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "The index does not exist in the row");
	return;
}

/**
 * Reads an attribute value by its name
 *
 *<code>
 *	echo $robot->readAttribute('name');
 *</code>
 *
 * @param string $attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, readAttribute){

	zval *attribute, *attribute_value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &attribute);
	
	if (phalcon_isset_property_zval(this_ptr, attribute TSRMLS_CC)) {
		PHALCON_OBS_VAR(attribute_value);
		phalcon_read_property_zval(&attribute_value, this_ptr, attribute, PH_NOISY_CC);
		RETURN_CCTOR(attribute_value);
	}
	RETURN_MM_NULL();
}

/**
 * Writes an attribute value by its name
 *
 *<code>
 *	$robot->writeAttribute('name', 'Rosey');
 *</code>
 *
 * @param string $attribute
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, writeAttribute){

	zval *attribute, *value;

	phalcon_fetch_params(0, 2, 0, &attribute, &value);
	
	phalcon_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
	
}

