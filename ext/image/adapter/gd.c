
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
 *	$image = new Phalcon\Image\Adapter\Imagick("upload/test.jpg");
 *	$image->resize(200, 200)->rotate(90)->crop(100, 100);
 *	if ($image->save()) {
 *		echo 'success';
 *	}
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
		PHALCON_INIT_NVAR(gd_info);
		phalcon_call_func(gd_info, "gd_info");

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
		PHALCON_CONCAT_SVSVS(exception_message, "Phalcon\\Image\\Adapter\\GD requires GD version '", version ,"' or greater, you have '", gd_version, ",");
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
	zval *image = NULL, *tmp_image = NULL, *ret = NULL, *dst;
	int tmp_width, tmp_height, tmp_pre_width, tmp_pre_height, tmp_reduction_width, tmp_reduction_height;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &width, &height);

	PHALCON_OBS_VAR(ori_width);
	phalcon_read_property_this(&ori_width, this_ptr, SL("_width"), PH_NOISY_CC);

	PHALCON_OBS_VAR(ori_height);
	phalcon_read_property_this(&ori_height, this_ptr, SL("_height"), PH_NOISY_CC);

	tmp_width = phalcon_get_intval(width);
	tmp_height = phalcon_get_intval(height);

	tmp_pre_width = phalcon_get_intval(ori_width);
	tmp_pre_height = phalcon_get_intval(ori_height);

	PHALCON_INIT_VAR(pre_width);
	ZVAL_LONG(pre_width, tmp_pre_width);

	PHALCON_INIT_VAR(pre_height);
	ZVAL_LONG(pre_height, tmp_pre_height);

	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_INIT_VAR(dst);
	ZVAL_LONG(dst, 0);

	if (tmp_width > (tmp_pre_width / 2) && tmp_height > (tmp_pre_height / 2)) {
		tmp_reduction_width = (int)(tmp_width*1.1 + 0.5);

		PHALCON_INIT_VAR(reduction_width);
		ZVAL_LONG(reduction_width, tmp_reduction_width);

		tmp_reduction_height = (int)(tmp_height*1.1 + 0.5);

		PHALCON_INIT_VAR(reduction_height);
		ZVAL_LONG(reduction_height, tmp_reduction_height);

		while ((tmp_pre_width / 2 > tmp_reduction_width) && (tmp_pre_height / 2 > tmp_reduction_height)) {
			tmp_pre_width = (int)(tmp_pre_width/2);
			tmp_pre_height = (int)(tmp_pre_height/2);
		}

		PHALCON_INIT_NVAR(pre_width);
		ZVAL_LONG(pre_width, tmp_pre_width);

		PHALCON_INIT_NVAR(pre_height);
		ZVAL_LONG(pre_height, tmp_pre_height);

		PHALCON_INIT_VAR(tmp_image);

		phalcon_call_method_p2(tmp_image, this_ptr, "_create", pre_width, pre_height);

		PHALCON_INIT_NVAR(ret);
		PHALCON_CALL_FUNCTION(ret, &ret, "imagecopyresized", 10, tmp_image, image, dst, dst, dst, dst, pre_width, pre_height, ori_width, ori_height);
		
		if (zend_is_true(ret)) {
			phalcon_call_func_p1_noret("imagedestroy", image);
			PHALCON_CPY_WRT(image, tmp_image);
		}
	}

	PHALCON_INIT_NVAR(tmp_image);
	phalcon_call_method_p2(tmp_image, this_ptr, "_create", width, height);

	PHALCON_INIT_NVAR(ret);
	PHALCON_CALL_FUNCTION(ret, &ret, "imagecopyresampled", 10, tmp_image, image, dst, dst, dst, dst, width, height, pre_width, pre_height);

	if (zend_is_true(ret)) {
		phalcon_call_func_p1_noret("imagedestroy", image);
		phalcon_update_property_this(this_ptr, SL("_image"), tmp_image TSRMLS_CC);

		phalcon_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);
	}

	PHALCON_MM_RESTORE();
}

