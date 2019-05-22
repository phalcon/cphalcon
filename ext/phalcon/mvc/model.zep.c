
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/iterator.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model
 *
 * Phalcon\Mvc\Model connects business objects and database tables to create a
 * persistable domain model where logic and data are presented in one wrapping.
 * It‘s an implementation of the object-relational mapping (ORM).
 *
 * A model represents the information (data) of the application and the rules to
 * manipulate that data. Models are primarily used for managing the rules of
 * interaction with a corresponding database table. In most cases, each table in
 * your database will correspond to one model in your application. The bulk of
 * your application's business logic will be concentrated in the models.
 *
 * Phalcon\Mvc\Model is the first ORM written in Zephir/C languages for PHP,
 * giving to developers high performance when interacting with databases while
 * is also easy to use.
 *
 * <code>
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * if ($robot->save() === false) {
 *     echo "Umh, We can store robots: ";
 *
 *     $messages = $robot->getMessages();
 *
 *     foreach ($messages as $message) {
 *         echo $message;
 *     }
 * } else {
 *     echo "Great, a new robot was saved successfully!";
 * }
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc, Model, phalcon, mvc_model, phalcon_mvc_model_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_model_ce, SL("dirtyState"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("dirtyRelated"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("errorMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("modelsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("modelsMetaData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("related"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_model_ce, SL("operationMade"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("oldSnapshot"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("skipped"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("snapshot"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("transaction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("uniqueKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("uniqueParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("uniqueTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_model_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model;
	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_DETACHED"), 2);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_PERSISTENT"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_TRANSIENT"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_CREATE"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_DELETE"), 3);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_NONE"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_UPDATE"), 2);

	zephir_declare_class_constant_string(phalcon_mvc_model_ce, SL("TRANSACTION_INDEX"), "transaction");

	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_mvc_entityinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_mvc_modelinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_mvc_model_resultinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, zend_ce_serializable);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("jsonserializable")));
	return SUCCESS;

}

PHP_METHOD(Phalcon_Mvc_Model, getTransaction) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "transaction");

}

/**
 * Phalcon\Mvc\Model constructor
 */
PHP_METHOD(Phalcon_Mvc_Model, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL;
	zval *data = NULL, data_sub, *container = NULL, container_sub, *modelsManager = NULL, modelsManager_sub, __$null, _1$$4, _2$$4, _4$$4, _5$$5, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&modelsManager_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &data, &container, &modelsManager);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!container) {
		container = &container_sub;
		ZEPHIR_CPY_WRT(container, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(container);
	}
	if (!modelsManager) {
		modelsManager = &modelsManager_sub;
		ZEPHIR_CPY_WRT(modelsManager, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(modelsManager);
	}


	if (Z_TYPE_P(container) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(container, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
	}
	if (UNEXPECTED(Z_TYPE_P(container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "the services related to the ODM");
		ZEPHIR_CALL_CE_STATIC(&_2$$4, phalcon_mvc_model_exception_ce, "containerservicenotfound", &_3, 0, &_4$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 1, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Model.zep", 139 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("container"), container);
	if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_STRING(&_6$$5, "modelsManager");
		ZEPHIR_CALL_METHOD(&_5$$5, container, "getshared", NULL, 0, &_6$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(modelsManager, &_5$$5);
		if (UNEXPECTED(Z_TYPE_P(modelsManager) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/Mvc/Model.zep", 153);
			return;
		}
	}
	zephir_update_property_zval(this_ptr, SL("modelsManager"), modelsManager);
	ZEPHIR_CALL_METHOD(NULL, modelsManager, "initialize", NULL, 0, this_ptr);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, SL("onconstruct") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0, data);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, data);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles method calls when a method is not implemented
 *
 * @return    mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval arguments;
	zval *method_param = NULL, *arguments_param = NULL, modelName, status, records, _1, _2, _3;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&arguments);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &arguments_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&arguments, arguments_param);


	ZEPHIR_CALL_SELF(&records, "_invokefinder", &_0, 417, &method, &arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(&records) != IS_NULL) {
		RETURN_CCTOR(&records);
	}
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", NULL, 0, &modelName, &method, &arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(&records) != IS_NULL) {
		RETURN_CCTOR(&records);
	}
	zephir_read_property(&_1, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&status, &_1, "missingmethod", NULL, 0, this_ptr, &method, &arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(&status) != IS_NULL) {
		RETURN_CCTOR(&status);
	}
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVSVS(&_3, "The method '", &method, "' doesn't exist on model '", &modelName, "'");
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 1, &_3);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_2, "phalcon/Mvc/Model.zep", 221 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Handles method calls when a static method is not implemented
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, __callStatic) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval arguments;
	zval *method_param = NULL, *arguments_param = NULL;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&arguments);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &arguments_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&arguments, arguments_param);


	ZEPHIR_RETURN_CALL_SELF("_invokefinder", &_0, 417, &method, &arguments);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Magic method to get related records using the relation alias as a
 * property
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, modelName, manager, lowerProperty, relation, _0, _4, _5, _6, _1$$3, _2$$4, _3$$4;
	zval property, method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&lowerProperty);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(&property, property_param);
	} else {
		ZEPHIR_INIT_VAR(&property);
		ZVAL_EMPTY_STRING(&property);
	}


	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&lowerProperty);
	zephir_fast_strtolower(&lowerProperty, &property);
	ZEPHIR_CALL_METHOD(&_0, &manager, "getrelationbyalias", NULL, 0, &modelName, &lowerProperty);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_0);
	if (Z_TYPE_P(&relation) == IS_OBJECT) {
		zephir_read_property(&_1$$3, this_ptr, SL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_1$$3, &lowerProperty)) {
			zephir_read_property(&_2$$4, this_ptr, SL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_3$$4, &_2$$4, &lowerProperty, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 263 TSRMLS_CC);
			RETURN_CTOR(&_3$$4);
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelated", NULL, 0, &lowerProperty);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_camelize(&_4, &property, NULL  );
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SV(&_5, "get", &_4);
	zephir_get_strval(&method, &_5);
	if ((zephir_method_exists(this_ptr, &method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVSV(&_6, "Access to undefined property ", &modelName, "::", &property);
	ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 2, &_6);
	zephir_check_call_status();
	RETURN_MM_NULL();

}

/**
 * Magic method to check if a property is a valid relation
 */
PHP_METHOD(Phalcon_Mvc_Model, __isset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, modelName, manager, relation, _0;
	zval property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(&property, property_param);
	} else {
		ZEPHIR_INIT_VAR(&property);
		ZVAL_EMPTY_STRING(&property);
	}


	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_0, &manager, "getrelationbyalias", NULL, 0, &modelName, &property);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_0);
	RETURN_MM_BOOL(Z_TYPE_P(&relation) == IS_OBJECT);

}

/**
 * Magic method to assign values to the the model
 *
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_Model, __set) {

	zend_bool _0;
	zval related;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *value, value_sub, lowerProperty, modelName, manager, relation, referencedModel, item, dirtyState, _12, _13, _1$$3, _2$$4, _3$$4, _4$$6, _5$$7, _6$$8, _7$$9, _8$$9, *_9$$10, _10$$14, _11$$14, _14$$16, _15$$17;
	zval property, _16$$17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&lowerProperty);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&dirtyState);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_15$$17);
	ZVAL_UNDEF(&related);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &value);

	zephir_get_strval(&property, property_param);


	_0 = Z_TYPE_P(value) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(value, phalcon_mvc_modelinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&lowerProperty);
		zephir_fast_strtolower(&lowerProperty, &property);
		ZEPHIR_INIT_VAR(&modelName);
		zephir_get_class(&modelName, this_ptr, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, &manager, "getrelationbyalias", NULL, 0, &modelName, &lowerProperty);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_1$$3);
		if (Z_TYPE_P(&relation) == IS_OBJECT) {
			zephir_read_property(&_2$$4, this_ptr, SL("dirtyState"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&dirtyState, &_2$$4);
			ZEPHIR_CALL_METHOD(&_3$$4, value, "getdirtystate", NULL, 0);
			zephir_check_call_status();
			if (!ZEPHIR_IS_EQUAL(&_3$$4, &dirtyState)) {
				ZEPHIR_INIT_NVAR(&dirtyState);
				ZVAL_LONG(&dirtyState, 1);
			}
			zephir_read_property(&_2$$4, this_ptr, SL("related"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_2$$4, &lowerProperty, PH_SEPARATE);
			zephir_update_property_array(this_ptr, SL("dirtyRelated"), &lowerProperty, value TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("dirtyState"), &dirtyState);
			RETVAL_ZVAL(value, 1, 0);
			RETURN_MM();
		}
	} else if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&lowerProperty);
		zephir_fast_strtolower(&lowerProperty, &property);
		ZEPHIR_INIT_NVAR(&modelName);
		zephir_get_class(&modelName, this_ptr, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$6, &manager, "getrelationbyalias", NULL, 0, &modelName, &lowerProperty);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_4$$6);
		if (Z_TYPE_P(&relation) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_5$$7, &relation, "gettype", NULL, 0);
			zephir_check_call_status();
			do {
				if (ZEPHIR_IS_LONG(&_5$$7, 0) || ZEPHIR_IS_LONG(&_5$$7, 1)) {
					ZEPHIR_CALL_METHOD(&_6$$8, &relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", NULL, 0, &_6$$8);
					zephir_check_call_status();
					if (Z_TYPE_P(&referencedModel) == IS_OBJECT) {
						ZEPHIR_CALL_METHOD(NULL, &referencedModel, "assign", NULL, 0, value);
						zephir_check_call_status();
						zephir_read_property(&_7$$9, this_ptr, SL("related"), PH_NOISY_CC | PH_READONLY);
						zephir_array_unset(&_7$$9, &lowerProperty, PH_SEPARATE);
						zephir_update_property_array(this_ptr, SL("dirtyRelated"), &lowerProperty, &referencedModel TSRMLS_CC);
						ZEPHIR_INIT_ZVAL_NREF(_8$$9);
						ZVAL_LONG(&_8$$9, 1);
						zephir_update_property_zval(this_ptr, SL("dirtyState"), &_8$$9);
						RETVAL_ZVAL(value, 1, 0);
						RETURN_MM();
					}
					break;
				}
				if (ZEPHIR_IS_LONG(&_5$$7, 2) || ZEPHIR_IS_LONG(&_5$$7, 4)) {
					ZEPHIR_INIT_VAR(&related);
					array_init(&related);
					zephir_is_iterable(value, 0, "phalcon/Mvc/Model.zep", 402);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(value), _9$$10)
					{
						ZEPHIR_INIT_NVAR(&item);
						ZVAL_COPY(&item, _9$$10);
						if (Z_TYPE_P(&item) == IS_OBJECT) {
							if (zephir_instance_of_ev(&item, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
								zephir_array_append(&related, &item, PH_SEPARATE, "phalcon/Mvc/Model.zep", 397);
							}
						}
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&item);
					if (zephir_fast_count_int(&related TSRMLS_CC) > 0) {
						zephir_read_property(&_10$$14, this_ptr, SL("related"), PH_NOISY_CC | PH_READONLY);
						zephir_array_unset(&_10$$14, &lowerProperty, PH_SEPARATE);
						zephir_update_property_array(this_ptr, SL("dirtyRelated"), &lowerProperty, &related TSRMLS_CC);
						ZEPHIR_INIT_ZVAL_NREF(_11$$14);
						ZVAL_LONG(&_11$$14, 1);
						zephir_update_property_zval(this_ptr, SL("dirtyState"), &_11$$14);
						RETVAL_ZVAL(value, 1, 0);
						RETURN_MM();
					}
					break;
				}
			} while(0);

		}
	}
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "_possiblesetter", NULL, 418, &property, value);
	zephir_check_call_status();
	if (zephir_is_true(&_12)) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_13, "property_exists", NULL, 419, this_ptr, &property);
	zephir_check_call_status();
	if (zephir_is_true(&_13)) {
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_14$$16, &manager, "isvisiblemodelproperty", NULL, 0, this_ptr, &property);
		zephir_check_call_status();
		if (UNEXPECTED(!zephir_is_true(&_14$$16))) {
			ZEPHIR_INIT_VAR(&_15$$17);
			object_init_ex(&_15$$17, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_16$$17);
			ZEPHIR_CONCAT_SVS(&_16$$17, "Property '", &property, "' does not have a setter.");
			ZEPHIR_CALL_METHOD(NULL, &_15$$17, "__construct", NULL, 1, &_16$$17);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_15$$17, "phalcon/Mvc/Model.zep", 431 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_update_property_zval_zval(this_ptr, &property, value TSRMLS_CC);
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * Setups a behavior in a model
 *
 *<code>
 * use Phalcon\Mvc\Model;
 * use Phalcon\Mvc\Model\Behavior\Timestampable;
 *
 * class Robots extends Model
 * {
 *     public function initialize()
 *     {
 *         $this->addBehavior(
 *             new Timestampable(
 *                 [
 *                     "onCreate" => [
 *                         "field"  => "created_at",
 *                         "format" => "Y-m-d",
 *                     ],
 *                 ]
 *             )
 *         );
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, addBehavior) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *behavior, behavior_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&behavior_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &behavior);



	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "addbehavior", NULL, 0, this_ptr, behavior);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Appends a customized message on the validation process
 *
 * <code>
 * use Phalcon\Mvc\Model;
 * use Phalcon\Messages\Message as Message;
 *
 * class Robots extends Model
 * {
 *     public function beforeSave()
 *     {
 *         if ($this->name === "Peter") {
 *             $message = new Message(
 *                 "Sorry, but a robot cannot be named Peter"
 *             );
 *
 *             $this->appendMessage($message);
 *         }
 *     }
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, appendMessage) {

	zval *message, message_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);

	zephir_fetch_params(0, 1, 0, &message);



	zephir_update_property_array_append(this_ptr, SL("errorMessages"), message TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Assigns values to a model from an array
 *
 * <code>
 * $robot->assign(
 *     [
 *         "type" => "mechanical",
 *         "name" => "Astro Boy",
 *         "year" => 1952,
 *     ]
 * );
 *
 * // Assign by db row, column map needed
 * $robot->assign(
 *     $dbRow,
 *     [
 *         "db_type" => "type",
 *         "db_name" => "name",
 *         "db_year" => "year",
 *     ]
 * );
 *
 * // Allow assign only name and year
 * $robot->assign(
 *     $_POST,
 *     null,
 *     [
 *         "name",
 *         "year",
 *     ]
 * );
 *
 * // By default assign method will use setters if exist, you can disable it by using ini_set to directly use properties
 *
 * ini_set("phalcon.orm.disable_assign_setters", true);
 *
 * $robot->assign(
 *     $_POST,
 *     null,
 *     [
 *         "name",
 *         "year",
 *     ]
 * );
 * </code>
 *
 * @param array dataColumnMap array to transform keys of data to another
 * @param array whiteList
 */
PHP_METHOD(Phalcon_Mvc_Model, assign) {

	zend_bool _5$$10, _11$$16;
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *dataColumnMap = NULL, dataColumnMap_sub, *whiteList = NULL, whiteList_sub, __$null, key, keyMapped, value, attribute, attributeField, metaData, columnMap, disableAssignSetters, _3, *_4, *_0$$3, _6$$11, _8$$14, _9$$14, _12$$16;
	zval data, dataMapped;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&dataMapped);
	ZVAL_UNDEF(&dataColumnMap_sub);
	ZVAL_UNDEF(&whiteList_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keyMapped);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&disableAssignSetters);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_12$$16);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &data_param, &dataColumnMap, &whiteList);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!dataColumnMap) {
		dataColumnMap = &dataColumnMap_sub;
		dataColumnMap = &__$null;
	}
	if (!whiteList) {
		whiteList = &whiteList_sub;
		whiteList = &__$null;
	}


	ZEPHIR_INIT_VAR(&disableAssignSetters);
	ZVAL_BOOL(&disableAssignSetters, ZEPHIR_GLOBAL(orm).disable_assign_setters);
	if (Z_TYPE_P(dataColumnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&dataMapped);
		array_init(&dataMapped);
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 565);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _2$$3);
			} else {
				ZVAL_LONG(&key, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0$$3);
			ZEPHIR_OBS_NVAR(&keyMapped);
			if (zephir_array_isset_fetch(&keyMapped, dataColumnMap, &key, 0 TSRMLS_CC)) {
				zephir_array_update_zval(&dataMapped, &keyMapped, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_CPY_WRT(&dataMapped, &data);
	}
	if (zephir_fast_count_int(&dataMapped TSRMLS_CC) == 0) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	ZEPHIR_CALL_METHOD(&_3, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_3, 0, "phalcon/Mvc/Model.zep", 622);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _4)
	{
		ZEPHIR_INIT_NVAR(&attribute);
		ZVAL_COPY(&attribute, _4);
		_5$$10 = !(zephir_array_isset(&columnMap, &attribute));
		if (_5$$10) {
			_5$$10 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
		}
		if (_5$$10) {
			ZEPHIR_CALL_SELF(&_6$$11, "caseinsensitivecolumnmap", &_7, 420, &columnMap, &attribute);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&attribute, &_6$$11);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0 TSRMLS_CC))) {
				if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
					ZEPHIR_INIT_NVAR(&_8$$14);
					object_init_ex(&_8$$14, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_9$$14);
					ZEPHIR_CONCAT_SVS(&_9$$14, "Column '", &attribute, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_8$$14, "__construct", &_10, 1, &_9$$14);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$14, "phalcon/Mvc/Model.zep", 596 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				continue;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, &attribute);
		}
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_array_isset_fetch(&value, &dataMapped, &attributeField, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(whiteList) == IS_ARRAY) {
				if (!(zephir_fast_in_array(&attributeField, whiteList TSRMLS_CC))) {
					continue;
				}
			}
			_11$$16 = zephir_is_true(&disableAssignSetters);
			if (!(_11$$16)) {
				ZEPHIR_CALL_METHOD(&_12$$16, this_ptr, "_possiblesetter", &_13, 418, &attributeField, &value);
				zephir_check_call_status();
				_11$$16 = !zephir_is_true(&_12$$16);
			}
			if (_11$$16) {
				zephir_update_property_zval_zval(this_ptr, &attributeField, &value TSRMLS_CC);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&attribute);
	RETURN_THIS();

}

/**
 * Returns the average value on a column for a result-set of rows matching
 * the specified conditions
 *
 * <code>
 * // What's the average price of robots?
 * $average = Robots::average(
 *     [
 *         "column" => "price",
 *     ]
 * );
 *
 * echo "The average price is ", $average, "\n";
 *
 * // What's the average price of mechanical robots?
 * $average = Robots::average(
 *     [
 *         "type = 'mechanical'",
 *         "column" => "price",
 *     ]
 * );
 *
 * echo "The average price of mechanical robots is ", $average, "\n";
 * </code>
 *
 * @param array parameters
 * @return double
 */
PHP_METHOD(Phalcon_Mvc_Model, average) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "AVG");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "average");
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, 0, &_0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Assigns values to a model from an array returning a new model
 *
 *<code>
 * $robot = Phalcon\Mvc\Model::cloneResult(
 *     new Robots(),
 *     [
 *         "type" => "mechanical",
 *         "name" => "Astro Boy",
 *         "year" => 1952,
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResult) {

	zend_string *_3;
	zend_ulong _2;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *dirtyState_param = NULL, instance, key, value, _0, *_1, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &base, &data_param, &dirtyState_param);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!dirtyState_param) {
		dirtyState = 0;
	} else {
		dirtyState = zephir_get_intval(dirtyState_param);
	}


	ZEPHIR_INIT_VAR(&instance);
	if (zephir_clone(&instance, base TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZVAL_LONG(&_0, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, &instance, "setdirtystate", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 700);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		if (UNEXPECTED(Z_TYPE_P(&key) != IS_STRING)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid key in array data provided to dumpResult()", "phalcon/Mvc/Model.zep", 690);
			return;
		}
		zephir_update_property_zval_zval(&instance, &key, &value TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "afterFetch");
	ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_4);
	zephir_check_call_status();
	RETURN_CCTOR(&instance);

}

