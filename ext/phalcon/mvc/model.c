
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"


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
/**
 * Phalcon\Mvc\Model
 *
 * <p>Phalcon\Mvc\Model connects business objects and database tables to create
 * a persistable domain model where logic and data are presented in one wrapping.
 * It‘s an implementation of the object-relational mapping (ORM).</p>
 *
 * <p>A model represents the information (data) of the application and the rules to manipulate that data.
 * Models are primarily used for managing the rules of interaction with a corresponding database table.
 * In most cases, each table in your database will correspond to one model in your application.
 * The bulk of your application’s business logic will be concentrated in the models.</p>
 *
 * <p>Phalcon\Mvc\Model is the first ORM written in C-language for PHP, giving to developers high performance
 * when interacting with databases while is also easy to use.</p>
 *
 * <code>
 *
 * $robot = new Robots();
 * $robot->type = 'mechanical';
 * $robot->name = 'Astro Boy';
 * $robot->year = 1952;
 * if ($robot->save() == false) {
 *  echo "Umh, We can store robots: ";
 *  foreach ($robot->getMessages() as $message) {
 *    echo message;
 *  }
 * } else {
 *  echo "Great, a new robot was saved successfully!";
 * }
 * </code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc, Model, phalcon, mvc_model, phalcon_mvc_model_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_modelsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_modelsMetaData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_errorMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_model_ce, SL("_operationMade"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_model_ce, SL("_dirtyState"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_transaction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_skipped"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_related"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_snapshot"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_NONE"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_CREATE"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_UPDATE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_DELETE"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_PERSISTENT"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_TRANSIENT"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_DETACHED"), 2 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_mvc_modelinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_mvc_model_resultinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model constructor
 *
 * @param Phalcon\DiInterface dependencyInjector
 * @param Phalcon\Mvc\Model\ManagerInterface modelsManager
 */
PHP_METHOD(Phalcon_Mvc_Model, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zend_bool _0, _1;
	zval *dependencyInjector = NULL, *modelsManager = NULL, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &dependencyInjector, &modelsManager);

	if (!dependencyInjector) {
		ZEPHIR_CPY_WRT(dependencyInjector, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(dependencyInjector);
	}
	if (!modelsManager) {
		ZEPHIR_CPY_WRT(modelsManager, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(modelsManager);
	}


	_0 = Z_TYPE_P(dependencyInjector) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	_1 = Z_TYPE_P(modelsManager) != IS_NULL;
	if (_1) {
		_1 = !zephir_instance_of_ev(modelsManager, phalcon_mvc_model_managerinterface_ce TSRMLS_CC);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'modelsManager' must be an instance of 'Phalcon\\Mvc\\Model\\ManagerInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_2);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model.zep", 132);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "modelsManager", 0);
		ZEPHIR_CALL_METHOD(&_3, dependencyInjector, "getshared", NULL, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(modelsManager, _3);
		if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/mvc/model.zep", 143);
			return;
		}
	}
	zephir_update_property_this(this_ptr, SL("_modelsManager"), modelsManager TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, modelsManager, "initialize", NULL, this_ptr);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, SS("onconstruct") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	if (!(zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the dependency injection container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets a custom events manager
 *
 * @param Phalcon\Events\ManagerInterface eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Model, setEventsManager) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *eventsManager, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventsManager);



	if (!(zephir_instance_of_ev(eventsManager, phalcon_events_managerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'eventsManager' must be an instance of 'Phalcon\\Events\\ManagerInterface'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setcustomeventsmanager", NULL, this_ptr, eventsManager);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the custom events manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getEventsManager) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getcustomeventsmanager", NULL, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the models meta-data service related to the entity instance
 *
 * @return Phalcon\Mvc\Model\MetaDataInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsMetaData) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *metaData = NULL, *dependencyInjector = NULL, *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_modelsMetaData"), PH_NOISY_CC);
	if (Z_TYPE_P(metaData) != IS_OBJECT) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(dependencyInjector, _0);
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model.zep", 222);
			return;
		}
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "modelsMetadata", 0);
		ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(metaData, _1);
		if (Z_TYPE_P(metaData) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsMetadata' is not valid", "phalcon/mvc/model.zep", 230);
			return;
		}
		zephir_update_property_this(this_ptr, SL("_modelsMetaData"), metaData TSRMLS_CC);
	}
	RETURN_CCTOR(metaData);

}

