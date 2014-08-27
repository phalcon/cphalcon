
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
  |          Nikolaos Dimopoulos <nikos@phalconphp.com>                    |
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_AMF_H
#define PHALCON_AMF_H

#include "php_phalcon.h"

#include "ext/standard/php_smart_str.h"

#define PHALCON_AMF3_CLIENT_SUCCESS_METHOD "/onResult"
#define PHALCON_AMF3_CLIENT_FAILURE_METHOD "/onStatus"
#define PHALCON_AMF3_DEFAULT_REQUEST_RESPONSE_URI "/1"
#define PHALCON_AMF3_CONTENT_TYPE "application/x-amf"

#define PHALCON_AMF3_MAX_STORED_OBJECTS 1024

#define PHALCON_AMF3_UNDEFINED   0x00
#define PHALCON_AMF3_NULL        0x01
#define PHALCON_AMF3_FALSE       0x02
#define PHALCON_AMF3_TRUE        0x03
#define PHALCON_AMF3_INTEGER     0x04
#define PHALCON_AMF3_DOUBLE      0x05
#define PHALCON_AMF3_STRING      0x06
#define PHALCON_AMF3_XMLDOC      0x07
#define PHALCON_AMF3_DATE        0x08
#define PHALCON_AMF3_ARRAY       0x09
#define PHALCON_AMF3_OBJECT      0x0a
#define PHALCON_AMF3_XML         0x0b
#define PHALCON_AMF3_BYTEARRAY   0x0c

#define PHALCON_AMF3_MAX_INT     268435455 /*  (2^28)-1 */
#define PHALCON_AMF3_MIN_INT    -268435456 /* -(2^28)   */

// Encoding options
#define PHALCON_AMF3_OPTION_FORCE_OBJECT      0x01

// Decoding options
#define PHALCON_AMF3_OPTION_CLASS_MAP         0x01
#define PHALCON_AMF3_OPTION_CLASS_AUTOLOAD    0x02
#define PHALCON_AMF3_OPTION_CLASS_CONSTRUCT   0x04

#define ZVAL_RESET(A) \
	if (!(A)) { \
		ALLOC_INIT_ZVAL((A)); \
	} else { \
		zval_dtor((A)); \
		ZVAL_NULL((A)); \
	}

extern zend_class_entry *phalcon_amf_ce;

PHALCON_INIT_CLASS(Phalcon_Amf);

#endif /* PHALCON_AMF_H */