/**
 * Assigns values to a model from an array, returning a new model.
 *
 *<code>
 * $robot = \Phalcon\Mvc\Model::cloneResultMap(
 *     new Robots(),
 *     [
 *         "type" => "mechanical",
 *         "name" => "Astro Boy",
 *         "year" => 1952,
 *     ]
 * );
 *</code>
 *
 * @param \Phalcon\Mvc\ModelInterface|\Phalcon\Mvc\Model\Row base
 * @param array columnMap
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMap) {

	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL;
	zend_bool keepSnapshots, _7$$3;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *columnMap, columnMap_sub, *dirtyState_param = NULL, *keepSnapshots_param = NULL, instance, attribute, key, value, castValue, attributeName, _0, *_1, _4$$7, _5$$7, _8$$9, _9$$10, _11$$14, _12$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&castValue);
	ZVAL_UNDEF(&attributeName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$18);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &base, &data_param, &columnMap, &dirtyState_param, &keepSnapshots_param);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!dirtyState_param) {
		dirtyState = 0;
	} else {
		dirtyState = zephir_get_intval(dirtyState_param);
	}
	if (!keepSnapshots_param) {
		keepSnapshots = 0;
	} else {
		keepSnapshots = zephir_get_boolval(keepSnapshots_param);
	}


	ZEPHIR_INIT_VAR(&instance);
	if (zephir_clone(&instance, base TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZVAL_LONG(&_0, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, &instance, "setdirtystate", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 803);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		if (Z_TYPE_P(&key) != IS_STRING) {
			continue;
		}
		if (Z_TYPE_P(columnMap) != IS_ARRAY) {
			zephir_update_property_zval_zval(&instance, &key, &value TSRMLS_CC);
			continue;
		}
		ZEPHIR_OBS_NVAR(&attribute);
		if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0 TSRMLS_CC))) {
			if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
				ZEPHIR_INIT_NVAR(&_4$$7);
				object_init_ex(&_4$$7, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_5$$7);
				ZEPHIR_CONCAT_SVS(&_5$$7, "Column '", &key, "' doesn't make part of the column map");
				ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", &_6, 1, &_5$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$7, "phalcon/Mvc/Model.zep", 748 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			continue;
		}
		if (Z_TYPE_P(&attribute) != IS_ARRAY) {
			zephir_update_property_zval_zval(&instance, &attribute, &value TSRMLS_CC);
			continue;
		}
		_7$$3 = !ZEPHIR_IS_STRING(&value, "");
		if (_7$$3) {
			_7$$3 = Z_TYPE_P(&value) != IS_NULL;
		}
		if (_7$$3) {
			zephir_array_fetch_long(&_8$$9, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 761 TSRMLS_CC);
			do {
				if (ZEPHIR_IS_LONG(&_8$$9, 0)) {
					ZVAL_LONG(&_9$$10, 10);
					ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_10, 26, &value, &_9$$10);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(&_8$$9, 9) || ZEPHIR_IS_LONG(&_8$$9, 3) || ZEPHIR_IS_LONG(&_8$$9, 7)) {
					ZEPHIR_INIT_NVAR(&castValue);
					ZVAL_DOUBLE(&castValue, zephir_get_doubleval(&value));
					break;
				}
				if (ZEPHIR_IS_LONG(&_8$$9, 8)) {
					ZEPHIR_INIT_NVAR(&castValue);
					ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
					break;
				}
				ZEPHIR_CPY_WRT(&castValue, &value);
				break;
			} while(0);

		} else {
			zephir_array_fetch_long(&_11$$14, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 781 TSRMLS_CC);
			do {
				if (ZEPHIR_IS_LONG(&_11$$14, 0) || ZEPHIR_IS_LONG(&_11$$14, 9) || ZEPHIR_IS_LONG(&_11$$14, 3) || ZEPHIR_IS_LONG(&_11$$14, 7) || ZEPHIR_IS_LONG(&_11$$14, 8)) {
					ZEPHIR_INIT_NVAR(&castValue);
					ZVAL_NULL(&castValue);
					break;
				}
				ZEPHIR_CPY_WRT(&castValue, &value);
				break;
			} while(0);

		}
		ZEPHIR_OBS_NVAR(&attributeName);
		zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 796 TSRMLS_CC);
		zephir_update_property_zval_zval(&instance, &attributeName, &castValue TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (keepSnapshots) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "setsnapshotdata", NULL, 0, &data, columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &instance, "setoldsnapshotdata", NULL, 0, &data, columnMap);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(&instance, SL("fireevent") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_12$$18);
		ZVAL_STRING(&_12$$18, "afterFetch");
		ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_12$$18);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&instance);

}

/**
 * Returns an hydrated result based on the data and the column map
 *
 * @param array columnMap
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMapHydrate) {

	zend_bool _3$$7;
	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_9 = NULL;
	zend_long hydrationMode, ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap, columnMap_sub, *hydrationMode_param = NULL, key, value, attribute, attributeName, *_0, _4$$8, _6$$10, _7$$10;
	zval data, hydrateArray;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&hydrateArray);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&attributeName);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data_param, &columnMap, &hydrationMode_param);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	hydrationMode = zephir_get_intval(hydrationMode_param);


	if (Z_TYPE_P(columnMap) != IS_ARRAY) {
		if (hydrationMode == 1) {
			RETURN_CTOR(&data);
		}
	}
	ZEPHIR_INIT_VAR(&hydrateArray);
	array_init(&hydrateArray);
	zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 884);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		if (Z_TYPE_P(&key) != IS_STRING) {
			continue;
		}
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			_3$$7 = !(zephir_array_isset(columnMap, &key));
			if (_3$$7) {
				_3$$7 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
			}
			if (_3$$7) {
				ZEPHIR_CALL_SELF(&_4$$8, "caseinsensitivecolumnmap", &_5, 420, columnMap, &key);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&key, &_4$$8);
			}
			ZEPHIR_OBS_NVAR(&attribute);
			if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0 TSRMLS_CC))) {
				if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
					ZEPHIR_INIT_NVAR(&_6$$10);
					object_init_ex(&_6$$10, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_7$$10);
					ZEPHIR_CONCAT_SVS(&_7$$10, "Column '", &key, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_6$$10, "__construct", &_8, 1, &_7$$10);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_6$$10, "phalcon/Mvc/Model.zep", 863 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				continue;
			}
			if (Z_TYPE_P(&attribute) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeName);
				zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 873 TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(&attributeName, &attribute);
			}
			zephir_array_update_zval(&hydrateArray, &attributeName, &value, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&hydrateArray, &key, &value, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (hydrationMode != 1) {
		ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_arr_ce, "arraytoobject", &_9, 421, &hydrateArray);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(&hydrateArray);

}

/**
 * Counts how many records match the specified conditions
 *
 * <code>
 * // How many robots are there?
 * $number = Robots::count();
 *
 * echo "There are ", $number, "\n";
 *
 * // How many mechanical robots are there?
 * $number = Robots::count("type = 'mechanical'");
 *
 * echo "There are ", $number, " mechanical robots\n";
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, count) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, result, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "COUNT");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "rowcount");
	ZEPHIR_CALL_SELF(&result, "_groupresult", NULL, 0, &_0, &_1, parameters);
	zephir_check_call_status();
	if (Z_TYPE_P(&result) == IS_STRING) {
		RETURN_MM_LONG(zephir_get_intval(&result));
	}
	RETURN_CCTOR(&result);

}

/**
 * Inserts a model instance. If the instance already exists in the
 * persistence it will throw an exception
 * Returning true on success or false otherwise.
 *
 *<code>
 * // Creating a new robot
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * $robot->create();
 *
 * // Passing an array to create
 * $robot = new Robots();
 *
 * $robot->assign(
 *     [
 *         "type" => "mechanical",
 *         "name" => "Astro Boy",
 *         "year" => 1952,
 *     ]
 * );
 *
 * $robot->create();
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, create) {

	zval _2$$3;
	zval metaData, _0, _1, _3$$3, _4$$3, _5$$3, _6$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getreadconnection", NULL, 422);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_exists", NULL, 0, &metaData, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_messages_message_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Record cannot be created because it already exists");
		ZVAL_NULL(&_5$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "InvalidCreateAttempt");
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 404, &_4$$3, &_5$$3, &_6$$3);
		zephir_check_call_status();
		zephir_array_fast_append(&_2$$3, &_3$$3);
		zephir_update_property_zval(this_ptr, SL("errorMessages"), &_2$$3);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "save", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 *
 * <code>
 * $robot = Robots::findFirst("id=100");
 *
 * $robot->delete();
 *
 * $robots = Robots::find("type = 'mechanical'");
 *
 * foreach ($robots as $robot) {
 *     $robot->delete();
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, delete) {

	zval values, bindTypes, conditions;
	zval __$true, __$false, metaData, writeConnection, primaryKeys, bindDataTypes, columnMap, attributeField, primaryKey, bindType, value, schema, source, table, success, _0, _1, *_3, _17, _2$$3, _4$$9, _5$$9, _7$$11, _8$$11, _9$$13, _10$$13, _11$$8, _13$$8, _14$$14, _15$$14, _16$$14, _18$$19, _19$$22;
	zephir_fcall_cache_entry *_6 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&writeConnection);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&primaryKey);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_18$$19);
	ZVAL_UNDEF(&_19$$22);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&conditions);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 423);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 3);
	zephir_update_property_zval(this_ptr, SL("operationMade"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, SL("errorMessages"), &_1);
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "_checkforeignkeysreverserestrict", NULL, 424);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&bindTypes);
	array_init(&bindTypes);
	ZEPHIR_INIT_VAR(&conditions);
	array_init(&conditions);
	ZEPHIR_CALL_METHOD(&primaryKeys, &metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, &metaData, "getbindtypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	if (UNEXPECTED(!(zephir_fast_count_int(&primaryKeys TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation", "phalcon/Mvc/Model.zep", 1038);
		return;
	}
	zephir_is_iterable(&primaryKeys, 0, "phalcon/Mvc/Model.zep", 1086);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _3)
	{
		ZEPHIR_INIT_NVAR(&primaryKey);
		ZVAL_COPY(&primaryKey, _3);
		ZEPHIR_OBS_NVAR(&bindType);
		if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(&_4$$9);
			object_init_ex(&_4$$9, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_5$$9);
			ZEPHIR_CONCAT_SVS(&_5$$9, "Column '", &primaryKey, "' have not defined a bind data type");
			ZEPHIR_CALL_METHOD(NULL, &_4$$9, "__construct", &_6, 1, &_5$$9);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$9, "phalcon/Mvc/Model.zep", 1052 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0 TSRMLS_CC)))) {
				ZEPHIR_INIT_NVAR(&_7$$11);
				object_init_ex(&_7$$11, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_8$$11);
				ZEPHIR_CONCAT_SVS(&_8$$11, "Column '", &primaryKey, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, &_7$$11, "__construct", &_6, 1, &_8$$11);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$11, "phalcon/Mvc/Model.zep", 1062 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
		}
		ZEPHIR_OBS_NVAR(&value);
		if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)))) {
			ZEPHIR_INIT_NVAR(&_9$$13);
			object_init_ex(&_9$$13, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_10$$13);
			ZEPHIR_CONCAT_SVS(&_10$$13, "Cannot delete the record because the primary key attribute: '", &attributeField, "' wasn't set");
			ZEPHIR_CALL_METHOD(NULL, &_9$$13, "__construct", &_6, 1, &_10$$13);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$13, "phalcon/Mvc/Model.zep", 1075 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1081);
		ZEPHIR_CALL_METHOD(&_11$$8, &writeConnection, "escapeidentifier", &_12, 0, &primaryKey);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_13$$8);
		ZEPHIR_CONCAT_VS(&_13$$8, &_11$$8, " = ?");
		zephir_array_append(&conditions, &_13$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1082);
		zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1083);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&primaryKey);
	if (ZEPHIR_GLOBAL(orm).events) {
		if (0) {
			zephir_update_property_zval(this_ptr, SL("skipped"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("skipped"), &__$false);
		}
		ZEPHIR_INIT_VAR(&_15$$14);
		ZVAL_STRING(&_15$$14, "beforeDelete");
		ZEPHIR_CALL_METHOD(&_14$$14, this_ptr, "fireeventcancel", NULL, 0, &_15$$14);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_14$$14)) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property(&_16$$14, this_ptr, SL("skipped"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_16$$14)) {
			RETURN_MM_BOOL(1);
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 425);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 426);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_INIT_VAR(&_17);
	zephir_fast_join_str(&_17, SL(" AND "), &conditions TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&success, &writeConnection, "delete", NULL, 0, &table, &_17, &values, &bindTypes);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_18$$19, this_ptr, "_checkforeignkeysreversecascade", NULL, 427);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_18$$19)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (zephir_is_true(&success)) {
			ZEPHIR_INIT_VAR(&_19$$22);
			ZVAL_STRING(&_19$$22, "afterDelete");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_19$$22);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 2);
	zephir_update_property_zval(this_ptr, SL("dirtyState"), &_0);
	RETURN_CCTOR(&success);

}

/**
 * Returns a simple representation of the object that can be used with
 * `var_dump()`
 *
 *<code>
 * var_dump(
 *     $robot->dump()
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, dump) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 7, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Query for a set of records that match the specified conditions
 *
 * <code>
 * // How many robots are there?
 * $robots = Robots::find();
 *
 * echo "There are ", count($robots), "\n";
 *
 * // How many mechanical robots are there?
 * $robots = Robots::find(
 *     "type = 'mechanical'"
 * );
 *
 * echo "There are ", count($robots), "\n";
 *
 * // Get and print virtual robots ordered by name
 * $robots = Robots::find(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *     ]
 * );
 *
 * foreach ($robots as $robot) {
 *     echo $robot->name, "\n";
 * }
 *
 * // Get first 100 virtual robots ordered by name
 * $robots = Robots::find(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *         "limit" => 100,
 *     ]
 * );
 *
 * foreach ($robots as $robot) {
 *     echo $robot->name, "\n";
 * }
 *
 * // encapsulate find it into an running transaction esp. useful for application unit-tests
 * // or complex business logic where we wanna control which transactions are used.
 *
 * $myTransaction = new Transaction(\Phalcon\Di::getDefault());
 * $myTransaction->begin();
 *
 * $newRobot = new Robot();
 * $newRobot->setTransaction($myTransaction);
 *
 * $newRobot->assign(
 *     [
 *         'name' => 'test',
 *         'type' => 'mechanical',
 *         'year' => 1944,
 *     ]
 * );
 *
 * $newRobot->save();
 *
 * $resultInsideTransaction = Robot::find(
 *     [
 *         'name' => 'test',
 *         Model::TRANSACTION_INDEX => $myTransaction,
 *     ]
 * );
 *
 * $resultOutsideTransaction = Robot::find(['name' => 'test']);
 *
 * foreach ($setInsideTransaction as $robot) {
 *     echo $robot->name, "\n";
 * }
 *
 * foreach ($setOutsideTransaction as $robot) {
 *     echo $robot->name, "\n";
 * }
 *
 * // reverts all not commited changes
 * $myTransaction->rollback();
 *
 * // creating two different transactions
 * $myTransaction1 = new Transaction(\Phalcon\Di::getDefault());
 * $myTransaction1->begin();
 * $myTransaction2 = new Transaction(\Phalcon\Di::getDefault());
 * $myTransaction2->begin();
 *
 *  // add a new robots
 * $firstNewRobot = new Robot();
 * $firstNewRobot->setTransaction($myTransaction1);
 * $firstNewRobot->assign(
 *     [
 *         'name' => 'first-transaction-robot',
 *         'type' => 'mechanical',
 *         'year' => 1944,
 *     ]
 * );
 * $firstNewRobot->save();
 *
 * $secondNewRobot = new Robot();
 * $secondNewRobot->setTransaction($myTransaction2);
 * $secondNewRobot->assign(
 *     [
 *         'name' => 'second-transaction-robot',
 *         'type' => 'fictional',
 *         'year' => 1984,
 *     ]
 * );
 * $secondNewRobot->save();
 *
 * // this transaction will find the robot.
 * $resultInFirstTransaction = Robot::find(
 *     [
 *         'name'                   => 'first-transaction-robot',
 *         Model::TRANSACTION_INDEX => $myTransaction1,
 *     ]
 * );
 *
 * // this transaction won't find the robot.
 * $resultInSecondTransaction = Robot::find(
 *     [
 *         'name'                   => 'first-transaction-robot',
 *         Model::TRANSACTION_INDEX => $myTransaction2,
 *     ]
 * );
 *
 * // this transaction won't find the robot.
 * $resultOutsideAnyExplicitTransaction = Robot::find(
 *     [
 *         'name' => 'first-transaction-robot',
 *     ]
 * );
 *
 * // this transaction won't find the robot.
 * $resultInFirstTransaction = Robot::find(
 *     [
 *         'name'                   => 'second-transaction-robot',
 *         Model::TRANSACTION_INDEX => $myTransaction2,
 *     ]
 * );
 *
 * // this transaction will find the robot.
 * $resultInSecondTransaction = Robot::find(
 *     [
 *         'name'                   => 'second-transaction-robot',
 *         Model::TRANSACTION_INDEX => $myTransaction1,
 *     ]
 * );
 *
 * // this transaction won't find the robot.
 * $resultOutsideAnyExplicitTransaction = Robot::find(
 *     [
 *         'name' => 'second-transaction-robot',
 *     ]
 * );
 *
 * $transaction1->rollback();
 * $transaction2->rollback();
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, find) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters = NULL, parameters_sub, __$null, params, query, resultset, hydration;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&hydration);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1329);
		}
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_CALL_STATIC(&query, "getpreparedquery", &_0, 428, &params);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&resultset, &query, "execute", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&resultset) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(&hydration);
		if (zephir_array_isset_string_fetch(&hydration, &params, SL("hydration"), 0)) {
			ZEPHIR_CALL_METHOD(NULL, &resultset, "sethydratemode", NULL, 0, &hydration);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&resultset);

}

/**
 * Query the first record that matches the specified conditions
 *
 * <code>
 * // What's the first robot in robots table?
 * $robot = Robots::findFirst();
 *
 * echo "The robot name is ", $robot->name;
 *
 * // What's the first mechanical robot in robots table?
 * $robot = Robots::findFirst(
 *     "type = 'mechanical'"
 * );
 *
 * echo "The first mechanical robot name is ", $robot->name;
 *
 * // Get first virtual robot ordered by name
 * $robot = Robots::findFirst(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *     ]
 * );
 *
 * echo "The first virtual robot name is ", $robot->name;
 *
 * // behaviour with transaction
 * $myTransaction = new Transaction(\Phalcon\Di::getDefault());
 * $myTransaction->begin();
 *
 * $newRobot = new Robot();
 * $newRobot->setTransaction($myTransaction);
 * $newRobot->assign(
 *     [
 *         'name' => 'test',
 *         'type' => 'mechanical',
 *         'year' => 1944,
 *     ]
 * );
 * $newRobot->save();
 *
 * $findsARobot = Robot::findFirst(
 *     [
 *         'name'                   => 'test',
 *         Model::TRANSACTION_INDEX => $myTransaction,
 *     ]
 * );
 *
 * $doesNotFindARobot = Robot::findFirst(
 *     [
 *         'name' => 'test',
 *     ]
 * );
 *
 * var_dump($findARobot);
 * var_dump($doesNotFindARobot);
 *
 * $transaction->commit();
 *
 * $doesFindTheRobotNow = Robot::findFirst(
 *     [
 *         'name' => 'test',
 *     ]
 * );
 * </code>
 *
 * @param string|array parameters
 */
