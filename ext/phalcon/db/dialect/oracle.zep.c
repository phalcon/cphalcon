
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


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\Db\Dialect\Oracle
 *
 * Generates database specific SQL for the Oracle RBDM
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Oracle) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Oracle, phalcon, db_dialect_oracle, phalcon_db_dialect_ce, NULL, 0);

	zend_declare_property_string(phalcon_db_dialect_oracle_ce, SL("_escapeChar"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

