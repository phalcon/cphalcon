
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include "php.h"
#include "../php_ext.h"
#include "../ext.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"


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
 * Phalcon\Db\Result\Pdo
 *
 * Encapsulates the resultset internals
 *
 * <code>
 *	$result = connection->query("SELECT * FROM robots ORDER BY name");
 *	$result->setFetchMode(Phalcon\Db::FETCH_NUM);
 *	while ($robot = $result->fetchArray()) {
 *		print_r($robot);
 *	}
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Result_Pdo) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db\\Result, Pdo, phalcon, db_result_pdo, NULL, 0);

	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_connection"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_result"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Active fetch mode
 */
	zend_declare_property_long(phalcon_db_result_pdo_ce, SL("_fetchMode"), 4, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Internal resultset
 *
 * @var PDOStatement
 */
	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_pdoStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_sqlStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_bindParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_bindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_result_pdo_ce, SL("_rowCount"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