PHP_METHOD(Phalcon_Mvc_Model, findFirst) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *parameters = NULL, parameters_sub, __$null, params, query, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	_0 = Z_TYPE_P(parameters) == IS_STRING;
	if (!(_0)) {
		_0 = zephir_is_numeric(parameters);
	}
	if (Z_TYPE_P(parameters) == IS_NULL) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else if (Z_TYPE_P(parameters) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&params, parameters);
	} else if (_0) {
		ZEPHIR_INIT_NVAR(&params);
		zephir_create_array(&params, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&params, parameters);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Parameters passed must be of type array, string, numeric or null", "phalcon/Mvc/Model.zep", 1435);
		return;
	}
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_STATIC(&query, "getpreparedquery", &_1, 428, &params, &_2);
	zephir_check_call_status();
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_CALL_METHOD(NULL, &query, "setuniquerow", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&query, "execute", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events
 * manager are notified
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEvent) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, _0;
	zval eventName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

	if (UNEXPECTED(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(&eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(&eventName);
		ZVAL_EMPTY_STRING(&eventName);
	}


	if ((zephir_method_exists(this_ptr, &eventName TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &eventName, NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "notifyevent", NULL, 0, &eventName, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events
 * manager are notified
 * This method stops if one of the callbacks/listeners returns bool false
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEventCancel) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, _0$$3, _1;
	zval eventName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

	if (UNEXPECTED(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(&eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(&eventName);
		ZVAL_EMPTY_STRING(&eventName);
	}


	if ((zephir_method_exists(this_ptr, &eventName TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(&_0$$3, this_ptr, &eventName, NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	zephir_read_property(&_1, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "notifyevent", NULL, 0, &eventName, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a list of changed values.
 *
 * <code>
 * $robots = Robots::findFirst();
 * print_r($robots->getChangedFields()); // []
 *
 * $robots->deleted = 'Y';
 *
 * $robots->getChangedFields();
 * print_r($robots->getChangedFields()); // ["deleted"]
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, getChangedFields) {

	zend_string *_4;
	zend_ulong _3;
	zval changed;
	zval metaData, name, snapshot, columnMap, allAttributes, value, _0, _1, *_2, _5$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&allAttributes);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&changed);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("snapshot"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	if (UNEXPECTED(Z_TYPE_P(&snapshot) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record doesn't have a valid data snapshot", "phalcon/Mvc/Model.zep", 1521);
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getreversecolumnmap", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&columnMap) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&allAttributes, &metaData, "getdatatypes", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&allAttributes, &columnMap);
	}
	ZEPHIR_INIT_VAR(&changed);
	array_init(&changed);
	ZEPHIR_INIT_VAR(&_1);
	zephir_is_iterable(&allAttributes, 0, "phalcon/Mvc/Model.zep", 1579);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&allAttributes), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&name, _4);
		} else {
			ZVAL_LONG(&name, _3);
		}
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_COPY(&_1, _2);
		if (!(zephir_array_isset(&snapshot, &name))) {
			zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1554);
			continue;
		}
		ZEPHIR_OBS_NVAR(&value);
		if (!(zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC))) {
			zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1564);
			continue;
		}
		zephir_array_fetch(&_5$$6, &snapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1572 TSRMLS_CC);
		if (!ZEPHIR_IS_IDENTICAL(&value, &_5$$6)) {
			zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1573);
			continue;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CTOR(&changed);

}

/**
 * Returns one of the DIRTY_STATE_* constants telling if the record exists
 * in the database or not
 */
PHP_METHOD(Phalcon_Mvc_Model, getDirtyState) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "dirtyState");

}

/**
 * Returns the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * Returns the custom events manager
 */
PHP_METHOD(Phalcon_Mvc_Model, getEventsManager) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getcustomeventsmanager", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns array of validation messages
 *
 *<code>
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * if ($robot->save() === false) {
 *     echo "Umh, We can't store robots right now ";
 *
 *     $messages = $robot->getMessages();
 *
 *     foreach ($messages as $message) {
 *         echo $message;
 *     }
 * } else {
 *     echo "Great, a new robot was saved successfully!";
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, getMessages) {

	zend_bool _0;
	zval filtered;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filter = NULL, filter_sub, __$null, message, _1$$3, *_2$$3, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&filtered);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &filter);

	if (!filter) {
		filter = &filter_sub;
		filter = &__$null;
	}


	_0 = Z_TYPE_P(filter) == IS_STRING;
	if (_0) {
		_0 = !(ZEPHIR_IS_EMPTY(filter));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&filtered);
		array_init(&filtered);
		zephir_read_property(&_1$$3, this_ptr, SL("errorMessages"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "phalcon/Mvc/Model.zep", 1644);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$3), _2$$3)
		{
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_COPY(&message, _2$$3);
			ZEPHIR_CALL_METHOD(&_3$$4, &message, "getfield", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EQUAL(&_3$$4, filter)) {
				zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1640);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&message);
		RETURN_CTOR(&filtered);
	}
	RETURN_MM_MEMBER(getThis(), "errorMessages");

}

/**
 * Returns the models manager related to the entity instance
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "modelsManager");

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsMetaData) {

	zval metaData, container, _0$$3, _1$$3, _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&metaData);
	zephir_read_property(&metaData, this_ptr, SL("modelsMetaData"), PH_NOISY_CC);
	if (Z_TYPE_P(&metaData) != IS_OBJECT) {
		zephir_read_property(&_0$$3, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_0$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&_1$$3, &container, "getshared", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&metaData, &_1$$3);
		if (UNEXPECTED(Z_TYPE_P(&metaData) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsMetadata' is not valid", "phalcon/Mvc/Model.zep", 1678);
			return;
		}
		zephir_update_property_zval(this_ptr, SL("modelsMetaData"), &metaData);
	}
	RETURN_CCTOR(&metaData);

}

/**
 * Returns the type of the latest operation performed by the ORM
 * Returns one of the OP_* class constants
 */
PHP_METHOD(Phalcon_Mvc_Model, getOperationMade) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "operationMade");

}

/**
 * Returns the internal old snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, getOldSnapshotData) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "oldSnapshot");

}

/**
 * Gets the connection used to read data for the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnection) {

	zval transaction, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("transaction"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&transaction, &_0);
	if (Z_TYPE_P(&transaction) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(&transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getreadconnection", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the DependencyInjection connection service name used to read data
 * related the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnectionService) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getreadconnectionservice", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns related records based on defined relations
 *
 * @param array arguments
 * @return \Phalcon\Mvc\Model\Resultset\Simple|Phalcon\Mvc\Model\Resultset\Simple|false
 */
PHP_METHOD(Phalcon_Mvc_Model, getRelated) {

	zend_bool _5$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, *arguments = NULL, arguments_sub, __$null, relation, className, manager, result, lowerAlias, _0, _1, _2$$3, _3$$3, _4$$4, _6$$4, _7$$5, _8$$6, _9$$7;
	zval alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&lowerAlias);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &alias_param, &arguments);

	zephir_get_strval(&alias, alias_param);
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, this_ptr, 0 TSRMLS_CC);
	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&lowerAlias);
	zephir_fast_strtolower(&lowerAlias, &alias);
	ZEPHIR_CALL_METHOD(&_1, &manager, "getrelationbyalias", NULL, 0, &className, &lowerAlias);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_1);
	if (UNEXPECTED(Z_TYPE_P(&relation) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVSVS(&_3$$3, "There is no defined relations for the model '", &className, "' using alias '", &alias, "'");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 1, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Mvc/Model.zep", 1757 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(arguments) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_4$$4, &relation, "isreusable", NULL, 0);
		zephir_check_call_status();
		_5$$4 = zephir_is_true(&_4$$4);
		if (_5$$4) {
			ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "isrelationshiploaded", NULL, 0, &lowerAlias);
			zephir_check_call_status();
			_5$$4 = zephir_is_true(&_6$$4);
		}
		if (_5$$4) {
			zephir_read_property(&_7$$5, this_ptr, SL("related"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_VAR(&result);
			zephir_array_fetch(&result, &_7$$5, &lowerAlias, PH_NOISY, "phalcon/Mvc/Model.zep", 1769 TSRMLS_CC);
		} else {
			ZVAL_NULL(&_8$$6);
			ZEPHIR_CALL_METHOD(&result, &manager, "getrelationrecords", NULL, 0, &relation, &_8$$6, this_ptr, arguments);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("related"), &lowerAlias, &result TSRMLS_CC);
		}
	} else {
		ZVAL_NULL(&_9$$7);
		ZEPHIR_CALL_METHOD(&result, &manager, "getrelationrecords", NULL, 0, &relation, &_9$$7, this_ptr, arguments);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

/**
 * Checks if saved related records have already been loaded.
 *
 * Only returns true if the records were previously fetched
 * through the model without any additional parameters.
 *
 * <code>
 * $robot = Robots::findFirst();
 * var_dump($robot->isRelationshipLoaded('robotsParts')); // false
 *
 * $robotsParts = $robot->getRobotsParts(['id > 0']);
 * var_dump($robot->isRelationshipLoaded('robotsParts')); // false
 *
 * $robotsParts = $robot->getRobotsParts(); // or $robot->robotsParts
 * var_dump($robot->isRelationshipLoaded('robotsParts')); // true
 *
 * $robot->robotsParts = [new RobotsParts()];
 * var_dump($robot->isRelationshipLoaded('robotsParts')); // false
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, isRelationshipLoaded) {

	zval *relationshipAlias_param = NULL, _0, _1;
	zval relationshipAlias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&relationshipAlias);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &relationshipAlias_param);

	zephir_get_strval(&relationshipAlias, relationshipAlias_param);


	zephir_read_property(&_0, this_ptr, SL("related"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, &relationshipAlias);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &_1));

}

/**
 * Returns schema name where the mapped table is located
 */
PHP_METHOD(Phalcon_Mvc_Model, getSchema) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getmodelschema", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the internal snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, getSnapshotData) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "snapshot");

}

/**
 * Returns the table name mapped in the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getSource) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getmodelsource", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a list of updated values.
 *
 * <code>
 * $robots = Robots::findFirst();
 * print_r($robots->getChangedFields()); // []
 *
 * $robots->deleted = 'Y';
 *
 * $robots->getChangedFields();
 * print_r($robots->getChangedFields()); // ["deleted"]
 * $robots->save();
 * print_r($robots->getChangedFields()); // []
 * print_r($robots->getUpdatedFields()); // ["deleted"]
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, getUpdatedFields) {

	zend_bool _4$$6;
	zend_string *_3;
	zend_ulong _2;
	zval updated;
	zval name, snapshot, oldSnapshot, value, _0, *_1, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&oldSnapshot);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&updated);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("snapshot"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	zephir_read_property(&_0, this_ptr, SL("oldSnapshot"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&oldSnapshot, &_0);
	if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).update_snapshot_on_save))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Update snapshot on save must be enabled for this method to work properly", "phalcon/Mvc/Model.zep", 1868);
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&snapshot) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record doesn't have a valid data snapshot", "phalcon/Mvc/Model.zep", 1874);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!ZEPHIR_IS_LONG(&_0, 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Change checking cannot be performed because the object has not been persisted or is deleted", "phalcon/Mvc/Model.zep", 1883);
		return;
	}
	ZEPHIR_INIT_VAR(&updated);
	array_init(&updated);
	zephir_is_iterable(&snapshot, 0, "phalcon/Mvc/Model.zep", 1898);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&snapshot), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&name, _3);
		} else {
			ZVAL_LONG(&name, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		_4$$6 = !(zephir_array_isset(&oldSnapshot, &name));
		if (!(_4$$6)) {
			zephir_array_fetch(&_5$$6, &oldSnapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1893 TSRMLS_CC);
			_4$$6 = !ZEPHIR_IS_IDENTICAL(&value, &_5$$6);
		}
		if (_4$$6) {
			zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1894);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CTOR(&updated);

}

/**
 * Gets the connection used to write data to the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnection) {

	zval transaction, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("transaction"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&transaction, &_0);
	if (Z_TYPE_P(&transaction) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(&transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getwriteconnection", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the DependencyInjection connection service name used to write
 * data related to the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnectionService) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getwriteconnectionservice", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if a specific attribute has changed
 * This only works if the model is keeping data snapshots
 *
 *<code>
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * $robot->create();
 *
 * $robot->type = "hydraulic";
 *
 * $hasChanged = $robot->hasChanged("type"); // returns true
 * $hasChanged = $robot->hasChanged(["type", "name"]); // returns true
 * $hasChanged = $robot->hasChanged(["type", "name"], true); // returns false
 *</code>
 *
 * @param string|array fieldName
 */
PHP_METHOD(Phalcon_Mvc_Model, hasChanged) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool allFields;
	zval *fieldName = NULL, fieldName_sub, *allFields_param = NULL, __$null, changedFields, intersect;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fieldName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&changedFields);
	ZVAL_UNDEF(&intersect);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fieldName, &allFields_param);

	if (!fieldName) {
		fieldName = &fieldName_sub;
		fieldName = &__$null;
	}
	if (!allFields_param) {
		allFields = 0;
	} else {
		allFields = zephir_get_boolval(allFields_param);
	}


	ZEPHIR_CALL_METHOD(&changedFields, this_ptr, "getchangedfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fieldName) == IS_STRING) {
		RETURN_MM_BOOL(zephir_fast_in_array(fieldName, &changedFields TSRMLS_CC));
	}
	if (Z_TYPE_P(fieldName) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect", NULL, 215, fieldName, &changedFields);
		zephir_check_call_status();
		if (allFields) {
			RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(&intersect, fieldName));
		}
		RETURN_MM_BOOL(zephir_fast_count_int(&intersect TSRMLS_CC) > 0);
	}
	RETURN_MM_BOOL(zephir_fast_count_int(&changedFields TSRMLS_CC) > 0);

}

/**
 * Checks if the object has internal snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, hasSnapshotData) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("snapshot"), PH_NOISY_CC);
	RETURN_MM_BOOL(Z_TYPE_P(&_0) == IS_ARRAY);

}

/**
 * Check if a specific attribute was updated
 * This only works if the model is keeping data snapshots
 *
 * @param string|array fieldName
 */
PHP_METHOD(Phalcon_Mvc_Model, hasUpdated) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool allFields;
	zval *fieldName = NULL, fieldName_sub, *allFields_param = NULL, __$null, updatedFields, intersect;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fieldName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&updatedFields);
	ZVAL_UNDEF(&intersect);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fieldName, &allFields_param);

	if (!fieldName) {
		fieldName = &fieldName_sub;
		fieldName = &__$null;
	}
	if (!allFields_param) {
		allFields = 0;
	} else {
		allFields = zephir_get_boolval(allFields_param);
	}


	ZEPHIR_CALL_METHOD(&updatedFields, this_ptr, "getupdatedfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fieldName) == IS_STRING) {
		RETURN_MM_BOOL(zephir_fast_in_array(fieldName, &updatedFields TSRMLS_CC));
	}
	if (Z_TYPE_P(fieldName) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect", NULL, 215, fieldName, &updatedFields);
		zephir_check_call_status();
		if (allFields) {
			RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(&intersect, fieldName));
		}
		RETURN_MM_BOOL(zephir_fast_count_int(&intersect TSRMLS_CC) > 0);
	}
	RETURN_MM_BOOL(zephir_fast_count_int(&updatedFields TSRMLS_CC) > 0);

}

/**
 * Serializes the object for json_encode
 *
 *<code>
 * echo json_encode($robot);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, jsonSerialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the maximum value of a column for a result-set of rows that match
 * the specified conditions
 *
 * <code>
 * // What is the maximum robot id?
 * $id = Robots::maximum(
 *     [
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The maximum robot id is: ", $id, "\n";
 *
 * // What is the maximum id of mechanical robots?
 * $sum = Robots::maximum(
 *     [
 *         "type = 'mechanical'",
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The maximum robot id of mechanical robots is ", $id, "\n";
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, maximum) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "MAX");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "maximum");
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, 0, &_0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the minimum value of a column for a result-set of rows that match
 * the specified conditions
 *
 * <code>
 * // What is the minimum robot id?
 * $id = Robots::minimum(
 *     [
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The minimum robot id is: ", $id;
 *
 * // What is the minimum id of mechanical robots?
 * $sum = Robots::minimum(
 *     [
 *         "type = 'mechanical'",
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The minimum robot id of mechanical robots is ", $id;
 * </code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Mvc_Model, minimum) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "MIN");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "minimum");
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, 0, &_0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Create a criteria for a specific model
 */
PHP_METHOD(Phalcon_Mvc_Model, query) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *container = NULL, container_sub, __$null, criteria, _3, _1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&criteria);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &container);

	if (!container) {
		container = &container_sub;
		ZEPHIR_CPY_WRT(container, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(container);
	}


	if (Z_TYPE_P(container) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(container, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&criteria);
	if (zephir_instance_of_ev(container, phalcon_diinterface_ce TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "Phalcon\\Mvc\\Model\\Criteria");
		ZEPHIR_CALL_METHOD(&_1$$4, container, "get", NULL, 0, &_2$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&criteria, &_1$$4);
	} else {
		object_init_ex(&criteria, phalcon_mvc_model_criteria_ce);
		if (zephir_has_constructor(&criteria TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &criteria, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, &criteria, "setdi", NULL, 429, container);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_get_called_class(&_3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &criteria, "setmodelname", NULL, 430, &_3);
	zephir_check_call_status();
	RETURN_CCTOR(&criteria);

}

/**
 * Reads an attribute value by its name
 *
 * <code>
 * echo $robot->readAttribute("name");
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, readAttribute) {

	zval *attribute_param = NULL, _0;
	zval attribute;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_0);

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


	if (!(zephir_isset_property_zval(this_ptr, &attribute TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property_zval(&_0, this_ptr, &attribute, PH_NOISY_CC);
	RETURN_CCTOR(&_0);

}

/**
 * Refreshes the model attributes re-querying the record from the database
 */
PHP_METHOD(Phalcon_Mvc_Model, refresh) {

	zval fields, _7, _6$$9;
	zval metaData, readConnection, schema, source, table, uniqueKey, tables, uniqueParams, dialect, row, attribute, manager, columnMap, _0, _1, _4, *_5, _8, _9, _11, _2$$6, _3$$6, _10$$10;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&readConnection);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&uniqueKey);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&uniqueParams);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_6$$9);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!ZEPHIR_IS_LONG(&_0, 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/Mvc/Model.zep", 2152);
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 422);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_1);
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 425);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 426);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	zephir_read_property(&_1, this_ptr, SL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueKey, &_1);
	if (!(zephir_is_true(&uniqueKey))) {
		ZEPHIR_CALL_METHOD(&_2$$6, this_ptr, "_exists", NULL, 0, &metaData, &readConnection, &table);
		zephir_check_call_status();
		if (UNEXPECTED(!zephir_is_true(&_2$$6))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/Mvc/Model.zep", 2177);
			return;
		}
		zephir_read_property(&_3$$6, this_ptr, SL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueKey, &_3$$6);
	}
	zephir_read_property(&_1, this_ptr, SL("uniqueParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueParams, &_1);
	if (UNEXPECTED(Z_TYPE_P(&uniqueParams) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/Mvc/Model.zep", 2188);
		return;
	}
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_CALL_METHOD(&_4, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_4, 0, "phalcon/Mvc/Model.zep", 2203);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
	{
		ZEPHIR_INIT_NVAR(&attribute);
		ZVAL_COPY(&attribute, _5);
		ZEPHIR_INIT_NVAR(&_6$$9);
		zephir_create_array(&_6$$9, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_6$$9, &attribute);
		zephir_array_append(&fields, &_6$$9, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2197);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&dialect, &readConnection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_7, SL("columns"), &fields, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_8, &readConnection, "escapeidentifier", NULL, 0, &table);
	zephir_check_call_status();
	zephir_array_update_string(&_7, SL("tables"), &_8, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_7, SL("where"), &uniqueKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&tables, &dialect, "select", NULL, 0, &_7);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("uniqueTypes"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_9, 2);
	ZEPHIR_CALL_METHOD(&row, &readConnection, "fetchone", NULL, 0, &tables, &_9, &uniqueParams, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&row) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, &row, &columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_10$$10, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_10$$10)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsnapshotdata", NULL, 0, &row, &columnMap);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoldsnapshotdata", NULL, 0, &row, &columnMap);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "afterFetch");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_11);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Inserts or updates a model instance. Returning true on success or false
 * otherwise.
 *
 *<code>
 * // Creating a new robot
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * $robot->save();
 *
 * // Updating a robot name
 * $robot = Robots::findFirst("id = 100");
 *
 * $robot->name = "Biomass";
 *
 * $robot->save();
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, save) {

	zend_bool hasDirtyRelated = 0;
	zval metaData, schema, writeConnection, readConnection, source, table, identityField, exists, success, dirtyRelated, _0, _1, _5, _2$$3, _3$$7, _4$$8, _6$$10, _7$$11, _8$$11, _9$$14, _10$$16, _11$$18, _12$$21, _13$$20;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&writeConnection);
	ZVAL_UNDEF(&readConnection);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&identityField);
	ZVAL_UNDEF(&exists);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&dirtyRelated);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_10$$16);
	ZVAL_UNDEF(&_11$$18);
	ZVAL_UNDEF(&_12$$21);
	ZVAL_UNDEF(&_13$$20);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 423);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "prepareSave");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dirtyRelated, &_1);
	hasDirtyRelated = zephir_fast_count_int(&dirtyRelated TSRMLS_CC) > 0;
	if (hasDirtyRelated) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "_presaverelatedrecords", NULL, 0, &writeConnection, &dirtyRelated);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 425);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 426);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 422);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&exists, this_ptr, "_exists", NULL, 0, &metaData, &readConnection, &table);
	zephir_check_call_status();
	if (zephir_is_true(&exists)) {
		ZEPHIR_INIT_ZVAL_NREF(_3$$7);
		ZVAL_LONG(&_3$$7, 2);
		zephir_update_property_zval(this_ptr, SL("operationMade"), &_3$$7);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_4$$8);
		ZVAL_LONG(&_4$$8, 1);
		zephir_update_property_zval(this_ptr, SL("operationMade"), &_4$$8);
	}
	ZEPHIR_INIT_NVAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("errorMessages"), &_0);
	ZEPHIR_CALL_METHOD(&identityField, &metaData, "getidentityfield", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "_presave", NULL, 0, &metaData, &exists, &identityField);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_5)) {
		if (hasDirtyRelated) {
			ZVAL_BOOL(&_6$$10, 0);
			ZEPHIR_CALL_METHOD(NULL, &writeConnection, "rollback", NULL, 0, &_6$$10);
			zephir_check_call_status();
		}
		if (UNEXPECTED(ZEPHIR_GLOBAL(orm).exception_on_failed_save)) {
			ZEPHIR_INIT_VAR(&_7$$11);
			object_init_ex(&_7$$11, phalcon_mvc_model_validationfailed_ce);
			ZEPHIR_CALL_METHOD(&_8$$11, this_ptr, "getmessages", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_7$$11, "__construct", NULL, 431, this_ptr, &_8$$11);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$11, "phalcon/Mvc/Model.zep", 2352 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(0);
	}
	if (zephir_is_true(&exists)) {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "_dolowupdate", NULL, 0, &metaData, &writeConnection, &table);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "_dolowinsert", NULL, 0, &metaData, &writeConnection, &table, &identityField);
		zephir_check_call_status();
	}
	if (zephir_is_true(&success)) {
		ZEPHIR_INIT_ZVAL_NREF(_9$$14);
		ZVAL_LONG(&_9$$14, 0);
		zephir_update_property_zval(this_ptr, SL("dirtyState"), &_9$$14);
	}
	if (hasDirtyRelated) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
			ZVAL_BOOL(&_10$$16, 0);
			ZEPHIR_CALL_METHOD(NULL, &writeConnection, "rollback", NULL, 0, &_10$$16);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&success, this_ptr, "_postsaverelatedrecords", NULL, 0, &writeConnection, &dirtyRelated);
			zephir_check_call_status();
		}
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		ZEPHIR_CALL_METHOD(&_11$$18, this_ptr, "_postsave", NULL, 0, &success, &exists);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&success, &_11$$18);
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
		zephir_check_call_status();
	} else {
		if (hasDirtyRelated) {
			ZEPHIR_INIT_VAR(&_12$$21);
			array_init(&_12$$21);
			zephir_update_property_zval(this_ptr, SL("dirtyRelated"), &_12$$21);
		}
		ZEPHIR_INIT_VAR(&_13$$20);
		ZVAL_STRING(&_13$$20, "afterSave");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_13$$20);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&success);

}

