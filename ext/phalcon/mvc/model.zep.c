
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
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
 * Phalcon\Mvc\Model connects business objects and database tables to create
 * a persistable domain model where logic and data are presented in one wrapping.
 * It‘s an implementation of the object-relational mapping (ORM).
 *
 * A model represents the information (data) of the application and the rules to manipulate that data.
 * Models are primarily used for managing the rules of interaction with a corresponding database table.
 * In most cases, each table in your database will correspond to one model in your application.
 * The bulk of your application's business logic will be concentrated in the models.
 *
 * Phalcon\Mvc\Model is the first ORM written in Zephir/C languages for PHP, giving to developers high performance
 * when interacting with databases while is also easy to use.
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

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_model_ce, SL("_dirtyState"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_errorMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_modelsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_modelsMetaData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_related"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_model_ce, SL("_operationMade"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_oldSnapshot"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_skipped"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_snapshot"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_transaction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

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


	RETURN_MEMBER(getThis(), "_transaction");

}

/**
 * Phalcon\Mvc\Model constructor
 */
PHP_METHOD(Phalcon_Mvc_Model, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data = NULL, data_sub, *dependencyInjector = NULL, dependencyInjector_sub, *modelsManager = NULL, modelsManager_sub, __$null, _1$$5, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_UNDEF(&modelsManager_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &data, &dependencyInjector, &modelsManager);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!dependencyInjector) {
		dependencyInjector = &dependencyInjector_sub;
		ZEPHIR_CPY_WRT(dependencyInjector, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(dependencyInjector);
	}
	if (!modelsManager) {
		modelsManager = &modelsManager_sub;
		ZEPHIR_CPY_WRT(modelsManager, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(modelsManager);
	}


	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(dependencyInjector, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model.zep", 138);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);
	if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "modelsManager");
		ZEPHIR_CALL_METHOD(&_1$$5, dependencyInjector, "getshared", NULL, 0, &_2$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(modelsManager, &_1$$5);
		if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/mvc/model.zep", 149);
			return;
		}
	}
	zephir_update_property_zval(this_ptr, SL("_modelsManager"), modelsManager);
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
 * @return	mixed
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


	ZEPHIR_CALL_SELF(&records, "_invokefinder", &_0, 313, &method, &arguments);
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
	zephir_read_property(&_1, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&status, &_1, "missingmethod", NULL, 0, this_ptr, &method, &arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(&status) != IS_NULL) {
		RETURN_CCTOR(&status);
	}
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVSVS(&_3, "The method '", &method, "' doesn't exist on model '", &modelName, "'");
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 4, &_3);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_2, "phalcon/mvc/model.zep", 210 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Handles method calls when a static method is not implemented
 *
 * @return	mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, __callStatic) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval arguments;
	zval *method_param = NULL, *arguments_param = NULL, records, _1$$3;
	zval method, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&arguments);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &arguments_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&arguments, arguments_param);


	ZEPHIR_CALL_SELF(&records, "_invokefinder", &_0, 313, &method, &arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(&records) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "The static method '", &method, "' doesn't exist");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/mvc/model.zep", 224 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&records);

}

/**
 * Magic method to get related records using the relation alias as a property
 *
 * @return \Phalcon\Mvc\Model\Resultset|Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, __get) {

	zend_bool _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, modelName, manager, lowerProperty, relation, result, method, _0, _6, _7, _2$$3, _4$$3, _5$$3, _3$$4;
	zval property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&lowerProperty);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
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
		_1$$3 = zephir_isset_property_zval(this_ptr, &lowerProperty TSRMLS_CC);
		if (_1$$3) {
			ZEPHIR_OBS_VAR(&_2$$3);
			zephir_read_property_zval(&_2$$3, this_ptr, &lowerProperty, PH_NOISY_CC);
			_1$$3 = Z_TYPE_P(&_2$$3) == IS_OBJECT;
		}
		if (_1$$3) {
			ZEPHIR_OBS_VAR(&_3$$4);
			zephir_read_property_zval(&_3$$4, this_ptr, &lowerProperty, PH_NOISY_CC);
			RETURN_CCTOR(&_3$$4);
		}
		ZVAL_NULL(&_4$$3);
		ZVAL_NULL(&_5$$3);
		ZEPHIR_CALL_METHOD(&result, &manager, "getrelationrecords", NULL, 0, &relation, &_4$$3, this_ptr, &_5$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&result) == IS_OBJECT) {
			zephir_update_property_zval_zval(this_ptr, &lowerProperty, &result TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("_related"), &lowerProperty, &result);
		}
		RETURN_CCTOR(&result);
	}
	ZEPHIR_INIT_VAR(&_6);
	zephir_camelize(&_6, &property, NULL  );
	ZEPHIR_INIT_VAR(&method);
	ZEPHIR_CONCAT_SV(&method, "get", &_6);
	if ((zephir_method_exists(this_ptr, &method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SVSV(&_7, "Access to undefined property ", &modelName, "::", &property);
	ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 1, &_7);
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

	zend_string *_4$$6;
	zend_ulong _3$$6;
	zend_bool haveRelation = 0;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_9 = NULL, *_11 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *value, value_sub, lowerProperty, related, modelName, manager, lowerKey, relation, referencedModel, key, item, dirtyState, _15, _16, _0$$4, *_1$$6, _2$$6, _5$$10, _7$$11, _10$$15, _12$$16, _14$$17, _17$$20, _18$$21;
	zval property, _19$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&_19$$21);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&lowerProperty);
	ZVAL_UNDEF(&related);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&lowerKey);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&dirtyState);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_10$$15);
	ZVAL_UNDEF(&_12$$16);
	ZVAL_UNDEF(&_14$$17);
	ZVAL_UNDEF(&_17$$20);
	ZVAL_UNDEF(&_18$$21);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &value);

	zephir_get_strval(&property, property_param);


	if (Z_TYPE_P(value) == IS_OBJECT) {
		if (zephir_instance_of_ev(value, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
			ZEPHIR_OBS_VAR(&dirtyState);
			zephir_read_property(&dirtyState, this_ptr, SL("_dirtyState"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_0$$4, value, "getdirtystate", NULL, 0);
			zephir_check_call_status();
			if (!ZEPHIR_IS_EQUAL(&_0$$4, &dirtyState)) {
				ZEPHIR_INIT_NVAR(&dirtyState);
				ZVAL_LONG(&dirtyState, 1);
			}
			ZEPHIR_INIT_VAR(&lowerProperty);
			zephir_fast_strtolower(&lowerProperty, &property);
			zephir_update_property_zval_zval(this_ptr, &lowerProperty, value TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("_related"), &lowerProperty, value);
			zephir_update_property_zval(this_ptr, SL("_dirtyState"), &dirtyState);
			RETVAL_ZVAL(value, 1, 0);
			RETURN_MM();
		}
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&lowerProperty);
		zephir_fast_strtolower(&lowerProperty, &property);
		ZEPHIR_INIT_VAR(&modelName);
		zephir_get_class(&modelName, this_ptr, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
		zephir_check_call_status();
		haveRelation = 0;
		ZEPHIR_INIT_VAR(&related);
		array_init(&related);
		zephir_is_iterable(value, 0, "phalcon/mvc/model.zep", 369);
		if (Z_TYPE_P(value) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(value), _3$$6, _4$$6, _1$$6)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_4$$6 != NULL) { 
					ZVAL_STR_COPY(&key, _4$$6);
				} else {
					ZVAL_LONG(&key, _3$$6);
				}
				ZEPHIR_INIT_NVAR(&item);
				ZVAL_COPY(&item, _1$$6);
				if (Z_TYPE_P(&item) == IS_OBJECT) {
					if (zephir_instance_of_ev(&item, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
						zephir_array_append(&related, &item, PH_SEPARATE, "phalcon/mvc/model.zep", 354);
						haveRelation = 1;
					}
				} else {
					ZEPHIR_INIT_NVAR(&lowerKey);
					zephir_fast_strtolower(&lowerKey, &key);
					zephir_update_property_zval_zval(this_ptr, &lowerKey, &item TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_5$$10, &manager, "getrelationbyalias", &_6, 0, &modelName, &lowerProperty);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&relation, &_5$$10);
					if (Z_TYPE_P(&relation) == IS_OBJECT) {
						ZEPHIR_CALL_METHOD(&_7$$11, &relation, "getreferencedmodel", &_8, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_9, 0, &_7$$11);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &referencedModel, "writeattribute", NULL, 0, &lowerKey, &item);
						zephir_check_call_status();
						haveRelation = 1;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, value, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$6, value, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, value, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&item, value, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&item) == IS_OBJECT) {
						if (zephir_instance_of_ev(&item, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
							zephir_array_append(&related, &item, PH_SEPARATE, "phalcon/mvc/model.zep", 354);
							haveRelation = 1;
						}
					} else {
						ZEPHIR_INIT_NVAR(&lowerKey);
						zephir_fast_strtolower(&lowerKey, &key);
						zephir_update_property_zval_zval(this_ptr, &lowerKey, &item TSRMLS_CC);
						ZEPHIR_CALL_METHOD(&_10$$15, &manager, "getrelationbyalias", &_11, 0, &modelName, &lowerProperty);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&relation, &_10$$15);
						if (Z_TYPE_P(&relation) == IS_OBJECT) {
							ZEPHIR_CALL_METHOD(&_12$$16, &relation, "getreferencedmodel", &_8, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_13, 0, &_12$$16);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &referencedModel, "writeattribute", NULL, 0, &lowerKey, &item);
							zephir_check_call_status();
							haveRelation = 1;
						}
					}
				ZEPHIR_CALL_METHOD(NULL, value, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&item);
		ZEPHIR_INIT_NVAR(&key);
		if (zephir_fast_count_int(&related TSRMLS_CC) > 0) {
			zephir_update_property_array(this_ptr, SL("_related"), &lowerProperty, &related);
			ZEPHIR_INIT_ZVAL_NREF(_14$$17);
			ZVAL_LONG(&_14$$17, 1);
			zephir_update_property_zval(this_ptr, SL("_dirtyState"), &_14$$17);
		}
		if (haveRelation == 1) {
			RETVAL_ZVAL(value, 1, 0);
			RETURN_MM();
		}
	}
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "_possiblesetter", NULL, 314, &property, value);
	zephir_check_call_status();
	if (zephir_is_true(&_15)) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_16, "property_exists", NULL, 315, this_ptr, &property);
	zephir_check_call_status();
	if (zephir_is_true(&_16)) {
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_17$$20, &manager, "isvisiblemodelproperty", NULL, 0, this_ptr, &property);
		zephir_check_call_status();
		if (!(zephir_is_true(&_17$$20))) {
			ZEPHIR_INIT_VAR(&_18$$21);
			object_init_ex(&_18$$21, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_19$$21);
			ZEPHIR_CONCAT_SVS(&_19$$21, "Property '", &property, "' does not have a setter.");
			ZEPHIR_CALL_METHOD(NULL, &_18$$21, "__construct", NULL, 4, &_19$$21);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_18$$21, "phalcon/mvc/model.zep", 388 TSRMLS_CC);
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
 *
 * use Phalcon\Mvc\Model;
 * use Phalcon\Mvc\Model\Behavior\Timestampable;
 *
 * class Robots extends Model
 * {
 *     public function initialize()
 *     {
 *         $this->addBehavior(
 *             new Timestampable(
 *                [
 *                    "onCreate" => [
 *                         "field"  => "created_at",
 *                         "format" => "Y-m-d",
 * 	                   ],
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



	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
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



	zephir_update_property_array_append(this_ptr, SL("_errorMessages"), message);
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

	zend_bool _7$$12, _13$$19, _16$$23, _20$$30;
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *dataColumnMap = NULL, dataColumnMap_sub, *whiteList = NULL, whiteList_sub, __$null, key, keyMapped, value, attribute, attributeField, metaData, columnMap, dataMapped, disableAssignSetters, _4, *_5, _6, *_0$$3, _1$$3, _8$$13, _10$$16, _11$$16, _14$$19, _17$$24, _18$$27, _19$$27, _21$$30;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
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
	ZVAL_UNDEF(&dataMapped);
	ZVAL_UNDEF(&disableAssignSetters);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_10$$16);
	ZVAL_UNDEF(&_11$$16);
	ZVAL_UNDEF(&_14$$19);
	ZVAL_UNDEF(&_17$$24);
	ZVAL_UNDEF(&_18$$27);
	ZVAL_UNDEF(&_19$$27);
	ZVAL_UNDEF(&_21$$30);

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
		zephir_is_iterable(&data, 0, "phalcon/mvc/model.zep", 519);
		if (Z_TYPE_P(&data) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _3$$3);
				} else {
					ZVAL_LONG(&key, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				ZEPHIR_OBS_NVAR(&keyMapped);
				if (zephir_array_isset_fetch(&keyMapped, dataColumnMap, &key, 0 TSRMLS_CC)) {
					zephir_array_update_zval(&dataMapped, &keyMapped, &value, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&keyMapped);
					if (zephir_array_isset_fetch(&keyMapped, dataColumnMap, &key, 0 TSRMLS_CC)) {
						zephir_array_update_zval(&dataMapped, &keyMapped, &value, PH_COPY | PH_SEPARATE);
					}
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
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
	ZEPHIR_CALL_METHOD(&_4, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_4, 0, "phalcon/mvc/model.zep", 573);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _5);
			_7$$12 = !(zephir_array_isset(&columnMap, &attribute));
			if (_7$$12) {
				_7$$12 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
			}
			if (_7$$12) {
				ZEPHIR_CALL_SELF(&_8$$13, "caseinsensitivecolumnmap", &_9, 316, &columnMap, &attribute);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&attribute, &_8$$13);
			}
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0 TSRMLS_CC))) {
					if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
						ZEPHIR_INIT_NVAR(&_10$$16);
						object_init_ex(&_10$$16, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_11$$16);
						ZEPHIR_CONCAT_SVS(&_11$$16, "Column '", &attribute, "' doesn\\'t make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_10$$16, "__construct", &_12, 4, &_11$$16);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_10$$16, "phalcon/mvc/model.zep", 546 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					} else {
						continue;
					}
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
				_13$$19 = zephir_is_true(&disableAssignSetters);
				if (!(_13$$19)) {
					ZEPHIR_CALL_METHOD(&_14$$19, this_ptr, "_possiblesetter", &_15, 314, &attributeField, &value);
					zephir_check_call_status();
					_13$$19 = !zephir_is_true(&_14$$19);
				}
				if (_13$$19) {
					zephir_update_property_zval_zval(this_ptr, &attributeField, &value TSRMLS_CC);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &_4, "current", NULL, 0);
			zephir_check_call_status();
				_16$$23 = !(zephir_array_isset(&columnMap, &attribute));
				if (_16$$23) {
					_16$$23 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
				}
				if (_16$$23) {
					ZEPHIR_CALL_SELF(&_17$$24, "caseinsensitivecolumnmap", &_9, 316, &columnMap, &attribute);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&attribute, &_17$$24);
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0 TSRMLS_CC))) {
						if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
							ZEPHIR_INIT_NVAR(&_18$$27);
							object_init_ex(&_18$$27, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_19$$27);
							ZEPHIR_CONCAT_SVS(&_19$$27, "Column '", &attribute, "' doesn\\'t make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_18$$27, "__construct", &_12, 4, &_19$$27);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_18$$27, "phalcon/mvc/model.zep", 546 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						} else {
							continue;
						}
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
					_20$$30 = zephir_is_true(&disableAssignSetters);
					if (!(_20$$30)) {
						ZEPHIR_CALL_METHOD(&_21$$30, this_ptr, "_possiblesetter", &_15, 314, &attributeField, &value);
						zephir_check_call_status();
						_20$$30 = !zephir_is_true(&_21$$30);
					}
					if (_20$$30) {
						zephir_update_property_zval_zval(this_ptr, &attributeField, &value TSRMLS_CC);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	RETURN_THIS();

}

/**
 * Returns the average value on a column for a result-set of rows matching the specified conditions
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

	zend_string *_4;
	zend_ulong _3;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *dirtyState_param = NULL, instance, key, value, _0, *_1, _2, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
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
	zephir_is_iterable(&data, 0, "phalcon/mvc/model.zep", 646);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			if (Z_TYPE_P(&key) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid key in array data provided to dumpResult()", "phalcon/mvc/model.zep", 638);
				return;
			}
			zephir_update_property_zval_zval(&instance, &key, &value TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) != IS_STRING) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid key in array data provided to dumpResult()", "phalcon/mvc/model.zep", 638);
					return;
				}
				zephir_update_property_zval_zval(&instance, &key, &value TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "afterFetch");
	ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_5);
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

	zend_string *_4;
	zend_ulong _3;
	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL;
	zend_bool keepSnapshots, _8$$4, _15$$19;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *columnMap, columnMap_sub, *dirtyState_param = NULL, *keepSnapshots_param = NULL, instance, attribute, key, value, castValue, attributeName, _0, *_1, _2, _5$$7, _6$$7, _9$$10, _10$$11, _12$$15, _13$$22, _14$$22, _16$$25, _17$$26, _18$$30, _19$$34;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_13$$22);
	ZVAL_UNDEF(&_14$$22);
	ZVAL_UNDEF(&_16$$25);
	ZVAL_UNDEF(&_17$$26);
	ZVAL_UNDEF(&_18$$30);
	ZVAL_UNDEF(&_19$$34);
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
	zephir_is_iterable(&data, 0, "phalcon/mvc/model.zep", 747);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			if (Z_TYPE_P(&key) == IS_STRING) {
				if (Z_TYPE_P(columnMap) != IS_ARRAY) {
					zephir_update_property_zval_zval(&instance, &key, &value TSRMLS_CC);
					continue;
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0 TSRMLS_CC))) {
					if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
						ZEPHIR_INIT_NVAR(&_5$$7);
						object_init_ex(&_5$$7, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_6$$7);
						ZEPHIR_CONCAT_SVS(&_6$$7, "Column '", &key, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", &_7, 4, &_6$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_5$$7, "phalcon/mvc/model.zep", 690 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					} else {
						continue;
					}
				}
				if (Z_TYPE_P(&attribute) != IS_ARRAY) {
					zephir_update_property_zval_zval(&instance, &attribute, &value TSRMLS_CC);
					continue;
				}
				_8$$4 = !ZEPHIR_IS_STRING(&value, "");
				if (_8$$4) {
					_8$$4 = Z_TYPE_P(&value) != IS_NULL;
				}
				if (_8$$4) {
					zephir_array_fetch_long(&_9$$10, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 702 TSRMLS_CC);
					do {
						if (ZEPHIR_IS_LONG(&_9$$10, 0)) {
							ZVAL_LONG(&_10$$11, 10);
							ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_11, 22, &value, &_10$$11);
							zephir_check_call_status();
							break;
						}
						if (ZEPHIR_IS_LONG(&_9$$10, 9) || ZEPHIR_IS_LONG(&_9$$10, 3) || ZEPHIR_IS_LONG(&_9$$10, 7)) {
							ZEPHIR_INIT_NVAR(&castValue);
							ZVAL_DOUBLE(&castValue, zephir_get_doubleval(&value));
							break;
						}
						if (ZEPHIR_IS_LONG(&_9$$10, 8)) {
							ZEPHIR_INIT_NVAR(&castValue);
							ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
							break;
						}
						ZEPHIR_CPY_WRT(&castValue, &value);
						break;
					} while(0);

				} else {
					zephir_array_fetch_long(&_12$$15, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 723 TSRMLS_CC);
					do {
						if (ZEPHIR_IS_LONG(&_12$$15, 0) || ZEPHIR_IS_LONG(&_12$$15, 9) || ZEPHIR_IS_LONG(&_12$$15, 3) || ZEPHIR_IS_LONG(&_12$$15, 7) || ZEPHIR_IS_LONG(&_12$$15, 8)) {
							ZEPHIR_INIT_NVAR(&castValue);
							ZVAL_NULL(&castValue);
							break;
						}
						ZEPHIR_CPY_WRT(&castValue, &value);
						break;
					} while(0);

				}
				ZEPHIR_OBS_NVAR(&attributeName);
				zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/mvc/model.zep", 739 TSRMLS_CC);
				zephir_update_property_zval_zval(&instance, &attributeName, &castValue TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) == IS_STRING) {
					if (Z_TYPE_P(columnMap) != IS_ARRAY) {
						zephir_update_property_zval_zval(&instance, &key, &value TSRMLS_CC);
						continue;
					}
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0 TSRMLS_CC))) {
						if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
							ZEPHIR_INIT_NVAR(&_13$$22);
							object_init_ex(&_13$$22, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_14$$22);
							ZEPHIR_CONCAT_SVS(&_14$$22, "Column '", &key, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_13$$22, "__construct", &_7, 4, &_14$$22);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_13$$22, "phalcon/mvc/model.zep", 690 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						} else {
							continue;
						}
					}
					if (Z_TYPE_P(&attribute) != IS_ARRAY) {
						zephir_update_property_zval_zval(&instance, &attribute, &value TSRMLS_CC);
						continue;
					}
					_15$$19 = !ZEPHIR_IS_STRING(&value, "");
					if (_15$$19) {
						_15$$19 = Z_TYPE_P(&value) != IS_NULL;
					}
					if (_15$$19) {
						zephir_array_fetch_long(&_16$$25, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 702 TSRMLS_CC);
						do {
							if (ZEPHIR_IS_LONG(&_16$$25, 0)) {
								ZVAL_LONG(&_17$$26, 10);
								ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_11, 22, &value, &_17$$26);
								zephir_check_call_status();
								break;
							}
							if (ZEPHIR_IS_LONG(&_16$$25, 9) || ZEPHIR_IS_LONG(&_16$$25, 3) || ZEPHIR_IS_LONG(&_16$$25, 7)) {
								ZEPHIR_INIT_NVAR(&castValue);
								ZVAL_DOUBLE(&castValue, zephir_get_doubleval(&value));
								break;
							}
							if (ZEPHIR_IS_LONG(&_16$$25, 8)) {
								ZEPHIR_INIT_NVAR(&castValue);
								ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
								break;
							}
							ZEPHIR_CPY_WRT(&castValue, &value);
							break;
						} while(0);

					} else {
						zephir_array_fetch_long(&_18$$30, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 723 TSRMLS_CC);
						do {
							if (ZEPHIR_IS_LONG(&_18$$30, 0) || ZEPHIR_IS_LONG(&_18$$30, 9) || ZEPHIR_IS_LONG(&_18$$30, 3) || ZEPHIR_IS_LONG(&_18$$30, 7) || ZEPHIR_IS_LONG(&_18$$30, 8)) {
								ZEPHIR_INIT_NVAR(&castValue);
								ZVAL_NULL(&castValue);
								break;
							}
							ZEPHIR_CPY_WRT(&castValue, &value);
							break;
						} while(0);

					}
					ZEPHIR_OBS_NVAR(&attributeName);
					zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/mvc/model.zep", 739 TSRMLS_CC);
					zephir_update_property_zval_zval(&instance, &attributeName, &castValue TSRMLS_CC);
				}
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (keepSnapshots) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "setsnapshotdata", NULL, 0, &data, columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &instance, "setoldsnapshotdata", NULL, 0, &data, columnMap);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(&instance, SL("fireevent") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_19$$34);
		ZVAL_STRING(&_19$$34, "afterFetch");
		ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_19$$34);
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

	zend_bool _4$$9, _10$$23;
	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	zend_long hydrationMode, ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap, columnMap_sub, *hydrationMode_param = NULL, hydrateArray, hydrateObject, key, value, attribute, attributeName, *_0, _1, _5$$10, _7$$12, _8$$12, _11$$24, _12$$26, _13$$26;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&hydrateArray);
	ZVAL_UNDEF(&hydrateObject);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&attributeName);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_11$$24);
	ZVAL_UNDEF(&_12$$26);
	ZVAL_UNDEF(&_13$$26);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data_param, &columnMap, &hydrationMode_param);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	hydrationMode = zephir_get_intval(hydrationMode_param);


	if (Z_TYPE_P(columnMap) != IS_ARRAY) {
		if (hydrationMode == 1) {
			RETURN_CTOR(&data);
		}
	}
	if (hydrationMode == 1) {
		ZEPHIR_INIT_VAR(&hydrateArray);
		array_init(&hydrateArray);
	} else {
		ZEPHIR_INIT_VAR(&hydrateObject);
		object_init(&hydrateObject);
	}
	zephir_is_iterable(&data, 0, "phalcon/mvc/model.zep", 836);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (Z_TYPE_P(&key) != IS_STRING) {
				continue;
			}
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				_4$$9 = !(zephir_array_isset(columnMap, &key));
				if (_4$$9) {
					_4$$9 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
				}
				if (_4$$9) {
					ZEPHIR_CALL_SELF(&_5$$10, "caseinsensitivecolumnmap", &_6, 316, columnMap, &key);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&key, &_5$$10);
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0 TSRMLS_CC))) {
					if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
						ZEPHIR_INIT_NVAR(&_7$$12);
						object_init_ex(&_7$$12, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_8$$12);
						ZEPHIR_CONCAT_SVS(&_8$$12, "Column '", &key, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_7$$12, "__construct", &_9, 4, &_8$$12);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_7$$12, "phalcon/mvc/model.zep", 807 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					} else {
						continue;
					}
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeName);
					zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/mvc/model.zep", 817 TSRMLS_CC);
				} else {
					ZEPHIR_CPY_WRT(&attributeName, &attribute);
				}
				if (hydrationMode == 1) {
					zephir_array_update_zval(&hydrateArray, &attributeName, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_update_property_zval_zval(&hydrateObject, &attributeName, &value TSRMLS_CC);
				}
			} else {
				if (hydrationMode == 1) {
					zephir_array_update_zval(&hydrateArray, &key, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_update_property_zval_zval(&hydrateObject, &key, &value TSRMLS_CC);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) != IS_STRING) {
					continue;
				}
				if (Z_TYPE_P(columnMap) == IS_ARRAY) {
					_10$$23 = !(zephir_array_isset(columnMap, &key));
					if (_10$$23) {
						_10$$23 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
					}
					if (_10$$23) {
						ZEPHIR_CALL_SELF(&_11$$24, "caseinsensitivecolumnmap", &_6, 316, columnMap, &key);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&key, &_11$$24);
					}
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0 TSRMLS_CC))) {
						if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
							ZEPHIR_INIT_NVAR(&_12$$26);
							object_init_ex(&_12$$26, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_13$$26);
							ZEPHIR_CONCAT_SVS(&_13$$26, "Column '", &key, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_12$$26, "__construct", &_9, 4, &_13$$26);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_12$$26, "phalcon/mvc/model.zep", 807 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						} else {
							continue;
						}
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeName);
						zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/mvc/model.zep", 817 TSRMLS_CC);
					} else {
						ZEPHIR_CPY_WRT(&attributeName, &attribute);
					}
					if (hydrationMode == 1) {
						zephir_array_update_zval(&hydrateArray, &attributeName, &value, PH_COPY | PH_SEPARATE);
					} else {
						zephir_update_property_zval_zval(&hydrateObject, &attributeName, &value TSRMLS_CC);
					}
				} else {
					if (hydrationMode == 1) {
						zephir_array_update_zval(&hydrateArray, &key, &value, PH_COPY | PH_SEPARATE);
					} else {
						zephir_update_property_zval_zval(&hydrateObject, &key, &value TSRMLS_CC);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (hydrationMode == 1) {
		RETURN_CCTOR(&hydrateArray);
	}
	RETURN_CCTOR(&hydrateObject);

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
 * Inserts a model instance. If the instance already exists in the persistence it will throw an exception
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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getreadconnection", NULL, 0);
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
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 300, &_4$$3, &_5$$3, &_6$$3);
		zephir_check_call_status();
		zephir_array_fast_append(&_2$$3, &_3$$3);
		zephir_update_property_zval(this_ptr, SL("_errorMessages"), &_2$$3);
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

	zval __$true, __$false, metaData, writeConnection, values, bindTypes, primaryKeys, bindDataTypes, columnMap, attributeField, conditions, primaryKey, bindType, value, schema, source, table, success, _0, _1, *_3, _4, _27, _2$$3, _5$$9, _6$$9, _8$$11, _9$$11, _10$$13, _11$$13, _12$$8, _14$$8, _15$$15, _16$$15, _17$$17, _18$$17, _19$$19, _20$$19, _21$$14, _23$$14, _24$$20, _25$$20, _26$$22, _28$$26, _29$$29;
	zephir_fcall_cache_entry *_7 = NULL, *_13 = NULL, *_22 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&writeConnection);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&primaryKey);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$19);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_26$$22);
	ZVAL_UNDEF(&_28$$26);
	ZVAL_UNDEF(&_29$$29);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 3);
	zephir_update_property_zval(this_ptr, SL("_operationMade"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, SL("_errorMessages"), &_1);
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "_checkforeignkeysreverserestrict", NULL, 317);
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
	if (!(zephir_fast_count_int(&primaryKeys TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation", "phalcon/mvc/model.zep", 979);
		return;
	}
	zephir_is_iterable(&primaryKeys, 0, "phalcon/mvc/model.zep", 1022);
	if (Z_TYPE_P(&primaryKeys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _3)
		{
			ZEPHIR_INIT_NVAR(&primaryKey);
			ZVAL_COPY(&primaryKey, _3);
			ZEPHIR_OBS_NVAR(&bindType);
			if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryKey, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(&_5$$9);
				object_init_ex(&_5$$9, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_6$$9);
				ZEPHIR_CONCAT_SVS(&_6$$9, "Column '", &primaryKey, "' have not defined a bind data type");
				ZEPHIR_CALL_METHOD(NULL, &_5$$9, "__construct", &_7, 4, &_6$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$9, "phalcon/mvc/model.zep", 991 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_8$$11);
					object_init_ex(&_8$$11, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_9$$11);
					ZEPHIR_CONCAT_SVS(&_9$$11, "Column '", &primaryKey, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_8$$11, "__construct", &_7, 4, &_9$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$11, "phalcon/mvc/model.zep", 999 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
			}
			ZEPHIR_OBS_NVAR(&value);
			if (!(zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC))) {
				ZEPHIR_INIT_NVAR(&_10$$13);
				object_init_ex(&_10$$13, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_11$$13);
				ZEPHIR_CONCAT_SVS(&_11$$13, "Cannot delete the record because the primary key attribute: '", &attributeField, "' wasn't set");
				ZEPHIR_CALL_METHOD(NULL, &_10$$13, "__construct", &_7, 4, &_11$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_10$$13, "phalcon/mvc/model.zep", 1011 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 1017);
			ZEPHIR_CALL_METHOD(&_12$$8, &writeConnection, "escapeidentifier", &_13, 0, &primaryKey);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_14$$8);
			ZEPHIR_CONCAT_VS(&_14$$8, &_12$$8, " = ?");
			zephir_array_append(&conditions, &_14$$8, PH_SEPARATE, "phalcon/mvc/model.zep", 1018);
			zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 1019);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &primaryKeys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&primaryKey, &primaryKeys, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&bindType);
				if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryKey, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_15$$15);
					object_init_ex(&_15$$15, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_16$$15);
					ZEPHIR_CONCAT_SVS(&_16$$15, "Column '", &primaryKey, "' have not defined a bind data type");
					ZEPHIR_CALL_METHOD(NULL, &_15$$15, "__construct", &_7, 4, &_16$$15);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_15$$15, "phalcon/mvc/model.zep", 991 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(&_17$$17);
						object_init_ex(&_17$$17, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_18$$17);
						ZEPHIR_CONCAT_SVS(&_18$$17, "Column '", &primaryKey, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_17$$17, "__construct", &_7, 4, &_18$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_17$$17, "phalcon/mvc/model.zep", 999 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
				}
				ZEPHIR_OBS_NVAR(&value);
				if (!(zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC))) {
					ZEPHIR_INIT_NVAR(&_19$$19);
					object_init_ex(&_19$$19, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_20$$19);
					ZEPHIR_CONCAT_SVS(&_20$$19, "Cannot delete the record because the primary key attribute: '", &attributeField, "' wasn't set");
					ZEPHIR_CALL_METHOD(NULL, &_19$$19, "__construct", &_7, 4, &_20$$19);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_19$$19, "phalcon/mvc/model.zep", 1011 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 1017);
				ZEPHIR_CALL_METHOD(&_21$$14, &writeConnection, "escapeidentifier", &_22, 0, &primaryKey);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_23$$14);
				ZEPHIR_CONCAT_VS(&_23$$14, &_21$$14, " = ?");
				zephir_array_append(&conditions, &_23$$14, PH_SEPARATE, "phalcon/mvc/model.zep", 1018);
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 1019);
			ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&primaryKey);
	if (ZEPHIR_GLOBAL(orm).events) {
		if (0) {
			zephir_update_property_zval(this_ptr, SL("_skipped"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_skipped"), &__$false);
		}
		ZEPHIR_INIT_VAR(&_25$$20);
		ZVAL_STRING(&_25$$20, "beforeDelete");
		ZEPHIR_CALL_METHOD(&_24$$20, this_ptr, "fireeventcancel", NULL, 0, &_25$$20);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_24$$20)) {
			RETURN_MM_BOOL(0);
		} else {
			zephir_read_property(&_26$$22, this_ptr, SL("_skipped"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_26$$22)) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_INIT_VAR(&_27);
	zephir_fast_join_str(&_27, SL(" AND "), &conditions TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&success, &writeConnection, "delete", NULL, 0, &table, &_27, &values, &bindTypes);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_28$$26, this_ptr, "_checkforeignkeysreversecascade", NULL, 318);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_28$$26)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (zephir_is_true(&success)) {
			ZEPHIR_INIT_VAR(&_29$$29);
			ZVAL_STRING(&_29$$29, "afterDelete");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_29$$29);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 2);
	zephir_update_property_zval(this_ptr, SL("_dirtyState"), &_0);
	RETURN_CCTOR(&success);

}

/**
 * Returns a simple representation of the object that can be used with var_dump
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

	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 14, this_ptr);
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
 *	 echo $robot->name, "\n";
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
 *	 echo $robot->name, "\n";
 * }
 *
 * // encapsulate find it into an running transaction esp. useful for application unit-tests
 * // or complex business logic where we wanna control which transactions are used.
 *
 * $myTransaction = new Transaction(\Phalcon\Di::getDefault());
 * $myTransaction->begin();
 * $newRobot = new Robot();
 * $newRobot->setTransaction($myTransaction);
 * $newRobot->save(['name' => 'test', 'type' => 'mechanical', 'year' => 1944]);
 *
 * $resultInsideTransaction = Robot::find(['name' => 'test', Model::TRANSACTION_INDEX => $myTransaction]);
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
 * $firstNewRobot->save(['name' => 'first-transaction-robot', 'type' => 'mechanical', 'year' => 1944]);
 *
 * $secondNewRobot = new Robot();
 * $secondNewRobot->setTransaction($myTransaction2);
 * $secondNewRobot->save(['name' => 'second-transaction-robot', 'type' => 'fictional', 'year' => 1984]);
 *
 * // this transaction will find the robot.
 * $resultInFirstTransaction = Robot::find(['name' => 'first-transaction-robot', Model::TRANSACTION_INDEX => $myTransaction1]);
 * // this transaction won't find the robot.
 * $resultInSecondTransaction = Robot::find(['name' => 'first-transaction-robot', Model::TRANSACTION_INDEX => $myTransaction2]);
 * // this transaction won't find the robot.
 * $resultOutsideAnyExplicitTransaction = Robot::find(['name' => 'first-transaction-robot']);
 *
 * // this transaction won't find the robot.
 * $resultInFirstTransaction = Robot::find(['name' => 'second-transaction-robot', Model::TRANSACTION_INDEX => $myTransaction2]);
 * // this transaction will find the robot.
 * $resultInSecondTransaction = Robot::find(['name' => 'second-transaction-robot', Model::TRANSACTION_INDEX => $myTransaction1]);
 * // this transaction won't find the robot.
 * $resultOutsideAnyExplicitTransaction = Robot::find(['name' => 'second-transaction-robot']);
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
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/mvc/model.zep", 1197);
		}
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_CALL_STATIC(&query, "getpreparedquery", &_0, 319, &params);
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
 * $newRobot = new Robot();
 * $newRobot->setTransaction($myTransaction);
 * $newRobot->save(['name' => 'test', 'type' => 'mechanical', 'year' => 1944]);
 *
 * $findsARobot = Robot::findFirst(['name' => 'test', Model::TRANSACTION_INDEX => $myTransaction]);
 * $doesNotFindARobot = Robot::findFirst(['name' => 'test']);
 *
 * var_dump($findARobot);
 * var_dump($doesNotFindARobot);
 *
 * $transaction->commit();
 * $doesFindTheRobotNow = Robot::findFirst(['name' => 'test']);
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
		_0 = 1 == zephir_is_numeric(parameters);
	}
	if (Z_TYPE_P(parameters) == IS_NULL) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else if (Z_TYPE_P(parameters) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&params, parameters);
	} else if (_0) {
		ZEPHIR_INIT_NVAR(&params);
		array_init(&params);
		zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/mvc/model.zep", 1277);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Parameters passed must be of type array, string, numeric or null", "phalcon/mvc/model.zep", 1279);
		return;
	}
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_STATIC(&query, "getpreparedquery", &_1, 319, &params, &_2);
	zephir_check_call_status();
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_CALL_METHOD(NULL, &query, "setuniquerow", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&query, "execute", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
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
	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "notifyevent", NULL, 0, &eventName, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 * This method stops if one of the callbacks/listeners returns bool false
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEventCancel) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, _0$$3, _1, _2;
	zval eventName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

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
	zephir_read_property(&_1, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "notifyevent", NULL, 0, &eventName, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_2)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

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
	zval metaData, changed, name, snapshot, columnMap, allAttributes, value, _0, *_1, _2, _5$$6, _6$$10;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&changed);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&allAttributes);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$10);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&snapshot);
	zephir_read_property(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
	if (Z_TYPE_P(&snapshot) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record doesn't have a valid data snapshot", "phalcon/mvc/model.zep", 1358);
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
	ZEPHIR_INIT_VAR(&_0);
	zephir_is_iterable(&allAttributes, 0, "phalcon/mvc/model.zep", 1411);
	if (Z_TYPE_P(&allAttributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&allAttributes), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&_0);
			ZVAL_COPY(&_0, _1);
			if (!(zephir_array_isset(&snapshot, &name))) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/mvc/model.zep", 1390);
				continue;
			}
			ZEPHIR_OBS_NVAR(&value);
			if (!(zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC))) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/mvc/model.zep", 1398);
				continue;
			}
			zephir_array_fetch(&_5$$6, &snapshot, &name, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1405 TSRMLS_CC);
			if (!ZEPHIR_IS_IDENTICAL(&value, &_5$$6)) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/mvc/model.zep", 1406);
				continue;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &allAttributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &allAttributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &allAttributes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_0, &allAttributes, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_array_isset(&snapshot, &name))) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/mvc/model.zep", 1390);
					continue;
				}
				ZEPHIR_OBS_NVAR(&value);
				if (!(zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC))) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/mvc/model.zep", 1398);
					continue;
				}
				zephir_array_fetch(&_6$$10, &snapshot, &name, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1405 TSRMLS_CC);
				if (!ZEPHIR_IS_IDENTICAL(&value, &_6$$10)) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/mvc/model.zep", 1406);
					continue;
				}
			ZEPHIR_CALL_METHOD(NULL, &allAttributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&changed);

}

/**
 * Returns one of the DIRTY_STATE_* constants telling if the record exists in the database or not
 */
