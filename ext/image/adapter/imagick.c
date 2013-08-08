
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
 * Phalcon\Image\\Adapter\Imagick
 *
 * Image manipulation support. Allows images to be resized, cropped, etc.
 *
 *<code>
 *	$image = new Phalcon\Image\Adapter\Imagick("upload/test.jpg");
 *	$image->resize(200, 200);
 *	$image->save();
 *</code>
 */


/**
 * Phalcon\Image\Adapter\Imagick initializer
 */
PHALCON_INIT_CLASS(Phalcon_Image_Adapter_Imagick){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Imagick, image_adapter_imagick, "phalcon\\image\\adapter",  phalcon_image_adapter_imagick_method_entry, 0);

	zend_class_implements(phalcon_image_adapter_imagick_ce TSRMLS_CC, 1, phalcon_image_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Checks if Imagick is enabled
 *
 * @return  boolean
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, check){

	zval *module_name, *ret = NULL, *exception_message;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(module_name);
	ZVAL_STRING(module_name, "imagick", 1);

	PHALCON_INIT_NVAR(ret);
	phalcon_call_func_p1(ret, "extension_loaded", module_name);

	if (!zend_is_true(ret)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick is not installed, or the extension is not loaded");
		return;
	}

	phalcon_update_static_property(SL("phalcon\\image\\adapter\\imagick"), SL("_checked"), ret TSRMLS_CC);

	ZVAL_BOOL(return_value, 1);

	RETURN_MM();
}

