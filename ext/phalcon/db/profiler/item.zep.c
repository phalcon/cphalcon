
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This class identifies each profile in a Phalcon\Db\Profiler
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Profiler_Item) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db\\Profiler, Item, phalcon, db_profiler_item, phalcon_db_profiler_item_method_entry, 0);

	/**
	 * Timestamp when the profile ended
	 *
	 * @var double
	 */
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("finalTime"), ZEND_ACC_PROTECTED);

	/**
	 * Timestamp when the profile started
	 *
	 * @var double
	 */
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("initialTime"), ZEND_ACC_PROTECTED);

	/**
	 * SQL bind types related to the profile
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("sqlBindTypes"), ZEND_ACC_PROTECTED);

	/**
	 * SQL statement related to the profile
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("sqlStatement"), ZEND_ACC_PROTECTED);

	/**
	 * SQL variables related to the profile
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("sqlVariables"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Timestamp when the profile ended
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setFinalTime) {

	zval *finalTime_param = NULL, _0;
	double finalTime;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(finalTime)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &finalTime_param);

	finalTime = zephir_get_doubleval(finalTime_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(&_0, finalTime);
	zephir_update_property_zval(this_ptr, ZEND_STRL("finalTime"), &_0);
	RETURN_THISW();

}

/**
 * Timestamp when the profile ended
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getFinalTime) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "finalTime");

}

/**
 * Timestamp when the profile started
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setInitialTime) {

	zval *initialTime_param = NULL, _0;
	double initialTime;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(initialTime)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &initialTime_param);

	initialTime = zephir_get_doubleval(initialTime_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(&_0, initialTime);
	zephir_update_property_zval(this_ptr, ZEND_STRL("initialTime"), &_0);
	RETURN_THISW();

}

/**
 * Timestamp when the profile started
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getInitialTime) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "initialTime");

}

/**
 * SQL bind types related to the profile
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setSqlBindTypes) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sqlBindTypes_param = NULL;
	zval sqlBindTypes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlBindTypes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(sqlBindTypes)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlBindTypes_param);

	zephir_get_arrval(&sqlBindTypes, sqlBindTypes_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("sqlBindTypes"), &sqlBindTypes);
	RETURN_THIS();

}

/**
 * SQL bind types related to the profile
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getSqlBindTypes) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "sqlBindTypes");

}

/**
 * SQL statement related to the profile
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setSqlStatement) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sqlStatement_param = NULL;
	zval sqlStatement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlStatement);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(sqlStatement)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlStatement_param);

	zephir_get_strval(&sqlStatement, sqlStatement_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("sqlStatement"), &sqlStatement);
	RETURN_THIS();

}

/**
 * SQL statement related to the profile
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getSqlStatement) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "sqlStatement");

}

/**
 * SQL variables related to the profile
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setSqlVariables) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sqlVariables_param = NULL;
	zval sqlVariables;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlVariables);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(sqlVariables)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlVariables_param);

	zephir_get_arrval(&sqlVariables, sqlVariables_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("sqlVariables"), &sqlVariables);
	RETURN_THIS();

}

/**
 * SQL variables related to the profile
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getSqlVariables) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "sqlVariables");

}

/**
 * Returns the total time in seconds spent by the profile
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("finalTime"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("initialTime"), PH_NOISY_CC | PH_READONLY);
	zephir_sub_function(return_value, &_0, &_1);
	return;

}

