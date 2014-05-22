
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

#include "amf/message.h"

#include "kernel/main.h"
#include "kernel/object.h"

/**
 * Phalcon\Amf\Message
 *
 * content holder for an Amf Message.
 *
 */
zend_class_entry *phalcon_amf_message_ce;

PHP_METHOD(Phalcon_Amf_Message, __construct);
PHP_METHOD(Phalcon_Amf_Message, setTarget);
PHP_METHOD(Phalcon_Amf_Message, getTarget);
PHP_METHOD(Phalcon_Amf_Message, setResponse);
PHP_METHOD(Phalcon_Amf_Message, getResponse);
PHP_METHOD(Phalcon_Amf_Message, setData);
PHP_METHOD(Phalcon_Amf_Message, getData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_amf_message___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, response)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_amf_message_settarget, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_amf_message_setresponse, 0, 0, 1)
	ZEND_ARG_INFO(0, response)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_amf_message_setdata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_amf_message_method_entry[] = {
	PHP_ME(Phalcon_Amf_Message, __construct, arginfo_phalcon_amf_message___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Amf_Message, setTarget, arginfo_phalcon_amf_message_settarget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Message, getTarget, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Message, setResponse, arginfo_phalcon_amf_message_setresponse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Message, getResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Message, setData, arginfo_phalcon_amf_message_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Message, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Amf\Message initializer
 */
PHALCON_INIT_CLASS(Phalcon_Amf_Message){

	PHALCON_REGISTER_CLASS(Phalcon\\Amf, Message, amf_message, phalcon_amf_message_method_entry, 0);

	zend_declare_property_null(phalcon_amf_message_ce, SL("_target"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_message_ce, SL("_response"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_message_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Amf_Message, __construct){

	zval *target = NULL, *response = NULL, *data = NULL;

	phalcon_fetch_params(0, 0, 3, &target, &response, &data);

	if (target) {
		phalcon_update_property_this(this_ptr, SL("_target"), target TSRMLS_CC);
	}

	if (response) {
		phalcon_update_property_this(this_ptr, SL("_response"), response TSRMLS_CC);
	}

	if (data) {
		phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	}
}

PHP_METHOD(Phalcon_Amf_Message, setTarget){

	zval *target;

	phalcon_fetch_params(0, 1, 0, &target);

	phalcon_update_property_this(this_ptr, SL("_target"), target TSRMLS_CC);
}

PHP_METHOD(Phalcon_Amf_Message, getTarget){

	RETURN_MEMBER(this_ptr, "_target");
}

PHP_METHOD(Phalcon_Amf_Message, setResponse){

	zval *response;

	phalcon_fetch_params(0, 1, 0, &response);

	phalcon_update_property_this(this_ptr, SL("_response"), response TSRMLS_CC);
}

PHP_METHOD(Phalcon_Amf_Message, getResponse){

	RETURN_MEMBER(this_ptr, "_response");
}

PHP_METHOD(Phalcon_Amf_Message, setData){

	zval *data;

	phalcon_fetch_params(0, 1, 0, &data);

	phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
}

PHP_METHOD(Phalcon_Amf_Message, getData){

	RETURN_MEMBER(this_ptr, "_data");
}
