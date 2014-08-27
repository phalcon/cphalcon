
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

#include "amf/header.h"

#include "kernel/main.h"
#include "kernel/object.h"

/**
 * Phalcon\Amf\Header
 *
 * content holder for an Amf Header.
 *
 */
zend_class_entry *phalcon_amf_header_ce;

PHP_METHOD(Phalcon_Amf_Header, __construct);
PHP_METHOD(Phalcon_Amf_Header, getName);
PHP_METHOD(Phalcon_Amf_Header, getRequired);
PHP_METHOD(Phalcon_Amf_Header, getData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_amf_header___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_amf_header_method_entry[] = {
	PHP_ME(Phalcon_Amf_Header, __construct, arginfo_phalcon_amf_header___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Amf_Header, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Header, getRequired, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Header, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Amf\Header initializer
 */
PHALCON_INIT_CLASS(Phalcon_Amf_Header){

	PHALCON_REGISTER_CLASS(Phalcon\\Amf, Header, amf_header, phalcon_amf_header_method_entry, 0);

	zend_declare_property_null(phalcon_amf_header_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_amf_header_ce, SL("_required"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_header_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Amf_Header, __construct){

	zval *name, *required, *data;

	phalcon_fetch_params(0, 3, 0, &name, &required, &data);

	phalcon_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_required"), required TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
}

PHP_METHOD(Phalcon_Amf_Header, getName){

	RETURN_MEMBER(this_ptr, "_name");
}

PHP_METHOD(Phalcon_Amf_Header, getRequired){

	RETURN_MEMBER(this_ptr, "_required");
}

PHP_METHOD(Phalcon_Amf_Header, getData){

	RETURN_MEMBER(this_ptr, "_data");
}
