
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

#include "mvc/model/relation.h"
#include "mvc/model/relationinterface.h"

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
zend_class_entry *phalcon_mvc_model_relation_ce;

PHP_METHOD(Phalcon_Mvc_Model_Relation, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Relation, setIntermediateRelation);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getType);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedModel);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getFields);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedFields);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getOptions);
PHP_METHOD(Phalcon_Mvc_Model_Relation, isForeignKey);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getForeignKey);
PHP_METHOD(Phalcon_Mvc_Model_Relation, isThrough);
PHP_METHOD(Phalcon_Mvc_Model_Relation, isReusable);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateFields);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateModel);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relation___construct, 0, 0, 4)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_relation_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Relation, __construct, arginfo_phalcon_mvc_model_relation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Relation, setIntermediateRelation, arginfo_phalcon_mvc_model_relationinterface_setintermediaterelation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getReferencedModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getReferencedFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, isForeignKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getForeignKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, isThrough, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, isReusable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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

	phalcon_fetch_params(0, 4, 1, &type, &referenced_model, &fields, &referenced_fields, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_referencedModel"), referenced_model TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_fields"), fields TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_referencedFields"), referenced_fields TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
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
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
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

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);

	if (phalcon_array_isset_string_fetch(&foreign_key, options, SS("foreignKey"))) {
		if (zend_is_true(foreign_key)) {
			RETURN_ZVAL(foreign_key, 1, 0);
		}
	}
	
	RETURN_FALSE;
}

/**
 * Check whether the relation is a 'many-to-many' relation or not
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isThrough){

	zval *type;

	type = phalcon_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY TSRMLS_CC);
	if (PHALCON_IS_LONG(type, 3) || PHALCON_IS_LONG(type, 4)) {
		RETURN_TRUE;
	}
	
	RETURN_FALSE;
}

/**
 * Check if records returned by getting belongs-to/has-many are implicitly cached during the current request
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isReusable){

	zval *options, *reusable;

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);

	if (phalcon_array_isset_string_fetch(&reusable, options, SS("reusable"))) {
		RETURN_ZVAL(reusable, 1, 0);
	}
	
	RETURN_FALSE;
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
