
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
  | Authors: Vladimir Kolesnikov <vladimir@free-sevastopol.com>            |
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

#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/output.h"

/**
 * Phalcon\Image\\Adapter\GD
 *
 * Image manipulation support. Allows images to be resized, cropped, etc.
 *
 *<code>
 *	$image = new Phalcon\Image\Adapter\GD("upload/test.jpg");
 *	$image->resize(200, 200);
 *	$$image->save();
 *</code>
 */


/**
 * Phalcon\Image\Adapter\GD initializer
 */
PHALCON_INIT_CLASS(Phalcon_Image_Adapter_GD){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, GD, image_adapter_gd, "phalcon\\image\\adapter",  phalcon_image_adapter_gd_method_entry, 0);

	zend_class_implements(phalcon_image_adapter_gd_ce TSRMLS_CC, 1, phalcon_image_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Checks if GD is enabled
 *
 * @return  boolean
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, check){

	zval *func_name, *ret = NULL, *gd_info = NULL, *gd_version = NULL, *version, *exception_message;
	zval *op, *pattern = NULL, *matches = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(func_name);
	ZVAL_STRING(func_name, "gd_info", 1);

	PHALCON_INIT_NVAR(ret);
	phalcon_call_func_p1(ret, "function_exists", func_name);

	if (!zend_is_true(ret)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "GD is either not installed or not enabled, check your configuration");
		return;
	}

	PHALCON_INIT_NVAR(gd_version);
	if (zend_get_constant(SL("GD_VERSION"), gd_version TSRMLS_CC) == FAILURE) {

		if (!gd_info) {
			PHALCON_INIT_NVAR(gd_info);
			phalcon_call_func(gd_info, "gd_info");
		}

		PHALCON_INIT_NVAR(pattern);
		ZVAL_STRING(pattern, "#\\d+\\.\\d+(?:\\.\\d+)?#", 1);

		if (phalcon_array_isset_string(gd_info, SS("GD Version"))) {
			PHALCON_OBS_NVAR(gd_version);
			phalcon_array_fetch_string(&gd_version, gd_info, SL("GD Version"), PH_NOISY);

			PHALCON_INIT_NVAR(matches);
		
			PHALCON_INIT_NVAR(ret);
			phalcon_preg_match(ret, pattern, gd_version, matches TSRMLS_CC);

			if (zend_is_true(ret)) {
				if (phalcon_array_isset_long(matches, 0)) {
					PHALCON_OBS_NVAR(gd_version);
					phalcon_array_fetch_long(&gd_version, matches, 0, PH_NOISY);
				} else {
					PHALCON_INIT_NVAR(gd_version);
					ZVAL_STRING(gd_version, "", 1);
				}
			} else {				
				PHALCON_INIT_NVAR(gd_version);
				ZVAL_STRING(gd_version, "", 1);
			}
		}
	}

	PHALCON_INIT_VAR(version);
	ZVAL_STRING(version, "2.0.1", 1);

	PHALCON_INIT_VAR(op);
	ZVAL_STRING(op, ">=", 1);

	PHALCON_INIT_NVAR(ret);
	phalcon_call_func_p3(ret, "version_compare", gd_version, version, op);

	if (!zend_is_true(ret)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVSVS(exception_message, "Image_GD requires GD version '", version ,"' or greater, you have '", gd_version, ",");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_image_exception_ce, exception_message);
		return;
	}

	phalcon_update_static_property(SL("phalcon\\image\\adapter\\gd"), SL("_checked"), ret TSRMLS_CC);

	ZVAL_BOOL(return_value, 1);

	RETURN_MM();
}

