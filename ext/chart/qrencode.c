
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

#ifdef PHALCON_USE_QRENCODE
#include <png.h>
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "php_open_temporary_file.h"

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
#include "kernel/output.h"

#include "chart/qrencode.h"

#ifdef PHALCON_USE_QRENCODE
#include <qrencode.h>

static int le_qr;

typedef struct {
    QRcode *c;
} php_qrcode;

static void qr_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
    php_qrcode *qr = (php_qrcode *) rsrc->ptr;

    if (qr->c)
        QRcode_free (qr->c);
    efree (qr);
}
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

#ifdef PHALCON_USE_QRENCODE
    le_qr = zend_register_list_destructors_ex(qr_dtor, NULL, "qr", module_number);

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
#endif
	zend_declare_property_null(phalcon_chart_qrencode_ce, SL("_qr"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_chart_qrencode_ce, SL("_text"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_chart_qrencode_ce, SL("_version"), 4, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_chart_qrencode_ce, SL("_level"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_chart_qrencode_ce, SL("_mode"), 3, ZEND_ACC_PROTECTED TSRMLS_CC);
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
 * @param boolean $casesensitive
 */
PHP_METHOD(Phalcon_Chart_QRencode, __construct){

	zval *text = NULL, *version = NULL, *level = NULL, *mode = NULL, *casesensitive = NULL;

	phalcon_fetch_params(0, 0, 5, &text, &version, &level, &mode, &casesensitive);
	
	if (text) {
		if (Z_TYPE_P(text) != IS_STRING) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_chart_exception_ce, "text parameter must be string");
			return;
		}
		phalcon_update_property_this(this_ptr, SL("_text"), text TSRMLS_CC);
	}
	
	if (version) {
		if (Z_TYPE_P(version) != IS_LONG) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_chart_exception_ce, "version parameter must be int");
			return;
		}
		phalcon_update_property_this(this_ptr, SL("_version"), version TSRMLS_CC);
	}
	
	if (level) {
		if (Z_TYPE_P(level) != IS_LONG) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_chart_exception_ce, "level parameter must be int");
			return;
		}
		phalcon_update_property_this(this_ptr, SL("_level"), level TSRMLS_CC);
	}
	
	if (mode) {
		if (Z_TYPE_P(mode) != IS_LONG) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_chart_exception_ce, "mode parameter must be int");
			return;
		}
		phalcon_update_property_this(this_ptr, SL("_mode"), mode TSRMLS_CC);
	}
	
	if (casesensitive) {
		if (Z_TYPE_P(casesensitive) != IS_LONG && Z_TYPE_P(casesensitive) != IS_BOOL) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_chart_exception_ce, "casesensitive parameter must be int or bool");
			return;
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
 * @param string $text
 * @param int $version
 * @param int $level
 * @param int $mode
 * @param boolean $casesensitive
 * @return boolean
 */
