
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

#include "image/adapter/imagick.h"
#include "image.h"
#include "image/adapter.h"
#include "image/adapterinterface.h"
#include "image/exception.h"

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
 * Phalcon\Image\Adapter\Imagick
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
zend_class_entry *phalcon_image_adapter_imagick_ce;

PHP_METHOD(Phalcon_Image_Adapter_Imagick, check);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __construct);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _resize);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _liquidRescale);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _crop);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _rotate);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _flip);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _sharpen);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _reflection);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _watermark);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _text);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _mask);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _background);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _blur);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _pixelate);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _save);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _render);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __destruct);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, getInternalImInstance);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, setResourceLimit);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick_setresourcelimit, 0, 0, 2)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_image_adapter_imagick_method_entry[] = {
	PHP_ME(Phalcon_Image_Adapter_Imagick, check, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Image_Adapter_Imagick, __construct, arginfo_phalcon_image_adapter_imagick___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _resize, arginfo_phalcon_image_adapter__resize, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _liquidRescale, arginfo_phalcon_image_adapter__liquidrescale, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _crop, arginfo_phalcon_image_adapter__crop, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _rotate, arginfo_phalcon_image_adapter__rotate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _flip, arginfo_phalcon_image_adapter__flip, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _sharpen, arginfo_phalcon_image_adapter__sharpen, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _reflection, arginfo_phalcon_image_adapter__reflection, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _watermark, arginfo_phalcon_image_adapter__watermark, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _text, arginfo_phalcon_image_adapter__text, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _mask, arginfo_phalcon_image_adapter__mask, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _background, arginfo_phalcon_image_adapter__background, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _blur, arginfo_phalcon_image_adapter__blur, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _pixelate, arginfo_phalcon_image_adapter__pixelate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _save, arginfo_phalcon_image_adapter__save, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _render, arginfo_phalcon_image_adapter__render, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Phalcon_Image_Adapter_Imagick, getInternalImInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_Imagick, setResourceLimit, arginfo_phalcon_image_adapter_imagick_setresourcelimit, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Image\Adapter\Imagick initializer
 */
PHALCON_INIT_CLASS(Phalcon_Image_Adapter_Imagick){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Imagick, image_adapter_imagick, phalcon_image_adapter_ce, phalcon_image_adapter_imagick_method_entry, 0);

	zend_declare_property_null(phalcon_image_adapter_imagick_ce, SL("_version"), ZEND_ACC_PROTECTED | ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_imagick_ce, SL("_checked"), ZEND_ACC_PROTECTED | ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(phalcon_image_adapter_imagick_ce TSRMLS_CC, 1, phalcon_image_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Checks if Imagick is enabled
 *
 * @return  boolean
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, check){

	zval *version;

	if (!phalcon_class_exists(SL("imagick"), 0 TSRMLS_CC)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick is not installed, or the extension is not loaded");
		return;
	}

	MAKE_STD_ZVAL(version);
	if (!zend_get_constant_ex(SL("imagick::IMAGICK_EXTNUM"), version, NULL, ZEND_FETCH_CLASS_SILENT TSRMLS_CC)) {
		zend_update_static_property_long(phalcon_image_adapter_imagick_ce, SL("_version"), 0 TSRMLS_CC);
	}
	else {
		zend_update_static_property_long(phalcon_image_adapter_imagick_ce, SL("_version"), phalcon_get_intval(version) TSRMLS_CC);
	}

	zval_ptr_dtor(&version);

	zend_update_static_property_bool(phalcon_image_adapter_imagick_ce, SL("_checked"), 1 TSRMLS_CC);
	RETURN_TRUE;
}

/**
 * Phalcon\Image\Imagick constructor
 *
 * @param string $file
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __construct){

	zval **file, **w = NULL, **h = NULL;
	zval *width = NULL, *height = NULL;
	zval *checked, *realpath, *format = NULL, *type = NULL, *mime, *im, *ret = NULL, *mode, *imagickpixel, *color;
	zend_class_entry *imagick_ce, *ce1;

	phalcon_fetch_params_ex(1, 2, &file, &w, &h);

	PHALCON_ENSURE_IS_STRING(file);

	PHALCON_MM_GROW();

	imagick_ce = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	checked = phalcon_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked") TSRMLS_CC);

	if (!zend_is_true(checked)) {
		PHALCON_CALL_CE_STATIC(NULL, phalcon_image_adapter_imagick_ce, "check");
	}

	phalcon_update_property_this(this_ptr, SL("_file"), *file TSRMLS_CC);

	PHALCON_INIT_VAR(im);
	object_init_ex(im, imagick_ce);
	if (phalcon_has_constructor(im TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, im, "__construct");
	}

	if (phalcon_file_exists(*file TSRMLS_CC) != FAILURE) {
		PHALCON_INIT_VAR(realpath);
		phalcon_realpath(realpath, *file TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_realpath"), realpath TSRMLS_CC);

		PHALCON_CALL_METHOD(NULL, im, "readImage", realpath);

		PHALCON_CALL_METHOD(&width, im, "getImageWidth");
		phalcon_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);

		PHALCON_CALL_METHOD(&height, im, "getImageHeight");
		phalcon_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);

		PHALCON_CALL_METHOD(&type, im, "getImageType");
		phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

		PHALCON_CALL_METHOD(&format, im, "getImageFormat");

		PHALCON_INIT_VAR(mime);
		PHALCON_CONCAT_SV(mime, "image/", format);

		phalcon_update_property_this(this_ptr, SL("_mime"), mime TSRMLS_CC);

		PHALCON_CALL_METHOD(&ret, im, "getImageAlphaChannel");

		if (!zend_is_true(ret)) {
			PHALCON_INIT_VAR(mode);
			phalcon_get_class_constant(mode, imagick_ce, SS("ALPHACHANNEL_SET") TSRMLS_CC);
			PHALCON_CALL_METHOD(NULL, im, "setImageAlphaChannel", mode);
		}

		if (phalcon_get_intval(type) == 1) {
			PHALCON_CALL_METHOD(&ret, im, "coalesceImages");

			PHALCON_CALL_METHOD(NULL, im, "clear");
			PHALCON_CALL_METHOD(NULL, im, "destroy");

			phalcon_update_property_this(this_ptr, SL("_image"), ret TSRMLS_CC);
		} else {
			phalcon_update_property_this(this_ptr, SL("_image"), im TSRMLS_CC);
		}
	} else if (w && h) {
		ce1 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

		PHALCON_INIT_VAR(imagickpixel);
		object_init_ex(imagickpixel, ce1);

		if (phalcon_has_constructor(imagickpixel TSRMLS_CC)) {
			PHALCON_INIT_VAR(color);
			ZVAL_STRING(color, "transparent", 1);

			PHALCON_CALL_METHOD(NULL, imagickpixel, "__construct", color);
		}

		PHALCON_CALL_METHOD(NULL, im, "newImage", *w, *h, imagickpixel);

		PHALCON_INIT_VAR(format);
		ZVAL_STRING(format, "png", 1);

		PHALCON_CALL_METHOD(&ret, im, "setformat", format);
		PHALCON_CALL_METHOD(&ret, im, "setImageFormat", format);

		phalcon_update_property_this(this_ptr, SL("_image"), im TSRMLS_CC);

		phalcon_update_property_this(this_ptr, SL("_realpath"), *file TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_width"), *w TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_height"), *h TSRMLS_CC);

		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 3);

		phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

		PHALCON_INIT_VAR(mime);
		ZVAL_STRING(mime, "image/png", 1);

		phalcon_update_property_this(this_ptr, SL("_mime"), mime TSRMLS_CC);
	} else {
		zend_throw_exception_ex(phalcon_image_exception_ce, 0 TSRMLS_CC, "Failed to create image from file '%s'", Z_STRVAL_PP(file));
		PHALCON_MM_RESTORE();
		return;
	}

	PHALCON_MM_RESTORE();
}

/**
 * Execute a resize.
 *
 * @param int $width
 * @param int $height
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _resize) {

	zval *width, *height;
	zval *im, *w = NULL, *h = NULL, *next = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &width, &height);

	im = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHOD(NULL, im, "setIteratorIndex", PHALCON_GLOBAL(z_null));

	do {
		PHALCON_CALL_METHOD(NULL, im, "scaleImage", width, height);
		PHALCON_CALL_METHOD(&next, im, "nextImage");
	} while (zend_is_true(next));

	PHALCON_CALL_METHOD(&w, im, "getImageWidth");
	PHALCON_CALL_METHOD(&h, im, "getImageHeight");

	phalcon_update_property_this(this_ptr, SL("_width"), w TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_height"), h TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * This method scales the images using liquid rescaling method. Only support Imagick
 *
 * @param int $width   new width
 * @param int $height  new height
 * @param int $delta_x How much the seam can traverse on x-axis. Passing 0 causes the seams to be straight. 
 * @param int $rigidity Introduces a bias for non-straight seams. This parameter is typically 0.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _liquidRescale){

	zval *width, *height, *delta_x = NULL, *rigidity = NULL;
	zval *im, *ret = NULL, *w = NULL, *h = NULL, *next = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &width, &height, &delta_x, &rigidity);

	im = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHOD(NULL, im, "setIteratorIndex", PHALCON_GLOBAL(z_zero));

	do {
		PHALCON_CALL_METHOD(&ret, im, "liquidRescaleImage", width, height, delta_x, rigidity);

		if (!zend_is_true(ret)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::liquidRescale failed");
			return;
		}

		PHALCON_CALL_METHOD(&next, im, "nextImage");
	} while (zend_is_true(next));

	PHALCON_CALL_METHOD(&w, im, "getImageWidth");
	PHALCON_CALL_METHOD(&h, im, "getImageHeight");

	phalcon_update_property_this(this_ptr, SL("_width"), w TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_height"), h TSRMLS_CC);

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
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _crop) {

	zval *width, *height, *offset_x, *offset_y, *w = NULL, *h = NULL;
	zval *im, *next = NULL, *zero;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &width, &height, &offset_x, &offset_y);

	im   = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);
	zero = PHALCON_GLOBAL(z_zero);

	PHALCON_CALL_METHOD(NULL, im, "setIteratorIndex", zero);

	do {
		PHALCON_CALL_METHOD(NULL, im, "cropImage", width, height, offset_x, offset_y);
		PHALCON_CALL_METHOD(NULL, im, "setImagePage", width, height, zero, zero);
		PHALCON_CALL_METHOD(&next, im, "nextImage");
	} while (zend_is_true(next));

	PHALCON_CALL_METHOD(&w, im, "getImageWidth");
	PHALCON_CALL_METHOD(&h, im, "getImageHeight");

	phalcon_update_property_this(this_ptr, SL("_width"), w TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_height"), h TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Execute a rotation.
 *
 * @param int $degrees
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _rotate) {

	zval *degrees;
	zval *im, *background, *color, *ret = NULL, *w = NULL, *h = NULL, *zero, *next = NULL;
	zend_class_entry *imagick_pixel_ce;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &degrees);

	imagick_pixel_ce = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	im = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	zero = PHALCON_GLOBAL(z_zero);

	PHALCON_INIT_VAR(background);
	object_init_ex(background, imagick_pixel_ce);

	PHALCON_INIT_VAR(color);
	ZVAL_STRING(color, "transparent", 1);

	PHALCON_CALL_METHOD(NULL, background, "__construct", color);

	PHALCON_CALL_METHOD(NULL, im, "setIteratorIndex", zero);

	do {
		PHALCON_CALL_METHOD(&ret, im, "rotateImage", background, degrees);

		if (!zend_is_true(ret)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::rotate failed");
			return;
		}

		if (!w) {
			PHALCON_CALL_METHOD(&w, im, "getImageWidth");
			PHALCON_CALL_METHOD(&h, im, "getImageHeight");
		}

		PHALCON_CALL_METHOD(NULL, im, "setImagePage", w, h, zero, zero);

		PHALCON_CALL_METHOD(&next, im, "nextImage");
	} while (zend_is_true(next));

	phalcon_update_property_this(this_ptr, SL("_width"), w TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_height"), h TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Execute a flip.
 *
 * @param int $direction
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _flip) {

	zval **direction;
	zval *im, *next = NULL;
	char *method;

	phalcon_fetch_params_ex(1, 0, &direction);
	PHALCON_ENSURE_IS_LONG(direction);

	PHALCON_MM_GROW();

	im     = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);
	method = (Z_LVAL_PP(direction) == 11) ? "flopImage" : "flipImage";

	PHALCON_CALL_METHOD(NULL, im, "setIteratorIndex", PHALCON_GLOBAL(z_zero));

	do {
		PHALCON_CALL_METHOD(NULL, im, method);
		PHALCON_CALL_METHOD(&next, im, "nextImage");
	} while (zend_is_true(next));

	PHALCON_MM_RESTORE();
}

/**
 * Execute a sharpen.
 *
 * @param int $amount
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _sharpen) {

	zval *amount, *a, *ret = NULL, *im, *zero, *next = NULL;
	int int_amount;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &amount);

	im = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	int_amount = phalcon_get_intval(amount);
	int_amount = (int_amount < 5) ? 5 : int_amount;

	PHALCON_INIT_VAR(a);
	ZVAL_DOUBLE(a, int_amount * 0.03);

	zero = PHALCON_GLOBAL(z_zero);

	PHALCON_CALL_METHOD(NULL, im, "setIteratorIndex", zero);

	do {
		PHALCON_CALL_METHOD(&ret, im, "sharpenImage", zero, a);

		if (!zend_is_true(ret)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::sharpen failed");
			return;
		}

		PHALCON_CALL_METHOD(&next, im, "nextImage");
	} while (zend_is_true(next));

	PHALCON_MM_RESTORE();
}

/**
 * Execute a reflection.
 *
 * @param int $height
 * @param int $opacity
 * @param boolean $fade_in
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _reflection) {

	zval *height, *opacity, *fade_in, *o;
	zval *im, *reflection, *image_width, *image_height, *reflection_width = NULL, *reflection_height = NULL, *zero;
	zval *fade, *pseudoString, *composite = NULL, *constant, *channel, *image;
	zval *background, *mode, *ret = NULL, *w = NULL, *h = NULL, *delay = NULL, *h0, *colorspace = NULL;
	zval *next = NULL;
	zend_class_entry *imagick_ce, *imagick_pixel_ce;
	zval *version;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &height, &opacity, &fade_in);

	imagick_ce       = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	imagick_pixel_ce = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	im           = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);
	image_width  = phalcon_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY TSRMLS_CC);
	image_height = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY TSRMLS_CC);
	version      = phalcon_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_version") TSRMLS_CC);

	PHALCON_INIT_VAR(reflection);
	if (phalcon_get_intval(version) >= 30100) {
		if (FAILURE == phalcon_clone(reflection, im TSRMLS_CC)) {
			RETURN_MM();
		}
	}
	else {
		PHALCON_CALL_METHOD(&reflection, im, "clone");
	}

	zero = PHALCON_GLOBAL(z_zero);

	PHALCON_CALL_METHOD(NULL, reflection, "setIteratorIndex", zero);

	do {
		PHALCON_CALL_METHOD(NULL, reflection, "flipImage");
		PHALCON_CALL_METHOD(NULL, reflection, "cropImage", image_width, height, zero, zero);
		PHALCON_CALL_METHOD(NULL, reflection, "setImagePage", image_width, height, zero, zero);
		PHALCON_CALL_METHOD(&next, reflection, "nextImage");
	} while (zend_is_true(next));


	PHALCON_INIT_VAR(fade);
	object_init_ex(fade, imagick_ce);
	if (phalcon_has_constructor(fade TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, fade, "__construct");
	}

	PHALCON_INIT_VAR(pseudoString);
	ZVAL_STRING(pseudoString, (zend_is_true(fade_in) ? "gradient:black-transparent" : "gradient:transparent-black"), 1);

	PHALCON_CALL_METHOD(&reflection_width, reflection, "getImageWidth");
	PHALCON_CALL_METHOD(&reflection_height, reflection, "getImageHeight");

	PHALCON_ENSURE_IS_LONG(&reflection_width);
	PHALCON_ENSURE_IS_LONG(&reflection_height);

	PHALCON_CALL_METHOD(NULL, fade, "newPseudoImage", reflection_width, reflection_height, pseudoString);

	PHALCON_INIT_VAR(composite);
	phalcon_get_class_constant(composite, imagick_ce, SS("COMPOSITE_DSTOUT") TSRMLS_CC);

	PHALCON_CALL_METHOD(NULL, reflection, "setIteratorIndex", zero);

	do {
		PHALCON_CALL_METHOD(&ret, reflection, "compositeImage", fade, composite, zero, zero);

		if (!zend_is_true(ret)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed");
			return;
		}

		PHALCON_CALL_METHOD(&next, reflection, "nextImage");
	} while (zend_is_true(next));

	PHALCON_INIT_VAR(constant);
	phalcon_get_class_constant(constant, imagick_ce, SS("EVALUATE_MULTIPLY") TSRMLS_CC);

	PHALCON_INIT_VAR(o);
	ZVAL_DOUBLE(o, phalcon_get_intval(opacity) / 100);

	PHALCON_INIT_VAR(channel);
	phalcon_get_class_constant(channel, imagick_ce, SS("CHANNEL_ALPHA") TSRMLS_CC);
 

	PHALCON_CALL_METHOD(NULL, reflection, "setIteratorIndex", zero);

	do {
		PHALCON_CALL_METHOD(NULL, reflection, "evaluateImage", constant, o, channel);
		PHALCON_CALL_METHOD(&next, reflection, "nextImage");
	} while (zend_is_true(next));

	PHALCON_INIT_VAR(image);
	object_init_ex(image, imagick_ce);
	if (phalcon_has_constructor(image TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, image, "__construct");
	}

	PHALCON_INIT_VAR(h0);
	ZVAL_LONG(h0, phalcon_get_intval(image_height) + phalcon_get_intval(height));

	PHALCON_INIT_VAR(background);
	object_init_ex(background, imagick_pixel_ce);
	if (phalcon_has_constructor(background TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, background, "__construct");
	}

	PHALCON_INIT_VAR(mode);
	phalcon_get_class_constant(mode, imagick_ce, SS("ALPHACHANNEL_SET") TSRMLS_CC);

	PHALCON_CALL_METHOD(&colorspace, im, "getcolorspace");

	PHALCON_INIT_NVAR(composite);
	phalcon_get_class_constant(composite, imagick_ce, SS("COMPOSITE_SRC") TSRMLS_CC);

	PHALCON_CALL_METHOD(NULL, im, "setIteratorIndex", zero);

	PHALCON_CALL_METHOD(&delay, im, "getImageDelay");

	do {
		PHALCON_CALL_METHOD(NULL, image, "newImage", image_width, h0, background);
		PHALCON_CALL_METHOD(NULL, image, "setImageAlphaChannel", mode);
		PHALCON_CALL_METHOD(NULL, image, "setcolorspace", colorspace);
		PHALCON_CALL_METHOD(NULL, image, "setImageDelay", delay);
		PHALCON_CALL_METHOD(&ret, image, "compositeImage", im, composite, zero, zero);

		if (!zend_is_true(ret)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed");
			return;
		}

		PHALCON_CALL_METHOD(&next, im, "nextImage");
	} while (zend_is_true(next));

	PHALCON_INIT_NVAR(composite);
	phalcon_get_class_constant(composite, imagick_ce, SS("COMPOSITE_OVER") TSRMLS_CC);

	PHALCON_CALL_METHOD(NULL, image, "setIteratorIndex", zero);
	PHALCON_CALL_METHOD(NULL, reflection, "setIteratorIndex", zero);

	do {
		PHALCON_CALL_METHOD(&ret, image, "compositeImage", reflection, composite, zero, image_height);

		if (!zend_is_true(ret)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed");
			return;
		}

		PHALCON_CALL_METHOD(&next, image, "nextImage");
		PHALCON_CALL_METHOD(NULL, reflection, "nextImage");
	} while (zend_is_true(next));

	PHALCON_CALL_METHOD(&w, image, "getImageWidth");
	PHALCON_CALL_METHOD(&h, image, "getImageHeight");

	phalcon_update_property_this(this_ptr, SL("_width"), w TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_height"), h TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);

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
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _watermark) {

	zval *watermark_image, *offset_x, *offset_y, *opacity, *op =NULL;
	zval *im, *watermark, *realpath = NULL, *blob = NULL, *ret = NULL, *channel;
	zval *op_constant = NULL, *composite, *index, *next = NULL, *type;
	zend_class_entry *ce0;
	double num;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &watermark_image, &offset_x, &offset_y, &opacity);

	ce0 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	PHALCON_OBS_VAR(im);
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	PHALCON_OBS_VAR(type);
	phalcon_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(watermark);
	object_init_ex(watermark, ce0);
	if (phalcon_has_constructor(watermark TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, watermark, "__construct");
	}

	PHALCON_CALL_METHOD(&realpath, watermark_image, "getrealpath");
	PHALCON_CALL_METHOD(&blob, watermark_image, "render");
	PHALCON_CALL_METHOD(NULL, watermark, "readImageBlob", blob, realpath);

	PHALCON_INIT_VAR(channel);
	phalcon_get_class_constant(channel, ce0, SS("ALPHACHANNEL_ACTIVATE") TSRMLS_CC);

	PHALCON_CALL_METHOD(&ret, watermark, "getImageAlphaChannel");

	if (!PHALCON_IS_EQUAL(ret, channel)) {
		PHALCON_INIT_NVAR(channel);
		phalcon_get_class_constant(channel, ce0, SS("ALPHACHANNEL_OPAQUE") TSRMLS_CC);

		PHALCON_CALL_METHOD(NULL, watermark, "setImageAlphaChannel", channel);
	}

	if (phalcon_get_intval(opacity) < 100) {
		PHALCON_INIT_NVAR(op_constant);
		phalcon_get_class_constant(op_constant, ce0, SS("EVALUATE_MULTIPLY") TSRMLS_CC);

		num = Z_LVAL_P(opacity) / 100;

		PHALCON_INIT_NVAR(op);
		ZVAL_DOUBLE(op, num);

		PHALCON_INIT_NVAR(channel);
		phalcon_get_class_constant(channel, ce0, SS("CHANNEL_ALPHA") TSRMLS_CC);

		PHALCON_CALL_METHOD(NULL, watermark, "evaluateImage", op_constant, op, channel);
	}

	PHALCON_INIT_VAR(composite);
	phalcon_get_class_constant(composite, ce0, SS("COMPOSITE_DISSOLVE") TSRMLS_CC);

	if (phalcon_get_intval(type) == 1) {
		PHALCON_INIT_VAR(index);
		ZVAL_LONG(index, 0);

		PHALCON_CALL_METHOD(NULL, im, "setIteratorIndex", index);

		do {
			PHALCON_CALL_METHOD(&ret, im, "compositeImage", watermark, composite, offset_x, offset_y);

			if (!zend_is_true(ret)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::watermark failed");
				return;
			}

			PHALCON_CALL_METHOD(&next, im, "nextImage");
		} while (zend_is_true(next));
	} else {
		PHALCON_CALL_METHOD(&ret, im, "compositeImage", watermark, composite, offset_x, offset_y);

		if (!zend_is_true(ret)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::watermark failed");
			return;
		}
	}

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
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _text) {

	zval **text, **ofs_x = NULL, **ofs_y = NULL, **opacity = NULL, **r = NULL, **g = NULL, **b = NULL, **size = NULL, **fontfile = NULL;
	zval *im, *draw, *pixel, *format, *color = NULL, *op, *gravity, *tmp_a;
	zval *offset_x = NULL, *offset_y = NULL;
	zend_class_entry *imagick_ce, *imagick_draw_ce, *imagick_pixel_ce;
	int x, y;

	phalcon_fetch_params_ex(9, 0, &text, &ofs_x, &ofs_y, &opacity, &r, &g, &b, &size, &fontfile);

	PHALCON_MM_GROW();

	imagick_ce       = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	imagick_draw_ce  = zend_fetch_class(SL("ImagickDraw"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	imagick_pixel_ce = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	if (!ofs_x) {
		PHALCON_INIT_VAR(offset_x);
	} else {
		PHALCON_CPY_WRT_CTOR(offset_x, *ofs_x);
	}

	if (!offset_y) {
		PHALCON_INIT_VAR(offset_y);
	} else {
		PHALCON_CPY_WRT_CTOR(offset_x, *ofs_y);
	}

	if (!r) {
		r = &PHALCON_GLOBAL(z_zero);
	}

	if (!g) {
		g = &PHALCON_GLOBAL(z_zero);
	}

	if (!b) {
		b = &PHALCON_GLOBAL(z_zero);
	}

	PHALCON_INIT_VAR(op);
	if (!opacity) {
		ZVAL_DOUBLE(op, 1);
	}
	else {
		ZVAL_DOUBLE(op, phalcon_get_intval(*opacity)/100);
	}

	PHALCON_OBS_VAR(im);
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(draw);
	object_init_ex(draw, imagick_draw_ce);
	if (phalcon_has_constructor(draw TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, draw, "__construct");
	}

	PHALCON_INIT_VAR(format);
	ZVAL_STRING(format, "rgb(%d, %d, %d)", 1);
	PHALCON_CALL_FUNCTION(&color, "sprintf", format, *r, *g, *b);

	PHALCON_INIT_VAR(pixel);
	object_init_ex(pixel, imagick_pixel_ce);
	if (phalcon_has_constructor(pixel TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, pixel, "__construct", color);
	}

	PHALCON_CALL_METHOD(NULL, draw, "setfillcolor", pixel);

	if (fontfile && Z_TYPE_PP(fontfile) == IS_STRING) {
		PHALCON_CALL_METHOD(NULL, draw, "setfont", *fontfile);
	}

	if (size) {
		PHALCON_CALL_METHOD(NULL, draw, "setfontsize", *size);
	}

	PHALCON_CALL_METHOD(NULL, draw, "setfillopacity", op);

	PHALCON_INIT_VAR(tmp_a);
	ZVAL_LONG(tmp_a, 0);

	PHALCON_INIT_VAR(gravity);

	if (Z_TYPE_P(offset_x) == IS_BOOL) {
		if (Z_TYPE_P(offset_y) == IS_BOOL) {
			if (zend_is_true(offset_x) && zend_is_true(offset_y)) {
				PHALCON_INIT_NVAR(offset_x);
				ZVAL_LONG(offset_x, 0);

				PHALCON_INIT_NVAR(offset_y);
				ZVAL_LONG(offset_y, 0);

				PHALCON_INIT_VAR(gravity);
				phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_SOUTHEAST") TSRMLS_CC);
			} else if (zend_is_true(offset_x)) {
				PHALCON_INIT_NVAR(offset_x);
				ZVAL_LONG(offset_x, 0);

				PHALCON_INIT_NVAR(offset_y);
				ZVAL_LONG(offset_y, 0);

				PHALCON_INIT_VAR(gravity);
				phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_EAST") TSRMLS_CC);
			} else if (zend_is_true(offset_y)) {
				PHALCON_INIT_NVAR(offset_x);
				ZVAL_LONG(offset_x, 0);

				PHALCON_INIT_NVAR(offset_y);
				ZVAL_LONG(offset_y, 0);

				PHALCON_INIT_VAR(gravity);
				phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_SOUTH") TSRMLS_CC);
			} else {
				PHALCON_INIT_NVAR(offset_x);
				ZVAL_LONG(offset_x, 0);

				PHALCON_INIT_NVAR(offset_y);
				ZVAL_LONG(offset_y, 0);

				PHALCON_INIT_VAR(gravity);
				phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_CENTER") TSRMLS_CC);
			}
		} else if (Z_TYPE_P(offset_y) == IS_LONG) {
			y = phalcon_get_intval(offset_y);

			if (zend_is_true(offset_x)) {
				if (y < 0) {
					PHALCON_INIT_NVAR(offset_x);
					ZVAL_LONG(offset_x, 0);

					PHALCON_INIT_NVAR(offset_y);
					ZVAL_LONG(offset_y, y * -1);

					PHALCON_INIT_VAR(gravity);
					phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_SOUTHEAST") TSRMLS_CC);
				} else {
					PHALCON_INIT_NVAR(offset_x);
					ZVAL_LONG(offset_x, 0);

					PHALCON_INIT_VAR(gravity);
					phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_NORTHEAST") TSRMLS_CC);
				}
			} else {
				if (y < 0) {
					PHALCON_INIT_NVAR(offset_x);
					ZVAL_LONG(offset_x, 0);

					PHALCON_INIT_NVAR(offset_y);
					ZVAL_LONG(offset_y, y * -1);

					PHALCON_INIT_VAR(gravity);
					phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_SOUTH") TSRMLS_CC);
				} else {
					PHALCON_INIT_NVAR(offset_x);
					ZVAL_LONG(offset_x, 0);

					PHALCON_INIT_VAR(gravity);
					phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_NORTH") TSRMLS_CC);
				}
			}
		}
	} else if (Z_TYPE_P(offset_x) == IS_LONG) {
		x = phalcon_get_intval(offset_x);
		if (Z_TYPE_P(offset_y) == IS_BOOL) {
			if (zend_is_true(offset_y)) {
				if (x < 0) {
					PHALCON_INIT_NVAR(offset_x);
					ZVAL_LONG(offset_x, x * -1);

					PHALCON_INIT_NVAR(offset_y);
					ZVAL_LONG(offset_y, 0);

					PHALCON_INIT_VAR(gravity);
					phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_SOUTHEAST") TSRMLS_CC);
				} else {
					PHALCON_INIT_NVAR(offset_y);
					ZVAL_LONG(offset_y, 0);

					PHALCON_INIT_VAR(gravity);
					phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_SOUTH") TSRMLS_CC);
				}
			} else {
				if (x < 0) {
					PHALCON_INIT_NVAR(offset_x);
					ZVAL_LONG(offset_x, x * -1);

					PHALCON_INIT_NVAR(offset_y);
					ZVAL_LONG(offset_y, 0);

					PHALCON_INIT_VAR(gravity);
					phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_EAST") TSRMLS_CC);
				} else {
					PHALCON_INIT_NVAR(offset_y);
					ZVAL_LONG(offset_y, 0);

					PHALCON_INIT_VAR(gravity);
					phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_WEST") TSRMLS_CC);
				}
			}
		} else if (Z_TYPE_P(offset_y) == IS_LONG) {

			x = phalcon_get_intval(offset_x);
			y = phalcon_get_intval(offset_y);

			if (x < 0) {
				if (y < 0) {
					PHALCON_INIT_NVAR(offset_x);
					ZVAL_LONG(offset_x, x * -1);

					PHALCON_INIT_NVAR(offset_y);
					ZVAL_LONG(offset_y, y * -1);

					PHALCON_INIT_VAR(gravity);
					phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_SOUTHEAST") TSRMLS_CC);
				} else {					
					PHALCON_INIT_NVAR(offset_x);
					ZVAL_LONG(offset_x, x * -1);

					PHALCON_INIT_VAR(gravity);
					phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_NORTHEAST") TSRMLS_CC);
				}
			} else {
				if (y < 0) {
					PHALCON_INIT_NVAR(offset_x);
					ZVAL_LONG(offset_x, 0);

					PHALCON_INIT_NVAR(offset_y);
					ZVAL_LONG(offset_y, y * -1);

					PHALCON_INIT_VAR(gravity);
					phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_SOUTHWEST") TSRMLS_CC);
				} else {					
					PHALCON_INIT_NVAR(offset_x);
					ZVAL_LONG(offset_x, 0);

					PHALCON_INIT_VAR(gravity);
					phalcon_get_class_constant(gravity, imagick_ce, SS("GRAVITY_NORTHWEST") TSRMLS_CC);
				}
			}
		}
	}
	
	PHALCON_CALL_METHOD(NULL, draw, "setgravity", gravity);
	PHALCON_CALL_METHOD(NULL, im, "annotateImage", draw, offset_x, offset_y, tmp_a, *text);

	PHALCON_MM_RESTORE();
}

/**
 * Composite one image onto another
 *
 * @param Phalcon\Image\Adapter $mask  mask Image instance
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _mask){

	zval *mask, *im, *mask_im, *realpath = NULL, *blob = NULL, *matte, *composite, *zero, *next = NULL;
	zend_class_entry *imagick_ce;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &mask);

	imagick_ce = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	im = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(mask_im);
	object_init_ex(mask_im, imagick_ce);
	if (phalcon_has_constructor(mask_im TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, mask_im, "__construct");
	}

	PHALCON_CALL_METHOD(&realpath, mask, "getrealpath");
	PHALCON_CALL_METHOD(&blob, mask, "render");

	PHALCON_CALL_METHOD(NULL, mask_im, "readImageBlob", blob, realpath);

	PHALCON_INIT_VAR(matte);
	ZVAL_LONG(matte, 1);

	zero = PHALCON_GLOBAL(z_zero);

	PHALCON_INIT_VAR(composite);
	phalcon_get_class_constant(composite, imagick_ce, SS("COMPOSITE_DSTIN") TSRMLS_CC);

	PHALCON_CALL_METHOD(NULL, im, "setIteratorIndex", zero);

	do {
		PHALCON_CALL_METHOD(NULL, im, "setImageMatte", matte);
		PHALCON_CALL_METHOD(NULL, im, "compositeImage", mask_im, composite, zero, zero);
		PHALCON_CALL_METHOD(&next, im, "nextImage");
	} while (zend_is_true(next));

	PHALCON_CALL_METHOD(NULL, mask_im, "clear");

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
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _background) {

	zval *r, *g, *b, *opacity, *op = NULL;
	zval *im, *color = NULL, *format, *background, *imagickpixel, *width, *height, *ret = NULL;
	zval *mode, *op_constant, *channel, *composite, *zero, *next = NULL;
	zend_class_entry *imagick_ce, *imagick_pixel_ce;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &r, &g, &b, &opacity);

	imagick_ce       = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	imagick_pixel_ce = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	im     = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);
	width  = phalcon_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY TSRMLS_CC);
	height = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(format);
	ZVAL_STRING(format, "rgb(%d, %d, %d)", 1);
	PHALCON_CALL_FUNCTION(&color, "sprintf", format, r, g, b);
	
	PHALCON_INIT_VAR(background);
	object_init_ex(background, imagick_ce);
	if (phalcon_has_constructor(background TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, background, "__construct");
	}

	PHALCON_INIT_VAR(imagickpixel);
	object_init_ex(imagickpixel, imagick_pixel_ce);
	PHALCON_CALL_METHOD(NULL, imagickpixel, "__construct", color);

	PHALCON_CALL_METHOD(NULL, background, "newImage", width, height, imagickpixel);

	PHALCON_CALL_METHOD(&ret, background, "getImageAlphaChannel");

	if (!zend_is_true(ret)) {
		PHALCON_INIT_VAR(mode);
		phalcon_get_class_constant(mode, imagick_ce, SS("ALPHACHANNEL_SET") TSRMLS_CC);

		PHALCON_CALL_METHOD(NULL, background, "setImageAlphaChannel", mode);
	}

	PHALCON_INIT_NVAR(imagickpixel);
	object_init_ex(imagickpixel, imagick_pixel_ce);

	PHALCON_INIT_NVAR(color);
	ZVAL_STRING(color, "transparent", 1);

	PHALCON_CALL_METHOD(NULL, imagickpixel, "__construct", color);

	PHALCON_CALL_METHOD(NULL, background, "setImageBackgroundColor", imagickpixel);

	PHALCON_INIT_VAR(op_constant);
	phalcon_get_class_constant(op_constant, imagick_ce, SS("EVALUATE_MULTIPLY") TSRMLS_CC);

	PHALCON_INIT_NVAR(op);
	ZVAL_DOUBLE(op, phalcon_get_intval(opacity) / 100);

	PHALCON_INIT_VAR(channel);
	phalcon_get_class_constant(channel, imagick_ce, SS("CHANNEL_ALPHA") TSRMLS_CC);

	PHALCON_CALL_METHOD(NULL, background, "evaluateImage", op_constant, op, channel);

	PHALCON_CALL_METHOD(&ret, im, "getcolorspace");
	PHALCON_CALL_METHOD(NULL, background, "setcolorspace", ret);

	PHALCON_INIT_VAR(composite);
	phalcon_get_class_constant(composite, imagick_ce, SS("COMPOSITE_DISSOLVE") TSRMLS_CC);

	zero = PHALCON_GLOBAL(z_zero);

	PHALCON_CALL_METHOD(NULL, im, "setIteratorIndex", zero);

	do {
		PHALCON_CALL_METHOD(&ret, background, "compositeImage", im, composite, zero, zero);

		if (!zend_is_true(ret)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::background failed");
			return;
		}

		PHALCON_CALL_METHOD(&next, im, "nextImage");
	} while (zend_is_true(next));

	phalcon_update_property_this(this_ptr, SL("_image"), background TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Blur image
 *
 * @param int $radius Blur radius
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _blur){

	zval *radius;
	zval *im, *sigma, *next = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &radius);

	im = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(sigma);
	ZVAL_DOUBLE(sigma, 100);

	PHALCON_CALL_METHOD(NULL, im, "setIteratorIndex", PHALCON_GLOBAL(z_zero));

	do {
		PHALCON_CALL_METHOD(NULL, im, "blurImage", radius, sigma);
		PHALCON_CALL_METHOD(&next, im, "nextImage");
	} while (zend_is_true(next));

	PHALCON_MM_RESTORE();
}

/**
 * Pixelate image
 *
 * @param int $amount amount to pixelate
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _pixelate){

	zval **amount, *index;
	zval *im, *width, *height, *tmp_width, *tmp_height, *next = NULL;
	int w, h;

	phalcon_fetch_params_ex(1, 0, &amount);
	PHALCON_ENSURE_IS_LONG(amount);

	if (Z_LVAL_PP(amount) < 2) {
		ZVAL_LONG(*amount, 2);
	}

	PHALCON_MM_GROW();

	im     = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);
	width  = phalcon_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY TSRMLS_CC);
	height = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY TSRMLS_CC);

	w = (int)((phalcon_get_intval(width) / Z_LVAL_PP(amount)) + 0.5);
	h = (int)((phalcon_get_intval(height) / Z_LVAL_PP(amount)) + 0.5);

	PHALCON_INIT_VAR(tmp_width);
	PHALCON_INIT_VAR(tmp_height);

	ZVAL_LONG(tmp_width, w);
	ZVAL_LONG(tmp_height, h);

	index = PHALCON_GLOBAL(z_zero);
	PHALCON_CALL_METHOD(NULL, im, "setIteratorIndex", index);

	do {
		PHALCON_CALL_METHOD(NULL, im, "scaleImage", tmp_width, tmp_height);
		PHALCON_CALL_METHOD(NULL, im, "scaleImage", width, height);
		PHALCON_CALL_METHOD(&next, im, "nextImage");
	} while (zend_is_true(next));

	PHALCON_MM_RESTORE();
}

/**
 * Execute a save.
 *
 * @param string $file
 * @param int $quality
 * @return boolean
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _save) {

	zval *file, *quality, *exception_message;
	zval *constant, *ret = NULL, *extension, *mime = NULL, *format, *type, *im, *fp = NULL, *mode, *compression;
	zend_class_entry *imagick_ce;
	char *ext;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &file, &quality);

	imagick_ce = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	PHALCON_INIT_VAR(constant);
	if (!zend_get_constant(SL("PATHINFO_EXTENSION"), constant TSRMLS_CC)) {
		RETURN_MM();
	}

	PHALCON_CALL_FUNCTION(&ret, "pathinfo", file, constant);

	PHALCON_INIT_VAR(extension);
	phalcon_fast_strtolower(extension, ret);

	PHALCON_INIT_VAR(format);
	phalcon_fast_strtolower(format, extension);

	ext = Z_STRVAL_P(format);

	PHALCON_INIT_VAR(type);
	if (strcmp(ext, "gif") == 0) {
		ZVAL_LONG(type, 1);
	} else if (strcmp(ext, "jpg") == 0 || strcmp(ext, "jpeg") == 0) {
		ZVAL_LONG(type, 2);
	} else if (strcmp(ext, "png") == 0) {
		ZVAL_LONG(type, 3);
	} else {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Installed ImageMagick does not support '", extension, "' images");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_image_exception_ce, exception_message);
		return;
	}

	PHALCON_OBS_VAR(im);
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHOD(NULL, im, "setformat", format);
	PHALCON_CALL_METHOD(NULL, im, "setImageFormat", format);
	PHALCON_CALL_METHOD(NULL, im, "stripImage");

	if (phalcon_get_intval(type) == 1) {
		PHALCON_CALL_METHOD(NULL, im, "optimizeImageLayers");

		PHALCON_INIT_VAR(mode);
		ZVAL_STRING(mode, "w", 1);

		PHALCON_CALL_FUNCTION(&fp, "fopen", file, mode);
		if (Z_TYPE_P(fp) != IS_RESOURCE) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "The image file cannot be saved");
			return;
		}

		PHALCON_CALL_METHOD(&ret, im, "writeImagesFile", fp);
		PHALCON_CALL_FUNCTION(NULL, "fclose", fp);
	} else {
		if (phalcon_get_intval(type) == 2) {
			PHALCON_INIT_VAR(compression);
			phalcon_get_class_constant(compression, imagick_ce, SS("COMPRESSION_JPEG") TSRMLS_CC);
			PHALCON_CALL_METHOD(NULL, im, "setImageCompression", compression );
		}

		PHALCON_CALL_METHOD(NULL, im, "setImageCompressionQuality", quality);
		PHALCON_CALL_METHOD(&ret, im, "writeImage", file);
	}

	if (zend_is_true(ret)) {
		phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

		PHALCON_CALL_FUNCTION(&mime, "image_type_to_mime_type", type);

		phalcon_update_property_this(this_ptr, SL("_mime"), mime TSRMLS_CC);

		RETVAL_TRUE;
	} else {
		RETVAL_FALSE;
	}

	PHALCON_MM_RESTORE();
}

/**
 * Execute a render.
 *
 * @param string $type
 * @param int $quality
 * @return string
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _render) {

	zval *extension, *quality, *exception_message;
	zval *mime = NULL, *format, *type, *im, *image_string = NULL, *compression;
	zend_class_entry *imagick_ce;
	char *ext;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &extension, &quality);

	imagick_ce = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	PHALCON_INIT_VAR(format);
	phalcon_fast_strtolower(format, extension);

	ext = Z_STRVAL_P(format);

	if (strncmp(ext, "gif", 3) == 0) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 1);
	} else if (strncmp(ext, "jpg", 3) == 0 || strncmp(ext, "jpeg", 4) == 0) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 2);
	} else if (strncmp(ext, "png", 3) == 0) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 3);
	} else {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Installed ImageMagick does not support '", extension, "' images");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_image_exception_ce, exception_message);
		return;
	}

	PHALCON_OBS_VAR(im);
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHOD(NULL, im, "setformat", format);
	PHALCON_CALL_METHOD(NULL, im, "setImageFormat", format);
	PHALCON_CALL_METHOD(NULL, im, "stripImage");

	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

	PHALCON_CALL_FUNCTION(&mime, "image_type_to_mime_type", type);

	phalcon_update_property_this(this_ptr, SL("_mime"), mime TSRMLS_CC);

	if (phalcon_get_intval(type) == 1) {
		PHALCON_CALL_METHOD(NULL, im, "optimizeImageLayers");
		PHALCON_CALL_METHOD(&image_string, im, "getImagesBlob");
	} else {
		if (phalcon_get_intval(type) == 2) {
			PHALCON_INIT_VAR(compression);
			phalcon_get_class_constant(compression, imagick_ce, SS("COMPRESSION_JPEG") TSRMLS_CC);
			PHALCON_CALL_METHOD(NULL, im, "setImageCompression", compression );
		}

		PHALCON_CALL_METHOD(NULL, im, "setImageCompressionQuality", quality);
		PHALCON_CALL_METHOD(&image_string, im, "getImageBlob");
	}
	RETURN_CTOR(image_string);
}

/**
 * Destroys the loaded image to free up resources.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __destruct){

	zval *im;

	im = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(im) == IS_OBJECT) {
		PHALCON_CALL_METHODW(NULL, im, "destroy");
	}
}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, getInternalImInstance)
{
	RETURN_MEMBER(getThis(), "_image");
}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, setResourceLimit)
{
	zval **resource, **limit;
	zval *im;
	zend_class_entry *imagick_ce;

	phalcon_fetch_params_ex(2, 0, &resource, &limit);

	imagick_ce = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	if (EXPECTED(imagick_ce != NULL)) {
		zval *params[] = { *resource, *limit };

		MAKE_STD_ZVAL(im);
		object_init_ex(im, imagick_ce);
		if (FAILURE == phalcon_call_method(NULL, im, "setresourcelimit", 2, params TSRMLS_CC)) {
			;
		}

		zval_ptr_dtor(&im);
	}
}