/**
 * Serializes the object ignoring connections, services, related objects or
 * static properties
 */
PHP_METHOD(Phalcon_Mvc_Model, serialize) {

	zval _3$$4;
	zend_bool _2$$3;
	zval attributes, snapshot, manager, _0, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&attributes, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_0, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("snapshot"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&snapshot, &_1$$3);
		_2$$3 = Z_TYPE_P(&snapshot) != IS_NULL;
		if (_2$$3) {
			_2$$3 = !ZEPHIR_IS_EQUAL(&attributes, &snapshot);
		}
		if (_2$$3) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("_attributes"), &attributes, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_3$$4, SL("snapshot"), &snapshot, PH_COPY | PH_SEPARATE);
			ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 23, &_3$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 23, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes the object from a serialized string
 */
PHP_METHOD(Phalcon_Mvc_Model, unserialize) {

	zend_string *_10$$3;
	zend_ulong _9$$3;
	zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, attributes, container, manager, key, value, snapshot, _1$$4, _2$$4, _4$$4, _5$$3, _6$$3, *_8$$3, _7$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_FUNCTION(&attributes, "unserialize", NULL, 24, data);
	zephir_check_call_status();
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "the services related to the ODM");
			ZEPHIR_CALL_CE_STATIC(&_2$$4, phalcon_mvc_model_exception_ce, "containerservicenotfound", &_3, 0, &_4$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 1, &_2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Model.zep", 2473 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval(this_ptr, SL("container"), &container);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "modelsManager");
		ZEPHIR_CALL_METHOD(&_5$$3, &container, "getshared", NULL, 0, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&manager, &_5$$3);
		if (UNEXPECTED(Z_TYPE_P(&manager) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/Mvc/Model.zep", 2489);
			return;
		}
		zephir_update_property_zval(this_ptr, SL("modelsManager"), &manager);
		ZEPHIR_CALL_METHOD(NULL, &manager, "initialize", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$3)) {
			if (zephir_array_isset_string_fetch(&snapshot, &attributes, SL("snapshot"), 1)) {
				zephir_update_property_zval(this_ptr, SL("snapshot"), &snapshot);
				zephir_array_fetch_string(&_7$$7, &attributes, SL("_attributes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2505 TSRMLS_CC);
				ZEPHIR_CPY_WRT(&attributes, &_7$$7);
			} else {
				zephir_update_property_zval(this_ptr, SL("snapshot"), &attributes);
			}
		}
		zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 2517);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _9$$3, _10$$3, _8$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_10$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _10$$3);
			} else {
				ZVAL_LONG(&key, _9$$3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _8$$3);
			zephir_update_property_zval_zval(this_ptr, &key, &value TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjection connection service name
 */
PHP_METHOD(Phalcon_Mvc_Model, setConnectionService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, _0;
	zval connectionService;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connectionService);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
		ZVAL_EMPTY_STRING(&connectionService);
	}


	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setconnectionservice", NULL, 0, this_ptr, &connectionService);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
 */
PHP_METHOD(Phalcon_Mvc_Model, setDirtyState) {

	zval *dirtyState_param = NULL, _0;
	zend_long dirtyState;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &dirtyState_param);

	dirtyState = zephir_get_intval(dirtyState_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, dirtyState);
	zephir_update_property_zval(this_ptr, SL("dirtyState"), &_0);
	RETURN_THISW();

}

/**
 * Sets the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model, setDI) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params(0, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

/**
 * Sets a custom events manager
 */
PHP_METHOD(Phalcon_Mvc_Model, setEventsManager) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventsManager, eventsManager_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventsManager);



	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setcustomeventsmanager", NULL, 0, this_ptr, eventsManager);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjection connection service name used to read data
 */
PHP_METHOD(Phalcon_Mvc_Model, setReadConnectionService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, _0;
	zval connectionService;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connectionService);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
		ZVAL_EMPTY_STRING(&connectionService);
	}


	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setreadconnectionservice", NULL, 0, this_ptr, &connectionService);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets the record's old snapshot data.
 * This method is used internally to set old snapshot data when the model
 * was set up to keep snapshot data
 *
 * @param array data
 * @param array columnMap
 */
PHP_METHOD(Phalcon_Mvc_Model, setOldSnapshotData) {

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, attribute, *_0$$3, _3$$7, _4$$7, _6$$10, _7$$10;
	zval data, snapshot;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &columnMap);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!columnMap) {
		columnMap = &columnMap_sub;
		columnMap = &__$null;
	}


	if (Z_TYPE_P(columnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&snapshot);
		array_init(&snapshot);
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 2626);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _2$$3);
			} else {
				ZVAL_LONG(&key, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0$$3);
			if (Z_TYPE_P(&key) != IS_STRING) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&attribute);
			if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0 TSRMLS_CC))) {
				if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
					ZEPHIR_INIT_NVAR(&_3$$7);
					object_init_ex(&_3$$7, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4$$7);
					ZEPHIR_CONCAT_SVS(&_4$$7, "Column '", &key, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_3$$7, "__construct", &_5, 1, &_4$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_3$$7, "phalcon/Mvc/Model.zep", 2606 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				continue;
			}
			if (Z_TYPE_P(&attribute) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0 TSRMLS_CC))) {
					if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
						ZEPHIR_INIT_NVAR(&_6$$10);
						object_init_ex(&_6$$10, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_7$$10);
						ZEPHIR_CONCAT_SVS(&_7$$10, "Column '", &key, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_6$$10, "__construct", &_5, 1, &_7$$10);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_6$$10, "phalcon/Mvc/Model.zep", 2617 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
			}
			zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_CPY_WRT(&snapshot, &data);
	}
	zephir_update_property_zval(this_ptr, SL("oldSnapshot"), &snapshot);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the record's snapshot data.
 * This method is used internally to set snapshot data when the model was
 * set up to keep snapshot data
 *
 * @param array columnMap
 */
PHP_METHOD(Phalcon_Mvc_Model, setSnapshotData) {

	zend_bool _3$$4;
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, attribute, *_0$$3, _4$$6, _6$$8, _7$$8, _9$$11, _10$$11;
	zval data, snapshot;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &columnMap);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!columnMap) {
		columnMap = &columnMap_sub;
		columnMap = &__$null;
	}


	if (Z_TYPE_P(columnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&snapshot);
		array_init(&snapshot);
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 2691);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _2$$3);
			} else {
				ZVAL_LONG(&key, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0$$3);
			if (Z_TYPE_P(&key) != IS_STRING) {
				continue;
			}
			_3$$4 = !(zephir_array_isset(columnMap, &key));
			if (_3$$4) {
				_3$$4 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
			}
			if (_3$$4) {
				ZEPHIR_CALL_SELF(&_4$$6, "caseinsensitivecolumnmap", &_5, 420, columnMap, &key);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&key, &_4$$6);
			}
			ZEPHIR_OBS_NVAR(&attribute);
			if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0 TSRMLS_CC))) {
				if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
					ZEPHIR_INIT_NVAR(&_6$$8);
					object_init_ex(&_6$$8, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_7$$8);
					ZEPHIR_CONCAT_SVS(&_7$$8, "Column '", &key, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_6$$8, "__construct", &_8, 1, &_7$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_6$$8, "phalcon/Mvc/Model.zep", 2671 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				continue;
			}
			if (Z_TYPE_P(&attribute) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0 TSRMLS_CC))) {
					if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
						ZEPHIR_INIT_NVAR(&_9$$11);
						object_init_ex(&_9$$11, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_10$$11);
						ZEPHIR_CONCAT_SVS(&_10$$11, "Column '", &key, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_9$$11, "__construct", &_8, 1, &_10$$11);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_9$$11, "phalcon/Mvc/Model.zep", 2682 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
			}
			zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_CPY_WRT(&snapshot, &data);
	}
	zephir_update_property_zval(this_ptr, SL("snapshot"), &snapshot);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a transaction related to the Model instance
 *
 *<code>
 * use Phalcon\Mvc\Model\Transaction\Manager as TxManager;
 * use Phalcon\Mvc\Model\Transaction\Failed as TxFailed;
 *
 * try {
 *     $txManager = new TxManager();
 *
 *     $transaction = $txManager->get();
 *
 *     $robot = new Robots();
 *
 *     $robot->setTransaction($transaction);
 *
 *     $robot->name       = "WALL·E";
 *     $robot->created_at = date("Y-m-d");
 *
 *     if ($robot->save() === false) {
 *         $transaction->rollback("Can't save robot");
 *     }
 *
 *     $robotPart = new RobotParts();
 *
 *     $robotPart->setTransaction($transaction);
 *
 *     $robotPart->type = "head";
 *
 *     if ($robotPart->save() === false) {
 *         $transaction->rollback("Robot part cannot be saved");
 *     }
 *
 *     $transaction->commit();
 * } catch (TxFailed $e) {
 *     echo "Failed, reason: ", $e->getMessage();
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, setTransaction) {

	zval *transaction, transaction_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transaction_sub);

	zephir_fetch_params(0, 1, 0, &transaction);



	zephir_update_property_zval(this_ptr, SL("transaction"), transaction);
	RETURN_THISW();

}

/**
 * Enables/disables options in the ORM
 */
PHP_METHOD(Phalcon_Mvc_Model, setup) {

	zval *options_param = NULL, disableEvents, columnRenaming, notNullValidations, exceptionOnFailedSave, phqlLiterals, virtualForeignKeys, lateStateBinding, castOnHydrate, ignoreUnknownColumns, updateSnapshotOnSave, disableAssignSetters, caseInsensitiveColumnMap, prefetchRecords, lastInsertId;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&disableEvents);
	ZVAL_UNDEF(&columnRenaming);
	ZVAL_UNDEF(&notNullValidations);
	ZVAL_UNDEF(&exceptionOnFailedSave);
	ZVAL_UNDEF(&phqlLiterals);
	ZVAL_UNDEF(&virtualForeignKeys);
	ZVAL_UNDEF(&lateStateBinding);
	ZVAL_UNDEF(&castOnHydrate);
	ZVAL_UNDEF(&ignoreUnknownColumns);
	ZVAL_UNDEF(&updateSnapshotOnSave);
	ZVAL_UNDEF(&disableAssignSetters);
	ZVAL_UNDEF(&caseInsensitiveColumnMap);
	ZVAL_UNDEF(&prefetchRecords);
	ZVAL_UNDEF(&lastInsertId);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	ZEPHIR_OBS_VAR(&disableEvents);
	if (zephir_array_isset_string_fetch(&disableEvents, &options, SL("events"), 0)) {
		ZEPHIR_GLOBAL(orm).events = zend_is_true(&disableEvents);
	}
	ZEPHIR_OBS_VAR(&virtualForeignKeys);
	if (zephir_array_isset_string_fetch(&virtualForeignKeys, &options, SL("virtualForeignKeys"), 0)) {
		ZEPHIR_GLOBAL(orm).virtual_foreign_keys = zend_is_true(&virtualForeignKeys);
	}
	ZEPHIR_OBS_VAR(&columnRenaming);
	if (zephir_array_isset_string_fetch(&columnRenaming, &options, SL("columnRenaming"), 0)) {
		ZEPHIR_GLOBAL(orm).column_renaming = zend_is_true(&columnRenaming);
	}
	ZEPHIR_OBS_VAR(&notNullValidations);
	if (zephir_array_isset_string_fetch(&notNullValidations, &options, SL("notNullValidations"), 0)) {
		ZEPHIR_GLOBAL(orm).not_null_validations = zend_is_true(&notNullValidations);
	}
	ZEPHIR_OBS_VAR(&exceptionOnFailedSave);
	if (zephir_array_isset_string_fetch(&exceptionOnFailedSave, &options, SL("exceptionOnFailedSave"), 0)) {
		ZEPHIR_GLOBAL(orm).exception_on_failed_save = zend_is_true(&exceptionOnFailedSave);
	}
	ZEPHIR_OBS_VAR(&phqlLiterals);
	if (zephir_array_isset_string_fetch(&phqlLiterals, &options, SL("phqlLiterals"), 0)) {
		ZEPHIR_GLOBAL(orm).enable_literals = zend_is_true(&phqlLiterals);
	}
	ZEPHIR_OBS_VAR(&lateStateBinding);
	if (zephir_array_isset_string_fetch(&lateStateBinding, &options, SL("lateStateBinding"), 0)) {
		ZEPHIR_GLOBAL(orm).late_state_binding = zend_is_true(&lateStateBinding);
	}
	ZEPHIR_OBS_VAR(&castOnHydrate);
	if (zephir_array_isset_string_fetch(&castOnHydrate, &options, SL("castOnHydrate"), 0)) {
		ZEPHIR_GLOBAL(orm).cast_on_hydrate = zend_is_true(&castOnHydrate);
	}
	ZEPHIR_OBS_VAR(&ignoreUnknownColumns);
	if (zephir_array_isset_string_fetch(&ignoreUnknownColumns, &options, SL("ignoreUnknownColumns"), 0)) {
		ZEPHIR_GLOBAL(orm).ignore_unknown_columns = zend_is_true(&ignoreUnknownColumns);
	}
	ZEPHIR_OBS_VAR(&caseInsensitiveColumnMap);
	if (zephir_array_isset_string_fetch(&caseInsensitiveColumnMap, &options, SL("caseInsensitiveColumnMap"), 0)) {
		ZEPHIR_GLOBAL(orm).case_insensitive_column_map = zend_is_true(&caseInsensitiveColumnMap);
	}
	ZEPHIR_OBS_VAR(&updateSnapshotOnSave);
	if (zephir_array_isset_string_fetch(&updateSnapshotOnSave, &options, SL("updateSnapshotOnSave"), 0)) {
		ZEPHIR_GLOBAL(orm).update_snapshot_on_save = zend_is_true(&updateSnapshotOnSave);
	}
	ZEPHIR_OBS_VAR(&disableAssignSetters);
	if (zephir_array_isset_string_fetch(&disableAssignSetters, &options, SL("disableAssignSetters"), 0)) {
		ZEPHIR_GLOBAL(orm).disable_assign_setters = zend_is_true(&disableAssignSetters);
	}
	ZEPHIR_OBS_VAR(&prefetchRecords);
	if (zephir_array_isset_string_fetch(&prefetchRecords, &options, SL("prefetchRecords"), 0)) {
		ZEPHIR_GLOBAL(orm).resultset_prefetch_records = Z_LVAL_P(&prefetchRecords);
	}
	ZEPHIR_OBS_VAR(&lastInsertId);
	if (zephir_array_isset_string_fetch(&lastInsertId, &options, SL("castLastInsertIdToInt"), 0)) {
		ZEPHIR_GLOBAL(orm).cast_last_insert_id_to_int = zend_is_true(&lastInsertId);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjection connection service name used to write data
 */
PHP_METHOD(Phalcon_Mvc_Model, setWriteConnectionService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, _0;
	zval connectionService;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connectionService);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
		ZVAL_EMPTY_STRING(&connectionService);
	}


	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "setwriteconnectionservice", NULL, 0, this_ptr, &connectionService);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Skips the current operation forcing a success state
 */
PHP_METHOD(Phalcon_Mvc_Model, skipOperation) {

	zval *skip_param = NULL, __$true, __$false;
	zend_bool skip;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &skip_param);

	skip = zephir_get_boolval(skip_param);


	if (skip) {
		zephir_update_property_zval(this_ptr, SL("skipped"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("skipped"), &__$false);
	}

}

/**
 * Calculates the sum on a column for a result-set of rows that match the
 * specified conditions
 *
 * <code>
 * // How much are all robots?
 * $sum = Robots::sum(
 *     [
 *         "column" => "price",
 *     ]
 * );
 *
 * echo "The total price of robots is ", $sum, "\n";
 *
 * // How much are mechanical robots?
 * $sum = Robots::sum(
 *     [
 *         "type = 'mechanical'",
 *         "column" => "price",
 *     ]
 * );
 *
 * echo "The total price of mechanical robots is  ", $sum, "\n";
 * </code>
 *
 * @param array parameters
 * @return double
 */
PHP_METHOD(Phalcon_Mvc_Model, sum) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "SUM");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "sumatory");
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, 0, &_0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the instance as an array representation
 *
 *<code>
 * print_r(
 *     $robot->toArray()
 * );
 *</code>
 *
 * @param array $columns
 */
PHP_METHOD(Phalcon_Mvc_Model, toArray) {

	zend_bool _2$$4;
	zval data;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columns = NULL, columns_sub, __$null, metaData, columnMap, attribute, attributeField, value, _0, *_1, _3$$5, _5$$7, _6$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &columns);

	if (!columns) {
		columns = &columns_sub;
		columns = &__$null;
	}


	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Mvc/Model.zep", 2956);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&attribute);
		ZVAL_COPY(&attribute, _1);
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			_2$$4 = !(zephir_array_isset(&columnMap, &attribute));
			if (_2$$4) {
				_2$$4 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
			}
			if (_2$$4) {
				ZEPHIR_CALL_SELF(&_3$$5, "caseinsensitivecolumnmap", &_4, 420, &columnMap, &attribute);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&attribute, &_3$$5);
			}
			ZEPHIR_OBS_NVAR(&attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0 TSRMLS_CC))) {
				if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
					ZEPHIR_INIT_NVAR(&_5$$7);
					object_init_ex(&_5$$7, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_6$$7);
					ZEPHIR_CONCAT_SVS(&_6$$7, "Column '", &attribute, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", &_7, 1, &_6$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_5$$7, "phalcon/Mvc/Model.zep", 2934 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				continue;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, &attribute);
		}
		if (Z_TYPE_P(columns) == IS_ARRAY) {
			if (!(zephir_fast_in_array(&attributeField, columns TSRMLS_CC))) {
				continue;
			}
		}
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
			zephir_array_update_zval(&data, &attributeField, &value, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&data, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&attribute);
	RETURN_CTOR(&data);

}

