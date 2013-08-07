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
#include "kernel/exception.h"

#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Image\Adapter
 *
 * Base class for Phalcon\Image adapters
 */


/**
 * Phalcon\Image\Adapter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Image_Adapter){

	PHALCON_REGISTER_CLASS(Phalcon\\Image, Adapter, image_adapter, phalcon_image_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_image_adapter_ce, SL("_image"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_checked"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_file"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_realpath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_imageinfo"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_width"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_height"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_mime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Image constructor
 */
PHP_METHOD(Phalcon_Image_Adapter, __construct){

	zval *file, *realpath, *imageinfo, *width, *height, *type, *mime, *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &file);

	if (Z_TYPE_P(file) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "file didn't return a valid string");
		return;
	}

	
	phalcon_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);

	PHALCON_INIT_VAR(realpath);
	phalcon_call_func_p1(realpath, "realpath", file);
	phalcon_update_property_this(this_ptr, SL("_realpath"), realpath TSRMLS_CC);

	PHALCON_INIT_VAR(imageinfo);
	phalcon_call_func_p1(imageinfo, "getimagesize", realpath);

	if (Z_TYPE_P(imageinfo) != IS_ARRAY) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Can't open image file at '", realpath, "'");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_image_exception_ce, exception_message);
		return;
	}

	if (phalcon_array_isset_long(imageinfo, 0)) {
		PHALCON_OBS_VAR(width);
		phalcon_array_fetch_long(&width, imageinfo, 0, PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
	}

	if (phalcon_array_isset_long(imageinfo, 1)) {
		PHALCON_OBS_VAR(height);
		phalcon_array_fetch_long(&height, imageinfo, 1, PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);
	}

	if (phalcon_array_isset_long(imageinfo, 2)) {
		PHALCON_OBS_VAR(type);
		phalcon_array_fetch_long(&type, imageinfo, 2, PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	}

	if (phalcon_array_isset_string(imageinfo, SS("mime"))) {
		PHALCON_OBS_VAR(mime);
		phalcon_array_fetch_string(&mime, imageinfo, SL("mime"), PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_mime"), mime TSRMLS_CC);
	}

	phalcon_update_property_this(this_ptr, SL("_imageinfo"), imageinfo TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Returns the real path of the image file 
 *
 * @return string
 */
PHP_METHOD(Phalcon_Image_Adapter, getRealPath){


	RETURN_MEMBER(this_ptr, "_realpath");
}

/**
 * Returns the width of images 
 *
 * @return int
 */
PHP_METHOD(Phalcon_Image_Adapter, getWidth){


	RETURN_MEMBER(this_ptr, "_width");
}

/**
 * Returns the height of images 
 *
 * @return int
 */
PHP_METHOD(Phalcon_Image_Adapter, getHeight){


	RETURN_MEMBER(this_ptr, "_height");
}

/**
 * Returns the type of images 
 *
 * @return int
 */
PHP_METHOD(Phalcon_Image_Adapter, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

/**
 * Returns the mime of images 
 *
 * @return string
 */
PHP_METHOD(Phalcon_Image_Adapter, getMime){


	RETURN_MEMBER(this_ptr, "_mime");
}

/**
 * Returns the image of images 
 *
 * @return resource
 */
PHP_METHOD(Phalcon_Image_Adapter, getImage){


	RETURN_MEMBER(this_ptr, "_image");
}

/**
 * Resize the image to the given size. Either the width or the height can
 * be omitted and the image will be resized proportionally.
 *
 * @param int $width   new width
 * @param int $height  new height
 * @param int $master  master dimension
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, resize){

	zval *width = NULL, *height = NULL, *master = NULL;
	zval *image_width, *image_height, *w, *h;
	int tmp_image_width, tmp_image_height, tmp_width, tmp_height;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &width, &height, &master);

	if (!width) {
		PHALCON_INIT_VAR(width);
		ZVAL_NULL(width);
	}

	if (!height) {
		PHALCON_INIT_VAR(height);
		ZVAL_NULL(height);
	}

	if (!master) {
		PHALCON_INIT_VAR(master);
		ZVAL_LONG(master, 4);
	}

	PHALCON_OBS_VAR(image_width);
	phalcon_read_property_this(&image_width, this_ptr, SL("_width"), PH_NOISY_CC);

	PHALCON_OBS_VAR(image_height);
	phalcon_read_property_this(&image_height, this_ptr, SL("_height"), PH_NOISY_CC);

	if (Z_LVAL_P(master) == 2 && Z_TYPE_P(width) == IS_LONG) {
		ZVAL_LONG(master, 4);
	} else if (Z_LVAL_P(master) == 3 && Z_TYPE_P(height) == IS_LONG) {
		ZVAL_LONG(master, 4);
	}

	if (Z_TYPE_P(width) != IS_LONG) {
		if (Z_LVAL_P(master) == 1) {
			ZVAL_LONG(width, Z_LVAL_P(image_width));
		} else {
			ZVAL_LONG(master, 3);
		}
	}

	if (Z_TYPE_P(height) != IS_LONG) {
		if (Z_LVAL_P(master) == 1) {
			ZVAL_LONG(height, Z_LVAL_P(image_height));
		} else {
			ZVAL_LONG(master, 2);
		}
	}

	tmp_width = Z_LVAL_P(width);
	tmp_height = Z_LVAL_P(height);
	tmp_image_width = Z_LVAL_P(image_width);
	tmp_image_height = Z_LVAL_P(image_height);

	switch (Z_LVAL_P(master)) {
		case 4: // AUTO
		{
			if ( (tmp_image_width / tmp_width) > (tmp_image_height / tmp_height)) {
				ZVAL_LONG(master, 2);
			} else {
				ZVAL_LONG(master, 3);
			}
			break;
		}
		case 5: // INVERSE
		{
			if ( (tmp_image_width / tmp_width) > (tmp_image_height / tmp_height)) {
				ZVAL_LONG(master, 3);
			} else {
				ZVAL_LONG(master, 2);
			}
			break;
		}
	
	}

	switch (Z_LVAL_P(master)) {
		case 2: // WIDTH
		{
			ZVAL_LONG(height, tmp_image_height * tmp_width / tmp_image_width);
			break;
		}
		case 3: // HEIGHT
		{
			ZVAL_LONG(width, tmp_image_width * tmp_height / tmp_image_height);
			break;
		}
		case 6: //PRECISE
		{
			if ((tmp_width / tmp_height) > (tmp_image_width / tmp_image_height)) {
				ZVAL_LONG(height, tmp_image_height * tmp_width / tmp_image_width);
			} else {
				ZVAL_LONG(width, tmp_image_width * tmp_height / tmp_image_height);
			}
			break;
		}
	
	}

	PHALCON_INIT_VAR(w);
	phalcon_call_func_p1(w, "round", width);
	
	if (Z_LVAL_P(w) <= 0) {
		ZVAL_LONG(w, 1);
	}

	PHALCON_INIT_VAR(h);
	phalcon_call_func_p1(h, "round", height);
	if (Z_LVAL_P(h) <= 0) {
		ZVAL_LONG(h, 1);
	}

	phalcon_call_method_p2_noret(this_ptr, "_resize", w, h);

	RETURN_THIS();
}

/**
 * Crop an image to the given size. Either the width or the height can be
 * omitted and the current width or height will be used.
 *
 * @param int $width new width
 * @param int $height new height
 * @param int $offset_x  offset from the left
 * @param int $offset_y  offset from the top
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, crop){

	zval *width, *height, *offset_x = NULL, *offset_y = NULL;
	zval *t = NULL, *w = NULL, *h = NULL, *x = NULL, *y = NULL, *image_width, *image_height;
	int tmp_max_width, tmp_max_height, tmp_x, tmp_y, tmp_width, tmp_height, tmp_image_width, tmp_image_height, tmp_offset_x, tmp_offset_y;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 2, &width, &height, &offset_x, &offset_y);

	if (Z_TYPE_P(width) != IS_LONG || Z_TYPE_P(width) != IS_LONG) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "The param must be an int");
		return;
	}

	PHALCON_OBS_VAR(image_width);
	phalcon_read_property_this(&image_width, this_ptr, SL("_width"), PH_NOISY_CC);

	PHALCON_OBS_VAR(image_height);
	phalcon_read_property_this(&image_height, this_ptr, SL("_height"), PH_NOISY_CC);

	tmp_width = Z_LVAL_P(width);
	tmp_height = Z_LVAL_P(height);
	tmp_image_width = Z_LVAL_P(image_width);
	tmp_image_height = Z_LVAL_P(image_height);

	if (tmp_width > tmp_image_width) {
		PHALCON_INIT_NVAR(w);
		ZVAL_LONG(w, tmp_image_width);
	} else {
		PHALCON_CPY_WRT(w, width);
	}

	if (tmp_height > tmp_image_height) {
		PHALCON_INIT_NVAR(h);
		ZVAL_LONG(h, tmp_image_height);
	} else {
		PHALCON_CPY_WRT(h, height);
	}

	tmp_width = Z_LVAL_P(w);
	tmp_height = Z_LVAL_P(h);

	if (!offset_x || Z_TYPE_P(offset_x) != IS_LONG) {
		tmp_x = (tmp_image_width - tmp_width) / 2;

		PHALCON_INIT_NVAR(t);
		ZVAL_LONG(t, tmp_x);

		PHALCON_INIT_NVAR(x);
		phalcon_call_func_p1(x, "round", t);
	} else if (zend_is_true(offset_x)) {
		tmp_x = tmp_image_width - tmp_width;

		PHALCON_INIT_NVAR(x);
		ZVAL_LONG(x, tmp_x);
	} else if (Z_LVAL_P(offset_x) < 0) {
		tmp_x = tmp_image_width - tmp_width + Z_LVAL_P(offset_x);
		
		PHALCON_INIT_NVAR(x);
		ZVAL_LONG(x, tmp_x);
	} else {
		tmp_x = Z_LVAL_P(offset_x);
	}

	if (!offset_y || Z_TYPE_P(offset_y) != IS_LONG) {
		tmp_y = (tmp_image_height - tmp_height) / 2;

		PHALCON_INIT_NVAR(t);
		ZVAL_LONG(t, tmp_y);

		PHALCON_INIT_NVAR(y);
		phalcon_call_func_p1(y, "round", t);
	} else if (zend_is_true(offset_y)) {
		tmp_y = tmp_image_height - tmp_height;

		PHALCON_INIT_NVAR(y);
		ZVAL_LONG(y, tmp_y);
	} else if (Z_LVAL_P(offset_y) < 0) {
		tmp_y = tmp_image_height - tmp_height + Z_LVAL_P(offset_y);
		
		PHALCON_INIT_NVAR(y);
		ZVAL_LONG(y, tmp_y);
	} else {
		tmp_y = Z_LVAL_P(offset_y);
	}


	tmp_max_width = tmp_image_width - tmp_x;
	tmp_max_height = tmp_image_height - tmp_y;

	if (tmp_width > tmp_max_width) {
		tmp_width = tmp_max_width;
	}

	if (tmp_height > tmp_max_height) {
		tmp_height = tmp_max_height;
	}

	PHALCON_INIT_NVAR(w);
	ZVAL_LONG(w, tmp_width);

	PHALCON_INIT_NVAR(h);
	ZVAL_LONG(h, tmp_height);
	
	phalcon_call_method_p4_noret(this_ptr, "_crop", w, h, x, y);

	RETURN_THIS();
}

/**
 * Rotate the image by a given amount.
 *
 * @param int $degrees  degrees to rotate: -360-360
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, rotate){

	zval *degrees, *d;
	int tmp_degrees;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &degrees);

	if (Z_TYPE_P(degrees) != IS_LONG) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "degrees must be an int");
		return;
	}

	tmp_degrees = Z_LVAL_P(degrees);

	if (tmp_degrees > 180) {
		do {
			tmp_degrees -= 360;
		} while (tmp_degrees > 180);
	} else if (tmp_degrees < -180) {
		do {
			tmp_degrees += 360;
		} while (tmp_degrees < -180);
	}

	PHALCON_INIT_VAR(d);
	ZVAL_LONG(d, tmp_degrees);

	phalcon_call_method_p1_noret(this_ptr, "_rotate", d);

	RETURN_THIS();
}

/**
 * Flip the image along the horizontal or vertical axis.
 *
 * @param $int $direction  direction: Image::HORIZONTAL, Image::VERTICAL
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, flip){

	zval *direction, *d = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &direction);

	if (Z_TYPE_P(direction) != IS_LONG) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "direction must be an int");
		return;
	}

	if (Z_LVAL_P(direction) != 11) {
		PHALCON_INIT_NVAR(d);
		ZVAL_LONG(d, 12);
	} else {
		PHALCON_CPY_WRT(d, direction);
	}

	phalcon_call_method_p1_noret(this_ptr, "_flip", d);

	RETURN_THIS();
}

/**
 * Sharpen the image by a given amount.
 *
 * @param int $amount amount to sharpen: 1-100
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, sharpen){

	zval *amount, *tmp_amount = NULL;
	int a;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &amount);

	if (Z_TYPE_P(amount) != IS_LONG) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "amount must be an int");
		return;
	}

	a = Z_LVAL_P(amount);

	if (a > 100) {
		a = 100;
	} else if (a < 1) {
		a = 1;
	}

	PHALCON_INIT_NVAR(tmp_amount);
	ZVAL_LONG(tmp_amount, a);

	phalcon_call_method_p1_noret(this_ptr, "_sharpen", tmp_amount);

	RETURN_THIS();
}

/**
 * Add a reflection to an image. The most opaque part of the reflection
 * will be equal to the opacity setting and fade out to full transparent.
 * Alpha transparency is preserved.
 *
 * @param int $height reflection height
 * @param int $opacity reflection opacity: 0-100
 * @param boolean $fade_in TRUE to fade in, FALSE to fade out
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, reflection){

	zval *height = NULL, *opacity = NULL, *fade_in = NULL, *h = NULL, *o = NULL, *f = NULL;
	zval *image_height;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &height, &opacity, &fade_in);

	PHALCON_OBS_VAR(image_height);
	phalcon_read_property_this(&image_height, this_ptr, SL("_height"), PH_NOISY_CC);

	if (!height || Z_TYPE_P(height) != IS_LONG || Z_LVAL_P(height) > Z_LVAL_P(image_height)) {
		PHALCON_INIT_NVAR(h);
		ZVAL_LONG(h, Z_LVAL_P(image_height));
	} else {
		PHALCON_CPY_WRT(h, height);
	}

	if (!opacity || Z_TYPE_P(opacity) != IS_LONG || Z_LVAL_P(opacity) > 100) {
		PHALCON_INIT_NVAR(o);
		ZVAL_LONG(o, 100);
	} else if (Z_LVAL_P(opacity) < 0) {
		PHALCON_INIT_NVAR(o);
		ZVAL_LONG(o, 0);
	} else {
		PHALCON_CPY_WRT(o, opacity);
	}

	if (!fade_in) {
		PHALCON_INIT_NVAR(f);
		ZVAL_LONG(f, 0);
	} else {
		PHALCON_CPY_WRT(f, fade_in);
	}

	phalcon_call_method_p3_noret(this_ptr, "_reflection", h, o, f);

	RETURN_THIS();
}

/**
 * Add a watermark to an image with a specified opacity. Alpha transparency
 * will be preserved.
 *
 * @param Phalcon\Image\Adapter $watermark  watermark Image instance
 * @param int $offset_x offset from the left
 * @param int $offset_y offset from the top
 * @param int $opacity opacity of watermark: 1-100
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, watermark){

	zval *watermark, *offset_x = NULL, *offset_y = NULL, *opacity = NULL, *ox = NULL, *oy = NULL, *op = NULL;
	zval *image_width, *image_height, *watermark_width, *watermark_height;
	double d;
	int i;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &watermark, &offset_x, &offset_y, &opacity);

	PHALCON_OBS_VAR(image_width);
	phalcon_read_property_this(&image_width, this_ptr, SL("_width"), PH_NOISY_CC);

	PHALCON_OBS_VAR(image_height);
	phalcon_read_property_this(&image_height, this_ptr, SL("_height"), PH_NOISY_CC);

	PHALCON_OBS_VAR(watermark_width);
	phalcon_read_property_this(&watermark_width, watermark, SL("_width"), PH_NOISY_CC);

	PHALCON_OBS_VAR(watermark_height);
	phalcon_read_property_this(&watermark_height, watermark, SL("_height"), PH_NOISY_CC);

	if (!offset_x) {
		d = (Z_LVAL_P(image_width) - Z_LVAL_P(watermark_width)) / 2;
		i = (int)(d + 0.5);

		PHALCON_INIT_NVAR(ox);
		ZVAL_LONG(ox, i);
	} else if (zend_is_true(offset_x)) {
		d = Z_LVAL_P(image_width) - Z_LVAL_P(watermark_width);
		i = (int)(d + 0.5);

		PHALCON_INIT_NVAR(ox);
		ZVAL_LONG(ox, i);
	} else if (Z_TYPE_P(offset_x) == IS_LONG ) {
		if (Z_LVAL_P(offset_x) < 0) {
			d = Z_LVAL_P(image_width) - Z_LVAL_P(watermark_width) + Z_LVAL_P(offset_x);
			i = (int)(d + 0.5);

			PHALCON_INIT_NVAR(ox);
			ZVAL_LONG(ox, i);
		} else {
			PHALCON_CPY_WRT(ox, offset_x);
		}
	} else {
		d = (Z_LVAL_P(image_width) - Z_LVAL_P(watermark_width)) / 2;
		i = (int)(d + 0.5);

		PHALCON_INIT_NVAR(ox);
		ZVAL_LONG(ox, i);
	}

	if (!offset_y) {
		d = (Z_LVAL_P(image_height) - Z_LVAL_P(watermark_height)) / 2;
		i = (int)(d + 0.5);

		PHALCON_INIT_NVAR(oy);
		ZVAL_LONG(oy, i);
	} else if (zend_is_true(offset_y)) {
		d = Z_LVAL_P(image_height) - Z_LVAL_P(watermark_height);
		i = (int)(d + 0.5);

		PHALCON_INIT_NVAR(oy);
		ZVAL_LONG(oy, i);
	} else if (Z_TYPE_P(offset_y) == IS_LONG ) {
		if (Z_LVAL_P(offset_y) < 0) {
			d = Z_LVAL_P(image_height) - Z_LVAL_P(watermark_height) + Z_LVAL_P(offset_y);
			i = (int)(d + 0.5);

			PHALCON_INIT_NVAR(oy);
			ZVAL_LONG(oy, i);
		} else {
			PHALCON_CPY_WRT(oy, offset_y);
		}
	} else {
		d = (Z_LVAL_P(image_height) - Z_LVAL_P(watermark_height)) / 2;
		i = (int)(d + 0.5);

		PHALCON_INIT_NVAR(oy);
		ZVAL_LONG(oy, i);
	}

	if (!opacity) {
		i = 100;
	} else {
		i = Z_LVAL_P(opacity);

		if (i < 1) {
			i = 1;
		} else if (i > 100) {
			i = 100;
		}
	}

	PHALCON_INIT_NVAR(op);
	ZVAL_LONG(op, i);

	phalcon_call_method_p4_noret(this_ptr, "_watermark", watermark, ox, oy, op);

	RETURN_THIS();
}

/**
 * Set the background color of an image. This is only useful for images
 * with alpha transparency.
 *
 * @param string $color hexadecimal color value
 * @param int $opacity background opacity: 0-100
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, background){

	zval *color, *opacity, *op;
	zval *tmp = NULL, *tmp_color = NULL, *r = NULL, *g = NULL, *b = NULL;
	zval *pattern, *replacement;
	int i;
	char *c;
	char arr[3];
	char str[7];

	PHALCON_MM_GROW();

	//bzero(&arr, sizeof(arr));
	memset(arr, 0, sizeof(arr));
	memset(str, 0, sizeof(str));

	phalcon_fetch_params(1, 1, 1, &color, &opacity);

	if (Z_TYPE_P(color) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "color must be an string");
		return;
	}

	c = Z_STRVAL_P(color);

	if (c[0] == '#') {
		PHALCON_INIT_NVAR(tmp);
		ZVAL_LONG(tmp, 1);
		
		PHALCON_INIT_NVAR(tmp_color);
		phalcon_call_func_p2(tmp_color, "substr", color, tmp);
	} else {
		PHALCON_CPY_WRT(tmp_color, color);
	}

	if (Z_STRLEN_P(tmp_color) == 3) {
		PHALCON_INIT_VAR(pattern);
		ZVAL_STRING(pattern, "#.#", 1);

		PHALCON_INIT_VAR(replacement);
		ZVAL_STRING(replacement, "$0$0", 1);

		PHALCON_INIT_NVAR(tmp);
		phalcon_call_func_p3(tmp, "preg_replace", pattern, replacement, tmp_color);

		PHALCON_CPY_WRT(tmp_color, tmp);
	}

	i = Z_STRLEN_P(tmp_color);

	strncpy(str, Z_STRVAL_P(tmp_color), i > 6 ? 6 : i);

	if (strlen(str) >= 6) {

		arr[0] = str[0];
		arr[1] = str[1];

		PHALCON_INIT_NVAR(tmp);
		ZVAL_STRING(tmp, arr, 1);

		PHALCON_INIT_NVAR(r);
		phalcon_call_func_p1(r, "hexdec", tmp);

		arr[0] = str[2];
		arr[1] = str[3];

		PHALCON_INIT_NVAR(tmp);
		ZVAL_STRING(tmp, arr, 1);


		PHALCON_INIT_NVAR(g);
		phalcon_call_func_p1(g, "hexdec", tmp);

		arr[0] = str[4];
		arr[1] = str[5];

		PHALCON_INIT_NVAR(tmp);
		ZVAL_STRING(tmp, arr, 1);

		PHALCON_INIT_NVAR(b);
		phalcon_call_func_p1(b, "hexdec", tmp);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "color is not valid");
		return;
	}

	if (!opacity) {
		i = 100;
	} else {
		i = Z_LVAL_P(opacity);

		if (i < 1) {
			i = 1;
		} else if (i > 100) {
			i = 100;
		}
	}

	PHALCON_INIT_NVAR(op);
	ZVAL_LONG(op, i);

	phalcon_call_method_p4_noret(this_ptr, "_background", r, g, b, op);

	RETURN_THIS();
}

/**
 * Save the image. If the filename is omitted, the original image will
 * be overwritten.
 *
 * @param string $file new image path
 * @param int $quality quality of image: 1-100
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, save){

	zval *file = NULL, *quality = NULL, *exception_message;
	zval *ret, *dir, *constant;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &file, &quality);

	if (!file) {
		PHALCON_OBS_VAR(file);
		phalcon_read_property_this(&file, this_ptr, SL("_realpath"), PH_NOISY_CC);
	}
	
	if (!quality) {
		PHALCON_INIT_VAR(quality);
		ZVAL_LONG(quality, 100);
	} else if (Z_TYPE_P(quality) != IS_LONG) {
		PHALCON_INIT_NVAR(quality);
		ZVAL_LONG(quality, 100);
	}

	PHALCON_INIT_VAR(ret);
	phalcon_call_func_p1(ret, "is_file", file);

	if (zend_is_true(ret)) {
		phalcon_call_func_p1(ret, "is_writable", file);
		if (!zend_is_true(ret)) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "File must be writable: '", file, "'");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_image_exception_ce, exception_message);
			return;
		}
	} else {
		PHALCON_INIT_VAR(constant);
		if (zend_get_constant(SL("PATHINFO_DIRNAME"), constant TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}

		PHALCON_INIT_NVAR(ret);
		phalcon_call_func_p2(ret, "pathinfo", file, constant);

		PHALCON_INIT_VAR(dir);
		phalcon_call_func_p1(dir, "realpath", ret);

		PHALCON_INIT_NVAR(ret);
		phalcon_call_func_p1(ret, "is_dir", dir);

		if (!zend_is_true(ret)) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Directory must be writable: '", dir, "'");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_image_exception_ce, exception_message);
			return;
		} else {
			PHALCON_INIT_NVAR(ret);
			phalcon_call_func_p1(ret, "is_writable", dir);
			if (!zend_is_true(ret)) {
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Directory must be writable: '", dir, "'");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_image_exception_ce, exception_message);
				return;
			}
		}

	}

	if (Z_LVAL_P(quality) > 100) {
		ZVAL_LONG(quality, 100);
	} else if (Z_LVAL_P(quality) < 1) {
		ZVAL_LONG(quality, 1);
	}

	phalcon_call_method_p2_noret(this_ptr, "_save", file, quality);

	RETURN_THIS();
}

/**
 * Render the image and return the binary string.
 *
 * @param string $ext image type to return: png, jpg, gif, etc
 * @param int $quality quality of image: 1-100
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, render){

	zval *ext = NULL, *quality = NULL, *type, *include_dot, *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &ext, &quality);

	if (!ext) {
		PHALCON_INIT_VAR(include_dot);
		ZVAL_BOOL(include_dot, 0);

		PHALCON_OBS_VAR(type);
		phalcon_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY_CC);

		PHALCON_INIT_VAR(ext);
		phalcon_call_func_p2(ext, "image_type_to_extension", type, include_dot);
	}
	
	if (!quality) {
		PHALCON_INIT_VAR(quality);
		ZVAL_LONG(quality, 100);
	} else if (Z_TYPE_P(quality) != IS_LONG) {
		PHALCON_INIT_NVAR(quality);
		ZVAL_LONG(quality, 100);
	}

	phalcon_call_method_p2(return_value, this_ptr, "_render", ext, quality);

	RETURN_MM();
}