/**
 * Returns the models manager related to the entity instance
 *
 * @return Phalcon\Mvc\Model\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsManager) {


	RETURN_MEMBER(this_ptr, "_modelsManager");

}

/**
 * Sets a transaction related to the Model instance
 *
 *<code>
 *use Phalcon\Mvc\Model\Transaction\Manager as TxManager;
 *use Phalcon\Mvc\Model\Transaction\Failed as TxFailed;
 *
 *try {
 *
 *  $txManager = new TxManager();
 *
 *  $transaction = $txManager->get();
 *
 *  $robot = new Robots();
 *  $robot->setTransaction($transaction);
 *  $robot->name = 'WALL·E';
 *  $robot->created_at = date('Y-m-d');
 *  if ($robot->save() == false) {
 *    $transaction->rollback("Can't save robot");
 *  }
 *
 *  $robotPart = new RobotParts();
 *  $robotPart->setTransaction($transaction);
 *  $robotPart->type = 'head';
 *  if ($robotPart->save() == false) {
 *    $transaction->rollback("Robot part cannot be saved");
 *  }
 *
 *  $transaction->commit();
 *
 *} catch (TxFailed $e) {
 *  echo 'Failed, reason: ', $e->getMessage();
 *}
 *
 *</code>
 *
 * @param Phalcon\Mvc\Model\TransactionInterface $transaction
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setTransaction) {

	zval *transaction;

	zephir_fetch_params(0, 1, 0, &transaction);



	if (!(zephir_instance_of_ev(transaction, phalcon_mvc_model_transactioninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'transaction' must be an instance of 'Phalcon\\Mvc\\Model\\TransactionInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(transaction) == IS_OBJECT) {
		zephir_update_property_this(this_ptr, SL("_transaction"), transaction TSRMLS_CC);
		RETURN_THISW();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_model_exception_ce, "Transaction should be an object", "phalcon/mvc/model.zep", 296);
	return;

}

/**
 * Sets table name which model should be mapped
 *
 * @param string source
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setSource) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, *_0;
	zval *source = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &source_param);

	if (unlikely(Z_TYPE_P(source_param) != IS_STRING && Z_TYPE_P(source_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(source_param) == IS_STRING)) {
		source = source_param;
	} else {
		ZEPHIR_INIT_VAR(source);
		ZVAL_EMPTY_STRING(source);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setmodelsource", NULL, this_ptr, source);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Returns table name mapped in the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getSource) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getmodelsource", NULL, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets schema name where table mapped is located
 *
 * @param string schema
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setSchema) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *schema_param = NULL, *_0;
	zval *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &schema_param);

	if (unlikely(Z_TYPE_P(schema_param) != IS_STRING && Z_TYPE_P(schema_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(schema_param) == IS_STRING)) {
		schema = schema_param;
	} else {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "setmodelschema", NULL, this_ptr, schema);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns schema name where table mapped is located
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getSchema) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getmodelschema", NULL, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the DependencyInjection connection service name
 *
 * @param string connectionService
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setConnectionService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, *_0;
	zval *connectionService = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		connectionService = connectionService_param;
	} else {
		ZEPHIR_INIT_VAR(connectionService);
		ZVAL_EMPTY_STRING(connectionService);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setconnectionservice", NULL, this_ptr, connectionService);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets the DependencyInjection connection service name used to read data
 *
 * @param string connectionService
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setReadConnectionService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, *_0;
	zval *connectionService = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		connectionService = connectionService_param;
	} else {
		ZEPHIR_INIT_VAR(connectionService);
		ZVAL_EMPTY_STRING(connectionService);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setreadconnectionservice", NULL, this_ptr, connectionService);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets the DependencyInjection connection service name used to write data
 *
 * @param string connectionService
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setWriteConnectionService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, *_0;
	zval *connectionService = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		connectionService = connectionService_param;
	} else {
		ZEPHIR_INIT_VAR(connectionService);
		ZVAL_EMPTY_STRING(connectionService);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "setwriteconnectionservice", NULL, this_ptr, connectionService);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the DependencyInjection connection service name used to read data related the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnectionService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getreadconnectionservice", NULL, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the DependencyInjection connection service name used to write data related to the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnectionService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getwriteconnectionservice", NULL, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
 *
 * @param int dirtyState
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setDirtyState) {

	zval *dirtyState_param = NULL, *_0;
	int dirtyState;

	zephir_fetch_params(0, 1, 0, &dirtyState_param);

	dirtyState = zephir_get_intval(dirtyState_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, dirtyState);
	zephir_update_property_this(this_ptr, SL("_dirtyState"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns one of the DIRTY_STATE_* constants telling if the record exists in the database or not
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model, getDirtyState) {


	RETURN_MEMBER(this_ptr, "_dirtyState");

}

/**
 * Gets the connection used to read data for the model
 *
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getreadconnection", NULL, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets the connection used to write data to the model
 *
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *transaction = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_transaction"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(transaction, _0);
	if (Z_TYPE_P(transaction) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(transaction, "getconnection", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getwriteconnection", NULL, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Assigns values to a model from an array
 *
 *<code>
 *$robot->assign(array(
 *  'type' => 'mechanical',
 *  'name' => 'Astro Boy',
 *  'year' => 1952
 *));
 *</code>
 *
 * @param array data
 * @param array columnMap
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, assign) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *data, *columnMap = NULL, *key = NULL, *value = NULL, *attribute = NULL, **_2, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &columnMap);

	if (!columnMap) {
		columnMap = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Data to dump in the object must be an Array", "phalcon/mvc/model.zep", 466);
		return;
	}
	zephir_is_iterable(data, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(attribute);
			if (zephir_array_isset_fetch(&attribute, columnMap, key, 0 TSRMLS_CC)) {
				zephir_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_3);
				object_init_ex(_3, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "Column '", key, "' doesn\'t make part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 482 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Assigns values to a model from an array returning a new model.
 *
 *<code>
 *$robot = \Phalcon\Mvc\Model::cloneResultMap(new Robots(), array(
 *  'type' => 'mechanical',
 *  'name' => 'Astro Boy',
 *  'year' => 1952
 *));
 *</code>
 *
 * @param Phalcon\Mvc\ModelInterface|Phalcon\Mvc\Model\Row base
 * @param array data
 * @param array columnMap
 * @param int dirtyState
 * @param boolean keepSnapshots
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMap) {

	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_2;
	HashPosition _1;
	zend_bool keepSnapshots;
	int dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval *base, *data, *columnMap, *dirtyState_param = NULL, *keepSnapshots_param = NULL, *instance, *attribute = NULL, *key = NULL, *value = NULL, *_0, **_3, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &base, &data, &columnMap, &dirtyState_param, &keepSnapshots_param);

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


	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Data to dump in the object must be an Array", "phalcon/mvc/model.zep", 515);
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	if (zephir_clone(instance, base TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, instance, "setdirtystate", NULL, _0);
	zephir_check_call_status();
	zephir_is_iterable(data, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (Z_TYPE_P(key) == IS_STRING) {
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attribute);
				if (zephir_array_isset_fetch(&attribute, columnMap, key, 0 TSRMLS_CC)) {
					zephir_update_property_zval_zval(instance, attribute, value TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_4);
					object_init_ex(_4, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_SVS(_5, "Column '", key, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_6, _5);
					zephir_check_call_status();
					zephir_throw_exception_debug(_4, "phalcon/mvc/model.zep", 539 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				zephir_update_property_zval_zval(instance, key, value TSRMLS_CC);
			}
		}
	}
	if (keepSnapshots) {
		ZEPHIR_CALL_METHOD(NULL, instance, "setsnapshotdata", NULL, data, columnMap);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(instance, SS("afterfetch") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "afterfetch", NULL);
		zephir_check_call_status();
	}
	RETURN_CCTOR(instance);

}

/**
 * Returns an hydrated result based on the data and the column map
 *
 * @param array data
 * @param array columnMap
 * @param int hydrationMode
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMapHydrate) {

	zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_1;
	HashPosition _0;
	int hydrationMode, ZEPHIR_LAST_CALL_STATUS;
	zval *data, *columnMap, *hydrationMode_param = NULL, *hydrate, *key = NULL, *value = NULL, *attribute = NULL, **_2, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data, &columnMap, &hydrationMode_param);

	hydrationMode = zephir_get_intval(hydrationMode_param);


	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Data to hidrate must be an Array", "phalcon/mvc/model.zep", 577);
		return;
	}
	if (Z_TYPE_P(columnMap) != IS_ARRAY) {
		if (hydrationMode == 1) {
			RETURN_CCTOR(data);
		}
	}
	ZEPHIR_INIT_VAR(hydrate);
	if (hydrationMode == 1) {
		array_init(hydrate);
	} else {
		object_init(hydrate);
	}
	zephir_is_iterable(data, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (Z_TYPE_P(key) == IS_STRING) {
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, key, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_LNVAR(_3);
					object_init_ex(_3, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SVS(_4, "Column '", key, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
					zephir_check_call_status();
					zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 606 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (hydrationMode == 1) {
					zephir_array_update_zval(&hydrate, attribute, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_update_property_zval_zval(hydrate, attribute, value TSRMLS_CC);
				}
			} else {
				if (hydrationMode == 1) {
					zephir_array_update_zval(&hydrate, key, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_update_property_zval_zval(hydrate, key, value TSRMLS_CC);
				}
			}
		}
	}
	RETURN_CCTOR(hydrate);

}

/**
 * Assigns values to a model from an array returning a new model
 *
 *<code>
 *$robot = Phalcon\Mvc\Model::cloneResult(new Robots(), array(
 *  'type' => 'mechanical',
 *  'name' => 'Astro Boy',
 *  'year' => 1952
 *));
 *</code>
 *
 * @param Phalcon\Mvc\Model $base
 * @param array data
 * @param int dirtyState
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResult) {

	HashTable *_2;
	HashPosition _1;
	int dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval *base, *data, *dirtyState_param = NULL, *instance, *key = NULL, *value = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &base, &data, &dirtyState_param);

	if (!dirtyState_param) {
		dirtyState = 0;
	} else {
		dirtyState = zephir_get_intval(dirtyState_param);
	}


	if (!(zephir_instance_of_ev(base, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'base' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Data to dump in the object must be an Array", "phalcon/mvc/model.zep", 648);
		return;
	}
	ZEPHIR_INIT_VAR(instance);
	if (zephir_clone(instance, base TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, instance, "setdirtystate", NULL, _0);
	zephir_check_call_status();
	zephir_is_iterable(data, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (Z_TYPE_P(key) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid key in array data provided to dumpResult()", "phalcon/mvc/model.zep", 663);
			return;
		}
		zephir_update_property_zval_zval(instance, key, value TSRMLS_CC);
	}
	if ((zephir_method_exists_ex(instance, SS("afterfetch") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "afterfetch", NULL);
		zephir_check_call_status();
	}
	RETURN_CCTOR(instance);

}

/**
 * Allows to query a set of records that match the specified conditions
 *
 * <code>
 *
 * //How many robots are there?
 * $robots = Robots::find();
 * echo "There are ", count($robots), "\n";
 *
 * //How many mechanical robots are there?
 * $robots = Robots::find("type='mechanical'");
 * echo "There are ", count($robots), "\n";
 *
 * //Get and print virtual robots ordered by name
 * $robots = Robots::find(array("type='virtual'", "order" => "name"));
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 *
 * //Get first 100 virtual robots ordered by name
 * $robots = Robots::find(array("type='virtual'", "order" => "name", "limit" => 100));
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 * </code>
 *
 * @param 	array parameters
 * @return  Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, find) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, *params = NULL, *builder, *query = NULL, *bindParams = NULL, *bindTypes = NULL, *cache, *resultset = NULL, *hydration, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE);
		}
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_INIT_VAR(builder);
	object_init_ex(builder, phalcon_mvc_model_query_builder_ce);
	ZEPHIR_CALL_METHOD(NULL, builder, "__construct", NULL, params);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_get_called_class(_0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, builder, "from", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, builder, "getquery",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(bindParams);
	ZVAL_NULL(bindParams);
	ZEPHIR_INIT_VAR(bindTypes);
	ZVAL_NULL(bindTypes);
	ZEPHIR_OBS_NVAR(bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, params, SS("bind"), 0 TSRMLS_CC)) {
		ZEPHIR_OBS_NVAR(bindTypes);
		zephir_array_isset_string_fetch(&bindTypes, params, SS("bindTypes"), 0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(cache);
	if (zephir_array_isset_string_fetch(&cache, params, SS("cache"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, query, "cache", NULL, cache);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&resultset, query, "execute", NULL, bindParams, bindTypes);
	zephir_check_call_status();
	if (Z_TYPE_P(resultset) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(hydration);
		if (zephir_array_isset_string_fetch(&hydration, params, SS("hydration"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, resultset, "sethydratemode", NULL, hydration);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(resultset);

}

/**
 * Allows to query the first record that match the specified conditions
 *
 * <code>
 *
 * //What's the first robot in robots table?
 * $robot = Robots::findFirst();
 * echo "The robot name is ", $robot->name;
 *
 * //What's the first mechanical robot in robots table?
 * $robot = Robots::findFirst("type='mechanical'");
 * echo "The first mechanical robot name is ", $robot->name;
 *
 * //Get first virtual robot ordered by name
 * $robot = Robots::findFirst(array("type='virtual'", "order" => "name"));
 * echo "The first virtual robot name is ", $robot->name;
 *
 * </code>
 *
 * @param array parameters
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, findFirst) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, *params = NULL, *builder, *query = NULL, *bindParams = NULL, *bindTypes = NULL, *cache, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE);
		}
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_INIT_VAR(builder);
	object_init_ex(builder, phalcon_mvc_model_query_builder_ce);
	ZEPHIR_CALL_METHOD(NULL, builder, "__construct", NULL, params);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_get_called_class(_0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, builder, "from", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(NULL, builder, "limit", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, builder, "getquery",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(bindParams);
	ZVAL_NULL(bindParams);
	ZEPHIR_INIT_VAR(bindTypes);
	ZVAL_NULL(bindTypes);
	ZEPHIR_OBS_NVAR(bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, params, SS("bind"), 0 TSRMLS_CC)) {
		ZEPHIR_OBS_NVAR(bindTypes);
		zephir_array_isset_string_fetch(&bindTypes, params, SS("bindTypes"), 0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(cache);
	if (zephir_array_isset_string_fetch(&cache, params, SS("cache"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, query, "cache", NULL, cache);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, query, "setuniquerow", NULL, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(query, "execute", NULL, bindParams, bindTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Create a criteria for a specific model
 *
 * @param Phalcon\DiInterface dependencyInjector
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model, query) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zend_bool _0;
	zval *dependencyInjector = NULL, *criteria, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		ZEPHIR_CPY_WRT(dependencyInjector, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(dependencyInjector);
	}


	_0 = Z_TYPE_P(dependencyInjector) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_1);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(criteria);
	object_init_ex(criteria, phalcon_mvc_model_criteria_ce);
	if (zephir_has_constructor(criteria TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, criteria, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, criteria, "setdi", NULL, dependencyInjector);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_get_called_class(_2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, criteria, "setmodelname", NULL, _2);
	zephir_check_call_status();
	RETURN_CCTOR(criteria);

}

/**
 * Checks if the current record already exists or not
 *
 * @param Phalcon\Mvc\Model\MetadataInterface metaData
 * @param Phalcon\Db\AdapterInterface connection
 * @param string|array table
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _exists) {

	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	HashTable *_1;
	HashPosition _0;
	int numberEmpty, numberPrimary, ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, *connection, *table = NULL, *uniqueParams = NULL, *uniqueTypes = NULL, *uniqueKey = NULL, *columnMap = NULL, *primaryKeys = NULL, *wherePk, *field = NULL, *attributeField = NULL, *value = NULL, *bindDataTypes = NULL, *joinWhere, *num = NULL, *type = NULL, *schema = NULL, *source = NULL, **_2, *_3 = NULL, *_4 = NULL, *_7 = NULL, *_8, *_9, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &metaData, &connection, &table);

	if (!table) {
		ZEPHIR_CPY_WRT(table, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(table);
	}


	if (!(zephir_instance_of_ev(metaData, phalcon_mvc_model_metadatainterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'metaData' must be an instance of 'Phalcon\\Mvc\\Model\\MetadataInterface'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(connection, phalcon_db_adapterinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'connection' must be an instance of 'Phalcon\\Db\\AdapterInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(uniqueParams);
	ZVAL_NULL(uniqueParams);
	ZEPHIR_INIT_VAR(uniqueTypes);
	ZVAL_NULL(uniqueTypes);
	ZEPHIR_OBS_VAR(uniqueKey);
	zephir_read_property_this(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	if (Z_TYPE_P(uniqueKey) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, this_ptr);
		zephir_check_call_status();
		numberPrimary = zephir_fast_count_int(primaryKeys TSRMLS_CC);
		if (!(numberPrimary)) {
			RETURN_MM_BOOL(0);
		}
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, this_ptr);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(columnMap);
			ZVAL_NULL(columnMap);
		}
		numberEmpty = 0;
		ZEPHIR_INIT_VAR(wherePk);
		array_init(wherePk);
		ZEPHIR_INIT_BNVAR(uniqueParams);
		array_init(uniqueParams);
		ZEPHIR_INIT_BNVAR(uniqueTypes);
		array_init(uniqueTypes);
		zephir_is_iterable(primaryKeys, &_1, &_0, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(field, _2);
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_LNVAR(_3);
					object_init_ex(_3, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SVS(_4, "Column '", field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
					zephir_check_call_status();
					zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 911 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, field);
			}
			ZEPHIR_INIT_NVAR(value);
			ZVAL_NULL(value);
			ZEPHIR_OBS_NVAR(value);
			if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
				if (ZEPHIR_IS_EMPTY(value)) {
					numberEmpty++;
				}
				zephir_array_append(&uniqueParams, value, PH_SEPARATE);
			} else {
				zephir_array_append(&uniqueParams, ZEPHIR_GLOBAL(global_null), PH_SEPARATE);
				numberEmpty++;
			}
			ZEPHIR_OBS_NVAR(type);
			if (!(zephir_array_isset_fetch(&type, bindDataTypes, field, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_LNVAR(_3);
				object_init_ex(_3, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "Column '", field, "' isn't part of the table columns");
				ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_6, _4);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 937 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&uniqueTypes, type, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_7, connection, "escapeidentifier", NULL, field);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_3);
			ZEPHIR_CONCAT_VS(_3, _7, " = ?");
			zephir_array_append(&wherePk, _3, PH_SEPARATE);
		}
		if (numberPrimary == numberEmpty) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(joinWhere);
		zephir_fast_join_str(joinWhere, SL(" AND "), wherePk TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_uniqueKey"), joinWhere TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_uniqueParams"), uniqueParams TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_uniqueTypes"), uniqueTypes TSRMLS_CC);
		ZEPHIR_CPY_WRT(uniqueKey, joinWhere);
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_dirtyState"), PH_NOISY_CC);
	if (!(zephir_is_true(_8))) {
		RETURN_MM_BOOL(1);
	}
	if (Z_TYPE_P(uniqueKey) == IS_NULL) {
		ZEPHIR_OBS_NVAR(uniqueKey);
		zephir_read_property_this(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(uniqueParams) == IS_NULL) {
		ZEPHIR_OBS_NVAR(uniqueParams);
		zephir_read_property_this(&uniqueParams, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(uniqueTypes) == IS_NULL) {
		ZEPHIR_OBS_NVAR(uniqueTypes);
		zephir_read_property_this(&uniqueTypes, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC);
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource",  NULL);
	zephir_check_call_status();
	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_NVAR(table);
		array_init_size(table, 3);
		zephir_array_fast_append(table, schema);
		zephir_array_fast_append(table, source);
	} else {
		ZEPHIR_CPY_WRT(table, source);
	}
	ZEPHIR_CALL_METHOD(&_7, connection, "escapeidentifier", NULL, table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_CONCAT_SVSV(_9, "SELECT COUNT(*) \"rowcount\" FROM ", _7, " WHERE ", uniqueKey);
	ZEPHIR_CALL_METHOD(&num, connection, "fetchone", NULL, _9, ZEPHIR_GLOBAL(global_null), uniqueParams, uniqueTypes);
	zephir_check_call_status();
	zephir_array_fetch_string(&_10, num, SL("rowcount"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if (zephir_is_true(_10)) {
		ZEPHIR_INIT_ZVAL_NREF(_8);
		ZVAL_LONG(_8, 0);
		zephir_update_property_this(this_ptr, SL("_dirtyState"), _8 TSRMLS_CC);
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_8);
		ZVAL_LONG(_8, 1);
		zephir_update_property_this(this_ptr, SL("_dirtyState"), _8 TSRMLS_CC);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Generate a PHQL SELECT statement for an aggregate
 *
 * @param string function
 * @param string alias
 * @param array parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, _groupResult) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *functionName_param = NULL, *alias_param = NULL, *parameters, *params = NULL, *distinctColumn, *groupColumn, *columns = NULL, *bindParams = NULL, *bindTypes = NULL, *resultset = NULL, *cache, *firstRow = NULL, *groupColumns, *builder, *query = NULL, *_0, *_1;
	zval *functionName = NULL, *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &functionName_param, &alias_param, &parameters);

	if (unlikely(Z_TYPE_P(functionName_param) != IS_STRING && Z_TYPE_P(functionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'functionName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(functionName_param) == IS_STRING)) {
		functionName = functionName_param;
	} else {
		ZEPHIR_INIT_VAR(functionName);
		ZVAL_EMPTY_STRING(functionName);
	}
	if (unlikely(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(alias_param) == IS_STRING)) {
		alias = alias_param;
	} else {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_EMPTY_STRING(alias);
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE);
		}
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_OBS_VAR(groupColumn);
	if (!(zephir_array_isset_string_fetch(&groupColumn, params, SS("column"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(groupColumn);
		ZVAL_LONG(groupColumn, '*');
	}
	ZEPHIR_OBS_VAR(distinctColumn);
	if (zephir_array_isset_string_fetch(&distinctColumn, params, SS("distinct"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(columns);
		ZEPHIR_CONCAT_VSVSV(columns, functionName, "(DISTINCT ", distinctColumn, ") AS ", alias);
	} else {
		ZEPHIR_INIT_NVAR(columns);
		ZEPHIR_OBS_VAR(groupColumns);
		if (zephir_array_isset_string_fetch(&groupColumns, params, SS("group"), 0 TSRMLS_CC)) {
			ZEPHIR_CONCAT_VSVSVSV(columns, groupColumns, ", ", functionName, "(", groupColumn, ") AS ", alias);
		} else {
			ZEPHIR_CONCAT_VSVSV(columns, functionName, "(", groupColumn, ") AS ", alias);
		}
	}
	ZEPHIR_INIT_VAR(builder);
	object_init_ex(builder, phalcon_mvc_model_query_builder_ce);
	ZEPHIR_CALL_METHOD(NULL, builder, "__construct", NULL, params);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, builder, "columns", NULL, columns);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_get_called_class(_0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, builder, "from", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, builder, "getquery",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(bindParams);
	ZVAL_NULL(bindParams);
	ZEPHIR_INIT_VAR(bindTypes);
	ZVAL_NULL(bindTypes);
	ZEPHIR_OBS_NVAR(bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, params, SS("bind"), 0 TSRMLS_CC)) {
		ZEPHIR_OBS_NVAR(bindTypes);
		zephir_array_isset_string_fetch(&bindTypes, params, SS("bindTypes"), 0 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&resultset, query, "execute", NULL, bindParams, bindTypes);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(cache);
	if (zephir_array_isset_string_fetch(&cache, params, SS("cache"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, query, "cache", NULL, cache);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(params, SS("group"))) {
		RETURN_CCTOR(resultset);
	}
	ZEPHIR_CALL_METHOD(&firstRow, resultset, "getfirst",  NULL);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, firstRow, alias, PH_NOISY_CC);
	RETURN_CCTOR(_1);

}

/**
 * Allows to count how many records match the specified conditions
 *
 * <code>
 *
 * //How many robots are there?
 * $number = Robots::count();
 * echo "There are ", $number, "\n";
 *
 * //How many mechanical robots are there?
 * $number = Robots::count("type='mechanical'");
 * echo "There are ", $number, " mechanical robots\n";
 *
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, count) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "COUNT", 0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "rowcount", 0);
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, _0, _1, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to calculate a summatory on a column that match the specified conditions
 *
 * <code>
 *
 * //How much are all robots?
 * $sum = Robots::sum(array('column' => 'price'));
 * echo "The total price of robots is ", $sum, "\n";
 *
 * //How much are mechanical robots?
 * $sum = Robots::sum(array("type='mechanical'", 'column' => 'price'));
 * echo "The total price of mechanical robots is  ", $sum, "\n";
 *
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, sum) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "SUM", 0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "sumatory", 0);
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, _0, _1, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to get the maximum value of a column that match the specified conditions
 *
 * <code>
 *
 * //What is the maximum robot id?
 * $id = Robots::maximum(array('column' => 'id'));
 * echo "The maximum robot id is: ", $id, "\n";
 *
 * //What is the maximum id of mechanical robots?
 * $sum = Robots::maximum(array("type='mechanical'", 'column' => 'id'));
 * echo "The maximum robot id of mechanical robots is ", $id, "\n";
 *
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, maximum) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "MAX", 0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "maximum", 0);
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, _0, _1, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to get the minimum value of a column that match the specified conditions
 *
 * <code>
 *
 * //What is the minimum robot id?
 * $id = Robots::minimum(array('column' => 'id'));
 * echo "The minimum robot id is: ", $id;
 *
 * //What is the minimum id of mechanical robots?
 * $sum = Robots::minimum(array("type='mechanical'", 'column' => 'id'));
 * echo "The minimum robot id of mechanical robots is ", $id;
 *
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, minimum) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "MIN", 0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "minimum", 0);
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, _0, _1, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to calculate the average value on a column matching the specified conditions
 *
 * <code>
 *
 * //What's the average price of robots?
 * $average = Robots::average(array('column' => 'price'));
 * echo "The average price is ", $average, "\n";
 *
 * //What's the average price of mechanical robots?
 * $average = Robots::average(array("type='mechanical'", 'column' => 'price'));
 * echo "The average price of mechanical robots is ", $average, "\n";
 *
 * </code>
 *
 * @param array parameters
 * @return double
 */