PHP_METHOD(Phalcon_Chart_QRencode, generate){

	zval *text = NULL, *version = NULL, *level = NULL, *mode = NULL, *casesensitive = NULL;
#ifdef PHALCON_USE_QRENCODE
	zval *zid;
#endif

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 5, &text, &version, &level, &mode, &casesensitive);

	if (text) {
		if (Z_TYPE_P(text) != IS_STRING) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_chart_exception_ce, "text parameter must be string");
			return;
		}
		phalcon_update_property_this(this_ptr, SL("_text"), text TSRMLS_CC);
	} else {
		PHALCON_OBS_VAR(text);
		phalcon_read_property_this(&text, this_ptr, SL("_text"), PH_NOISY_CC);
	}
	
	if (version) {
		if (Z_TYPE_P(version) != IS_LONG) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_chart_exception_ce, "version parameter must be int");
			return;
		}
		phalcon_update_property_this(this_ptr, SL("_version"), version TSRMLS_CC);
	} else {
		PHALCON_OBS_VAR(version);
		phalcon_read_property_this(&version, this_ptr, SL("_version"), PH_NOISY_CC);
	}
	
	if (level) {
		if (Z_TYPE_P(level) != IS_LONG) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_chart_exception_ce, "level parameter must be int");
			return;
		}
		phalcon_update_property_this(this_ptr, SL("_level"), level TSRMLS_CC);
	} else {
		PHALCON_OBS_VAR(level);
		phalcon_read_property_this(&level, this_ptr, SL("_level"), PH_NOISY_CC);
	}
	
	if (mode) {
		if (Z_TYPE_P(mode) != IS_LONG) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_chart_exception_ce, "mode parameter must be int");
			return;
		}
		phalcon_update_property_this(this_ptr, SL("_mode"), mode TSRMLS_CC);
	} else {
		PHALCON_OBS_VAR(mode);
		phalcon_read_property_this(&mode, this_ptr, SL("_mode"), PH_NOISY_CC);
	}
	
	if (casesensitive) {
		if (Z_TYPE_P(casesensitive) != IS_LONG && Z_TYPE_P(casesensitive) != IS_BOOL) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_chart_exception_ce, "casesensitive parameter must be int or bool");
			return;
		}
		phalcon_update_property_this(this_ptr, SL("_casesensitive"), casesensitive TSRMLS_CC);
	} else {
		PHALCON_OBS_VAR(casesensitive);
		phalcon_read_property_this(&casesensitive, this_ptr, SL("_casesensitive"), PH_NOISY_CC);
	}

#ifdef PHALCON_USE_QRENCODE
	php_qrcode *qr = NULL;

	qr = (php_qrcode *) emalloc (sizeof (php_qrcode));

	if (Z_LVAL_P(mode) == QR_MODE_8) {
		qr->c = QRcode_encodeString8bit(Z_STRVAL_P(text), Z_LVAL_P(version), Z_LVAL_P(level));
	} else {
		qr->c = QRcode_encodeString(Z_STRVAL_P(text), Z_LVAL_P(version), Z_LVAL_P(level), Z_LVAL_P(mode), zend_is_true(casesensitive) ? 1 : 0);
	}

	if (qr->c == NULL)  {
		efree(qr);
		RETURN_MM_FALSE;
	} else {
		PHALCON_INIT_VAR(zid);
		ZEND_REGISTER_RESOURCE(zid, qr, le_qr);		
		phalcon_update_property_this(this_ptr, SL("_qr"), zid TSRMLS_CC);
		RETURN_MM_TRUE;
	}
#endif
	RETURN_MM_FALSE;
}

/**
 * Render the image and return the binary string.
 *
 *     $data = \Phalcon\Chart\QRencode::render();
 *
 * @param size $size
 * @param margin $margin.
 * @return string
 */
PHP_METHOD(Phalcon_Chart_QRencode, render){

	zval *size = NULL, *margin = NULL;
#ifdef PHALCON_USE_QRENCODE
	zval *zid;
    long s = 3, m = 4;
#endif

    PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &size, &margin);

	if (size && Z_TYPE_P(size) != IS_NULL && Z_TYPE_P(size) != IS_LONG) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_chart_exception_ce, "size parameter must be int");
		return;
	}

	if (margin && Z_TYPE_P(margin) != IS_NULL && Z_TYPE_P(margin) != IS_LONG) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_chart_exception_ce, "margin parameter must be int");
		return;
	}
	
