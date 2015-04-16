
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Mvc\Collection\Document
 *
 * This component allows Phalcon\Mvc\Collection to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_Document) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Collection, Document, phalcon, mvc_collection_document, phalcon_mvc_collection_document_method_entry, 0);

	zend_class_implements(phalcon_mvc_collection_document_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Checks whether an offset exists in the document
 *
 * @param int index
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetExists) {

	zval *index_param = NULL;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	RETURN_MM_BOOL(zephir_isset_property_zval(this_ptr, index TSRMLS_CC));

}

/**
 * Returns the value of a field using the ArrayAccess interfase
 *
 * @param string index
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetGet) {

	zval *index, *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	ZEPHIR_OBS_VAR(value);
	if (zephir_fetch_property_zval(&value, this_ptr, index, PH_SILENT_CC)) {
		RETURN_CCTOR(value);
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The index does not exist in the row", "phalcon/mvc/collection/document.zep", 55);
	return;

}

/**
 * Change a value using the ArrayAccess interface
 *
 * @param string index
 * @param mixed value
 * @param Phalcon\Mvc\ModelInterface value
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetSet) {

	zval *index, *value;

	zephir_fetch_params(0, 2, 0, &index, &value);



	zephir_update_property_zval_zval(this_ptr, index, value TSRMLS_CC);

}

/**
 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param string offset
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetUnset) {

	zval *offset;

	zephir_fetch_params(0, 1, 0, &offset);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_collection_exception_ce, "The index does not exist in the row", "phalcon/mvc/collection/document.zep", 77);
	return;

}

/**
 * Reads an attribute value by its name
 *
 *<code>
 *        echo robot->readAttribute('name');
 *</code>
 *
 * @param string attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, readAttribute) {

	zval *attribute, *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute);



	ZEPHIR_OBS_VAR(value);
	if (zephir_fetch_property_zval(&value, this_ptr, attribute, PH_SILENT_CC)) {
		RETURN_CTOR(value);
	}
	RETURN_MM_NULL();

}

/**
 * Writes an attribute value by its name
 *
 *<code>
 *        robot->writeAttribute('name', 'Rosey');
 *</code>
 *
 * @param string attribute
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, writeAttribute) {

	zval *attribute_param = NULL, *value;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);

	if (unlikely(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(attribute);
		ZVAL_EMPTY_STRING(attribute);
	}


	zephir_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

