
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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




}

/**
 * SQL statement related to the profile
 *
 * @var string
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getSqlStatement) {



}

/**
 * Timestamp when the profile started
 *
 * @var double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setInitialTime) {

	zval *initialTime;

	zephir_fetch_params(0, 1, 0, &initialTime);




}

/**
 * Timestamp when the profile started
 *
 * @var double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getInitialTime) {



}

/**
 * Timestamp when the profile ended
 *
 * @var double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setFinalTime) {

	zval *finalTime;

	zephir_fetch_params(0, 1, 0, &finalTime);




}

/**
 * Timestamp when the profile ended
 *
 * @var double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getFinalTime) {



}

/**
 * Returns the total time in seconds spent by the profile
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_finalTime"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_initialTime"), PH_NOISY_CC);
	sub_function(return_value, _0, _1 TSRMLS_CC);
	return;

}

