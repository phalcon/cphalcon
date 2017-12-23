
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

	zephir_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_SELECT"), 309);

	zephir_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_INSERT"), 306);

	zephir_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_UPDATE"), 300);

	zephir_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_DELETE"), 303);

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

	zval *this_ptr = getThis();


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
	zval *phql = NULL, phql_sub, *dependencyInjector = NULL, dependencyInjector_sub, *options = NULL, options_sub, __$true, __$false, __$null, enableImplicitJoins;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&phql_sub);
	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&enableImplicitJoins);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &phql, &dependencyInjector, &options);

	if (!phql) {
		phql = &phql_sub;
		phql = &__$null;
	}
	if (!dependencyInjector) {
		dependencyInjector = &dependencyInjector_sub;
		dependencyInjector = &__$null;
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	if (Z_TYPE_P(phql) != IS_NULL) {
		zephir_update_property_zval(this_ptr, SL("_phql"), phql);
	}
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, dependencyInjector);
		zephir_check_call_status();
	}
	_0 = Z_TYPE_P(options) == IS_ARRAY;
	if (_0) {
		ZEPHIR_OBS_VAR(&enableImplicitJoins);
		_0 = zephir_array_isset_string_fetch(&enableImplicitJoins, options, SL("enable_implicit_joins"), 0);
	}
	if (_0) {
		if (ZEPHIR_IS_TRUE(&enableImplicitJoins)) {
			zephir_update_property_zval(this_ptr, SL("_enableImplicitJoins"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_enableImplicitJoins"), &__$false);
		}
	} else {
		if (ZEPHIR_GLOBAL(orm).enable_implicit_joins) {
			zephir_update_property_zval(this_ptr, SL("_enableImplicitJoins"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_enableImplicitJoins"), &__$false);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setDI) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dependencyInjector, dependencyInjector_sub, manager, metaData, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dependencyInjector);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "modelsManager");
	ZEPHIR_CALL_METHOD(&manager, dependencyInjector, "getshared", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&manager) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Injected service 'modelsManager' is invalid", "phalcon/mvc/model/query.zep", 192);
		return;
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "modelsMetadata");
	ZEPHIR_CALL_METHOD(&metaData, dependencyInjector, "getshared", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&metaData) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Injected service 'modelsMetaData' is invalid", "phalcon/mvc/model/query.zep", 197);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_manager"), &manager);
	zephir_update_property_zval(this_ptr, SL("_metaData"), &metaData);
	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Tells to the query if only the first row in the resultset must be returned
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setUniqueRow) {

	zval *uniqueRow_param = NULL, __$true, __$false;
	zend_bool uniqueRow;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &uniqueRow_param);

	uniqueRow = zephir_get_boolval(uniqueRow_param);


	if (uniqueRow) {
		zephir_update_property_zval(this_ptr, SL("_uniqueRow"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_uniqueRow"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Check if the query is programmed to get only the first row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getUniqueRow) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_uniqueRow");

}

/**
 * Replaces the model's name to its source name in a qualified-name expression
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getQualified) {

	zend_bool _0, _1;
	zephir_fcall_cache_entry *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, number = 0;
	zval *expr_param = NULL, columnName, sqlColumnAliases, metaData, sqlAliases, source, sqlAliasesModelsInstances, realColumnName, columnDomain, model, models, columnMap, hasModel, className, _2, _3$$5, _4$$5, _5$$5, _6$$7, _7$$7, _8$$7, _9$$10, _10$$10, _11$$10, _12$$12, *_13$$12, _14$$13, _16$$15, _17$$15, _18$$15, _19$$16, _20$$16, _21$$16, _22$$18, _23$$18, _24$$18, _25$$22, _26$$22, _27$$22;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&sqlColumnAliases);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&sqlAliases);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&sqlAliasesModelsInstances);
	ZVAL_UNDEF(&realColumnName);
	ZVAL_UNDEF(&columnDomain);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&hasModel);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_23$$18);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_25$$22);
	ZVAL_UNDEF(&_26$$22);
	ZVAL_UNDEF(&_27$$22);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);


	ZEPHIR_OBS_VAR(&columnName);
	zephir_array_fetch_string(&columnName, &expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 241 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&sqlColumnAliases);
	zephir_read_property(&sqlColumnAliases, this_ptr, SL("_sqlColumnAliases"), PH_NOISY_CC);
	_0 = zephir_array_isset(&sqlColumnAliases, &columnName);
	if (_0) {
		_1 = !(zephir_array_isset_string(&expr, SL("domain")));
		if (!(_1)) {
			zephir_array_fetch_string(&_2, &expr, SL("domain"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 247 TSRMLS_CC);
			_1 = ZEPHIR_IS_EMPTY(&_2);
		}
		_0 = _1;
	}
	if (_0) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		add_assoc_stringl_ex(return_value, SL("type"), SL("qualified"));
		zephir_array_update_string(return_value, SL("name"), &columnName, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&metaData);
	zephir_read_property(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&columnDomain);
	if (zephir_array_isset_string_fetch(&columnDomain, &expr, SL("domain"), 0)) {
		ZEPHIR_OBS_VAR(&sqlAliases);
		zephir_read_property(&sqlAliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&source);
		if (!(zephir_array_isset_fetch(&source, &sqlAliases, &columnDomain, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(&_3$$5);
			object_init_ex(&_3$$5, phalcon_mvc_model_exception_ce);
			zephir_read_property(&_4$$5, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_5$$5);
			ZEPHIR_CONCAT_SVSV(&_5$$5, "Unknown model or alias '", &columnDomain, "' (11), when preparing: ", &_4$$5);
			ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 4, &_5$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$5, "phalcon/mvc/model/query.zep", 267 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_OBS_VAR(&sqlAliasesModelsInstances);
			zephir_read_property(&sqlAliasesModelsInstances, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
			ZEPHIR_OBS_VAR(&model);
			if (!(zephir_array_isset_fetch(&model, &sqlAliasesModelsInstances, &columnDomain, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(&_6$$7);
				object_init_ex(&_6$$7, phalcon_mvc_model_exception_ce);
				zephir_read_property(&_7$$7, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_8$$7);
				ZEPHIR_CONCAT_SVSV(&_8$$7, "There is no model related to model or alias '", &columnDomain, "', when executing: ", &_7$$7);
				ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", NULL, 4, &_8$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$7, "phalcon/mvc/model/query.zep", 286 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getreversecolumnmap", NULL, 0, &model);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(&realColumnName);
			if (!(zephir_array_isset_fetch(&realColumnName, &columnMap, &columnName, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(&_9$$10);
				object_init_ex(&_9$$10, phalcon_mvc_model_exception_ce);
				zephir_read_property(&_10$$10, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_11$$10);
				ZEPHIR_CONCAT_SVSVSV(&_11$$10, "Column '", &columnName, "' doesn't belong to the model or alias '", &columnDomain, "', when executing: ", &_10$$10);
				ZEPHIR_CALL_METHOD(NULL, &_9$$10, "__construct", NULL, 4, &_11$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_9$$10, "phalcon/mvc/model/query.zep", 298 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&realColumnName, &columnName);
		}
	} else {
		number = 0;
		ZEPHIR_INIT_VAR(&hasModel);
		ZVAL_BOOL(&hasModel, 0);
		zephir_read_property(&_12$$12, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_12$$12, 0, "phalcon/mvc/model/query.zep", 328);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_12$$12), _13$$12)
		{
			ZEPHIR_INIT_NVAR(&model);
			ZVAL_COPY(&model, _13$$12);
			ZEPHIR_CALL_METHOD(&_14$$13, &metaData, "hasattribute", &_15, 0, &model, &columnName);
			zephir_check_call_status();
			if (zephir_is_true(&_14$$13)) {
				number++;
				if (number > 1) {
					ZEPHIR_INIT_NVAR(&_16$$15);
					object_init_ex(&_16$$15, phalcon_mvc_model_exception_ce);
					zephir_read_property(&_17$$15, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_LNVAR(_18$$15);
					ZEPHIR_CONCAT_SVSV(&_18$$15, "The column '", &columnName, "' is ambiguous, when preparing: ", &_17$$15);
					ZEPHIR_CALL_METHOD(NULL, &_16$$15, "__construct", NULL, 4, &_18$$15);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_16$$15, "phalcon/mvc/model/query.zep", 319 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&hasModel, &model);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&model);
		if (ZEPHIR_IS_FALSE_IDENTICAL(&hasModel)) {
			ZEPHIR_INIT_VAR(&_19$$16);
			object_init_ex(&_19$$16, phalcon_mvc_model_exception_ce);
			zephir_read_property(&_20$$16, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_21$$16);
			ZEPHIR_CONCAT_SVSV(&_21$$16, "Column '", &columnName, "' doesn't belong to any of the selected models (1), when preparing: ", &_20$$16);
			ZEPHIR_CALL_METHOD(NULL, &_19$$16, "__construct", NULL, 4, &_21$$16);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_19$$16, "phalcon/mvc/model/query.zep", 331 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(&models);
		zephir_read_property(&models, this_ptr, SL("_models"), PH_NOISY_CC);
		if (Z_TYPE_P(&models) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The models list was not loaded correctly", "phalcon/mvc/model/query.zep", 339);
			return;
		}
		ZEPHIR_INIT_VAR(&className);
		zephir_get_class(&className, &hasModel, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&source);
		if (!(zephir_array_isset_fetch(&source, &models, &className, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(&_22$$18);
			object_init_ex(&_22$$18, phalcon_mvc_model_exception_ce);
			zephir_read_property(&_23$$18, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_24$$18);
			ZEPHIR_CONCAT_SVSV(&_24$$18, "Can't obtain model's source from models list: '", &className, "', when preparing: ", &_23$$18);
			ZEPHIR_CALL_METHOD(NULL, &_22$$18, "__construct", NULL, 4, &_24$$18);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_22$$18, "phalcon/mvc/model/query.zep", 349 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getreversecolumnmap", NULL, 0, &hasModel);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&realColumnName);
			if (!(zephir_array_isset_fetch(&realColumnName, &columnMap, &columnName, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(&_25$$22);
				object_init_ex(&_25$$22, phalcon_mvc_model_exception_ce);
				zephir_read_property(&_26$$22, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_27$$22);
				ZEPHIR_CONCAT_SVSV(&_27$$22, "Column '", &columnName, "' doesn't belong to any of the selected models (3), when preparing: ", &_26$$22);
				ZEPHIR_CALL_METHOD(NULL, &_25$$22, "__construct", NULL, 4, &_27$$22);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_25$$22, "phalcon/mvc/model/query.zep", 368 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&realColumnName, &columnName);
		}
	}
	zephir_create_array(return_value, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SL("type"), SL("qualified"));
	zephir_array_update_string(return_value, SL("domain"), &source, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("name"), &realColumnName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("balias"), &columnName, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Resolves an expression in a single call argument
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCallArgument) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argument_param = NULL, _0;
	zval argument;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &argument_param);

	ZEPHIR_OBS_COPY_OR_DUP(&argument, argument_param);


	zephir_array_fetch_string(&_0, &argument, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 391 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&_0, 352)) {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		add_assoc_stringl_ex(return_value, SL("type"), SL("all"));
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getexpression", NULL, 316, &argument);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Resolves an expression in a single call argument
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCaseExpression) {

	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, whenClauses, whenExpr, _0, *_1, _10, _11, _3$$4, _4$$4, _6$$4, _8$$5, _9$$5;
	zval expr, _2$$4, _7$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&whenClauses);
	ZVAL_UNDEF(&whenExpr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);


	ZEPHIR_INIT_VAR(&whenClauses);
	array_init(&whenClauses);
	zephir_array_fetch_string(&_0, &expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 405 TSRMLS_CC);
	zephir_is_iterable(&_0, 0, "phalcon/mvc/model/query.zep", 420);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&whenExpr);
		ZVAL_COPY(&whenExpr, _1);
		if (zephir_array_isset_string(&whenExpr, SL("right"))) {
			ZEPHIR_INIT_NVAR(&_2$$4);
			zephir_create_array(&_2$$4, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_2$$4, SL("type"), SL("when"));
			zephir_array_fetch_string(&_4$$4, &whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 409 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "_getexpression", &_5, 316, &_4$$4);
			zephir_check_call_status();
			zephir_array_update_string(&_2$$4, SL("expr"), &_3$$4, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_6$$4, &whenExpr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 410 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "_getexpression", &_5, 316, &_6$$4);
			zephir_check_call_status();
			zephir_array_update_string(&_2$$4, SL("then"), &_3$$4, PH_COPY | PH_SEPARATE);
			zephir_array_append(&whenClauses, &_2$$4, PH_SEPARATE, "phalcon/mvc/model/query.zep", 411);
		} else {
			ZEPHIR_INIT_NVAR(&_7$$5);
			zephir_create_array(&_7$$5, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_7$$5, SL("type"), SL("else"));
			zephir_array_fetch_string(&_9$$5, &whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 415 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_8$$5, this_ptr, "_getexpression", &_5, 316, &_9$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_7$$5, SL("expr"), &_8$$5, PH_COPY | PH_SEPARATE);
			zephir_array_append(&whenClauses, &_7$$5, PH_SEPARATE, "phalcon/mvc/model/query.zep", 416);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&whenExpr);
	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SL("type"), SL("case"));
	zephir_array_fetch_string(&_11, &expr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 422 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "_getexpression", &_5, 316, &_11);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("expr"), &_10, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("when-clauses"), &whenClauses, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Resolves an expression in a single call argument
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getFunctionCall) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, distinct = 0;
	zval *expr_param = NULL, arguments, argument, functionArgs, _7, *_0$$6, _1$$7, _3$$8, _4$$9, _5$$9, _6$$10;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&functionArgs);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);


	ZEPHIR_OBS_VAR(&arguments);
	if (zephir_array_isset_string_fetch(&arguments, &expr, SL("arguments"), 0)) {
		if (zephir_array_isset_string(&expr, SL("distinct"))) {
			distinct = 1;
		} else {
			distinct = 0;
		}
		ZEPHIR_INIT_VAR(&functionArgs);
		if (zephir_array_isset_long(&arguments, 0)) {
			array_init(&functionArgs);
			zephir_is_iterable(&arguments, 0, "phalcon/mvc/model/query.zep", 448);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arguments), _0$$6)
			{
				ZEPHIR_INIT_NVAR(&argument);
				ZVAL_COPY(&argument, _0$$6);
				ZEPHIR_CALL_METHOD(&_1$$7, this_ptr, "_getcallargument", &_2, 317, &argument);
				zephir_check_call_status();
				zephir_array_append(&functionArgs, &_1$$7, PH_SEPARATE, "phalcon/mvc/model/query.zep", 446);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&argument);
		} else {
			zephir_create_array(&functionArgs, 1, 0 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3$$8, this_ptr, "_getcallargument", &_2, 317, &arguments);
			zephir_check_call_status();
			zephir_array_fast_append(&functionArgs, &_3$$8);
		}
		if (distinct) {
			zephir_create_array(return_value, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
			ZEPHIR_OBS_VAR(&_4$$9);
			zephir_array_fetch_string(&_4$$9, &expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 456 TSRMLS_CC);
			zephir_array_update_string(return_value, SL("name"), &_4$$9, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_5$$9);
			ZVAL_LONG(&_5$$9, distinct);
			zephir_array_update_string(return_value, SL("distinct"), &_5$$9, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		} else {
			zephir_create_array(return_value, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
			ZEPHIR_OBS_VAR(&_6$$10);
			zephir_array_fetch_string(&_6$$10, &expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 463 TSRMLS_CC);
			zephir_array_update_string(return_value, SL("name"), &_6$$10, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
	ZEPHIR_OBS_VAR(&_7);
	zephir_array_fetch_string(&_7, &expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 472 TSRMLS_CC);
	zephir_array_update_string(return_value, SL("name"), &_7, PH_COPY | PH_SEPARATE);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool quoting, tempNotQuoting = 0;
	zval *expr, expr_sub, *quoting_param = NULL, exprType, exprLeft, exprRight, left, right, listItems, exprListItem, exprReturn, value, escapedValue, exprValue, valueParts, name, bindType, bind, _0$$5, _1$$6, _2$$25, _3$$33, _4$$33, _5$$33, _6$$33, _7$$34, _8$$34, _9$$37, _10$$37, _11$$38, _12$$38, _13$$39, _14$$39, _15$$40, _16$$40, _17$$41, _18$$41, _19$$42, _20$$42, _21$$43, _28$$43, _22$$44, _23$$44, _24$$45, _25$$45, _26$$46, _27$$46, _29$$47, _30$$47, _31$$48, _32$$65, _33$$68, _34$$68, _35$$69, _36$$69, *_37$$71, _38$$72;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr_sub);
	ZVAL_UNDEF(&exprType);
	ZVAL_UNDEF(&exprLeft);
	ZVAL_UNDEF(&exprRight);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&listItems);
	ZVAL_UNDEF(&exprListItem);
	ZVAL_UNDEF(&exprReturn);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&escapedValue);
	ZVAL_UNDEF(&exprValue);
	ZVAL_UNDEF(&valueParts);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$25);
	ZVAL_UNDEF(&_3$$33);
	ZVAL_UNDEF(&_4$$33);
	ZVAL_UNDEF(&_5$$33);
	ZVAL_UNDEF(&_6$$33);
	ZVAL_UNDEF(&_7$$34);
	ZVAL_UNDEF(&_8$$34);
	ZVAL_UNDEF(&_9$$37);
	ZVAL_UNDEF(&_10$$37);
	ZVAL_UNDEF(&_11$$38);
	ZVAL_UNDEF(&_12$$38);
	ZVAL_UNDEF(&_13$$39);
	ZVAL_UNDEF(&_14$$39);
	ZVAL_UNDEF(&_15$$40);
	ZVAL_UNDEF(&_16$$40);
	ZVAL_UNDEF(&_17$$41);
	ZVAL_UNDEF(&_18$$41);
	ZVAL_UNDEF(&_19$$42);
	ZVAL_UNDEF(&_20$$42);
	ZVAL_UNDEF(&_21$$43);
	ZVAL_UNDEF(&_28$$43);
	ZVAL_UNDEF(&_22$$44);
	ZVAL_UNDEF(&_23$$44);
	ZVAL_UNDEF(&_24$$45);
	ZVAL_UNDEF(&_25$$45);
	ZVAL_UNDEF(&_26$$46);
	ZVAL_UNDEF(&_27$$46);
	ZVAL_UNDEF(&_29$$47);
	ZVAL_UNDEF(&_30$$47);
	ZVAL_UNDEF(&_31$$48);
	ZVAL_UNDEF(&_32$$65);
	ZVAL_UNDEF(&_33$$68);
	ZVAL_UNDEF(&_34$$68);
	ZVAL_UNDEF(&_35$$69);
	ZVAL_UNDEF(&_36$$69);
	ZVAL_UNDEF(&_38$$72);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expr, &quoting_param);

	if (!quoting_param) {
		quoting = 1;
	} else {
		quoting = zephir_get_boolval(quoting_param);
	}


	ZEPHIR_INIT_VAR(&left);
	ZVAL_NULL(&left);
	ZEPHIR_INIT_VAR(&right);
	ZVAL_NULL(&right);
	ZEPHIR_OBS_VAR(&exprType);
	if (zephir_array_isset_string_fetch(&exprType, expr, SL("type"), 0)) {
		tempNotQuoting = 1;
		if (!ZEPHIR_IS_LONG(&exprType, 409)) {
			ZEPHIR_OBS_VAR(&exprLeft);
			if (zephir_array_isset_string_fetch(&exprLeft, expr, SL("left"), 0)) {
				if (tempNotQuoting) {
					ZVAL_BOOL(&_0$$5, 1);
				} else {
					ZVAL_BOOL(&_0$$5, 0);
				}
				ZEPHIR_CALL_METHOD(&left, this_ptr, "_getexpression", NULL, 316, &exprLeft, &_0$$5);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_VAR(&exprRight);
			if (zephir_array_isset_string_fetch(&exprRight, expr, SL("right"), 0)) {
				if (tempNotQuoting) {
					ZVAL_BOOL(&_1$$6, 1);
				} else {
					ZVAL_BOOL(&_1$$6, 0);
				}
				ZEPHIR_CALL_METHOD(&right, this_ptr, "_getexpression", NULL, 316, &exprRight, &_1$$6);
				zephir_check_call_status();
			}
		}
		do {
			if (ZEPHIR_IS_LONG(&exprType, '<')) {
				ZEPHIR_INIT_VAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("<"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '=')) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("="));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '>')) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL(">"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 270)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("<>"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 271)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("<="));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 272)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL(">="));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 266)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("AND"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 267)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("OR"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 355)) {
				ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "_getqualified", NULL, 318, expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '+')) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("+"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '-')) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("-"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '*')) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("*"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '/')) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("/"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '%')) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("%"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '&')) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("&"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '|')) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("|"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 356) || ZEPHIR_IS_LONG(&exprType, 407)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("parentheses"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 367)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("-"));
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 258) || ZEPHIR_IS_LONG(&exprType, 259) || ZEPHIR_IS_LONG(&exprType, 414)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("literal"));
				ZEPHIR_OBS_VAR(&_2$$25);
				zephir_array_fetch_string(&_2$$25, expr, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 590 TSRMLS_CC);
				zephir_array_update_string(&exprReturn, SL("value"), &_2$$25, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 333)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("literal"));
				add_assoc_stringl_ex(&exprReturn, SL("value"), SL("TRUE"));
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 334)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("literal"));
				add_assoc_stringl_ex(&exprReturn, SL("value"), SL("FALSE"));
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 260)) {
				ZEPHIR_OBS_VAR(&value);
				zephir_array_fetch_string(&value, expr, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 602 TSRMLS_CC);
				if (quoting == 1) {
					if (zephir_memnstr_str(&value, SL("'"), "phalcon/mvc/model/query.zep", 607)) {
						ZEPHIR_INIT_VAR(&escapedValue);
						phalcon_orm_singlequotes(&escapedValue, &value TSRMLS_CC);
					} else {
						ZEPHIR_CPY_WRT(&escapedValue, &value);
					}
					ZEPHIR_INIT_VAR(&exprValue);
					ZEPHIR_CONCAT_SVS(&exprValue, "'", &escapedValue, "'");
				} else {
					ZEPHIR_CPY_WRT(&exprValue, &value);
				}
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("literal"));
				zephir_array_update_string(&exprReturn, SL("value"), &exprValue, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 273)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("placeholder"));
				ZEPHIR_INIT_VAR(&_3$$33);
				zephir_array_fetch_string(&_4$$33, expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 620 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_5$$33);
				ZVAL_STRING(&_5$$33, "?");
				ZEPHIR_INIT_VAR(&_6$$33);
				ZVAL_STRING(&_6$$33, ":");
				zephir_fast_str_replace(&_3$$33, &_5$$33, &_6$$33, &_4$$33 TSRMLS_CC);
				zephir_array_update_string(&exprReturn, SL("value"), &_3$$33, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 274)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("placeholder"));
				zephir_array_fetch_string(&_7$$34, expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 624 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_8$$34);
				ZEPHIR_CONCAT_SV(&_8$$34, ":", &_7$$34);
				zephir_array_update_string(&exprReturn, SL("value"), &_8$$34, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 277)) {
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch_string(&value, expr, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 628 TSRMLS_CC);
				if (zephir_memnstr_str(&value, SL(":"), "phalcon/mvc/model/query.zep", 629)) {
					ZEPHIR_INIT_VAR(&valueParts);
					zephir_fast_explode_str(&valueParts, SL(":"), &value, LONG_MAX TSRMLS_CC);
					ZEPHIR_OBS_VAR(&name);
					zephir_array_fetch_long(&name, &valueParts, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 632 TSRMLS_CC);
					ZEPHIR_OBS_VAR(&bindType);
					zephir_array_fetch_long(&bindType, &valueParts, 1, PH_NOISY, "phalcon/mvc/model/query.zep", 633 TSRMLS_CC);
					do {
						if (ZEPHIR_IS_STRING(&bindType, "str")) {
							ZEPHIR_INIT_VAR(&_9$$37);
							ZVAL_LONG(&_9$$37, 2);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), &name, &_9$$37 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(&exprReturn);
							zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(&exprReturn, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_10$$37);
							ZEPHIR_CONCAT_SV(&_10$$37, ":", &name);
							zephir_array_update_string(&exprReturn, SL("value"), &_10$$37, PH_COPY | PH_SEPARATE);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "int")) {
							ZEPHIR_INIT_VAR(&_11$$38);
							ZVAL_LONG(&_11$$38, 1);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), &name, &_11$$38 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(&exprReturn);
							zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(&exprReturn, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_12$$38);
							ZEPHIR_CONCAT_SV(&_12$$38, ":", &name);
							zephir_array_update_string(&exprReturn, SL("value"), &_12$$38, PH_COPY | PH_SEPARATE);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "double")) {
							ZEPHIR_INIT_VAR(&_13$$39);
							ZVAL_LONG(&_13$$39, 32);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), &name, &_13$$39 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(&exprReturn);
							zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(&exprReturn, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_14$$39);
							ZEPHIR_CONCAT_SV(&_14$$39, ":", &name);
							zephir_array_update_string(&exprReturn, SL("value"), &_14$$39, PH_COPY | PH_SEPARATE);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "bool")) {
							ZEPHIR_INIT_VAR(&_15$$40);
							ZVAL_LONG(&_15$$40, 5);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), &name, &_15$$40 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(&exprReturn);
							zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(&exprReturn, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_16$$40);
							ZEPHIR_CONCAT_SV(&_16$$40, ":", &name);
							zephir_array_update_string(&exprReturn, SL("value"), &_16$$40, PH_COPY | PH_SEPARATE);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "blob")) {
							ZEPHIR_INIT_VAR(&_17$$41);
							ZVAL_LONG(&_17$$41, 3);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), &name, &_17$$41 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(&exprReturn);
							zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(&exprReturn, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_18$$41);
							ZEPHIR_CONCAT_SV(&_18$$41, ":", &name);
							zephir_array_update_string(&exprReturn, SL("value"), &_18$$41, PH_COPY | PH_SEPARATE);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "null")) {
							ZEPHIR_INIT_VAR(&_19$$42);
							ZVAL_LONG(&_19$$42, 0);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), &name, &_19$$42 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(&exprReturn);
							zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(&exprReturn, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_20$$42);
							ZEPHIR_CONCAT_SV(&_20$$42, ":", &name);
							zephir_array_update_string(&exprReturn, SL("value"), &_20$$42, PH_COPY | PH_SEPARATE);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "array") || ZEPHIR_IS_STRING(&bindType, "array-str") || ZEPHIR_IS_STRING(&bindType, "array-int")) {
							ZEPHIR_OBS_VAR(&bind);
							zephir_read_property(&_21$$43, this_ptr, SL("_bindParams"), PH_NOISY_CC | PH_READONLY);
							if (!(zephir_array_isset_fetch(&bind, &_21$$43, &name, 0 TSRMLS_CC))) {
								ZEPHIR_INIT_VAR(&_22$$44);
								object_init_ex(&_22$$44, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_VAR(&_23$$44);
								ZEPHIR_CONCAT_SV(&_23$$44, "Bind value is required for array type placeholder: ", &name);
								ZEPHIR_CALL_METHOD(NULL, &_22$$44, "__construct", NULL, 4, &_23$$44);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_22$$44, "phalcon/mvc/model/query.zep", 672 TSRMLS_CC);
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (Z_TYPE_P(&bind) != IS_ARRAY) {
								ZEPHIR_INIT_VAR(&_24$$45);
								object_init_ex(&_24$$45, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_VAR(&_25$$45);
								ZEPHIR_CONCAT_SV(&_25$$45, "Bind type requires an array in placeholder: ", &name);
								ZEPHIR_CALL_METHOD(NULL, &_24$$45, "__construct", NULL, 4, &_25$$45);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_24$$45, "phalcon/mvc/model/query.zep", 676 TSRMLS_CC);
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (zephir_fast_count_int(&bind TSRMLS_CC) < 1) {
								ZEPHIR_INIT_VAR(&_26$$46);
								object_init_ex(&_26$$46, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_VAR(&_27$$46);
								ZEPHIR_CONCAT_SV(&_27$$46, "At least one value must be bound in placeholder: ", &name);
								ZEPHIR_CALL_METHOD(NULL, &_26$$46, "__construct", NULL, 4, &_27$$46);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_26$$46, "phalcon/mvc/model/query.zep", 680 TSRMLS_CC);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&exprReturn);
							zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
							add_assoc_stringl_ex(&exprReturn, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_28$$43);
							ZEPHIR_CONCAT_SV(&_28$$43, ":", &name);
							zephir_array_update_string(&exprReturn, SL("value"), &_28$$43, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&exprReturn, SL("rawValue"), &name, PH_COPY | PH_SEPARATE);
							add_assoc_long_ex(&exprReturn, SL("times"), zephir_fast_count_int(&bind TSRMLS_CC));
							break;
						}
						ZEPHIR_INIT_VAR(&_29$$47);
						object_init_ex(&_29$$47, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_VAR(&_30$$47);
						ZEPHIR_CONCAT_SV(&_30$$47, "Unknown bind type: ", &bindType);
						ZEPHIR_CALL_METHOD(NULL, &_29$$47, "__construct", NULL, 4, &_30$$47);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_29$$47, "phalcon/mvc/model/query.zep", 692 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					} while(0);

				} else {
					ZEPHIR_INIT_NVAR(&exprReturn);
					zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
					add_assoc_stringl_ex(&exprReturn, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_31$$48);
					ZEPHIR_CONCAT_SV(&_31$$48, ":", &value);
					zephir_array_update_string(&exprReturn, SL("value"), &_31$$48, PH_COPY | PH_SEPARATE);
				}
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 322)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("literal"));
				add_assoc_stringl_ex(&exprReturn, SL("value"), SL("NULL"));
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 268)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("LIKE"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 351)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("NOT LIKE"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 275)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("ILIKE"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 357)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("NOT ILIKE"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '!')) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("NOT "));
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 365)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL(" IS NULL"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 366)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL(" IS NOT NULL"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 315)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("IN"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 323)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("NOT IN"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 408)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("EXISTS"));
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 330)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("DISTINCT "));
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 331)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("BETWEEN"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 276)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("AGAINST"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 332)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("cast"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 335)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("convert"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 358)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("literal"));
				ZEPHIR_OBS_VAR(&_32$$65);
				zephir_array_fetch_string(&_32$$65, expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 765 TSRMLS_CC);
				zephir_array_update_string(&exprReturn, SL("value"), &_32$$65, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 350)) {
				ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "_getfunctioncall", NULL, 319, expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 409)) {
				ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "_getcaseexpression", NULL, 320, expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 309)) {
				ZEPHIR_INIT_NVAR(&exprReturn);
				zephir_create_array(&exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("select"));
				ZVAL_BOOL(&_34$$68, 1);
				ZEPHIR_CALL_METHOD(&_33$$68, this_ptr, "_prepareselect", NULL, 321, expr, &_34$$68);
				zephir_check_call_status();
				zephir_array_update_string(&exprReturn, SL("value"), &_33$$68, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_VAR(&_35$$69);
			object_init_ex(&_35$$69, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_36$$69);
			ZEPHIR_CONCAT_SV(&_36$$69, "Unknown expression type ", &exprType);
			ZEPHIR_CALL_METHOD(NULL, &_35$$69, "__construct", NULL, 4, &_36$$69);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_35$$69, "phalcon/mvc/model/query.zep", 781 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

		RETURN_CCTOR(&exprReturn);
	}
	if (zephir_array_isset_string(expr, SL("domain"))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualified", NULL, 318, expr);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_array_isset_long(expr, 0)) {
		ZEPHIR_INIT_VAR(&listItems);
		array_init(&listItems);
		zephir_is_iterable(expr, 0, "phalcon/mvc/model/query.zep", 802);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(expr), _37$$71)
		{
			ZEPHIR_INIT_NVAR(&exprListItem);
			ZVAL_COPY(&exprListItem, _37$$71);
			ZEPHIR_CALL_METHOD(&_38$$72, this_ptr, "_getexpression", NULL, 316, &exprListItem);
			zephir_check_call_status();
			zephir_array_append(&listItems, &_38$$72, PH_SEPARATE, "phalcon/mvc/model/query.zep", 800);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&exprListItem);
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		add_assoc_stringl_ex(return_value, SL("type"), SL("list"));
		zephir_array_fast_append(return_value, &listItems);
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

	zend_string *_3$$4;
	zend_ulong _2$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *column_param = NULL, sqlColumns, columnType, sqlAliases, modelName, source, columnDomain, sqlColumnAlias, preparedAlias, sqlExprColumn, sqlAliasesModels, sqlColumn, columnData, balias, eager, _12, _13, _0$$4, *_1$$4, _4$$5, _6$$6, _7$$9, _8$$9, _9$$9, _10$$13, _11$$16;
	zval column;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&sqlColumns);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&sqlAliases);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&columnDomain);
	ZVAL_UNDEF(&sqlColumnAlias);
	ZVAL_UNDEF(&preparedAlias);
	ZVAL_UNDEF(&sqlExprColumn);
	ZVAL_UNDEF(&sqlAliasesModels);
	ZVAL_UNDEF(&sqlColumn);
	ZVAL_UNDEF(&columnData);
	ZVAL_UNDEF(&balias);
	ZVAL_UNDEF(&eager);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$16);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column_param);

	ZEPHIR_OBS_COPY_OR_DUP(&column, column_param);


	ZEPHIR_OBS_VAR(&columnType);
	if (!(zephir_array_isset_string_fetch(&columnType, &column, SL("type"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 819);
		return;
	}
	ZEPHIR_INIT_VAR(&sqlColumns);
	array_init(&sqlColumns);
	ZEPHIR_OBS_VAR(&eager);
	zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 0);
	if (ZEPHIR_IS_LONG(&columnType, 352)) {
		zephir_read_property(&_0$$4, this_ptr, SL("_models"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_0$$4, 0, "phalcon/mvc/model/query.zep", 849);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0$$4), _2$$4, _3$$4, _1$$4)
		{
			ZEPHIR_INIT_NVAR(&modelName);
			if (_3$$4 != NULL) { 
				ZVAL_STR_COPY(&modelName, _3$$4);
			} else {
				ZVAL_LONG(&modelName, _2$$4);
			}
			ZEPHIR_INIT_NVAR(&source);
			ZVAL_COPY(&source, _1$$4);
			ZEPHIR_INIT_NVAR(&sqlColumn);
			zephir_create_array(&sqlColumn, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&sqlColumn, SL("type"), SL("object"));
			zephir_array_update_string(&sqlColumn, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&sqlColumn, SL("column"), &source, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_4$$5, "lcfirst", &_5, 65, &modelName);
			zephir_check_call_status();
			zephir_array_update_string(&sqlColumn, SL("balias"), &_4$$5, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(&eager) != IS_NULL) {
				zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_string(&_6$$6, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 844 TSRMLS_CC);
				zephir_array_update_string(&sqlColumn, SL("eagerType"), &_6$$6, PH_COPY | PH_SEPARATE);
			}
			zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 847);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&source);
		ZEPHIR_INIT_NVAR(&modelName);
		RETURN_CCTOR(&sqlColumns);
	}
	if (!(zephir_array_isset_string(&column, SL("column")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 853);
		return;
	}
	if (ZEPHIR_IS_LONG(&columnType, 353)) {
		ZEPHIR_OBS_VAR(&sqlAliases);
		zephir_read_property(&sqlAliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&columnDomain);
		zephir_array_fetch_string(&columnDomain, &column, SL("column"), PH_NOISY, "phalcon/mvc/model/query.zep", 866 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&source);
		if (!(zephir_array_isset_fetch(&source, &sqlAliases, &columnDomain, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(&_7$$9);
			object_init_ex(&_7$$9, phalcon_mvc_model_exception_ce);
			zephir_read_property(&_8$$9, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_9$$9);
			ZEPHIR_CONCAT_SVSV(&_9$$9, "Unknown model or alias '", &columnDomain, "' (2), when preparing: ", &_8$$9);
			ZEPHIR_CALL_METHOD(NULL, &_7$$9, "__construct", NULL, 4, &_9$$9);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$9, "phalcon/mvc/model/query.zep", 869 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&sqlColumnAlias, &source);
		ZEPHIR_OBS_VAR(&preparedAlias);
		zephir_array_isset_string_fetch(&preparedAlias, &column, SL("balias"), 0);
		ZEPHIR_OBS_VAR(&sqlAliasesModels);
		zephir_read_property(&sqlAliasesModels, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&modelName);
		zephir_array_fetch(&modelName, &sqlAliasesModels, &columnDomain, PH_NOISY, "phalcon/mvc/model/query.zep", 883 TSRMLS_CC);
		if (Z_TYPE_P(&preparedAlias) != IS_STRING) {
			if (ZEPHIR_IS_EQUAL(&columnDomain, &modelName)) {
				ZEPHIR_CALL_FUNCTION(&preparedAlias, "lcfirst", &_5, 65, &modelName);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&preparedAlias, &columnDomain);
			}
		}
		ZEPHIR_INIT_NVAR(&sqlColumn);
		zephir_create_array(&sqlColumn, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&sqlColumn, SL("type"), SL("object"));
		zephir_array_update_string(&sqlColumn, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&sqlColumn, SL("column"), &sqlColumnAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&sqlColumn, SL("balias"), &preparedAlias, PH_COPY | PH_SEPARATE);
		if (Z_TYPE_P(&eager) != IS_NULL) {
			zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_10$$13, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 909 TSRMLS_CC);
			zephir_array_update_string(&sqlColumn, SL("eagerType"), &_10$$13, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 912);
		RETURN_CCTOR(&sqlColumns);
	}
	if (ZEPHIR_IS_LONG(&columnType, 354)) {
		ZEPHIR_INIT_NVAR(&sqlColumn);
		zephir_create_array(&sqlColumn, 1, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&sqlColumn, SL("type"), SL("scalar"));
		ZEPHIR_OBS_VAR(&columnData);
		zephir_array_fetch_string(&columnData, &column, SL("column"), PH_NOISY, "phalcon/mvc/model/query.zep", 926 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&sqlExprColumn, this_ptr, "_getexpression", NULL, 316, &columnData);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&balias);
		if (zephir_array_isset_string_fetch(&balias, &sqlExprColumn, SL("balias"), 0)) {
			zephir_array_update_string(&sqlColumn, SL("balias"), &balias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &balias, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&eager) != IS_NULL) {
			zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_11$$16, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 939 TSRMLS_CC);
			zephir_array_update_string(&sqlColumn, SL("eagerType"), &_11$$16, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&sqlColumn, SL("column"), &sqlExprColumn, PH_COPY | PH_SEPARATE);
		zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 943);
		RETURN_CCTOR(&sqlColumns);
	}
	ZEPHIR_INIT_VAR(&_12);
	object_init_ex(&_12, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_CONCAT_SV(&_13, "Unknown type of column ", &columnType);
	ZEPHIR_CALL_METHOD(NULL, &_12, "__construct", NULL, 4, &_13);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_12, "phalcon/mvc/model/query.zep", 948 TSRMLS_CC);
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
	zval *manager, manager_sub, *qualifiedName, qualifiedName_sub, modelName, model, source, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager_sub);
	ZVAL_UNDEF(&qualifiedName_sub);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &manager, &qualifiedName);



	ZEPHIR_OBS_VAR(&modelName);
	if (!(zephir_array_isset_string_fetch(&modelName, qualifiedName, SL("name"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 963);
		return;
	}
	ZEPHIR_CALL_METHOD(&model, manager, "load", NULL, 0, &modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(return_value, &schema);
		zephir_array_fast_append(return_value, &source);
		RETURN_MM();
	}
	RETURN_CCTOR(&source);

}

/**
 * Resolves a JOIN clause checking if the associated models exist
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoin) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *manager, manager_sub, *join, join_sub, qualified, modelName, realModelName, nsAlias, source, model, schema, _0$$3, _1$$5, _2$$5, _3$$5, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager_sub);
	ZVAL_UNDEF(&join_sub);
	ZVAL_UNDEF(&qualified);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&realModelName);
	ZVAL_UNDEF(&nsAlias);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &manager, &join);



	ZEPHIR_OBS_VAR(&qualified);
	if (zephir_array_isset_string_fetch(&qualified, join, SL("qualified"), 0)) {
		zephir_array_fetch_string(&_0$$3, &qualified, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 987 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(&_0$$3, 355)) {
			ZEPHIR_OBS_VAR(&modelName);
			zephir_array_fetch_string(&modelName, &qualified, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 989 TSRMLS_CC);
			if (zephir_memnstr_str(&modelName, SL(":"), "phalcon/mvc/model/query.zep", 991)) {
				ZEPHIR_INIT_VAR(&nsAlias);
				zephir_fast_explode_str(&nsAlias, SL(":"), &modelName, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_2$$5, &nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 993 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_1$$5, manager, "getnamespacealias", NULL, 0, &_2$$5);
				zephir_check_call_status();
				zephir_array_fetch_long(&_3$$5, &nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 993 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&realModelName);
				ZEPHIR_CONCAT_VSV(&realModelName, &_1$$5, "\\", &_3$$5);
			} else {
				ZEPHIR_CPY_WRT(&realModelName, &modelName);
			}
			ZVAL_BOOL(&_4$$4, 1);
			ZEPHIR_CALL_METHOD(&model, manager, "load", NULL, 0, &realModelName, &_4$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
			zephir_check_call_status();
			zephir_create_array(return_value, 4, 0 TSRMLS_CC);
			zephir_array_update_string(return_value, SL("schema"), &schema, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("source"), &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("modelName"), &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("model"), &model, PH_COPY | PH_SEPARATE);
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
	zval *join, join_sub, type, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&join_sub);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &join);



	ZEPHIR_OBS_VAR(&type);
	if (!(zephir_array_isset_string_fetch(&type, join, SL("type"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 1025);
		return;
	}
	do {
		if (ZEPHIR_IS_LONG(&type, 360)) {
			RETURN_MM_STRING("INNER");
		}
		if (ZEPHIR_IS_LONG(&type, 361)) {
			RETURN_MM_STRING("LEFT");
		}
		if (ZEPHIR_IS_LONG(&type, 362)) {
			RETURN_MM_STRING("RIGHT");
		}
		if (ZEPHIR_IS_LONG(&type, 363)) {
			RETURN_MM_STRING("CROSS");
		}
		if (ZEPHIR_IS_LONG(&type, 364)) {
			RETURN_MM_STRING("FULL OUTER");
		}
	} while(0);

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_mvc_model_exception_ce);
	zephir_read_property(&_1, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVSV(&_2, "Unknown join type ", &type, ", when preparing: ", &_1);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 4, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/mvc/model/query.zep", 1046 TSRMLS_CC);
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

	zend_string *_6$$4;
	zend_ulong _5$$4;
	zval _0$$3, _2$$3, _3$$3, _11$$5, _13$$5, _14$$5;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *joinType_param = NULL, *joinSource, joinSource_sub, *modelAlias, modelAlias_sub, *joinAlias, joinAlias_sub, *relation, relation_sub, fields, referencedFields, sqlJoinConditions, sqlJoinPartialConditions, position, field, referencedField, _1$$3, *_4$$4, _7$$6, _8$$6, _9$$6, _12$$5;
	zval joinType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&joinType);
	ZVAL_UNDEF(&joinSource_sub);
	ZVAL_UNDEF(&modelAlias_sub);
	ZVAL_UNDEF(&joinAlias_sub);
	ZVAL_UNDEF(&relation_sub);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&sqlJoinConditions);
	ZVAL_UNDEF(&sqlJoinPartialConditions);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&referencedField);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &joinType_param, &joinSource, &modelAlias, &joinAlias, &relation);

	if (UNEXPECTED(Z_TYPE_P(joinType_param) != IS_STRING && Z_TYPE_P(joinType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinType' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinType_param) == IS_STRING)) {
		zephir_get_strval(&joinType, joinType_param);
	} else {
		ZEPHIR_INIT_VAR(&joinType);
		ZVAL_EMPTY_STRING(&joinType);
	}


	ZEPHIR_INIT_VAR(&sqlJoinConditions);
	ZVAL_NULL(&sqlJoinConditions);
	ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&fields) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&sqlJoinConditions);
		zephir_create_array(&sqlJoinConditions, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_0$$3, SL("type"), SL("binary-op"));
		add_assoc_stringl_ex(&_0$$3, SL("op"), SL("="));
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(&_2$$3, SL("type"), 355);
		zephir_array_update_string(&_2$$3, SL("domain"), modelAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_2$$3, SL("name"), &fields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "_getqualified", NULL, 318, &_2$$3);
		zephir_check_call_status();
		zephir_array_update_string(&_0$$3, SL("left"), &_1$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_3$$3, SL("type"), SL("qualified"));
		zephir_array_update_string(&_3$$3, SL("domain"), joinAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3$$3, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "_getqualified", NULL, 318, &_3$$3);
		zephir_check_call_status();
		zephir_array_update_string(&_0$$3, SL("right"), &_1$$3, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&sqlJoinConditions, &_0$$3);
	} else {
		ZEPHIR_INIT_VAR(&sqlJoinPartialConditions);
		array_init(&sqlJoinPartialConditions);
		zephir_is_iterable(&fields, 0, "phalcon/mvc/model/query.zep", 1136);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _5$$4, _6$$4, _4$$4)
		{
			ZEPHIR_INIT_NVAR(&position);
			if (_6$$4 != NULL) { 
				ZVAL_STR_COPY(&position, _6$$4);
			} else {
				ZVAL_LONG(&position, _5$$4);
			}
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _4$$4);
			ZEPHIR_OBS_NVAR(&referencedField);
			if (!(zephir_array_isset_fetch(&referencedField, &referencedFields, &position, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(&_7$$6);
				object_init_ex(&_7$$6, phalcon_mvc_model_exception_ce);
				zephir_read_property(&_8$$6, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_LNVAR(_9$$6);
				ZEPHIR_CONCAT_SVSVSV(&_9$$6, "The number of fields must be equal to the number of referenced fields in join ", modelAlias, "-", joinAlias, ", when preparing: ", &_8$$6);
				ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", &_10, 4, &_9$$6);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$6, "phalcon/mvc/model/query.zep", 1112 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_11$$5);
			zephir_create_array(&_11$$5, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_11$$5, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_11$$5, SL("op"), SL("="));
			ZEPHIR_INIT_NVAR(&_13$$5);
			zephir_create_array(&_13$$5, 3, 0 TSRMLS_CC);
			add_assoc_long_ex(&_13$$5, SL("type"), 355);
			zephir_array_update_string(&_13$$5, SL("domain"), modelAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13$$5, SL("name"), &field, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "_getqualified", NULL, 318, &_13$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_11$$5, SL("left"), &_12$$5, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_14$$5);
			zephir_create_array(&_14$$5, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_14$$5, SL("type"), SL("qualified"));
			zephir_array_update_string(&_14$$5, SL("domain"), joinAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$5, SL("name"), &referencedField, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "_getqualified", NULL, 318, &_14$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_11$$5, SL("right"), &_12$$5, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlJoinPartialConditions, &_11$$5, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1133);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&field);
		ZEPHIR_INIT_NVAR(&position);
	}
	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
	zephir_array_update_string(return_value, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("source"), joinSource, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("conditions"), &sqlJoinConditions, PH_COPY | PH_SEPARATE);
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

	zval _8$$4, _10$$4, _11$$6, _12$$6, _13$$6, _15$$6, _16$$6, _17$$6, _18$$6;
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *joinType, joinType_sub, *joinSource, joinSource_sub, *modelAlias, modelAlias_sub, *joinAlias, joinAlias_sub, *relation, relation_sub, sqlJoins, fields, referencedFields, intermediateModelName, intermediateModel, intermediateSource, intermediateSchema, intermediateFields, intermediateReferencedFields, referencedModelName, manager, field, position, intermediateField, sqlEqualsJoinCondition, *_0$$3, _3$$5, _4$$5, _5$$5, _7$$4, _14$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&joinType_sub);
	ZVAL_UNDEF(&joinSource_sub);
	ZVAL_UNDEF(&modelAlias_sub);
	ZVAL_UNDEF(&joinAlias_sub);
	ZVAL_UNDEF(&relation_sub);
	ZVAL_UNDEF(&sqlJoins);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&intermediateModelName);
	ZVAL_UNDEF(&intermediateModel);
	ZVAL_UNDEF(&intermediateSource);
	ZVAL_UNDEF(&intermediateSchema);
	ZVAL_UNDEF(&intermediateFields);
	ZVAL_UNDEF(&intermediateReferencedFields);
	ZVAL_UNDEF(&referencedModelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&intermediateField);
	ZVAL_UNDEF(&sqlEqualsJoinCondition);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);



	ZEPHIR_INIT_VAR(&sqlJoins);
	array_init(&sqlJoins);
	ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateModelName, relation, "getintermediatemodel", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&manager);
	zephir_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&intermediateModel, &manager, "load", NULL, 0, &intermediateModelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateSource, &intermediateModel, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateSchema, &intermediateModel, "getschema", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_sqlAliases"), &intermediateModelName, &intermediateSource TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_sqlAliasesModelsInstances"), &intermediateModelName, &intermediateModel TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&intermediateFields, relation, "getintermediatefields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateReferencedFields, relation, "getintermediatereferencedfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedModelName, relation, "getreferencedmodel", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		zephir_is_iterable(&fields, 0, "phalcon/mvc/model/query.zep", 1263);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&field, _2$$3);
			} else {
				ZVAL_LONG(&field, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&position);
			ZVAL_COPY(&position, _0$$3);
			if (!(zephir_array_isset(&referencedFields, &position))) {
				ZEPHIR_INIT_NVAR(&_3$$5);
				object_init_ex(&_3$$5, phalcon_mvc_model_exception_ce);
				zephir_read_property(&_4$$5, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_LNVAR(_5$$5);
				ZEPHIR_CONCAT_SVSVSV(&_5$$5, "The number of fields must be equal to the number of referenced fields in join ", modelAlias, "-", joinAlias, ", when preparing: ", &_4$$5);
				ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", &_6, 4, &_5$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$5, "phalcon/mvc/model/query.zep", 1234 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&intermediateField);
			zephir_array_fetch(&intermediateField, &intermediateFields, &position, PH_NOISY, "phalcon/mvc/model/query.zep", 1240 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&sqlEqualsJoinCondition);
			zephir_create_array(&sqlEqualsJoinCondition, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&sqlEqualsJoinCondition, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&sqlEqualsJoinCondition, SL("op"), SL("="));
			ZEPHIR_INIT_NVAR(&_8$$4);
			zephir_create_array(&_8$$4, 3, 0 TSRMLS_CC);
			add_assoc_long_ex(&_8$$4, SL("type"), 355);
			zephir_array_update_string(&_8$$4, SL("domain"), modelAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_8$$4, SL("name"), &field, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "_getqualified", &_9, 318, &_8$$4);
			zephir_check_call_status();
			zephir_array_update_string(&sqlEqualsJoinCondition, SL("left"), &_7$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_10$$4);
			zephir_create_array(&_10$$4, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_10$$4, SL("type"), SL("qualified"));
			zephir_array_update_string(&_10$$4, SL("domain"), joinAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_10$$4, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "_getqualified", &_9, 318, &_10$$4);
			zephir_check_call_status();
			zephir_array_update_string(&sqlEqualsJoinCondition, SL("right"), &_7$$4, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&position);
		ZEPHIR_INIT_NVAR(&field);
	} else {
		ZEPHIR_INIT_NVAR(&sqlJoins);
		zephir_create_array(&sqlJoins, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_11$$6);
		zephir_create_array(&_11$$6, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&_11$$6, SL("type"), joinType, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_11$$6, SL("source"), &intermediateSource, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_12$$6);
		zephir_create_array(&_12$$6, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_13$$6);
		zephir_create_array(&_13$$6, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_13$$6, SL("type"), SL("binary-op"));
		add_assoc_stringl_ex(&_13$$6, SL("op"), SL("="));
		ZEPHIR_INIT_VAR(&_15$$6);
		zephir_create_array(&_15$$6, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(&_15$$6, SL("type"), 355);
		zephir_array_update_string(&_15$$6, SL("domain"), modelAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_15$$6, SL("name"), &fields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_14$$6, this_ptr, "_getqualified", &_9, 318, &_15$$6);
		zephir_check_call_status();
		zephir_array_update_string(&_13$$6, SL("left"), &_14$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_16$$6);
		zephir_create_array(&_16$$6, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_16$$6, SL("type"), SL("qualified"));
		zephir_array_update_string(&_16$$6, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_16$$6, SL("name"), &intermediateFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_14$$6, this_ptr, "_getqualified", &_9, 318, &_16$$6);
		zephir_check_call_status();
		zephir_array_update_string(&_13$$6, SL("right"), &_14$$6, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_12$$6, &_13$$6);
		zephir_array_update_string(&_11$$6, SL("conditions"), &_12$$6, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&sqlJoins, &_11$$6);
		ZEPHIR_INIT_NVAR(&_11$$6);
		zephir_create_array(&_11$$6, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&_11$$6, SL("type"), joinType, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_11$$6, SL("source"), joinSource, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_12$$6);
		zephir_create_array(&_12$$6, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_13$$6);
		zephir_create_array(&_13$$6, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_13$$6, SL("type"), SL("binary-op"));
		add_assoc_stringl_ex(&_13$$6, SL("op"), SL("="));
		ZEPHIR_INIT_VAR(&_17$$6);
		zephir_create_array(&_17$$6, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(&_17$$6, SL("type"), 355);
		zephir_array_update_string(&_17$$6, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_17$$6, SL("name"), &intermediateReferencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_14$$6, this_ptr, "_getqualified", &_9, 318, &_17$$6);
		zephir_check_call_status();
		zephir_array_update_string(&_13$$6, SL("left"), &_14$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_18$$6);
		zephir_create_array(&_18$$6, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_18$$6, SL("type"), SL("qualified"));
		zephir_array_update_string(&_18$$6, SL("domain"), &referencedModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_18$$6, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_14$$6, this_ptr, "_getqualified", &_9, 318, &_18$$6);
		zephir_check_call_status();
		zephir_array_update_string(&_13$$6, SL("right"), &_14$$6, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_12$$6, &_13$$6);
		zephir_array_update_string(&_11$$6, SL("conditions"), &_12$$6, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&sqlJoins, &_11$$6);
	}
	RETURN_CCTOR(&sqlJoins);

}

/**
 * Processes the JOINs in the query returning an internal representation for the database dialect
 *
 * @param array select
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoins) {

	zval _20$$15, _21$$15, _41$$29, _43$$30, _44$$30;
	zend_string *_12, *_28, *_19$$14, *_31$$17;
	zend_ulong _11, _27, _18$$14, _30$$17;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_6 = NULL, *_14 = NULL, *_32 = NULL, *_33 = NULL, *_38 = NULL, *_39 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *select, select_sub, __$true, models, sqlAliases, sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances, modelsInstances, fromModels, sqlJoins, joinModels, joinSources, joinTypes, joinPreCondition, joinPrepared, manager, selectJoins, joinItem, joins, joinData, schema, source, model, realModelName, completeSource, joinType, aliasExpr, alias, joinAliasName, joinExpr, fromModelName, joinAlias, joinModel, joinSource, preCondition, modelNameAlias, relation, relations, modelAlias, sqlJoin, sqlJoinItem, selectTables, tables, tableItem, *_0, *_10, _15, *_22, _25, *_26, _3$$9, _4$$9, _5$$9, _7$$11, _8$$11, _9$$11, _13$$13, _16$$14, *_17$$14, _23$$16, _24$$16, *_29$$17, _34$$22, _35$$22, _36$$22, _37$$23, *_40$$26, _42$$29;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&select_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&sqlAliases);
	ZVAL_UNDEF(&sqlAliasesModels);
	ZVAL_UNDEF(&sqlModelsAliases);
	ZVAL_UNDEF(&sqlAliasesModelsInstances);
	ZVAL_UNDEF(&modelsInstances);
	ZVAL_UNDEF(&fromModels);
	ZVAL_UNDEF(&sqlJoins);
	ZVAL_UNDEF(&joinModels);
	ZVAL_UNDEF(&joinSources);
	ZVAL_UNDEF(&joinTypes);
	ZVAL_UNDEF(&joinPreCondition);
	ZVAL_UNDEF(&joinPrepared);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&selectJoins);
	ZVAL_UNDEF(&joinItem);
	ZVAL_UNDEF(&joins);
	ZVAL_UNDEF(&joinData);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&realModelName);
	ZVAL_UNDEF(&completeSource);
	ZVAL_UNDEF(&joinType);
	ZVAL_UNDEF(&aliasExpr);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&joinAliasName);
	ZVAL_UNDEF(&joinExpr);
	ZVAL_UNDEF(&fromModelName);
	ZVAL_UNDEF(&joinAlias);
	ZVAL_UNDEF(&joinModel);
	ZVAL_UNDEF(&joinSource);
	ZVAL_UNDEF(&preCondition);
	ZVAL_UNDEF(&modelNameAlias);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&modelAlias);
	ZVAL_UNDEF(&sqlJoin);
	ZVAL_UNDEF(&sqlJoinItem);
	ZVAL_UNDEF(&selectTables);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&tableItem);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_34$$22);
	ZVAL_UNDEF(&_35$$22);
	ZVAL_UNDEF(&_36$$22);
	ZVAL_UNDEF(&_37$$23);
	ZVAL_UNDEF(&_42$$29);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_41$$29);
	ZVAL_UNDEF(&_43$$30);
	ZVAL_UNDEF(&_44$$30);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &select);



	ZEPHIR_OBS_VAR(&models);
	zephir_read_property(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&sqlAliases);
	zephir_read_property(&sqlAliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&sqlAliasesModels);
	zephir_read_property(&sqlAliasesModels, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&sqlModelsAliases);
	zephir_read_property(&sqlModelsAliases, this_ptr, SL("_sqlModelsAliases"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&sqlAliasesModelsInstances);
	zephir_read_property(&sqlAliasesModelsInstances, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&modelsInstances);
	zephir_read_property(&modelsInstances, this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(&fromModels, &models);
	ZEPHIR_INIT_VAR(&sqlJoins);
	array_init(&sqlJoins);
	ZEPHIR_INIT_VAR(&joinModels);
	array_init(&joinModels);
	ZEPHIR_INIT_VAR(&joinSources);
	array_init(&joinSources);
	ZEPHIR_INIT_VAR(&joinTypes);
	array_init(&joinTypes);
	ZEPHIR_INIT_VAR(&joinPreCondition);
	array_init(&joinPreCondition);
	ZEPHIR_INIT_VAR(&joinPrepared);
	array_init(&joinPrepared);
	ZEPHIR_OBS_VAR(&manager);
	zephir_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&tables);
	zephir_array_fetch_string(&tables, select, SL("tables"), PH_NOISY, "phalcon/mvc/model/query.zep", 1354 TSRMLS_CC);
	if (!(zephir_array_isset_long(&tables, 0))) {
		ZEPHIR_INIT_VAR(&selectTables);
		zephir_create_array(&selectTables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&selectTables, &tables);
	} else {
		ZEPHIR_CPY_WRT(&selectTables, &tables);
	}
	ZEPHIR_OBS_VAR(&joins);
	zephir_array_fetch_string(&joins, select, SL("joins"), PH_NOISY, "phalcon/mvc/model/query.zep", 1361 TSRMLS_CC);
	if (!(zephir_array_isset_long(&joins, 0))) {
		ZEPHIR_INIT_VAR(&selectJoins);
		zephir_create_array(&selectJoins, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&selectJoins, &joins);
	} else {
		ZEPHIR_CPY_WRT(&selectJoins, &joins);
	}
	zephir_is_iterable(&selectJoins, 0, "phalcon/mvc/model/query.zep", 1514);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&selectJoins), _0)
	{
		ZEPHIR_INIT_NVAR(&joinItem);
		ZVAL_COPY(&joinItem, _0);
		ZEPHIR_CALL_METHOD(&joinData, this_ptr, "_getjoin", &_1, 322, &manager, &joinItem);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&source);
		zephir_array_fetch_string(&source, &joinData, SL("source"), PH_NOISY, "phalcon/mvc/model/query.zep", 1374 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&schema);
		zephir_array_fetch_string(&schema, &joinData, SL("schema"), PH_NOISY, "phalcon/mvc/model/query.zep", 1375 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&model);
		zephir_array_fetch_string(&model, &joinData, SL("model"), PH_NOISY, "phalcon/mvc/model/query.zep", 1376 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&realModelName);
		zephir_array_fetch_string(&realModelName, &joinData, SL("modelName"), PH_NOISY, "phalcon/mvc/model/query.zep", 1377 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&completeSource);
		zephir_create_array(&completeSource, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&completeSource, &source);
		zephir_array_fast_append(&completeSource, &schema);
		ZEPHIR_CALL_METHOD(&joinType, this_ptr, "_getjointype", &_2, 323, &joinItem);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&aliasExpr);
		if (zephir_array_isset_string_fetch(&aliasExpr, &joinItem, SL("alias"), 0)) {
			ZEPHIR_OBS_NVAR(&alias);
			zephir_array_fetch_string(&alias, &aliasExpr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1390 TSRMLS_CC);
			if (zephir_array_isset(&joinModels, &alias)) {
				ZEPHIR_INIT_NVAR(&_3$$9);
				object_init_ex(&_3$$9, phalcon_mvc_model_exception_ce);
				zephir_read_property(&_4$$9, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_LNVAR(_5$$9);
				ZEPHIR_CONCAT_SVSV(&_5$$9, "Cannot use '", &alias, "' as join alias because it was already used, when preparing: ", &_4$$9);
				ZEPHIR_CALL_METHOD(NULL, &_3$$9, "__construct", &_6, 4, &_5$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$9, "phalcon/mvc/model/query.zep", 1398 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1404);
			zephir_array_update_zval(&joinTypes, &alias, &joinType, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinModels, &alias, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, &realModelName, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModels, &alias, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, &realModelName, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinSources, &alias, &completeSource, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinPrepared, &alias, &joinItem, PH_COPY | PH_SEPARATE);
		} else {
			if (zephir_array_isset(&joinModels, &realModelName)) {
				ZEPHIR_INIT_NVAR(&_7$$11);
				object_init_ex(&_7$$11, phalcon_mvc_model_exception_ce);
				zephir_read_property(&_8$$11, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_LNVAR(_9$$11);
				ZEPHIR_CONCAT_SVSV(&_9$$11, "Cannot use '", &realModelName, "' as join alias because it was already used, when preparing: ", &_8$$11);
				ZEPHIR_CALL_METHOD(NULL, &_7$$11, "__construct", &_6, 4, &_9$$11);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$11, "phalcon/mvc/model/query.zep", 1459 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&joinTypes, &realModelName, &joinType, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliases, &realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinModels, &realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, &realModelName, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModels, &realModelName, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, &realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinSources, &realModelName, &completeSource, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinPrepared, &realModelName, &joinItem, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_zval(&modelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&joinItem);
	zephir_update_property_zval(this_ptr, SL("_models"), &models);
	zephir_update_property_zval(this_ptr, SL("_sqlAliases"), &sqlAliases);
	zephir_update_property_zval(this_ptr, SL("_sqlAliasesModels"), &sqlAliasesModels);
	zephir_update_property_zval(this_ptr, SL("_sqlModelsAliases"), &sqlModelsAliases);
	zephir_update_property_zval(this_ptr, SL("_sqlAliasesModelsInstances"), &sqlAliasesModelsInstances);
	zephir_update_property_zval(this_ptr, SL("_modelsInstances"), &modelsInstances);
	zephir_is_iterable(&joinPrepared, 0, "phalcon/mvc/model/query.zep", 1534);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinPrepared), _11, _12, _10)
	{
		ZEPHIR_INIT_NVAR(&joinAliasName);
		if (_12 != NULL) { 
			ZVAL_STR_COPY(&joinAliasName, _12);
		} else {
			ZVAL_LONG(&joinAliasName, _11);
		}
		ZEPHIR_INIT_NVAR(&joinItem);
		ZVAL_COPY(&joinItem, _10);
		ZEPHIR_OBS_NVAR(&joinExpr);
		if (zephir_array_isset_string_fetch(&joinExpr, &joinItem, SL("conditions"), 0)) {
			ZEPHIR_CALL_METHOD(&_13$$13, this_ptr, "_getexpression", &_14, 316, &joinExpr);
			zephir_check_call_status();
			zephir_array_update_zval(&joinPreCondition, &joinAliasName, &_13$$13, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&joinItem);
	ZEPHIR_INIT_NVAR(&joinAliasName);
	zephir_read_property(&_15, this_ptr, SL("_enableImplicitJoins"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_15))) {
		ZEPHIR_INIT_VAR(&_16$$14);
		zephir_is_iterable(&joinPrepared, 0, "phalcon/mvc/model/query.zep", 1545);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinPrepared), _18$$14, _19$$14, _17$$14)
		{
			ZEPHIR_INIT_NVAR(&joinAliasName);
			if (_19$$14 != NULL) { 
				ZVAL_STR_COPY(&joinAliasName, _19$$14);
			} else {
				ZVAL_LONG(&joinAliasName, _18$$14);
			}
			ZEPHIR_INIT_NVAR(&_16$$14);
			ZVAL_COPY(&_16$$14, _17$$14);
			ZEPHIR_OBS_NVAR(&joinType);
			zephir_array_fetch(&joinType, &joinTypes, &joinAliasName, PH_NOISY, "phalcon/mvc/model/query.zep", 1536 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&joinSource);
			zephir_array_fetch(&joinSource, &joinSources, &joinAliasName, PH_NOISY, "phalcon/mvc/model/query.zep", 1537 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&preCondition);
			zephir_array_fetch(&preCondition, &joinPreCondition, &joinAliasName, PH_NOISY, "phalcon/mvc/model/query.zep", 1538 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_20$$15);
			zephir_create_array(&_20$$15, 3, 0 TSRMLS_CC);
			zephir_array_update_string(&_20$$15, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_20$$15, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_21$$15);
			zephir_create_array(&_21$$15, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_21$$15, &preCondition);
			zephir_array_update_string(&_20$$15, SL("conditions"), &_21$$15, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlJoins, &_20$$15, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1543);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_16$$14);
		ZEPHIR_INIT_NVAR(&joinAliasName);
		RETURN_CCTOR(&sqlJoins);
	}
	ZEPHIR_INIT_NVAR(&fromModels);
	array_init(&fromModels);
	zephir_is_iterable(&selectTables, 0, "phalcon/mvc/model/query.zep", 1559);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&selectTables), _22)
	{
		ZEPHIR_INIT_NVAR(&tableItem);
		ZVAL_COPY(&tableItem, _22);
		zephir_array_fetch_string(&_23$$16, &tableItem, SL("qualifiedName"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1553 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&_24$$16);
		zephir_array_fetch_string(&_24$$16, &_23$$16, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1553 TSRMLS_CC);
		zephir_array_update_zval(&fromModels, &_24$$16, &__$true, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&tableItem);
	ZEPHIR_INIT_VAR(&_25);
	zephir_is_iterable(&fromModels, 0, "phalcon/mvc/model/query.zep", 1667);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fromModels), _27, _28, _26)
	{
		ZEPHIR_INIT_NVAR(&fromModelName);
		if (_28 != NULL) { 
			ZVAL_STR_COPY(&fromModelName, _28);
		} else {
			ZVAL_LONG(&fromModelName, _27);
		}
		ZEPHIR_INIT_NVAR(&_25);
		ZVAL_COPY(&_25, _26);
		zephir_is_iterable(&joinModels, 0, "phalcon/mvc/model/query.zep", 1665);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinModels), _30$$17, _31$$17, _29$$17)
		{
			ZEPHIR_INIT_NVAR(&joinAlias);
			if (_31$$17 != NULL) { 
				ZVAL_STR_COPY(&joinAlias, _31$$17);
			} else {
				ZVAL_LONG(&joinAlias, _30$$17);
			}
			ZEPHIR_INIT_NVAR(&joinModel);
			ZVAL_COPY(&joinModel, _29$$17);
			ZEPHIR_OBS_NVAR(&joinSource);
			zephir_array_fetch(&joinSource, &joinSources, &joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1566 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&joinType);
			zephir_array_fetch(&joinType, &joinTypes, &joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1571 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&preCondition);
			if (!(zephir_array_isset_fetch(&preCondition, &joinPreCondition, &joinAlias, 0 TSRMLS_CC))) {
				ZEPHIR_OBS_NVAR(&modelNameAlias);
				zephir_array_fetch(&modelNameAlias, &sqlAliasesModels, &joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1581 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_32, 0, &fromModelName, &modelNameAlias);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&relation)) {
					ZEPHIR_CALL_METHOD(&relations, &manager, "getrelationsbetween", &_33, 0, &fromModelName, &modelNameAlias);
					zephir_check_call_status();
					if (Z_TYPE_P(&relations) == IS_ARRAY) {
						if (zephir_fast_count_int(&relations TSRMLS_CC) != 1) {
							ZEPHIR_INIT_NVAR(&_34$$22);
							object_init_ex(&_34$$22, phalcon_mvc_model_exception_ce);
							zephir_read_property(&_35$$22, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_INIT_LNVAR(_36$$22);
							ZEPHIR_CONCAT_SVSVSV(&_36$$22, "There is more than one relation between models '", &fromModelName, "' and '", &joinModel, "', the join must be done using an alias, when preparing: ", &_35$$22);
							ZEPHIR_CALL_METHOD(NULL, &_34$$22, "__construct", &_6, 4, &_36$$22);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_34$$22, "phalcon/mvc/model/query.zep", 1601 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&relation);
						zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 1607 TSRMLS_CC);
					}
				}
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_OBS_NVAR(&modelAlias);
					zephir_array_fetch(&modelAlias, &sqlModelsAliases, &fromModelName, PH_NOISY, "phalcon/mvc/model/query.zep", 1619 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_37$$23, &relation, "isthrough", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(&_37$$23))) {
						ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "_getsinglejoin", &_38, 324, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
						zephir_check_call_status();
					} else {
						ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "_getmultijoin", &_39, 325, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
						zephir_check_call_status();
					}
					if (zephir_array_isset_long(&sqlJoin, 0)) {
						zephir_is_iterable(&sqlJoin, 0, "phalcon/mvc/model/query.zep", 1637);
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&sqlJoin), _40$$26)
						{
							ZEPHIR_INIT_NVAR(&sqlJoinItem);
							ZVAL_COPY(&sqlJoinItem, _40$$26);
							zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1635);
						} ZEND_HASH_FOREACH_END();
						ZEPHIR_INIT_NVAR(&sqlJoinItem);
					} else {
						zephir_array_append(&sqlJoins, &sqlJoin, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1638);
					}
				} else {
					ZEPHIR_INIT_NVAR(&_41$$29);
					zephir_create_array(&_41$$29, 3, 0 TSRMLS_CC);
					zephir_array_update_string(&_41$$29, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_41$$29, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_42$$29);
					array_init(&_42$$29);
					zephir_array_update_string(&_41$$29, SL("conditions"), &_42$$29, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlJoins, &_41$$29, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1650);
				}
			} else {
				ZEPHIR_INIT_NVAR(&_43$$30);
				zephir_create_array(&_43$$30, 3, 0 TSRMLS_CC);
				zephir_array_update_string(&_43$$30, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_43$$30, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_44$$30);
				zephir_create_array(&_44$$30, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(&_44$$30, &preCondition);
				zephir_array_update_string(&_43$$30, SL("conditions"), &_44$$30, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlJoins, &_43$$30, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1662);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&joinModel);
		ZEPHIR_INIT_NVAR(&joinAlias);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&_25);
	ZEPHIR_INIT_NVAR(&fromModelName);
	RETURN_CCTOR(&sqlJoins);

}

/**
 * Returns a processed order clause for a SELECT statement
 *
 * @param array|string $order
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getOrderClause) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *order, order_sub, orderColumns, orderParts, orderItem, orderPartExpr, orderSort, orderPartSort, *_0, _1$$5, _3$$7, _4$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&order_sub);
	ZVAL_UNDEF(&orderColumns);
	ZVAL_UNDEF(&orderParts);
	ZVAL_UNDEF(&orderItem);
	ZVAL_UNDEF(&orderPartExpr);
	ZVAL_UNDEF(&orderSort);
	ZVAL_UNDEF(&orderPartSort);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &order);



	if (!(zephir_array_isset_long(order, 0))) {
		ZEPHIR_INIT_VAR(&orderColumns);
		zephir_create_array(&orderColumns, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&orderColumns, order);
	} else {
		ZEPHIR_CPY_WRT(&orderColumns, order);
	}
	ZEPHIR_INIT_VAR(&orderParts);
	array_init(&orderParts);
	zephir_is_iterable(&orderColumns, 0, "phalcon/mvc/model/query.zep", 1708);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&orderColumns), _0)
	{
		ZEPHIR_INIT_NVAR(&orderItem);
		ZVAL_COPY(&orderItem, _0);
		zephir_array_fetch_string(&_1$$5, &orderItem, SL("column"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1690 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&orderPartExpr, this_ptr, "_getexpression", &_2, 316, &_1$$5);
		zephir_check_call_status();
		if (zephir_array_isset_string_fetch(&orderSort, &orderItem, SL("sort"), 1)) {
			ZEPHIR_INIT_NVAR(&orderPartSort);
			if (ZEPHIR_IS_LONG(&orderSort, 327)) {
				zephir_create_array(&orderPartSort, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(&orderPartSort, &orderPartExpr);
				ZEPHIR_INIT_NVAR(&_3$$7);
				ZVAL_STRING(&_3$$7, "ASC");
				zephir_array_fast_append(&orderPartSort, &_3$$7);
			} else {
				zephir_create_array(&orderPartSort, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(&orderPartSort, &orderPartExpr);
				ZEPHIR_INIT_NVAR(&_4$$8);
				ZVAL_STRING(&_4$$8, "DESC");
				zephir_array_fast_append(&orderPartSort, &_4$$8);
			}
		} else {
			ZEPHIR_INIT_NVAR(&orderPartSort);
			zephir_create_array(&orderPartSort, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&orderPartSort, &orderPartExpr);
		}
		zephir_array_append(&orderParts, &orderPartSort, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1705);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&orderItem);
	RETURN_CCTOR(&orderParts);

}

/**
 * Returns a processed group clause for a SELECT statement
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getGroupClause) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group_param = NULL, groupItem, groupParts, *_0$$3, _1$$4, _3$$5;
	zval group;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&groupItem);
	ZVAL_UNDEF(&groupParts);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group_param);

	ZEPHIR_OBS_COPY_OR_DUP(&group, group_param);


	ZEPHIR_INIT_VAR(&groupParts);
	if (zephir_array_isset_long(&group, 0)) {
		array_init(&groupParts);
		zephir_is_iterable(&group, 0, "phalcon/mvc/model/query.zep", 1726);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&group), _0$$3)
		{
			ZEPHIR_INIT_NVAR(&groupItem);
			ZVAL_COPY(&groupItem, _0$$3);
			ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "_getexpression", &_2, 316, &groupItem);
			zephir_check_call_status();
			zephir_array_append(&groupParts, &_1$$4, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1724);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&groupItem);
	} else {
		zephir_create_array(&groupParts, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "_getexpression", &_2, 316, &group);
		zephir_check_call_status();
		zephir_array_fast_append(&groupParts, &_3$$5);
	}
	RETURN_CCTOR(&groupParts);

}

/**
 * Returns a processed limit clause for a SELECT statement
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getLimitClause) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *limitClause_param = NULL, number, offset, _0$$3, _1$$4;
	zval limitClause, limit;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&limitClause);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &limitClause_param);

	ZEPHIR_OBS_COPY_OR_DUP(&limitClause, limitClause_param);


	ZEPHIR_INIT_VAR(&limit);
	array_init(&limit);
	ZEPHIR_OBS_VAR(&number);
	if (zephir_array_isset_string_fetch(&number, &limitClause, SL("number"), 0)) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "_getexpression", NULL, 316, &number);
		zephir_check_call_status();
		zephir_array_update_string(&limit, SL("number"), &_0$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&offset);
	if (zephir_array_isset_string_fetch(&offset, &limitClause, SL("offset"), 0)) {
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "_getexpression", NULL, 316, &offset);
		zephir_check_call_status();
		zephir_array_update_string(&limit, SL("offset"), &_1$$4, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(&limit);

}

/**
 * Analyzes a SELECT intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareSelect) {

	zval _21$$27, _22$$27, _23$$27;
	zval _13$$27, _43$$47;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_10 = NULL, *_14 = NULL, *_16 = NULL, *_39 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, position = 0, number = 0;
	zval *ast = NULL, ast_sub, *merge = NULL, merge_sub, __$null, __$true, sqlModels, sqlTables, sqlAliases, sqlColumns, select, tables, columns, sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances, models, modelsInstances, selectedModels, manager, metaData, selectedModel, qualifiedName, modelName, nsAlias, realModelName, model, schema, source, completeSource, alias, joins, sqlJoins, selectColumns, sqlColumnAliases, column, sqlColumn, sqlSelect, distinct, having, where, groupBy, order, limit, tempModels, tempModelsInstances, tempSqlAliases, tempSqlModelsAliases, tempSqlAliasesModelsInstances, tempSqlAliasesModels, with, withs, withItem, automaticJoins, relation, joinAlias, relationModel, bestAlias, eagerType, *_0, *_37, _1$$15, _2$$15, _4$$15, _5$$14, _7$$20, _8$$20, _9$$20, *_11$$24, _12$$27, _15$$28, _17$$30, _18$$31, _19$$31, _20$$31, _24$$33, _25$$33, _26$$33, _27$$33, _28$$33, _29$$33, _30$$33, _31$$33, _32$$33, _33$$33, _34$$33, _35$$33, _36$$36, _38$$41, *_40$$41, _41$$46, _42$$47, _44$$51, _45$$52, _46$$53, _47$$54, _48$$55;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ast_sub);
	ZVAL_UNDEF(&merge_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&sqlModels);
	ZVAL_UNDEF(&sqlTables);
	ZVAL_UNDEF(&sqlAliases);
	ZVAL_UNDEF(&sqlColumns);
	ZVAL_UNDEF(&select);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&sqlAliasesModels);
	ZVAL_UNDEF(&sqlModelsAliases);
	ZVAL_UNDEF(&sqlAliasesModelsInstances);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&modelsInstances);
	ZVAL_UNDEF(&selectedModels);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&selectedModel);
	ZVAL_UNDEF(&qualifiedName);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&nsAlias);
	ZVAL_UNDEF(&realModelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&completeSource);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&joins);
	ZVAL_UNDEF(&sqlJoins);
	ZVAL_UNDEF(&selectColumns);
	ZVAL_UNDEF(&sqlColumnAliases);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&sqlColumn);
	ZVAL_UNDEF(&sqlSelect);
	ZVAL_UNDEF(&distinct);
	ZVAL_UNDEF(&having);
	ZVAL_UNDEF(&where);
	ZVAL_UNDEF(&groupBy);
	ZVAL_UNDEF(&order);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&tempModels);
	ZVAL_UNDEF(&tempModelsInstances);
	ZVAL_UNDEF(&tempSqlAliases);
	ZVAL_UNDEF(&tempSqlModelsAliases);
	ZVAL_UNDEF(&tempSqlAliasesModelsInstances);
	ZVAL_UNDEF(&tempSqlAliasesModels);
	ZVAL_UNDEF(&with);
	ZVAL_UNDEF(&withs);
	ZVAL_UNDEF(&withItem);
	ZVAL_UNDEF(&automaticJoins);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&joinAlias);
	ZVAL_UNDEF(&relationModel);
	ZVAL_UNDEF(&bestAlias);
	ZVAL_UNDEF(&eagerType);
	ZVAL_UNDEF(&_1$$15);
	ZVAL_UNDEF(&_2$$15);
	ZVAL_UNDEF(&_4$$15);
	ZVAL_UNDEF(&_5$$14);
	ZVAL_UNDEF(&_7$$20);
	ZVAL_UNDEF(&_8$$20);
	ZVAL_UNDEF(&_9$$20);
	ZVAL_UNDEF(&_12$$27);
	ZVAL_UNDEF(&_15$$28);
	ZVAL_UNDEF(&_17$$30);
	ZVAL_UNDEF(&_18$$31);
	ZVAL_UNDEF(&_19$$31);
	ZVAL_UNDEF(&_20$$31);
	ZVAL_UNDEF(&_24$$33);
	ZVAL_UNDEF(&_25$$33);
	ZVAL_UNDEF(&_26$$33);
	ZVAL_UNDEF(&_27$$33);
	ZVAL_UNDEF(&_28$$33);
	ZVAL_UNDEF(&_29$$33);
	ZVAL_UNDEF(&_30$$33);
	ZVAL_UNDEF(&_31$$33);
	ZVAL_UNDEF(&_32$$33);
	ZVAL_UNDEF(&_33$$33);
	ZVAL_UNDEF(&_34$$33);
	ZVAL_UNDEF(&_35$$33);
	ZVAL_UNDEF(&_36$$36);
	ZVAL_UNDEF(&_38$$41);
	ZVAL_UNDEF(&_41$$46);
	ZVAL_UNDEF(&_42$$47);
	ZVAL_UNDEF(&_44$$51);
	ZVAL_UNDEF(&_45$$52);
	ZVAL_UNDEF(&_46$$53);
	ZVAL_UNDEF(&_47$$54);
	ZVAL_UNDEF(&_48$$55);
	ZVAL_UNDEF(&_13$$27);
	ZVAL_UNDEF(&_43$$47);
	ZVAL_UNDEF(&_21$$27);
	ZVAL_UNDEF(&_22$$27);
	ZVAL_UNDEF(&_23$$27);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &ast, &merge);

	if (!ast) {
		ast = &ast_sub;
		ZEPHIR_CPY_WRT(ast, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(ast);
	}
	if (!merge) {
		merge = &merge_sub;
		ZEPHIR_CPY_WRT(merge, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(merge);
	}


	if (ZEPHIR_IS_EMPTY(ast)) {
		ZEPHIR_OBS_NVAR(ast);
		zephir_read_property(ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(merge) == IS_NULL) {
		ZEPHIR_INIT_NVAR(merge);
		ZVAL_BOOL(merge, 0);
	}
	ZEPHIR_OBS_VAR(&select);
	if (!(zephir_array_isset_string_fetch(&select, ast, SL("select"), 0))) {
		ZEPHIR_CPY_WRT(&select, ast);
	}
	ZEPHIR_OBS_VAR(&tables);
	if (!(zephir_array_isset_string_fetch(&tables, &select, SL("tables"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 1781);
		return;
	}
	ZEPHIR_OBS_VAR(&columns);
	if (!(zephir_array_isset_string_fetch(&columns, &select, SL("columns"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 1785);
		return;
	}
	ZEPHIR_INIT_VAR(&sqlModels);
	array_init(&sqlModels);
	ZEPHIR_INIT_VAR(&sqlTables);
	array_init(&sqlTables);
	ZEPHIR_INIT_VAR(&sqlColumns);
	array_init(&sqlColumns);
	ZEPHIR_INIT_VAR(&sqlAliases);
	array_init(&sqlAliases);
	ZEPHIR_INIT_VAR(&sqlAliasesModels);
	array_init(&sqlAliasesModels);
	ZEPHIR_INIT_VAR(&sqlModelsAliases);
	array_init(&sqlModelsAliases);
	ZEPHIR_INIT_VAR(&sqlAliasesModelsInstances);
	array_init(&sqlAliasesModelsInstances);
	ZEPHIR_INIT_VAR(&models);
	array_init(&models);
	ZEPHIR_INIT_VAR(&modelsInstances);
	array_init(&modelsInstances);
	if (!(zephir_array_isset_long(&tables, 0))) {
		ZEPHIR_INIT_VAR(&selectedModels);
		zephir_create_array(&selectedModels, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&selectedModels, &tables);
	} else {
		ZEPHIR_CPY_WRT(&selectedModels, &tables);
	}
	if (!(zephir_array_isset_long(&columns, 0))) {
		ZEPHIR_INIT_VAR(&selectColumns);
		zephir_create_array(&selectColumns, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&selectColumns, &columns);
	} else {
		ZEPHIR_CPY_WRT(&selectColumns, &columns);
	}
	ZEPHIR_OBS_VAR(&manager);
	zephir_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&metaData);
	zephir_read_property(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (Z_TYPE_P(&manager) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A models-manager is required to execute the query", "phalcon/mvc/model/query.zep", 1847);
		return;
	}
	if (Z_TYPE_P(&metaData) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A meta-data is required to execute the query", "phalcon/mvc/model/query.zep", 1851);
		return;
	}
	number = 0;
	ZEPHIR_INIT_VAR(&automaticJoins);
	array_init(&automaticJoins);
	zephir_is_iterable(&selectedModels, 0, "phalcon/mvc/model/query.zep", 1980);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&selectedModels), _0)
	{
		ZEPHIR_INIT_NVAR(&selectedModel);
		ZVAL_COPY(&selectedModel, _0);
		ZEPHIR_OBS_NVAR(&qualifiedName);
		zephir_array_fetch_string(&qualifiedName, &selectedModel, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 1860 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&modelName);
		zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1861 TSRMLS_CC);
		if (zephir_memnstr_str(&modelName, SL(":"), "phalcon/mvc/model/query.zep", 1864)) {
			ZEPHIR_INIT_NVAR(&nsAlias);
			zephir_fast_explode_str(&nsAlias, SL(":"), &modelName, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_2$$15, &nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1866 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_1$$15, &manager, "getnamespacealias", &_3, 0, &_2$$15);
			zephir_check_call_status();
			zephir_array_fetch_long(&_4$$15, &nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1866 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&realModelName);
			ZEPHIR_CONCAT_VSV(&realModelName, &_1$$15, "\\", &_4$$15);
		} else {
			ZEPHIR_CPY_WRT(&realModelName, &modelName);
		}
		ZVAL_BOOL(&_5$$14, 1);
		ZEPHIR_CALL_METHOD(&model, &manager, "load", &_6, 0, &realModelName, &_5$$14);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&schema)) {
			ZEPHIR_INIT_NVAR(&completeSource);
			zephir_create_array(&completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&completeSource, &source);
			zephir_array_fast_append(&completeSource, &schema);
		} else {
			ZEPHIR_CPY_WRT(&completeSource, &source);
		}
		ZEPHIR_OBS_NVAR(&alias);
		if (zephir_array_isset_string_fetch(&alias, &selectedModel, SL("alias"), 0)) {
			if (zephir_array_isset(&sqlAliases, &alias)) {
				ZEPHIR_INIT_NVAR(&_7$$20);
				object_init_ex(&_7$$20, phalcon_mvc_model_exception_ce);
				zephir_read_property(&_8$$20, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_LNVAR(_9$$20);
				ZEPHIR_CONCAT_SVSV(&_9$$20, "Alias '", &alias, "' is used more than once, when preparing: ", &_8$$20);
				ZEPHIR_CALL_METHOD(NULL, &_7$$20, "__construct", &_10, 4, &_9$$20);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$20, "phalcon/mvc/model/query.zep", 1890 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModels, &alias, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, &realModelName, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(&completeSource) == IS_ARRAY) {
				zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1902);
			} else {
				ZEPHIR_INIT_NVAR(&completeSource);
				zephir_create_array(&completeSource, 3, 0 TSRMLS_CC);
				zephir_array_fast_append(&completeSource, &source);
				zephir_array_fast_append(&completeSource, &__$null);
				zephir_array_fast_append(&completeSource, &alias);
			}
			zephir_array_update_zval(&models, &realModelName, &alias, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_CPY_WRT(&alias, &source);
			zephir_array_update_zval(&sqlAliases, &realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModels, &realModelName, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, &realModelName, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, &realModelName, &source, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_NVAR(&with);
		if (zephir_array_isset_string_fetch(&with, &selectedModel, SL("with"), 0)) {
			if (!(zephir_array_isset_long(&with, 0))) {
				ZEPHIR_INIT_NVAR(&withs);
				zephir_create_array(&withs, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(&withs, &with);
			} else {
				ZEPHIR_CPY_WRT(&withs, &with);
			}
			zephir_is_iterable(&withs, 0, "phalcon/mvc/model/query.zep", 1972);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&withs), _11$$24)
			{
				ZEPHIR_INIT_NVAR(&withItem);
				ZVAL_COPY(&withItem, _11$$24);
				ZEPHIR_SINIT_NVAR(_12$$27);
				ZVAL_LONG(&_12$$27, number);
				ZEPHIR_INIT_LNVAR(_13$$27);
				ZEPHIR_CONCAT_SV(&_13$$27, "AA", &_12$$27);
				ZEPHIR_CPY_WRT(&joinAlias, &_13$$27);
				ZEPHIR_OBS_NVAR(&relationModel);
				zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1930 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_14, 0, &realModelName, &relationModel);
				zephir_check_call_status();
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_15$$28);
					ZVAL_STRING(&_15$$28, "alias");
					ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_15$$28);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationsbetween", &_16, 0, &realModelName, &relationModel);
					zephir_check_call_status();
					if (Z_TYPE_P(&relation) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_17$$30);
						ZVAL_STRING(&_17$$30, "alias");
						ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_17$$30);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_18$$31);
						object_init_ex(&_18$$31, phalcon_mvc_model_exception_ce);
						zephir_read_property(&_19$$31, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_LNVAR(_20$$31);
						ZEPHIR_CONCAT_SVSVSV(&_20$$31, "Can't find a relationship between '", &realModelName, "' and '", &relationModel, "' when preparing: ", &_19$$31);
						ZEPHIR_CALL_METHOD(NULL, &_18$$31, "__construct", &_10, 4, &_20$$31);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_18$$31, "phalcon/mvc/model/query.zep", 1946 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_INIT_NVAR(&_21$$27);
				zephir_create_array(&_21$$27, 5, 0 TSRMLS_CC);
				add_assoc_long_ex(&_21$$27, SL("type"), 353);
				zephir_array_update_string(&_21$$27, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_21$$27, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_21$$27, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_21$$27, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
				zephir_array_append(&selectColumns, &_21$$27, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1956);
				ZEPHIR_INIT_NVAR(&_22$$27);
				zephir_create_array(&_22$$27, 3, 0 TSRMLS_CC);
				add_assoc_long_ex(&_22$$27, SL("type"), 360);
				ZEPHIR_INIT_NVAR(&_23$$27);
				zephir_create_array(&_23$$27, 2, 0 TSRMLS_CC);
				add_assoc_long_ex(&_23$$27, SL("type"), 355);
				zephir_array_update_string(&_23$$27, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_22$$27, SL("qualified"), &_23$$27, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_23$$27);
				zephir_create_array(&_23$$27, 2, 0 TSRMLS_CC);
				add_assoc_long_ex(&_23$$27, SL("type"), 355);
				zephir_array_update_string(&_23$$27, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_22$$27, SL("alias"), &_23$$27, PH_COPY | PH_SEPARATE);
				zephir_array_append(&automaticJoins, &_22$$27, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1968);
				number++;
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&withItem);
		}
		zephir_array_append(&sqlModels, &realModelName, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1974);
		zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1975);
		zephir_array_update_zval(&modelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&selectedModel);
	if (!(zephir_is_true(merge))) {
		zephir_update_property_zval(this_ptr, SL("_models"), &models);
		zephir_update_property_zval(this_ptr, SL("_modelsInstances"), &modelsInstances);
		zephir_update_property_zval(this_ptr, SL("_sqlAliases"), &sqlAliases);
		zephir_update_property_zval(this_ptr, SL("_sqlAliasesModels"), &sqlAliasesModels);
		zephir_update_property_zval(this_ptr, SL("_sqlModelsAliases"), &sqlModelsAliases);
		zephir_update_property_zval(this_ptr, SL("_sqlAliasesModelsInstances"), &sqlAliasesModelsInstances);
	} else {
		ZEPHIR_OBS_VAR(&tempModels);
		zephir_read_property(&tempModels, this_ptr, SL("_models"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&tempModelsInstances);
		zephir_read_property(&tempModelsInstances, this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&tempSqlAliases);
		zephir_read_property(&tempSqlAliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&tempSqlAliasesModels);
		zephir_read_property(&tempSqlAliasesModels, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&tempSqlModelsAliases);
		zephir_read_property(&tempSqlModelsAliases, this_ptr, SL("_sqlModelsAliases"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&tempSqlAliasesModelsInstances);
		zephir_read_property(&tempSqlAliasesModelsInstances, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_24$$33);
		zephir_read_property(&_25$$33, this_ptr, SL("_models"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_24$$33, &_25$$33, &models TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_models"), &_24$$33);
		ZEPHIR_INIT_VAR(&_26$$33);
		zephir_read_property(&_27$$33, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_26$$33, &_27$$33, &modelsInstances TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_modelsInstances"), &_26$$33);
		ZEPHIR_INIT_VAR(&_28$$33);
		zephir_read_property(&_29$$33, this_ptr, SL("_sqlAliases"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_28$$33, &_29$$33, &sqlAliases TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_sqlAliases"), &_28$$33);
		ZEPHIR_INIT_VAR(&_30$$33);
		zephir_read_property(&_31$$33, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_30$$33, &_31$$33, &sqlAliasesModels TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_sqlAliasesModels"), &_30$$33);
		ZEPHIR_INIT_VAR(&_32$$33);
		zephir_read_property(&_33$$33, this_ptr, SL("_sqlModelsAliases"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_32$$33, &_33$$33, &sqlModelsAliases TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_sqlModelsAliases"), &_32$$33);
		ZEPHIR_INIT_VAR(&_34$$33);
		zephir_read_property(&_35$$33, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_34$$33, &_35$$33, &sqlAliasesModelsInstances TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_sqlAliasesModelsInstances"), &_34$$33);
	}
	ZEPHIR_OBS_VAR(&joins);
	zephir_array_isset_string_fetch(&joins, &select, SL("joins"), 0);
	if (zephir_fast_count_int(&joins TSRMLS_CC)) {
		if (zephir_fast_count_int(&automaticJoins TSRMLS_CC)) {
			if (zephir_array_isset_long(&joins, 0)) {
				ZEPHIR_INIT_VAR(&_36$$36);
				zephir_fast_array_merge(&_36$$36, &joins, &automaticJoins TSRMLS_CC);
				zephir_array_update_string(&select, SL("joins"), &_36$$36, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_append(&automaticJoins, &joins, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2012);
				zephir_array_update_string(&select, SL("joins"), &automaticJoins, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_CALL_METHOD(&sqlJoins, this_ptr, "_getjoins", NULL, 326, &select);
		zephir_check_call_status();
	} else {
		if (zephir_fast_count_int(&automaticJoins TSRMLS_CC)) {
			zephir_array_update_string(&select, SL("joins"), &automaticJoins, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&sqlJoins, this_ptr, "_getjoins", NULL, 326, &select);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&sqlJoins);
			array_init(&sqlJoins);
		}
	}
	position = 0;
	ZEPHIR_INIT_VAR(&sqlColumnAliases);
	array_init(&sqlColumnAliases);
	zephir_is_iterable(&selectColumns, 0, "phalcon/mvc/model/query.zep", 2065);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&selectColumns), _37)
	{
		ZEPHIR_INIT_NVAR(&column);
		ZVAL_COPY(&column, _37);
		ZEPHIR_CALL_METHOD(&_38$$41, this_ptr, "_getselectcolumn", &_39, 327, &column);
		zephir_check_call_status();
		zephir_is_iterable(&_38$$41, 0, "phalcon/mvc/model/query.zep", 2064);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_38$$41), _40$$41)
		{
			ZEPHIR_INIT_NVAR(&sqlColumn);
			ZVAL_COPY(&sqlColumn, _40$$41);
			ZEPHIR_OBS_NVAR(&alias);
			if (zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0)) {
				zephir_array_update_string(&sqlColumn, SL("balias"), &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlColumnAliases, &alias, &__$true, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_OBS_NVAR(&alias);
				if (zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0)) {
					zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_fetch_string(&_41$$46, &sqlColumn, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2054 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(&_41$$46, "scalar")) {
						ZEPHIR_SINIT_NVAR(_42$$47);
						ZVAL_LONG(&_42$$47, position);
						ZEPHIR_INIT_LNVAR(_43$$47);
						ZEPHIR_CONCAT_SV(&_43$$47, "_", &_42$$47);
						zephir_array_update_zval(&sqlColumns, &_43$$47, &sqlColumn, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2057);
					}
				}
			}
			position++;
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&sqlColumn);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&column);
	zephir_update_property_zval(this_ptr, SL("_sqlColumnAliases"), &sqlColumnAliases);
	ZEPHIR_INIT_VAR(&sqlSelect);
	zephir_create_array(&sqlSelect, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&sqlSelect, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlSelect, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlSelect, SL("columns"), &sqlColumns, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&distinct);
	if (zephir_array_isset_string_fetch(&distinct, &select, SL("distinct"), 0)) {
		zephir_array_update_string(&sqlSelect, SL("distinct"), &distinct, PH_COPY | PH_SEPARATE);
	}
	if (zephir_fast_count_int(&sqlJoins TSRMLS_CC)) {
		zephir_array_update_string(&sqlSelect, SL("joins"), &sqlJoins, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&where);
	if (zephir_array_isset_string_fetch(&where, ast, SL("where"), 0)) {
		ZEPHIR_CALL_METHOD(&_44$$51, this_ptr, "_getexpression", NULL, 316, &where);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("where"), &_44$$51, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&groupBy);
	if (zephir_array_isset_string_fetch(&groupBy, ast, SL("groupBy"), 0)) {
		ZEPHIR_CALL_METHOD(&_45$$52, this_ptr, "_getgroupclause", NULL, 328, &groupBy);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("group"), &_45$$52, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&having);
	if (zephir_array_isset_string_fetch(&having, ast, SL("having"), 0)) {
		ZEPHIR_CALL_METHOD(&_46$$53, this_ptr, "_getexpression", NULL, 316, &having);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("having"), &_46$$53, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&order);
	if (zephir_array_isset_string_fetch(&order, ast, SL("orderBy"), 0)) {
		ZEPHIR_CALL_METHOD(&_47$$54, this_ptr, "_getorderclause", NULL, 329, &order);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("order"), &_47$$54, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&limit);
	if (zephir_array_isset_string_fetch(&limit, ast, SL("limit"), 0)) {
		ZEPHIR_CALL_METHOD(&_48$$55, this_ptr, "_getlimitclause", NULL, 330, &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("limit"), &_48$$55, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string(ast, SL("forUpdate"))) {
		zephir_array_update_string(&sqlSelect, SL("forUpdate"), &__$true, PH_COPY | PH_SEPARATE);
	}
	if (zephir_is_true(merge)) {
		zephir_update_property_zval(this_ptr, SL("_models"), &tempModels);
		zephir_update_property_zval(this_ptr, SL("_modelsInstances"), &tempModelsInstances);
		zephir_update_property_zval(this_ptr, SL("_sqlAliases"), &tempSqlAliases);
		zephir_update_property_zval(this_ptr, SL("_sqlAliasesModels"), &tempSqlAliasesModels);
		zephir_update_property_zval(this_ptr, SL("_sqlModelsAliases"), &tempSqlModelsAliases);
		zephir_update_property_zval(this_ptr, SL("_sqlAliasesModelsInstances"), &tempSqlAliasesModelsInstances);
	}
	RETURN_CCTOR(&sqlSelect);

}

/**
 * Analyzes an INSERT intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareInsert) {

	zval _6$$9;
	zend_bool notQuoting = 0;
	zval ast, qualifiedName, nsAlias, manager, modelName, model, source, schema, exprValues, exprValue, sqlInsert, metaData, fields, sqlFields, field, name, realModelName, _3, _4, *_5, _0$$6, _1$$6, _2$$6, _7$$9, _8$$9, _9$$9, *_11$$10, _12$$11, _14$$12, _15$$12, _16$$12;
	zephir_fcall_cache_entry *_10 = NULL, *_13 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ast);
	ZVAL_UNDEF(&qualifiedName);
	ZVAL_UNDEF(&nsAlias);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&exprValues);
	ZVAL_UNDEF(&exprValue);
	ZVAL_UNDEF(&sqlInsert);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&sqlFields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&realModelName);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_6$$9);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&ast);
	zephir_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	if (!(zephir_array_isset_string(&ast, SL("qualifiedName")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST", "phalcon/mvc/model/query.zep", 2137);
		return;
	}
	if (!(zephir_array_isset_string(&ast, SL("values")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST", "phalcon/mvc/model/query.zep", 2141);
		return;
	}
	ZEPHIR_OBS_VAR(&qualifiedName);
	zephir_array_fetch_string(&qualifiedName, &ast, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 2144 TSRMLS_CC);
	if (!(zephir_array_isset_string(&qualifiedName, SL("name")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST", "phalcon/mvc/model/query.zep", 2148);
		return;
	}
	ZEPHIR_OBS_VAR(&manager);
	zephir_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&modelName);
	zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2152 TSRMLS_CC);
	if (zephir_memnstr_str(&modelName, SL(":"), "phalcon/mvc/model/query.zep", 2155)) {
		ZEPHIR_INIT_VAR(&nsAlias);
		zephir_fast_explode_str(&nsAlias, SL(":"), &modelName, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_1$$6, &nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2157 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_0$$6, &manager, "getnamespacealias", NULL, 0, &_1$$6);
		zephir_check_call_status();
		zephir_array_fetch_long(&_2$$6, &nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2157 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&realModelName);
		ZEPHIR_CONCAT_VSV(&realModelName, &_0$$6, "\\", &_2$$6);
	} else {
		ZEPHIR_CPY_WRT(&realModelName, &modelName);
	}
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(&model, &manager, "load", NULL, 0, &realModelName, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_NVAR(&source);
		zephir_create_array(&source, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&source, &schema);
		zephir_array_fast_append(&source, &source);
	}
	notQuoting = 0;
	ZEPHIR_INIT_VAR(&exprValues);
	array_init(&exprValues);
	zephir_array_fetch_string(&_4, &ast, SL("values"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2173 TSRMLS_CC);
	zephir_is_iterable(&_4, 0, "phalcon/mvc/model/query.zep", 2182);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
	{
		ZEPHIR_INIT_NVAR(&exprValue);
		ZVAL_COPY(&exprValue, _5);
		ZEPHIR_INIT_NVAR(&_6$$9);
		zephir_create_array(&_6$$9, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&_7$$9);
		zephir_array_fetch_string(&_7$$9, &exprValue, SL("type"), PH_NOISY, "phalcon/mvc/model/query.zep", 2177 TSRMLS_CC);
		zephir_array_update_string(&_6$$9, SL("type"), &_7$$9, PH_COPY | PH_SEPARATE);
		if (notQuoting) {
			ZVAL_BOOL(&_9$$9, 1);
		} else {
			ZVAL_BOOL(&_9$$9, 0);
		}
		ZEPHIR_CALL_METHOD(&_8$$9, this_ptr, "_getexpression", &_10, 316, &exprValue, &_9$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_6$$9, SL("value"), &_8$$9, PH_COPY | PH_SEPARATE);
		zephir_array_append(&exprValues, &_6$$9, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2179);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&exprValue);
	ZEPHIR_INIT_VAR(&sqlInsert);
	zephir_create_array(&sqlInsert, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&sqlInsert, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlInsert, SL("table"), &source, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&metaData);
	zephir_read_property(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&fields);
	if (zephir_array_isset_string_fetch(&fields, &ast, SL("fields"), 0)) {
		ZEPHIR_INIT_VAR(&sqlFields);
		array_init(&sqlFields);
		zephir_is_iterable(&fields, 0, "phalcon/mvc/model/query.zep", 2206);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _11$$10)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _11$$10);
			ZEPHIR_OBS_NVAR(&name);
			zephir_array_fetch_string(&name, &field, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2193 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_12$$11, &metaData, "hasattribute", &_13, 0, &model, &name);
			zephir_check_call_status();
			if (!(zephir_is_true(&_12$$11))) {
				ZEPHIR_INIT_NVAR(&_14$$12);
				object_init_ex(&_14$$12, phalcon_mvc_model_exception_ce);
				zephir_read_property(&_15$$12, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_LNVAR(_16$$12);
				ZEPHIR_CONCAT_SVSVSV(&_16$$12, "The model '", &modelName, "' doesn't have the attribute '", &name, "', when preparing: ", &_15$$12);
				ZEPHIR_CALL_METHOD(NULL, &_14$$12, "__construct", &_17, 4, &_16$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_14$$12, "phalcon/mvc/model/query.zep", 2199 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&sqlFields, &name, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2203);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&field);
		zephir_array_update_string(&sqlInsert, SL("fields"), &sqlFields, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_string(&sqlInsert, SL("values"), &exprValues, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&sqlInsert);

}

/**
 * Analyzes an UPDATE intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareUpdate) {

	zval _12$$17;
	zend_bool notQuoting = 0;
	zval __$null, ast, update, tables, values, modelsInstances, models, sqlTables, sqlAliases, sqlAliasesModelsInstances, updateTables, nsAlias, realModelName, completeSource, sqlModels, manager, table, qualifiedName, modelName, model, source, schema, alias, sqlFields, sqlValues, updateValues, updateValue, exprColumn, sqlUpdate, where, limit, *_0, *_7, _1$$9, _2$$9, _4$$9, _5$$8, _8$$17, _9$$17, _10$$17, _13$$17, _14$$17, _15$$17, _16$$18, _17$$18, _18$$19;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&ast);
	ZVAL_UNDEF(&update);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&modelsInstances);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&sqlTables);
	ZVAL_UNDEF(&sqlAliases);
	ZVAL_UNDEF(&sqlAliasesModelsInstances);
	ZVAL_UNDEF(&updateTables);
	ZVAL_UNDEF(&nsAlias);
	ZVAL_UNDEF(&realModelName);
	ZVAL_UNDEF(&completeSource);
	ZVAL_UNDEF(&sqlModels);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&qualifiedName);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&sqlFields);
	ZVAL_UNDEF(&sqlValues);
	ZVAL_UNDEF(&updateValues);
	ZVAL_UNDEF(&updateValue);
	ZVAL_UNDEF(&exprColumn);
	ZVAL_UNDEF(&sqlUpdate);
	ZVAL_UNDEF(&where);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&_1$$9);
	ZVAL_UNDEF(&_2$$9);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_8$$17);
	ZVAL_UNDEF(&_9$$17);
	ZVAL_UNDEF(&_10$$17);
	ZVAL_UNDEF(&_13$$17);
	ZVAL_UNDEF(&_14$$17);
	ZVAL_UNDEF(&_15$$17);
	ZVAL_UNDEF(&_16$$18);
	ZVAL_UNDEF(&_17$$18);
	ZVAL_UNDEF(&_18$$19);
	ZVAL_UNDEF(&_12$$17);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&ast);
	zephir_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&update);
	if (!(zephir_array_isset_string_fetch(&update, &ast, SL("update"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST", "phalcon/mvc/model/query.zep", 2230);
		return;
	}
	ZEPHIR_OBS_VAR(&tables);
	if (!(zephir_array_isset_string_fetch(&tables, &update, SL("tables"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST", "phalcon/mvc/model/query.zep", 2234);
		return;
	}
	ZEPHIR_OBS_VAR(&values);
	if (!(zephir_array_isset_string_fetch(&values, &update, SL("values"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST", "phalcon/mvc/model/query.zep", 2238);
		return;
	}
	ZEPHIR_INIT_VAR(&models);
	array_init(&models);
	ZEPHIR_INIT_VAR(&modelsInstances);
	array_init(&modelsInstances);
	ZEPHIR_INIT_VAR(&sqlTables);
	array_init(&sqlTables);
	ZEPHIR_INIT_VAR(&sqlModels);
	array_init(&sqlModels);
	ZEPHIR_INIT_VAR(&sqlAliases);
	array_init(&sqlAliases);
	ZEPHIR_INIT_VAR(&sqlAliasesModelsInstances);
	array_init(&sqlAliasesModelsInstances);
	if (!(zephir_array_isset_long(&tables, 0))) {
		ZEPHIR_INIT_VAR(&updateTables);
		zephir_create_array(&updateTables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&updateTables, &tables);
	} else {
		ZEPHIR_CPY_WRT(&updateTables, &tables);
	}
	ZEPHIR_OBS_VAR(&manager);
	zephir_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	zephir_is_iterable(&updateTables, 0, "phalcon/mvc/model/query.zep", 2313);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&updateTables), _0)
	{
		ZEPHIR_INIT_NVAR(&table);
		ZVAL_COPY(&table, _0);
		ZEPHIR_OBS_NVAR(&qualifiedName);
		zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 2261 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&modelName);
		zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2262 TSRMLS_CC);
		if (zephir_memnstr_str(&modelName, SL(":"), "phalcon/mvc/model/query.zep", 2267)) {
			ZEPHIR_INIT_NVAR(&nsAlias);
			zephir_fast_explode_str(&nsAlias, SL(":"), &modelName, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_2$$9, &nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2269 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_1$$9, &manager, "getnamespacealias", &_3, 0, &_2$$9);
			zephir_check_call_status();
			zephir_array_fetch_long(&_4$$9, &nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2269 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&realModelName);
			ZEPHIR_CONCAT_VSV(&realModelName, &_1$$9, "\\", &_4$$9);
		} else {
			ZEPHIR_CPY_WRT(&realModelName, &modelName);
		}
		ZVAL_BOOL(&_5$$8, 1);
		ZEPHIR_CALL_METHOD(&model, &manager, "load", &_6, 0, &realModelName, &_5$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&completeSource);
		if (zephir_is_true(&schema)) {
			zephir_create_array(&completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&completeSource, &source);
			zephir_array_fast_append(&completeSource, &schema);
		} else {
			zephir_create_array(&completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&completeSource, &source);
			zephir_array_fast_append(&completeSource, &__$null);
		}
		ZEPHIR_OBS_NVAR(&alias);
		if (zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0)) {
			zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2295);
			zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2296);
			zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, &alias, &realModelName, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&sqlAliases, &realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2302);
			zephir_array_update_zval(&models, &realModelName, &source, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&sqlModels, &realModelName, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2306);
		zephir_array_update_zval(&modelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&table);
	zephir_update_property_zval(this_ptr, SL("_models"), &models);
	zephir_update_property_zval(this_ptr, SL("_modelsInstances"), &modelsInstances);
	zephir_update_property_zval(this_ptr, SL("_sqlAliases"), &sqlAliases);
	zephir_update_property_zval(this_ptr, SL("_sqlAliasesModelsInstances"), &sqlAliasesModelsInstances);
	ZEPHIR_INIT_VAR(&sqlFields);
	array_init(&sqlFields);
	ZEPHIR_INIT_VAR(&sqlValues);
	array_init(&sqlValues);
	if (!(zephir_array_isset_long(&values, 0))) {
		ZEPHIR_INIT_VAR(&updateValues);
		zephir_create_array(&updateValues, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&updateValues, &values);
	} else {
		ZEPHIR_CPY_WRT(&updateValues, &values);
	}
	notQuoting = 0;
	zephir_is_iterable(&updateValues, 0, "phalcon/mvc/model/query.zep", 2337);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&updateValues), _7)
	{
		ZEPHIR_INIT_NVAR(&updateValue);
		ZVAL_COPY(&updateValue, _7);
		zephir_array_fetch_string(&_9$$17, &updateValue, SL("column"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2329 TSRMLS_CC);
		if (notQuoting) {
			ZVAL_BOOL(&_10$$17, 1);
		} else {
			ZVAL_BOOL(&_10$$17, 0);
		}
		ZEPHIR_CALL_METHOD(&_8$$17, this_ptr, "_getexpression", &_11, 316, &_9$$17, &_10$$17);
		zephir_check_call_status();
		zephir_array_append(&sqlFields, &_8$$17, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2329);
		ZEPHIR_OBS_NVAR(&exprColumn);
		zephir_array_fetch_string(&exprColumn, &updateValue, SL("expr"), PH_NOISY, "phalcon/mvc/model/query.zep", 2330 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_12$$17);
		zephir_create_array(&_12$$17, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&_13$$17);
		zephir_array_fetch_string(&_13$$17, &exprColumn, SL("type"), PH_NOISY, "phalcon/mvc/model/query.zep", 2332 TSRMLS_CC);
		zephir_array_update_string(&_12$$17, SL("type"), &_13$$17, PH_COPY | PH_SEPARATE);
		if (notQuoting) {
			ZVAL_BOOL(&_15$$17, 1);
		} else {
			ZVAL_BOOL(&_15$$17, 0);
		}
		ZEPHIR_CALL_METHOD(&_14$$17, this_ptr, "_getexpression", &_11, 316, &exprColumn, &_15$$17);
		zephir_check_call_status();
		zephir_array_update_string(&_12$$17, SL("value"), &_14$$17, PH_COPY | PH_SEPARATE);
		zephir_array_append(&sqlValues, &_12$$17, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2334);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&updateValue);
	ZEPHIR_INIT_VAR(&sqlUpdate);
	zephir_create_array(&sqlUpdate, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&sqlUpdate, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("fields"), &sqlFields, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("values"), &sqlValues, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&where);
	if (zephir_array_isset_string_fetch(&where, &ast, SL("where"), 0)) {
		ZVAL_BOOL(&_17$$18, 1);
		ZEPHIR_CALL_METHOD(&_16$$18, this_ptr, "_getexpression", &_11, 316, &where, &_17$$18);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("where"), &_16$$18, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&limit);
	if (zephir_array_isset_string_fetch(&limit, &ast, SL("limit"), 0)) {
		ZEPHIR_CALL_METHOD(&_18$$19, this_ptr, "_getlimitclause", NULL, 330, &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("limit"), &_18$$19, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&sqlUpdate);

}

/**
 * Analyzes a DELETE intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareDelete) {

	zval __$null, ast, delete, tables, models, modelsInstances, sqlTables, sqlModels, sqlAliases, sqlAliasesModelsInstances, deleteTables, manager, table, qualifiedName, modelName, nsAlias, realModelName, model, source, schema, completeSource, alias, sqlDelete, where, limit, *_0, _1$$8, _2$$8, _4$$8, _5$$7, _7$$14, _8$$14, _9$$15;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&ast);
	ZVAL_UNDEF(&delete);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&modelsInstances);
	ZVAL_UNDEF(&sqlTables);
	ZVAL_UNDEF(&sqlModels);
	ZVAL_UNDEF(&sqlAliases);
	ZVAL_UNDEF(&sqlAliasesModelsInstances);
	ZVAL_UNDEF(&deleteTables);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&qualifiedName);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&nsAlias);
	ZVAL_UNDEF(&realModelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&completeSource);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&sqlDelete);
	ZVAL_UNDEF(&where);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&_1$$8);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$14);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_9$$15);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&ast);
	zephir_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&delete);
	if (!(zephir_array_isset_string_fetch(&delete, &ast, SL("delete"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST", "phalcon/mvc/model/query.zep", 2369);
		return;
	}
	ZEPHIR_OBS_VAR(&tables);
	if (!(zephir_array_isset_string_fetch(&tables, &delete, SL("tables"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST", "phalcon/mvc/model/query.zep", 2373);
		return;
	}
	ZEPHIR_INIT_VAR(&models);
	array_init(&models);
	ZEPHIR_INIT_VAR(&modelsInstances);
	array_init(&modelsInstances);
	ZEPHIR_INIT_VAR(&sqlTables);
	array_init(&sqlTables);
	ZEPHIR_INIT_VAR(&sqlModels);
	array_init(&sqlModels);
	ZEPHIR_INIT_VAR(&sqlAliases);
	array_init(&sqlAliases);
	ZEPHIR_INIT_VAR(&sqlAliasesModelsInstances);
	array_init(&sqlAliasesModelsInstances);
	if (!(zephir_array_isset_long(&tables, 0))) {
		ZEPHIR_INIT_VAR(&deleteTables);
		zephir_create_array(&deleteTables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&deleteTables, &tables);
	} else {
		ZEPHIR_CPY_WRT(&deleteTables, &tables);
	}
	ZEPHIR_OBS_VAR(&manager);
	zephir_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	zephir_is_iterable(&deleteTables, 0, "phalcon/mvc/model/query.zep", 2443);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&deleteTables), _0)
	{
		ZEPHIR_INIT_NVAR(&table);
		ZVAL_COPY(&table, _0);
		ZEPHIR_OBS_NVAR(&qualifiedName);
		zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 2397 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&modelName);
		zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2398 TSRMLS_CC);
		if (zephir_memnstr_str(&modelName, SL(":"), "phalcon/mvc/model/query.zep", 2403)) {
			ZEPHIR_INIT_NVAR(&nsAlias);
			zephir_fast_explode_str(&nsAlias, SL(":"), &modelName, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_2$$8, &nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2405 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_1$$8, &manager, "getnamespacealias", &_3, 0, &_2$$8);
			zephir_check_call_status();
			zephir_array_fetch_long(&_4$$8, &nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2405 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&realModelName);
			ZEPHIR_CONCAT_VSV(&realModelName, &_1$$8, "\\", &_4$$8);
		} else {
			ZEPHIR_CPY_WRT(&realModelName, &modelName);
		}
		ZVAL_BOOL(&_5$$7, 1);
		ZEPHIR_CALL_METHOD(&model, &manager, "load", &_6, 0, &realModelName, &_5$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&completeSource);
		if (zephir_is_true(&schema)) {
			zephir_create_array(&completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&completeSource, &source);
			zephir_array_fast_append(&completeSource, &schema);
		} else {
			zephir_create_array(&completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&completeSource, &source);
			zephir_array_fast_append(&completeSource, &__$null);
		}
		ZEPHIR_OBS_NVAR(&alias);
		if (zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0)) {
			zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2425);
			zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2426);
			zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, &alias, &realModelName, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&sqlAliases, &realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2432);
			zephir_array_update_zval(&models, &realModelName, &source, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&sqlModels, &realModelName, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2436);
		zephir_array_update_zval(&modelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&table);
	zephir_update_property_zval(this_ptr, SL("_models"), &models);
	zephir_update_property_zval(this_ptr, SL("_modelsInstances"), &modelsInstances);
	zephir_update_property_zval(this_ptr, SL("_sqlAliases"), &sqlAliases);
	zephir_update_property_zval(this_ptr, SL("_sqlAliasesModelsInstances"), &sqlAliasesModelsInstances);
	ZEPHIR_INIT_VAR(&sqlDelete);
	array_init(&sqlDelete);
	zephir_array_update_string(&sqlDelete, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlDelete, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&where);
	if (zephir_array_isset_string_fetch(&where, &ast, SL("where"), 0)) {
		ZVAL_BOOL(&_8$$14, 1);
		ZEPHIR_CALL_METHOD(&_7$$14, this_ptr, "_getexpression", NULL, 316, &where, &_8$$14);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("where"), &_7$$14, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&limit);
	if (zephir_array_isset_string_fetch(&limit, &ast, SL("limit"), 0)) {
		ZEPHIR_CALL_METHOD(&_9$$15, this_ptr, "_getlimitclause", NULL, 330, &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("limit"), &_9$$15, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&sqlDelete);

}

/**
 * Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang generating another
 * intermediate representation that could be executed by Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, parse) {

	zval intermediate, phql, ast, irPhql, uniqueId, type, _0$$5, _1$$7, _2$$13, _3$$13;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&phql);
	ZVAL_UNDEF(&ast);
	ZVAL_UNDEF(&irPhql);
	ZVAL_UNDEF(&uniqueId);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&_2$$13);
	ZVAL_UNDEF(&_3$$13);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&intermediate);
	zephir_read_property(&intermediate, this_ptr, SL("_intermediate"), PH_NOISY_CC);
	if (Z_TYPE_P(&intermediate) == IS_ARRAY) {
		RETURN_CCTOR(&intermediate);
	}
	ZEPHIR_OBS_VAR(&phql);
	zephir_read_property(&phql, this_ptr, SL("_phql"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&ast);
	ZEPHIR_LAST_CALL_STATUS = phql_parse_phql(&ast, &phql TSRMLS_CC);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&irPhql);
	ZVAL_NULL(&irPhql);
	ZEPHIR_INIT_VAR(&uniqueId);
	ZVAL_NULL(&uniqueId);
	if (Z_TYPE_P(&ast) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(&uniqueId);
		if (zephir_array_isset_string_fetch(&uniqueId, &ast, SL("id"), 0)) {
			ZEPHIR_OBS_NVAR(&irPhql);
			zephir_read_static_property_ce(&_0$$5, phalcon_mvc_model_query_ce, SL("_irPhqlCache"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset_fetch(&irPhql, &_0$$5, &uniqueId, 0 TSRMLS_CC)) {
				if (Z_TYPE_P(&irPhql) == IS_ARRAY) {
					zephir_array_fetch_string(&_1$$7, &ast, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2494 TSRMLS_CC);
					zephir_update_property_zval(this_ptr, SL("_type"), &_1$$7);
					RETURN_CCTOR(&irPhql);
				}
			}
		}
		ZEPHIR_OBS_VAR(&type);
		if (zephir_array_isset_string_fetch(&type, &ast, SL("type"), 0)) {
			zephir_update_property_zval(this_ptr, SL("_ast"), &ast);
			zephir_update_property_zval(this_ptr, SL("_type"), &type);
			do {
				if (ZEPHIR_IS_LONG(&type, 309)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_prepareselect", NULL, 321);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 306)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_prepareinsert", NULL, 331);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 300)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_prepareupdate", NULL, 332);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 303)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_preparedelete", NULL, 333);
					zephir_check_call_status();
					break;
				}
				ZEPHIR_INIT_VAR(&_2$$13);
				object_init_ex(&_2$$13, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_3$$13);
				ZEPHIR_CONCAT_SVSV(&_3$$13, "Unknown statement ", &type, ", when preparing: ", &phql);
				ZEPHIR_CALL_METHOD(NULL, &_2$$13, "__construct", NULL, 4, &_3$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_2$$13, "phalcon/mvc/model/query.zep", 2527 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} while(0);

		}
	}
	if (Z_TYPE_P(&irPhql) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted AST", "phalcon/mvc/model/query.zep", 2533);
		return;
	}
	if (Z_TYPE_P(&uniqueId) == IS_LONG) {
		zephir_update_static_property_array_multi_ce(phalcon_mvc_model_query_ce, SL("_irPhqlCache"), &irPhql TSRMLS_CC, SL("z"), 1, &uniqueId);
	}
	zephir_update_property_zval(this_ptr, SL("_intermediate"), &irPhql);
	RETURN_CCTOR(&irPhql);

}

/**
 * Returns the current cache backend instance
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getCache) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_cache");

}

/**
 * Executes the SELECT intermediate representation producing a Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeSelect) {

	zend_class_entry *_55$$63;
	zval _17$$25, _23$$28, _39$$59, _44$$61;
	zend_string *_10, *_27$$35, *_31$$41, *_43$$60;
	zend_ulong _9, _26$$35, _30$$41, _42$$60;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberObjects = 0;
	zend_bool simulate, haveObjects = 0, haveScalars = 0, isComplex = 0, isSimpleStd = 0, isKeepingSnapshots = 0, _35, _24$$19, _47$$51;
	zval *intermediate, intermediate_sub, *bindParams, bindParams_sub, *bindTypes, bindTypes_sub, *simulate_param = NULL, __$true, __$null, manager, modelName, models, model, connection, connectionTypes, columns, column, selectColumns, simpleColumnMap, metaData, aliasCopy, sqlColumn, attributes, instance, columnMap, attribute, columnAlias, sqlAlias, dialect, sqlSelect, bindCounts, processed, wildcard, value, processedTypes, typeWildcard, result, resultData, cache, resultObject, columns1, typesColumnMap, wildcardValue, resultsetClassName, *_0, *_6, *_8, _33, _36, _1$$3, _2$$4, _5$$5, _7$$7, _11$$19, _12$$20, *_16$$22, _19$$22, _18$$25, _21$$26, *_22$$27, *_25$$35, _28$$39, *_29$$41, _32$$43, _34$$47, _37$$58, *_38$$58, _40$$59, *_41$$60, _45$$61, _46$$53, _57$$51, _48$$64, _49$$64, _50$$63, _51$$63, _54$$63, _56$$63, _52$$65, _53$$65;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate_sub);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&connectionTypes);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&selectColumns);
	ZVAL_UNDEF(&simpleColumnMap);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&aliasCopy);
	ZVAL_UNDEF(&sqlColumn);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&columnAlias);
	ZVAL_UNDEF(&sqlAlias);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&sqlSelect);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&processed);
	ZVAL_UNDEF(&wildcard);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&processedTypes);
	ZVAL_UNDEF(&typeWildcard);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&resultData);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&resultObject);
	ZVAL_UNDEF(&columns1);
	ZVAL_UNDEF(&typesColumnMap);
	ZVAL_UNDEF(&wildcardValue);
	ZVAL_UNDEF(&resultsetClassName);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_11$$19);
	ZVAL_UNDEF(&_12$$20);
	ZVAL_UNDEF(&_19$$22);
	ZVAL_UNDEF(&_18$$25);
	ZVAL_UNDEF(&_21$$26);
	ZVAL_UNDEF(&_28$$39);
	ZVAL_UNDEF(&_32$$43);
	ZVAL_UNDEF(&_34$$47);
	ZVAL_UNDEF(&_37$$58);
	ZVAL_UNDEF(&_40$$59);
	ZVAL_UNDEF(&_45$$61);
	ZVAL_UNDEF(&_46$$53);
	ZVAL_UNDEF(&_57$$51);
	ZVAL_UNDEF(&_48$$64);
	ZVAL_UNDEF(&_49$$64);
	ZVAL_UNDEF(&_50$$63);
	ZVAL_UNDEF(&_51$$63);
	ZVAL_UNDEF(&_54$$63);
	ZVAL_UNDEF(&_56$$63);
	ZVAL_UNDEF(&_52$$65);
	ZVAL_UNDEF(&_53$$65);
	ZVAL_UNDEF(&_17$$25);
	ZVAL_UNDEF(&_23$$28);
	ZVAL_UNDEF(&_39$$59);
	ZVAL_UNDEF(&_44$$61);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &intermediate, &bindParams, &bindTypes, &simulate_param);

	ZEPHIR_SEPARATE_PARAM(intermediate);
	if (!simulate_param) {
		simulate = 0;
	} else {
		simulate = zephir_get_boolval(simulate_param);
	}


	ZEPHIR_OBS_VAR(&manager);
	zephir_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&connectionTypes);
	array_init(&connectionTypes);
	ZEPHIR_OBS_VAR(&models);
	zephir_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 2576 TSRMLS_CC);
	zephir_is_iterable(&models, 0, "phalcon/mvc/model/query.zep", 2597);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&models), _0)
	{
		ZEPHIR_INIT_NVAR(&modelName);
		ZVAL_COPY(&modelName, _0);
		ZEPHIR_OBS_NVAR(&model);
		zephir_read_property(&_1$$3, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset_fetch(&model, &_1$$3, &modelName, 0 TSRMLS_CC))) {
			ZVAL_BOOL(&_2$$4, 1);
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_3, 0, &modelName, &_2$$4);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("_modelsInstances"), &modelName, &model TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&connection, this_ptr, "getreadconnection", &_4, 0, &model, intermediate, bindParams, bindTypes);
		zephir_check_call_status();
		if (Z_TYPE_P(&connection) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_5$$5, &connection, "gettype", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_zval(&connectionTypes, &_5$$5, &__$true, PH_COPY | PH_SEPARATE);
			if (zephir_fast_count_int(&connectionTypes TSRMLS_CC) == 2) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cannot use models of different database systems in the same query", "phalcon/mvc/model/query.zep", 2592);
				return;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&modelName);
	ZEPHIR_OBS_VAR(&columns);
	zephir_array_fetch_string(&columns, intermediate, SL("columns"), PH_NOISY, "phalcon/mvc/model/query.zep", 2597 TSRMLS_CC);
	haveObjects = 0;
	haveScalars = 0;
	isComplex = 0;
	numberObjects = 0;
	ZEPHIR_CPY_WRT(&columns1, &columns);
	zephir_is_iterable(&columns, 0, "phalcon/mvc/model/query.zep", 2624);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _6)
	{
		ZEPHIR_INIT_NVAR(&column);
		ZVAL_COPY(&column, _6);
		if (Z_TYPE_P(&column) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid column definition", "phalcon/mvc/model/query.zep", 2610);
			return;
		}
		zephir_array_fetch_string(&_7$$7, &column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2613 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_7$$7, "scalar")) {
			if (!(zephir_array_isset_string(&column, SL("balias")))) {
				isComplex = 1;
			}
			haveScalars = 1;
		} else {
			haveObjects = 1;
			numberObjects++;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&column);
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
	ZEPHIR_INIT_VAR(&instance);
	ZVAL_NULL(&instance);
	ZEPHIR_INIT_VAR(&selectColumns);
	array_init(&selectColumns);
	ZEPHIR_INIT_VAR(&simpleColumnMap);
	array_init(&simpleColumnMap);
	ZEPHIR_OBS_VAR(&metaData);
	zephir_read_property(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	zephir_is_iterable(&columns, 0, "phalcon/mvc/model/query.zep", 2723);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columns), _9, _10, _8)
	{
		ZEPHIR_INIT_NVAR(&aliasCopy);
		if (_10 != NULL) { 
			ZVAL_STR_COPY(&aliasCopy, _10);
		} else {
			ZVAL_LONG(&aliasCopy, _9);
		}
		ZEPHIR_INIT_NVAR(&column);
		ZVAL_COPY(&column, _8);
		ZEPHIR_OBS_NVAR(&sqlColumn);
		zephir_array_fetch_string(&sqlColumn, &column, SL("column"), PH_NOISY, "phalcon/mvc/model/query.zep", 2648 TSRMLS_CC);
		zephir_array_fetch_string(&_11$$19, &column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2651 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_11$$19, "object")) {
			ZEPHIR_OBS_NVAR(&modelName);
			zephir_array_fetch_string(&modelName, &column, SL("model"), PH_NOISY, "phalcon/mvc/model/query.zep", 2653 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&instance);
			zephir_read_property(&_12$$20, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset_fetch(&instance, &_12$$20, &modelName, 0 TSRMLS_CC))) {
				ZEPHIR_CALL_METHOD(&instance, &manager, "load", &_13, 0, &modelName);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("_modelsInstances"), &modelName, &instance TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&attributes, &metaData, "getattributes", &_14, 0, &instance);
			zephir_check_call_status();
			if (isComplex == 1) {
				if (ZEPHIR_GLOBAL(orm).column_renaming) {
					ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", &_15, 0, &instance);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&columnMap);
					ZVAL_NULL(&columnMap);
				}
				zephir_is_iterable(&attributes, 0, "phalcon/mvc/model/query.zep", 2679);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _16$$22)
				{
					ZEPHIR_INIT_NVAR(&attribute);
					ZVAL_COPY(&attribute, _16$$22);
					ZEPHIR_INIT_NVAR(&_17$$25);
					zephir_create_array(&_17$$25, 3, 0 TSRMLS_CC);
					zephir_array_fast_append(&_17$$25, &attribute);
					zephir_array_fast_append(&_17$$25, &sqlColumn);
					ZEPHIR_INIT_LNVAR(_18$$25);
					ZEPHIR_CONCAT_SVSV(&_18$$25, "_", &sqlColumn, "_", &attribute);
					zephir_array_fast_append(&_17$$25, &_18$$25);
					zephir_array_append(&selectColumns, &_17$$25, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2675);
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&attribute);
				zephir_array_update_multi(&columns1, &instance TSRMLS_CC, SL("zs"), 3, &aliasCopy, SL("instance"));
				zephir_array_update_multi(&columns1, &attributes TSRMLS_CC, SL("zs"), 3, &aliasCopy, SL("attributes"));
				zephir_array_update_multi(&columns1, &columnMap TSRMLS_CC, SL("zs"), 3, &aliasCopy, SL("columnMap"));
				ZEPHIR_CALL_METHOD(&_19$$22, &manager, "iskeepingsnapshots", &_20, 0, &instance);
				zephir_check_call_status();
				isKeepingSnapshots = zephir_get_boolval(&_19$$22);
				if (isKeepingSnapshots) {
					ZEPHIR_INIT_NVAR(&_21$$26);
					ZVAL_BOOL(&_21$$26, isKeepingSnapshots);
					zephir_array_update_multi(&columns1, &_21$$26 TSRMLS_CC, SL("zs"), 3, &aliasCopy, SL("keepSnapshots"));
				}
			} else {
				zephir_is_iterable(&attributes, 0, "phalcon/mvc/model/query.zep", 2697);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _22$$27)
				{
					ZEPHIR_INIT_NVAR(&attribute);
					ZVAL_COPY(&attribute, _22$$27);
					ZEPHIR_INIT_NVAR(&_23$$28);
					zephir_create_array(&_23$$28, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_23$$28, &attribute);
					zephir_array_fast_append(&_23$$28, &sqlColumn);
					zephir_array_append(&selectColumns, &_23$$28, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2695);
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&attribute);
			}
		} else {
			ZEPHIR_INIT_NVAR(&columnAlias);
			if (Z_TYPE_P(&aliasCopy) == IS_LONG) {
				zephir_create_array(&columnAlias, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(&columnAlias, &sqlColumn);
				zephir_array_fast_append(&columnAlias, &__$null);
			} else {
				zephir_create_array(&columnAlias, 3, 0 TSRMLS_CC);
				zephir_array_fast_append(&columnAlias, &sqlColumn);
				zephir_array_fast_append(&columnAlias, &__$null);
				zephir_array_fast_append(&columnAlias, &aliasCopy);
			}
			zephir_array_append(&selectColumns, &columnAlias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2708);
		}
		_24$$19 = isComplex == 0;
		if (_24$$19) {
			_24$$19 = isSimpleStd == 1;
		}
		if (_24$$19) {
			ZEPHIR_OBS_NVAR(&sqlAlias);
			if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
				zephir_array_update_zval(&simpleColumnMap, &sqlAlias, &aliasCopy, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&simpleColumnMap, &aliasCopy, &aliasCopy, PH_COPY | PH_SEPARATE);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&column);
	ZEPHIR_INIT_NVAR(&aliasCopy);
	ZEPHIR_INIT_VAR(&bindCounts);
	array_init(&bindCounts);
	zephir_array_update_string(intermediate, SL("columns"), &selectColumns, PH_COPY | PH_SEPARATE);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&processed);
		array_init(&processed);
		zephir_is_iterable(bindParams, 0, "phalcon/mvc/model/query.zep", 2744);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(bindParams), _26$$35, _27$$35, _25$$35)
		{
			ZEPHIR_INIT_NVAR(&wildcard);
			if (_27$$35 != NULL) { 
				ZVAL_STR_COPY(&wildcard, _27$$35);
			} else {
				ZVAL_LONG(&wildcard, _26$$35);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _25$$35);
			if (Z_TYPE_P(&wildcard) == IS_LONG) {
				ZEPHIR_INIT_NVAR(&wildcardValue);
				ZEPHIR_CONCAT_SV(&wildcardValue, ":", &wildcard);
			} else {
				ZEPHIR_CPY_WRT(&wildcardValue, &wildcard);
			}
			zephir_array_update_zval(&processed, &wildcardValue, &value, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_28$$39);
				ZVAL_LONG(&_28$$39, zephir_fast_count_int(&value TSRMLS_CC));
				zephir_array_update_zval(&bindCounts, &wildcardValue, &_28$$39, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&wildcard);
	} else {
		ZEPHIR_CPY_WRT(&processed, bindParams);
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&processedTypes);
		array_init(&processedTypes);
		zephir_is_iterable(bindTypes, 0, "phalcon/mvc/model/query.zep", 2760);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(bindTypes), _30$$41, _31$$41, _29$$41)
		{
			ZEPHIR_INIT_NVAR(&typeWildcard);
			if (_31$$41 != NULL) { 
				ZVAL_STR_COPY(&typeWildcard, _31$$41);
			} else {
				ZVAL_LONG(&typeWildcard, _30$$41);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _29$$41);
			if (Z_TYPE_P(&typeWildcard) == IS_LONG) {
				ZEPHIR_INIT_LNVAR(_32$$43);
				ZEPHIR_CONCAT_SV(&_32$$43, ":", &typeWildcard);
				zephir_array_update_zval(&processedTypes, &_32$$43, &value, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&processedTypes, &typeWildcard, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&typeWildcard);
	} else {
		ZEPHIR_CPY_WRT(&processedTypes, bindTypes);
	}
	if (zephir_fast_count_int(&bindCounts TSRMLS_CC)) {
		zephir_array_update_string(intermediate, SL("bindCounts"), &bindCounts, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&dialect, &connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&sqlSelect, &dialect, "select", NULL, 0, intermediate);
	zephir_check_call_status();
	zephir_read_property(&_33, this_ptr, SL("_sharedLock"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_33)) {
		ZEPHIR_CALL_METHOD(&_34$$47, &dialect, "sharedlock", NULL, 0, &sqlSelect);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&sqlSelect, &_34$$47);
	}
	if (simulate) {
		zephir_create_array(return_value, 3, 0 TSRMLS_CC);
		zephir_array_update_string(return_value, SL("sql"), &sqlSelect, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(return_value, SL("bind"), &processed, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(return_value, SL("bindTypes"), &processedTypes, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&result, &connection, "query", NULL, 0, &sqlSelect, &processed, &processedTypes);
	zephir_check_call_status();
	_35 = zephir_instance_of_ev(&result, phalcon_db_resultinterface_ce TSRMLS_CC);
	if (_35) {
		ZEPHIR_CALL_METHOD(&_36, &result, "numrows", NULL, 0);
		zephir_check_call_status();
		_35 = zephir_is_true(&_36);
	}
	if (_35) {
		ZEPHIR_CPY_WRT(&resultData, &result);
	} else {
		ZEPHIR_INIT_NVAR(&resultData);
		ZVAL_BOOL(&resultData, 0);
	}
	ZEPHIR_OBS_VAR(&cache);
	zephir_read_property(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	if (isComplex == 0) {
		if (isSimpleStd == 1) {
			ZEPHIR_INIT_VAR(&resultObject);
			object_init_ex(&resultObject, phalcon_mvc_model_row_ce);
			if (zephir_has_constructor(&resultObject TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, &resultObject, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			isKeepingSnapshots = 0;
		} else {
			if (Z_TYPE_P(&instance) == IS_OBJECT) {
				ZEPHIR_CPY_WRT(&resultObject, &instance);
			} else {
				ZEPHIR_CPY_WRT(&resultObject, &model);
			}
			if (!(ZEPHIR_GLOBAL(orm).cast_on_hydrate)) {
				ZEPHIR_CALL_METHOD(&simpleColumnMap, &metaData, "getcolumnmap", NULL, 0, &resultObject);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, &resultObject);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&typesColumnMap, &metaData, "getdatatypes", NULL, 0, &resultObject);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&simpleColumnMap);
				if (Z_TYPE_P(&columnMap) == IS_NULL) {
					array_init(&simpleColumnMap);
					ZEPHIR_CALL_METHOD(&_37$$58, &metaData, "getattributes", NULL, 0, &resultObject);
					zephir_check_call_status();
					zephir_is_iterable(&_37$$58, 0, "phalcon/mvc/model/query.zep", 2846);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_37$$58), _38$$58)
					{
						ZEPHIR_INIT_NVAR(&attribute);
						ZVAL_COPY(&attribute, _38$$58);
						ZEPHIR_INIT_NVAR(&_39$$59);
						zephir_create_array(&_39$$59, 2, 0 TSRMLS_CC);
						zephir_array_fast_append(&_39$$59, &attribute);
						ZEPHIR_OBS_NVAR(&_40$$59);
						zephir_array_fetch(&_40$$59, &typesColumnMap, &attribute, PH_NOISY, "phalcon/mvc/model/query.zep", 2844 TSRMLS_CC);
						zephir_array_fast_append(&_39$$59, &_40$$59);
						zephir_array_update_zval(&simpleColumnMap, &attribute, &_39$$59, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&attribute);
				} else {
					array_init(&simpleColumnMap);
					zephir_is_iterable(&columnMap, 0, "phalcon/mvc/model/query.zep", 2851);
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columnMap), _42$$60, _43$$60, _41$$60)
					{
						ZEPHIR_INIT_NVAR(&column);
						if (_43$$60 != NULL) { 
							ZVAL_STR_COPY(&column, _43$$60);
						} else {
							ZVAL_LONG(&column, _42$$60);
						}
						ZEPHIR_INIT_NVAR(&attribute);
						ZVAL_COPY(&attribute, _41$$60);
						ZEPHIR_INIT_NVAR(&_44$$61);
						zephir_create_array(&_44$$61, 2, 0 TSRMLS_CC);
						zephir_array_fast_append(&_44$$61, &attribute);
						ZEPHIR_OBS_NVAR(&_45$$61);
						zephir_array_fetch(&_45$$61, &typesColumnMap, &column, PH_NOISY, "phalcon/mvc/model/query.zep", 2849 TSRMLS_CC);
						zephir_array_fast_append(&_44$$61, &_45$$61);
						zephir_array_update_zval(&simpleColumnMap, &column, &_44$$61, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&attribute);
					ZEPHIR_INIT_NVAR(&column);
				}
			}
			ZEPHIR_CALL_METHOD(&_46$$53, &manager, "iskeepingsnapshots", NULL, 0, &resultObject);
			zephir_check_call_status();
			isKeepingSnapshots = zephir_get_boolval(&_46$$53);
		}
		_47$$51 = zephir_instance_of_ev(&resultObject, phalcon_mvc_modelinterface_ce TSRMLS_CC);
		if (_47$$51) {
			_47$$51 = (zephir_method_exists_ex(&resultObject, SL("getresultsetclass") TSRMLS_CC) == SUCCESS);
		}
		if (_47$$51) {
			ZEPHIR_CALL_METHOD(&resultsetClassName, &resultObject, "getresultsetclass", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&resultsetClassName)) {
				if (!(zephir_class_exists(&resultsetClassName, 1 TSRMLS_CC))) {
					ZEPHIR_INIT_VAR(&_48$$64);
					object_init_ex(&_48$$64, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_VAR(&_49$$64);
					ZEPHIR_CONCAT_SVS(&_49$$64, "Resultset class \"", &resultsetClassName, "\" not found");
					ZEPHIR_CALL_METHOD(NULL, &_48$$64, "__construct", NULL, 4, &_49$$64);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_48$$64, "phalcon/mvc/model/query.zep", 2865 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_VAR(&_50$$63);
				ZVAL_STRING(&_50$$63, "Phalcon\\Mvc\\Model\\ResultsetInterface");
				ZEPHIR_CALL_FUNCTION(&_51$$63, "is_subclass_of", NULL, 306, &resultsetClassName, &_50$$63);
				zephir_check_call_status();
				if (!(zephir_is_true(&_51$$63))) {
					ZEPHIR_INIT_VAR(&_52$$65);
					object_init_ex(&_52$$65, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_VAR(&_53$$65);
					ZEPHIR_CONCAT_SVS(&_53$$65, "Resultset class \"", &resultsetClassName, "\" must be an implementation of Phalcon\\Mvc\\Model\\ResultsetInterface");
					ZEPHIR_CALL_METHOD(NULL, &_52$$65, "__construct", NULL, 4, &_53$$65);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_52$$65, "phalcon/mvc/model/query.zep", 2869 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_fetch_safe_class(&_54$$63, &resultsetClassName);
				_55$$63 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_54$$63), Z_STRLEN_P(&_54$$63), ZEND_FETCH_CLASS_AUTO);
				object_init_ex(return_value, _55$$63);
				if (zephir_has_constructor(return_value TSRMLS_CC)) {
					if (isKeepingSnapshots) {
						ZVAL_BOOL(&_56$$63, 1);
					} else {
						ZVAL_BOOL(&_56$$63, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &simpleColumnMap, &resultObject, &resultData, &cache, &_56$$63);
					zephir_check_call_status();
				}
				RETURN_MM();
			}
		}
		object_init_ex(return_value, phalcon_mvc_model_resultset_simple_ce);
		if (isKeepingSnapshots) {
			ZVAL_BOOL(&_57$$51, 1);
		} else {
			ZVAL_BOOL(&_57$$51, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 334, &simpleColumnMap, &resultObject, &resultData, &cache, &_57$$51);
		zephir_check_call_status();
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_mvc_model_resultset_complex_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 335, &columns1, &resultData, &cache);
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

	zend_string *_4;
	zend_ulong _3;
	zend_bool automaticFields = 0;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_13 = NULL, *_15 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate, intermediate_sub, *bindParams, bindParams_sub, *bindTypes, bindTypes_sub, modelName, manager, connection, metaData, attributes, fields, columnMap, dialect, insertValues, number, value, model, values, exprValue, insertValue, wildcard, fieldName, attributeName, insertModel, _0, *_2, _19, _20, _1$$3, _5$$8, _7$$11, _9$$11, _10$$11, _11$$13, _12$$13, _14$$14, _17$$17, _18$$17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate_sub);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&insertValues);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&exprValue);
	ZVAL_UNDEF(&insertValue);
	ZVAL_UNDEF(&wildcard);
	ZVAL_UNDEF(&fieldName);
	ZVAL_UNDEF(&attributeName);
	ZVAL_UNDEF(&insertModel);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$17);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_OBS_VAR(&modelName);
	zephir_array_fetch_string(&modelName, intermediate, SL("model"), PH_NOISY, "phalcon/mvc/model/query.zep", 2904 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&manager);
	zephir_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&model);
	zephir_read_property(&_0, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&model, &_0, &modelName, 0 TSRMLS_CC))) {
		ZVAL_BOOL(&_1$$3, 1);
		ZEPHIR_CALL_METHOD(&model, &manager, "load", NULL, 0, &modelName, &_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, &model, intermediate, bindParams, bindTypes);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&metaData);
	zephir_read_property(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&attributes, &metaData, "getattributes", NULL, 0, &model);
	zephir_check_call_status();
	automaticFields = 0;
	ZEPHIR_OBS_VAR(&fields);
	if (!(zephir_array_isset_string_fetch(&fields, intermediate, SL("fields"), 0))) {
		automaticFields = 1;
		ZEPHIR_CPY_WRT(&fields, &attributes);
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, &model);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
	}
	ZEPHIR_OBS_VAR(&values);
	zephir_array_fetch_string(&values, intermediate, SL("values"), PH_NOISY, "phalcon/mvc/model/query.zep", 2930 TSRMLS_CC);
	if (zephir_fast_count_int(&fields TSRMLS_CC) != zephir_fast_count_int(&values TSRMLS_CC)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The column count does not match the values count", "phalcon/mvc/model/query.zep", 2936);
		return;
	}
	ZEPHIR_CALL_METHOD(&dialect, &connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&insertValues);
	array_init(&insertValues);
	zephir_is_iterable(&values, 0, "phalcon/mvc/model/query.zep", 3006);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&values), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&number);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&number, _4);
		} else {
			ZVAL_LONG(&number, _3);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _2);
		ZEPHIR_OBS_NVAR(&exprValue);
		zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 2947 TSRMLS_CC);
		zephir_array_fetch_string(&_5$$8, &value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2948 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(&_5$$8, 260) || ZEPHIR_IS_LONG(&_5$$8, 258) || ZEPHIR_IS_LONG(&_5$$8, 259)) {
				ZEPHIR_CALL_METHOD(&insertValue, &dialect, "getsqlexpression", &_6, 0, &exprValue);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&_5$$8, 322)) {
				ZEPHIR_INIT_NVAR(&insertValue);
				ZVAL_NULL(&insertValue);
				break;
			}
			if (ZEPHIR_IS_LONG(&_5$$8, 273) || ZEPHIR_IS_LONG(&_5$$8, 274) || ZEPHIR_IS_LONG(&_5$$8, 277)) {
				if (Z_TYPE_P(bindParams) != IS_ARRAY) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array", "phalcon/mvc/model/query.zep", 2965);
					return;
				}
				ZEPHIR_CALL_METHOD(&_7$$11, &dialect, "getsqlexpression", &_8, 0, &exprValue);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$11);
				ZVAL_STRING(&_9$$11, ":");
				ZEPHIR_INIT_NVAR(&_10$$11);
				ZVAL_STRING(&_10$$11, "");
				ZEPHIR_INIT_NVAR(&wildcard);
				zephir_fast_str_replace(&wildcard, &_9$$11, &_10$$11, &_7$$11 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&insertValue);
				if (!(zephir_array_isset_fetch(&insertValue, bindParams, &wildcard, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_11$$13);
					object_init_ex(&_11$$13, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_12$$13);
					ZEPHIR_CONCAT_SVS(&_12$$13, "Bound parameter '", &wildcard, "' cannot be replaced because it isn't in the placeholders list");
					ZEPHIR_CALL_METHOD(NULL, &_11$$13, "__construct", &_13, 4, &_12$$13);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$13, "phalcon/mvc/model/query.zep", 2972 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				break;
			}
			ZEPHIR_INIT_NVAR(&insertValue);
			object_init_ex(&insertValue, phalcon_db_rawvalue_ce);
			ZEPHIR_CALL_METHOD(&_14$$14, &dialect, "getsqlexpression", &_15, 0, &exprValue);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &insertValue, "__construct", &_16, 21, &_14$$14);
			zephir_check_call_status();
			break;
		} while(0);

		ZEPHIR_OBS_NVAR(&fieldName);
		zephir_array_fetch(&fieldName, &fields, &number, PH_NOISY, "phalcon/mvc/model/query.zep", 2982 TSRMLS_CC);
		if (automaticFields == 1) {
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeName);
				if (!(zephir_array_isset_fetch(&attributeName, &columnMap, &fieldName, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_17$$17);
					object_init_ex(&_17$$17, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_18$$17);
					ZEPHIR_CONCAT_SVS(&_18$$17, "Column '", &fieldName, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_17$$17, "__construct", &_13, 4, &_18$$17);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_17$$17, "phalcon/mvc/model/query.zep", 2990 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeName, &fieldName);
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeName, &fieldName);
		}
		zephir_array_update_zval(&insertValues, &attributeName, &insertValue, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&number);
	ZEPHIR_CALL_METHOD(&_19, &manager, "load", NULL, 0, &modelName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&insertModel);
	if (zephir_clone(&insertModel, &_19 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZEPHIR_CALL_METHOD(&_20, &insertModel, "create", NULL, 0, &insertValues);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 336, &_20, &insertModel);
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

	zend_string *_4;
	zend_ulong _3;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_13 = NULL, *_15 = NULL, *_16 = NULL, *_19 = NULL, *_21 = NULL, *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate, intermediate_sub, *bindParams, bindParams_sub, *bindTypes, bindTypes_sub, models, modelName, model, connection, dialect, fields, values, updateValues, fieldName, value, selectBindParams, selectBindTypes, number, field, records, exprValue, updateValue, wildcard, record, _0, *_2, _18, _24, _1$$4, _5$$5, _7$$10, _9$$10, _10$$10, _11$$13, _12$$13, _14$$15, _17$$16, _20$$17, _22$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate_sub);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&updateValues);
	ZVAL_UNDEF(&fieldName);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&selectBindParams);
	ZVAL_UNDEF(&selectBindTypes);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&exprValue);
	ZVAL_UNDEF(&updateValue);
	ZVAL_UNDEF(&wildcard);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_22$$18);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_OBS_VAR(&models);
	zephir_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 3030 TSRMLS_CC);
	if (zephir_array_isset_long(&models, 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Updating several models at the same time is still not supported", "phalcon/mvc/model/query.zep", 3033);
		return;
	}
	ZEPHIR_OBS_VAR(&modelName);
	zephir_array_fetch_long(&modelName, &models, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 3036 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&model);
	zephir_read_property(&_0, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&model, &_0, &modelName, 0 TSRMLS_CC))) {
		zephir_read_property(&_1$$4, this_ptr, SL("_manager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&model, &_1$$4, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, &model, intermediate, bindParams, bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&dialect, &connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&fields);
	zephir_array_fetch_string(&fields, intermediate, SL("fields"), PH_NOISY, "phalcon/mvc/model/query.zep", 3049 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&values);
	zephir_array_fetch_string(&values, intermediate, SL("values"), PH_NOISY, "phalcon/mvc/model/query.zep", 3050 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&updateValues);
	array_init(&updateValues);
	ZEPHIR_CPY_WRT(&selectBindParams, bindParams);
	ZEPHIR_CPY_WRT(&selectBindTypes, bindTypes);
	zephir_is_iterable(&fields, 0, "phalcon/mvc/model/query.zep", 3119);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&number);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&number, _4);
		} else {
			ZVAL_LONG(&number, _3);
		}
		ZEPHIR_INIT_NVAR(&field);
		ZVAL_COPY(&field, _2);
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_fetch(&value, &values, &number, PH_NOISY, "phalcon/mvc/model/query.zep", 3065 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&exprValue);
		zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 3066 TSRMLS_CC);
		if (zephir_array_isset_string(&field, SL("balias"))) {
			ZEPHIR_OBS_NVAR(&fieldName);
			zephir_array_fetch_string(&fieldName, &field, SL("balias"), PH_NOISY, "phalcon/mvc/model/query.zep", 3069 TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(&fieldName);
			zephir_array_fetch_string(&fieldName, &field, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 3071 TSRMLS_CC);
		}
		zephir_array_fetch_string(&_5$$5, &value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 3074 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(&_5$$5, 260) || ZEPHIR_IS_LONG(&_5$$5, 258) || ZEPHIR_IS_LONG(&_5$$5, 259)) {
				ZEPHIR_CALL_METHOD(&updateValue, &dialect, "getsqlexpression", &_6, 0, &exprValue);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&_5$$5, 322)) {
				ZEPHIR_INIT_NVAR(&updateValue);
				ZVAL_NULL(&updateValue);
				break;
			}
			if (ZEPHIR_IS_LONG(&_5$$5, 273) || ZEPHIR_IS_LONG(&_5$$5, 274) || ZEPHIR_IS_LONG(&_5$$5, 277)) {
				if (Z_TYPE_P(bindParams) != IS_ARRAY) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array", "phalcon/mvc/model/query.zep", 3091);
					return;
				}
				ZEPHIR_CALL_METHOD(&_7$$10, &dialect, "getsqlexpression", &_8, 0, &exprValue);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$10);
				ZVAL_STRING(&_9$$10, ":");
				ZEPHIR_INIT_NVAR(&_10$$10);
				ZVAL_STRING(&_10$$10, "");
				ZEPHIR_INIT_NVAR(&wildcard);
				zephir_fast_str_replace(&wildcard, &_9$$10, &_10$$10, &_7$$10 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&updateValue);
				if (zephir_array_isset_fetch(&updateValue, bindParams, &wildcard, 0 TSRMLS_CC)) {
					zephir_array_unset(&selectBindParams, &wildcard, PH_SEPARATE);
					zephir_array_unset(&selectBindTypes, &wildcard, PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_11$$13);
					object_init_ex(&_11$$13, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_12$$13);
					ZEPHIR_CONCAT_SVS(&_12$$13, "Bound parameter '", &wildcard, "' cannot be replaced because it's not in the placeholders list");
					ZEPHIR_CALL_METHOD(NULL, &_11$$13, "__construct", &_13, 4, &_12$$13);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$13, "phalcon/mvc/model/query.zep", 3101 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				break;
			}
			if (ZEPHIR_IS_LONG(&_5$$5, 277)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not supported", "phalcon/mvc/model/query.zep", 3106);
				return;
			}
			ZEPHIR_INIT_NVAR(&updateValue);
			object_init_ex(&updateValue, phalcon_db_rawvalue_ce);
			ZEPHIR_CALL_METHOD(&_14$$15, &dialect, "getsqlexpression", &_15, 0, &exprValue);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &updateValue, "__construct", &_16, 21, &_14$$15);
			zephir_check_call_status();
			break;
		} while(0);

		zephir_array_update_zval(&updateValues, &fieldName, &updateValue, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&field);
	ZEPHIR_INIT_NVAR(&number);
	ZEPHIR_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", NULL, 337, &model, intermediate, &selectBindParams, &selectBindTypes);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&records TSRMLS_CC))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		ZVAL_BOOL(&_17$$16, 1);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 336, &_17$$16);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, &model, intermediate, bindParams, bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &connection, "begin", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &records, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_18, &records, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_18))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&record, &records, "current", &_19, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_20$$17, &record, "update", NULL, 0, &updateValues);
		zephir_check_call_status();
		if (!(zephir_is_true(&_20$$17))) {
			ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", &_21, 0);
			zephir_check_call_status();
			object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
			ZVAL_BOOL(&_22$$18, 0);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 336, &_22$$18, &record);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(NULL, &records, "next", &_23, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &connection, "commit", NULL, 0);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZVAL_BOOL(&_24, 1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 336, &_24);
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
	zval *intermediate, intermediate_sub, *bindParams, bindParams_sub, *bindTypes, bindTypes_sub, models, modelName, model, records, connection, record, _0, _3, _9, _1$$4, _2$$5, _5$$6, _7$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate_sub);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_OBS_VAR(&models);
	zephir_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 3178 TSRMLS_CC);
	if (zephir_array_isset_long(&models, 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Delete from several models at the same time is still not supported", "phalcon/mvc/model/query.zep", 3181);
		return;
	}
	ZEPHIR_OBS_VAR(&modelName);
	zephir_array_fetch_long(&modelName, &models, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 3184 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&model);
	zephir_read_property(&_0, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&model, &_0, &modelName, 0 TSRMLS_CC))) {
		zephir_read_property(&_1$$4, this_ptr, SL("_manager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&model, &_1$$4, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", NULL, 337, &model, intermediate, bindParams, bindTypes);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&records TSRMLS_CC))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		ZVAL_BOOL(&_2$$5, 1);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 336, &_2$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, &model, intermediate, bindParams, bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &connection, "begin", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &records, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_3, &records, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_3))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&record, &records, "current", &_4, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$6, &record, "delete", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_5$$6))) {
			ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", &_6, 0);
			zephir_check_call_status();
			object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
			ZVAL_BOOL(&_7$$7, 0);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 336, &_7$$7, &record);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(NULL, &records, "next", &_8, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &connection, "commit", NULL, 0);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZVAL_BOOL(&_9, 1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 336, &_9);
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

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *intermediate, intermediate_sub, *bindParams, bindParams_sub, *bindTypes, bindTypes_sub, selectIr, whereConditions, limitConditions, query, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&intermediate_sub);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_UNDEF(&selectIr);
	ZVAL_UNDEF(&whereConditions);
	ZVAL_UNDEF(&limitConditions);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &model, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_INIT_VAR(&selectIr);
	zephir_create_array(&selectIr, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_1, SL("type"), SL("object"));
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_class(&_2, model, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("model"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, model, "getsource", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("column"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&selectIr, SL("columns"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&_4);
	zephir_array_fetch_string(&_4, intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 3267 TSRMLS_CC);
	zephir_array_update_string(&selectIr, SL("models"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_4);
	zephir_array_fetch_string(&_4, intermediate, SL("tables"), PH_NOISY, "phalcon/mvc/model/query.zep", 3269 TSRMLS_CC);
	zephir_array_update_string(&selectIr, SL("tables"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&whereConditions);
	if (zephir_array_isset_string_fetch(&whereConditions, intermediate, SL("where"), 0)) {
		zephir_array_update_string(&selectIr, SL("where"), &whereConditions, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&limitConditions);
	if (zephir_array_isset_string_fetch(&limitConditions, intermediate, SL("limit"), 0)) {
		zephir_array_update_string(&selectIr, SL("limit"), &limitConditions, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&query);
	object_init_ex(&query, phalcon_mvc_model_query_ce);
	ZEPHIR_CALL_METHOD(NULL, &query, "__construct", NULL, 338);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &query, "setdi", NULL, 339, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_6, 309);
	ZEPHIR_CALL_METHOD(NULL, &query, "settype", NULL, 340, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &query, "setintermediate", NULL, 341, &selectIr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&query, "execute", NULL, 342, bindParams, bindTypes);
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
	zval *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null, uniqueRow, cacheOptions, key, cacheService, cache, result, preparedResult, defaultBindParams, mergedParams, defaultBindTypes, mergedTypes, type, lifetime, intermediate, _0$$3, _1$$9, _4$$27, _5$$27;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&uniqueRow);
	ZVAL_UNDEF(&cacheOptions);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&cacheService);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&preparedResult);
	ZVAL_UNDEF(&defaultBindParams);
	ZVAL_UNDEF(&mergedParams);
	ZVAL_UNDEF(&defaultBindTypes);
	ZVAL_UNDEF(&mergedTypes);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&lifetime);
	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$9);
	ZVAL_UNDEF(&_4$$27);
	ZVAL_UNDEF(&_5$$27);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &bindParams, &bindTypes);

	if (!bindParams) {
		bindParams = &bindParams_sub;
		bindParams = &__$null;
	}
	if (!bindTypes) {
		bindTypes = &bindTypes_sub;
		bindTypes = &__$null;
	}


	ZEPHIR_OBS_VAR(&uniqueRow);
	zephir_read_property(&uniqueRow, this_ptr, SL("_uniqueRow"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&cacheOptions);
	zephir_read_property(&cacheOptions, this_ptr, SL("_cacheOptions"), PH_NOISY_CC);
	if (Z_TYPE_P(&cacheOptions) != IS_NULL) {
		if (Z_TYPE_P(&cacheOptions) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid caching options", "phalcon/mvc/model/query.zep", 3315);
			return;
		}
		ZEPHIR_OBS_VAR(&key);
		if (!(zephir_array_isset_string_fetch(&key, &cacheOptions, SL("key"), 0))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A cache key must be provided to identify the cached resultset in the cache backend", "phalcon/mvc/model/query.zep", 3322);
			return;
		}
		ZEPHIR_OBS_VAR(&lifetime);
		if (!(zephir_array_isset_string_fetch(&lifetime, &cacheOptions, SL("lifetime"), 0))) {
			ZEPHIR_INIT_NVAR(&lifetime);
			ZVAL_LONG(&lifetime, 3600);
		}
		ZEPHIR_OBS_VAR(&cacheService);
		if (!(zephir_array_isset_string_fetch(&cacheService, &cacheOptions, SL("service"), 0))) {
			ZEPHIR_INIT_NVAR(&cacheService);
			ZVAL_STRING(&cacheService, "modelsCache");
		}
		zephir_read_property(&_0$$3, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&cache, &_0$$3, "getshared", NULL, 0, &cacheService);
		zephir_check_call_status();
		if (Z_TYPE_P(&cache) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cache service must be an object", "phalcon/mvc/model/query.zep", 3341);
			return;
		}
		ZEPHIR_CALL_METHOD(&result, &cache, "get", NULL, 0, &key, &lifetime);
		zephir_check_call_status();
		if (Z_TYPE_P(&result) != IS_NULL) {
			if (Z_TYPE_P(&result) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cache didn't return a valid resultset", "phalcon/mvc/model/query.zep", 3348);
				return;
			}
			ZVAL_BOOL(&_1$$9, 0);
			ZEPHIR_CALL_METHOD(NULL, &result, "setisfresh", NULL, 0, &_1$$9);
			zephir_check_call_status();
			if (zephir_is_true(&uniqueRow)) {
				ZEPHIR_CALL_METHOD(&preparedResult, &result, "getfirst", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&preparedResult, &result);
			}
			RETURN_CCTOR(&preparedResult);
		}
		zephir_update_property_zval(this_ptr, SL("_cache"), &cache);
	}
	ZEPHIR_CALL_METHOD(&intermediate, this_ptr, "parse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&defaultBindParams);
	zephir_read_property(&defaultBindParams, this_ptr, SL("_bindParams"), PH_NOISY_CC);
	if (Z_TYPE_P(&defaultBindParams) == IS_ARRAY) {
		if (Z_TYPE_P(bindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&mergedParams);
			zephir_add_function(&mergedParams, &defaultBindParams, bindParams);
		} else {
			ZEPHIR_CPY_WRT(&mergedParams, &defaultBindParams);
		}
	} else {
		ZEPHIR_CPY_WRT(&mergedParams, bindParams);
	}
	ZEPHIR_OBS_VAR(&defaultBindTypes);
	zephir_read_property(&defaultBindTypes, this_ptr, SL("_bindTypes"), PH_NOISY_CC);
	if (Z_TYPE_P(&defaultBindTypes) == IS_ARRAY) {
		if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&mergedTypes);
			zephir_add_function(&mergedTypes, &defaultBindTypes, bindTypes);
		} else {
			ZEPHIR_CPY_WRT(&mergedTypes, &defaultBindTypes);
		}
	} else {
		ZEPHIR_CPY_WRT(&mergedTypes, bindTypes);
	}
	_2 = Z_TYPE_P(&mergedParams) != IS_NULL;
	if (_2) {
		_2 = Z_TYPE_P(&mergedParams) != IS_ARRAY;
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameters must be an array", "phalcon/mvc/model/query.zep", 3402);
		return;
	}
	_3 = Z_TYPE_P(&mergedTypes) != IS_NULL;
	if (_3) {
		_3 = Z_TYPE_P(&mergedTypes) != IS_ARRAY;
	}
	if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameter types must be an array", "phalcon/mvc/model/query.zep", 3406);
		return;
	}
	ZEPHIR_OBS_VAR(&type);
	zephir_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(&type, 309)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executeselect", NULL, 343, &intermediate, &mergedParams, &mergedTypes);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 306)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executeinsert", NULL, 344, &intermediate, &mergedParams, &mergedTypes);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 300)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executeupdate", NULL, 345, &intermediate, &mergedParams, &mergedTypes);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 303)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executedelete", NULL, 346, &intermediate, &mergedParams, &mergedTypes);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_VAR(&_4$$27);
		object_init_ex(&_4$$27, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$27);
		ZEPHIR_CONCAT_SV(&_5$$27, "Unknown statement ", &type);
		ZEPHIR_CALL_METHOD(NULL, &_4$$27, "__construct", NULL, 4, &_5$$27);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$27, "phalcon/mvc/model/query.zep", 3429 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	if (Z_TYPE_P(&cacheOptions) != IS_NULL) {
		if (!ZEPHIR_IS_LONG(&type, 309)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only PHQL statements that return resultsets can be cached", "phalcon/mvc/model/query.zep", 3441);
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, &cache, "save", NULL, 0, &key, &result, &lifetime);
		zephir_check_call_status();
	}
	if (zephir_is_true(&uniqueRow)) {
		ZEPHIR_CALL_METHOD(&preparedResult, &result, "getfirst", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&preparedResult, &result);
	}
	RETURN_CCTOR(&preparedResult);

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
	zval *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &bindParams, &bindTypes);

	if (!bindParams) {
		bindParams = &bindParams_sub;
		bindParams = &__$null;
	}
	if (!bindTypes) {
		bindTypes = &bindTypes_sub;
		bindTypes = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_uniqueRow"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, bindParams, bindTypes);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "execute", NULL, 342, bindParams, bindTypes);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "getfirst", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the type of PHQL statement to be executed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setType) {

	zval *type_param = NULL, _0;
	zend_long type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &type_param);

	type = zephir_get_intval(type_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, type);
	zephir_update_property_zval(this_ptr, SL("_type"), &_0);
	RETURN_THISW();

}

/**
 * Gets the type of PHQL statement executed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_type");

}

/**
 * Set default bind parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindParams) {

	zend_bool merge;
	zval *bindParams_param = NULL, *merge_param = NULL, currentBindParams, _0$$4;
	zval bindParams;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&currentBindParams);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &bindParams_param, &merge_param);

	ZEPHIR_OBS_COPY_OR_DUP(&bindParams, bindParams_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		zephir_read_property(&currentBindParams, this_ptr, SL("_bindParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_add_function(&_0$$4, &currentBindParams, &bindParams);
			zephir_update_property_zval(this_ptr, SL("_bindParams"), &_0$$4);
		} else {
			zephir_update_property_zval(this_ptr, SL("_bindParams"), &bindParams);
		}
	} else {
		zephir_update_property_zval(this_ptr, SL("_bindParams"), &bindParams);
	}
	RETURN_THIS();

}

/**
 * Returns default bind params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_bindParams");

}

/**
 * Set default bind parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindTypes) {

	zend_bool merge;
	zval *bindTypes_param = NULL, *merge_param = NULL, currentBindTypes, _0$$4;
	zval bindTypes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&currentBindTypes);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &bindTypes_param, &merge_param);

	ZEPHIR_OBS_COPY_OR_DUP(&bindTypes, bindTypes_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		zephir_read_property(&currentBindTypes, this_ptr, SL("_bindTypes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&currentBindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_add_function(&_0$$4, &currentBindTypes, &bindTypes);
			zephir_update_property_zval(this_ptr, SL("_bindTypes"), &_0$$4);
		} else {
			zephir_update_property_zval(this_ptr, SL("_bindTypes"), &bindTypes);
		}
	} else {
		zephir_update_property_zval(this_ptr, SL("_bindTypes"), &bindTypes);
	}
	RETURN_THIS();

}

/**
 * Set SHARED LOCK clause
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setSharedLock) {

	zval *sharedLock_param = NULL, __$true, __$false;
	zend_bool sharedLock;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 0, 1, &sharedLock_param);

	if (!sharedLock_param) {
		sharedLock = 0;
	} else {
		sharedLock = zephir_get_boolval(sharedLock_param);
	}


	if (sharedLock) {
		zephir_update_property_zval(this_ptr, SL("_sharedLock"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_sharedLock"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Returns default bind types
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindTypes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_bindTypes");

}

/**
 * Allows to set the IR to be executed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setIntermediate) {

	zval *intermediate_param = NULL;
	zval intermediate;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &intermediate_param);

	ZEPHIR_OBS_COPY_OR_DUP(&intermediate, intermediate_param);


	zephir_update_property_zval(this_ptr, SL("_intermediate"), &intermediate);
	RETURN_THIS();

}

/**
 * Returns the intermediate representation of the PHQL statement
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getIntermediate) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_intermediate");

}

/**
 * Sets the cache parameters of the query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, cache) {

	zval *cacheOptions, cacheOptions_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cacheOptions_sub);

	zephir_fetch_params(0, 1, 0, &cacheOptions);



	zephir_update_property_zval(this_ptr, SL("_cacheOptions"), cacheOptions);
	RETURN_THISW();

}

/**
 * Returns the current cache options
 *
 * @param array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getCacheOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_cacheOptions");

}

/**
 * Returns the SQL to be generated by the internal PHQL (only works in SELECT statements)
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getSql) {

	zval intermediate, _0, _1$$3, _2$$3, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&intermediate, this_ptr, "parse", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_0, 309)) {
		zephir_read_property(&_1$$3, this_ptr, SL("_bindParams"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_2$$3, this_ptr, SL("_bindTypes"), PH_NOISY_CC | PH_READONLY);
		ZVAL_BOOL(&_3$$3, 1);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_executeselect", NULL, 343, &intermediate, &_1$$3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "This type of statement generates multiple SQL statements", "phalcon/mvc/model/query.zep", 3621);
	return;

}

/**
 * Destroys the internal PHQL cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, clean) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(phalcon_mvc_model_query_ce, ZEND_STRL("_irPhqlCache"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the read connection from the model if there is no transaction set inside the query object
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getReadConnection) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval intermediate, bindParams, bindTypes;
	zval *model, model_sub, *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, connection, transaction;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &model, &intermediate_param, &bindParams_param, &bindTypes_param);

	if (!intermediate_param) {
		ZEPHIR_INIT_VAR(&intermediate);
		array_init(&intermediate);
	} else {
		zephir_get_arrval(&intermediate, intermediate_param);
	}
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
		zephir_get_arrval(&bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(&bindTypes);
		array_init(&bindTypes);
	} else {
		zephir_get_arrval(&bindTypes, bindTypes_param);
	}


	ZEPHIR_INIT_VAR(&connection);
	ZVAL_NULL(&connection);
	ZEPHIR_OBS_VAR(&transaction);
	zephir_read_property(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	_0 = Z_TYPE_P(&transaction) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(&transaction, phalcon_mvc_model_transactioninterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(&transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(model, SL("selectreadconnection") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&connection, model, "selectreadconnection", NULL, 0, &intermediate, &bindParams, &bindTypes);
		zephir_check_call_status();
		if (Z_TYPE_P(&connection) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "selectReadConnection did not return a connection", "phalcon/mvc/model/query.zep", 3648);
			return;
		}
		RETURN_CCTOR(&connection);
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
	zval intermediate, bindParams, bindTypes;
	zval *model, model_sub, *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, connection, transaction;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &model, &intermediate_param, &bindParams_param, &bindTypes_param);

	if (!intermediate_param) {
		ZEPHIR_INIT_VAR(&intermediate);
		array_init(&intermediate);
	} else {
		zephir_get_arrval(&intermediate, intermediate_param);
	}
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
		zephir_get_arrval(&bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(&bindTypes);
		array_init(&bindTypes);
	} else {
		zephir_get_arrval(&bindTypes, bindTypes_param);
	}


	ZEPHIR_INIT_VAR(&connection);
	ZVAL_NULL(&connection);
	ZEPHIR_OBS_VAR(&transaction);
	zephir_read_property(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	_0 = Z_TYPE_P(&transaction) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(&transaction, phalcon_mvc_model_transactioninterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(&transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(model, SL("selectwriteconnection") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&connection, model, "selectwriteconnection", NULL, 0, &intermediate, &bindParams, &bindTypes);
		zephir_check_call_status();
		if (Z_TYPE_P(&connection) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "selectWriteConnection did not return a connection", "phalcon/mvc/model/query.zep", 3671);
			return;
		}
		RETURN_CCTOR(&connection);
	}
	ZEPHIR_RETURN_CALL_METHOD(model, "getwriteconnection", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * allows to wrap a transaction around all queries
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setTransaction) {

	zval *transaction, transaction_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transaction_sub);

	zephir_fetch_params(0, 1, 0, &transaction);



	zephir_update_property_zval(this_ptr, SL("_transaction"), transaction);
	RETURN_THISW();

}