#ifdef PHALCON_USE_QRENCODE
	if (Z_TYPE_P(size) == IS_LONG) {
		s = Z_LVAL_P(size);
	}
	if (Z_TYPE_P(margin) == IS_LONG) {
		m = Z_LVAL_P(margin);
	}

    FILE *fp = NULL;
    unsigned char *row, *p, *q;
    int x, y, xx, yy, bit;
    int realwidth;
    char *path;
    int b;
    char buf[4096];
    png_structp png_ptr;
    png_infop info_ptr;
	php_qrcode *qr = NULL;

	PHALCON_OBS_VAR(zid);
	phalcon_read_property_this(&zid, this_ptr, SL("_qr"), PH_NOISY_CC);

    if (Z_TYPE_P(zid) == IS_NULL) {
		RETURN_MM_FALSE;
	}

	ZEND_FETCH_RESOURCE2(qr, php_qrcode *, &zid, -1, "qr handle", le_qr, NULL);

	fp = php_open_temporary_file(NULL, NULL, &path TSRMLS_CC);
	if (!fp) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_chart_exception_ce, "Unable to open temporary file for writing");
		return;
	}

	realwidth = (qr->c->width + m * 2) * s;
	row = (unsigned char *) emalloc ((realwidth + 7) / 8);

	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if(png_ptr == NULL) {
		fclose(fp);
		PHALCON_THROW_EXCEPTION_STR(phalcon_chart_exception_ce, "Failed to initialize PNG writer");
		return;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if(info_ptr == NULL) {
		fclose(fp);
		PHALCON_THROW_EXCEPTION_STR(phalcon_chart_exception_ce, "Failed to initialize PNG writer");
		return;
	}

	if(setjmp(png_jmpbuf(png_ptr))) {
		png_destroy_write_struct(&png_ptr, &info_ptr);
		fclose(fp);
		PHALCON_THROW_EXCEPTION_STR(phalcon_chart_exception_ce, "Failed to write PNG writer");
		return;
	}

	png_init_io(png_ptr, fp);

	png_set_IHDR(png_ptr, info_ptr, realwidth, realwidth, 1, PNG_COLOR_TYPE_GRAY, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
	png_write_info(png_ptr, info_ptr);

	memset(row, 0xff, (realwidth + 7) / 8);
	for(y = 0; y < m * s; y++) {
		png_write_row(png_ptr, row);
	}

	p = qr->c->data;

	for(y = 0; y < qr->c->width; y++) {
		bit = 7;
		memset(row, 0xff, (realwidth + 7) / 8);
		q = row;
		q += m * s / 8;
		bit = 7 - (m * s % 8);
		for(x = 0; x < qr->c->width; x++) {
			for(xx = 0; xx < s; xx++) {
				*q ^= (*p & 1) << bit;
				bit--;
				if(bit < 0) {
					q++;
					bit = 7;
				}
			}
			p++;
		}

		for(yy=0; yy < s; yy++) {
			png_write_row(png_ptr, row);
		}
	}

	memset(row, 0xff, (realwidth + 7) / 8);
	for(y=0; y < m * s; y++) {
		png_write_row(png_ptr, row);
	}

	png_write_end(png_ptr, info_ptr);
	png_destroy_write_struct(&png_ptr, &info_ptr);

	efree (row);
	fseek (fp, 0, SEEK_SET);

	phalcon_ob_start(TSRMLS_C);

	while ((b = fread (buf, 1, sizeof(buf), fp)) > 0) {
		php_write(buf, b TSRMLS_CC);
	}

	phalcon_ob_get_contents(return_value TSRMLS_CC);
	phalcon_ob_end_clean(TSRMLS_C);

	fclose (fp);
	VCWD_UNLINK((const char *)path);
	efree(path);
#endif       
}

/**
 * Save the image
 *
 *     $ret = \Phalcon\Chart\QRencode::save('qr.png');
 *
 * @param filename $filename
 * @param size $size
 * @param margin $margin.
 * @return boolean
 */
PHP_METHOD(Phalcon_Chart_QRencode, save){

	zval *filename, *size = NULL, *margin = NULL;
#ifdef PHALCON_USE_QRENCODE
	zval *zid, *exception_message;
	char *fn = NULL;
    long s = 3, m = 4;
#endif

    PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &filename, &size, &margin);

	if (Z_TYPE_P(filename) != IS_STRING || PHALCON_IS_EMPTY(filename)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_chart_exception_ce, "filename parameter must be string");
		return;
	}

	if (size && Z_TYPE_P(size) != IS_NULL && Z_TYPE_P(size) != IS_LONG) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_chart_exception_ce, "size parameter must be int");
		return;
	}

	if (margin && Z_TYPE_P(margin) != IS_NULL && Z_TYPE_P(margin) != IS_LONG) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_chart_exception_ce, "margin parameter must be int");
		return;
	}
	
