/*
  +------------------------------------------------------------------------+
  | Phalcon Framework									  |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)	   |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled	 |
  | with this package in the file docs/LICENSE.txt.				|
  |												|
  | If you did not receive a copy of the license and are unable to		 |
  | obtain it through the world-wide-web, please send an email		 |
  | to license@phalconphp.com so we can send you a copy immediately.	   |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>				  |
  |		  Eduar Carvajal <eduar@phalconphp.com>				 |
  |		  Nikolaos Dimopoulos <nikos@phalconphp.com>				|
  +------------------------------------------------------------------------+
*/

#include "amf.h"
#include "amf/serializer.h"
#include "amf/header.h"
#include "amf/message.h"
#include "amf/packet.h"
#include "amf/exception.h"

#include "ext/standard/php_smart_str.h"

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Amf
 *
 * Phalcon\Amf is designed to simplify building of HTML amfs.
 * It provides a set of helpers to generate HTML in a dynamic way.
 * This component is an abstract class that you can extend to add more helpers.
 */
zend_class_entry *phalcon_amf_serializer_ce;

PHP_METHOD(Phalcon_Amf_Serializer, __construct);
PHP_METHOD(Phalcon_Amf_Serializer, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_amf_serializer___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO();

static const zend_function_entry phalcon_amf_serializer_method_entry[] = {
	PHP_ME(Phalcon_Amf_Serializer, __construct, arginfo_phalcon_amf_serializer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Amf_Serializer, render, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Amf\Serializer initializer
 */
PHALCON_INIT_CLASS(Phalcon_Amf_Serializer){

	PHALCON_REGISTER_CLASS(Phalcon\\Amf, Serializer, amf_serializer, phalcon_amf_serializer_method_entry, 0);

	zend_declare_class_constant_long(phalcon_image_ce, SL("MAX_STORED_OBJECTS"), PHALCON_AMF_MAX_STORED_OBJECTS TSRMLS_CC);

	zend_declare_property_null(phalcon_amf_serializer_ce, SL("_outBuffer"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_serializer_ce, SL("_packet"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_serializer_ce, SL("_storedObjects"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_serializer_ce, SL("_storedStrings"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_serializer_ce, SL("_className2TraitsInfo"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_serializer_ce, SL("_voConverter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon_Amf_Serializer constructor
 *
 * @param string $file
 */
PHP_METHOD(Phalcon_Amf_Serializer, __construct){

	zval *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &data);

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Amf_Serializer, render){

}