/**
 * Updates a model instance. If the instance doesn't exist in the
 * persistence it will throw an exception. Returning true on success or
 * false otherwise.
 *
 *<code>
 * // Updating a robot name
 * $robot = Robots::findFirst("id = 100");
 *
 * $robot->name = "Biomass";
 *
 * $robot->update();
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, update) {

	zval _3$$4;
	zval metaData, _0, _1$$3, _2$$3, _4$$4, _5$$4, _6$$4, _7$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getreadconnection", NULL, 422);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "_exists", NULL, 0, &metaData, &_2$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(&_1$$3))) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_4$$4);
			object_init_ex(&_4$$4, phalcon_messages_message_ce);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "Record cannot be updated because it does not exist");
			ZVAL_NULL(&_6$$4);
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "InvalidUpdateAttempt");
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 404, &_5$$4, &_6$$4, &_7$$4);
			zephir_check_call_status();
			zephir_array_fast_append(&_3$$4, &_4$$4);
			zephir_update_property_zval(this_ptr, SL("errorMessages"), &_3$$4);
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "save", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Writes an attribute value by its name
 *
 *<code>
 * $robot->writeAttribute("name", "Rosey");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, writeAttribute) {

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

/**
 * Reads "belongs to" relations and check the virtual foreign keys when
 * inserting or updating records to verify that inserted/updated values are
 * present in the related entity
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysRestrict) {

	zend_string *_7$$7;
	zend_ulong _6$$7;
	zend_bool error = 0, validateWithNulls = 0, _11$$3;
	zval conditions, _13$$3;
	zval manager, belongsTo, foreignKey, relation, position, bindParams, extraConditions, message, fields, referencedFields, field, referencedModel, value, allowNulls, _0, *_1, _2$$5, _3$$3, _12$$3, _14$$3, *_5$$7, _8$$8, _9$$8, _10$$10, _15$$18, _16$$16, _17$$16, _20$$21;
	zephir_fcall_cache_entry *_4 = NULL, *_18 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, action = 0, numberNull = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&belongsTo);
	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&extraConditions);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&allowNulls);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_20$$21);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_13$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&belongsTo, &manager, "getbelongsto", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	zephir_is_iterable(&belongsTo, 0, "phalcon/Mvc/Model.zep", 3163);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&belongsTo), _1)
	{
		ZEPHIR_INIT_NVAR(&relation);
		ZVAL_COPY(&relation, _1);
		validateWithNulls = 0;
		ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
			continue;
		}
		action = 1;
		if (zephir_array_isset_string(&foreignKey, SL("action"))) {
			ZEPHIR_OBS_NVAR(&_2$$5);
			zephir_array_fetch_string(&_2$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3058 TSRMLS_CC);
			action = zephir_get_intval(&_2$$5);
		}
		if (action != 1) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&_3$$3, &relation, "getreferencedmodel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_4, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&conditions);
		array_init(&conditions);
		ZEPHIR_INIT_NVAR(&bindParams);
		array_init(&bindParams);
		numberNull = 0;
		ZEPHIR_CALL_METHOD(&fields, &relation, "getfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&fields) == IS_ARRAY) {
			zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model.zep", 3101);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _6$$7, _7$$7, _5$$7)
			{
				ZEPHIR_INIT_NVAR(&position);
				if (_7$$7 != NULL) { 
					ZVAL_STR_COPY(&position, _7$$7);
				} else {
					ZVAL_LONG(&position, _6$$7);
				}
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _5$$7);
				ZEPHIR_OBS_NVAR(&value);
				zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
				zephir_array_fetch(&_8$$8, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3093 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_9$$8);
				ZEPHIR_CONCAT_SVSV(&_9$$8, "[", &_8$$8, "] = ?", &position);
				zephir_array_append(&conditions, &_9$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3093);
				zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3094);
				if (Z_TYPE_P(&value) == IS_NULL) {
					numberNull++;
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&field);
			ZEPHIR_INIT_NVAR(&position);
			validateWithNulls = numberNull == zephir_fast_count_int(&fields TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(&value);
			zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
			ZEPHIR_INIT_LNVAR(_10$$10);
			ZEPHIR_CONCAT_SVS(&_10$$10, "[", &referencedFields, "] = ?0");
			zephir_array_append(&conditions, &_10$$10, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3105);
			zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3106);
			if (Z_TYPE_P(&value) == IS_NULL) {
				validateWithNulls = 1;
			}
		}
		ZEPHIR_OBS_NVAR(&extraConditions);
		if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
			zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3117);
		}
		if (validateWithNulls) {
			ZEPHIR_OBS_NVAR(&allowNulls);
			if (zephir_array_isset_string_fetch(&allowNulls, &foreignKey, SL("allowNulls"), 0)) {
				validateWithNulls = zephir_get_boolval(&allowNulls);
			} else {
				validateWithNulls = 0;
			}
		}
		_11$$3 = !validateWithNulls;
		if (_11$$3) {
			ZEPHIR_INIT_NVAR(&_13$$3);
			zephir_create_array(&_13$$3, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_14$$3);
			zephir_fast_join_str(&_14$$3, SL(" AND "), &conditions TSRMLS_CC);
			zephir_array_fast_append(&_13$$3, &_14$$3);
			zephir_array_update_string(&_13$$3, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_12$$3, &referencedModel, "count", NULL, 0, &_13$$3);
			zephir_check_call_status();
			_11$$3 = !zephir_is_true(&_12$$3);
		}
		if (_11$$3) {
			ZEPHIR_OBS_NVAR(&message);
			if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
				ZEPHIR_INIT_NVAR(&message);
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_15$$18);
					zephir_fast_join_str(&_15$$18, SL(", "), &fields TSRMLS_CC);
					ZEPHIR_CONCAT_SVS(&message, "Value of fields \"", &_15$$18, "\" does not exist on referenced table");
				} else {
					ZEPHIR_CONCAT_SVS(&message, "Value of field \"", &fields, "\" does not exist on referenced table");
				}
			}
			ZEPHIR_INIT_NVAR(&_16$$16);
			object_init_ex(&_16$$16, phalcon_messages_message_ce);
			ZEPHIR_INIT_NVAR(&_17$$16);
			ZVAL_STRING(&_17$$16, "ConstraintViolation");
			ZEPHIR_CALL_METHOD(NULL, &_16$$16, "__construct", &_18, 404, &message, &fields, &_17$$16);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_19, 0, &_16$$16);
			zephir_check_call_status();
			error = 1;
			break;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&relation);
	if (error) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_VAR(&_20$$21);
			ZVAL_STRING(&_20$$21, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_20$$21);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual
 * foreign keys (cascade) when deleting records
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseCascade) {

	zend_string *_8$$7;
	zend_ulong _7$$7;
	zval _12$$3;
	zend_bool _2$$3;
	zval manager, relations, relation, foreignKey, resultset, conditions, bindParams, referencedModel, referencedFields, fields, field, position, value, extraConditions, _0, *_1, _4$$3, _13$$3, _14$$3, _3$$5, *_6$$7, _9$$8, _10$$8, _11$$9;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, action = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&extraConditions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&relations, 0, "phalcon/Mvc/Model.zep", 3283);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relations), _1)
	{
		ZEPHIR_INIT_NVAR(&relation);
		ZVAL_COPY(&relation, _1);
		ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
			continue;
		}
		action = 0;
		_2$$3 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
		if (_2$$3) {
			_2$$3 = zephir_array_isset_string(&foreignKey, SL("action"));
		}
		if (_2$$3) {
			ZEPHIR_OBS_NVAR(&_3$$5);
			zephir_array_fetch_string(&_3$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3215 TSRMLS_CC);
			action = zephir_get_intval(&_3$$5);
		}
		if (action != 2) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&_4$$3, &relation, "getreferencedmodel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_5, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&fields, &relation, "getfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&conditions);
		array_init(&conditions);
		ZEPHIR_INIT_NVAR(&bindParams);
		array_init(&bindParams);
		if (Z_TYPE_P(&fields) == IS_ARRAY) {
			zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model.zep", 3248);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _7$$7, _8$$7, _6$$7)
			{
				ZEPHIR_INIT_NVAR(&position);
				if (_8$$7 != NULL) { 
					ZVAL_STR_COPY(&position, _8$$7);
				} else {
					ZVAL_LONG(&position, _7$$7);
				}
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _6$$7);
				ZEPHIR_OBS_NVAR(&value);
				zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
				zephir_array_fetch(&_9$$8, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3245 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_10$$8);
				ZEPHIR_CONCAT_SVSV(&_10$$8, "[", &_9$$8, "] = ?", &position);
				zephir_array_append(&conditions, &_10$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3245);
				zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3246);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&field);
			ZEPHIR_INIT_NVAR(&position);
		} else {
			ZEPHIR_OBS_NVAR(&value);
			zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
			ZEPHIR_INIT_LNVAR(_11$$9);
			ZEPHIR_CONCAT_SVS(&_11$$9, "[", &referencedFields, "] = ?0");
			zephir_array_append(&conditions, &_11$$9, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3251);
			zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3252);
		}
		ZEPHIR_OBS_NVAR(&extraConditions);
		if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
			zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3259);
		}
		ZEPHIR_INIT_NVAR(&_12$$3);
		zephir_create_array(&_12$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_13$$3);
		zephir_fast_join_str(&_13$$3, SL(" AND "), &conditions TSRMLS_CC);
		zephir_array_fast_append(&_12$$3, &_13$$3);
		zephir_array_update_string(&_12$$3, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&resultset, &referencedModel, "find", NULL, 0, &_12$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_14$$3, &resultset, "delete", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_14$$3)) {
			RETURN_MM_BOOL(0);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&relation);
	RETURN_MM_BOOL(1);

}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual
 * foreign keys (restrict) when deleting records
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseRestrict) {

	zend_string *_7$$7;
	zend_ulong _6$$7;
	zval _12$$3;
	zval manager, relations, foreignKey, relation, relationClass, referencedModel, fields, referencedFields, conditions, bindParams, position, field, value, extraConditions, message, _0, *_1, _11$$3, _13$$3, _3$$5, *_5$$7, _8$$8, _9$$8, _10$$9, _14$$11, _15$$11, _18$$14;
	zend_bool error = 0, _2$$3;
	zephir_fcall_cache_entry *_4 = NULL, *_16 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, action = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&relationClass);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&extraConditions);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_12$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	zephir_is_iterable(&relations, 0, "phalcon/Mvc/Model.zep", 3406);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relations), _1)
	{
		ZEPHIR_INIT_NVAR(&relation);
		ZVAL_COPY(&relation, _1);
		ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
			continue;
		}
		action = 1;
		_2$$3 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
		if (_2$$3) {
			_2$$3 = zephir_array_isset_string(&foreignKey, SL("action"));
		}
		if (_2$$3) {
			ZEPHIR_OBS_NVAR(&_3$$5);
			zephir_array_fetch_string(&_3$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3329 TSRMLS_CC);
			action = zephir_get_intval(&_3$$5);
		}
		if (action != 1) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&relationClass, &relation, "getreferencedmodel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_4, 0, &relationClass);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&fields, &relation, "getfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&conditions);
		array_init(&conditions);
		ZEPHIR_INIT_NVAR(&bindParams);
		array_init(&bindParams);
		if (Z_TYPE_P(&fields) == IS_ARRAY) {
			zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model.zep", 3363);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _6$$7, _7$$7, _5$$7)
			{
				ZEPHIR_INIT_NVAR(&position);
				if (_7$$7 != NULL) { 
					ZVAL_STR_COPY(&position, _7$$7);
				} else {
					ZVAL_LONG(&position, _6$$7);
				}
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _5$$7);
				ZEPHIR_OBS_NVAR(&value);
				zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
				zephir_array_fetch(&_8$$8, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3360 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_9$$8);
				ZEPHIR_CONCAT_SVSV(&_9$$8, "[", &_8$$8, "] = ?", &position);
				zephir_array_append(&conditions, &_9$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3360);
				zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3361);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&field);
			ZEPHIR_INIT_NVAR(&position);
		} else {
			ZEPHIR_OBS_NVAR(&value);
			zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
			ZEPHIR_INIT_LNVAR(_10$$9);
			ZEPHIR_CONCAT_SVS(&_10$$9, "[", &referencedFields, "] = ?0");
			zephir_array_append(&conditions, &_10$$9, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3366);
			zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3367);
		}
		ZEPHIR_OBS_NVAR(&extraConditions);
		if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
			zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3374);
		}
		ZEPHIR_INIT_NVAR(&_12$$3);
		zephir_create_array(&_12$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_13$$3);
		zephir_fast_join_str(&_13$$3, SL(" AND "), &conditions TSRMLS_CC);
		zephir_array_fast_append(&_12$$3, &_13$$3);
		zephir_array_update_string(&_12$$3, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_11$$3, &referencedModel, "count", NULL, 0, &_12$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_11$$3)) {
			ZEPHIR_OBS_NVAR(&message);
			if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
				ZEPHIR_INIT_NVAR(&message);
				ZEPHIR_CONCAT_SV(&message, "Record is referenced by model ", &relationClass);
			}
			ZEPHIR_INIT_NVAR(&_14$$11);
			object_init_ex(&_14$$11, phalcon_messages_message_ce);
			ZEPHIR_INIT_NVAR(&_15$$11);
			ZVAL_STRING(&_15$$11, "ConstraintViolation");
			ZEPHIR_CALL_METHOD(NULL, &_14$$11, "__construct", &_16, 404, &message, &fields, &_15$$11);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_17, 0, &_14$$11);
			zephir_check_call_status();
			error = 1;
			break;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&relation);
	if (error) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_VAR(&_18$$14);
			ZVAL_STRING(&_18$$14, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_18$$14);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Sends a pre-build INSERT SQL statement to the relational database system
 *
 * @param string|array table
 * @param bool|string identityField
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowInsert) {

	zend_string *_27$$38;
	zend_ulong _26$$38;
	zend_bool useExplicitIdentity = 0, _21, _5$$11, _18$$23, _29$$38;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table, table_sub, *identityField, identityField_sub, __$null, bindSkip, fields, values, bindTypes, attributes, bindDataTypes, automaticAttributes, field, columnMap, value, attributeField, success, bindType, defaultValue, sequenceName, defaultValues, unsetDefaultValues, source, schema, snapshot, lastInsertedId, manager, _0, *_1, _2$$7, _3$$7, _7$$12, _8$$12, _9$$14, _10$$14, _11$$16, _13$$16, _14$$16, _15$$18, _16$$21, _17$$21, _19$$28, _20$$28, _22$$31, _23$$37, _24$$37, *_25$$38, _28$$38;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData_sub);
	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&identityField_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&bindSkip);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&automaticAttributes);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&sequenceName);
	ZVAL_UNDEF(&defaultValues);
	ZVAL_UNDEF(&unsetDefaultValues);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&lastInsertedId);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_11$$16);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_16$$21);
	ZVAL_UNDEF(&_17$$21);
	ZVAL_UNDEF(&_19$$28);
	ZVAL_UNDEF(&_20$$28);
	ZVAL_UNDEF(&_22$$31);
	ZVAL_UNDEF(&_23$$37);
	ZVAL_UNDEF(&_24$$37);
	ZVAL_UNDEF(&_28$$38);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &metaData, &connection, &table, &identityField);



	ZEPHIR_INIT_VAR(&bindSkip);
	ZVAL_LONG(&bindSkip, 1024);
	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&snapshot);
	array_init(&snapshot);
	ZEPHIR_INIT_VAR(&bindTypes);
	array_init(&bindTypes);
	ZEPHIR_INIT_VAR(&unsetDefaultValues);
	array_init(&unsetDefaultValues);
	ZEPHIR_CALL_METHOD(&attributes, metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticcreateattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&defaultValues, metaData, "getdefaultvalues", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 3523);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _1)
	{
		ZEPHIR_INIT_NVAR(&field);
		ZVAL_COPY(&field, _1);
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC)))) {
				ZEPHIR_INIT_NVAR(&_2$$7);
				object_init_ex(&_2$$7, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_3$$7);
				ZEPHIR_CONCAT_SVS(&_3$$7, "Column '", &field, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, &_2$$7, "__construct", &_4, 1, &_3$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_2$$7, "phalcon/Mvc/Model.zep", 3465 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, &field);
		}
		if (!(zephir_array_isset(&automaticAttributes, &attributeField))) {
			if (!ZEPHIR_IS_EQUAL(&field, identityField)) {
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
					_5$$11 = Z_TYPE_P(&value) == IS_NULL;
					if (_5$$11) {
						_5$$11 = zephir_array_isset(&defaultValues, &field);
					}
					if (_5$$11) {
						ZEPHIR_CALL_METHOD(&value, connection, "getdefaultvalue", &_6, 0);
						zephir_check_call_status();
						zephir_array_fetch(&_7$$12, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3484 TSRMLS_CC);
						zephir_array_update_zval(&snapshot, &attributeField, &_7$$12, PH_COPY | PH_SEPARATE);
						zephir_array_fetch(&_8$$12, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3485 TSRMLS_CC);
						zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_8$$12, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(&bindType);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0 TSRMLS_CC)))) {
						ZEPHIR_INIT_NVAR(&_9$$14);
						object_init_ex(&_9$$14, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_10$$14);
						ZEPHIR_CONCAT_SVS(&_10$$14, "Column '", &field, "' have not defined a bind data type");
						ZEPHIR_CALL_METHOD(NULL, &_9$$14, "__construct", &_4, 1, &_10$$14);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_9$$14, "phalcon/Mvc/Model.zep", 3496 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3499);
					zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3500);
					zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3501);
				} else {
					if (zephir_array_isset(&defaultValues, &field)) {
						ZEPHIR_CALL_METHOD(&_11$$16, connection, "getdefaultvalue", &_12, 0);
						zephir_check_call_status();
						zephir_array_append(&values, &_11$$16, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3504);
						zephir_array_fetch(&_13$$16, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3506 TSRMLS_CC);
						zephir_array_update_zval(&snapshot, &attributeField, &_13$$16, PH_COPY | PH_SEPARATE);
						zephir_array_fetch(&_14$$16, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3507 TSRMLS_CC);
						zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_14$$16, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3509);
						zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
					}
					zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3513);
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3514);
				}
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&field);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(identityField)) {
		ZEPHIR_CALL_METHOD(&defaultValue, connection, "getdefaultidvalue", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_15$$18, connection, "useexplicitidvalue", NULL, 0);
		zephir_check_call_status();
		useExplicitIdentity = zephir_get_boolval(&_15$$18);
		if (useExplicitIdentity) {
			zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3533);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, identityField, 0 TSRMLS_CC)))) {
				ZEPHIR_INIT_VAR(&_16$$21);
				object_init_ex(&_16$$21, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_17$$21);
				ZEPHIR_CONCAT_SVS(&_17$$21, "Identity column '", identityField, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, &_16$$21, "__construct", &_4, 1, &_17$$21);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_16$$21, "phalcon/Mvc/Model.zep", 3543 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, identityField);
		}
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
			_18$$23 = Z_TYPE_P(&value) == IS_NULL;
			if (!(_18$$23)) {
				_18$$23 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
			}
			if (_18$$23) {
				if (useExplicitIdentity) {
					zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3555);
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3555);
				}
			} else {
				if (!(useExplicitIdentity)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3563);
				}
				ZEPHIR_OBS_NVAR(&bindType);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, identityField, 0 TSRMLS_CC)))) {
					ZEPHIR_INIT_VAR(&_19$$28);
					object_init_ex(&_19$$28, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_VAR(&_20$$28);
					ZEPHIR_CONCAT_SVS(&_20$$28, "Identity column '", identityField, "' isn\\'t part of the table columns");
					ZEPHIR_CALL_METHOD(NULL, &_19$$28, "__construct", &_4, 1, &_20$$28);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_19$$28, "phalcon/Mvc/Model.zep", 3572 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3575);
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3576);
			}
		} else {
			if (useExplicitIdentity) {
				zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3580);
				zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3581);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&success, connection, "insert", NULL, 0, table, &values, &fields, &bindTypes);
	zephir_check_call_status();
	_21 = zephir_is_true(&success);
	if (_21) {
		_21 = !ZEPHIR_IS_FALSE_IDENTICAL(identityField);
	}
	if (_21) {
		ZEPHIR_INIT_VAR(&sequenceName);
		ZVAL_NULL(&sequenceName);
		ZEPHIR_CALL_METHOD(&_22$$31, connection, "supportsequences", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_22$$31)) {
			if ((zephir_method_exists_ex(this_ptr, SL("getsequencename") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&sequenceName, this_ptr, "getsequencename", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 426);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 425);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&sequenceName);
				if (ZEPHIR_IS_EMPTY(&schema)) {
					ZEPHIR_CONCAT_VSVS(&sequenceName, &source, "_", identityField, "_seq");
				} else {
					ZEPHIR_CONCAT_VSVSVS(&sequenceName, &schema, ".", &source, "_", identityField, "_seq");
				}
			}
		}
		ZEPHIR_CALL_METHOD(&lastInsertedId, connection, "lastinsertid", NULL, 0, &sequenceName);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_GLOBAL(orm).cast_last_insert_id_to_int)) {
			ZVAL_LONG(&_23$$37, 10);
			ZEPHIR_CALL_FUNCTION(&_24$$37, "intval", NULL, 26, &lastInsertedId, &_23$$37);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&lastInsertedId, &_24$$37);
		}
		zephir_update_property_zval_zval(this_ptr, &attributeField, &lastInsertedId TSRMLS_CC);
		zephir_array_update_zval(&snapshot, &attributeField, &lastInsertedId, PH_COPY | PH_SEPARATE);
		zephir_update_property_zval(this_ptr, SL("uniqueParams"), &__$null);
	}
	if (zephir_is_true(&success)) {
		zephir_is_iterable(&unsetDefaultValues, 0, "phalcon/Mvc/Model.zep", 3644);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&unsetDefaultValues), _26$$38, _27$$38, _25$$38)
		{
			ZEPHIR_INIT_NVAR(&attributeField);
			if (_27$$38 != NULL) { 
				ZVAL_STR_COPY(&attributeField, _27$$38);
			} else {
				ZVAL_LONG(&attributeField, _26$$38);
			}
			ZEPHIR_INIT_NVAR(&defaultValue);
			ZVAL_COPY(&defaultValue, _25$$38);
			zephir_update_property_zval_zval(this_ptr, &attributeField, &defaultValue TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&defaultValue);
		ZEPHIR_INIT_NVAR(&attributeField);
		ZEPHIR_CALL_METHOD(&_28$$38, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_29$$38 = zephir_is_true(&_28$$38);
		if (_29$$38) {
			_29$$38 = ZEPHIR_GLOBAL(orm).update_snapshot_on_save;
		}
		if (_29$$38) {
			zephir_update_property_zval(this_ptr, SL("snapshot"), &snapshot);
		}
	}
	RETURN_CCTOR(&success);

}

/**
 * Sends a pre-build UPDATE SQL statement to the relational database system
 *
 * @param string|array table
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowUpdate) {

	zval _13$$25, _14$$25;
	zval _18;
	zend_bool useDynamicUpdate = 0, changed = 0, _19, _20;
	zephir_fcall_cache_entry *_5 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table, table_sub, __$null, bindSkip, fields, values, dataType, dataTypes, bindTypes, manager, bindDataTypes, field, automaticAttributes, snapshotValue, uniqueKey, uniqueParams, uniqueTypes, snapshot, nonPrimary, columnMap, attributeField, value, primaryKeys, bindType, newSnapshot, success, _0, _1, *_2, _3$$9, _4$$9, _6$$12, _7$$12, _8$$22, _9$$22, _10$$24, _12$$24, *_15$$31, _16$$35, _17$$35, _21$$40, _22$$41;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData_sub);
	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&table_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&bindSkip);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&dataType);
	ZVAL_UNDEF(&dataTypes);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&automaticAttributes);
	ZVAL_UNDEF(&snapshotValue);
	ZVAL_UNDEF(&uniqueKey);
	ZVAL_UNDEF(&uniqueParams);
	ZVAL_UNDEF(&uniqueTypes);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&nonPrimary);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&newSnapshot);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_6$$12);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_8$$22);
	ZVAL_UNDEF(&_9$$22);
	ZVAL_UNDEF(&_10$$24);
	ZVAL_UNDEF(&_12$$24);
	ZVAL_UNDEF(&_16$$35);
	ZVAL_UNDEF(&_17$$35);
	ZVAL_UNDEF(&_21$$40);
	ZVAL_UNDEF(&_22$$41);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_13$$25);
	ZVAL_UNDEF(&_14$$25);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &metaData, &connection, &table);



	ZEPHIR_INIT_VAR(&bindSkip);
	ZVAL_LONG(&bindSkip, 1024);
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&bindTypes);
	array_init(&bindTypes);
	ZEPHIR_INIT_VAR(&newSnapshot);
	array_init(&newSnapshot);
	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_1, &manager, "isusingdynamicupdate", NULL, 0, this_ptr);
	zephir_check_call_status();
	useDynamicUpdate = zephir_get_boolval(&_1);
	zephir_read_property(&_0, this_ptr, SL("snapshot"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	if (useDynamicUpdate) {
		if (Z_TYPE_P(&snapshot) != IS_ARRAY) {
			useDynamicUpdate = 0;
		}
	}
	ZEPHIR_CALL_METHOD(&dataTypes, metaData, "getdatatypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&nonPrimary, metaData, "getnonprimarykeyattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticupdateattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	zephir_is_iterable(&nonPrimary, 0, "phalcon/Mvc/Model.zep", 3819);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&nonPrimary), _2)
	{
		ZEPHIR_INIT_NVAR(&field);
		ZVAL_COPY(&field, _2);
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC)))) {
				ZEPHIR_INIT_NVAR(&_3$$9);
				object_init_ex(&_3$$9, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_4$$9);
				ZEPHIR_CONCAT_SVS(&_4$$9, "Column '", &field, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, &_3$$9, "__construct", &_5, 1, &_4$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$9, "phalcon/Mvc/Model.zep", 3708 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, &field);
		}
		if (!(zephir_array_isset(&automaticAttributes, &attributeField))) {
			ZEPHIR_OBS_NVAR(&bindType);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0 TSRMLS_CC)))) {
				ZEPHIR_INIT_NVAR(&_6$$12);
				object_init_ex(&_6$$12, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_7$$12);
				ZEPHIR_CONCAT_SVS(&_7$$12, "Column '", &field, "' have not defined a bind data type");
				ZEPHIR_CALL_METHOD(NULL, &_6$$12, "__construct", &_5, 1, &_7$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$12, "phalcon/Mvc/Model.zep", 3721 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&value);
			if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
				if (!(useDynamicUpdate)) {
					zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3733);
					zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3734);
					zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3735);
				} else {
					ZEPHIR_OBS_NVAR(&snapshotValue);
					if (!(zephir_array_isset_fetch(&snapshotValue, &snapshot, &attributeField, 0 TSRMLS_CC))) {
						changed = 1;
					} else {
						if (Z_TYPE_P(&value) == IS_NULL) {
							changed = Z_TYPE_P(&snapshotValue) != IS_NULL;
						} else {
							if (Z_TYPE_P(&snapshotValue) == IS_NULL) {
								changed = 1;
							} else {
								ZEPHIR_OBS_NVAR(&dataType);
								if (UNEXPECTED(!(zephir_array_isset_fetch(&dataType, &dataTypes, &field, 0 TSRMLS_CC)))) {
									ZEPHIR_INIT_NVAR(&_8$$22);
									object_init_ex(&_8$$22, phalcon_mvc_model_exception_ce);
									ZEPHIR_INIT_LNVAR(_9$$22);
									ZEPHIR_CONCAT_SVS(&_9$$22, "Column '", &field, "' have not defined a data type");
									ZEPHIR_CALL_METHOD(NULL, &_8$$22, "__construct", &_5, 1, &_9$$22);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_8$$22, "phalcon/Mvc/Model.zep", 3760 TSRMLS_CC);
									ZEPHIR_MM_RESTORE();
									return;
								}
								do {
									if (ZEPHIR_IS_LONG(&dataType, 8)) {
										changed = zephir_get_boolval(&snapshotValue) != zephir_get_boolval(&value);
										break;
									}
									if (ZEPHIR_IS_LONG(&dataType, 3) || ZEPHIR_IS_LONG(&dataType, 7)) {
										ZEPHIR_CALL_FUNCTION(&_10$$24, "floatval", &_11, 432, &snapshotValue);
										zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_12$$24, "floatval", &_11, 432, &value);
										zephir_check_call_status();
										changed = !ZEPHIR_IS_IDENTICAL(&_10$$24, &_12$$24);
										break;
									}
									if (ZEPHIR_IS_LONG(&dataType, 0) || ZEPHIR_IS_LONG(&dataType, 1) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 4) || ZEPHIR_IS_LONG(&dataType, 5) || ZEPHIR_IS_LONG(&dataType, 6) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 14)) {
										zephir_get_strval(&_13$$25, &snapshotValue);
										zephir_get_strval(&_14$$25, &value);
										changed = !ZEPHIR_IS_IDENTICAL(&_13$$25, &_14$$25);
										break;
									}
									changed = !ZEPHIR_IS_EQUAL(&value, &snapshotValue);
								} while(0);

							}
						}
					}
					if (changed) {
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3799);
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3800);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3801);
					}
				}
				zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
				zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3809);
				zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3810);
				zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3811);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&field);
	if (!(zephir_fast_count_int(&fields TSRMLS_CC))) {
		if (useDynamicUpdate) {
			zephir_update_property_zval(this_ptr, SL("oldSnapshot"), &snapshot);
		}
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_0, this_ptr, SL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueKey, &_0);
	zephir_read_property(&_0, this_ptr, SL("uniqueParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueParams, &_0);
	zephir_read_property(&_0, this_ptr, SL("uniqueTypes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueTypes, &_0);
	if (Z_TYPE_P(&uniqueParams) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (UNEXPECTED(!(zephir_fast_count_int(&primaryKeys TSRMLS_CC)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation", "phalcon/Mvc/Model.zep", 3843);
			return;
		}
		ZEPHIR_INIT_NVAR(&uniqueParams);
		array_init(&uniqueParams);
		zephir_is_iterable(&primaryKeys, 0, "phalcon/Mvc/Model.zep", 3870);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _15$$31)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _15$$31);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC)))) {
					ZEPHIR_INIT_NVAR(&_16$$35);
					object_init_ex(&_16$$35, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_17$$35);
					ZEPHIR_CONCAT_SVS(&_17$$35, "Column '", &field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_16$$35, "__construct", &_5, 1, &_17$$35);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_16$$35, "phalcon/Mvc/Model.zep", 3856 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &field);
			}
			ZEPHIR_OBS_NVAR(&value);
			if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
				zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
				zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3864);
			} else {
				zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
				zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3867);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&field);
	}
	ZEPHIR_INIT_VAR(&_18);
	zephir_create_array(&_18, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_18, SL("conditions"), &uniqueKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_18, SL("bind"), &uniqueParams, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_18, SL("bindTypes"), &uniqueTypes, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&success, connection, "update", NULL, 0, table, &fields, &values, &_18, &bindTypes);
	zephir_check_call_status();
	_19 = zephir_is_true(&success);
	if (_19) {
		ZEPHIR_CALL_METHOD(&_1, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_19 = zephir_is_true(&_1);
	}
	_20 = _19;
	if (_20) {
		_20 = ZEPHIR_GLOBAL(orm).update_snapshot_on_save;
	}
	if (_20) {
		if (Z_TYPE_P(&snapshot) == IS_ARRAY) {
			zephir_update_property_zval(this_ptr, SL("oldSnapshot"), &snapshot);
			ZEPHIR_INIT_VAR(&_21$$40);
			zephir_fast_array_merge(&_21$$40, &snapshot, &newSnapshot TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("snapshot"), &_21$$40);
		} else {
			ZEPHIR_INIT_VAR(&_22$$41);
			array_init(&_22$$41);
			zephir_update_property_zval(this_ptr, SL("oldSnapshot"), &_22$$41);
			zephir_update_property_zval(this_ptr, SL("snapshot"), &newSnapshot);
		}
	}
	RETURN_CCTOR(&success);

}

/**
 * Checks whether the current record already exists
 *
 * @param string|array table
 */