PHP_METHOD(Phalcon_Mvc_Model, getDirtyState) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_dirtyState");

}

/**
 * Returns the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_dependencyInjector");

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

	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filter = NULL, filter_sub, __$null, filtered, message, _1$$3, *_2$$3, _3$$3, _4$$4, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$6);

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
		zephir_read_property(&_1$$3, this_ptr, SL("_errorMessages"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "phalcon/mvc/model.zep", 1472);
		if (Z_TYPE_P(&_1$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$3), _2$$3)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _2$$3);
				ZEPHIR_CALL_METHOD(&_4$$4, &message, "getfield", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_EQUAL(&_4$$4, filter)) {
					zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/mvc/model.zep", 1469);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$3, &_1$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&message, &_1$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_5$$6, &message, "getfield", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_EQUAL(&_5$$6, filter)) {
						zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/mvc/model.zep", 1469);
					}
				ZEPHIR_CALL_METHOD(NULL, &_1$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&message);
		RETURN_CCTOR(&filtered);
	}
	RETURN_MM_MEMBER(getThis(), "_errorMessages");

}

/**
 * Returns the models manager related to the entity instance
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_modelsManager");

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsMetaData) {

	zval metaData, dependencyInjector, _0$$3, _1$$3, _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&metaData);
	zephir_read_property(&metaData, this_ptr, SL("_modelsMetaData"), PH_NOISY_CC);
	if (Z_TYPE_P(&metaData) != IS_OBJECT) {
		zephir_read_property(&_0$$3, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&dependencyInjector, &_0$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&_1$$3, &dependencyInjector, "getshared", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&metaData, &_1$$3);
		if (Z_TYPE_P(&metaData) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsMetadata' is not valid", "phalcon/mvc/model.zep", 1503);
			return;
		}
		zephir_update_property_zval(this_ptr, SL("_modelsMetaData"), &metaData);
	}
	RETURN_CCTOR(&metaData);

}

/**
 * Returns the type of the latest operation performed by the ORM
 * Returns one of the OP_* class constants
 */
PHP_METHOD(Phalcon_Mvc_Model, getOperationMade) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_operationMade");

}

/**
 * Returns the internal old snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, getOldSnapshotData) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_oldSnapshot");

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

	zephir_read_property(&_0, this_ptr, SL("_transaction"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&transaction, &_0);
	if (Z_TYPE_P(&transaction) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(&transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getreadconnection", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the DependencyInjection connection service name used to read data related the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnectionService) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getreadconnectionservice", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns related records based on defined relations
 *
 * @param array arguments
 */
