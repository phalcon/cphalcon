
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/collection/document.h"
#include "mvc/collection/exception.h"

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
zend_class_entry *phalcon_mvc_collection_document_ce;

PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetExists);
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetGet);
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetSet);
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetUnset);
PHP_METHOD(Phalcon_Mvc_Collection_Document, readAttribute);
PHP_METHOD(Phalcon_Mvc_Collection_Document, writeAttribute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_collection_document_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Collection_Document, offsetExists, arginfo_phalcon_mvc_collection_document_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, offsetGet, arginfo_phalcon_mvc_collection_document_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, offsetSet, arginfo_phalcon_mvc_collection_document_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, offsetUnset, arginfo_phalcon_mvc_collection_document_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, readAttribute, arginfo_phalcon_mvc_collection_document_readattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, writeAttribute, arginfo_phalcon_mvc_collection_document_writeattribute, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Collection\Document initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_Document){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Collection, Document, mvc_collection_document, phalcon_mvc_collection_document_method_entry, 0);

	zend_class_implements(phalcon_mvc_collection_document_ce TSRMLS_CC, 1, zend_ce_arrayaccess);

	return SUCCESS;
}

/**
 * Checks whether an offset exists in the document
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
		phalcon_read_property_zval(&value, this_ptr, index, PH_NOISY TSRMLS_CC);
		RETURN_CTOR(value);
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
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_collection_exception_ce, "The index does not exist in the row");
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
		phalcon_read_property_zval(&attribute_value, this_ptr, attribute, PH_NOISY TSRMLS_CC);
		RETURN_CTOR(attribute_value);
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
