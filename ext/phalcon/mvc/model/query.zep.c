
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "phalcon/mvc/model/orm.h"
#include "phalcon/mvc/model/query/scanner.h"
#include "phalcon/mvc/model/query/phql.h"


/**
 * Phalcon\Mvc\Model\Query
 *
 * This class takes a PHQL intermediate representation and executes it.
 *
 *<code>
 * $phql = "SELECT c.price*0.16 AS taxes, c.* FROM Cars AS c JOIN Brands AS b
 *          WHERE b.name = :name: ORDER BY c.name";
 *
 * $result = $manager->executeQuery(
 *     $phql,
 *     [
 *         "name" => "Lamborghini",
 *     ]
 * );
 *
 * foreach ($result as $row) {
 *     echo "Name: ",  $row->cars->name, "\n";
 *     echo "Price: ", $row->cars->price, "\n";
 *     echo "Taxes: ", $row->taxes, "\n";
 * }
 *
 * // with transaction
 * use Phalcon\Mvc\Model\Query;
 * use Phalcon\Mvc\Model\Transaction;
 *
 * // $di needs to have the service "db" registered for this to work
 * $di = Phalcon\Di\FactoryDefault::getDefault();
 *
 * $phql = 'SELECT * FROM robot';
 *
 * $myTransaction = new Transaction($di);
 * $myTransaction->begin();
 *
 * $newRobot = new Robot();
 * $newRobot->setTransaction($myTransaction);
 * $newRobot->type = "mechanical";
 * $newRobot->name = "Astro Boy";
 * $newRobot->year = 1952;
 * $newRobot->save();
 *
 * $queryWithTransaction = new Query($phql, $di);
 * $queryWithTransaction->setTransaction($myTransaction);
 *
 * $resultWithEntries = $queryWithTransaction->execute();
 *
 * $queryWithOutTransaction = new Query($phql, $di);
 * $resultWithOutEntries = $queryWithTransaction->execute()
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Query, phalcon, mvc_model_query, phalcon_mvc_model_query_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_manager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_metaData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_phql"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_ast"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_intermediate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_models"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sqlAliases"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sqlAliasesModels"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sqlModelsAliases"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sqlAliasesModelsInstances"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sqlColumnAliases"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_modelsInstances"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_cache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_cacheOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_uniqueRow"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_bindParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_bindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_enableImplicitJoins"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sharedLock"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * TransactionInterface so that the query can wrap a transaction
	 * around batch updates and intermediate selects within the transaction.
	 * however if a model got a transaction set inside it will use the local transaction instead of this one
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_transaction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_irPhqlCache"), ZEND_ACC_STATIC|ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_SELECT"), 309 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_INSERT"), 306 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_UPDATE"), 300 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_DELETE"), 303 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_query_ce TSRMLS_CC, 1, phalcon_mvc_model_queryinterface_ce);
	zend_class_implements(phalcon_mvc_model_query_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * TransactionInterface so that the query can wrap a transaction
 *
 *
 * around batch updates and intermediate selects within the transaction.
 * however if a model got a transaction set inside it will use the local transaction instead of this one
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getTransaction) {

	

	RETURN_MEMBER(getThis(), "_transaction");

}

/**
 * Phalcon\Mvc\Model\Query constructor
 *
 * @param string phql
 * @param \Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, __construct) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *phql = NULL, *dependencyInjector = NULL, *options = NULL, *enableImplicitJoins = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &phql, &dependencyInjector, &options);

	if (!phql) {
		phql = ZEPHIR_GLOBAL(global_null);
	}
	if (!dependencyInjector) {
		dependencyInjector = ZEPHIR_GLOBAL(global_null);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(phql) != IS_NULL) {
		zephir_update_property_this(getThis(), SL("_phql"), phql TSRMLS_CC);
	}
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, dependencyInjector);
		zephir_check_call_status();
	}
	_0 = Z_TYPE_P(options) == IS_ARRAY;
	if (_0) {
		ZEPHIR_OBS_VAR(enableImplicitJoins);
		_0 = zephir_array_isset_string_fetch(&enableImplicitJoins, options, SS("enable_implicit_joins"), 0 TSRMLS_CC);
	}
	if (_0) {
		if (ZEPHIR_IS_TRUE(enableImplicitJoins)) {
			zephir_update_property_this(getThis(), SL("_enableImplicitJoins"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_enableImplicitJoins"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	} else {
		if (ZEPHIR_GLOBAL(orm).enable_implicit_joins) {
			zephir_update_property_this(getThis(), SL("_enableImplicitJoins"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_enableImplicitJoins"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setDI) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dependencyInjector, *manager = NULL, *metaData = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dependencyInjector);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "modelsManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&manager, dependencyInjector, "getshared", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Injected service 'modelsManager' is invalid", "phalcon/mvc/model/query.zep", 192);
		return;
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&metaData, dependencyInjector, "getshared", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(metaData) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Injected service 'modelsMetaData' is invalid", "phalcon/mvc/model/query.zep", 197);
		return;
	}
	zephir_update_property_this(getThis(), SL("_manager"), manager TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_metaData"), metaData TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getDI) {

	

	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Tells to the query if only the first row in the resultset must be returned
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setUniqueRow) {

	zval *uniqueRow_param = NULL;
	zend_bool uniqueRow;

	zephir_fetch_params(0, 1, 0, &uniqueRow_param);

	uniqueRow = zephir_get_boolval(uniqueRow_param);


	if (uniqueRow) {
		zephir_update_property_this(getThis(), SL("_uniqueRow"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_uniqueRow"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Check if the query is programmed to get only the first row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getUniqueRow) {

	

	RETURN_MEMBER(getThis(), "_uniqueRow");

}

/**
 * Replaces the model's name to its source name in a qualified-name expression
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getQualified) {

	HashTable *_14$$12;
	HashPosition _13$$12;
	zend_bool _0, _1;
	zephir_fcall_cache_entry *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, number = 0;
	zval *expr_param = NULL, *columnName = NULL, *sqlColumnAliases = NULL, *metaData = NULL, *sqlAliases = NULL, *source = NULL, *sqlAliasesModelsInstances = NULL, *realColumnName = NULL, *columnDomain = NULL, *model = NULL, *models = NULL, *columnMap = NULL, *hasModel = NULL, *className = NULL, *_2, *_3$$5, *_4$$5, *_5$$5, *_6$$7, *_7$$7, *_8$$7, *_9$$10, *_10$$10, *_11$$10, *_12$$12, **_15$$12, *_16$$13 = NULL, *_18$$15 = NULL, *_19$$15, *_20$$15 = NULL, *_21$$16, *_22$$16, *_23$$16, *_24$$18, *_25$$18, *_26$$18, *_27$$22, *_28$$22, *_29$$22;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	expr = expr_param;


	ZEPHIR_OBS_VAR(columnName);
	zephir_array_fetch_string(&columnName, expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 241 TSRMLS_CC);
	ZEPHIR_OBS_VAR(sqlColumnAliases);
	zephir_read_property_this(&sqlColumnAliases, this_ptr, SL("_sqlColumnAliases"), PH_NOISY_CC);
	_0 = zephir_array_isset(sqlColumnAliases, columnName);
	if (_0) {
		_1 = !(zephir_array_isset_string(expr, SS("domain")));
		if (!(_1)) {
			zephir_array_fetch_string(&_2, expr, SL("domain"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 247 TSRMLS_CC);
			_1 = ZEPHIR_IS_EMPTY(_2);
		}
		_0 = _1;
	}
	if (_0) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		add_assoc_stringl_ex(return_value, SS("type"), SL("qualified"), 1);
		zephir_array_update_string(&return_value, SL("name"), &columnName, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(columnDomain);
	if (zephir_array_isset_string_fetch(&columnDomain, expr, SS("domain"), 0 TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(sqlAliases);
		zephir_read_property_this(&sqlAliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(source);
		if (!(zephir_array_isset_fetch(&source, sqlAliases, columnDomain, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_3$$5);
			object_init_ex(_3$$5, phalcon_mvc_model_exception_ce);
			_4$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_5$$5);
			ZEPHIR_CONCAT_SVSV(_5$$5, "Unknown model or alias '", columnDomain, "' (11), when preparing: ", _4$$5);
			ZEPHIR_CALL_METHOD(NULL, _3$$5, "__construct", NULL, 9, _5$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3$$5, "phalcon/mvc/model/query.zep", 267 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_OBS_VAR(sqlAliasesModelsInstances);
			zephir_read_property_this(&sqlAliasesModelsInstances, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
			ZEPHIR_OBS_VAR(model);
			if (!(zephir_array_isset_fetch(&model, sqlAliasesModelsInstances, columnDomain, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_6$$7);
				object_init_ex(_6$$7, phalcon_mvc_model_exception_ce);
				_7$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_8$$7);
				ZEPHIR_CONCAT_SVSV(_8$$7, "There is no model related to model or alias '", columnDomain, "', when executing: ", _7$$7);
				ZEPHIR_CALL_METHOD(NULL, _6$$7, "__construct", NULL, 9, _8$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_6$$7, "phalcon/mvc/model/query.zep", 286 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getreversecolumnmap", NULL, 0, model);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(columnMap);
			ZVAL_NULL(columnMap);
		}
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(realColumnName);
			if (!(zephir_array_isset_fetch(&realColumnName, columnMap, columnName, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_9$$10);
				object_init_ex(_9$$10, phalcon_mvc_model_exception_ce);
				_10$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_11$$10);
				ZEPHIR_CONCAT_SVSVSV(_11$$10, "Column '", columnName, "' doesn't belong to the model or alias '", columnDomain, "', when executing: ", _10$$10);
				ZEPHIR_CALL_METHOD(NULL, _9$$10, "__construct", NULL, 9, _11$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(_9$$10, "phalcon/mvc/model/query.zep", 298 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(realColumnName, columnName);
		}
	} else {
		number = 0;
		ZEPHIR_INIT_VAR(hasModel);
		ZVAL_BOOL(hasModel, 0);
		_12$$12 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
		zephir_is_iterable(_12$$12, &_14$$12, &_13$$12, 0, 0, "phalcon/mvc/model/query.zep", 328);
		for (
		  ; zend_hash_get_current_data_ex(_14$$12, (void**) &_15$$12, &_13$$12) == SUCCESS
		  ; zend_hash_move_forward_ex(_14$$12, &_13$$12)
		) {
			ZEPHIR_GET_HVALUE(model, _15$$12);
			ZEPHIR_CALL_METHOD(&_16$$13, metaData, "hasattribute", &_17, 0, model, columnName);
			zephir_check_call_status();
			if (zephir_is_true(_16$$13)) {
				number++;
				if (number > 1) {
					ZEPHIR_INIT_NVAR(_18$$15);
					object_init_ex(_18$$15, phalcon_mvc_model_exception_ce);
					_19$$15 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
					ZEPHIR_INIT_LNVAR(_20$$15);
					ZEPHIR_CONCAT_SVSV(_20$$15, "The column '", columnName, "' is ambiguous, when preparing: ", _19$$15);
					ZEPHIR_CALL_METHOD(NULL, _18$$15, "__construct", NULL, 9, _20$$15);
					zephir_check_call_status();
					zephir_throw_exception_debug(_18$$15, "phalcon/mvc/model/query.zep", 319 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(hasModel, model);
			}
		}
		if (ZEPHIR_IS_FALSE_IDENTICAL(hasModel)) {
			ZEPHIR_INIT_VAR(_21$$16);
			object_init_ex(_21$$16, phalcon_mvc_model_exception_ce);
			_22$$16 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_23$$16);
			ZEPHIR_CONCAT_SVSV(_23$$16, "Column '", columnName, "' doesn't belong to any of the selected models (1), when preparing: ", _22$$16);
			ZEPHIR_CALL_METHOD(NULL, _21$$16, "__construct", NULL, 9, _23$$16);
			zephir_check_call_status();
			zephir_throw_exception_debug(_21$$16, "phalcon/mvc/model/query.zep", 331 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(models);
		zephir_read_property_this(&models, this_ptr, SL("_models"), PH_NOISY_CC);
		if (Z_TYPE_P(models) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The models list was not loaded correctly", "phalcon/mvc/model/query.zep", 339);
			return;
		}
		ZEPHIR_INIT_VAR(className);
		zephir_get_class(className, hasModel, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(source);
		if (!(zephir_array_isset_fetch(&source, models, className, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_24$$18);
			object_init_ex(_24$$18, phalcon_mvc_model_exception_ce);
			_25$$18 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_26$$18);
			ZEPHIR_CONCAT_SVSV(_26$$18, "Can't obtain model's source from models list: '", className, "', when preparing: ", _25$$18);
			ZEPHIR_CALL_METHOD(NULL, _24$$18, "__construct", NULL, 9, _26$$18);
			zephir_check_call_status();
			zephir_throw_exception_debug(_24$$18, "phalcon/mvc/model/query.zep", 349 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getreversecolumnmap", NULL, 0, hasModel);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(columnMap);
			ZVAL_NULL(columnMap);
		}
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(realColumnName);
			if (!(zephir_array_isset_fetch(&realColumnName, columnMap, columnName, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_27$$22);
				object_init_ex(_27$$22, phalcon_mvc_model_exception_ce);
				_28$$22 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_29$$22);
				ZEPHIR_CONCAT_SVSV(_29$$22, "Column '", columnName, "' doesn't belong to any of the selected models (3), when preparing: ", _28$$22);
				ZEPHIR_CALL_METHOD(NULL, _27$$22, "__construct", NULL, 9, _29$$22);
				zephir_check_call_status();
				zephir_throw_exception_debug(_27$$22, "phalcon/mvc/model/query.zep", 368 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(realColumnName, columnName);
		}
	}
	zephir_create_array(return_value, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SS("type"), SL("qualified"), 1);
	zephir_array_update_string(&return_value, SL("domain"), &source, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("name"), &realColumnName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("balias"), &columnName, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Resolves an expression in a single call argument
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCallArgument) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argument_param = NULL, *_0;
	zval *argument = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &argument_param);

	argument = argument_param;


	zephir_array_fetch_string(&_0, argument, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 391 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(_0, 352)) {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		add_assoc_stringl_ex(return_value, SS("type"), SL("all"), 1);
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getexpression", NULL, 355, argument);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Resolves an expression in a single call argument
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCaseExpression) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *whenClauses = NULL, *whenExpr = NULL, *_0, **_3, *_12 = NULL, *_13, *_5$$4 = NULL, *_6$$4, *_8$$4, *_10$$5 = NULL, *_11$$5;
	zval *expr = NULL, *_4$$4 = NULL, *_9$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	expr = expr_param;


	ZEPHIR_INIT_VAR(whenClauses);
	array_init(whenClauses);
	zephir_array_fetch_string(&_0, expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 405 TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/mvc/model/query.zep", 420);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(whenExpr, _3);
		if (zephir_array_isset_string(whenExpr, SS("right"))) {
			ZEPHIR_INIT_NVAR(_4$$4);
			zephir_create_array(_4$$4, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_4$$4, SS("type"), SL("when"), 1);
			zephir_array_fetch_string(&_6$$4, whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 409 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "_getexpression", &_7, 355, _6$$4);
			zephir_check_call_status();
			zephir_array_update_string(&_4$$4, SL("expr"), &_5$$4, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_8$$4, whenExpr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 410 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "_getexpression", &_7, 355, _8$$4);
			zephir_check_call_status();
			zephir_array_update_string(&_4$$4, SL("then"), &_5$$4, PH_COPY | PH_SEPARATE);
			zephir_array_append(&whenClauses, _4$$4, PH_SEPARATE, "phalcon/mvc/model/query.zep", 411);
		} else {
			ZEPHIR_INIT_NVAR(_9$$5);
			zephir_create_array(_9$$5, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_9$$5, SS("type"), SL("else"), 1);
			zephir_array_fetch_string(&_11$$5, whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 415 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_10$$5, this_ptr, "_getexpression", &_7, 355, _11$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_9$$5, SL("expr"), &_10$$5, PH_COPY | PH_SEPARATE);
			zephir_array_append(&whenClauses, _9$$5, PH_SEPARATE, "phalcon/mvc/model/query.zep", 416);
		}
	}
	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SS("type"), SL("case"), 1);
	zephir_array_fetch_string(&_13, expr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 422 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "_getexpression", &_7, 355, _13);
	zephir_check_call_status();
	zephir_array_update_string(&return_value, SL("expr"), &_12, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("when-clauses"), &whenClauses, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Resolves an expression in a single call argument
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getFunctionCall) {

	HashTable *_1$$6;
	HashPosition _0$$6;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, distinct = 0;
	zval *expr_param = NULL, *arguments = NULL, *argument = NULL, *functionArgs = NULL, *_9, **_2$$6, *_3$$7 = NULL, *_5$$8 = NULL, *_6$$9, *_7$$9, *_8$$10;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	expr = expr_param;


	ZEPHIR_OBS_VAR(arguments);
	if (zephir_array_isset_string_fetch(&arguments, expr, SS("arguments"), 0 TSRMLS_CC)) {
		if (zephir_array_isset_string(expr, SS("distinct"))) {
			distinct = 1;
		} else {
			distinct = 0;
		}
		ZEPHIR_INIT_VAR(functionArgs);
		if (zephir_array_isset_long(arguments, 0)) {
			array_init(functionArgs);
			zephir_is_iterable(arguments, &_1$$6, &_0$$6, 0, 0, "phalcon/mvc/model/query.zep", 448);
			for (
			  ; zend_hash_get_current_data_ex(_1$$6, (void**) &_2$$6, &_0$$6) == SUCCESS
			  ; zend_hash_move_forward_ex(_1$$6, &_0$$6)
			) {
				ZEPHIR_GET_HVALUE(argument, _2$$6);
				ZEPHIR_CALL_METHOD(&_3$$7, this_ptr, "_getcallargument", &_4, 356, argument);
				zephir_check_call_status();
				zephir_array_append(&functionArgs, _3$$7, PH_SEPARATE, "phalcon/mvc/model/query.zep", 446);
			}
		} else {
			zephir_create_array(functionArgs, 1, 0 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_5$$8, this_ptr, "_getcallargument", &_4, 356, arguments);
			zephir_check_call_status();
			zephir_array_fast_append(functionArgs, _5$$8);
		}
		if (distinct) {
			zephir_create_array(return_value, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(return_value, SS("type"), SL("functionCall"), 1);
			ZEPHIR_OBS_VAR(_6$$9);
			zephir_array_fetch_string(&_6$$9, expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 456 TSRMLS_CC);
			zephir_array_update_string(&return_value, SL("name"), &_6$$9, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(_7$$9);
			ZVAL_LONG(_7$$9, distinct);
			zephir_array_update_string(&return_value, SL("distinct"), &_7$$9, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		} else {
			zephir_create_array(return_value, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(return_value, SS("type"), SL("functionCall"), 1);
			ZEPHIR_OBS_VAR(_8$$10);
			zephir_array_fetch_string(&_8$$10, expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 463 TSRMLS_CC);
			zephir_array_update_string(&return_value, SL("name"), &_8$$10, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SS("type"), SL("functionCall"), 1);
	ZEPHIR_OBS_VAR(_9);
	zephir_array_fetch_string(&_9, expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 472 TSRMLS_CC);
	zephir_array_update_string(&return_value, SL("name"), &_9, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Resolves an expression from its intermediate code into a string
 *
 * @param array expr
 * @param boolean quoting
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getExpression) {

	HashTable *_38$$71;
	HashPosition _37$$71;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool quoting, tempNotQuoting = 0;
	zval *expr, *quoting_param = NULL, *exprType = NULL, *exprLeft = NULL, *exprRight = NULL, *left = NULL, *right = NULL, *listItems = NULL, *exprListItem = NULL, *exprReturn = NULL, *value = NULL, *escapedValue = NULL, *exprValue = NULL, *valueParts = NULL, *name = NULL, *bindType = NULL, *bind = NULL, *_0$$5, *_1$$6, *_2$$25, *_3$$33, *_4$$33, _5$$33, _6$$33, *_7$$34, *_8$$34, *_9$$37, *_10$$37, *_11$$38, *_12$$38, *_13$$39, *_14$$39, *_15$$40, *_16$$40, *_17$$41, *_18$$41, *_19$$42, *_20$$42, *_21$$43, *_28$$43, *_22$$44, *_23$$44, *_24$$45, *_25$$45, *_26$$46, *_27$$46, *_29$$47, *_30$$47, *_31$$48, *_32$$65, *_33$$68 = NULL, *_34$$68, *_35$$69, *_36$$69, **_39$$71, *_40$$72 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expr, &quoting_param);

	if (!quoting_param) {
		quoting = 1;
	} else {
		quoting = zephir_get_boolval(quoting_param);
	}


	ZEPHIR_INIT_VAR(left);
	ZVAL_NULL(left);
	ZEPHIR_INIT_VAR(right);
	ZVAL_NULL(right);
	ZEPHIR_OBS_VAR(exprType);
	if (zephir_array_isset_string_fetch(&exprType, expr, SS("type"), 0 TSRMLS_CC)) {
		tempNotQuoting = 1;
		if (!ZEPHIR_IS_LONG(exprType, 409)) {
			ZEPHIR_OBS_VAR(exprLeft);
			if (zephir_array_isset_string_fetch(&exprLeft, expr, SS("left"), 0 TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_0$$5);
				if (tempNotQuoting) {
					ZVAL_BOOL(_0$$5, 1);
				} else {
					ZVAL_BOOL(_0$$5, 0);
				}
				ZEPHIR_CALL_METHOD(&left, this_ptr, "_getexpression", NULL, 355, exprLeft, _0$$5);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_VAR(exprRight);
			if (zephir_array_isset_string_fetch(&exprRight, expr, SS("right"), 0 TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_1$$6);
				if (tempNotQuoting) {
					ZVAL_BOOL(_1$$6, 1);
				} else {
					ZVAL_BOOL(_1$$6, 0);
				}
				ZEPHIR_CALL_METHOD(&right, this_ptr, "_getexpression", NULL, 355, exprRight, _1$$6);
				zephir_check_call_status();
			}
		}
		do {
			if (ZEPHIR_IS_LONG(exprType, '<')) {
				ZEPHIR_INIT_VAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("<"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '=')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("="), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '>')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL(">"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 270)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("<>"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 271)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("<="), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 272)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL(">="), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 266)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("AND"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 267)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("OR"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 355)) {
				ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "_getqualified", NULL, 357, expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '+')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("+"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '-')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("-"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '*')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("*"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '/')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("/"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '%')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("%"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '&')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("&"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '|')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("|"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 356) || ZEPHIR_IS_LONG(exprType, 407)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("parentheses"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 367)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("-"), 1);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 258) || ZEPHIR_IS_LONG(exprType, 259) || ZEPHIR_IS_LONG(exprType, 414)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				ZEPHIR_OBS_VAR(_2$$25);
				zephir_array_fetch_string(&_2$$25, expr, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 590 TSRMLS_CC);
				zephir_array_update_string(&exprReturn, SL("value"), &_2$$25, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 333)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				add_assoc_stringl_ex(exprReturn, SS("value"), SL("TRUE"), 1);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 334)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				add_assoc_stringl_ex(exprReturn, SS("value"), SL("FALSE"), 1);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 260)) {
				ZEPHIR_OBS_VAR(value);
				zephir_array_fetch_string(&value, expr, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 602 TSRMLS_CC);
				if (quoting == 1) {
					if (zephir_memnstr_str(value, SL("'"), "phalcon/mvc/model/query.zep", 607)) {
						ZEPHIR_INIT_VAR(escapedValue);
						phalcon_orm_singlequotes(escapedValue, value TSRMLS_CC);
					} else {
						ZEPHIR_CPY_WRT(escapedValue, value);
					}
					ZEPHIR_INIT_VAR(exprValue);
					ZEPHIR_CONCAT_SVS(exprValue, "'", escapedValue, "'");
				} else {
					ZEPHIR_CPY_WRT(exprValue, value);
				}
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				zephir_array_update_string(&exprReturn, SL("value"), &exprValue, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 273)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
				ZEPHIR_INIT_VAR(_3$$33);
				zephir_array_fetch_string(&_4$$33, expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 620 TSRMLS_CC);
				ZEPHIR_SINIT_VAR(_5$$33);
				ZVAL_STRING(&_5$$33, "?", 0);
				ZEPHIR_SINIT_VAR(_6$$33);
				ZVAL_STRING(&_6$$33, ":", 0);
				zephir_fast_str_replace(&_3$$33, &_5$$33, &_6$$33, _4$$33 TSRMLS_CC);
				zephir_array_update_string(&exprReturn, SL("value"), &_3$$33, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 274)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
				zephir_array_fetch_string(&_7$$34, expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 624 TSRMLS_CC);
				ZEPHIR_INIT_VAR(_8$$34);
				ZEPHIR_CONCAT_SV(_8$$34, ":", _7$$34);
				zephir_array_update_string(&exprReturn, SL("value"), &_8$$34, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 277)) {
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch_string(&value, expr, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 628 TSRMLS_CC);
				if (zephir_memnstr_str(value, SL(":"), "phalcon/mvc/model/query.zep", 629)) {
					ZEPHIR_INIT_VAR(valueParts);
					zephir_fast_explode_str(valueParts, SL(":"), value, LONG_MAX TSRMLS_CC);
					ZEPHIR_OBS_VAR(name);
					zephir_array_fetch_long(&name, valueParts, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 632 TSRMLS_CC);
					ZEPHIR_OBS_VAR(bindType);
					zephir_array_fetch_long(&bindType, valueParts, 1, PH_NOISY, "phalcon/mvc/model/query.zep", 633 TSRMLS_CC);
					do {
						if (ZEPHIR_IS_STRING(bindType, "str")) {
							ZEPHIR_INIT_VAR(_9$$37);
							ZVAL_LONG(_9$$37, 2);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), name, _9$$37 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(exprReturn);
							zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
							ZEPHIR_INIT_VAR(_10$$37);
							ZEPHIR_CONCAT_SV(_10$$37, ":", name);
							zephir_array_update_string(&exprReturn, SL("value"), &_10$$37, PH_COPY | PH_SEPARATE);
							break;
						}
						if (ZEPHIR_IS_STRING(bindType, "int")) {
							ZEPHIR_INIT_VAR(_11$$38);
							ZVAL_LONG(_11$$38, 1);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), name, _11$$38 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(exprReturn);
							zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
							ZEPHIR_INIT_VAR(_12$$38);
							ZEPHIR_CONCAT_SV(_12$$38, ":", name);
							zephir_array_update_string(&exprReturn, SL("value"), &_12$$38, PH_COPY | PH_SEPARATE);
							break;
						}
						if (ZEPHIR_IS_STRING(bindType, "double")) {
							ZEPHIR_INIT_VAR(_13$$39);
							ZVAL_LONG(_13$$39, 32);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), name, _13$$39 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(exprReturn);
							zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
							ZEPHIR_INIT_VAR(_14$$39);
							ZEPHIR_CONCAT_SV(_14$$39, ":", name);
							zephir_array_update_string(&exprReturn, SL("value"), &_14$$39, PH_COPY | PH_SEPARATE);
							break;
						}
						if (ZEPHIR_IS_STRING(bindType, "bool")) {
							ZEPHIR_INIT_VAR(_15$$40);
							ZVAL_LONG(_15$$40, 5);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), name, _15$$40 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(exprReturn);
							zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
							ZEPHIR_INIT_VAR(_16$$40);
							ZEPHIR_CONCAT_SV(_16$$40, ":", name);
							zephir_array_update_string(&exprReturn, SL("value"), &_16$$40, PH_COPY | PH_SEPARATE);
							break;
						}
						if (ZEPHIR_IS_STRING(bindType, "blob")) {
							ZEPHIR_INIT_VAR(_17$$41);
							ZVAL_LONG(_17$$41, 3);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), name, _17$$41 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(exprReturn);
							zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
							ZEPHIR_INIT_VAR(_18$$41);
							ZEPHIR_CONCAT_SV(_18$$41, ":", name);
							zephir_array_update_string(&exprReturn, SL("value"), &_18$$41, PH_COPY | PH_SEPARATE);
							break;
						}
						if (ZEPHIR_IS_STRING(bindType, "null")) {
							ZEPHIR_INIT_VAR(_19$$42);
							ZVAL_LONG(_19$$42, 0);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), name, _19$$42 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(exprReturn);
							zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
							ZEPHIR_INIT_VAR(_20$$42);
							ZEPHIR_CONCAT_SV(_20$$42, ":", name);
							zephir_array_update_string(&exprReturn, SL("value"), &_20$$42, PH_COPY | PH_SEPARATE);
							break;
						}
						if (ZEPHIR_IS_STRING(bindType, "array") || ZEPHIR_IS_STRING(bindType, "array-str") || ZEPHIR_IS_STRING(bindType, "array-int")) {
							ZEPHIR_OBS_VAR(bind);
							_21$$43 = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
							if (!(zephir_array_isset_fetch(&bind, _21$$43, name, 0 TSRMLS_CC))) {
								ZEPHIR_INIT_VAR(_22$$44);
								object_init_ex(_22$$44, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_VAR(_23$$44);
								ZEPHIR_CONCAT_SV(_23$$44, "Bind value is required for array type placeholder: ", name);
								ZEPHIR_CALL_METHOD(NULL, _22$$44, "__construct", NULL, 9, _23$$44);
								zephir_check_call_status();
								zephir_throw_exception_debug(_22$$44, "phalcon/mvc/model/query.zep", 672 TSRMLS_CC);
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (Z_TYPE_P(bind) != IS_ARRAY) {
								ZEPHIR_INIT_VAR(_24$$45);
								object_init_ex(_24$$45, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_VAR(_25$$45);
								ZEPHIR_CONCAT_SV(_25$$45, "Bind type requires an array in placeholder: ", name);
								ZEPHIR_CALL_METHOD(NULL, _24$$45, "__construct", NULL, 9, _25$$45);
								zephir_check_call_status();
								zephir_throw_exception_debug(_24$$45, "phalcon/mvc/model/query.zep", 676 TSRMLS_CC);
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (zephir_fast_count_int(bind TSRMLS_CC) < 1) {
								ZEPHIR_INIT_VAR(_26$$46);
								object_init_ex(_26$$46, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_VAR(_27$$46);
								ZEPHIR_CONCAT_SV(_27$$46, "At least one value must be bound in placeholder: ", name);
								ZEPHIR_CALL_METHOD(NULL, _26$$46, "__construct", NULL, 9, _27$$46);
								zephir_check_call_status();
								zephir_throw_exception_debug(_26$$46, "phalcon/mvc/model/query.zep", 680 TSRMLS_CC);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(exprReturn);
							zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
							add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
							ZEPHIR_INIT_VAR(_28$$43);
							ZEPHIR_CONCAT_SV(_28$$43, ":", name);
							zephir_array_update_string(&exprReturn, SL("value"), &_28$$43, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&exprReturn, SL("rawValue"), &name, PH_COPY | PH_SEPARATE);
							add_assoc_long_ex(exprReturn, SS("times"), zephir_fast_count_int(bind TSRMLS_CC));
							break;
						}
						ZEPHIR_INIT_VAR(_29$$47);
						object_init_ex(_29$$47, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_VAR(_30$$47);
						ZEPHIR_CONCAT_SV(_30$$47, "Unknown bind type: ", bindType);
						ZEPHIR_CALL_METHOD(NULL, _29$$47, "__construct", NULL, 9, _30$$47);
						zephir_check_call_status();
						zephir_throw_exception_debug(_29$$47, "phalcon/mvc/model/query.zep", 692 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					} while(0);

				} else {
					ZEPHIR_INIT_NVAR(exprReturn);
					zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
					add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
					ZEPHIR_INIT_VAR(_31$$48);
					ZEPHIR_CONCAT_SV(_31$$48, ":", value);
					zephir_array_update_string(&exprReturn, SL("value"), &_31$$48, PH_COPY | PH_SEPARATE);
				}
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 322)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				add_assoc_stringl_ex(exprReturn, SS("value"), SL("NULL"), 1);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 268)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("LIKE"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 351)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("NOT LIKE"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 275)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("ILIKE"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 357)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("NOT ILIKE"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '!')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("NOT "), 1);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 365)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL(" IS NULL"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 366)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL(" IS NOT NULL"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 315)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("IN"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 323)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("NOT IN"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 408)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("EXISTS"), 1);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 330)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("DISTINCT "), 1);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 331)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("BETWEEN"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 276)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("AGAINST"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 332)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("cast"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 335)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("convert"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 358)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				ZEPHIR_OBS_VAR(_32$$65);
				zephir_array_fetch_string(&_32$$65, expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 765 TSRMLS_CC);
				zephir_array_update_string(&exprReturn, SL("value"), &_32$$65, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 350)) {
				ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "_getfunctioncall", NULL, 358, expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 409)) {
				ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "_getcaseexpression", NULL, 359, expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 309)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("select"), 1);
				ZEPHIR_INIT_VAR(_34$$68);
				ZVAL_BOOL(_34$$68, 1);
				ZEPHIR_CALL_METHOD(&_33$$68, this_ptr, "_prepareselect", NULL, 360, expr, _34$$68);
				zephir_check_call_status();
				zephir_array_update_string(&exprReturn, SL("value"), &_33$$68, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_VAR(_35$$69);
			object_init_ex(_35$$69, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(_36$$69);
			ZEPHIR_CONCAT_SV(_36$$69, "Unknown expression type ", exprType);
			ZEPHIR_CALL_METHOD(NULL, _35$$69, "__construct", NULL, 9, _36$$69);
			zephir_check_call_status();
			zephir_throw_exception_debug(_35$$69, "phalcon/mvc/model/query.zep", 781 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

		RETURN_CCTOR(exprReturn);
	}
	if (zephir_array_isset_string(expr, SS("domain"))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualified", NULL, 357, expr);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_array_isset_long(expr, 0)) {
		ZEPHIR_INIT_VAR(listItems);
		array_init(listItems);
		zephir_is_iterable(expr, &_38$$71, &_37$$71, 0, 0, "phalcon/mvc/model/query.zep", 802);
		for (
		  ; zend_hash_get_current_data_ex(_38$$71, (void**) &_39$$71, &_37$$71) == SUCCESS
		  ; zend_hash_move_forward_ex(_38$$71, &_37$$71)
		) {
			ZEPHIR_GET_HVALUE(exprListItem, _39$$71);
			ZEPHIR_CALL_METHOD(&_40$$72, this_ptr, "_getexpression", NULL, 355, exprListItem);
			zephir_check_call_status();
			zephir_array_append(&listItems, _40$$72, PH_SEPARATE, "phalcon/mvc/model/query.zep", 800);
		}
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		add_assoc_stringl_ex(return_value, SS("type"), SL("list"), 1);
		zephir_array_fast_append(return_value, listItems);
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Unknown expression", "phalcon/mvc/model/query.zep", 805);
	return;

}

/**
 * Resolves a column from its intermediate representation into an array used to determine
 * if the resultset produced is simple or complex
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSelectColumn) {

	HashTable *_2$$4;
	HashPosition _1$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *column_param = NULL, *sqlColumns = NULL, *columnType = NULL, *sqlAliases = NULL, *modelName = NULL, *source = NULL, *columnDomain = NULL, *sqlColumnAlias = NULL, *preparedAlias = NULL, *sqlExprColumn = NULL, *sqlAliasesModels = NULL, *sqlColumn = NULL, *columnData = NULL, *balias = NULL, *eager = NULL, *_12, *_13, *_0$$4, **_3$$4, *_4$$5 = NULL, *_6$$6, *_7$$9, *_8$$9, *_9$$9, *_10$$13, *_11$$16;
	zval *column = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column_param);

	column = column_param;


	ZEPHIR_OBS_VAR(columnType);
	if (!(zephir_array_isset_string_fetch(&columnType, column, SS("type"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 819);
		return;
	}
	ZEPHIR_INIT_VAR(sqlColumns);
	array_init(sqlColumns);
	ZEPHIR_OBS_VAR(eager);
	zephir_array_isset_string_fetch(&eager, column, SS("eager"), 0 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(columnType, 352)) {
		_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_models"), PH_NOISY_CC);
		zephir_is_iterable(_0$$4, &_2$$4, &_1$$4, 0, 0, "phalcon/mvc/model/query.zep", 849);
		for (
		  ; zend_hash_get_current_data_ex(_2$$4, (void**) &_3$$4, &_1$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_2$$4, &_1$$4)
		) {
			ZEPHIR_GET_HMKEY(modelName, _2$$4, _1$$4);
			ZEPHIR_GET_HVALUE(source, _3$$4);
			ZEPHIR_INIT_NVAR(sqlColumn);
			zephir_create_array(sqlColumn, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(sqlColumn, SS("type"), SL("object"), 1);
			zephir_array_update_string(&sqlColumn, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&sqlColumn, SL("column"), &source, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_4$$5, "lcfirst", &_5, 71, modelName);
			zephir_check_call_status();
			zephir_array_update_string(&sqlColumn, SL("balias"), &_4$$5, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(eager) != IS_NULL) {
				zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_string(&_6$$6, column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 844 TSRMLS_CC);
				zephir_array_update_string(&sqlColumn, SL("eagerType"), &_6$$6, PH_COPY | PH_SEPARATE);
			}
			zephir_array_append(&sqlColumns, sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 847);
		}
		RETURN_CCTOR(sqlColumns);
	}
	if (!(zephir_array_isset_string(column, SS("column")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 853);
		return;
	}
	if (ZEPHIR_IS_LONG(columnType, 353)) {
		ZEPHIR_OBS_VAR(sqlAliases);
		zephir_read_property_this(&sqlAliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(columnDomain);
		zephir_array_fetch_string(&columnDomain, column, SL("column"), PH_NOISY, "phalcon/mvc/model/query.zep", 866 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(source);
		if (!(zephir_array_isset_fetch(&source, sqlAliases, columnDomain, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_7$$9);
			object_init_ex(_7$$9, phalcon_mvc_model_exception_ce);
			_8$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_9$$9);
			ZEPHIR_CONCAT_SVSV(_9$$9, "Unknown model or alias '", columnDomain, "' (2), when preparing: ", _8$$9);
			ZEPHIR_CALL_METHOD(NULL, _7$$9, "__construct", NULL, 9, _9$$9);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$9, "phalcon/mvc/model/query.zep", 869 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(sqlColumnAlias, source);
		ZEPHIR_OBS_VAR(preparedAlias);
		zephir_array_isset_string_fetch(&preparedAlias, column, SS("balias"), 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(sqlAliasesModels);
		zephir_read_property_this(&sqlAliasesModels, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(modelName);
		zephir_array_fetch(&modelName, sqlAliasesModels, columnDomain, PH_NOISY, "phalcon/mvc/model/query.zep", 883 TSRMLS_CC);
		if (Z_TYPE_P(preparedAlias) != IS_STRING) {
			if (ZEPHIR_IS_EQUAL(columnDomain, modelName)) {
				ZEPHIR_CALL_FUNCTION(&preparedAlias, "lcfirst", &_5, 71, modelName);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(preparedAlias, columnDomain);
			}
		}
		ZEPHIR_INIT_NVAR(sqlColumn);
		zephir_create_array(sqlColumn, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(sqlColumn, SS("type"), SL("object"), 1);
		zephir_array_update_string(&sqlColumn, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&sqlColumn, SL("column"), &sqlColumnAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&sqlColumn, SL("balias"), &preparedAlias, PH_COPY | PH_SEPARATE);
		if (Z_TYPE_P(eager) != IS_NULL) {
			zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_10$$13, column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 909 TSRMLS_CC);
			zephir_array_update_string(&sqlColumn, SL("eagerType"), &_10$$13, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&sqlColumns, sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 912);
		RETURN_CCTOR(sqlColumns);
	}
	if (ZEPHIR_IS_LONG(columnType, 354)) {
		ZEPHIR_INIT_NVAR(sqlColumn);
		zephir_create_array(sqlColumn, 1, 0 TSRMLS_CC);
		add_assoc_stringl_ex(sqlColumn, SS("type"), SL("scalar"), 1);
		ZEPHIR_OBS_VAR(columnData);
		zephir_array_fetch_string(&columnData, column, SL("column"), PH_NOISY, "phalcon/mvc/model/query.zep", 926 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&sqlExprColumn, this_ptr, "_getexpression", NULL, 355, columnData);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(balias);
		if (zephir_array_isset_string_fetch(&balias, sqlExprColumn, SS("balias"), 0 TSRMLS_CC)) {
			zephir_array_update_string(&sqlColumn, SL("balias"), &balias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &balias, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(eager) != IS_NULL) {
			zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_11$$16, column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 939 TSRMLS_CC);
			zephir_array_update_string(&sqlColumn, SL("eagerType"), &_11$$16, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&sqlColumn, SL("column"), &sqlExprColumn, PH_COPY | PH_SEPARATE);
		zephir_array_append(&sqlColumns, sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 943);
		RETURN_CCTOR(sqlColumns);
	}
	ZEPHIR_INIT_VAR(_12);
	object_init_ex(_12, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_CONCAT_SV(_13, "Unknown type of column ", columnType);
	ZEPHIR_CALL_METHOD(NULL, _12, "__construct", NULL, 9, _13);
	zephir_check_call_status();
	zephir_throw_exception_debug(_12, "phalcon/mvc/model/query.zep", 948 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Resolves a table in a SELECT statement checking if the model exists
 *
 * @param \Phalcon\Mvc\Model\ManagerInterface manager
 * @param array qualifiedName
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getTable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *manager, *qualifiedName, *modelName = NULL, *model = NULL, *source = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &manager, &qualifiedName);



	ZEPHIR_OBS_VAR(modelName);
	if (!(zephir_array_isset_string_fetch(&modelName, qualifiedName, SS("name"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 963);
		return;
	}
	ZEPHIR_CALL_METHOD(&model, manager, "load", NULL, 0, modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(schema)) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(return_value, schema);
		zephir_array_fast_append(return_value, source);
		RETURN_MM();
	}
	RETURN_CCTOR(source);

}

/**
 * Resolves a JOIN clause checking if the associated models exist
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoin) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *manager, *join, *qualified = NULL, *modelName = NULL, *realModelName = NULL, *nsAlias = NULL, *source = NULL, *model = NULL, *schema = NULL, *_0$$3, *_1$$5 = NULL, *_2$$5, *_3$$5, *_4$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &manager, &join);



	ZEPHIR_OBS_VAR(qualified);
	if (zephir_array_isset_string_fetch(&qualified, join, SS("qualified"), 0 TSRMLS_CC)) {
		zephir_array_fetch_string(&_0$$3, qualified, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 987 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(_0$$3, 355)) {
			ZEPHIR_OBS_VAR(modelName);
			zephir_array_fetch_string(&modelName, qualified, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 989 TSRMLS_CC);
			if (zephir_memnstr_str(modelName, SL(":"), "phalcon/mvc/model/query.zep", 991)) {
				ZEPHIR_INIT_VAR(nsAlias);
				zephir_fast_explode_str(nsAlias, SL(":"), modelName, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_2$$5, nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 993 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_1$$5, manager, "getnamespacealias", NULL, 0, _2$$5);
				zephir_check_call_status();
				zephir_array_fetch_long(&_3$$5, nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 993 TSRMLS_CC);
				ZEPHIR_INIT_VAR(realModelName);
				ZEPHIR_CONCAT_VSV(realModelName, _1$$5, "\\", _3$$5);
			} else {
				ZEPHIR_CPY_WRT(realModelName, modelName);
			}
			ZEPHIR_INIT_VAR(_4$$4);
			ZVAL_BOOL(_4$$4, 1);
			ZEPHIR_CALL_METHOD(&model, manager, "load", NULL, 0, realModelName, _4$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
			zephir_check_call_status();
			zephir_create_array(return_value, 4, 0 TSRMLS_CC);
			zephir_array_update_string(&return_value, SL("schema"), &schema, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&return_value, SL("source"), &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&return_value, SL("modelName"), &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&return_value, SL("model"), &model, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 1011);
	return;

}

/**
 * Resolves a JOIN type
 *
 * @param array join
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoinType) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *join, *type = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &join);



	ZEPHIR_OBS_VAR(type);
	if (!(zephir_array_isset_string_fetch(&type, join, SS("type"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 1025);
		return;
	}
	do {
		if (ZEPHIR_IS_LONG(type, 360)) {
			RETURN_MM_STRING("INNER", 1);
		}
		if (ZEPHIR_IS_LONG(type, 361)) {
			RETURN_MM_STRING("LEFT", 1);
		}
		if (ZEPHIR_IS_LONG(type, 362)) {
			RETURN_MM_STRING("RIGHT", 1);
		}
		if (ZEPHIR_IS_LONG(type, 363)) {
			RETURN_MM_STRING("CROSS", 1);
		}
		if (ZEPHIR_IS_LONG(type, 364)) {
			RETURN_MM_STRING("FULL OUTER", 1);
		}
	} while(0);

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_mvc_model_exception_ce);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVSV(_2, "Unknown join type ", type, ", when preparing: ", _1);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 9, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_0, "phalcon/mvc/model/query.zep", 1046 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Resolves joins involving has-one/belongs-to/has-many relations
 *
 * @param string joinType
 * @param string joinSource
 * @param string modelAlias
 * @param string joinAlias
 * @param \Phalcon\Mvc\Model\RelationInterface relation
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSingleJoin) {

	HashTable *_5$$4;
	HashPosition _4$$4;
	zval *_0$$3, *_2$$3, *_3$$3, *_11$$5 = NULL, *_13$$5 = NULL, *_14$$5 = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *joinType_param = NULL, *joinSource, *modelAlias, *joinAlias, *relation, *fields = NULL, *referencedFields = NULL, *sqlJoinConditions = NULL, *sqlJoinPartialConditions = NULL, *position = NULL, *field = NULL, *referencedField = NULL, *_1$$3 = NULL, **_6$$4, *_7$$6 = NULL, *_8$$6, *_9$$6 = NULL, *_12$$5 = NULL;
	zval *joinType = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &joinType_param, &joinSource, &modelAlias, &joinAlias, &relation);

	if (UNEXPECTED(Z_TYPE_P(joinType_param) != IS_STRING && Z_TYPE_P(joinType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinType' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinType_param) == IS_STRING)) {
		zephir_get_strval(joinType, joinType_param);
	} else {
		ZEPHIR_INIT_VAR(joinType);
		ZVAL_EMPTY_STRING(joinType);
	}


	ZEPHIR_INIT_VAR(sqlJoinConditions);
	ZVAL_NULL(sqlJoinConditions);
	ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fields) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(sqlJoinConditions);
		zephir_create_array(sqlJoinConditions, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_create_array(_0$$3, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_0$$3, SS("type"), SL("binary-op"), 1);
		add_assoc_stringl_ex(_0$$3, SS("op"), SL("="), 1);
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_create_array(_2$$3, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(_2$$3, SS("type"), 355);
		zephir_array_update_string(&_2$$3, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_2$$3, SL("name"), &fields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "_getqualified", NULL, 357, _2$$3);
		zephir_check_call_status();
		zephir_array_update_string(&_0$$3, SL("left"), &_1$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_create_array(_3$$3, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_3$$3, SS("type"), SL("qualified"), 1);
		zephir_array_update_string(&_3$$3, SL("domain"), &joinAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3$$3, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "_getqualified", NULL, 357, _3$$3);
		zephir_check_call_status();
		zephir_array_update_string(&_0$$3, SL("right"), &_1$$3, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(sqlJoinConditions, _0$$3);
	} else {
		ZEPHIR_INIT_VAR(sqlJoinPartialConditions);
		array_init(sqlJoinPartialConditions);
		zephir_is_iterable(fields, &_5$$4, &_4$$4, 0, 0, "phalcon/mvc/model/query.zep", 1136);
		for (
		  ; zend_hash_get_current_data_ex(_5$$4, (void**) &_6$$4, &_4$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_5$$4, &_4$$4)
		) {
			ZEPHIR_GET_HMKEY(position, _5$$4, _4$$4);
			ZEPHIR_GET_HVALUE(field, _6$$4);
			ZEPHIR_OBS_NVAR(referencedField);
			if (!(zephir_array_isset_fetch(&referencedField, referencedFields, position, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_7$$6);
				object_init_ex(_7$$6, phalcon_mvc_model_exception_ce);
				_8$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_9$$6);
				ZEPHIR_CONCAT_SVSVSV(_9$$6, "The number of fields must be equal to the number of referenced fields in join ", modelAlias, "-", joinAlias, ", when preparing: ", _8$$6);
				ZEPHIR_CALL_METHOD(NULL, _7$$6, "__construct", &_10, 9, _9$$6);
				zephir_check_call_status();
				zephir_throw_exception_debug(_7$$6, "phalcon/mvc/model/query.zep", 1112 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(_11$$5);
			zephir_create_array(_11$$5, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_11$$5, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(_11$$5, SS("op"), SL("="), 1);
			ZEPHIR_INIT_NVAR(_13$$5);
			zephir_create_array(_13$$5, 3, 0 TSRMLS_CC);
			add_assoc_long_ex(_13$$5, SS("type"), 355);
			zephir_array_update_string(&_13$$5, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13$$5, SL("name"), &field, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "_getqualified", NULL, 357, _13$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_11$$5, SL("left"), &_12$$5, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_14$$5);
			zephir_create_array(_14$$5, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_14$$5, SS("type"), SL("qualified"), 1);
			zephir_array_update_string(&_14$$5, SL("domain"), &joinAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$5, SL("name"), &referencedField, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "_getqualified", NULL, 357, _14$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_11$$5, SL("right"), &_12$$5, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlJoinPartialConditions, _11$$5, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1133);
		}
	}
	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&return_value, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("conditions"), &sqlJoinConditions, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Resolves joins involving many-to-many relations
 *
 * @param string joinType
 * @param string joinSource
 * @param string modelAlias
 * @param string joinAlias
 * @param \Phalcon\Mvc\Model\RelationInterface relation
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getMultiJoin) {

	zval *_8$$4 = NULL, *_10$$4 = NULL, *_11$$6 = NULL, *_12$$6 = NULL, *_13$$6 = NULL, *_15$$6, *_16$$6, *_17$$6, *_18$$6;
	HashTable *_1$$3;
	HashPosition _0$$3;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *joinType, *joinSource, *modelAlias, *joinAlias, *relation, *sqlJoins = NULL, *fields = NULL, *referencedFields = NULL, *intermediateModelName = NULL, *intermediateModel = NULL, *intermediateSource = NULL, *intermediateSchema = NULL, *intermediateFields = NULL, *intermediateReferencedFields = NULL, *referencedModelName = NULL, *manager = NULL, *field = NULL, *position = NULL, *intermediateField = NULL, *sqlEqualsJoinCondition = NULL, **_2$$3, *_3$$5 = NULL, *_4$$5, *_5$$5 = NULL, *_7$$4 = NULL, *_14$$6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);



	ZEPHIR_INIT_VAR(sqlJoins);
	array_init(sqlJoins);
	ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateModelName, relation, "getintermediatemodel", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&intermediateModel, manager, "load", NULL, 0, intermediateModelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateSource, intermediateModel, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateSchema, intermediateModel, "getschema", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_sqlAliases"), intermediateModelName, intermediateSource TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_sqlAliasesModelsInstances"), intermediateModelName, intermediateModel TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&intermediateFields, relation, "getintermediatefields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateReferencedFields, relation, "getintermediatereferencedfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedModelName, relation, "getreferencedmodel", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fields) == IS_ARRAY) {
		zephir_is_iterable(fields, &_1$$3, &_0$$3, 0, 0, "phalcon/mvc/model/query.zep", 1263);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HMKEY(field, _1$$3, _0$$3);
			ZEPHIR_GET_HVALUE(position, _2$$3);
			if (!(zephir_array_isset(referencedFields, position))) {
				ZEPHIR_INIT_NVAR(_3$$5);
				object_init_ex(_3$$5, phalcon_mvc_model_exception_ce);
				_4$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_5$$5);
				ZEPHIR_CONCAT_SVSVSV(_5$$5, "The number of fields must be equal to the number of referenced fields in join ", modelAlias, "-", joinAlias, ", when preparing: ", _4$$5);
				ZEPHIR_CALL_METHOD(NULL, _3$$5, "__construct", &_6, 9, _5$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3$$5, "phalcon/mvc/model/query.zep", 1234 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(intermediateField);
			zephir_array_fetch(&intermediateField, intermediateFields, position, PH_NOISY, "phalcon/mvc/model/query.zep", 1240 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(sqlEqualsJoinCondition);
			zephir_create_array(sqlEqualsJoinCondition, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(sqlEqualsJoinCondition, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(sqlEqualsJoinCondition, SS("op"), SL("="), 1);
			ZEPHIR_INIT_NVAR(_8$$4);
			zephir_create_array(_8$$4, 3, 0 TSRMLS_CC);
			add_assoc_long_ex(_8$$4, SS("type"), 355);
			zephir_array_update_string(&_8$$4, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_8$$4, SL("name"), &field, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "_getqualified", &_9, 357, _8$$4);
			zephir_check_call_status();
			zephir_array_update_string(&sqlEqualsJoinCondition, SL("left"), &_7$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_10$$4);
			zephir_create_array(_10$$4, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_10$$4, SS("type"), SL("qualified"), 1);
			zephir_array_update_string(&_10$$4, SL("domain"), &joinAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_10$$4, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "_getqualified", &_9, 357, _10$$4);
			zephir_check_call_status();
			zephir_array_update_string(&sqlEqualsJoinCondition, SL("right"), &_7$$4, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_INIT_NVAR(sqlJoins);
		zephir_create_array(sqlJoins, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_11$$6);
		zephir_create_array(_11$$6, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&_11$$6, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_11$$6, SL("source"), &intermediateSource, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_12$$6);
		zephir_create_array(_12$$6, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_13$$6);
		zephir_create_array(_13$$6, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_13$$6, SS("type"), SL("binary-op"), 1);
		add_assoc_stringl_ex(_13$$6, SS("op"), SL("="), 1);
		ZEPHIR_INIT_VAR(_15$$6);
		zephir_create_array(_15$$6, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(_15$$6, SS("type"), 355);
		zephir_array_update_string(&_15$$6, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_15$$6, SL("name"), &fields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_14$$6, this_ptr, "_getqualified", &_9, 357, _15$$6);
		zephir_check_call_status();
		zephir_array_update_string(&_13$$6, SL("left"), &_14$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_16$$6);
		zephir_create_array(_16$$6, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_16$$6, SS("type"), SL("qualified"), 1);
		zephir_array_update_string(&_16$$6, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_16$$6, SL("name"), &intermediateFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_14$$6, this_ptr, "_getqualified", &_9, 357, _16$$6);
		zephir_check_call_status();
		zephir_array_update_string(&_13$$6, SL("right"), &_14$$6, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(_12$$6, _13$$6);
		zephir_array_update_string(&_11$$6, SL("conditions"), &_12$$6, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(sqlJoins, _11$$6);
		ZEPHIR_INIT_NVAR(_11$$6);
		zephir_create_array(_11$$6, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&_11$$6, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_11$$6, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_12$$6);
		zephir_create_array(_12$$6, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_13$$6);
		zephir_create_array(_13$$6, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_13$$6, SS("type"), SL("binary-op"), 1);
		add_assoc_stringl_ex(_13$$6, SS("op"), SL("="), 1);
		ZEPHIR_INIT_VAR(_17$$6);
		zephir_create_array(_17$$6, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(_17$$6, SS("type"), 355);
		zephir_array_update_string(&_17$$6, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_17$$6, SL("name"), &intermediateReferencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_14$$6, this_ptr, "_getqualified", &_9, 357, _17$$6);
		zephir_check_call_status();
		zephir_array_update_string(&_13$$6, SL("left"), &_14$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_18$$6);
		zephir_create_array(_18$$6, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_18$$6, SS("type"), SL("qualified"), 1);
		zephir_array_update_string(&_18$$6, SL("domain"), &referencedModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_18$$6, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_14$$6, this_ptr, "_getqualified", &_9, 357, _18$$6);
		zephir_check_call_status();
		zephir_array_update_string(&_13$$6, SL("right"), &_14$$6, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(_12$$6, _13$$6);
		zephir_array_update_string(&_11$$6, SL("conditions"), &_12$$6, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(sqlJoins, _11$$6);
	}
	RETURN_CCTOR(sqlJoins);

}

/**
 * Processes the JOINs in the query returning an internal representation for the database dialect
 *
 * @param array select
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoins) {

	zval *_22$$15 = NULL, *_23$$15 = NULL, *_47$$29 = NULL, *_49$$30 = NULL, *_50$$30 = NULL;
	HashTable *_1, *_13, *_25, *_31, *_20$$14, *_34$$17, *_45$$26;
	HashPosition _0, _12, _24, _30, _19$$14, _33$$17, _44$$26;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL, *_8 = NULL, *_16 = NULL, *_36 = NULL, *_37 = NULL, *_42 = NULL, *_43 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *select, *models = NULL, *sqlAliases = NULL, *sqlAliasesModels = NULL, *sqlModelsAliases = NULL, *sqlAliasesModelsInstances = NULL, *modelsInstances = NULL, *fromModels = NULL, *sqlJoins = NULL, *joinModels = NULL, *joinSources = NULL, *joinTypes = NULL, *joinPreCondition = NULL, *joinPrepared = NULL, *manager = NULL, *selectJoins = NULL, *joinItem = NULL, *joins = NULL, *joinData = NULL, *schema = NULL, *source = NULL, *model = NULL, *realModelName = NULL, *completeSource = NULL, *joinType = NULL, *aliasExpr = NULL, *alias = NULL, *joinAliasName = NULL, *joinExpr = NULL, *fromModelName = NULL, *joinAlias = NULL, *joinModel = NULL, *joinSource = NULL, *preCondition = NULL, *modelNameAlias = NULL, *relation = NULL, *relations = NULL, *modelAlias = NULL, *sqlJoin = NULL, *sqlJoinItem = NULL, *selectTables = NULL, *tables = NULL, *tableItem = NULL, **_2, **_14, *_17, **_26, *_29 = NULL, **_32, *_5$$9 = NULL, *_6$$9, *_7$$9 = NULL, *_9$$11 = NULL, *_10$$11, *_11$$11 = NULL, *_15$$13 = NULL, *_18$$14 = NULL, **_21$$14, *_27$$16, *_28$$16 = NULL, **_35$$17, *_38$$22 = NULL, *_39$$22, *_40$$22 = NULL, *_41$$23 = NULL, **_46$$26, *_48$$29 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &select);



	ZEPHIR_OBS_VAR(models);
	zephir_read_property_this(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(sqlAliases);
	zephir_read_property_this(&sqlAliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(sqlAliasesModels);
	zephir_read_property_this(&sqlAliasesModels, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(sqlModelsAliases);
	zephir_read_property_this(&sqlModelsAliases, this_ptr, SL("_sqlModelsAliases"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(sqlAliasesModelsInstances);
	zephir_read_property_this(&sqlAliasesModelsInstances, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(modelsInstances);
	zephir_read_property_this(&modelsInstances, this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(fromModels, models);
	ZEPHIR_INIT_VAR(sqlJoins);
	array_init(sqlJoins);
	ZEPHIR_INIT_VAR(joinModels);
	array_init(joinModels);
	ZEPHIR_INIT_VAR(joinSources);
	array_init(joinSources);
	ZEPHIR_INIT_VAR(joinTypes);
	array_init(joinTypes);
	ZEPHIR_INIT_VAR(joinPreCondition);
	array_init(joinPreCondition);
	ZEPHIR_INIT_VAR(joinPrepared);
	array_init(joinPrepared);
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(tables);
	zephir_array_fetch_string(&tables, select, SL("tables"), PH_NOISY, "phalcon/mvc/model/query.zep", 1354 TSRMLS_CC);
	if (!(zephir_array_isset_long(tables, 0))) {
		ZEPHIR_INIT_VAR(selectTables);
		zephir_create_array(selectTables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(selectTables, tables);
	} else {
		ZEPHIR_CPY_WRT(selectTables, tables);
	}
	ZEPHIR_OBS_VAR(joins);
	zephir_array_fetch_string(&joins, select, SL("joins"), PH_NOISY, "phalcon/mvc/model/query.zep", 1361 TSRMLS_CC);
	if (!(zephir_array_isset_long(joins, 0))) {
		ZEPHIR_INIT_VAR(selectJoins);
		zephir_create_array(selectJoins, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(selectJoins, joins);
	} else {
		ZEPHIR_CPY_WRT(selectJoins, joins);
	}
	zephir_is_iterable(selectJoins, &_1, &_0, 0, 0, "phalcon/mvc/model/query.zep", 1514);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(joinItem, _2);
		ZEPHIR_CALL_METHOD(&joinData, this_ptr, "_getjoin", &_3, 361, manager, joinItem);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(source);
		zephir_array_fetch_string(&source, joinData, SL("source"), PH_NOISY, "phalcon/mvc/model/query.zep", 1374 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(schema);
		zephir_array_fetch_string(&schema, joinData, SL("schema"), PH_NOISY, "phalcon/mvc/model/query.zep", 1375 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(model);
		zephir_array_fetch_string(&model, joinData, SL("model"), PH_NOISY, "phalcon/mvc/model/query.zep", 1376 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(realModelName);
		zephir_array_fetch_string(&realModelName, joinData, SL("modelName"), PH_NOISY, "phalcon/mvc/model/query.zep", 1377 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(completeSource);
		zephir_create_array(completeSource, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(completeSource, source);
		zephir_array_fast_append(completeSource, schema);
		ZEPHIR_CALL_METHOD(&joinType, this_ptr, "_getjointype", &_4, 362, joinItem);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(aliasExpr);
		if (zephir_array_isset_string_fetch(&aliasExpr, joinItem, SS("alias"), 0 TSRMLS_CC)) {
			ZEPHIR_OBS_NVAR(alias);
			zephir_array_fetch_string(&alias, aliasExpr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1390 TSRMLS_CC);
			if (zephir_array_isset(joinModels, alias)) {
				ZEPHIR_INIT_NVAR(_5$$9);
				object_init_ex(_5$$9, phalcon_mvc_model_exception_ce);
				_6$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_7$$9);
				ZEPHIR_CONCAT_SVSV(_7$$9, "Cannot use '", alias, "' as join alias because it was already used, when preparing: ", _6$$9);
				ZEPHIR_CALL_METHOD(NULL, _5$$9, "__construct", &_8, 9, _7$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(_5$$9, "phalcon/mvc/model/query.zep", 1398 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&completeSource, alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1404);
			zephir_array_update_zval(&joinTypes, alias, &joinType, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliases, alias, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinModels, alias, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, realModelName, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModels, alias, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, alias, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, realModelName, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinSources, alias, &completeSource, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinPrepared, alias, &joinItem, PH_COPY | PH_SEPARATE);
		} else {
			if (zephir_array_isset(joinModels, realModelName)) {
				ZEPHIR_INIT_NVAR(_9$$11);
				object_init_ex(_9$$11, phalcon_mvc_model_exception_ce);
				_10$$11 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_11$$11);
				ZEPHIR_CONCAT_SVSV(_11$$11, "Cannot use '", realModelName, "' as join alias because it was already used, when preparing: ", _10$$11);
				ZEPHIR_CALL_METHOD(NULL, _9$$11, "__construct", &_8, 9, _11$$11);
				zephir_check_call_status();
				zephir_throw_exception_debug(_9$$11, "phalcon/mvc/model/query.zep", 1459 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&joinTypes, realModelName, &joinType, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliases, realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinModels, realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, realModelName, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModels, realModelName, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinSources, realModelName, &completeSource, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinPrepared, realModelName, &joinItem, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_zval(&modelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_this(getThis(), SL("_models"), models TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_sqlAliases"), sqlAliases TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_sqlAliasesModels"), sqlAliasesModels TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_sqlModelsAliases"), sqlModelsAliases TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_sqlAliasesModelsInstances"), sqlAliasesModelsInstances TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_modelsInstances"), modelsInstances TSRMLS_CC);
	zephir_is_iterable(joinPrepared, &_13, &_12, 0, 0, "phalcon/mvc/model/query.zep", 1534);
	for (
	  ; zend_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
	  ; zend_hash_move_forward_ex(_13, &_12)
	) {
		ZEPHIR_GET_HMKEY(joinAliasName, _13, _12);
		ZEPHIR_GET_HVALUE(joinItem, _14);
		ZEPHIR_OBS_NVAR(joinExpr);
		if (zephir_array_isset_string_fetch(&joinExpr, joinItem, SS("conditions"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_15$$13, this_ptr, "_getexpression", &_16, 355, joinExpr);
			zephir_check_call_status();
			zephir_array_update_zval(&joinPreCondition, joinAliasName, &_15$$13, PH_COPY | PH_SEPARATE);
		}
	}
	_17 = zephir_fetch_nproperty_this(this_ptr, SL("_enableImplicitJoins"), PH_NOISY_CC);
	if (!(zephir_is_true(_17))) {
		ZEPHIR_INIT_VAR(_18$$14);
		zephir_is_iterable(joinPrepared, &_20$$14, &_19$$14, 0, 0, "phalcon/mvc/model/query.zep", 1545);
		for (
		  ; zend_hash_get_current_data_ex(_20$$14, (void**) &_21$$14, &_19$$14) == SUCCESS
		  ; zend_hash_move_forward_ex(_20$$14, &_19$$14)
		) {
			ZEPHIR_GET_HMKEY(joinAliasName, _20$$14, _19$$14);
			ZEPHIR_GET_HVALUE(_18$$14, _21$$14);
			ZEPHIR_OBS_NVAR(joinType);
			zephir_array_fetch(&joinType, joinTypes, joinAliasName, PH_NOISY, "phalcon/mvc/model/query.zep", 1536 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(joinSource);
			zephir_array_fetch(&joinSource, joinSources, joinAliasName, PH_NOISY, "phalcon/mvc/model/query.zep", 1537 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(preCondition);
			zephir_array_fetch(&preCondition, joinPreCondition, joinAliasName, PH_NOISY, "phalcon/mvc/model/query.zep", 1538 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_22$$15);
			zephir_create_array(_22$$15, 3, 0 TSRMLS_CC);
			zephir_array_update_string(&_22$$15, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_22$$15, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_23$$15);
			zephir_create_array(_23$$15, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_23$$15, preCondition);
			zephir_array_update_string(&_22$$15, SL("conditions"), &_23$$15, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlJoins, _22$$15, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1543);
		}
		RETURN_CCTOR(sqlJoins);
	}
	ZEPHIR_INIT_NVAR(fromModels);
	array_init(fromModels);
	zephir_is_iterable(selectTables, &_25, &_24, 0, 0, "phalcon/mvc/model/query.zep", 1559);
	for (
	  ; zend_hash_get_current_data_ex(_25, (void**) &_26, &_24) == SUCCESS
	  ; zend_hash_move_forward_ex(_25, &_24)
	) {
		ZEPHIR_GET_HVALUE(tableItem, _26);
		zephir_array_fetch_string(&_27$$16, tableItem, SL("qualifiedName"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1553 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_28$$16);
		zephir_array_fetch_string(&_28$$16, _27$$16, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1553 TSRMLS_CC);
		zephir_array_update_zval(&fromModels, _28$$16, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_29);
	zephir_is_iterable(fromModels, &_31, &_30, 0, 0, "phalcon/mvc/model/query.zep", 1667);
	for (
	  ; zend_hash_get_current_data_ex(_31, (void**) &_32, &_30) == SUCCESS
	  ; zend_hash_move_forward_ex(_31, &_30)
	) {
		ZEPHIR_GET_HMKEY(fromModelName, _31, _30);
		ZEPHIR_GET_HVALUE(_29, _32);
		zephir_is_iterable(joinModels, &_34$$17, &_33$$17, 0, 0, "phalcon/mvc/model/query.zep", 1665);
		for (
		  ; zend_hash_get_current_data_ex(_34$$17, (void**) &_35$$17, &_33$$17) == SUCCESS
		  ; zend_hash_move_forward_ex(_34$$17, &_33$$17)
		) {
			ZEPHIR_GET_HMKEY(joinAlias, _34$$17, _33$$17);
			ZEPHIR_GET_HVALUE(joinModel, _35$$17);
			ZEPHIR_OBS_NVAR(joinSource);
			zephir_array_fetch(&joinSource, joinSources, joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1566 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(joinType);
			zephir_array_fetch(&joinType, joinTypes, joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1571 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(preCondition);
			if (!(zephir_array_isset_fetch(&preCondition, joinPreCondition, joinAlias, 0 TSRMLS_CC))) {
				ZEPHIR_OBS_NVAR(modelNameAlias);
				zephir_array_fetch(&modelNameAlias, sqlAliasesModels, joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1581 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&relation, manager, "getrelationbyalias", &_36, 0, fromModelName, modelNameAlias);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(relation)) {
					ZEPHIR_CALL_METHOD(&relations, manager, "getrelationsbetween", &_37, 0, fromModelName, modelNameAlias);
					zephir_check_call_status();
					if (Z_TYPE_P(relations) == IS_ARRAY) {
						if (zephir_fast_count_int(relations TSRMLS_CC) != 1) {
							ZEPHIR_INIT_NVAR(_38$$22);
							object_init_ex(_38$$22, phalcon_mvc_model_exception_ce);
							_39$$22 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
							ZEPHIR_INIT_LNVAR(_40$$22);
							ZEPHIR_CONCAT_SVSVSV(_40$$22, "There is more than one relation between models '", fromModelName, "' and '", joinModel, "', the join must be done using an alias, when preparing: ", _39$$22);
							ZEPHIR_CALL_METHOD(NULL, _38$$22, "__construct", &_8, 9, _40$$22);
							zephir_check_call_status();
							zephir_throw_exception_debug(_38$$22, "phalcon/mvc/model/query.zep", 1601 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(relation);
						zephir_array_fetch_long(&relation, relations, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 1607 TSRMLS_CC);
					}
				}
				if (Z_TYPE_P(relation) == IS_OBJECT) {
					ZEPHIR_OBS_NVAR(modelAlias);
					zephir_array_fetch(&modelAlias, sqlModelsAliases, fromModelName, PH_NOISY, "phalcon/mvc/model/query.zep", 1619 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_41$$23, relation, "isthrough", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(_41$$23))) {
						ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "_getsinglejoin", &_42, 363, joinType, joinSource, modelAlias, joinAlias, relation);
						zephir_check_call_status();
					} else {
						ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "_getmultijoin", &_43, 364, joinType, joinSource, modelAlias, joinAlias, relation);
						zephir_check_call_status();
					}
					if (zephir_array_isset_long(sqlJoin, 0)) {
						zephir_is_iterable(sqlJoin, &_45$$26, &_44$$26, 0, 0, "phalcon/mvc/model/query.zep", 1637);
						for (
						  ; zend_hash_get_current_data_ex(_45$$26, (void**) &_46$$26, &_44$$26) == SUCCESS
						  ; zend_hash_move_forward_ex(_45$$26, &_44$$26)
						) {
							ZEPHIR_GET_HVALUE(sqlJoinItem, _46$$26);
							zephir_array_append(&sqlJoins, sqlJoinItem, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1635);
						}
					} else {
						zephir_array_append(&sqlJoins, sqlJoin, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1638);
					}
				} else {
					ZEPHIR_INIT_NVAR(_47$$29);
					zephir_create_array(_47$$29, 3, 0 TSRMLS_CC);
					zephir_array_update_string(&_47$$29, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_47$$29, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(_48$$29);
					array_init(_48$$29);
					zephir_array_update_string(&_47$$29, SL("conditions"), &_48$$29, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlJoins, _47$$29, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1650);
				}
			} else {
				ZEPHIR_INIT_NVAR(_49$$30);
				zephir_create_array(_49$$30, 3, 0 TSRMLS_CC);
				zephir_array_update_string(&_49$$30, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_49$$30, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_50$$30);
				zephir_create_array(_50$$30, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(_50$$30, preCondition);
				zephir_array_update_string(&_49$$30, SL("conditions"), &_50$$30, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlJoins, _49$$30, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1662);
			}
		}
	}
	RETURN_CCTOR(sqlJoins);

}

/**
 * Returns a processed order clause for a SELECT statement
 *
 * @param array|string $order
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getOrderClause) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *order, *orderColumns = NULL, *orderParts = NULL, *orderItem = NULL, *orderPartExpr = NULL, *orderSort = NULL, *orderPartSort = NULL, **_2, *_3$$5, *_5$$7 = NULL, *_6$$8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &order);



	if (!(zephir_array_isset_long(order, 0))) {
		ZEPHIR_INIT_VAR(orderColumns);
		zephir_create_array(orderColumns, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(orderColumns, order);
	} else {
		ZEPHIR_CPY_WRT(orderColumns, order);
	}
	ZEPHIR_INIT_VAR(orderParts);
	array_init(orderParts);
	zephir_is_iterable(orderColumns, &_1, &_0, 0, 0, "phalcon/mvc/model/query.zep", 1708);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(orderItem, _2);
		zephir_array_fetch_string(&_3$$5, orderItem, SL("column"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1690 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&orderPartExpr, this_ptr, "_getexpression", &_4, 355, _3$$5);
		zephir_check_call_status();
		if (zephir_array_isset_string_fetch(&orderSort, orderItem, SS("sort"), 1 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(orderPartSort);
			if (ZEPHIR_IS_LONG(orderSort, 327)) {
				zephir_create_array(orderPartSort, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(orderPartSort, orderPartExpr);
				ZEPHIR_INIT_NVAR(_5$$7);
				ZVAL_STRING(_5$$7, "ASC", 1);
				zephir_array_fast_append(orderPartSort, _5$$7);
			} else {
				zephir_create_array(orderPartSort, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(orderPartSort, orderPartExpr);
				ZEPHIR_INIT_NVAR(_6$$8);
				ZVAL_STRING(_6$$8, "DESC", 1);
				zephir_array_fast_append(orderPartSort, _6$$8);
			}
		} else {
			ZEPHIR_INIT_NVAR(orderPartSort);
			zephir_create_array(orderPartSort, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(orderPartSort, orderPartExpr);
		}
		zephir_array_append(&orderParts, orderPartSort, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1705);
	}
	RETURN_CCTOR(orderParts);

}

/**
 * Returns a processed group clause for a SELECT statement
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getGroupClause) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group_param = NULL, *groupItem = NULL, *groupParts = NULL, **_2$$3, *_3$$4 = NULL, *_5$$5 = NULL;
	zval *group = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group_param);

	group = group_param;


	ZEPHIR_INIT_VAR(groupParts);
	if (zephir_array_isset_long(group, 0)) {
		array_init(groupParts);
		zephir_is_iterable(group, &_1$$3, &_0$$3, 0, 0, "phalcon/mvc/model/query.zep", 1726);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(groupItem, _2$$3);
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "_getexpression", &_4, 355, groupItem);
			zephir_check_call_status();
			zephir_array_append(&groupParts, _3$$4, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1724);
		}
	} else {
		zephir_create_array(groupParts, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_5$$5, this_ptr, "_getexpression", &_4, 355, group);
		zephir_check_call_status();
		zephir_array_fast_append(groupParts, _5$$5);
	}
	RETURN_CCTOR(groupParts);

}

/**
 * Returns a processed limit clause for a SELECT statement
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getLimitClause) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *limitClause_param = NULL, *number = NULL, *offset = NULL, *_0$$3 = NULL, *_1$$4 = NULL;
	zval *limitClause = NULL, *limit;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &limitClause_param);

	limitClause = limitClause_param;


	ZEPHIR_INIT_VAR(limit);
	array_init(limit);
	ZEPHIR_OBS_VAR(number);
	if (zephir_array_isset_string_fetch(&number, limitClause, SS("number"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "_getexpression", NULL, 355, number);
		zephir_check_call_status();
		zephir_array_update_string(&limit, SL("number"), &_0$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(offset);
	if (zephir_array_isset_string_fetch(&offset, limitClause, SS("offset"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "_getexpression", NULL, 355, offset);
		zephir_check_call_status();
		zephir_array_update_string(&limit, SL("offset"), &_1$$4, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(limit);

}

/**
 * Analyzes a SELECT intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareSelect) {

	zval *_25$$27 = NULL, *_26$$27 = NULL, *_27$$27 = NULL;
	zval *_17$$27 = NULL, *_51$$47 = NULL;
	HashTable *_1, *_42, *_14$$24, *_47$$41;
	HashPosition _0, _41, _13$$24, _46$$41;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_12 = NULL, *_18 = NULL, *_20 = NULL, *_45 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, position = 0, number = 0;
	zval *ast = NULL, *merge = NULL, *sqlModels = NULL, *sqlTables = NULL, *sqlAliases = NULL, *sqlColumns = NULL, *select = NULL, *tables = NULL, *columns = NULL, *sqlAliasesModels = NULL, *sqlModelsAliases = NULL, *sqlAliasesModelsInstances = NULL, *models = NULL, *modelsInstances = NULL, *selectedModels = NULL, *manager = NULL, *metaData = NULL, *selectedModel = NULL, *qualifiedName = NULL, *modelName = NULL, *nsAlias = NULL, *realModelName = NULL, *model = NULL, *schema = NULL, *source = NULL, *completeSource = NULL, *alias = NULL, *joins = NULL, *sqlJoins = NULL, *selectColumns = NULL, *sqlColumnAliases = NULL, *column = NULL, *sqlColumn = NULL, *sqlSelect = NULL, *distinct = NULL, *having = NULL, *where = NULL, *groupBy = NULL, *order = NULL, *limit = NULL, *tempModels = NULL, *tempModelsInstances = NULL, *tempSqlAliases = NULL, *tempSqlModelsAliases = NULL, *tempSqlAliasesModelsInstances = NULL, *tempSqlAliasesModels = NULL, *with = NULL, *withs = NULL, *withItem = NULL, *automaticJoins = NULL, *relation = NULL, *joinAlias = NULL, *relationModel = NULL, *bestAlias = NULL, *eagerType = NULL, **_2, **_43, *_3$$15 = NULL, *_4$$15, *_6$$15, *_7$$14 = NULL, *_9$$20 = NULL, *_10$$20, *_11$$20 = NULL, **_15$$24, _16$$27 = zval_used_for_init, *_19$$28 = NULL, *_21$$30 = NULL, *_22$$31 = NULL, *_23$$31, *_24$$31 = NULL, *_28$$33, *_29$$33, *_30$$33, *_31$$33, *_32$$33, *_33$$33, *_34$$33, *_35$$33, *_36$$33, *_37$$33, *_38$$33, *_39$$33, *_40$$36, *_44$$41 = NULL, **_48$$41, *_49$$46, _50$$47 = zval_used_for_init, *_52$$51 = NULL, *_53$$52 = NULL, *_54$$53 = NULL, *_55$$54 = NULL, *_56$$55 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &ast, &merge);

	if (!ast) {
		ZEPHIR_CPY_WRT(ast, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(ast);
	}
	if (!merge) {
		ZEPHIR_CPY_WRT(merge, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(merge);
	}


	if (ZEPHIR_IS_EMPTY(ast)) {
		ZEPHIR_OBS_NVAR(ast);
		zephir_read_property_this(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(merge) == IS_NULL) {
		ZEPHIR_INIT_NVAR(merge);
		ZVAL_BOOL(merge, 0);
	}
	ZEPHIR_OBS_VAR(select);
	if (!(zephir_array_isset_string_fetch(&select, ast, SS("select"), 0 TSRMLS_CC))) {
		ZEPHIR_CPY_WRT(select, ast);
	}
	ZEPHIR_OBS_VAR(tables);
	if (!(zephir_array_isset_string_fetch(&tables, select, SS("tables"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 1781);
		return;
	}
	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, select, SS("columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 1785);
		return;
	}
	ZEPHIR_INIT_VAR(sqlModels);
	array_init(sqlModels);
	ZEPHIR_INIT_VAR(sqlTables);
	array_init(sqlTables);
	ZEPHIR_INIT_VAR(sqlColumns);
	array_init(sqlColumns);
	ZEPHIR_INIT_VAR(sqlAliases);
	array_init(sqlAliases);
	ZEPHIR_INIT_VAR(sqlAliasesModels);
	array_init(sqlAliasesModels);
	ZEPHIR_INIT_VAR(sqlModelsAliases);
	array_init(sqlModelsAliases);
	ZEPHIR_INIT_VAR(sqlAliasesModelsInstances);
	array_init(sqlAliasesModelsInstances);
	ZEPHIR_INIT_VAR(models);
	array_init(models);
	ZEPHIR_INIT_VAR(modelsInstances);
	array_init(modelsInstances);
	if (!(zephir_array_isset_long(tables, 0))) {
		ZEPHIR_INIT_VAR(selectedModels);
		zephir_create_array(selectedModels, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(selectedModels, tables);
	} else {
		ZEPHIR_CPY_WRT(selectedModels, tables);
	}
	if (!(zephir_array_isset_long(columns, 0))) {
		ZEPHIR_INIT_VAR(selectColumns);
		zephir_create_array(selectColumns, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(selectColumns, columns);
	} else {
		ZEPHIR_CPY_WRT(selectColumns, columns);
	}
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A models-manager is required to execute the query", "phalcon/mvc/model/query.zep", 1847);
		return;
	}
	if (Z_TYPE_P(metaData) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A meta-data is required to execute the query", "phalcon/mvc/model/query.zep", 1851);
		return;
	}
	number = 0;
	ZEPHIR_INIT_VAR(automaticJoins);
	array_init(automaticJoins);
	zephir_is_iterable(selectedModels, &_1, &_0, 0, 0, "phalcon/mvc/model/query.zep", 1980);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(selectedModel, _2);
		ZEPHIR_OBS_NVAR(qualifiedName);
		zephir_array_fetch_string(&qualifiedName, selectedModel, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 1860 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(modelName);
		zephir_array_fetch_string(&modelName, qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1861 TSRMLS_CC);
		if (zephir_memnstr_str(modelName, SL(":"), "phalcon/mvc/model/query.zep", 1864)) {
			ZEPHIR_INIT_NVAR(nsAlias);
			zephir_fast_explode_str(nsAlias, SL(":"), modelName, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_4$$15, nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1866 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3$$15, manager, "getnamespacealias", &_5, 0, _4$$15);
			zephir_check_call_status();
			zephir_array_fetch_long(&_6$$15, nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1866 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(realModelName);
			ZEPHIR_CONCAT_VSV(realModelName, _3$$15, "\\", _6$$15);
		} else {
			ZEPHIR_CPY_WRT(realModelName, modelName);
		}
		ZEPHIR_INIT_NVAR(_7$$14);
		ZVAL_BOOL(_7$$14, 1);
		ZEPHIR_CALL_METHOD(&model, manager, "load", &_8, 0, realModelName, _7$$14);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(schema)) {
			ZEPHIR_INIT_NVAR(completeSource);
			zephir_create_array(completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(completeSource, source);
			zephir_array_fast_append(completeSource, schema);
		} else {
			ZEPHIR_CPY_WRT(completeSource, source);
		}
		ZEPHIR_OBS_NVAR(alias);
		if (zephir_array_isset_string_fetch(&alias, selectedModel, SS("alias"), 0 TSRMLS_CC)) {
			if (zephir_array_isset(sqlAliases, alias)) {
				ZEPHIR_INIT_NVAR(_9$$20);
				object_init_ex(_9$$20, phalcon_mvc_model_exception_ce);
				_10$$20 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_11$$20);
				ZEPHIR_CONCAT_SVSV(_11$$20, "Alias '", alias, "' is used more than once, when preparing: ", _10$$20);
				ZEPHIR_CALL_METHOD(NULL, _9$$20, "__construct", &_12, 9, _11$$20);
				zephir_check_call_status();
				zephir_throw_exception_debug(_9$$20, "phalcon/mvc/model/query.zep", 1890 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&sqlAliases, alias, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModels, alias, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, realModelName, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, alias, &model, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(completeSource) == IS_ARRAY) {
				zephir_array_append(&completeSource, alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1902);
			} else {
				ZEPHIR_INIT_NVAR(completeSource);
				zephir_create_array(completeSource, 3, 0 TSRMLS_CC);
				zephir_array_fast_append(completeSource, source);
				zephir_array_fast_append(completeSource, ZEPHIR_GLOBAL(global_null));
				zephir_array_fast_append(completeSource, alias);
			}
			zephir_array_update_zval(&models, realModelName, &alias, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_CPY_WRT(alias, source);
			zephir_array_update_zval(&sqlAliases, realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModels, realModelName, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, realModelName, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, realModelName, &source, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_NVAR(with);
		if (zephir_array_isset_string_fetch(&with, selectedModel, SS("with"), 0 TSRMLS_CC)) {
			if (!(zephir_array_isset_long(with, 0))) {
				ZEPHIR_INIT_NVAR(withs);
				zephir_create_array(withs, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(withs, with);
			} else {
				ZEPHIR_CPY_WRT(withs, with);
			}
			zephir_is_iterable(withs, &_14$$24, &_13$$24, 0, 0, "phalcon/mvc/model/query.zep", 1972);
			for (
			  ; zend_hash_get_current_data_ex(_14$$24, (void**) &_15$$24, &_13$$24) == SUCCESS
			  ; zend_hash_move_forward_ex(_14$$24, &_13$$24)
			) {
				ZEPHIR_GET_HVALUE(withItem, _15$$24);
				ZEPHIR_SINIT_NVAR(_16$$27);
				ZVAL_LONG(&_16$$27, number);
				ZEPHIR_INIT_LNVAR(_17$$27);
				ZEPHIR_CONCAT_SV(_17$$27, "AA", &_16$$27);
				ZEPHIR_CPY_WRT(joinAlias, _17$$27);
				ZEPHIR_OBS_NVAR(relationModel);
				zephir_array_fetch_string(&relationModel, withItem, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1930 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&relation, manager, "getrelationbyalias", &_18, 0, realModelName, relationModel);
				zephir_check_call_status();
				if (Z_TYPE_P(relation) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(_19$$28);
					ZVAL_STRING(_19$$28, "alias", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&bestAlias, relation, "getoption", NULL, 0, _19$$28);
					zephir_check_temp_parameter(_19$$28);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&relationModel, relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&eagerType, relation, "gettype", NULL, 0);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(&relation, manager, "getrelationsbetween", &_20, 0, realModelName, relationModel);
					zephir_check_call_status();
					if (Z_TYPE_P(relation) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(_21$$30);
						ZVAL_STRING(_21$$30, "alias", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(&bestAlias, relation, "getoption", NULL, 0, _21$$30);
						zephir_check_temp_parameter(_21$$30);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&relationModel, relation, "getreferencedmodel", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&eagerType, relation, "gettype", NULL, 0);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(_22$$31);
						object_init_ex(_22$$31, phalcon_mvc_model_exception_ce);
						_23$$31 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
						ZEPHIR_INIT_LNVAR(_24$$31);
						ZEPHIR_CONCAT_SVSVSV(_24$$31, "Can't find a relationship between '", realModelName, "' and '", relationModel, "' when preparing: ", _23$$31);
						ZEPHIR_CALL_METHOD(NULL, _22$$31, "__construct", &_12, 9, _24$$31);
						zephir_check_call_status();
						zephir_throw_exception_debug(_22$$31, "phalcon/mvc/model/query.zep", 1946 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_INIT_NVAR(_25$$27);
				zephir_create_array(_25$$27, 5, 0 TSRMLS_CC);
				add_assoc_long_ex(_25$$27, SS("type"), 353);
				zephir_array_update_string(&_25$$27, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_25$$27, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_25$$27, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_25$$27, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
				zephir_array_append(&selectColumns, _25$$27, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1956);
				ZEPHIR_INIT_NVAR(_26$$27);
				zephir_create_array(_26$$27, 3, 0 TSRMLS_CC);
				add_assoc_long_ex(_26$$27, SS("type"), 360);
				ZEPHIR_INIT_NVAR(_27$$27);
				zephir_create_array(_27$$27, 2, 0 TSRMLS_CC);
				add_assoc_long_ex(_27$$27, SS("type"), 355);
				zephir_array_update_string(&_27$$27, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_26$$27, SL("qualified"), &_27$$27, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_27$$27);
				zephir_create_array(_27$$27, 2, 0 TSRMLS_CC);
				add_assoc_long_ex(_27$$27, SS("type"), 355);
				zephir_array_update_string(&_27$$27, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_26$$27, SL("alias"), &_27$$27, PH_COPY | PH_SEPARATE);
				zephir_array_append(&automaticJoins, _26$$27, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1968);
				number++;
			}
		}
		zephir_array_append(&sqlModels, realModelName, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1974);
		zephir_array_append(&sqlTables, completeSource, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1975);
		zephir_array_update_zval(&modelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_is_true(merge))) {
		zephir_update_property_this(getThis(), SL("_models"), models TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_modelsInstances"), modelsInstances TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_sqlAliases"), sqlAliases TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_sqlAliasesModels"), sqlAliasesModels TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_sqlModelsAliases"), sqlModelsAliases TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_sqlAliasesModelsInstances"), sqlAliasesModelsInstances TSRMLS_CC);
	} else {
		ZEPHIR_OBS_VAR(tempModels);
		zephir_read_property_this(&tempModels, this_ptr, SL("_models"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(tempModelsInstances);
		zephir_read_property_this(&tempModelsInstances, this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(tempSqlAliases);
		zephir_read_property_this(&tempSqlAliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(tempSqlAliasesModels);
		zephir_read_property_this(&tempSqlAliasesModels, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(tempSqlModelsAliases);
		zephir_read_property_this(&tempSqlModelsAliases, this_ptr, SL("_sqlModelsAliases"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(tempSqlAliasesModelsInstances);
		zephir_read_property_this(&tempSqlAliasesModelsInstances, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_28$$33);
		_29$$33 = zephir_fetch_nproperty_this(this_ptr, SL("_models"), PH_NOISY_CC);
		zephir_fast_array_merge(_28$$33, &(_29$$33), &(models) TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_models"), _28$$33 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_30$$33);
		_31$$33 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
		zephir_fast_array_merge(_30$$33, &(_31$$33), &(modelsInstances) TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_modelsInstances"), _30$$33 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_32$$33);
		_33$$33 = zephir_fetch_nproperty_this(this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
		zephir_fast_array_merge(_32$$33, &(_33$$33), &(sqlAliases) TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_sqlAliases"), _32$$33 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_34$$33);
		_35$$33 = zephir_fetch_nproperty_this(this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
		zephir_fast_array_merge(_34$$33, &(_35$$33), &(sqlAliasesModels) TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_sqlAliasesModels"), _34$$33 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_36$$33);
		_37$$33 = zephir_fetch_nproperty_this(this_ptr, SL("_sqlModelsAliases"), PH_NOISY_CC);
		zephir_fast_array_merge(_36$$33, &(_37$$33), &(sqlModelsAliases) TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_sqlModelsAliases"), _36$$33 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_38$$33);
		_39$$33 = zephir_fetch_nproperty_this(this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
		zephir_fast_array_merge(_38$$33, &(_39$$33), &(sqlAliasesModelsInstances) TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_sqlAliasesModelsInstances"), _38$$33 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(joins);
	zephir_array_isset_string_fetch(&joins, select, SS("joins"), 0 TSRMLS_CC);
	if (zephir_fast_count_int(joins TSRMLS_CC)) {
		if (zephir_fast_count_int(automaticJoins TSRMLS_CC)) {
			if (zephir_array_isset_long(joins, 0)) {
				ZEPHIR_INIT_VAR(_40$$36);
				zephir_fast_array_merge(_40$$36, &(joins), &(automaticJoins) TSRMLS_CC);
				zephir_array_update_string(&select, SL("joins"), &_40$$36, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_append(&automaticJoins, joins, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2012);
				zephir_array_update_string(&select, SL("joins"), &automaticJoins, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_CALL_METHOD(&sqlJoins, this_ptr, "_getjoins", NULL, 365, select);
		zephir_check_call_status();
	} else {
		if (zephir_fast_count_int(automaticJoins TSRMLS_CC)) {
			zephir_array_update_string(&select, SL("joins"), &automaticJoins, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&sqlJoins, this_ptr, "_getjoins", NULL, 365, select);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(sqlJoins);
			array_init(sqlJoins);
		}
	}
	position = 0;
	ZEPHIR_INIT_VAR(sqlColumnAliases);
	array_init(sqlColumnAliases);
	zephir_is_iterable(selectColumns, &_42, &_41, 0, 0, "phalcon/mvc/model/query.zep", 2065);
	for (
	  ; zend_hash_get_current_data_ex(_42, (void**) &_43, &_41) == SUCCESS
	  ; zend_hash_move_forward_ex(_42, &_41)
	) {
		ZEPHIR_GET_HVALUE(column, _43);
		ZEPHIR_CALL_METHOD(&_44$$41, this_ptr, "_getselectcolumn", &_45, 366, column);
		zephir_check_call_status();
		zephir_is_iterable(_44$$41, &_47$$41, &_46$$41, 0, 0, "phalcon/mvc/model/query.zep", 2064);
		for (
		  ; zend_hash_get_current_data_ex(_47$$41, (void**) &_48$$41, &_46$$41) == SUCCESS
		  ; zend_hash_move_forward_ex(_47$$41, &_46$$41)
		) {
			ZEPHIR_GET_HVALUE(sqlColumn, _48$$41);
			ZEPHIR_OBS_NVAR(alias);
			if (zephir_array_isset_string_fetch(&alias, column, SS("alias"), 0 TSRMLS_CC)) {
				zephir_array_update_string(&sqlColumn, SL("balias"), &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlColumns, alias, &sqlColumn, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlColumnAliases, alias, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_OBS_NVAR(alias);
				if (zephir_array_isset_string_fetch(&alias, sqlColumn, SS("balias"), 0 TSRMLS_CC)) {
					zephir_array_update_zval(&sqlColumns, alias, &sqlColumn, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_fetch_string(&_49$$46, sqlColumn, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2054 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(_49$$46, "scalar")) {
						ZEPHIR_SINIT_NVAR(_50$$47);
						ZVAL_LONG(&_50$$47, position);
						ZEPHIR_INIT_LNVAR(_51$$47);
						ZEPHIR_CONCAT_SV(_51$$47, "_", &_50$$47);
						zephir_array_update_zval(&sqlColumns, _51$$47, &sqlColumn, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_append(&sqlColumns, sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2057);
					}
				}
			}
			position++;
		}
	}
	zephir_update_property_this(getThis(), SL("_sqlColumnAliases"), sqlColumnAliases TSRMLS_CC);
	ZEPHIR_INIT_VAR(sqlSelect);
	zephir_create_array(sqlSelect, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&sqlSelect, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlSelect, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlSelect, SL("columns"), &sqlColumns, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(distinct);
	if (zephir_array_isset_string_fetch(&distinct, select, SS("distinct"), 0 TSRMLS_CC)) {
		zephir_array_update_string(&sqlSelect, SL("distinct"), &distinct, PH_COPY | PH_SEPARATE);
	}
	if (zephir_fast_count_int(sqlJoins TSRMLS_CC)) {
		zephir_array_update_string(&sqlSelect, SL("joins"), &sqlJoins, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(where);
	if (zephir_array_isset_string_fetch(&where, ast, SS("where"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_52$$51, this_ptr, "_getexpression", NULL, 355, where);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("where"), &_52$$51, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(groupBy);
	if (zephir_array_isset_string_fetch(&groupBy, ast, SS("groupBy"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_53$$52, this_ptr, "_getgroupclause", NULL, 367, groupBy);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("group"), &_53$$52, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(having);
	if (zephir_array_isset_string_fetch(&having, ast, SS("having"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_54$$53, this_ptr, "_getexpression", NULL, 355, having);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("having"), &_54$$53, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(order);
	if (zephir_array_isset_string_fetch(&order, ast, SS("orderBy"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_55$$54, this_ptr, "_getorderclause", NULL, 368, order);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("order"), &_55$$54, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(limit);
	if (zephir_array_isset_string_fetch(&limit, ast, SS("limit"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_56$$55, this_ptr, "_getlimitclause", NULL, 369, limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("limit"), &_56$$55, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string(ast, SS("forUpdate"))) {
		zephir_array_update_string(&sqlSelect, SL("forUpdate"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	}
	if (zephir_is_true(merge)) {
		zephir_update_property_this(getThis(), SL("_models"), tempModels TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_modelsInstances"), tempModelsInstances TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_sqlAliases"), tempSqlAliases TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_sqlAliasesModels"), tempSqlAliasesModels TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_sqlModelsAliases"), tempSqlModelsAliases TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_sqlAliasesModelsInstances"), tempSqlAliasesModelsInstances TSRMLS_CC);
	}
	RETURN_CCTOR(sqlSelect);

}

/**
 * Analyzes an INSERT intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareInsert) {

	zval *_8$$9 = NULL;
	HashTable *_6, *_14$$10;
	HashPosition _5, _13$$10;
	zend_bool notQuoting = 0;
	zval *ast = NULL, *qualifiedName = NULL, *nsAlias = NULL, *manager = NULL, *modelName = NULL, *model = NULL, *source = NULL, *schema = NULL, *exprValues = NULL, *exprValue = NULL, *sqlInsert = NULL, *metaData = NULL, *fields = NULL, *sqlFields = NULL, *field = NULL, *name = NULL, *realModelName = NULL, *_3, *_4, **_7, *_0$$6 = NULL, *_1$$6, *_2$$6, *_9$$9 = NULL, *_10$$9 = NULL, *_11$$9 = NULL, **_15$$10, *_16$$11 = NULL, *_18$$12 = NULL, *_19$$12, *_20$$12 = NULL;
	zephir_fcall_cache_entry *_12 = NULL, *_17 = NULL, *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(ast);
	zephir_read_property_this(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	if (!(zephir_array_isset_string(ast, SS("qualifiedName")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST", "phalcon/mvc/model/query.zep", 2137);
		return;
	}
	if (!(zephir_array_isset_string(ast, SS("values")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST", "phalcon/mvc/model/query.zep", 2141);
		return;
	}
	ZEPHIR_OBS_VAR(qualifiedName);
	zephir_array_fetch_string(&qualifiedName, ast, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 2144 TSRMLS_CC);
	if (!(zephir_array_isset_string(qualifiedName, SS("name")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST", "phalcon/mvc/model/query.zep", 2148);
		return;
	}
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(modelName);
	zephir_array_fetch_string(&modelName, qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2152 TSRMLS_CC);
	if (zephir_memnstr_str(modelName, SL(":"), "phalcon/mvc/model/query.zep", 2155)) {
		ZEPHIR_INIT_VAR(nsAlias);
		zephir_fast_explode_str(nsAlias, SL(":"), modelName, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_1$$6, nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2157 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_0$$6, manager, "getnamespacealias", NULL, 0, _1$$6);
		zephir_check_call_status();
		zephir_array_fetch_long(&_2$$6, nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2157 TSRMLS_CC);
		ZEPHIR_INIT_VAR(realModelName);
		ZEPHIR_CONCAT_VSV(realModelName, _0$$6, "\\", _2$$6);
	} else {
		ZEPHIR_CPY_WRT(realModelName, modelName);
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_CALL_METHOD(&model, manager, "load", NULL, 0, realModelName, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_NVAR(source);
		zephir_create_array(source, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(source, schema);
		zephir_array_fast_append(source, source);
	}
	notQuoting = 0;
	ZEPHIR_INIT_VAR(exprValues);
	array_init(exprValues);
	zephir_array_fetch_string(&_4, ast, SL("values"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2173 TSRMLS_CC);
	zephir_is_iterable(_4, &_6, &_5, 0, 0, "phalcon/mvc/model/query.zep", 2182);
	for (
	  ; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zend_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(exprValue, _7);
		ZEPHIR_INIT_NVAR(_8$$9);
		zephir_create_array(_8$$9, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_9$$9);
		zephir_array_fetch_string(&_9$$9, exprValue, SL("type"), PH_NOISY, "phalcon/mvc/model/query.zep", 2177 TSRMLS_CC);
		zephir_array_update_string(&_8$$9, SL("type"), &_9$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_11$$9);
		if (notQuoting) {
			ZVAL_BOOL(_11$$9, 1);
		} else {
			ZVAL_BOOL(_11$$9, 0);
		}
		ZEPHIR_CALL_METHOD(&_10$$9, this_ptr, "_getexpression", &_12, 355, exprValue, _11$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_8$$9, SL("value"), &_10$$9, PH_COPY | PH_SEPARATE);
		zephir_array_append(&exprValues, _8$$9, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2179);
	}
	ZEPHIR_INIT_VAR(sqlInsert);
	zephir_create_array(sqlInsert, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&sqlInsert, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlInsert, SL("table"), &source, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(fields);
	if (zephir_array_isset_string_fetch(&fields, ast, SS("fields"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(sqlFields);
		array_init(sqlFields);
		zephir_is_iterable(fields, &_14$$10, &_13$$10, 0, 0, "phalcon/mvc/model/query.zep", 2206);
		for (
		  ; zend_hash_get_current_data_ex(_14$$10, (void**) &_15$$10, &_13$$10) == SUCCESS
		  ; zend_hash_move_forward_ex(_14$$10, &_13$$10)
		) {
			ZEPHIR_GET_HVALUE(field, _15$$10);
			ZEPHIR_OBS_NVAR(name);
			zephir_array_fetch_string(&name, field, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2193 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_16$$11, metaData, "hasattribute", &_17, 0, model, name);
			zephir_check_call_status();
			if (!(zephir_is_true(_16$$11))) {
				ZEPHIR_INIT_NVAR(_18$$12);
				object_init_ex(_18$$12, phalcon_mvc_model_exception_ce);
				_19$$12 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_20$$12);
				ZEPHIR_CONCAT_SVSVSV(_20$$12, "The model '", modelName, "' doesn't have the attribute '", name, "', when preparing: ", _19$$12);
				ZEPHIR_CALL_METHOD(NULL, _18$$12, "__construct", &_21, 9, _20$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(_18$$12, "phalcon/mvc/model/query.zep", 2199 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&sqlFields, name, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2203);
		}
		zephir_array_update_string(&sqlInsert, SL("fields"), &sqlFields, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_string(&sqlInsert, SL("values"), &exprValues, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(sqlInsert);

}

/**
 * Analyzes an UPDATE intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareUpdate) {

	zval *_16$$17 = NULL;
	HashTable *_1, *_10;
	HashPosition _0, _9;
	zend_bool notQuoting = 0;
	zval *ast = NULL, *update = NULL, *tables = NULL, *values = NULL, *modelsInstances = NULL, *models = NULL, *sqlTables = NULL, *sqlAliases = NULL, *sqlAliasesModelsInstances = NULL, *updateTables = NULL, *nsAlias = NULL, *realModelName = NULL, *completeSource = NULL, *sqlModels = NULL, *manager = NULL, *table = NULL, *qualifiedName = NULL, *modelName = NULL, *model = NULL, *source = NULL, *schema = NULL, *alias = NULL, *sqlFields = NULL, *sqlValues = NULL, *updateValues = NULL, *updateValue = NULL, *exprColumn = NULL, *sqlUpdate = NULL, *where = NULL, *limit = NULL, **_2, **_11, *_3$$9 = NULL, *_4$$9, *_6$$9, *_7$$8 = NULL, *_12$$17 = NULL, *_13$$17, *_14$$17 = NULL, *_17$$17 = NULL, *_18$$17 = NULL, *_19$$17 = NULL, *_20$$18 = NULL, *_21$$18, *_22$$19 = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(ast);
	zephir_read_property_this(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(update);
	if (!(zephir_array_isset_string_fetch(&update, ast, SS("update"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST", "phalcon/mvc/model/query.zep", 2230);
		return;
	}
	ZEPHIR_OBS_VAR(tables);
	if (!(zephir_array_isset_string_fetch(&tables, update, SS("tables"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST", "phalcon/mvc/model/query.zep", 2234);
		return;
	}
	ZEPHIR_OBS_VAR(values);
	if (!(zephir_array_isset_string_fetch(&values, update, SS("values"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST", "phalcon/mvc/model/query.zep", 2238);
		return;
	}
	ZEPHIR_INIT_VAR(models);
	array_init(models);
	ZEPHIR_INIT_VAR(modelsInstances);
	array_init(modelsInstances);
	ZEPHIR_INIT_VAR(sqlTables);
	array_init(sqlTables);
	ZEPHIR_INIT_VAR(sqlModels);
	array_init(sqlModels);
	ZEPHIR_INIT_VAR(sqlAliases);
	array_init(sqlAliases);
	ZEPHIR_INIT_VAR(sqlAliasesModelsInstances);
	array_init(sqlAliasesModelsInstances);
	if (!(zephir_array_isset_long(tables, 0))) {
		ZEPHIR_INIT_VAR(updateTables);
		zephir_create_array(updateTables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(updateTables, tables);
	} else {
		ZEPHIR_CPY_WRT(updateTables, tables);
	}
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	zephir_is_iterable(updateTables, &_1, &_0, 0, 0, "phalcon/mvc/model/query.zep", 2313);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(table, _2);
		ZEPHIR_OBS_NVAR(qualifiedName);
		zephir_array_fetch_string(&qualifiedName, table, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 2261 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(modelName);
		zephir_array_fetch_string(&modelName, qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2262 TSRMLS_CC);
		if (zephir_memnstr_str(modelName, SL(":"), "phalcon/mvc/model/query.zep", 2267)) {
			ZEPHIR_INIT_NVAR(nsAlias);
			zephir_fast_explode_str(nsAlias, SL(":"), modelName, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_4$$9, nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2269 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3$$9, manager, "getnamespacealias", &_5, 0, _4$$9);
			zephir_check_call_status();
			zephir_array_fetch_long(&_6$$9, nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2269 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(realModelName);
			ZEPHIR_CONCAT_VSV(realModelName, _3$$9, "\\", _6$$9);
		} else {
			ZEPHIR_CPY_WRT(realModelName, modelName);
		}
		ZEPHIR_INIT_NVAR(_7$$8);
		ZVAL_BOOL(_7$$8, 1);
		ZEPHIR_CALL_METHOD(&model, manager, "load", &_8, 0, realModelName, _7$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(completeSource);
		if (zephir_is_true(schema)) {
			zephir_create_array(completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(completeSource, source);
			zephir_array_fast_append(completeSource, schema);
		} else {
			zephir_create_array(completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(completeSource, source);
			zephir_array_fast_append(completeSource, ZEPHIR_GLOBAL(global_null));
		}
		ZEPHIR_OBS_NVAR(alias);
		if (zephir_array_isset_string_fetch(&alias, table, SS("alias"), 0 TSRMLS_CC)) {
			zephir_array_update_zval(&sqlAliases, alias, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_append(&completeSource, alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2295);
			zephir_array_append(&sqlTables, completeSource, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2296);
			zephir_array_update_zval(&sqlAliasesModelsInstances, alias, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, alias, &realModelName, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&sqlAliases, realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlTables, source, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2302);
			zephir_array_update_zval(&models, realModelName, &source, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&sqlModels, realModelName, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2306);
		zephir_array_update_zval(&modelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_this(getThis(), SL("_models"), models TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_modelsInstances"), modelsInstances TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_sqlAliases"), sqlAliases TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_sqlAliasesModelsInstances"), sqlAliasesModelsInstances TSRMLS_CC);
	ZEPHIR_INIT_VAR(sqlFields);
	array_init(sqlFields);
	ZEPHIR_INIT_VAR(sqlValues);
	array_init(sqlValues);
	if (!(zephir_array_isset_long(values, 0))) {
		ZEPHIR_INIT_VAR(updateValues);
		zephir_create_array(updateValues, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(updateValues, values);
	} else {
		ZEPHIR_CPY_WRT(updateValues, values);
	}
	notQuoting = 0;
	zephir_is_iterable(updateValues, &_10, &_9, 0, 0, "phalcon/mvc/model/query.zep", 2337);
	for (
	  ; zend_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zend_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HVALUE(updateValue, _11);
		zephir_array_fetch_string(&_13$$17, updateValue, SL("column"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2329 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_14$$17);
		if (notQuoting) {
			ZVAL_BOOL(_14$$17, 1);
		} else {
			ZVAL_BOOL(_14$$17, 0);
		}
		ZEPHIR_CALL_METHOD(&_12$$17, this_ptr, "_getexpression", &_15, 355, _13$$17, _14$$17);
		zephir_check_call_status();
		zephir_array_append(&sqlFields, _12$$17, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2329);
		ZEPHIR_OBS_NVAR(exprColumn);
		zephir_array_fetch_string(&exprColumn, updateValue, SL("expr"), PH_NOISY, "phalcon/mvc/model/query.zep", 2330 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_16$$17);
		zephir_create_array(_16$$17, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_17$$17);
		zephir_array_fetch_string(&_17$$17, exprColumn, SL("type"), PH_NOISY, "phalcon/mvc/model/query.zep", 2332 TSRMLS_CC);
		zephir_array_update_string(&_16$$17, SL("type"), &_17$$17, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_19$$17);
		if (notQuoting) {
			ZVAL_BOOL(_19$$17, 1);
		} else {
			ZVAL_BOOL(_19$$17, 0);
		}
		ZEPHIR_CALL_METHOD(&_18$$17, this_ptr, "_getexpression", &_15, 355, exprColumn, _19$$17);
		zephir_check_call_status();
		zephir_array_update_string(&_16$$17, SL("value"), &_18$$17, PH_COPY | PH_SEPARATE);
		zephir_array_append(&sqlValues, _16$$17, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2334);
	}
	ZEPHIR_INIT_VAR(sqlUpdate);
	zephir_create_array(sqlUpdate, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&sqlUpdate, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("fields"), &sqlFields, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("values"), &sqlValues, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(where);
	if (zephir_array_isset_string_fetch(&where, ast, SS("where"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_21$$18);
		ZVAL_BOOL(_21$$18, 1);
		ZEPHIR_CALL_METHOD(&_20$$18, this_ptr, "_getexpression", &_15, 355, where, _21$$18);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("where"), &_20$$18, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(limit);
	if (zephir_array_isset_string_fetch(&limit, ast, SS("limit"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_22$$19, this_ptr, "_getlimitclause", NULL, 369, limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("limit"), &_22$$19, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(sqlUpdate);

}

/**
 * Analyzes a DELETE intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareDelete) {

	HashTable *_1;
	HashPosition _0;
	zval *ast = NULL, *delete = NULL, *tables = NULL, *models = NULL, *modelsInstances = NULL, *sqlTables = NULL, *sqlModels = NULL, *sqlAliases = NULL, *sqlAliasesModelsInstances = NULL, *deleteTables = NULL, *manager = NULL, *table = NULL, *qualifiedName = NULL, *modelName = NULL, *nsAlias = NULL, *realModelName = NULL, *model = NULL, *source = NULL, *schema = NULL, *completeSource = NULL, *alias = NULL, *sqlDelete = NULL, *where = NULL, *limit = NULL, **_2, *_3$$8 = NULL, *_4$$8, *_6$$8, *_7$$7 = NULL, *_9$$14 = NULL, *_10$$14, *_11$$15 = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(ast);
	zephir_read_property_this(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(delete);
	if (!(zephir_array_isset_string_fetch(&delete, ast, SS("delete"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST", "phalcon/mvc/model/query.zep", 2369);
		return;
	}
	ZEPHIR_OBS_VAR(tables);
	if (!(zephir_array_isset_string_fetch(&tables, delete, SS("tables"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST", "phalcon/mvc/model/query.zep", 2373);
		return;
	}
	ZEPHIR_INIT_VAR(models);
	array_init(models);
	ZEPHIR_INIT_VAR(modelsInstances);
	array_init(modelsInstances);
	ZEPHIR_INIT_VAR(sqlTables);
	array_init(sqlTables);
	ZEPHIR_INIT_VAR(sqlModels);
	array_init(sqlModels);
	ZEPHIR_INIT_VAR(sqlAliases);
	array_init(sqlAliases);
	ZEPHIR_INIT_VAR(sqlAliasesModelsInstances);
	array_init(sqlAliasesModelsInstances);
	if (!(zephir_array_isset_long(tables, 0))) {
		ZEPHIR_INIT_VAR(deleteTables);
		zephir_create_array(deleteTables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(deleteTables, tables);
	} else {
		ZEPHIR_CPY_WRT(deleteTables, tables);
	}
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	zephir_is_iterable(deleteTables, &_1, &_0, 0, 0, "phalcon/mvc/model/query.zep", 2443);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(table, _2);
		ZEPHIR_OBS_NVAR(qualifiedName);
		zephir_array_fetch_string(&qualifiedName, table, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 2397 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(modelName);
		zephir_array_fetch_string(&modelName, qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2398 TSRMLS_CC);
		if (zephir_memnstr_str(modelName, SL(":"), "phalcon/mvc/model/query.zep", 2403)) {
			ZEPHIR_INIT_NVAR(nsAlias);
			zephir_fast_explode_str(nsAlias, SL(":"), modelName, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_4$$8, nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2405 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3$$8, manager, "getnamespacealias", &_5, 0, _4$$8);
			zephir_check_call_status();
			zephir_array_fetch_long(&_6$$8, nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2405 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(realModelName);
			ZEPHIR_CONCAT_VSV(realModelName, _3$$8, "\\", _6$$8);
		} else {
			ZEPHIR_CPY_WRT(realModelName, modelName);
		}
		ZEPHIR_INIT_NVAR(_7$$7);
		ZVAL_BOOL(_7$$7, 1);
		ZEPHIR_CALL_METHOD(&model, manager, "load", &_8, 0, realModelName, _7$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(completeSource);
		if (zephir_is_true(schema)) {
			zephir_create_array(completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(completeSource, source);
			zephir_array_fast_append(completeSource, schema);
		} else {
			zephir_create_array(completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(completeSource, source);
			zephir_array_fast_append(completeSource, ZEPHIR_GLOBAL(global_null));
		}
		ZEPHIR_OBS_NVAR(alias);
		if (zephir_array_isset_string_fetch(&alias, table, SS("alias"), 0 TSRMLS_CC)) {
			zephir_array_update_zval(&sqlAliases, alias, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_append(&completeSource, alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2425);
			zephir_array_append(&sqlTables, completeSource, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2426);
			zephir_array_update_zval(&sqlAliasesModelsInstances, alias, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, alias, &realModelName, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&sqlAliases, realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlTables, source, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2432);
			zephir_array_update_zval(&models, realModelName, &source, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&sqlModels, realModelName, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2436);
		zephir_array_update_zval(&modelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_this(getThis(), SL("_models"), models TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_modelsInstances"), modelsInstances TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_sqlAliases"), sqlAliases TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_sqlAliasesModelsInstances"), sqlAliasesModelsInstances TSRMLS_CC);
	ZEPHIR_INIT_VAR(sqlDelete);
	array_init(sqlDelete);
	zephir_array_update_string(&sqlDelete, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlDelete, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(where);
	if (zephir_array_isset_string_fetch(&where, ast, SS("where"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_10$$14);
		ZVAL_BOOL(_10$$14, 1);
		ZEPHIR_CALL_METHOD(&_9$$14, this_ptr, "_getexpression", NULL, 355, where, _10$$14);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("where"), &_9$$14, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(limit);
	if (zephir_array_isset_string_fetch(&limit, ast, SS("limit"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_11$$15, this_ptr, "_getlimitclause", NULL, 369, limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("limit"), &_11$$15, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(sqlDelete);

}

/**
 * Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang generating another
 * intermediate representation that could be executed by Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, parse) {

	zval *intermediate = NULL, *phql = NULL, *ast = NULL, *irPhql = NULL, *uniqueId = NULL, *type = NULL, *_0$$5, *_1$$7, *_2$$13, *_3$$13;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(intermediate);
	zephir_read_property_this(&intermediate, this_ptr, SL("_intermediate"), PH_NOISY_CC);
	if (Z_TYPE_P(intermediate) == IS_ARRAY) {
		RETURN_CCTOR(intermediate);
	}
	ZEPHIR_OBS_VAR(phql);
	zephir_read_property_this(&phql, this_ptr, SL("_phql"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(ast);
	ZEPHIR_LAST_CALL_STATUS = phql_parse_phql(ast, phql TSRMLS_CC);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(irPhql);
	ZVAL_NULL(irPhql);
	ZEPHIR_INIT_VAR(uniqueId);
	ZVAL_NULL(uniqueId);
	if (Z_TYPE_P(ast) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(uniqueId);
		if (zephir_array_isset_string_fetch(&uniqueId, ast, SS("id"), 0 TSRMLS_CC)) {
			ZEPHIR_OBS_NVAR(irPhql);
			_0$$5 = zephir_fetch_static_property_ce(phalcon_mvc_model_query_ce, SL("_irPhqlCache") TSRMLS_CC);
			if (zephir_array_isset_fetch(&irPhql, _0$$5, uniqueId, 0 TSRMLS_CC)) {
				if (Z_TYPE_P(irPhql) == IS_ARRAY) {
					zephir_array_fetch_string(&_1$$7, ast, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2494 TSRMLS_CC);
					zephir_update_property_this(getThis(), SL("_type"), _1$$7 TSRMLS_CC);
					RETURN_CCTOR(irPhql);
				}
			}
		}
		ZEPHIR_OBS_VAR(type);
		if (zephir_array_isset_string_fetch(&type, ast, SS("type"), 0 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_ast"), ast TSRMLS_CC);
			zephir_update_property_this(getThis(), SL("_type"), type TSRMLS_CC);
			do {
				if (ZEPHIR_IS_LONG(type, 309)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_prepareselect", NULL, 360);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(type, 306)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_prepareinsert", NULL, 370);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(type, 300)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_prepareupdate", NULL, 371);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(type, 303)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_preparedelete", NULL, 372);
					zephir_check_call_status();
					break;
				}
				ZEPHIR_INIT_VAR(_2$$13);
				object_init_ex(_2$$13, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(_3$$13);
				ZEPHIR_CONCAT_SVSV(_3$$13, "Unknown statement ", type, ", when preparing: ", phql);
				ZEPHIR_CALL_METHOD(NULL, _2$$13, "__construct", NULL, 9, _3$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(_2$$13, "phalcon/mvc/model/query.zep", 2527 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} while(0);

		}
	}
	if (Z_TYPE_P(irPhql) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted AST", "phalcon/mvc/model/query.zep", 2533);
		return;
	}
	if (Z_TYPE_P(uniqueId) == IS_LONG) {
		zephir_update_static_property_array_multi_ce(phalcon_mvc_model_query_ce, SL("_irPhqlCache"), &irPhql TSRMLS_CC, SL("z"), 1, uniqueId);
	}
	zephir_update_property_this(getThis(), SL("_intermediate"), irPhql TSRMLS_CC);
	RETURN_CCTOR(irPhql);

}

/**
 * Returns the current cache backend instance
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getCache) {

	

	RETURN_MEMBER(getThis(), "_cache");

}

/**
 * Executes the SELECT intermediate representation producing a Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeSelect) {

	zend_class_entry *_65$$63;
	zval *_23$$25 = NULL, *_31$$28 = NULL, *_49$$59 = NULL, *_54$$61 = NULL;
	HashTable *_1, *_9, *_13, *_21$$22, *_29$$27, *_34$$35, *_38$$41, *_47$$58, *_52$$60;
	HashPosition _0, _8, _12, _20$$22, _28$$27, _33$$35, _37$$41, _46$$58, _51$$60;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_17 = NULL, *_18 = NULL, *_19 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberObjects = 0;
	zend_bool simulate, haveObjects = 0, haveScalars = 0, isComplex = 0, isSimpleStd = 0, isKeepingSnapshots = 0, _43, _32$$19, _57$$51;
	zval *intermediate, *bindParams, *bindTypes, *simulate_param = NULL, *manager = NULL, *modelName = NULL, *models = NULL, *model = NULL, *connection = NULL, *connectionTypes = NULL, *columns = NULL, *column = NULL, *selectColumns = NULL, *simpleColumnMap = NULL, *metaData = NULL, *aliasCopy = NULL, *sqlColumn = NULL, *attributes = NULL, *instance = NULL, *columnMap = NULL, *attribute = NULL, *columnAlias = NULL, *sqlAlias = NULL, *dialect = NULL, *sqlSelect = NULL, *bindCounts = NULL, *processed = NULL, *wildcard = NULL, *value = NULL, *processedTypes = NULL, *typeWildcard = NULL, *result = NULL, *resultData = NULL, *cache = NULL, *resultObject = NULL, *columns1 = NULL, *typesColumnMap = NULL, *wildcardValue = NULL, *resultsetClassName = NULL, **_2, **_10, **_14, *_41, *_44 = NULL, *_3$$3, *_4$$4 = NULL, *_7$$5 = NULL, *_11$$7, *_15$$19, *_16$$20, **_22$$22, *_25$$22 = NULL, *_24$$25 = NULL, *_27$$26 = NULL, **_30$$27, **_35$$35, *_36$$39 = NULL, **_39$$41, *_40$$43 = NULL, *_42$$47 = NULL, *_45$$58 = NULL, **_48$$58, *_50$$59 = NULL, **_53$$60, *_55$$61 = NULL, *_56$$53 = NULL, *_67$$51, *_58$$64, *_59$$64, _60$$63, *_61$$63 = NULL, *_64$$63 = NULL, *_66$$63, *_62$$65, *_63$$65;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &intermediate, &bindParams, &bindTypes, &simulate_param);

	ZEPHIR_SEPARATE_PARAM(intermediate);
	if (!simulate_param) {
		simulate = 0;
	} else {
		simulate = zephir_get_boolval(simulate_param);
	}


	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(connectionTypes);
	array_init(connectionTypes);
	ZEPHIR_OBS_VAR(models);
	zephir_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 2576 TSRMLS_CC);
	zephir_is_iterable(models, &_1, &_0, 0, 0, "phalcon/mvc/model/query.zep", 2597);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(modelName, _2);
		ZEPHIR_OBS_NVAR(model);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
		if (!(zephir_array_isset_fetch(&model, _3$$3, modelName, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_4$$4);
			ZVAL_BOOL(_4$$4, 1);
			ZEPHIR_CALL_METHOD(&model, manager, "load", &_5, 0, modelName, _4$$4);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("_modelsInstances"), modelName, model TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&connection, this_ptr, "getreadconnection", &_6, 0, model, intermediate, bindParams, bindTypes);
		zephir_check_call_status();
		if (Z_TYPE_P(connection) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_7$$5, connection, "gettype", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_zval(&connectionTypes, _7$$5, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			if (zephir_fast_count_int(connectionTypes TSRMLS_CC) == 2) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cannot use models of different database systems in the same query", "phalcon/mvc/model/query.zep", 2592);
				return;
			}
		}
	}
	ZEPHIR_OBS_VAR(columns);
	zephir_array_fetch_string(&columns, intermediate, SL("columns"), PH_NOISY, "phalcon/mvc/model/query.zep", 2597 TSRMLS_CC);
	haveObjects = 0;
	haveScalars = 0;
	isComplex = 0;
	numberObjects = 0;
	ZEPHIR_CPY_WRT(columns1, columns);
	zephir_is_iterable(columns, &_9, &_8, 0, 0, "phalcon/mvc/model/query.zep", 2624);
	for (
	  ; zend_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
	  ; zend_hash_move_forward_ex(_9, &_8)
	) {
		ZEPHIR_GET_HVALUE(column, _10);
		if (Z_TYPE_P(column) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid column definition", "phalcon/mvc/model/query.zep", 2610);
			return;
		}
		zephir_array_fetch_string(&_11$$7, column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2613 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_11$$7, "scalar")) {
			if (!(zephir_array_isset_string(column, SS("balias")))) {
				isComplex = 1;
			}
			haveScalars = 1;
		} else {
			haveObjects = 1;
			numberObjects++;
		}
	}
	if (isComplex == 0) {
		if (haveObjects == 1) {
			if (haveScalars == 1) {
				isComplex = 1;
			} else {
				if (numberObjects == 1) {
					isSimpleStd = 0;
				} else {
					isComplex = 1;
				}
			}
		} else {
			isSimpleStd = 1;
		}
	}
	ZEPHIR_INIT_VAR(instance);
	ZVAL_NULL(instance);
	ZEPHIR_INIT_VAR(selectColumns);
	array_init(selectColumns);
	ZEPHIR_INIT_VAR(simpleColumnMap);
	array_init(simpleColumnMap);
	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	zephir_is_iterable(columns, &_13, &_12, 0, 0, "phalcon/mvc/model/query.zep", 2723);
	for (
	  ; zend_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
	  ; zend_hash_move_forward_ex(_13, &_12)
	) {
		ZEPHIR_GET_HMKEY(aliasCopy, _13, _12);
		ZEPHIR_GET_HVALUE(column, _14);
		ZEPHIR_OBS_NVAR(sqlColumn);
		zephir_array_fetch_string(&sqlColumn, column, SL("column"), PH_NOISY, "phalcon/mvc/model/query.zep", 2648 TSRMLS_CC);
		zephir_array_fetch_string(&_15$$19, column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2651 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_15$$19, "object")) {
			ZEPHIR_OBS_NVAR(modelName);
			zephir_array_fetch_string(&modelName, column, SL("model"), PH_NOISY, "phalcon/mvc/model/query.zep", 2653 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(instance);
			_16$$20 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
			if (!(zephir_array_isset_fetch(&instance, _16$$20, modelName, 0 TSRMLS_CC))) {
				ZEPHIR_CALL_METHOD(&instance, manager, "load", &_17, 0, modelName);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("_modelsInstances"), modelName, instance TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&attributes, metaData, "getattributes", &_18, 0, instance);
			zephir_check_call_status();
			if (isComplex == 1) {
				if (ZEPHIR_GLOBAL(orm).column_renaming) {
					ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", &_19, 0, instance);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(columnMap);
					ZVAL_NULL(columnMap);
				}
				zephir_is_iterable(attributes, &_21$$22, &_20$$22, 0, 0, "phalcon/mvc/model/query.zep", 2679);
				for (
				  ; zend_hash_get_current_data_ex(_21$$22, (void**) &_22$$22, &_20$$22) == SUCCESS
				  ; zend_hash_move_forward_ex(_21$$22, &_20$$22)
				) {
					ZEPHIR_GET_HVALUE(attribute, _22$$22);
					ZEPHIR_INIT_NVAR(_23$$25);
					zephir_create_array(_23$$25, 3, 0 TSRMLS_CC);
					zephir_array_fast_append(_23$$25, attribute);
					zephir_array_fast_append(_23$$25, sqlColumn);
					ZEPHIR_INIT_LNVAR(_24$$25);
					ZEPHIR_CONCAT_SVSV(_24$$25, "_", sqlColumn, "_", attribute);
					zephir_array_fast_append(_23$$25, _24$$25);
					zephir_array_append(&selectColumns, _23$$25, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2675);
				}
				zephir_array_update_multi(&columns1, &instance TSRMLS_CC, SL("zs"), 3, aliasCopy, SL("instance"));
				zephir_array_update_multi(&columns1, &attributes TSRMLS_CC, SL("zs"), 3, aliasCopy, SL("attributes"));
				zephir_array_update_multi(&columns1, &columnMap TSRMLS_CC, SL("zs"), 3, aliasCopy, SL("columnMap"));
				ZEPHIR_CALL_METHOD(&_25$$22, manager, "iskeepingsnapshots", &_26, 0, instance);
				zephir_check_call_status();
				isKeepingSnapshots = zephir_get_boolval(_25$$22);
				if (isKeepingSnapshots) {
					ZEPHIR_INIT_NVAR(_27$$26);
					ZVAL_BOOL(_27$$26, isKeepingSnapshots);
					zephir_array_update_multi(&columns1, &_27$$26 TSRMLS_CC, SL("zs"), 3, aliasCopy, SL("keepSnapshots"));
				}
			} else {
				zephir_is_iterable(attributes, &_29$$27, &_28$$27, 0, 0, "phalcon/mvc/model/query.zep", 2697);
				for (
				  ; zend_hash_get_current_data_ex(_29$$27, (void**) &_30$$27, &_28$$27) == SUCCESS
				  ; zend_hash_move_forward_ex(_29$$27, &_28$$27)
				) {
					ZEPHIR_GET_HVALUE(attribute, _30$$27);
					ZEPHIR_INIT_NVAR(_31$$28);
					zephir_create_array(_31$$28, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(_31$$28, attribute);
					zephir_array_fast_append(_31$$28, sqlColumn);
					zephir_array_append(&selectColumns, _31$$28, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2695);
				}
			}
		} else {
			ZEPHIR_INIT_NVAR(columnAlias);
			if (Z_TYPE_P(aliasCopy) == IS_LONG) {
				zephir_create_array(columnAlias, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(columnAlias, sqlColumn);
				zephir_array_fast_append(columnAlias, ZEPHIR_GLOBAL(global_null));
			} else {
				zephir_create_array(columnAlias, 3, 0 TSRMLS_CC);
				zephir_array_fast_append(columnAlias, sqlColumn);
				zephir_array_fast_append(columnAlias, ZEPHIR_GLOBAL(global_null));
				zephir_array_fast_append(columnAlias, aliasCopy);
			}
			zephir_array_append(&selectColumns, columnAlias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2708);
		}
		_32$$19 = isComplex == 0;
		if (_32$$19) {
			_32$$19 = isSimpleStd == 1;
		}
		if (_32$$19) {
			ZEPHIR_OBS_NVAR(sqlAlias);
			if (zephir_array_isset_string_fetch(&sqlAlias, column, SS("sqlAlias"), 0 TSRMLS_CC)) {
				zephir_array_update_zval(&simpleColumnMap, sqlAlias, &aliasCopy, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&simpleColumnMap, aliasCopy, &aliasCopy, PH_COPY | PH_SEPARATE);
			}
		}
	}
	ZEPHIR_INIT_VAR(bindCounts);
	array_init(bindCounts);
	zephir_array_update_string(&intermediate, SL("columns"), &selectColumns, PH_COPY | PH_SEPARATE);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(processed);
		array_init(processed);
		zephir_is_iterable(bindParams, &_34$$35, &_33$$35, 0, 0, "phalcon/mvc/model/query.zep", 2744);
		for (
		  ; zend_hash_get_current_data_ex(_34$$35, (void**) &_35$$35, &_33$$35) == SUCCESS
		  ; zend_hash_move_forward_ex(_34$$35, &_33$$35)
		) {
			ZEPHIR_GET_HMKEY(wildcard, _34$$35, _33$$35);
			ZEPHIR_GET_HVALUE(value, _35$$35);
			if (Z_TYPE_P(wildcard) == IS_LONG) {
				ZEPHIR_INIT_NVAR(wildcardValue);
				ZEPHIR_CONCAT_SV(wildcardValue, ":", wildcard);
			} else {
				ZEPHIR_CPY_WRT(wildcardValue, wildcard);
			}
			zephir_array_update_zval(&processed, wildcardValue, &value, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(value) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(_36$$39);
				ZVAL_LONG(_36$$39, zephir_fast_count_int(value TSRMLS_CC));
				zephir_array_update_zval(&bindCounts, wildcardValue, &_36$$39, PH_COPY | PH_SEPARATE);
			}
		}
	} else {
		ZEPHIR_CPY_WRT(processed, bindParams);
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(processedTypes);
		array_init(processedTypes);
		zephir_is_iterable(bindTypes, &_38$$41, &_37$$41, 0, 0, "phalcon/mvc/model/query.zep", 2760);
		for (
		  ; zend_hash_get_current_data_ex(_38$$41, (void**) &_39$$41, &_37$$41) == SUCCESS
		  ; zend_hash_move_forward_ex(_38$$41, &_37$$41)
		) {
			ZEPHIR_GET_HMKEY(typeWildcard, _38$$41, _37$$41);
			ZEPHIR_GET_HVALUE(value, _39$$41);
			if (Z_TYPE_P(typeWildcard) == IS_LONG) {
				ZEPHIR_INIT_LNVAR(_40$$43);
				ZEPHIR_CONCAT_SV(_40$$43, ":", typeWildcard);
				zephir_array_update_zval(&processedTypes, _40$$43, &value, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&processedTypes, typeWildcard, &value, PH_COPY | PH_SEPARATE);
			}
		}
	} else {
		ZEPHIR_CPY_WRT(processedTypes, bindTypes);
	}
	if (zephir_fast_count_int(bindCounts TSRMLS_CC)) {
		zephir_array_update_string(&intermediate, SL("bindCounts"), &bindCounts, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&dialect, connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&sqlSelect, dialect, "select", NULL, 0, intermediate);
	zephir_check_call_status();
	_41 = zephir_fetch_nproperty_this(this_ptr, SL("_sharedLock"), PH_NOISY_CC);
	if (zephir_is_true(_41)) {
		ZEPHIR_CALL_METHOD(&_42$$47, dialect, "sharedlock", NULL, 0, sqlSelect);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(sqlSelect, _42$$47);
	}
	if (simulate) {
		zephir_create_array(return_value, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&return_value, SL("sql"), &sqlSelect, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&return_value, SL("bind"), &processed, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&return_value, SL("bindTypes"), &processedTypes, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&result, connection, "query", NULL, 0, sqlSelect, processed, processedTypes);
	zephir_check_call_status();
	_43 = zephir_instance_of_ev(result, phalcon_db_resultinterface_ce TSRMLS_CC);
	if (_43) {
		ZEPHIR_CALL_METHOD(&_44, result, "numrows", NULL, 0);
		zephir_check_call_status();
		_43 = zephir_is_true(_44);
	}
	if (_43) {
		ZEPHIR_CPY_WRT(resultData, result);
	} else {
		ZEPHIR_INIT_NVAR(resultData);
		ZVAL_BOOL(resultData, 0);
	}
	ZEPHIR_OBS_VAR(cache);
	zephir_read_property_this(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	if (isComplex == 0) {
		if (isSimpleStd == 1) {
			ZEPHIR_INIT_VAR(resultObject);
			object_init_ex(resultObject, phalcon_mvc_model_row_ce);
			if (zephir_has_constructor(resultObject TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, resultObject, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			isKeepingSnapshots = 0;
		} else {
			if (Z_TYPE_P(instance) == IS_OBJECT) {
				ZEPHIR_CPY_WRT(resultObject, instance);
			} else {
				ZEPHIR_CPY_WRT(resultObject, model);
			}
			if (!(ZEPHIR_GLOBAL(orm).cast_on_hydrate)) {
				ZEPHIR_CALL_METHOD(&simpleColumnMap, metaData, "getcolumnmap", NULL, 0, resultObject);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, resultObject);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&typesColumnMap, metaData, "getdatatypes", NULL, 0, resultObject);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(simpleColumnMap);
				if (Z_TYPE_P(columnMap) == IS_NULL) {
					array_init(simpleColumnMap);
					ZEPHIR_CALL_METHOD(&_45$$58, metaData, "getattributes", NULL, 0, resultObject);
					zephir_check_call_status();
					zephir_is_iterable(_45$$58, &_47$$58, &_46$$58, 0, 0, "phalcon/mvc/model/query.zep", 2846);
					for (
					  ; zend_hash_get_current_data_ex(_47$$58, (void**) &_48$$58, &_46$$58) == SUCCESS
					  ; zend_hash_move_forward_ex(_47$$58, &_46$$58)
					) {
						ZEPHIR_GET_HVALUE(attribute, _48$$58);
						ZEPHIR_INIT_NVAR(_49$$59);
						zephir_create_array(_49$$59, 2, 0 TSRMLS_CC);
						zephir_array_fast_append(_49$$59, attribute);
						ZEPHIR_OBS_NVAR(_50$$59);
						zephir_array_fetch(&_50$$59, typesColumnMap, attribute, PH_NOISY, "phalcon/mvc/model/query.zep", 2844 TSRMLS_CC);
						zephir_array_fast_append(_49$$59, _50$$59);
						zephir_array_update_zval(&simpleColumnMap, attribute, &_49$$59, PH_COPY | PH_SEPARATE);
					}
				} else {
					array_init(simpleColumnMap);
					zephir_is_iterable(columnMap, &_52$$60, &_51$$60, 0, 0, "phalcon/mvc/model/query.zep", 2851);
					for (
					  ; zend_hash_get_current_data_ex(_52$$60, (void**) &_53$$60, &_51$$60) == SUCCESS
					  ; zend_hash_move_forward_ex(_52$$60, &_51$$60)
					) {
						ZEPHIR_GET_HMKEY(column, _52$$60, _51$$60);
						ZEPHIR_GET_HVALUE(attribute, _53$$60);
						ZEPHIR_INIT_NVAR(_54$$61);
						zephir_create_array(_54$$61, 2, 0 TSRMLS_CC);
						zephir_array_fast_append(_54$$61, attribute);
						ZEPHIR_OBS_NVAR(_55$$61);
						zephir_array_fetch(&_55$$61, typesColumnMap, column, PH_NOISY, "phalcon/mvc/model/query.zep", 2849 TSRMLS_CC);
						zephir_array_fast_append(_54$$61, _55$$61);
						zephir_array_update_zval(&simpleColumnMap, column, &_54$$61, PH_COPY | PH_SEPARATE);
					}
				}
			}
			ZEPHIR_CALL_METHOD(&_56$$53, manager, "iskeepingsnapshots", NULL, 0, resultObject);
			zephir_check_call_status();
			isKeepingSnapshots = zephir_get_boolval(_56$$53);
		}
		_57$$51 = zephir_instance_of_ev(resultObject, phalcon_mvc_modelinterface_ce TSRMLS_CC);
		if (_57$$51) {
			_57$$51 = (zephir_method_exists_ex(resultObject, SS("getresultsetclass") TSRMLS_CC) == SUCCESS);
		}
		if (_57$$51) {
			ZEPHIR_CALL_METHOD(&resultsetClassName, resultObject, "getresultsetclass", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(resultsetClassName)) {
				if (!(zephir_class_exists(resultsetClassName, 1 TSRMLS_CC))) {
					ZEPHIR_INIT_VAR(_58$$64);
					object_init_ex(_58$$64, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_VAR(_59$$64);
					ZEPHIR_CONCAT_SVS(_59$$64, "Resultset class \"", resultsetClassName, "\" not found");
					ZEPHIR_CALL_METHOD(NULL, _58$$64, "__construct", NULL, 9, _59$$64);
					zephir_check_call_status();
					zephir_throw_exception_debug(_58$$64, "phalcon/mvc/model/query.zep", 2865 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_SINIT_VAR(_60$$63);
				ZVAL_STRING(&_60$$63, "Phalcon\\Mvc\\Model\\ResultsetInterface", 0);
				ZEPHIR_CALL_FUNCTION(&_61$$63, "is_subclass_of", NULL, 343, resultsetClassName, &_60$$63);
				zephir_check_call_status();
				if (!(zephir_is_true(_61$$63))) {
					ZEPHIR_INIT_VAR(_62$$65);
					object_init_ex(_62$$65, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_VAR(_63$$65);
					ZEPHIR_CONCAT_SVS(_63$$65, "Resultset class \"", resultsetClassName, "\" must be an implementation of Phalcon\\Mvc\\Model\\ResultsetInterface");
					ZEPHIR_CALL_METHOD(NULL, _62$$65, "__construct", NULL, 9, _63$$65);
					zephir_check_call_status();
					zephir_throw_exception_debug(_62$$65, "phalcon/mvc/model/query.zep", 2869 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_fetch_safe_class(_64$$63, resultsetClassName);
					_65$$63 = zend_fetch_class(Z_STRVAL_P(_64$$63), Z_STRLEN_P(_64$$63), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(return_value, _65$$63);
				if (zephir_has_constructor(return_value TSRMLS_CC)) {
					ZEPHIR_INIT_VAR(_66$$63);
					if (isKeepingSnapshots) {
						ZVAL_BOOL(_66$$63, 1);
					} else {
						ZVAL_BOOL(_66$$63, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, simpleColumnMap, resultObject, resultData, cache, _66$$63);
					zephir_check_call_status();
				}
				RETURN_MM();
			}
		}
		object_init_ex(return_value, phalcon_mvc_model_resultset_simple_ce);
		ZEPHIR_INIT_VAR(_67$$51);
		if (isKeepingSnapshots) {
			ZVAL_BOOL(_67$$51, 1);
		} else {
			ZVAL_BOOL(_67$$51, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 373, simpleColumnMap, resultObject, resultData, cache, _67$$51);
		zephir_check_call_status();
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_mvc_model_resultset_complex_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 374, columns1, resultData, cache);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Executes the INSERT intermediate representation producing a Phalcon\Mvc\Model\Query\Status
 *
 * @param array intermediate
 * @param array bindParams
 * @param array bindTypes
 * @return \Phalcon\Mvc\Model\Query\StatusInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeInsert) {

	HashTable *_3;
	HashPosition _2;
	zend_bool automaticFields = 0;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_13 = NULL, *_15 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate, *bindParams, *bindTypes, *modelName = NULL, *manager = NULL, *connection = NULL, *metaData = NULL, *attributes = NULL, *fields = NULL, *columnMap = NULL, *dialect = NULL, *insertValues = NULL, *number = NULL, *value = NULL, *model = NULL, *values = NULL, *exprValue = NULL, *insertValue = NULL, *wildcard = NULL, *fieldName = NULL, *attributeName = NULL, *insertModel = NULL, *_0, **_4, *_19 = NULL, *_20 = NULL, *_1$$3, *_5$$8, *_7$$11 = NULL, _9$$11 = zval_used_for_init, _10$$11 = zval_used_for_init, *_11$$13 = NULL, *_12$$13 = NULL, *_14$$14 = NULL, *_17$$17 = NULL, *_18$$17 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_OBS_VAR(modelName);
	zephir_array_fetch_string(&modelName, intermediate, SL("model"), PH_NOISY, "phalcon/mvc/model/query.zep", 2904 TSRMLS_CC);
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(model);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&model, _0, modelName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_BOOL(_1$$3, 1);
		ZEPHIR_CALL_METHOD(&model, manager, "load", NULL, 0, modelName, _1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, model, intermediate, bindParams, bindTypes);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&attributes, metaData, "getattributes", NULL, 0, model);
	zephir_check_call_status();
	automaticFields = 0;
	ZEPHIR_OBS_VAR(fields);
	if (!(zephir_array_isset_string_fetch(&fields, intermediate, SS("fields"), 0 TSRMLS_CC))) {
		automaticFields = 1;
		ZEPHIR_CPY_WRT(fields, attributes);
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, model);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(columnMap);
			ZVAL_NULL(columnMap);
		}
	}
	ZEPHIR_OBS_VAR(values);
	zephir_array_fetch_string(&values, intermediate, SL("values"), PH_NOISY, "phalcon/mvc/model/query.zep", 2930 TSRMLS_CC);
	if (zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(values TSRMLS_CC)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The column count does not match the values count", "phalcon/mvc/model/query.zep", 2936);
		return;
	}
	ZEPHIR_CALL_METHOD(&dialect, connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(insertValues);
	array_init(insertValues);
	zephir_is_iterable(values, &_3, &_2, 0, 0, "phalcon/mvc/model/query.zep", 3006);
	for (
	  ; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zend_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(number, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		ZEPHIR_OBS_NVAR(exprValue);
		zephir_array_fetch_string(&exprValue, value, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 2947 TSRMLS_CC);
		zephir_array_fetch_string(&_5$$8, value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2948 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(_5$$8, 260) || ZEPHIR_IS_LONG(_5$$8, 258) || ZEPHIR_IS_LONG(_5$$8, 259)) {
				ZEPHIR_CALL_METHOD(&insertValue, dialect, "getsqlexpression", &_6, 0, exprValue);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(_5$$8, 322)) {
				ZEPHIR_INIT_NVAR(insertValue);
				ZVAL_NULL(insertValue);
				break;
			}
			if (ZEPHIR_IS_LONG(_5$$8, 273) || ZEPHIR_IS_LONG(_5$$8, 274) || ZEPHIR_IS_LONG(_5$$8, 277)) {
				if (Z_TYPE_P(bindParams) != IS_ARRAY) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array", "phalcon/mvc/model/query.zep", 2965);
					return;
				}
				ZEPHIR_CALL_METHOD(&_7$$11, dialect, "getsqlexpression", &_8, 0, exprValue);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_9$$11);
				ZVAL_STRING(&_9$$11, ":", 0);
				ZEPHIR_SINIT_NVAR(_10$$11);
				ZVAL_STRING(&_10$$11, "", 0);
				ZEPHIR_INIT_NVAR(wildcard);
				zephir_fast_str_replace(&wildcard, &_9$$11, &_10$$11, _7$$11 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(insertValue);
				if (!(zephir_array_isset_fetch(&insertValue, bindParams, wildcard, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_11$$13);
					object_init_ex(_11$$13, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_12$$13);
					ZEPHIR_CONCAT_SVS(_12$$13, "Bound parameter '", wildcard, "' cannot be replaced because it isn't in the placeholders list");
					ZEPHIR_CALL_METHOD(NULL, _11$$13, "__construct", &_13, 9, _12$$13);
					zephir_check_call_status();
					zephir_throw_exception_debug(_11$$13, "phalcon/mvc/model/query.zep", 2972 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				break;
			}
			ZEPHIR_INIT_NVAR(insertValue);
			object_init_ex(insertValue, phalcon_db_rawvalue_ce);
			ZEPHIR_CALL_METHOD(&_14$$14, dialect, "getsqlexpression", &_15, 0, exprValue);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, insertValue, "__construct", &_16, 26, _14$$14);
			zephir_check_call_status();
			break;
		} while(0);

		ZEPHIR_OBS_NVAR(fieldName);
		zephir_array_fetch(&fieldName, fields, number, PH_NOISY, "phalcon/mvc/model/query.zep", 2982 TSRMLS_CC);
		if (automaticFields == 1) {
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeName);
				if (!(zephir_array_isset_fetch(&attributeName, columnMap, fieldName, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_17$$17);
					object_init_ex(_17$$17, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_18$$17);
					ZEPHIR_CONCAT_SVS(_18$$17, "Column '", fieldName, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _17$$17, "__construct", &_13, 9, _18$$17);
					zephir_check_call_status();
					zephir_throw_exception_debug(_17$$17, "phalcon/mvc/model/query.zep", 2990 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeName, fieldName);
			}
		} else {
			ZEPHIR_CPY_WRT(attributeName, fieldName);
		}
		zephir_array_update_zval(&insertValues, attributeName, &insertValue, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&_19, manager, "load", NULL, 0, modelName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(insertModel);
	if (zephir_clone(insertModel, _19 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZEPHIR_CALL_METHOD(&_20, insertModel, "create", NULL, 0, insertValues);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 375, _20, insertModel);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Executes the UPDATE intermediate representation producing a Phalcon\Mvc\Model\Query\Status
 *
 * @param array intermediate
 * @param array bindParams
 * @param array bindTypes
 * @return \Phalcon\Mvc\Model\Query\StatusInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeUpdate) {

	HashTable *_3;
	HashPosition _2;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_13 = NULL, *_15 = NULL, *_16 = NULL, *_19 = NULL, *_21 = NULL, *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate, *bindParams, *bindTypes, *models = NULL, *modelName = NULL, *model = NULL, *connection = NULL, *dialect = NULL, *fields = NULL, *values = NULL, *updateValues = NULL, *fieldName = NULL, *value = NULL, *selectBindParams = NULL, *selectBindTypes = NULL, *number = NULL, *field = NULL, *records = NULL, *exprValue = NULL, *updateValue = NULL, *wildcard = NULL, *record = NULL, *_0, **_4, *_18 = NULL, *_24, *_1$$4, *_5$$5, *_7$$10 = NULL, _9$$10 = zval_used_for_init, _10$$10 = zval_used_for_init, *_11$$13 = NULL, *_12$$13 = NULL, *_14$$15 = NULL, *_17$$16, *_20$$17 = NULL, *_22$$18 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_OBS_VAR(models);
	zephir_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 3030 TSRMLS_CC);
	if (zephir_array_isset_long(models, 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Updating several models at the same time is still not supported", "phalcon/mvc/model/query.zep", 3033);
		return;
	}
	ZEPHIR_OBS_VAR(modelName);
	zephir_array_fetch_long(&modelName, models, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 3036 TSRMLS_CC);
	ZEPHIR_OBS_VAR(model);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&model, _0, modelName, 0 TSRMLS_CC))) {
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&model, _1$$4, "load", NULL, 0, modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, model, intermediate, bindParams, bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&dialect, connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(fields);
	zephir_array_fetch_string(&fields, intermediate, SL("fields"), PH_NOISY, "phalcon/mvc/model/query.zep", 3049 TSRMLS_CC);
	ZEPHIR_OBS_VAR(values);
	zephir_array_fetch_string(&values, intermediate, SL("values"), PH_NOISY, "phalcon/mvc/model/query.zep", 3050 TSRMLS_CC);
	ZEPHIR_INIT_VAR(updateValues);
	array_init(updateValues);
	ZEPHIR_CPY_WRT(selectBindParams, bindParams);
	ZEPHIR_CPY_WRT(selectBindTypes, bindTypes);
	zephir_is_iterable(fields, &_3, &_2, 0, 0, "phalcon/mvc/model/query.zep", 3119);
	for (
	  ; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zend_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(number, _3, _2);
		ZEPHIR_GET_HVALUE(field, _4);
		ZEPHIR_OBS_NVAR(value);
		zephir_array_fetch(&value, values, number, PH_NOISY, "phalcon/mvc/model/query.zep", 3065 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(exprValue);
		zephir_array_fetch_string(&exprValue, value, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 3066 TSRMLS_CC);
		if (zephir_array_isset_string(field, SS("balias"))) {
			ZEPHIR_OBS_NVAR(fieldName);
			zephir_array_fetch_string(&fieldName, field, SL("balias"), PH_NOISY, "phalcon/mvc/model/query.zep", 3069 TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(fieldName);
			zephir_array_fetch_string(&fieldName, field, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 3071 TSRMLS_CC);
		}
		zephir_array_fetch_string(&_5$$5, value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 3074 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(_5$$5, 260) || ZEPHIR_IS_LONG(_5$$5, 258) || ZEPHIR_IS_LONG(_5$$5, 259)) {
				ZEPHIR_CALL_METHOD(&updateValue, dialect, "getsqlexpression", &_6, 0, exprValue);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(_5$$5, 322)) {
				ZEPHIR_INIT_NVAR(updateValue);
				ZVAL_NULL(updateValue);
				break;
			}
			if (ZEPHIR_IS_LONG(_5$$5, 273) || ZEPHIR_IS_LONG(_5$$5, 274) || ZEPHIR_IS_LONG(_5$$5, 277)) {
				if (Z_TYPE_P(bindParams) != IS_ARRAY) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array", "phalcon/mvc/model/query.zep", 3091);
					return;
				}
				ZEPHIR_CALL_METHOD(&_7$$10, dialect, "getsqlexpression", &_8, 0, exprValue);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_9$$10);
				ZVAL_STRING(&_9$$10, ":", 0);
				ZEPHIR_SINIT_NVAR(_10$$10);
				ZVAL_STRING(&_10$$10, "", 0);
				ZEPHIR_INIT_NVAR(wildcard);
				zephir_fast_str_replace(&wildcard, &_9$$10, &_10$$10, _7$$10 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(updateValue);
				if (zephir_array_isset_fetch(&updateValue, bindParams, wildcard, 0 TSRMLS_CC)) {
					zephir_array_unset(&selectBindParams, wildcard, PH_SEPARATE);
					zephir_array_unset(&selectBindTypes, wildcard, PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(_11$$13);
					object_init_ex(_11$$13, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_12$$13);
					ZEPHIR_CONCAT_SVS(_12$$13, "Bound parameter '", wildcard, "' cannot be replaced because it's not in the placeholders list");
					ZEPHIR_CALL_METHOD(NULL, _11$$13, "__construct", &_13, 9, _12$$13);
					zephir_check_call_status();
					zephir_throw_exception_debug(_11$$13, "phalcon/mvc/model/query.zep", 3101 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				break;
			}
			if (ZEPHIR_IS_LONG(_5$$5, 277)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not supported", "phalcon/mvc/model/query.zep", 3106);
				return;
			}
			ZEPHIR_INIT_NVAR(updateValue);
			object_init_ex(updateValue, phalcon_db_rawvalue_ce);
			ZEPHIR_CALL_METHOD(&_14$$15, dialect, "getsqlexpression", &_15, 0, exprValue);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, updateValue, "__construct", &_16, 26, _14$$15);
			zephir_check_call_status();
			break;
		} while(0);

		zephir_array_update_zval(&updateValues, fieldName, &updateValue, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", NULL, 376, model, intermediate, selectBindParams, selectBindTypes);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(records TSRMLS_CC))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		ZEPHIR_INIT_VAR(_17$$16);
		ZVAL_BOOL(_17$$16, 1);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 375, _17$$16);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, model, intermediate, bindParams, bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, records, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_18, records, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_18))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&record, records, "current", &_19, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_20$$17, record, "update", NULL, 0, updateValues);
		zephir_check_call_status();
		if (!(zephir_is_true(_20$$17))) {
			ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_21, 0);
			zephir_check_call_status();
			object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
			ZEPHIR_INIT_NVAR(_22$$18);
			ZVAL_BOOL(_22$$18, 0);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 375, _22$$18, record);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(NULL, records, "next", &_23, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZEPHIR_INIT_VAR(_24);
	ZVAL_BOOL(_24, 1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 375, _24);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Executes the DELETE intermediate representation producing a Phalcon\Mvc\Model\Query\Status
 *
 * @param array intermediate
 * @param array bindParams
 * @param array bindTypes
 * @return \Phalcon\Mvc\Model\Query\StatusInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeDelete) {

	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate, *bindParams, *bindTypes, *models = NULL, *modelName = NULL, *model = NULL, *records = NULL, *connection = NULL, *record = NULL, *_0, *_3 = NULL, *_9, *_1$$4, *_2$$5, *_5$$6 = NULL, *_7$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_OBS_VAR(models);
	zephir_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 3178 TSRMLS_CC);
	if (zephir_array_isset_long(models, 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Delete from several models at the same time is still not supported", "phalcon/mvc/model/query.zep", 3181);
		return;
	}
	ZEPHIR_OBS_VAR(modelName);
	zephir_array_fetch_long(&modelName, models, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 3184 TSRMLS_CC);
	ZEPHIR_OBS_VAR(model);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&model, _0, modelName, 0 TSRMLS_CC))) {
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&model, _1$$4, "load", NULL, 0, modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", NULL, 376, model, intermediate, bindParams, bindTypes);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(records TSRMLS_CC))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		ZEPHIR_INIT_VAR(_2$$5);
		ZVAL_BOOL(_2$$5, 1);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 375, _2$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, model, intermediate, bindParams, bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, records, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_3, records, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_3))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&record, records, "current", &_4, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$6, record, "delete", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_5$$6))) {
			ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_6, 0);
			zephir_check_call_status();
			object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
			ZEPHIR_INIT_NVAR(_7$$7);
			ZVAL_BOOL(_7$$7, 0);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 375, _7$$7, record);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(NULL, records, "next", &_8, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_BOOL(_9, 1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 375, _9);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Query the records on which the UPDATE/DELETE operation well be done
 *
 * @param \Phalcon\Mvc\ModelInterface model
 * @param array intermediate
 * @param array bindParams
 * @param array bindTypes
 * @return \Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getRelatedRecords) {

	zval *_0, *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, *intermediate, *bindParams, *bindTypes, *selectIr = NULL, *whereConditions = NULL, *limitConditions = NULL, *query = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &model, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_INIT_VAR(selectIr);
	zephir_create_array(selectIr, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("type"), SL("object"), 1);
	ZEPHIR_INIT_VAR(_2);
	zephir_get_class(_2, model, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("model"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, model, "getsource", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("column"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_fast_append(_0, _1);
	zephir_array_update_string(&selectIr, SL("columns"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_4);
	zephir_array_fetch_string(&_4, intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 3267 TSRMLS_CC);
	zephir_array_update_string(&selectIr, SL("models"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_4);
	zephir_array_fetch_string(&_4, intermediate, SL("tables"), PH_NOISY, "phalcon/mvc/model/query.zep", 3269 TSRMLS_CC);
	zephir_array_update_string(&selectIr, SL("tables"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(whereConditions);
	if (zephir_array_isset_string_fetch(&whereConditions, intermediate, SS("where"), 0 TSRMLS_CC)) {
		zephir_array_update_string(&selectIr, SL("where"), &whereConditions, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(limitConditions);
	if (zephir_array_isset_string_fetch(&limitConditions, intermediate, SS("limit"), 0 TSRMLS_CC)) {
		zephir_array_update_string(&selectIr, SL("limit"), &limitConditions, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	ZEPHIR_CALL_METHOD(NULL, query, "__construct", NULL, 377);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, query, "setdi", NULL, 378, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 309);
	ZEPHIR_CALL_METHOD(NULL, query, "settype", NULL, 379, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, query, "setintermediate", NULL, 380, selectIr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(query, "execute", NULL, 381, bindParams, bindTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Executes a parsed PHQL statement
 *
 * @param array bindParams
 * @param array bindTypes
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, execute) {

	zend_bool _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bindParams = NULL, *bindTypes = NULL, *uniqueRow = NULL, *cacheOptions = NULL, *key = NULL, *cacheService = NULL, *cache = NULL, *result = NULL, *preparedResult = NULL, *defaultBindParams = NULL, *mergedParams = NULL, *defaultBindTypes = NULL, *mergedTypes = NULL, *type = NULL, *lifetime = NULL, *intermediate = NULL, *_0$$3, *_1$$9, *_4$$27, *_5$$27;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &bindParams, &bindTypes);

	if (!bindParams) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(uniqueRow);
	zephir_read_property_this(&uniqueRow, this_ptr, SL("_uniqueRow"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(cacheOptions);
	zephir_read_property_this(&cacheOptions, this_ptr, SL("_cacheOptions"), PH_NOISY_CC);
	if (Z_TYPE_P(cacheOptions) != IS_NULL) {
		if (Z_TYPE_P(cacheOptions) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid caching options", "phalcon/mvc/model/query.zep", 3315);
			return;
		}
		ZEPHIR_OBS_VAR(key);
		if (!(zephir_array_isset_string_fetch(&key, cacheOptions, SS("key"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A cache key must be provided to identify the cached resultset in the cache backend", "phalcon/mvc/model/query.zep", 3322);
			return;
		}
		ZEPHIR_OBS_VAR(lifetime);
		if (!(zephir_array_isset_string_fetch(&lifetime, cacheOptions, SS("lifetime"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(lifetime);
			ZVAL_LONG(lifetime, 3600);
		}
		ZEPHIR_OBS_VAR(cacheService);
		if (!(zephir_array_isset_string_fetch(&cacheService, cacheOptions, SS("service"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(cacheService);
			ZVAL_STRING(cacheService, "modelsCache", 1);
		}
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&cache, _0$$3, "getshared", NULL, 0, cacheService);
		zephir_check_call_status();
		if (Z_TYPE_P(cache) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cache service must be an object", "phalcon/mvc/model/query.zep", 3341);
			return;
		}
		ZEPHIR_CALL_METHOD(&result, cache, "get", NULL, 0, key, lifetime);
		zephir_check_call_status();
		if (Z_TYPE_P(result) != IS_NULL) {
			if (Z_TYPE_P(result) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cache didn't return a valid resultset", "phalcon/mvc/model/query.zep", 3348);
				return;
			}
			ZEPHIR_INIT_VAR(_1$$9);
			ZVAL_BOOL(_1$$9, 0);
			ZEPHIR_CALL_METHOD(NULL, result, "setisfresh", NULL, 0, _1$$9);
			zephir_check_call_status();
			if (zephir_is_true(uniqueRow)) {
				ZEPHIR_CALL_METHOD(&preparedResult, result, "getfirst", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(preparedResult, result);
			}
			RETURN_CCTOR(preparedResult);
		}
		zephir_update_property_this(getThis(), SL("_cache"), cache TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(defaultBindParams);
	zephir_read_property_this(&defaultBindParams, this_ptr, SL("_bindParams"), PH_NOISY_CC);
	if (Z_TYPE_P(defaultBindParams) == IS_ARRAY) {
		if (Z_TYPE_P(bindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_add_function(mergedParams, defaultBindParams, bindParams);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, defaultBindParams);
		}
	} else {
		ZEPHIR_CPY_WRT(mergedParams, bindParams);
	}
	zephir_update_property_this(getThis(), SL("_bindParams"), mergedParams TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&intermediate, this_ptr, "parse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(defaultBindTypes);
	zephir_read_property_this(&defaultBindTypes, this_ptr, SL("_bindTypes"), PH_NOISY_CC);
	if (Z_TYPE_P(defaultBindTypes) == IS_ARRAY) {
		if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedTypes);
			zephir_add_function(mergedTypes, defaultBindTypes, bindTypes);
		} else {
			ZEPHIR_CPY_WRT(mergedTypes, defaultBindTypes);
		}
	} else {
		ZEPHIR_CPY_WRT(mergedTypes, bindTypes);
	}
	_2 = Z_TYPE_P(mergedParams) != IS_NULL;
	if (_2) {
		_2 = Z_TYPE_P(mergedParams) != IS_ARRAY;
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameters must be an array", "phalcon/mvc/model/query.zep", 3404);
		return;
	}
	_3 = Z_TYPE_P(mergedTypes) != IS_NULL;
	if (_3) {
		_3 = Z_TYPE_P(mergedTypes) != IS_ARRAY;
	}
	if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameter types must be an array", "phalcon/mvc/model/query.zep", 3408);
		return;
	}
	ZEPHIR_OBS_VAR(type);
	zephir_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(type, 309)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executeselect", NULL, 382, intermediate, mergedParams, mergedTypes);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(type, 306)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executeinsert", NULL, 383, intermediate, mergedParams, mergedTypes);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(type, 300)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executeupdate", NULL, 384, intermediate, mergedParams, mergedTypes);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(type, 303)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executedelete", NULL, 385, intermediate, mergedParams, mergedTypes);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_VAR(_4$$27);
		object_init_ex(_4$$27, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_5$$27);
		ZEPHIR_CONCAT_SV(_5$$27, "Unknown statement ", type);
		ZEPHIR_CALL_METHOD(NULL, _4$$27, "__construct", NULL, 9, _5$$27);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$27, "phalcon/mvc/model/query.zep", 3431 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	if (Z_TYPE_P(cacheOptions) != IS_NULL) {
		if (!ZEPHIR_IS_LONG(type, 309)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only PHQL statements that return resultsets can be cached", "phalcon/mvc/model/query.zep", 3443);
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, cache, "save", NULL, 0, key, result, lifetime);
		zephir_check_call_status();
	}
	if (zephir_is_true(uniqueRow)) {
		ZEPHIR_CALL_METHOD(&preparedResult, result, "getfirst", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(preparedResult, result);
	}
	RETURN_CCTOR(preparedResult);

}

/**
 * Executes the query returning the first result
 *
 * @param array bindParams
 * @param array bindTypes
 * @return \Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getSingleResult) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bindParams = NULL, *bindTypes = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &bindParams, &bindTypes);

	if (!bindParams) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueRow"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, bindParams, bindTypes);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "execute", NULL, 381, bindParams, bindTypes);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_1, "getfirst", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the type of PHQL statement to be executed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setType) {

	zval *type_param = NULL, *_0;
	zend_long type;

	zephir_fetch_params(0, 1, 0, &type_param);

	type = zephir_get_intval(type_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, type);
	zephir_update_property_this(getThis(), SL("_type"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Gets the type of PHQL statement executed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getType) {

	

	RETURN_MEMBER(getThis(), "_type");

}

/**
 * Set default bind parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindParams) {

	zend_bool merge;
	zval *bindParams_param = NULL, *merge_param = NULL, *currentBindParams = NULL, *_0$$4;
	zval *bindParams = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &bindParams_param, &merge_param);

	bindParams = bindParams_param;
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		currentBindParams = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
		if (Z_TYPE_P(currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_0$$4);
			zephir_add_function(_0$$4, currentBindParams, bindParams);
			zephir_update_property_this(getThis(), SL("_bindParams"), _0$$4 TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_bindParams"), bindParams TSRMLS_CC);
		}
	} else {
		zephir_update_property_this(getThis(), SL("_bindParams"), bindParams TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Returns default bind params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindParams) {

	

	RETURN_MEMBER(getThis(), "_bindParams");

}

/**
 * Set default bind parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindTypes) {

	zend_bool merge;
	zval *bindTypes_param = NULL, *merge_param = NULL, *currentBindTypes = NULL, *_0$$4;
	zval *bindTypes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &bindTypes_param, &merge_param);

	bindTypes = bindTypes_param;
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (UNEXPECTED(merge)) {
		currentBindTypes = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
		if (Z_TYPE_P(currentBindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_0$$4);
			zephir_add_function(_0$$4, currentBindTypes, bindTypes);
			zephir_update_property_this(getThis(), SL("_bindTypes"), _0$$4 TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_bindTypes"), bindTypes TSRMLS_CC);
		}
	} else {
		zephir_update_property_this(getThis(), SL("_bindTypes"), bindTypes TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Set SHARED LOCK clause
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setSharedLock) {

	zval *sharedLock_param = NULL;
	zend_bool sharedLock;

	zephir_fetch_params(0, 0, 1, &sharedLock_param);

	if (!sharedLock_param) {
		sharedLock = 0;
	} else {
		sharedLock = zephir_get_boolval(sharedLock_param);
	}


	if (sharedLock) {
		zephir_update_property_this(getThis(), SL("_sharedLock"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_sharedLock"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Returns default bind types
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindTypes) {

	

	RETURN_MEMBER(getThis(), "_bindTypes");

}

/**
 * Allows to set the IR to be executed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setIntermediate) {

	zval *intermediate_param = NULL;
	zval *intermediate = NULL;

	zephir_fetch_params(0, 1, 0, &intermediate_param);

	intermediate = intermediate_param;


	zephir_update_property_this(getThis(), SL("_intermediate"), intermediate TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the intermediate representation of the PHQL statement
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getIntermediate) {

	

	RETURN_MEMBER(getThis(), "_intermediate");

}

/**
 * Sets the cache parameters of the query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, cache) {

	zval *cacheOptions;

	zephir_fetch_params(0, 1, 0, &cacheOptions);



	zephir_update_property_this(getThis(), SL("_cacheOptions"), cacheOptions TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the current cache options
 *
 * @param array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getCacheOptions) {

	

	RETURN_MEMBER(getThis(), "_cacheOptions");

}

/**
 * Returns the SQL to be generated by the internal PHQL (only works in SELECT statements)
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getSql) {

	zval *intermediate = NULL, *_0, *_1$$3, *_2$$3, *_3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&intermediate, this_ptr, "parse", NULL, 0);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_0, 309)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_BOOL(_3$$3, 1);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_executeselect", NULL, 382, intermediate, _1$$3, _2$$3, _3$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "This type of statement generates multiple SQL statements", "phalcon/mvc/model/query.zep", 3623);
	return;

}

/**
 * Destroys the internal PHQL cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, clean) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(phalcon_mvc_model_query_ce, SL("_irPhqlCache"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the read connection from the model if there is no transaction set inside the query object
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getReadConnection) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate = NULL, *bindParams = NULL, *bindTypes = NULL;
	zval *model, *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, *connection = NULL, *transaction = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &model, &intermediate_param, &bindParams_param, &bindTypes_param);

	if (!intermediate_param) {
		ZEPHIR_INIT_VAR(intermediate);
		array_init(intermediate);
	} else {
		zephir_get_arrval(intermediate, intermediate_param);
	}
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(bindParams);
		array_init(bindParams);
	} else {
		zephir_get_arrval(bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(bindTypes);
		array_init(bindTypes);
	} else {
		zephir_get_arrval(bindTypes, bindTypes_param);
	}


	ZEPHIR_INIT_VAR(connection);
	ZVAL_NULL(connection);
	ZEPHIR_OBS_VAR(transaction);
	zephir_read_property_this(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	_0 = Z_TYPE_P(transaction) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(transaction, phalcon_mvc_model_transactioninterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(model, SS("selectreadconnection") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&connection, model, "selectreadconnection", NULL, 0, intermediate, bindParams, bindTypes);
		zephir_check_call_status();
		if (Z_TYPE_P(connection) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "selectReadConnection did not return a connection", "phalcon/mvc/model/query.zep", 3650);
			return;
		}
		RETURN_CCTOR(connection);
	}
	ZEPHIR_RETURN_CALL_METHOD(model, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets the write connection from the model if there is no transaction inside the query object
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getWriteConnection) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate = NULL, *bindParams = NULL, *bindTypes = NULL;
	zval *model, *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, *connection = NULL, *transaction = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &model, &intermediate_param, &bindParams_param, &bindTypes_param);

	if (!intermediate_param) {
		ZEPHIR_INIT_VAR(intermediate);
		array_init(intermediate);
	} else {
		zephir_get_arrval(intermediate, intermediate_param);
	}
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(bindParams);
		array_init(bindParams);
	} else {
		zephir_get_arrval(bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(bindTypes);
		array_init(bindTypes);
	} else {
		zephir_get_arrval(bindTypes, bindTypes_param);
	}


	ZEPHIR_INIT_VAR(connection);
	ZVAL_NULL(connection);
	ZEPHIR_OBS_VAR(transaction);
	zephir_read_property_this(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	_0 = Z_TYPE_P(transaction) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(transaction, phalcon_mvc_model_transactioninterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(model, SS("selectwriteconnection") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&connection, model, "selectwriteconnection", NULL, 0, intermediate, bindParams, bindTypes);
		zephir_check_call_status();
		if (Z_TYPE_P(connection) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "selectWriteConnection did not return a connection", "phalcon/mvc/model/query.zep", 3673);
			return;
		}
		RETURN_CCTOR(connection);
	}
	ZEPHIR_RETURN_CALL_METHOD(model, "getwriteconnection", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * allows to wrap a transaction around all queries
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setTransaction) {

	zval *transaction;

	zephir_fetch_params(0, 1, 0, &transaction);



	zephir_update_property_this(getThis(), SL("_transaction"), transaction TSRMLS_CC);
	RETURN_THISW();

}

