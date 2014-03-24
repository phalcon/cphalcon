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
	ZEND_ARG_INFO(0, message)
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

	zend_declare_class_constant_long(phalcon_amf_serializer_ce, SL("MAX_STORED_OBJECTS"), PHALCON_AMF3_MAX_STORED_OBJECTS TSRMLS_CC);

	zend_declare_property_null(phalcon_amf_serializer_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_serializer_ce, SL("_rawData"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_serializer_ce, SL("_outBuffer"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_serializer_ce, SL("_packet"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_serializer_ce, SL("_storedObjects"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_serializer_ce, SL("_storedStrings"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_serializer_ce, SL("_className2TraitsInfo"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_serializer_ce, SL("_voConverter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

static int big_endian_short_map[2];
static int little_endian_short_map[2];
static int big_endian_long_map[4];
static int little_endian_long_map[4];

static void phalcon_amf3_pack(smart_str *buf, zval **val, int size, int *map)
{
	int i;
	char *v;

	convert_to_long_ex(val);
	v = (char *) &Z_LVAL_PP(val);

	for (i = 0; i < size; i++) {
		smart_str_appendc(buf, v[big_endian_short_map[i]]);
	}
}

/**
 * Phalcon_Amf_Serializer constructor
 *
 * @param string $file
 */
PHP_METHOD(Phalcon_Amf_Serializer, __construct){

	zval *message, *rawdata;
	zval *target = NULL, *response = NULL, *data = NULL, *tmp = NULL;
	zval *val = NULL;
	smart_str buf = { 0 };
	char machine_little_endian;
	int machine_endian_check = 1;
	int size = 4;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);

	phalcon_update_property_this(this_ptr, SL("_message"), message TSRMLS_CC);

	machine_little_endian = ((char *)&machine_endian_check)[0];

	if (machine_little_endian) {
		big_endian_short_map[0] = 1;
		big_endian_short_map[1] = 0;
		little_endian_short_map[0] = 0;
		little_endian_short_map[1] = 1;

		big_endian_long_map[0] = 3;
		big_endian_long_map[1] = 2;
		big_endian_long_map[2] = 1;
		big_endian_long_map[3] = 0;
		little_endian_long_map[0] = 0;
		little_endian_long_map[1] = 1;
		little_endian_long_map[2] = 2;
		little_endian_long_map[3] = 3;
	} else {
		size = sizeof(Z_LVAL_P(val));
		
		big_endian_short_map[0] = size - 2;
		big_endian_short_map[1] = size - 1;
		little_endian_short_map[0] = size - 1;
		little_endian_short_map[1] = size - 2;

		big_endian_long_map[0] = size - 4;
		big_endian_long_map[1] = size - 3;
		big_endian_long_map[2] = size - 2;
		big_endian_long_map[3] = size - 1;
		little_endian_long_map[0] = size - 1;
		little_endian_long_map[1] = size - 2;
		little_endian_long_map[2] = size - 3;
		little_endian_long_map[3] = size - 4;
	}

	PHALCON_INIT_NVAR(val);
	ZVAL_LONG(val, 0);

	/* write the version (always 0) */
	phalcon_amf3_pack(&buf, &val, 2, big_endian_short_map);

	/* write header count */
	phalcon_amf3_pack(&buf, &val, 2, big_endian_short_map);

	/* write message count */
	PHALCON_INIT_NVAR(val);
	ZVAL_LONG(val, 1);
	phalcon_amf3_pack(&buf, &val, 2, big_endian_short_map);

	PHALCON_CALL_METHOD(&target, message, "gettarget");
	PHALCON_CALL_METHOD(&response, message, "getresponse");
	PHALCON_CALL_METHOD(&data, message, "getdata");

	// write target count */
	PHALCON_INIT_NVAR(val);
	ZVAL_LONG(val, Z_STRLEN_P(target));

	phalcon_amf3_pack(&buf, &val, 2, big_endian_short_map);

	// write target */
	smart_str_appendl(&buf, Z_STRVAL_P(target), Z_STRLEN_P(target));

	// write response count */
	PHALCON_INIT_NVAR(val);
	ZVAL_LONG(val, Z_STRLEN_P(response));

	phalcon_amf3_pack(&buf, &val, 2, big_endian_short_map);

	// write response */
	smart_str_appendl(&buf, Z_STRVAL_P(response), Z_STRLEN_P(response));

	PHALCON_CALL_CE_STATIC(&tmp, phalcon_amf_ce, "encode", data);

	// write data length + 1 */
	PHALCON_INIT_NVAR(val);
	ZVAL_LONG(val, Z_STRLEN_P(tmp)+1);

	phalcon_amf3_pack(&buf, &val, 4, big_endian_long_map);

	/* write AMF3 flag */
	smart_str_appendc(&buf, 0x11);
	
	smart_str_appendl(&buf, Z_STRVAL_P(tmp), Z_STRLEN_P(tmp));

	PHALCON_INIT_VAR(rawdata);
	ZVAL_STRINGL(rawdata, buf.c, buf.len, 1);
	smart_str_free(&buf);

	phalcon_update_property_this(this_ptr, SL("_rawData"), rawdata TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Amf_Serializer, render){
	RETURN_MEMBER(this_ptr, "_rawData");
}
