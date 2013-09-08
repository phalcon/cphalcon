
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

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
 |          Marcio Paiva <mpaivabarbosa@gmail.com>                        |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Db\Adapter\Pdo\Oracle
 *
 * Specific functions for the Oracle database system
 * <code>
 *
 * $config = array(
 *  "dbname" => "//localhost/dbname",
 *  "username" => "oracle",
 *  "password" => "oracle"
 * );
 *
 * $connection = new Phalcon\Db\Adapter\Pdo\Oracle($config);
 *
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Oracle) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, phalcon, Oracle, db_adapter_pdo_oracle, phalcon_db_adapter_pdo_ce, NULL, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_oracle_ce, SL("_type"), "oci", ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_string(phalcon_db_adapter_pdo_oracle_ce, SL("_dialectType"), "oracle", ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