/**
 * This method scales the images using liquid rescaling method. Only support Imagick
 *
 * @param int $width   new width
 * @param int $height  new height
 * @param int $delta_x How much the seam can traverse on x-axis. Passing 0 causes the seams to be straight. 
 * @param int $rigidity Introduces a bias for non-straight seams. This parameter is typically 0.
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _liquidRescale){

	zval *width, *height, *delta_x = NULL, *rigidity = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &width, &height, &delta_x, &rigidity);

	PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "The GD does not support liquidRescale");

	RETURN_THIS();
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
	zval *image, *tmp_image = NULL, *dst, *ret = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &width, &height, &offset_x, &offset_y);

	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_INIT_NVAR(tmp_image);
	phalcon_call_method_p2(tmp_image, this_ptr, "_create", width, height);

	PHALCON_INIT_VAR(dst);
	ZVAL_LONG(dst, 0);

	PHALCON_INIT_NVAR(ret);
	PHALCON_CALL_FUNCTION(ret, &ret, "imagecopyresampled", 10, tmp_image, image, dst, dst, offset_x, offset_y, width, height, width, height);

	if (zend_is_true(ret)) {
		phalcon_call_func_p1_noret("imagedestroy", image);
		phalcon_update_property_this(this_ptr, SL("_image"), tmp_image TSRMLS_CC);

		phalcon_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Execute a rotation.
 *
 * @param int $degrees
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _rotate) {

	zval *degrees;
	zval *bundled = NULL, *image = NULL, *tmp_image, *color, *alpha, *transparent, *ignore_transparent, *saveflag, *ret;
	zval *w, *h, *dst, *pct;
	int tmp_degrees;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &degrees);

	PHALCON_SEPARATE_PARAM(degrees);

	PHALCON_INIT_VAR(color);
	ZVAL_LONG(color, 0);

	PHALCON_INIT_VAR(alpha);
	ZVAL_LONG(alpha, 127);

	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_INIT_VAR(transparent);
	phalcon_call_func_p5(transparent, "imagecolorallocatealpha", image, color, color, color, alpha);

	tmp_degrees = phalcon_get_intval(degrees);

	PHALCON_INIT_NVAR(degrees);
	ZVAL_LONG(degrees, 360 - tmp_degrees);

	PHALCON_INIT_VAR(ignore_transparent);
	ZVAL_LONG(ignore_transparent, 1);

	PHALCON_INIT_VAR(tmp_image);
	phalcon_call_func_p4(tmp_image, "imagerotate", image, degrees, transparent, ignore_transparent);

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

			PHALCON_CALL_FUNCTION(NULL, NULL, "imagecopy", 8, flipped_image, image, dst_x, dst_y, src_x, src_y, src_width, src_height);
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

			PHALCON_CALL_FUNCTION(NULL, NULL, "imagecopy", 8, flipped_image, image, dst_x, dst_y, src_x, src_y, src_width, src_height);
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

	a = phalcon_get_intval(amount);

	if (a > 100) {
		a = 100;
	} else if (a < 1) {
		a = 1;
	}

	b = -18 + (a * 0.08);

	if (b < 0) {
		b = b * -1;
	}

	PHALCON_INIT_NVAR(tmp_amount);
	ZVAL_DOUBLE(tmp_amount, b);

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
	ZVAL_DOUBLE(tmp_amount, b);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, 0);

	PHALCON_INIT_VAR(ret);
	phalcon_call_func_p4(ret, "imageconvolution", image, matrix, tmp_amount, tmp);

	if (zend_is_true(ret)) {

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

	zval *height, *opacity, *fade_in, *o = NULL, *tmp = NULL;
	zval *reflection, *line = NULL, *image, *image_width, *image_height, *dst, *src_y = NULL, *dst_y = NULL, *dst_opacity = NULL, *filtertype = NULL;
	int h0, h1, tmp_opacity, int_opacity, offset;
	double stepping;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &height, &opacity, &fade_in);

	PHALCON_SEPARATE_PARAM(height);

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

	h0 = phalcon_get_intval(height);
	h1 = phalcon_get_intval(image_height);

	tmp_opacity = phalcon_get_intval(opacity);

	tmp_opacity = (int)((tmp_opacity * 127 / 100) - 127 + 0.5);

	if (tmp_opacity < 0) {
		tmp_opacity = tmp_opacity * -1;
	}

	if (tmp_opacity < 127) {
		stepping = (127 - tmp_opacity) / h0;
	} else {
		stepping = 127 / h0;
	}

	PHALCON_INIT_NVAR(height);
	ZVAL_DOUBLE(height, h0 + h1);

	PHALCON_INIT_VAR(reflection);
	phalcon_call_method_p2(reflection, this_ptr, "_create", image_width, height);

	PHALCON_INIT_VAR(dst);
	ZVAL_LONG(dst, 0);

	PHALCON_CALL_FUNCTION(NULL, NULL, "imagecopy", 8, reflection, image, dst, dst, dst, dst, image_width, image_height);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, 1);

	for (offset = 0; h0 >= offset; offset++) {
		PHALCON_INIT_NVAR(src_y);
		ZVAL_LONG(src_y, h1 - offset - 1);

		PHALCON_INIT_NVAR(dst_y);
		ZVAL_LONG(dst_y, h1 + offset);

		if (zend_is_true(fade_in)) {

			int_opacity = (int)(tmp_opacity + (stepping * (h0 - offset)) + 0.5);

			PHALCON_INIT_NVAR(dst_opacity);
			ZVAL_LONG(dst_opacity, int_opacity);
		} else {
			int_opacity = (int)(tmp_opacity + (stepping * offset) + 0.5);

			PHALCON_INIT_NVAR(dst_opacity);
			ZVAL_LONG(dst_opacity, int_opacity);
		}

		PHALCON_INIT_NVAR(line);
		phalcon_call_method_p2(line, this_ptr, "_create", image_width, tmp);

		phalcon_call_func_p8_noret("imagecopy", line, image, dst, dst, dst, src_y, image_width, tmp);
		phalcon_call_func_p6_noret("imagefilter", line, filtertype, dst, dst, dst, dst_opacity);

		phalcon_call_func_p8_noret("imagecopy", reflection, line, dst, dst_y, dst, dst, image_width, tmp);
	}

	phalcon_call_func_p1_noret("imagedestroy", image);
	phalcon_update_property_this(this_ptr, SL("_image"), reflection TSRMLS_CC);

	PHALCON_INIT_NVAR(image_width);
	phalcon_call_func_p1(image_width, "imagesx", reflection);

	PHALCON_INIT_NVAR(image_height);
	phalcon_call_func_p1(image_height, "imagesy", reflection);

	phalcon_update_property_this(this_ptr, SL("_width"), image_width TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_height"), image_height TSRMLS_CC);

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

	PHALCON_SEPARATE_PARAM(watermark);

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

		phalcon_call_func_p6_noret("imagefilledrectangle", overlay, tmp, tmp, width, height, color);
	}

	PHALCON_INIT_NVAR(blendmode);
	ZVAL_LONG(blendmode, 1);
	phalcon_call_func_p2_noret("imagealphablending", image, blendmode);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, 0);

	PHALCON_INIT_VAR(ret);
	phalcon_call_func_p8(ret, "imagecopy", image, overlay, offset_x, offset_y, tmp, tmp, width, height);

	if (zend_is_true(ret)) {
		ZVAL_BOOL(return_value, 1);
	} else {
		ZVAL_BOOL(return_value, 0);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Composite one image onto another

 *
 * @param Phalcon\Image\Adapter $mask  mask Image instance
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _mask){

	zval *mask, *image, *mask_image, *mask_image_width, *mask_image_height, *newimage, *image_width, *image_height, *saveflag, *color, *c, *alpha = NULL;
	zval *r = NULL, *g = NULL, *b = NULL, *index = NULL, *index2 = NULL, *zx = NULL, *zy = NULL, *red = NULL;
	zval *temp_image;
	int x, y, w, h, i;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &mask);
	
	PHALCON_SEPARATE_PARAM(mask);

	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_INIT_VAR(mask_image);
	phalcon_call_method(mask_image, mask, "getImage");

	PHALCON_INIT_VAR(mask_image_width);
	phalcon_call_func_p1(mask_image_width, "imagesx", mask_image);

	PHALCON_INIT_VAR(mask_image_height);
	phalcon_call_func_p1(mask_image_height, "imagesy", mask_image);

	PHALCON_OBS_VAR(image_width);
	phalcon_read_property_this(&image_width, this_ptr, SL("_width"), PH_NOISY_CC);

	PHALCON_OBS_VAR(image_height);
	phalcon_read_property_this(&image_height, this_ptr, SL("_height"), PH_NOISY_CC);

	PHALCON_INIT_VAR(newimage);
	phalcon_call_method_p2(newimage, this_ptr, "_create", image_width, image_height);

	PHALCON_INIT_VAR(saveflag);
	ZVAL_BOOL(saveflag, 1);

	phalcon_call_func_p2_noret("imagesavealpha", newimage, saveflag);

	PHALCON_INIT_VAR(c);
	ZVAL_LONG(c, 0);

	PHALCON_INIT_VAR(alpha);
	ZVAL_LONG(alpha, 127);

	PHALCON_INIT_VAR(color);
	phalcon_call_func_p5(color, "imagecolorallocatealpha", newimage, c, c, c, alpha);

	phalcon_call_func_p4_noret("imagefill", newimage, c, c, color);

	if(!PHALCON_IS_EQUAL(image_width, mask_image_width) || !PHALCON_IS_EQUAL(image_height, mask_image_height)) {

		PHALCON_INIT_VAR(temp_image);
		phalcon_call_func_p2(temp_image, "imagecreatetruecolor", image_width, image_height);

		PHALCON_CALL_FUNCTION(NULL, NULL, "imagecopyresampled", 10, temp_image, mask_image, c, c, c, c, image_width, image_height, mask_image_width, mask_image_height);
		
		phalcon_call_func_p1_noret("imagedestroy", mask_image);
		PHALCON_CPY_WRT(mask_image, temp_image);
	}
	
	w = phalcon_get_intval(image_width);
	h = phalcon_get_intval(image_height);

	for (x=0; x < w; x++) {
		PHALCON_INIT_NVAR(zx);
		ZVAL_LONG(zx, x);
		for (y=0; y < h; y++) {
			PHALCON_INIT_NVAR(zy);
			ZVAL_LONG(zy, y);

			PHALCON_INIT_NVAR(index);
			phalcon_call_func_p3(index, "imagecolorat", mask_image, zx, zy);

			PHALCON_INIT_NVAR(alpha);
			phalcon_call_func_p2(alpha, "imagecolorsforindex", mask_image, index);

			if (phalcon_array_isset_string(alpha, SS("red"))) {
				PHALCON_OBS_VAR(red);
				phalcon_array_fetch_string(&red, alpha, SL("red"), PH_NOISY);

				i = (int)(127 - (phalcon_get_intval(red) / 2));

				PHALCON_INIT_NVAR(alpha);
				ZVAL_LONG(alpha, i);
			}

			PHALCON_INIT_NVAR(index2);
			phalcon_call_func_p3(index2, "imagecolorat", image, zx, zy);

			PHALCON_INIT_NVAR(c);
			phalcon_call_func_p2(c, "imagecolorsforindex", image, index2);

			if (phalcon_array_isset_string(c, SS("red"))) {
				PHALCON_OBS_VAR(r);
				phalcon_array_fetch_string(&r, c, SL("red"), PH_NOISY);
			}
			
			if (phalcon_array_isset_string(c, SS("green"))) {
				PHALCON_OBS_VAR(g);
				phalcon_array_fetch_string(&g, c, SL("green"), PH_NOISY);
			}
			
			if (phalcon_array_isset_string(c, SS("blue"))) {
				PHALCON_OBS_VAR(b);
				phalcon_array_fetch_string(&b, c, SL("blue"), PH_NOISY);
			}

			PHALCON_INIT_VAR(color);
			phalcon_call_func_p5(color, "imagecolorallocatealpha", newimage, r, g, b, alpha);

			phalcon_call_func_p4_noret("imagesetpixel", newimage, zx, zy, color);


		}
	}

	phalcon_update_property_this(this_ptr, SL("_image"), newimage TSRMLS_CC);
	phalcon_call_func_p1_noret("imagedestroy", image);
	phalcon_call_func_p1_noret("imagedestroy", mask_image);

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

	phalcon_call_func_p6_noret("imagefilledrectangle", background, tmp, tmp, width, height, color);

	PHALCON_INIT_VAR(blendmode);
	ZVAL_BOOL(blendmode, 1);

	phalcon_call_func_p2_noret("imagealphablending", background, blendmode);

	PHALCON_INIT_VAR(ret);
	phalcon_call_func_p8(ret, "imagecopy", background, image, tmp, tmp, tmp, tmp, width, height);

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

