
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

#include "db/rawvalue.h"
#include "kernel/main.h"
#include "kernel/object.h"

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
 *	$subscriber->created_at = new Phalcon\Db\RawValue('now()');
 *	$subscriber->save();
 *</code>
 */
zend_class_entry *phalcon_db_rawvalue_ce;

PHP_METHOD(Phalcon_Db_RawValue, __construct);
PHP_METHOD(Phalcon_Db_RawValue, getValue);
PHP_METHOD(Phalcon_Db_RawValue, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_rawvalue___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_db_rawvalue_method_entry[] = {
	PHP_ME(Phalcon_Db_RawValue, __construct, arginfo_phalcon_db_rawvalue___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_RawValue, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_RawValue, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Db\RawValue initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_RawValue){

	PHALCON_REGISTER_CLASS(Phalcon\\Db, RawValue, db_rawvalue, phalcon_db_rawvalue_method_entry, 0);

	zend_declare_property_null(phalcon_db_rawvalue_ce, SL("_value"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Db\RawValue constructor
 *
 * @param string $value
 */
PHP_METHOD(Phalcon_Db_RawValue, __construct){

	zval *value;

	phalcon_fetch_params(0, 1, 0, &value);
	
	phalcon_update_property_this(this_ptr, SL("_value"), value TSRMLS_CC);
	
}

/**
 * Returns internal raw value without quoting or formating
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_RawValue, getValue){


	RETURN_MEMBER(this_ptr, "_value");
}

/**
 * Magic method __toString returns raw value without quoting or formating
 */
PHP_METHOD(Phalcon_Db_RawValue, __toString){


	RETURN_MEMBER(this_ptr, "_value");
}
