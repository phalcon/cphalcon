
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


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
 * Phalcon\Db
 *
 * Phalcon\Db and its related classes provide a simple SQL database interface for Phalcon Framework.
 * The Phalcon\Db is the basic class you use to connect your PHP application to an RDBMS.
 * There is a different adapter class for each brand of RDBMS.
 *
 * This component is intended to lower level database operations. If you want to interact with databases using
 * higher level of abstraction use Phalcon\Mvc\Model.
 *
 * Phalcon\Db is an abstract class. You only can use it with a database adapter like Phalcon\Db\Adapter\Pdo
 *
 * <code>
 *
 *try {
 *
 *  $connection = new Phalcon\Db\Adapter\Pdo\Mysql(array(
 *     'host' => '192.168.0.11',
 *     'username' => 'sigma',
 *     'password' => 'secret',
 *     'dbname' => 'blog',
 *     'port' => '3306',
 *  ));
 *
 *  $result = $connection->query("SELECT * FROM robots LIMIT 5");
 *  $result->setFetchMode(Phalcon\Db::FETCH_NUM);
 *  while ($robot = $result->fetch()) {
 *    print_r($robot);
 *  }
 *
 *} catch (Phalcon\Db\Exception $e) {
 *	echo $e->getMessage(), PHP_EOL;
 *}
 *
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Db, phalcon, db, phalcon_db_method_entry, 0);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_ASSOC"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_BOTH"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_NUM"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_OBJ"), 4 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Enables/disables options in the Database component
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Db, setup) {

	zval *options, *escapeIdentifiers, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options);



	if ((Z_TYPE_P(options) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Options must be an array");
		return;
	}
	if (zephir_array_isset_string_fetch(&escapeIdentifiers, options, SS("escapeSqlIdentifiers"), 1 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "db.escape_identifiers", 1);
		zephir_call_func_p2_noret("globals_set", _0, escapeIdentifiers);
	}
	ZEPHIR_MM_RESTORE();

}

