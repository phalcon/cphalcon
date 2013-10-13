
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
  |          Vladimir Kolesnikov <vladimir@free-sevastopol.com>            |
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

	zval class_name;
	zval *version;

	INIT_ZVAL(class_name);
	ZVAL_STRING(&class_name, "imagick", 0);

	if (!phalcon_class_exists(&class_name, 0 TSRMLS_CC)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick is not installed, or the extension is not loaded");
		return;
	}

	ALLOC_INIT_ZVAL(version);
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
	zval *width, *height;
	zval *checked, *realpath, *format, *type, *mime, *im, *ret, *mode, *imagickpixel, *color;
	zend_class_entry *imagick_ce, *ce1;

	phalcon_fetch_params_ex(1, 2, &file, &w, &h);

	PHALCON_ENSURE_IS_STRING(file);

	PHALCON_MM_GROW();

	imagick_ce = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	checked = phalcon_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked") TSRMLS_CC);

	if (!zend_is_true(checked)) {
		phalcon_call_static_noret("phalcon\\image\\adapter\\imagick", "check");
	}

	phalcon_update_property_this(this_ptr, SL("_file"), *file TSRMLS_CC);

	PHALCON_INIT_VAR(im);
	object_init_ex(im, imagick_ce);
	if (phalcon_has_constructor(im TSRMLS_CC)) {
		phalcon_call_method_noret(im, "__construct");
	}

	if (phalcon_file_exists(*file TSRMLS_CC) != FAILURE) {
		PHALCON_INIT_VAR(realpath);
		phalcon_realpath(realpath, *file TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_realpath"), realpath TSRMLS_CC);

		phalcon_call_method_p1_noret(im, "readimage", realpath);

		PHALCON_INIT_VAR(width);
		phalcon_call_method(width, im, "getimagewidth");
		phalcon_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);

		PHALCON_INIT_VAR(height);
		phalcon_call_method(height, im, "getimageheight");
		phalcon_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);

		PHALCON_INIT_VAR(type);
		phalcon_call_method(type, im, "getImageType");
		phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

		PHALCON_INIT_VAR(format);
		phalcon_call_method(format, im, "getImageFormat");

		PHALCON_INIT_VAR(mime);
		PHALCON_CONCAT_SV(mime, "image/", format);

		phalcon_update_property_this(this_ptr, SL("_mime"), mime TSRMLS_CC);

		PHALCON_INIT_VAR(ret);
		phalcon_call_method(ret, im, "getImageAlphaChannel");

		if (!zend_is_true(ret)) {
			PHALCON_INIT_VAR(mode);
			phalcon_get_class_constant(mode, imagick_ce, SS("ALPHACHANNEL_SET") TSRMLS_CC);
			phalcon_call_method_p1_noret(im, "setImageAlphaChannel", mode);
		}

		if (phalcon_get_intval(type) == 1) {
			PHALCON_INIT_NVAR(ret);
			phalcon_call_method(ret, im, "coalesceImages");

			phalcon_call_method_noret(im, "clear");
			phalcon_call_method_noret(im, "destroy");

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

			phalcon_call_method_p1_noret(imagickpixel, "__construct", color);
		}

		phalcon_call_method_p3_noret(im, "newImage", *w, *h, imagickpixel);

		PHALCON_INIT_VAR(format);
		ZVAL_STRING(format, "png", 1);

		PHALCON_INIT_VAR(ret);
		phalcon_call_method_p1(ret, im, "setFormat", format);
		phalcon_call_method_p1(ret, im, "setImageFormat", format);

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
	zval *im, *w, *h, *next = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &width, &height);

	im = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);

	phalcon_call_method_p1_noret(im, "setiteratorindex", PHALCON_GLOBAL(z_null));

	do {
		phalcon_call_method_p2_noret(im, "scaleimage", width, height);

		PHALCON_INIT_NVAR(next);
		phalcon_call_method(next, im, "nextimage");
	} while (zend_is_true(next));

	PHALCON_INIT_VAR(w);
	phalcon_call_method(w, im, "getimagewidth");

	PHALCON_INIT_VAR(h);
	phalcon_call_method(h, im, "getimageheight");

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
	zval *im, *ret = NULL, *w, *h, *next = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &width, &height, &delta_x, &rigidity);

	im = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);

	phalcon_call_method_p1_noret(im, "setiteratorindex", PHALCON_GLOBAL(z_zero));

	do {
		PHALCON_INIT_NVAR(ret);
		phalcon_call_method_p4(ret, im, "liquidrescaleimage", width, height, delta_x, rigidity);

		if (!zend_is_true(ret)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::liquidRescale failed");
			return;
		}

		PHALCON_INIT_NVAR(next);
		phalcon_call_method(next, im, "nextimage");
	} while (zend_is_true(next));

	PHALCON_INIT_VAR(w);
	phalcon_call_method(w, im, "getimagewidth");

	PHALCON_INIT_VAR(h);
	phalcon_call_method(h, im, "getimageheight");

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

	zval *width, *height, *offset_x, *offset_y, *w, *h;
	zval *im, *next = NULL, *zero;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &width, &height, &offset_x, &offset_y);

	im   = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zero = PHALCON_GLOBAL(z_zero);

	phalcon_call_method_p1_noret(im, "setiteratorindex", zero);

	do {
		phalcon_call_method_p4_noret(im, "cropimage", width, height, offset_x, offset_y);
		phalcon_call_method_p4_noret(im, "setimagepage", width, height, zero, zero);

		PHALCON_INIT_NVAR(next);
		phalcon_call_method(next, im, "nextimage");
	} while (zend_is_true(next));

	PHALCON_INIT_VAR(w);
	phalcon_call_method(w, im, "getimagewidth");

	PHALCON_INIT_VAR(h);
	phalcon_call_method(h, im, "getimageheight");

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

	im = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);

	zero = PHALCON_GLOBAL(z_zero);

	PHALCON_INIT_VAR(background);
	object_init_ex(background, imagick_pixel_ce);

	PHALCON_INIT_VAR(color);
	ZVAL_STRING(color, "transparent", 1);

	phalcon_call_method_p1_noret(background, "__construct", color);

	phalcon_call_method_p1_noret(im, "setiteratorindex", zero);

	do {
		PHALCON_INIT_NVAR(ret);
		phalcon_call_method_p2(ret, im, "rotateimage", background, degrees);

		if (!zend_is_true(ret)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::rotate failed");
			return;
		}

		if (!w) {
			PHALCON_INIT_NVAR(w);
			phalcon_call_method(w, im, "getimagewidth");

			PHALCON_INIT_NVAR(h);
			phalcon_call_method(h, im, "getimageheight");
		}

		phalcon_call_method_p4_noret(im, "setimagepage", w, h, zero, zero);

		PHALCON_INIT_NVAR(next);
		phalcon_call_method(next, im, "nextimage");
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

	im     = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	method = (Z_LVAL_PP(direction) == 11) ? "flopimage" : "flipimage";

	phalcon_call_method_p1_noret(im, "setiteratorindex", PHALCON_GLOBAL(z_zero));

	do {
		phalcon_call_method_noret(im, method);

		PHALCON_INIT_NVAR(next);
		phalcon_call_method(next, im, "nextimage");
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

	im = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);

	int_amount = phalcon_get_intval(amount);
	int_amount = (int_amount < 5) ? 5 : int_amount;

	PHALCON_INIT_VAR(a);
	ZVAL_DOUBLE(a, int_amount * 0.03);

	zero = PHALCON_GLOBAL(z_zero);

	phalcon_call_method_p1_noret(im, "setiteratorindex", zero);

	do {
		PHALCON_INIT_NVAR(ret);
		phalcon_call_method_p2(ret, im, "sharpenimage", zero, a);

		if (!zend_is_true(ret)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::sharpen failed");
			return;
		}

		PHALCON_INIT_NVAR(next);
		phalcon_call_method(next, im, "nextimage");
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
	zval *im, *reflection, *image_width, *image_height, *reflection_width, *reflection_height, *zero;
	zval *fade, *pseudoString, *composite = NULL, *constant, *channel, *image, *background, *mode, *ret = NULL, *w, *h, *delay, *h0, *colorspace;
	zval *next = NULL;
	zend_class_entry *imagick_ce, *imagick_pixel_ce;
	zval *version;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &height, &opacity, &fade_in);

	imagick_ce       = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	imagick_pixel_ce = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	im           = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	image_width  = phalcon_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	image_height = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	version      = phalcon_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_version") TSRMLS_CC);

	PHALCON_INIT_VAR(reflection);
	if (phalcon_get_intval(version) >= 30100) {
		if (FAILURE == phalcon_clone(reflection, im TSRMLS_CC)) {
			RETURN_MM();
		}
	}
	else {
		phalcon_call_method(reflection, im, "clone");
	}

	zero = PHALCON_GLOBAL(z_zero);

	phalcon_call_method_p1_noret(reflection, "setiteratorindex", zero);

	do {
		phalcon_call_method_noret(reflection, "flipimage");
		phalcon_call_method_p4_noret(reflection, "cropimage", image_width, height, zero, zero);
		phalcon_call_method_p4_noret(reflection, "setimagepage", image_width, height, zero, zero);

		PHALCON_INIT_NVAR(next);
		phalcon_call_method(next, reflection, "nextimage");
	} while (zend_is_true(next));


	PHALCON_INIT_VAR(fade);
	object_init_ex(fade, imagick_ce);
	if (phalcon_has_constructor(fade TSRMLS_CC)) {
		phalcon_call_method_noret(fade, "__construct");
	}

	PHALCON_INIT_VAR(pseudoString);
	ZVAL_STRING(pseudoString, (zend_is_true(fade_in) ? "gradient:black-transparent" : "gradient:transparent-black"), 1);

	PHALCON_INIT_VAR(reflection_width);
	phalcon_call_method(reflection_width, reflection, "getimagewidth");

	PHALCON_INIT_VAR(reflection_height);
	phalcon_call_method(reflection_height, reflection, "getimageheight");

	PHALCON_ENSURE_IS_LONG(&reflection_width);
	PHALCON_ENSURE_IS_LONG(&reflection_height);

	phalcon_call_method_p3_noret(fade, "newpseudoimage", reflection_width, reflection_height, pseudoString);

	PHALCON_INIT_VAR(composite);
	phalcon_get_class_constant(composite, imagick_ce, SS("COMPOSITE_DSTOUT") TSRMLS_CC);

	phalcon_call_method_p1_noret(reflection, "setiteratorindex", zero);

	do {
		PHALCON_INIT_NVAR(ret);
		phalcon_call_method_p4(ret, reflection, "compositeimage", fade, composite, zero, zero);

		if (!zend_is_true(ret)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed");
			return;
		}

		PHALCON_INIT_NVAR(next);
		phalcon_call_method(next, reflection, "nextimage");
	} while (zend_is_true(next));

	PHALCON_INIT_VAR(constant);
	phalcon_get_class_constant(constant, imagick_ce, SS("EVALUATE_MULTIPLY") TSRMLS_CC);

	PHALCON_INIT_VAR(o);
	ZVAL_DOUBLE(o, phalcon_get_intval(opacity) / 100);

	PHALCON_INIT_VAR(channel);
	phalcon_get_class_constant(channel, imagick_ce, SS("CHANNEL_ALPHA") TSRMLS_CC);
 

	phalcon_call_method_p1_noret(reflection, "setiteratorindex", zero);

	do {
		phalcon_call_method_p3_noret(reflection, "evaluateImage", constant, o, channel);

		PHALCON_INIT_NVAR(next);
		phalcon_call_method(next, reflection, "nextimage");
	} while (zend_is_true(next));

	PHALCON_INIT_VAR(image);
	object_init_ex(image, imagick_ce);
	if (phalcon_has_constructor(image TSRMLS_CC)) {
		phalcon_call_method_noret(image, "__construct");
	}

	PHALCON_INIT_VAR(h0);
	ZVAL_LONG(h0, phalcon_get_intval(image_height) + phalcon_get_intval(height));

	PHALCON_INIT_VAR(background);
	object_init_ex(background, imagick_pixel_ce);
	if (phalcon_has_constructor(background TSRMLS_CC)) {
		phalcon_call_method_noret(background, "__construct");
	}

	PHALCON_INIT_VAR(mode);
	phalcon_get_class_constant(mode, imagick_ce, SS("ALPHACHANNEL_SET") TSRMLS_CC);

	PHALCON_INIT_VAR(colorspace);
	phalcon_call_method(colorspace, im, "getColorspace");

	PHALCON_INIT_NVAR(composite);
	phalcon_get_class_constant(composite, imagick_ce, SS("COMPOSITE_SRC") TSRMLS_CC);

	phalcon_call_method_p1_noret(im, "setiteratorindex", zero);

	PHALCON_INIT_VAR(delay);
	phalcon_call_method(delay, im, "getImageDelay");

	do {
		phalcon_call_method_p3_noret(image, "newImage", image_width, h0, background);
		phalcon_call_method_p1_noret(image, "setImageAlphaChannel", mode);
		phalcon_call_method_p1_noret(image, "setColorspace", colorspace);
		phalcon_call_method_p1_noret(image, "setImageDelay", delay);

		PHALCON_INIT_NVAR(ret);
		phalcon_call_method_p4(ret, image, "compositeImage", im, composite, zero, zero);

		if (!zend_is_true(ret)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed");
			return;
		}

		PHALCON_INIT_NVAR(next);
		phalcon_call_method(next, im, "nextimage");
	} while (zend_is_true(next));

	PHALCON_INIT_NVAR(composite);
	phalcon_get_class_constant(composite, imagick_ce, SS("COMPOSITE_OVER") TSRMLS_CC);

	phalcon_call_method_p1_noret(image, "setiteratorindex", zero);
	phalcon_call_method_p1_noret(reflection, "setiteratorindex", zero);

	do {
		PHALCON_INIT_NVAR(ret);
		phalcon_call_method_p4(ret, image, "compositeImage", reflection, composite, zero, image_height);

		if (!zend_is_true(ret)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed");
			return;
		}

		PHALCON_INIT_NVAR(next);
		phalcon_call_method(next, image, "nextimage");

		phalcon_call_method_noret(reflection, "nextimage");
	} while (zend_is_true(next));

	PHALCON_INIT_VAR(w);
	phalcon_call_method(w, image, "getimagewidth");

	PHALCON_INIT_VAR(h);
	phalcon_call_method(h, image, "getimageheight");

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
	zval *im, *watermark, *realpath, *blob, *ret = NULL, *channel, *op_constant = NULL, *composite, *index, *next = NULL, *type;
	zend_class_entry *ce0;
	double num;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &watermark_image, &offset_x, &offset_y, &opacity);

	ce0 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	PHALCON_OBS_VAR(im);
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_OBS_VAR(type);
	phalcon_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY_CC);

	PHALCON_INIT_VAR(watermark);
	object_init_ex(watermark, ce0);
	if (phalcon_has_constructor(watermark TSRMLS_CC)) {
		phalcon_call_method_noret(watermark, "__construct");
	}

	PHALCON_INIT_VAR(realpath);	
	phalcon_call_method(realpath, watermark_image, "getRealPath");

	PHALCON_INIT_VAR(blob);	
	phalcon_call_method(blob, watermark_image, "render");

	phalcon_call_method_p2_noret(watermark, "readImageBlob", blob, realpath);

	PHALCON_INIT_VAR(channel);
	phalcon_get_class_constant(channel, ce0, SS("ALPHACHANNEL_ACTIVATE") TSRMLS_CC);

	PHALCON_INIT_VAR(ret);
	phalcon_call_method(ret, watermark, "getImageAlphaChannel");

	if (!PHALCON_IS_EQUAL(ret, channel)) {
		PHALCON_INIT_NVAR(channel);
		phalcon_get_class_constant(channel, ce0, SS("ALPHACHANNEL_OPAQUE") TSRMLS_CC);

		phalcon_call_method_p1_noret(watermark, "setImageAlphaChannel", channel);
	}

	if (phalcon_get_intval(opacity) < 100) {
		PHALCON_INIT_NVAR(op_constant);
		phalcon_get_class_constant(op_constant, ce0, SS("EVALUATE_MULTIPLY") TSRMLS_CC);

		num = Z_LVAL_P(opacity) / 100;

		PHALCON_INIT_NVAR(op);
		ZVAL_DOUBLE(op, num);

		PHALCON_INIT_NVAR(channel);
		phalcon_get_class_constant(channel, ce0, SS("CHANNEL_ALPHA") TSRMLS_CC);

		phalcon_call_method_p3_noret(watermark, "evaluateImage", op_constant, op, channel);
	}

	PHALCON_INIT_VAR(composite);
	phalcon_get_class_constant(composite, ce0, SS("COMPOSITE_DISSOLVE") TSRMLS_CC);

	if (phalcon_get_intval(type) == 1) {
		PHALCON_INIT_VAR(index);
		ZVAL_LONG(index, 0);

		phalcon_call_method_p1_noret(im, "setiteratorindex", index);

		do {
			PHALCON_INIT_NVAR(ret);
			phalcon_call_method_p4(ret, im, "compositeImage", watermark, composite, offset_x, offset_y);

			if (!zend_is_true(ret)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::watermark failed");
				return;
			}

			PHALCON_INIT_NVAR(next);
			phalcon_call_method(next, im, "nextimage");
		} while (zend_is_true(next));
	} else {
		PHALCON_INIT_NVAR(ret);
		phalcon_call_method_p4(ret, im, "compositeImage", watermark, composite, offset_x, offset_y);

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
	zval *im, *draw, *pixel, *format, *color, *op, *gravity, *tmp_a;
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
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_INIT_VAR(draw);
	object_init_ex(draw, imagick_draw_ce);
	if (phalcon_has_constructor(draw TSRMLS_CC)) {
		phalcon_call_method_noret(draw, "__construct");
	}

	PHALCON_INIT_VAR(format);
	ZVAL_STRING(format, "rgb(%d, %d, %d)", 1);

	PHALCON_INIT_VAR(color);
	phalcon_call_func_p4(color, "sprintf", format, *r, *g, *b);

	PHALCON_INIT_VAR(pixel);
	object_init_ex(pixel, imagick_pixel_ce);
	if (phalcon_has_constructor(pixel TSRMLS_CC)) {
		phalcon_call_method_p1_noret(pixel, "__construct", color);
	}

	phalcon_call_method_p1_noret(draw, "setFillColor", pixel);

	if (fontfile && Z_TYPE_PP(fontfile) == IS_STRING) {
		phalcon_call_method_p1_noret(draw, "setFont", *fontfile);
	}

	if (size) {
		phalcon_call_method_p1_noret(draw, "setFontSize", *size);
	}

	phalcon_call_method_p1_noret(draw, "setfillopacity", op);

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
	
	phalcon_call_method_p1_noret(draw, "setGravity", gravity);
	phalcon_call_method_p5_noret(im, "annotateImage", draw, offset_x, offset_y, tmp_a, *text);

	PHALCON_MM_RESTORE();
}

