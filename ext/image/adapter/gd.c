
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
  |          Vladimir Kolesnikov <vladimir@free-sevastopol.com>            |
  +------------------------------------------------------------------------+
*/


#include "image/adapter/gd.h"
#include "image.h"
#include "image/adapter.h"
#include "image/adapterinterface.h"
#include "image/exception.h"

#include <ext/standard/php_versioning.h>

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
#include "kernel/file.h"

/**
 * Phalcon\Image\Adapter\GD
 *
 * Image manipulation support. Allows images to be resized, cropped, etc.
 *
 *<code>
 *	$image = new Phalcon\Image\Adapter\GD("upload/test.jpg");
 *	$image->resize(200, 200)->rotate(90)->crop(100, 100);
 *	if ($image->save()) {
 *		echo 'success';
 *	}
 *</code>
 */
zend_class_entry *phalcon_image_adapter_gd_ce;

PHP_METHOD(Phalcon_Image_Adapter_GD, check);
PHP_METHOD(Phalcon_Image_Adapter_GD, __construct);
PHP_METHOD(Phalcon_Image_Adapter_GD, _resize);
PHP_METHOD(Phalcon_Image_Adapter_GD, _liquidRescale);
PHP_METHOD(Phalcon_Image_Adapter_GD, _crop);
PHP_METHOD(Phalcon_Image_Adapter_GD, _rotate);
PHP_METHOD(Phalcon_Image_Adapter_GD, _flip);
PHP_METHOD(Phalcon_Image_Adapter_GD, _sharpen);
PHP_METHOD(Phalcon_Image_Adapter_GD, _reflection);
PHP_METHOD(Phalcon_Image_Adapter_GD, _watermark);
PHP_METHOD(Phalcon_Image_Adapter_GD, _text);
PHP_METHOD(Phalcon_Image_Adapter_GD, _mask);
PHP_METHOD(Phalcon_Image_Adapter_GD, _background);
PHP_METHOD(Phalcon_Image_Adapter_GD, _blur);
PHP_METHOD(Phalcon_Image_Adapter_GD, _pixelate);
PHP_METHOD(Phalcon_Image_Adapter_GD, _save);
PHP_METHOD(Phalcon_Image_Adapter_GD, _render);
PHP_METHOD(Phalcon_Image_Adapter_GD, _create);
PHP_METHOD(Phalcon_Image_Adapter_GD, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__create, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_image_adapter_gd_method_entry[] = {
	PHP_ME(Phalcon_Image_Adapter_GD, check, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Image_Adapter_GD, __construct, arginfo_phalcon_image_adapter_gd___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Image_Adapter_GD, _resize, arginfo_phalcon_image_adapter__resize, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, _liquidRescale, arginfo_phalcon_image_adapter__liquidrescale, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, _crop, arginfo_phalcon_image_adapter__crop, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, _rotate, arginfo_phalcon_image_adapter__rotate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, _flip, arginfo_phalcon_image_adapter__flip, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, _sharpen, arginfo_phalcon_image_adapter__sharpen, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, _reflection, arginfo_phalcon_image_adapter__reflection, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, _watermark, arginfo_phalcon_image_adapter__watermark, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, _text, arginfo_phalcon_image_adapter__text, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, _mask, arginfo_phalcon_image_adapter__mask, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, _background, arginfo_phalcon_image_adapter__background, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, _blur, arginfo_phalcon_image_adapter__blur, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, _pixelate, arginfo_phalcon_image_adapter__pixelate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, _save, arginfo_phalcon_image_adapter__save, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, _render, arginfo_phalcon_image_adapter__render, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, _create, arginfo_phalcon_image_adapter_gd__create, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_GD, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};

/**
 * Phalcon\Image\Adapter\GD initializer
 */
PHALCON_INIT_CLASS(Phalcon_Image_Adapter_GD){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, GD, image_adapter_gd, phalcon_image_adapter_ce,  phalcon_image_adapter_gd_method_entry, 0);

	zend_class_implements(phalcon_image_adapter_gd_ce TSRMLS_CC, 1, phalcon_image_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Checks if GD is enabled
 *
 * @return  boolean
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, check){

	zval *ret = NULL, *gd_info = NULL, *gd_version, *version, *exception_message;
	zval *pattern, *matches;
	int rc;

	PHALCON_MM_GROW();

	if (phalcon_function_exists_ex(SS("gd_info") TSRMLS_CC) == FAILURE) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "GD is either not installed or not enabled, check your configuration");
		return;
	}

	PHALCON_INIT_VAR(gd_version);
	if (!zend_get_constant(SL("GD_VERSION"), gd_version TSRMLS_CC)) {
		PHALCON_CALL_FUNCTION(&gd_info, "gd_info");

		if (phalcon_array_isset_string_fetch(&gd_version, gd_info, SS("GD Version"))) {

			PHALCON_INIT_VAR(matches);
		
			PHALCON_INIT_VAR(pattern);
			ZVAL_STRING(pattern, "#\\d+\\.\\d+(?:\\.\\d+)?#", 1);

			PHALCON_INIT_VAR(ret);
			RETURN_MM_ON_FAILURE(phalcon_preg_match(ret, pattern, gd_version, matches TSRMLS_CC));

			if (zend_is_true(ret)) {
				if (!phalcon_array_isset_long_fetch(&version, matches, 0)) {
					PHALCON_INIT_VAR(version);
					ZVAL_EMPTY_STRING(version);
				}
			} else {
				PHALCON_INIT_VAR(version);
				ZVAL_EMPTY_STRING(version);
			}
		}
		else {
			version = gd_version;
		}
	}

	rc = php_version_compare(Z_STRVAL_P(gd_version), "2.0.1");

	if (-1 == rc) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SV(exception_message, "Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have '", gd_version);
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_image_exception_ce, exception_message);
		return;
	}

	PHALCON_INIT_NVAR(ret);
	ZVAL_TRUE(ret);
	phalcon_update_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked"), ret TSRMLS_CC);

	RETURN_MM_TRUE;
}

