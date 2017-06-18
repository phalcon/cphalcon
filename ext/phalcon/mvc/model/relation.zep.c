
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"


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

	if (UNEXPECTED(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
		zephir_get_strval(referencedModel, referencedModel_param);
	} else {
		ZEPHIR_INIT_VAR(referencedModel);
		ZVAL_EMPTY_STRING(referencedModel);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(getThis(), SL("_type"), type TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_referencedModel"), referencedModel TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_fields"), fields TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_referencedFields"), referencedFields TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_options"), options TSRMLS_CC);
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

	if (UNEXPECTED(Z_TYPE_P(intermediateModel_param) != IS_STRING && Z_TYPE_P(intermediateModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'intermediateModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(intermediateModel_param) == IS_STRING)) {
		zephir_get_strval(intermediateModel, intermediateModel_param);
	} else {
		ZEPHIR_INIT_VAR(intermediateModel);
		ZVAL_EMPTY_STRING(intermediateModel);
	}


	zephir_update_property_this(getThis(), SL("_intermediateFields"), intermediateFields TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_intermediateModel"), intermediateModel TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_intermediateReferencedFields"), intermediateReferencedFields TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the relation type
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getType) {

	

	RETURN_MEMBER(getThis(), "_type");

}

/**
 * Returns the referenced model
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedModel) {

	

	RETURN_MEMBER(getThis(), "_referencedModel");

}

/**
 * Returns the fields
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getFields) {

	

	RETURN_MEMBER(getThis(), "_fields");

}

/**
 * Returns the referenced fields
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedFields) {

	

	RETURN_MEMBER(getThis(), "_referencedFields");

}

/**
 * Returns the options
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getOptions) {

	

	RETURN_MEMBER(getThis(), "_options");

}

/**
 * Returns an option by the specified name
 * If the option doesn't exist null is returned	 
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getOption) {

	zval *name_param = NULL, *option = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&option, _0, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(option);
	}
	RETURN_MM_NULL();

}

/**
 * Check whether the relation act as a foreign key
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isForeignKey) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset_string(_0, SS("foreignKey")));

}

/**
 * Returns the foreign key configuration
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getForeignKey) {

	zval *options = NULL, *foreignKey = NULL;


	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&foreignKey, options, SS("foreignKey"), 1 TSRMLS_CC)) {
			if (zephir_is_true(foreignKey)) {
				RETURN_CTORW(foreignKey);
			}
		}
	}
	RETURN_BOOL(0);

}

/**
 * Returns parameters that must be always used when the related records are obtained
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getParams) {

	zval *options = NULL, *params = NULL;


	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&params, options, SS("params"), 1 TSRMLS_CC)) {
			if (zephir_is_true(params)) {
				RETURN_CTORW(params);
			}
		}
	}
	RETURN_BOOL(0);

}

/**
 * Check whether the relation is a 'many-to-many' relation or not
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isThrough) {

	zend_bool _0;
	zval *type = NULL;


	type = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	_0 = ZEPHIR_IS_LONG(type, 3);
	if (!(_0)) {
		_0 = ZEPHIR_IS_LONG(type, 4);
	}
	RETURN_BOOL(_0);

}

/**
 * Check if records returned by getting belongs-to/has-many are implicitly cached during the current request
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isReusable) {

	zval *options = NULL, *reusable = NULL;


	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) {
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

	

	RETURN_MEMBER(getThis(), "_intermediateFields");

}

/**
 * Gets the intermediate model for has-*-through relations
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateModel) {

	

	RETURN_MEMBER(getThis(), "_intermediateModel");

}

/**
 * Gets the intermediate referenced fields for has-*-through relations
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields) {

	

	RETURN_MEMBER(getThis(), "_intermediateReferencedFields");

}