/**
 * Composite one image onto another
 *
 * @param Phalcon\Image\Adapter $mask  mask Image instance
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _mask){

	zval *mask, *im, *mask_im, *realpath, *blob, *matte, *composite, *zero, *next = NULL;
	zend_class_entry *imagick_ce;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &mask);

	imagick_ce = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	im = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_INIT_VAR(mask_im);
	object_init_ex(mask_im, imagick_ce);
	if (phalcon_has_constructor(mask_im TSRMLS_CC)) {
		phalcon_call_method_noret(mask_im, "__construct");
	}

	PHALCON_INIT_VAR(realpath);
	phalcon_call_method(realpath, mask, "getRealPath");

	PHALCON_INIT_VAR(blob);
	phalcon_call_method(blob, mask, "render");

	phalcon_call_method_p2_noret(mask_im, "readImageBlob", blob, realpath);

	PHALCON_INIT_VAR(matte);
	ZVAL_LONG(matte, 1);

	zero = PHALCON_GLOBAL(z_zero);

	PHALCON_INIT_VAR(composite);
	phalcon_get_class_constant(composite, imagick_ce, SS("COMPOSITE_DSTIN") TSRMLS_CC);

	phalcon_call_method_p1_noret(im, "setiteratorindex", zero);

	do {
		phalcon_call_method_p1_noret(im, "setImageMatte", matte);
		phalcon_call_method_p4_noret(im, "compositeImage", mask_im, composite, zero, zero);

		PHALCON_INIT_NVAR(next);
		phalcon_call_method(next, im, "nextimage");
	} while (zend_is_true(next));

	phalcon_call_method_noret(mask_im, "clear");

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
	zval *im, *color, *format, *background, *imagickpixel, *width, *height, *ret = NULL, *mode, *op_constant, *channel, *composite, *zero, *next = NULL;
	zend_class_entry *imagick_ce, *imagick_pixel_ce;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &r, &g, &b, &opacity);

	imagick_ce       = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	imagick_pixel_ce = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	im     = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	width  = phalcon_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	height = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);

	PHALCON_INIT_VAR(format);
	ZVAL_STRING(format, "rgb(%d, %d, %d)", 1);

	PHALCON_INIT_VAR(color);
	phalcon_call_func_p4(color, "sprintf", format, r, g, b);
	
	PHALCON_INIT_VAR(background);
	object_init_ex(background, imagick_ce);
	if (phalcon_has_constructor(background TSRMLS_CC)) {
		phalcon_call_method_noret(background, "__construct");
	}

	PHALCON_INIT_VAR(imagickpixel);
	object_init_ex(imagickpixel, imagick_pixel_ce);
	phalcon_call_method_p1_noret(imagickpixel, "__construct", color);

	phalcon_call_method_p3_noret(background, "newImage", width, height, imagickpixel);

	PHALCON_INIT_VAR(ret);
	phalcon_call_method(ret, background, "getImageAlphaChannel");

	if (!zend_is_true(ret)) {
		PHALCON_INIT_VAR(mode);
		phalcon_get_class_constant(mode, imagick_ce, SS("ALPHACHANNEL_SET") TSRMLS_CC);

		phalcon_call_method_p1_noret(background, "setImageAlphaChannel", mode);
	}

	PHALCON_INIT_NVAR(imagickpixel);
	object_init_ex(imagickpixel, imagick_pixel_ce);

	PHALCON_INIT_NVAR(color);
	ZVAL_STRING(color, "transparent", 1);

	phalcon_call_method_p1_noret(imagickpixel, "__construct", color);

	phalcon_call_method_p1_noret(background, "setImageBackgroundColor", imagickpixel);

	PHALCON_INIT_VAR(op_constant);
	phalcon_get_class_constant(op_constant, imagick_ce, SS("EVALUATE_MULTIPLY") TSRMLS_CC);

	PHALCON_INIT_NVAR(op);
	ZVAL_DOUBLE(op, phalcon_get_intval(opacity) / 100);

	PHALCON_INIT_VAR(channel);
	phalcon_get_class_constant(channel, imagick_ce, SS("CHANNEL_ALPHA") TSRMLS_CC);

	phalcon_call_method_p3_noret(background, "evaluateImage", op_constant, op, channel);

	PHALCON_INIT_NVAR(ret);
	phalcon_call_method(ret, im, "getColorspace");

	phalcon_call_method_p1_noret(background, "setColorspace", ret);

	PHALCON_INIT_VAR(composite);
	phalcon_get_class_constant(composite, imagick_ce, SS("COMPOSITE_DISSOLVE") TSRMLS_CC);

	zero = PHALCON_GLOBAL(z_zero);

	phalcon_call_method_p1_noret(im, "setiteratorindex", zero);

	do {
		PHALCON_INIT_NVAR(ret);
		phalcon_call_method_p4(ret, background, "compositeImage", im, composite, zero, zero);

		if (!zend_is_true(ret)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick::background failed");
			return;
		}

		PHALCON_INIT_NVAR(next);
		phalcon_call_method(next, im, "nextimage");
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

	im = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_INIT_VAR(sigma);
	ZVAL_DOUBLE(sigma, 100);

	phalcon_call_method_p1_noret(im, "setiteratorindex", PHALCON_GLOBAL(z_zero));

	do {
		phalcon_call_method_p2_noret(im, "blurImage", radius, sigma);
		PHALCON_INIT_NVAR(next);
		phalcon_call_method(next, im, "nextimage");
	} while (zend_is_true(next));

	PHALCON_MM_RESTORE();
}

/**
 * Pixelate image
 *
 * @param int $amount amount to pixelate
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _pixelate){

	zval *amount, *index;
	zval *im, *width, *height, *tmp_width, *tmp_height, *next = NULL;
	int w, h;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &amount);

	im     = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	width  = phalcon_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	height = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);

	w = (int)((phalcon_get_intval(width) / phalcon_get_intval(amount)) + 0.5);
	h = (int)((phalcon_get_intval(height) / phalcon_get_intval(amount)) + 0.5);

	PHALCON_INIT_VAR(tmp_width);
	PHALCON_INIT_VAR(tmp_height);

	ZVAL_LONG(tmp_width, w);
	ZVAL_LONG(tmp_height, h);

	index = PHALCON_GLOBAL(z_zero);
	phalcon_call_method_p1_noret(im, "setiteratorindex", index);

	do {
		phalcon_call_method_p2_noret(im, "scaleimage", tmp_width, tmp_height);
		phalcon_call_method_p2_noret(im, "scaleimage", width, height);

		PHALCON_INIT_NVAR(next);
		phalcon_call_method(next, im, "nextimage");
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
	zval *constant, *ret, *extension, *mime, *format, *type, *im, *fp, *mode, *compression;
	zend_class_entry *imagick_ce;
	char *ext;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &file, &quality);

	imagick_ce = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	PHALCON_INIT_VAR(constant);
	if (!zend_get_constant(SL("PATHINFO_EXTENSION"), constant TSRMLS_CC)) {
		RETURN_MM();
	}

	PHALCON_INIT_VAR(ret);
	phalcon_call_func_p2(ret, "pathinfo", file, constant);

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
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY_CC);

	phalcon_call_method_p1_noret(im, "setFormat", format);
	phalcon_call_method_p1_noret(im, "setImageFormat", format);
	phalcon_call_method_noret(im, "stripImage");

	if (phalcon_get_intval(type) == 1) {
		phalcon_call_method_noret(im, "optimizeImageLayers");

		PHALCON_INIT_VAR(mode);
		ZVAL_STRING(mode, "w", 1);

		PHALCON_INIT_VAR(fp);
		phalcon_call_func_p2(fp, "fopen", file, mode);

		if (Z_TYPE_P(fp) != IS_RESOURCE) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "The image file cannot be saved");
			return;
		}

		PHALCON_INIT_NVAR(ret);
		phalcon_call_method_p1(ret, im, "writeImagesFile", fp);
		phalcon_call_func_p1_noret("fclose", fp);
	} else {
		if (phalcon_get_intval(type) == 2) {
			PHALCON_INIT_VAR(compression);
			phalcon_get_class_constant(compression, imagick_ce, SS("COMPRESSION_JPEG") TSRMLS_CC);
			phalcon_call_method_p1_noret(im, "setImageCompression", compression );
		}
		phalcon_call_method_p1_noret(im, "setImageCompressionQuality", quality);

		PHALCON_INIT_NVAR(ret);
		phalcon_call_method_p1(ret, im, "writeImage", file);
	}

	if (zend_is_true(ret)) {
		phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

		PHALCON_INIT_VAR(mime);
		phalcon_call_func_p1(mime, "image_type_to_mime_type", type);

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
	zval *mime, *format, *type, *im, *image_string, *compression;
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
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY_CC);

	phalcon_call_method_p1_noret(im, "setFormat", format);
	phalcon_call_method_p1_noret(im, "setImageFormat", format);
	phalcon_call_method_noret(im, "stripImage");

	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

	PHALCON_INIT_VAR(mime);
	phalcon_call_func_p1(mime, "image_type_to_mime_type", type);

	phalcon_update_property_this(this_ptr, SL("_mime"), mime TSRMLS_CC);

	if (phalcon_get_intval(type) == 1) {
		phalcon_call_method_noret(im, "optimizeImageLayers");

		PHALCON_INIT_VAR(image_string);
		phalcon_call_method(image_string, im, "getImagesBlob");
	} else {
		if (phalcon_get_intval(type) == 2) {
			PHALCON_INIT_VAR(compression);
			phalcon_get_class_constant(compression, imagick_ce, SS("COMPRESSION_JPEG") TSRMLS_CC);
			phalcon_call_method_p1_noret(im, "setImageCompression", compression );
		}
		phalcon_call_method_p1_noret(im, "setImageCompressionQuality", quality);

		PHALCON_INIT_VAR(image_string);
		phalcon_call_method(image_string, im, "getImageBlob");
	}
	RETURN_CTOR(image_string);
}

/**
 * Destroys the loaded image to free up resources.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __destruct){

	zval *im;

	im = phalcon_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);

	if (Z_TYPE_P(im) == IS_OBJECT) {
		phalcon_call_method_params(NULL, NULL, im, SL("destroy"), zend_inline_hash_func(SS("destroy")) TSRMLS_CC, 0);
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
		MAKE_STD_ZVAL(im);
		object_init_ex(im, imagick_ce);
		phalcon_call_method_params(NULL, NULL, im, SL("setresourcelimit"), zend_inline_hash_func(SS("setresourcelimit")) TSRMLS_CC, 2, *resource, *limit);
		zval_ptr_dtor(&im);
	}
}