/**
 * Phalcon\Image\Imagick constructor
 *
 * @param string $file
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __construct){

	zval *file, *exception_message;
	zval *checked = NULL, *realpath, *im, *ret, *mode;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &file);

	if (Z_TYPE_P(file) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "file didn't return a valid string");
		return;
	}

	PHALCON_OBS_VAR(checked);
	phalcon_read_static_property(&checked, SL("phalcon\\image\\adapter\\imagick"), SL("_checked") TSRMLS_CC);

	if (!zend_is_true(checked)) {
		phalcon_call_static_noret("phalcon\\image\\adapter\\imagick", "check");
	}

	phalcon_call_parent_p1_noret(this_ptr, phalcon_image_adapter_imagick_ce, "__construct", file);

	PHALCON_OBS_VAR(realpath);
	phalcon_read_property_this(&realpath, this_ptr, SL("_realpath"), PH_NOISY_CC);

	ce0 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_INIT_VAR(im);
	object_init_ex(im, ce0);
	if (phalcon_has_constructor(im TSRMLS_CC)) {
		phalcon_call_method_noret(im, "__construct");
	}

	phalcon_call_method_p1_noret(im, "readImage", realpath);

	PHALCON_INIT_VAR(ret);
	phalcon_call_method(ret, im, "getImageAlphaChannel");

	if (!zend_is_true(ret)) {		 
		PHALCON_INIT_VAR(mode);
		phalcon_get_class_constant(mode, ce0, SS("ALPHACHANNEL_SET") TSRMLS_CC);
		phalcon_call_method_p1_noret(im, "setImageAlphaChannel", mode);
	}

	phalcon_update_property_this(this_ptr, SL("_image"), im TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Execute a resize.
 *
 * @param int $width
 * @param int $height
 * @return boolean
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _resize) {

	zval *width = NULL, *height = NULL;
	zval *im, *ret, *w, *h;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &width, &height);

	PHALCON_OBS_VAR(im);
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_INIT_VAR(ret);
	phalcon_call_method_p2(ret, im, "scaleImage", width, height);

	if (zend_is_true(ret)) {
		PHALCON_INIT_VAR(w);
		phalcon_call_method(w, im, "getImageWidth");

		PHALCON_INIT_VAR(h);
		phalcon_call_method(h, im, "getImageHeight");

		phalcon_update_property_this(this_ptr, SL("_width"), w TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_height"), h TSRMLS_CC);

		ZVAL_BOOL(return_value, 1);
	} else {
		ZVAL_BOOL(return_value, 0);
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
 * @return boolean
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _crop) {

	zval *width, *height, *offset_x, *offset_y;
	zval *im, *ret, *w, *h, *tmp;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &width, &height, &offset_x, &offset_y);

	PHALCON_OBS_VAR(im);
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_INIT_VAR(ret);
	phalcon_call_method_p4(ret, im, "cropImage", width, height, offset_x, offset_y);

	if (zend_is_true(ret)) {
		PHALCON_INIT_VAR(w);
		phalcon_call_method(w, im, "getImageWidth");

		PHALCON_INIT_VAR(h);
		phalcon_call_method(h, im, "getImageHeight");

		phalcon_update_property_this(this_ptr, SL("_width"), w TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_height"), h TSRMLS_CC);

		PHALCON_INIT_VAR(tmp);
		ZVAL_LONG(tmp, 0);

		phalcon_call_method_p4_noret(im, "setImagePage", w, h, tmp, tmp);

		ZVAL_BOOL(return_value, 1);
	} else {
		ZVAL_BOOL(return_value, 0);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Execute a rotation.
 *
 * @param int $degrees
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _rotate) {

	zval *degrees;
	zval *im, *background, *color, *ret, *w, *h, *tmp;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &degrees);

	PHALCON_OBS_VAR(im);
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY_CC);

	ce0 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	PHALCON_INIT_VAR(background);
	object_init_ex(background, ce0);
	if (phalcon_has_constructor(background TSRMLS_CC)) {
		PHALCON_INIT_VAR(color);
		ZVAL_STRING(color, "transparent", 1);

		phalcon_call_method_p1_noret(background, "__construct", color);
	}

	PHALCON_INIT_VAR(ret);
	phalcon_call_method_p2(ret, im, "rotateImage", background, degrees);

	if (zend_is_true(ret)) {
		PHALCON_INIT_VAR(w);
		phalcon_call_method(w, im, "getImageWidth");

		PHALCON_INIT_VAR(h);
		phalcon_call_method(h, im, "getImageHeight");

		phalcon_update_property_this(this_ptr, SL("_width"), w TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_height"), h TSRMLS_CC);

		PHALCON_INIT_VAR(tmp);
		ZVAL_LONG(tmp, 0);

		phalcon_call_method_p4_noret(im, "setImagePage", w, h, tmp, tmp);

		ZVAL_BOOL(return_value, 1);
	} else {
		ZVAL_BOOL(return_value, 0);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Execute a flip.
 *
 * @param int $direction
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _flip) {

	zval *direction;
	zval *im, *ret;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &direction);

	PHALCON_OBS_VAR(im);
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY_CC);

	if (Z_LVAL_P(direction) == 11) {
		PHALCON_INIT_VAR(ret);
		phalcon_call_method(ret, im, "flopImage");
	} else {
		PHALCON_INIT_VAR(ret);
		phalcon_call_method(ret, im, "flipImage");
	}

	if (zend_is_true(ret)) {
		ZVAL_BOOL(return_value, 1);
	} else {
		ZVAL_BOOL(return_value, 0);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Execute a sharpen.
 *
 * @param int $amount
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _sharpen) {

	zval *amount, *a, *ret, *im, *tmp;
	int int_amount;
	double num;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &amount);

	PHALCON_OBS_VAR(im);
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY_CC);

	int_amount = Z_LVAL_P(amount);

	int_amount = (int_amount < 5) ? 5 : int_amount;
	num = (int_amount * 3.0) / 100;

	PHALCON_INIT_VAR(a);
	ZVAL_DOUBLE(a, num);

	PHALCON_INIT_VAR(tmp);
	ZVAL_LONG(tmp, 0);

	PHALCON_INIT_VAR(ret);
	phalcon_call_method_p2(ret, im, "sharpenImage", tmp, a);

	if (zend_is_true(ret)) {
		ZVAL_BOOL(return_value, 1);
	} else {
		ZVAL_BOOL(return_value, 0);
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
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _reflection) {

	zval *height, *opacity, *fade_in, *o;
	zval *im, *reflection, *image_width, *image_height, *reflection_width, *reflection_height, *tmp, *direction, *tmp_direction;
	zval *fade, *pseudoString, *composite, *constant, *channel, *image, *background, *mode, *ret, *w, *h;
	zend_class_entry *ce0, *ce1;
	int int_amount, ini_h;
	double num;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &height, &opacity, &fade_in);

	PHALCON_OBS_VAR(im);
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_OBS_VAR(image_width);
	phalcon_read_property_this(&image_width, this_ptr, SL("_width"), PH_NOISY_CC);

	PHALCON_OBS_VAR(image_height);
	phalcon_read_property_this(&image_height, this_ptr, SL("_height"), PH_NOISY_CC);

	PHALCON_INIT_VAR(reflection);
	phalcon_call_method(reflection, im, "clone");

	phalcon_call_method_noret(reflection, "flipImage");

	PHALCON_INIT_VAR(tmp);
	ZVAL_LONG(tmp, 0);

	phalcon_call_method_p4_noret(reflection, "cropImage", image_width, height, tmp, tmp);
	phalcon_call_method_p4_noret(reflection, "setImagePage", image_width, height, tmp, tmp);

	PHALCON_INIT_VAR(direction);
	array_init_size(direction, 2);

	phalcon_array_append_string(&direction, SL("transparent"), PH_SEPARATE);
	phalcon_array_append_string(&direction, SL("black"), PH_SEPARATE);

	if (zend_is_true(fade_in)) {
		PHALCON_INIT_NVAR(tmp_direction);
		phalcon_call_func_p1(tmp_direction, "array_reverse", direction);
	} else {
		PHALCON_CPY_WRT(tmp_direction, direction);
	}


	ce0 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_INIT_VAR(fade);
	object_init_ex(fade, ce0);
	if (phalcon_has_constructor(fade TSRMLS_CC)) {
		phalcon_call_method_noret(fade, "__construct");
	}

	PHALCON_INIT_NVAR(tmp);
	ZVAL_STRING(tmp, "gradient:%s-%s", 1);

	PHALCON_INIT_VAR(pseudoString);
	phalcon_call_func_p2(pseudoString, "vsprintf", tmp, tmp_direction);

	
	PHALCON_INIT_VAR(reflection_width);
	phalcon_call_method(reflection_width, reflection, "getImageWidth");

	PHALCON_INIT_VAR(reflection_height);
	phalcon_call_method(reflection_height, reflection, "getImageHeight");

	phalcon_call_method_p3_noret(fade, "newPseudoImage", reflection_width, reflection_height, pseudoString);

	PHALCON_INIT_VAR(composite);
	phalcon_get_class_constant(composite, ce0, SS("COMPOSITE_DSTOUT") TSRMLS_CC);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, 0);

	phalcon_call_method_p4_noret(reflection, "compositeImage", fade, composite, tmp, tmp);

	PHALCON_INIT_VAR(constant);
	phalcon_get_class_constant(constant, ce0, SS("EVALUATE_MULTIPLY") TSRMLS_CC);

	int_amount = Z_LVAL_P(opacity);
	num = int_amount / 100;

	PHALCON_INIT_VAR(o);
	ZVAL_DOUBLE(o, num);

	PHALCON_INIT_VAR(channel);
	phalcon_get_class_constant(channel, ce0, SS("CHANNEL_ALPHA") TSRMLS_CC);
 
	phalcon_call_method_p3_noret(reflection, "evaluateImage", constant, o, channel);

	PHALCON_INIT_VAR(image);
	object_init_ex(image, ce0);
	if (phalcon_has_constructor(image TSRMLS_CC)) {
		phalcon_call_method_noret(image, "__construct");
	}

	ini_h = Z_LVAL_P(image_height) + Z_LVAL_P(height);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, ini_h);

	ce1 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	PHALCON_INIT_VAR(background);
	object_init_ex(background, ce1);
	if (phalcon_has_constructor(background TSRMLS_CC)) {
		phalcon_call_method_noret(background, "__construct");
	}

	phalcon_call_method_p3_noret(image, "newImage", image_width, tmp, background);

	PHALCON_INIT_VAR(mode);
	phalcon_get_class_constant(mode, ce0, SS("ALPHACHANNEL_SET") TSRMLS_CC);
	phalcon_call_method_p1_noret(image, "setImageAlphaChannel", mode);

	PHALCON_INIT_VAR(ret);
	phalcon_call_method(ret, im, "getColorspace");
	phalcon_call_method_p1_noret(image, "setColorspace", ret);

	PHALCON_INIT_NVAR(composite);
	phalcon_get_class_constant(composite, ce0, SS("COMPOSITE_SRC") TSRMLS_CC);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, 0);

	PHALCON_INIT_NVAR(ret);
	phalcon_call_method_p4(ret, image, "compositeImage", im, composite, tmp, tmp);

	if (zend_is_true(ret)) {
		PHALCON_INIT_NVAR(composite);
		phalcon_get_class_constant(composite, ce0, SS("COMPOSITE_OVER") TSRMLS_CC);

		PHALCON_INIT_NVAR(tmp);
		ZVAL_LONG(tmp, 0);

		PHALCON_INIT_NVAR(ret);
		phalcon_call_method_p4(ret, image, "compositeImage", reflection, composite, tmp, image_height);
		if (zend_is_true(ret)) {
			PHALCON_INIT_VAR(w);
			phalcon_call_method(w, image, "getImageWidth");

			PHALCON_INIT_VAR(h);
			phalcon_call_method(h, image, "getImageHeight");

			phalcon_update_property_this(this_ptr, SL("_width"), w TSRMLS_CC);
			phalcon_update_property_this(this_ptr, SL("_height"), h TSRMLS_CC);
			phalcon_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);

			ZVAL_BOOL(return_value, 1);
		} else {
			ZVAL_BOOL(return_value, 0);
		}
	} else {
		ZVAL_BOOL(return_value, 0);
	}

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
	zval *im, *tmp, *watermark, *ret, *channel, *op_constant = NULL, *composite;
	zend_class_entry *ce0;
	double num;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &watermark_image, &offset_x, &offset_y, &opacity);

	PHALCON_SEPARATE_PARAM(watermark_image);

	PHALCON_OBS_VAR(im);
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_INIT_VAR(watermark);
	phalcon_call_method(watermark, watermark_image, "getImage");

	ce0 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	PHALCON_INIT_VAR(channel);
	phalcon_get_class_constant(channel, ce0, SS("ALPHACHANNEL_ACTIVATE") TSRMLS_CC);

	PHALCON_INIT_VAR(ret);
	phalcon_call_method(ret, watermark, "getImageAlphaChannel");

	if (!PHALCON_IS_EQUAL(ret, channel)) {
		PHALCON_INIT_NVAR(channel);
		phalcon_get_class_constant(channel, ce0, SS("ALPHACHANNEL_OPAQUE") TSRMLS_CC);

		phalcon_call_method_p1_noret(watermark, "setImageAlphaChannel", channel);
	}

	if (Z_LVAL_P(opacity) < 100) {
		PHALCON_INIT_NVAR(op_constant);
		phalcon_get_class_constant(op_constant, ce0, SS("EVALUATE_MULTIPLY") TSRMLS_CC);

		num = Z_LVAL_P(opacity) / 100;

		PHALCON_INIT_NVAR(op);
		ZVAL_DOUBLE(op, num);

		PHALCON_INIT_NVAR(channel);
		phalcon_get_class_constant(channel, ce0, SS("CHANNEL_ALPHA") TSRMLS_CC);

		phalcon_call_method_p3_noret(watermark, "evaluateImage", op_constant, op, channel);
	}

	PHALCON_INIT_NVAR(composite);
	phalcon_get_class_constant(composite, ce0, SS("COMPOSITE_DISSOLVE") TSRMLS_CC);

	PHALCON_INIT_NVAR(ret);
	phalcon_call_method_p4(ret, im, "compositeImage", watermark, composite, offset_x, offset_y);

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
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _background) {

	zval *r, *g, *b, *opacity, *op = NULL;
	zval *im, *color, *format, *background, *imagickpixel, *width, *height, *ret, *mode, *op_constant, *channel, *composite, *tmp;
	zend_class_entry *ce0, *ce1;
	double num;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &r, &g, &b, &opacity);

	ce0 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ce1 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	
	PHALCON_OBS_VAR(im);
	phalcon_read_property_this(&im, this_ptr, SL("_image"), PH_NOISY_CC);

	PHALCON_OBS_VAR(width);
	phalcon_read_property_this(&width, this_ptr, SL("_width"), PH_NOISY_CC);

	PHALCON_OBS_VAR(height);
	phalcon_read_property_this(&height, this_ptr, SL("_height"), PH_NOISY_CC);

	PHALCON_INIT_VAR(format);
	ZVAL_STRING(format, "rgb(%d, %d, %d)", 1);

	PHALCON_INIT_VAR(color);
	phalcon_call_func_p4(color, "sprintf", format, r, g, b);
	
	PHALCON_INIT_VAR(background);
	object_init_ex(background, ce0);
	if (phalcon_has_constructor(background TSRMLS_CC)) {
		phalcon_call_method_noret(background, "__construct");
	}

	PHALCON_INIT_VAR(imagickpixel);
	object_init_ex(imagickpixel, ce1);
	if (phalcon_has_constructor(imagickpixel TSRMLS_CC)) {
		phalcon_call_method_p1_noret(imagickpixel, "__construct", color);
	}

	phalcon_call_method_p3_noret(background, "newImage", width, height, imagickpixel);

	PHALCON_INIT_VAR(ret);
	phalcon_call_method(ret, background, "getImageAlphaChannel");

	if (!zend_is_true(ret)) {
		PHALCON_INIT_VAR(mode);
		phalcon_get_class_constant(mode, ce0, SS("ALPHACHANNEL_SET") TSRMLS_CC);

		phalcon_call_method_p1_noret(background, "setImageAlphaChannel", mode);
	}

	PHALCON_INIT_NVAR(imagickpixel);
	object_init_ex(imagickpixel, ce1);
	if (phalcon_has_constructor(imagickpixel TSRMLS_CC)) {
		PHALCON_INIT_NVAR(color);
		ZVAL_STRING(color, "transparent", 1);

		phalcon_call_method_p1_noret(imagickpixel, "__construct", color);
	}

	phalcon_call_method_p1_noret(background, "setImageBackgroundColor", imagickpixel);

	PHALCON_INIT_VAR(op_constant);
	phalcon_get_class_constant(op_constant, ce0, SS("EVALUATE_MULTIPLY") TSRMLS_CC);

	num = Z_LVAL_P(opacity) / 100;

	PHALCON_INIT_NVAR(op);
	ZVAL_DOUBLE(op, num);

	PHALCON_INIT_VAR(channel);
	phalcon_get_class_constant(channel, ce0, SS("CHANNEL_ALPHA") TSRMLS_CC);

	phalcon_call_method_p3_noret(background, "evaluateImage", op_constant, op, channel);

	PHALCON_INIT_NVAR(ret);
	phalcon_call_method(ret, im, "getColorspace");

	phalcon_call_method_p1_noret(background, "setColorspace", ret);

	PHALCON_INIT_VAR(composite);
	phalcon_get_class_constant(composite, ce0, SS("COMPOSITE_DISSOLVE") TSRMLS_CC);

	PHALCON_INIT_VAR(tmp);
	ZVAL_LONG(tmp, 0);

	PHALCON_INIT_NVAR(ret);
	phalcon_call_method_p4(ret, background, "compositeImage", im, composite, tmp, tmp);

	if (zend_is_true(ret)) {
		phalcon_update_property_this(this_ptr, SL("_image"), background TSRMLS_CC);

		ZVAL_BOOL(return_value, 1);
	} else {
		ZVAL_BOOL(return_value, 0);
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
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _save) {

	zval *file, *quality, *exception_message;
	zval *constant, *ret, *extension, *mime, *format, *type, *im;
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
	phalcon_call_method_p1_noret(im, "setImageCompressionQuality", quality);

	PHALCON_INIT_NVAR(ret);
	phalcon_call_method_p1(ret, im, "writeImage", file);

	if (zend_is_true(ret)) {
		phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

		PHALCON_INIT_VAR(mime);
		phalcon_call_func_p1(mime, "image_type_to_mime_type", type);

		phalcon_update_property_this(this_ptr, SL("_mime"), mime TSRMLS_CC);

		ZVAL_BOOL(return_value, 1);
	} else {
		ZVAL_BOOL(return_value, 0);
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
	zval *mime, *format, *type, *im, *image_string;
	char *ext;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &extension, &quality);

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
	phalcon_call_method_p1_noret(im, "setImageCompressionQuality", quality);

	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

	PHALCON_INIT_VAR(mime);
	phalcon_call_func_p1(mime, "image_type_to_mime_type", type);

	phalcon_update_property_this(this_ptr, SL("_mime"), mime TSRMLS_CC);

	PHALCON_INIT_VAR(image_string);
	phalcon_call_method(image_string, im, "getImagesBlob");

	RETURN_CCTOR(image_string);
}