PHP_METHOD(Phalcon_Mvc_Model, getRelated) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, *arguments = NULL, arguments_sub, __$null, relation, className, manager, _0, _1, _2$$3, _3$$3;
	zval alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &alias_param, &arguments);

	zephir_get_strval(&alias, alias_param);
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, this_ptr, 0 TSRMLS_CC);
	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_1, &manager, "getrelationbyalias", NULL, 0, &className, &alias);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_1);
	if (Z_TYPE_P(&relation) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVSVS(&_3$$3, "There is no defined relations for the model '", &className, "' using alias '", &alias, "'");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 4, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/mvc/model.zep", 1570 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_NULL(&_0);
	ZEPHIR_RETURN_CALL_METHOD(&manager, "getrelationrecords", NULL, 0, &relation, &_0, this_ptr, arguments);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Mvc_Model, isRelationshipLoaded) {

	zval *relationshipAlias_param = NULL, _0;
	zval relationshipAlias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&relationshipAlias);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &relationshipAlias_param);

	zephir_get_strval(&relationshipAlias, relationshipAlias_param);


	zephir_read_property(&_0, this_ptr, SL("_related"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &relationshipAlias));

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

	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getmodelschema", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the internal snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, getSnapshotData) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_snapshot");

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

	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
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

	zend_string *_4;
	zend_ulong _3;
	zval updated, name, snapshot, oldSnapshot, value, _0, *_1, _2, _5$$6, _6$$9;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&updated);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&oldSnapshot);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$9);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&snapshot);
	zephir_read_property(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&oldSnapshot);
	zephir_read_property(&oldSnapshot, this_ptr, SL("_oldSnapshot"), PH_NOISY_CC);
	if (!(ZEPHIR_GLOBAL(orm).update_snapshot_on_save)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Update snapshot on save must be enabled for this method to work properly", "phalcon/mvc/model.zep", 1634);
		return;
	}
	if (Z_TYPE_P(&snapshot) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record doesn't have a valid data snapshot", "phalcon/mvc/model.zep", 1638);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("_dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_LONG(&_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Change checking cannot be performed because the object has not been persisted or is deleted", "phalcon/mvc/model.zep", 1645);
		return;
	}
	ZEPHIR_INIT_VAR(&updated);
	array_init(&updated);
	zephir_is_iterable(&snapshot, 0, "phalcon/mvc/model.zep", 1665);
	if (Z_TYPE_P(&snapshot) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&snapshot), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			if (!(zephir_array_isset(&oldSnapshot, &name))) {
				zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/mvc/model.zep", 1655);
				continue;
			}
			zephir_array_fetch(&_5$$6, &oldSnapshot, &name, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1659 TSRMLS_CC);
			if (!ZEPHIR_IS_IDENTICAL(&value, &_5$$6)) {
				zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/mvc/model.zep", 1660);
				continue;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &snapshot, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &snapshot, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &snapshot, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &snapshot, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_array_isset(&oldSnapshot, &name))) {
					zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/mvc/model.zep", 1655);
					continue;
				}
				zephir_array_fetch(&_6$$9, &oldSnapshot, &name, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1659 TSRMLS_CC);
				if (!ZEPHIR_IS_IDENTICAL(&value, &_6$$9)) {
					zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/mvc/model.zep", 1660);
					continue;
				}
			ZEPHIR_CALL_METHOD(NULL, &snapshot, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&updated);

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

	zephir_read_property(&_0, this_ptr, SL("_transaction"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&transaction, &_0);
	if (Z_TYPE_P(&transaction) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(&transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getwriteconnection", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the DependencyInjection connection service name used to write data related to the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnectionService) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
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
 * $robot->type = "hydraulic";
 * $hasChanged = $robot->hasChanged("type"); // returns true
 * $hasChanged = $robot->hasChanged(["type", "name"]); // returns true
 * $hasChanged = $robot->hasChanged(["type", "name", true]); // returns false
 *</code>
 *
 * @param string|array fieldName
 */
PHP_METHOD(Phalcon_Mvc_Model, hasChanged) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool allFields;
	zval *fieldName = NULL, fieldName_sub, *allFields_param = NULL, __$null, changedFields, _0$$5, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fieldName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&changedFields);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$4);

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
	} else if (Z_TYPE_P(fieldName) == IS_ARRAY) {
		if (allFields) {
			ZEPHIR_CALL_FUNCTION(&_0$$5, "array_intersect", NULL, 320, fieldName, &changedFields);
			zephir_check_call_status();
			RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(&_0$$5, fieldName));
		}
		ZEPHIR_CALL_FUNCTION(&_1$$4, "array_intersect", NULL, 320, fieldName, &changedFields);
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_fast_count_int(&_1$$4 TSRMLS_CC) > 0);
	}
	RETURN_MM_BOOL(zephir_fast_count_int(&changedFields TSRMLS_CC) > 0);

}

/**
 * Checks if the object has internal snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, hasSnapshotData) {

	zval snapshot;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&snapshot);


	zephir_read_property(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(Z_TYPE_P(&snapshot) == IS_ARRAY);

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
	zval *fieldName = NULL, fieldName_sub, *allFields_param = NULL, __$null, updatedFields, _0$$5, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fieldName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&updatedFields);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$4);

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
	} else if (Z_TYPE_P(fieldName) == IS_ARRAY) {
		if (allFields) {
			ZEPHIR_CALL_FUNCTION(&_0$$5, "array_intersect", NULL, 320, fieldName, &updatedFields);
			zephir_check_call_status();
			RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(&_0$$5, fieldName));
		}
		ZEPHIR_CALL_FUNCTION(&_1$$4, "array_intersect", NULL, 320, fieldName, &updatedFields);
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_fast_count_int(&_1$$4 TSRMLS_CC) > 0);
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
 * Returns the maximum value of a column for a result-set of rows that match the specified conditions
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
 * Returns the minimum value of a column for a result-set of rows that match the specified conditions
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
 * @return mixed
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
	zval *dependencyInjector = NULL, dependencyInjector_sub, __$null, criteria, _3, _1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&criteria);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		dependencyInjector = &dependencyInjector_sub;
		ZEPHIR_CPY_WRT(dependencyInjector, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(dependencyInjector);
	}


	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(dependencyInjector, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&criteria);
	if (zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "Phalcon\\Mvc\\Model\\Criteria");
		ZEPHIR_CALL_METHOD(&_1$$4, dependencyInjector, "get", NULL, 0, &_2$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&criteria, &_1$$4);
	} else {
		object_init_ex(&criteria, phalcon_mvc_model_criteria_ce);
		if (zephir_has_constructor(&criteria TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &criteria, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, &criteria, "setdi", NULL, 321, dependencyInjector);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_get_called_class(&_3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &criteria, "setmodelname", NULL, 322, &_3);
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

	zval _8, _6$$9, _7$$10;
	zval metaData, readConnection, schema, source, table, uniqueKey, tables, uniqueParams, dialect, row, fields, attribute, manager, columnMap, _0, _1, _3, *_4, _5, _9, _10, _12, _2$$6, _11$$11;
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
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$10);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_LONG(&_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/mvc/model.zep", 1902);
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_1);
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_OBS_VAR(&uniqueKey);
	zephir_read_property(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	if (!(zephir_is_true(&uniqueKey))) {
		ZEPHIR_CALL_METHOD(&_2$$6, this_ptr, "_exists", NULL, 0, &metaData, &readConnection, &table);
		zephir_check_call_status();
		if (!(zephir_is_true(&_2$$6))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/mvc/model.zep", 1925);
			return;
		}
		ZEPHIR_OBS_NVAR(&uniqueKey);
		zephir_read_property(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(&uniqueParams);
	zephir_read_property(&uniqueParams, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	if (Z_TYPE_P(&uniqueParams) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/mvc/model.zep", 1933);
		return;
	}
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_CALL_METHOD(&_3, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_3, 0, "phalcon/mvc/model.zep", 1947);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _4)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _4);
			ZEPHIR_INIT_NVAR(&_6$$9);
			zephir_create_array(&_6$$9, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_6$$9, &attribute);
			zephir_array_append(&fields, &_6$$9, PH_SEPARATE, "phalcon/mvc/model.zep", 1941);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &_3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$10);
				zephir_create_array(&_7$$10, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(&_7$$10, &attribute);
				zephir_array_append(&fields, &_7$$10, PH_SEPARATE, "phalcon/mvc/model.zep", 1941);
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&dialect, &readConnection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	zephir_create_array(&_8, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_8, SL("columns"), &fields, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_9, &readConnection, "escapeidentifier", NULL, 0, &table);
	zephir_check_call_status();
	zephir_array_update_string(&_8, SL("tables"), &_9, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_8, SL("where"), &uniqueKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&tables, &dialect, "select", NULL, 0, &_8);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_10, 2);
	ZEPHIR_CALL_METHOD(&row, &readConnection, "fetchone", NULL, 0, &tables, &_10, &uniqueParams, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&row) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, &row, &columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_11$$11, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_11$$11)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsnapshotdata", NULL, 0, &row, &columnMap);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoldsnapshotdata", NULL, 0, &row, &columnMap);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "afterFetch");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_12);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Inserts or updates a model instance. Returning true on success or false otherwise.
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

	zval metaData, related, schema, writeConnection, readConnection, source, table, identityField, exists, success, _0, _4, _1$$3, _2$$7, _3$$8, _5$$10, _6$$11, _7$$11, _8$$14, _9$$16, _10$$18, _11$$20;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&related);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&writeConnection);
	ZVAL_UNDEF(&readConnection);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&identityField);
	ZVAL_UNDEF(&exists);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_9$$16);
	ZVAL_UNDEF(&_10$$18);
	ZVAL_UNDEF(&_11$$20);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "prepareSave");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&related);
	zephir_read_property(&related, this_ptr, SL("_related"), PH_NOISY_CC);
	if (Z_TYPE_P(&related) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "_presaverelatedrecords", NULL, 0, &writeConnection, &related);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&exists, this_ptr, "_exists", NULL, 0, &metaData, &readConnection, &table);
	zephir_check_call_status();
	if (zephir_is_true(&exists)) {
		ZEPHIR_INIT_ZVAL_NREF(_2$$7);
		ZVAL_LONG(&_2$$7, 2);
		zephir_update_property_zval(this_ptr, SL("_operationMade"), &_2$$7);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_3$$8);
		ZVAL_LONG(&_3$$8, 1);
		zephir_update_property_zval(this_ptr, SL("_operationMade"), &_3$$8);
	}
	ZEPHIR_INIT_NVAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("_errorMessages"), &_0);
	ZEPHIR_CALL_METHOD(&identityField, &metaData, "getidentityfield", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "_presave", NULL, 0, &metaData, &exists, &identityField);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_4)) {
		if (Z_TYPE_P(&related) == IS_ARRAY) {
			ZVAL_BOOL(&_5$$10, 0);
			ZEPHIR_CALL_METHOD(NULL, &writeConnection, "rollback", NULL, 0, &_5$$10);
			zephir_check_call_status();
		}
		if (ZEPHIR_GLOBAL(orm).exception_on_failed_save) {
			ZEPHIR_INIT_VAR(&_6$$11);
			object_init_ex(&_6$$11, phalcon_mvc_model_validationfailed_ce);
			ZEPHIR_CALL_METHOD(&_7$$11, this_ptr, "getmessages", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_6$$11, "__construct", NULL, 323, this_ptr, &_7$$11);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$11, "phalcon/mvc/model.zep", 2075 TSRMLS_CC);
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
		ZEPHIR_INIT_ZVAL_NREF(_8$$14);
		ZVAL_LONG(&_8$$14, 0);
		zephir_update_property_zval(this_ptr, SL("_dirtyState"), &_8$$14);
	}
	if (Z_TYPE_P(&related) == IS_ARRAY) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
			ZVAL_BOOL(&_9$$16, 0);
			ZEPHIR_CALL_METHOD(NULL, &writeConnection, "rollback", NULL, 0, &_9$$16);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&success, this_ptr, "_postsaverelatedrecords", NULL, 0, &writeConnection, &related);
			zephir_check_call_status();
		}
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		ZEPHIR_CALL_METHOD(&_10$$18, this_ptr, "_postsave", NULL, 0, &success, &exists);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&success, &_10$$18);
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_11$$20);
		ZVAL_STRING(&_11$$20, "afterSave");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_11$$20);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&success);

}

/**
 * Serializes the object ignoring connections, services, related objects or static properties
 */
PHP_METHOD(Phalcon_Mvc_Model, serialize) {

	zval _2$$4;
	zend_bool _1$$3;
	zval attributes, snapshot, manager, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&attributes, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_0, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_OBS_VAR(&snapshot);
		zephir_read_property(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
		_1$$3 = Z_TYPE_P(&snapshot) != IS_NULL;
		if (_1$$3) {
			_1$$3 = !ZEPHIR_IS_EQUAL(&attributes, &snapshot);
		}
		if (_1$$3) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_create_array(&_2$$4, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&_2$$4, SL("_attributes"), &attributes, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_2$$4, SL("_snapshot"), &snapshot, PH_COPY | PH_SEPARATE);
			ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 50, &_2$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 50, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes the object from a serialized string
 */
PHP_METHOD(Phalcon_Mvc_Model, unserialize) {

	zend_string *_7$$3;
	zend_ulong _6$$3;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, attributes, dependencyInjector, manager, key, value, snapshot, _1$$3, _2$$3, *_4$$3, _5$$3, _3$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_3$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_FUNCTION(&attributes, "unserialize", NULL, 51, data);
	zephir_check_call_status();
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model.zep", 2170);
			return;
		}
		zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), &dependencyInjector);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "modelsManager");
		ZEPHIR_CALL_METHOD(&_1$$3, &dependencyInjector, "getshared", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&manager, &_1$$3);
		if (Z_TYPE_P(&manager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/mvc/model.zep", 2183);
			return;
		}
		zephir_update_property_zval(this_ptr, SL("_modelsManager"), &manager);
		ZEPHIR_CALL_METHOD(NULL, &manager, "initialize", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$3)) {
			if (zephir_array_isset_string_fetch(&snapshot, &attributes, SL("_snapshot"), 1)) {
				zephir_update_property_zval(this_ptr, SL("_snapshot"), &snapshot);
				zephir_array_fetch_string(&_3$$7, &attributes, SL("_attributes"), PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 2198 TSRMLS_CC);
				ZEPHIR_CPY_WRT(&attributes, &_3$$7);
			} else {
				zephir_update_property_zval(this_ptr, SL("_snapshot"), &attributes);
			}
		}
		zephir_is_iterable(&attributes, 0, "phalcon/mvc/model.zep", 2211);
		if (Z_TYPE_P(&attributes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _6$$3, _7$$3, _4$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_7$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _7$$3);
				} else {
					ZVAL_LONG(&key, _6$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _4$$3);
				zephir_update_property_zval_zval(this_ptr, &key, &value TSRMLS_CC);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$3, &attributes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &attributes, "current", NULL, 0);
				zephir_check_call_status();
					zephir_update_property_zval_zval(this_ptr, &key, &value TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
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


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
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
	zephir_update_property_zval(this_ptr, SL("_dirtyState"), &_0);
	RETURN_THISW();

}

/**
 * Sets the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

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



	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
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


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setreadconnectionservice", NULL, 0, this_ptr, &connectionService);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets the record's old snapshot data.
 * This method is used internally to set old snapshot data when the model was set up to keep snapshot data
 *
 * @param array data
 * @param array columnMap
 */
PHP_METHOD(Phalcon_Mvc_Model, setOldSnapshotData) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, snapshot, attribute, *_0$$3, _1$$3, _4$$7, _5$$7, _7$$11, _8$$11, _9$$16, _10$$16, _11$$20, _12$$20;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$16);
	ZVAL_UNDEF(&_10$$16);
	ZVAL_UNDEF(&_11$$20);
	ZVAL_UNDEF(&_12$$20);

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
		zephir_is_iterable(&data, 0, "phalcon/mvc/model.zep", 2300);
		if (Z_TYPE_P(&data) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _3$$3);
				} else {
					ZVAL_LONG(&key, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				if (Z_TYPE_P(&key) != IS_STRING) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0 TSRMLS_CC))) {
					if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
						ZEPHIR_INIT_NVAR(&_4$$7);
						object_init_ex(&_4$$7, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_5$$7);
						ZEPHIR_CONCAT_SVS(&_5$$7, "Column '", &key, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", &_6, 4, &_5$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_4$$7, "phalcon/mvc/model.zep", 2284 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					} else {
						continue;
					}
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0 TSRMLS_CC))) {
						if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
							ZEPHIR_INIT_NVAR(&_7$$11);
							object_init_ex(&_7$$11, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_8$$11);
							ZEPHIR_CONCAT_SVS(&_8$$11, "Column '", &key, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_7$$11, "__construct", &_6, 4, &_8$$11);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_7$$11, "phalcon/mvc/model.zep", 2292 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						} else {
							continue;
						}
					}
				}
				zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&key) != IS_STRING) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0 TSRMLS_CC))) {
						if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
							ZEPHIR_INIT_NVAR(&_9$$16);
							object_init_ex(&_9$$16, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_10$$16);
							ZEPHIR_CONCAT_SVS(&_10$$16, "Column '", &key, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_9$$16, "__construct", &_6, 4, &_10$$16);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_9$$16, "phalcon/mvc/model.zep", 2284 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						} else {
							continue;
						}
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attribute);
						if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0 TSRMLS_CC))) {
							if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
								ZEPHIR_INIT_NVAR(&_11$$20);
								object_init_ex(&_11$$20, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_LNVAR(_12$$20);
								ZEPHIR_CONCAT_SVS(&_12$$20, "Column '", &key, "' doesn't make part of the column map");
								ZEPHIR_CALL_METHOD(NULL, &_11$$20, "__construct", &_6, 4, &_12$$20);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_11$$20, "phalcon/mvc/model.zep", 2292 TSRMLS_CC);
								ZEPHIR_MM_RESTORE();
								return;
							} else {
								continue;
							}
						}
					}
					zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_CPY_WRT(&snapshot, &data);
	}
	zephir_update_property_zval(this_ptr, SL("_oldSnapshot"), &snapshot);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the record's snapshot data.
 * This method is used internally to set snapshot data when the model was set up to keep snapshot data
 *
 * @param array columnMap
 */
PHP_METHOD(Phalcon_Mvc_Model, setSnapshotData) {

	zend_bool _4$$4, _12$$14;
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, snapshot, attribute, *_0$$3, _1$$3, _5$$6, _7$$8, _8$$8, _10$$12, _11$$12, _13$$16, _14$$18, _15$$18, _16$$22, _17$$22;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_14$$18);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_16$$22);
	ZVAL_UNDEF(&_17$$22);

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
		zephir_is_iterable(&data, 0, "phalcon/mvc/model.zep", 2360);
		if (Z_TYPE_P(&data) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _3$$3);
				} else {
					ZVAL_LONG(&key, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				if (Z_TYPE_P(&key) != IS_STRING) {
					continue;
				}
				_4$$4 = !(zephir_array_isset(columnMap, &key));
				if (_4$$4) {
					_4$$4 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
				}
				if (_4$$4) {
					ZEPHIR_CALL_SELF(&_5$$6, "caseinsensitivecolumnmap", &_6, 316, columnMap, &key);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&key, &_5$$6);
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0 TSRMLS_CC))) {
					if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
						ZEPHIR_INIT_NVAR(&_7$$8);
						object_init_ex(&_7$$8, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_8$$8);
						ZEPHIR_CONCAT_SVS(&_8$$8, "Column '", &key, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_7$$8, "__construct", &_9, 4, &_8$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_7$$8, "phalcon/mvc/model.zep", 2342 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					} else {
						continue;
					}
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0 TSRMLS_CC))) {
						if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
							ZEPHIR_INIT_NVAR(&_10$$12);
							object_init_ex(&_10$$12, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_11$$12);
							ZEPHIR_CONCAT_SVS(&_11$$12, "Column '", &key, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_10$$12, "__construct", &_9, 4, &_11$$12);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_10$$12, "phalcon/mvc/model.zep", 2351 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						} else {
							continue;
						}
					}
				}
				zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&key) != IS_STRING) {
						continue;
					}
					_12$$14 = !(zephir_array_isset(columnMap, &key));
					if (_12$$14) {
						_12$$14 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
					}
					if (_12$$14) {
						ZEPHIR_CALL_SELF(&_13$$16, "caseinsensitivecolumnmap", &_6, 316, columnMap, &key);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&key, &_13$$16);
					}
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0 TSRMLS_CC))) {
						if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
							ZEPHIR_INIT_NVAR(&_14$$18);
							object_init_ex(&_14$$18, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_15$$18);
							ZEPHIR_CONCAT_SVS(&_15$$18, "Column '", &key, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_14$$18, "__construct", &_9, 4, &_15$$18);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_14$$18, "phalcon/mvc/model.zep", 2342 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						} else {
							continue;
						}
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attribute);
						if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0 TSRMLS_CC))) {
							if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
								ZEPHIR_INIT_NVAR(&_16$$22);
								object_init_ex(&_16$$22, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_LNVAR(_17$$22);
								ZEPHIR_CONCAT_SVS(&_17$$22, "Column '", &key, "' doesn't make part of the column map");
								ZEPHIR_CALL_METHOD(NULL, &_16$$22, "__construct", &_9, 4, &_17$$22);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_16$$22, "phalcon/mvc/model.zep", 2351 TSRMLS_CC);
								ZEPHIR_MM_RESTORE();
								return;
							} else {
								continue;
							}
						}
					}
					zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_CPY_WRT(&snapshot, &data);
	}
	zephir_update_property_zval(this_ptr, SL("_snapshot"), &snapshot);
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



	zephir_update_property_zval(this_ptr, SL("_transaction"), transaction);
	RETURN_THISW();

}

/**
 * Enables/disables options in the ORM
 */
