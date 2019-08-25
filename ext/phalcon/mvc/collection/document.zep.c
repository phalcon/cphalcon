
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Collection\Document
 *
 * This component allows Phalcon\Mvc\Collection to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_Document) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Collection, Document, phalcon, mvc_collection_document, phalcon_mvc_collection_document_method_entry, 0);

	zend_class_implements(phalcon_mvc_collection_document_ce TSRMLS_CC, 1, phalcon_mvc_entityinterface_ce);
	zend_class_implements(phalcon_mvc_collection_document_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Returns the value of a field using the ArrayAccess interfase
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetGet) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *index, index_sub, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	ZEPHIR_OBS_VAR(&value);
	if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, index, PH_SILENT_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The index does not exist in the row", "phalcon/Mvc/Collection/Document.zep", 33);
		return;
	}
	RETURN_CCTOR(&value);

}

/**
 * Checks whether an offset exists in the document
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetExists) {

	zval *index, index_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &index);



	RETURN_BOOL(zephir_isset_property_zval(this_ptr, index TSRMLS_CC));

}

/**
 * Change a value using the ArrayAccess interface
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetSet) {

	zval *index, index_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &index, &value);



	zephir_update_property_zval_zval(this_ptr, index, value TSRMLS_CC);

}

/**
 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetUnset) {

	zval *index, index_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &index);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_collection_exception_ce, "The index does not exist in the row", "phalcon/Mvc/Collection/Document.zep", 60);
	return;

}

/**
 * Reads an attribute value by its name
 *
 *```php
 *  echo $robot->readAttribute("name");
 *```
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, readAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attribute_param = NULL, value;
	zval attribute;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute_param);

	if (UNEXPECTED(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(&attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(&attribute);
		ZVAL_EMPTY_STRING(&attribute);
	}


	ZEPHIR_OBS_VAR(&value);
	if (!(zephir_fetch_property_zval(&value, this_ptr, &attribute, PH_SILENT_CC))) {
		RETURN_MM_NULL();
	}
	RETURN_CTOR(&value);

}

/**
 * Returns the instance as an array representation
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, toArray) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 214, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Writes an attribute value by its name
 *
 *```php
 *  $robot->writeAttribute("name", "Rosey");
 *```
 */
PHP_METHOD(Phalcon_Mvc_Collection_Document, writeAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attribute_param = NULL, *value, value_sub;
	zval attribute;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);

	if (UNEXPECTED(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(&attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(&attribute);
		ZVAL_EMPTY_STRING(&attribute);
	}


	zephir_update_property_zval_zval(this_ptr, &attribute, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

