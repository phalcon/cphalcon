
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "phalcon/mvc/model/orm.h"
#include "phalcon/mvc/model/query/scanner.h"
#include "phalcon/mvc/model/query/phql.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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

	zend_declare_property_long(phalcon_mvc_model_query_ce, SL("_nestingLevel"), -1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * TransactionInterface so that the query can wrap a transaction
	 * around batch updates and intermediate selects within the transaction.
	 * however if a model got a transaction set inside it will use the local transaction instead of this one
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_transaction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_irPhqlCache"), ZEND_ACC_STATIC|ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_model_query_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_Query;
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *phql_param = NULL, *dependencyInjector = NULL, dependencyInjector_sub, *options_param = NULL, __$true, __$false, __$null, enableImplicitJoins;
	zval phql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&phql);
	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&enableImplicitJoins);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &phql_param, &dependencyInjector, &options_param);

	if (!phql_param) {
		ZEPHIR_INIT_VAR(&phql);
		ZVAL_STRING(&phql, "");
	} else {
		zephir_get_strval(&phql, phql_param);
	}
	if (!dependencyInjector) {
		dependencyInjector = &dependencyInjector_sub;
		dependencyInjector = &__$null;
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	if (!ZEPHIR_IS_STRING_IDENTICAL(&phql, "")) {
		zephir_update_property_zval(this_ptr, SL("_phql"), &phql);
	}
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, dependencyInjector);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&enableImplicitJoins);
	if (zephir_array_isset_string_fetch(&enableImplicitJoins, &options, SL("enable_implicit_joins"), 0)) {
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Injected service 'modelsManager' is invalid", "phalcon/mvc/model/query.zep", 180);
		return;
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "modelsMetadata");
	ZEPHIR_CALL_METHOD(&metaData, dependencyInjector, "getshared", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&metaData) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Injected service 'modelsMetaData' is invalid", "phalcon/mvc/model/query.zep", 185);
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

	zend_bool _2, _3;
	zephir_fcall_cache_entry *_18 = NULL, *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, number = 0;
	zval *expr_param = NULL, columnName, nestingLevel, sqlColumnAliases, metaData, sqlAliases, source, sqlAliasesModelsInstances, realColumnName, columnDomain, model, models, columnMap, hasModel, className, _0, _4, _1$$3, _5$$7, _6$$7, _7$$7, _8$$9, _9$$9, _10$$9, _11$$12, _12$$12, _13$$12, _14$$14, *_15$$14, _16$$14, _17$$15, _19$$17, _20$$17, _21$$17, _22$$18, _24$$20, _25$$20, _26$$20, _27$$21, _28$$21, _29$$21, _30$$23, _31$$23, _32$$23, _33$$27, _34$$27, _35$$27;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&nestingLevel);
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
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_26$$20);
	ZVAL_UNDEF(&_27$$21);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_30$$23);
	ZVAL_UNDEF(&_31$$23);
	ZVAL_UNDEF(&_32$$23);
	ZVAL_UNDEF(&_33$$27);
	ZVAL_UNDEF(&_34$$27);
	ZVAL_UNDEF(&_35$$27);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);


	ZEPHIR_OBS_VAR(&columnName);
	zephir_array_fetch_string(&columnName, &expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 229 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&nestingLevel);
	zephir_read_property(&nestingLevel, this_ptr, SL("_nestingLevel"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, SL("_sqlColumnAliases"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &nestingLevel)) {
		zephir_read_property(&_1$$3, this_ptr, SL("_sqlColumnAliases"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&sqlColumnAliases);
		zephir_array_fetch(&sqlColumnAliases, &_1$$3, &nestingLevel, PH_NOISY, "phalcon/mvc/model/query.zep", 237 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&sqlColumnAliases);
		array_init(&sqlColumnAliases);
	}
	_2 = zephir_array_isset(&sqlColumnAliases, &columnName);
	if (_2) {
		_3 = !(zephir_array_isset_string(&expr, SL("domain")));
		if (!(_3)) {
			zephir_array_fetch_string(&_4, &expr, SL("domain"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 242 TSRMLS_CC);
			_3 = ZEPHIR_IS_EMPTY(&_4);
		}
		_2 = _3;
	}
	if (_2) {
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
			ZEPHIR_INIT_VAR(&_5$$7);
			object_init_ex(&_5$$7, phalcon_mvc_model_exception_ce);
			zephir_read_property(&_6$$7, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_7$$7);
			ZEPHIR_CONCAT_SVSV(&_7$$7, "Unknown model or alias '", &columnDomain, "' (11), when preparing: ", &_6$$7);
			ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", NULL, 4, &_7$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$7, "phalcon/mvc/model/query.zep", 262 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_OBS_VAR(&sqlAliasesModelsInstances);
			zephir_read_property(&sqlAliasesModelsInstances, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
			ZEPHIR_OBS_VAR(&model);
			if (!(zephir_array_isset_fetch(&model, &sqlAliasesModelsInstances, &columnDomain, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(&_8$$9);
				object_init_ex(&_8$$9, phalcon_mvc_model_exception_ce);
				zephir_read_property(&_9$$9, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_10$$9);
				ZEPHIR_CONCAT_SVSV(&_10$$9, "There is no model related to model or alias '", &columnDomain, "', when executing: ", &_9$$9);
				ZEPHIR_CALL_METHOD(NULL, &_8$$9, "__construct", NULL, 4, &_10$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_8$$9, "phalcon/mvc/model/query.zep", 281 TSRMLS_CC);
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
				ZEPHIR_INIT_VAR(&_11$$12);
				object_init_ex(&_11$$12, phalcon_mvc_model_exception_ce);
				zephir_read_property(&_12$$12, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_13$$12);
				ZEPHIR_CONCAT_SVSVSV(&_13$$12, "Column '", &columnName, "' doesn't belong to the model or alias '", &columnDomain, "', when executing: ", &_12$$12);
				ZEPHIR_CALL_METHOD(NULL, &_11$$12, "__construct", NULL, 4, &_13$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$12, "phalcon/mvc/model/query.zep", 293 TSRMLS_CC);
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
		zephir_read_property(&_14$$14, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_14$$14, 0, "phalcon/mvc/model/query.zep", 323);
		if (Z_TYPE_P(&_14$$14) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_14$$14), _15$$14)
			{
				ZEPHIR_INIT_NVAR(&model);
				ZVAL_COPY(&model, _15$$14);
				ZEPHIR_CALL_METHOD(&_17$$15, &metaData, "hasattribute", &_18, 0, &model, &columnName);
				zephir_check_call_status();
				if (zephir_is_true(&_17$$15)) {
					number++;
					if (number > 1) {
						ZEPHIR_INIT_NVAR(&_19$$17);
						object_init_ex(&_19$$17, phalcon_mvc_model_exception_ce);
						zephir_read_property(&_20$$17, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_LNVAR(_21$$17);
						ZEPHIR_CONCAT_SVSV(&_21$$17, "The column '", &columnName, "' is ambiguous, when preparing: ", &_20$$17);
						ZEPHIR_CALL_METHOD(NULL, &_19$$17, "__construct", NULL, 4, &_21$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_19$$17, "phalcon/mvc/model/query.zep", 314 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&hasModel, &model);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_14$$14, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_16$$14, &_14$$14, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_16$$14)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&model, &_14$$14, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_22$$18, &metaData, "hasattribute", &_23, 0, &model, &columnName);
					zephir_check_call_status();
					if (zephir_is_true(&_22$$18)) {
						number++;
						if (number > 1) {
							ZEPHIR_INIT_NVAR(&_24$$20);
							object_init_ex(&_24$$20, phalcon_mvc_model_exception_ce);
							zephir_read_property(&_25$$20, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_INIT_LNVAR(_26$$20);
							ZEPHIR_CONCAT_SVSV(&_26$$20, "The column '", &columnName, "' is ambiguous, when preparing: ", &_25$$20);
							ZEPHIR_CALL_METHOD(NULL, &_24$$20, "__construct", NULL, 4, &_26$$20);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_24$$20, "phalcon/mvc/model/query.zep", 314 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CPY_WRT(&hasModel, &model);
					}
				ZEPHIR_CALL_METHOD(NULL, &_14$$14, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&model);
		if (ZEPHIR_IS_FALSE_IDENTICAL(&hasModel)) {
			ZEPHIR_INIT_VAR(&_27$$21);
			object_init_ex(&_27$$21, phalcon_mvc_model_exception_ce);
			zephir_read_property(&_28$$21, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_29$$21);
			ZEPHIR_CONCAT_SVSV(&_29$$21, "Column '", &columnName, "' doesn't belong to any of the selected models (1), when preparing: ", &_28$$21);
			ZEPHIR_CALL_METHOD(NULL, &_27$$21, "__construct", NULL, 4, &_29$$21);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_27$$21, "phalcon/mvc/model/query.zep", 326 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(&models);
		zephir_read_property(&models, this_ptr, SL("_models"), PH_NOISY_CC);
		if (Z_TYPE_P(&models) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The models list was not loaded correctly", "phalcon/mvc/model/query.zep", 334);
			return;
		}
		ZEPHIR_INIT_VAR(&className);
		zephir_get_class(&className, &hasModel, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&source);
		if (!(zephir_array_isset_fetch(&source, &models, &className, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(&_30$$23);
			object_init_ex(&_30$$23, phalcon_mvc_model_exception_ce);
			zephir_read_property(&_31$$23, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_32$$23);
			ZEPHIR_CONCAT_SVSV(&_32$$23, "Can't obtain model's source from models list: '", &className, "', when preparing: ", &_31$$23);
			ZEPHIR_CALL_METHOD(NULL, &_30$$23, "__construct", NULL, 4, &_32$$23);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_30$$23, "phalcon/mvc/model/query.zep", 344 TSRMLS_CC);
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
				ZEPHIR_INIT_VAR(&_33$$27);
				object_init_ex(&_33$$27, phalcon_mvc_model_exception_ce);
				zephir_read_property(&_34$$27, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_35$$27);
				ZEPHIR_CONCAT_SVSV(&_35$$27, "Column '", &columnName, "' doesn't belong to any of the selected models (3), when preparing: ", &_34$$27);
				ZEPHIR_CALL_METHOD(NULL, &_33$$27, "__construct", NULL, 4, &_35$$27);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_33$$27, "phalcon/mvc/model/query.zep", 363 TSRMLS_CC);
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


	zephir_array_fetch_string(&_0, &argument, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 386 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&_0, 352)) {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		add_assoc_stringl_ex(return_value, SL("type"), SL("all"));
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getexpression", NULL, 337, &argument);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Resolves an expression in a single call argument
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCaseExpression) {

	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, whenClauses, whenExpr, _0, *_1, _2, _18, _19, _4$$4, _5$$4, _7$$4, _9$$5, _10$$5, _12$$7, _13$$7, _14$$7, _16$$8, _17$$8;
	zval expr, _3$$4, _8$$5, _11$$7, _15$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&whenClauses);
	ZVAL_UNDEF(&whenExpr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);


	ZEPHIR_INIT_VAR(&whenClauses);
	array_init(&whenClauses);
	zephir_array_fetch_string(&_0, &expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 400 TSRMLS_CC);
	zephir_is_iterable(&_0, 0, "phalcon/mvc/model/query.zep", 415);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&whenExpr);
			ZVAL_COPY(&whenExpr, _1);
			if (zephir_array_isset_string(&whenExpr, SL("right"))) {
				ZEPHIR_INIT_NVAR(&_3$$4);
				zephir_create_array(&_3$$4, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_3$$4, SL("type"), SL("when"));
				zephir_array_fetch_string(&_5$$4, &whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 404 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "_getexpression", &_6, 337, &_5$$4);
				zephir_check_call_status();
				zephir_array_update_string(&_3$$4, SL("expr"), &_4$$4, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_string(&_7$$4, &whenExpr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 405 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "_getexpression", &_6, 337, &_7$$4);
				zephir_check_call_status();
				zephir_array_update_string(&_3$$4, SL("then"), &_4$$4, PH_COPY | PH_SEPARATE);
				zephir_array_append(&whenClauses, &_3$$4, PH_SEPARATE, "phalcon/mvc/model/query.zep", 406);
			} else {
				ZEPHIR_INIT_NVAR(&_8$$5);
				zephir_create_array(&_8$$5, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_8$$5, SL("type"), SL("else"));
				zephir_array_fetch_string(&_10$$5, &whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 410 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_9$$5, this_ptr, "_getexpression", &_6, 337, &_10$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_8$$5, SL("expr"), &_9$$5, PH_COPY | PH_SEPARATE);
				zephir_array_append(&whenClauses, &_8$$5, PH_SEPARATE, "phalcon/mvc/model/query.zep", 411);
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
			ZEPHIR_CALL_METHOD(&whenExpr, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_array_isset_string(&whenExpr, SL("right"))) {
					ZEPHIR_INIT_NVAR(&_11$$7);
					zephir_create_array(&_11$$7, 3, 0 TSRMLS_CC);
					add_assoc_stringl_ex(&_11$$7, SL("type"), SL("when"));
					zephir_array_fetch_string(&_13$$7, &whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 404 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_12$$7, this_ptr, "_getexpression", &_6, 337, &_13$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_11$$7, SL("expr"), &_12$$7, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_string(&_14$$7, &whenExpr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 405 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_12$$7, this_ptr, "_getexpression", &_6, 337, &_14$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_11$$7, SL("then"), &_12$$7, PH_COPY | PH_SEPARATE);
					zephir_array_append(&whenClauses, &_11$$7, PH_SEPARATE, "phalcon/mvc/model/query.zep", 406);
				} else {
					ZEPHIR_INIT_NVAR(&_15$$8);
					zephir_create_array(&_15$$8, 2, 0 TSRMLS_CC);
					add_assoc_stringl_ex(&_15$$8, SL("type"), SL("else"));
					zephir_array_fetch_string(&_17$$8, &whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 410 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_16$$8, this_ptr, "_getexpression", &_6, 337, &_17$$8);
					zephir_check_call_status();
					zephir_array_update_string(&_15$$8, SL("expr"), &_16$$8, PH_COPY | PH_SEPARATE);
					zephir_array_append(&whenClauses, &_15$$8, PH_SEPARATE, "phalcon/mvc/model/query.zep", 411);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&whenExpr);
	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SL("type"), SL("case"));
	zephir_array_fetch_string(&_19, &expr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 417 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_18, this_ptr, "_getexpression", &_6, 337, &_19);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("expr"), &_18, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("when-clauses"), &whenClauses, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Resolves an expression in a single call argument
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getFunctionCall) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, distinct = 0;
	zval *expr_param = NULL, arguments, argument, functionArgs, _10, *_0$$6, _1$$6, _2$$7, _4$$8, _5$$9, _6$$9, _7$$10, _8$$10, _9$$11;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&functionArgs);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$11);

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
			zephir_is_iterable(&arguments, 0, "phalcon/mvc/model/query.zep", 443);
			if (Z_TYPE_P(&arguments) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arguments), _0$$6)
				{
					ZEPHIR_INIT_NVAR(&argument);
					ZVAL_COPY(&argument, _0$$6);
					ZEPHIR_CALL_METHOD(&_2$$7, this_ptr, "_getcallargument", &_3, 338, &argument);
					zephir_check_call_status();
					zephir_array_append(&functionArgs, &_2$$7, PH_SEPARATE, "phalcon/mvc/model/query.zep", 441);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &arguments, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_1$$6, &arguments, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_1$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&argument, &arguments, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_4$$8, this_ptr, "_getcallargument", &_3, 338, &argument);
						zephir_check_call_status();
						zephir_array_append(&functionArgs, &_4$$8, PH_SEPARATE, "phalcon/mvc/model/query.zep", 441);
					ZEPHIR_CALL_METHOD(NULL, &arguments, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&argument);
		} else {
			ZEPHIR_INIT_VAR(&_5$$9);
			zephir_create_array(&_5$$9, 1, 0 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_6$$9, this_ptr, "_getcallargument", &_3, 338, &arguments);
			zephir_check_call_status();
			zephir_array_fast_append(&_5$$9, &_6$$9);
			ZEPHIR_CPY_WRT(&functionArgs, &_5$$9);
		}
		if (distinct) {
			zephir_create_array(return_value, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
			ZEPHIR_OBS_VAR(&_7$$10);
			zephir_array_fetch_string(&_7$$10, &expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 451 TSRMLS_CC);
			zephir_array_update_string(return_value, SL("name"), &_7$$10, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_8$$10);
			ZVAL_LONG(&_8$$10, distinct);
			zephir_array_update_string(return_value, SL("distinct"), &_8$$10, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		} else {
			zephir_create_array(return_value, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
			ZEPHIR_OBS_VAR(&_9$$11);
			zephir_array_fetch_string(&_9$$11, &expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 458 TSRMLS_CC);
			zephir_array_update_string(return_value, SL("name"), &_9$$11, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
	ZEPHIR_OBS_VAR(&_10);
	zephir_array_fetch_string(&_10, &expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 467 TSRMLS_CC);
	zephir_array_update_string(return_value, SL("name"), &_10, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Resolves an expression from its intermediate code into a string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getExpression) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool quoting, tempNotQuoting = 0;
	zval *expr_param = NULL, *quoting_param = NULL, exprType, exprLeft, exprRight, left, right, listItems, exprListItem, exprReturn, value, escapedValue, exprValue, valueParts, name, bindType, bind, _0$$5, _1$$6, _2$$8, _3$$9, _4$$10, _5$$11, _6$$12, _7$$13, _8$$14, _9$$16, _10$$17, _11$$18, _12$$19, _13$$20, _14$$21, _15$$22, _16$$23, _17$$24, _18$$25, _19$$25, _20$$26, _21$$27, _22$$28, _23$$33, _24$$33, _25$$33, _26$$33, _27$$33, _28$$34, _29$$34, _30$$34, _31$$37, _32$$37, _33$$37, _34$$38, _35$$38, _36$$38, _37$$39, _38$$39, _39$$39, _40$$40, _41$$40, _42$$40, _43$$41, _44$$41, _45$$41, _46$$42, _47$$42, _48$$42, _49$$43, _56$$43, _57$$43, _50$$44, _51$$44, _52$$45, _53$$45, _54$$46, _55$$46, _58$$47, _59$$47, _60$$48, _61$$48, _62$$49, _63$$50, _64$$51, _65$$52, _66$$53, _67$$54, _68$$55, _69$$56, _70$$57, _71$$58, _72$$59, _73$$60, _74$$61, _75$$62, _76$$63, _77$$64, _78$$65, _79$$65, _80$$68, _81$$68, _82$$68, _83$$69, _84$$69, *_85$$71, _86$$71, _87$$72, _88$$73;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
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
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$12);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_9$$16);
	ZVAL_UNDEF(&_10$$17);
	ZVAL_UNDEF(&_11$$18);
	ZVAL_UNDEF(&_12$$19);
	ZVAL_UNDEF(&_13$$20);
	ZVAL_UNDEF(&_14$$21);
	ZVAL_UNDEF(&_15$$22);
	ZVAL_UNDEF(&_16$$23);
	ZVAL_UNDEF(&_17$$24);
	ZVAL_UNDEF(&_18$$25);
	ZVAL_UNDEF(&_19$$25);
	ZVAL_UNDEF(&_20$$26);
	ZVAL_UNDEF(&_21$$27);
	ZVAL_UNDEF(&_22$$28);
	ZVAL_UNDEF(&_23$$33);
	ZVAL_UNDEF(&_24$$33);
	ZVAL_UNDEF(&_25$$33);
	ZVAL_UNDEF(&_26$$33);
	ZVAL_UNDEF(&_27$$33);
	ZVAL_UNDEF(&_28$$34);
	ZVAL_UNDEF(&_29$$34);
	ZVAL_UNDEF(&_30$$34);
	ZVAL_UNDEF(&_31$$37);
	ZVAL_UNDEF(&_32$$37);
	ZVAL_UNDEF(&_33$$37);
	ZVAL_UNDEF(&_34$$38);
	ZVAL_UNDEF(&_35$$38);
	ZVAL_UNDEF(&_36$$38);
	ZVAL_UNDEF(&_37$$39);
	ZVAL_UNDEF(&_38$$39);
	ZVAL_UNDEF(&_39$$39);
	ZVAL_UNDEF(&_40$$40);
	ZVAL_UNDEF(&_41$$40);
	ZVAL_UNDEF(&_42$$40);
	ZVAL_UNDEF(&_43$$41);
	ZVAL_UNDEF(&_44$$41);
	ZVAL_UNDEF(&_45$$41);
	ZVAL_UNDEF(&_46$$42);
	ZVAL_UNDEF(&_47$$42);
	ZVAL_UNDEF(&_48$$42);
	ZVAL_UNDEF(&_49$$43);
	ZVAL_UNDEF(&_56$$43);
	ZVAL_UNDEF(&_57$$43);
	ZVAL_UNDEF(&_50$$44);
	ZVAL_UNDEF(&_51$$44);
	ZVAL_UNDEF(&_52$$45);
	ZVAL_UNDEF(&_53$$45);
	ZVAL_UNDEF(&_54$$46);
	ZVAL_UNDEF(&_55$$46);
	ZVAL_UNDEF(&_58$$47);
	ZVAL_UNDEF(&_59$$47);
	ZVAL_UNDEF(&_60$$48);
	ZVAL_UNDEF(&_61$$48);
	ZVAL_UNDEF(&_62$$49);
	ZVAL_UNDEF(&_63$$50);
	ZVAL_UNDEF(&_64$$51);
	ZVAL_UNDEF(&_65$$52);
	ZVAL_UNDEF(&_66$$53);
	ZVAL_UNDEF(&_67$$54);
	ZVAL_UNDEF(&_68$$55);
	ZVAL_UNDEF(&_69$$56);
	ZVAL_UNDEF(&_70$$57);
	ZVAL_UNDEF(&_71$$58);
	ZVAL_UNDEF(&_72$$59);
	ZVAL_UNDEF(&_73$$60);
	ZVAL_UNDEF(&_74$$61);
	ZVAL_UNDEF(&_75$$62);
	ZVAL_UNDEF(&_76$$63);
	ZVAL_UNDEF(&_77$$64);
	ZVAL_UNDEF(&_78$$65);
	ZVAL_UNDEF(&_79$$65);
	ZVAL_UNDEF(&_80$$68);
	ZVAL_UNDEF(&_81$$68);
	ZVAL_UNDEF(&_82$$68);
	ZVAL_UNDEF(&_83$$69);
	ZVAL_UNDEF(&_84$$69);
	ZVAL_UNDEF(&_86$$71);
	ZVAL_UNDEF(&_87$$72);
	ZVAL_UNDEF(&_88$$73);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expr_param, &quoting_param);

	zephir_get_arrval(&expr, expr_param);
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
	if (zephir_array_isset_string_fetch(&exprType, &expr, SL("type"), 0)) {
		tempNotQuoting = 1;
		if (!ZEPHIR_IS_LONG(&exprType, 409)) {
			ZEPHIR_OBS_VAR(&exprLeft);
			if (zephir_array_isset_string_fetch(&exprLeft, &expr, SL("left"), 0)) {
				if (tempNotQuoting) {
					ZVAL_BOOL(&_0$$5, 1);
				} else {
					ZVAL_BOOL(&_0$$5, 0);
				}
				ZEPHIR_CALL_METHOD(&left, this_ptr, "_getexpression", NULL, 337, &exprLeft, &_0$$5);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_VAR(&exprRight);
			if (zephir_array_isset_string_fetch(&exprRight, &expr, SL("right"), 0)) {
				if (tempNotQuoting) {
					ZVAL_BOOL(&_1$$6, 1);
				} else {
					ZVAL_BOOL(&_1$$6, 0);
				}
				ZEPHIR_CALL_METHOD(&right, this_ptr, "_getexpression", NULL, 337, &exprRight, &_1$$6);
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
				ZEPHIR_INIT_VAR(&_2$$8);
				zephir_create_array(&_2$$8, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_2$$8, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_2$$8, SL("op"), SL("="));
				zephir_array_update_string(&_2$$8, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_2$$8, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_2$$8);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '>')) {
				ZEPHIR_INIT_VAR(&_3$$9);
				zephir_create_array(&_3$$9, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_3$$9, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_3$$9, SL("op"), SL(">"));
				zephir_array_update_string(&_3$$9, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_3$$9, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_3$$9);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 270)) {
				ZEPHIR_INIT_VAR(&_4$$10);
				zephir_create_array(&_4$$10, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_4$$10, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_4$$10, SL("op"), SL("<>"));
				zephir_array_update_string(&_4$$10, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_4$$10, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_4$$10);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 271)) {
				ZEPHIR_INIT_VAR(&_5$$11);
				zephir_create_array(&_5$$11, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_5$$11, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_5$$11, SL("op"), SL("<="));
				zephir_array_update_string(&_5$$11, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_5$$11, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_5$$11);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 272)) {
				ZEPHIR_INIT_VAR(&_6$$12);
				zephir_create_array(&_6$$12, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_6$$12, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_6$$12, SL("op"), SL(">="));
				zephir_array_update_string(&_6$$12, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_6$$12, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_6$$12);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 266)) {
				ZEPHIR_INIT_VAR(&_7$$13);
				zephir_create_array(&_7$$13, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_7$$13, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_7$$13, SL("op"), SL("AND"));
				zephir_array_update_string(&_7$$13, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_7$$13, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_7$$13);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 267)) {
				ZEPHIR_INIT_VAR(&_8$$14);
				zephir_create_array(&_8$$14, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_8$$14, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_8$$14, SL("op"), SL("OR"));
				zephir_array_update_string(&_8$$14, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_8$$14, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_8$$14);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 355)) {
				ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "_getqualified", NULL, 339, &expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '+')) {
				ZEPHIR_INIT_VAR(&_9$$16);
				zephir_create_array(&_9$$16, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_9$$16, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_9$$16, SL("op"), SL("+"));
				zephir_array_update_string(&_9$$16, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_9$$16, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_9$$16);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '-')) {
				ZEPHIR_INIT_VAR(&_10$$17);
				zephir_create_array(&_10$$17, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_10$$17, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_10$$17, SL("op"), SL("-"));
				zephir_array_update_string(&_10$$17, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10$$17, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_10$$17);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '*')) {
				ZEPHIR_INIT_VAR(&_11$$18);
				zephir_create_array(&_11$$18, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_11$$18, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_11$$18, SL("op"), SL("*"));
				zephir_array_update_string(&_11$$18, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_11$$18, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_11$$18);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '/')) {
				ZEPHIR_INIT_VAR(&_12$$19);
				zephir_create_array(&_12$$19, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_12$$19, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_12$$19, SL("op"), SL("/"));
				zephir_array_update_string(&_12$$19, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_12$$19, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_12$$19);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '%')) {
				ZEPHIR_INIT_VAR(&_13$$20);
				zephir_create_array(&_13$$20, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_13$$20, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_13$$20, SL("op"), SL("%"));
				zephir_array_update_string(&_13$$20, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_13$$20, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_13$$20);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '&')) {
				ZEPHIR_INIT_VAR(&_14$$21);
				zephir_create_array(&_14$$21, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_14$$21, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_14$$21, SL("op"), SL("&"));
				zephir_array_update_string(&_14$$21, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_14$$21, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_14$$21);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '|')) {
				ZEPHIR_INIT_VAR(&_15$$22);
				zephir_create_array(&_15$$22, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_15$$22, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_15$$22, SL("op"), SL("|"));
				zephir_array_update_string(&_15$$22, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_15$$22, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_15$$22);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 356) || ZEPHIR_IS_LONG(&exprType, 407)) {
				ZEPHIR_INIT_VAR(&_16$$23);
				zephir_create_array(&_16$$23, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_16$$23, SL("type"), SL("parentheses"));
				zephir_array_update_string(&_16$$23, SL("left"), &left, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_16$$23);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 367)) {
				ZEPHIR_INIT_VAR(&_17$$24);
				zephir_create_array(&_17$$24, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_17$$24, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&_17$$24, SL("op"), SL("-"));
				zephir_array_update_string(&_17$$24, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_17$$24);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 258) || ZEPHIR_IS_LONG(&exprType, 259) || ZEPHIR_IS_LONG(&exprType, 414)) {
				ZEPHIR_INIT_VAR(&_18$$25);
				zephir_create_array(&_18$$25, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_18$$25, SL("type"), SL("literal"));
				ZEPHIR_OBS_VAR(&_19$$25);
				zephir_array_fetch_string(&_19$$25, &expr, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 581 TSRMLS_CC);
				zephir_array_update_string(&_18$$25, SL("value"), &_19$$25, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_18$$25);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 333)) {
				ZEPHIR_INIT_VAR(&_20$$26);
				zephir_create_array(&_20$$26, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_20$$26, SL("type"), SL("literal"));
				add_assoc_stringl_ex(&_20$$26, SL("value"), SL("TRUE"));
				ZEPHIR_CPY_WRT(&exprReturn, &_20$$26);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 334)) {
				ZEPHIR_INIT_VAR(&_21$$27);
				zephir_create_array(&_21$$27, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_21$$27, SL("type"), SL("literal"));
				add_assoc_stringl_ex(&_21$$27, SL("value"), SL("FALSE"));
				ZEPHIR_CPY_WRT(&exprReturn, &_21$$27);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 260)) {
				ZEPHIR_OBS_VAR(&value);
				zephir_array_fetch_string(&value, &expr, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 593 TSRMLS_CC);
				if (quoting == 1) {
					if (zephir_memnstr_str(&value, SL("'"), "phalcon/mvc/model/query.zep", 598)) {
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
				ZEPHIR_INIT_VAR(&_22$$28);
				zephir_create_array(&_22$$28, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_22$$28, SL("type"), SL("literal"));
				zephir_array_update_string(&_22$$28, SL("value"), &exprValue, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_22$$28);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 273)) {
				ZEPHIR_INIT_VAR(&_23$$33);
				zephir_create_array(&_23$$33, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_23$$33, SL("type"), SL("placeholder"));
				ZEPHIR_INIT_VAR(&_24$$33);
				zephir_array_fetch_string(&_25$$33, &expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 611 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_26$$33);
				ZVAL_STRING(&_26$$33, "?");
				ZEPHIR_INIT_VAR(&_27$$33);
				ZVAL_STRING(&_27$$33, ":");
				zephir_fast_str_replace(&_24$$33, &_26$$33, &_27$$33, &_25$$33 TSRMLS_CC);
				zephir_array_update_string(&_23$$33, SL("value"), &_24$$33, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_23$$33);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 274)) {
				ZEPHIR_INIT_VAR(&_28$$34);
				zephir_create_array(&_28$$34, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_28$$34, SL("type"), SL("placeholder"));
				zephir_array_fetch_string(&_29$$34, &expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 615 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_30$$34);
				ZEPHIR_CONCAT_SV(&_30$$34, ":", &_29$$34);
				zephir_array_update_string(&_28$$34, SL("value"), &_30$$34, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_28$$34);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 277)) {
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch_string(&value, &expr, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 619 TSRMLS_CC);
				if (zephir_memnstr_str(&value, SL(":"), "phalcon/mvc/model/query.zep", 620)) {
					ZEPHIR_INIT_VAR(&valueParts);
					zephir_fast_explode_str(&valueParts, SL(":"), &value, LONG_MAX TSRMLS_CC);
					ZEPHIR_OBS_VAR(&name);
					zephir_array_fetch_long(&name, &valueParts, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 623 TSRMLS_CC);
					ZEPHIR_OBS_VAR(&bindType);
					zephir_array_fetch_long(&bindType, &valueParts, 1, PH_NOISY, "phalcon/mvc/model/query.zep", 624 TSRMLS_CC);
					do {
						if (ZEPHIR_IS_STRING(&bindType, "str")) {
							ZEPHIR_INIT_VAR(&_31$$37);
							ZVAL_LONG(&_31$$37, 2);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), &name, &_31$$37);
							ZEPHIR_INIT_NVAR(&_31$$37);
							ZEPHIR_INIT_VAR(&_32$$37);
							zephir_create_array(&_32$$37, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(&_32$$37, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_33$$37);
							ZEPHIR_CONCAT_SV(&_33$$37, ":", &name);
							zephir_array_update_string(&_32$$37, SL("value"), &_33$$37, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&exprReturn, &_32$$37);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "int")) {
							ZEPHIR_INIT_VAR(&_34$$38);
							ZVAL_LONG(&_34$$38, 1);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), &name, &_34$$38);
							ZEPHIR_INIT_NVAR(&_34$$38);
							ZEPHIR_INIT_VAR(&_35$$38);
							zephir_create_array(&_35$$38, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(&_35$$38, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_36$$38);
							ZEPHIR_CONCAT_SV(&_36$$38, ":", &name);
							zephir_array_update_string(&_35$$38, SL("value"), &_36$$38, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&exprReturn, &_35$$38);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "double")) {
							ZEPHIR_INIT_VAR(&_37$$39);
							ZVAL_LONG(&_37$$39, 32);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), &name, &_37$$39);
							ZEPHIR_INIT_NVAR(&_37$$39);
							ZEPHIR_INIT_VAR(&_38$$39);
							zephir_create_array(&_38$$39, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(&_38$$39, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_39$$39);
							ZEPHIR_CONCAT_SV(&_39$$39, ":", &name);
							zephir_array_update_string(&_38$$39, SL("value"), &_39$$39, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&exprReturn, &_38$$39);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "bool")) {
							ZEPHIR_INIT_VAR(&_40$$40);
							ZVAL_LONG(&_40$$40, 5);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), &name, &_40$$40);
							ZEPHIR_INIT_NVAR(&_40$$40);
							ZEPHIR_INIT_VAR(&_41$$40);
							zephir_create_array(&_41$$40, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(&_41$$40, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_42$$40);
							ZEPHIR_CONCAT_SV(&_42$$40, ":", &name);
							zephir_array_update_string(&_41$$40, SL("value"), &_42$$40, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&exprReturn, &_41$$40);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "blob")) {
							ZEPHIR_INIT_VAR(&_43$$41);
							ZVAL_LONG(&_43$$41, 3);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), &name, &_43$$41);
							ZEPHIR_INIT_NVAR(&_43$$41);
							ZEPHIR_INIT_VAR(&_44$$41);
							zephir_create_array(&_44$$41, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(&_44$$41, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_45$$41);
							ZEPHIR_CONCAT_SV(&_45$$41, ":", &name);
							zephir_array_update_string(&_44$$41, SL("value"), &_45$$41, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&exprReturn, &_44$$41);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "null")) {
							ZEPHIR_INIT_VAR(&_46$$42);
							ZVAL_LONG(&_46$$42, 0);
							zephir_update_property_array(this_ptr, SL("_bindTypes"), &name, &_46$$42);
							ZEPHIR_INIT_NVAR(&_46$$42);
							ZEPHIR_INIT_VAR(&_47$$42);
							zephir_create_array(&_47$$42, 2, 0 TSRMLS_CC);
							add_assoc_stringl_ex(&_47$$42, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_48$$42);
							ZEPHIR_CONCAT_SV(&_48$$42, ":", &name);
							zephir_array_update_string(&_47$$42, SL("value"), &_48$$42, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&exprReturn, &_47$$42);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "array") || ZEPHIR_IS_STRING(&bindType, "array-str") || ZEPHIR_IS_STRING(&bindType, "array-int")) {
							ZEPHIR_OBS_VAR(&bind);
							zephir_read_property(&_49$$43, this_ptr, SL("_bindParams"), PH_NOISY_CC | PH_READONLY);
							if (!(zephir_array_isset_fetch(&bind, &_49$$43, &name, 0 TSRMLS_CC))) {
								ZEPHIR_INIT_VAR(&_50$$44);
								object_init_ex(&_50$$44, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_VAR(&_51$$44);
								ZEPHIR_CONCAT_SV(&_51$$44, "Bind value is required for array type placeholder: ", &name);
								ZEPHIR_CALL_METHOD(NULL, &_50$$44, "__construct", NULL, 4, &_51$$44);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_50$$44, "phalcon/mvc/model/query.zep", 663 TSRMLS_CC);
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (Z_TYPE_P(&bind) != IS_ARRAY) {
								ZEPHIR_INIT_VAR(&_52$$45);
								object_init_ex(&_52$$45, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_VAR(&_53$$45);
								ZEPHIR_CONCAT_SV(&_53$$45, "Bind type requires an array in placeholder: ", &name);
								ZEPHIR_CALL_METHOD(NULL, &_52$$45, "__construct", NULL, 4, &_53$$45);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_52$$45, "phalcon/mvc/model/query.zep", 667 TSRMLS_CC);
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (zephir_fast_count_int(&bind TSRMLS_CC) < 1) {
								ZEPHIR_INIT_VAR(&_54$$46);
								object_init_ex(&_54$$46, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_VAR(&_55$$46);
								ZEPHIR_CONCAT_SV(&_55$$46, "At least one value must be bound in placeholder: ", &name);
								ZEPHIR_CALL_METHOD(NULL, &_54$$46, "__construct", NULL, 4, &_55$$46);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_54$$46, "phalcon/mvc/model/query.zep", 671 TSRMLS_CC);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_VAR(&_56$$43);
							zephir_create_array(&_56$$43, 4, 0 TSRMLS_CC);
							add_assoc_stringl_ex(&_56$$43, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_57$$43);
							ZEPHIR_CONCAT_SV(&_57$$43, ":", &name);
							zephir_array_update_string(&_56$$43, SL("value"), &_57$$43, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_56$$43, SL("rawValue"), &name, PH_COPY | PH_SEPARATE);
							add_assoc_long_ex(&_56$$43, SL("times"), zephir_fast_count_int(&bind TSRMLS_CC));
							ZEPHIR_CPY_WRT(&exprReturn, &_56$$43);
							break;
						}
						ZEPHIR_INIT_VAR(&_58$$47);
						object_init_ex(&_58$$47, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_VAR(&_59$$47);
						ZEPHIR_CONCAT_SV(&_59$$47, "Unknown bind type: ", &bindType);
						ZEPHIR_CALL_METHOD(NULL, &_58$$47, "__construct", NULL, 4, &_59$$47);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_58$$47, "phalcon/mvc/model/query.zep", 683 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					} while(0);

				} else {
					ZEPHIR_INIT_VAR(&_60$$48);
					zephir_create_array(&_60$$48, 2, 0 TSRMLS_CC);
					add_assoc_stringl_ex(&_60$$48, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_61$$48);
					ZEPHIR_CONCAT_SV(&_61$$48, ":", &value);
					zephir_array_update_string(&_60$$48, SL("value"), &_61$$48, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_60$$48);
				}
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 322)) {
				ZEPHIR_INIT_VAR(&_62$$49);
				zephir_create_array(&_62$$49, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_62$$49, SL("type"), SL("literal"));
				add_assoc_stringl_ex(&_62$$49, SL("value"), SL("NULL"));
				ZEPHIR_CPY_WRT(&exprReturn, &_62$$49);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 268)) {
				ZEPHIR_INIT_VAR(&_63$$50);
				zephir_create_array(&_63$$50, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_63$$50, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_63$$50, SL("op"), SL("LIKE"));
				zephir_array_update_string(&_63$$50, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_63$$50, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_63$$50);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 351)) {
				ZEPHIR_INIT_VAR(&_64$$51);
				zephir_create_array(&_64$$51, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_64$$51, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_64$$51, SL("op"), SL("NOT LIKE"));
				zephir_array_update_string(&_64$$51, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_64$$51, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_64$$51);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 275)) {
				ZEPHIR_INIT_VAR(&_65$$52);
				zephir_create_array(&_65$$52, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_65$$52, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_65$$52, SL("op"), SL("ILIKE"));
				zephir_array_update_string(&_65$$52, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_65$$52, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_65$$52);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 357)) {
				ZEPHIR_INIT_VAR(&_66$$53);
				zephir_create_array(&_66$$53, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_66$$53, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_66$$53, SL("op"), SL("NOT ILIKE"));
				zephir_array_update_string(&_66$$53, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_66$$53, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_66$$53);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '!')) {
				ZEPHIR_INIT_VAR(&_67$$54);
				zephir_create_array(&_67$$54, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_67$$54, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&_67$$54, SL("op"), SL("NOT "));
				zephir_array_update_string(&_67$$54, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_67$$54);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 365)) {
				ZEPHIR_INIT_VAR(&_68$$55);
				zephir_create_array(&_68$$55, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_68$$55, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&_68$$55, SL("op"), SL(" IS NULL"));
				zephir_array_update_string(&_68$$55, SL("left"), &left, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_68$$55);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 366)) {
				ZEPHIR_INIT_VAR(&_69$$56);
				zephir_create_array(&_69$$56, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_69$$56, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&_69$$56, SL("op"), SL(" IS NOT NULL"));
				zephir_array_update_string(&_69$$56, SL("left"), &left, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_69$$56);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 315)) {
				ZEPHIR_INIT_VAR(&_70$$57);
				zephir_create_array(&_70$$57, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_70$$57, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_70$$57, SL("op"), SL("IN"));
				zephir_array_update_string(&_70$$57, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_70$$57, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_70$$57);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 323)) {
				ZEPHIR_INIT_VAR(&_71$$58);
				zephir_create_array(&_71$$58, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_71$$58, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_71$$58, SL("op"), SL("NOT IN"));
				zephir_array_update_string(&_71$$58, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_71$$58, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_71$$58);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 408)) {
				ZEPHIR_INIT_VAR(&_72$$59);
				zephir_create_array(&_72$$59, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_72$$59, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&_72$$59, SL("op"), SL("EXISTS"));
				zephir_array_update_string(&_72$$59, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_72$$59);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 330)) {
				ZEPHIR_INIT_VAR(&_73$$60);
				zephir_create_array(&_73$$60, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_73$$60, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&_73$$60, SL("op"), SL("DISTINCT "));
				zephir_array_update_string(&_73$$60, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_73$$60);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 331)) {
				ZEPHIR_INIT_VAR(&_74$$61);
				zephir_create_array(&_74$$61, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_74$$61, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_74$$61, SL("op"), SL("BETWEEN"));
				zephir_array_update_string(&_74$$61, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_74$$61, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_74$$61);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 276)) {
				ZEPHIR_INIT_VAR(&_75$$62);
				zephir_create_array(&_75$$62, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_75$$62, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_75$$62, SL("op"), SL("AGAINST"));
				zephir_array_update_string(&_75$$62, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_75$$62, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_75$$62);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 332)) {
				ZEPHIR_INIT_VAR(&_76$$63);
				zephir_create_array(&_76$$63, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_76$$63, SL("type"), SL("cast"));
				zephir_array_update_string(&_76$$63, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_76$$63, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_76$$63);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 335)) {
				ZEPHIR_INIT_VAR(&_77$$64);
				zephir_create_array(&_77$$64, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_77$$64, SL("type"), SL("convert"));
				zephir_array_update_string(&_77$$64, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_77$$64, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_77$$64);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 358)) {
				ZEPHIR_INIT_VAR(&_78$$65);
				zephir_create_array(&_78$$65, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_78$$65, SL("type"), SL("literal"));
				ZEPHIR_OBS_VAR(&_79$$65);
				zephir_array_fetch_string(&_79$$65, &expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 756 TSRMLS_CC);
				zephir_array_update_string(&_78$$65, SL("value"), &_79$$65, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_78$$65);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 350)) {
				ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "_getfunctioncall", NULL, 340, &expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 409)) {
				ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "_getcaseexpression", NULL, 341, &expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 309)) {
				ZEPHIR_INIT_VAR(&_80$$68);
				zephir_create_array(&_80$$68, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_80$$68, SL("type"), SL("select"));
				ZVAL_BOOL(&_82$$68, 1);
				ZEPHIR_CALL_METHOD(&_81$$68, this_ptr, "_prepareselect", NULL, 342, &expr, &_82$$68);
				zephir_check_call_status();
				zephir_array_update_string(&_80$$68, SL("value"), &_81$$68, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_80$$68);
				break;
			}
			ZEPHIR_INIT_VAR(&_83$$69);
			object_init_ex(&_83$$69, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_84$$69);
			ZEPHIR_CONCAT_SV(&_84$$69, "Unknown expression type ", &exprType);
			ZEPHIR_CALL_METHOD(NULL, &_83$$69, "__construct", NULL, 4, &_84$$69);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_83$$69, "phalcon/mvc/model/query.zep", 772 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

		RETURN_CCTOR(&exprReturn);
	}
	if (zephir_array_isset_string(&expr, SL("domain"))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualified", NULL, 339, &expr);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_array_isset_long(&expr, 0)) {
		ZEPHIR_INIT_VAR(&listItems);
		array_init(&listItems);
		zephir_is_iterable(&expr, 0, "phalcon/mvc/model/query.zep", 793);
		if (Z_TYPE_P(&expr) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&expr), _85$$71)
			{
				ZEPHIR_INIT_NVAR(&exprListItem);
				ZVAL_COPY(&exprListItem, _85$$71);
				ZEPHIR_CALL_METHOD(&_87$$72, this_ptr, "_getexpression", NULL, 337, &exprListItem);
				zephir_check_call_status();
				zephir_array_append(&listItems, &_87$$72, PH_SEPARATE, "phalcon/mvc/model/query.zep", 791);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &expr, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_86$$71, &expr, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_86$$71)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&exprListItem, &expr, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_88$$73, this_ptr, "_getexpression", NULL, 337, &exprListItem);
					zephir_check_call_status();
					zephir_array_append(&listItems, &_88$$73, PH_SEPARATE, "phalcon/mvc/model/query.zep", 791);
				ZEPHIR_CALL_METHOD(NULL, &expr, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&exprListItem);
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		add_assoc_stringl_ex(return_value, SL("type"), SL("list"));
		zephir_array_fast_append(return_value, &listItems);
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Unknown expression", "phalcon/mvc/model/query.zep", 796);
	return;

}