PHP_METHOD(Phalcon_Mvc_Model, setup) {

	zval *options_param = NULL, disableEvents, columnRenaming, notNullValidations, exceptionOnFailedSave, phqlLiterals, virtualForeignKeys, lateStateBinding, castOnHydrate, ignoreUnknownColumns, updateSnapshotOnSave, disableAssignSetters, caseInsensitiveColumnMap;
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


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
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
		zephir_update_property_zval(this_ptr, SL("_skipped"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_skipped"), &__$false);
	}

}

/**
 * Calculates the sum on a column for a result-set of rows that match the specified conditions
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

	zend_bool _3$$4, _9$$15;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columns = NULL, columns_sub, __$null, data, metaData, columnMap, attribute, attributeField, value, _0, *_1, _2, _4$$5, _6$$7, _7$$7, _10$$16, _11$$18, _12$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_10$$16);
	ZVAL_UNDEF(&_11$$18);
	ZVAL_UNDEF(&_12$$18);

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
	zephir_is_iterable(&_0, 0, "phalcon/mvc/model.zep", 2603);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _1);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				_3$$4 = !(zephir_array_isset(&columnMap, &attribute));
				if (_3$$4) {
					_3$$4 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
				}
				if (_3$$4) {
					ZEPHIR_CALL_SELF(&_4$$5, "caseinsensitivecolumnmap", &_5, 316, &columnMap, &attribute);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&attribute, &_4$$5);
				}
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0 TSRMLS_CC))) {
					if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
						ZEPHIR_INIT_NVAR(&_6$$7);
						object_init_ex(&_6$$7, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_7$$7);
						ZEPHIR_CONCAT_SVS(&_7$$7, "Column '", &attribute, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", &_8, 4, &_7$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_6$$7, "phalcon/mvc/model.zep", 2581 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					} else {
						continue;
					}
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
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					_9$$15 = !(zephir_array_isset(&columnMap, &attribute));
					if (_9$$15) {
						_9$$15 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
					}
					if (_9$$15) {
						ZEPHIR_CALL_SELF(&_10$$16, "caseinsensitivecolumnmap", &_5, 316, &columnMap, &attribute);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&attribute, &_10$$16);
					}
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0 TSRMLS_CC))) {
						if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
							ZEPHIR_INIT_NVAR(&_11$$18);
							object_init_ex(&_11$$18, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_12$$18);
							ZEPHIR_CONCAT_SVS(&_12$$18, "Column '", &attribute, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_11$$18, "__construct", &_8, 4, &_12$$18);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_11$$18, "phalcon/mvc/model.zep", 2581 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						} else {
							continue;
						}
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
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	RETURN_CCTOR(&data);

}

/**
 * Updates a model instance. If the instance doesn't exist in the persistence it will throw an exception
 * Returning true on success or false otherwise.
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

	zephir_read_property(&_0, this_ptr, SL("_dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getreadconnection", NULL, 0);
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
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 300, &_5$$4, &_6$$4, &_7$$4);
			zephir_check_call_status();
			zephir_array_fast_append(&_3$$4, &_4$$4);
			zephir_update_property_zval(this_ptr, SL("_errorMessages"), &_3$$4);
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
 * Reads "belongs to" relations and check the virtual foreign keys when inserting or updating records
 * to verify that inserted/updated values are present in the related entity
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysRestrict) {

	zend_string *_9$$8, *_30$$28;
	zend_ulong _8$$8, _29$$28;
	zval _17$$3, _38$$23;
	zend_bool error = 0, validateWithNulls = 0, _15$$3, _36$$23;
	zval manager, belongsTo, foreignKey, relation, conditions, position, bindParams, extraConditions, message, fields, referencedFields, field, referencedModel, value, allowNulls, _0, *_1, _2, _3$$6, _4$$3, _16$$3, _18$$3, *_6$$8, _7$$8, _10$$9, _11$$9, _12$$11, _13$$11, _14$$13, _19$$21, _20$$19, _21$$19, _24$$26, _25$$23, _37$$23, _39$$23, *_27$$28, _28$$28, _31$$29, _32$$29, _33$$31, _34$$31, _35$$33, _40$$41, _41$$39, _42$$39, _43$$44;
	zephir_fcall_cache_entry *_5 = NULL, *_22 = NULL, *_23 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, action = 0, numberNull = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&belongsTo);
	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&conditions);
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_19$$21);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_24$$26);
	ZVAL_UNDEF(&_25$$23);
	ZVAL_UNDEF(&_37$$23);
	ZVAL_UNDEF(&_39$$23);
	ZVAL_UNDEF(&_28$$28);
	ZVAL_UNDEF(&_31$$29);
	ZVAL_UNDEF(&_32$$29);
	ZVAL_UNDEF(&_33$$31);
	ZVAL_UNDEF(&_34$$31);
	ZVAL_UNDEF(&_35$$33);
	ZVAL_UNDEF(&_40$$41);
	ZVAL_UNDEF(&_41$$39);
	ZVAL_UNDEF(&_42$$39);
	ZVAL_UNDEF(&_43$$44);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_38$$23);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&belongsTo, &manager, "getbelongsto", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	zephir_is_iterable(&belongsTo, 0, "phalcon/mvc/model.zep", 2800);
	if (Z_TYPE_P(&belongsTo) == IS_ARRAY) {
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
			if (Z_TYPE_P(&foreignKey) == IS_ARRAY) {
				if (zephir_array_isset_string(&foreignKey, SL("action"))) {
					ZEPHIR_OBS_NVAR(&_3$$6);
					zephir_array_fetch_string(&_3$$6, &foreignKey, SL("action"), PH_NOISY, "phalcon/mvc/model.zep", 2702 TSRMLS_CC);
					action = zephir_get_intval(&_3$$6);
				}
			}
			if (action != 1) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&_4$$3, &relation, "getreferencedmodel", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_5, 0, &_4$$3);
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
				zephir_is_iterable(&fields, 0, "phalcon/mvc/model.zep", 2740);
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _8$$8, _9$$8, _6$$8)
					{
						ZEPHIR_INIT_NVAR(&position);
						if (_9$$8 != NULL) { 
							ZVAL_STR_COPY(&position, _9$$8);
						} else {
							ZVAL_LONG(&position, _8$$8);
						}
						ZEPHIR_INIT_NVAR(&field);
						ZVAL_COPY(&field, _6$$8);
						ZEPHIR_OBS_NVAR(&value);
						zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
						zephir_array_fetch(&_10$$9, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 2733 TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_11$$9);
						ZEPHIR_CONCAT_SVSV(&_11$$9, "[", &_10$$9, "] = ?", &position);
						zephir_array_append(&conditions, &_11$$9, PH_SEPARATE, "phalcon/mvc/model.zep", 2733);
						zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2734);
						if (Z_TYPE_P(&value) == IS_NULL) {
							numberNull++;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_7$$8, &fields, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_7$$8)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&position, &fields, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_12$$11, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 2733 TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_13$$11);
							ZEPHIR_CONCAT_SVSV(&_13$$11, "[", &_12$$11, "] = ?", &position);
							zephir_array_append(&conditions, &_13$$11, PH_SEPARATE, "phalcon/mvc/model.zep", 2733);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2734);
							if (Z_TYPE_P(&value) == IS_NULL) {
								numberNull++;
							}
						ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&field);
				ZEPHIR_INIT_NVAR(&position);
				validateWithNulls = numberNull == zephir_fast_count_int(&fields TSRMLS_CC);
			} else {
				ZEPHIR_OBS_NVAR(&value);
				zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
				ZEPHIR_INIT_LNVAR(_14$$13);
				ZEPHIR_CONCAT_SVS(&_14$$13, "[", &referencedFields, "] = ?0");
				zephir_array_append(&conditions, &_14$$13, PH_SEPARATE, "phalcon/mvc/model.zep", 2745);
				zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2746);
				if (Z_TYPE_P(&value) == IS_NULL) {
					validateWithNulls = 1;
				}
			}
			ZEPHIR_OBS_NVAR(&extraConditions);
			if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
				zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/mvc/model.zep", 2757);
			}
			if (validateWithNulls) {
				ZEPHIR_OBS_NVAR(&allowNulls);
				if (zephir_array_isset_string_fetch(&allowNulls, &foreignKey, SL("allowNulls"), 0)) {
					validateWithNulls = zephir_get_boolval(&allowNulls);
				} else {
					validateWithNulls = 0;
				}
			}
			_15$$3 = !validateWithNulls;
			if (_15$$3) {
				ZEPHIR_INIT_NVAR(&_17$$3);
				zephir_create_array(&_17$$3, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_18$$3);
				zephir_fast_join_str(&_18$$3, SL(" AND "), &conditions TSRMLS_CC);
				zephir_array_fast_append(&_17$$3, &_18$$3);
				zephir_array_update_string(&_17$$3, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_16$$3, &referencedModel, "count", NULL, 0, &_17$$3);
				zephir_check_call_status();
				_15$$3 = !zephir_is_true(&_16$$3);
			}
			if (_15$$3) {
				ZEPHIR_OBS_NVAR(&message);
				if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
					ZEPHIR_INIT_NVAR(&message);
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_19$$21);
						zephir_fast_join_str(&_19$$21, SL(", "), &fields TSRMLS_CC);
						ZEPHIR_CONCAT_SVS(&message, "Value of fields \"", &_19$$21, "\" does not exist on referenced table");
					} else {
						ZEPHIR_CONCAT_SVS(&message, "Value of field \"", &fields, "\" does not exist on referenced table");
					}
				}
				ZEPHIR_INIT_NVAR(&_20$$19);
				object_init_ex(&_20$$19, phalcon_messages_message_ce);
				ZEPHIR_INIT_NVAR(&_21$$19);
				ZVAL_STRING(&_21$$19, "ConstraintViolation");
				ZEPHIR_CALL_METHOD(NULL, &_20$$19, "__construct", &_22, 300, &message, &fields, &_21$$19);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_23, 0, &_20$$19);
				zephir_check_call_status();
				error = 1;
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &belongsTo, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &belongsTo, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&relation, &belongsTo, "current", NULL, 0);
			zephir_check_call_status();
				validateWithNulls = 0;
				ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
					continue;
				}
				action = 1;
				if (Z_TYPE_P(&foreignKey) == IS_ARRAY) {
					if (zephir_array_isset_string(&foreignKey, SL("action"))) {
						ZEPHIR_OBS_NVAR(&_24$$26);
						zephir_array_fetch_string(&_24$$26, &foreignKey, SL("action"), PH_NOISY, "phalcon/mvc/model.zep", 2702 TSRMLS_CC);
						action = zephir_get_intval(&_24$$26);
					}
				}
				if (action != 1) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_25$$23, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_26, 0, &_25$$23);
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
					zephir_is_iterable(&fields, 0, "phalcon/mvc/model.zep", 2740);
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _29$$28, _30$$28, _27$$28)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_30$$28 != NULL) { 
								ZVAL_STR_COPY(&position, _30$$28);
							} else {
								ZVAL_LONG(&position, _29$$28);
							}
							ZEPHIR_INIT_NVAR(&field);
							ZVAL_COPY(&field, _27$$28);
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_31$$29, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 2733 TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_32$$29);
							ZEPHIR_CONCAT_SVSV(&_32$$29, "[", &_31$$29, "] = ?", &position);
							zephir_array_append(&conditions, &_32$$29, PH_SEPARATE, "phalcon/mvc/model.zep", 2733);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2734);
							if (Z_TYPE_P(&value) == IS_NULL) {
								numberNull++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_28$$28, &fields, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_28$$28)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&position, &fields, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&value);
								zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
								zephir_array_fetch(&_33$$31, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 2733 TSRMLS_CC);
								ZEPHIR_INIT_LNVAR(_34$$31);
								ZEPHIR_CONCAT_SVSV(&_34$$31, "[", &_33$$31, "] = ?", &position);
								zephir_array_append(&conditions, &_34$$31, PH_SEPARATE, "phalcon/mvc/model.zep", 2733);
								zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2734);
								if (Z_TYPE_P(&value) == IS_NULL) {
									numberNull++;
								}
							ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&field);
					ZEPHIR_INIT_NVAR(&position);
					validateWithNulls = numberNull == zephir_fast_count_int(&fields TSRMLS_CC);
				} else {
					ZEPHIR_OBS_NVAR(&value);
					zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
					ZEPHIR_INIT_LNVAR(_35$$33);
					ZEPHIR_CONCAT_SVS(&_35$$33, "[", &referencedFields, "] = ?0");
					zephir_array_append(&conditions, &_35$$33, PH_SEPARATE, "phalcon/mvc/model.zep", 2745);
					zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2746);
					if (Z_TYPE_P(&value) == IS_NULL) {
						validateWithNulls = 1;
					}
				}
				ZEPHIR_OBS_NVAR(&extraConditions);
				if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
					zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/mvc/model.zep", 2757);
				}
				if (validateWithNulls) {
					ZEPHIR_OBS_NVAR(&allowNulls);
					if (zephir_array_isset_string_fetch(&allowNulls, &foreignKey, SL("allowNulls"), 0)) {
						validateWithNulls = zephir_get_boolval(&allowNulls);
					} else {
						validateWithNulls = 0;
					}
				}
				_36$$23 = !validateWithNulls;
				if (_36$$23) {
					ZEPHIR_INIT_NVAR(&_38$$23);
					zephir_create_array(&_38$$23, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_39$$23);
					zephir_fast_join_str(&_39$$23, SL(" AND "), &conditions TSRMLS_CC);
					zephir_array_fast_append(&_38$$23, &_39$$23);
					zephir_array_update_string(&_38$$23, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_37$$23, &referencedModel, "count", NULL, 0, &_38$$23);
					zephir_check_call_status();
					_36$$23 = !zephir_is_true(&_37$$23);
				}
				if (_36$$23) {
					ZEPHIR_OBS_NVAR(&message);
					if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
						ZEPHIR_INIT_NVAR(&message);
						if (Z_TYPE_P(&fields) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_40$$41);
							zephir_fast_join_str(&_40$$41, SL(", "), &fields TSRMLS_CC);
							ZEPHIR_CONCAT_SVS(&message, "Value of fields \"", &_40$$41, "\" does not exist on referenced table");
						} else {
							ZEPHIR_CONCAT_SVS(&message, "Value of field \"", &fields, "\" does not exist on referenced table");
						}
					}
					ZEPHIR_INIT_NVAR(&_41$$39);
					object_init_ex(&_41$$39, phalcon_messages_message_ce);
					ZEPHIR_INIT_NVAR(&_42$$39);
					ZVAL_STRING(&_42$$39, "ConstraintViolation");
					ZEPHIR_CALL_METHOD(NULL, &_41$$39, "__construct", &_22, 300, &message, &fields, &_42$$39);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_23, 0, &_41$$39);
					zephir_check_call_status();
					error = 1;
					break;
				}
			ZEPHIR_CALL_METHOD(NULL, &belongsTo, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&relation);
	if (error == 1) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_VAR(&_43$$44);
			ZVAL_STRING(&_43$$44, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_43$$44);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (cascade) when deleting records
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseCascade) {

	zend_string *_9$$8, *_24$$19;
	zend_ulong _8$$8, _23$$19;
	zval _15$$3, _30$$14;
	zval manager, relations, relation, foreignKey, resultset, conditions, bindParams, referencedModel, referencedFields, fields, field, position, value, extraConditions, _0, *_1, _2, _3$$6, _4$$3, _16$$3, _17$$3, *_6$$8, _7$$8, _10$$9, _11$$9, _12$$10, _13$$10, _14$$11, _18$$17, _19$$14, _31$$14, _32$$14, *_21$$19, _22$$19, _25$$20, _26$$20, _27$$21, _28$$21, _29$$22;
	zephir_fcall_cache_entry *_5 = NULL, *_20 = NULL;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_26$$20);
	ZVAL_UNDEF(&_27$$21);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_29$$22);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_30$$14);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&relations, 0, "phalcon/mvc/model.zep", 2913);
	if (Z_TYPE_P(&relations) == IS_ARRAY) {
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
			if (Z_TYPE_P(&foreignKey) == IS_ARRAY) {
				if (zephir_array_isset_string(&foreignKey, SL("action"))) {
					ZEPHIR_OBS_NVAR(&_3$$6);
					zephir_array_fetch_string(&_3$$6, &foreignKey, SL("action"), PH_NOISY, "phalcon/mvc/model.zep", 2852 TSRMLS_CC);
					action = zephir_get_intval(&_3$$6);
				}
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
				zephir_is_iterable(&fields, 0, "phalcon/mvc/model.zep", 2882);
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _8$$8, _9$$8, _6$$8)
					{
						ZEPHIR_INIT_NVAR(&position);
						if (_9$$8 != NULL) { 
							ZVAL_STR_COPY(&position, _9$$8);
						} else {
							ZVAL_LONG(&position, _8$$8);
						}
						ZEPHIR_INIT_NVAR(&field);
						ZVAL_COPY(&field, _6$$8);
						ZEPHIR_OBS_NVAR(&value);
						zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
						zephir_array_fetch(&_10$$9, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 2879 TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_11$$9);
						ZEPHIR_CONCAT_SVSV(&_11$$9, "[", &_10$$9, "] = ?", &position);
						zephir_array_append(&conditions, &_11$$9, PH_SEPARATE, "phalcon/mvc/model.zep", 2879);
						zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2880);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_7$$8, &fields, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_7$$8)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&position, &fields, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_12$$10, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 2879 TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_13$$10);
							ZEPHIR_CONCAT_SVSV(&_13$$10, "[", &_12$$10, "] = ?", &position);
							zephir_array_append(&conditions, &_13$$10, PH_SEPARATE, "phalcon/mvc/model.zep", 2879);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2880);
						ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&field);
				ZEPHIR_INIT_NVAR(&position);
			} else {
				ZEPHIR_OBS_NVAR(&value);
				zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
				ZEPHIR_INIT_LNVAR(_14$$11);
				ZEPHIR_CONCAT_SVS(&_14$$11, "[", &referencedFields, "] = ?0");
				zephir_array_append(&conditions, &_14$$11, PH_SEPARATE, "phalcon/mvc/model.zep", 2884);
				zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2885);
			}
			ZEPHIR_OBS_NVAR(&extraConditions);
			if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
				zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/mvc/model.zep", 2892);
			}
			ZEPHIR_INIT_NVAR(&_15$$3);
			zephir_create_array(&_15$$3, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_16$$3);
			zephir_fast_join_str(&_16$$3, SL(" AND "), &conditions TSRMLS_CC);
			zephir_array_fast_append(&_15$$3, &_16$$3);
			zephir_array_update_string(&_15$$3, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&resultset, &referencedModel, "find", NULL, 0, &_15$$3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_17$$3, &resultset, "delete", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_17$$3)) {
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &relations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &relations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&relation, &relations, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
					continue;
				}
				action = 0;
				if (Z_TYPE_P(&foreignKey) == IS_ARRAY) {
					if (zephir_array_isset_string(&foreignKey, SL("action"))) {
						ZEPHIR_OBS_NVAR(&_18$$17);
						zephir_array_fetch_string(&_18$$17, &foreignKey, SL("action"), PH_NOISY, "phalcon/mvc/model.zep", 2852 TSRMLS_CC);
						action = zephir_get_intval(&_18$$17);
					}
				}
				if (action != 2) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_19$$14, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_20, 0, &_19$$14);
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
					zephir_is_iterable(&fields, 0, "phalcon/mvc/model.zep", 2882);
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _23$$19, _24$$19, _21$$19)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_24$$19 != NULL) { 
								ZVAL_STR_COPY(&position, _24$$19);
							} else {
								ZVAL_LONG(&position, _23$$19);
							}
							ZEPHIR_INIT_NVAR(&field);
							ZVAL_COPY(&field, _21$$19);
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_25$$20, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 2879 TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_26$$20);
							ZEPHIR_CONCAT_SVSV(&_26$$20, "[", &_25$$20, "] = ?", &position);
							zephir_array_append(&conditions, &_26$$20, PH_SEPARATE, "phalcon/mvc/model.zep", 2879);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2880);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_22$$19, &fields, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_22$$19)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&position, &fields, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&value);
								zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
								zephir_array_fetch(&_27$$21, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 2879 TSRMLS_CC);
								ZEPHIR_INIT_LNVAR(_28$$21);
								ZEPHIR_CONCAT_SVSV(&_28$$21, "[", &_27$$21, "] = ?", &position);
								zephir_array_append(&conditions, &_28$$21, PH_SEPARATE, "phalcon/mvc/model.zep", 2879);
								zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2880);
							ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&field);
					ZEPHIR_INIT_NVAR(&position);
				} else {
					ZEPHIR_OBS_NVAR(&value);
					zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
					ZEPHIR_INIT_LNVAR(_29$$22);
					ZEPHIR_CONCAT_SVS(&_29$$22, "[", &referencedFields, "] = ?0");
					zephir_array_append(&conditions, &_29$$22, PH_SEPARATE, "phalcon/mvc/model.zep", 2884);
					zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2885);
				}
				ZEPHIR_OBS_NVAR(&extraConditions);
				if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
					zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/mvc/model.zep", 2892);
				}
				ZEPHIR_INIT_NVAR(&_30$$14);
				zephir_create_array(&_30$$14, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_31$$14);
				zephir_fast_join_str(&_31$$14, SL(" AND "), &conditions TSRMLS_CC);
				zephir_array_fast_append(&_30$$14, &_31$$14);
				zephir_array_update_string(&_30$$14, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&resultset, &referencedModel, "find", NULL, 0, &_30$$14);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_32$$14, &resultset, "delete", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_32$$14)) {
					RETURN_MM_BOOL(0);
				}
			ZEPHIR_CALL_METHOD(NULL, &relations, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&relation);
	RETURN_MM_BOOL(1);

}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (restrict) when deleting records
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseRestrict) {

	zval _15$$3, _33$$15;
	zend_string *_8$$8, *_26$$20;
	zend_ulong _7$$8, _25$$20;
	zval manager, relations, foreignKey, relation, relationClass, referencedModel, fields, referencedFields, conditions, bindParams, position, field, value, extraConditions, message, _0, *_1, _2, _3$$6, *_5$$8, _6$$8, _9$$9, _10$$9, _11$$10, _12$$10, _13$$11, _14$$3, _16$$3, _17$$13, _18$$13, _21$$18, *_23$$20, _24$$20, _27$$21, _28$$21, _29$$22, _30$$22, _31$$23, _32$$15, _34$$15, _35$$25, _36$$25, _37$$28;
	zend_bool error = 0;
	zephir_fcall_cache_entry *_4 = NULL, *_19 = NULL, *_20 = NULL, *_22 = NULL;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_27$$21);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_29$$22);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_31$$23);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_34$$15);
	ZVAL_UNDEF(&_35$$25);
	ZVAL_UNDEF(&_36$$25);
	ZVAL_UNDEF(&_37$$28);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_33$$15);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	zephir_is_iterable(&relations, 0, "phalcon/mvc/model.zep", 3031);
	if (Z_TYPE_P(&relations) == IS_ARRAY) {
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
			if (Z_TYPE_P(&foreignKey) == IS_ARRAY) {
				if (zephir_array_isset_string(&foreignKey, SL("action"))) {
					ZEPHIR_OBS_NVAR(&_3$$6);
					zephir_array_fetch_string(&_3$$6, &foreignKey, SL("action"), PH_NOISY, "phalcon/mvc/model.zep", 2959 TSRMLS_CC);
					action = zephir_get_intval(&_3$$6);
				}
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
				zephir_is_iterable(&fields, 0, "phalcon/mvc/model.zep", 2993);
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _7$$8, _8$$8, _5$$8)
					{
						ZEPHIR_INIT_NVAR(&position);
						if (_8$$8 != NULL) { 
							ZVAL_STR_COPY(&position, _8$$8);
						} else {
							ZVAL_LONG(&position, _7$$8);
						}
						ZEPHIR_INIT_NVAR(&field);
						ZVAL_COPY(&field, _5$$8);
						ZEPHIR_OBS_NVAR(&value);
						zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
						zephir_array_fetch(&_9$$9, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 2989 TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_10$$9);
						ZEPHIR_CONCAT_SVSV(&_10$$9, "[", &_9$$9, "] = ?", &position);
						zephir_array_append(&conditions, &_10$$9, PH_SEPARATE, "phalcon/mvc/model.zep", 2989);
						zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2990);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_6$$8, &fields, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_6$$8)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&position, &fields, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_11$$10, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 2989 TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_12$$10);
							ZEPHIR_CONCAT_SVSV(&_12$$10, "[", &_11$$10, "] = ?", &position);
							zephir_array_append(&conditions, &_12$$10, PH_SEPARATE, "phalcon/mvc/model.zep", 2989);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2990);
						ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&field);
				ZEPHIR_INIT_NVAR(&position);
			} else {
				ZEPHIR_OBS_NVAR(&value);
				zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
				ZEPHIR_INIT_LNVAR(_13$$11);
				ZEPHIR_CONCAT_SVS(&_13$$11, "[", &referencedFields, "] = ?0");
				zephir_array_append(&conditions, &_13$$11, PH_SEPARATE, "phalcon/mvc/model.zep", 2995);
				zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2996);
			}
			ZEPHIR_OBS_NVAR(&extraConditions);
			if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
				zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/mvc/model.zep", 3003);
			}
			ZEPHIR_INIT_NVAR(&_15$$3);
			zephir_create_array(&_15$$3, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_16$$3);
			zephir_fast_join_str(&_16$$3, SL(" AND "), &conditions TSRMLS_CC);
			zephir_array_fast_append(&_15$$3, &_16$$3);
			zephir_array_update_string(&_15$$3, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_14$$3, &referencedModel, "count", NULL, 0, &_15$$3);
			zephir_check_call_status();
			if (zephir_is_true(&_14$$3)) {
				ZEPHIR_OBS_NVAR(&message);
				if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
					ZEPHIR_INIT_NVAR(&message);
					ZEPHIR_CONCAT_SV(&message, "Record is referenced by model ", &relationClass);
				}
				ZEPHIR_INIT_NVAR(&_17$$13);
				object_init_ex(&_17$$13, phalcon_messages_message_ce);
				ZEPHIR_INIT_NVAR(&_18$$13);
				ZVAL_STRING(&_18$$13, "ConstraintViolation");
				ZEPHIR_CALL_METHOD(NULL, &_17$$13, "__construct", &_19, 300, &message, &fields, &_18$$13);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_20, 0, &_17$$13);
				zephir_check_call_status();
				error = 1;
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &relations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &relations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&relation, &relations, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
					continue;
				}
				action = 1;
				if (Z_TYPE_P(&foreignKey) == IS_ARRAY) {
					if (zephir_array_isset_string(&foreignKey, SL("action"))) {
						ZEPHIR_OBS_NVAR(&_21$$18);
						zephir_array_fetch_string(&_21$$18, &foreignKey, SL("action"), PH_NOISY, "phalcon/mvc/model.zep", 2959 TSRMLS_CC);
						action = zephir_get_intval(&_21$$18);
					}
				}
				if (action != 1) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&relationClass, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_22, 0, &relationClass);
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
					zephir_is_iterable(&fields, 0, "phalcon/mvc/model.zep", 2993);
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _25$$20, _26$$20, _23$$20)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_26$$20 != NULL) { 
								ZVAL_STR_COPY(&position, _26$$20);
							} else {
								ZVAL_LONG(&position, _25$$20);
							}
							ZEPHIR_INIT_NVAR(&field);
							ZVAL_COPY(&field, _23$$20);
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_27$$21, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 2989 TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_28$$21);
							ZEPHIR_CONCAT_SVSV(&_28$$21, "[", &_27$$21, "] = ?", &position);
							zephir_array_append(&conditions, &_28$$21, PH_SEPARATE, "phalcon/mvc/model.zep", 2989);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2990);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_24$$20, &fields, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_24$$20)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&position, &fields, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&value);
								zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
								zephir_array_fetch(&_29$$22, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 2989 TSRMLS_CC);
								ZEPHIR_INIT_LNVAR(_30$$22);
								ZEPHIR_CONCAT_SVSV(&_30$$22, "[", &_29$$22, "] = ?", &position);
								zephir_array_append(&conditions, &_30$$22, PH_SEPARATE, "phalcon/mvc/model.zep", 2989);
								zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2990);
							ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&field);
					ZEPHIR_INIT_NVAR(&position);
				} else {
					ZEPHIR_OBS_NVAR(&value);
					zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
					ZEPHIR_INIT_LNVAR(_31$$23);
					ZEPHIR_CONCAT_SVS(&_31$$23, "[", &referencedFields, "] = ?0");
					zephir_array_append(&conditions, &_31$$23, PH_SEPARATE, "phalcon/mvc/model.zep", 2995);
					zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2996);
				}
				ZEPHIR_OBS_NVAR(&extraConditions);
				if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
					zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/mvc/model.zep", 3003);
				}
				ZEPHIR_INIT_NVAR(&_33$$15);
				zephir_create_array(&_33$$15, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_34$$15);
				zephir_fast_join_str(&_34$$15, SL(" AND "), &conditions TSRMLS_CC);
				zephir_array_fast_append(&_33$$15, &_34$$15);
				zephir_array_update_string(&_33$$15, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_32$$15, &referencedModel, "count", NULL, 0, &_33$$15);
				zephir_check_call_status();
				if (zephir_is_true(&_32$$15)) {
					ZEPHIR_OBS_NVAR(&message);
					if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
						ZEPHIR_INIT_NVAR(&message);
						ZEPHIR_CONCAT_SV(&message, "Record is referenced by model ", &relationClass);
					}
					ZEPHIR_INIT_NVAR(&_35$$25);
					object_init_ex(&_35$$25, phalcon_messages_message_ce);
					ZEPHIR_INIT_NVAR(&_36$$25);
					ZVAL_STRING(&_36$$25, "ConstraintViolation");
					ZEPHIR_CALL_METHOD(NULL, &_35$$25, "__construct", &_19, 300, &message, &fields, &_36$$25);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_20, 0, &_35$$25);
					zephir_check_call_status();
					error = 1;
					break;
				}
			ZEPHIR_CALL_METHOD(NULL, &relations, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&relation);
	if (error == 1) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_VAR(&_37$$28);
			ZVAL_STRING(&_37$$28, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_37$$28);
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

	zend_bool useExplicitIdentity = 0, _26, _28, _30, _6$$11, _14$$24, _23$$36;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_11 = NULL, *_15 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table, table_sub, *identityField, identityField_sub, __$null, bindSkip, fields, values, bindTypes, attributes, bindDataTypes, automaticAttributes, field, columnMap, value, attributeField, success, bindType, defaultValue, sequenceName, defaultValues, source, schema, snapshot, lastInsertedId, manager, _0, *_1, _2, _29, _3$$7, _4$$7, _8$$14, _9$$14, _10$$16, _12$$20, _13$$20, _16$$27, _17$$27, _18$$29, _20$$31, _21$$34, _22$$34, _24$$41, _25$$41, _27$$44;
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
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&lastInsertedId);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_10$$16);
	ZVAL_UNDEF(&_12$$20);
	ZVAL_UNDEF(&_13$$20);
	ZVAL_UNDEF(&_16$$27);
	ZVAL_UNDEF(&_17$$27);
	ZVAL_UNDEF(&_18$$29);
	ZVAL_UNDEF(&_20$$31);
	ZVAL_UNDEF(&_21$$34);
	ZVAL_UNDEF(&_22$$34);
	ZVAL_UNDEF(&_24$$41);
	ZVAL_UNDEF(&_25$$41);
	ZVAL_UNDEF(&_27$$44);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &metaData, &connection, &table, &identityField);



	ZEPHIR_INIT_VAR(&bindSkip);
	ZVAL_LONG(&bindSkip, 1024);
	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&snapshot);
	array_init(&snapshot);
	ZEPHIR_INIT_VAR(&bindTypes);
	array_init(&bindTypes);
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
	zephir_is_iterable(&attributes, 0, "phalcon/mvc/model.zep", 3140);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _1)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _1);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_3$$7);
					object_init_ex(&_3$$7, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4$$7);
					ZEPHIR_CONCAT_SVS(&_4$$7, "Column '", &field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_3$$7, "__construct", &_5, 4, &_4$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_3$$7, "phalcon/mvc/model.zep", 3085 TSRMLS_CC);
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
						_6$$11 = Z_TYPE_P(&value) == IS_NULL;
						if (_6$$11) {
							_6$$11 = zephir_array_isset(&defaultValues, &field);
						}
						if (_6$$11) {
							zephir_array_update_zval(&snapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(&value, connection, "getdefaultvalue", &_7, 0);
							zephir_check_call_status();
						} else {
							zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_OBS_NVAR(&bindType);
						if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_8$$14);
							object_init_ex(&_8$$14, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_9$$14);
							ZEPHIR_CONCAT_SVS(&_9$$14, "Column '", &field, "' have not defined a bind data type");
							ZEPHIR_CALL_METHOD(NULL, &_8$$14, "__construct", &_5, 4, &_9$$14);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_8$$14, "phalcon/mvc/model.zep", 3114 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/mvc/model.zep", 3117);
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 3117);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 3117);
					} else {
						if (zephir_array_isset(&defaultValues, &field)) {
							ZEPHIR_CALL_METHOD(&_10$$16, connection, "getdefaultvalue", &_11, 0);
							zephir_check_call_status();
							zephir_array_append(&values, &_10$$16, PH_SEPARATE, "phalcon/mvc/model.zep", 3121);
							zephir_array_update_zval(&snapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 3127);
							zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/mvc/model.zep", 3131);
						zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 3131);
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(&_12$$20);
						object_init_ex(&_12$$20, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_13$$20);
						ZEPHIR_CONCAT_SVS(&_13$$20, "Column '", &field, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_12$$20, "__construct", &_5, 4, &_13$$20);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_12$$20, "phalcon/mvc/model.zep", 3085 TSRMLS_CC);
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
							_14$$24 = Z_TYPE_P(&value) == IS_NULL;
							if (_14$$24) {
								_14$$24 = zephir_array_isset(&defaultValues, &field);
							}
							if (_14$$24) {
								zephir_array_update_zval(&snapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&value, connection, "getdefaultvalue", &_15, 0);
								zephir_check_call_status();
							} else {
								zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							}
							ZEPHIR_OBS_NVAR(&bindType);
							if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0 TSRMLS_CC))) {
								ZEPHIR_INIT_NVAR(&_16$$27);
								object_init_ex(&_16$$27, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_LNVAR(_17$$27);
								ZEPHIR_CONCAT_SVS(&_17$$27, "Column '", &field, "' have not defined a bind data type");
								ZEPHIR_CALL_METHOD(NULL, &_16$$27, "__construct", &_5, 4, &_17$$27);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_16$$27, "phalcon/mvc/model.zep", 3114 TSRMLS_CC);
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/mvc/model.zep", 3117);
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 3117);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 3117);
						} else {
							if (zephir_array_isset(&defaultValues, &field)) {
								ZEPHIR_CALL_METHOD(&_18$$29, connection, "getdefaultvalue", &_19, 0);
								zephir_check_call_status();
								zephir_array_append(&values, &_18$$29, PH_SEPARATE, "phalcon/mvc/model.zep", 3121);
								zephir_array_update_zval(&snapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 3127);
								zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/mvc/model.zep", 3131);
							zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 3131);
						}
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(identityField)) {
		ZEPHIR_CALL_METHOD(&defaultValue, connection, "getdefaultidvalue", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_20$$31, connection, "useexplicitidvalue", NULL, 0);
		zephir_check_call_status();
		useExplicitIdentity = zephir_get_boolval(&_20$$31);
		if (useExplicitIdentity) {
			zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/mvc/model.zep", 3149);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, &columnMap, identityField, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(&_21$$34);
				object_init_ex(&_21$$34, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_22$$34);
				ZEPHIR_CONCAT_SVS(&_22$$34, "Identity column '", identityField, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, &_21$$34, "__construct", &_5, 4, &_22$$34);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_21$$34, "phalcon/mvc/model.zep", 3157 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, identityField);
		}
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
			_23$$36 = Z_TYPE_P(&value) == IS_NULL;
			if (!(_23$$36)) {
				_23$$36 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
			}
			if (_23$$36) {
				if (useExplicitIdentity) {
					zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/mvc/model.zep", 3170);
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 3170);
				}
			} else {
				if (!(useExplicitIdentity)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/mvc/model.zep", 3178);
				}
				ZEPHIR_OBS_NVAR(&bindType);
				if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, identityField, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_VAR(&_24$$41);
					object_init_ex(&_24$$41, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_VAR(&_25$$41);
					ZEPHIR_CONCAT_SVS(&_25$$41, "Identity column '", identityField, "' isn\\'t part of the table columns");
					ZEPHIR_CALL_METHOD(NULL, &_24$$41, "__construct", &_5, 4, &_25$$41);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_24$$41, "phalcon/mvc/model.zep", 3185 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 3188);
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 3188);
			}
		} else {
			if (useExplicitIdentity) {
				zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/mvc/model.zep", 3192);
				zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 3192);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&success, connection, "insert", NULL, 0, table, &values, &fields, &bindTypes);
	zephir_check_call_status();
	_26 = zephir_is_true(&success);
	if (_26) {
		_26 = !ZEPHIR_IS_FALSE_IDENTICAL(identityField);
	}
	if (_26) {
		ZEPHIR_INIT_VAR(&sequenceName);
		ZVAL_NULL(&sequenceName);
		ZEPHIR_CALL_METHOD(&_27$$44, connection, "supportsequences", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_27$$44)) {
			if ((zephir_method_exists_ex(this_ptr, SL("getsequencename") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&sequenceName, this_ptr, "getsequencename", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
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
		zephir_update_property_zval_zval(this_ptr, &attributeField, &lastInsertedId TSRMLS_CC);
		zephir_array_update_zval(&snapshot, &attributeField, &lastInsertedId, PH_COPY | PH_SEPARATE);
		zephir_update_property_zval(this_ptr, SL("_uniqueParams"), &__$null);
	}
	_28 = zephir_is_true(&success);
	if (_28) {
		ZEPHIR_CALL_METHOD(&_29, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_28 = zephir_is_true(&_29);
	}
	_30 = _28;
	if (_30) {
		_30 = ZEPHIR_GLOBAL(orm).update_snapshot_on_save;
	}
	if (_30) {
		zephir_update_property_zval(this_ptr, SL("_snapshot"), &snapshot);
	}
	RETURN_CCTOR(&success);

}

/**
 * Sends a pre-build UPDATE SQL statement to the relational database system
 *
 * @param string|array table
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowUpdate) {

	zval _14$$25, _15$$25, _24$$47, _25$$47;
	zval _32;
	zend_bool useDynamicUpdate = 0, changed = 0, _33, _34;
	zephir_fcall_cache_entry *_6 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table, table_sub, __$null, bindSkip, fields, values, dataType, dataTypes, bindTypes, manager, bindDataTypes, field, automaticAttributes, snapshotValue, uniqueKey, uniqueParams, uniqueTypes, snapshot, nonPrimary, columnMap, attributeField, value, primaryKeys, bindType, newSnapshot, success, _0, _1, *_2, _3, _4$$9, _5$$9, _7$$12, _8$$12, _9$$22, _10$$22, _11$$24, _13$$24, _16$$31, _17$$31, _18$$34, _19$$34, _20$$44, _21$$44, _22$$46, _23$$46, *_26$$53, _27$$53, _28$$57, _29$$57, _30$$63, _31$$63, _35$$68, _36$$69;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$22);
	ZVAL_UNDEF(&_10$$22);
	ZVAL_UNDEF(&_11$$24);
	ZVAL_UNDEF(&_13$$24);
	ZVAL_UNDEF(&_16$$31);
	ZVAL_UNDEF(&_17$$31);
	ZVAL_UNDEF(&_18$$34);
	ZVAL_UNDEF(&_19$$34);
	ZVAL_UNDEF(&_20$$44);
	ZVAL_UNDEF(&_21$$44);
	ZVAL_UNDEF(&_22$$46);
	ZVAL_UNDEF(&_23$$46);
	ZVAL_UNDEF(&_27$$53);
	ZVAL_UNDEF(&_28$$57);
	ZVAL_UNDEF(&_29$$57);
	ZVAL_UNDEF(&_30$$63);
	ZVAL_UNDEF(&_31$$63);
	ZVAL_UNDEF(&_35$$68);
	ZVAL_UNDEF(&_36$$69);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_14$$25);
	ZVAL_UNDEF(&_15$$25);
	ZVAL_UNDEF(&_24$$47);
	ZVAL_UNDEF(&_25$$47);

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
	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_1, &manager, "isusingdynamicupdate", NULL, 0, this_ptr);
	zephir_check_call_status();
	useDynamicUpdate = zephir_get_boolval(&_1);
	ZEPHIR_OBS_VAR(&snapshot);
	zephir_read_property(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
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
	zephir_is_iterable(&nonPrimary, 0, "phalcon/mvc/model.zep", 3406);
	if (Z_TYPE_P(&nonPrimary) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&nonPrimary), _2)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _2);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_4$$9);
					object_init_ex(&_4$$9, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5$$9);
					ZEPHIR_CONCAT_SVS(&_5$$9, "Column '", &field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_4$$9, "__construct", &_6, 4, &_5$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_4$$9, "phalcon/mvc/model.zep", 3299 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &field);
			}
			if (!(zephir_array_isset(&automaticAttributes, &attributeField))) {
				ZEPHIR_OBS_NVAR(&bindType);
				if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_7$$12);
					object_init_ex(&_7$$12, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_8$$12);
					ZEPHIR_CONCAT_SVS(&_8$$12, "Column '", &field, "' have not defined a bind data type");
					ZEPHIR_CALL_METHOD(NULL, &_7$$12, "__construct", &_6, 4, &_8$$12);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_7$$12, "phalcon/mvc/model.zep", 3311 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
					if (!(useDynamicUpdate)) {
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/mvc/model.zep", 3325);
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 3325);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 3326);
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
									if (!(zephir_array_isset_fetch(&dataType, &dataTypes, &field, 0 TSRMLS_CC))) {
										ZEPHIR_INIT_NVAR(&_9$$22);
										object_init_ex(&_9$$22, phalcon_mvc_model_exception_ce);
										ZEPHIR_INIT_LNVAR(_10$$22);
										ZEPHIR_CONCAT_SVS(&_10$$22, "Column '", &field, "' have not defined a data type");
										ZEPHIR_CALL_METHOD(NULL, &_9$$22, "__construct", &_6, 4, &_10$$22);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_9$$22, "phalcon/mvc/model.zep", 3351 TSRMLS_CC);
										ZEPHIR_MM_RESTORE();
										return;
									}
									do {
										if (ZEPHIR_IS_LONG(&dataType, 8)) {
											changed = zephir_get_boolval(&snapshotValue) != zephir_get_boolval(&value);
											break;
										}
										if (ZEPHIR_IS_LONG(&dataType, 3) || ZEPHIR_IS_LONG(&dataType, 7)) {
											ZEPHIR_CALL_FUNCTION(&_11$$24, "floatval", &_12, 324, &snapshotValue);
											zephir_check_call_status();
											ZEPHIR_CALL_FUNCTION(&_13$$24, "floatval", &_12, 324, &value);
											zephir_check_call_status();
											changed = !ZEPHIR_IS_IDENTICAL(&_11$$24, &_13$$24);
											break;
										}
										if (ZEPHIR_IS_LONG(&dataType, 0) || ZEPHIR_IS_LONG(&dataType, 1) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 4) || ZEPHIR_IS_LONG(&dataType, 5) || ZEPHIR_IS_LONG(&dataType, 6) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 14)) {
											zephir_get_strval(&_14$$25, &snapshotValue);
											zephir_get_strval(&_15$$25, &value);
											changed = !ZEPHIR_IS_IDENTICAL(&_14$$25, &_15$$25);
											break;
										}
										changed = !ZEPHIR_IS_EQUAL(&value, &snapshotValue);
									} while(0);

								}
							}
						}
						if (changed) {
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/mvc/model.zep", 3390);
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 3390);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 3391);
						}
					}
					zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
					zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/mvc/model.zep", 3398);
					zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/mvc/model.zep", 3398);
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 3398);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &nonPrimary, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &nonPrimary, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &nonPrimary, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(&_16$$31);
						object_init_ex(&_16$$31, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_17$$31);
						ZEPHIR_CONCAT_SVS(&_17$$31, "Column '", &field, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_16$$31, "__construct", &_6, 4, &_17$$31);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_16$$31, "phalcon/mvc/model.zep", 3299 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				if (!(zephir_array_isset(&automaticAttributes, &attributeField))) {
					ZEPHIR_OBS_NVAR(&bindType);
					if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(&_18$$34);
						object_init_ex(&_18$$34, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_19$$34);
						ZEPHIR_CONCAT_SVS(&_19$$34, "Column '", &field, "' have not defined a bind data type");
						ZEPHIR_CALL_METHOD(NULL, &_18$$34, "__construct", &_6, 4, &_19$$34);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_18$$34, "phalcon/mvc/model.zep", 3311 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						if (!(useDynamicUpdate)) {
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/mvc/model.zep", 3325);
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 3325);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 3326);
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
										if (!(zephir_array_isset_fetch(&dataType, &dataTypes, &field, 0 TSRMLS_CC))) {
											ZEPHIR_INIT_NVAR(&_20$$44);
											object_init_ex(&_20$$44, phalcon_mvc_model_exception_ce);
											ZEPHIR_INIT_LNVAR(_21$$44);
											ZEPHIR_CONCAT_SVS(&_21$$44, "Column '", &field, "' have not defined a data type");
											ZEPHIR_CALL_METHOD(NULL, &_20$$44, "__construct", &_6, 4, &_21$$44);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_20$$44, "phalcon/mvc/model.zep", 3351 TSRMLS_CC);
											ZEPHIR_MM_RESTORE();
											return;
										}
										do {
											if (ZEPHIR_IS_LONG(&dataType, 8)) {
												changed = zephir_get_boolval(&snapshotValue) != zephir_get_boolval(&value);
												break;
											}
											if (ZEPHIR_IS_LONG(&dataType, 3) || ZEPHIR_IS_LONG(&dataType, 7)) {
												ZEPHIR_CALL_FUNCTION(&_22$$46, "floatval", &_12, 324, &snapshotValue);
												zephir_check_call_status();
												ZEPHIR_CALL_FUNCTION(&_23$$46, "floatval", &_12, 324, &value);
												zephir_check_call_status();
												changed = !ZEPHIR_IS_IDENTICAL(&_22$$46, &_23$$46);
												break;
											}
											if (ZEPHIR_IS_LONG(&dataType, 0) || ZEPHIR_IS_LONG(&dataType, 1) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 4) || ZEPHIR_IS_LONG(&dataType, 5) || ZEPHIR_IS_LONG(&dataType, 6) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 14)) {
												zephir_get_strval(&_24$$47, &snapshotValue);
												zephir_get_strval(&_25$$47, &value);
												changed = !ZEPHIR_IS_IDENTICAL(&_24$$47, &_25$$47);
												break;
											}
											changed = !ZEPHIR_IS_EQUAL(&value, &snapshotValue);
										} while(0);

									}
								}
							}
							if (changed) {
								zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/mvc/model.zep", 3390);
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 3390);
								zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 3391);
							}
						}
						zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/mvc/model.zep", 3398);
						zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/mvc/model.zep", 3398);
						zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 3398);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &nonPrimary, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	if (!(zephir_fast_count_int(&fields TSRMLS_CC))) {
		if (useDynamicUpdate) {
			zephir_update_property_zval(this_ptr, SL("_oldSnapshot"), &snapshot);
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_OBS_VAR(&uniqueKey);
	zephir_read_property(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&uniqueParams);
	zephir_read_property(&uniqueParams, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&uniqueTypes);
	zephir_read_property(&uniqueTypes, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC);
	if (Z_TYPE_P(&uniqueParams) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (!(zephir_fast_count_int(&primaryKeys TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation", "phalcon/mvc/model.zep", 3428);
			return;
		}
		ZEPHIR_INIT_NVAR(&uniqueParams);
		array_init(&uniqueParams);
		zephir_is_iterable(&primaryKeys, 0, "phalcon/mvc/model.zep", 3453);
		if (Z_TYPE_P(&primaryKeys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _26$$53)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _26$$53);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(&_28$$57);
						object_init_ex(&_28$$57, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_29$$57);
						ZEPHIR_CONCAT_SVS(&_29$$57, "Column '", &field, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_28$$57, "__construct", &_6, 4, &_29$$57);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_28$$57, "phalcon/mvc/model.zep", 3439 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
					zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 3447);
				} else {
					zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/mvc/model.zep", 3450);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_27$$53, &primaryKeys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_27$$53)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &primaryKeys, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_30$$63);
							object_init_ex(&_30$$63, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_31$$63);
							ZEPHIR_CONCAT_SVS(&_31$$63, "Column '", &field, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_30$$63, "__construct", &_6, 4, &_31$$63);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_30$$63, "phalcon/mvc/model.zep", 3439 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 3447);
					} else {
						zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/mvc/model.zep", 3450);
					}
				ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&field);
	}
	ZEPHIR_INIT_VAR(&_32);
	zephir_create_array(&_32, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_32, SL("conditions"), &uniqueKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_32, SL("bind"), &uniqueParams, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_32, SL("bindTypes"), &uniqueTypes, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&success, connection, "update", NULL, 0, table, &fields, &values, &_32, &bindTypes);
	zephir_check_call_status();
	_33 = zephir_is_true(&success);
	if (_33) {
		ZEPHIR_CALL_METHOD(&_1, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_33 = zephir_is_true(&_1);
	}
	_34 = _33;
	if (_34) {
		_34 = ZEPHIR_GLOBAL(orm).update_snapshot_on_save;
	}
	if (_34) {
		if (Z_TYPE_P(&snapshot) == IS_ARRAY) {
			zephir_update_property_zval(this_ptr, SL("_oldSnapshot"), &snapshot);
			ZEPHIR_INIT_VAR(&_35$$68);
			zephir_fast_array_merge(&_35$$68, &snapshot, &newSnapshot TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("_snapshot"), &_35$$68);
		} else {
			ZEPHIR_INIT_VAR(&_36$$69);
			array_init(&_36$$69);
			zephir_update_property_zval(this_ptr, SL("_oldSnapshot"), &_36$$69);
			zephir_update_property_zval(this_ptr, SL("_snapshot"), &newSnapshot);
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

	zend_bool _5$$11, _13$$19;
	zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberEmpty = 0, numberPrimary = 0;
	zval *metaData, metaData_sub, *connection, connection_sub, *table = NULL, table_sub, __$null, uniqueParams, uniqueTypes, uniqueKey, columnMap, primaryKeys, wherePk, field, attributeField, value, bindDataTypes, joinWhere, num, type, schema, source, _19, _21, _22, _23, _24, *_0$$3, _1$$3, _2$$9, _3$$9, _6$$14, _7$$14, _8$$7, _10$$7, _11$$17, _12$$17, _14$$22, _15$$22, _16$$15, _18$$15, _20$$28, _25$$30, _26$$31;
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
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$9);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_6$$14);
	ZVAL_UNDEF(&_7$$14);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&_14$$22);
	ZVAL_UNDEF(&_15$$22);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_20$$28);
	ZVAL_UNDEF(&_25$$30);
	ZVAL_UNDEF(&_26$$31);

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
	ZEPHIR_OBS_VAR(&uniqueKey);
	zephir_read_property(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
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
		zephir_is_iterable(&primaryKeys, 0, "phalcon/mvc/model.zep", 3564);
		if (Z_TYPE_P(&primaryKeys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _0$$3);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(&_2$$9);
						object_init_ex(&_2$$9, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_3$$9);
						ZEPHIR_CONCAT_SVS(&_3$$9, "Column '", &field, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_2$$9, "__construct", &_4, 4, &_3$$9);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_2$$9, "phalcon/mvc/model.zep", 3528 TSRMLS_CC);
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
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 3546);
				} else {
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/mvc/model.zep", 3549);
					numberEmpty++;
				}
				ZEPHIR_OBS_NVAR(&type);
				if (!(zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_6$$14);
					object_init_ex(&_6$$14, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_7$$14);
					ZEPHIR_CONCAT_SVS(&_7$$14, "Column '", &field, "' isn't part of the table columns");
					ZEPHIR_CALL_METHOD(NULL, &_6$$14, "__construct", &_4, 4, &_7$$14);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_6$$14, "phalcon/mvc/model.zep", 3554 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/mvc/model.zep", 3557);
				ZEPHIR_CALL_METHOD(&_8$$7, connection, "escapeidentifier", &_9, 0, &field);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_10$$7);
				ZEPHIR_CONCAT_VS(&_10$$7, &_8$$7, " = ?");
				zephir_array_append(&wherePk, &_10$$7, PH_SEPARATE, "phalcon/mvc/model.zep", 3558);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &primaryKeys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &primaryKeys, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_11$$17);
							object_init_ex(&_11$$17, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_12$$17);
							ZEPHIR_CONCAT_SVS(&_12$$17, "Column '", &field, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_11$$17, "__construct", &_4, 4, &_12$$17);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_11$$17, "phalcon/mvc/model.zep", 3528 TSRMLS_CC);
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
						_13$$19 = Z_TYPE_P(&value) == IS_NULL;
						if (!(_13$$19)) {
							_13$$19 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
						}
						if (_13$$19) {
							numberEmpty++;
						}
						zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 3546);
					} else {
						zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/mvc/model.zep", 3549);
						numberEmpty++;
					}
					ZEPHIR_OBS_NVAR(&type);
					if (!(zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(&_14$$22);
						object_init_ex(&_14$$22, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_15$$22);
						ZEPHIR_CONCAT_SVS(&_15$$22, "Column '", &field, "' isn't part of the table columns");
						ZEPHIR_CALL_METHOD(NULL, &_14$$22, "__construct", &_4, 4, &_15$$22);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_14$$22, "phalcon/mvc/model.zep", 3554 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/mvc/model.zep", 3557);
					ZEPHIR_CALL_METHOD(&_16$$15, connection, "escapeidentifier", &_17, 0, &field);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_18$$15);
					ZEPHIR_CONCAT_VS(&_18$$15, &_16$$15, " = ?");
					zephir_array_append(&wherePk, &_18$$15, PH_SEPARATE, "phalcon/mvc/model.zep", 3558);
				ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		if (numberPrimary == numberEmpty) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&joinWhere);
		zephir_fast_join_str(&joinWhere, SL(" AND "), &wherePk TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_uniqueKey"), &joinWhere);
		zephir_update_property_zval(this_ptr, SL("_uniqueParams"), &uniqueParams);
		zephir_update_property_zval(this_ptr, SL("_uniqueTypes"), &uniqueTypes);
		ZEPHIR_CPY_WRT(&uniqueKey, &joinWhere);
	}
	zephir_read_property(&_19, this_ptr, SL("_dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_19))) {
		RETURN_MM_BOOL(1);
	}
	if (Z_TYPE_P(&uniqueKey) == IS_NULL) {
		ZEPHIR_OBS_NVAR(&uniqueKey);
		zephir_read_property(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(&uniqueParams) == IS_NULL) {
		ZEPHIR_OBS_NVAR(&uniqueParams);
		zephir_read_property(&uniqueParams, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(&uniqueTypes) == IS_NULL) {
		ZEPHIR_OBS_NVAR(&uniqueTypes);
		zephir_read_property(&uniqueTypes, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC);
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&_20$$28);
		zephir_create_array(&_20$$28, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_20$$28, &schema);
		zephir_array_fast_append(&_20$$28, &source);
		ZEPHIR_CPY_WRT(table, &_20$$28);
	} else {
		ZEPHIR_CPY_WRT(table, &source);
	}
	ZEPHIR_CALL_METHOD(&_21, connection, "escapeidentifier", NULL, 0, table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_22);
	ZEPHIR_CONCAT_SVSV(&_22, "SELECT COUNT(*) \"rowcount\" FROM ", &_21, " WHERE ", &uniqueKey);
	ZVAL_NULL(&_23);
	ZEPHIR_CALL_METHOD(&num, connection, "fetchone", NULL, 0, &_22, &_23, &uniqueParams, &uniqueTypes);
	zephir_check_call_status();
	zephir_array_fetch_string(&_24, &num, SL("rowcount"), PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 3614 TSRMLS_CC);
	if (zephir_is_true(&_24)) {
		ZEPHIR_INIT_ZVAL_NREF(_25$$30);
		ZVAL_LONG(&_25$$30, 0);
		zephir_update_property_zval(this_ptr, SL("_dirtyState"), &_25$$30);
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_26$$31);
		ZVAL_LONG(&_26$$31, 1);
		zephir_update_property_zval(this_ptr, SL("_dirtyState"), &_26$$31);
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
	zval *modelName_param = NULL, *method_param = NULL, *arguments, arguments_sub, manager, relation, queryMethod, extraArgs, _0, _1$$3, _2$$3, _3$$3, _4$$4, _5$$4, _6$$4;
	zval modelName, method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&queryMethod);
	ZVAL_UNDEF(&extraArgs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

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


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&relation);
	ZVAL_BOOL(&relation, 0);
	ZEPHIR_INIT_VAR(&queryMethod);
	ZVAL_NULL(&queryMethod);
	if (zephir_start_with_str(&method, SL("get"))) {
		ZVAL_LONG(&_2$$3, 3);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_substr(&_3$$3, &method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(&_1$$3, &manager, "getrelationbyalias", NULL, 0, &modelName, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_1$$3);
	} else if (zephir_start_with_str(&method, SL("count"))) {
		ZEPHIR_INIT_NVAR(&queryMethod);
		ZVAL_STRING(&queryMethod, "count");
		ZVAL_LONG(&_5$$4, 5);
		ZEPHIR_INIT_VAR(&_6$$4);
		zephir_substr(&_6$$4, &method, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(&_4$$4, &manager, "getrelationbyalias", NULL, 0, &modelName, &_6$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_4$$4);
	}
	if (Z_TYPE_P(&relation) != IS_OBJECT) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(&extraArgs);
	zephir_array_isset_long_fetch(&extraArgs, arguments, 0, 0 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(&manager, "getrelationrecords", NULL, 0, &relation, &queryMethod, this_ptr, &extraArgs);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generate a PHQL SELECT statement for an aggregate
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Mvc_Model, _groupResult) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *functionName_param = NULL, *alias_param = NULL, *parameters, parameters_sub, params, distinctColumn, groupColumn, columns, bindParams, bindTypes, resultset, cache, firstRow, groupColumns, builder, query, dependencyInjector, manager, _1, _2, _3;
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
	ZVAL_UNDEF(&dependencyInjector);
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


	ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "modelsManager");
	ZEPHIR_CALL_METHOD(&_1, &dependencyInjector, "getshared", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/mvc/model.zep", 3688);
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
	if (!(zephir_array_isset_long_fetch(&value, &arguments, 0, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_3$$7);
		object_init_ex(&_3$$7, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$7);
		ZEPHIR_CONCAT_SVS(&_4$$7, "The static method '", &method, "' requires one argument");
		ZEPHIR_CALL_METHOD(NULL, &_3$$7, "__construct", NULL, 4, &_4$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$7, "phalcon/mvc/model.zep", 3800 TSRMLS_CC);
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
		ZEPHIR_CALL_FUNCTION(&extraMethodFirst, "lcfirst", NULL, 53, &extraMethod);
		zephir_check_call_status();
		if (zephir_array_isset(&attributes, &extraMethodFirst)) {
			ZEPHIR_CPY_WRT(&field, &extraMethodFirst);
		} else {
			ZEPHIR_INIT_NVAR(&field);
			zephir_uncamelize(&field, &extraMethod, NULL  );
			if (!(zephir_array_isset(&attributes, &field))) {
				ZEPHIR_INIT_VAR(&_7$$13);
				object_init_ex(&_7$$13, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_8$$13);
				ZEPHIR_CONCAT_SVS(&_8$$13, "Cannot resolve attribute '", &extraMethod, "' in the model");
				ZEPHIR_CALL_METHOD(NULL, &_7$$13, "__construct", NULL, 4, &_8$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$13, "phalcon/mvc/model.zep", 3834 TSRMLS_CC);
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
	if ((zephir_method_exists(this_ptr, &possibleSetter TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &possibleSetter, NULL, 0, value);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Executes internal hooks before save a record
 */
PHP_METHOD(Phalcon_Mvc_Model, _preSave) {

	zephir_fcall_cache_entry *_11 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool exists, error = 0, isNull = 0, _12$$27, _13$$27, _14$$27, _22$$46, _23$$46, _24$$46;
	zval *metaData, metaData_sub, *exists_param = NULL, *identityField, identityField_sub, __$true, __$false, notNull, columnMap, dataTypeNumeric, automaticAttributes, defaultValues, field, attributeField, value, emptyStringValues, _30, _31, _0$$3, _1$$3, _2$$5, _3$$5, _4$$7, _5$$7, _6$$9, *_7$$12, _8$$12, _9$$19, _10$$19, _15$$27, _16$$32, _17$$32, _18$$32, _20$$38, _21$$38, _25$$46, _26$$51, _27$$51, _28$$51, _29$$56, _32$$58, _33$$60, _34$$60, _35$$62, _36$$62, _37$$59, _38$$59, _39$$59, _44$$59, _40$$66, _41$$66, _42$$68, _43$$68;
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
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$19);
	ZVAL_UNDEF(&_10$$19);
	ZVAL_UNDEF(&_15$$27);
	ZVAL_UNDEF(&_16$$32);
	ZVAL_UNDEF(&_17$$32);
	ZVAL_UNDEF(&_18$$32);
	ZVAL_UNDEF(&_20$$38);
	ZVAL_UNDEF(&_21$$38);
	ZVAL_UNDEF(&_25$$46);
	ZVAL_UNDEF(&_26$$51);
	ZVAL_UNDEF(&_27$$51);
	ZVAL_UNDEF(&_28$$51);
	ZVAL_UNDEF(&_29$$56);
	ZVAL_UNDEF(&_32$$58);
	ZVAL_UNDEF(&_33$$60);
	ZVAL_UNDEF(&_34$$60);
	ZVAL_UNDEF(&_35$$62);
	ZVAL_UNDEF(&_36$$62);
	ZVAL_UNDEF(&_37$$59);
	ZVAL_UNDEF(&_38$$59);
	ZVAL_UNDEF(&_39$$59);
	ZVAL_UNDEF(&_44$$59);
	ZVAL_UNDEF(&_40$$66);
	ZVAL_UNDEF(&_41$$66);
	ZVAL_UNDEF(&_42$$68);
	ZVAL_UNDEF(&_43$$68);

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
		if (!(exists)) {
			ZEPHIR_INIT_VAR(&_3$$5);
			ZVAL_STRING(&_3$$5, "beforeValidationOnCreate");
			ZEPHIR_CALL_METHOD(&_2$$5, this_ptr, "fireeventcancel", NULL, 0, &_3$$5);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$5)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_VAR(&_5$$7);
			ZVAL_STRING(&_5$$7, "beforeValidationOnUpdate");
			ZEPHIR_CALL_METHOD(&_4$$7, this_ptr, "fireeventcancel", NULL, 0, &_5$$7);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_4$$7)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_6$$9, this_ptr, "_checkforeignkeysrestrict", NULL, 325);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_6$$9)) {
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
			zephir_is_iterable(&notNull, 0, "phalcon/mvc/model.zep", 4020);
			if (Z_TYPE_P(&notNull) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&notNull), _7$$12)
				{
					ZEPHIR_INIT_NVAR(&field);
					ZVAL_COPY(&field, _7$$12);
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_9$$19);
							object_init_ex(&_9$$19, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_10$$19);
							ZEPHIR_CONCAT_SVS(&_10$$19, "Column '", &field, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_9$$19, "__construct", &_11, 4, &_10$$19);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_9$$19, "phalcon/mvc/model.zep", 3947 TSRMLS_CC);
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
										_12$$27 = Z_TYPE_P(&value) == IS_NULL;
										if (!(_12$$27)) {
											_13$$27 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
											if (_13$$27) {
												_14$$27 = !(zephir_array_isset(&defaultValues, &field));
												if (!(_14$$27)) {
													zephir_array_fetch(&_15$$27, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 3978 TSRMLS_CC);
													_14$$27 = !ZEPHIR_IS_IDENTICAL(&value, &_15$$27);
												}
												_13$$27 = _14$$27;
											}
											_12$$27 = _13$$27;
										}
										if (_12$$27) {
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
						if (isNull == 1) {
							if (!(exists)) {
								if (ZEPHIR_IS_EQUAL(&field, identityField)) {
									continue;
								}
								if (zephir_array_isset(&defaultValues, &field)) {
									continue;
								}
							}
							ZEPHIR_INIT_NVAR(&_16$$32);
							object_init_ex(&_16$$32, phalcon_messages_message_ce);
							ZEPHIR_INIT_LNVAR(_17$$32);
							ZEPHIR_CONCAT_VS(&_17$$32, &attributeField, " is required");
							ZEPHIR_INIT_NVAR(&_18$$32);
							ZVAL_STRING(&_18$$32, "PresenceOf");
							ZEPHIR_CALL_METHOD(NULL, &_16$$32, "__construct", &_19, 300, &_17$$32, &attributeField, &_18$$32);
							zephir_check_call_status();
							zephir_update_property_array_append(this_ptr, SL("_errorMessages"), &_16$$32);
							ZEPHIR_INIT_NVAR(&_16$$32);
							error = 1;
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &notNull, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_8$$12, &notNull, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_8$$12)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&field, &notNull, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&attributeField);
							if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC))) {
								ZEPHIR_INIT_NVAR(&_20$$38);
								object_init_ex(&_20$$38, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_LNVAR(_21$$38);
								ZEPHIR_CONCAT_SVS(&_21$$38, "Column '", &field, "' isn't part of the column map");
								ZEPHIR_CALL_METHOD(NULL, &_20$$38, "__construct", &_11, 4, &_21$$38);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_20$$38, "phalcon/mvc/model.zep", 3947 TSRMLS_CC);
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
											_22$$46 = Z_TYPE_P(&value) == IS_NULL;
											if (!(_22$$46)) {
												_23$$46 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
												if (_23$$46) {
													_24$$46 = !(zephir_array_isset(&defaultValues, &field));
													if (!(_24$$46)) {
														zephir_array_fetch(&_25$$46, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 3978 TSRMLS_CC);
														_24$$46 = !ZEPHIR_IS_IDENTICAL(&value, &_25$$46);
													}
													_23$$46 = _24$$46;
												}
												_22$$46 = _23$$46;
											}
											if (_22$$46) {
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
							if (isNull == 1) {
								if (!(exists)) {
									if (ZEPHIR_IS_EQUAL(&field, identityField)) {
										continue;
									}
									if (zephir_array_isset(&defaultValues, &field)) {
										continue;
									}
								}
								ZEPHIR_INIT_NVAR(&_26$$51);
								object_init_ex(&_26$$51, phalcon_messages_message_ce);
								ZEPHIR_INIT_LNVAR(_27$$51);
								ZEPHIR_CONCAT_VS(&_27$$51, &attributeField, " is required");
								ZEPHIR_INIT_NVAR(&_28$$51);
								ZVAL_STRING(&_28$$51, "PresenceOf");
								ZEPHIR_CALL_METHOD(NULL, &_26$$51, "__construct", &_19, 300, &_27$$51, &attributeField, &_28$$51);
								zephir_check_call_status();
								zephir_update_property_array_append(this_ptr, SL("_errorMessages"), &_26$$51);
								ZEPHIR_INIT_NVAR(&_26$$51);
								error = 1;
							}
						}
					ZEPHIR_CALL_METHOD(NULL, &notNull, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&field);
			if (error == 1) {
				if (ZEPHIR_GLOBAL(orm).events) {
					ZEPHIR_INIT_VAR(&_29$$56);
					ZVAL_STRING(&_29$$56, "onValidationFails");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_29$$56);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
					zephir_check_call_status();
				}
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_VAR(&_31);
	ZVAL_STRING(&_31, "validation");
	ZEPHIR_CALL_METHOD(&_30, this_ptr, "fireeventcancel", NULL, 0, &_31);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_30)) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_VAR(&_32$$58);
			ZVAL_STRING(&_32$$58, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_32$$58);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (!(exists)) {
			ZEPHIR_INIT_VAR(&_34$$60);
			ZVAL_STRING(&_34$$60, "afterValidationOnCreate");
			ZEPHIR_CALL_METHOD(&_33$$60, this_ptr, "fireeventcancel", NULL, 0, &_34$$60);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_33$$60)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_VAR(&_36$$62);
			ZVAL_STRING(&_36$$62, "afterValidationOnUpdate");
			ZEPHIR_CALL_METHOD(&_35$$62, this_ptr, "fireeventcancel", NULL, 0, &_36$$62);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_35$$62)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_INIT_VAR(&_38$$59);
		ZVAL_STRING(&_38$$59, "afterValidation");
		ZEPHIR_CALL_METHOD(&_37$$59, this_ptr, "fireeventcancel", NULL, 0, &_38$$59);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_37$$59)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&_38$$59);
		ZVAL_STRING(&_38$$59, "beforeSave");
		ZEPHIR_CALL_METHOD(&_39$$59, this_ptr, "fireeventcancel", NULL, 0, &_38$$59);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_39$$59)) {
			RETURN_MM_BOOL(0);
		}
		if (0) {
			zephir_update_property_zval(this_ptr, SL("_skipped"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_skipped"), &__$false);
		}
		if (exists) {
			ZEPHIR_INIT_VAR(&_41$$66);
			ZVAL_STRING(&_41$$66, "beforeUpdate");
			ZEPHIR_CALL_METHOD(&_40$$66, this_ptr, "fireeventcancel", NULL, 0, &_41$$66);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_40$$66)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_VAR(&_43$$68);
			ZVAL_STRING(&_43$$68, "beforeCreate");
			ZEPHIR_CALL_METHOD(&_42$$68, this_ptr, "fireeventcancel", NULL, 0, &_43$$68);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_42$$68)) {
				RETURN_MM_BOOL(0);
			}
		}
		zephir_read_property(&_44$$59, this_ptr, SL("_skipped"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_44$$59)) {
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

	zval _20$$10, _22$$12, _36$$20, _37$$22;
	zend_string *_5;
	zend_ulong _4;
	zend_bool nesting = 0;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_15 = NULL, *_21 = NULL, *_24 = NULL, *_27 = NULL, *_29 = NULL, *_31 = NULL, *_39 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, *related, related_sub, className, manager, type, relation, columns, referencedFields, referencedModel, message, name, record, _0, _1, *_2, _3, _6$$3, _9$$6, _14$$7, _16$$5, _25$$5, _17$$8, *_18$$8, _19$$8, _23$$8, _26$$13, _28$$16, _30$$17, _32$$15, _40$$15, _33$$18, *_34$$18, _35$$18, _38$$18;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_30$$17);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_40$$15);
	ZVAL_UNDEF(&_33$$18);
	ZVAL_UNDEF(&_35$$18);
	ZVAL_UNDEF(&_38$$18);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_36$$20);
	ZVAL_UNDEF(&_37$$22);

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
	zephir_is_iterable(related, 0, "phalcon/mvc/model.zep", 4189);
	if (Z_TYPE_P(related) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(related), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&name, _5);
			} else {
				ZVAL_LONG(&name, _4);
			}
			ZEPHIR_INIT_NVAR(&record);
			ZVAL_COPY(&record, _2);
			ZEPHIR_CALL_METHOD(&_6$$3, &manager, "getrelationbyalias", &_7, 0, &className, &name);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&relation, &_6$$3);
			if (Z_TYPE_P(&relation) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&type, &relation, "gettype", &_8, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&type, 0)) {
					if (Z_TYPE_P(&record) != IS_OBJECT) {
						if (nesting) {
							ZVAL_BOOL(&_9$$6, 1);
						} else {
							ZVAL_BOOL(&_9$$6, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_10, 0, &_9$$6);
						zephir_check_call_status();
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects can be stored as part of belongs-to relations", "phalcon/mvc/model.zep", 4136);
						return;
					}
					ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", &_11, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getreferencedmodel", &_12, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", &_13, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&columns) == IS_ARRAY) {
						if (nesting) {
							ZVAL_BOOL(&_14$$7, 1);
						} else {
							ZVAL_BOOL(&_14$$7, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_15, 0, &_14$$7);
						zephir_check_call_status();
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/mvc/model.zep", 4145);
						return;
					}
					ZEPHIR_CALL_METHOD(&_16$$5, &record, "save", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(&_16$$5))) {
						ZEPHIR_CALL_METHOD(&_17$$8, &record, "getmessages", NULL, 0);
						zephir_check_call_status();
						zephir_is_iterable(&_17$$8, 0, "phalcon/mvc/model.zep", 4176);
						if (Z_TYPE_P(&_17$$8) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_17$$8), _18$$8)
							{
								ZEPHIR_INIT_NVAR(&message);
								ZVAL_COPY(&message, _18$$8);
								if (Z_TYPE_P(&message) == IS_OBJECT) {
									ZEPHIR_INIT_NVAR(&_20$$10);
									zephir_create_array(&_20$$10, 1, 0 TSRMLS_CC);
									zephir_array_update_string(&_20$$10, SL("model"), &record, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_20$$10);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_21, 0, &message);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_17$$8, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_19$$8, &_17$$8, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_19$$8)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&message, &_17$$8, "current", NULL, 0);
								zephir_check_call_status();
									if (Z_TYPE_P(&message) == IS_OBJECT) {
										ZEPHIR_INIT_NVAR(&_22$$12);
										zephir_create_array(&_22$$12, 1, 0 TSRMLS_CC);
										zephir_array_update_string(&_22$$12, SL("model"), &record, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_22$$12);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_21, 0, &message);
									zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &_17$$8, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&message);
						if (nesting) {
							ZVAL_BOOL(&_23$$8, 1);
						} else {
							ZVAL_BOOL(&_23$$8, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_24, 0, &_23$$8);
						zephir_check_call_status();
						RETURN_MM_BOOL(0);
					}
					ZEPHIR_CALL_METHOD(&_25$$5, &record, "readattribute", NULL, 0, &referencedFields);
					zephir_check_call_status();
					zephir_update_property_zval_zval(this_ptr, &columns, &_25$$5 TSRMLS_CC);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, related, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, related, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, related, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&record, related, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_26$$13, &manager, "getrelationbyalias", &_27, 0, &className, &name);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&relation, &_26$$13);
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&type, &relation, "gettype", &_8, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&type, 0)) {
						if (Z_TYPE_P(&record) != IS_OBJECT) {
							if (nesting) {
								ZVAL_BOOL(&_28$$16, 1);
							} else {
								ZVAL_BOOL(&_28$$16, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_29, 0, &_28$$16);
							zephir_check_call_status();
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects can be stored as part of belongs-to relations", "phalcon/mvc/model.zep", 4136);
							return;
						}
						ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", &_11, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getreferencedmodel", &_12, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", &_13, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&columns) == IS_ARRAY) {
							if (nesting) {
								ZVAL_BOOL(&_30$$17, 1);
							} else {
								ZVAL_BOOL(&_30$$17, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_31, 0, &_30$$17);
							zephir_check_call_status();
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/mvc/model.zep", 4145);
							return;
						}
						ZEPHIR_CALL_METHOD(&_32$$15, &record, "save", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_is_true(&_32$$15))) {
							ZEPHIR_CALL_METHOD(&_33$$18, &record, "getmessages", NULL, 0);
							zephir_check_call_status();
							zephir_is_iterable(&_33$$18, 0, "phalcon/mvc/model.zep", 4176);
							if (Z_TYPE_P(&_33$$18) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_33$$18), _34$$18)
								{
									ZEPHIR_INIT_NVAR(&message);
									ZVAL_COPY(&message, _34$$18);
									if (Z_TYPE_P(&message) == IS_OBJECT) {
										ZEPHIR_INIT_NVAR(&_36$$20);
										zephir_create_array(&_36$$20, 1, 0 TSRMLS_CC);
										zephir_array_update_string(&_36$$20, SL("model"), &record, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_36$$20);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_21, 0, &message);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_33$$18, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_35$$18, &_33$$18, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_35$$18)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&message, &_33$$18, "current", NULL, 0);
									zephir_check_call_status();
										if (Z_TYPE_P(&message) == IS_OBJECT) {
											ZEPHIR_INIT_NVAR(&_37$$22);
											zephir_create_array(&_37$$22, 1, 0 TSRMLS_CC);
											zephir_array_update_string(&_37$$22, SL("model"), &record, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_37$$22);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_21, 0, &message);
										zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &_33$$18, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&message);
							if (nesting) {
								ZVAL_BOOL(&_38$$18, 1);
							} else {
								ZVAL_BOOL(&_38$$18, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_39, 0, &_38$$18);
							zephir_check_call_status();
							RETURN_MM_BOOL(0);
						}
						ZEPHIR_CALL_METHOD(&_40$$15, &record, "readattribute", NULL, 0, &referencedFields);
						zephir_check_call_status();
						zephir_update_property_zval_zval(this_ptr, &columns, &_40$$15 TSRMLS_CC);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, related, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
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


	if (success == 1) {
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

	zval _33$$16, _35$$18, _43$$22, _44$$24, _51$$29, _52$$31, _60$$35, _61$$37, _88$$53, _89$$55, _97$$59, _98$$61, _105$$66, _106$$68, _114$$72, _115$$74;
	zend_string *_4;
	zend_ulong _3;
	zend_bool nesting = 0, isThrough = 0, _9$$4, _71$$41;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_16 = NULL, *_18 = NULL, *_21 = NULL, *_23 = NULL, *_24 = NULL, *_25 = NULL, *_26 = NULL, *_34 = NULL, *_37 = NULL, *_38 = NULL, *_46 = NULL, *_54 = NULL, *_55 = NULL, *_63 = NULL, *_65 = NULL, *_69 = NULL, *_73 = NULL, *_75 = NULL, *_78 = NULL, *_91 = NULL, *_92 = NULL, *_100 = NULL, *_108 = NULL, *_109 = NULL, *_117 = NULL, *_119 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, *related, related_sub, className, manager, relation, name, record, message, columns, referencedModel, referencedFields, relatedRecords, value, recordAfter, intermediateModel, intermediateFields, intermediateValue, intermediateModelName, intermediateReferencedFields, _0, *_1, _2, _122, _5$$3, _7$$4, _22$$4, *_27$$4, _28$$4, _10$$6, _15$$7, _17$$10, _19$$10, _20$$10, _29$$12, _30$$14, *_31$$14, _32$$14, _36$$14, _39$$19, _40$$20, *_41$$20, _42$$20, _45$$20, _47$$25, _48$$27, *_49$$27, _50$$27, _53$$27, _56$$32, _57$$33, *_58$$33, _59$$33, _62$$33, _64$$39, _66$$39, _67$$39, _68$$40, _70$$41, _81$$41, *_82$$41, _83$$41, _72$$43, _74$$44, _76$$45, _77$$47, _79$$47, _80$$47, _84$$49, _85$$51, *_86$$51, _87$$51, _90$$51, _93$$56, _94$$57, *_95$$57, _96$$57, _99$$57, _101$$62, _102$$64, *_103$$64, _104$$64, _107$$64, _110$$69, _111$$70, *_112$$70, _113$$70, _116$$70, _118$$76, _120$$76, _121$$76;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_122);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_28$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_36$$14);
	ZVAL_UNDEF(&_39$$19);
	ZVAL_UNDEF(&_40$$20);
	ZVAL_UNDEF(&_42$$20);
	ZVAL_UNDEF(&_45$$20);
	ZVAL_UNDEF(&_47$$25);
	ZVAL_UNDEF(&_48$$27);
	ZVAL_UNDEF(&_50$$27);
	ZVAL_UNDEF(&_53$$27);
	ZVAL_UNDEF(&_56$$32);
	ZVAL_UNDEF(&_57$$33);
	ZVAL_UNDEF(&_59$$33);
	ZVAL_UNDEF(&_62$$33);
	ZVAL_UNDEF(&_64$$39);
	ZVAL_UNDEF(&_66$$39);
	ZVAL_UNDEF(&_67$$39);
	ZVAL_UNDEF(&_68$$40);
	ZVAL_UNDEF(&_70$$41);
	ZVAL_UNDEF(&_81$$41);
	ZVAL_UNDEF(&_83$$41);
	ZVAL_UNDEF(&_72$$43);
	ZVAL_UNDEF(&_74$$44);
	ZVAL_UNDEF(&_76$$45);
	ZVAL_UNDEF(&_77$$47);
	ZVAL_UNDEF(&_79$$47);
	ZVAL_UNDEF(&_80$$47);
	ZVAL_UNDEF(&_84$$49);
	ZVAL_UNDEF(&_85$$51);
	ZVAL_UNDEF(&_87$$51);
	ZVAL_UNDEF(&_90$$51);
	ZVAL_UNDEF(&_93$$56);
	ZVAL_UNDEF(&_94$$57);
	ZVAL_UNDEF(&_96$$57);
	ZVAL_UNDEF(&_99$$57);
	ZVAL_UNDEF(&_101$$62);
	ZVAL_UNDEF(&_102$$64);
	ZVAL_UNDEF(&_104$$64);
	ZVAL_UNDEF(&_107$$64);
	ZVAL_UNDEF(&_110$$69);
	ZVAL_UNDEF(&_111$$70);
	ZVAL_UNDEF(&_113$$70);
	ZVAL_UNDEF(&_116$$70);
	ZVAL_UNDEF(&_118$$76);
	ZVAL_UNDEF(&_120$$76);
	ZVAL_UNDEF(&_121$$76);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_35$$18);
	ZVAL_UNDEF(&_43$$22);
	ZVAL_UNDEF(&_44$$24);
	ZVAL_UNDEF(&_51$$29);
	ZVAL_UNDEF(&_52$$31);
	ZVAL_UNDEF(&_60$$35);
	ZVAL_UNDEF(&_61$$37);
	ZVAL_UNDEF(&_88$$53);
	ZVAL_UNDEF(&_89$$55);
	ZVAL_UNDEF(&_97$$59);
	ZVAL_UNDEF(&_98$$61);
	ZVAL_UNDEF(&_105$$66);
	ZVAL_UNDEF(&_106$$68);
	ZVAL_UNDEF(&_114$$72);
	ZVAL_UNDEF(&_115$$74);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &related);



	nesting = 0;
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_is_iterable(related, 0, "phalcon/mvc/model.zep", 4398);
	if (Z_TYPE_P(related) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(related), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&record);
			ZVAL_COPY(&record, _1);
			ZEPHIR_CALL_METHOD(&_5$$3, &manager, "getrelationbyalias", &_6, 0, &className, &name);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&relation, &_5$$3);
			if (Z_TYPE_P(&relation) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&_7$$4, &relation, "gettype", &_8, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_7$$4, 0)) {
					continue;
				}
				_9$$4 = Z_TYPE_P(&record) != IS_OBJECT;
				if (_9$$4) {
					_9$$4 = Z_TYPE_P(&record) != IS_ARRAY;
				}
				if (_9$$4) {
					if (nesting) {
						ZVAL_BOOL(&_10$$6, 1);
					} else {
						ZVAL_BOOL(&_10$$6, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_11, 0, &_10$$6);
					zephir_check_call_status();
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects/arrays can be stored as part of has-many/has-one/has-many-to-many relations", "phalcon/mvc/model.zep", 4242);
					return;
				}
				ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", &_12, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getreferencedmodel", &_13, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", &_14, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&columns) == IS_ARRAY) {
					if (nesting) {
						ZVAL_BOOL(&_15$$7, 1);
					} else {
						ZVAL_BOOL(&_15$$7, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_16, 0, &_15$$7);
					zephir_check_call_status();
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/mvc/model.zep", 4251);
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
				if (!(zephir_fetch_property_zval(&value, this_ptr, &columns, PH_SILENT_CC))) {
					if (nesting) {
						ZVAL_BOOL(&_17$$10, 1);
					} else {
						ZVAL_BOOL(&_17$$10, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_18, 0, &_17$$10);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_19$$10);
					object_init_ex(&_19$$10, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_20$$10);
					ZEPHIR_CONCAT_SVS(&_20$$10, "The column '", &columns, "' needs to be present in the model");
					ZEPHIR_CALL_METHOD(NULL, &_19$$10, "__construct", &_21, 4, &_20$$10);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_19$$10, "phalcon/mvc/model.zep", 4265 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_22$$4, &relation, "isthrough", &_23, 0);
				zephir_check_call_status();
				isThrough = zephir_get_boolval(&_22$$4);
				if (isThrough) {
					ZEPHIR_CALL_METHOD(&intermediateModelName, &relation, "getintermediatemodel", &_24, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&intermediateFields, &relation, "getintermediatefields", &_25, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&intermediateReferencedFields, &relation, "getintermediatereferencedfields", &_26, 0);
					zephir_check_call_status();
				}
				zephir_is_iterable(&relatedRecords, 0, "phalcon/mvc/model.zep", 4384);
				if (Z_TYPE_P(&relatedRecords) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _27$$4)
					{
						ZEPHIR_INIT_NVAR(&recordAfter);
						ZVAL_COPY(&recordAfter, _27$$4);
						if (!(isThrough)) {
							ZEPHIR_CALL_METHOD(NULL, &recordAfter, "writeattribute", NULL, 0, &referencedFields, &value);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_29$$12, &recordAfter, "save", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_is_true(&_29$$12))) {
							ZEPHIR_CALL_METHOD(&_30$$14, &recordAfter, "getmessages", NULL, 0);
							zephir_check_call_status();
							zephir_is_iterable(&_30$$14, 0, "phalcon/mvc/model.zep", 4324);
							if (Z_TYPE_P(&_30$$14) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_30$$14), _31$$14)
								{
									ZEPHIR_INIT_NVAR(&message);
									ZVAL_COPY(&message, _31$$14);
									if (Z_TYPE_P(&message) == IS_OBJECT) {
										ZEPHIR_INIT_NVAR(&_33$$16);
										zephir_create_array(&_33$$16, 1, 0 TSRMLS_CC);
										zephir_array_update_string(&_33$$16, SL("model"), &record, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_33$$16);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_30$$14, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_32$$14, &_30$$14, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_32$$14)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&message, &_30$$14, "current", NULL, 0);
									zephir_check_call_status();
										if (Z_TYPE_P(&message) == IS_OBJECT) {
											ZEPHIR_INIT_NVAR(&_35$$18);
											zephir_create_array(&_35$$18, 1, 0 TSRMLS_CC);
											zephir_array_update_string(&_35$$18, SL("model"), &record, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_35$$18);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
										zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &_30$$14, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&message);
							if (nesting) {
								ZVAL_BOOL(&_36$$14, 1);
							} else {
								ZVAL_BOOL(&_36$$14, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_37, 0, &_36$$14);
							zephir_check_call_status();
							RETURN_MM_BOOL(0);
						}
						if (isThrough) {
							ZEPHIR_CALL_METHOD(&intermediateModel, &manager, "load", &_38, 0, &intermediateModelName);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateFields, &value);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&intermediateValue, &recordAfter, "readattribute", NULL, 0, &referencedFields);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateReferencedFields, &intermediateValue);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_39$$19, &intermediateModel, "save", NULL, 0);
							zephir_check_call_status();
							if (!(zephir_is_true(&_39$$19))) {
								ZEPHIR_CALL_METHOD(&_40$$20, &intermediateModel, "getmessages", NULL, 0);
								zephir_check_call_status();
								zephir_is_iterable(&_40$$20, 0, "phalcon/mvc/model.zep", 4378);
								if (Z_TYPE_P(&_40$$20) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_40$$20), _41$$20)
									{
										ZEPHIR_INIT_NVAR(&message);
										ZVAL_COPY(&message, _41$$20);
										if (Z_TYPE_P(&message) == IS_OBJECT) {
											ZEPHIR_INIT_NVAR(&_43$$22);
											zephir_create_array(&_43$$22, 1, 0 TSRMLS_CC);
											zephir_array_update_string(&_43$$22, SL("model"), &record, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_43$$22);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
										zephir_check_call_status();
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &_40$$20, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_42$$20, &_40$$20, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_42$$20)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&message, &_40$$20, "current", NULL, 0);
										zephir_check_call_status();
											if (Z_TYPE_P(&message) == IS_OBJECT) {
												ZEPHIR_INIT_NVAR(&_44$$24);
												zephir_create_array(&_44$$24, 1, 0 TSRMLS_CC);
												zephir_array_update_string(&_44$$24, SL("model"), &record, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_44$$24);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
											zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, &_40$$20, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&message);
								if (nesting) {
									ZVAL_BOOL(&_45$$20, 1);
								} else {
									ZVAL_BOOL(&_45$$20, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_46, 0, &_45$$20);
								zephir_check_call_status();
								RETURN_MM_BOOL(0);
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_28$$4, &relatedRecords, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_28$$4)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&recordAfter, &relatedRecords, "current", NULL, 0);
						zephir_check_call_status();
							if (!(isThrough)) {
								ZEPHIR_CALL_METHOD(NULL, &recordAfter, "writeattribute", NULL, 0, &referencedFields, &value);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_47$$25, &recordAfter, "save", NULL, 0);
							zephir_check_call_status();
							if (!(zephir_is_true(&_47$$25))) {
								ZEPHIR_CALL_METHOD(&_48$$27, &recordAfter, "getmessages", NULL, 0);
								zephir_check_call_status();
								zephir_is_iterable(&_48$$27, 0, "phalcon/mvc/model.zep", 4324);
								if (Z_TYPE_P(&_48$$27) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_48$$27), _49$$27)
									{
										ZEPHIR_INIT_NVAR(&message);
										ZVAL_COPY(&message, _49$$27);
										if (Z_TYPE_P(&message) == IS_OBJECT) {
											ZEPHIR_INIT_NVAR(&_51$$29);
											zephir_create_array(&_51$$29, 1, 0 TSRMLS_CC);
											zephir_array_update_string(&_51$$29, SL("model"), &record, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_51$$29);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
										zephir_check_call_status();
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &_48$$27, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_50$$27, &_48$$27, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_50$$27)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&message, &_48$$27, "current", NULL, 0);
										zephir_check_call_status();
											if (Z_TYPE_P(&message) == IS_OBJECT) {
												ZEPHIR_INIT_NVAR(&_52$$31);
												zephir_create_array(&_52$$31, 1, 0 TSRMLS_CC);
												zephir_array_update_string(&_52$$31, SL("model"), &record, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_52$$31);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
											zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, &_48$$27, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&message);
								if (nesting) {
									ZVAL_BOOL(&_53$$27, 1);
								} else {
									ZVAL_BOOL(&_53$$27, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_54, 0, &_53$$27);
								zephir_check_call_status();
								RETURN_MM_BOOL(0);
							}
							if (isThrough) {
								ZEPHIR_CALL_METHOD(&intermediateModel, &manager, "load", &_55, 0, &intermediateModelName);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateFields, &value);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&intermediateValue, &recordAfter, "readattribute", NULL, 0, &referencedFields);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateReferencedFields, &intermediateValue);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_56$$32, &intermediateModel, "save", NULL, 0);
								zephir_check_call_status();
								if (!(zephir_is_true(&_56$$32))) {
									ZEPHIR_CALL_METHOD(&_57$$33, &intermediateModel, "getmessages", NULL, 0);
									zephir_check_call_status();
									zephir_is_iterable(&_57$$33, 0, "phalcon/mvc/model.zep", 4378);
									if (Z_TYPE_P(&_57$$33) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_57$$33), _58$$33)
										{
											ZEPHIR_INIT_NVAR(&message);
											ZVAL_COPY(&message, _58$$33);
											if (Z_TYPE_P(&message) == IS_OBJECT) {
												ZEPHIR_INIT_NVAR(&_60$$35);
												zephir_create_array(&_60$$35, 1, 0 TSRMLS_CC);
												zephir_array_update_string(&_60$$35, SL("model"), &record, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_60$$35);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
											zephir_check_call_status();
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &_57$$33, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_59$$33, &_57$$33, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_59$$33)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&message, &_57$$33, "current", NULL, 0);
											zephir_check_call_status();
												if (Z_TYPE_P(&message) == IS_OBJECT) {
													ZEPHIR_INIT_NVAR(&_61$$37);
													zephir_create_array(&_61$$37, 1, 0 TSRMLS_CC);
													zephir_array_update_string(&_61$$37, SL("model"), &record, PH_COPY | PH_SEPARATE);
													ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_61$$37);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
												zephir_check_call_status();
											ZEPHIR_CALL_METHOD(NULL, &_57$$33, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&message);
									if (nesting) {
										ZVAL_BOOL(&_62$$33, 1);
									} else {
										ZVAL_BOOL(&_62$$33, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_63, 0, &_62$$33);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							}
						ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&recordAfter);
			} else {
				if (Z_TYPE_P(&record) != IS_ARRAY) {
					if (nesting) {
						ZVAL_BOOL(&_64$$39, 1);
					} else {
						ZVAL_BOOL(&_64$$39, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_65, 0, &_64$$39);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_66$$39);
					object_init_ex(&_66$$39, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_67$$39);
					ZEPHIR_CONCAT_SVSVS(&_67$$39, "There are no defined relations for the model '", &className, "' using alias '", &name, "'");
					ZEPHIR_CALL_METHOD(NULL, &_66$$39, "__construct", &_21, 4, &_67$$39);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_66$$39, "phalcon/mvc/model.zep", 4390 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, related, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, related, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, related, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&record, related, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_68$$40, &manager, "getrelationbyalias", &_69, 0, &className, &name);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&relation, &_68$$40);
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&_70$$41, &relation, "gettype", &_8, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_70$$41, 0)) {
						continue;
					}
					_71$$41 = Z_TYPE_P(&record) != IS_OBJECT;
					if (_71$$41) {
						_71$$41 = Z_TYPE_P(&record) != IS_ARRAY;
					}
					if (_71$$41) {
						if (nesting) {
							ZVAL_BOOL(&_72$$43, 1);
						} else {
							ZVAL_BOOL(&_72$$43, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_73, 0, &_72$$43);
						zephir_check_call_status();
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects/arrays can be stored as part of has-many/has-one/has-many-to-many relations", "phalcon/mvc/model.zep", 4242);
						return;
					}
					ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", &_12, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getreferencedmodel", &_13, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", &_14, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&columns) == IS_ARRAY) {
						if (nesting) {
							ZVAL_BOOL(&_74$$44, 1);
						} else {
							ZVAL_BOOL(&_74$$44, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_75, 0, &_74$$44);
						zephir_check_call_status();
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/mvc/model.zep", 4251);
						return;
					}
					if (Z_TYPE_P(&record) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_76$$45);
						zephir_create_array(&_76$$45, 1, 0 TSRMLS_CC);
						zephir_array_fast_append(&_76$$45, &record);
						ZEPHIR_CPY_WRT(&relatedRecords, &_76$$45);
					} else {
						ZEPHIR_CPY_WRT(&relatedRecords, &record);
					}
					ZEPHIR_OBS_NVAR(&value);
					if (!(zephir_fetch_property_zval(&value, this_ptr, &columns, PH_SILENT_CC))) {
						if (nesting) {
							ZVAL_BOOL(&_77$$47, 1);
						} else {
							ZVAL_BOOL(&_77$$47, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_78, 0, &_77$$47);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_79$$47);
						object_init_ex(&_79$$47, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_80$$47);
						ZEPHIR_CONCAT_SVS(&_80$$47, "The column '", &columns, "' needs to be present in the model");
						ZEPHIR_CALL_METHOD(NULL, &_79$$47, "__construct", &_21, 4, &_80$$47);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_79$$47, "phalcon/mvc/model.zep", 4265 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_81$$41, &relation, "isthrough", &_23, 0);
					zephir_check_call_status();
					isThrough = zephir_get_boolval(&_81$$41);
					if (isThrough) {
						ZEPHIR_CALL_METHOD(&intermediateModelName, &relation, "getintermediatemodel", &_24, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&intermediateFields, &relation, "getintermediatefields", &_25, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&intermediateReferencedFields, &relation, "getintermediatereferencedfields", &_26, 0);
						zephir_check_call_status();
					}
					zephir_is_iterable(&relatedRecords, 0, "phalcon/mvc/model.zep", 4384);
					if (Z_TYPE_P(&relatedRecords) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _82$$41)
						{
							ZEPHIR_INIT_NVAR(&recordAfter);
							ZVAL_COPY(&recordAfter, _82$$41);
							if (!(isThrough)) {
								ZEPHIR_CALL_METHOD(NULL, &recordAfter, "writeattribute", NULL, 0, &referencedFields, &value);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_84$$49, &recordAfter, "save", NULL, 0);
							zephir_check_call_status();
							if (!(zephir_is_true(&_84$$49))) {
								ZEPHIR_CALL_METHOD(&_85$$51, &recordAfter, "getmessages", NULL, 0);
								zephir_check_call_status();
								zephir_is_iterable(&_85$$51, 0, "phalcon/mvc/model.zep", 4324);
								if (Z_TYPE_P(&_85$$51) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_85$$51), _86$$51)
									{
										ZEPHIR_INIT_NVAR(&message);
										ZVAL_COPY(&message, _86$$51);
										if (Z_TYPE_P(&message) == IS_OBJECT) {
											ZEPHIR_INIT_NVAR(&_88$$53);
											zephir_create_array(&_88$$53, 1, 0 TSRMLS_CC);
											zephir_array_update_string(&_88$$53, SL("model"), &record, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_88$$53);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
										zephir_check_call_status();
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &_85$$51, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_87$$51, &_85$$51, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_87$$51)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&message, &_85$$51, "current", NULL, 0);
										zephir_check_call_status();
											if (Z_TYPE_P(&message) == IS_OBJECT) {
												ZEPHIR_INIT_NVAR(&_89$$55);
												zephir_create_array(&_89$$55, 1, 0 TSRMLS_CC);
												zephir_array_update_string(&_89$$55, SL("model"), &record, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_89$$55);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
											zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, &_85$$51, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&message);
								if (nesting) {
									ZVAL_BOOL(&_90$$51, 1);
								} else {
									ZVAL_BOOL(&_90$$51, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_91, 0, &_90$$51);
								zephir_check_call_status();
								RETURN_MM_BOOL(0);
							}
							if (isThrough) {
								ZEPHIR_CALL_METHOD(&intermediateModel, &manager, "load", &_92, 0, &intermediateModelName);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateFields, &value);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&intermediateValue, &recordAfter, "readattribute", NULL, 0, &referencedFields);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateReferencedFields, &intermediateValue);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_93$$56, &intermediateModel, "save", NULL, 0);
								zephir_check_call_status();
								if (!(zephir_is_true(&_93$$56))) {
									ZEPHIR_CALL_METHOD(&_94$$57, &intermediateModel, "getmessages", NULL, 0);
									zephir_check_call_status();
									zephir_is_iterable(&_94$$57, 0, "phalcon/mvc/model.zep", 4378);
									if (Z_TYPE_P(&_94$$57) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_94$$57), _95$$57)
										{
											ZEPHIR_INIT_NVAR(&message);
											ZVAL_COPY(&message, _95$$57);
											if (Z_TYPE_P(&message) == IS_OBJECT) {
												ZEPHIR_INIT_NVAR(&_97$$59);
												zephir_create_array(&_97$$59, 1, 0 TSRMLS_CC);
												zephir_array_update_string(&_97$$59, SL("model"), &record, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_97$$59);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
											zephir_check_call_status();
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &_94$$57, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_96$$57, &_94$$57, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_96$$57)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&message, &_94$$57, "current", NULL, 0);
											zephir_check_call_status();
												if (Z_TYPE_P(&message) == IS_OBJECT) {
													ZEPHIR_INIT_NVAR(&_98$$61);
													zephir_create_array(&_98$$61, 1, 0 TSRMLS_CC);
													zephir_array_update_string(&_98$$61, SL("model"), &record, PH_COPY | PH_SEPARATE);
													ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_98$$61);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
												zephir_check_call_status();
											ZEPHIR_CALL_METHOD(NULL, &_94$$57, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&message);
									if (nesting) {
										ZVAL_BOOL(&_99$$57, 1);
									} else {
										ZVAL_BOOL(&_99$$57, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_100, 0, &_99$$57);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_83$$41, &relatedRecords, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_83$$41)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&recordAfter, &relatedRecords, "current", NULL, 0);
							zephir_check_call_status();
								if (!(isThrough)) {
									ZEPHIR_CALL_METHOD(NULL, &recordAfter, "writeattribute", NULL, 0, &referencedFields, &value);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_101$$62, &recordAfter, "save", NULL, 0);
								zephir_check_call_status();
								if (!(zephir_is_true(&_101$$62))) {
									ZEPHIR_CALL_METHOD(&_102$$64, &recordAfter, "getmessages", NULL, 0);
									zephir_check_call_status();
									zephir_is_iterable(&_102$$64, 0, "phalcon/mvc/model.zep", 4324);
									if (Z_TYPE_P(&_102$$64) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_102$$64), _103$$64)
										{
											ZEPHIR_INIT_NVAR(&message);
											ZVAL_COPY(&message, _103$$64);
											if (Z_TYPE_P(&message) == IS_OBJECT) {
												ZEPHIR_INIT_NVAR(&_105$$66);
												zephir_create_array(&_105$$66, 1, 0 TSRMLS_CC);
												zephir_array_update_string(&_105$$66, SL("model"), &record, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_105$$66);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
											zephir_check_call_status();
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &_102$$64, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_104$$64, &_102$$64, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_104$$64)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&message, &_102$$64, "current", NULL, 0);
											zephir_check_call_status();
												if (Z_TYPE_P(&message) == IS_OBJECT) {
													ZEPHIR_INIT_NVAR(&_106$$68);
													zephir_create_array(&_106$$68, 1, 0 TSRMLS_CC);
													zephir_array_update_string(&_106$$68, SL("model"), &record, PH_COPY | PH_SEPARATE);
													ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_106$$68);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
												zephir_check_call_status();
											ZEPHIR_CALL_METHOD(NULL, &_102$$64, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&message);
									if (nesting) {
										ZVAL_BOOL(&_107$$64, 1);
									} else {
										ZVAL_BOOL(&_107$$64, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_108, 0, &_107$$64);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								if (isThrough) {
									ZEPHIR_CALL_METHOD(&intermediateModel, &manager, "load", &_109, 0, &intermediateModelName);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateFields, &value);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&intermediateValue, &recordAfter, "readattribute", NULL, 0, &referencedFields);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateReferencedFields, &intermediateValue);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&_110$$69, &intermediateModel, "save", NULL, 0);
									zephir_check_call_status();
									if (!(zephir_is_true(&_110$$69))) {
										ZEPHIR_CALL_METHOD(&_111$$70, &intermediateModel, "getmessages", NULL, 0);
										zephir_check_call_status();
										zephir_is_iterable(&_111$$70, 0, "phalcon/mvc/model.zep", 4378);
										if (Z_TYPE_P(&_111$$70) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_111$$70), _112$$70)
											{
												ZEPHIR_INIT_NVAR(&message);
												ZVAL_COPY(&message, _112$$70);
												if (Z_TYPE_P(&message) == IS_OBJECT) {
													ZEPHIR_INIT_NVAR(&_114$$72);
													zephir_create_array(&_114$$72, 1, 0 TSRMLS_CC);
													zephir_array_update_string(&_114$$72, SL("model"), &record, PH_COPY | PH_SEPARATE);
													ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_114$$72);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
												zephir_check_call_status();
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &_111$$70, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_113$$70, &_111$$70, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_113$$70)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&message, &_111$$70, "current", NULL, 0);
												zephir_check_call_status();
													if (Z_TYPE_P(&message) == IS_OBJECT) {
														ZEPHIR_INIT_NVAR(&_115$$74);
														zephir_create_array(&_115$$74, 1, 0 TSRMLS_CC);
														zephir_array_update_string(&_115$$74, SL("model"), &record, PH_COPY | PH_SEPARATE);
														ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_115$$74);
														zephir_check_call_status();
													}
													ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_34, 0, &message);
													zephir_check_call_status();
												ZEPHIR_CALL_METHOD(NULL, &_111$$70, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&message);
										if (nesting) {
											ZVAL_BOOL(&_116$$70, 1);
										} else {
											ZVAL_BOOL(&_116$$70, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_117, 0, &_116$$70);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								}
							ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&recordAfter);
				} else {
					if (Z_TYPE_P(&record) != IS_ARRAY) {
						if (nesting) {
							ZVAL_BOOL(&_118$$76, 1);
						} else {
							ZVAL_BOOL(&_118$$76, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_119, 0, &_118$$76);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_120$$76);
						object_init_ex(&_120$$76, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_121$$76);
						ZEPHIR_CONCAT_SVSVS(&_121$$76, "There are no defined relations for the model '", &className, "' using alias '", &name, "'");
						ZEPHIR_CALL_METHOD(NULL, &_120$$76, "__construct", &_21, 4, &_121$$76);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_120$$76, "phalcon/mvc/model.zep", 4390 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			ZEPHIR_CALL_METHOD(NULL, related, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&record);
	ZEPHIR_INIT_NVAR(&name);
	if (nesting) {
		ZVAL_BOOL(&_122, 1);
	} else {
		ZVAL_BOOL(&_122, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0, &_122);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated UPDATE statement
 *
 *<code>
 *
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
	zval *attributes_param = NULL, __$true, keysAttributes, attribute, *_0, _1, _2;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/mvc/model.zep", 4430);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _0);
			zephir_array_update_zval(&keysAttributes, &attribute, &__$true, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&keysAttributes, &attribute, &__$true, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_2, "setemptystringattributes", NULL, 0, this_ptr, &keysAttributes);
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

	zephir_read_property(&_0, this_ptr, SL("_operationMade"), PH_NOISY_CC | PH_READONLY);
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
 *
 * class RobotsParts extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->belongsTo("robots_id", "Robots", "id");
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


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
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
	zval *params, params_sub, *limit = NULL, limit_sub, __$null, builder, bindParams, bindTypes, transaction, cache, manager, query, dependencyInjector, _1, _2, _3$$5, _4$$7;
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
	ZVAL_UNDEF(&dependencyInjector);
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


	ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "modelsManager");
	ZEPHIR_CALL_METHOD(&_1, &dependencyInjector, "getshared", NULL, 0, &_2);
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
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->hasMany("id", "RobotsParts", "robots_id");
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


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasmany", NULL, 0, this_ptr, fields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setup an n-n relation between two models, through an intermediate relation
 *
 *<code>
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         // Setup a many-to-many relation to Parts through RobotsParts
 *         $this->hasManyToMany(
 *             "id",
 *             "RobotsParts",
 *             "robots_id",
 *             "parts_id",
 *             "Parts",
 *             "id",
 *         );
 *     }
 * }
 *</code>
 *
 * @param	string|array fields
 * @param	string|array intermediateFields
 * @param	string|array intermediateReferencedFields
 * @param   string|array referencedFields
 * @param   array options
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


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasmanytomany", NULL, 0, this_ptr, fields, &intermediateModel, intermediateFields, intermediateReferencedFields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setup a 1-1 relation between two models
 *
 *<code>
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->hasOne("id", "RobotsDescription", "robots_id");
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


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasone", NULL, 0, this_ptr, fields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets if the model must keep the original record snapshot in memory
 *
 *<code>
 *
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


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
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


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "setmodelschema", NULL, 0, this_ptr, &schema);
	zephir_check_call_status();
	RETURN_MM();

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


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setmodelsource", NULL, 0, this_ptr, &source);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT/UPDATE statement
 *
 *<code>
 *
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
 *
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
	zval *attributes_param = NULL, __$null, keysAttributes, attribute, *_0, _1, _2;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/mvc/model.zep", 4701);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _0);
			zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_2, "setautomaticcreateattributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated UPDATE statement
 *
 *<code>
 *
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
	zval *attributes_param = NULL, __$null, keysAttributes, attribute, *_0, _1, _2;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/mvc/model.zep", 4732);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _0);
			zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_2, "setautomaticupdateattributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets if a model must use dynamic update instead of the all-field update
 *
 *<code>
 *
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


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
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
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", &_7, 300, &_3$$4, &_4$$4, &_5$$4, &_6$$4);
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


	zephir_read_property(&_0, this_ptr, SL("_errorMessages"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_fast_count_int(&_0 TSRMLS_CC) > 0);

}