PHP_METHOD(Phalcon_Mvc_Model, _exists) {

	zend_bool _5$$11;
	zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberEmpty = 0, numberPrimary = 0;
	zval *metaData, metaData_sub, *connection, connection_sub, *table = NULL, table_sub, __$null, uniqueParams, uniqueTypes, uniqueKey, columnMap, primaryKeys, wherePk, field, attributeField, value, bindDataTypes, joinWhere, num, type, schema, source, _0, _14, _15, _16, _17, *_1$$3, _2$$9, _3$$9, _6$$14, _7$$14, _8$$7, _10$$7, _11$$17, _12$$18, _13$$19, _18$$22, _19$$23;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData_sub);
	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&table_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&uniqueParams);
	ZVAL_UNDEF(&uniqueTypes);
	ZVAL_UNDEF(&uniqueKey);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&wherePk);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&joinWhere);
	ZVAL_UNDEF(&num);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$9);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_6$$14);
	ZVAL_UNDEF(&_7$$14);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_12$$18);
	ZVAL_UNDEF(&_13$$19);
	ZVAL_UNDEF(&_18$$22);
	ZVAL_UNDEF(&_19$$23);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &metaData, &connection, &table);

	if (!table) {
		table = &table_sub;
		ZEPHIR_CPY_WRT(table, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(table);
	}


	ZEPHIR_INIT_VAR(&uniqueParams);
	ZVAL_NULL(&uniqueParams);
	ZEPHIR_INIT_VAR(&uniqueTypes);
	ZVAL_NULL(&uniqueTypes);
	zephir_read_property(&_0, this_ptr, SL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueKey, &_0);
	if (Z_TYPE_P(&uniqueKey) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, 0, this_ptr);
		zephir_check_call_status();
		numberPrimary = zephir_fast_count_int(&primaryKeys TSRMLS_CC);
		if (!(numberPrimary)) {
			RETURN_MM_BOOL(0);
		}
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
		numberEmpty = 0;
		ZEPHIR_INIT_VAR(&wherePk);
		array_init(&wherePk);
		ZEPHIR_INIT_NVAR(&uniqueParams);
		array_init(&uniqueParams);
		ZEPHIR_INIT_NVAR(&uniqueTypes);
		array_init(&uniqueTypes);
		zephir_is_iterable(&primaryKeys, 0, "phalcon/Mvc/Model.zep", 3994);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _1$$3)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _1$$3);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC)))) {
					ZEPHIR_INIT_NVAR(&_2$$9);
					object_init_ex(&_2$$9, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_3$$9);
					ZEPHIR_CONCAT_SVS(&_3$$9, "Column '", &field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_2$$9, "__construct", &_4, 1, &_3$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_2$$9, "phalcon/Mvc/Model.zep", 3953 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &field);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_NULL(&value);
			ZEPHIR_OBS_NVAR(&value);
			if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
				_5$$11 = Z_TYPE_P(&value) == IS_NULL;
				if (!(_5$$11)) {
					_5$$11 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
				}
				if (_5$$11) {
					numberEmpty++;
				}
				zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3974);
			} else {
				zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3976);
				numberEmpty++;
			}
			ZEPHIR_OBS_NVAR(&type);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0 TSRMLS_CC)))) {
				ZEPHIR_INIT_NVAR(&_6$$14);
				object_init_ex(&_6$$14, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_7$$14);
				ZEPHIR_CONCAT_SVS(&_7$$14, "Column '", &field, "' isn't part of the table columns");
				ZEPHIR_CALL_METHOD(NULL, &_6$$14, "__construct", &_4, 1, &_7$$14);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$14, "phalcon/Mvc/Model.zep", 3983 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3986);
			ZEPHIR_CALL_METHOD(&_8$$7, connection, "escapeidentifier", &_9, 0, &field);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_10$$7);
			ZEPHIR_CONCAT_VS(&_10$$7, &_8$$7, " = ?");
			zephir_array_append(&wherePk, &_10$$7, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3987);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&field);
		if (numberPrimary == numberEmpty) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&joinWhere);
		zephir_fast_join_str(&joinWhere, SL(" AND "), &wherePk TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("uniqueKey"), &joinWhere);
		zephir_update_property_zval(this_ptr, SL("uniqueParams"), &uniqueParams);
		zephir_update_property_zval(this_ptr, SL("uniqueTypes"), &uniqueTypes);
		ZEPHIR_CPY_WRT(&uniqueKey, &joinWhere);
	}
	zephir_read_property(&_0, this_ptr, SL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(1);
	}
	if (Z_TYPE_P(&uniqueKey) == IS_NULL) {
		zephir_read_property(&_11$$17, this_ptr, SL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueKey, &_11$$17);
	}
	if (Z_TYPE_P(&uniqueParams) == IS_NULL) {
		zephir_read_property(&_12$$18, this_ptr, SL("uniqueParams"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueParams, &_12$$18);
	}
	if (Z_TYPE_P(&uniqueTypes) == IS_NULL) {
		zephir_read_property(&_13$$19, this_ptr, SL("uniqueTypes"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueTypes, &_13$$19);
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 425);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 426);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_NVAR(table);
		zephir_create_array(table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(table, &schema);
		zephir_array_fast_append(table, &source);
	} else {
		ZEPHIR_CPY_WRT(table, &source);
	}
	ZEPHIR_CALL_METHOD(&_14, connection, "escapeidentifier", NULL, 0, table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_CONCAT_SVSV(&_15, "SELECT COUNT(*) \"rowcount\" FROM ", &_14, " WHERE ", &uniqueKey);
	ZVAL_NULL(&_16);
	ZEPHIR_CALL_METHOD(&num, connection, "fetchone", NULL, 0, &_15, &_16, &uniqueParams, &uniqueTypes);
	zephir_check_call_status();
	zephir_array_fetch_string(&_17, &num, SL("rowcount"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4048 TSRMLS_CC);
	if (zephir_is_true(&_17)) {
		ZEPHIR_INIT_ZVAL_NREF(_18$$22);
		ZVAL_LONG(&_18$$22, 0);
		zephir_update_property_zval(this_ptr, SL("dirtyState"), &_18$$22);
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_19$$23);
		ZVAL_LONG(&_19$$23, 1);
		zephir_update_property_zval(this_ptr, SL("dirtyState"), &_19$$23);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns related records defined relations depending on the method name
 *
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, _getRelatedRecords) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *method_param = NULL, *arguments, arguments_sub, manager, relation, queryMethod, extraArgs, alias, _0, _1$$3, _2$$3, _3$$5, _4$$5, _5$$5;
	zval modelName, method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&queryMethod);
	ZVAL_UNDEF(&extraArgs);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &modelName_param, &method_param, &arguments);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}


	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&relation);
	ZVAL_BOOL(&relation, 0);
	ZEPHIR_INIT_VAR(&queryMethod);
	ZVAL_NULL(&queryMethod);
	ZEPHIR_OBS_VAR(&extraArgs);
	zephir_array_isset_long_fetch(&extraArgs, arguments, 0, 0 TSRMLS_CC);
	if (zephir_start_with_str(&method, SL("get"))) {
		ZVAL_LONG(&_1$$3, 3);
		ZEPHIR_INIT_VAR(&alias);
		zephir_substr(&alias, &method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(&_2$$3, &manager, "getrelationbyalias", NULL, 0, &modelName, &alias);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_2$$3);
		if (Z_TYPE_P(&relation) != IS_OBJECT) {
			RETURN_MM_NULL();
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelated", NULL, 0, &alias, &extraArgs);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_start_with_str(&method, SL("count"))) {
		ZEPHIR_INIT_NVAR(&queryMethod);
		ZVAL_STRING(&queryMethod, "count");
		ZVAL_LONG(&_4$$5, 5);
		ZEPHIR_INIT_VAR(&_5$$5);
		zephir_substr(&_5$$5, &method, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(&_3$$5, &manager, "getrelationbyalias", NULL, 0, &modelName, &_5$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_3$$5);
		if (Z_TYPE_P(&relation) != IS_OBJECT) {
			RETURN_MM_NULL();
		}
		ZEPHIR_RETURN_CALL_METHOD(&manager, "getrelationrecords", NULL, 0, &relation, &queryMethod, this_ptr, &extraArgs);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * Generate a PHQL SELECT statement for an aggregate
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Mvc_Model, _groupResult) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *functionName_param = NULL, *alias_param = NULL, *parameters, parameters_sub, params, distinctColumn, groupColumn, columns, bindParams, bindTypes, resultset, cache, firstRow, groupColumns, builder, query, container, manager, _1, _2, _3;
	zval functionName, alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&functionName);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&distinctColumn);
	ZVAL_UNDEF(&groupColumn);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&firstRow);
	ZVAL_UNDEF(&groupColumns);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &functionName_param, &alias_param, &parameters);

	if (UNEXPECTED(Z_TYPE_P(functionName_param) != IS_STRING && Z_TYPE_P(functionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'functionName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(functionName_param) == IS_STRING)) {
		zephir_get_strval(&functionName, functionName_param);
	} else {
		ZEPHIR_INIT_VAR(&functionName);
		ZVAL_EMPTY_STRING(&functionName);
	}
	if (UNEXPECTED(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(&alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_EMPTY_STRING(&alias);
	}


	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_ce, "getdefault", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "modelsManager");
	ZEPHIR_CALL_METHOD(&_1, &container, "getshared", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4143);
		}
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_OBS_VAR(&groupColumn);
	if (!(zephir_array_isset_string_fetch(&groupColumn, &params, SL("column"), 0))) {
		ZEPHIR_INIT_NVAR(&groupColumn);
		ZVAL_STRING(&groupColumn, "*");
	}
	ZEPHIR_OBS_VAR(&distinctColumn);
	if (zephir_array_isset_string_fetch(&distinctColumn, &params, SL("distinct"), 0)) {
		ZEPHIR_INIT_VAR(&columns);
		ZEPHIR_CONCAT_VSVSV(&columns, &functionName, "(DISTINCT ", &distinctColumn, ") AS ", &alias);
	} else {
		ZEPHIR_OBS_VAR(&groupColumns);
		ZEPHIR_INIT_NVAR(&columns);
		if (zephir_array_isset_string_fetch(&groupColumns, &params, SL("group"), 0)) {
			ZEPHIR_CONCAT_VSVSVSV(&columns, &groupColumns, ", ", &functionName, "(", &groupColumn, ") AS ", &alias);
		} else {
			ZEPHIR_CONCAT_VSVSV(&columns, &functionName, "(", &groupColumn, ") AS ", &alias);
		}
	}
	ZEPHIR_CALL_METHOD(&_1, &manager, "createbuilder", NULL, 0, &params);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&builder, &_1);
	ZEPHIR_CALL_METHOD(NULL, &builder, "columns", NULL, 0, &columns);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	zephir_get_called_class(&_2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &builder, "from", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &builder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&query, &_1);
	ZEPHIR_INIT_VAR(&bindParams);
	ZVAL_NULL(&bindParams);
	ZEPHIR_INIT_VAR(&bindTypes);
	ZVAL_NULL(&bindTypes);
	ZEPHIR_OBS_NVAR(&bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, &params, SL("bind"), 0)) {
		ZEPHIR_OBS_NVAR(&bindTypes);
		zephir_array_isset_string_fetch(&bindTypes, &params, SL("bindTypes"), 0);
	}
	ZEPHIR_OBS_VAR(&cache);
	if (zephir_array_isset_string_fetch(&cache, &params, SL("cache"), 0)) {
		ZEPHIR_CALL_METHOD(NULL, &query, "cache", NULL, 0, &cache);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&resultset, &query, "execute", NULL, 0, &bindParams, &bindTypes);
	zephir_check_call_status();
	if (zephir_array_isset_string(&params, SL("group"))) {
		RETURN_CCTOR(&resultset);
	}
	ZEPHIR_CALL_METHOD(&firstRow, &resultset, "getfirst", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property_zval(&_3, &firstRow, &alias, PH_NOISY_CC);
	RETURN_CCTOR(&_3);

}

