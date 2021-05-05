
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
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
 * Phalcon\Mvc\Model\Relation
 *
 * This class represents a relationship between two models
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Relation)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Relation, phalcon, mvc_model_relation, phalcon_mvc_model_relation_method_entry, 0);

	/**
	 * @var array|string
	 */
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("fields"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|string
	 */
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("intermediateFields"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("intermediateModel"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|string
	 */
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("intermediateReferencedFields"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("options"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|string
	 */
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("referencedFields"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("referencedModel"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("type"), ZEND_ACC_PROTECTED);
	phalcon_mvc_model_relation_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_Relation;
	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("ACTION_CASCADE"), 2);

	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("ACTION_RESTRICT"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("BELONGS_TO"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("HAS_MANY"), 2);

	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("HAS_MANY_THROUGH"), 4);

	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("HAS_ONE"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("HAS_ONE_THROUGH"), 3);

	zephir_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("NO_ACTION"), 0);

	zend_class_implements(phalcon_mvc_model_relation_ce, 1, phalcon_mvc_model_relationinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Relation constructor
 *
 * @param int type
 * @param string referencedModel
 * @param array|string fields
 * @param array|string referencedFields
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options;
	zval referencedModel;
	zval *type_param = NULL, *referencedModel_param = NULL, *fields, fields_sub, *referencedFields, referencedFields_sub, *options_param = NULL, _0;
	zend_long type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 5)
		Z_PARAM_LONG(type)
		Z_PARAM_STR(referencedModel)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &type_param, &referencedModel_param, &fields, &referencedFields, &options_param);
	type = zephir_get_intval(type_param);
	if (UNEXPECTED(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
		zephir_get_strval(&referencedModel, referencedModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referencedModel);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, type);
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("referencedModel"), &referencedModel);
	zephir_update_property_zval(this_ptr, ZEND_STRL("fields"), fields);
	zephir_update_property_zval(this_ptr, ZEND_STRL("referencedFields"), referencedFields);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the fields
 *
 * @return array|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getFields)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "fields");
}

/**
 * Returns the foreign key configuration
 *
 * @return array|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getForeignKey)
{
	zval options, foreignKey, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	if (zephir_array_isset_string_fetch(&foreignKey, &options, SL("foreignKey"), 1)) {
		if (zephir_is_true(&foreignKey)) {
			RETURN_CTOR(&foreignKey);
		}
	}
	RETURN_MM_BOOL(0);
}

/**
 * Gets the intermediate fields for has-*-through relations
 *
 * @return array|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateFields)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "intermediateFields");
}

/**
 * Gets the intermediate model for has-*-through relations
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateModel)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "intermediateModel");
}

/**
 * Gets the intermediate referenced fields for has-*-through relations
 *
 * @return array|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "intermediateReferencedFields");
}

/**
 * Returns an option by the specified name
 * If the option doesn't exist null is returned
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, option, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&option, &_0, &name, 1))) {
		RETURN_MM_NULL();
	}
	RETURN_CTOR(&option);
}

/**
 * Returns the options
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getOptions)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "options");
}

/**
 * Returns parameters that must be always used when the related records are obtained
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getParams)
{
	zval options, params, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	ZEPHIR_OBS_VAR(&params);
	if (zephir_array_isset_string_fetch(&params, &options, SL("params"), 0)) {
		if (zephir_is_true(&params)) {
			if (zephir_is_callable(&params)) {
				ZEPHIR_CALL_USER_FUNC(return_value, &params);
				zephir_check_call_status();
				RETURN_MM();
			}
			RETURN_CCTOR(&params);
		}
	}
	RETURN_MM_BOOL(0);
}

/**
 * Returns the relation type
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getType)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "type");
}

/**
 * Returns the referenced fields
 *
 * @return array|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedFields)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "referencedFields");
}

/**
 * Returns the referenced model
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedModel)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "referencedModel");
}

/**
 * Check whether the relation act as a foreign key
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isForeignKey)
{
	zval foreignKey, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&foreignKey, &_0, SL("foreignKey"), 1))) {
		RETURN_BOOL(0);
	}
	RETURN_BOOL(zephir_get_boolval(&foreignKey));
}

/**
 * Check whether the relation is a 'many-to-many' relation or not
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isThrough)
{
	zend_bool _1;
	zval type, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&type, &_0);
	_1 = ZEPHIR_IS_LONG(&type, 3);
	if (!(_1)) {
		_1 = ZEPHIR_IS_LONG(&type, 4);
	}
	RETURN_MM_BOOL(_1);
}

/**
 * Check if records returned by getting belongs-to/has-many are implicitly cached during the current request
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, isReusable)
{
	zval options, reusable, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&reusable);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	if (!(zephir_array_isset_string_fetch(&reusable, &options, SL("reusable"), 1))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CTOR(&reusable);
}

/**
 * Sets the intermediate model data for has-*-through relations
 *
 * @param array|string intermediateFields
 * @param string       intermediateModel
 * @param array|string intermediateReferencedFields
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, setIntermediateRelation)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval intermediateModel;
	zval *intermediateFields, intermediateFields_sub, *intermediateModel_param = NULL, *intermediateReferencedFields, intermediateReferencedFields_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediateFields_sub);
	ZVAL_UNDEF(&intermediateReferencedFields_sub);
	ZVAL_UNDEF(&intermediateModel);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(intermediateFields)
		Z_PARAM_STR(intermediateModel)
		Z_PARAM_ZVAL(intermediateReferencedFields)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediateFields, &intermediateModel_param, &intermediateReferencedFields);
	if (UNEXPECTED(Z_TYPE_P(intermediateModel_param) != IS_STRING && Z_TYPE_P(intermediateModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'intermediateModel' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(intermediateModel_param) == IS_STRING)) {
		zephir_get_strval(&intermediateModel, intermediateModel_param);
	} else {
		ZEPHIR_INIT_VAR(&intermediateModel);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("intermediateFields"), intermediateFields);
	zephir_update_property_zval(this_ptr, ZEND_STRL("intermediateModel"), &intermediateModel);
	zephir_update_property_zval(this_ptr, ZEND_STRL("intermediateReferencedFields"), intermediateReferencedFields);
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Phalcon_Mvc_Model_Relation(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

