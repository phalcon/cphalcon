
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

#include "amf/packet.h"

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/array.h"

/**
 * Phalcon\Amf\Packet
 *
 * content holder for an Amf Packet.
 *
 */
zend_class_entry *phalcon_amf_packet_ce;

PHP_METHOD(Phalcon_Amf_Packet, __construct);
PHP_METHOD(Phalcon_Amf_Packet, setVersion);
PHP_METHOD(Phalcon_Amf_Packet, getVersion);
PHP_METHOD(Phalcon_Amf_Packet, appendHeader);
PHP_METHOD(Phalcon_Amf_Packet, getHeaders);
PHP_METHOD(Phalcon_Amf_Packet, appendMessage);
PHP_METHOD(Phalcon_Amf_Packet, getMessage);
PHP_METHOD(Phalcon_Amf_Packet, getMessages);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_amf_packet_setversion, 0, 0, 1)
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_amf_packet_appendheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_amf_packet_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_amf_packet_method_entry[] = {
	PHP_ME(Phalcon_Amf_Packet, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Amf_Packet, setVersion, arginfo_phalcon_amf_packet_setversion, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Packet, getVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Packet, appendHeader, arginfo_phalcon_amf_packet_appendheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Packet, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Packet, appendMessage, arginfo_phalcon_amf_packet_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Packet, getMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Packet, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Amf\Packet initializer
 */
PHALCON_INIT_CLASS(Phalcon_Amf_Packet){

	PHALCON_REGISTER_CLASS(Phalcon\\Amf, Packet, amf_packet, phalcon_amf_packet_method_entry, 0);

	zend_declare_property_null(phalcon_amf_packet_ce, SL("_headers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_packet_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_amf_packet_ce, SL("_version"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Amf_Packet, __construct){

	zval *headers, *messages;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(headers);
	array_init(headers);

	PHALCON_INIT_VAR(messages);
	array_init(messages); 

	phalcon_update_property_this(this_ptr, SL("_headers"), headers TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_messages"), messages TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Amf_Packet, setVersion){

	zval *version;

	phalcon_fetch_params(0, 1, 0, &version);

	phalcon_update_property_this(this_ptr, SL("_version"), version TSRMLS_CC);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Amf_Packet, getVersion){

	RETURN_MEMBER(this_ptr, "_version");
}

PHP_METHOD(Phalcon_Amf_Packet, appendHeader){

	zval *header;

	phalcon_fetch_params(0, 1, 0, &header);

	phalcon_update_property_array_append(this_ptr, SL("_headers"), header TSRMLS_CC);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Amf_Packet, getHeaders){

	RETURN_MEMBER(this_ptr, "_headers");
}

PHP_METHOD(Phalcon_Amf_Packet, appendMessage){

	zval *message;

	phalcon_fetch_params(0, 1, 0, &message);

	phalcon_update_property_array_append(this_ptr, SL("_messages"), message TSRMLS_CC);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Amf_Packet, getMessage){

	zval *postion, *messages, *message;

	phalcon_fetch_params(0, 1, 0, &postion);

	messages = phalcon_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY TSRMLS_CC);

	if (phalcon_array_isset_fetch(&message, messages, postion)) {
		RETURN_CCTORW(message);
	}

	RETURN_NULL();
}


PHP_METHOD(Phalcon_Amf_Packet, getMessages){

	RETURN_MEMBER(this_ptr, "_messages");
}
