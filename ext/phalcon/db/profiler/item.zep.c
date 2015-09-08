
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
 * Phalcon\Db\Profiler\Item
 *
 * This class identifies each profile in a Phalcon\Db\Profiler
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Profiler_Item) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db\\Profiler, Item, phalcon, db_profiler_item, phalcon_db_profiler_item_method_entry, 0);

	/**
	 * SQL statement related to the profile
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_sqlStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * SQL variables related to the profile
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_sqlVariables"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * SQL bind types related to the profile
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_sqlBindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Timestamp when the profile started
	 *
	 * @var double
	 */
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_initialTime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Timestamp when the profile ended
	 *
	 * @var double
	 */
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_finalTime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * SQL statement related to the profile
 *
 * @var string
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setSqlStatement) {

	zval *sqlStatement;

	zephir_fetch_params(0, 1, 0, &sqlStatement);



	zephir_update_property_this(this_ptr, SL("_sqlStatement"), sqlStatement TSRMLS_CC);

}

/**
 * SQL statement related to the profile
 *
 * @var string
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getSqlStatement) {


	RETURN_MEMBER(this_ptr, "_sqlStatement");

}

/**
 * SQL variables related to the profile
 *
 * @var array
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setSqlVariables) {

	zval *sqlVariables;

	zephir_fetch_params(0, 1, 0, &sqlVariables);



	zephir_update_property_this(this_ptr, SL("_sqlVariables"), sqlVariables TSRMLS_CC);

}

/**
 * SQL variables related to the profile
 *
 * @var array
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getSqlVariables) {


	RETURN_MEMBER(this_ptr, "_sqlVariables");

}

/**
 * SQL bind types related to the profile
 *
 * @var array
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setSqlBindTypes) {

	zval *sqlBindTypes;

	zephir_fetch_params(0, 1, 0, &sqlBindTypes);



	zephir_update_property_this(this_ptr, SL("_sqlBindTypes"), sqlBindTypes TSRMLS_CC);

}

/**
 * SQL bind types related to the profile
 *
 * @var array
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getSqlBindTypes) {


	RETURN_MEMBER(this_ptr, "_sqlBindTypes");

}

/**
 * Timestamp when the profile started
 *
 * @var double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setInitialTime) {

	zval *initialTime;

	zephir_fetch_params(0, 1, 0, &initialTime);



	zephir_update_property_this(this_ptr, SL("_initialTime"), initialTime TSRMLS_CC);

}

/**
 * Timestamp when the profile started
 *
 * @var double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getInitialTime) {


	RETURN_MEMBER(this_ptr, "_initialTime");

}

/**
 * Timestamp when the profile ended
 *
 * @var double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setFinalTime) {

	zval *finalTime;

	zephir_fetch_params(0, 1, 0, &finalTime);



	zephir_update_property_this(this_ptr, SL("_finalTime"), finalTime TSRMLS_CC);

}

/**
 * Timestamp when the profile ended
 *
 * @var double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getFinalTime) {


	RETURN_MEMBER(this_ptr, "_finalTime");

}

/**
 * Returns the total time in seconds spent by the profile
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_finalTime"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_initialTime"), PH_NOISY_CC);
	sub_function(return_value, _0, _1 TSRMLS_CC);
	return;

}