/**
 * Phalcon\Image\GD constructor
 *
 * @param string $file
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, __construct){

	zval *file, *width = NULL, *height = NULL, *exception_message;
	zval *checked, *realpath, *type, *mime = NULL, *image = NULL, *imageinfo = NULL;
	zval *saveflag, *blendmode;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &file, &width, &height);

	if (Z_TYPE_P(file) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "file parameter should be a string");
		return;
	}

	checked = phalcon_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);

	if (!zend_is_true(checked)) {
		PHALCON_CALL_CE_STATIC(NULL, phalcon_image_adapter_gd_ce, "check");
	}
	
	phalcon_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);

	if (phalcon_file_exists(file TSRMLS_CC) != FAILURE) {
		PHALCON_INIT_VAR(realpath);
		phalcon_realpath(realpath, file TSRMLS_CC);
		if (unlikely(Z_TYPE_P(realpath) != IS_STRING)) {
			convert_to_string(realpath);
		}

		phalcon_update_property_this(this_ptr, SL("_realpath"), realpath TSRMLS_CC);

		PHALCON_CALL_FUNCTION(&imageinfo, "getimagesize", realpath);

		if (width) {
			PHALCON_SEPARATE_PARAM(width);
		}

		if (height) {
			PHALCON_SEPARATE_PARAM(height);
		}

		if (phalcon_array_isset_long_fetch(&width, imageinfo, 0)) {
			phalcon_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
		}

		if (phalcon_array_isset_long_fetch(&height, imageinfo, 1)) {
			phalcon_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);
		}

		if (phalcon_array_isset_long_fetch(&type, imageinfo, 2)) {
			convert_to_long(type);
			phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
		}
		else {
			PHALCON_INIT_VAR(type);
			ZVAL_LONG(type, -1);
		}

		if (phalcon_array_isset_string_fetch(&mime, imageinfo, SS("mime"))) {
			convert_to_string(mime);
			phalcon_update_property_this(this_ptr, SL("_mime"), mime TSRMLS_CC);
		}

		assert(Z_TYPE_P(type) == IS_LONG);

		switch (Z_LVAL_P(type)) {
			case 1: // GIF
				PHALCON_CALL_FUNCTION(&image, "imagecreatefromgif", realpath);
				break;

			case 2: // JPEG
				PHALCON_CALL_FUNCTION(&image, "imagecreatefromjpeg", realpath);
				break;

			case 3: // PNG
				PHALCON_CALL_FUNCTION(&image, "imagecreatefrompng", realpath);
				break;

			default:
				if (mime) {
					assert(Z_TYPE_P(mime) == IS_STRING);
					zend_throw_exception_ex(phalcon_image_exception_ce, 0 TSRMLS_CC, "Installed GD does not support '%s' images", Z_STRVAL_P(mime));
				}
				else {
					zend_throw_exception_ex(phalcon_image_exception_ce, 0 TSRMLS_CC, "Installed GD does not support such images");
				}

				RETURN_MM();
		}

		if (Z_TYPE_P(image) != IS_RESOURCE) {
			assert(Z_TYPE_P(realpath) == IS_STRING);
			zend_throw_exception_ex(phalcon_image_exception_ce, 0 TSRMLS_CC, "Failed to create image from file '%s'", Z_STRVAL_P(realpath));
			RETURN_MM();
		}

		PHALCON_INIT_VAR(saveflag);
		ZVAL_TRUE(saveflag);

		PHALCON_CALL_FUNCTION(NULL, "imagesavealpha", image, saveflag);
	} else if (width && height) {
		PHALCON_CALL_FUNCTION(&image, "imagecreatetruecolor", width, height);

		if (Z_TYPE_P(image) != IS_RESOURCE) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "imagecreatetruecolor() failed");
			return;
		}

		PHALCON_INIT_VAR(blendmode);
		ZVAL_TRUE(blendmode);

		PHALCON_INIT_VAR(saveflag);
		ZVAL_TRUE(saveflag);

		PHALCON_CALL_FUNCTION(NULL, "imagealphablending", image, blendmode);
		PHALCON_CALL_FUNCTION(NULL, "imagesavealpha", image, saveflag);
		
		phalcon_update_property_this(this_ptr, SL("_realpath"), file TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);

		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 3);

		phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

		PHALCON_INIT_VAR(mime);
		ZVAL_STRING(mime, "image/png", 1);

		phalcon_update_property_this(this_ptr, SL("_mime"), mime TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Failed to create image from file '", file, "'");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_image_exception_ce, exception_message);
		return;
	}

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

	zval *width, *height;
	zval *image = NULL, *tmp_image = NULL;
	zval *ori_width, *ori_height, *pre_width, *pre_height, *reduction_width, *reduction_height, *ret = NULL, *dst;
	int tmp_width, tmp_height, tmp_pre_width, tmp_pre_height, tmp_reduction_width, tmp_reduction_height;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &width, &height);

	image = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	if (PHP_VERSION_ID < 50500) {
		ori_width      = phalcon_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY TSRMLS_CC);
		ori_height     = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY TSRMLS_CC);

		tmp_width      = phalcon_get_intval(width);
		tmp_height     = phalcon_get_intval(height);

		tmp_pre_width  = phalcon_get_intval(ori_width);
		tmp_pre_height = phalcon_get_intval(ori_height);

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

			PHALCON_INIT_VAR(pre_width);
			ZVAL_LONG(pre_width, tmp_pre_width);

			PHALCON_INIT_VAR(pre_height);
			ZVAL_LONG(pre_height, tmp_pre_height);

			PHALCON_CALL_METHOD(&tmp_image, this_ptr, "_create", pre_width, pre_height);

			PHALCON_CALL_FUNCTION(&ret, "imagecopyresized", tmp_image, image, dst, dst, dst, dst, pre_width, pre_height, ori_width, ori_height);

			if (zend_is_true(ret)) {
				PHALCON_CALL_FUNCTION(NULL, "imagedestroy", image);
				PHALCON_CPY_WRT_CTOR(image, tmp_image);
			}
		} else {
			PHALCON_INIT_VAR(pre_width);
			ZVAL_LONG(pre_width, tmp_pre_width);

			PHALCON_INIT_VAR(pre_height);
			ZVAL_LONG(pre_height, tmp_pre_height);
		}

		PHALCON_CALL_METHOD(&tmp_image, this_ptr, "_create", width, height);
		PHALCON_CALL_FUNCTION(&ret, "imagecopyresampled", tmp_image, image, dst, dst, dst, dst, width, height, pre_width, pre_height);

		if (zend_is_true(ret)) {
			PHALCON_CALL_FUNCTION(NULL, "imagedestroy", image);
			phalcon_update_property_this(this_ptr, SL("_image"), tmp_image TSRMLS_CC);

			phalcon_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
			phalcon_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);
		}
	}
	else {
		PHALCON_CALL_FUNCTION(&tmp_image, "imagescale", image, width, height);

		if (Z_TYPE_P(tmp_image) == IS_RESOURCE) {
			PHALCON_CALL_FUNCTION(NULL, "imagedestroy", image);
			phalcon_update_property_this(this_ptr, SL("_image"), tmp_image TSRMLS_CC);

			phalcon_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
			phalcon_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);
		}
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

	zend_throw_exception_ex(phalcon_image_exception_ce, 0 TSRMLS_CC, "The GD does not support liquidRescale");
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
	zval *image, *tmp_image = NULL;
	zval *dst, *ret = NULL;
	zval *rect;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &width, &height, &offset_x, &offset_y);

	image = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	if (PHP_VERSION_ID < 50500) {
		PHALCON_CALL_METHOD(&tmp_image, this_ptr, "_create", width, height);

		PHALCON_INIT_VAR(dst);
		ZVAL_LONG(dst, 0);

		PHALCON_CALL_FUNCTION(&ret, "imagecopyresampled", tmp_image, image, dst, dst, offset_x, offset_y, width, height, width, height);

		if (zend_is_true(ret)) {
			PHALCON_CALL_FUNCTION(NULL, "imagedestroy", image);
			phalcon_update_property_this(this_ptr, SL("_image"), tmp_image TSRMLS_CC);

			phalcon_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
			phalcon_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);
		}
	}
	else {
		PHALCON_INIT_VAR(rect);
		array_init_size(rect, 4);
		phalcon_array_update_string(&rect, SL("x"), offset_x, PH_COPY);
		phalcon_array_update_string(&rect, SL("y"), offset_y, PH_COPY);
		phalcon_array_update_string(&rect, SL("width"), width, PH_COPY);
		phalcon_array_update_string(&rect, SL("height"), height, PH_COPY);

		PHALCON_CALL_FUNCTION(&tmp_image, "imagecrop", image, rect);

		if (Z_TYPE_P(tmp_image) == IS_RESOURCE) {
			PHALCON_CALL_FUNCTION(NULL, "imagedestroy", image);
			phalcon_update_property_this(this_ptr, SL("_image"), tmp_image TSRMLS_CC);

			phalcon_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
			phalcon_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);
		}
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
	zval *image = NULL, *tmp_image = NULL, *color, *alpha, *transparent = NULL;
	zval *ignore_transparent, *saveflag;
	zval *w = NULL, *h = NULL;
	int tmp_degrees;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &degrees);

	PHALCON_SEPARATE_PARAM(degrees);

	PHALCON_INIT_VAR(color);
	ZVAL_LONG(color, 0);

	PHALCON_INIT_VAR(alpha);
	ZVAL_LONG(alpha, 127);

	image = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_FUNCTION(&transparent, "imagecolorallocatealpha", image, color, color, color, alpha);

	tmp_degrees = phalcon_get_intval(degrees);

	PHALCON_INIT_NVAR(degrees);
	ZVAL_LONG(degrees, 360 - tmp_degrees);

	PHALCON_INIT_VAR(ignore_transparent);
	ZVAL_LONG(ignore_transparent, 1);

	PHALCON_CALL_FUNCTION(&tmp_image, "imagerotate", image, degrees, transparent, ignore_transparent);

	PHALCON_INIT_VAR(saveflag);
	ZVAL_TRUE(saveflag);

	PHALCON_CALL_FUNCTION(NULL, "imagesavealpha", tmp_image, saveflag);
	PHALCON_CALL_FUNCTION(&w, "imagesx", tmp_image);
	PHALCON_CALL_FUNCTION(&h, "imagesy", tmp_image);
	PHALCON_CALL_FUNCTION(NULL, "imagedestroy", image);
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
	zval *image = NULL;
	zval *flipped_image = NULL;
	zval *width, *height;
	zval *dst_x = NULL, *dst_y = NULL, *src_x = NULL, *src_y = NULL, *src_width = NULL, *src_height = NULL;
	int w, h, x, y;
	zval *mode;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &direction);

	image  = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	if (PHP_VERSION_ID < 50500) {
		width  = phalcon_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY TSRMLS_CC);
		height = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY TSRMLS_CC);

		PHALCON_CALL_METHOD(&flipped_image, this_ptr, "_create", width, height);

		w = Z_LVAL_P(width);
		h = Z_LVAL_P(height);

		if (Z_LVAL_P(direction) == PHALCON_IMAGE_HORIZONTAL) {
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

				PHALCON_CALL_FUNCTION(NULL, "imagecopy", flipped_image, image, dst_x, dst_y, src_x, src_y, src_width, src_height);
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

				PHALCON_CALL_FUNCTION(NULL, "imagecopy", flipped_image, image, dst_x, dst_y, src_x, src_y, src_width, src_height);
			}
		}

		PHALCON_CALL_FUNCTION(NULL, "imagedestroy", image);
		phalcon_update_property_this(this_ptr, SL("_image"), flipped_image TSRMLS_CC);
	}
	else {
		PHALCON_INIT_VAR(mode);
		if (Z_LVAL_P(direction) == PHALCON_IMAGE_HORIZONTAL) {
			if (!zend_get_constant(SL("IMG_FLIP_HORIZONTAL"), mode TSRMLS_CC)) {
				RETURN_MM();
			}
		} else {
			if (!zend_get_constant(SL("IMG_FLIP_VERTICAL"), mode TSRMLS_CC)) {
				RETURN_MM();
			}
		}

		PHALCON_CALL_FUNCTION(NULL, "imageflip", image, mode);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Execute a sharpen.
 *
 * @param int $amount
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _sharpen) {

	zval *amount, *tmp = NULL, *tmp_amount = NULL, *matrix, *item = NULL;
	zval *image = NULL, *ret = NULL, *width = NULL, *height = NULL;
	int a;
	double b;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &amount);

	image = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	a = phalcon_get_intval(amount);

	if (a > 100) {
		a = 100;
	} else if (a < 1) {
		a = 1;
	}

	b = -18 + (a * 0.08);

	if (b < 0) {
		b = -b;
	}

	PHALCON_INIT_NVAR(tmp_amount);
	ZVAL_LONG(tmp_amount, (long int)(floor(a*100.0+0.5)/100));

	PHALCON_INIT_VAR(matrix);
	array_init_size(matrix, 3);

	/* 1 */
	PHALCON_INIT_NVAR(item);
	array_init_size(item, 3);

	phalcon_array_append_long(&item, -1, 0);
	phalcon_array_append_long(&item, -1, 0);
	phalcon_array_append_long(&item, -1, 0);

	phalcon_array_append(&matrix, item, 0);

	/* 2 */
	PHALCON_INIT_NVAR(item);
	array_init_size(item, 3);

	phalcon_array_append_long(&item, -1, 0);
	phalcon_array_append(&item, tmp_amount, 0);
	phalcon_array_append_long(&item, -1, 0);

	phalcon_array_append(&matrix, item, 0);

	/* 3 */
	PHALCON_INIT_NVAR(item);
	array_init_size(item, 3);

	phalcon_array_append_long(&item, -1, 0);
	phalcon_array_append_long(&item, -1, 0);
	phalcon_array_append_long(&item, -1, 0);

	phalcon_array_append(&matrix, item, 9);

	b = b - 8;

	PHALCON_INIT_NVAR(tmp_amount);
	ZVAL_DOUBLE(tmp_amount, b);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, 0);

	PHALCON_CALL_FUNCTION(&ret, "imageconvolution", image, matrix, tmp_amount, tmp);

	if (zend_is_true(ret)) {
		PHALCON_CALL_FUNCTION(&width, "imagesx", image);
		PHALCON_CALL_FUNCTION(&height, "imagesy", image);

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

	zval *height, *opacity, *fade_in, *tmp = NULL;
	zval *reflection = NULL, *line = NULL, *image, *image_width = NULL, *image_height = NULL;
	zval *dst, *src_y = NULL, *dst_y = NULL, *dst_opacity = NULL, *filtertype = NULL;
	int h0, h1, tmp_opacity, int_opacity, offset;
	double stepping;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &height, &opacity, &fade_in);

	PHALCON_SEPARATE_PARAM(height);

	image        = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);
	image_width  = phalcon_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY TSRMLS_CC);
	image_height = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(filtertype);
	if (!zend_get_constant(SL("IMG_FILTER_COLORIZE"), filtertype TSRMLS_CC)) {
		RETURN_MM();
	}

	h0 = phalcon_get_intval(height);
	h1 = phalcon_get_intval(image_height);

	if (unlikely(h0 == 0)) {
		h0 = 1;
	}

	tmp_opacity = phalcon_get_intval(opacity);

	tmp_opacity = (int)((tmp_opacity * 127 / 100) - 127 + 0.5);

	if (tmp_opacity < 0) {
		tmp_opacity = -tmp_opacity;
	}

	if (tmp_opacity < 127) {
		stepping = (127 - tmp_opacity) / h0;
	} else {
		stepping = 127 / h0;
	}

	PHALCON_INIT_NVAR(height);
	ZVAL_DOUBLE(height, h0 + h1);

	PHALCON_CALL_METHOD(&reflection, this_ptr, "_create", image_width, height);

	PHALCON_INIT_VAR(dst);
	ZVAL_LONG(dst, 0);

	PHALCON_CALL_FUNCTION(NULL, "imagecopy", reflection, image, dst, dst, dst, dst, image_width, image_height);

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

		PHALCON_CALL_METHOD(&line, this_ptr, "_create", image_width, tmp);

		PHALCON_CALL_FUNCTION(NULL, "imagecopy", line, image, dst, dst, dst, src_y, image_width, tmp);
		PHALCON_CALL_FUNCTION(NULL, "imagefilter", line, filtertype, dst, dst, dst, dst_opacity);

		PHALCON_CALL_FUNCTION(NULL, "imagecopy", reflection, line, dst, dst_y, dst, dst, image_width, tmp);
	}

	PHALCON_CALL_FUNCTION(NULL, "imagedestroy", image);
	phalcon_update_property_this(this_ptr, SL("_image"), reflection TSRMLS_CC);

	image_width = NULL;
	PHALCON_CALL_FUNCTION(&image_width, "imagesx", reflection);
	image_height = NULL;
	PHALCON_CALL_FUNCTION(&image_height, "imagesy", reflection);

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

	zval *watermark, *offset_x = NULL, *offset_y = NULL, *opacity = NULL, *op = NULL;
	zval *image, *overlay = NULL, *blob = NULL, *saveflag, *width = NULL, *height = NULL;
	zval *color = NULL, *tmp = NULL, *effect, *blendmode, *ret = NULL;
	int int_opacity;
	double num;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &watermark, &offset_x, &offset_y, &opacity);

	image = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHOD(&blob, watermark, "render");

	PHALCON_CALL_FUNCTION(&overlay, "imagecreatefromstring", blob);

	PHALCON_INIT_VAR(saveflag);
	ZVAL_TRUE(saveflag);

	PHALCON_CALL_FUNCTION(NULL, "imagesavealpha", overlay, saveflag);

	PHALCON_CALL_FUNCTION(&width, "imagesx", overlay);
	PHALCON_CALL_FUNCTION(&height, "imagesy", overlay);

	int_opacity = Z_LVAL_P(opacity);
	if (int_opacity < 100) {
		num = (int_opacity * 127.0 / 100) - 127;

		if (num < 0) {
			num = -num;
		}

		int_opacity = (int)num;

		PHALCON_INIT_VAR(op);
		ZVAL_LONG(op, int_opacity);

		PHALCON_INIT_NVAR(tmp);
		ZVAL_LONG(tmp, 127);


		PHALCON_CALL_FUNCTION(&color, "imagecolorallocatealpha", overlay, tmp, tmp, tmp, op);

		PHALCON_INIT_VAR(effect);
		if (!zend_get_constant(SL("IMG_EFFECT_OVERLAY"), effect TSRMLS_CC)) {
			RETURN_MM();
		}

		PHALCON_CALL_FUNCTION(NULL, "imagelayereffect", overlay, effect);

		PHALCON_INIT_NVAR(tmp);
		ZVAL_LONG(tmp, 0);

		PHALCON_CALL_FUNCTION(NULL, "imagefilledrectangle", overlay, tmp, tmp, width, height, color);
	}

	PHALCON_INIT_VAR(blendmode);
	ZVAL_LONG(blendmode, 1);
	PHALCON_CALL_FUNCTION(NULL, "imagealphablending", image, blendmode);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, 0);

	PHALCON_CALL_FUNCTION(&ret, "imagecopy", image, overlay, offset_x, offset_y, tmp, tmp, width, height);

	RETVAL_BOOL(zend_is_true(ret));
	PHALCON_MM_RESTORE();
}