/**
 * Attempts to find key case-insensitively
 */
PHP_METHOD(Phalcon_Mvc_Model, caseInsensitiveColumnMap) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columnMap, columnMap_sub, *key, key_sub, cmKey, _0, *_1, _2, _3$$3, _4$$3, _5$$5, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&cmKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &columnMap, &key);



	ZEPHIR_INIT_VAR(&_0);
	zephir_array_keys(&_0, columnMap TSRMLS_CC);
	zephir_is_iterable(&_0, 0, "phalcon/mvc/model.zep", 4863);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&cmKey);
			ZVAL_COPY(&cmKey, _1);
			ZEPHIR_INIT_NVAR(&_3$$3);
			zephir_fast_strtolower(&_3$$3, &cmKey);
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_fast_strtolower(&_4$$3, key);
			if (ZEPHIR_IS_EQUAL(&_3$$3, &_4$$3)) {
				RETURN_CCTOR(&cmKey);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&cmKey, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$5);
				zephir_fast_strtolower(&_5$$5, &cmKey);
				ZEPHIR_INIT_NVAR(&_6$$5);
				zephir_fast_strtolower(&_6$$5, key);
				if (ZEPHIR_IS_EQUAL(&_5$$5, &_6$$5)) {
					RETURN_CCTOR(&cmKey);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&cmKey);
	RETVAL_ZVAL(key, 1, 0);
	RETURN_MM();

}

zend_object *zephir_init_properties_Phalcon_Mvc_Model(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_oldSnapshot"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_oldSnapshot"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_errorMessages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_errorMessages"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

