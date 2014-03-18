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

#include "amf/deserializer.h"
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
zend_class_entry *phalcon_amf_deserializer_ce;

PHP_METHOD(Phalcon_Amf_Deserializer, __construct);
PHP_METHOD(Phalcon_Amf_Deserializer, getPacket);
PHP_METHOD(Phalcon_Amf_Deserializer, readByte);
PHP_METHOD(Phalcon_Amf_Deserializer, readBuffer);
PHP_METHOD(Phalcon_Amf_Deserializer, seek);
PHP_METHOD(Phalcon_Amf_Deserializer, readBool);
PHP_METHOD(Phalcon_Amf_Deserializer, readInt);
PHP_METHOD(Phalcon_Amf_Deserializer, readDouble);
PHP_METHOD(Phalcon_Amf_Deserializer, readLong);
PHP_METHOD(Phalcon_Amf_Deserializer, readUTF);
PHP_METHOD(Phalcon_Amf_Deserializer, readLongUTF);
PHP_METHOD(Phalcon_Amf_Deserializer, readObject);
PHP_METHOD(Phalcon_Amf_Deserializer, readArray);
PHP_METHOD(Phalcon_Amf_Deserializer, readCustomClass);
PHP_METHOD(Phalcon_Amf_Deserializer, readData);
PHP_METHOD(Phalcon_Amf_Deserializer, readAmf3Int);
PHP_METHOD(Phalcon_Amf_Deserializer, readAmf3String);
PHP_METHOD(Phalcon_Amf_Deserializer, readAmf3Array);
PHP_METHOD(Phalcon_Amf_Deserializer, readAmf3Object);
PHP_METHOD(Phalcon_Amf_Deserializer, readAmf3Data);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_amf_deserializer___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_amf_deserializer_readbuffer, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_amf_deserializer_method_entry[] = {
	PHP_ME(Phalcon_Amf_Deserializer, __construct, arginfo_phalcon_amf_deserializer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Amf_Deserializer, getPacket, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readByte, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readBuffer, arginfo_phalcon_amf_deserializer_readbuffer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, seek, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readBool, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readInt, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readDouble, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readLong, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readUTF, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readLongUTF, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readObject, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readCustomClass, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readAmf3Int, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readAmf3String, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readAmf3Array, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readAmf3Object, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Amf_Deserializer, readAmf3Data, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Amf\Deserializer initializer
 */
PHALCON_INIT_CLASS(Phalcon_Amf_Deserializer){

	PHALCON_REGISTER_CLASS(Phalcon\\Amf, Deserializer, amf_deserializer, phalcon_amf_deserializer_method_entry, 0);

	zend_declare_property_null(phalcon_amf_deserializer_ce, SL("_rawData"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_amf_deserializer_ce, SL("_rawSize"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_amf_deserializer_ce, SL("_rawPos"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_deserializer_ce, SL("_packet"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_deserializer_ce, SL("_storedStrings"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_deserializer_ce, SL("_storedArrays"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_amf_deserializer_ce, SL("_storedObjects"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon_Amf_Deserializer constructor
 *
 * @param string $file
 */
PHP_METHOD(Phalcon_Amf_Deserializer, __construct){

	zval *rawdata, *option;
	zval *packet, *firstByte = NULL, *secondByte = NULL, *elements = NULL;
	zval *name = NULL, *required = NULL, *type = NULL, *data = NULL, *header = NULL;
	zval *target = NULL, *response = NULL, *message = NULL;
	zval *seeknum;
	int size = 0, first, second, num;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &rawdata);

	size = Z_STRLEN_P(rawdata);

	phalcon_update_property_this(this_ptr, SL("_rawData"), rawdata TSRMLS_CC);
	phalcon_update_property_long(this_ptr, SL("_rawSize"), size TSRMLS_CC);

	PHALCON_INIT_VAR(packet);
	object_init_ex(packet, phalcon_amf_packet_ce);
	PHALCON_CALL_METHOD(NULL, packet, "__construct");

	PHALCON_CALL_SELF(&firstByte, "readbyte");
	PHALCON_CALL_SELF(&secondByte, "readbyte");

	first = phalcon_get_intval(firstByte);
	second = phalcon_get_intval(secondByte);

	if (first != 0 && first != 3) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_amf_exception_ce, "Malformed Amf Packet, connection may have dropped");
		return;
	}

	if (second == 3) {
		PHALCON_CALL_METHOD(NULL, packet, "setversion", secondByte);
	}

	PHALCON_INIT_VAR(seeknum);
	ZVAL_LONG(seeknum, 4);

	// parse header
	PHALCON_CALL_SELF(&elements, "readint"); //  find the total number of header elements
	num = phalcon_get_intval(elements);
	while (num--) { // loop over all of the header elements
		PHALCON_CALL_SELF(&name, "readutf");
		PHALCON_CALL_SELF(&required, "readbyte"); // find the must understand flag
		PHALCON_CALL_SELF(NULL, "seek", seeknum); // grab the length of the header element
		PHALCON_CALL_SELF(&type, "readbyte"); // grab the type of the element
		PHALCON_CALL_SELF(&data, "readdata", type); // turn the element into real data

		PHALCON_INIT_NVAR(header);
		object_init_ex(header, phalcon_amf_header_ce);

		PHALCON_CALL_METHOD(NULL, header, "__construct", name, required, data);

		PHALCON_CALL_METHOD(NULL, packet, "appendheader", header);
	}

	//phalcon_update_property_long(this_ptr, SL("_rawPos"), 6 TSRMLS_CC);

	// parse message
	PHALCON_CALL_SELF(&elements, "readint");
	num = phalcon_get_intval(elements);
	while (num--) {
		PHALCON_CALL_SELF(&target, "readutf");
		PHALCON_CALL_SELF(&response, "readutf");
		PHALCON_CALL_SELF(NULL, "seek", seeknum);
		PHALCON_CALL_SELF(&type, "readbyte");
		PHALCON_CALL_SELF(&data, "readdata", type);

		PHALCON_INIT_NVAR(message);
		object_init_ex(message, phalcon_amf_message_ce);

		PHALCON_CALL_METHOD(NULL, message, "__construct", target, response, data);

		PHALCON_CALL_METHOD(NULL, packet, "appendmessage", message);
	}


	phalcon_update_property_this(this_ptr, SL("_packet"), packet TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Amf_Deserializer, getPacket){

	RETURN_MEMBER(this_ptr, "_packet");
}

PHP_METHOD(Phalcon_Amf_Deserializer, readByte){

	zval *rawdata, *rawsize, *rawpos;
	const char *buf;
	int size, pos, ret;

	rawdata = phalcon_fetch_nproperty_this(this_ptr, SL("_rawData"), PH_NOISY TSRMLS_CC);
	rawsize = phalcon_fetch_nproperty_this(this_ptr, SL("_rawSize"), PH_NOISY TSRMLS_CC);
	rawpos = phalcon_fetch_nproperty_this(this_ptr, SL("_rawPos"), PH_NOISY TSRMLS_CC);

	buf = Z_STRVAL_P(rawdata);
	size = phalcon_get_intval(rawsize);
	pos = phalcon_get_intval(rawpos);

	if (pos >= size) {
		zend_throw_exception_ex(phalcon_amf_exception_ce, 0 TSRMLS_CC, "Insufficient type data at position %d", pos);
		return;
	}

	ret = buf[pos++];

	phalcon_update_property_long(this_ptr, SL("_rawPos"), pos TSRMLS_CC);

	RETURN_LONG(ret);
}

PHP_METHOD(Phalcon_Amf_Deserializer, readBuffer){

	zval *length, *rawdata,  *rawpos;
	int len, pos, ret;

	phalcon_fetch_params(0, 1, 0, &length);

	len = phalcon_get_intval(length);

	rawdata = phalcon_fetch_nproperty_this(this_ptr, SL("_rawData"), PH_NOISY TSRMLS_CC);
	rawpos = phalcon_fetch_nproperty_this(this_ptr, SL("_rawPos"), PH_NOISY TSRMLS_CC);

	pos = phalcon_get_intval(rawpos);

	phalcon_substr(return_value, rawdata, pos, len);

	phalcon_update_property_long(this_ptr, SL("_rawPos"), pos + len TSRMLS_CC);
}

PHP_METHOD(Phalcon_Amf_Deserializer, seek){

	zval *offset, *rawsize, *rawpos;
	int size, pos;

	phalcon_fetch_params(0, 1, 0, &offset);

	rawsize = phalcon_fetch_nproperty_this(this_ptr, SL("_rawSize"), PH_NOISY TSRMLS_CC);
	rawpos = phalcon_fetch_nproperty_this(this_ptr, SL("_rawPos"), PH_NOISY TSRMLS_CC);

	size = phalcon_get_intval(rawsize);
	pos = phalcon_get_intval(rawpos) + phalcon_get_intval(offset);

	if (pos >= size) {
		zend_throw_exception_ex(phalcon_amf_exception_ce, 0 TSRMLS_CC, "Insufficient type data at position %d", pos);
		return;
	}

	phalcon_update_property_long(this_ptr, SL("_rawPos"), pos TSRMLS_CC);
}

PHP_METHOD(Phalcon_Amf_Deserializer, readBool){

	zval *rawdata, *rawsize, *rawpos;
	const char *buf;
	int size, pos, ret;

	rawdata = phalcon_fetch_nproperty_this(this_ptr, SL("_rawData"), PH_NOISY TSRMLS_CC);
	rawsize = phalcon_fetch_nproperty_this(this_ptr, SL("_rawSize"), PH_NOISY TSRMLS_CC);
	rawpos = phalcon_fetch_nproperty_this(this_ptr, SL("_rawPos"), PH_NOISY TSRMLS_CC);

	buf = Z_STRVAL_P(rawdata);
	size = phalcon_get_intval(rawsize);
	pos = phalcon_get_intval(rawpos);

	if (pos >= size) {
		zend_throw_exception_ex(phalcon_amf_exception_ce, 0 TSRMLS_CC, "Insufficient type data at position %d", pos);
		return;
	}

	ret = (buf[pos++] == 1);

	phalcon_update_property_long(this_ptr, SL("_rawPos"), pos TSRMLS_CC);

	RETURN_BOOL(ret);
}

PHP_METHOD(Phalcon_Amf_Deserializer, readInt){

	zval *rawdata, *rawsize, *rawpos;
	const char *buf;
	int size, pos, val1, val2;

	rawdata = phalcon_fetch_nproperty_this(this_ptr, SL("_rawData"), PH_NOISY TSRMLS_CC);
	rawsize = phalcon_fetch_nproperty_this(this_ptr, SL("_rawSize"), PH_NOISY TSRMLS_CC);
	rawpos = phalcon_fetch_nproperty_this(this_ptr, SL("_rawPos"), PH_NOISY TSRMLS_CC);


	buf = Z_STRVAL_P(rawdata);
	size = phalcon_get_intval(rawsize);
	pos = phalcon_get_intval(rawpos);

	if (pos + 2 > size) {
		zend_throw_exception_ex(phalcon_amf_exception_ce, 0 TSRMLS_CC, "Insufficient type data at position %d", pos);
		return;
	}

	val1 = buf[pos++];
	val2 = buf[pos++];

	phalcon_update_property_long(this_ptr, SL("_rawPos"), pos TSRMLS_CC);

	RETURN_LONG((val1 << 8) | val2);
}

PHP_METHOD(Phalcon_Amf_Deserializer, readDouble){

	zval *rawdata, *rawsize, *rawpos;
	union { int i; char c; } t;
	union { double d; char c[8]; } u;
	const char *buf;
	int size, pos, val1, val2;

	rawdata = phalcon_fetch_nproperty_this(this_ptr, SL("_rawData"), PH_NOISY TSRMLS_CC);
	rawsize = phalcon_fetch_nproperty_this(this_ptr, SL("_rawSize"), PH_NOISY TSRMLS_CC);
	rawpos = phalcon_fetch_nproperty_this(this_ptr, SL("_rawPos"), PH_NOISY TSRMLS_CC);

	buf = Z_STRVAL_P(rawdata);
	size = phalcon_get_intval(rawsize);
	pos = phalcon_get_intval(rawpos);

	if (pos + 8 > size) {
		zend_throw_exception_ex(phalcon_amf_exception_ce, 0 TSRMLS_CC, "Insufficient type data at position %d", pos);
		return;
	}

	buf += pos;

	t.i = 1;
	if (!t.c) {
		memcpy(u.c, buf, 8);
	} else {
		int i;
		for (i = 0; i < 8; ++i) {
			u.c[i] = buf[7 - i];
		}
	}

	phalcon_update_property_long(this_ptr, SL("_rawPos"), pos+8 TSRMLS_CC);

	RETURN_LONG(u.d);
}

PHP_METHOD(Phalcon_Amf_Deserializer, readLong){

	zval *rawdata, *rawsize, *rawpos;
	const char *buf;
	int size, pos, val1, val2, val3, val4;

	rawdata = phalcon_fetch_nproperty_this(this_ptr, SL("_rawData"), PH_NOISY TSRMLS_CC);
	rawsize = phalcon_fetch_nproperty_this(this_ptr, SL("_rawSize"), PH_NOISY TSRMLS_CC);
	rawpos = phalcon_fetch_nproperty_this(this_ptr, SL("_rawPos"), PH_NOISY TSRMLS_CC);

	buf = Z_STRVAL_P(rawdata);
	size = phalcon_get_intval(rawsize);
	pos = phalcon_get_intval(rawpos);

	if (pos + 4 > size) {
		zend_throw_exception_ex(phalcon_amf_exception_ce, 0 TSRMLS_CC, "Insufficient type data at position %d", pos);
		return;
	}

	val1 = buf[pos++];
	val2 = buf[pos++];
	val3 = buf[pos++];
	val4 = buf[pos++];
	
	phalcon_update_property_long(this_ptr, SL("_rawPos"), pos TSRMLS_CC);

	RETURN_LONG((val1 << 24) | (val2 << 16) | (val3 << 8) | val4);
}

PHP_METHOD(Phalcon_Amf_Deserializer, readUTF){

	zval *rawdata, *rawsize, *rawpos;
	zval *vallength = NULL;
	int size, length, pos;

	rawsize = phalcon_fetch_nproperty_this(this_ptr, SL("_rawSize"), PH_NOISY TSRMLS_CC);
	size = phalcon_get_intval(rawsize);

	PHALCON_CALL_SELFW(&vallength, "readint");

	length = phalcon_get_intval(vallength);

	if (length <= 0) {
		RETURN_EMPTY_STRING();
	}

	if (pos + length > size) {
		zend_throw_exception_ex(phalcon_amf_exception_ce, 0 TSRMLS_CC, "Insufficient type data at position %d", pos);
		return;
	}

	rawdata = phalcon_fetch_nproperty_this(this_ptr, SL("_rawData"), PH_NOISY TSRMLS_CC);
	rawpos = phalcon_fetch_nproperty_this(this_ptr, SL("_rawPos"), PH_NOISY TSRMLS_CC);

	pos = phalcon_get_intval(rawpos);

	phalcon_substr(return_value, rawdata, pos, length);

	phalcon_update_property_long(this_ptr, SL("_rawPos"), pos + length TSRMLS_CC);
}

PHP_METHOD(Phalcon_Amf_Deserializer, readLongUTF){

	zval *rawdata, *rawsize, *rawpos;
	zval *vallength = NULL;
	int size, pos;
	long length;

	rawsize = phalcon_fetch_nproperty_this(this_ptr, SL("_rawSize"), PH_NOISY TSRMLS_CC);
	size = phalcon_get_intval(rawsize);

	PHALCON_CALL_SELFW(&vallength, "readlong");

	length = phalcon_get_intval(vallength);

	if (length <= 0) {
		RETURN_EMPTY_STRING();
	}

	if (pos + length > size) {
		zend_throw_exception_ex(phalcon_amf_exception_ce, 0 TSRMLS_CC, "Insufficient type data at position %d", pos);
		return;
	}

	rawdata = phalcon_fetch_nproperty_this(this_ptr, SL("_rawData"), PH_NOISY TSRMLS_CC);
	rawpos = phalcon_fetch_nproperty_this(this_ptr, SL("_rawPos"), PH_NOISY TSRMLS_CC);

	pos = phalcon_get_intval(rawpos);

	phalcon_substr(return_value, rawdata, pos, length);

	phalcon_update_property_long(this_ptr, SL("_rawPos"), pos + length TSRMLS_CC);
}

PHP_METHOD(Phalcon_Amf_Deserializer, readObject){

	zval *key = NULL, *type = NULL, *value = NULL;

	object_init(return_value);

	PHALCON_CALL_SELFW(&key, "readutf");
	PHALCON_CALL_SELFW(&type, "readbyte");

	while (phalcon_get_intval(type) != 9) {
		PHALCON_CALL_SELFW(&value, "readdata", type);

		phalcon_update_property_zval_zval(return_value, key, value TSRMLS_CC);

		PHALCON_CALL_SELFW(&key, "readutf");
		PHALCON_CALL_SELFW(&type, "readbyte");
	}
}

PHP_METHOD(Phalcon_Amf_Deserializer, readArray){

	zval *vallength = NULL, *type = NULL, *value = NULL;
	int length, i;

	array_init(return_value);

	PHALCON_CALL_SELFW(&vallength, "readlong");

	length = phalcon_get_intval(vallength);

	for (i = 0; i < length; i++) {
		PHALCON_CALL_SELFW(&type, "readbyte");
		PHALCON_CALL_SELFW(&value, "readdata", type);

		phalcon_array_append(&return_value, value, 0);
	}
}

PHP_METHOD(Phalcon_Amf_Deserializer, readCustomClass){

	zval *identifier = NULL;

	PHALCON_CALL_SELFW(&identifier, "readutf");

	// TODO:
}

PHP_METHOD(Phalcon_Amf_Deserializer, readData){

	zval *rawtype, *rawpos;
	int type;

	phalcon_fetch_params(0, 1, 0, &rawtype);

	type = phalcon_get_intval(rawtype);
	rawpos = phalcon_fetch_nproperty_this(this_ptr, SL("_rawPos"), PH_NOISY TSRMLS_CC);
	
	switch (type) {
		case 0x11: //Amf3-specific
			PHALCON_RETURN_CALL_SELFW("readamf3data");
			break;
		case 0: // number
			PHALCON_RETURN_CALL_SELFW("readdouble");
			break;
		case 1: // boolean
			PHALCON_RETURN_CALL_SELFW("readboolean");
			break;
		case 2: // string
			PHALCON_RETURN_CALL_SELFW("readutf");
			break;
		case 3: // object Object
			PHALCON_RETURN_CALL_SELFW("readobject");
			break;
		//ignore movie clip
		case 5: // null
			break;
		case 6: // undefined
			break;
		case 7: // Circular references are returned here
			break;
		case 8: // mixed array with numeric and string keys
			break;
		case 9: //object end. not worth , TODO maybe some integrity checking
			break;
		case 0X0A: // 10 array
			PHALCON_RETURN_CALL_SELFW("readarray");
			break;
		case 0X0B: // date
			break;
		case 0X0C: // string, strlen(string) > 2^16
			PHALCON_RETURN_CALL_SELFW("readlongutf");
			break;
		case 0X0D: // mainly internal AS objects
			break;
		//ignore recordset
		case 0X0F: // XML
			break;
		case 0x10: // Custom Class
			PHALCON_RETURN_CALL_SELFW("readcustomclass");
			break;
		default: // unknown case
			zend_throw_exception_ex(phalcon_amf_exception_ce, 0 TSRMLS_CC, "Found unhandled type with code: %d", type);
			break;
	}
}

PHP_METHOD(Phalcon_Amf_Deserializer, readAmf3Int){

	zval *byte = NULL, *tmpbyte = NULL;
	int i, tmp;

	PHALCON_CALL_SELFW(&type, "readbyte");

	i = phalcon_get_intval(type);

	if (i < 128) {
		RETURN_LONG(i);
	}

	i = (i & 0x7f) << 7;

	PHALCON_CALL_SELFW(&tmpbyte, "readbyte");

	tmp = phalcon_get_intval(tmpbyte);

	if (tmp < 128) {
		RETURN_LONG(i | tmp);
	}

	i = (i | (tmp & 0x7f)) << 7;

	PHALCON_CALL_SELFW(&tmpbyte, "readbyte");

	tmp = phalcon_get_intval(tmpbyte);

	if (tmp < 128) {
		RETURN_LONG(i | tmp);
	}

	i = (i | (tmp & 0x7f)) << 8;

	PHALCON_CALL_SELFW(&tmpbyte, "readbyte");

	tmp = phalcon_get_intval(tmpbyte);

	i |= tmp;

	// Integers in Amf3 are 29 bit. The MSB (of those 29 bit) is the sign bit.
	// In order to properly convert that integer to a PHP integer - the system
	// might be 32 bit, 64 bit, 128 bit or whatever - all higher bits need to
	// be set.

	if ((i & 0x10000000) !== 0) {
		i |= ~0x1fffffff; // extend the sign bit regardless of integer (bit) size
	}

	RETURN_LONG(i);
}

PHP_METHOD(Phalcon_Amf_Deserializer, readAmf3String){

	zval *strrefval = NULL, *storedstrings, *number_storedstrings;
	zval *str = NULL, *strlen;
	int strref, number, len;

	PHALCON_MM_GROW();

	storedstrings = phalcon_fetch_nproperty_this(this_ptr, SL("_storedStrings"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(storedstrings) != IS_ARRAY) {
		array_init(storedstrings);
	}

	PHALCON_CALL_SELF(&strrefval, "readamf3int");

	strref = phalcon_get_intval(strrefval);

	PHALCON_INIT_VAR(number_storedstrings);
	phalcon_fast_count(number_storedstrings, storedstrings TSRMLS_CC);

	number = phalcon_get_intval(number_storedstrings);

	if ((strref & 0x01) == 0) {
		strref = strref >> 1;
		if (!phalcon_array_isset_long_fetch(&return_value, storedstrings, strref)) {
			zend_throw_exception_ex(phalcon_amf_exception_ce, 0 TSRMLS_CC, "Undefined string reference: %d", strref);
			RETURN_MM();
		}
	} else {
		len = strref >> 1;
		if (len > 0) {
			PHALCON_INIT_VAR(strlen);
			ZVAL_LONG(strlen, len);

			PHALCON_CALL_SELF(&str, "readbuffer", strlen);

			phalcon_array_append(&storedstrings, str, 0);

			phalcon_update_property_this(this_ptr, SL("_storedStrings"), storedstrings TSRMLS_CC);
		}

		RETURN_CCTOR(str);
	}
}

PHP_METHOD(Phalcon_Amf_Deserializer, readAmf3Array){

	zval *handleval = NULL, *storedarrays;
	zval *key = NULL, *value = NULL;
	int handle, tmp;

	storedarrays = phalcon_fetch_nproperty_this(this_ptr, SL("_storedArrays"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(storedarrays) != IS_ARRAY) {
		array_init(storedarrays);
	}

	PHALCON_CALL_SELFW(&handleval, "readamf3int");

	handle = phalcon_get_intval(handleval);

	tmp = (handle & 1) == 0;
	
	handle = handle >> 1;

	if (tmp) {
		if (!phalcon_array_isset_long_fetch(&return_value, storedarrays, handle)) {
			zend_throw_exception_ex(phalcon_amf_exception_ce, 0 TSRMLS_CC, "Undefined Array reference: %d", handle);
			return;
		}
	}

	PHALCON_CALL_SELFW(&key, "readamf3string");

	array_init(return_value);

	while(!PHALCON_IS_EMPTY(key)) {
		PHALCON_CALL_SELFW(&value, "readamf3data");
		phalcon_array_update_zval(&return_value, &key, value, 0);
		PHALCON_CALL_SELFW(&key, "readamf3string");
	}

	phalcon_array_append(&storedarrays, return_value, 0);

	phalcon_update_property_this(this_ptr, SL("_storedArrays"), storedarrays TSRMLS_CC);

	RETURN_CCTORW(return_value);
}

PHP_METHOD(Phalcon_Amf_Deserializer, readAmf3Object){

	zval *handleval = NULL, *storedobjects;
	zval *typeIdentifier = NULL, *classDefinition, *classMemberDefinitions, *member = NULL;
	int handle, tmp, inlineClassDef, typeObject, externalizable, dynamic, memberCount;

	PHALCON_MM_GROW();

	storedobjects = phalcon_fetch_nproperty_this(this_ptr, SL("_storedObjects"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(storedobjects) != IS_ARRAY) {
		array_init(storedobjects);
	}

	PHALCON_CALL_SELF(&handleval, "readamf3int");

	handle = phalcon_get_intval(handleval);

	tmp = (handle & 1) == 0;

	handle = handle >> 1;

	if (tmp) {
		if (!phalcon_array_isset_long_fetch(&return_value, storedobjects, handle)) {
			zend_throw_exception_ex(phalcon_amf_exception_ce, 0 TSRMLS_CC, "Undefined Object reference: %d", handle);
			RETURN_MM();
		}
	}

	//an inline object
	inlineClassDef = ((handle & 1) != 0);
	handle = handle >> 1;

	if (inlineClassDef) {
		PHALCON_CALL_SELF(&typeIdentifier, "readamf3string");

		typeObject = !PHALCON_IS_EMPTY(typeIdentifier);
		externalizable = ((handle & 1) != 0);
		handle = handle >> 1;
		dynamic = ((handle & 1) != 0);
		handle = handle >> 1;
		memberCount = handle;

		PHALCON_INIT_VAR(classMemberDefinitions);
		array_init_size(classMemberDefinitions, memberCount);
		for (tmp = 0; tmp < memberCount; tmp++) {
			PHALCON_CALL_SELF(&member, "readamf3string");
			phalcon_array_append(&classMemberDefinitions, member, 0);
		}
        
		PHALCON_INIT_VAR(classDefinition);
		array_init(classDefinition);

		phalcon_array_update_zval(&classDefinition, SL("type"), typeIdentifier, 0);
		phalcon_array_update_zval(&classDefinition, SL("members"), classMemberDefinitions, 0);
		phalcon_array_update_string_bool(&classDefinition, SL("externalizable"), externalizable, 0);
		phalcon_array_update_string_bool(&classDefinition, SL("dynamic"), dynamic, 0);

		phalcon_array_append(&storedobjects, classDefinition, 0);

		phalcon_update_property_this(this_ptr, SL("_storedObjects"), storedobjects TSRMLS_CC);
	} else if (!phalcon_array_isset_long_fetch(&classDefinition, storedobjects, handle)) {
		zend_throw_exception_ex(phalcon_amf_exception_ce, 0 TSRMLS_CC, "Undefined Object reference: %d", handle);
		RETURN_MM();
	}

	PHALCON_MM_RESTORE();

}

PHP_METHOD(Phalcon_Amf_Deserializer, readAmf3Data){

	zval *type = NULL;

	PHALCON_CALL_SELFW(&type, "readbyte");

	type = phalcon_get_intval(rawtype);

	switch (type) {
		case 0x00:
			return new Amfphp_Core_Amf_Types_Undefined();
		case 0x01:
			RETURN_NULL();
		case 0x02:
			RETURN_FALSE; //boolean false
		case 0x03:
			RETURN_TRUE; //boolean true
		case 0x04:
			PHALCON_RETURN_CALL_SELFW("readamf3int");
			break;
		case 0x05:
			PHALCON_RETURN_CALL_SELFW("readdouble");
			break;
		case 0x06:
			PHALCON_RETURN_CALL_SELFW("readamf3string");
			break;
		case 0x07:
			break;
		case 0x08:
			break;
		case 0x09:
			PHALCON_RETURN_CALL_SELFW("readamf3array");
			break;
		case 0x0A:
			PHALCON_RETURN_CALL_SELFW("readamf3Object");
			break;
		case 0x0B:
			break;
		case 0x0C:
			break;
		case 0x0D:
		case 0x0E:
		case 0x0F:
		case 0x10:
			break;
		case 0x11 :
			PHALCON_THROW_EXCEPTION_STR(phalcon_amf_exception_ce, "dictionaries not supported, as it is not possible to use an object as array key in PHP");
			break;
		default:
			zend_throw_exception_ex(phalcon_amf_exception_ce, 0 TSRMLS_CC, "undefined Amf3 type encountered: %d", type);
	}
}