/**
 * Execute a text
 *
 * @param string text
 * @param int $offset_x
 * @param int $offset_y
 * @param int $opacity
 * @param int $r
 * @param int $g
 * @param int $b
 * @param int $size
 * @param string $fontfile
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _text) {
	zval *text, *offset_x, *offset_y, *opacity, *r, *g, *b, *size, *fontfile = NULL;
	zval *image, *image_width, *image_height, *tmp = NULL, *space = NULL;
	zval *s0 = NULL, *s1 = NULL, *s4 = NULL, *s5 = NULL, *width = NULL, *height = NULL, *color = NULL;
	int w, h, w1, h1, x, y, i;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 9, 0, &text, &offset_x, &offset_y, &opacity, &r, &g, &b, &size, &fontfile);

	PHALCON_SEPARATE_PARAM(offset_x);
	PHALCON_SEPARATE_PARAM(offset_y);
	PHALCON_SEPARATE_PARAM(opacity);

	PHALCON_OBS_VAR(image);
	phalcon_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	PHALCON_OBS_VAR(image_width);
	phalcon_read_property_this(&image_width, this_ptr, SL("_width"), PH_NOISY TSRMLS_CC);

	PHALCON_OBS_VAR(image_height);
	phalcon_read_property_this(&image_height, this_ptr, SL("_height"), PH_NOISY TSRMLS_CC);
	
	w = phalcon_get_intval(image_width);
	h = phalcon_get_intval(image_height);

	i = Z_LVAL_P(opacity);

	i = (int)((i * 127 / 100) - 127);

	if (i < 0) {
		i *= -1;
	}

	PHALCON_INIT_NVAR(opacity);
	ZVAL_LONG(opacity, i);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, 0);

	if (Z_TYPE_P(fontfile) == IS_STRING) {
		PHALCON_CALL_FUNCTION(&space, "imagettfbbox", size, tmp, fontfile, text);

		phalcon_array_isset_long_fetch(&s0, space, 0);
		phalcon_array_isset_long_fetch(&s1, space, 1);
		phalcon_array_isset_long_fetch(&s4, space, 4);
		phalcon_array_isset_long_fetch(&s5, space, 5);

		if (!s0 || !s1 || !s4 || !s5) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Call to imagettfbbox() failed");
			return;
		}

		w1 = phalcon_get_intval(s4) - phalcon_get_intval(s0);
		if (w1 < 0) {
			w1 = -w1;
		}
		w1 += 10;

		PHALCON_INIT_VAR(width);
		ZVAL_LONG(width, w1);

		h1 = phalcon_get_intval(s5) - phalcon_get_intval(s1);
		if (h1 < 0) {
			h1 = -h1;
		}
		h1 += 10;

		PHALCON_INIT_VAR(height);
		ZVAL_LONG(height, h1);

		if (Z_TYPE_P(offset_x) == IS_LONG ) {
			x = phalcon_get_intval(offset_x);
			if (x < 0) {
				x = (int)(w - w1 + x + 0.5);
			}
		} else if (zend_is_true(offset_x)) {
			x = (int)(w - w1);
		} else {
			x = (int)(((w - w1) / 2) + 0.5);
		}

		PHALCON_INIT_NVAR(offset_x);
		ZVAL_LONG(offset_x, x);

		if (Z_TYPE_P(offset_y) == IS_LONG ) {
			y = phalcon_get_intval(offset_y);
			if (y < 0) {
				y = (int)(h - h1 + y + 0.5);
			}
		} else if (zend_is_true(offset_y)) {
			y = (int)(h - h1);
		} else {
			y = (int)(((h - h1) / 2) + 0.5);
		}

		PHALCON_INIT_NVAR(offset_y);
		ZVAL_LONG(offset_y, y);

		PHALCON_CALL_FUNCTION(&color, "imagecolorallocatealpha", image, r, g, b, opacity);
		PHALCON_CALL_FUNCTION(NULL, "imagettftext", image, size, tmp, offset_x, offset_y, color, fontfile, text);
	} else {
		PHALCON_CALL_FUNCTION(&width, "imagefontwidth", size);
		PHALCON_CALL_FUNCTION(&height, "imagefontheight", size);

		i = Z_STRLEN_P(text);

		w1 =  phalcon_get_intval(width) * i;
		h1 =  phalcon_get_intval(height);

		PHALCON_INIT_NVAR(width);
		ZVAL_LONG(width, w1);

		PHALCON_INIT_NVAR(height);
		ZVAL_LONG(height, h1);

		if (Z_TYPE_P(offset_x) == IS_LONG ) {
			x = phalcon_get_intval(offset_x);
			if (x < 0) {
				x = (int)(w - w1 + x);
			}
		} else if (zend_is_true(offset_x)) {
			x = (int)(w - w1);
		} else {
			x = (int)((w - w1) / 2);
		}

		PHALCON_INIT_NVAR(offset_x);
		ZVAL_LONG(offset_x, x);

		if (Z_TYPE_P(offset_y) == IS_LONG ) {
			y = phalcon_get_intval(offset_y);
			if (y < 0) {
				y = (int)(h - h1 + y);
			}
		} else if (zend_is_true(offset_y)) {
			y = (int)(h - h1);
		} else {
			y = (int)((h - h1) / 2);
		}

		PHALCON_INIT_NVAR(offset_y);
		ZVAL_LONG(offset_y, y);

		PHALCON_CALL_FUNCTION(&color, "imagecolorallocatealpha", image, r, g, b, opacity);
		PHALCON_CALL_FUNCTION(NULL, "imagestring", image, size, offset_x, offset_y, text, color);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Composite one image onto another

 *
 * @param Phalcon\Image\Adapter $mask  mask Image instance
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _mask){

	zval *mask, *image, *mask_image = NULL, *blob = NULL;
	zval *mask_image_width = NULL, *mask_image_height = NULL, *newimage = NULL;
	zval *image_width, *image_height, *saveflag, *color = NULL, *c, *alpha = NULL;
	zval *r = NULL, *g = NULL, *b = NULL, *index = NULL, *index2 = NULL, *zx = NULL, *zy = NULL, *red = NULL;
	zval *temp_image = NULL;
	int x, y, w, h, i;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &mask);

	image = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHOD(&blob, mask, "render");

	PHALCON_CALL_FUNCTION(&mask_image, "imagecreatefromstring", blob);

	PHALCON_INIT_VAR(saveflag);
	ZVAL_TRUE(saveflag);

	PHALCON_CALL_FUNCTION(NULL, "imagesavealpha", mask_image, saveflag);

	PHALCON_CALL_FUNCTION(&mask_image_width, "imagesx", mask_image);
	PHALCON_CALL_FUNCTION(&mask_image_height, "imagesy", mask_image);

	image_width  = phalcon_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY TSRMLS_CC);
	image_height = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHOD(&newimage, this_ptr, "_create", image_width, image_height);

	PHALCON_CALL_FUNCTION(NULL, "imagesavealpha", newimage, saveflag);

	PHALCON_INIT_VAR(c);
	ZVAL_LONG(c, 0);

	PHALCON_INIT_VAR(alpha);
	ZVAL_LONG(alpha, 127);

	PHALCON_CALL_FUNCTION(&color, "imagecolorallocatealpha", newimage, c, c, c, alpha);

	PHALCON_CALL_FUNCTION(NULL, "imagefill", newimage, c, c, color);

	if(!PHALCON_IS_EQUAL(image_width, mask_image_width) || !PHALCON_IS_EQUAL(image_height, mask_image_height)) {
		PHALCON_CALL_FUNCTION(&temp_image, "imagecreatetruecolor", image_width, image_height);
		PHALCON_CALL_FUNCTION(NULL, "imagecopyresampled", temp_image, mask_image, c, c, c, c, image_width, image_height, mask_image_width, mask_image_height);
		PHALCON_CALL_FUNCTION(NULL, "imagedestroy", mask_image);

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

			PHALCON_CALL_FUNCTION(&index, "imagecolorat", mask_image, zx, zy);
			PHALCON_CALL_FUNCTION(&alpha, "imagecolorsforindex", mask_image, index);

			if (phalcon_array_isset_string_fetch(&red, alpha, SS("red"))) {
				i = (int)(127 - (phalcon_get_intval(red) / 2));

				PHALCON_INIT_NVAR(alpha);
				ZVAL_LONG(alpha, i);
			}

			PHALCON_CALL_FUNCTION(&index2, "imagecolorat", image, zx, zy);
			PHALCON_CALL_FUNCTION(&c, "imagecolorsforindex", image, index2);

			phalcon_array_isset_string_fetch(&r, c, SS("red"));
			phalcon_array_isset_string_fetch(&g, c, SS("green"));
			phalcon_array_isset_string_fetch(&b, c, SS("blue"));

			PHALCON_CALL_FUNCTION(&color, "imagecolorallocatealpha", newimage, r, g, b, alpha);
			PHALCON_CALL_FUNCTION(NULL, "imagesetpixel", newimage, zx, zy, color);
		}
	}

	PHALCON_CALL_FUNCTION(NULL, "imagedestroy", image);
	PHALCON_CALL_FUNCTION(NULL, "imagedestroy", mask_image);
	phalcon_update_property_this(this_ptr, SL("_image"), newimage TSRMLS_CC);

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
	zval *image, *background = NULL, *width, *height, *color = NULL, *tmp, *blendmode, *ret = NULL;
	int int_opacity;
	double num;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &r, &g, &b, &opacity);

	image  = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);
	width  = phalcon_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY TSRMLS_CC);
	height = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY TSRMLS_CC);

	int_opacity = Z_LVAL_P(opacity);

	num = (int_opacity * 127.0 / 100) - 127;

	if (num < 0) {
		num = -num;
	}

	int_opacity = (int)num;

	PHALCON_CALL_METHOD(&background, this_ptr, "_create", width, height);

	PHALCON_INIT_VAR(op);
	ZVAL_LONG(op, int_opacity);

	PHALCON_CALL_FUNCTION(&color, "imagecolorallocatealpha", background, r, g, b, op);

	PHALCON_INIT_VAR(tmp);
	ZVAL_LONG(tmp, 0);

	PHALCON_CALL_FUNCTION(NULL, "imagefilledrectangle", background, tmp, tmp, width, height, color);

	PHALCON_INIT_VAR(blendmode);
	ZVAL_TRUE(blendmode);

	PHALCON_CALL_FUNCTION(NULL, "imagealphablending", background, blendmode);
	PHALCON_CALL_FUNCTION(&ret, "imagecopy", background, image, tmp, tmp, tmp, tmp, width, height);

	if (zend_is_true(ret)) {
		PHALCON_CALL_FUNCTION(NULL, "imagedestroy", image);
		phalcon_update_property_this(this_ptr, SL("_image"), background TSRMLS_CC);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Blur image
 *
 * @param int $radius Blur radius
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _blur){

	zval *radius;
	zval *image, *constant;
	int r, i;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &radius);	

	image = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(constant);
	if (!zend_get_constant(SL("IMG_FILTER_GAUSSIAN_BLUR"), constant TSRMLS_CC)) {
		RETURN_MM();
	}

	r = phalcon_get_intval(radius);

	for (i = 0; i < r; i++) {
		PHALCON_CALL_FUNCTION(NULL, "imagefilter", image, constant);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Pixelate image
 *
 * @param int $amount amount to pixelate
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, _pixelate){

	zval *amount;
	zval *image, *width, *height, *color = NULL, *tmp1 = NULL, *tmp2 = NULL, *tmp3 = NULL, *tmp4 = NULL;
	int a, x, y, x1, y1, w, h;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &amount);

	image  = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);
	width  = phalcon_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY TSRMLS_CC);
	height = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY TSRMLS_CC);

	a = phalcon_get_intval(amount);
	w = phalcon_get_intval(width);
	h = phalcon_get_intval(height);

	for(x = 0; x < w; x += a) {
		for (y = 0; y < h; y += a) {
			x1 = (int)(x + a/2 + 0.5);
			y1 = (int)(y + a/2 + 0.5);

			PHALCON_INIT_NVAR(tmp1);
			ZVAL_LONG(tmp1, x1)

			PHALCON_INIT_NVAR(tmp2);
			ZVAL_LONG(tmp2, y1)

			PHALCON_CALL_FUNCTION(&color, "imagecolorat", image, tmp1, tmp2);

			PHALCON_INIT_NVAR(tmp1);
			ZVAL_LONG(tmp1, x)

			PHALCON_INIT_NVAR(tmp2);
			ZVAL_LONG(tmp2, y)

			x1 = x + a;
			y1 = y + a;

			PHALCON_INIT_NVAR(tmp3);
			ZVAL_LONG(tmp3, x1)

			PHALCON_INIT_NVAR(tmp4);
			ZVAL_LONG(tmp4, y1)

			PHALCON_CALL_FUNCTION(NULL, "imagefilledrectangle", image, tmp1, tmp2, tmp3, tmp4, color);
		}
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
	zval *ret = NULL, *extension, *type, *mime = NULL, *constant, *image;
	const char *func_name = "imagegif";
	char *ext;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &file, &quality);

	PHALCON_INIT_VAR(constant);
	if (!zend_get_constant(SL("PATHINFO_EXTENSION"), constant TSRMLS_CC)) {
		RETURN_MM();
	}

	PHALCON_CALL_FUNCTION(&ret, "pathinfo", file, constant);

	PHALCON_INIT_VAR(extension);
	phalcon_fast_strtolower(extension, ret);

	ext = Z_STRVAL_P(extension);

	if (strcmp(ext, "gif") == 0) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 1);
			
		PHALCON_INIT_NVAR(q);

		func_name = "imagegif";
	} else if (strcmp(ext, "jpg") == 0 || strcmp(ext, "jpeg") == 0) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 2);

		PHALCON_CPY_WRT(q, quality);

		func_name = "imagejpeg";
	} else if (strcmp(ext, "png") == 0) {
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
	
	image = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(quality) == IS_LONG) {
		PHALCON_CALL_FUNCTION(&ret, func_name, image, file, q);
	} else {
		PHALCON_CALL_FUNCTION(&ret, func_name, image, file);
	}

	if (zend_is_true(ret)) {
		phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

		PHALCON_CALL_FUNCTION(&mime, "image_type_to_mime_type", type);
		phalcon_update_property_this(this_ptr, SL("_mime"), mime TSRMLS_CC);

		RETVAL_TRUE;
	} else {
		RETVAL_FALSE;
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
	zval *file, *ret = NULL, *type, *mime = NULL, *image;
	const char *func_name = "imagegif";
	char *ext;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &extension, &quality);

	PHALCON_INIT_VAR(file);

	PHALCON_INIT_VAR(ret);
	phalcon_fast_strtolower(ret, extension);

	ext = Z_STRVAL_P(ret);

	if (strcmp(ext, "gif") == 0) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 1);
			
		PHALCON_INIT_NVAR(q);

		func_name = "imagegif";
	} else if (strcmp(ext, "jpg") == 0 || strcmp(ext, "jpeg") == 0) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 2);

		PHALCON_CPY_WRT(q, quality);

		func_name = "imagejpeg";
	} else if (strcmp(ext, "png") == 0) {
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
	
	image = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	phalcon_ob_start(TSRMLS_C);

	if (Z_TYPE_P(quality) == IS_LONG) {
		PHALCON_CALL_FUNCTION(&ret, func_name, image, file, q);
	} else {
		PHALCON_CALL_FUNCTION(&ret, func_name, image, file);
	}

	phalcon_ob_get_contents(return_value TSRMLS_CC);
	phalcon_ob_end_clean(TSRMLS_C);

	if (zend_is_true(ret)) {
		phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

		PHALCON_CALL_FUNCTION(&mime, "image_type_to_mime_type", type);
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

	zval *width, *height, *image = NULL, *blendmode, *saveflag;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &width, &height);

	PHALCON_CALL_FUNCTION(&image, "imagecreatetruecolor", width, height);

	if (Z_TYPE_P(image) != IS_RESOURCE) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "imagecreatetruecolor() failed");
		return;
	}

	PHALCON_INIT_VAR(blendmode);
	ZVAL_FALSE(blendmode);

	PHALCON_INIT_VAR(saveflag);
	ZVAL_TRUE(saveflag);

	PHALCON_CALL_FUNCTION(NULL, "imagealphablending", image, blendmode);
	PHALCON_CALL_FUNCTION(NULL, "imagesavealpha", image, saveflag);

	RETURN_CTOR(image);
}

/**
 * Destroys the loaded image to free up resources.
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, __destruct){

	zval *image;

	PHALCON_MM_GROW();

	image = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(image) == IS_RESOURCE) {
		PHALCON_CALL_FUNCTION(NULL, "imagedestroy", image);
	}
	
	PHALCON_MM_RESTORE();
}