/**
 * Try to check if the query must invoke a finder
 *
 * @return \Phalcon\Mvc\ModelInterface[]|\Phalcon\Mvc\ModelInterface|bool
 */
PHP_METHOD(Phalcon_Mvc_Model, _invokeFinder) {

	zend_class_entry *_6, *_12;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, _9, _11;
	zval *method_param = NULL, *arguments_param = NULL, extraMethod, type, modelName, value, model, attributes, field, extraMethodFirst, metaData, _5, _10, _0$$3, _1$$4, _2$$5, _3$$7, _7$$13, _8$$13;
	zval method, _4$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&extraMethod);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&extraMethodFirst);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &arguments_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&arguments, arguments_param);


	ZEPHIR_INIT_VAR(&extraMethod);
	ZVAL_NULL(&extraMethod);
	if (zephir_start_with_str(&method, SL("findFirstBy"))) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "findFirst");
		ZVAL_LONG(&_0$$3, 11);
		ZEPHIR_INIT_NVAR(&extraMethod);
		zephir_substr(&extraMethod, &method, 11 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	} else if (zephir_start_with_str(&method, SL("findBy"))) {
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_STRING(&type, "find");
		ZVAL_LONG(&_1$$4, 6);
		ZEPHIR_INIT_NVAR(&extraMethod);
		zephir_substr(&extraMethod, &method, 6 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	} else if (zephir_start_with_str(&method, SL("countBy"))) {
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_STRING(&type, "count");
		ZVAL_LONG(&_2$$5, 7);
		ZEPHIR_INIT_NVAR(&extraMethod);
		zephir_substr(&extraMethod, &method, 7 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	}
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_called_class(&modelName TSRMLS_CC);
	if (!(zephir_is_true(&extraMethod))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(&value);
	if (UNEXPECTED(!(zephir_array_isset_long_fetch(&value, &arguments, 0, 0 TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_3$$7);
		object_init_ex(&_3$$7, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$7);
		ZEPHIR_CONCAT_SVS(&_4$$7, "The static method '", &method, "' requires one argument");
		ZEPHIR_CALL_METHOD(NULL, &_3$$7, "__construct", NULL, 1, &_4$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$7, "phalcon/Mvc/Model.zep", 4262 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&model);
	zephir_fetch_safe_class(&_5, &modelName);
	_6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_5), Z_STRLEN_P(&_5), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&model, _6);
	if (zephir_has_constructor(&model TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &model, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&metaData, &model, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&attributes, &metaData, "getreversecolumnmap", NULL, 0, &model);
	zephir_check_call_status();
	if (Z_TYPE_P(&attributes) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&attributes, &metaData, "getdatatypes", NULL, 0, &model);
		zephir_check_call_status();
	}
	if (zephir_array_isset(&attributes, &extraMethod)) {
		ZEPHIR_CPY_WRT(&field, &extraMethod);
	} else {
		ZEPHIR_CALL_FUNCTION(&extraMethodFirst, "lcfirst", NULL, 68, &extraMethod);
		zephir_check_call_status();
		if (zephir_array_isset(&attributes, &extraMethodFirst)) {
			ZEPHIR_CPY_WRT(&field, &extraMethodFirst);
		} else {
			ZEPHIR_INIT_NVAR(&field);
			zephir_uncamelize(&field, &extraMethod, NULL  );
			if (UNEXPECTED(!(zephir_array_isset(&attributes, &field)))) {
				ZEPHIR_INIT_VAR(&_7$$13);
				object_init_ex(&_7$$13, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_8$$13);
				ZEPHIR_CONCAT_SVS(&_8$$13, "Cannot resolve attribute '", &extraMethod, "' in the model");
				ZEPHIR_CALL_METHOD(NULL, &_7$$13, "__construct", NULL, 1, &_8$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$13, "phalcon/Mvc/Model.zep", 4299 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_SVS(&_10, "[", &field, "] = ?0");
	zephir_array_update_string(&_9, SL("conditions"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_11);
	zephir_create_array(&_11, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_11, &value);
	zephir_array_update_string(&_9, SL("bind"), &_11, PH_COPY | PH_SEPARATE);
	_12 = zephir_fetch_class(&modelName TSRMLS_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC_ZVAL(_12, type, NULL, 0, &_9);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check for, and attempt to use, possible setter.
 */
PHP_METHOD(Phalcon_Mvc_Model, _possibleSetter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *value, value_sub, possibleSetter, _0;
	zval property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&possibleSetter);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &value);

	zephir_get_strval(&property, property_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_camelize(&_0, &property, NULL  );
	ZEPHIR_INIT_VAR(&possibleSetter);
	ZEPHIR_CONCAT_SV(&possibleSetter, "set", &_0);
	if (!((zephir_method_exists(this_ptr, &possibleSetter TSRMLS_CC)  == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &possibleSetter, NULL, 0, value);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * Executes internal hooks before save a record
 */
PHP_METHOD(Phalcon_Mvc_Model, _preSave) {

	zval eventName;
	zephir_fcall_cache_entry *_7 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool exists, error = 0, isNull = 0, _8$$26, _9$$26, _10$$26;
	zval *metaData, metaData_sub, *exists_param = NULL, *identityField, identityField_sub, __$true, __$false, notNull, columnMap, dataTypeNumeric, automaticAttributes, defaultValues, field, attributeField, value, emptyStringValues, _17, _18, _0$$3, _1$$3, _2$$3, _3$$8, *_4$$11, _5$$18, _6$$18, _11$$26, _12$$31, _13$$31, _14$$31, _16$$36, _19$$38, _20$$39, _21$$39, _22$$39, _23$$39, _24$$39, _25$$39;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData_sub);
	ZVAL_UNDEF(&identityField_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&notNull);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&dataTypeNumeric);
	ZVAL_UNDEF(&automaticAttributes);
	ZVAL_UNDEF(&defaultValues);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&emptyStringValues);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_5$$18);
	ZVAL_UNDEF(&_6$$18);
	ZVAL_UNDEF(&_11$$26);
	ZVAL_UNDEF(&_12$$31);
	ZVAL_UNDEF(&_13$$31);
	ZVAL_UNDEF(&_14$$31);
	ZVAL_UNDEF(&_16$$36);
	ZVAL_UNDEF(&_19$$38);
	ZVAL_UNDEF(&_20$$39);
	ZVAL_UNDEF(&_21$$39);
	ZVAL_UNDEF(&_22$$39);
	ZVAL_UNDEF(&_23$$39);
	ZVAL_UNDEF(&_24$$39);
	ZVAL_UNDEF(&_25$$39);
	ZVAL_UNDEF(&eventName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &metaData, &exists_param, &identityField);

	exists = zephir_get_boolval(exists_param);


	if (ZEPHIR_GLOBAL(orm).events) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "beforeValidation");
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "fireeventcancel", NULL, 0, &_1$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$3)) {
			RETURN_MM_BOOL(0);
		}
		if (exists) {
			ZEPHIR_INIT_VAR(&eventName);
			ZVAL_STRING(&eventName, "beforeValidationOnUpdate");
		} else {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "beforeValidationOnCreate");
		}
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_3$$8, this_ptr, "_checkforeignkeysrestrict", NULL, 433);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$8)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GLOBAL(orm).not_null_validations) {
		ZEPHIR_CALL_METHOD(&notNull, metaData, "getnotnullattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (Z_TYPE_P(&notNull) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&dataTypeNumeric, metaData, "getdatatypesnumeric", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_GLOBAL(orm).column_renaming) {
				ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&columnMap);
				ZVAL_NULL(&columnMap);
			}
			if (exists) {
				ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticupdateattributes", NULL, 0, this_ptr);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticcreateattributes", NULL, 0, this_ptr);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&defaultValues, metaData, "getdefaultvalues", NULL, 0, this_ptr);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&emptyStringValues, metaData, "getemptystringattributes", NULL, 0, this_ptr);
			zephir_check_call_status();
			error = 0;
			zephir_is_iterable(&notNull, 0, "phalcon/Mvc/Model.zep", 4494);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&notNull), _4$$11)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _4$$11);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC)))) {
						ZEPHIR_INIT_NVAR(&_5$$18);
						object_init_ex(&_5$$18, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_6$$18);
						ZEPHIR_CONCAT_SVS(&_6$$18, "Column '", &field, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_5$$18, "__construct", &_7, 1, &_6$$18);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_5$$18, "phalcon/Mvc/Model.zep", 4419 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				if (!(zephir_array_isset(&automaticAttributes, &attributeField))) {
					isNull = 0;
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						if (Z_TYPE_P(&value) != IS_OBJECT) {
							if (!(zephir_array_isset(&dataTypeNumeric, &field))) {
								if (zephir_array_isset(&emptyStringValues, &field)) {
									if (Z_TYPE_P(&value) == IS_NULL) {
										isNull = 1;
									}
								} else {
									_8$$26 = Z_TYPE_P(&value) == IS_NULL;
									if (!(_8$$26)) {
										_9$$26 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
										if (_9$$26) {
											_10$$26 = !(zephir_array_isset(&defaultValues, &field));
											if (!(_10$$26)) {
												zephir_array_fetch(&_11$$26, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4448 TSRMLS_CC);
												_10$$26 = !ZEPHIR_IS_IDENTICAL(&value, &_11$$26);
											}
											_9$$26 = _10$$26;
										}
										_8$$26 = _9$$26;
									}
									if (_8$$26) {
										isNull = 1;
									}
								}
							} else {
								if (!(zephir_is_numeric(&value))) {
									isNull = 1;
								}
							}
						}
					} else {
						isNull = 1;
					}
					if (isNull) {
						if (!(exists)) {
							if (ZEPHIR_IS_EQUAL(&field, identityField)) {
								continue;
							}
							if (zephir_array_isset(&defaultValues, &field)) {
								continue;
							}
						}
						ZEPHIR_INIT_NVAR(&_12$$31);
						object_init_ex(&_12$$31, phalcon_messages_message_ce);
						ZEPHIR_INIT_LNVAR(_13$$31);
						ZEPHIR_CONCAT_VS(&_13$$31, &attributeField, " is required");
						ZEPHIR_INIT_NVAR(&_14$$31);
						ZVAL_STRING(&_14$$31, "PresenceOf");
						ZEPHIR_CALL_METHOD(NULL, &_12$$31, "__construct", &_15, 404, &_13$$31, &attributeField, &_14$$31);
						zephir_check_call_status();
						zephir_update_property_array_append(this_ptr, SL("errorMessages"), &_12$$31 TSRMLS_CC);
						error = 1;
					}
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&field);
			if (error) {
				if (ZEPHIR_GLOBAL(orm).events) {
					ZEPHIR_INIT_VAR(&_16$$36);
					ZVAL_STRING(&_16$$36, "onValidationFails");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_16$$36);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
					zephir_check_call_status();
				}
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_VAR(&_18);
	ZVAL_STRING(&_18, "validation");
	ZEPHIR_CALL_METHOD(&_17, this_ptr, "fireeventcancel", NULL, 0, &_18);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_17)) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_VAR(&_19$$38);
			ZVAL_STRING(&_19$$38, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_19$$38);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (exists) {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "afterValidationOnUpdate");
		} else {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "afterValidationOnCreate");
		}
		ZEPHIR_CALL_METHOD(&_20$$39, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_20$$39)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&_22$$39);
		ZVAL_STRING(&_22$$39, "afterValidation");
		ZEPHIR_CALL_METHOD(&_21$$39, this_ptr, "fireeventcancel", NULL, 0, &_22$$39);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_21$$39)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&_22$$39);
		ZVAL_STRING(&_22$$39, "beforeSave");
		ZEPHIR_CALL_METHOD(&_23$$39, this_ptr, "fireeventcancel", NULL, 0, &_22$$39);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_23$$39)) {
			RETURN_MM_BOOL(0);
		}
		if (0) {
			zephir_update_property_zval(this_ptr, SL("skipped"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("skipped"), &__$false);
		}
		if (exists) {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "beforeUpdate");
		} else {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "beforeCreate");
		}
		ZEPHIR_CALL_METHOD(&_24$$39, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_24$$39)) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property(&_25$$39, this_ptr, SL("skipped"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_25$$39)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Saves related records that must be stored prior to save the master record
 *
 * @param \Phalcon\Mvc\ModelInterface[] related
 */
PHP_METHOD(Phalcon_Mvc_Model, _preSaveRelatedRecords) {

	zval _18$$10;
	zend_string *_4;
	zend_ulong _3;
	zend_bool nesting = 0;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_14 = NULL, *_19 = NULL, *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, *related, related_sub, className, manager, type, relation, columns, referencedFields, referencedModel, message, name, record, _0, _1, *_2, _5$$3, _8$$6, _13$$7, _15$$5, _22$$5, _16$$8, *_17$$8, _20$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&related_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_18$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &related);



	nesting = 0;
	if (nesting) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	zephir_is_iterable(related, 0, "phalcon/Mvc/Model.zep", 4671);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(related), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&name, _4);
		} else {
			ZVAL_LONG(&name, _3);
		}
		ZEPHIR_INIT_NVAR(&record);
		ZVAL_COPY(&record, _2);
		ZEPHIR_CALL_METHOD(&_5$$3, &manager, "getrelationbyalias", &_6, 0, &className, &name);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_5$$3);
		if (Z_TYPE_P(&relation) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&type, &relation, "gettype", &_7, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(&type, 0)) {
				if (UNEXPECTED(Z_TYPE_P(&record) != IS_OBJECT)) {
					if (nesting) {
						ZVAL_BOOL(&_8$$6, 1);
					} else {
						ZVAL_BOOL(&_8$$6, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_9, 0, &_8$$6);
					zephir_check_call_status();
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects can be stored as part of belongs-to relations", "phalcon/Mvc/Model.zep", 4614);
					return;
				}
				ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", &_10, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getreferencedmodel", &_11, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", &_12, 0);
				zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
					if (nesting) {
						ZVAL_BOOL(&_13$$7, 1);
					} else {
						ZVAL_BOOL(&_13$$7, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_14, 0, &_13$$7);
					zephir_check_call_status();
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/Mvc/Model.zep", 4624);
					return;
				}
				ZEPHIR_CALL_METHOD(&_15$$5, &record, "save", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_15$$5))) {
					ZEPHIR_CALL_METHOD(&_16$$8, &record, "getmessages", NULL, 0);
					zephir_check_call_status();
					zephir_is_iterable(&_16$$8, 0, "phalcon/Mvc/Model.zep", 4657);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_16$$8), _17$$8)
					{
						ZEPHIR_INIT_NVAR(&message);
						ZVAL_COPY(&message, _17$$8);
						if (Z_TYPE_P(&message) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_18$$10);
							zephir_create_array(&_18$$10, 1, 0 TSRMLS_CC);
							zephir_array_update_string(&_18$$10, SL("model"), &record, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_18$$10);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_19, 0, &message);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&message);
					if (nesting) {
						ZVAL_BOOL(&_20$$8, 1);
					} else {
						ZVAL_BOOL(&_20$$8, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_21, 0, &_20$$8);
					zephir_check_call_status();
					RETURN_MM_BOOL(0);
				}
				ZEPHIR_CALL_METHOD(&_22$$5, &record, "readattribute", NULL, 0, &referencedFields);
				zephir_check_call_status();
				zephir_update_property_zval_zval(this_ptr, &columns, &_22$$5 TSRMLS_CC);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&record);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_MM_BOOL(1);

}

/**
 * Executes internal events after save a record
 */
PHP_METHOD(Phalcon_Mvc_Model, _postSave) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *success_param = NULL, *exists_param = NULL, _0$$4, _1$$5;
	zend_bool success, exists;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &success_param, &exists_param);

	success = zephir_get_boolval(success_param);
	exists = zephir_get_boolval(exists_param);


	if (success) {
		if (exists) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZVAL_STRING(&_0$$4, "afterUpdate");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_0$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_1$$5);
			ZVAL_STRING(&_1$$5, "afterCreate");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_1$$5);
			zephir_check_call_status();
		}
	}
	RETURN_MM_BOOL(success);

}

/**
 * Save the related records assigned in the has-one/has-many relations
 *
 * @param  Phalcon\Mvc\ModelInterface[] related
 */