/**
 * Phalcon\Image\GD constructor
 *
 * @param string $file
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, __construct){

	zval *file, *exception_message;
	zval *checked = NULL, *realpath = NULL, *type = NULL, *mime = NULL, *image = NULL;
	zval *ret, *saveflag;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &file);

	if (Z_TYPE_P(file) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "file didn't return a valid string");
		return;
	}

	PHALCON_OBS_VAR(checked);
	phalcon_read_static_property(&checked, SL("phalcon\\image\\adapter\\gd"), SL("_checked") TSRMLS_CC);

	if (!zend_is_true(checked)) {
		phalcon_call_static_noret("phalcon\\image\\adapter\\gd", "check");
	}

	phalcon_call_parent_p1_noret(this_ptr, phalcon_image_adapter_gd_ce, "__construct", file);

	PHALCON_OBS_VAR(realpath);
	phalcon_read_property_this(&realpath, this_ptr, SL("_realpath"), PH_NOISY_CC);

	PHALCON_OBS_VAR(type);
	phalcon_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY_CC);

	PHALCON_OBS_VAR(mime);
	phalcon_read_property_this(&mime, this_ptr, SL("_mime"), PH_NOISY_CC);

	switch (Z_LVAL_P(type)) {
		case 1: // GIF
		{
			PHALCON_INIT_VAR(image);
			phalcon_call_func_p1(image, "imagecreatefromgif", realpath);
			break;
		}
		case 2: // JPEG
		{
			PHALCON_INIT_VAR(image);
			phalcon_call_func_p1(image, "imagecreatefromjpeg", realpath);
			break;
		}
		case 3: // PNG
		{
			PHALCON_INIT_VAR(image);
			phalcon_call_func_p1(image, "imagecreatefrompng", realpath);
			break;
		}
		default:
		{
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Installed GD does not support '", mime, "' images");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_image_exception_ce, exception_message);
			return;
		}
	}

	if (Z_TYPE_P(image) != IS_RESOURCE) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Create image from file '", realpath, "' failure  ");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_image_exception_ce, exception_message);
		return;
	}

	PHALCON_INIT_VAR(saveflag);
	ZVAL_BOOL(saveflag, 1);

	phalcon_call_func_p2_noret("imagesavealpha", image, saveflag);

	phalcon_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Execute a resize.
 *
 * @param int $width
 * @param int $height
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _resize) {

	zval *width = NULL, *height = NULL, *ori_width, *ori_height, *pre_width, *pre_height, *reduction_width, *reduction_height;
	zval *w = NULL, *h = NULL, *w0, *h0, *image = NULL, *tmp_image = NULL, *ret = NULL, *dst;
	int tmp_width, tmp_height, tmp_pre_width, tmp_pre_height, tmp_reduction_width, tmp_reduction_height;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &width, &height);

	PHALCON_OBS_VAR(ori_width);
	phalcon_read_property_this(&ori_width, this_ptr, SL("_width"), PH_NOISY_CC);

	PHALCON_OBS_VAR(ori_height);
	phalcon_read_property_this(&ori_height, this_ptr, SL("_height"), PH_NOISY_CC);

	PHALCON_OBS_VAR(pre_width);
	phalcon_read_property_this(&pre_width, this_ptr, SL("_width"), PH_NOISY_CC);

	PHALCON_OBS_VAR(pre_height);
	phalcon_read_property_this(&pre_height, this_ptr, SL("_height"), PH_NOISY_CC);

	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_INIT_VAR(dst);
	ZVAL_LONG(dst, 0);

	tmp_width = Z_LVAL_P(width);
	tmp_height = Z_LVAL_P(height);
	tmp_pre_width = Z_LVAL_P(pre_width);
	tmp_pre_height = Z_LVAL_P(pre_height);

	if (tmp_width > (tmp_pre_width / 2) && tmp_height > (tmp_pre_height / 2)) {
		PHALCON_INIT_VAR(w);
		ZVAL_LONG(w, tmp_width*1.1);

		PHALCON_INIT_VAR(reduction_width);
		phalcon_call_func_p1(reduction_width, "round", w);

		PHALCON_INIT_VAR(h);
		ZVAL_LONG(h, tmp_height*1.1);

		PHALCON_INIT_VAR(reduction_height);
		phalcon_call_func_p1(reduction_height, "round", h);

		tmp_reduction_width = Z_LVAL_P(reduction_width);
		tmp_reduction_height = Z_LVAL_P(reduction_height);

		while ((tmp_pre_width / 2 > tmp_reduction_width) && (tmp_pre_height / 2 > tmp_reduction_height)) {
			PHALCON_INIT_NVAR(w0);
			ZVAL_LONG(w0, tmp_pre_width/2);

			PHALCON_INIT_NVAR(h0);
			ZVAL_LONG(h0, tmp_pre_height/2);

			PHALCON_INIT_NVAR(pre_width);
			ZVAL_LONG(pre_width, (int)Z_LVAL_P(w0));

			PHALCON_INIT_NVAR(pre_height);
			ZVAL_LONG(pre_height, (int)Z_LVAL_P(h0));
					
			tmp_pre_width = Z_LVAL_P(pre_width);
			tmp_pre_height = Z_LVAL_P(pre_height);
		}

		PHALCON_INIT_VAR(tmp_image);

		phalcon_call_method_p2(tmp_image, this_ptr, "_create", pre_width, pre_height);

		PHALCON_INIT_NVAR(ret);
		PHALCON_CALL_FUNCTION(ret, "imagecopyresized", 10, tmp_image, image, dst, dst, dst, dst, pre_width, pre_height, ori_width, ori_height);
		
		if (zend_is_true(ret)) {
			phalcon_call_func_p1_noret("imagedestroy", image);
			phalcon_update_property_this(this_ptr, SL("_image"), tmp_image TSRMLS_CC);

			PHALCON_CPY_WRT(image, tmp_image);
		}
	}

	PHALCON_INIT_NVAR(tmp_image);
	phalcon_call_method_p2(tmp_image, this_ptr, "_create", width, height);

	PHALCON_INIT_NVAR(ret);
	PHALCON_CALL_FUNCTION(ret, "imagecopyresampled", 10, tmp_image, image, dst, dst, dst, dst, width, height, pre_width, pre_height);

	if (zend_is_true(ret)) {
		phalcon_call_func_p1_noret("imagedestroy", image);
		phalcon_update_property_this(this_ptr, SL("_image"), tmp_image TSRMLS_CC);

		PHALCON_INIT_NVAR(w);
		phalcon_call_func_p1(w, "imagesx", tmp_image);

		PHALCON_INIT_NVAR(h);
		phalcon_call_func_p1(h, "imagesy", tmp_image);

		phalcon_update_property_this(this_ptr, SL("_width"), w TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_height"), h TSRMLS_CC);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Execute a crop.
 *
 * @param int $width
 * @param int $height
 * @param int $offset_x
 * @param int $offset_y
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _crop) {
	zval *width, *height, *offset_x, *offset_y;
	zval *w = NULL, *h = NULL, *image, *tmp_image = NULL, *dst, *ret = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &width, &height, &offset_x, &offset_y);

	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_INIT_NVAR(tmp_image);
	phalcon_call_method_p2(tmp_image, this_ptr, "_create", width, height);

	PHALCON_INIT_VAR(dst);
	ZVAL_LONG(dst, 0);

	PHALCON_INIT_NVAR(ret);
	PHALCON_CALL_FUNCTION(ret, "imagecopyresampled", 10, tmp_image, image, dst, dst, offset_x, offset_y, width, height, width, height);

	if (zend_is_true(ret)) {
		phalcon_call_func_p1_noret("imagedestroy", image);
		phalcon_update_property_this(this_ptr, SL("_image"), tmp_image TSRMLS_CC);

		PHALCON_INIT_NVAR(w);
		phalcon_call_func_p1(w, "imagesx", tmp_image);

		PHALCON_INIT_NVAR(h);
		phalcon_call_func_p1(h, "imagesy", tmp_image);

		phalcon_update_property_this(this_ptr, SL("_width"), w TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_height"), h TSRMLS_CC);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Execute a rotation.
 *
 * @param int $degrees
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _rotate) {

	zval *degrees, *d;
	zval *bundled = NULL, *image = NULL, *tmp_image, *color, *alpha, *transparent, *ignore_transparent, *saveflag, *ret;
	zval *w, *h, *dst, *pct;
	int tmp_degrees;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &degrees);

	PHALCON_INIT_VAR(color);
	ZVAL_LONG(color, 0);

	PHALCON_INIT_VAR(alpha);
	ZVAL_LONG(alpha, 127);

	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_INIT_VAR(transparent);
	phalcon_call_func_p5(transparent, "imagecolorallocatealpha", image, color, color, color, alpha);

	tmp_degrees = Z_LVAL_P(degrees);

	PHALCON_INIT_VAR(d);
	ZVAL_LONG(d, 360 - tmp_degrees);

	PHALCON_INIT_VAR(ignore_transparent);
	ZVAL_LONG(ignore_transparent, 1);

	PHALCON_INIT_VAR(tmp_image);
	phalcon_call_func_p4(tmp_image, "imagerotate", image, d, transparent, ignore_transparent);

	PHALCON_INIT_VAR(saveflag);
	ZVAL_BOOL(saveflag, 1);

	phalcon_call_func_p2_noret("imagesavealpha", tmp_image, saveflag);

	PHALCON_INIT_VAR(w);
	phalcon_call_func_p1(w, "imagesx", tmp_image);

	PHALCON_INIT_VAR(h);
	phalcon_call_func_p1(h, "imagesy", tmp_image);

	phalcon_call_func_p1_noret("imagedestroy", image);
	phalcon_update_property_this(this_ptr, SL("_image"), tmp_image TSRMLS_CC);

	phalcon_update_property_this(this_ptr, SL("_width"), w TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_height"), h TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Execute a flip.
 *
 * @param int $direction
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _flip) {

	zval *direction;
	zval *image = NULL, *flipped_image, *width, *height, *dst_x = NULL, *dst_y = NULL, *src_x = NULL, *src_y = NULL, *src_width = NULL, *src_height = NULL;	
	int w, h, x, y;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &direction);

	PHALCON_OBS_VAR(width);
	phalcon_read_property_this(&width, this_ptr, SL("_width"), PH_NOISY_CC);

	PHALCON_OBS_VAR(height);
	phalcon_read_property_this(&height, this_ptr, SL("_height"), PH_NOISY_CC);

	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_INIT_VAR(flipped_image);
	phalcon_call_method_p2(flipped_image, this_ptr, "_create", width, height);

	w = Z_LVAL_P(width);
	h = Z_LVAL_P(height);

	if (Z_LVAL_P(direction) == 11) {

		PHALCON_INIT_NVAR(dst_y);
		ZVAL_LONG(dst_y, 0);

		PHALCON_INIT_NVAR(src_y);
		ZVAL_LONG(src_y, 0);

		PHALCON_INIT_NVAR(src_width);
		ZVAL_LONG(src_width, 1);

		PHALCON_INIT_NVAR(src_height);
		ZVAL_LONG(src_height, h);

		for (x = 0; x < w; x++)
		{
			PHALCON_INIT_NVAR(dst_x);
			ZVAL_LONG(dst_x, x);

			PHALCON_INIT_NVAR(src_x);
			ZVAL_LONG(src_x, w - x - 1);

			PHALCON_CALL_FUNCTION(NULL, "imagecopy", 8, flipped_image, image, dst_x, dst_y, src_x, src_y, src_width, src_height);
		}
	} else {
		PHALCON_INIT_NVAR(dst_x);
		ZVAL_LONG(dst_x, 0);

		PHALCON_INIT_NVAR(src_x);
		ZVAL_LONG(src_x, 0);

		PHALCON_INIT_NVAR(src_width);
		ZVAL_LONG(src_width, w);

		PHALCON_INIT_NVAR(src_height);
		ZVAL_LONG(src_height, 1);

		for (y = 0; y < h; y++)
		{
			PHALCON_INIT_NVAR(dst_y);
			ZVAL_LONG(dst_y, y);

			PHALCON_INIT_NVAR(src_y);
			ZVAL_LONG(src_y, h - y - 1);

			PHALCON_CALL_FUNCTION(NULL, "imagecopy", 8, flipped_image, image, dst_x, dst_y, src_x, src_y, src_width, src_height);
		}
	}

	phalcon_call_func_p1_noret("imagedestroy", image);
	phalcon_update_property_this(this_ptr, SL("_image"), flipped_image TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Execute a sharpen.
 *
 * @param int $amount
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _sharpen) {

	zval *amount, *tmp = NULL, *tmp_amount = NULL, *precision, *matrix, *item = NULL;
	zval *bundled = NULL, *image = NULL, *tmp_image, *ret, *width = NULL, *height = NULL;
	int a;
	double b;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &amount);

	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);

	a = Z_LVAL_P(amount);
	b = a;

	b = -18 + (a * 0.08);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, b);

	PHALCON_INIT_NVAR(tmp_amount);
	phalcon_call_func_p1(tmp_amount, "abs", tmp);

	b = Z_LVAL_P(tmp_amount);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, a);

	PHALCON_INIT_VAR(precision);
	ZVAL_LONG(precision, 2);

	PHALCON_INIT_NVAR(tmp_amount);
	phalcon_call_func_p2(tmp_amount, "round", tmp, precision);

	PHALCON_INIT_VAR(matrix);
	array_init_size(matrix, 3);

	// 1
	PHALCON_INIT_NVAR(item);
	array_init_size(item, 3);

	phalcon_array_append_long(&item, -1, PH_SEPARATE);
	phalcon_array_append_long(&item, -1, PH_SEPARATE);
	phalcon_array_append_long(&item, -1, PH_SEPARATE);

	phalcon_array_append(&matrix, item, PH_SEPARATE);

	// 2
	PHALCON_INIT_NVAR(item);
	array_init_size(item, 3);

	phalcon_array_append_long(&item, -1, PH_SEPARATE);
	phalcon_array_append(&item, tmp_amount, PH_SEPARATE);
	phalcon_array_append_long(&item, -1, PH_SEPARATE);

	phalcon_array_append(&matrix, item, PH_SEPARATE);

	// 3
	PHALCON_INIT_NVAR(item);
	array_init_size(item, 3);

	phalcon_array_append_long(&item, -1, PH_SEPARATE);
	phalcon_array_append_long(&item, -1, PH_SEPARATE);
	phalcon_array_append_long(&item, -1, PH_SEPARATE);

	phalcon_array_append(&matrix, item, PH_SEPARATE);

	b = b - 8;

	PHALCON_INIT_NVAR(tmp_amount);
	ZVAL_LONG(tmp_amount, b);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, 0);

	PHALCON_INIT_VAR(ret);
	phalcon_call_func_p4(ret, "imageconvolution", image, matrix, tmp_amount, tmp);

	if (zend_is_true(ret)) {
		phalcon_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);

		PHALCON_INIT_NVAR(width);
		phalcon_call_func_p1(width, "imagesx", image);

		PHALCON_INIT_NVAR(height);
		phalcon_call_func_p1(height, "imagesy", image);

		phalcon_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Execute a reflection.
 *
 * @param int $height
 * @param int $opacity
 * @param boolean $fade_in
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _reflection) {

	zval *height, *opacity, *fade_in, *o = NULL, *w = NULL, *h = NULL, *tmp = NULL;
	zval *reflection, *line = NULL, *image, *image_width, *image_height, *dst, *src_y = NULL, *dst_y = NULL, *dst_opacity = NULL, *filtertype = NULL;
	int h0, h1, int_opacity, offset;
	double num, stepping;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &height, &opacity, &fade_in);

	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_OBS_VAR(image_width);
	phalcon_read_property_this(&image_width, this_ptr, SL("_width"), PH_NOISY_CC);

	PHALCON_OBS_VAR(image_height);
	phalcon_read_property_this(&image_height, this_ptr, SL("_height"), PH_NOISY_CC);

	PHALCON_INIT_VAR(filtertype);
	if (zend_get_constant(SL("IMG_FILTER_COLORIZE"), filtertype TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}

	h0 = Z_LVAL_P(height);
	h1 = Z_LVAL_P(image_height);

	int_opacity = Z_LVAL_P(opacity);

	num = (int_opacity * 127 / 100) - 127;

	if (num < 0) {
		num = num * -1;
	}

	int_opacity = num+0.5;

	if (int_opacity < 127) {
		stepping = (127 - int_opacity) / h0;
	} else {
		stepping = 127 / h0;
	}

	PHALCON_INIT_NVAR(h);
	ZVAL_LONG(h, h0 + h1);

	PHALCON_INIT_VAR(reflection);
	phalcon_call_method_p2(reflection, this_ptr, "_create", image_width, h);

	PHALCON_INIT_VAR(dst);
	ZVAL_LONG(dst, 0);

	PHALCON_CALL_FUNCTION(NULL, "imagecopy", 8, reflection, image, dst, dst, dst, dst, image_width, image_height);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, 1);

	for (offset = 0; h0 >= offset; offset++) {
		PHALCON_INIT_NVAR(src_y);
		ZVAL_LONG(src_y, h1 - offset - 1);

		PHALCON_INIT_NVAR(dst_y);
		ZVAL_LONG(dst_y, h1 + offset);

		if (zend_is_true(fade_in)) {
			num = int_opacity + (stepping * (h0 - offset));

			PHALCON_INIT_NVAR(dst_opacity);
			ZVAL_LONG(dst_opacity, (int)(num+0.5));
		} else {
			num = int_opacity + (stepping * offset);

			PHALCON_INIT_NVAR(dst_opacity);
			ZVAL_LONG(dst_opacity, (int)(num+0.5));
		}

		PHALCON_INIT_NVAR(line);
		phalcon_call_method_p2(line, this_ptr, "_create", image_width, tmp);

		PHALCON_CALL_FUNCTION(NULL, "imagecopy", 8, line, image, dst, dst, dst, src_y, image_width, tmp);
		PHALCON_CALL_FUNCTION(NULL, "imagefilter", 6, line, filtertype, dst, dst, dst, dst_opacity);

		PHALCON_CALL_FUNCTION(NULL, "imagecopy", 8, filtertype, line, dst, dst_y, dst, dst, image_width, tmp);
	}

	phalcon_call_func_p1_noret("imagedestroy", image);
	phalcon_update_property_this(this_ptr, SL("_image"), reflection TSRMLS_CC);

	PHALCON_INIT_NVAR(w);
	phalcon_call_func_p1(w, "imagesx", reflection);

	PHALCON_INIT_NVAR(h);
	phalcon_call_func_p1(h, "imagesy", reflection);

	phalcon_update_property_this(this_ptr, SL("_width"), w TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_height"), h TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Execute a watermarking.
 *
 * @param Phalcon\Image\Adapter $watermark
 * @param int $offset_x
 * @param int $offset_y
 * @param int $opacity
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _watermark) {

	zval *watermark, *offset_x = NULL, *offset_y = NULL, *opacity = NULL, *ox = NULL, *oy = NULL, *op = NULL;
	zval  *image, *overlay, *saveflag, *width, *height, *color, *tmp = NULL, *effect, *blendmode, *ret;
	int int_opacity;
	double num;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &watermark, &offset_x, &offset_y, &opacity);

	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_INIT_VAR(overlay);
	phalcon_call_method(overlay, watermark, "getImage");

	PHALCON_INIT_VAR(saveflag);
	ZVAL_BOOL(saveflag, 1);

	phalcon_call_func_p2_noret("imagesavealpha", overlay, saveflag);

	PHALCON_INIT_VAR(width);
	phalcon_call_func_p1(width, "imagesx", overlay);

	PHALCON_INIT_VAR(height);
	phalcon_call_func_p1(height, "imagesy", overlay);

	int_opacity = Z_LVAL_P(opacity);
	if (int_opacity < 100) {
		num = (int_opacity * 127 / 100) - 127;

		if (num < 0) {
			num = num * -1;
		}

		int_opacity = num;

		PHALCON_INIT_VAR(op);
		ZVAL_LONG(op, int_opacity);

		PHALCON_INIT_NVAR(tmp);
		ZVAL_LONG(tmp, 127);


		PHALCON_INIT_VAR(color);
		phalcon_call_func_p5(color, "imagecolorallocatealpha", overlay, tmp, tmp, tmp, op);

		PHALCON_INIT_VAR(effect);
		if (zend_get_constant(SL("IMG_EFFECT_OVERLAY"), effect TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}

		phalcon_call_func_p2_noret("imagelayereffect", overlay, effect);

		PHALCON_INIT_NVAR(tmp);
		ZVAL_LONG(tmp, 0);

		PHALCON_CALL_FUNCTION(NULL, "imagefilledrectangle", 6, overlay, tmp, tmp, width, height, color);
	}

	PHALCON_INIT_NVAR(blendmode);
	ZVAL_LONG(blendmode, 1);
	phalcon_call_func_p2_noret("imagealphablending", image, blendmode);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, 0);

	PHALCON_INIT_VAR(ret);
	PHALCON_CALL_FUNCTION(ret, "imagecopy", 8, image, overlay, offset_x, offset_y, tmp, tmp, width, height);

	if (zend_is_true(ret)) {
		ZVAL_BOOL(return_value, 1);
	} else {
		ZVAL_BOOL(return_value, 0);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Execute a background.
 *
 * @param int $r
 * @param int $g
 * @param int $b
 * @param int $opacity
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _background) {

	zval *r, *g, *b, *opacity, *op;
	zval  *image, *background, *width, *height, *color, *tmp, *blendmode, *ret;
	int int_opacity;
	double num;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &r, &g, &b, &opacity);

	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_OBS_VAR(width);
	phalcon_read_property_this(&width, this_ptr, SL("_width"), PH_NOISY_CC);

	PHALCON_OBS_VAR(height);
	phalcon_read_property_this(&height, this_ptr, SL("_height"), PH_NOISY_CC);

	int_opacity = Z_LVAL_P(opacity);

	num = (int_opacity * 127 / 100) - 127;

	if (num < 0) {
		num = num * -1;
	}

	int_opacity = num;

	PHALCON_INIT_VAR(background);
	phalcon_call_method_p2(background, this_ptr, "_create", width, height);

	PHALCON_INIT_VAR(op);
	ZVAL_LONG(op, int_opacity);

	PHALCON_INIT_VAR(color);
	phalcon_call_func_p5(color, "imagecolorallocatealpha", background, r, g, b, op);

	PHALCON_INIT_VAR(tmp);
	ZVAL_LONG(tmp, 0);

	PHALCON_CALL_FUNCTION(NULL, "imagefilledrectangle", 6, background, tmp, tmp, width, height, color);

	PHALCON_INIT_VAR(blendmode);
	ZVAL_BOOL(blendmode, 1);

	phalcon_call_func_p2_noret("imagealphablending", background, blendmode);

	PHALCON_INIT_VAR(ret);
	PHALCON_CALL_FUNCTION(ret, "imagecopy", 8, background, image, tmp, tmp, tmp, tmp, width, height);

	if (zend_is_true(ret)) {
		phalcon_call_func_p1_noret("imagedestroy", image);
		phalcon_update_property_this(this_ptr, SL("_image"), background TSRMLS_CC);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Execute a save.
 *
 * @param string $file
 * @param int $quality
 * @return boolean
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _save) {

	zval *file = NULL, *quality = NULL, *exception_message, *q = NULL;
	zval *ret, *extension, *type, *mime, *constant, *image;
	const char *func_name = "imagegif";
	char *ext;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &file, &quality);

	PHALCON_INIT_VAR(constant);
	if (zend_get_constant(SL("PATHINFO_EXTENSION"), constant TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}

	PHALCON_INIT_VAR(ret);
	phalcon_call_func_p2(ret, "pathinfo", file, constant);

	PHALCON_INIT_VAR(extension);
	phalcon_fast_strtolower(extension, ret);

	ext = Z_STRVAL_P(extension);

	if (strncmp(ext, "gif", 3) == 0) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 1);
			
		PHALCON_INIT_NVAR(q);

		func_name = "imagegif";
	} else if (strncmp(ext, "jpg", 3) == 0 || strncmp(ext, "jpeg", 4) == 0) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 2);

		PHALCON_CPY_WRT(q, quality);

		func_name = "imagejpeg";
	} else if (strncmp(ext, "png", 3) == 0) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 3);
			
		PHALCON_INIT_NVAR(q);
        ZVAL_LONG(q, 9);

		func_name = "imagepng";
	} else {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Installed GD does not support '", extension, "' images");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_image_exception_ce, exception_message);
		return;
	}
	
	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);

	if (Z_TYPE_P(quality) == IS_LONG) {
		PHALCON_INIT_NVAR(ret);
		phalcon_call_func_p3(ret, func_name, image, file, q);
	} else {
		PHALCON_INIT_NVAR(ret);
		phalcon_call_func_p2(ret, func_name, image, file);
	}

	if (zend_is_true(ret)) {
		phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

		PHALCON_INIT_VAR(mime);
		phalcon_call_func_p1(mime, "image_type_to_mime_type", type);
		phalcon_update_property_this(this_ptr, SL("_mime"), mime TSRMLS_CC);

		ZVAL_BOOL(return_value, 1);
	} else {
		ZVAL_BOOL(return_value, 0);
	}

	RETURN_MM();
}

/**
 * Execute a render.
 *
 * @param string $type
 * @param int $quality
 * @return string
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _render) {

	zval *extension = NULL, *quality = NULL, *exception_message, *q = NULL;
	zval *file, *ret = NULL, *type, *mime, *image;
	const char *func_name = "imagegif";
	char *ext;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &extension, &quality);

	PHALCON_INIT_VAR(file);

	PHALCON_INIT_VAR(ret);
	phalcon_fast_strtolower(ret, extension);

	ext = Z_STRVAL_P(ret);

	if (strncmp(ext, "gif", 3) == 0) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 1);
			
		PHALCON_INIT_NVAR(q);

		func_name = "imagegif";
	} else if (strncmp(ext, "jpg", 3) == 0 || strncmp(ext, "jpeg", 4) == 0) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 2);

		PHALCON_CPY_WRT(q, quality);

		func_name = "imagejpeg";
	} else if (strncmp(ext, "png", 3) == 0) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 3);
			
		PHALCON_INIT_NVAR(q);
		ZVAL_LONG(q, 9);

		func_name = "imagepng";
	} else {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Installed GD does not support '", extension, "' images");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_image_exception_ce, exception_message);
		return;
	}
	
	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);

	phalcon_ob_start(TSRMLS_C);

	if (Z_TYPE_P(quality) == IS_LONG) {
		PHALCON_INIT_NVAR(ret);
		phalcon_call_func_p3(ret, func_name, image, file, q);
	} else {
		PHALCON_INIT_NVAR(ret);
		phalcon_call_func_p2(ret, func_name, image, file);
	}

	phalcon_ob_get_contents(return_value TSRMLS_CC);
	phalcon_ob_end_clean(TSRMLS_C);

	if (zend_is_true(ret)) {
		phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

		PHALCON_INIT_VAR(mime);
		phalcon_call_func_p1(mime, "image_type_to_mime_type", type);
		phalcon_update_property_this(this_ptr, SL("_mime"), mime TSRMLS_CC);
	}

	RETURN_MM();
}

/**
 * Create an empty image with the given width and height.
 *
 * @param int $width
 * @param int $height
 * @return resource
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _create) {

	zval *width, *height, *image, *blendmode, *saveflag;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &width, &height);

	PHALCON_INIT_VAR(image);
	phalcon_call_func_p2(image, "imagecreatetruecolor", width, height);

	if (Z_TYPE_P(image) != IS_RESOURCE) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Call imagecreatetruecolor failure");
		return;
	}

	PHALCON_INIT_VAR(blendmode);
	ZVAL_BOOL(blendmode, 0);

	PHALCON_INIT_VAR(saveflag);
	ZVAL_BOOL(saveflag, 1);

	phalcon_call_func_p2_noret("imagealphablending", image, blendmode);
	phalcon_call_func_p2_noret("imagesavealpha", image, saveflag);

	RETURN_CCTOR(image);
}

/**
 * Destroys the loaded image to free up resources.
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, __destruct){

	zval *image = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);

	if (!image && Z_TYPE_P(image) == IS_RESOURCE) {
		phalcon_call_func_p1_noret("imagedestroy", image);
	}
	
	PHALCON_MM_RESTORE();
}