#ifdef PHALCON_USE_QRENCODE
	if (Z_TYPE_P(size) == IS_LONG) {
		s = Z_LVAL_P(size);
	}
	if (Z_TYPE_P(margin) == IS_LONG) {
		m = Z_LVAL_P(margin);
	}
	
	fn = Z_STRVAL_P(filename);

    FILE *fp = NULL;
    unsigned char *row, *p, *q;
    int x, y, xx, yy, bit;
    int realwidth;

    png_structp png_ptr;
    png_infop info_ptr;
	php_qrcode *qr = NULL;

	PHALCON_OBS_VAR(zid);
	phalcon_read_property_this(&zid, this_ptr, SL("_qr"), PH_NOISY_CC);

    if (Z_TYPE_P(zid) == IS_NULL) {
		RETURN_MM_FALSE;
	}

	ZEND_FETCH_RESOURCE2(qr, php_qrcode *, &zid, -1, "qr handle", le_qr, NULL);

	fp = VCWD_FOPEN(fn, "wb");
	if (!fp) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Unable to open '", filename, "' for writing");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_chart_qrencode_ce, exception_message);
		return;
	}	

	realwidth = (qr->c->width + m * 2) * s;
	row = (unsigned char *) emalloc ((realwidth + 7) / 8);

	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if(png_ptr == NULL) {
		fclose(fp);
		PHALCON_THROW_EXCEPTION_STR(phalcon_chart_exception_ce, "Failed to initialize PNG writer");
		return;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if(info_ptr == NULL) {
		fclose(fp);
		PHALCON_THROW_EXCEPTION_STR(phalcon_chart_exception_ce, "Failed to initialize PNG writer");
		return;
	}

	if(setjmp(png_jmpbuf(png_ptr))) {
		png_destroy_write_struct(&png_ptr, &info_ptr);
		fclose(fp);
		PHALCON_THROW_EXCEPTION_STR(phalcon_chart_exception_ce, "Failed to write PNG writer");
		return;
	}

	png_init_io(png_ptr, fp);

	png_set_IHDR(png_ptr, info_ptr, realwidth, realwidth, 1, PNG_COLOR_TYPE_GRAY, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
	png_write_info(png_ptr, info_ptr);

	memset(row, 0xff, (realwidth + 7) / 8);
	for(y = 0; y < m * s; y++) {
		png_write_row(png_ptr, row);
	}

	p = qr->c->data;
	for(y = 0; y < qr->c->width; y++) {
		bit = 7;
		memset(row, 0xff, (realwidth + 7) / 8);
		q = row;
		q += m * s / 8;
		bit = 7 - (m * s % 8);
		for(x = 0; x < qr->c->width; x++) {
			for(xx = 0; xx < s; xx++) {
				*q ^= (*p & 1) << bit;
				bit--;
				if(bit < 0) {
					q++;
					bit = 7;
				}
			}
			p++;
		}

		for(yy=0; yy < s; yy++) {
			png_write_row(png_ptr, row);
		}
	}

	memset(row, 0xff, (realwidth + 7) / 8);
	for(y=0; y < m * s; y++)
		png_write_row(png_ptr, row);

	png_write_end(png_ptr, info_ptr);
	png_destroy_write_struct(&png_ptr, &info_ptr);

	efree (row);

	fflush (fp);
	fclose (fp);
#endif

	RETURN_MM_TRUE;
}

