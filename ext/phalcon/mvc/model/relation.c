
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"


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
 * Phalcon\Mvc\Model\Relation
 *
 * This class represents a relationship between two models
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Relation) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Relation, phalcon, mvc_model_relation, phalcon_mvc_model_relation_method_entry, 0);

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
 * @param int type
 * @param string referencedModel
 * @param string|array fields
 * @param string|array referencedFields
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, __construct) {

	zval *referencedModel = NULL;
	zval *type, *referencedModel_param = NULL, *fields, *referencedFields, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &type, &referencedModel_param, &fields, &referencedFields, &options);

		if (Z_TYPE_P(referencedModel_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		referencedModel = referencedModel_param;

	if (!options || Z_TYPE_P(options) == IS_NULL) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_referencedModel"), referencedModel TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_fields"), fields TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_referencedFields"), referencedFields TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the intermediate model data for has-*-through relations
 *
 * @param string|array intermediateFields
 * @param string intermediateModel
 * @param string intermediateReferencedFields
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, setIntermediateRelation) {

	zval *intermediateModel = NULL;
	zval *intermediateFields, *intermediateModel_param = NULL, *intermediateReferencedFields;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediateFields, &intermediateModel_param, &intermediateReferencedFields);

		if (Z_TYPE_P(intermediateModel_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'intermediateModel' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		intermediateModel = intermediateModel_param;



	zephir_update_property_this(this_ptr, SL("_intermediateFields"), intermediateFields TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_intermediateModel"), intermediateModel TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_intermediateReferencedFields"), intermediateReferencedFields TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the relation type
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Returns the referenced model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedModel) {


	RETURN_MEMBER(this_ptr, "_referencedModel");

}

/**
 * Returns the fields
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getFields) {


	RETURN_MEMBER(this_ptr, "_fields");

}

/**
 * Returns the referenced fields
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedFields) {


	RETURN_MEMBER(this_ptr, "_referencedFields");

}

/**
 * Returns the options
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getOptions) {


	RETURN_MEMBER(this_ptr, "_options");

}

/**
 * Check whether the relation act as a foreign key
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isForeignKey) {

	zval *options;


	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if ((Z_TYPE_P(options) == IS_ARRAY)) {
		if (zephir_array_isset_string(options, SS("foreignKey"))) {
			RETURN_BOOL(1);
		}
	}
	RETURN_BOOL(0);

}

/**
 * Returns the foreign key configuration
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getForeignKey) {

	zval *options, *foreignKey;


	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if ((Z_TYPE_P(options) == IS_ARRAY)) {
		if (zephir_array_isset_string_fetch(&foreignKey, options, SS("foreignKey"), 1 TSRMLS_CC)) {
			if (zephir_is_true(foreignKey)) {
				RETURN_CTORW(foreignKey);
			}
		}
	}
	RETURN_BOOL(0);

}

/**
 * Check whether the relation is a 'many-to-many' relation or not
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isThrough) {

	zval *type;


	type = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	RETURN_BOOL((ZEPHIR_IS_LONG(type, 3) || ZEPHIR_IS_LONG(type, 4)));

}

/**
 * Check if records returned by getting belongs-to/has-many are implicitly cached during the current request
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isReusable) {

	zval *options, *reusable;


	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if ((Z_TYPE_P(options) == IS_ARRAY)) {
		if (zephir_array_isset_string_fetch(&reusable, options, SS("reusable"), 1 TSRMLS_CC)) {
			RETURN_CTORW(reusable);
		}
	}
	RETURN_BOOL(0);

}

/**
 * Gets the intermediate fields for has-*-through relations
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateFields) {


	RETURN_MEMBER(this_ptr, "_intermediateFields");

}

/**
 * Gets the intermediate model for has-*-through relations
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateModel) {


	RETURN_MEMBER(this_ptr, "_intermediateModel");

}

/**
 * Gets the intermediate referenced fields for has-*-through relations
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields) {


	RETURN_MEMBER(this_ptr, "_intermediateReferencedFields");

}

