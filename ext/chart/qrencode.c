
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"

#include "chart/qrencode.h"

#ifdef PHALCON_USE_QRENCODE
#include <qrencode.h>
#endif

/**
 * Phalcon\Chart\QRencode
 *
 * Phalcon\Chart\QRencode is array helper.
 * This component is an abstract class that you can extend to add more helpers.
 */


/**
 * Phalcon\Chart\QRencode initializer
 */
PHALCON_INIT_CLASS(Phalcon_Chart_QRencode){

	PHALCON_REGISTER_CLASS(Phalcon\\Chart, QRencode, chart_qrencode, phalcon_chart_qrencode_method_entry, 0);

	/* Mode */
	zend_declare_class_constant_long(phalcon_chart_qrencode_ce, SL("MODE_NUL"), QR_MODE_NUL TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_chart_qrencode_ce, SL("MODE_NUM"), QR_MODE_NUM TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_chart_qrencode_ce, SL("MODE_8"), QR_MODE_8 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_chart_qrencode_ce, SL("MODE_KANJI"), QR_MODE_KANJI TSRMLS_CC);

	/* Level */
	zend_declare_class_constant_long(phalcon_chart_qrencode_ce, SL("LEVEL_L"), QR_ECLEVEL_L TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_chart_qrencode_ce, SL("LEVEL_M"), QR_ECLEVEL_M TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_chart_qrencode_ce, SL("LEVEL_Q"), QR_ECLEVEL_Q TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_chart_qrencode_ce, SL("LEVEL_H"), QR_ECLEVEL_H TSRMLS_CC);

	zend_declare_property_null(phalcon_chart_qrencode_ce, SL("_text"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_chart_qrencode_ce, SL("_version"), 4, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_chart_qrencode_ce, SL("_level"), QR_ECLEVEL_L, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_chart_qrencode_ce, SL("_mode"), QR_MODE_KANJI, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_chart_qrencode_ce, SL("_casesensitive"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Chart\QRencode constructor
 *
 *   $qr = new \Phalcon\Chart\QRencode::__construct('Phalcon is a web framework', 4, QR_ECLEVEL_L, QR_MODE_KANJI, TRUE);
 *   $qr->save();
 *
 * @param string $text
 * @param int $version
 * @param int $level
 * @param int $mode
 * @param bool $casesensitive
 */
PHP_METHOD(Phalcon_Chart_QRencode, __construct){

	zval *text = NULL, *version = NULL, *level = NULL, *mode = NULL, *casesensitive = NULL;

	phalcon_fetch_params(0, 0, 5, &text, &version, &level, &mode, &casesensitive);
	
	if (text) {
		if (Z_TYPE_P(text) != IS_STRING) {
			PHALCON_SEPARATE_PARAM(text);
			convert_to_string_ex(&text);
		}
		phalcon_update_property_this(this_ptr, SL("_text"), text TSRMLS_CC);
	}
	
	if (version) {
		if (Z_TYPE_P(version) != IS_LONG) {
			PHALCON_SEPARATE_PARAM(version);
			convert_to_long_ex(&version);
		}
		phalcon_update_property_this(this_ptr, SL("_version"), version TSRMLS_CC);
	}
	
	if (level) {
		if (Z_TYPE_P(level) != IS_LONG) {
			PHALCON_SEPARATE_PARAM(level);
			convert_to_long_ex(&level);
		}
		phalcon_update_property_this(this_ptr, SL("_level"), level TSRMLS_CC);
	}
	
	if (mode) {
		if (Z_TYPE_P(mode) != IS_LONG) {
			PHALCON_SEPARATE_PARAM(mode);
			convert_to_long_ex(&mode);
		}
		phalcon_update_property_this(this_ptr, SL("_mode"), mode TSRMLS_CC);
	}
	
	if (casesensitive) {
		if (Z_TYPE_P(casesensitive) != IS_LONG) {
			PHALCON_SEPARATE_PARAM(casesensitive);
			convert_to_long_ex(&casesensitive);
		}
		phalcon_update_property_this(this_ptr, SL("_casesensitive"), casesensitive TSRMLS_CC);
	}
}

/**
 * Generate QR data
 *
 *     // Returns TRUE
 *     \Phalcon\Chart\QRencode::generate();
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Chart_QRencode, generate){

	zval *text, *version, *level, *mode, *casesensitive;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(text);
	phalcon_read_property_this(&text, this_ptr, SL("_text"), PH_NOISY_CC);

	PHALCON_OBS_VAR(version);
	phalcon_read_property_this(&version, this_ptr, SL("_version"), PH_NOISY_CC);

	PHALCON_OBS_VAR(level);
	phalcon_read_property_this(&level, this_ptr, SL("_level"), PH_NOISY_CC);

	PHALCON_OBS_VAR(mode);
	phalcon_read_property_this(&mode, this_ptr, SL("_mode"), PH_NOISY_CC);

	PHALCON_OBS_VAR(casesensitive);
	phalcon_read_property_this(&mode, this_ptr, SL("_casesensitive"), PH_NOISY_CC);

#ifdef PHALCON_USE_QRENCODE

    if (zend_parse_parameters( ZEND_NUM_ARGS() TSRMLS_CC, "s|llll", &text, &text_len, &version, &level, &mode, &casesensitive) == FAILURE)
        RETURN_FALSE;

    qr = (php_qrcode *) emalloc (sizeof (php_qrcode));
    if (mode == QR_MODE_8)
        qr->c = QRcode_encodeString8bit(text, version, level);
    else
        qr->c = QRcode_encodeString(text, version, level, mode, casesensitive);

    if (qr->c == NULL)
    {
        efree (qr);
        RETURN_FALSE;
    }

	zend_printf("test.h");
	ZEND_REGISTER_RESOURCE (return_value, qr, le_qr);
#endif
	PHALCON_MM_RESTORE();
}

/**
 * Save to image file or return image data
 *
 *     $data = \Phalcon\Chart\QRencode::save();
 *     $ret = \Phalcon\Chart\QRencode::save('qr.png');
 *
 * @return mixed/boolean
 */
PHP_METHOD(Phalcon_Chart_QRencode, save){
}