PHP_METHOD(Phalcon_Mvc_Model, _postSaveRelatedRecords) {

	zval _30$$16, _38$$20;
	zend_string *_3;
	zend_ulong _2;
	zend_bool nesting = 0, isThrough = 0, _8$$4;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_15 = NULL, *_17 = NULL, *_20 = NULL, *_22 = NULL, *_23 = NULL, *_24 = NULL, *_25 = NULL, *_31 = NULL, *_33 = NULL, *_34 = NULL, *_40 = NULL, *_42 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, *related, related_sub, className, manager, relation, name, record, message, columns, referencedModel, referencedFields, relatedRecords, value, recordAfter, intermediateModel, intermediateFields, intermediateValue, intermediateModelName, intermediateReferencedFields, _0, *_1, _45, _4$$3, _6$$4, _21$$4, *_26$$4, _9$$6, _14$$7, _16$$10, _18$$10, _19$$10, _27$$12, _28$$14, *_29$$14, _32$$14, _35$$17, _36$$18, *_37$$18, _39$$18, _41$$22, _43$$22, _44$$22;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&related_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&relatedRecords);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&recordAfter);
	ZVAL_UNDEF(&intermediateModel);
	ZVAL_UNDEF(&intermediateFields);
	ZVAL_UNDEF(&intermediateValue);
	ZVAL_UNDEF(&intermediateModelName);
	ZVAL_UNDEF(&intermediateReferencedFields);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_35$$17);
	ZVAL_UNDEF(&_36$$18);
	ZVAL_UNDEF(&_39$$18);
	ZVAL_UNDEF(&_41$$22);
	ZVAL_UNDEF(&_43$$22);
	ZVAL_UNDEF(&_44$$22);
	ZVAL_UNDEF(&_30$$16);
	ZVAL_UNDEF(&_38$$20);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &related);



	nesting = 0;
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_is_iterable(related, 0, "phalcon/Mvc/Model.zep", 4901);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(related), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&name, _3);
		} else {
			ZVAL_LONG(&name, _2);
		}
		ZEPHIR_INIT_NVAR(&record);
		ZVAL_COPY(&record, _1);
		ZEPHIR_CALL_METHOD(&_4$$3, &manager, "getrelationbyalias", &_5, 0, &className, &name);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_4$$3);
		if (Z_TYPE_P(&relation) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_6$$4, &relation, "gettype", &_7, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(&_6$$4, 0)) {
				continue;
			}
			_8$$4 = Z_TYPE_P(&record) != IS_OBJECT;
			if (_8$$4) {
				_8$$4 = Z_TYPE_P(&record) != IS_ARRAY;
			}
			if (UNEXPECTED(_8$$4)) {
				if (nesting) {
					ZVAL_BOOL(&_9$$6, 1);
				} else {
					ZVAL_BOOL(&_9$$6, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_10, 0, &_9$$6);
				zephir_check_call_status();
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects/arrays can be stored as part of has-many/has-one/has-many-to-many relations", "phalcon/Mvc/Model.zep", 4731);
				return;
			}
			ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", &_11, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getreferencedmodel", &_12, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", &_13, 0);
			zephir_check_call_status();
			if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
				if (nesting) {
					ZVAL_BOOL(&_14$$7, 1);
				} else {
					ZVAL_BOOL(&_14$$7, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_15, 0, &_14$$7);
				zephir_check_call_status();
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/Mvc/Model.zep", 4741);
				return;
			}
			if (Z_TYPE_P(&record) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&relatedRecords);
				zephir_create_array(&relatedRecords, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(&relatedRecords, &record);
			} else {
				ZEPHIR_CPY_WRT(&relatedRecords, &record);
			}
			ZEPHIR_OBS_NVAR(&value);
			if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, &columns, PH_SILENT_CC)))) {
				if (nesting) {
					ZVAL_BOOL(&_16$$10, 1);
				} else {
					ZVAL_BOOL(&_16$$10, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_17, 0, &_16$$10);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_18$$10);
				object_init_ex(&_18$$10, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_19$$10);
				ZEPHIR_CONCAT_SVS(&_19$$10, "The column '", &columns, "' needs to be present in the model");
				ZEPHIR_CALL_METHOD(NULL, &_18$$10, "__construct", &_20, 1, &_19$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_18$$10, "phalcon/Mvc/Model.zep", 4758 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_21$$4, &relation, "isthrough", &_22, 0);
			zephir_check_call_status();
			isThrough = zephir_get_boolval(&_21$$4);
			if (isThrough) {
				ZEPHIR_CALL_METHOD(&intermediateModelName, &relation, "getintermediatemodel", &_23, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&intermediateFields, &relation, "getintermediatefields", &_24, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&intermediateReferencedFields, &relation, "getintermediatereferencedfields", &_25, 0);
				zephir_check_call_status();
			}
			zephir_is_iterable(&relatedRecords, 0, "phalcon/Mvc/Model.zep", 4887);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _26$$4)
			{
				ZEPHIR_INIT_NVAR(&recordAfter);
				ZVAL_COPY(&recordAfter, _26$$4);
				if (!(isThrough)) {
					ZEPHIR_CALL_METHOD(NULL, &recordAfter, "writeattribute", NULL, 0, &referencedFields, &value);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_27$$12, &recordAfter, "save", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_27$$12))) {
					ZEPHIR_CALL_METHOD(&_28$$14, &recordAfter, "getmessages", NULL, 0);
					zephir_check_call_status();
					zephir_is_iterable(&_28$$14, 0, "phalcon/Mvc/Model.zep", 4817);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_28$$14), _29$$14)
					{
						ZEPHIR_INIT_NVAR(&message);
						ZVAL_COPY(&message, _29$$14);
						if (Z_TYPE_P(&message) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_30$$16);
							zephir_create_array(&_30$$16, 1, 0 TSRMLS_CC);
							zephir_array_update_string(&_30$$16, SL("model"), &record, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_30$$16);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_31, 0, &message);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&message);
					if (nesting) {
						ZVAL_BOOL(&_32$$14, 1);
					} else {
						ZVAL_BOOL(&_32$$14, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_33, 0, &_32$$14);
					zephir_check_call_status();
					RETURN_MM_BOOL(0);
				}
				if (isThrough) {
					ZEPHIR_CALL_METHOD(&intermediateModel, &manager, "load", &_34, 0, &intermediateModelName);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateFields, &value);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&intermediateValue, &recordAfter, "readattribute", NULL, 0, &referencedFields);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateReferencedFields, &intermediateValue);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_35$$17, &intermediateModel, "save", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(&_35$$17))) {
						ZEPHIR_CALL_METHOD(&_36$$18, &intermediateModel, "getmessages", NULL, 0);
						zephir_check_call_status();
						zephir_is_iterable(&_36$$18, 0, "phalcon/Mvc/Model.zep", 4881);
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_36$$18), _37$$18)
						{
							ZEPHIR_INIT_NVAR(&message);
							ZVAL_COPY(&message, _37$$18);
							if (Z_TYPE_P(&message) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_38$$20);
								zephir_create_array(&_38$$20, 1, 0 TSRMLS_CC);
								zephir_array_update_string(&_38$$20, SL("model"), &record, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_38$$20);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_31, 0, &message);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
						ZEPHIR_INIT_NVAR(&message);
						if (nesting) {
							ZVAL_BOOL(&_39$$18, 1);
						} else {
							ZVAL_BOOL(&_39$$18, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_40, 0, &_39$$18);
						zephir_check_call_status();
						RETURN_MM_BOOL(0);
					}
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&recordAfter);
		} else {
			if (UNEXPECTED(Z_TYPE_P(&record) != IS_ARRAY)) {
				if (nesting) {
					ZVAL_BOOL(&_41$$22, 1);
				} else {
					ZVAL_BOOL(&_41$$22, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_42, 0, &_41$$22);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_43$$22);
				object_init_ex(&_43$$22, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_44$$22);
				ZEPHIR_CONCAT_SVSVS(&_44$$22, "There are no defined relations for the model '", &className, "' using alias '", &name, "'");
				ZEPHIR_CALL_METHOD(NULL, &_43$$22, "__construct", &_20, 1, &_44$$22);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_43$$22, "phalcon/Mvc/Model.zep", 4893 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&record);
	ZEPHIR_INIT_NVAR(&name);
	if (nesting) {
		ZVAL_BOOL(&_45, 1);
	} else {
		ZVAL_BOOL(&_45, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0, &_45);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated UPDATE statement
 *
 *<code>
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->allowEmptyStringValues(
 *             [
 *                 "name",
 *             ]
 *         );
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, allowEmptyStringValues) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$true, keysAttributes, attribute, *_0, _1;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 4934);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
	{
		ZEPHIR_INIT_NVAR(&attribute);
		ZVAL_COPY(&attribute, _0);
		zephir_array_update_zval(&keysAttributes, &attribute, &__$true, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "setemptystringattributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Cancel the current operation
 */
PHP_METHOD(Phalcon_Mvc_Model, _cancelOperation) {

	zval _0, _1$$3, _2$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("operationMade"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_0, 3)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "notDeleted");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_1$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "notSaved");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_2$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Setup a reverse 1-1 or n-1 relation between two models
 *
 *<code>
 * class RobotsParts extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->belongsTo(
 *             "robots_id",
 *             Robots::class,
 *             "id"
 *         );
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, belongsTo) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval referenceModel;
	zval *fields, fields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&referenceModel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);

	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
		ZVAL_EMPTY_STRING(&referenceModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addbelongsto", NULL, 0, this_ptr, fields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * shared prepare query logic for find and findFirst method
 */
PHP_METHOD(Phalcon_Mvc_Model, getPreparedQuery) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *params, params_sub, *limit = NULL, limit_sub, __$null, builder, bindParams, bindTypes, transaction, cache, manager, query, container, _1, _2, _3$$5, _4$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&limit_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params, &limit);

	if (!limit) {
		limit = &limit_sub;
		limit = &__$null;
	}


	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_ce, "getdefault", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "modelsManager");
	ZEPHIR_CALL_METHOD(&_1, &container, "getshared", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	ZEPHIR_CALL_METHOD(&_1, &manager, "createbuilder", NULL, 0, params);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&builder, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_get_called_class(&_2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &builder, "from", NULL, 0, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(limit) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, &builder, "limit", NULL, 0, limit);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, &builder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&query, &_1);
	ZEPHIR_OBS_VAR(&bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, params, SL("bind"), 0)) {
		if (Z_TYPE_P(&bindParams) == IS_ARRAY) {
			ZVAL_BOOL(&_3$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, &query, "setbindparams", NULL, 0, &bindParams, &_3$$5);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(&bindTypes);
		if (zephir_array_isset_string_fetch(&bindTypes, params, SL("bindTypes"), 0)) {
			if (Z_TYPE_P(&bindTypes) == IS_ARRAY) {
				ZVAL_BOOL(&_4$$7, 1);
				ZEPHIR_CALL_METHOD(NULL, &query, "setbindtypes", NULL, 0, &bindTypes, &_4$$7);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_OBS_VAR(&transaction);
	if (zephir_array_isset_string_fetch(&transaction, params, SL("transaction"), 0)) {
		if (zephir_instance_of_ev(&transaction, phalcon_mvc_model_transactioninterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &query, "settransaction", NULL, 0, &transaction);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(&cache);
	if (zephir_array_isset_string_fetch(&cache, params, SL("cache"), 0)) {
		ZEPHIR_CALL_METHOD(NULL, &query, "cache", NULL, 0, &cache);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&query);

}

/**
 * Setup a 1-n relation between two models
 *
 *<code>
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->hasMany(
 *             "id",
 *             RobotsParts::class,
 *             "robots_id"
 *         );
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, hasMany) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval referenceModel;
	zval *fields, fields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&referenceModel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);

	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
		ZVAL_EMPTY_STRING(&referenceModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasmany", NULL, 0, this_ptr, fields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setup an n-n relation between two models, through an intermediate
 * relation
 *
 *<code>
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         // Setup a many-to-many relation to Parts through RobotsParts
 *         $this->hasManyToMany(
 *             "id",
 *             RobotsParts::class,
 *             "robots_id",
 *             "parts_id",
 *             Parts::class,
 *             "id",
 *         );
 *     }
 * }
 *</code>
 *
 * @param    string|array fields
 * @param    string|array intermediateFields
 * @param    string|array intermediateReferencedFields
 * @param    string|array referencedFields
 * @param    array options
 */
PHP_METHOD(Phalcon_Mvc_Model, hasManyToMany) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval intermediateModel, referenceModel;
	zval *fields, fields_sub, *intermediateModel_param = NULL, *intermediateFields, intermediateFields_sub, *intermediateReferencedFields, intermediateReferencedFields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&intermediateFields_sub);
	ZVAL_UNDEF(&intermediateReferencedFields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&intermediateModel);
	ZVAL_UNDEF(&referenceModel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 1, &fields, &intermediateModel_param, &intermediateFields, &intermediateReferencedFields, &referenceModel_param, &referencedFields, &options);

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
	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
		ZVAL_EMPTY_STRING(&referenceModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasmanytomany", NULL, 0, this_ptr, fields, &intermediateModel, intermediateFields, intermediateReferencedFields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setup a 1-1 relation between two models
 *
 *<code>
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->hasOne(
 *             "id",
 *             RobotsDescription::class,
 *             "robots_id"
 *         );
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, hasOne) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval referenceModel;
	zval *fields, fields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&referenceModel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);

	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
		ZVAL_EMPTY_STRING(&referenceModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasone", NULL, 0, this_ptr, fields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets if the model must keep the original record snapshot in memory
 *
 *<code>
 * use Phalcon\Mvc\Model;
 *
 * class Robots extends Model
 * {
 *     public function initialize()
 *     {
 *         $this->keepSnapshots(true);
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, keepSnapshots) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keepSnapshot_param = NULL, _0, _1;
	zend_bool keepSnapshot;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keepSnapshot_param);

	keepSnapshot = zephir_get_boolval(keepSnapshot_param);


	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	if (keepSnapshot) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "keepsnapshots", NULL, 0, this_ptr, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets schema name where the mapped table is located
 */
PHP_METHOD(Phalcon_Mvc_Model, setSchema) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *schema_param = NULL, _0;
	zval schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(schema_param) != IS_STRING && Z_TYPE_P(schema_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schema_param) == IS_STRING)) {
		zephir_get_strval(&schema, schema_param);
	} else {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_EMPTY_STRING(&schema);
	}


	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setmodelschema", NULL, 0, this_ptr, &schema);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets the table name to which model should be mapped
 */
PHP_METHOD(Phalcon_Mvc_Model, setSource) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, _0;
	zval source;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &source_param);

	if (UNEXPECTED(Z_TYPE_P(source_param) != IS_STRING && Z_TYPE_P(source_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(source_param) == IS_STRING)) {
		zephir_get_strval(&source, source_param);
	} else {
		ZEPHIR_INIT_VAR(&source);
		ZVAL_EMPTY_STRING(&source);
	}


	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setmodelsource", NULL, 0, this_ptr, &source);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT/UPDATE statement
 *
 *<code>
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->skipAttributes(
 *             [
 *                 "price",
 *             ]
 *         );
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "skipattributesoncreate", NULL, 0, &attributes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "skipattributesonupdate", NULL, 0, &attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT statement
 *
 *<code>
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->skipAttributesOnCreate(
 *             [
 *                 "created_at",
 *             ]
 *         );
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnCreate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$null, attribute, *_0, _1;
	zval attributes, keysAttributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 5235);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
	{
		ZEPHIR_INIT_NVAR(&attribute);
		ZVAL_COPY(&attribute, _0);
		zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "setautomaticcreateattributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated UPDATE statement
 *
 *<code>
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->skipAttributesOnUpdate(
 *             [
 *                 "modified_in",
 *             ]
 *         );
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnUpdate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$null, attribute, *_0, _1;
	zval attributes, keysAttributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 5270);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
	{
		ZEPHIR_INIT_NVAR(&attribute);
		ZVAL_COPY(&attribute, _0);
		zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "setautomaticupdateattributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets if a model must use dynamic update instead of the all-field update
 *
 *<code>
 * use Phalcon\Mvc\Model;
 *
 * class Robots extends Model
 * {
 *     public function initialize()
 *     {
 *         $this->useDynamicUpdate(true);
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, useDynamicUpdate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dynamicUpdate_param = NULL, _0, _1;
	zend_bool dynamicUpdate;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dynamicUpdate_param);

	dynamicUpdate = zephir_get_boolval(dynamicUpdate_param);


	zephir_read_property(&_0, this_ptr, SL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	if (dynamicUpdate) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "usedynamicupdate", NULL, 0, this_ptr, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Executes validators on every validation call
 *
 *<code>
 * use Phalcon\Mvc\Model;
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\ExclusionIn;
 *
 * class Subscriptors extends Model
 * {
 *     public function validation()
 *     {
 *         $validator = new Validation();
 *
 *         $validator->add(
 *             "status",
 *             new ExclusionIn(
 *                 [
 *                     "domain" => [
 *                         "A",
 *                         "I",
 *                     ],
 *                 ]
 *             )
 *         );
 *
 *         return $this->validate($validator);
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, validate) {

	zend_object_iterator *_1;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validator, validator_sub, messages, message, _0, _2$$4, _3$$4, _4$$4, _5$$4, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validator_sub);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &validator);



	ZVAL_NULL(&_0);
	ZEPHIR_CALL_METHOD(&messages, validator, "validate", NULL, 0, &_0, this_ptr);
	zephir_check_call_status();
	if (((Z_TYPE_P(&messages) == IS_TRUE || Z_TYPE_P(&messages) == IS_FALSE) == 1)) {
		RETURN_CCTOR(&messages);
	}
	_1 = zephir_get_iterator(&messages TSRMLS_CC);
	_1->funcs->rewind(_1 TSRMLS_CC);
	for (;_1->funcs->valid(_1 TSRMLS_CC) == SUCCESS && !EG(exception); _1->funcs->move_forward(_1 TSRMLS_CC)) {
		{
			ZEPHIR_ITERATOR_COPY(&message, _1);
		}
		ZEPHIR_INIT_NVAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_messages_message_ce);
		ZEPHIR_CALL_METHOD(&_3$$4, &message, "getmessage", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, &message, "getfield", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$4, &message, "gettype", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$4, &message, "getcode", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", &_7, 404, &_3$$4, &_4$$4, &_5$$4, &_6$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_8, 0, &_2$$4);
		zephir_check_call_status();
	}
	zend_iterator_dtor(_1);
	RETURN_MM_BOOL(!(zephir_fast_count_int(&messages TSRMLS_CC)));

}

/**
 * Check whether validation process has generated any messages
 *
 *<code>
 * use Phalcon\Mvc\Model;
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\ExclusionIn;
 *
 * class Subscriptors extends Model
 * {
 *     public function validation()
 *     {
 *         $validator = new Validation();
 *
 *         $validator->validate(
 *             "status",
 *             new ExclusionIn(
 *                 [
 *                     "domain" => [
 *                         "A",
 *                         "I",
 *                     ],
 *                 ]
 *             )
 *         );
 *
 *         return $this->validate($validator);
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, validationHasFailed) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("errorMessages"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_fast_count_int(&_0 TSRMLS_CC) > 0);

}

/**
 * Attempts to find key case-insensitively
 */
PHP_METHOD(Phalcon_Mvc_Model, caseInsensitiveColumnMap) {

	zval *columnMap, columnMap_sub, *key, key_sub, cmKey, _0, *_1, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&cmKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &columnMap, &key);



	ZEPHIR_INIT_VAR(&_0);
	zephir_array_keys(&_0, columnMap TSRMLS_CC);
	zephir_is_iterable(&_0, 0, "phalcon/Mvc/Model.zep", 5406);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&cmKey);
		ZVAL_COPY(&cmKey, _1);
		ZEPHIR_INIT_NVAR(&_2$$3);
		zephir_fast_strtolower(&_2$$3, &cmKey);
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_fast_strtolower(&_3$$3, key);
		if (ZEPHIR_IS_EQUAL(&_2$$3, &_3$$3)) {
			RETURN_CCTOR(&cmKey);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&cmKey);
	RETVAL_ZVAL(key, 1, 0);
	RETURN_MM();

}

zend_object *zephir_init_properties_Phalcon_Mvc_Model(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("oldSnapshot"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("oldSnapshot"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("related"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("related"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("errorMessages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("errorMessages"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("dirtyRelated"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

