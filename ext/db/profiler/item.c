
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

#include "db/profiler/item.h"
#include "kernel/main.h"
#include "kernel/object.h"

/**
 * Phalcon\Db\Profiler\Item
 *
 * This class identifies each profile in a Phalcon\Db\Profiler
 *
 */
zend_class_entry *phalcon_db_profiler_item_ce;

PHP_METHOD(Phalcon_Db_Profiler_Item, setSQLStatement);
PHP_METHOD(Phalcon_Db_Profiler_Item, getSQLStatement);
PHP_METHOD(Phalcon_Db_Profiler_Item, setSQLVariables);
PHP_METHOD(Phalcon_Db_Profiler_Item, getSQLVariables);
PHP_METHOD(Phalcon_Db_Profiler_Item, setSQLBindTypes);
PHP_METHOD(Phalcon_Db_Profiler_Item, getSQLBindTypes);
PHP_METHOD(Phalcon_Db_Profiler_Item, setInitialTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, setFinalTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, getInitialTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, getFinalTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setsqlstatement, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setsqlvariables, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlVariables)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setsqlbindtypes, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlBindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setinitialtime, 0, 0, 1)
	ZEND_ARG_INFO(0, initialTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setfinaltime, 0, 0, 1)
	ZEND_ARG_INFO(0, finalTime)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_db_profiler_item_method_entry[] = {
	PHP_ME(Phalcon_Db_Profiler_Item, setSQLStatement, arginfo_phalcon_db_profiler_item_setsqlstatement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getSQLStatement, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, setSQLVariables, arginfo_phalcon_db_profiler_item_setsqlvariables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getSQLVariables, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, setSQLBindTypes, arginfo_phalcon_db_profiler_item_setsqlbindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getSQLBindTypes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, setInitialTime, arginfo_phalcon_db_profiler_item_setinitialtime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, setFinalTime, arginfo_phalcon_db_profiler_item_setfinaltime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getInitialTime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getFinalTime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Db\Profiler\Item initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Profiler_Item){

	PHALCON_REGISTER_CLASS(Phalcon\\Db\\Profiler, Item, db_profiler_item, phalcon_db_profiler_item_method_entry, 0);

	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_sqlStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_sqlVariables"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_sqlBindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_initialTime"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_finalTime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Sets the SQL statement related to the profile
 *
 * @param string $sqlStatement
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setSQLStatement){

	zval *sql_statement;

	phalcon_fetch_params(0, 1, 0, &sql_statement);
	
	phalcon_update_property_this(this_ptr, SL("_sqlStatement"), sql_statement TSRMLS_CC);
	
}

/**
 * Returns the SQL statement related to the profile
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getSQLStatement){


	RETURN_MEMBER(this_ptr, "_sqlStatement");
}

/**
 * Sets the SQL variables related to the profile
 *
 * @param array $sqlParams
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setSQLVariables){

	zval *sql_variables;

	phalcon_fetch_params(0, 1, 0, &sql_variables);
	
	phalcon_update_property_this(this_ptr, SL("_sqlVariables"), sql_variables TSRMLS_CC);
	
}

/**
 * Returns the SQL variables related to the profile
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getSQLVariables){


	RETURN_MEMBER(this_ptr, "_sqlVariables");
}

/**
 * Sets the SQL bind types related to the profile
 *
 * @param array $sqlParams
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setSQLBindTypes){

	zval *sql_bindtypes;

	phalcon_fetch_params(0, 1, 0, &sql_bindtypes);

	phalcon_update_property_this(this_ptr, SL("_sqlBindTypes"), sql_bindtypes TSRMLS_CC);

}

/**
 * Returns the SQL bind types related to the profile
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getSQLBindTypes){


	RETURN_MEMBER(this_ptr, "_sqlBindTypes");
}

/**
 * Sets the timestamp on when the profile started
 *
 * @param int $initialTime
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setInitialTime){

	zval *initial_time;

	phalcon_fetch_params(0, 1, 0, &initial_time);
	
	phalcon_update_property_this(this_ptr, SL("_initialTime"), initial_time TSRMLS_CC);
	
}

/**
 * Sets the timestamp on when the profile ended
 *
 * @param int $finalTime
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setFinalTime){

	zval *final_time;

	phalcon_fetch_params(0, 1, 0, &final_time);
	
	phalcon_update_property_this(this_ptr, SL("_finalTime"), final_time TSRMLS_CC);
	
}

/**
 * Returns the initial time in milseconds on when the profile started
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getInitialTime){


	RETURN_MEMBER(this_ptr, "_initialTime");
}

/**
 * Returns the initial time in milseconds on when the profile ended
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getFinalTime){


	RETURN_MEMBER(this_ptr, "_finalTime");
}

/**
 * Returns the total time in seconds spent by the profile
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds){

	zval *final_time, *initial_time;

	final_time   = phalcon_fetch_nproperty_this(this_ptr, SL("_finalTime"), PH_NOISY TSRMLS_CC);
	initial_time = phalcon_fetch_nproperty_this(this_ptr, SL("_initialTime"), PH_NOISY TSRMLS_CC);
	sub_function(return_value, final_time, initial_time TSRMLS_CC);
}
