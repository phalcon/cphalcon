
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


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
 * Phalcon\Db\RawValue
 *
 * This class allows to insert/update raw data without quoting or formating.
 *
 *The next example shows how to use the MySQL now() function as a field value.
 *
 *<code>
 *	$subscriber = new Subscribers();
 *	$subscriber->email = 'andres@phalconphp.com';
 *	$subscriber->createdAt = new Phalcon\Db\RawValue('now()');
 *	$subscriber->save();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_RawValue) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, RawValue, phalcon, db_rawvalue, phalcon_db_rawvalue_method_entry, 0);

/**
	 * Raw value without quoting or formating
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_rawvalue_ce, SL("_value"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Raw value without quoting or formating
 *
 * @var string
 */
PHP_METHOD(Phalcon_Db_RawValue, getValue) {



}

/**
 * Raw value without quoting or formating
 *
 * @var string
 */
PHP_METHOD(Phalcon_Db_RawValue, __toString) {



}

/**
 * Phalcon\Db\RawValue constructor
 *
 * @param string value
 */
PHP_METHOD(Phalcon_Db_RawValue, __construct) {

	zval *value_param = NULL;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

		zephir_get_strval(value, value_param);


	zephir_update_property_this(this_ptr, SL("_value"), value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

