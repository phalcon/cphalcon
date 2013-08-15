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
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
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
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "file parameter should be a string");
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
 * @param int $master  master dimension, if master equal TENSILE, the width and height must be input
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, resize){

	zval *width = NULL, *height = NULL, *master = NULL;
	zval *image_width, *image_height;
	int tmp_image_width, tmp_image_height, tmp_width, tmp_height;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &width, &height, &master);

	if (!master) {
		PHALCON_INIT_VAR(master);
		ZVAL_LONG(master, 4);
	} else {
		PHALCON_SEPARATE_PARAM(master);
	}

	if (Z_TYPE_P(master) != IS_LONG) {
		convert_to_long(master);
	}

	if (phalcon_get_intval(master) == 7) {
		if (!width || !height) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "width and height parameter must be input");
			return;
		}

		if (Z_TYPE_P(width) != IS_LONG) {
			convert_to_long(width);
		}

		if (Z_TYPE_P(height) != IS_LONG) {
			convert_to_long(height);
		}
	} else {
		if (!width) {
			PHALCON_INIT_VAR(width);
		} else {
			PHALCON_SEPARATE_PARAM(width);
		}

		if (!height) {
			PHALCON_INIT_VAR(height);
		} else {
			PHALCON_SEPARATE_PARAM(height);
		}

		PHALCON_OBS_VAR(image_width);
		phalcon_read_property_this(&image_width, this_ptr, SL("_width"), PH_NOISY_CC);

		PHALCON_OBS_VAR(image_height);
		phalcon_read_property_this(&image_height, this_ptr, SL("_height"), PH_NOISY_CC);
		
		tmp_image_width = phalcon_get_intval(image_width);
		tmp_image_height = phalcon_get_intval(image_height);

		if (Z_LVAL_P(master) == 2 && Z_TYPE_P(width) == IS_LONG) {
			ZVAL_LONG(master, 4);
		} else if (Z_LVAL_P(master) == 3 && Z_TYPE_P(height) == IS_LONG) {
			ZVAL_LONG(master, 4);
		}

		if (Z_TYPE_P(width) != IS_LONG) {
			if (Z_LVAL_P(master) == 1) {
				tmp_width = tmp_image_width;
			} else {
				ZVAL_LONG(master, 3);
			}
		} else {
			tmp_width = Z_LVAL_P(width);
		}

		if (Z_TYPE_P(height) != IS_LONG) {
			if (Z_LVAL_P(master) == 1) {
				tmp_height = tmp_image_height;
			} else {
				ZVAL_LONG(master, 2);
			}
		} else {
			tmp_height = Z_LVAL_P(height);
		}

		switch (phalcon_get_intval(master)) {
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

		switch (phalcon_get_intval(master)) {
			case 2: // WIDTH
			{
				tmp_height = (int)((tmp_image_height * tmp_width / tmp_image_width) + 0.5);
				break;
			}
			case 3: // HEIGHT
			{
				tmp_width = (int)((tmp_image_width * tmp_height / tmp_image_height) + 0.5);
				break;
			}
			case 6: //PRECISE
			{
				if ((tmp_width / tmp_height) > (tmp_image_width / tmp_image_height)) {
					tmp_height = (int)((tmp_image_height * tmp_width / tmp_image_width) + 0.5);
				} else {
					tmp_width = (int)((tmp_image_width * tmp_height / tmp_image_height) + 0.5);
				}
				break;
			}
		
		}
		
		if (tmp_width <= 0) {
			tmp_width = 1;
		}

		if (tmp_height <= 0) {
			tmp_height = 1;
		}

		PHALCON_INIT_NVAR(width);
		ZVAL_LONG(width, tmp_width);

		PHALCON_INIT_NVAR(height);
		ZVAL_LONG(height, tmp_height);
	}

	phalcon_call_method_p2_noret(this_ptr, "_resize", width, height);

	RETURN_THIS();
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
PHP_METHOD(Phalcon_Image_Adapter, liquidRescale){

	zval *width, *height, *delta_x = NULL, *rigidity = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 2, &width, &height, &delta_x, &rigidity);

	if (Z_TYPE_P(width) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(width);
		convert_to_long(width);
	}

	if (Z_TYPE_P(height) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(height);
		convert_to_long(height);
	}

	if (!delta_x) {
		PHALCON_INIT_VAR(delta_x);
		ZVAL_LONG(delta_x, 0);
	} else if (Z_TYPE_P(delta_x) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(delta_x);
		convert_to_long(delta_x);
	}

	if (!rigidity) {
		PHALCON_INIT_VAR(rigidity);
		ZVAL_LONG(rigidity, 0);
	} else if (Z_TYPE_P(rigidity) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(rigidity);
		convert_to_long(rigidity);
	}

	phalcon_call_method_p4_noret(this_ptr, "_liquidRescale", width, height, delta_x, rigidity);

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
	zval *image_width, *image_height;
	int tmp_max_width, tmp_max_height, tmp_width, tmp_height, tmp_image_width, tmp_image_height, tmp_offset_x, tmp_offset_y;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 2, &width, &height, &offset_x, &offset_y);

	PHALCON_SEPARATE_PARAM(width);
	PHALCON_SEPARATE_PARAM(height);

	if (Z_TYPE_P(width) != IS_LONG) {
		convert_to_long(width);
	}

	if (Z_TYPE_P(height) != IS_LONG) {
		convert_to_long(height);
	}

	PHALCON_OBS_VAR(image_width);
	phalcon_read_property_this(&image_width, this_ptr, SL("_width"), PH_NOISY_CC);

	PHALCON_OBS_VAR(image_height);
	phalcon_read_property_this(&image_height, this_ptr, SL("_height"), PH_NOISY_CC);

	tmp_width = phalcon_get_intval(width);
	tmp_height = phalcon_get_intval(height);
	tmp_image_width = phalcon_get_intval(image_width);
	tmp_image_height = phalcon_get_intval(image_height);

	if (tmp_width > tmp_image_width) {
		tmp_width = tmp_image_width;
	}

	if (tmp_height > tmp_image_height) {
		tmp_height = tmp_image_height;
	}

	if (!offset_x) {
		tmp_offset_x = (int)(((tmp_image_width - tmp_width) / 2) + 0.5);
	} else {		
		PHALCON_SEPARATE_PARAM(offset_x);

		if (zend_is_true(offset_x)) {
			tmp_offset_x = tmp_image_width - tmp_width;
		} else if (Z_TYPE_P(offset_x) != IS_LONG) {
			tmp_offset_x = (int)(((tmp_image_width - tmp_width) / 2) + 0.5);
		} else if (Z_LVAL_P(offset_x) < 0) {
			tmp_offset_x = (int)(tmp_image_width - tmp_width + Z_LVAL_P(offset_x) + 0.5);
		} else {
			tmp_offset_x = Z_LVAL_P(offset_x);
		}
	}

	if (!offset_y) {
		tmp_offset_y = (int)(((tmp_image_height - tmp_height) / 2) + 0.5);
	} else {
		PHALCON_SEPARATE_PARAM(offset_y);

		if (zend_is_true(offset_y)) {
			tmp_offset_y = tmp_image_height - tmp_height;
		} else if (Z_TYPE_P(offset_y) != IS_LONG) {
			tmp_offset_y = (int)(((tmp_image_height - tmp_height) / 2) + 0.5);
		} else if (Z_LVAL_P(offset_y) < 0) {
			tmp_offset_y = tmp_image_height - tmp_height + Z_LVAL_P(offset_y);
		} else {
			tmp_offset_y = Z_LVAL_P(offset_y);
		}
	}

	tmp_max_width = tmp_image_width - tmp_offset_x;
	tmp_max_height = tmp_image_height - tmp_offset_y;

	if (tmp_width > tmp_max_width) {
		tmp_width = tmp_max_width;
	}

	if (tmp_height > tmp_max_height) {
		tmp_height = tmp_max_height;
	}

	PHALCON_INIT_NVAR(width);
	ZVAL_LONG(width, tmp_width);

	PHALCON_INIT_NVAR(height);
	ZVAL_LONG(height, tmp_height);

	PHALCON_INIT_NVAR(offset_x);
	ZVAL_LONG(offset_x, tmp_offset_x);

	PHALCON_INIT_NVAR(offset_y);
	ZVAL_LONG(offset_y, tmp_offset_y);
	
	phalcon_call_method_p4_noret(this_ptr, "_crop", width, height, offset_x, offset_y);

	RETURN_THIS();
}

