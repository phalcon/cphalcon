
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

	zend_declare_property_null(phalcon_chart_qrencode_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_chart_qrencode_ce, SL("_version"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_chart_qrencode_ce, SL("_level"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_chart_qrencode_ce, SL("_mode"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_chart_qrencode_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_chart_qrencode_ce, SL("_casesensitive"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Chart\QRencode constructor
 *
 *   $qr = new \Phalcon\Chart\QRencode::__construct('Phalcon is a web framework', 4, QR_ECLEVEL_L, QR_MODE_KANJI, TRUE);
 *   $qr->save();
 *
 * @param string $data
 * @param int $version
 * @param int $level
 * @param int $mode
 * @param bool $casesensitive
 */
PHP_METHOD(Phalcon_Chart_QRencode, __construct){

	zval *data = NULL, *version = NULL, *level = NULL, *mode = NULL, *casesensitive = NULL;

	phalcon_fetch_params(0, 0, 5, &data, &version, &level, &mode, &casesensitive);
	
	if (data) {
		phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	}
	
	if (version) {
		phalcon_update_property_this(this_ptr, SL("_version"), version TSRMLS_CC);
	}
	
	if (level) {
		phalcon_update_property_this(this_ptr, SL("_level"), level TSRMLS_CC);
	}
	
	if (mode) {
		phalcon_update_property_this(this_ptr, SL("_mode"), mode TSRMLS_CC);
	}
	
	if (casesensitive) {
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