PHP_METHOD(Phalcon_Mvc_Model, average) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "AVG", 0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "average", 0);
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, _0, _1, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 *
 * @param string eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEvent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, *_0;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

	if (unlikely(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(eventName_param) == IS_STRING)) {
		eventName = eventName_param;
	} else {
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_EMPTY_STRING(eventName);
	}


	if ((zephir_method_exists(this_ptr, eventName TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, Z_STRVAL_P(eventName), NULL);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "notifyevent", NULL, eventName, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 * This method stops if one of the callbacks/listeners returns boolean false
 *
 * @param string eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEventCancel) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, *_0 = NULL, *_1;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

	if (unlikely(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(eventName_param) == IS_STRING)) {
		eventName = eventName_param;
	} else {
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_EMPTY_STRING(eventName);
	}


	if ((zephir_method_exists(this_ptr, eventName TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, Z_STRVAL_P(eventName),  NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(_0)) {
			RETURN_MM_BOOL(0);
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, _1, "notifyevent", NULL, eventName, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(_0)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Cancel the current operation
 *
 */
PHP_METHOD(Phalcon_Mvc_Model, _cancelOperation) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_operationMade"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_0, 3)) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "notDeleted", 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "notSaved", 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Appends a customized message on the validation process
 *
 * <code>
 * use \Phalcon\Mvc\Model\Message as Message;
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *
 *   public function beforeSave()
 *   {
 *     if ($this->name == 'Peter') {
 *        $message = new Message("Sorry, but a robot cannot be named Peter");
 *        $this->appendMessage($message);
 *     }
 *   }
 * }
 * </code>
 *
 * @param Phalcon\Mvc\Model\MessageInterface message
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, appendMessage) {

	zval *message;

	zephir_fetch_params(0, 1, 0, &message);



	if (!(zephir_instance_of_ev(message, phalcon_mvc_model_messageinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'message' must be an instance of 'Phalcon\\Mvc\\Model\\MessageInterface'", "", 0);
		return;
	}
	zephir_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Executes validators on every validation call
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 *class Subscriptors extends \Phalcon\Mvc\Model
 *{
 *
 *	public function validation()
 *  {
 * 		$this->validate(new ExclusionIn(array(
 *			'field' => 'status',
 *			'domain' => array('A', 'I')
 *		)));
 *		if ($this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 *
 * @param object validator
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, validate) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *validator, *message = NULL, *_0 = NULL, *_1 = NULL, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &validator);



	if (Z_TYPE_P(validator) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Validator must be an Object", "phalcon/mvc/model.zep", 1331);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, validator, "validate", NULL, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(_0)) {
		ZEPHIR_CALL_METHOD(&_1, validator, "getmessages",  NULL);
		zephir_check_call_status();
		zephir_is_iterable(_1, &_3, &_2, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(message, _4);
			zephir_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Check whether validation process has generated any messages
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 *class Subscriptors extends \Phalcon\Mvc\Model
 *{
 *
 *	public function validation()
 *  {
 * 		$this->validate(new ExclusionIn(array(
 *			'field' => 'status',
 *			'domain' => array('A', 'I')
 *		)));
 *		if ($this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, validationHasFailed) {

	zval *errorMessages;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(errorMessages);
	zephir_read_property_this(&errorMessages, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
	if (Z_TYPE_P(errorMessages) == IS_ARRAY) {
		RETURN_MM_BOOL(zephir_fast_count_int(errorMessages TSRMLS_CC) > 0);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns all the validation messages
 *
 *<code>
 *	$robot = new Robots();
 *	$robot->type = 'mechanical';
 *	$robot->name = 'Astro Boy';
 *	$robot->year = 1952;
 *	if ($robot->save() == false) {
 *  	echo "Umh, We can't store robots right now ";
 *  	foreach ($robot->getMessages() as $message) {
 *			echo $message;
 *		}
 *	} else {
 *  	echo "Great, a new robot was saved successfully!";
 *	}
 * </code>
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model, getMessages) {


	RETURN_MEMBER(this_ptr, "_errorMessages");

}

/**
 * Reads "belongs to" relations and check the virtual foreign keys when inserting or updating records
 * to verify that inserted/updated values are present in the related entity
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysRestrict) {

	zephir_fcall_cache_entry *_14 = NULL, *_15 = NULL;
	zval *_11 = NULL;
	HashTable *_2, *_6;
	HashPosition _1, _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool error;
	zval *manager = NULL, *belongsTo = NULL, *foreignKey = NULL, *relation = NULL, *conditions = NULL, *position = NULL, *bindParams = NULL, *extraConditions = NULL, *message = NULL, *fields = NULL, *referencedFields = NULL, *field = NULL, *action = NULL, *referencedModel = NULL, *value = NULL, *_0, **_3, *_4 = NULL, **_7, *_8, *_9 = NULL, *_10 = NULL, *_12 = NULL, *_13 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_CALL_METHOD(&belongsTo, manager, "getbelongsto", NULL, this_ptr);
	zephir_check_call_status();
	if (zephir_fast_count_int(belongsTo TSRMLS_CC)) {
		error = 0;
		zephir_is_iterable(belongsTo, &_2, &_1, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(relation, _3);
			ZEPHIR_CALL_METHOD(&foreignKey, relation, "getforeignkey",  NULL);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE(foreignKey)) {
				ZEPHIR_INIT_NVAR(action);
				ZVAL_LONG(action, 1);
				if (Z_TYPE_P(foreignKey) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(action);
					zephir_array_isset_string_fetch(&action, foreignKey, SS("action"), 0 TSRMLS_CC);
				}
				if (ZEPHIR_IS_LONG(action, 1)) {
					ZEPHIR_CALL_METHOD(&_4, relation, "getreferencedmodel",  NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, manager, "load", NULL, _4);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(conditions);
					array_init(conditions);
					ZEPHIR_INIT_NVAR(bindParams);
					array_init(bindParams);
					ZEPHIR_CALL_METHOD(&fields, relation, "getfields",  NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields",  NULL);
					zephir_check_call_status();
					if (Z_TYPE_P(fields) == IS_ARRAY) {
						zephir_is_iterable(fields, &_6, &_5, 0, 0);
						for (
						  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
						  ; zephir_hash_move_forward_ex(_6, &_5)
						) {
							ZEPHIR_GET_HMKEY(position, _6, _5);
							ZEPHIR_GET_HVALUE(field, _7);
							ZEPHIR_OBS_NVAR(value);
							zephir_fetch_property_zval(&value, this_ptr, field, PH_SILENT_CC);
							zephir_array_fetch(&_8, referencedFields, position, PH_NOISY | PH_READONLY TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_9);
							ZEPHIR_CONCAT_SVSV(_9, "[", _8, "] = ?", position);
							zephir_array_append(&conditions, _9, PH_SEPARATE);
							zephir_array_append(&bindParams, value, PH_SEPARATE);
						}
					} else {
						ZEPHIR_OBS_NVAR(value);
						zephir_fetch_property_zval(&value, this_ptr, fields, PH_SILENT_CC);
						ZEPHIR_INIT_LNVAR(_9);
						ZEPHIR_CONCAT_SVS(_9, "[", referencedFields, "] = ?0");
						zephir_array_append(&conditions, _9, PH_SEPARATE);
						zephir_array_append(&bindParams, value, PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(extraConditions);
					if (zephir_array_isset_string_fetch(&extraConditions, foreignKey, SS("conditions"), 0 TSRMLS_CC)) {
						zephir_array_append(&conditions, extraConditions, PH_SEPARATE);
					}
					ZEPHIR_INIT_NVAR(_11);
					array_init_size(_11, 3);
					ZEPHIR_INIT_NVAR(_12);
					zephir_fast_join_str(_12, SL(" AND "), conditions TSRMLS_CC);
					zephir_array_fast_append(_11, _12);
					zephir_array_update_string(&_11, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_10, referencedModel, "count", NULL, _11);
					zephir_check_call_status();
					if (!(zephir_is_true(_10))) {
						ZEPHIR_OBS_NVAR(message);
						if (!(zephir_array_isset_string_fetch(&message, foreignKey, SS("message"), 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(message);
							if (Z_TYPE_P(fields) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(_12);
								zephir_fast_join_str(_12, SL(", "), fields TSRMLS_CC);
								ZEPHIR_CONCAT_SVS(message, "Value of fields '", _12, "' does not exist on referenced table");
							} else {
								ZEPHIR_CONCAT_SVS(message, "Value of field '", fields, "' does not exist on referenced table");
							}
						}
						ZEPHIR_INIT_LNVAR(_9);
						object_init_ex(_9, phalcon_mvc_model_message_ce);
						ZEPHIR_INIT_NVAR(_13);
						ZVAL_STRING(_13, "ConstraintViolation", 0);
						ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_14, message, fields, _13);
						zephir_check_temp_parameter(_13);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_15, _9);
						zephir_check_call_status();
						error = 1;
						break;
					}
				}
			}
		}
		if (error == 1) {
			if (ZEPHIR_GLOBAL(orm).events) {
				ZEPHIR_INIT_NVAR(_12);
				ZVAL_STRING(_12, "onValidationFails", 0);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, _12);
				zephir_check_temp_parameter(_12);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL);
				zephir_check_call_status();
			}
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (cascade) when deleting records
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseCascade) {

	zval *_10 = NULL;
	HashTable *_2, *_6;
	HashPosition _1, _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *manager = NULL, *relations = NULL, *relation = NULL, *foreignKey = NULL, *resulset = NULL, *conditions = NULL, *bindParams = NULL, *referencedModel = NULL, *referencedFields = NULL, *action = NULL, *fields = NULL, *field = NULL, *position = NULL, *value = NULL, *extraConditions = NULL, *_0, **_3, *_4 = NULL, **_7, *_8, *_9 = NULL, *_11 = NULL, *_12 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_CALL_METHOD(&relations, manager, "gethasoneandhasmany", NULL, this_ptr);
	zephir_check_call_status();
	if (zephir_fast_count_int(relations TSRMLS_CC)) {
		zephir_is_iterable(relations, &_2, &_1, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(relation, _3);
			ZEPHIR_CALL_METHOD(&foreignKey, relation, "getforeignkey",  NULL);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE(foreignKey)) {
				ZEPHIR_INIT_NVAR(action);
				ZVAL_LONG(action, 0);
				if (Z_TYPE_P(foreignKey) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(action);
					zephir_array_isset_string_fetch(&action, foreignKey, SS("action"), 0 TSRMLS_CC);
				}
				if (ZEPHIR_IS_LONG(action, 2)) {
					ZEPHIR_CALL_METHOD(&_4, relation, "getreferencedmodel",  NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, manager, "load", NULL, _4);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&fields, relation, "getfields",  NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields",  NULL);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(conditions);
					array_init(conditions);
					ZEPHIR_INIT_NVAR(bindParams);
					array_init(bindParams);
					if (Z_TYPE_P(fields) == IS_ARRAY) {
						zephir_is_iterable(fields, &_6, &_5, 0, 0);
						for (
						  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
						  ; zephir_hash_move_forward_ex(_6, &_5)
						) {
							ZEPHIR_GET_HMKEY(position, _6, _5);
							ZEPHIR_GET_HVALUE(field, _7);
							ZEPHIR_OBS_NVAR(value);
							zephir_fetch_property_zval(&value, this_ptr, field, PH_SILENT_CC);
							zephir_array_fetch(&_8, referencedFields, position, PH_NOISY | PH_READONLY TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_9);
							ZEPHIR_CONCAT_SVSV(_9, "[", _8, "] = ?", position);
							zephir_array_append(&conditions, _9, PH_SEPARATE);
							zephir_array_append(&bindParams, value, PH_SEPARATE);
						}
					} else {
						ZEPHIR_OBS_NVAR(value);
						zephir_fetch_property_zval(&value, this_ptr, fields, PH_SILENT_CC);
						ZEPHIR_INIT_LNVAR(_9);
						ZEPHIR_CONCAT_SVS(_9, "[", referencedFields, "] = ?0");
						zephir_array_append(&conditions, _9, PH_SEPARATE);
						zephir_array_append(&bindParams, value, PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(extraConditions);
					if (zephir_array_isset_string_fetch(&extraConditions, foreignKey, SS("conditions"), 0 TSRMLS_CC)) {
						zephir_array_append(&conditions, extraConditions, PH_SEPARATE);
					}
					ZEPHIR_INIT_NVAR(_10);
					array_init_size(_10, 3);
					ZEPHIR_INIT_NVAR(_11);
					zephir_fast_join_str(_11, SL(" AND "), conditions TSRMLS_CC);
					zephir_array_fast_append(_10, _11);
					zephir_array_update_string(&_10, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&resulset, referencedModel, "find", NULL, _10);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_12, resulset, "delete",  NULL);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE(_12)) {
						RETURN_MM_BOOL(0);
					}
				}
			}
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (restrict) when deleting records
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseRestrict) {

	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL;
	zval *_9 = NULL;
	HashTable *_1, *_4;
	HashPosition _0, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *manager, *relations = NULL, *foreignKey = NULL, *action = NULL, *relation = NULL, *relationClass = NULL, *referencedModel = NULL, *fields = NULL, *referencedFields = NULL, *conditions = NULL, *bindParams = NULL, *position = NULL, *field = NULL, *value = NULL, *extraConditions = NULL, *message = NULL, **_2, **_5, *_6, *_7 = NULL, *_8 = NULL, *_10 = NULL;
	zend_bool error;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&relations, manager, "gethasoneandhasmany", NULL, this_ptr);
	zephir_check_call_status();
	if (zephir_fast_count_int(relations TSRMLS_CC)) {
		error = 0;
		zephir_is_iterable(relations, &_1, &_0, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(relation, _2);
			ZEPHIR_CALL_METHOD(&foreignKey, relation, "getforeignkey",  NULL);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE(foreignKey)) {
				ZEPHIR_INIT_NVAR(action);
				ZVAL_LONG(action, 1);
				if (Z_TYPE_P(foreignKey) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(action);
					zephir_array_isset_string_fetch(&action, foreignKey, SS("action"), 0 TSRMLS_CC);
				}
				if (ZEPHIR_IS_LONG(action, 1)) {
					ZEPHIR_CALL_METHOD(&relationClass, relation, "getreferencedmodel",  NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, manager, "load", NULL, relationClass);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&fields, relation, "getfields",  NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields",  NULL);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(conditions);
					array_init(conditions);
					ZEPHIR_INIT_NVAR(bindParams);
					array_init(bindParams);
					if (Z_TYPE_P(fields) == IS_ARRAY) {
						zephir_is_iterable(fields, &_4, &_3, 0, 0);
						for (
						  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
						  ; zephir_hash_move_forward_ex(_4, &_3)
						) {
							ZEPHIR_GET_HMKEY(position, _4, _3);
							ZEPHIR_GET_HVALUE(field, _5);
							ZEPHIR_OBS_NVAR(value);
							zephir_fetch_property_zval(&value, this_ptr, field, PH_SILENT_CC);
							zephir_array_fetch(&_6, referencedFields, position, PH_NOISY | PH_READONLY TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_7);
							ZEPHIR_CONCAT_SVSV(_7, "[", _6, "] = ?", position);
							zephir_array_append(&conditions, _7, PH_SEPARATE);
							zephir_array_append(&bindParams, value, PH_SEPARATE);
						}
					} else {
						ZEPHIR_OBS_NVAR(value);
						zephir_fetch_property_zval(&value, this_ptr, fields, PH_SILENT_CC);
						ZEPHIR_INIT_LNVAR(_7);
						ZEPHIR_CONCAT_SVS(_7, "[", referencedFields, "] = ?0");
						zephir_array_append(&conditions, _7, PH_SEPARATE);
						zephir_array_append(&bindParams, value, PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(extraConditions);
					if (zephir_array_isset_string_fetch(&extraConditions, foreignKey, SS("conditions"), 0 TSRMLS_CC)) {
						zephir_array_append(&conditions, extraConditions, PH_SEPARATE);
					}
					ZEPHIR_INIT_NVAR(_9);
					array_init_size(_9, 3);
					ZEPHIR_INIT_NVAR(_10);
					zephir_fast_join_str(_10, SL(" AND "), conditions TSRMLS_CC);
					zephir_array_fast_append(_9, _10);
					zephir_array_update_string(&_9, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_8, referencedModel, "count", NULL, _9);
					zephir_check_call_status();
					if (zephir_is_true(_8)) {
						ZEPHIR_OBS_NVAR(message);
						if (!(zephir_array_isset_string_fetch(&message, foreignKey, SS("message"), 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(message);
							ZEPHIR_CONCAT_SV(message, "Record is referenced by model ", relationClass);
						}
						ZEPHIR_INIT_LNVAR(_7);
						object_init_ex(_7, phalcon_mvc_model_message_ce);
						ZEPHIR_INIT_NVAR(_10);
						ZVAL_STRING(_10, "ConstraintViolation", 0);
						ZEPHIR_CALL_METHOD(NULL, _7, "__construct", &_11, message, fields, _10);
						zephir_check_temp_parameter(_10);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_12, _7);
						zephir_check_call_status();
						error = 1;
						break;
					}
				}
			}
		}
		if (error == 1) {
			if (ZEPHIR_GLOBAL(orm).events) {
				ZEPHIR_INIT_NVAR(_10);
				ZVAL_STRING(_10, "onValidationFails", 0);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, _10);
				zephir_check_temp_parameter(_10);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL);
				zephir_check_call_status();
			}
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Executes internal hooks before save a record
 *
 * @param Phalcon\Mvc\Model\MetadataInterface metaData
 * @param boolean exists
 * @param string identityField
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _preSave) {

	zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL;
	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool exists, error, isNull;
	zval *metaData, *exists_param = NULL, *identityField, *notNull = NULL, *columnMap = NULL, *dataTypeNumeric = NULL, *automaticAttributes = NULL, *field = NULL, *attributeField = NULL, *value = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, **_5, *_6 = NULL, *_7 = NULL, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &metaData, &exists_param, &identityField);

	exists = zephir_get_boolval(exists_param);


	if (!(zephir_instance_of_ev(metaData, phalcon_mvc_model_metadatainterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'metaData' must be an instance of 'Phalcon\\Mvc\\Model\\MetadataInterface'", "", 0);
		return;
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "beforeValidation", 0);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "fireeventcancel", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(_0)) {
			RETURN_MM_BOOL(0);
		}
		if (exists) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "beforeValidationOnCreate", 0);
			ZEPHIR_CALL_METHOD(&_2, this_ptr, "fireeventcancel", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(_2)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "beforeValidationOnUpdate", 0);
			ZEPHIR_CALL_METHOD(&_2, this_ptr, "fireeventcancel", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(_2)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "_checkforeignkeysrestrict",  NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(_0)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GLOBAL(orm).not_null_validations) {
		ZEPHIR_CALL_METHOD(&notNull, metaData, "getnotnullattributes", NULL, this_ptr);
		zephir_check_call_status();
		if (Z_TYPE_P(notNull) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&dataTypeNumeric, metaData, "getdatatypesnumeric", NULL, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_GLOBAL(orm).column_renaming) {
				ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, this_ptr);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(columnMap);
				ZVAL_NULL(columnMap);
			}
			if (exists) {
				ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticupdateattributes", NULL, this_ptr);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticcreateattributes", NULL, this_ptr);
				zephir_check_call_status();
			}
			error = 0;
			zephir_is_iterable(notNull, &_4, &_3, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
			  ; zephir_hash_move_forward_ex(_4, &_3)
			) {
				ZEPHIR_GET_HVALUE(field, _5);
				if (!(zephir_array_isset(automaticAttributes, field))) {
					isNull = 0;
					if (Z_TYPE_P(columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(attributeField);
						if (!(zephir_array_isset_fetch(&attributeField, columnMap, field, 0 TSRMLS_CC))) {
							ZEPHIR_INIT_LNVAR(_6);
							object_init_ex(_6, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_7);
							ZEPHIR_CONCAT_SVS(_7, "Column '", field, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_8, _7);
							zephir_check_call_status();
							zephir_throw_exception_debug(_6, "phalcon/mvc/model.zep", 1851 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(attributeField, field);
					}
					ZEPHIR_OBS_NVAR(value);
					if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
						if (Z_TYPE_P(value) != IS_OBJECT) {
							if (!(zephir_array_isset(dataTypeNumeric, field))) {
								if (ZEPHIR_IS_EMPTY(value)) {
									isNull = 1;
								}
							} else {
								if (!(zephir_is_numeric(value))) {
									isNull = 1;
								}
							}
						}
					} else {
						isNull = 1;
					}
					if (isNull == 1) {
						if (!(exists)) {
							if (ZEPHIR_IS_EQUAL(field, identityField)) {
								continue;
							}
						}
						ZEPHIR_INIT_LNVAR(_6);
						object_init_ex(_6, phalcon_mvc_model_message_ce);
						ZEPHIR_INIT_LNVAR(_7);
						ZEPHIR_CONCAT_VS(_7, attributeField, " is required");
						ZEPHIR_INIT_NVAR(_1);
						ZVAL_STRING(_1, "PresenceOf", 0);
						ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_9, _7, attributeField, _1);
						zephir_check_temp_parameter(_1);
						zephir_check_call_status();
						zephir_update_property_array_append(this_ptr, SL("_errorMessages"), _6 TSRMLS_CC);
						error = 1;
					}
				}
			}
			if (error == 1) {
				if (ZEPHIR_GLOBAL(orm).events) {
					ZEPHIR_INIT_NVAR(_1);
					ZVAL_STRING(_1, "onValidationFails", 0);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, _1);
					zephir_check_temp_parameter(_1);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL);
					zephir_check_call_status();
				}
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "validation", 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fireeventcancel", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(_0)) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "onValidationFails", 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (!(exists)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "afterValidationOnCreate", 0);
			ZEPHIR_CALL_METHOD(&_0, this_ptr, "fireeventcancel", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(_0)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "afterValidationOnUpdate", 0);
			ZEPHIR_CALL_METHOD(&_2, this_ptr, "fireeventcancel", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(_2)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "afterValidation", 0);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "fireeventcancel", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(_2)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "beforeSave", 0);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "fireeventcancel", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(_2)) {
			RETURN_MM_BOOL(0);
		}
		zephir_update_property_this(this_ptr, SL("_skipped"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		if (exists) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "beforeUpdate", 0);
			ZEPHIR_CALL_METHOD(&_2, this_ptr, "fireeventcancel", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(_2)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "beforeCreate", 0);
			ZEPHIR_CALL_METHOD(&_2, this_ptr, "fireeventcancel", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(_2)) {
				RETURN_MM_BOOL(0);
			}
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_skipped"), PH_NOISY_CC);
		if (ZEPHIR_IS_TRUE(_10)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Executes internal events after save a record
 *
 * @param boolean success
 * @param boolean exists
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _postSave) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *success_param = NULL, *exists_param = NULL, *_0 = NULL;
	zend_bool success, exists;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &success_param, &exists_param);

	success = zephir_get_boolval(success_param);
	exists = zephir_get_boolval(exists_param);


	if (success == 1) {
		if (exists) {
			ZEPHIR_INIT_VAR(_0);
			ZVAL_STRING(_0, "afterUpdate", 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "afterCreate", 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "afterSave", 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		RETURN_MM_BOOL(success);
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "notSave", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL);
	zephir_check_call_status();
	RETURN_MM_BOOL(0);

}

/**
 * Sends a pre-build INSERT SQL statement to the relational database system
 *
 * @param Phalcon\Mvc\Model\MetadataInterface metaData
 * @param Phalcon\Db\AdapterInterface connection
 * @param string|array table
 * @param boolean|string identityField
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowInsert) {

	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool useExplicitIdentity, _8;
	zval *metaData, *connection, *table, *identityField, *bindSkip, *fields, *values, *bindTypes, *attributes = NULL, *bindDataTypes = NULL, *automaticAttributes = NULL, *field = NULL, *columnMap = NULL, *value = NULL, *attributeField = NULL, *success = NULL, *bindType = NULL, *defaultValue = NULL, *sequenceName = NULL, **_2, *_3 = NULL, *_4 = NULL, *_7 = NULL, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &metaData, &connection, &table, &identityField);



	if (!(zephir_instance_of_ev(metaData, phalcon_mvc_model_metadatainterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'metaData' must be an instance of 'Phalcon\\Mvc\\Model\\MetadataInterface'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(connection, phalcon_db_adapterinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'connection' must be an instance of 'Phalcon\\Db\\AdapterInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(bindSkip);
	ZVAL_LONG(bindSkip, 1024);
	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	ZEPHIR_INIT_VAR(values);
	array_init(values);
	ZEPHIR_INIT_VAR(bindTypes);
	array_init(bindTypes);
	ZEPHIR_CALL_METHOD(&attributes, metaData, "getattributes", NULL, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticcreateattributes", NULL, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(columnMap);
		ZVAL_NULL(columnMap);
	}
	zephir_is_iterable(attributes, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(field, _2);
		if (!(zephir_array_isset(automaticAttributes, field))) {
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_LNVAR(_3);
					object_init_ex(_3, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SVS(_4, "Column '", field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
					zephir_check_call_status();
					zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 2046 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, field);
			}
			if (!ZEPHIR_IS_EQUAL(field, identityField)) {
				zephir_array_append(&fields, field, PH_SEPARATE);
				ZEPHIR_OBS_NVAR(value);
				if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
					ZEPHIR_OBS_NVAR(bindType);
					if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, field, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_LNVAR(_3);
						object_init_ex(_3, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_4);
						ZEPHIR_CONCAT_SVS(_4, "Column '", field, "' have not defined a bind data type");
						ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_6, _4);
						zephir_check_call_status();
						zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 2068 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&values, value, PH_SEPARATE);
					zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
				} else {
					zephir_array_append(&values, ZEPHIR_GLOBAL(global_null), PH_SEPARATE);
					zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE);
				}
			}
		}
	}
	if (!ZEPHIR_IS_FALSE(identityField)) {
		ZEPHIR_CALL_METHOD(&defaultValue, connection, "getdefaultidvalue",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7, connection, "useexplicitidvalue",  NULL);
		zephir_check_call_status();
		useExplicitIdentity = zephir_get_boolval(_7);
		if (useExplicitIdentity) {
			zephir_array_append(&fields, identityField, PH_SEPARATE);
		}
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, columnMap, identityField, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_LNVAR(_3);
				object_init_ex(_3, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "Identity column '", identityField, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 2099 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(attributeField, identityField);
		}
		ZEPHIR_OBS_NVAR(value);
		if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
			if (ZEPHIR_IS_EMPTY(value)) {
				if (useExplicitIdentity) {
					zephir_array_append(&values, defaultValue, PH_SEPARATE);
					zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE);
				}
			} else {
				if (!(useExplicitIdentity)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(bindType);
				if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, identityField, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_LNVAR(_3);
					object_init_ex(_3, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SVS(_4, "Identity column '", identityField, "' isn\'t part of the table columns");
					ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4);
					zephir_check_call_status();
					zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 2127 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, value, PH_SEPARATE);
				zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
			}
		} else {
			if (useExplicitIdentity) {
				zephir_array_append(&values, defaultValue, PH_SEPARATE);
				zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&success, connection, "insert", NULL, table, values, fields, bindTypes);
	zephir_check_call_status();
	_8 = zephir_is_true(success);
	if (_8) {
		_8 = !ZEPHIR_IS_FALSE(identityField);
	}
	if (_8) {
		ZEPHIR_INIT_VAR(sequenceName);
		ZVAL_NULL(sequenceName);
		ZEPHIR_CALL_METHOD(&_7, connection, "supportsequences",  NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE(_7)) {
			if ((zephir_method_exists_ex(this_ptr, SS("getsequencename") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&sequenceName, this_ptr, "getsequencename",  NULL);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&_9, this_ptr, "getsource",  NULL);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(sequenceName);
				ZEPHIR_CONCAT_VSVS(sequenceName, _9, "_", identityField, "_seq");
			}
		}
		ZEPHIR_CALL_METHOD(&_9, connection, "lastinsertid", NULL, sequenceName);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, attributeField, _9 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_uniqueParams"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	}
	RETURN_CCTOR(success);

}

/**
 * Sends a pre-build UPDATE SQL statement to the relational database system
 *
 * @param Phalcon\Mvc\Model\MetaDataInterface metaData
 * @param Phalcon\Db\AdapterInterface connection
 * @param string|array table
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowUpdate) {

	zval *_12;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL, *_11 = NULL;
	HashTable *_2, *_9;
	HashPosition _1, _8;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool useDynamicUpdate, changed;
	zval *metaData, *connection, *table, *bindSkip, *fields, *values, *bindTypes, *manager, *bindDataTypes = NULL, *field = NULL, *automaticAttributes = NULL, *snapshotValue = NULL, *uniqueKey, *uniqueParams, *uniqueTypes, *snapshot, *nonPrimary = NULL, *columnMap = NULL, *attributeField = NULL, *value = NULL, *primaryKeys = NULL, *bindType = NULL, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL, **_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &metaData, &connection, &table);



	if (!(zephir_instance_of_ev(metaData, phalcon_mvc_model_metadatainterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'metaData' must be an instance of 'Phalcon\\Mvc\\Model\\MetaDataInterface'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(connection, phalcon_db_adapterinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'connection' must be an instance of 'Phalcon\\Db\\AdapterInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(bindSkip);
	ZVAL_LONG(bindSkip, 1024);
	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	ZEPHIR_INIT_VAR(values);
	array_init(values);
	ZEPHIR_INIT_VAR(bindTypes);
	array_init(bindTypes);
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, manager, "isusingdynamicupdate", NULL, this_ptr);
	zephir_check_call_status();
	useDynamicUpdate = zephir_get_boolval(_0);
	if (useDynamicUpdate) {
		ZEPHIR_OBS_VAR(snapshot);
		zephir_read_property_this(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
		if (Z_TYPE_P(snapshot) != IS_ARRAY) {
			useDynamicUpdate = 0;
		}
	}
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&nonPrimary, metaData, "getnonprimarykeyattributes", NULL, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticupdateattributes", NULL, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(columnMap);
		ZVAL_NULL(columnMap);
	}
	zephir_is_iterable(nonPrimary, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(field, _3);
		if (!(zephir_array_isset(automaticAttributes, field))) {
			ZEPHIR_OBS_NVAR(bindType);
			if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, field, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_LNVAR(_4);
				object_init_ex(_4, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_SVS(_5, "Column '", field, "' have not defined a bind data type");
				ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_6, _5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_4, "phalcon/mvc/model.zep", 2225 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_LNVAR(_4);
					object_init_ex(_4, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_SVS(_5, "Column '", field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_7, _5);
					zephir_check_call_status();
					zephir_throw_exception_debug(_4, "phalcon/mvc/model.zep", 2233 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, field);
			}
			ZEPHIR_OBS_NVAR(value);
			if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
				if (!(useDynamicUpdate)) {
					zephir_array_append(&fields, field, PH_SEPARATE);
					zephir_array_append(&values, value, PH_SEPARATE);
					zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
				} else {
					ZEPHIR_OBS_NVAR(snapshotValue);
					if (!(zephir_array_isset_fetch(&snapshotValue, snapshot, attributeField, 0 TSRMLS_CC))) {
						changed = 1;
					} else {
						changed = !ZEPHIR_IS_EQUAL(value, snapshotValue);
					}
					if (changed) {
						zephir_array_append(&fields, field, PH_SEPARATE);
						zephir_array_append(&values, value, PH_SEPARATE);
						zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
					}
				}
			} else {
				zephir_array_append(&fields, field, PH_SEPARATE);
				zephir_array_append(&values, ZEPHIR_GLOBAL(global_null), PH_SEPARATE);
				zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE);
			}
		}
	}
	if (!(zephir_fast_count_int(fields TSRMLS_CC))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_OBS_VAR(uniqueKey);
	zephir_read_property_this(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(uniqueParams);
	zephir_read_property_this(&uniqueParams, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(uniqueTypes);
	zephir_read_property_this(&uniqueTypes, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC);
	if (Z_TYPE_P(uniqueParams) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, this_ptr);
		zephir_check_call_status();
		if (!(zephir_fast_count_int(primaryKeys TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation", "phalcon/mvc/model.zep", 2299);
			return;
		}
		ZEPHIR_INIT_BNVAR(uniqueParams);
		array_init(uniqueParams);
		zephir_is_iterable(primaryKeys, &_9, &_8, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
		  ; zephir_hash_move_forward_ex(_9, &_8)
		) {
			ZEPHIR_GET_HVALUE(field, _10);
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_LNVAR(_4);
					object_init_ex(_4, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_SVS(_5, "Column '", field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_11, _5);
					zephir_check_call_status();
					zephir_throw_exception_debug(_4, "phalcon/mvc/model.zep", 2310 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, field);
			}
			ZEPHIR_OBS_NVAR(value);
			if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
				zephir_array_append(&uniqueParams, value, PH_SEPARATE);
			} else {
				zephir_array_append(&uniqueParams, ZEPHIR_GLOBAL(global_null), PH_SEPARATE);
			}
		}
	}
	ZEPHIR_INIT_VAR(_12);
	array_init_size(_12, 5);
	zephir_array_update_string(&_12, SL("conditions"), &uniqueKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_12, SL("bind"), &uniqueParams, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_12, SL("bindTypes"), &uniqueTypes, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(connection, "update", NULL, table, fields, values, _12, bindTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Saves related records that must be stored prior to save the master record
 *
 * @param Phalcon\Db\AdapterInterface connection
 * @param Phalcon\Mvc\ModelInterface[] related
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _preSaveRelatedRecords) {

	zephir_fcall_cache_entry *_7 = NULL;
	HashTable *_1, *_5;
	HashPosition _0, _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool nesting;
	zval *connection, *related, *className, *manager = NULL, *type = NULL, *relation = NULL, *columns = NULL, *referencedFields = NULL, *referencedModel = NULL, *message = NULL, *name = NULL, *record = NULL, **_2, *_3 = NULL, **_6, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &related);



	if (!(zephir_instance_of_ev(connection, phalcon_db_adapterinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'connection' must be an instance of 'Phalcon\\Db\\AdapterInterface'", "", 0);
		return;
	}
	nesting = 0;
	ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager",  NULL);
	zephir_check_call_status();
	zephir_is_iterable(related, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(name, _1, _0);
		ZEPHIR_GET_HVALUE(record, _2);
		ZEPHIR_CALL_METHOD(&relation, manager, "getrelationbyalias", NULL, className, name);
		zephir_check_call_status();
		if (Z_TYPE_P(relation) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&type, relation, "gettype",  NULL);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(type, 0)) {
				if (Z_TYPE_P(record) != IS_OBJECT) {
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
					zephir_check_call_status();
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects can be stored as part of belongs-to relations", "phalcon/mvc/model.zep", 2378);
					return;
				}
				ZEPHIR_CALL_METHOD(&columns, relation, "getfields",  NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, relation, "getreferencedmodel",  NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields",  NULL);
				zephir_check_call_status();
				if (Z_TYPE_P(columns) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
					zephir_check_call_status();
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/mvc/model.zep", 2387);
					return;
				}
				ZEPHIR_CALL_METHOD(&_3, record, "save",  NULL);
				zephir_check_call_status();
				if (!(zephir_is_true(_3))) {
					ZEPHIR_CALL_METHOD(&_3, record, "getmessages",  NULL);
					zephir_check_call_status();
					zephir_is_iterable(_3, &_5, &_4, 0, 0);
					for (
					  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
					  ; zephir_hash_move_forward_ex(_5, &_4)
					) {
						ZEPHIR_GET_HVALUE(message, _6);
						if (Z_TYPE_P(record) == IS_OBJECT) {
							ZEPHIR_CALL_METHOD(NULL, message, "setmodel", NULL, record);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_7, message);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
					zephir_check_call_status();
					RETURN_MM_BOOL(0);
				}
				ZEPHIR_CALL_METHOD(&_8, record, "readattribute", NULL, referencedFields);
				zephir_check_call_status();
				zephir_update_property_zval_zval(this_ptr, columns, _8 TSRMLS_CC);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Save the related records assigned in the has-one/has-many relations
 *
 * @param Phalcon\Db\AdapterInterface connection
 * @param Phalcon\Mvc\ModelInterface[] related
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _postSaveRelatedRecords) {

	zephir_fcall_cache_entry *_6 = NULL, *_14 = NULL, *_19 = NULL;
	HashTable *_1, *_9, *_12, *_17;
	HashPosition _0, _8, _11, _16;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool nesting, isThrough;
	zval *connection, *related, *className, *manager = NULL, *relation = NULL, *name = NULL, *record = NULL, *message = NULL, *columns = NULL, *referencedModel = NULL, *referencedFields = NULL, *relatedRecords = NULL, *value = NULL, *recordAfter = NULL, *intermediateModel = NULL, *intermediateFields = NULL, *intermediateValue = NULL, *intermediateModelName = NULL, *intermediateReferencedFields = NULL, **_2, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_7 = NULL, **_10, **_13, *_15 = NULL, **_18;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &related);



	if (!(zephir_instance_of_ev(connection, phalcon_db_adapterinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'connection' must be an instance of 'Phalcon\\Db\\AdapterInterface'", "", 0);
		return;
	}
	nesting = 0;
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager",  NULL);
	zephir_check_call_status();
	zephir_is_iterable(related, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(name, _1, _0);
		ZEPHIR_GET_HVALUE(record, _2);
		ZEPHIR_CALL_METHOD(&relation, manager, "getrelationbyalias", NULL, className, name);
		zephir_check_call_status();
		if (Z_TYPE_P(relation) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_3, relation, "gettype",  NULL);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(_3, 0)) {
				continue;
			}
			if (Z_TYPE_P(record) != IS_OBJECT) {
				if (Z_TYPE_P(record) != IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
					zephir_check_call_status();
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects/arrays can be stored as part of has-many/has-one/has-many-to-many relations", "phalcon/mvc/model.zep", 2470);
					return;
				}
			}
			ZEPHIR_CALL_METHOD(&columns, relation, "getfields",  NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedModel, relation, "getreferencedmodel",  NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields",  NULL);
			zephir_check_call_status();
			if (Z_TYPE_P(columns) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_check_call_status();
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/mvc/model.zep", 2480);
				return;
			}
			if (Z_TYPE_P(record) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(relatedRecords);
				array_init_size(relatedRecords, 2);
				zephir_array_fast_append(relatedRecords, record);
			} else {
				ZEPHIR_CPY_WRT(relatedRecords, record);
			}
			ZEPHIR_OBS_NVAR(value);
			if (!(zephir_fetch_property_zval(&value, this_ptr, columns, PH_SILENT_CC))) {
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_4);
				object_init_ex(_4, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_SVS(_5, "The column '", columns, "' needs to be present in the model");
				ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_6, _5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_4, "phalcon/mvc/model.zep", 2494 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_7, relation, "isthrough",  NULL);
			zephir_check_call_status();
			isThrough = zephir_get_boolval(_7);
			if (isThrough) {
				ZEPHIR_CALL_METHOD(&intermediateModelName, relation, "getintermediatemodel",  NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&intermediateFields, relation, "getintermediatefields",  NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&intermediateReferencedFields, relation, "getintermediatereferencedfields",  NULL);
				zephir_check_call_status();
			}
			zephir_is_iterable(relatedRecords, &_9, &_8, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
			  ; zephir_hash_move_forward_ex(_9, &_8)
			) {
				ZEPHIR_GET_HVALUE(recordAfter, _10);
				if (!(isThrough)) {
					ZEPHIR_CALL_METHOD(NULL, recordAfter, "writeattribute", NULL, referencedFields, value);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(&intermediateModel, manager, "load", NULL, intermediateModelName, ZEPHIR_GLOBAL(global_true));
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, intermediateModel, "writeattribute", NULL, intermediateFields, value);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(intermediateValue);
					zephir_read_property_zval(&intermediateValue, recordAfter, referencedFields, PH_NOISY_CC);
					ZEPHIR_CALL_METHOD(NULL, intermediateModel, "writeattribute", NULL, intermediateReferencedFields, intermediateValue);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_7, intermediateModel, "save",  NULL);
					zephir_check_call_status();
					if (!(zephir_is_true(_7))) {
						ZEPHIR_CALL_METHOD(&_7, intermediateModel, "getmessages",  NULL);
						zephir_check_call_status();
						zephir_is_iterable(_7, &_12, &_11, 0, 0);
						for (
						  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
						  ; zephir_hash_move_forward_ex(_12, &_11)
						) {
							ZEPHIR_GET_HVALUE(message, _13);
							if (Z_TYPE_P(message) != IS_OBJECT) {
								ZEPHIR_CALL_METHOD(NULL, message, "setmodel", NULL, record);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_14, message);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
						zephir_check_call_status();
						RETURN_MM_BOOL(0);
					}
				}
				ZEPHIR_CALL_METHOD(&_15, recordAfter, "save",  NULL);
				zephir_check_call_status();
				if (!(zephir_is_true(_15))) {
					ZEPHIR_CALL_METHOD(&_15, recordAfter, "getmessages",  NULL);
					zephir_check_call_status();
					zephir_is_iterable(_15, &_17, &_16, 0, 0);
					for (
					  ; zephir_hash_get_current_data_ex(_17, (void**) &_18, &_16) == SUCCESS
					  ; zephir_hash_move_forward_ex(_17, &_16)
					) {
						ZEPHIR_GET_HVALUE(message, _18);
						if (Z_TYPE_P(message) == IS_OBJECT) {
							ZEPHIR_CALL_METHOD(NULL, message, "setmodel", NULL, record);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_14, message);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
					zephir_check_call_status();
					RETURN_MM_BOOL(0);
				}
			}
		} else {
			if (Z_TYPE_P(record) != IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_4);
				object_init_ex(_4, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_SVSVS(_5, "There are no defined relations for the model '", className, "' using alias '", name, "'");
				ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_19, _5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_4, "phalcon/mvc/model.zep", 2610 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * Inserts or updates a model instance. Returning true on success or false otherwise.
 *
 *<code>
 *	//Creating a new robot
 *	$robot = new Robots();
 *	$robot->type = 'mechanical';
 *	$robot->name = 'Astro Boy';
 *	$robot->year = 1952;
 *	$robot->save();
 *
 *	//Updating a robot name
 *	$robot = Robots::findFirst("id=100");
 *	$robot->name = "Biomass";
 *	$robot->save();
 *</code>
 *
 * @param array data
 * @param array whiteList
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, save) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *whiteList = NULL, *metaData = NULL, *attribute = NULL, *attributes = NULL, *related, *schema = NULL, *possibleSetter = NULL, *value = NULL, *writeConnection = NULL, *readConnection = NULL, *source = NULL, *table = NULL, *identityField = NULL, *exists = NULL, *success = NULL, **_2, *_3 = NULL, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &whiteList);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}
	if (!whiteList) {
		whiteList = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata",  NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(data) != IS_NULL) {
		if (Z_TYPE_P(data) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Data passed to save() must be an array", "phalcon/mvc/model.zep", 2657);
			return;
		}
		ZEPHIR_CALL_METHOD(&attributes, metaData, "getcolumnmap", NULL, this_ptr);
		zephir_check_call_status();
		if (Z_TYPE_P(attributes) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&attributes, metaData, "getattributes", NULL, this_ptr);
			zephir_check_call_status();
		}
		zephir_is_iterable(attributes, &_1, &_0, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(attribute, _2);
			ZEPHIR_OBS_NVAR(value);
			if (zephir_array_isset_fetch(&value, data, attribute, 0 TSRMLS_CC)) {
				if (Z_TYPE_P(whiteList) == IS_ARRAY) {
					if (!(zephir_fast_in_array(attribute, whiteList TSRMLS_CC))) {
						continue;
					}
				}
				ZEPHIR_INIT_NVAR(possibleSetter);
				ZEPHIR_CONCAT_SV(possibleSetter, "set", attribute);
				if ((zephir_method_exists(this_ptr, possibleSetter TSRMLS_CC)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, Z_STRVAL_P(possibleSetter), NULL, value);
					zephir_check_call_status();
				} else {
					zephir_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
				}
			}
		}
	}
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection",  NULL);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(related);
	zephir_read_property_this(&related, this_ptr, SL("_related"), PH_NOISY_CC);
	if (Z_TYPE_P(related) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "_presaverelatedrecords", NULL, writeConnection, related);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(_3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource",  NULL);
	zephir_check_call_status();
	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(table);
		array_init_size(table, 3);
		zephir_array_fast_append(table, schema);
		zephir_array_fast_append(table, source);
	} else {
		ZEPHIR_CPY_WRT(table, source);
	}
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&exists, this_ptr, "_exists", NULL, metaData, readConnection, table);
	zephir_check_call_status();
	if (zephir_is_true(exists)) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, 2);
		zephir_update_property_this(this_ptr, SL("_operationMade"), _4 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, 1);
		zephir_update_property_this(this_ptr, SL("_operationMade"), _4 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_5);
	array_init(_5);
	zephir_update_property_this(this_ptr, SL("_errorMessages"), _5 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&identityField, metaData, "getidentityfield", NULL, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "_presave", NULL, metaData, exists, identityField);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(_3)) {
		if (Z_TYPE_P(related) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(NULL, writeConnection, "rollback", NULL, ZEPHIR_GLOBAL(global_false));
			zephir_check_call_status();
		}
		if (ZEPHIR_GLOBAL(orm).exception_on_failed_save) {
			ZEPHIR_INIT_VAR(_6);
			object_init_ex(_6, phalcon_mvc_model_validationfailed_ce);
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_errorMessages"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, this_ptr, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6, "phalcon/mvc/model.zep", 2769 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(0);
	}
	if (zephir_is_true(exists)) {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "_dolowupdate", NULL, metaData, writeConnection, table);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "_dolowinsert", NULL, metaData, writeConnection, table, identityField);
		zephir_check_call_status();
	}
	if (zephir_is_true(success)) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, 0);
		zephir_update_property_this(this_ptr, SL("_dirtyState"), _4 TSRMLS_CC);
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "_postsave", NULL, success, exists);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(success, _3);
	}
	if (Z_TYPE_P(related) == IS_ARRAY) {
		if (ZEPHIR_IS_FALSE(success)) {
			ZEPHIR_CALL_METHOD(NULL, writeConnection, "rollback", NULL, ZEPHIR_GLOBAL(global_false));
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "_postsaverelatedrecords", NULL, writeConnection, related);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(_3)) {
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_CCTOR(success);

}

/**
 * Inserts a model instance. If the instance already exists in the persistance it will throw an exception
 * Returning true on success or false otherwise.
 *
 *<code>
 *	//Creating a new robot
 *	$robot = new Robots();
 *	$robot->type = 'mechanical';
 *	$robot->name = 'Astro Boy';
 *	$robot->year = 1952;
 *	$robot->create();
 *
 *  //Passing an array to create
 *  $robot = new Robots();
 *  $robot->create(array(
 *      'type' => 'mechanical',
 *      'name' => 'Astroy Boy',
 *      'year' => 1952
 *  ));
 *</code>
 *
 * @param array data
 * @param array whiteList
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, create) {

	zval *_8;
	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *whiteList = NULL, *metaData = NULL, *attribute = NULL, *possibleSetter = NULL, *value = NULL, *columnMap = NULL, *attributeField = NULL, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL, *_7 = NULL, *_9, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &whiteList);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}
	if (!whiteList) {
		whiteList = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata",  NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(data) != IS_NULL) {
		if (Z_TYPE_P(data) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Data passed to create() must be an array", "phalcon/mvc/model.zep", 2856);
			return;
		}
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, this_ptr);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(columnMap);
			ZVAL_NULL(columnMap);
		}
		ZEPHIR_CALL_METHOD(&_0, metaData, "getattributes", NULL, this_ptr);
		zephir_check_call_status();
		zephir_is_iterable(_0, &_2, &_1, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(attribute, _3);
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, attribute, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_LNVAR(_4);
					object_init_ex(_4, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_SVS(_5, "Column '", attribute, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_6, _5);
					zephir_check_call_status();
					zephir_throw_exception_debug(_4, "phalcon/mvc/model.zep", 2875 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, attribute);
			}
			ZEPHIR_OBS_NVAR(value);
			if (zephir_array_isset_fetch(&value, data, attributeField, 0 TSRMLS_CC)) {
				if (Z_TYPE_P(whiteList) == IS_ARRAY) {
					if (!(zephir_fast_in_array(attributeField, whiteList TSRMLS_CC))) {
						continue;
					}
				}
				ZEPHIR_INIT_NVAR(possibleSetter);
				ZEPHIR_CONCAT_SV(possibleSetter, "set", attributeField);
				if ((zephir_method_exists(this_ptr, possibleSetter TSRMLS_CC)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, Z_STRVAL_P(possibleSetter), NULL, value);
					zephir_check_call_status();
				} else {
					zephir_update_property_zval_zval(this_ptr, attributeField, value TSRMLS_CC);
				}
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getreadconnection",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_exists", NULL, metaData, _7);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_8);
		array_init_size(_8, 2);
		ZEPHIR_INIT_LNVAR(_4);
		object_init_ex(_4, phalcon_mvc_model_message_ce);
		ZEPHIR_INIT_VAR(_9);
		ZVAL_STRING(_9, "Record cannot be created because it already exists", 0);
		ZEPHIR_INIT_VAR(_10);
		ZVAL_STRING(_10, "InvalidCreateAttempt", 0);
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, _9, ZEPHIR_GLOBAL(global_null), _10);
		zephir_check_temp_parameter(_9);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
		zephir_array_fast_append(_8, _4);
		zephir_update_property_this(this_ptr, SL("_errorMessages"), _8 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "save", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Updates a model instance. If the instance doesn't exist in the persistance it will throw an exception
 * Returning true on success or false otherwise.
 *
 *<code>
 *	//Updating a robot name
 *	$robot = Robots::findFirst("id=100");
 *	$robot->name = "Biomass";
 *	$robot->update();
 *</code>
 *
 * @param array data
 * @param array whiteList
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, update) {

	zval *_9;
	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *whiteList = NULL, *metaData = NULL, *columnMap = NULL, *attribute = NULL, *attributeField = NULL, *possibleSetter = NULL, *value = NULL, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL, *_7, *_8 = NULL, *_10, *_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &whiteList);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}
	if (!whiteList) {
		whiteList = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(metaData);
	ZVAL_NULL(metaData);
	if (Z_TYPE_P(data) != IS_NULL) {
		if (Z_TYPE_P(data) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Data passed to update() must be an array", "phalcon/mvc/model.zep", 2954);
			return;
		}
		ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata",  NULL);
		zephir_check_call_status();
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, this_ptr);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(columnMap);
			ZVAL_NULL(columnMap);
		}
		ZEPHIR_CALL_METHOD(&_0, metaData, "getattributes", NULL, this_ptr);
		zephir_check_call_status();
		zephir_is_iterable(_0, &_2, &_1, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(attribute, _3);
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, attribute, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_LNVAR(_4);
					object_init_ex(_4, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_SVS(_5, "Column '", attribute, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_6, _5);
					zephir_check_call_status();
					zephir_throw_exception_debug(_4, "phalcon/mvc/model.zep", 2974 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, attribute);
			}
			ZEPHIR_OBS_NVAR(value);
			if (zephir_array_isset_fetch(&value, data, attributeField, 0 TSRMLS_CC)) {
				if (Z_TYPE_P(whiteList) == IS_ARRAY) {
					if (!(zephir_fast_in_array(attributeField, whiteList TSRMLS_CC))) {
						continue;
					}
				}
				ZEPHIR_INIT_NVAR(possibleSetter);
				ZEPHIR_CONCAT_SV(possibleSetter, "set", attributeField);
				if ((zephir_method_exists(this_ptr, possibleSetter TSRMLS_CC)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, Z_STRVAL_P(possibleSetter), NULL, value);
					zephir_check_call_status();
				} else {
					zephir_update_property_zval_zval(this_ptr, attributeField, value TSRMLS_CC);
				}
			}
		}
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_dirtyState"), PH_NOISY_CC);
	if (zephir_is_true(_7)) {
		if (Z_TYPE_P(metaData) == IS_NULL) {
			ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata",  NULL);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_8, this_ptr, "getreadconnection",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "_exists", NULL, metaData, _8);
		zephir_check_call_status();
		if (zephir_is_true(_0)) {
			ZEPHIR_INIT_VAR(_9);
			array_init_size(_9, 2);
			ZEPHIR_INIT_LNVAR(_4);
			object_init_ex(_4, phalcon_mvc_model_message_ce);
			ZEPHIR_INIT_VAR(_10);
			ZVAL_STRING(_10, "Record cannot be updated because it does not exist", 0);
			ZEPHIR_INIT_VAR(_11);
			ZVAL_STRING(_11, "InvalidUpdateAttempt", 0);
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, _10, ZEPHIR_GLOBAL(global_null), _11);
			zephir_check_temp_parameter(_10);
			zephir_check_temp_parameter(_11);
			zephir_check_call_status();
			zephir_array_fast_append(_9, _4);
			zephir_update_property_this(this_ptr, SL("_errorMessages"), _9 TSRMLS_CC);
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "save", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 *
 * <code>
 *$robot = Robots::findFirst("id=100");
 *$robot->delete();
 *
 *foreach (Robots::find("type = 'mechanical'") as $robot) {
 *   $robot->delete();
 *}
 * </code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, delete) {

	zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL, *_10 = NULL;
	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *metaData = NULL, *writeConnection = NULL, *values, *bindTypes, *primaryKeys = NULL, *bindDataTypes = NULL, *columnMap = NULL, *attributeField = NULL, *conditions, *primaryKey = NULL, *bindType = NULL, *value = NULL, *schema = NULL, *source = NULL, *table = NULL, *success = NULL, *_0, *_1, *_2 = NULL, **_5, *_6 = NULL, *_7 = NULL, *_11 = NULL, *_12;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 3);
	zephir_update_property_this(this_ptr, SL("_operationMade"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_errorMessages"), _1 TSRMLS_CC);
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "_checkforeignkeysreverserestrict",  NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(_2)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(values);
	array_init(values);
	ZEPHIR_INIT_VAR(bindTypes);
	array_init(bindTypes);
	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(columnMap);
		ZVAL_NULL(columnMap);
	}
	if (!(zephir_fast_count_int(primaryKeys TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation", "phalcon/mvc/model.zep", 3085);
		return;
	}
	zephir_is_iterable(primaryKeys, &_4, &_3, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(primaryKey, _5);
		ZEPHIR_OBS_NVAR(bindType);
		if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, primaryKey, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_LNVAR(_6);
			object_init_ex(_6, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_7);
			ZEPHIR_CONCAT_SVS(_7, "Column '", primaryKey, "' have not defined a bind data type");
			ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_8, _7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6, "phalcon/mvc/model.zep", 3097 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, columnMap, primaryKey, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_LNVAR(_6);
				object_init_ex(_6, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_SVS(_7, "Column '", primaryKey, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_9, _7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_6, "phalcon/mvc/model.zep", 3105 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(attributeField, primaryKey);
		}
		ZEPHIR_OBS_NVAR(value);
		if (!(zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC))) {
			ZEPHIR_INIT_LNVAR(_6);
			object_init_ex(_6, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_7);
			ZEPHIR_CONCAT_SVS(_7, "Cannot delete the record because the primary key attribute: '", attributeField, "' wasn't set");
			ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_10, _7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6, "phalcon/mvc/model.zep", 3115 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_append(&values, value, PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_2, writeConnection, "escapeidentifier", NULL, primaryKey);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_6);
		ZEPHIR_CONCAT_VS(_6, _2, " = ?");
		zephir_array_append(&conditions, _6, PH_SEPARATE);
		zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		zephir_update_property_this(this_ptr, SL("_skipped"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		ZEPHIR_INIT_VAR(_11);
		ZVAL_STRING(_11, "beforeDelete", 0);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "fireeventcancel", NULL, _11);
		zephir_check_temp_parameter(_11);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(_2)) {
			RETURN_MM_BOOL(0);
		} else {
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("_skipped"), PH_NOISY_CC);
			if (ZEPHIR_IS_TRUE(_0)) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource",  NULL);
	zephir_check_call_status();
	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(table);
		array_init_size(table, 3);
		zephir_array_fast_append(table, schema);
		zephir_array_fast_append(table, source);
	} else {
		ZEPHIR_CPY_WRT(table, source);
	}
	ZEPHIR_INIT_NVAR(_11);
	zephir_fast_join_str(_11, SL(" AND "), conditions TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&success, writeConnection, "delete", NULL, table, _11, values, bindTypes);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "_checkforeignkeysreversecascade",  NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(_2)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (zephir_is_true(success)) {
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_STRING(_11, "afterDelete", 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, _11);
			zephir_check_temp_parameter(_11);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_ZVAL_NREF(_12);
	ZVAL_LONG(_12, 2);
	zephir_update_property_this(this_ptr, SL("_dirtyState"), _12 TSRMLS_CC);
	RETURN_CCTOR(success);

}

/**
 * Returns the type of the latest operation performed by the ORM
 * Returns one of the OP_* class constants
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model, getOperationMade) {


	RETURN_MEMBER(this_ptr, "_operationMade");

}

/**
 * Refreshes the model attributes re-querying the record from the database
 */
PHP_METHOD(Phalcon_Mvc_Model, refresh) {

	zval *_5 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *metaData = NULL, *readConnection = NULL, *schema = NULL, *source = NULL, *table = NULL, *uniqueKey = NULL, *uniqueParams, *dialect = NULL, *row = NULL, *fields, *attribute = NULL, *_0, *_1 = NULL, **_4, *_6 = NULL, *_7, *_8;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dirtyState"), PH_NOISY_CC);
	if (!ZEPHIR_IS_LONG(_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/mvc/model.zep", 3203);
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource",  NULL);
	zephir_check_call_status();
	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(table);
		array_init_size(table, 3);
		zephir_array_fast_append(table, schema);
		zephir_array_fast_append(table, source);
	} else {
		ZEPHIR_CPY_WRT(table, source);
	}
	ZEPHIR_OBS_VAR(uniqueKey);
	zephir_read_property_this(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	if (!(zephir_is_true(uniqueKey))) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "_exists", NULL, metaData, readConnection, table);
		zephir_check_call_status();
		if (zephir_is_true(_1)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/mvc/model.zep", 3225);
			return;
		}
		ZEPHIR_OBS_NVAR(uniqueKey);
		zephir_read_property_this(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(uniqueParams);
	zephir_read_property_this(&uniqueParams, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	if (Z_TYPE_P(uniqueParams) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/mvc/model.zep", 3233);
		return;
	}
	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	ZEPHIR_CALL_METHOD(&_1, metaData, "getattributes", NULL, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(_1, &_3, &_2, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(attribute, _4);
		ZEPHIR_INIT_NVAR(_5);
		array_init_size(_5, 2);
		zephir_array_fast_append(_5, attribute);
		zephir_array_append(&fields, _5, PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&dialect, readConnection, "getdialect",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_5);
	array_init_size(_5, 5);
	zephir_array_update_string(&_5, SL("columns"), &fields, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_6, readConnection, "escapeidentifier", NULL, table);
	zephir_check_call_status();
	zephir_array_update_string(&_5, SL("tables"), &_6, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("where"), &uniqueKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, dialect, "select", NULL, _5);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueTypes"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, 1);
	ZEPHIR_CALL_METHOD(&row, readConnection, "fetchone", NULL, _1, _8, uniqueParams, _7);
	zephir_check_call_status();
	if (Z_TYPE_P(row) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_6, metaData, "getcolumnmap", NULL, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, row, _6);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Skips the current operation forcing a success state
 *
 * @param boolean skip
 */
PHP_METHOD(Phalcon_Mvc_Model, skipOperation) {

	zval *skip_param = NULL;
	zend_bool skip;

	zephir_fetch_params(0, 1, 0, &skip_param);

	skip = zephir_get_boolval(skip_param);


	zephir_update_property_this(this_ptr, SL("_skipped"), skip ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

/**
 * Reads an attribute value by its name
 *
 * <code>
 * echo $robot->readAttribute('name');
 * </code>
 *
 * @param string attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, readAttribute) {

	zval *attribute_param = NULL, *_0;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute_param);

	if (unlikely(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(attribute_param) == IS_STRING)) {
		attribute = attribute_param;
	} else {
		ZEPHIR_INIT_VAR(attribute);
		ZVAL_EMPTY_STRING(attribute);
	}


	if (zephir_isset_property_zval(this_ptr, attribute TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_0);
		zephir_read_property_zval(&_0, this_ptr, attribute, PH_NOISY_CC);
		RETURN_CCTOR(_0);
	}
	RETURN_MM_NULL();

}

/**
 * Writes an attribute value by its name
 *
 * <code>
 * 	$robot->writeAttribute('name', 'Rosey');
 * </code>
 *
 * @param string attribute
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_Model, writeAttribute) {

	zval *attribute_param = NULL, *value;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);

	if (unlikely(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(attribute_param) == IS_STRING)) {
		attribute = attribute_param;
	} else {
		ZEPHIR_INIT_VAR(attribute);
		ZVAL_EMPTY_STRING(attribute);
	}


	zephir_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT/UPDATE statement
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->skipAttributes(array('price'));
 *   }
 *
 *}
 *</code>
 *
 * @param array attributes
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributes) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *attributes, *keysAttributes, *metaData = NULL, *attribute = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes);



	if (Z_TYPE_P(attributes) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Attributes must be an array", "phalcon/mvc/model.zep", 3331);
		return;
	}
	ZEPHIR_INIT_VAR(keysAttributes);
	array_init(keysAttributes);
	zephir_is_iterable(attributes, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(attribute, _2);
		zephir_array_update_zval(&keysAttributes, attribute, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, metaData, "setautomaticcreateattributes", NULL, this_ptr, keysAttributes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, metaData, "setautomaticupdateattributes", NULL, this_ptr, keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT statement
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->skipAttributesOnCreate(array('created_at'));
 *   }
 *
 *}
 *</code>
 *
 * @param array attributes
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnCreate) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *attributes, *keysAttributes, *metaData = NULL, *attribute = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes);



	if (Z_TYPE_P(attributes) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Attributes must be an array", "phalcon/mvc/model.zep", 3369);
		return;
	}
	ZEPHIR_INIT_VAR(keysAttributes);
	array_init(keysAttributes);
	zephir_is_iterable(attributes, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(attribute, _2);
		zephir_array_update_zval(&keysAttributes, attribute, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, metaData, "setautomaticcreateattributes", NULL, this_ptr, keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated UPDATE statement
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->skipAttributesOnUpdate(array('modified_in'));
 *   }
 *
 *}
 *</code>
 *
 * @param array attributes
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnUpdate) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *attributes, *keysAttributes, *attribute = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes);



	if (Z_TYPE_P(attributes) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Attributes must be an array", "phalcon/mvc/model.zep", 3406);
		return;
	}
	ZEPHIR_INIT_VAR(keysAttributes);
	array_init(keysAttributes);
	zephir_is_iterable(attributes, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(attribute, _2);
		zephir_array_update_zval(&keysAttributes, attribute, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getmodelsmetadata",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _3, "setautomaticupdateattributes", NULL, this_ptr, keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Setup a 1-1 relation between two models
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->hasOne('id', 'RobotsDescription', 'robots_id');
 *   }
 *
 *}
 *</code>
 *
 * @param	mixed fields
 * @param	string referenceModel
 * @param	mixed referencedFields
 * @param   array options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model, hasOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *referenceModel = NULL;
	zval *fields, *referenceModel_param = NULL, *referencedFields, *options = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		referenceModel = referenceModel_param;
	} else {
		ZEPHIR_INIT_VAR(referenceModel);
		ZVAL_EMPTY_STRING(referenceModel);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "addhasone", NULL, this_ptr, fields, referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setup a relation reverse 1-1  between two models
 *
 *<code>
 *<?php
 *
 *class RobotsParts extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->belongsTo('robots_id', 'Robots', 'id');
 *   }
 *
 *}
 *</code>
 *
 * @param	mixed fields
 * @param	string referenceModel
 * @param	mixed referencedFields
 * @param   array options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model, belongsTo) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *referenceModel = NULL;
	zval *fields, *referenceModel_param = NULL, *referencedFields, *options = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		referenceModel = referenceModel_param;
	} else {
		ZEPHIR_INIT_VAR(referenceModel);
		ZVAL_EMPTY_STRING(referenceModel);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "addbelongsto", NULL, this_ptr, fields, referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setup a relation 1-n between two models
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->hasMany('id', 'RobotsParts', 'robots_id');
 *   }
 *
 *}
 *</code>
 *
 * @param	mixed fields
 * @param	string referenceModel
 * @param	mixed referencedFields
 * @param   array options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model, hasMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *referenceModel = NULL;
	zval *fields, *referenceModel_param = NULL, *referencedFields, *options = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		referenceModel = referenceModel_param;
	} else {
		ZEPHIR_INIT_VAR(referenceModel);
		ZVAL_EMPTY_STRING(referenceModel);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "addhasmany", NULL, this_ptr, fields, referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setup a relation n-n between two models through an intermediate relation
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       //Setup a many-to-many relation to Parts through RobotsParts
 *       $this->hasManyToMany(
 *			'id',
 *			'RobotsParts',
 *			'robots_id',
 *			'parts_id',
 *			'Parts',
 *			'id'
 *		);
 *   }
 *
 *}
 *</code>
 *
 * @param	string|array fields
 * @param	string intermediateModel
 * @param	string|array intermediateFields
 * @param	string|array intermediateReferencedFields
 * @param	string referencedModel
 * @param   string|array referencedFields
 * @param   array options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model, hasManyToMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *intermediateModel = NULL, *referenceModel = NULL;
	zval *fields, *intermediateModel_param = NULL, *intermediateFields, *intermediateReferencedFields, *referenceModel_param = NULL, *referencedFields, *options = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 1, &fields, &intermediateModel_param, &intermediateFields, &intermediateReferencedFields, &referenceModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(intermediateModel_param) != IS_STRING && Z_TYPE_P(intermediateModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'intermediateModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(intermediateModel_param) == IS_STRING)) {
		intermediateModel = intermediateModel_param;
	} else {
		ZEPHIR_INIT_VAR(intermediateModel);
		ZVAL_EMPTY_STRING(intermediateModel);
	}
	zephir_get_strval(referenceModel, referenceModel_param);
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "addhasmanytomany", NULL, this_ptr, fields, intermediateModel, intermediateFields, intermediateReferencedFields, referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setups a behavior in a model
 *
 *<code>
 *<?php
 *
 *use Phalcon\Mvc\Model\Behavior\Timestampable;
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *		$this->addBehavior(new Timestampable(array(
 *			'onCreate' => array(
 *				'field' => 'created_at',
 *				'format' => 'Y-m-d'
 *			)
 *		)));
 *   }
 *
 *}
 *</code>
 *
 * @param Phalcon\Mvc\Model\BehaviorInterface behavior
 */
PHP_METHOD(Phalcon_Mvc_Model, addBehavior) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *behavior, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &behavior);



	if (!(zephir_instance_of_ev(behavior, phalcon_mvc_model_behaviorinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'behavior' must be an instance of 'Phalcon\\Mvc\\Model\\BehaviorInterface'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "addbehavior", NULL, this_ptr, behavior);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets if the model must keep the original record snapshot in memory
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *		$this->keepSnapshots(true);
 *   }
 *
 *}
 *</code>
 *
 * @param boolean keepSnapshots
 */
PHP_METHOD(Phalcon_Mvc_Model, keepSnapshots) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keepSnapshot_param = NULL, *_0;
	zend_bool keepSnapshot;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keepSnapshot_param);

	keepSnapshot = zephir_get_boolval(keepSnapshot_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "keepsnapshots", NULL, this_ptr, (keepSnapshot ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the record's snapshot data.
 * This method is used internally to set snapshot data when the model was set up to keep snapshot data
 *
 * @param array data
 * @param array columnMap
 */
PHP_METHOD(Phalcon_Mvc_Model, setSnapshotData) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *data, *columnMap = NULL, *key = NULL, *value = NULL, *snapshot, *attribute = NULL, **_2, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &columnMap);

	if (!columnMap) {
		columnMap = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The snapshot data must be an array", "phalcon/mvc/model.zep", 3617);
		return;
	}
	if (Z_TYPE_P(columnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(snapshot);
		array_init(snapshot);
		zephir_is_iterable(data, &_1, &_0, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(key, _1, _0);
			ZEPHIR_GET_HVALUE(value, _2);
			if (Z_TYPE_P(key) != IS_STRING) {
				continue;
			}
			ZEPHIR_OBS_NVAR(attribute);
			if (!(zephir_array_isset_fetch(&attribute, columnMap, key, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_LNVAR(_3);
				object_init_ex(_3, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "Column '", key, "' doesn't make part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 3639 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&snapshot, attribute, &value, PH_COPY | PH_SEPARATE);
		}
		zephir_update_property_this(this_ptr, SL("_snapshot"), snapshot TSRMLS_CC);
		RETURN_MM_NULL();
	}
	zephir_update_property_this(this_ptr, SL("_snapshot"), data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if the object has internal snapshot data
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, hasSnapshotData) {

	zval *snapshot;


	snapshot = zephir_fetch_nproperty_this(this_ptr, SL("_snapshot"), PH_NOISY_CC);
	if (Z_TYPE_P(snapshot) == IS_ARRAY) {
		RETURN_BOOL(1);
	}
	RETURN_BOOL(0);

}

/**
 * Returns the internal snapshot data
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model, getSnapshotData) {


	RETURN_MEMBER(this_ptr, "_snapshot");

}

/**
 * Check if a specific attribute has changed
 * This only works if the model is keeping data snapshots
 *
 * @param string|array fieldName
 */
PHP_METHOD(Phalcon_Mvc_Model, hasChanged) {

	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *fieldName = NULL, *snapshot, *metaData = NULL, *columnMap = NULL, *allAttributes = NULL, *value = NULL, *originalValue = NULL, *name = NULL, *type = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, **_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &fieldName);

	if (!fieldName) {
		fieldName = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(snapshot);
	zephir_read_property_this(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
	if (Z_TYPE_P(snapshot) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record doesn't have a valid data snapshot", "phalcon/mvc/model.zep", 3690);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dirtyState"), PH_NOISY_CC);
	if (!ZEPHIR_IS_LONG(_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Change checking cannot be performed because the object has not been persisted or is deleted", "phalcon/mvc/model.zep", 3697);
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, metaData, "getreversecolumnmap", NULL, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(columnMap) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&allAttributes, metaData, "getdatatypes", NULL, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(allAttributes, columnMap);
	}
	if (Z_TYPE_P(fieldName) == IS_ARRAY) {
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			if (!(zephir_array_isset(columnMap, fieldName))) {
				ZEPHIR_INIT_VAR(_1);
				object_init_ex(_1, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(_2);
				ZEPHIR_CONCAT_SVS(_2, "The field '", fieldName, "' is not part of the model");
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1, "phalcon/mvc/model.zep", 3729 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			if (!(zephir_array_isset(allAttributes, fieldName))) {
				ZEPHIR_INIT_LNVAR(_1);
				object_init_ex(_1, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_SVS(_2, "The field '", fieldName, "' is not part of the model");
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1, "phalcon/mvc/model.zep", 3733 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_OBS_VAR(value);
		if (!(zephir_fetch_property_zval(&value, this_ptr, fieldName, PH_SILENT_CC))) {
			ZEPHIR_INIT_LNVAR(_1);
			object_init_ex(_1, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_SVS(_2, "The field '", fieldName, "' is not defined on the model");
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1, "phalcon/mvc/model.zep", 3741 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(originalValue);
		if (!(zephir_array_isset_fetch(&originalValue, snapshot, fieldName, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_LNVAR(_1);
			object_init_ex(_1, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_CONCAT_SVS(_3, "The field '", fieldName, "' was not found in the snapshot");
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1, "phalcon/mvc/model.zep", 3748 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(!ZEPHIR_IS_EQUAL(value, originalValue));
	}
	zephir_is_iterable(allAttributes, &_5, &_4, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(name, _5, _4);
		ZEPHIR_GET_HVALUE(type, _6);
		ZEPHIR_OBS_NVAR(originalValue);
		if (!(zephir_array_isset_fetch(&originalValue, snapshot, name, 0 TSRMLS_CC))) {
			RETURN_MM_BOOL(1);
		}
		ZEPHIR_OBS_NVAR(value);
		if (!(zephir_fetch_property_zval(&value, this_ptr, name, PH_SILENT_CC))) {
			RETURN_MM_BOOL(1);
		}
		if (!ZEPHIR_IS_EQUAL(value, originalValue)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns a list of changed values
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model, getChangedFields) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *metaData = NULL, *changed, *name = NULL, *type = NULL, *snapshot, *columnMap = NULL, *allAttributes = NULL, *value = NULL, *_0, **_3, *_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(snapshot);
	zephir_read_property_this(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
	if (Z_TYPE_P(snapshot) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record doesn't have a valid data snapshot", "phalcon/mvc/model.zep", 3799);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dirtyState"), PH_NOISY_CC);
	if (!ZEPHIR_IS_LONG(_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Change checking cannot be performed because the object has not been persisted or is deleted", "phalcon/mvc/model.zep", 3806);
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, metaData, "getreversecolumnmap", NULL, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(columnMap) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&allAttributes, metaData, "getdatatypes", NULL, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(allAttributes, columnMap);
	}
	ZEPHIR_INIT_VAR(changed);
	array_init(changed);
	zephir_is_iterable(allAttributes, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(name, _2, _1);
		ZEPHIR_GET_HVALUE(type, _3);
		if (!(zephir_array_isset(snapshot, name))) {
			zephir_array_append(&changed, name, PH_SEPARATE);
			continue;
		}
		ZEPHIR_OBS_NVAR(value);
		if (!(zephir_fetch_property_zval(&value, this_ptr, name, PH_SILENT_CC))) {
			zephir_array_append(&changed, name, PH_SEPARATE);
			continue;
		}
		zephir_array_fetch(&_4, snapshot, name, PH_NOISY | PH_READONLY TSRMLS_CC);
		if (!ZEPHIR_IS_EQUAL(value, _4)) {
			zephir_array_append(&changed, name, PH_SEPARATE);
			continue;
		}
	}
	RETURN_CCTOR(changed);

}

/**
 * Sets if a model must use dynamic update instead of the all-field update
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *		$this->useDynamicUpdate(true);
 *   }
 *
 *}
 *</code>
 *
 * @param boolean dynamicUpdate
 */
PHP_METHOD(Phalcon_Mvc_Model, useDynamicUpdate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dynamicUpdate_param = NULL, *_0;
	zend_bool dynamicUpdate;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dynamicUpdate_param);

	dynamicUpdate = zephir_get_boolval(dynamicUpdate_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "usedynamicupdate", NULL, this_ptr, (dynamicUpdate ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns related records based on defined relations
 *
 * @param string alias
 * @param array arguments
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getRelated) {

	zval *_3, *_5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, *arguments = NULL, *relation = NULL, *className, *manager = NULL, *_0, *_1, *_2, *_4;
	zval *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &alias_param, &arguments);

	zephir_get_strval(alias, alias_param);
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, this_ptr, 0 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_CALL_METHOD(&relation, manager, "getrelationbyalias", NULL, className, alias);
	zephir_check_call_status();
	if (Z_TYPE_P(relation) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVSVS(_2, "There is no defined relations for the model '", className, "' using alias '", alias, "'");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/mvc/model.zep", 3905 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 3);
	zephir_array_fast_append(_3, manager);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "getRelationRecords", 1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_VAR(_5);
	array_init_size(_5, 7);
	zephir_array_fast_append(_5, relation);
	zephir_array_fast_append(_5, ZEPHIR_GLOBAL(global_null));
	zephir_array_fast_append(_5, this_ptr);
	zephir_array_fast_append(_5, arguments);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _3, _5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns related records defined relations depending on the method name
 *
 * @param string modelName
 * @param string method
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, _getRelatedRecords) {

	zval *_4, *_5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *modelName_param = NULL, *method_param = NULL, *arguments, *manager, *relation = NULL, *queryMethod, *extraArgs, _0 = zval_used_for_init, *_1 = NULL, *_3 = NULL;
	zval *modelName = NULL, *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &modelName_param, &method_param, &arguments);

	zephir_get_strval(modelName, modelName_param);
	zephir_get_strval(method, method_param);


	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(relation);
	ZVAL_BOOL(relation, 0);
	ZEPHIR_INIT_VAR(queryMethod);
	ZVAL_NULL(queryMethod);
	if (zephir_start_with_str(method, SL("get"))) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 3);
		ZEPHIR_CALL_FUNCTION(&_1, "substr", &_2, method, &_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&relation, manager, "getrelationbyalias", NULL, modelName, _1);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(relation) != IS_OBJECT) {
		if (zephir_start_with_str(method, SL("count"))) {
			ZEPHIR_INIT_BNVAR(queryMethod);
			ZVAL_STRING(queryMethod, "count", 1);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 5);
			ZEPHIR_CALL_FUNCTION(&_1, "substr", &_2, method, &_0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "count", 0);
			ZEPHIR_CALL_METHOD(&relation, manager, "getrelationbyalias", NULL, _3, _1);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		}
	}
	if (Z_TYPE_P(relation) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(extraArgs);
		zephir_array_isset_long_fetch(&extraArgs, arguments, 0, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4);
		array_init_size(_4, 3);
		zephir_array_fast_append(_4, manager);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "getRelationRecords", 1);
		zephir_array_fast_append(_4, _3);
		ZEPHIR_INIT_VAR(_5);
		array_init_size(_5, 7);
		zephir_array_fast_append(_5, relation);
		zephir_array_fast_append(_5, queryMethod);
		zephir_array_fast_append(_5, this_ptr);
		zephir_array_fast_append(_5, extraArgs);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _4, _5);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * Handles method calls when a method is not implemented
 *
 * @param	string method
 * @param	array arguments
 * @return	mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, __call) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *arguments = NULL, *modelName, *status = NULL, *records = NULL, *_0, *_1, *_2;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	zephir_get_strval(method, method_param);
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(modelName);
	zephir_get_class(modelName, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", NULL, modelName, method, arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(records) != IS_NULL) {
		RETURN_CCTOR(records);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&status, _0, "missingmethod", NULL, this_ptr, method, arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(status) != IS_NULL) {
		RETURN_CCTOR(status);
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVSVS(_2, "The method '", method, "' doesn't exist on model '", modelName, "'");
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "phalcon/mvc/model.zep", 3997 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Handles method calls when a static method is not implemented
 *
 * @param	string method
 * @param	array arguments
 * @return	mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, __callStatic) {

	zval *_7, *_8;
	zend_class_entry *_5, *_9;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL;
	zval *method_param = NULL, *arguments = NULL, *extraMethod = NULL, *type = NULL, *modelName, *value, *model, *attributes = NULL, *field = NULL, *extraMethodFirst = NULL, *metaData = NULL, _0 = zval_used_for_init, *_2 = NULL, *_3 = NULL;
	zval *method = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	zephir_get_strval(method, method_param);
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(extraMethod);
	ZVAL_NULL(extraMethod);
	if (zephir_start_with_str(method, SL("findFirstBy"))) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "findFirst", 1);
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 11);
		ZEPHIR_CALL_FUNCTION(&extraMethod, "substr", &_1, method, &_0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(extraMethod) == IS_NULL) {
		if (zephir_start_with_str(method, SL("findBy"))) {
			ZEPHIR_INIT_NVAR(type);
			ZVAL_STRING(type, "find", 1);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 6);
			ZEPHIR_CALL_FUNCTION(&extraMethod, "substr", &_1, method, &_0);
			zephir_check_call_status();
		}
	}
	if (Z_TYPE_P(extraMethod) == IS_NULL) {
		if (zephir_start_with_str(method, SL("countBy"))) {
			ZEPHIR_INIT_NVAR(type);
			ZVAL_STRING(type, "count", 1);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 7);
			ZEPHIR_CALL_FUNCTION(&extraMethod, "substr", &_1, method, &_0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(modelName);
	zephir_get_called_class(modelName TSRMLS_CC);
	if (!(zephir_is_true(extraMethod))) {
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVSVS(_3, "The static method '", method, "' doesn't exist on model '", modelName, "'");
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "phalcon/mvc/model.zep", 4048 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(value);
	if (!(zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_LNVAR(_2);
		object_init_ex(_2, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SVS(_4, "The static method '", method, "' requires one argument");
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "phalcon/mvc/model.zep", 4052 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(model);
	_5 = zend_fetch_class(Z_STRVAL_P(modelName), Z_STRLEN_P(modelName), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(model, _5);
	if (zephir_has_constructor(model TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, model, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&metaData, model, "getmodelsmetadata",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&attributes, metaData, "getreversecolumnmap", NULL, model);
	zephir_check_call_status();
	if (Z_TYPE_P(attributes) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&attributes, metaData, "getdatatypes", NULL, model);
		zephir_check_call_status();
	}
	if (zephir_array_isset(attributes, extraMethod)) {
		ZEPHIR_CPY_WRT(field, extraMethod);
	} else {
		ZEPHIR_CALL_FUNCTION(&extraMethodFirst, "lcfirst", &_6, extraMethod);
		zephir_check_call_status();
		if (zephir_array_isset(attributes, extraMethodFirst)) {
			ZEPHIR_CPY_WRT(field, extraMethodFirst);
		} else {
			ZEPHIR_INIT_VAR(field);
			zephir_uncamelize(field, extraMethod);
			if (!(zephir_array_isset(attributes, field))) {
				ZEPHIR_INIT_LNVAR(_2);
				object_init_ex(_2, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_3);
				ZEPHIR_CONCAT_SVS(_3, "Cannot resolve attribute '", extraMethod, "' in the model");
				ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _3);
				zephir_check_call_status();
				zephir_throw_exception_debug(_2, "phalcon/mvc/model.zep", 4086 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_INIT_VAR(_7);
	array_init_size(_7, 3);
	ZEPHIR_INIT_LNVAR(_2);
	ZEPHIR_CONCAT_VS(_2, field, " = ?0");
	zephir_array_update_string(&_7, SL("conditions"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_8);
	array_init_size(_8, 2);
	zephir_array_fast_append(_8, value);
	zephir_array_update_string(&_7, SL("bind"), &_8, PH_COPY | PH_SEPARATE);
	_9 = zend_fetch_class(Z_STRVAL_P(modelName), Z_STRLEN_P(modelName), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC(_9, Z_STRVAL_P(type), NULL, _7);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Magic method to assign values to the the model
 *
 * @param string property
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_Model, __set) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *value, *lowerProperty = NULL, *related, *modelName, *manager = NULL, *lowerKey = NULL, *relation = NULL, *referencedModel = NULL, *key = NULL, *item = NULL, *_0, **_3, *_4 = NULL;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &value);

	zephir_get_strval(property, property_param);


	if (Z_TYPE_P(value) == IS_OBJECT) {
		if (zephir_instance_of_ev(value, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(lowerProperty);
			zephir_fast_strtolower(lowerProperty, property);
			zephir_update_property_zval_zval(this_ptr, lowerProperty, value TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("_related"), lowerProperty, value TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_0);
			ZVAL_LONG(_0, 1);
			zephir_update_property_this(this_ptr, SL("_dirtyState"), _0 TSRMLS_CC);
			RETURN_CCTOR(value);
		}
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_NVAR(lowerProperty);
		zephir_fast_strtolower(lowerProperty, property);
		ZEPHIR_INIT_VAR(modelName);
		zephir_get_class(modelName, this_ptr, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager",  NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(related);
		array_init(related);
		zephir_is_iterable(value, &_2, &_1, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HMKEY(key, _2, _1);
			ZEPHIR_GET_HVALUE(item, _3);
			if (Z_TYPE_P(item) == IS_OBJECT) {
				if (zephir_instance_of_ev(item, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
					zephir_array_append(&related, value, PH_SEPARATE);
				}
			} else {
				ZEPHIR_INIT_NVAR(lowerKey);
				zephir_fast_strtolower(lowerKey, key);
				zephir_update_property_zval_zval(this_ptr, lowerKey, item TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&relation, manager, "getrelationbyalias", NULL, modelName, lowerProperty);
				zephir_check_call_status();
				if (Z_TYPE_P(relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&_4, relation, "getreferencedmodel",  NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, manager, "load", NULL, _4);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, referencedModel, "writeattribute", NULL, lowerKey, item);
					zephir_check_call_status();
				}
			}
		}
		if (zephir_fast_count_int(related TSRMLS_CC) > 0) {
			zephir_update_property_array(this_ptr, SL("_related"), lowerProperty, related TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_0);
			ZVAL_LONG(_0, 1);
			zephir_update_property_this(this_ptr, SL("_dirtyState"), _0 TSRMLS_CC);
		}
		RETURN_CCTOR(value);
	}
	zephir_update_property_zval_zval(this_ptr, property, value TSRMLS_CC);
	RETURN_CCTOR(value);

}

/**
 * Magic method to get related records using the relation alias as a property
 *
 * @param string property
 * @return Phalcon\Mvc\Model\Resultset|Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, __get) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *_0, *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *modelName, *manager = NULL, *lowerProperty, *relation = NULL, *result, *_1, *_3;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (unlikely(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(property_param) == IS_STRING)) {
		property = property_param;
	} else {
		ZEPHIR_INIT_VAR(property);
		ZVAL_EMPTY_STRING(property);
	}


	ZEPHIR_INIT_VAR(modelName);
	zephir_get_class(modelName, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(lowerProperty);
	zephir_fast_strtolower(lowerProperty, property);
	ZEPHIR_CALL_METHOD(&relation, manager, "getrelationbyalias", NULL, modelName, lowerProperty);
	zephir_check_call_status();
	if (Z_TYPE_P(relation) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(result);
		ZEPHIR_INIT_VAR(_0);
		array_init_size(_0, 3);
		zephir_array_fast_append(_0, manager);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "getRelationRecords", 1);
		zephir_array_fast_append(_0, _1);
		ZEPHIR_INIT_VAR(_2);
		array_init_size(_2, 7);
		zephir_array_fast_append(_2, relation);
		zephir_array_fast_append(_2, ZEPHIR_GLOBAL(global_null));
		zephir_array_fast_append(_2, this_ptr);
		zephir_array_fast_append(_2, ZEPHIR_GLOBAL(global_null));
		ZEPHIR_CALL_USER_FUNC_ARRAY(result, _0, _2);
		zephir_check_call_status();
		if (Z_TYPE_P(result) == IS_OBJECT) {
			zephir_update_property_zval_zval(this_ptr, lowerProperty, result TSRMLS_CC);
			if (zephir_instance_of_ev(result, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
				zephir_update_property_array(this_ptr, SL("_related"), lowerProperty, result TSRMLS_CC);
			}
		}
		RETURN_CCTOR(result);
	}
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVSV(_3, "Access to undefined property ", modelName, "::", property);
	ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", &_4, _3);
	zephir_check_call_status();
	RETURN_MM_NULL();

}

/**
 * Magic method to check if a property is a valid relation
 *
 * @param string property
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *modelName, *manager = NULL, *relation = NULL;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (unlikely(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(property_param) == IS_STRING)) {
		property = property_param;
	} else {
		ZEPHIR_INIT_VAR(property);
		ZVAL_EMPTY_STRING(property);
	}


	ZEPHIR_INIT_VAR(modelName);
	zephir_get_class(modelName, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&relation, manager, "getrelationbyalias", NULL, modelName, property);
	zephir_check_call_status();
	if (Z_TYPE_P(relation) == IS_OBJECT) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Serializes the object ignoring connections, services, related objects or static properties
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, serialize) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *metaData = NULL, *value = NULL, *attribute = NULL, *_0 = NULL, **_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, metaData, "getattributes", NULL, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(attribute, _3);
		ZEPHIR_OBS_NVAR(value);
		if (zephir_fetch_property_zval(&value, this_ptr, attribute, PH_SILENT_CC)) {
			zephir_array_update_zval(&data, attribute, &value, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&data, attribute, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", &_4, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes the object from a serialized string
 *
 * @param string data
 */
PHP_METHOD(Phalcon_Mvc_Model, unserialize) {

	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
	zval *data, *attributes = NULL, *dependencyInjector = NULL, *manager = NULL, *key = NULL, *value = NULL, *_2, **_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (Z_TYPE_P(data) == IS_STRING) {
		ZEPHIR_CALL_FUNCTION(&attributes, "unserialize", &_0, data);
		zephir_check_call_status();
		if (Z_TYPE_P(attributes) == IS_ARRAY) {
			ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_1);
			zephir_check_call_status();
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model.zep", 4289);
				return;
			}
			zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
			ZEPHIR_INIT_VAR(_2);
			ZVAL_STRING(_2, "modelsManager", 0);
			ZEPHIR_CALL_METHOD(&manager, dependencyInjector, "getshared", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			if (Z_TYPE_P(manager) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/mvc/model.zep", 4302);
				return;
			}
			zephir_update_property_this(this_ptr, SL("_modelsManager"), manager TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, manager, "initialize", NULL, this_ptr);
			zephir_check_call_status();
			zephir_is_iterable(attributes, &_4, &_3, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
			  ; zephir_hash_move_forward_ex(_4, &_3)
			) {
				ZEPHIR_GET_HMKEY(key, _4, _3);
				ZEPHIR_GET_HVALUE(value, _5);
				zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
			}
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data", "phalcon/mvc/model.zep", 4325);
	return;

}

/**
 * Returns a simple representation of the object that can be used with var_dump
 *
 *<code>
 * var_dump($robot->dump());
 *</code>
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model, dump) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", &_0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the instance as an array representation
 *
 *<code>
 * print_r($robot->toArray());
 *</code>
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model, toArray) {

	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *metaData = NULL, *columnMap = NULL, *attribute = NULL, *attributeField = NULL, *value = NULL, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, metaData, "getattributes", NULL, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(attribute, _3);
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, columnMap, attribute, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_LNVAR(_4);
				object_init_ex(_4, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_SVS(_5, "Column '", attribute, "' doesn't make part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_6, _5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_4, "phalcon/mvc/model.zep", 4366 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(attributeField, attribute);
		}
		ZEPHIR_OBS_NVAR(value);
		if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
			zephir_array_update_zval(&data, attributeField, &value, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&data, attributeField, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(data);

}

/**
 * Enables/disables options in the ORM
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model, setup) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *options_param = NULL, *disableEvents, *columnRenaming, *notNullValidations, *exceptionOnFailedSave, *phqlLiterals, *virtualForeignKeys, *_0 = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	if (unlikely(Z_TYPE_P(options_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'options' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		options = options_param;



	ZEPHIR_OBS_VAR(disableEvents);
	if (zephir_array_isset_string_fetch(&disableEvents, options, SS("events"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "orm.events", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "globals_set", &_1, _0, disableEvents);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(virtualForeignKeys);
	if (zephir_array_isset_string_fetch(&virtualForeignKeys, options, SS("virtualForeignKeys"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "orm.virtual_foreign_keys", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "globals_set", &_1, _0, virtualForeignKeys);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(columnRenaming);
	if (zephir_array_isset_string_fetch(&columnRenaming, options, SS("columnRenaming"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "orm.column_renaming", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "globals_set", &_1, _0, columnRenaming);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(notNullValidations);
	if (zephir_array_isset_string_fetch(&notNullValidations, options, SS("notNullValidations"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "orm.not_null_validations", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "globals_set", &_1, _0, notNullValidations);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(exceptionOnFailedSave);
	if (zephir_array_isset_string_fetch(&exceptionOnFailedSave, options, SS("exceptionOnFailedSave"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "orm.exception_on_failed_save", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "globals_set", &_1, _0, exceptionOnFailedSave);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(phqlLiterals);
	if (zephir_array_isset_string_fetch(&phqlLiterals, options, SS("phqlLiterals"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "orm.enable_literals", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "globals_set", &_1, _0, phqlLiterals);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