/**
 * Rotate the image by a given amount.
 *
 * @param int $degrees  degrees to rotate: -360-360
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, rotate){

	zval *degrees;
	int tmp_degrees;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &degrees);

	PHALCON_SEPARATE_PARAM(degrees);

	if (Z_TYPE_P(degrees) != IS_LONG) {
		convert_to_long(degrees);
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

	PHALCON_INIT_VAR(degrees);
	ZVAL_LONG(degrees, tmp_degrees);

	phalcon_call_method_p1_noret(this_ptr, "_rotate", degrees);

	RETURN_THIS();
}

/**
 * Flip the image along the horizontal or vertical axis.
 *
 * @param $int $direction  direction: Image::HORIZONTAL, Image::VERTICAL
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, flip){

	zval *direction;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &direction);
	
	PHALCON_SEPARATE_PARAM(direction);

	if (Z_TYPE_P(direction) != IS_LONG) {
		convert_to_long(direction);
	}

	if (Z_LVAL_P(direction) != 11) {
		ZVAL_LONG(direction, 12);
	}

	phalcon_call_method_p1_noret(this_ptr, "_flip", direction);

	RETURN_THIS();
}

/**
 * Sharpen the image by a given amount.
 *
 * @param int $amount amount to sharpen: 1-100
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, sharpen){

	zval *amount;
	int a;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &amount);

	PHALCON_SEPARATE_PARAM(amount);

	if (Z_TYPE_P(amount) != IS_LONG) {
		convert_to_long(amount);
	}

	if (phalcon_get_intval(amount) > 100) {
		ZVAL_LONG(amount, 100);
	} else if (phalcon_get_intval(amount) < 1) {
		ZVAL_LONG(amount, 1);
	}

	phalcon_call_method_p1_noret(this_ptr, "_sharpen", amount);

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

	zval *height = NULL, *opacity = NULL, *fade_in = NULL;
	zval *image_height;
	int tmp_image_height;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &height, &opacity, &fade_in);

	PHALCON_OBS_VAR(image_height);
	phalcon_read_property_this(&image_height, this_ptr, SL("_height"), PH_NOISY_CC);

	tmp_image_height = phalcon_get_intval(image_height);

	if (!height) {
		PHALCON_INIT_NVAR(height);
		ZVAL_LONG(height, tmp_image_height);
	} else if (Z_TYPE_P(height) != IS_LONG || Z_LVAL_P(height) > tmp_image_height) {
		PHALCON_SEPARATE_PARAM(height);

		PHALCON_INIT_NVAR(height);
		ZVAL_LONG(height, tmp_image_height);
	}

	if (!opacity) {
		PHALCON_INIT_NVAR(opacity);
		ZVAL_LONG(opacity, 100);
	} else {
		PHALCON_SEPARATE_PARAM(opacity);

		if (Z_TYPE_P(opacity) != IS_LONG || Z_LVAL_P(opacity) > 100) {
			PHALCON_INIT_NVAR(opacity);
			ZVAL_LONG(opacity, 100);
		} else if (Z_LVAL_P(opacity) < 0) {
			ZVAL_LONG(opacity, 0);
		}
	}

	if (!fade_in) {
		PHALCON_INIT_NVAR(fade_in);
		ZVAL_LONG(fade_in, 0);
	}

	phalcon_call_method_p3_noret(this_ptr, "_reflection", height, opacity, fade_in);

	RETURN_THIS();
}

/**
 * Add a watermark to an image with a specified opacity. Alpha transparency
 * will be preserved.
 *
 * @param Phalcon\Image\Adapter $watermark  watermark Image instance
 * @param int $offset_x offset from the left, If less than 0 offset from the right, If true right the x offset
 * @param int $offset_y offset from the top, If less than 0 offset from the bottom, If true bottom the Y offset
 * @param int $opacity opacity of watermark: 1-100
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, watermark){

	zval *watermark, *offset_x = NULL, *offset_y = NULL, *opacity = NULL;
	zval *image_width, *image_height, *watermark_width, *watermark_height;
	int tmp_image_width, tmp_image_height, tmp_watermark_width, tmp_watermark_height, tmp_offset_x, tmp_offset_y;

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

	tmp_image_width = phalcon_get_intval(image_width);
	tmp_image_height = phalcon_get_intval(image_height);
	tmp_watermark_width = phalcon_get_intval(watermark_width);
	tmp_watermark_height = phalcon_get_intval(watermark_height);

	if (!offset_x) {
		tmp_offset_x = (int)(((tmp_image_width - tmp_watermark_width) / 2) + 0.5);
	} else {
		PHALCON_SEPARATE_PARAM(offset_x);
		if (Z_TYPE_P(offset_x) == IS_LONG ) {		
			tmp_offset_x = phalcon_get_intval(offset_x);
			if (tmp_offset_x < 0) {
				tmp_offset_x = (int)(tmp_image_width - tmp_watermark_width + tmp_offset_x + 0.5);
			}
		} else if (zend_is_true(offset_x)) {
			tmp_offset_x = (int)(tmp_image_width - tmp_watermark_width);
		} else {
			tmp_offset_x = (int)(((tmp_image_width - tmp_watermark_width) / 2) + 0.5);
		}
	}

	PHALCON_INIT_NVAR(offset_x);
	ZVAL_LONG(offset_x, tmp_offset_x);

	if (!offset_y) {
		tmp_offset_y = (int)(((tmp_image_height - tmp_watermark_height) / 2) + 0.5);
	} else {		
		PHALCON_SEPARATE_PARAM(offset_y);
		if (Z_TYPE_P(offset_y) == IS_LONG ) {
			tmp_offset_y = phalcon_get_intval(offset_y);
			if (tmp_offset_y < 0) {
				tmp_offset_y = (int)(tmp_image_height - tmp_watermark_height + tmp_offset_y + 0.5);
			}
		} else if (zend_is_true(offset_y)) {
			tmp_offset_y = (int)(tmp_image_height - tmp_watermark_height);
		} else {
			tmp_offset_y = (int)(((tmp_image_height - tmp_watermark_height) / 2) + 0.5);
		}
	}

	PHALCON_INIT_NVAR(offset_y);
	ZVAL_LONG(offset_y, tmp_offset_y);

	if (!opacity) {
		PHALCON_INIT_NVAR(opacity);
		ZVAL_LONG(opacity, 100);
	} else {		
		PHALCON_SEPARATE_PARAM(opacity);

		PHALCON_INIT_NVAR(opacity);
		if (phalcon_get_intval(opacity) < 1) {
			ZVAL_LONG(opacity, 1);
		} else if (phalcon_get_intval(opacity) > 100) {
			ZVAL_LONG(opacity, 100);
		}
	}

	phalcon_call_method_p4_noret(this_ptr, "_watermark", watermark, offset_x, offset_y, opacity);

	RETURN_THIS();
}


/**
 * Add a text to an image with a specified opacity.
 *
 * @param string text
 * @param int $offset_x offset from the left, If less than 0 offset from the right, If true right the x offset
 * @param int $offset_y offset from the top, If less than 0 offset from the bottom, If true bottom the Y offset
 * @param int $opacity opacity of text: 1-100
 * @param string $color hexadecimal color value
 * @param int $size font pointsize
 * @param string $fontfile font path
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, text){

	zval *text, *offset_x = NULL, *offset_y = NULL, *opacity = NULL, *color = NULL, *size = NULL, *fontfile = NULL;
	zval *tmp_color = NULL, *pattern, *replacement, *tmp = NULL, *r, *g, *b;
	int i;
	char *c;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 6, &text, &offset_x, &offset_y, &opacity, &color, &size, &fontfile);

	if (!offset_x) {
		PHALCON_INIT_NVAR(offset_x);
	} else {
		PHALCON_SEPARATE_PARAM(offset_x);
	}
	
	if (!offset_y) {
		PHALCON_INIT_NVAR(offset_y);
	} else {
		PHALCON_SEPARATE_PARAM(offset_y);
	}

	if (Z_TYPE_P(offset_x) == IS_NULL ) {
		PHALCON_INIT_NVAR(offset_x);
		ZVAL_BOOL(offset_x, 0);
	}

	if (Z_TYPE_P(offset_y) == IS_NULL) {
		PHALCON_INIT_NVAR(offset_y);
		ZVAL_BOOL(offset_y, 0);
	}

	if (!opacity) {
		PHALCON_INIT_NVAR(opacity);
		ZVAL_LONG(opacity, 100);
	} else if (Z_TYPE_P(opacity) == IS_NULL) {
		PHALCON_SEPARATE_PARAM(opacity);
		PHALCON_INIT_NVAR(opacity);
		ZVAL_LONG(opacity, 100);
	}  else {
		i = phalcon_get_intval(opacity);

		if (i < 1) {
			PHALCON_SEPARATE_PARAM(opacity);
			PHALCON_INIT_NVAR(opacity);
			ZVAL_LONG(opacity, 1);
		} else if (i > 100) {
			PHALCON_SEPARATE_PARAM(opacity);
			PHALCON_INIT_NVAR(opacity);
			ZVAL_LONG(opacity, 100);
		}
	}

	if (!color) {
		PHALCON_INIT_NVAR(color);
		ZVAL_STRING(color, "#000000", 1);
	} else if (Z_TYPE_P(color) == IS_NULL) {
		PHALCON_SEPARATE_PARAM(color);
		PHALCON_INIT_NVAR(color);
		ZVAL_STRING(color, "#000000", 1);
	}

	if (!size) {
		PHALCON_INIT_NVAR(size);
		ZVAL_LONG(size, 12);
	} else if (Z_TYPE_P(size) == IS_NULL) {
		PHALCON_SEPARATE_PARAM(size);
		PHALCON_INIT_NVAR(size);
		ZVAL_LONG(size, 12);
	}

	if (!fontfile) {
		PHALCON_INIT_NVAR(fontfile);
	}

	c = Z_STRVAL_P(color);

	if (c[0] == '#') {
		PHALCON_INIT_NVAR(tmp_color);
		phalcon_substr(tmp_color, color, 1, 0);
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

	if (Z_STRLEN_P(tmp_color) >= 6) {
		PHALCON_INIT_NVAR(tmp);
		phalcon_substr(tmp, tmp_color, 0, 2);

		PHALCON_INIT_VAR(r);
		phalcon_call_func_p1(r, "hexdec", tmp);

		PHALCON_INIT_NVAR(tmp);
		phalcon_substr(tmp, tmp_color, 2, 2);

		PHALCON_INIT_VAR(g);
		phalcon_call_func_p1(g, "hexdec", tmp);

		PHALCON_INIT_NVAR(tmp);
		phalcon_substr(tmp, tmp_color, 4, 2);

		PHALCON_INIT_VAR(b);
		phalcon_call_func_p1(b, "hexdec", tmp);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "color is not valid");
		return;
	}

	PHALCON_CALL_METHOD(NULL, this_ptr, "_text", 0, 9, text, offset_x, offset_y, opacity, r, g, b, size, fontfile);

	RETURN_THIS();
}

/**
 * Composite one image onto another

 *
 * @param Phalcon\Image\Adapter $mask  mask Image instance
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, mask){

	zval *mask;

	phalcon_fetch_params(1, 1, 0, &mask);
	phalcon_call_method_p1_noret(this_ptr, "_mask", mask);

	RETURN_THISW();
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

	zval *color, *opacity = NULL;
	zval *tmp = NULL, *tmp_color = NULL, *r = NULL, *g = NULL, *b = NULL;
	zval *pattern, *replacement;
	int i;
	char *c;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &color, &opacity);

	if (Z_TYPE_P(color) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "color must be an string");
		return;
	}

	c = Z_STRVAL_P(color);

	if (c[0] == '#') {
		PHALCON_INIT_NVAR(tmp_color);
		phalcon_substr(tmp_color, color, 1, 0);
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

	if (Z_STRLEN_P(tmp_color) >= 6) {

		PHALCON_INIT_NVAR(tmp);
		phalcon_substr(tmp, tmp_color, 0, 2);

		PHALCON_INIT_NVAR(r);
		phalcon_call_func_p1(r, "hexdec", tmp);

		PHALCON_INIT_NVAR(tmp);
		phalcon_substr(tmp, tmp_color, 2, 2);

		PHALCON_INIT_NVAR(g);
		phalcon_call_func_p1(g, "hexdec", tmp);

		PHALCON_INIT_NVAR(tmp);
		phalcon_substr(tmp, tmp_color, 4, 2);

		PHALCON_INIT_NVAR(b);
		phalcon_call_func_p1(b, "hexdec", tmp);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "color is not valid");
		return;
	}

	if (!opacity) {
		PHALCON_INIT_NVAR(opacity);
		ZVAL_LONG(opacity, 100);
	} else {
		PHALCON_SEPARATE_PARAM(opacity);

		i = phalcon_get_intval(opacity);

		if (i < 1) {
			PHALCON_INIT_NVAR(opacity);
			ZVAL_LONG(opacity, 1);
		} else if (i > 100) {
			PHALCON_INIT_NVAR(opacity);
			ZVAL_LONG(opacity, 100);
		}
	}

	phalcon_call_method_p4_noret(this_ptr, "_background", r, g, b, opacity);

	RETURN_THIS();
}

/**
 * Blur image
 *
 * @param int $radius Blur radius
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, blur){

	zval *radius = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &radius);

	if (!radius) {
		PHALCON_INIT_VAR(radius);
		ZVAL_LONG(radius, 1);
	} else if (Z_TYPE_P(radius) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(radius);

		PHALCON_INIT_NVAR(radius);
		ZVAL_LONG(radius, 1);
	} else if (phalcon_get_intval(radius) < 1) {
		PHALCON_SEPARATE_PARAM(radius);

		PHALCON_INIT_NVAR(radius);
		ZVAL_LONG(radius, 1);
	}

	phalcon_call_method_p1_noret(this_ptr, "_blur", radius);

	RETURN_THIS();
}

/**
 * Save the image. If the filename is omitted, the original image will
 * be overwritten.
 *
 * @param string $file new image path
 * @param int $quality quality of image: 1-100
 * @return boolean
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
		PHALCON_SEPARATE_PARAM(quality);

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

	PHALCON_INIT_NVAR(ret);
	phalcon_call_method_p2(ret, this_ptr, "_save", file, quality);

	RETURN_CTOR(ret);
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
