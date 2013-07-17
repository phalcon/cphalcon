
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
#include "kernel/array.h"
#include "kernel/operators.h"

/**
 * Phalcon\Mvc\Model\Relation
 *
 * This class represents a relationship between two models
 */


/**
 * Phalcon\Mvc\Model\Relation initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Relation){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Relation, mvc_model_relation, phalcon_mvc_model_relation_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("_referencedModel"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("_fields"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("_referencedFields"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("_intermediateModel"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("_intermediateFields"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("_intermediateReferencedFields"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("BELONGS_TO"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("HAS_ONE"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("HAS_MANY"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("HAS_ONE_THROUGH"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("HAS_MANY_THROUGH"), 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("NO_ACTION"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("ACTION_RESTRICT"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("ACTION_CASCADE"), 2 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_relation_ce TSRMLS_CC, 1, phalcon_mvc_model_relationinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Relation constructor
 *
 * @param int $type
 * @param string $referencedModel
 * @param string|array $fields
 * @param string|array $referencedFields
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, __construct){

	zval *type, *referenced_model, *fields, *referenced_fields;
	zval *options = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 1, &type, &referenced_model, &fields, &referenced_fields, &options);
	
	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_referencedModel"), referenced_model TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_fields"), fields TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_referencedFields"), referenced_fields TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the intermediate model data for has-*-through relations
 *
 * @param string|array $intermediateFields
 * @param string $intermediateModel
 * @param string $intermediateReferencedFields
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, setIntermediateRelation){

	zval *intermediate_fields, *intermediate_model;
	zval *intermediate_referenced_fields;

	phalcon_fetch_params(0, 3, 0, &intermediate_fields, &intermediate_model, &intermediate_referenced_fields);
	
	phalcon_update_property_this(this_ptr, SL("_intermediateFields"), intermediate_fields TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_intermediateModel"), intermediate_model TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_intermediateReferencedFields"), intermediate_referenced_fields TSRMLS_CC);
	
}

/**
 * Returns the relation type
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

/**
 * Returns the referenced model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedModel){


	RETURN_MEMBER(this_ptr, "_referencedModel");
}

/**
 * Returns the fields
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getFields){


	RETURN_MEMBER(this_ptr, "_fields");
}

/**
 * Returns the referenced fields
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedFields){


	RETURN_MEMBER(this_ptr, "_referencedFields");
}

/**
 * Returns the options
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getOptions){


	RETURN_MEMBER(this_ptr, "_options");
}

/**
 * Check whether the relation act as a foreign key
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isForeignKey){

	zval *options;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		if (phalcon_array_isset_string(options, SS("foreignKey"))) {
			RETURN_MM_TRUE;
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Returns the foreign key configuration
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getForeignKey){

	zval *options, *foreign_key;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		if (phalcon_array_isset_string(options, SS("foreignKey"))) {
	
			PHALCON_OBS_VAR(foreign_key);
			phalcon_array_fetch_string(&foreign_key, options, SL("foreignKey"), PH_NOISY);
			if (zend_is_true(foreign_key)) {
				RETURN_CCTOR(foreign_key);
			}
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Check whether the relation is a 'many-to-many' relation or not
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isThrough){

	zval *type;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(type);
	phalcon_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	if (PHALCON_IS_LONG(type, 3)) {
		RETURN_MM_TRUE;
	} else {
		if (PHALCON_IS_LONG(type, 4)) {
			RETURN_MM_TRUE;
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Check if records returned by getting belongs-to/has-many are implicitly cached during the current request
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isReusable){

	zval *options, *reusable;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		if (phalcon_array_isset_string(options, SS("reusable"))) {
			PHALCON_OBS_VAR(reusable);
			phalcon_array_fetch_string(&reusable, options, SL("reusable"), PH_NOISY);
			RETURN_CCTOR(reusable);
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Gets the intermediate fields for has-*-through relations
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateFields){


	RETURN_MEMBER(this_ptr, "_intermediateFields");
}

/**
 * Gets the intermediate model for has-*-through relations
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateModel){


	RETURN_MEMBER(this_ptr, "_intermediateModel");
}

/**
 * Gets the intermediate referenced fields for has-*-through relations
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields){


	RETURN_MEMBER(this_ptr, "_intermediateReferencedFields");
}