/**
 * Resolves a column from its intermediate representation into an array used to determine
 * if the resultset produced is simple or complex
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSelectColumn) {

	zend_string *_4$$4;
	zend_ulong _3$$4;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column_param = NULL, sqlColumns, columnType, sqlAliases, modelName, source, columnDomain, sqlColumnAlias, preparedAlias, sqlExprColumn, sqlAliasesModels, sqlColumn, columnData, balias, eager, _18, _19, _0$$4, *_1$$4, _2$$4, _5$$5, _7$$6, _8$$7, _9$$7, _10$$8, _11$$11, _12$$11, _13$$11, _14$$10, _15$$15, _16$$16, _17$$18;
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
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$18);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column_param);

	ZEPHIR_OBS_COPY_OR_DUP(&column, column_param);


	ZEPHIR_OBS_VAR(&columnType);
	if (!(zephir_array_isset_string_fetch(&columnType, &column, SL("type"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 810);
		return;
	}
	ZEPHIR_INIT_VAR(&sqlColumns);
	array_init(&sqlColumns);
	ZEPHIR_OBS_VAR(&eager);
	zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 0);
	if (ZEPHIR_IS_LONG(&columnType, 352)) {
		zephir_read_property(&_0$$4, this_ptr, SL("_models"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_0$$4, 0, "phalcon/mvc/model/query.zep", 840);
		if (Z_TYPE_P(&_0$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0$$4), _3$$4, _4$$4, _1$$4)
			{
				ZEPHIR_INIT_NVAR(&modelName);
				if (_4$$4 != NULL) { 
					ZVAL_STR_COPY(&modelName, _4$$4);
				} else {
					ZVAL_LONG(&modelName, _3$$4);
				}
				ZEPHIR_INIT_NVAR(&source);
				ZVAL_COPY(&source, _1$$4);
				ZEPHIR_INIT_NVAR(&sqlColumn);
				zephir_create_array(&sqlColumn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&sqlColumn, SL("type"), SL("object"));
				zephir_array_update_string(&sqlColumn, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&sqlColumn, SL("column"), &source, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_5$$5, "lcfirst", &_6, 53, &modelName);
				zephir_check_call_status();
				zephir_array_update_string(&sqlColumn, SL("balias"), &_5$$5, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(&eager) != IS_NULL) {
					zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_string(&_7$$6, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 835 TSRMLS_CC);
					zephir_array_update_string(&sqlColumn, SL("eagerType"), &_7$$6, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 838);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_0$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$4, &_0$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&modelName, &_0$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &_0$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_8$$7);
					zephir_create_array(&_8$$7, 4, 0 TSRMLS_CC);
					add_assoc_stringl_ex(&_8$$7, SL("type"), SL("object"));
					zephir_array_update_string(&_8$$7, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_8$$7, SL("column"), &source, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_FUNCTION(&_9$$7, "lcfirst", &_6, 53, &modelName);
					zephir_check_call_status();
					zephir_array_update_string(&_8$$7, SL("balias"), &_9$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&sqlColumn, &_8$$7);
					if (Z_TYPE_P(&eager) != IS_NULL) {
						zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
						zephir_array_fetch_string(&_10$$8, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 835 TSRMLS_CC);
						zephir_array_update_string(&sqlColumn, SL("eagerType"), &_10$$8, PH_COPY | PH_SEPARATE);
					}
					zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 838);
				ZEPHIR_CALL_METHOD(NULL, &_0$$4, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&source);
		ZEPHIR_INIT_NVAR(&modelName);
		RETURN_CCTOR(&sqlColumns);
	}
	if (!(zephir_array_isset_string(&column, SL("column")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 844);
		return;
	}
	if (ZEPHIR_IS_LONG(&columnType, 353)) {
		ZEPHIR_OBS_VAR(&sqlAliases);
		zephir_read_property(&sqlAliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&columnDomain);
		zephir_array_fetch_string(&columnDomain, &column, SL("column"), PH_NOISY, "phalcon/mvc/model/query.zep", 857 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&source);
		if (!(zephir_array_isset_fetch(&source, &sqlAliases, &columnDomain, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(&_11$$11);
			object_init_ex(&_11$$11, phalcon_mvc_model_exception_ce);
			zephir_read_property(&_12$$11, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_13$$11);
			ZEPHIR_CONCAT_SVSV(&_13$$11, "Unknown model or alias '", &columnDomain, "' (2), when preparing: ", &_12$$11);
			ZEPHIR_CALL_METHOD(NULL, &_11$$11, "__construct", NULL, 4, &_13$$11);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_11$$11, "phalcon/mvc/model/query.zep", 860 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&sqlColumnAlias, &source);
		ZEPHIR_OBS_VAR(&preparedAlias);
		zephir_array_isset_string_fetch(&preparedAlias, &column, SL("balias"), 0);
		ZEPHIR_OBS_VAR(&sqlAliasesModels);
		zephir_read_property(&sqlAliasesModels, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&modelName);
		zephir_array_fetch(&modelName, &sqlAliasesModels, &columnDomain, PH_NOISY, "phalcon/mvc/model/query.zep", 874 TSRMLS_CC);
		if (Z_TYPE_P(&preparedAlias) != IS_STRING) {
			if (ZEPHIR_IS_EQUAL(&columnDomain, &modelName)) {
				ZEPHIR_CALL_FUNCTION(&preparedAlias, "lcfirst", &_6, 53, &modelName);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&preparedAlias, &columnDomain);
			}
		}
		ZEPHIR_INIT_VAR(&_14$$10);
		zephir_create_array(&_14$$10, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_14$$10, SL("type"), SL("object"));
		zephir_array_update_string(&_14$$10, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_14$$10, SL("column"), &sqlColumnAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_14$$10, SL("balias"), &preparedAlias, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&sqlColumn, &_14$$10);
		if (Z_TYPE_P(&eager) != IS_NULL) {
			zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_15$$15, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 900 TSRMLS_CC);
			zephir_array_update_string(&sqlColumn, SL("eagerType"), &_15$$15, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 903);
		RETURN_CCTOR(&sqlColumns);
	}
	if (ZEPHIR_IS_LONG(&columnType, 354)) {
		ZEPHIR_INIT_VAR(&_16$$16);
		zephir_create_array(&_16$$16, 1, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_16$$16, SL("type"), SL("scalar"));
		ZEPHIR_CPY_WRT(&sqlColumn, &_16$$16);
		ZEPHIR_OBS_VAR(&columnData);
		zephir_array_fetch_string(&columnData, &column, SL("column"), PH_NOISY, "phalcon/mvc/model/query.zep", 917 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&sqlExprColumn, this_ptr, "_getexpression", NULL, 337, &columnData);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&balias);
		if (zephir_array_isset_string_fetch(&balias, &sqlExprColumn, SL("balias"), 0)) {
			zephir_array_update_string(&sqlColumn, SL("balias"), &balias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &balias, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&eager) != IS_NULL) {
			zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_17$$18, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 930 TSRMLS_CC);
			zephir_array_update_string(&sqlColumn, SL("eagerType"), &_17$$18, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&sqlColumn, SL("column"), &sqlExprColumn, PH_COPY | PH_SEPARATE);
		zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 934);
		RETURN_CCTOR(&sqlColumns);
	}
	ZEPHIR_INIT_VAR(&_18);
	object_init_ex(&_18, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(&_19);
	ZEPHIR_CONCAT_SV(&_19, "Unknown type of column ", &columnType);
	ZEPHIR_CALL_METHOD(NULL, &_18, "__construct", NULL, 4, &_19);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_18, "phalcon/mvc/model/query.zep", 939 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Resolves a table in a SELECT statement checking if the model exists
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getTable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval qualifiedName;
	zval *manager, manager_sub, *qualifiedName_param = NULL, modelName, model, source, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager_sub);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&qualifiedName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &manager, &qualifiedName_param);

	zephir_get_arrval(&qualifiedName, qualifiedName_param);


	ZEPHIR_OBS_VAR(&modelName);
	if (!(zephir_array_isset_string_fetch(&modelName, &qualifiedName, SL("name"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 952);
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
	zval join;
	zval *manager, manager_sub, *join_param = NULL, qualified, modelName, realModelName, nsAlias, source, model, schema, _0$$3, _1$$5, _2$$5, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager_sub);
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
	ZVAL_UNDEF(&join);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &manager, &join_param);

	zephir_get_arrval(&join, join_param);


	ZEPHIR_OBS_VAR(&qualified);
	if (zephir_array_isset_string_fetch(&qualified, &join, SL("qualified"), 0)) {
		zephir_array_fetch_string(&_0$$3, &qualified, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 976 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(&_0$$3, 355)) {
			ZEPHIR_OBS_VAR(&modelName);
			zephir_array_fetch_string(&modelName, &qualified, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 978 TSRMLS_CC);
			if (zephir_memnstr_str(&modelName, SL(":"), "phalcon/mvc/model/query.zep", 980)) {
				ZEPHIR_INIT_VAR(&nsAlias);
				zephir_fast_explode_str(&nsAlias, SL(":"), &modelName, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_2$$5, &nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 982 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_1$$5, manager, "getnamespacealias", NULL, 0, &_2$$5);
				zephir_check_call_status();
				zephir_array_fetch_long(&_3$$5, &nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 982 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&realModelName);
				ZEPHIR_CONCAT_VSV(&realModelName, &_1$$5, "\\", &_3$$5);
			} else {
				ZEPHIR_CPY_WRT(&realModelName, &modelName);
			}
			ZEPHIR_CALL_METHOD(&model, manager, "load", NULL, 0, &realModelName);
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
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 1000);
	return;

}

/**
 * Resolves a JOIN type
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoinType) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *join_param = NULL, type, _0, _1, _2;
	zval join;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &join_param);

	zephir_get_arrval(&join, join_param);


	ZEPHIR_OBS_VAR(&type);
	if (!(zephir_array_isset_string_fetch(&type, &join, SL("type"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 1011);
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
	zephir_throw_exception_debug(&_0, "phalcon/mvc/model/query.zep", 1032 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Resolves joins involving has-one/belongs-to/has-many relations
 *
 * @param string joinSource
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSingleJoin) {

	zend_string *_8$$4;
	zend_ulong _7$$4;
	zval _1$$3, _3$$3, _4$$3, _13$$5, _15$$5, _16$$5, _20$$7, _22$$7, _23$$7;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *joinType_param = NULL, *joinSource, joinSource_sub, *modelAlias_param = NULL, *joinAlias_param = NULL, *relation, relation_sub, fields, referencedFields, sqlJoinConditions, sqlJoinPartialConditions, position, field, referencedField, _0$$3, _2$$3, *_5$$4, _6$$4, _9$$6, _10$$6, _11$$6, _14$$5, _17$$8, _18$$8, _19$$8, _21$$7;
	zval joinType, modelAlias, joinAlias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&joinType);
	ZVAL_UNDEF(&modelAlias);
	ZVAL_UNDEF(&joinAlias);
	ZVAL_UNDEF(&joinSource_sub);
	ZVAL_UNDEF(&relation_sub);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&sqlJoinConditions);
	ZVAL_UNDEF(&sqlJoinPartialConditions);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&referencedField);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &joinType_param, &joinSource, &modelAlias_param, &joinAlias_param, &relation);

	if (UNEXPECTED(Z_TYPE_P(joinType_param) != IS_STRING && Z_TYPE_P(joinType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinType' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinType_param) == IS_STRING)) {
		zephir_get_strval(&joinType, joinType_param);
	} else {
		ZEPHIR_INIT_VAR(&joinType);
		ZVAL_EMPTY_STRING(&joinType);
	}
	zephir_get_strval(&modelAlias, modelAlias_param);
	zephir_get_strval(&joinAlias, joinAlias_param);


	ZEPHIR_INIT_VAR(&sqlJoinConditions);
	ZVAL_NULL(&sqlJoinConditions);
	ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&fields) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_1$$3, SL("type"), SL("binary-op"));
		add_assoc_stringl_ex(&_1$$3, SL("op"), SL("="));
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(&_3$$3, SL("type"), 355);
		zephir_array_update_string(&_3$$3, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3$$3, SL("name"), &fields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "_getqualified", NULL, 339, &_3$$3);
		zephir_check_call_status();
		zephir_array_update_string(&_1$$3, SL("left"), &_2$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_create_array(&_4$$3, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_4$$3, SL("type"), SL("qualified"));
		zephir_array_update_string(&_4$$3, SL("domain"), &joinAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_4$$3, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "_getqualified", NULL, 339, &_4$$3);
		zephir_check_call_status();
		zephir_array_update_string(&_1$$3, SL("right"), &_2$$3, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_CPY_WRT(&sqlJoinConditions, &_0$$3);
	} else {
		ZEPHIR_INIT_VAR(&sqlJoinPartialConditions);
		array_init(&sqlJoinPartialConditions);
		zephir_is_iterable(&fields, 0, "phalcon/mvc/model/query.zep", 1117);
		if (Z_TYPE_P(&fields) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _7$$4, _8$$4, _5$$4)
			{
				ZEPHIR_INIT_NVAR(&position);
				if (_8$$4 != NULL) { 
					ZVAL_STR_COPY(&position, _8$$4);
				} else {
					ZVAL_LONG(&position, _7$$4);
				}
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _5$$4);
				ZEPHIR_OBS_NVAR(&referencedField);
				if (!(zephir_array_isset_fetch(&referencedField, &referencedFields, &position, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_9$$6);
					object_init_ex(&_9$$6, phalcon_mvc_model_exception_ce);
					zephir_read_property(&_10$$6, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_LNVAR(_11$$6);
					ZEPHIR_CONCAT_SVSVSV(&_11$$6, "The number of fields must be equal to the number of referenced fields in join ", &modelAlias, "-", &joinAlias, ", when preparing: ", &_10$$6);
					ZEPHIR_CALL_METHOD(NULL, &_9$$6, "__construct", &_12, 4, &_11$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$6, "phalcon/mvc/model/query.zep", 1093 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_13$$5);
				zephir_create_array(&_13$$5, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_13$$5, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_13$$5, SL("op"), SL("="));
				ZEPHIR_INIT_NVAR(&_15$$5);
				zephir_create_array(&_15$$5, 3, 0 TSRMLS_CC);
				add_assoc_long_ex(&_15$$5, SL("type"), 355);
				zephir_array_update_string(&_15$$5, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_15$$5, SL("name"), &field, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_14$$5, this_ptr, "_getqualified", NULL, 339, &_15$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_13$$5, SL("left"), &_14$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_16$$5);
				zephir_create_array(&_16$$5, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_16$$5, SL("type"), SL("qualified"));
				zephir_array_update_string(&_16$$5, SL("domain"), &joinAlias, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_16$$5, SL("name"), &referencedField, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_14$$5, this_ptr, "_getqualified", NULL, 339, &_16$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_13$$5, SL("right"), &_14$$5, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlJoinPartialConditions, &_13$$5, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1114);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_6$$4, &fields, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&position, &fields, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&referencedField);
					if (!(zephir_array_isset_fetch(&referencedField, &referencedFields, &position, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(&_17$$8);
						object_init_ex(&_17$$8, phalcon_mvc_model_exception_ce);
						zephir_read_property(&_18$$8, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_LNVAR(_19$$8);
						ZEPHIR_CONCAT_SVSVSV(&_19$$8, "The number of fields must be equal to the number of referenced fields in join ", &modelAlias, "-", &joinAlias, ", when preparing: ", &_18$$8);
						ZEPHIR_CALL_METHOD(NULL, &_17$$8, "__construct", &_12, 4, &_19$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_17$$8, "phalcon/mvc/model/query.zep", 1093 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_20$$7);
					zephir_create_array(&_20$$7, 4, 0 TSRMLS_CC);
					add_assoc_stringl_ex(&_20$$7, SL("type"), SL("binary-op"));
					add_assoc_stringl_ex(&_20$$7, SL("op"), SL("="));
					ZEPHIR_INIT_NVAR(&_22$$7);
					zephir_create_array(&_22$$7, 3, 0 TSRMLS_CC);
					add_assoc_long_ex(&_22$$7, SL("type"), 355);
					zephir_array_update_string(&_22$$7, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_22$$7, SL("name"), &field, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_21$$7, this_ptr, "_getqualified", NULL, 339, &_22$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_20$$7, SL("left"), &_21$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_23$$7);
					zephir_create_array(&_23$$7, 3, 0 TSRMLS_CC);
					add_assoc_stringl_ex(&_23$$7, SL("type"), SL("qualified"));
					zephir_array_update_string(&_23$$7, SL("domain"), &joinAlias, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_23$$7, SL("name"), &referencedField, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_21$$7, this_ptr, "_getqualified", NULL, 339, &_23$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_20$$7, SL("right"), &_21$$7, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlJoinPartialConditions, &_20$$7, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1114);
				ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
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
 * @param string joinSource
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getMultiJoin) {

	zval _9$$4, _11$$4, _17$$6, _18$$6, _20$$8, _21$$8, _22$$8, _24$$8, _25$$8, _26$$8, _27$$8;
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *joinType_param = NULL, *joinSource, joinSource_sub, *modelAlias_param = NULL, *joinAlias_param = NULL, *relation, relation_sub, sqlJoins, fields, referencedFields, intermediateModelName, intermediateModel, intermediateSource, intermediateSchema, intermediateFields, intermediateReferencedFields, referencedModelName, manager, field, position, intermediateField, sqlEqualsJoinCondition, *_0$$3, _1$$3, _4$$5, _5$$5, _6$$5, _8$$4, _12$$7, _13$$7, _14$$7, _15$$6, _16$$6, _19$$8, _23$$8;
	zval joinType, modelAlias, joinAlias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&joinType);
	ZVAL_UNDEF(&modelAlias);
	ZVAL_UNDEF(&joinAlias);
	ZVAL_UNDEF(&joinSource_sub);
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
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &joinType_param, &joinSource, &modelAlias_param, &joinAlias_param, &relation);

	if (UNEXPECTED(Z_TYPE_P(joinType_param) != IS_STRING && Z_TYPE_P(joinType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinType' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinType_param) == IS_STRING)) {
		zephir_get_strval(&joinType, joinType_param);
	} else {
		ZEPHIR_INIT_VAR(&joinType);
		ZVAL_EMPTY_STRING(&joinType);
	}
	zephir_get_strval(&modelAlias, modelAlias_param);
	zephir_get_strval(&joinAlias, joinAlias_param);


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
	zephir_update_property_array(this_ptr, SL("_sqlAliases"), &intermediateModelName, &intermediateSource);
	zephir_update_property_array(this_ptr, SL("_sqlAliasesModelsInstances"), &intermediateModelName, &intermediateModel);
	ZEPHIR_CALL_METHOD(&intermediateFields, relation, "getintermediatefields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateReferencedFields, relation, "getintermediatereferencedfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedModelName, relation, "getreferencedmodel", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		zephir_is_iterable(&fields, 0, "phalcon/mvc/model/query.zep", 1239);
		if (Z_TYPE_P(&fields) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&field);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&field, _3$$3);
				} else {
					ZVAL_LONG(&field, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&position);
				ZVAL_COPY(&position, _0$$3);
				if (!(zephir_array_isset(&referencedFields, &position))) {
					ZEPHIR_INIT_NVAR(&_4$$5);
					object_init_ex(&_4$$5, phalcon_mvc_model_exception_ce);
					zephir_read_property(&_5$$5, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_LNVAR(_6$$5);
					ZEPHIR_CONCAT_SVSVSV(&_6$$5, "The number of fields must be equal to the number of referenced fields in join ", &modelAlias, "-", &joinAlias, ", when preparing: ", &_5$$5);
					ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", &_7, 4, &_6$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_4$$5, "phalcon/mvc/model/query.zep", 1210 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&intermediateField);
				zephir_array_fetch(&intermediateField, &intermediateFields, &position, PH_NOISY, "phalcon/mvc/model/query.zep", 1216 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&sqlEqualsJoinCondition);
				zephir_create_array(&sqlEqualsJoinCondition, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&sqlEqualsJoinCondition, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&sqlEqualsJoinCondition, SL("op"), SL("="));
				ZEPHIR_INIT_NVAR(&_9$$4);
				zephir_create_array(&_9$$4, 3, 0 TSRMLS_CC);
				add_assoc_long_ex(&_9$$4, SL("type"), 355);
				zephir_array_update_string(&_9$$4, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_9$$4, SL("name"), &field, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "_getqualified", &_10, 339, &_9$$4);
				zephir_check_call_status();
				zephir_array_update_string(&sqlEqualsJoinCondition, SL("left"), &_8$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_11$$4);
				zephir_create_array(&_11$$4, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(&_11$$4, SL("type"), SL("qualified"));
				zephir_array_update_string(&_11$$4, SL("domain"), &joinAlias, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_11$$4, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "_getqualified", &_10, 339, &_11$$4);
				zephir_check_call_status();
				zephir_array_update_string(&sqlEqualsJoinCondition, SL("right"), &_8$$4, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &fields, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &fields, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&position, &fields, "current", NULL, 0);
				zephir_check_call_status();
					if (!(zephir_array_isset(&referencedFields, &position))) {
						ZEPHIR_INIT_NVAR(&_12$$7);
						object_init_ex(&_12$$7, phalcon_mvc_model_exception_ce);
						zephir_read_property(&_13$$7, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_LNVAR(_14$$7);
						ZEPHIR_CONCAT_SVSVSV(&_14$$7, "The number of fields must be equal to the number of referenced fields in join ", &modelAlias, "-", &joinAlias, ", when preparing: ", &_13$$7);
						ZEPHIR_CALL_METHOD(NULL, &_12$$7, "__construct", &_7, 4, &_14$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_12$$7, "phalcon/mvc/model/query.zep", 1210 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&intermediateField);
					zephir_array_fetch(&intermediateField, &intermediateFields, &position, PH_NOISY, "phalcon/mvc/model/query.zep", 1216 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_15$$6);
					zephir_create_array(&_15$$6, 4, 0 TSRMLS_CC);
					add_assoc_stringl_ex(&_15$$6, SL("type"), SL("binary-op"));
					add_assoc_stringl_ex(&_15$$6, SL("op"), SL("="));
					ZEPHIR_INIT_NVAR(&_17$$6);
					zephir_create_array(&_17$$6, 3, 0 TSRMLS_CC);
					add_assoc_long_ex(&_17$$6, SL("type"), 355);
					zephir_array_update_string(&_17$$6, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_17$$6, SL("name"), &field, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_16$$6, this_ptr, "_getqualified", &_10, 339, &_17$$6);
					zephir_check_call_status();
					zephir_array_update_string(&_15$$6, SL("left"), &_16$$6, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_18$$6);
					zephir_create_array(&_18$$6, 3, 0 TSRMLS_CC);
					add_assoc_stringl_ex(&_18$$6, SL("type"), SL("qualified"));
					zephir_array_update_string(&_18$$6, SL("domain"), &joinAlias, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_18$$6, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_16$$6, this_ptr, "_getqualified", &_10, 339, &_18$$6);
					zephir_check_call_status();
					zephir_array_update_string(&_15$$6, SL("right"), &_16$$6, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&sqlEqualsJoinCondition, &_15$$6);
				ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&position);
		ZEPHIR_INIT_NVAR(&field);
	} else {
		ZEPHIR_INIT_VAR(&_19$$8);
		zephir_create_array(&_19$$8, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_20$$8);
		zephir_create_array(&_20$$8, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&_20$$8, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_20$$8, SL("source"), &intermediateSource, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_21$$8);
		zephir_create_array(&_21$$8, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_22$$8);
		zephir_create_array(&_22$$8, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_22$$8, SL("type"), SL("binary-op"));
		add_assoc_stringl_ex(&_22$$8, SL("op"), SL("="));
		ZEPHIR_INIT_VAR(&_24$$8);
		zephir_create_array(&_24$$8, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(&_24$$8, SL("type"), 355);
		zephir_array_update_string(&_24$$8, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_24$$8, SL("name"), &fields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_23$$8, this_ptr, "_getqualified", &_10, 339, &_24$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_22$$8, SL("left"), &_23$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_25$$8);
		zephir_create_array(&_25$$8, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_25$$8, SL("type"), SL("qualified"));
		zephir_array_update_string(&_25$$8, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_25$$8, SL("name"), &intermediateFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_23$$8, this_ptr, "_getqualified", &_10, 339, &_25$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_22$$8, SL("right"), &_23$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_21$$8, &_22$$8);
		zephir_array_update_string(&_20$$8, SL("conditions"), &_21$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_19$$8, &_20$$8);
		ZEPHIR_INIT_NVAR(&_20$$8);
		zephir_create_array(&_20$$8, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&_20$$8, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_20$$8, SL("source"), joinSource, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_21$$8);
		zephir_create_array(&_21$$8, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_22$$8);
		zephir_create_array(&_22$$8, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_22$$8, SL("type"), SL("binary-op"));
		add_assoc_stringl_ex(&_22$$8, SL("op"), SL("="));
		ZEPHIR_INIT_VAR(&_26$$8);
		zephir_create_array(&_26$$8, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(&_26$$8, SL("type"), 355);
		zephir_array_update_string(&_26$$8, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_26$$8, SL("name"), &intermediateReferencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_23$$8, this_ptr, "_getqualified", &_10, 339, &_26$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_22$$8, SL("left"), &_23$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_27$$8);
		zephir_create_array(&_27$$8, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_27$$8, SL("type"), SL("qualified"));
		zephir_array_update_string(&_27$$8, SL("domain"), &referencedModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_27$$8, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_23$$8, this_ptr, "_getqualified", &_10, 339, &_27$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_22$$8, SL("right"), &_23$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_21$$8, &_22$$8);
		zephir_array_update_string(&_20$$8, SL("conditions"), &_21$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_19$$8, &_20$$8);
		ZEPHIR_CPY_WRT(&sqlJoins, &_19$$8);
	}
	RETURN_CCTOR(&sqlJoins);

}

/**
 * Processes the JOINs in the query returning an internal representation for the database dialect
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoins) {

	zend_string *_21, *_45, *_30$$21, *_49$$26, *_79$$55;
	zend_ulong _20, _44, _29$$21, _48$$26, _78$$55;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_7 = NULL, *_23 = NULL, *_50 = NULL, *_51 = NULL, *_56 = NULL, *_57 = NULL, *_64 = NULL, *_65 = NULL, *_80 = NULL, *_81 = NULL, *_92 = NULL, *_93 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *select_param = NULL, __$true, models, sqlAliases, sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances, modelsInstances, fromModels, sqlJoins, joinModels, joinSources, joinTypes, joinPreCondition, joinPrepared, manager, selectJoins, joinItem, joins, joinData, schema, source, model, realModelName, completeSource, joinType, aliasExpr, alias, joinAliasName, joinExpr, fromModelName, joinAlias, joinModel, joinSource, preCondition, modelNameAlias, relation, relations, modelAlias, sqlJoin, sqlJoinItem, selectTables, tables, tableItem, *_0, _1, *_18, _19, _25, *_35, _36, _41, *_42, _43, _4$$9, _5$$9, _6$$9, _8$$11, _9$$11, _10$$11, _11$$12, _12$$14, _13$$14, _14$$14, _15$$16, _16$$16, _17$$16, _22$$18, _24$$20, _26$$21, *_27$$21, _28$$21, _37$$24, _38$$24, _39$$25, _40$$25, *_46$$26, _47$$26, _52$$31, _53$$31, _54$$31, _55$$32, *_58$$35, _59$$35, _61$$39, _66$$45, _67$$45, _68$$45, _69$$46, *_70$$49, _71$$49, _73$$53, *_76$$55, _77$$55, _82$$60, _83$$60, _84$$60, _85$$61, *_86$$64, _87$$64, _89$$68, _94$$74, _95$$74, _96$$74, _97$$75, *_98$$78, _99$$78, _101$$82;
	zval select, _31$$22, _32$$22, _33$$23, _34$$23, _60$$39, _62$$40, _63$$40, _72$$53, _74$$54, _75$$54, _88$$68, _90$$69, _91$$69, _100$$82, _102$$83, _103$$83;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&select);
	ZVAL_UNDEF(&_31$$22);
	ZVAL_UNDEF(&_32$$22);
	ZVAL_UNDEF(&_33$$23);
	ZVAL_UNDEF(&_34$$23);
	ZVAL_UNDEF(&_60$$39);
	ZVAL_UNDEF(&_62$$40);
	ZVAL_UNDEF(&_63$$40);
	ZVAL_UNDEF(&_72$$53);
	ZVAL_UNDEF(&_74$$54);
	ZVAL_UNDEF(&_75$$54);
	ZVAL_UNDEF(&_88$$68);
	ZVAL_UNDEF(&_90$$69);
	ZVAL_UNDEF(&_91$$69);
	ZVAL_UNDEF(&_100$$82);
	ZVAL_UNDEF(&_102$$83);
	ZVAL_UNDEF(&_103$$83);
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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_26$$21);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_37$$24);
	ZVAL_UNDEF(&_38$$24);
	ZVAL_UNDEF(&_39$$25);
	ZVAL_UNDEF(&_40$$25);
	ZVAL_UNDEF(&_47$$26);
	ZVAL_UNDEF(&_52$$31);
	ZVAL_UNDEF(&_53$$31);
	ZVAL_UNDEF(&_54$$31);
	ZVAL_UNDEF(&_55$$32);
	ZVAL_UNDEF(&_59$$35);
	ZVAL_UNDEF(&_61$$39);
	ZVAL_UNDEF(&_66$$45);
	ZVAL_UNDEF(&_67$$45);
	ZVAL_UNDEF(&_68$$45);
	ZVAL_UNDEF(&_69$$46);
	ZVAL_UNDEF(&_71$$49);
	ZVAL_UNDEF(&_73$$53);
	ZVAL_UNDEF(&_77$$55);
	ZVAL_UNDEF(&_82$$60);
	ZVAL_UNDEF(&_83$$60);
	ZVAL_UNDEF(&_84$$60);
	ZVAL_UNDEF(&_85$$61);
	ZVAL_UNDEF(&_87$$64);
	ZVAL_UNDEF(&_89$$68);
	ZVAL_UNDEF(&_94$$74);
	ZVAL_UNDEF(&_95$$74);
	ZVAL_UNDEF(&_96$$74);
	ZVAL_UNDEF(&_97$$75);
	ZVAL_UNDEF(&_99$$78);
	ZVAL_UNDEF(&_101$$82);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &select_param);

	zephir_get_arrval(&select, select_param);


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
	zephir_array_fetch_string(&tables, &select, SL("tables"), PH_NOISY, "phalcon/mvc/model/query.zep", 1327 TSRMLS_CC);
	if (!(zephir_array_isset_long(&tables, 0))) {
		ZEPHIR_INIT_VAR(&selectTables);
		zephir_create_array(&selectTables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&selectTables, &tables);
	} else {
		ZEPHIR_CPY_WRT(&selectTables, &tables);
	}
	ZEPHIR_OBS_VAR(&joins);
	zephir_array_fetch_string(&joins, &select, SL("joins"), PH_NOISY, "phalcon/mvc/model/query.zep", 1334 TSRMLS_CC);
	if (!(zephir_array_isset_long(&joins, 0))) {
		ZEPHIR_INIT_VAR(&selectJoins);
		zephir_create_array(&selectJoins, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&selectJoins, &joins);
	} else {
		ZEPHIR_CPY_WRT(&selectJoins, &joins);
	}
	zephir_is_iterable(&selectJoins, 0, "phalcon/mvc/model/query.zep", 1487);
	if (Z_TYPE_P(&selectJoins) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&selectJoins), _0)
		{
			ZEPHIR_INIT_NVAR(&joinItem);
			ZVAL_COPY(&joinItem, _0);
			ZEPHIR_CALL_METHOD(&joinData, this_ptr, "_getjoin", &_2, 343, &manager, &joinItem);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&source);
			zephir_array_fetch_string(&source, &joinData, SL("source"), PH_NOISY, "phalcon/mvc/model/query.zep", 1347 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&schema);
			zephir_array_fetch_string(&schema, &joinData, SL("schema"), PH_NOISY, "phalcon/mvc/model/query.zep", 1348 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&model);
			zephir_array_fetch_string(&model, &joinData, SL("model"), PH_NOISY, "phalcon/mvc/model/query.zep", 1349 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&realModelName);
			zephir_array_fetch_string(&realModelName, &joinData, SL("modelName"), PH_NOISY, "phalcon/mvc/model/query.zep", 1350 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&completeSource);
			zephir_create_array(&completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&completeSource, &source);
			zephir_array_fast_append(&completeSource, &schema);
			ZEPHIR_CALL_METHOD(&joinType, this_ptr, "_getjointype", &_3, 344, &joinItem);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&aliasExpr);
			if (zephir_array_isset_string_fetch(&aliasExpr, &joinItem, SL("alias"), 0)) {
				ZEPHIR_OBS_NVAR(&alias);
				zephir_array_fetch_string(&alias, &aliasExpr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1363 TSRMLS_CC);
				if (zephir_array_isset(&joinModels, &alias)) {
					ZEPHIR_INIT_NVAR(&_4$$9);
					object_init_ex(&_4$$9, phalcon_mvc_model_exception_ce);
					zephir_read_property(&_5$$9, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_LNVAR(_6$$9);
					ZEPHIR_CONCAT_SVSV(&_6$$9, "Cannot use '", &alias, "' as join alias because it was already used, when preparing: ", &_5$$9);
					ZEPHIR_CALL_METHOD(NULL, &_4$$9, "__construct", &_7, 4, &_6$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_4$$9, "phalcon/mvc/model/query.zep", 1371 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1377);
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
					ZEPHIR_INIT_NVAR(&_8$$11);
					object_init_ex(&_8$$11, phalcon_mvc_model_exception_ce);
					zephir_read_property(&_9$$11, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_LNVAR(_10$$11);
					ZEPHIR_CONCAT_SVSV(&_10$$11, "Cannot use '", &realModelName, "' as join alias because it was already used, when preparing: ", &_9$$11);
					ZEPHIR_CALL_METHOD(NULL, &_8$$11, "__construct", &_7, 4, &_10$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$11, "phalcon/mvc/model/query.zep", 1432 TSRMLS_CC);
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
	} else {
		ZEPHIR_CALL_METHOD(NULL, &selectJoins, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &selectJoins, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&joinItem, &selectJoins, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&joinData, this_ptr, "_getjoin", &_2, 343, &manager, &joinItem);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&source);
				zephir_array_fetch_string(&source, &joinData, SL("source"), PH_NOISY, "phalcon/mvc/model/query.zep", 1347 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&schema);
				zephir_array_fetch_string(&schema, &joinData, SL("schema"), PH_NOISY, "phalcon/mvc/model/query.zep", 1348 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&model);
				zephir_array_fetch_string(&model, &joinData, SL("model"), PH_NOISY, "phalcon/mvc/model/query.zep", 1349 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&realModelName);
				zephir_array_fetch_string(&realModelName, &joinData, SL("modelName"), PH_NOISY, "phalcon/mvc/model/query.zep", 1350 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_11$$12);
				zephir_create_array(&_11$$12, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(&_11$$12, &source);
				zephir_array_fast_append(&_11$$12, &schema);
				ZEPHIR_CPY_WRT(&completeSource, &_11$$12);
				ZEPHIR_CALL_METHOD(&joinType, this_ptr, "_getjointype", &_3, 344, &joinItem);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&aliasExpr);
				if (zephir_array_isset_string_fetch(&aliasExpr, &joinItem, SL("alias"), 0)) {
					ZEPHIR_OBS_NVAR(&alias);
					zephir_array_fetch_string(&alias, &aliasExpr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1363 TSRMLS_CC);
					if (zephir_array_isset(&joinModels, &alias)) {
						ZEPHIR_INIT_NVAR(&_12$$14);
						object_init_ex(&_12$$14, phalcon_mvc_model_exception_ce);
						zephir_read_property(&_13$$14, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_LNVAR(_14$$14);
						ZEPHIR_CONCAT_SVSV(&_14$$14, "Cannot use '", &alias, "' as join alias because it was already used, when preparing: ", &_13$$14);
						ZEPHIR_CALL_METHOD(NULL, &_12$$14, "__construct", &_7, 4, &_14$$14);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_12$$14, "phalcon/mvc/model/query.zep", 1371 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1377);
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
						ZEPHIR_INIT_NVAR(&_15$$16);
						object_init_ex(&_15$$16, phalcon_mvc_model_exception_ce);
						zephir_read_property(&_16$$16, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_LNVAR(_17$$16);
						ZEPHIR_CONCAT_SVSV(&_17$$16, "Cannot use '", &realModelName, "' as join alias because it was already used, when preparing: ", &_16$$16);
						ZEPHIR_CALL_METHOD(NULL, &_15$$16, "__construct", &_7, 4, &_17$$16);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_15$$16, "phalcon/mvc/model/query.zep", 1432 TSRMLS_CC);
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
			ZEPHIR_CALL_METHOD(NULL, &selectJoins, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&joinItem);
	zephir_update_property_zval(this_ptr, SL("_models"), &models);
	zephir_update_property_zval(this_ptr, SL("_sqlAliases"), &sqlAliases);
	zephir_update_property_zval(this_ptr, SL("_sqlAliasesModels"), &sqlAliasesModels);
	zephir_update_property_zval(this_ptr, SL("_sqlModelsAliases"), &sqlModelsAliases);
	zephir_update_property_zval(this_ptr, SL("_sqlAliasesModelsInstances"), &sqlAliasesModelsInstances);
	zephir_update_property_zval(this_ptr, SL("_modelsInstances"), &modelsInstances);
	zephir_is_iterable(&joinPrepared, 0, "phalcon/mvc/model/query.zep", 1507);
	if (Z_TYPE_P(&joinPrepared) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinPrepared), _20, _21, _18)
		{
			ZEPHIR_INIT_NVAR(&joinAliasName);
			if (_21 != NULL) { 
				ZVAL_STR_COPY(&joinAliasName, _21);
			} else {
				ZVAL_LONG(&joinAliasName, _20);
			}
			ZEPHIR_INIT_NVAR(&joinItem);
			ZVAL_COPY(&joinItem, _18);
			ZEPHIR_OBS_NVAR(&joinExpr);
			if (zephir_array_isset_string_fetch(&joinExpr, &joinItem, SL("conditions"), 0)) {
				ZEPHIR_CALL_METHOD(&_22$$18, this_ptr, "_getexpression", &_23, 337, &joinExpr);
				zephir_check_call_status();
				zephir_array_update_zval(&joinPreCondition, &joinAliasName, &_22$$18, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &joinPrepared, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_19, &joinPrepared, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_19)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&joinAliasName, &joinPrepared, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&joinItem, &joinPrepared, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&joinExpr);
				if (zephir_array_isset_string_fetch(&joinExpr, &joinItem, SL("conditions"), 0)) {
					ZEPHIR_CALL_METHOD(&_24$$20, this_ptr, "_getexpression", &_23, 337, &joinExpr);
					zephir_check_call_status();
					zephir_array_update_zval(&joinPreCondition, &joinAliasName, &_24$$20, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &joinPrepared, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&joinItem);
	ZEPHIR_INIT_NVAR(&joinAliasName);
	zephir_read_property(&_25, this_ptr, SL("_enableImplicitJoins"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_25))) {
		ZEPHIR_INIT_VAR(&_26$$21);
		zephir_is_iterable(&joinPrepared, 0, "phalcon/mvc/model/query.zep", 1518);
		if (Z_TYPE_P(&joinPrepared) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinPrepared), _29$$21, _30$$21, _27$$21)
			{
				ZEPHIR_INIT_NVAR(&joinAliasName);
				if (_30$$21 != NULL) { 
					ZVAL_STR_COPY(&joinAliasName, _30$$21);
				} else {
					ZVAL_LONG(&joinAliasName, _29$$21);
				}
				ZEPHIR_INIT_NVAR(&_26$$21);
				ZVAL_COPY(&_26$$21, _27$$21);
				ZEPHIR_OBS_NVAR(&joinType);
				zephir_array_fetch(&joinType, &joinTypes, &joinAliasName, PH_NOISY, "phalcon/mvc/model/query.zep", 1509 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&joinSource);
				zephir_array_fetch(&joinSource, &joinSources, &joinAliasName, PH_NOISY, "phalcon/mvc/model/query.zep", 1510 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&preCondition);
				zephir_array_fetch(&preCondition, &joinPreCondition, &joinAliasName, PH_NOISY, "phalcon/mvc/model/query.zep", 1511 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_31$$22);
				zephir_create_array(&_31$$22, 3, 0 TSRMLS_CC);
				zephir_array_update_string(&_31$$22, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_31$$22, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_32$$22);
				zephir_create_array(&_32$$22, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(&_32$$22, &preCondition);
				zephir_array_update_string(&_31$$22, SL("conditions"), &_32$$22, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlJoins, &_31$$22, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1516);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &joinPrepared, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_28$$21, &joinPrepared, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_28$$21)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&joinAliasName, &joinPrepared, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_26$$21, &joinPrepared, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&joinType);
					zephir_array_fetch(&joinType, &joinTypes, &joinAliasName, PH_NOISY, "phalcon/mvc/model/query.zep", 1509 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&joinSource);
					zephir_array_fetch(&joinSource, &joinSources, &joinAliasName, PH_NOISY, "phalcon/mvc/model/query.zep", 1510 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&preCondition);
					zephir_array_fetch(&preCondition, &joinPreCondition, &joinAliasName, PH_NOISY, "phalcon/mvc/model/query.zep", 1511 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_33$$23);
					zephir_create_array(&_33$$23, 3, 0 TSRMLS_CC);
					zephir_array_update_string(&_33$$23, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_33$$23, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_34$$23);
					zephir_create_array(&_34$$23, 1, 0 TSRMLS_CC);
					zephir_array_fast_append(&_34$$23, &preCondition);
					zephir_array_update_string(&_33$$23, SL("conditions"), &_34$$23, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlJoins, &_33$$23, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1516);
				ZEPHIR_CALL_METHOD(NULL, &joinPrepared, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&_26$$21);
		ZEPHIR_INIT_NVAR(&joinAliasName);
		RETURN_CCTOR(&sqlJoins);
	}
	ZEPHIR_INIT_NVAR(&fromModels);
	array_init(&fromModels);
	zephir_is_iterable(&selectTables, 0, "phalcon/mvc/model/query.zep", 1532);
	if (Z_TYPE_P(&selectTables) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&selectTables), _35)
		{
			ZEPHIR_INIT_NVAR(&tableItem);
			ZVAL_COPY(&tableItem, _35);
			zephir_array_fetch_string(&_37$$24, &tableItem, SL("qualifiedName"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1526 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&_38$$24);
			zephir_array_fetch_string(&_38$$24, &_37$$24, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1526 TSRMLS_CC);
			zephir_array_update_zval(&fromModels, &_38$$24, &__$true, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &selectTables, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_36, &selectTables, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_36)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&tableItem, &selectTables, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_string(&_39$$25, &tableItem, SL("qualifiedName"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1526 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&_40$$25);
				zephir_array_fetch_string(&_40$$25, &_39$$25, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1526 TSRMLS_CC);
				zephir_array_update_zval(&fromModels, &_40$$25, &__$true, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &selectTables, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&tableItem);
	ZEPHIR_INIT_VAR(&_41);
	zephir_is_iterable(&fromModels, 0, "phalcon/mvc/model/query.zep", 1640);
	if (Z_TYPE_P(&fromModels) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fromModels), _44, _45, _42)
		{
			ZEPHIR_INIT_NVAR(&fromModelName);
			if (_45 != NULL) { 
				ZVAL_STR_COPY(&fromModelName, _45);
			} else {
				ZVAL_LONG(&fromModelName, _44);
			}
			ZEPHIR_INIT_NVAR(&_41);
			ZVAL_COPY(&_41, _42);
			zephir_is_iterable(&joinModels, 0, "phalcon/mvc/model/query.zep", 1638);
			if (Z_TYPE_P(&joinModels) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinModels), _48$$26, _49$$26, _46$$26)
				{
					ZEPHIR_INIT_NVAR(&joinAlias);
					if (_49$$26 != NULL) { 
						ZVAL_STR_COPY(&joinAlias, _49$$26);
					} else {
						ZVAL_LONG(&joinAlias, _48$$26);
					}
					ZEPHIR_INIT_NVAR(&joinModel);
					ZVAL_COPY(&joinModel, _46$$26);
					ZEPHIR_OBS_NVAR(&joinSource);
					zephir_array_fetch(&joinSource, &joinSources, &joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1539 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&joinType);
					zephir_array_fetch(&joinType, &joinTypes, &joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1544 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&preCondition);
					if (!(zephir_array_isset_fetch(&preCondition, &joinPreCondition, &joinAlias, 0 TSRMLS_CC))) {
						ZEPHIR_OBS_NVAR(&modelNameAlias);
						zephir_array_fetch(&modelNameAlias, &sqlAliasesModels, &joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1554 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_50, 0, &fromModelName, &modelNameAlias);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&relation)) {
							ZEPHIR_CALL_METHOD(&relations, &manager, "getrelationsbetween", &_51, 0, &fromModelName, &modelNameAlias);
							zephir_check_call_status();
							if (Z_TYPE_P(&relations) == IS_ARRAY) {
								if (zephir_fast_count_int(&relations TSRMLS_CC) != 1) {
									ZEPHIR_INIT_NVAR(&_52$$31);
									object_init_ex(&_52$$31, phalcon_mvc_model_exception_ce);
									zephir_read_property(&_53$$31, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_INIT_LNVAR(_54$$31);
									ZEPHIR_CONCAT_SVSVSV(&_54$$31, "There is more than one relation between models '", &fromModelName, "' and '", &joinModel, "', the join must be done using an alias, when preparing: ", &_53$$31);
									ZEPHIR_CALL_METHOD(NULL, &_52$$31, "__construct", &_7, 4, &_54$$31);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_52$$31, "phalcon/mvc/model/query.zep", 1574 TSRMLS_CC);
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&relation);
								zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 1580 TSRMLS_CC);
							}
						}
						if (Z_TYPE_P(&relation) == IS_OBJECT) {
							ZEPHIR_OBS_NVAR(&modelAlias);
							zephir_array_fetch(&modelAlias, &sqlModelsAliases, &fromModelName, PH_NOISY, "phalcon/mvc/model/query.zep", 1592 TSRMLS_CC);
							ZEPHIR_CALL_METHOD(&_55$$32, &relation, "isthrough", NULL, 0);
							zephir_check_call_status();
							if (!(zephir_is_true(&_55$$32))) {
								ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "_getsinglejoin", &_56, 345, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
								zephir_check_call_status();
							} else {
								ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "_getmultijoin", &_57, 346, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
								zephir_check_call_status();
							}
							if (zephir_array_isset_long(&sqlJoin, 0)) {
								zephir_is_iterable(&sqlJoin, 0, "phalcon/mvc/model/query.zep", 1610);
								if (Z_TYPE_P(&sqlJoin) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&sqlJoin), _58$$35)
									{
										ZEPHIR_INIT_NVAR(&sqlJoinItem);
										ZVAL_COPY(&sqlJoinItem, _58$$35);
										zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1608);
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &sqlJoin, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_59$$35, &sqlJoin, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_59$$35)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&sqlJoinItem, &sqlJoin, "current", NULL, 0);
										zephir_check_call_status();
											zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1608);
										ZEPHIR_CALL_METHOD(NULL, &sqlJoin, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&sqlJoinItem);
							} else {
								zephir_array_append(&sqlJoins, &sqlJoin, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1611);
							}
						} else {
							ZEPHIR_INIT_NVAR(&_60$$39);
							zephir_create_array(&_60$$39, 3, 0 TSRMLS_CC);
							zephir_array_update_string(&_60$$39, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_60$$39, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_61$$39);
							array_init(&_61$$39);
							zephir_array_update_string(&_60$$39, SL("conditions"), &_61$$39, PH_COPY | PH_SEPARATE);
							zephir_array_append(&sqlJoins, &_60$$39, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1623);
						}
					} else {
						ZEPHIR_INIT_NVAR(&_62$$40);
						zephir_create_array(&_62$$40, 3, 0 TSRMLS_CC);
						zephir_array_update_string(&_62$$40, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_62$$40, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_63$$40);
						zephir_create_array(&_63$$40, 1, 0 TSRMLS_CC);
						zephir_array_fast_append(&_63$$40, &preCondition);
						zephir_array_update_string(&_62$$40, SL("conditions"), &_63$$40, PH_COPY | PH_SEPARATE);
						zephir_array_append(&sqlJoins, &_62$$40, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1635);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &joinModels, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_47$$26, &joinModels, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_47$$26)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&joinAlias, &joinModels, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&joinModel, &joinModels, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&joinSource);
						zephir_array_fetch(&joinSource, &joinSources, &joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1539 TSRMLS_CC);
						ZEPHIR_OBS_NVAR(&joinType);
						zephir_array_fetch(&joinType, &joinTypes, &joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1544 TSRMLS_CC);
						ZEPHIR_OBS_NVAR(&preCondition);
						if (!(zephir_array_isset_fetch(&preCondition, &joinPreCondition, &joinAlias, 0 TSRMLS_CC))) {
							ZEPHIR_OBS_NVAR(&modelNameAlias);
							zephir_array_fetch(&modelNameAlias, &sqlAliasesModels, &joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1554 TSRMLS_CC);
							ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_64, 0, &fromModelName, &modelNameAlias);
							zephir_check_call_status();
							if (ZEPHIR_IS_FALSE_IDENTICAL(&relation)) {
								ZEPHIR_CALL_METHOD(&relations, &manager, "getrelationsbetween", &_65, 0, &fromModelName, &modelNameAlias);
								zephir_check_call_status();
								if (Z_TYPE_P(&relations) == IS_ARRAY) {
									if (zephir_fast_count_int(&relations TSRMLS_CC) != 1) {
										ZEPHIR_INIT_NVAR(&_66$$45);
										object_init_ex(&_66$$45, phalcon_mvc_model_exception_ce);
										zephir_read_property(&_67$$45, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
										ZEPHIR_INIT_LNVAR(_68$$45);
										ZEPHIR_CONCAT_SVSVSV(&_68$$45, "There is more than one relation between models '", &fromModelName, "' and '", &joinModel, "', the join must be done using an alias, when preparing: ", &_67$$45);
										ZEPHIR_CALL_METHOD(NULL, &_66$$45, "__construct", &_7, 4, &_68$$45);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_66$$45, "phalcon/mvc/model/query.zep", 1574 TSRMLS_CC);
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&relation);
									zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 1580 TSRMLS_CC);
								}
							}
							if (Z_TYPE_P(&relation) == IS_OBJECT) {
								ZEPHIR_OBS_NVAR(&modelAlias);
								zephir_array_fetch(&modelAlias, &sqlModelsAliases, &fromModelName, PH_NOISY, "phalcon/mvc/model/query.zep", 1592 TSRMLS_CC);
								ZEPHIR_CALL_METHOD(&_69$$46, &relation, "isthrough", NULL, 0);
								zephir_check_call_status();
								if (!(zephir_is_true(&_69$$46))) {
									ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "_getsinglejoin", &_56, 345, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
									zephir_check_call_status();
								} else {
									ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "_getmultijoin", &_57, 346, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
									zephir_check_call_status();
								}
								if (zephir_array_isset_long(&sqlJoin, 0)) {
									zephir_is_iterable(&sqlJoin, 0, "phalcon/mvc/model/query.zep", 1610);
									if (Z_TYPE_P(&sqlJoin) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&sqlJoin), _70$$49)
										{
											ZEPHIR_INIT_NVAR(&sqlJoinItem);
											ZVAL_COPY(&sqlJoinItem, _70$$49);
											zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1608);
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &sqlJoin, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_71$$49, &sqlJoin, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_71$$49)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&sqlJoinItem, &sqlJoin, "current", NULL, 0);
											zephir_check_call_status();
												zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1608);
											ZEPHIR_CALL_METHOD(NULL, &sqlJoin, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&sqlJoinItem);
								} else {
									zephir_array_append(&sqlJoins, &sqlJoin, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1611);
								}
							} else {
								ZEPHIR_INIT_NVAR(&_72$$53);
								zephir_create_array(&_72$$53, 3, 0 TSRMLS_CC);
								zephir_array_update_string(&_72$$53, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_72$$53, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_73$$53);
								array_init(&_73$$53);
								zephir_array_update_string(&_72$$53, SL("conditions"), &_73$$53, PH_COPY | PH_SEPARATE);
								zephir_array_append(&sqlJoins, &_72$$53, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1623);
							}
						} else {
							ZEPHIR_INIT_NVAR(&_74$$54);
							zephir_create_array(&_74$$54, 3, 0 TSRMLS_CC);
							zephir_array_update_string(&_74$$54, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_74$$54, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_75$$54);
							zephir_create_array(&_75$$54, 1, 0 TSRMLS_CC);
							zephir_array_fast_append(&_75$$54, &preCondition);
							zephir_array_update_string(&_74$$54, SL("conditions"), &_75$$54, PH_COPY | PH_SEPARATE);
							zephir_array_append(&sqlJoins, &_74$$54, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1635);
						}
					ZEPHIR_CALL_METHOD(NULL, &joinModels, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&joinModel);
			ZEPHIR_INIT_NVAR(&joinAlias);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fromModels, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_43, &fromModels, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_43)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&fromModelName, &fromModels, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_41, &fromModels, "current", NULL, 0);
			zephir_check_call_status();
				zephir_is_iterable(&joinModels, 0, "phalcon/mvc/model/query.zep", 1638);
				if (Z_TYPE_P(&joinModels) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinModels), _78$$55, _79$$55, _76$$55)
					{
						ZEPHIR_INIT_NVAR(&joinAlias);
						if (_79$$55 != NULL) { 
							ZVAL_STR_COPY(&joinAlias, _79$$55);
						} else {
							ZVAL_LONG(&joinAlias, _78$$55);
						}
						ZEPHIR_INIT_NVAR(&joinModel);
						ZVAL_COPY(&joinModel, _76$$55);
						ZEPHIR_OBS_NVAR(&joinSource);
						zephir_array_fetch(&joinSource, &joinSources, &joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1539 TSRMLS_CC);
						ZEPHIR_OBS_NVAR(&joinType);
						zephir_array_fetch(&joinType, &joinTypes, &joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1544 TSRMLS_CC);
						ZEPHIR_OBS_NVAR(&preCondition);
						if (!(zephir_array_isset_fetch(&preCondition, &joinPreCondition, &joinAlias, 0 TSRMLS_CC))) {
							ZEPHIR_OBS_NVAR(&modelNameAlias);
							zephir_array_fetch(&modelNameAlias, &sqlAliasesModels, &joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1554 TSRMLS_CC);
							ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_80, 0, &fromModelName, &modelNameAlias);
							zephir_check_call_status();
							if (ZEPHIR_IS_FALSE_IDENTICAL(&relation)) {
								ZEPHIR_CALL_METHOD(&relations, &manager, "getrelationsbetween", &_81, 0, &fromModelName, &modelNameAlias);
								zephir_check_call_status();
								if (Z_TYPE_P(&relations) == IS_ARRAY) {
									if (zephir_fast_count_int(&relations TSRMLS_CC) != 1) {
										ZEPHIR_INIT_NVAR(&_82$$60);
										object_init_ex(&_82$$60, phalcon_mvc_model_exception_ce);
										zephir_read_property(&_83$$60, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
										ZEPHIR_INIT_LNVAR(_84$$60);
										ZEPHIR_CONCAT_SVSVSV(&_84$$60, "There is more than one relation between models '", &fromModelName, "' and '", &joinModel, "', the join must be done using an alias, when preparing: ", &_83$$60);
										ZEPHIR_CALL_METHOD(NULL, &_82$$60, "__construct", &_7, 4, &_84$$60);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_82$$60, "phalcon/mvc/model/query.zep", 1574 TSRMLS_CC);
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&relation);
									zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 1580 TSRMLS_CC);
								}
							}
							if (Z_TYPE_P(&relation) == IS_OBJECT) {
								ZEPHIR_OBS_NVAR(&modelAlias);
								zephir_array_fetch(&modelAlias, &sqlModelsAliases, &fromModelName, PH_NOISY, "phalcon/mvc/model/query.zep", 1592 TSRMLS_CC);
								ZEPHIR_CALL_METHOD(&_85$$61, &relation, "isthrough", NULL, 0);
								zephir_check_call_status();
								if (!(zephir_is_true(&_85$$61))) {
									ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "_getsinglejoin", &_56, 345, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
									zephir_check_call_status();
								} else {
									ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "_getmultijoin", &_57, 346, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
									zephir_check_call_status();
								}
								if (zephir_array_isset_long(&sqlJoin, 0)) {
									zephir_is_iterable(&sqlJoin, 0, "phalcon/mvc/model/query.zep", 1610);
									if (Z_TYPE_P(&sqlJoin) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&sqlJoin), _86$$64)
										{
											ZEPHIR_INIT_NVAR(&sqlJoinItem);
											ZVAL_COPY(&sqlJoinItem, _86$$64);
											zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1608);
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &sqlJoin, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_87$$64, &sqlJoin, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_87$$64)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&sqlJoinItem, &sqlJoin, "current", NULL, 0);
											zephir_check_call_status();
												zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1608);
											ZEPHIR_CALL_METHOD(NULL, &sqlJoin, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&sqlJoinItem);
								} else {
									zephir_array_append(&sqlJoins, &sqlJoin, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1611);
								}
							} else {
								ZEPHIR_INIT_NVAR(&_88$$68);
								zephir_create_array(&_88$$68, 3, 0 TSRMLS_CC);
								zephir_array_update_string(&_88$$68, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_88$$68, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_89$$68);
								array_init(&_89$$68);
								zephir_array_update_string(&_88$$68, SL("conditions"), &_89$$68, PH_COPY | PH_SEPARATE);
								zephir_array_append(&sqlJoins, &_88$$68, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1623);
							}
						} else {
							ZEPHIR_INIT_NVAR(&_90$$69);
							zephir_create_array(&_90$$69, 3, 0 TSRMLS_CC);
							zephir_array_update_string(&_90$$69, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_90$$69, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_91$$69);
							zephir_create_array(&_91$$69, 1, 0 TSRMLS_CC);
							zephir_array_fast_append(&_91$$69, &preCondition);
							zephir_array_update_string(&_90$$69, SL("conditions"), &_91$$69, PH_COPY | PH_SEPARATE);
							zephir_array_append(&sqlJoins, &_90$$69, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1635);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &joinModels, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_77$$55, &joinModels, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_77$$55)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&joinAlias, &joinModels, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&joinModel, &joinModels, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&joinSource);
							zephir_array_fetch(&joinSource, &joinSources, &joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1539 TSRMLS_CC);
							ZEPHIR_OBS_NVAR(&joinType);
							zephir_array_fetch(&joinType, &joinTypes, &joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1544 TSRMLS_CC);
							ZEPHIR_OBS_NVAR(&preCondition);
							if (!(zephir_array_isset_fetch(&preCondition, &joinPreCondition, &joinAlias, 0 TSRMLS_CC))) {
								ZEPHIR_OBS_NVAR(&modelNameAlias);
								zephir_array_fetch(&modelNameAlias, &sqlAliasesModels, &joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1554 TSRMLS_CC);
								ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_92, 0, &fromModelName, &modelNameAlias);
								zephir_check_call_status();
								if (ZEPHIR_IS_FALSE_IDENTICAL(&relation)) {
									ZEPHIR_CALL_METHOD(&relations, &manager, "getrelationsbetween", &_93, 0, &fromModelName, &modelNameAlias);
									zephir_check_call_status();
									if (Z_TYPE_P(&relations) == IS_ARRAY) {
										if (zephir_fast_count_int(&relations TSRMLS_CC) != 1) {
											ZEPHIR_INIT_NVAR(&_94$$74);
											object_init_ex(&_94$$74, phalcon_mvc_model_exception_ce);
											zephir_read_property(&_95$$74, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
											ZEPHIR_INIT_LNVAR(_96$$74);
											ZEPHIR_CONCAT_SVSVSV(&_96$$74, "There is more than one relation between models '", &fromModelName, "' and '", &joinModel, "', the join must be done using an alias, when preparing: ", &_95$$74);
											ZEPHIR_CALL_METHOD(NULL, &_94$$74, "__construct", &_7, 4, &_96$$74);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_94$$74, "phalcon/mvc/model/query.zep", 1574 TSRMLS_CC);
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_OBS_NVAR(&relation);
										zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 1580 TSRMLS_CC);
									}
								}
								if (Z_TYPE_P(&relation) == IS_OBJECT) {
									ZEPHIR_OBS_NVAR(&modelAlias);
									zephir_array_fetch(&modelAlias, &sqlModelsAliases, &fromModelName, PH_NOISY, "phalcon/mvc/model/query.zep", 1592 TSRMLS_CC);
									ZEPHIR_CALL_METHOD(&_97$$75, &relation, "isthrough", NULL, 0);
									zephir_check_call_status();
									if (!(zephir_is_true(&_97$$75))) {
										ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "_getsinglejoin", &_56, 345, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
										zephir_check_call_status();
									} else {
										ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "_getmultijoin", &_57, 346, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
										zephir_check_call_status();
									}
									if (zephir_array_isset_long(&sqlJoin, 0)) {
										zephir_is_iterable(&sqlJoin, 0, "phalcon/mvc/model/query.zep", 1610);
										if (Z_TYPE_P(&sqlJoin) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&sqlJoin), _98$$78)
											{
												ZEPHIR_INIT_NVAR(&sqlJoinItem);
												ZVAL_COPY(&sqlJoinItem, _98$$78);
												zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1608);
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &sqlJoin, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_99$$78, &sqlJoin, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_99$$78)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&sqlJoinItem, &sqlJoin, "current", NULL, 0);
												zephir_check_call_status();
													zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1608);
												ZEPHIR_CALL_METHOD(NULL, &sqlJoin, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&sqlJoinItem);
									} else {
										zephir_array_append(&sqlJoins, &sqlJoin, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1611);
									}
								} else {
									ZEPHIR_INIT_NVAR(&_100$$82);
									zephir_create_array(&_100$$82, 3, 0 TSRMLS_CC);
									zephir_array_update_string(&_100$$82, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_100$$82, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
									ZEPHIR_INIT_NVAR(&_101$$82);
									array_init(&_101$$82);
									zephir_array_update_string(&_100$$82, SL("conditions"), &_101$$82, PH_COPY | PH_SEPARATE);
									zephir_array_append(&sqlJoins, &_100$$82, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1623);
								}
							} else {
								ZEPHIR_INIT_NVAR(&_102$$83);
								zephir_create_array(&_102$$83, 3, 0 TSRMLS_CC);
								zephir_array_update_string(&_102$$83, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_102$$83, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_103$$83);
								zephir_create_array(&_103$$83, 1, 0 TSRMLS_CC);
								zephir_array_fast_append(&_103$$83, &preCondition);
								zephir_array_update_string(&_102$$83, SL("conditions"), &_103$$83, PH_COPY | PH_SEPARATE);
								zephir_array_append(&sqlJoins, &_102$$83, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1635);
							}
						ZEPHIR_CALL_METHOD(NULL, &joinModels, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&joinModel);
				ZEPHIR_INIT_NVAR(&joinAlias);
			ZEPHIR_CALL_METHOD(NULL, &fromModels, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_41);
	ZEPHIR_INIT_NVAR(&fromModelName);
	RETURN_CCTOR(&sqlJoins);

}

/**
 * Returns a processed order clause for a SELECT statement
 *
 * @param array|string order
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getOrderClause) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *order, order_sub, orderColumns, orderParts, orderItem, orderPartExpr, orderSort, orderPartSort, *_0, _1, _2$$5, _4$$7, _5$$7, _6$$8, _7$$8, _8$$9, _9$$10, _10$$12, _11$$12, _12$$13, _13$$13, _14$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&order_sub);
	ZVAL_UNDEF(&orderColumns);
	ZVAL_UNDEF(&orderParts);
	ZVAL_UNDEF(&orderItem);
	ZVAL_UNDEF(&orderPartExpr);
	ZVAL_UNDEF(&orderSort);
	ZVAL_UNDEF(&orderPartSort);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_14$$14);

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
	zephir_is_iterable(&orderColumns, 0, "phalcon/mvc/model/query.zep", 1680);
	if (Z_TYPE_P(&orderColumns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&orderColumns), _0)
		{
			ZEPHIR_INIT_NVAR(&orderItem);
			ZVAL_COPY(&orderItem, _0);
			zephir_array_fetch_string(&_2$$5, &orderItem, SL("column"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1662 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&orderPartExpr, this_ptr, "_getexpression", &_3, 337, &_2$$5);
			zephir_check_call_status();
			if (zephir_array_isset_string_fetch(&orderSort, &orderItem, SL("sort"), 1)) {
				ZEPHIR_INIT_NVAR(&orderPartSort);
				if (ZEPHIR_IS_LONG(&orderSort, 327)) {
					ZEPHIR_INIT_NVAR(&_4$$7);
					zephir_create_array(&_4$$7, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_4$$7, &orderPartExpr);
					ZEPHIR_INIT_NVAR(&_5$$7);
					ZVAL_STRING(&_5$$7, "ASC");
					zephir_array_fast_append(&_4$$7, &_5$$7);
					ZEPHIR_CPY_WRT(&orderPartSort, &_4$$7);
				} else {
					ZEPHIR_INIT_NVAR(&_6$$8);
					zephir_create_array(&_6$$8, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_6$$8, &orderPartExpr);
					ZEPHIR_INIT_NVAR(&_7$$8);
					ZVAL_STRING(&_7$$8, "DESC");
					zephir_array_fast_append(&_6$$8, &_7$$8);
					ZEPHIR_CPY_WRT(&orderPartSort, &_6$$8);
				}
			} else {
				ZEPHIR_INIT_NVAR(&_8$$9);
				zephir_create_array(&_8$$9, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(&_8$$9, &orderPartExpr);
				ZEPHIR_CPY_WRT(&orderPartSort, &_8$$9);
			}
			zephir_array_append(&orderParts, &orderPartSort, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1677);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &orderColumns, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &orderColumns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&orderItem, &orderColumns, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_string(&_9$$10, &orderItem, SL("column"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1662 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&orderPartExpr, this_ptr, "_getexpression", &_3, 337, &_9$$10);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&orderSort);
				if (zephir_array_isset_string_fetch(&orderSort, &orderItem, SL("sort"), 0)) {
					if (ZEPHIR_IS_LONG(&orderSort, 327)) {
						ZEPHIR_INIT_NVAR(&_10$$12);
						zephir_create_array(&_10$$12, 2, 0 TSRMLS_CC);
						zephir_array_fast_append(&_10$$12, &orderPartExpr);
						ZEPHIR_INIT_NVAR(&_11$$12);
						ZVAL_STRING(&_11$$12, "ASC");
						zephir_array_fast_append(&_10$$12, &_11$$12);
						ZEPHIR_CPY_WRT(&orderPartSort, &_10$$12);
					} else {
						ZEPHIR_INIT_NVAR(&_12$$13);
						zephir_create_array(&_12$$13, 2, 0 TSRMLS_CC);
						zephir_array_fast_append(&_12$$13, &orderPartExpr);
						ZEPHIR_INIT_NVAR(&_13$$13);
						ZVAL_STRING(&_13$$13, "DESC");
						zephir_array_fast_append(&_12$$13, &_13$$13);
						ZEPHIR_CPY_WRT(&orderPartSort, &_12$$13);
					}
				} else {
					ZEPHIR_INIT_NVAR(&_14$$14);
					zephir_create_array(&_14$$14, 1, 0 TSRMLS_CC);
					zephir_array_fast_append(&_14$$14, &orderPartExpr);
					ZEPHIR_CPY_WRT(&orderPartSort, &_14$$14);
				}
				zephir_array_append(&orderParts, &orderPartSort, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1677);
			ZEPHIR_CALL_METHOD(NULL, &orderColumns, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&orderItem);
	RETURN_CCTOR(&orderParts);

}

/**
 * Returns a processed group clause for a SELECT statement
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getGroupClause) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group_param = NULL, groupItem, groupParts, *_0$$3, _1$$3, _2$$4, _4$$5, _5$$6, _6$$6;
	zval group;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&groupItem);
	ZVAL_UNDEF(&groupParts);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group_param);

	ZEPHIR_OBS_COPY_OR_DUP(&group, group_param);


	ZEPHIR_INIT_VAR(&groupParts);
	if (zephir_array_isset_long(&group, 0)) {
		array_init(&groupParts);
		zephir_is_iterable(&group, 0, "phalcon/mvc/model/query.zep", 1698);
		if (Z_TYPE_P(&group) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&group), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&groupItem);
				ZVAL_COPY(&groupItem, _0$$3);
				ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "_getexpression", &_3, 337, &groupItem);
				zephir_check_call_status();
				zephir_array_append(&groupParts, &_2$$4, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1696);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &group, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &group, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&groupItem, &group, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "_getexpression", &_3, 337, &groupItem);
					zephir_check_call_status();
					zephir_array_append(&groupParts, &_4$$5, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1696);
				ZEPHIR_CALL_METHOD(NULL, &group, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&groupItem);
	} else {
		ZEPHIR_INIT_VAR(&_5$$6);
		zephir_create_array(&_5$$6, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_6$$6, this_ptr, "_getexpression", &_3, 337, &group);
		zephir_check_call_status();
		zephir_array_fast_append(&_5$$6, &_6$$6);
		ZEPHIR_CPY_WRT(&groupParts, &_5$$6);
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
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "_getexpression", NULL, 337, &number);
		zephir_check_call_status();
		zephir_array_update_string(&limit, SL("number"), &_0$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&offset);
	if (zephir_array_isset_string_fetch(&offset, &limitClause, SL("offset"), 0)) {
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "_getexpression", NULL, 337, &offset);
		zephir_check_call_status();
		zephir_array_update_string(&limit, SL("offset"), &_1$$4, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(&limit);

}

/**
 * Analyzes a SELECT intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareSelect) {

	zval _23$$27, _24$$27, _25$$27, _35$$32, _36$$32, _37$$32, _60$$50, _61$$50, _62$$50, _72$$55, _73$$55, _74$$55;
	zval _15$$27, _27$$32, _52$$50, _64$$55, _100$$76, _107$$84, _117$$93, _124$$101;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_10 = NULL, *_16 = NULL, *_18 = NULL, *_28 = NULL, *_30 = NULL, *_40 = NULL, *_42 = NULL, *_53 = NULL, *_55 = NULL, *_65 = NULL, *_67 = NULL, *_91 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, position = 0, number = 0;
	zval *ast = NULL, ast_sub, *merge = NULL, merge_sub, __$null, __$true, sqlModels, sqlTables, sqlAliases, sqlColumns, select, tables, columns, sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances, models, modelsInstances, selectedModels, manager, metaData, selectedModel, qualifiedName, modelName, nsAlias, realModelName, model, schema, source, completeSource, alias, joins, sqlJoins, selectColumns, sqlColumnAliases, column, sqlColumn, sqlSelect, distinct, having, where, groupBy, order, limit, tempModels, tempModelsInstances, tempSqlAliases, tempSqlModelsAliases, tempSqlAliasesModelsInstances, tempSqlAliasesModels, with, withs, withItem, automaticJoins, relation, joinAlias, relationModel, bestAlias, eagerType, *_0, _1, *_88, _89, _125, _2$$15, _3$$15, _5$$15, _7$$20, _8$$20, _9$$20, _11$$22, *_12$$24, _13$$24, _14$$27, _17$$28, _19$$30, _20$$31, _21$$31, _22$$31, _26$$32, _29$$33, _31$$35, _32$$36, _33$$36, _34$$36, _38$$38, _39$$38, _41$$38, _43$$40, _44$$43, _45$$43, _46$$43, _47$$45, _48$$48, *_49$$47, _50$$47, _51$$50, _54$$51, _56$$53, _57$$54, _58$$54, _59$$54, _63$$55, _66$$56, _68$$58, _69$$59, _70$$59, _71$$59, _75$$61, _76$$61, _77$$61, _78$$61, _79$$61, _80$$61, _81$$61, _82$$61, _83$$61, _84$$61, _85$$61, _86$$61, _87$$64, _90$$69, *_92$$69, _93$$69, _94$$73, _95$$74, _96$$74, _97$$74, _98$$75, _99$$76, _101$$81, _102$$82, _103$$82, _104$$82, _105$$83, _106$$84, _108$$86, *_109$$86, _110$$86, _111$$90, _112$$91, _113$$91, _114$$91, _115$$92, _116$$93, _118$$98, _119$$99, _120$$99, _121$$99, _122$$100, _123$$101, _126$$105, _127$$106, _128$$107, _129$$108, _130$$109;
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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_89);
	ZVAL_UNDEF(&_125);
	ZVAL_UNDEF(&_2$$15);
	ZVAL_UNDEF(&_3$$15);
	ZVAL_UNDEF(&_5$$15);
	ZVAL_UNDEF(&_7$$20);
	ZVAL_UNDEF(&_8$$20);
	ZVAL_UNDEF(&_9$$20);
	ZVAL_UNDEF(&_11$$22);
	ZVAL_UNDEF(&_13$$24);
	ZVAL_UNDEF(&_14$$27);
	ZVAL_UNDEF(&_17$$28);
	ZVAL_UNDEF(&_19$$30);
	ZVAL_UNDEF(&_20$$31);
	ZVAL_UNDEF(&_21$$31);
	ZVAL_UNDEF(&_22$$31);
	ZVAL_UNDEF(&_26$$32);
	ZVAL_UNDEF(&_29$$33);
	ZVAL_UNDEF(&_31$$35);
	ZVAL_UNDEF(&_32$$36);
	ZVAL_UNDEF(&_33$$36);
	ZVAL_UNDEF(&_34$$36);
	ZVAL_UNDEF(&_38$$38);
	ZVAL_UNDEF(&_39$$38);
	ZVAL_UNDEF(&_41$$38);
	ZVAL_UNDEF(&_43$$40);
	ZVAL_UNDEF(&_44$$43);
	ZVAL_UNDEF(&_45$$43);
	ZVAL_UNDEF(&_46$$43);
	ZVAL_UNDEF(&_47$$45);
	ZVAL_UNDEF(&_48$$48);
	ZVAL_UNDEF(&_50$$47);
	ZVAL_UNDEF(&_51$$50);
	ZVAL_UNDEF(&_54$$51);
	ZVAL_UNDEF(&_56$$53);
	ZVAL_UNDEF(&_57$$54);
	ZVAL_UNDEF(&_58$$54);
	ZVAL_UNDEF(&_59$$54);
	ZVAL_UNDEF(&_63$$55);
	ZVAL_UNDEF(&_66$$56);
	ZVAL_UNDEF(&_68$$58);
	ZVAL_UNDEF(&_69$$59);
	ZVAL_UNDEF(&_70$$59);
	ZVAL_UNDEF(&_71$$59);
	ZVAL_UNDEF(&_75$$61);
	ZVAL_UNDEF(&_76$$61);
	ZVAL_UNDEF(&_77$$61);
	ZVAL_UNDEF(&_78$$61);
	ZVAL_UNDEF(&_79$$61);
	ZVAL_UNDEF(&_80$$61);
	ZVAL_UNDEF(&_81$$61);
	ZVAL_UNDEF(&_82$$61);
	ZVAL_UNDEF(&_83$$61);
	ZVAL_UNDEF(&_84$$61);
	ZVAL_UNDEF(&_85$$61);
	ZVAL_UNDEF(&_86$$61);
	ZVAL_UNDEF(&_87$$64);
	ZVAL_UNDEF(&_90$$69);
	ZVAL_UNDEF(&_93$$69);
	ZVAL_UNDEF(&_94$$73);
	ZVAL_UNDEF(&_95$$74);
	ZVAL_UNDEF(&_96$$74);
	ZVAL_UNDEF(&_97$$74);
	ZVAL_UNDEF(&_98$$75);
	ZVAL_UNDEF(&_99$$76);
	ZVAL_UNDEF(&_101$$81);
	ZVAL_UNDEF(&_102$$82);
	ZVAL_UNDEF(&_103$$82);
	ZVAL_UNDEF(&_104$$82);
	ZVAL_UNDEF(&_105$$83);
	ZVAL_UNDEF(&_106$$84);
	ZVAL_UNDEF(&_108$$86);
	ZVAL_UNDEF(&_110$$86);
	ZVAL_UNDEF(&_111$$90);
	ZVAL_UNDEF(&_112$$91);
	ZVAL_UNDEF(&_113$$91);
	ZVAL_UNDEF(&_114$$91);
	ZVAL_UNDEF(&_115$$92);
	ZVAL_UNDEF(&_116$$93);
	ZVAL_UNDEF(&_118$$98);
	ZVAL_UNDEF(&_119$$99);
	ZVAL_UNDEF(&_120$$99);
	ZVAL_UNDEF(&_121$$99);
	ZVAL_UNDEF(&_122$$100);
	ZVAL_UNDEF(&_123$$101);
	ZVAL_UNDEF(&_126$$105);
	ZVAL_UNDEF(&_127$$106);
	ZVAL_UNDEF(&_128$$107);
	ZVAL_UNDEF(&_129$$108);
	ZVAL_UNDEF(&_130$$109);
	ZVAL_UNDEF(&_15$$27);
	ZVAL_UNDEF(&_27$$32);
	ZVAL_UNDEF(&_52$$50);
	ZVAL_UNDEF(&_64$$55);
	ZVAL_UNDEF(&_100$$76);
	ZVAL_UNDEF(&_107$$84);
	ZVAL_UNDEF(&_117$$93);
	ZVAL_UNDEF(&_124$$101);
	ZVAL_UNDEF(&_23$$27);
	ZVAL_UNDEF(&_24$$27);
	ZVAL_UNDEF(&_25$$27);
	ZVAL_UNDEF(&_35$$32);
	ZVAL_UNDEF(&_36$$32);
	ZVAL_UNDEF(&_37$$32);
	ZVAL_UNDEF(&_60$$50);
	ZVAL_UNDEF(&_61$$50);
	ZVAL_UNDEF(&_62$$50);
	ZVAL_UNDEF(&_72$$55);
	ZVAL_UNDEF(&_73$$55);
	ZVAL_UNDEF(&_74$$55);

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 1753);
		return;
	}
	ZEPHIR_OBS_VAR(&columns);
	if (!(zephir_array_isset_string_fetch(&columns, &select, SL("columns"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 1757);
		return;
	}
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_nestingLevel") TSRMLS_CC));
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A models-manager is required to execute the query", "phalcon/mvc/model/query.zep", 1821);
		return;
	}
	if (Z_TYPE_P(&metaData) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A meta-data is required to execute the query", "phalcon/mvc/model/query.zep", 1825);
		return;
	}
	number = 0;
	ZEPHIR_INIT_VAR(&automaticJoins);
	array_init(&automaticJoins);
	zephir_is_iterable(&selectedModels, 0, "phalcon/mvc/model/query.zep", 1954);
	if (Z_TYPE_P(&selectedModels) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&selectedModels), _0)
		{
			ZEPHIR_INIT_NVAR(&selectedModel);
			ZVAL_COPY(&selectedModel, _0);
			ZEPHIR_OBS_NVAR(&qualifiedName);
			zephir_array_fetch_string(&qualifiedName, &selectedModel, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 1834 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&modelName);
			zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1835 TSRMLS_CC);
			if (zephir_memnstr_str(&modelName, SL(":"), "phalcon/mvc/model/query.zep", 1838)) {
				ZEPHIR_INIT_NVAR(&nsAlias);
				zephir_fast_explode_str(&nsAlias, SL(":"), &modelName, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_3$$15, &nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1840 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_2$$15, &manager, "getnamespacealias", &_4, 0, &_3$$15);
				zephir_check_call_status();
				zephir_array_fetch_long(&_5$$15, &nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1840 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&realModelName);
				ZEPHIR_CONCAT_VSV(&realModelName, &_2$$15, "\\", &_5$$15);
			} else {
				ZEPHIR_CPY_WRT(&realModelName, &modelName);
			}
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_6, 0, &realModelName);
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
					zephir_throw_exception_debug(&_7$$20, "phalcon/mvc/model/query.zep", 1864 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModels, &alias, &realModelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlModelsAliases, &realModelName, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(&completeSource) == IS_ARRAY) {
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1876);
				} else {
					ZEPHIR_INIT_NVAR(&_11$$22);
					zephir_create_array(&_11$$22, 3, 0 TSRMLS_CC);
					zephir_array_fast_append(&_11$$22, &source);
					zephir_array_fast_append(&_11$$22, &__$null);
					zephir_array_fast_append(&_11$$22, &alias);
					ZEPHIR_CPY_WRT(&completeSource, &_11$$22);
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
				zephir_is_iterable(&withs, 0, "phalcon/mvc/model/query.zep", 1946);
				if (Z_TYPE_P(&withs) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&withs), _12$$24)
					{
						ZEPHIR_INIT_NVAR(&withItem);
						ZVAL_COPY(&withItem, _12$$24);
						ZEPHIR_SINIT_NVAR(_14$$27);
						ZVAL_LONG(&_14$$27, number);
						ZEPHIR_INIT_LNVAR(_15$$27);
						ZEPHIR_CONCAT_SV(&_15$$27, "AA", &_14$$27);
						ZEPHIR_CPY_WRT(&joinAlias, &_15$$27);
						ZEPHIR_OBS_NVAR(&relationModel);
						zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1904 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_16, 0, &realModelName, &relationModel);
						zephir_check_call_status();
						if (Z_TYPE_P(&relation) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_17$$28);
							ZVAL_STRING(&_17$$28, "alias");
							ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_17$$28);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
							zephir_check_call_status();
						} else {
							ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationsbetween", &_18, 0, &realModelName, &relationModel);
							zephir_check_call_status();
							if (Z_TYPE_P(&relation) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_19$$30);
								ZVAL_STRING(&_19$$30, "alias");
								ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_19$$30);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
								zephir_check_call_status();
							} else {
								ZEPHIR_INIT_NVAR(&_20$$31);
								object_init_ex(&_20$$31, phalcon_mvc_model_exception_ce);
								zephir_read_property(&_21$$31, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
								ZEPHIR_INIT_LNVAR(_22$$31);
								ZEPHIR_CONCAT_SVSVSV(&_22$$31, "Can't find a relationship between '", &realModelName, "' and '", &relationModel, "' when preparing: ", &_21$$31);
								ZEPHIR_CALL_METHOD(NULL, &_20$$31, "__construct", &_10, 4, &_22$$31);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_20$$31, "phalcon/mvc/model/query.zep", 1920 TSRMLS_CC);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						ZEPHIR_INIT_NVAR(&_23$$27);
						zephir_create_array(&_23$$27, 5, 0 TSRMLS_CC);
						add_assoc_long_ex(&_23$$27, SL("type"), 353);
						zephir_array_update_string(&_23$$27, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_23$$27, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_23$$27, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_23$$27, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
						zephir_array_append(&selectColumns, &_23$$27, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1930);
						ZEPHIR_INIT_NVAR(&_24$$27);
						zephir_create_array(&_24$$27, 3, 0 TSRMLS_CC);
						add_assoc_long_ex(&_24$$27, SL("type"), 360);
						ZEPHIR_INIT_NVAR(&_25$$27);
						zephir_create_array(&_25$$27, 2, 0 TSRMLS_CC);
						add_assoc_long_ex(&_25$$27, SL("type"), 355);
						zephir_array_update_string(&_25$$27, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_24$$27, SL("qualified"), &_25$$27, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_25$$27);
						zephir_create_array(&_25$$27, 2, 0 TSRMLS_CC);
						add_assoc_long_ex(&_25$$27, SL("type"), 355);
						zephir_array_update_string(&_25$$27, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_24$$27, SL("alias"), &_25$$27, PH_COPY | PH_SEPARATE);
						zephir_array_append(&automaticJoins, &_24$$27, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1942);
						number++;
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &withs, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_13$$24, &withs, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_13$$24)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&withItem, &withs, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_SINIT_NVAR(_26$$32);
							ZVAL_LONG(&_26$$32, number);
							ZEPHIR_INIT_LNVAR(_27$$32);
							ZEPHIR_CONCAT_SV(&_27$$32, "AA", &_26$$32);
							ZEPHIR_CPY_WRT(&joinAlias, &_27$$32);
							ZEPHIR_OBS_NVAR(&relationModel);
							zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1904 TSRMLS_CC);
							ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_28, 0, &realModelName, &relationModel);
							zephir_check_call_status();
							if (Z_TYPE_P(&relation) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_29$$33);
								ZVAL_STRING(&_29$$33, "alias");
								ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_29$$33);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
								zephir_check_call_status();
							} else {
								ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationsbetween", &_30, 0, &realModelName, &relationModel);
								zephir_check_call_status();
								if (Z_TYPE_P(&relation) == IS_OBJECT) {
									ZEPHIR_INIT_NVAR(&_31$$35);
									ZVAL_STRING(&_31$$35, "alias");
									ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_31$$35);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
									zephir_check_call_status();
								} else {
									ZEPHIR_INIT_NVAR(&_32$$36);
									object_init_ex(&_32$$36, phalcon_mvc_model_exception_ce);
									zephir_read_property(&_33$$36, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_INIT_LNVAR(_34$$36);
									ZEPHIR_CONCAT_SVSVSV(&_34$$36, "Can't find a relationship between '", &realModelName, "' and '", &relationModel, "' when preparing: ", &_33$$36);
									ZEPHIR_CALL_METHOD(NULL, &_32$$36, "__construct", &_10, 4, &_34$$36);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_32$$36, "phalcon/mvc/model/query.zep", 1920 TSRMLS_CC);
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
							ZEPHIR_INIT_NVAR(&_35$$32);
							zephir_create_array(&_35$$32, 5, 0 TSRMLS_CC);
							add_assoc_long_ex(&_35$$32, SL("type"), 353);
							zephir_array_update_string(&_35$$32, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_35$$32, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_35$$32, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_35$$32, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
							zephir_array_append(&selectColumns, &_35$$32, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1930);
							ZEPHIR_INIT_NVAR(&_36$$32);
							zephir_create_array(&_36$$32, 3, 0 TSRMLS_CC);
							add_assoc_long_ex(&_36$$32, SL("type"), 360);
							ZEPHIR_INIT_NVAR(&_37$$32);
							zephir_create_array(&_37$$32, 2, 0 TSRMLS_CC);
							add_assoc_long_ex(&_37$$32, SL("type"), 355);
							zephir_array_update_string(&_37$$32, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_36$$32, SL("qualified"), &_37$$32, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_37$$32);
							zephir_create_array(&_37$$32, 2, 0 TSRMLS_CC);
							add_assoc_long_ex(&_37$$32, SL("type"), 355);
							zephir_array_update_string(&_37$$32, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_36$$32, SL("alias"), &_37$$32, PH_COPY | PH_SEPARATE);
							zephir_array_append(&automaticJoins, &_36$$32, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1942);
							number++;
						ZEPHIR_CALL_METHOD(NULL, &withs, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&withItem);
			}
			zephir_array_append(&sqlModels, &realModelName, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1948);
			zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1949);
			zephir_array_update_zval(&modelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &selectedModels, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &selectedModels, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&selectedModel, &selectedModels, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&qualifiedName);
				zephir_array_fetch_string(&qualifiedName, &selectedModel, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 1834 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1835 TSRMLS_CC);
				if (zephir_memnstr_str(&modelName, SL(":"), "phalcon/mvc/model/query.zep", 1838)) {
					ZEPHIR_INIT_NVAR(&nsAlias);
					zephir_fast_explode_str(&nsAlias, SL(":"), &modelName, LONG_MAX TSRMLS_CC);
					zephir_array_fetch_long(&_39$$38, &nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1840 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_38$$38, &manager, "getnamespacealias", &_40, 0, &_39$$38);
					zephir_check_call_status();
					zephir_array_fetch_long(&_41$$38, &nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1840 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&realModelName);
					ZEPHIR_CONCAT_VSV(&realModelName, &_38$$38, "\\", &_41$$38);
				} else {
					ZEPHIR_CPY_WRT(&realModelName, &modelName);
				}
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_42, 0, &realModelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&schema)) {
					ZEPHIR_INIT_NVAR(&_43$$40);
					zephir_create_array(&_43$$40, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_43$$40, &source);
					zephir_array_fast_append(&_43$$40, &schema);
					ZEPHIR_CPY_WRT(&completeSource, &_43$$40);
				} else {
					ZEPHIR_CPY_WRT(&completeSource, &source);
				}
				ZEPHIR_OBS_NVAR(&alias);
				if (zephir_array_isset_string_fetch(&alias, &selectedModel, SL("alias"), 0)) {
					if (zephir_array_isset(&sqlAliases, &alias)) {
						ZEPHIR_INIT_NVAR(&_44$$43);
						object_init_ex(&_44$$43, phalcon_mvc_model_exception_ce);
						zephir_read_property(&_45$$43, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_LNVAR(_46$$43);
						ZEPHIR_CONCAT_SVSV(&_46$$43, "Alias '", &alias, "' is used more than once, when preparing: ", &_45$$43);
						ZEPHIR_CALL_METHOD(NULL, &_44$$43, "__construct", &_10, 4, &_46$$43);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_44$$43, "phalcon/mvc/model/query.zep", 1864 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModels, &alias, &realModelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlModelsAliases, &realModelName, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
					if (Z_TYPE_P(&completeSource) == IS_ARRAY) {
						zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1876);
					} else {
						ZEPHIR_INIT_NVAR(&_47$$45);
						zephir_create_array(&_47$$45, 3, 0 TSRMLS_CC);
						zephir_array_fast_append(&_47$$45, &source);
						zephir_array_fast_append(&_47$$45, &__$null);
						zephir_array_fast_append(&_47$$45, &alias);
						ZEPHIR_CPY_WRT(&completeSource, &_47$$45);
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
						ZEPHIR_INIT_NVAR(&_48$$48);
						zephir_create_array(&_48$$48, 1, 0 TSRMLS_CC);
						zephir_array_fast_append(&_48$$48, &with);
						ZEPHIR_CPY_WRT(&withs, &_48$$48);
					} else {
						ZEPHIR_CPY_WRT(&withs, &with);
					}
					zephir_is_iterable(&withs, 0, "phalcon/mvc/model/query.zep", 1946);
					if (Z_TYPE_P(&withs) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&withs), _49$$47)
						{
							ZEPHIR_INIT_NVAR(&withItem);
							ZVAL_COPY(&withItem, _49$$47);
							ZEPHIR_SINIT_NVAR(_51$$50);
							ZVAL_LONG(&_51$$50, number);
							ZEPHIR_INIT_LNVAR(_52$$50);
							ZEPHIR_CONCAT_SV(&_52$$50, "AA", &_51$$50);
							ZEPHIR_CPY_WRT(&joinAlias, &_52$$50);
							ZEPHIR_OBS_NVAR(&relationModel);
							zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1904 TSRMLS_CC);
							ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_53, 0, &realModelName, &relationModel);
							zephir_check_call_status();
							if (Z_TYPE_P(&relation) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_54$$51);
								ZVAL_STRING(&_54$$51, "alias");
								ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_54$$51);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
								zephir_check_call_status();
							} else {
								ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationsbetween", &_55, 0, &realModelName, &relationModel);
								zephir_check_call_status();
								if (Z_TYPE_P(&relation) == IS_OBJECT) {
									ZEPHIR_INIT_NVAR(&_56$$53);
									ZVAL_STRING(&_56$$53, "alias");
									ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_56$$53);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
									zephir_check_call_status();
								} else {
									ZEPHIR_INIT_NVAR(&_57$$54);
									object_init_ex(&_57$$54, phalcon_mvc_model_exception_ce);
									zephir_read_property(&_58$$54, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_INIT_LNVAR(_59$$54);
									ZEPHIR_CONCAT_SVSVSV(&_59$$54, "Can't find a relationship between '", &realModelName, "' and '", &relationModel, "' when preparing: ", &_58$$54);
									ZEPHIR_CALL_METHOD(NULL, &_57$$54, "__construct", &_10, 4, &_59$$54);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_57$$54, "phalcon/mvc/model/query.zep", 1920 TSRMLS_CC);
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
							ZEPHIR_INIT_NVAR(&_60$$50);
							zephir_create_array(&_60$$50, 5, 0 TSRMLS_CC);
							add_assoc_long_ex(&_60$$50, SL("type"), 353);
							zephir_array_update_string(&_60$$50, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_60$$50, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_60$$50, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_60$$50, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
							zephir_array_append(&selectColumns, &_60$$50, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1930);
							ZEPHIR_INIT_NVAR(&_61$$50);
							zephir_create_array(&_61$$50, 3, 0 TSRMLS_CC);
							add_assoc_long_ex(&_61$$50, SL("type"), 360);
							ZEPHIR_INIT_NVAR(&_62$$50);
							zephir_create_array(&_62$$50, 2, 0 TSRMLS_CC);
							add_assoc_long_ex(&_62$$50, SL("type"), 355);
							zephir_array_update_string(&_62$$50, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_61$$50, SL("qualified"), &_62$$50, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_62$$50);
							zephir_create_array(&_62$$50, 2, 0 TSRMLS_CC);
							add_assoc_long_ex(&_62$$50, SL("type"), 355);
							zephir_array_update_string(&_62$$50, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_61$$50, SL("alias"), &_62$$50, PH_COPY | PH_SEPARATE);
							zephir_array_append(&automaticJoins, &_61$$50, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1942);
							number++;
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &withs, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_50$$47, &withs, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_50$$47)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&withItem, &withs, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_SINIT_NVAR(_63$$55);
								ZVAL_LONG(&_63$$55, number);
								ZEPHIR_INIT_LNVAR(_64$$55);
								ZEPHIR_CONCAT_SV(&_64$$55, "AA", &_63$$55);
								ZEPHIR_CPY_WRT(&joinAlias, &_64$$55);
								ZEPHIR_OBS_NVAR(&relationModel);
								zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1904 TSRMLS_CC);
								ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_65, 0, &realModelName, &relationModel);
								zephir_check_call_status();
								if (Z_TYPE_P(&relation) == IS_OBJECT) {
									ZEPHIR_INIT_NVAR(&_66$$56);
									ZVAL_STRING(&_66$$56, "alias");
									ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_66$$56);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
									zephir_check_call_status();
								} else {
									ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationsbetween", &_67, 0, &realModelName, &relationModel);
									zephir_check_call_status();
									if (Z_TYPE_P(&relation) == IS_OBJECT) {
										ZEPHIR_INIT_NVAR(&_68$$58);
										ZVAL_STRING(&_68$$58, "alias");
										ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_68$$58);
										zephir_check_call_status();
										ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
										zephir_check_call_status();
										ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
										zephir_check_call_status();
									} else {
										ZEPHIR_INIT_NVAR(&_69$$59);
										object_init_ex(&_69$$59, phalcon_mvc_model_exception_ce);
										zephir_read_property(&_70$$59, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
										ZEPHIR_INIT_LNVAR(_71$$59);
										ZEPHIR_CONCAT_SVSVSV(&_71$$59, "Can't find a relationship between '", &realModelName, "' and '", &relationModel, "' when preparing: ", &_70$$59);
										ZEPHIR_CALL_METHOD(NULL, &_69$$59, "__construct", &_10, 4, &_71$$59);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_69$$59, "phalcon/mvc/model/query.zep", 1920 TSRMLS_CC);
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
								ZEPHIR_INIT_NVAR(&_72$$55);
								zephir_create_array(&_72$$55, 5, 0 TSRMLS_CC);
								add_assoc_long_ex(&_72$$55, SL("type"), 353);
								zephir_array_update_string(&_72$$55, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_72$$55, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_72$$55, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_72$$55, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
								zephir_array_append(&selectColumns, &_72$$55, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1930);
								ZEPHIR_INIT_NVAR(&_73$$55);
								zephir_create_array(&_73$$55, 3, 0 TSRMLS_CC);
								add_assoc_long_ex(&_73$$55, SL("type"), 360);
								ZEPHIR_INIT_NVAR(&_74$$55);
								zephir_create_array(&_74$$55, 2, 0 TSRMLS_CC);
								add_assoc_long_ex(&_74$$55, SL("type"), 355);
								zephir_array_update_string(&_74$$55, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_73$$55, SL("qualified"), &_74$$55, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_74$$55);
								zephir_create_array(&_74$$55, 2, 0 TSRMLS_CC);
								add_assoc_long_ex(&_74$$55, SL("type"), 355);
								zephir_array_update_string(&_74$$55, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_73$$55, SL("alias"), &_74$$55, PH_COPY | PH_SEPARATE);
								zephir_array_append(&automaticJoins, &_73$$55, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1942);
								number++;
							ZEPHIR_CALL_METHOD(NULL, &withs, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&withItem);
				}
				zephir_array_append(&sqlModels, &realModelName, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1948);
				zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1949);
				zephir_array_update_zval(&modelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &selectedModels, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
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
		ZEPHIR_INIT_VAR(&_75$$61);
		zephir_read_property(&_76$$61, this_ptr, SL("_models"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_75$$61, &_76$$61, &models TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_models"), &_75$$61);
		ZEPHIR_INIT_VAR(&_77$$61);
		zephir_read_property(&_78$$61, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_77$$61, &_78$$61, &modelsInstances TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_modelsInstances"), &_77$$61);
		ZEPHIR_INIT_VAR(&_79$$61);
		zephir_read_property(&_80$$61, this_ptr, SL("_sqlAliases"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_79$$61, &_80$$61, &sqlAliases TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_sqlAliases"), &_79$$61);
		ZEPHIR_INIT_VAR(&_81$$61);
		zephir_read_property(&_82$$61, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_81$$61, &_82$$61, &sqlAliasesModels TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_sqlAliasesModels"), &_81$$61);
		ZEPHIR_INIT_VAR(&_83$$61);
		zephir_read_property(&_84$$61, this_ptr, SL("_sqlModelsAliases"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_83$$61, &_84$$61, &sqlModelsAliases TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_sqlModelsAliases"), &_83$$61);
		ZEPHIR_INIT_VAR(&_85$$61);
		zephir_read_property(&_86$$61, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_85$$61, &_86$$61, &sqlAliasesModelsInstances TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_sqlAliasesModelsInstances"), &_85$$61);
	}
	ZEPHIR_OBS_VAR(&joins);
	zephir_array_isset_string_fetch(&joins, &select, SL("joins"), 0);
	if (zephir_fast_count_int(&joins TSRMLS_CC)) {
		if (zephir_fast_count_int(&automaticJoins TSRMLS_CC)) {
			if (zephir_array_isset_long(&joins, 0)) {
				ZEPHIR_INIT_VAR(&_87$$64);
				zephir_fast_array_merge(&_87$$64, &joins, &automaticJoins TSRMLS_CC);
				zephir_array_update_string(&select, SL("joins"), &_87$$64, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_append(&automaticJoins, &joins, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1986);
				zephir_array_update_string(&select, SL("joins"), &automaticJoins, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_CALL_METHOD(&sqlJoins, this_ptr, "_getjoins", NULL, 347, &select);
		zephir_check_call_status();
	} else {
		if (zephir_fast_count_int(&automaticJoins TSRMLS_CC)) {
			zephir_array_update_string(&select, SL("joins"), &automaticJoins, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&sqlJoins, this_ptr, "_getjoins", NULL, 347, &select);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&sqlJoins);
			array_init(&sqlJoins);
		}
	}
	position = 0;
	ZEPHIR_INIT_VAR(&sqlColumnAliases);
	array_init(&sqlColumnAliases);
	zephir_is_iterable(&selectColumns, 0, "phalcon/mvc/model/query.zep", 2042);
	if (Z_TYPE_P(&selectColumns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&selectColumns), _88)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _88);
			ZEPHIR_CALL_METHOD(&_90$$69, this_ptr, "_getselectcolumn", &_91, 348, &column);
			zephir_check_call_status();
			zephir_is_iterable(&_90$$69, 0, "phalcon/mvc/model/query.zep", 2041);
			if (Z_TYPE_P(&_90$$69) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_90$$69), _92$$69)
				{
					ZEPHIR_INIT_NVAR(&sqlColumn);
					ZVAL_COPY(&sqlColumn, _92$$69);
					ZEPHIR_OBS_NVAR(&alias);
					if (zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0)) {
						zephir_array_update_string(&sqlColumn, SL("balias"), &alias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &alias, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&sqlColumnAliases, &alias, &__$true, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_OBS_NVAR(&alias);
						if (zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0)) {
							zephir_array_fetch_string(&_94$$73, &column, SL("column"), PH_READONLY, "phalcon/mvc/model/query.zep", 2026 TSRMLS_CC);
							if (zephir_array_isset_string(&_94$$73, SL("domain"))) {
								zephir_array_fetch_string(&_95$$74, &column, SL("column"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2027 TSRMLS_CC);
								zephir_array_fetch_string(&_96$$74, &_95$$74, SL("domain"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2027 TSRMLS_CC);
								ZEPHIR_INIT_LNVAR(_97$$74);
								ZEPHIR_CONCAT_VSV(&_97$$74, &_96$$74, "_", &alias);
								ZEPHIR_CPY_WRT(&alias, &_97$$74);
							}
							zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_fetch_string(&_98$$75, &sqlColumn, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2031 TSRMLS_CC);
							if (ZEPHIR_IS_STRING(&_98$$75, "scalar")) {
								ZEPHIR_SINIT_NVAR(_99$$76);
								ZVAL_LONG(&_99$$76, position);
								ZEPHIR_INIT_LNVAR(_100$$76);
								ZEPHIR_CONCAT_SV(&_100$$76, "_", &_99$$76);
								zephir_array_update_zval(&sqlColumns, &_100$$76, &sqlColumn, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2034);
							}
						}
					}
					position++;
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_90$$69, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_93$$69, &_90$$69, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_93$$69)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&sqlColumn, &_90$$69, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&alias);
						if (zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0)) {
							zephir_array_update_string(&sqlColumn, SL("balias"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
							zephir_array_update_zval(&sqlColumnAliases, &alias, &__$true, PH_COPY | PH_SEPARATE);
						} else {
							ZEPHIR_OBS_NVAR(&alias);
							if (zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0)) {
								zephir_array_fetch_string(&_101$$81, &column, SL("column"), PH_READONLY, "phalcon/mvc/model/query.zep", 2026 TSRMLS_CC);
								if (zephir_array_isset_string(&_101$$81, SL("domain"))) {
									zephir_array_fetch_string(&_102$$82, &column, SL("column"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2027 TSRMLS_CC);
									zephir_array_fetch_string(&_103$$82, &_102$$82, SL("domain"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2027 TSRMLS_CC);
									ZEPHIR_INIT_LNVAR(_104$$82);
									ZEPHIR_CONCAT_VSV(&_104$$82, &_103$$82, "_", &alias);
									ZEPHIR_CPY_WRT(&alias, &_104$$82);
								}
								zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_fetch_string(&_105$$83, &sqlColumn, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2031 TSRMLS_CC);
								if (ZEPHIR_IS_STRING(&_105$$83, "scalar")) {
									ZEPHIR_SINIT_NVAR(_106$$84);
									ZVAL_LONG(&_106$$84, position);
									ZEPHIR_INIT_LNVAR(_107$$84);
									ZEPHIR_CONCAT_SV(&_107$$84, "_", &_106$$84);
									zephir_array_update_zval(&sqlColumns, &_107$$84, &sqlColumn, PH_COPY | PH_SEPARATE);
								} else {
									zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2034);
								}
							}
						}
						position++;
					ZEPHIR_CALL_METHOD(NULL, &_90$$69, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&sqlColumn);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &selectColumns, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_89, &selectColumns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_89)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &selectColumns, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_108$$86, this_ptr, "_getselectcolumn", &_91, 348, &column);
				zephir_check_call_status();
				zephir_is_iterable(&_108$$86, 0, "phalcon/mvc/model/query.zep", 2041);
				if (Z_TYPE_P(&_108$$86) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_108$$86), _109$$86)
					{
						ZEPHIR_INIT_NVAR(&sqlColumn);
						ZVAL_COPY(&sqlColumn, _109$$86);
						ZEPHIR_OBS_NVAR(&alias);
						if (zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0)) {
							zephir_array_update_string(&sqlColumn, SL("balias"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
							zephir_array_update_zval(&sqlColumnAliases, &alias, &__$true, PH_COPY | PH_SEPARATE);
						} else {
							ZEPHIR_OBS_NVAR(&alias);
							if (zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0)) {
								zephir_array_fetch_string(&_111$$90, &column, SL("column"), PH_READONLY, "phalcon/mvc/model/query.zep", 2026 TSRMLS_CC);
								if (zephir_array_isset_string(&_111$$90, SL("domain"))) {
									zephir_array_fetch_string(&_112$$91, &column, SL("column"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2027 TSRMLS_CC);
									zephir_array_fetch_string(&_113$$91, &_112$$91, SL("domain"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2027 TSRMLS_CC);
									ZEPHIR_INIT_LNVAR(_114$$91);
									ZEPHIR_CONCAT_VSV(&_114$$91, &_113$$91, "_", &alias);
									ZEPHIR_CPY_WRT(&alias, &_114$$91);
								}
								zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_fetch_string(&_115$$92, &sqlColumn, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2031 TSRMLS_CC);
								if (ZEPHIR_IS_STRING(&_115$$92, "scalar")) {
									ZEPHIR_SINIT_NVAR(_116$$93);
									ZVAL_LONG(&_116$$93, position);
									ZEPHIR_INIT_LNVAR(_117$$93);
									ZEPHIR_CONCAT_SV(&_117$$93, "_", &_116$$93);
									zephir_array_update_zval(&sqlColumns, &_117$$93, &sqlColumn, PH_COPY | PH_SEPARATE);
								} else {
									zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2034);
								}
							}
						}
						position++;
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_108$$86, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_110$$86, &_108$$86, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_110$$86)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&sqlColumn, &_108$$86, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&alias);
							if (zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0)) {
								zephir_array_update_string(&sqlColumn, SL("balias"), &alias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &alias, PH_COPY | PH_SEPARATE);
								zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
								zephir_array_update_zval(&sqlColumnAliases, &alias, &__$true, PH_COPY | PH_SEPARATE);
							} else {
								ZEPHIR_OBS_NVAR(&alias);
								if (zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0)) {
									zephir_array_fetch_string(&_118$$98, &column, SL("column"), PH_READONLY, "phalcon/mvc/model/query.zep", 2026 TSRMLS_CC);
									if (zephir_array_isset_string(&_118$$98, SL("domain"))) {
										zephir_array_fetch_string(&_119$$99, &column, SL("column"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2027 TSRMLS_CC);
										zephir_array_fetch_string(&_120$$99, &_119$$99, SL("domain"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2027 TSRMLS_CC);
										ZEPHIR_INIT_LNVAR(_121$$99);
										ZEPHIR_CONCAT_VSV(&_121$$99, &_120$$99, "_", &alias);
										ZEPHIR_CPY_WRT(&alias, &_121$$99);
									}
									zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
								} else {
									zephir_array_fetch_string(&_122$$100, &sqlColumn, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2031 TSRMLS_CC);
									if (ZEPHIR_IS_STRING(&_122$$100, "scalar")) {
										ZEPHIR_SINIT_NVAR(_123$$101);
										ZVAL_LONG(&_123$$101, position);
										ZEPHIR_INIT_LNVAR(_124$$101);
										ZEPHIR_CONCAT_SV(&_124$$101, "_", &_123$$101);
										zephir_array_update_zval(&sqlColumns, &_124$$101, &sqlColumn, PH_COPY | PH_SEPARATE);
									} else {
										zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2034);
									}
								}
							}
							position++;
						ZEPHIR_CALL_METHOD(NULL, &_108$$86, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&sqlColumn);
			ZEPHIR_CALL_METHOD(NULL, &selectColumns, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	ZEPHIR_OBS_VAR(&_125);
	zephir_read_property(&_125, this_ptr, SL("_nestingLevel"), PH_NOISY_CC);
	zephir_update_property_array(this_ptr, SL("_sqlColumnAliases"), &_125, &sqlColumnAliases);
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
		ZEPHIR_CALL_METHOD(&_126$$105, this_ptr, "_getexpression", NULL, 337, &where);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("where"), &_126$$105, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&groupBy);
	if (zephir_array_isset_string_fetch(&groupBy, ast, SL("groupBy"), 0)) {
		ZEPHIR_CALL_METHOD(&_127$$106, this_ptr, "_getgroupclause", NULL, 349, &groupBy);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("group"), &_127$$106, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&having);
	if (zephir_array_isset_string_fetch(&having, ast, SL("having"), 0)) {
		ZEPHIR_CALL_METHOD(&_128$$107, this_ptr, "_getexpression", NULL, 337, &having);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("having"), &_128$$107, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&order);
	if (zephir_array_isset_string_fetch(&order, ast, SL("orderBy"), 0)) {
		ZEPHIR_CALL_METHOD(&_129$$108, this_ptr, "_getorderclause", NULL, 350, &order);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("order"), &_129$$108, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&limit);
	if (zephir_array_isset_string_fetch(&limit, ast, SL("limit"), 0)) {
		ZEPHIR_CALL_METHOD(&_130$$109, this_ptr, "_getlimitclause", NULL, 351, &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("limit"), &_130$$109, PH_COPY | PH_SEPARATE);
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
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_nestingLevel") TSRMLS_CC));
	RETURN_CCTOR(&sqlSelect);

}

/**
 * Analyzes an INSERT intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareInsert) {

	zval _7$$9, _12$$10;
	zend_bool notQuoting = 0;
	zval ast, qualifiedName, nsAlias, manager, modelName, model, source, schema, exprValues, exprValue, sqlInsert, metaData, fields, sqlFields, field, name, realModelName, _4, *_5, _6, _0$$6, _1$$6, _2$$6, _3$$8, _8$$9, _9$$9, _10$$9, _13$$10, _14$$10, _15$$10, *_16$$11, _17$$11, _18$$12, _20$$13, _21$$13, _22$$13, _24$$14, _26$$15, _27$$15, _28$$15;
	zephir_fcall_cache_entry *_11 = NULL, *_19 = NULL, *_23 = NULL, *_25 = NULL;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_12$$10);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&ast);
	zephir_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	if (!(zephir_array_isset_string(&ast, SL("qualifiedName")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST", "phalcon/mvc/model/query.zep", 2116);
		return;
	}
	if (!(zephir_array_isset_string(&ast, SL("values")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST", "phalcon/mvc/model/query.zep", 2120);
		return;
	}
	ZEPHIR_OBS_VAR(&qualifiedName);
	zephir_array_fetch_string(&qualifiedName, &ast, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 2123 TSRMLS_CC);
	if (!(zephir_array_isset_string(&qualifiedName, SL("name")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST", "phalcon/mvc/model/query.zep", 2127);
		return;
	}
	ZEPHIR_OBS_VAR(&manager);
	zephir_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&modelName);
	zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2131 TSRMLS_CC);
	if (zephir_memnstr_str(&modelName, SL(":"), "phalcon/mvc/model/query.zep", 2134)) {
		ZEPHIR_INIT_VAR(&nsAlias);
		zephir_fast_explode_str(&nsAlias, SL(":"), &modelName, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_1$$6, &nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2136 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_0$$6, &manager, "getnamespacealias", NULL, 0, &_1$$6);
		zephir_check_call_status();
		zephir_array_fetch_long(&_2$$6, &nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2136 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&realModelName);
		ZEPHIR_CONCAT_VSV(&realModelName, &_0$$6, "\\", &_2$$6);
	} else {
		ZEPHIR_CPY_WRT(&realModelName, &modelName);
	}
	ZEPHIR_CALL_METHOD(&model, &manager, "load", NULL, 0, &realModelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&_3$$8);
		zephir_create_array(&_3$$8, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_3$$8, &schema);
		zephir_array_fast_append(&_3$$8, &source);
		ZEPHIR_CPY_WRT(&source, &_3$$8);
	}
	notQuoting = 0;
	ZEPHIR_INIT_VAR(&exprValues);
	array_init(&exprValues);
	zephir_array_fetch_string(&_4, &ast, SL("values"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2152 TSRMLS_CC);
	zephir_is_iterable(&_4, 0, "phalcon/mvc/model/query.zep", 2161);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
		{
			ZEPHIR_INIT_NVAR(&exprValue);
			ZVAL_COPY(&exprValue, _5);
			ZEPHIR_INIT_NVAR(&_7$$9);
			zephir_create_array(&_7$$9, 2, 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&_8$$9);
			zephir_array_fetch_string(&_8$$9, &exprValue, SL("type"), PH_NOISY, "phalcon/mvc/model/query.zep", 2156 TSRMLS_CC);
			zephir_array_update_string(&_7$$9, SL("type"), &_8$$9, PH_COPY | PH_SEPARATE);
			if (notQuoting) {
				ZVAL_BOOL(&_10$$9, 1);
			} else {
				ZVAL_BOOL(&_10$$9, 0);
			}
			ZEPHIR_CALL_METHOD(&_9$$9, this_ptr, "_getexpression", &_11, 337, &exprValue, &_10$$9);
			zephir_check_call_status();
			zephir_array_update_string(&_7$$9, SL("value"), &_9$$9, PH_COPY | PH_SEPARATE);
			zephir_array_append(&exprValues, &_7$$9, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2158);
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
			ZEPHIR_CALL_METHOD(&exprValue, &_4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$10);
				zephir_create_array(&_12$$10, 2, 0 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&_13$$10);
				zephir_array_fetch_string(&_13$$10, &exprValue, SL("type"), PH_NOISY, "phalcon/mvc/model/query.zep", 2156 TSRMLS_CC);
				zephir_array_update_string(&_12$$10, SL("type"), &_13$$10, PH_COPY | PH_SEPARATE);
				if (notQuoting) {
					ZVAL_BOOL(&_15$$10, 1);
				} else {
					ZVAL_BOOL(&_15$$10, 0);
				}
				ZEPHIR_CALL_METHOD(&_14$$10, this_ptr, "_getexpression", &_11, 337, &exprValue, &_15$$10);
				zephir_check_call_status();
				zephir_array_update_string(&_12$$10, SL("value"), &_14$$10, PH_COPY | PH_SEPARATE);
				zephir_array_append(&exprValues, &_12$$10, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2158);
			ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
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
		zephir_is_iterable(&fields, 0, "phalcon/mvc/model/query.zep", 2185);
		if (Z_TYPE_P(&fields) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _16$$11)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _16$$11);
				ZEPHIR_OBS_NVAR(&name);
				zephir_array_fetch_string(&name, &field, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2172 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_18$$12, &metaData, "hasattribute", &_19, 0, &model, &name);
				zephir_check_call_status();
				if (!(zephir_is_true(&_18$$12))) {
					ZEPHIR_INIT_NVAR(&_20$$13);
					object_init_ex(&_20$$13, phalcon_mvc_model_exception_ce);
					zephir_read_property(&_21$$13, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_LNVAR(_22$$13);
					ZEPHIR_CONCAT_SVSVSV(&_22$$13, "The model '", &modelName, "' doesn't have the attribute '", &name, "', when preparing: ", &_21$$13);
					ZEPHIR_CALL_METHOD(NULL, &_20$$13, "__construct", &_23, 4, &_22$$13);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_20$$13, "phalcon/mvc/model/query.zep", 2178 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&sqlFields, &name, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2182);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_17$$11, &fields, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_17$$11)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&name);
					zephir_array_fetch_string(&name, &field, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2172 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_24$$14, &metaData, "hasattribute", &_25, 0, &model, &name);
					zephir_check_call_status();
					if (!(zephir_is_true(&_24$$14))) {
						ZEPHIR_INIT_NVAR(&_26$$15);
						object_init_ex(&_26$$15, phalcon_mvc_model_exception_ce);
						zephir_read_property(&_27$$15, this_ptr, SL("_phql"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_LNVAR(_28$$15);
						ZEPHIR_CONCAT_SVSVSV(&_28$$15, "The model '", &modelName, "' doesn't have the attribute '", &name, "', when preparing: ", &_27$$15);
						ZEPHIR_CALL_METHOD(NULL, &_26$$15, "__construct", &_23, 4, &_28$$15);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_26$$15, "phalcon/mvc/model/query.zep", 2178 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&sqlFields, &name, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2182);
				ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
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

	zval _22$$24, _29$$25;
	zend_bool notQuoting = 0;
	zval __$null, ast, update, tables, values, modelsInstances, models, sqlTables, sqlAliases, sqlAliasesModelsInstances, updateTables, nsAlias, realModelName, completeSource, sqlModels, manager, table, qualifiedName, modelName, model, source, schema, alias, sqlFields, sqlValues, updateValues, updateValue, exprColumn, sqlUpdate, where, limit, *_0, _1, *_16, _17, _2$$9, _3$$9, _5$$9, _7$$11, _8$$12, _9$$16, _10$$16, _12$$16, _14$$18, _15$$19, _18$$24, _19$$24, _20$$24, _23$$24, _24$$24, _25$$24, _26$$25, _27$$25, _28$$25, _30$$25, _31$$25, _32$$25, _33$$26, _34$$26, _35$$27;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_11 = NULL, *_13 = NULL, *_21 = NULL;
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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$9);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$16);
	ZVAL_UNDEF(&_10$$16);
	ZVAL_UNDEF(&_12$$16);
	ZVAL_UNDEF(&_14$$18);
	ZVAL_UNDEF(&_15$$19);
	ZVAL_UNDEF(&_18$$24);
	ZVAL_UNDEF(&_19$$24);
	ZVAL_UNDEF(&_20$$24);
	ZVAL_UNDEF(&_23$$24);
	ZVAL_UNDEF(&_24$$24);
	ZVAL_UNDEF(&_25$$24);
	ZVAL_UNDEF(&_26$$25);
	ZVAL_UNDEF(&_27$$25);
	ZVAL_UNDEF(&_28$$25);
	ZVAL_UNDEF(&_30$$25);
	ZVAL_UNDEF(&_31$$25);
	ZVAL_UNDEF(&_32$$25);
	ZVAL_UNDEF(&_33$$26);
	ZVAL_UNDEF(&_34$$26);
	ZVAL_UNDEF(&_35$$27);
	ZVAL_UNDEF(&_22$$24);
	ZVAL_UNDEF(&_29$$25);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&ast);
	zephir_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&update);
	if (!(zephir_array_isset_string_fetch(&update, &ast, SL("update"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST", "phalcon/mvc/model/query.zep", 2209);
		return;
	}
	ZEPHIR_OBS_VAR(&tables);
	if (!(zephir_array_isset_string_fetch(&tables, &update, SL("tables"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST", "phalcon/mvc/model/query.zep", 2213);
		return;
	}
	ZEPHIR_OBS_VAR(&values);
	if (!(zephir_array_isset_string_fetch(&values, &update, SL("values"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST", "phalcon/mvc/model/query.zep", 2217);
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
	zephir_is_iterable(&updateTables, 0, "phalcon/mvc/model/query.zep", 2292);
	if (Z_TYPE_P(&updateTables) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&updateTables), _0)
		{
			ZEPHIR_INIT_NVAR(&table);
			ZVAL_COPY(&table, _0);
			ZEPHIR_OBS_NVAR(&qualifiedName);
			zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 2240 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&modelName);
			zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2241 TSRMLS_CC);
			if (zephir_memnstr_str(&modelName, SL(":"), "phalcon/mvc/model/query.zep", 2246)) {
				ZEPHIR_INIT_NVAR(&nsAlias);
				zephir_fast_explode_str(&nsAlias, SL(":"), &modelName, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_3$$9, &nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2248 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_2$$9, &manager, "getnamespacealias", &_4, 0, &_3$$9);
				zephir_check_call_status();
				zephir_array_fetch_long(&_5$$9, &nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2248 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&realModelName);
				ZEPHIR_CONCAT_VSV(&realModelName, &_2$$9, "\\", &_5$$9);
			} else {
				ZEPHIR_CPY_WRT(&realModelName, &modelName);
			}
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_6, 0, &realModelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&completeSource);
			if (zephir_is_true(&schema)) {
				ZEPHIR_INIT_NVAR(&_7$$11);
				zephir_create_array(&_7$$11, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(&_7$$11, &source);
				zephir_array_fast_append(&_7$$11, &schema);
				ZEPHIR_CPY_WRT(&completeSource, &_7$$11);
			} else {
				ZEPHIR_INIT_NVAR(&_8$$12);
				zephir_create_array(&_8$$12, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(&_8$$12, &source);
				zephir_array_fast_append(&_8$$12, &__$null);
				ZEPHIR_CPY_WRT(&completeSource, &_8$$12);
			}
			ZEPHIR_OBS_NVAR(&alias);
			if (zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0)) {
				zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2274);
				zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2275);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&models, &alias, &realModelName, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&sqlAliases, &realModelName, &source, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2281);
				zephir_array_update_zval(&models, &realModelName, &source, PH_COPY | PH_SEPARATE);
			}
			zephir_array_append(&sqlModels, &realModelName, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2285);
			zephir_array_update_zval(&modelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &updateTables, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &updateTables, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&table, &updateTables, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&qualifiedName);
				zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 2240 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2241 TSRMLS_CC);
				if (zephir_memnstr_str(&modelName, SL(":"), "phalcon/mvc/model/query.zep", 2246)) {
					ZEPHIR_INIT_NVAR(&nsAlias);
					zephir_fast_explode_str(&nsAlias, SL(":"), &modelName, LONG_MAX TSRMLS_CC);
					zephir_array_fetch_long(&_10$$16, &nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2248 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_9$$16, &manager, "getnamespacealias", &_11, 0, &_10$$16);
					zephir_check_call_status();
					zephir_array_fetch_long(&_12$$16, &nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2248 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&realModelName);
					ZEPHIR_CONCAT_VSV(&realModelName, &_9$$16, "\\", &_12$$16);
				} else {
					ZEPHIR_CPY_WRT(&realModelName, &modelName);
				}
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_13, 0, &realModelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&schema)) {
					ZEPHIR_INIT_NVAR(&_14$$18);
					zephir_create_array(&_14$$18, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_14$$18, &source);
					zephir_array_fast_append(&_14$$18, &schema);
					ZEPHIR_CPY_WRT(&completeSource, &_14$$18);
				} else {
					ZEPHIR_INIT_NVAR(&_15$$19);
					zephir_create_array(&_15$$19, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_15$$19, &source);
					zephir_array_fast_append(&_15$$19, &__$null);
					ZEPHIR_CPY_WRT(&completeSource, &_15$$19);
				}
				ZEPHIR_OBS_NVAR(&alias);
				if (zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0)) {
					zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2274);
					zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2275);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&models, &alias, &realModelName, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&sqlAliases, &realModelName, &source, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2281);
					zephir_array_update_zval(&models, &realModelName, &source, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&sqlModels, &realModelName, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2285);
				zephir_array_update_zval(&modelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &updateTables, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
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
	zephir_is_iterable(&updateValues, 0, "phalcon/mvc/model/query.zep", 2316);
	if (Z_TYPE_P(&updateValues) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&updateValues), _16)
		{
			ZEPHIR_INIT_NVAR(&updateValue);
			ZVAL_COPY(&updateValue, _16);
			zephir_array_fetch_string(&_19$$24, &updateValue, SL("column"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2308 TSRMLS_CC);
			if (notQuoting) {
				ZVAL_BOOL(&_20$$24, 1);
			} else {
				ZVAL_BOOL(&_20$$24, 0);
			}
			ZEPHIR_CALL_METHOD(&_18$$24, this_ptr, "_getexpression", &_21, 337, &_19$$24, &_20$$24);
			zephir_check_call_status();
			zephir_array_append(&sqlFields, &_18$$24, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2308);
			ZEPHIR_OBS_NVAR(&exprColumn);
			zephir_array_fetch_string(&exprColumn, &updateValue, SL("expr"), PH_NOISY, "phalcon/mvc/model/query.zep", 2309 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_22$$24);
			zephir_create_array(&_22$$24, 2, 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&_23$$24);
			zephir_array_fetch_string(&_23$$24, &exprColumn, SL("type"), PH_NOISY, "phalcon/mvc/model/query.zep", 2311 TSRMLS_CC);
			zephir_array_update_string(&_22$$24, SL("type"), &_23$$24, PH_COPY | PH_SEPARATE);
			if (notQuoting) {
				ZVAL_BOOL(&_25$$24, 1);
			} else {
				ZVAL_BOOL(&_25$$24, 0);
			}
			ZEPHIR_CALL_METHOD(&_24$$24, this_ptr, "_getexpression", &_21, 337, &exprColumn, &_25$$24);
			zephir_check_call_status();
			zephir_array_update_string(&_22$$24, SL("value"), &_24$$24, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlValues, &_22$$24, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2313);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &updateValues, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_17, &updateValues, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&updateValue, &updateValues, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_string(&_27$$25, &updateValue, SL("column"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2308 TSRMLS_CC);
				if (notQuoting) {
					ZVAL_BOOL(&_28$$25, 1);
				} else {
					ZVAL_BOOL(&_28$$25, 0);
				}
				ZEPHIR_CALL_METHOD(&_26$$25, this_ptr, "_getexpression", &_21, 337, &_27$$25, &_28$$25);
				zephir_check_call_status();
				zephir_array_append(&sqlFields, &_26$$25, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2308);
				ZEPHIR_OBS_NVAR(&exprColumn);
				zephir_array_fetch_string(&exprColumn, &updateValue, SL("expr"), PH_NOISY, "phalcon/mvc/model/query.zep", 2309 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_29$$25);
				zephir_create_array(&_29$$25, 2, 0 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&_30$$25);
				zephir_array_fetch_string(&_30$$25, &exprColumn, SL("type"), PH_NOISY, "phalcon/mvc/model/query.zep", 2311 TSRMLS_CC);
				zephir_array_update_string(&_29$$25, SL("type"), &_30$$25, PH_COPY | PH_SEPARATE);
				if (notQuoting) {
					ZVAL_BOOL(&_32$$25, 1);
				} else {
					ZVAL_BOOL(&_32$$25, 0);
				}
				ZEPHIR_CALL_METHOD(&_31$$25, this_ptr, "_getexpression", &_21, 337, &exprColumn, &_32$$25);
				zephir_check_call_status();
				zephir_array_update_string(&_29$$25, SL("value"), &_31$$25, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlValues, &_29$$25, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2313);
			ZEPHIR_CALL_METHOD(NULL, &updateValues, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&updateValue);
	ZEPHIR_INIT_VAR(&sqlUpdate);
	zephir_create_array(&sqlUpdate, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&sqlUpdate, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("fields"), &sqlFields, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("values"), &sqlValues, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&where);
	if (zephir_array_isset_string_fetch(&where, &ast, SL("where"), 0)) {
		ZVAL_BOOL(&_34$$26, 1);
		ZEPHIR_CALL_METHOD(&_33$$26, this_ptr, "_getexpression", &_21, 337, &where, &_34$$26);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("where"), &_33$$26, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&limit);
	if (zephir_array_isset_string_fetch(&limit, &ast, SL("limit"), 0)) {
		ZEPHIR_CALL_METHOD(&_35$$27, this_ptr, "_getlimitclause", NULL, 351, &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("limit"), &_35$$27, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&sqlUpdate);

}

/**
 * Analyzes a DELETE intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareDelete) {

	zval __$null, ast, delete, tables, models, modelsInstances, sqlTables, sqlModels, sqlAliases, sqlAliasesModelsInstances, deleteTables, manager, table, qualifiedName, modelName, nsAlias, realModelName, model, source, schema, completeSource, alias, sqlDelete, where, limit, *_0, _1, _2$$8, _3$$8, _5$$8, _7$$10, _8$$11, _9$$15, _10$$15, _12$$15, _14$$17, _15$$18, _16$$21, _17$$21, _18$$22;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_11 = NULL, *_13 = NULL;
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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$15);
	ZVAL_UNDEF(&_10$$15);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_14$$17);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_16$$21);
	ZVAL_UNDEF(&_17$$21);
	ZVAL_UNDEF(&_18$$22);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&ast);
	zephir_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&delete);
	if (!(zephir_array_isset_string_fetch(&delete, &ast, SL("delete"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST", "phalcon/mvc/model/query.zep", 2348);
		return;
	}
	ZEPHIR_OBS_VAR(&tables);
	if (!(zephir_array_isset_string_fetch(&tables, &delete, SL("tables"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST", "phalcon/mvc/model/query.zep", 2352);
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
	zephir_is_iterable(&deleteTables, 0, "phalcon/mvc/model/query.zep", 2422);
	if (Z_TYPE_P(&deleteTables) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&deleteTables), _0)
		{
			ZEPHIR_INIT_NVAR(&table);
			ZVAL_COPY(&table, _0);
			ZEPHIR_OBS_NVAR(&qualifiedName);
			zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 2376 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&modelName);
			zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2377 TSRMLS_CC);
			if (zephir_memnstr_str(&modelName, SL(":"), "phalcon/mvc/model/query.zep", 2382)) {
				ZEPHIR_INIT_NVAR(&nsAlias);
				zephir_fast_explode_str(&nsAlias, SL(":"), &modelName, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_3$$8, &nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2384 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_2$$8, &manager, "getnamespacealias", &_4, 0, &_3$$8);
				zephir_check_call_status();
				zephir_array_fetch_long(&_5$$8, &nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2384 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&realModelName);
				ZEPHIR_CONCAT_VSV(&realModelName, &_2$$8, "\\", &_5$$8);
			} else {
				ZEPHIR_CPY_WRT(&realModelName, &modelName);
			}
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_6, 0, &realModelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&completeSource);
			if (zephir_is_true(&schema)) {
				ZEPHIR_INIT_NVAR(&_7$$10);
				zephir_create_array(&_7$$10, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(&_7$$10, &source);
				zephir_array_fast_append(&_7$$10, &schema);
				ZEPHIR_CPY_WRT(&completeSource, &_7$$10);
			} else {
				ZEPHIR_INIT_NVAR(&_8$$11);
				zephir_create_array(&_8$$11, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(&_8$$11, &source);
				zephir_array_fast_append(&_8$$11, &__$null);
				ZEPHIR_CPY_WRT(&completeSource, &_8$$11);
			}
			ZEPHIR_OBS_NVAR(&alias);
			if (zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0)) {
				zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2404);
				zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2405);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&models, &alias, &realModelName, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&sqlAliases, &realModelName, &source, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2411);
				zephir_array_update_zval(&models, &realModelName, &source, PH_COPY | PH_SEPARATE);
			}
			zephir_array_append(&sqlModels, &realModelName, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2415);
			zephir_array_update_zval(&modelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &deleteTables, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &deleteTables, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&table, &deleteTables, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&qualifiedName);
				zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 2376 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2377 TSRMLS_CC);
				if (zephir_memnstr_str(&modelName, SL(":"), "phalcon/mvc/model/query.zep", 2382)) {
					ZEPHIR_INIT_NVAR(&nsAlias);
					zephir_fast_explode_str(&nsAlias, SL(":"), &modelName, LONG_MAX TSRMLS_CC);
					zephir_array_fetch_long(&_10$$15, &nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2384 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_9$$15, &manager, "getnamespacealias", &_11, 0, &_10$$15);
					zephir_check_call_status();
					zephir_array_fetch_long(&_12$$15, &nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2384 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&realModelName);
					ZEPHIR_CONCAT_VSV(&realModelName, &_9$$15, "\\", &_12$$15);
				} else {
					ZEPHIR_CPY_WRT(&realModelName, &modelName);
				}
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_13, 0, &realModelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&schema)) {
					ZEPHIR_INIT_NVAR(&_14$$17);
					zephir_create_array(&_14$$17, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_14$$17, &source);
					zephir_array_fast_append(&_14$$17, &schema);
					ZEPHIR_CPY_WRT(&completeSource, &_14$$17);
				} else {
					ZEPHIR_INIT_NVAR(&_15$$18);
					zephir_create_array(&_15$$18, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_15$$18, &source);
					zephir_array_fast_append(&_15$$18, &__$null);
					ZEPHIR_CPY_WRT(&completeSource, &_15$$18);
				}
				ZEPHIR_OBS_NVAR(&alias);
				if (zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0)) {
					zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2404);
					zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2405);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&models, &alias, &realModelName, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&sqlAliases, &realModelName, &source, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2411);
					zephir_array_update_zval(&models, &realModelName, &source, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&sqlModels, &realModelName, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2415);
				zephir_array_update_zval(&modelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &deleteTables, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
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
		ZVAL_BOOL(&_17$$21, 1);
		ZEPHIR_CALL_METHOD(&_16$$21, this_ptr, "_getexpression", NULL, 337, &where, &_17$$21);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("where"), &_16$$21, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&limit);
	if (zephir_array_isset_string_fetch(&limit, &ast, SL("limit"), 0)) {
		ZEPHIR_CALL_METHOD(&_18$$22, this_ptr, "_getlimitclause", NULL, 351, &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("limit"), &_18$$22, PH_COPY | PH_SEPARATE);
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
					zephir_array_fetch_string(&_1$$7, &ast, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2473 TSRMLS_CC);
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
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_prepareselect", NULL, 342);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 306)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_prepareinsert", NULL, 352);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 300)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_prepareupdate", NULL, 353);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 303)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_preparedelete", NULL, 354);
					zephir_check_call_status();
					break;
				}
				ZEPHIR_INIT_VAR(&_2$$13);
				object_init_ex(&_2$$13, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_3$$13);
				ZEPHIR_CONCAT_SVSV(&_3$$13, "Unknown statement ", &type, ", when preparing: ", &phql);
				ZEPHIR_CALL_METHOD(NULL, &_2$$13, "__construct", NULL, 4, &_3$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_2$$13, "phalcon/mvc/model/query.zep", 2506 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} while(0);

		}
	}
	if (Z_TYPE_P(&irPhql) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted AST", "phalcon/mvc/model/query.zep", 2512);
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

	zend_class_entry *_99$$101;
	zend_string *_16, *_62$$64, *_68$$74, *_85$$97;
	zend_ulong _15, _61$$64, _67$$74, _84$$97;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL, *_7 = NULL, *_19 = NULL, *_20 = NULL, *_21 = NULL, *_29 = NULL, *_40 = NULL, *_41 = NULL, *_42 = NULL, *_50 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberObjects = 0;
	zend_bool simulate, haveObjects = 0, haveScalars = 0, isComplex = 0, isSimpleStd = 0, isKeepingSnapshots = 0, _73, _37$$28, _58$$46, _91$$87;
	zval *intermediate_param = NULL, *bindParams, bindParams_sub, *bindTypes, bindTypes_sub, *simulate_param = NULL, __$true, __$null, manager, modelName, models, model, connection, connectionTypes, columns, column, selectColumns, simpleColumnMap, metaData, aliasCopy, sqlColumn, attributes, instance, columnMap, attribute, columnAlias, sqlAlias, dialect, sqlSelect, bindCounts, processed, wildcard, value, processedTypes, typeWildcard, result, resultData, cache, resultObject, columns1, typesColumnMap, wildcardValue, resultsetClassName, *_0, _1, *_9, _10, *_13, _14, _71, _74, _2$$3, _5$$5, _6$$7, _8$$9, _11$$11, _12$$16, _17$$28, _18$$29, *_22$$31, _23$$31, _28$$31, _25$$34, _27$$35, _30$$36, *_31$$37, _32$$37, _35$$41, _36$$42, _38$$46, _39$$47, *_43$$49, _44$$49, _49$$49, _46$$52, _48$$53, _51$$54, *_52$$55, _53$$55, _56$$59, _57$$60, *_59$$64, _60$$64, _63$$68, _64$$72, *_65$$74, _66$$74, _69$$76, _70$$79, _72$$83, _75$$94, *_76$$94, _77$$94, _79$$95, _81$$96, *_82$$97, _83$$97, _87$$98, _89$$99, _90$$89, _101$$87, _92$$102, _93$$102, _94$$101, _95$$101, _98$$101, _100$$101, _96$$103, _97$$103;
	zval intermediate, _24$$34, _26$$35, _33$$38, _34$$39, _45$$52, _47$$53, _54$$56, _55$$57, _78$$95, _80$$96, _86$$98, _88$$99;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&_24$$34);
	ZVAL_UNDEF(&_26$$35);
	ZVAL_UNDEF(&_33$$38);
	ZVAL_UNDEF(&_34$$39);
	ZVAL_UNDEF(&_45$$52);
	ZVAL_UNDEF(&_47$$53);
	ZVAL_UNDEF(&_54$$56);
	ZVAL_UNDEF(&_55$$57);
	ZVAL_UNDEF(&_78$$95);
	ZVAL_UNDEF(&_80$$96);
	ZVAL_UNDEF(&_86$$98);
	ZVAL_UNDEF(&_88$$99);
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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_71);
	ZVAL_UNDEF(&_74);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$16);
	ZVAL_UNDEF(&_17$$28);
	ZVAL_UNDEF(&_18$$29);
	ZVAL_UNDEF(&_23$$31);
	ZVAL_UNDEF(&_28$$31);
	ZVAL_UNDEF(&_25$$34);
	ZVAL_UNDEF(&_27$$35);
	ZVAL_UNDEF(&_30$$36);
	ZVAL_UNDEF(&_32$$37);
	ZVAL_UNDEF(&_35$$41);
	ZVAL_UNDEF(&_36$$42);
	ZVAL_UNDEF(&_38$$46);
	ZVAL_UNDEF(&_39$$47);
	ZVAL_UNDEF(&_44$$49);
	ZVAL_UNDEF(&_49$$49);
	ZVAL_UNDEF(&_46$$52);
	ZVAL_UNDEF(&_48$$53);
	ZVAL_UNDEF(&_51$$54);
	ZVAL_UNDEF(&_53$$55);
	ZVAL_UNDEF(&_56$$59);
	ZVAL_UNDEF(&_57$$60);
	ZVAL_UNDEF(&_60$$64);
	ZVAL_UNDEF(&_63$$68);
	ZVAL_UNDEF(&_64$$72);
	ZVAL_UNDEF(&_66$$74);
	ZVAL_UNDEF(&_69$$76);
	ZVAL_UNDEF(&_70$$79);
	ZVAL_UNDEF(&_72$$83);
	ZVAL_UNDEF(&_75$$94);
	ZVAL_UNDEF(&_77$$94);
	ZVAL_UNDEF(&_79$$95);
	ZVAL_UNDEF(&_81$$96);
	ZVAL_UNDEF(&_83$$97);
	ZVAL_UNDEF(&_87$$98);
	ZVAL_UNDEF(&_89$$99);
	ZVAL_UNDEF(&_90$$89);
	ZVAL_UNDEF(&_101$$87);
	ZVAL_UNDEF(&_92$$102);
	ZVAL_UNDEF(&_93$$102);
	ZVAL_UNDEF(&_94$$101);
	ZVAL_UNDEF(&_95$$101);
	ZVAL_UNDEF(&_98$$101);
	ZVAL_UNDEF(&_100$$101);
	ZVAL_UNDEF(&_96$$103);
	ZVAL_UNDEF(&_97$$103);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &intermediate_param, &bindParams, &bindTypes, &simulate_param);

	zephir_get_arrval(&intermediate, intermediate_param);
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
	zephir_array_fetch_string(&models, &intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 2555 TSRMLS_CC);
	zephir_is_iterable(&models, 0, "phalcon/mvc/model/query.zep", 2576);
	if (Z_TYPE_P(&models) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&models), _0)
		{
			ZEPHIR_INIT_NVAR(&modelName);
			ZVAL_COPY(&modelName, _0);
			ZEPHIR_OBS_NVAR(&model);
			zephir_read_property(&_2$$3, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset_fetch(&model, &_2$$3, &modelName, 0 TSRMLS_CC))) {
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_3, 0, &modelName);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("_modelsInstances"), &modelName, &model);
			}
			ZEPHIR_CALL_METHOD(&connection, this_ptr, "getreadconnection", &_4, 0, &model, &intermediate, bindParams, bindTypes);
			zephir_check_call_status();
			if (Z_TYPE_P(&connection) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&_5$$5, &connection, "gettype", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&connectionTypes, &_5$$5, &__$true, PH_COPY | PH_SEPARATE);
				if (zephir_fast_count_int(&connectionTypes TSRMLS_CC) == 2) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cannot use models of different database systems in the same query", "phalcon/mvc/model/query.zep", 2571);
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &models, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &models, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&modelName, &models, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&model);
				zephir_read_property(&_6$$7, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset_fetch(&model, &_6$$7, &modelName, 0 TSRMLS_CC))) {
					ZEPHIR_CALL_METHOD(&model, &manager, "load", &_7, 0, &modelName);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("_modelsInstances"), &modelName, &model);
				}
				ZEPHIR_CALL_METHOD(&connection, this_ptr, "getreadconnection", &_4, 0, &model, &intermediate, bindParams, bindTypes);
				zephir_check_call_status();
				if (Z_TYPE_P(&connection) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&_8$$9, &connection, "gettype", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&connectionTypes, &_8$$9, &__$true, PH_COPY | PH_SEPARATE);
					if (zephir_fast_count_int(&connectionTypes TSRMLS_CC) == 2) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cannot use models of different database systems in the same query", "phalcon/mvc/model/query.zep", 2571);
						return;
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &models, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&modelName);
	ZEPHIR_OBS_VAR(&columns);
	zephir_array_fetch_string(&columns, &intermediate, SL("columns"), PH_NOISY, "phalcon/mvc/model/query.zep", 2576 TSRMLS_CC);
	haveObjects = 0;
	haveScalars = 0;
	isComplex = 0;
	numberObjects = 0;
	ZEPHIR_CPY_WRT(&columns1, &columns);
	zephir_is_iterable(&columns, 0, "phalcon/mvc/model/query.zep", 2603);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _9)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _9);
			if (Z_TYPE_P(&column) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid column definition", "phalcon/mvc/model/query.zep", 2589);
				return;
			}
			zephir_array_fetch_string(&_11$$11, &column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2592 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(&_11$$11, "scalar")) {
				if (!(zephir_array_isset_string(&column, SL("balias")))) {
					isComplex = 1;
				}
				haveScalars = 1;
			} else {
				haveObjects = 1;
				numberObjects++;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_10, &columns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &columns, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&column) != IS_ARRAY) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid column definition", "phalcon/mvc/model/query.zep", 2589);
					return;
				}
				zephir_array_fetch_string(&_12$$16, &column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2592 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(&_12$$16, "scalar")) {
					if (!(zephir_array_isset_string(&column, SL("balias")))) {
						isComplex = 1;
					}
					haveScalars = 1;
				} else {
					haveObjects = 1;
					numberObjects++;
				}
			ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
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
	zephir_is_iterable(&columns, 0, "phalcon/mvc/model/query.zep", 2702);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columns), _15, _16, _13)
		{
			ZEPHIR_INIT_NVAR(&aliasCopy);
			if (_16 != NULL) { 
				ZVAL_STR_COPY(&aliasCopy, _16);
			} else {
				ZVAL_LONG(&aliasCopy, _15);
			}
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _13);
			ZEPHIR_OBS_NVAR(&sqlColumn);
			zephir_array_fetch_string(&sqlColumn, &column, SL("column"), PH_NOISY, "phalcon/mvc/model/query.zep", 2627 TSRMLS_CC);
			zephir_array_fetch_string(&_17$$28, &column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2630 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(&_17$$28, "object")) {
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &column, SL("model"), PH_NOISY, "phalcon/mvc/model/query.zep", 2632 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&instance);
				zephir_read_property(&_18$$29, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset_fetch(&instance, &_18$$29, &modelName, 0 TSRMLS_CC))) {
					ZEPHIR_CALL_METHOD(&instance, &manager, "load", &_19, 0, &modelName);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("_modelsInstances"), &modelName, &instance);
				}
				ZEPHIR_CALL_METHOD(&attributes, &metaData, "getattributes", &_20, 0, &instance);
				zephir_check_call_status();
				if (isComplex == 1) {
					if (ZEPHIR_GLOBAL(orm).column_renaming) {
						ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", &_21, 0, &instance);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&columnMap);
						ZVAL_NULL(&columnMap);
					}
					zephir_is_iterable(&attributes, 0, "phalcon/mvc/model/query.zep", 2658);
					if (Z_TYPE_P(&attributes) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _22$$31)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _22$$31);
							ZEPHIR_INIT_NVAR(&_24$$34);
							zephir_create_array(&_24$$34, 3, 0 TSRMLS_CC);
							zephir_array_fast_append(&_24$$34, &attribute);
							zephir_array_fast_append(&_24$$34, &sqlColumn);
							ZEPHIR_INIT_LNVAR(_25$$34);
							ZEPHIR_CONCAT_SVSV(&_25$$34, "_", &sqlColumn, "_", &attribute);
							zephir_array_fast_append(&_24$$34, &_25$$34);
							zephir_array_append(&selectColumns, &_24$$34, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2654);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_23$$31, &attributes, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_23$$31)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_26$$35);
								zephir_create_array(&_26$$35, 3, 0 TSRMLS_CC);
								zephir_array_fast_append(&_26$$35, &attribute);
								zephir_array_fast_append(&_26$$35, &sqlColumn);
								ZEPHIR_INIT_LNVAR(_27$$35);
								ZEPHIR_CONCAT_SVSV(&_27$$35, "_", &sqlColumn, "_", &attribute);
								zephir_array_fast_append(&_26$$35, &_27$$35);
								zephir_array_append(&selectColumns, &_26$$35, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2654);
							ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
					zephir_array_update_multi(&columns1, &instance TSRMLS_CC, SL("zs"), 3, &aliasCopy, SL("instance"));
					zephir_array_update_multi(&columns1, &attributes TSRMLS_CC, SL("zs"), 3, &aliasCopy, SL("attributes"));
					zephir_array_update_multi(&columns1, &columnMap TSRMLS_CC, SL("zs"), 3, &aliasCopy, SL("columnMap"));
					ZEPHIR_CALL_METHOD(&_28$$31, &manager, "iskeepingsnapshots", &_29, 0, &instance);
					zephir_check_call_status();
					isKeepingSnapshots = zephir_get_boolval(&_28$$31);
					if (isKeepingSnapshots) {
						ZEPHIR_INIT_NVAR(&_30$$36);
						ZVAL_BOOL(&_30$$36, isKeepingSnapshots);
						zephir_array_update_multi(&columns1, &_30$$36 TSRMLS_CC, SL("zs"), 3, &aliasCopy, SL("keepSnapshots"));
					}
				} else {
					zephir_is_iterable(&attributes, 0, "phalcon/mvc/model/query.zep", 2676);
					if (Z_TYPE_P(&attributes) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _31$$37)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _31$$37);
							ZEPHIR_INIT_NVAR(&_33$$38);
							zephir_create_array(&_33$$38, 2, 0 TSRMLS_CC);
							zephir_array_fast_append(&_33$$38, &attribute);
							zephir_array_fast_append(&_33$$38, &sqlColumn);
							zephir_array_append(&selectColumns, &_33$$38, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2674);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_32$$37, &attributes, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_32$$37)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_34$$39);
								zephir_create_array(&_34$$39, 2, 0 TSRMLS_CC);
								zephir_array_fast_append(&_34$$39, &attribute);
								zephir_array_fast_append(&_34$$39, &sqlColumn);
								zephir_array_append(&selectColumns, &_34$$39, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2674);
							ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
				}
			} else {
				ZEPHIR_INIT_NVAR(&columnAlias);
				if (Z_TYPE_P(&aliasCopy) == IS_LONG) {
					ZEPHIR_INIT_NVAR(&_35$$41);
					zephir_create_array(&_35$$41, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_35$$41, &sqlColumn);
					zephir_array_fast_append(&_35$$41, &__$null);
					ZEPHIR_CPY_WRT(&columnAlias, &_35$$41);
				} else {
					ZEPHIR_INIT_NVAR(&_36$$42);
					zephir_create_array(&_36$$42, 3, 0 TSRMLS_CC);
					zephir_array_fast_append(&_36$$42, &sqlColumn);
					zephir_array_fast_append(&_36$$42, &__$null);
					zephir_array_fast_append(&_36$$42, &aliasCopy);
					ZEPHIR_CPY_WRT(&columnAlias, &_36$$42);
				}
				zephir_array_append(&selectColumns, &columnAlias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2687);
			}
			_37$$28 = isComplex == 0;
			if (_37$$28) {
				_37$$28 = isSimpleStd == 1;
			}
			if (_37$$28) {
				ZEPHIR_OBS_NVAR(&sqlAlias);
				if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
					zephir_array_update_zval(&simpleColumnMap, &sqlAlias, &aliasCopy, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&simpleColumnMap, &aliasCopy, &aliasCopy, PH_COPY | PH_SEPARATE);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_14, &columns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&aliasCopy, &columns, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&column, &columns, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&sqlColumn);
				zephir_array_fetch_string(&sqlColumn, &column, SL("column"), PH_NOISY, "phalcon/mvc/model/query.zep", 2627 TSRMLS_CC);
				zephir_array_fetch_string(&_38$$46, &column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2630 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(&_38$$46, "object")) {
					ZEPHIR_OBS_NVAR(&modelName);
					zephir_array_fetch_string(&modelName, &column, SL("model"), PH_NOISY, "phalcon/mvc/model/query.zep", 2632 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&instance);
					zephir_read_property(&_39$$47, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
					if (!(zephir_array_isset_fetch(&instance, &_39$$47, &modelName, 0 TSRMLS_CC))) {
						ZEPHIR_CALL_METHOD(&instance, &manager, "load", &_40, 0, &modelName);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("_modelsInstances"), &modelName, &instance);
					}
					ZEPHIR_CALL_METHOD(&attributes, &metaData, "getattributes", &_41, 0, &instance);
					zephir_check_call_status();
					if (isComplex == 1) {
						if (ZEPHIR_GLOBAL(orm).column_renaming) {
							ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", &_42, 0, &instance);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(&columnMap);
							ZVAL_NULL(&columnMap);
						}
						zephir_is_iterable(&attributes, 0, "phalcon/mvc/model/query.zep", 2658);
						if (Z_TYPE_P(&attributes) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _43$$49)
							{
								ZEPHIR_INIT_NVAR(&attribute);
								ZVAL_COPY(&attribute, _43$$49);
								ZEPHIR_INIT_NVAR(&_45$$52);
								zephir_create_array(&_45$$52, 3, 0 TSRMLS_CC);
								zephir_array_fast_append(&_45$$52, &attribute);
								zephir_array_fast_append(&_45$$52, &sqlColumn);
								ZEPHIR_INIT_LNVAR(_46$$52);
								ZEPHIR_CONCAT_SVSV(&_46$$52, "_", &sqlColumn, "_", &attribute);
								zephir_array_fast_append(&_45$$52, &_46$$52);
								zephir_array_append(&selectColumns, &_45$$52, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2654);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_44$$49, &attributes, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_44$$49)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_47$$53);
									zephir_create_array(&_47$$53, 3, 0 TSRMLS_CC);
									zephir_array_fast_append(&_47$$53, &attribute);
									zephir_array_fast_append(&_47$$53, &sqlColumn);
									ZEPHIR_INIT_LNVAR(_48$$53);
									ZEPHIR_CONCAT_SVSV(&_48$$53, "_", &sqlColumn, "_", &attribute);
									zephir_array_fast_append(&_47$$53, &_48$$53);
									zephir_array_append(&selectColumns, &_47$$53, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2654);
								ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&attribute);
						zephir_array_update_multi(&columns1, &instance TSRMLS_CC, SL("zs"), 3, &aliasCopy, SL("instance"));
						zephir_array_update_multi(&columns1, &attributes TSRMLS_CC, SL("zs"), 3, &aliasCopy, SL("attributes"));
						zephir_array_update_multi(&columns1, &columnMap TSRMLS_CC, SL("zs"), 3, &aliasCopy, SL("columnMap"));
						ZEPHIR_CALL_METHOD(&_49$$49, &manager, "iskeepingsnapshots", &_50, 0, &instance);
						zephir_check_call_status();
						isKeepingSnapshots = zephir_get_boolval(&_49$$49);
						if (isKeepingSnapshots) {
							ZEPHIR_INIT_NVAR(&_51$$54);
							ZVAL_BOOL(&_51$$54, isKeepingSnapshots);
							zephir_array_update_multi(&columns1, &_51$$54 TSRMLS_CC, SL("zs"), 3, &aliasCopy, SL("keepSnapshots"));
						}
					} else {
						zephir_is_iterable(&attributes, 0, "phalcon/mvc/model/query.zep", 2676);
						if (Z_TYPE_P(&attributes) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _52$$55)
							{
								ZEPHIR_INIT_NVAR(&attribute);
								ZVAL_COPY(&attribute, _52$$55);
								ZEPHIR_INIT_NVAR(&_54$$56);
								zephir_create_array(&_54$$56, 2, 0 TSRMLS_CC);
								zephir_array_fast_append(&_54$$56, &attribute);
								zephir_array_fast_append(&_54$$56, &sqlColumn);
								zephir_array_append(&selectColumns, &_54$$56, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2674);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_53$$55, &attributes, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_53$$55)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_55$$57);
									zephir_create_array(&_55$$57, 2, 0 TSRMLS_CC);
									zephir_array_fast_append(&_55$$57, &attribute);
									zephir_array_fast_append(&_55$$57, &sqlColumn);
									zephir_array_append(&selectColumns, &_55$$57, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2674);
								ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&attribute);
					}
				} else {
					if (Z_TYPE_P(&aliasCopy) == IS_LONG) {
						ZEPHIR_INIT_NVAR(&_56$$59);
						zephir_create_array(&_56$$59, 2, 0 TSRMLS_CC);
						zephir_array_fast_append(&_56$$59, &sqlColumn);
						zephir_array_fast_append(&_56$$59, &__$null);
						ZEPHIR_CPY_WRT(&columnAlias, &_56$$59);
					} else {
						ZEPHIR_INIT_NVAR(&_57$$60);
						zephir_create_array(&_57$$60, 3, 0 TSRMLS_CC);
						zephir_array_fast_append(&_57$$60, &sqlColumn);
						zephir_array_fast_append(&_57$$60, &__$null);
						zephir_array_fast_append(&_57$$60, &aliasCopy);
						ZEPHIR_CPY_WRT(&columnAlias, &_57$$60);
					}
					zephir_array_append(&selectColumns, &columnAlias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2687);
				}
				_58$$46 = isComplex == 0;
				if (_58$$46) {
					_58$$46 = isSimpleStd == 1;
				}
				if (_58$$46) {
					ZEPHIR_OBS_NVAR(&sqlAlias);
					if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
						zephir_array_update_zval(&simpleColumnMap, &sqlAlias, &aliasCopy, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&simpleColumnMap, &aliasCopy, &aliasCopy, PH_COPY | PH_SEPARATE);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	ZEPHIR_INIT_NVAR(&aliasCopy);
	ZEPHIR_INIT_VAR(&bindCounts);
	array_init(&bindCounts);
	zephir_array_update_string(&intermediate, SL("columns"), &selectColumns, PH_COPY | PH_SEPARATE);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&processed);
		array_init(&processed);
		zephir_is_iterable(bindParams, 0, "phalcon/mvc/model/query.zep", 2723);
		if (Z_TYPE_P(bindParams) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(bindParams), _61$$64, _62$$64, _59$$64)
			{
				ZEPHIR_INIT_NVAR(&wildcard);
				if (_62$$64 != NULL) { 
					ZVAL_STR_COPY(&wildcard, _62$$64);
				} else {
					ZVAL_LONG(&wildcard, _61$$64);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _59$$64);
				if (Z_TYPE_P(&wildcard) == IS_LONG) {
					ZEPHIR_INIT_NVAR(&wildcardValue);
					ZEPHIR_CONCAT_SV(&wildcardValue, ":", &wildcard);
				} else {
					ZEPHIR_CPY_WRT(&wildcardValue, &wildcard);
				}
				zephir_array_update_zval(&processed, &wildcardValue, &value, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_63$$68);
					ZVAL_LONG(&_63$$68, zephir_fast_count_int(&value TSRMLS_CC));
					zephir_array_update_zval(&bindCounts, &wildcardValue, &_63$$68, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, bindParams, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_60$$64, bindParams, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_60$$64)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&wildcard, bindParams, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, bindParams, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&wildcard) == IS_LONG) {
						ZEPHIR_INIT_NVAR(&wildcardValue);
						ZEPHIR_CONCAT_SV(&wildcardValue, ":", &wildcard);
					} else {
						ZEPHIR_CPY_WRT(&wildcardValue, &wildcard);
					}
					zephir_array_update_zval(&processed, &wildcardValue, &value, PH_COPY | PH_SEPARATE);
					if (Z_TYPE_P(&value) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_64$$72);
						ZVAL_LONG(&_64$$72, zephir_fast_count_int(&value TSRMLS_CC));
						zephir_array_update_zval(&bindCounts, &wildcardValue, &_64$$72, PH_COPY | PH_SEPARATE);
					}
				ZEPHIR_CALL_METHOD(NULL, bindParams, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&wildcard);
	} else {
		ZEPHIR_CPY_WRT(&processed, bindParams);
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&processedTypes);
		array_init(&processedTypes);
		zephir_is_iterable(bindTypes, 0, "phalcon/mvc/model/query.zep", 2739);
		if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(bindTypes), _67$$74, _68$$74, _65$$74)
			{
				ZEPHIR_INIT_NVAR(&typeWildcard);
				if (_68$$74 != NULL) { 
					ZVAL_STR_COPY(&typeWildcard, _68$$74);
				} else {
					ZVAL_LONG(&typeWildcard, _67$$74);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _65$$74);
				if (Z_TYPE_P(&typeWildcard) == IS_LONG) {
					ZEPHIR_INIT_LNVAR(_69$$76);
					ZEPHIR_CONCAT_SV(&_69$$76, ":", &typeWildcard);
					zephir_array_update_zval(&processedTypes, &_69$$76, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&processedTypes, &typeWildcard, &value, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, bindTypes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_66$$74, bindTypes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_66$$74)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&typeWildcard, bindTypes, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, bindTypes, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&typeWildcard) == IS_LONG) {
						ZEPHIR_INIT_LNVAR(_70$$79);
						ZEPHIR_CONCAT_SV(&_70$$79, ":", &typeWildcard);
						zephir_array_update_zval(&processedTypes, &_70$$79, &value, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&processedTypes, &typeWildcard, &value, PH_COPY | PH_SEPARATE);
					}
				ZEPHIR_CALL_METHOD(NULL, bindTypes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&typeWildcard);
	} else {
		ZEPHIR_CPY_WRT(&processedTypes, bindTypes);
	}
	if (zephir_fast_count_int(&bindCounts TSRMLS_CC)) {
		zephir_array_update_string(&intermediate, SL("bindCounts"), &bindCounts, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&dialect, &connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&sqlSelect, &dialect, "select", NULL, 0, &intermediate);
	zephir_check_call_status();
	zephir_read_property(&_71, this_ptr, SL("_sharedLock"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_71)) {
		ZEPHIR_CALL_METHOD(&_72$$83, &dialect, "sharedlock", NULL, 0, &sqlSelect);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&sqlSelect, &_72$$83);
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
	_73 = zephir_instance_of_ev(&result, phalcon_db_resultinterface_ce TSRMLS_CC);
	if (_73) {
		ZEPHIR_CALL_METHOD(&_74, &result, "numrows", NULL, 0);
		zephir_check_call_status();
		_73 = zephir_is_true(&_74);
	}
	if (_73) {
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
					ZEPHIR_CALL_METHOD(&_75$$94, &metaData, "getattributes", NULL, 0, &resultObject);
					zephir_check_call_status();
					zephir_is_iterable(&_75$$94, 0, "phalcon/mvc/model/query.zep", 2825);
					if (Z_TYPE_P(&_75$$94) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_75$$94), _76$$94)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _76$$94);
							ZEPHIR_INIT_NVAR(&_78$$95);
							zephir_create_array(&_78$$95, 2, 0 TSRMLS_CC);
							zephir_array_fast_append(&_78$$95, &attribute);
							ZEPHIR_OBS_NVAR(&_79$$95);
							zephir_array_fetch(&_79$$95, &typesColumnMap, &attribute, PH_NOISY, "phalcon/mvc/model/query.zep", 2823 TSRMLS_CC);
							zephir_array_fast_append(&_78$$95, &_79$$95);
							zephir_array_update_zval(&simpleColumnMap, &attribute, &_78$$95, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &_75$$94, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_77$$94, &_75$$94, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_77$$94)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, &_75$$94, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_80$$96);
								zephir_create_array(&_80$$96, 2, 0 TSRMLS_CC);
								zephir_array_fast_append(&_80$$96, &attribute);
								ZEPHIR_OBS_NVAR(&_81$$96);
								zephir_array_fetch(&_81$$96, &typesColumnMap, &attribute, PH_NOISY, "phalcon/mvc/model/query.zep", 2823 TSRMLS_CC);
								zephir_array_fast_append(&_80$$96, &_81$$96);
								zephir_array_update_zval(&simpleColumnMap, &attribute, &_80$$96, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &_75$$94, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
				} else {
					array_init(&simpleColumnMap);
					zephir_is_iterable(&columnMap, 0, "phalcon/mvc/model/query.zep", 2830);
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columnMap), _84$$97, _85$$97, _82$$97)
						{
							ZEPHIR_INIT_NVAR(&column);
							if (_85$$97 != NULL) { 
								ZVAL_STR_COPY(&column, _85$$97);
							} else {
								ZVAL_LONG(&column, _84$$97);
							}
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _82$$97);
							ZEPHIR_INIT_NVAR(&_86$$98);
							zephir_create_array(&_86$$98, 2, 0 TSRMLS_CC);
							zephir_array_fast_append(&_86$$98, &attribute);
							ZEPHIR_OBS_NVAR(&_87$$98);
							zephir_array_fetch(&_87$$98, &typesColumnMap, &column, PH_NOISY, "phalcon/mvc/model/query.zep", 2828 TSRMLS_CC);
							zephir_array_fast_append(&_86$$98, &_87$$98);
							zephir_array_update_zval(&simpleColumnMap, &column, &_86$$98, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &columnMap, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_83$$97, &columnMap, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_83$$97)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&column, &columnMap, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&attribute, &columnMap, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_88$$99);
								zephir_create_array(&_88$$99, 2, 0 TSRMLS_CC);
								zephir_array_fast_append(&_88$$99, &attribute);
								ZEPHIR_OBS_NVAR(&_89$$99);
								zephir_array_fetch(&_89$$99, &typesColumnMap, &column, PH_NOISY, "phalcon/mvc/model/query.zep", 2828 TSRMLS_CC);
								zephir_array_fast_append(&_88$$99, &_89$$99);
								zephir_array_update_zval(&simpleColumnMap, &column, &_88$$99, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &columnMap, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
					ZEPHIR_INIT_NVAR(&column);
				}
			}
			ZEPHIR_CALL_METHOD(&_90$$89, &manager, "iskeepingsnapshots", NULL, 0, &resultObject);
			zephir_check_call_status();
			isKeepingSnapshots = zephir_get_boolval(&_90$$89);
		}
		_91$$87 = zephir_instance_of_ev(&resultObject, phalcon_mvc_modelinterface_ce TSRMLS_CC);
		if (_91$$87) {
			_91$$87 = (zephir_method_exists_ex(&resultObject, SL("getresultsetclass") TSRMLS_CC) == SUCCESS);
		}
		if (_91$$87) {
			ZEPHIR_CALL_METHOD(&resultsetClassName, &resultObject, "getresultsetclass", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&resultsetClassName)) {
				if (!(zephir_class_exists(&resultsetClassName, 1 TSRMLS_CC))) {
					ZEPHIR_INIT_VAR(&_92$$102);
					object_init_ex(&_92$$102, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_VAR(&_93$$102);
					ZEPHIR_CONCAT_SVS(&_93$$102, "Resultset class \"", &resultsetClassName, "\" not found");
					ZEPHIR_CALL_METHOD(NULL, &_92$$102, "__construct", NULL, 4, &_93$$102);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_92$$102, "phalcon/mvc/model/query.zep", 2844 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_VAR(&_94$$101);
				ZVAL_STRING(&_94$$101, "Phalcon\\Mvc\\Model\\ResultsetInterface");
				ZEPHIR_CALL_FUNCTION(&_95$$101, "is_subclass_of", NULL, 327, &resultsetClassName, &_94$$101);
				zephir_check_call_status();
				if (!(zephir_is_true(&_95$$101))) {
					ZEPHIR_INIT_VAR(&_96$$103);
					object_init_ex(&_96$$103, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_VAR(&_97$$103);
					ZEPHIR_CONCAT_SVS(&_97$$103, "Resultset class \"", &resultsetClassName, "\" must be an implementation of Phalcon\\Mvc\\Model\\ResultsetInterface");
					ZEPHIR_CALL_METHOD(NULL, &_96$$103, "__construct", NULL, 4, &_97$$103);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_96$$103, "phalcon/mvc/model/query.zep", 2848 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_fetch_safe_class(&_98$$101, &resultsetClassName);
				_99$$101 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_98$$101), Z_STRLEN_P(&_98$$101), ZEND_FETCH_CLASS_AUTO);
				object_init_ex(return_value, _99$$101);
				if (zephir_has_constructor(return_value TSRMLS_CC)) {
					if (isKeepingSnapshots) {
						ZVAL_BOOL(&_100$$101, 1);
					} else {
						ZVAL_BOOL(&_100$$101, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &simpleColumnMap, &resultObject, &resultData, &cache, &_100$$101);
					zephir_check_call_status();
				}
				RETURN_MM();
			}
		}
		object_init_ex(return_value, phalcon_mvc_model_resultset_simple_ce);
		if (isKeepingSnapshots) {
			ZVAL_BOOL(&_101$$87, 1);
		} else {
			ZVAL_BOOL(&_101$$87, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 355, &simpleColumnMap, &resultObject, &resultData, &cache, &_101$$87);
		zephir_check_call_status();
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_mvc_model_resultset_complex_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 356, &columns1, &resultData, &cache);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Executes the INSERT intermediate representation producing a Phalcon\Mvc\Model\Query\Status
 *
 * @param array bindParams
 * @param array bindTypes
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeInsert) {

	zend_string *_4;
	zend_ulong _3;
	zend_bool automaticFields = 0;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_13 = NULL, *_15 = NULL, *_16 = NULL, *_20 = NULL, *_22 = NULL, *_28 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate_param = NULL, *bindParams, bindParams_sub, *bindTypes, bindTypes_sub, modelName, manager, connection, metaData, attributes, fields, columnMap, dialect, insertValues, number, value, model, values, exprValue, insertValue, wildcard, fieldName, attributeName, insertModel, _0, *_1, _2, _31, _5$$8, _7$$11, _9$$11, _10$$11, _11$$13, _12$$13, _14$$14, _17$$17, _18$$17, _19$$20, _21$$23, _23$$23, _24$$23, _25$$25, _26$$25, _27$$26, _29$$29, _30$$29;
	zval intermediate;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$20);
	ZVAL_UNDEF(&_21$$23);
	ZVAL_UNDEF(&_23$$23);
	ZVAL_UNDEF(&_24$$23);
	ZVAL_UNDEF(&_25$$25);
	ZVAL_UNDEF(&_26$$25);
	ZVAL_UNDEF(&_27$$26);
	ZVAL_UNDEF(&_29$$29);
	ZVAL_UNDEF(&_30$$29);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediate_param, &bindParams, &bindTypes);

	zephir_get_arrval(&intermediate, intermediate_param);


	ZEPHIR_OBS_VAR(&modelName);
	zephir_array_fetch_string(&modelName, &intermediate, SL("model"), PH_NOISY, "phalcon/mvc/model/query.zep", 2881 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&manager);
	zephir_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&model);
	zephir_read_property(&_0, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&model, &_0, &modelName, 0 TSRMLS_CC))) {
		ZEPHIR_CALL_METHOD(&model, &manager, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, &model, &intermediate, bindParams, bindTypes);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&metaData);
	zephir_read_property(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&attributes, &metaData, "getattributes", NULL, 0, &model);
	zephir_check_call_status();
	automaticFields = 0;
	ZEPHIR_OBS_VAR(&fields);
	if (!(zephir_array_isset_string_fetch(&fields, &intermediate, SL("fields"), 0))) {
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
	zephir_array_fetch_string(&values, &intermediate, SL("values"), PH_NOISY, "phalcon/mvc/model/query.zep", 2907 TSRMLS_CC);
	if (zephir_fast_count_int(&fields TSRMLS_CC) != zephir_fast_count_int(&values TSRMLS_CC)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The column count does not match the values count", "phalcon/mvc/model/query.zep", 2913);
		return;
	}
	ZEPHIR_CALL_METHOD(&dialect, &connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&insertValues);
	array_init(&insertValues);
	zephir_is_iterable(&values, 0, "phalcon/mvc/model/query.zep", 2982);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&values), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&number);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&number, _4);
			} else {
				ZVAL_LONG(&number, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_OBS_NVAR(&exprValue);
			zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 2924 TSRMLS_CC);
			zephir_array_fetch_string(&_5$$8, &value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2925 TSRMLS_CC);
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
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array", "phalcon/mvc/model/query.zep", 2942);
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
						zephir_throw_exception_debug(&_11$$13, "phalcon/mvc/model/query.zep", 2949 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					break;
				}
				ZEPHIR_INIT_NVAR(&insertValue);
				object_init_ex(&insertValue, phalcon_db_rawvalue_ce);
				ZEPHIR_CALL_METHOD(&_14$$14, &dialect, "getsqlexpression", &_15, 0, &exprValue);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &insertValue, "__construct", &_16, 17, &_14$$14);
				zephir_check_call_status();
				break;
			} while(0);

			ZEPHIR_OBS_NVAR(&fieldName);
			zephir_array_fetch(&fieldName, &fields, &number, PH_NOISY, "phalcon/mvc/model/query.zep", 2959 TSRMLS_CC);
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
						zephir_throw_exception_debug(&_17$$17, "phalcon/mvc/model/query.zep", 2967 TSRMLS_CC);
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
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&number, &values, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&exprValue);
				zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 2924 TSRMLS_CC);
				zephir_array_fetch_string(&_19$$20, &value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2925 TSRMLS_CC);
				do {
					if (ZEPHIR_IS_LONG(&_19$$20, 260) || ZEPHIR_IS_LONG(&_19$$20, 258) || ZEPHIR_IS_LONG(&_19$$20, 259)) {
						ZEPHIR_CALL_METHOD(&insertValue, &dialect, "getsqlexpression", &_20, 0, &exprValue);
						zephir_check_call_status();
						break;
					}
					if (ZEPHIR_IS_LONG(&_19$$20, 322)) {
						ZEPHIR_INIT_NVAR(&insertValue);
						ZVAL_NULL(&insertValue);
						break;
					}
					if (ZEPHIR_IS_LONG(&_19$$20, 273) || ZEPHIR_IS_LONG(&_19$$20, 274) || ZEPHIR_IS_LONG(&_19$$20, 277)) {
						if (Z_TYPE_P(bindParams) != IS_ARRAY) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array", "phalcon/mvc/model/query.zep", 2942);
							return;
						}
						ZEPHIR_CALL_METHOD(&_21$$23, &dialect, "getsqlexpression", &_22, 0, &exprValue);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_23$$23);
						ZVAL_STRING(&_23$$23, ":");
						ZEPHIR_INIT_NVAR(&_24$$23);
						ZVAL_STRING(&_24$$23, "");
						ZEPHIR_INIT_NVAR(&wildcard);
						zephir_fast_str_replace(&wildcard, &_23$$23, &_24$$23, &_21$$23 TSRMLS_CC);
						ZEPHIR_OBS_NVAR(&insertValue);
						if (!(zephir_array_isset_fetch(&insertValue, bindParams, &wildcard, 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_25$$25);
							object_init_ex(&_25$$25, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_26$$25);
							ZEPHIR_CONCAT_SVS(&_26$$25, "Bound parameter '", &wildcard, "' cannot be replaced because it isn't in the placeholders list");
							ZEPHIR_CALL_METHOD(NULL, &_25$$25, "__construct", &_13, 4, &_26$$25);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_25$$25, "phalcon/mvc/model/query.zep", 2949 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						break;
					}
					ZEPHIR_INIT_NVAR(&insertValue);
					object_init_ex(&insertValue, phalcon_db_rawvalue_ce);
					ZEPHIR_CALL_METHOD(&_27$$26, &dialect, "getsqlexpression", &_28, 0, &exprValue);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &insertValue, "__construct", &_16, 17, &_27$$26);
					zephir_check_call_status();
					break;
				} while(0);

				ZEPHIR_OBS_NVAR(&fieldName);
				zephir_array_fetch(&fieldName, &fields, &number, PH_NOISY, "phalcon/mvc/model/query.zep", 2959 TSRMLS_CC);
				if (automaticFields == 1) {
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeName);
						if (!(zephir_array_isset_fetch(&attributeName, &columnMap, &fieldName, 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_29$$29);
							object_init_ex(&_29$$29, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_30$$29);
							ZEPHIR_CONCAT_SVS(&_30$$29, "Column '", &fieldName, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_29$$29, "__construct", &_13, 4, &_30$$29);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_29$$29, "phalcon/mvc/model/query.zep", 2967 TSRMLS_CC);
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
			ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&number);
	ZEPHIR_CALL_METHOD(&insertModel, &manager, "load", NULL, 0, &modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &insertModel, "assign", NULL, 0, &insertValues);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZEPHIR_CALL_METHOD(&_31, &insertModel, "create", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 357, &_31, &insertModel);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Executes the UPDATE intermediate representation producing a Phalcon\Mvc\Model\Query\Status
 *
 * @param array bindParams
 * @param array bindTypes
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeUpdate) {

	zend_string *_5;
	zend_ulong _4;
	zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL, *_14 = NULL, *_16 = NULL, *_17 = NULL, *_19 = NULL, *_21 = NULL, *_27 = NULL, *_30 = NULL, *_32 = NULL, *_34 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate_param = NULL, *bindParams, bindParams_sub, *bindTypes, bindTypes_sub, models, modelName, model, connection, dialect, fields, values, updateValues, fieldName, value, selectBindParams, selectBindTypes, number, field, records, exprValue, updateValue, wildcard, record, _0, *_2, _3, _29, _35, _1$$4, _6$$5, _8$$10, _10$$10, _11$$10, _12$$13, _13$$13, _15$$15, _18$$16, _20$$21, _22$$21, _23$$21, _24$$24, _25$$24, _26$$26, _28$$27, _31$$28, _33$$29;
	zval intermediate;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_20$$21);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_24$$24);
	ZVAL_UNDEF(&_25$$24);
	ZVAL_UNDEF(&_26$$26);
	ZVAL_UNDEF(&_28$$27);
	ZVAL_UNDEF(&_31$$28);
	ZVAL_UNDEF(&_33$$29);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediate_param, &bindParams, &bindTypes);

	zephir_get_arrval(&intermediate, intermediate_param);


	ZEPHIR_OBS_VAR(&models);
	zephir_array_fetch_string(&models, &intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 3006 TSRMLS_CC);
	if (zephir_array_isset_long(&models, 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Updating several models at the same time is still not supported", "phalcon/mvc/model/query.zep", 3009);
		return;
	}
	ZEPHIR_OBS_VAR(&modelName);
	zephir_array_fetch_long(&modelName, &models, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 3012 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&model);
	zephir_read_property(&_0, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&model, &_0, &modelName, 0 TSRMLS_CC))) {
		zephir_read_property(&_1$$4, this_ptr, SL("_manager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&model, &_1$$4, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, &model, &intermediate, bindParams, bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&dialect, &connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&fields);
	zephir_array_fetch_string(&fields, &intermediate, SL("fields"), PH_NOISY, "phalcon/mvc/model/query.zep", 3025 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&values);
	zephir_array_fetch_string(&values, &intermediate, SL("values"), PH_NOISY, "phalcon/mvc/model/query.zep", 3026 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&updateValues);
	array_init(&updateValues);
	ZEPHIR_CPY_WRT(&selectBindParams, bindParams);
	ZEPHIR_CPY_WRT(&selectBindTypes, bindTypes);
	zephir_is_iterable(&fields, 0, "phalcon/mvc/model/query.zep", 3095);
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&number);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&number, _5);
			} else {
				ZVAL_LONG(&number, _4);
			}
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _2);
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch(&value, &values, &number, PH_NOISY, "phalcon/mvc/model/query.zep", 3041 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&exprValue);
			zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 3042 TSRMLS_CC);
			if (zephir_array_isset_string(&field, SL("balias"))) {
				ZEPHIR_OBS_NVAR(&fieldName);
				zephir_array_fetch_string(&fieldName, &field, SL("balias"), PH_NOISY, "phalcon/mvc/model/query.zep", 3045 TSRMLS_CC);
			} else {
				ZEPHIR_OBS_NVAR(&fieldName);
				zephir_array_fetch_string(&fieldName, &field, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 3047 TSRMLS_CC);
			}
			zephir_array_fetch_string(&_6$$5, &value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 3050 TSRMLS_CC);
			do {
				if (ZEPHIR_IS_LONG(&_6$$5, 260) || ZEPHIR_IS_LONG(&_6$$5, 258) || ZEPHIR_IS_LONG(&_6$$5, 259)) {
					ZEPHIR_CALL_METHOD(&updateValue, &dialect, "getsqlexpression", &_7, 0, &exprValue);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(&_6$$5, 322)) {
					ZEPHIR_INIT_NVAR(&updateValue);
					ZVAL_NULL(&updateValue);
					break;
				}
				if (ZEPHIR_IS_LONG(&_6$$5, 273) || ZEPHIR_IS_LONG(&_6$$5, 274) || ZEPHIR_IS_LONG(&_6$$5, 277)) {
					if (Z_TYPE_P(bindParams) != IS_ARRAY) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array", "phalcon/mvc/model/query.zep", 3067);
						return;
					}
					ZEPHIR_CALL_METHOD(&_8$$10, &dialect, "getsqlexpression", &_9, 0, &exprValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_10$$10);
					ZVAL_STRING(&_10$$10, ":");
					ZEPHIR_INIT_NVAR(&_11$$10);
					ZVAL_STRING(&_11$$10, "");
					ZEPHIR_INIT_NVAR(&wildcard);
					zephir_fast_str_replace(&wildcard, &_10$$10, &_11$$10, &_8$$10 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&updateValue);
					if (zephir_array_isset_fetch(&updateValue, bindParams, &wildcard, 0 TSRMLS_CC)) {
						zephir_array_unset(&selectBindParams, &wildcard, PH_SEPARATE);
						zephir_array_unset(&selectBindTypes, &wildcard, PH_SEPARATE);
					} else {
						ZEPHIR_INIT_NVAR(&_12$$13);
						object_init_ex(&_12$$13, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_13$$13);
						ZEPHIR_CONCAT_SVS(&_13$$13, "Bound parameter '", &wildcard, "' cannot be replaced because it's not in the placeholders list");
						ZEPHIR_CALL_METHOD(NULL, &_12$$13, "__construct", &_14, 4, &_13$$13);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_12$$13, "phalcon/mvc/model/query.zep", 3077 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					break;
				}
				if (ZEPHIR_IS_LONG(&_6$$5, 277)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not supported", "phalcon/mvc/model/query.zep", 3082);
					return;
				}
				ZEPHIR_INIT_NVAR(&updateValue);
				object_init_ex(&updateValue, phalcon_db_rawvalue_ce);
				ZEPHIR_CALL_METHOD(&_15$$15, &dialect, "getsqlexpression", &_16, 0, &exprValue);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &updateValue, "__construct", &_17, 17, &_15$$15);
				zephir_check_call_status();
				break;
			} while(0);

			zephir_array_update_zval(&updateValues, &fieldName, &updateValue, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &fields, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&number, &fields, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch(&value, &values, &number, PH_NOISY, "phalcon/mvc/model/query.zep", 3041 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&exprValue);
				zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 3042 TSRMLS_CC);
				if (zephir_array_isset_string(&field, SL("balias"))) {
					ZEPHIR_OBS_NVAR(&fieldName);
					zephir_array_fetch_string(&fieldName, &field, SL("balias"), PH_NOISY, "phalcon/mvc/model/query.zep", 3045 TSRMLS_CC);
				} else {
					ZEPHIR_OBS_NVAR(&fieldName);
					zephir_array_fetch_string(&fieldName, &field, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 3047 TSRMLS_CC);
				}
				zephir_array_fetch_string(&_18$$16, &value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 3050 TSRMLS_CC);
				do {
					if (ZEPHIR_IS_LONG(&_18$$16, 260) || ZEPHIR_IS_LONG(&_18$$16, 258) || ZEPHIR_IS_LONG(&_18$$16, 259)) {
						ZEPHIR_CALL_METHOD(&updateValue, &dialect, "getsqlexpression", &_19, 0, &exprValue);
						zephir_check_call_status();
						break;
					}
					if (ZEPHIR_IS_LONG(&_18$$16, 322)) {
						ZEPHIR_INIT_NVAR(&updateValue);
						ZVAL_NULL(&updateValue);
						break;
					}
					if (ZEPHIR_IS_LONG(&_18$$16, 273) || ZEPHIR_IS_LONG(&_18$$16, 274) || ZEPHIR_IS_LONG(&_18$$16, 277)) {
						if (Z_TYPE_P(bindParams) != IS_ARRAY) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array", "phalcon/mvc/model/query.zep", 3067);
							return;
						}
						ZEPHIR_CALL_METHOD(&_20$$21, &dialect, "getsqlexpression", &_21, 0, &exprValue);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_22$$21);
						ZVAL_STRING(&_22$$21, ":");
						ZEPHIR_INIT_NVAR(&_23$$21);
						ZVAL_STRING(&_23$$21, "");
						ZEPHIR_INIT_NVAR(&wildcard);
						zephir_fast_str_replace(&wildcard, &_22$$21, &_23$$21, &_20$$21 TSRMLS_CC);
						ZEPHIR_OBS_NVAR(&updateValue);
						if (zephir_array_isset_fetch(&updateValue, bindParams, &wildcard, 0 TSRMLS_CC)) {
							zephir_array_unset(&selectBindParams, &wildcard, PH_SEPARATE);
							zephir_array_unset(&selectBindTypes, &wildcard, PH_SEPARATE);
						} else {
							ZEPHIR_INIT_NVAR(&_24$$24);
							object_init_ex(&_24$$24, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_25$$24);
							ZEPHIR_CONCAT_SVS(&_25$$24, "Bound parameter '", &wildcard, "' cannot be replaced because it's not in the placeholders list");
							ZEPHIR_CALL_METHOD(NULL, &_24$$24, "__construct", &_14, 4, &_25$$24);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_24$$24, "phalcon/mvc/model/query.zep", 3077 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						break;
					}
					if (ZEPHIR_IS_LONG(&_18$$16, 277)) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not supported", "phalcon/mvc/model/query.zep", 3082);
						return;
					}
					ZEPHIR_INIT_NVAR(&updateValue);
					object_init_ex(&updateValue, phalcon_db_rawvalue_ce);
					ZEPHIR_CALL_METHOD(&_26$$26, &dialect, "getsqlexpression", &_27, 0, &exprValue);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &updateValue, "__construct", &_17, 17, &_26$$26);
					zephir_check_call_status();
					break;
				} while(0);

				zephir_array_update_zval(&updateValues, &fieldName, &updateValue, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	ZEPHIR_INIT_NVAR(&number);
	ZEPHIR_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", NULL, 358, &model, &intermediate, &selectBindParams, &selectBindTypes);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&records TSRMLS_CC))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		ZVAL_BOOL(&_28$$27, 1);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 357, &_28$$27);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, &model, &intermediate, bindParams, bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &connection, "begin", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &records, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_29, &records, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_29))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&record, &records, "current", &_30, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &record, "assign", NULL, 0, &updateValues);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_31$$28, &record, "update", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_31$$28))) {
			ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", &_32, 0);
			zephir_check_call_status();
			object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
			ZVAL_BOOL(&_33$$29, 0);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 357, &_33$$29, &record);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(NULL, &records, "next", &_34, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &connection, "commit", NULL, 0);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZVAL_BOOL(&_35, 1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 357, &_35);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Executes the DELETE intermediate representation producing a Phalcon\Mvc\Model\Query\Status
 *
 * @param array bindParams
 * @param array bindTypes
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeDelete) {

	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate_param = NULL, *bindParams, bindParams_sub, *bindTypes, bindTypes_sub, models, modelName, model, records, connection, record, _0, _3, _9, _1$$4, _2$$5, _5$$6, _7$$7;
	zval intermediate;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
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
	zephir_fetch_params(1, 3, 0, &intermediate_param, &bindParams, &bindTypes);

	zephir_get_arrval(&intermediate, intermediate_param);


	ZEPHIR_OBS_VAR(&models);
	zephir_array_fetch_string(&models, &intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 3154 TSRMLS_CC);
	if (zephir_array_isset_long(&models, 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Delete from several models at the same time is still not supported", "phalcon/mvc/model/query.zep", 3157);
		return;
	}
	ZEPHIR_OBS_VAR(&modelName);
	zephir_array_fetch_long(&modelName, &models, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 3160 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&model);
	zephir_read_property(&_0, this_ptr, SL("_modelsInstances"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&model, &_0, &modelName, 0 TSRMLS_CC))) {
		zephir_read_property(&_1$$4, this_ptr, SL("_manager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&model, &_1$$4, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", NULL, 358, &model, &intermediate, bindParams, bindTypes);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&records TSRMLS_CC))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		ZVAL_BOOL(&_2$$5, 1);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 357, &_2$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, &model, &intermediate, bindParams, bindTypes);
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
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 357, &_7$$7, &record);
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
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 357, &_9);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Query the records on which the UPDATE/DELETE operation well be done
 *
 * @param array bindParams
 * @param array bindTypes
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getRelatedRecords) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval intermediate, _0, _1;
	zval *model, model_sub, *intermediate_param = NULL, *bindParams, bindParams_sub, *bindTypes, bindTypes_sub, selectIr, whereConditions, limitConditions, query, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
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
	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &model, &intermediate_param, &bindParams, &bindTypes);

	zephir_get_arrval(&intermediate, intermediate_param);


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
	zephir_array_fetch_string(&_4, &intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 3239 TSRMLS_CC);
	zephir_array_update_string(&selectIr, SL("models"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_4);
	zephir_array_fetch_string(&_4, &intermediate, SL("tables"), PH_NOISY, "phalcon/mvc/model/query.zep", 3241 TSRMLS_CC);
	zephir_array_update_string(&selectIr, SL("tables"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&whereConditions);
	if (zephir_array_isset_string_fetch(&whereConditions, &intermediate, SL("where"), 0)) {
		zephir_array_update_string(&selectIr, SL("where"), &whereConditions, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&limitConditions);
	if (zephir_array_isset_string_fetch(&limitConditions, &intermediate, SL("limit"), 0)) {
		zephir_array_update_string(&selectIr, SL("limit"), &limitConditions, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&query);
	object_init_ex(&query, phalcon_mvc_model_query_ce);
	ZEPHIR_CALL_METHOD(NULL, &query, "__construct", NULL, 359);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &query, "setdi", NULL, 360, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_6, 309);
	ZEPHIR_CALL_METHOD(NULL, &query, "settype", NULL, 361, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &query, "setintermediate", NULL, 362, &selectIr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&query, "execute", NULL, 363, bindParams, bindTypes);
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid caching options", "phalcon/mvc/model/query.zep", 3287);
			return;
		}
		ZEPHIR_OBS_VAR(&key);
		if (!(zephir_array_isset_string_fetch(&key, &cacheOptions, SL("key"), 0))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A cache key must be provided to identify the cached resultset in the cache backend", "phalcon/mvc/model/query.zep", 3294);
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cache service must be an object", "phalcon/mvc/model/query.zep", 3313);
			return;
		}
		ZEPHIR_CALL_METHOD(&result, &cache, "get", NULL, 0, &key, &lifetime);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&result))) {
			if (Z_TYPE_P(&result) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cache didn't return a valid resultset", "phalcon/mvc/model/query.zep", 3320);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameters must be an array", "phalcon/mvc/model/query.zep", 3374);
		return;
	}
	_3 = Z_TYPE_P(&mergedTypes) != IS_NULL;
	if (_3) {
		_3 = Z_TYPE_P(&mergedTypes) != IS_ARRAY;
	}
	if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameter types must be an array", "phalcon/mvc/model/query.zep", 3378);
		return;
	}
	ZEPHIR_OBS_VAR(&type);
	zephir_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(&type, 309)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executeselect", NULL, 364, &intermediate, &mergedParams, &mergedTypes);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 306)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executeinsert", NULL, 365, &intermediate, &mergedParams, &mergedTypes);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 300)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executeupdate", NULL, 366, &intermediate, &mergedParams, &mergedTypes);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 303)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executedelete", NULL, 367, &intermediate, &mergedParams, &mergedTypes);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_VAR(&_4$$27);
		object_init_ex(&_4$$27, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$27);
		ZEPHIR_CONCAT_SV(&_5$$27, "Unknown statement ", &type);
		ZEPHIR_CALL_METHOD(NULL, &_4$$27, "__construct", NULL, 4, &_5$$27);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$27, "phalcon/mvc/model/query.zep", 3401 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	if (Z_TYPE_P(&cacheOptions) != IS_NULL) {
		if (!ZEPHIR_IS_LONG(&type, 309)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only PHQL statements that return resultsets can be cached", "phalcon/mvc/model/query.zep", 3413);
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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "execute", NULL, 363, bindParams, bindTypes);
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


	if (UNEXPECTED(merge)) {
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getIntermediate) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_intermediate");

}

/**
 * Sets the cache parameters of the query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, cache) {

	zval *cacheOptions_param = NULL;
	zval cacheOptions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cacheOptions);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cacheOptions_param);

	zephir_get_arrval(&cacheOptions, cacheOptions_param);


	zephir_update_property_zval(this_ptr, SL("_cacheOptions"), &cacheOptions);
	RETURN_THIS();

}

/**
 * Returns the current cache options
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
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_executeselect", NULL, 364, &intermediate, &_1$$3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "This type of statement generates multiple SQL statements", "phalcon/mvc/model/query.zep", 3584);
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "selectReadConnection did not return a connection", "phalcon/mvc/model/query.zep", 3611);
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "selectWriteConnection did not return a connection", "phalcon/mvc/model/query.zep", 3634);
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

zend_object *zephir_init_properties_Phalcon_Mvc_Model_Query(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_sqlColumnAliases"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_sqlColumnAliases"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

