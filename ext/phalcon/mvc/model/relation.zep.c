
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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

	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("BELONGS_TO"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("HAS_ONE"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("HAS_MANY"), 2);

	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("HAS_ONE_THROUGH"), 3);

	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("HAS_MANY_THROUGH"), 4);

	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("NO_ACTION"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("ACTION_RESTRICT"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("ACTION_CASCADE"), 2);

	zend_class_implements(phalcon_mvc_model_relation_ce TSRMLS_CC, 1, phalcon_mvc_model_relationinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Relation constructor
 *
 * @param int type
 * @param string|array fields
 * @param string|array referencedFields
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, __construct) {

	zval referencedModel;
	zval *type, type_sub, *referencedModel_param = NULL, *fields, fields_sub, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&referencedModel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &type, &referencedModel_param, &fields, &referencedFields, &options);

	if (UNEXPECTED(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
		zephir_get_strval(&referencedModel, referencedModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referencedModel);
		ZVAL_EMPTY_STRING(&referencedModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("_type"), type);
	zephir_update_property_zval(this_ptr, SL("_referencedModel"), &referencedModel);
	zephir_update_property_zval(this_ptr, SL("_fields"), fields);
	zephir_update_property_zval(this_ptr, SL("_referencedFields"), referencedFields);
	zephir_update_property_zval(this_ptr, SL("_options"), options);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the intermediate model data for has-*-through relations
 *
 * @param string|array intermediateFields
 * @param string intermediateReferencedFields
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, setIntermediateRelation) {

	zval intermediateModel;
	zval *intermediateFields, intermediateFields_sub, *intermediateModel_param = NULL, *intermediateReferencedFields, intermediateReferencedFields_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediateFields_sub);
	ZVAL_UNDEF(&intermediateReferencedFields_sub);
	ZVAL_UNDEF(&intermediateModel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediateFields, &intermediateModel_param, &intermediateReferencedFields);

	if (UNEXPECTED(Z_TYPE_P(intermediateModel_param) != IS_STRING && Z_TYPE_P(intermediateModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'intermediateModel' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(intermediateModel_param) == IS_STRING)) {
		zephir_get_strval(&intermediateModel, intermediateModel_param);
	} else {
		ZEPHIR_INIT_VAR(&intermediateModel);
		ZVAL_EMPTY_STRING(&intermediateModel);
	}


	zephir_update_property_zval(this_ptr, SL("_intermediateFields"), intermediateFields);
	zephir_update_property_zval(this_ptr, SL("_intermediateModel"), &intermediateModel);
	zephir_update_property_zval(this_ptr, SL("_intermediateReferencedFields"), intermediateReferencedFields);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the relation type
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_type");

}

/**
 * Returns the referenced model
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedModel) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_referencedModel");

}

/**
 * Returns the fields
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getFields) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_fields");

}

/**
 * Returns the referenced fields
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedFields) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_referencedFields");

}

/**
 * Returns the options
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_options");

}

/**
 * Returns an option by the specified name
 * If the option doesn't exist null is returned	 
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getOption) {

	zval *name_param = NULL, option, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&option, &_0, &name, 1 TSRMLS_CC)) {
		RETURN_CTOR(&option);
	}
	RETURN_MM_NULL();

}

/**
 * Check whether the relation act as a foreign key
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isForeignKey) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_string(&_0, SL("foreignKey")));

}

/**
 * Returns the foreign key configuration
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getForeignKey) {

	zval options, foreignKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&foreignKey);


	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&foreignKey, &options, SL("foreignKey"), 1)) {
			if (zephir_is_true(&foreignKey)) {
				RETURN_CTORW(&foreignKey);
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

	zval options, params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&params);


	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&params, &options, SL("params"), 1)) {
			if (zephir_is_true(&params)) {
				RETURN_CTORW(&params);
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
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);


	zephir_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
	_0 = ZEPHIR_IS_LONG(&type, 3);
	if (!(_0)) {
		_0 = ZEPHIR_IS_LONG(&type, 4);
	}
	RETURN_BOOL(_0);

}

/**
 * Check if records returned by getting belongs-to/has-many are implicitly cached during the current request
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isReusable) {

	zval options, reusable;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&reusable);


	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&reusable, &options, SL("reusable"), 1)) {
			RETURN_CTORW(&reusable);
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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_intermediateFields");

}

/**
 * Gets the intermediate model for has-*-through relations
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateModel) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_intermediateModel");

}

/**
 * Gets the intermediate referenced fields for has-*-through relations
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_intermediateReferencedFields");

}

