
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Image, Adapter, phalcon, image_adapter, phalcon_image_adapter_method_entry, 0);

	zend_declare_property_null(phalcon_image_adapter_ce, SL("_image"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_file"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_realpath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_width"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_height"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_mime"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_image_adapter_ce, SL("_checked"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Returns the image of images
 *
 * @return string
 */
PHP_METHOD(Phalcon_Image_Adapter, getImage) {


	RETURN_MEMBER(this_ptr, "_image");

}

/**
 * Returns the real path of the image file
 *
 * @return string
 */
PHP_METHOD(Phalcon_Image_Adapter, getRealPath) {


	RETURN_MEMBER(this_ptr, "_realpath");

}

/**
 * Returns the width of images
 *
 * @return int
 */
PHP_METHOD(Phalcon_Image_Adapter, getWidth) {


	RETURN_MEMBER(this_ptr, "_width");

}

/**
 * Returns the height of images
 *
 * @return int
 */
PHP_METHOD(Phalcon_Image_Adapter, getHeight) {


	RETURN_MEMBER(this_ptr, "_height");

}

/**
 * Returns the type of images
 *
 * @return int
 */
PHP_METHOD(Phalcon_Image_Adapter, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Returns the mime of images
 *
 * @return string
 */
PHP_METHOD(Phalcon_Image_Adapter, getMime) {


	RETURN_MEMBER(this_ptr, "_mime");

}

/**
 * Resize the image to the given size
 *
 * @param int width
 * @param int height
 * @param int master
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, resize) {

	double ratio;
	zval *width_param = NULL, *height_param = NULL, *master_param = NULL, *_0, *_1, *_2, *_3, *_4, *_5 = NULL, _6 = zval_used_for_init, *_7, *_8, *_9, *_10;
	int width, height, master;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &width_param, &height_param, &master_param);

	if (!width_param) {
		width = 0;
	} else {
		width = zephir_get_intval(width_param);
	}
	if (!height_param) {
		height = 0;
	} else {
		height = zephir_get_intval(height_param);
	}
	if (!master_param) {
		master = 7;	} else {
		master = zephir_get_intval(master_param);
	}


	if ((master == 7)) {
		if ((!width || !height)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "width and height must be specified");
			return;
		}
	} else {
		if ((master == 4)) {
			if ((!width || !height)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "width and height must be specified");
				return;
			}
			master = (0 == 1);
		}
		if ((master == 5)) {
			if ((!width || !height)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "width and height must be specified");
				return;
			}
			master = (0 == 1);
		}
		do {
			if ((master == 2)) {
				if (!(width)) {
					ZEPHIR_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "width must be specified");
					return;
				}
				_0 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				_1 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				height = ((zephir_get_numberval(_0) * width) / zephir_get_numberval(_1));
				break;
			}
			if ((master == 3)) {
				if (!(height)) {
					ZEPHIR_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "height must be specified");
					return;
				}
				_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				width = ((zephir_get_numberval(_0) * height) / zephir_get_numberval(_1));
				break;
			}
			if ((master == 6)) {
				if ((!width || !height)) {
					ZEPHIR_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "width and height must be specified");
					return;
				}
				_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_2);
				div_function(_2, _0, _1 TSRMLS_CC);
				ratio = zephir_get_numberval(_2);
				if ((((width / height)) > ratio)) {
					_0 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
					_1 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
					height = ((zephir_get_numberval(_0) * width) / zephir_get_numberval(_1));
				} else {
					_3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
					_4 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
					width = ((zephir_get_numberval(_3) * height) / zephir_get_numberval(_4));
				}
				break;
			}
			if ((master == 1)) {
				if (!(width)) {
					ZEPHIR_OBS_VAR(_5);
					zephir_read_property_this(&_5, this_ptr, SL("_width"), PH_NOISY_CC);
					width = zephir_get_intval(_5);
				}
				if (!(height)) {
					ZEPHIR_OBS_NVAR(_5);
					zephir_read_property_this(&_5, this_ptr, SL("_height"), PH_NOISY_CC);
					width = zephir_get_intval(_5);
				}
				break;
			}
		} while(0);

	}
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, width);
	ZEPHIR_INIT_VAR(_7);
	zephir_call_func_p1(_7, "round", &_6);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, 1);
	ZEPHIR_INIT_VAR(_8);
	zephir_call_func_p2(_8, "max", _7, &_6);
	width = zephir_get_intval(_8);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, height);
	ZEPHIR_INIT_BNVAR(_8);
	zephir_call_func_p1(_8, "round", &_6);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, 1);
	ZEPHIR_INIT_VAR(_9);
	zephir_call_func_p2(_9, "max", _8, &_6);
	height = zephir_get_intval(_9);
	ZEPHIR_INIT_BNVAR(_9);
	ZVAL_LONG(_9, width);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_LONG(_10, height);
	zephir_call_method_p2_noret(this_ptr, "_resize", _9, _10);
	RETURN_THIS();

}

/**
 * Crop an image to the given size
 *
 * @param int width
 * @param int height
 * @param int offset_x
 * @param int offset_y
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, crop) {

	zval *width_param = NULL, *height_param = NULL, *offset_x_param = NULL, *offset_y_param = NULL, *_0, *_1, *_2 = NULL, *_3, *_4;
	int width, height, offset_x, offset_y;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &width_param, &height_param, &offset_x_param, &offset_y_param);

		width = zephir_get_intval(width_param);
		height = zephir_get_intval(height_param);
	if (!offset_x_param) {
		offset_x = 0;
	} else {
		offset_x = zephir_get_intval(offset_x_param);
	}
	if (!offset_y_param) {
		offset_y = 0;
	} else {
		offset_y = zephir_get_intval(offset_y_param);
	}


	if (!(offset_x)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		offset_x = ((((zephir_get_numberval(_0) - width)) / 2));
	} else {
		if ((offset_x < 0)) {
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			offset_x = ((zephir_get_numberval(_0) - width) + offset_x);
		}
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		if (ZEPHIR_GT_LONG(_1, offset_x)) {
			ZEPHIR_OBS_VAR(_2);
			zephir_read_property_this(&_2, this_ptr, SL("_width"), PH_NOISY_CC);
			offset_x = zephir_get_intval(_2);
		}
	}
	if (!(offset_y)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		offset_y = ((((zephir_get_numberval(_0) - height)) / 2));
	} else {
		if ((offset_y < 0)) {
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			offset_y = ((zephir_get_numberval(_0) - height) + offset_y);
		}
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		if (ZEPHIR_GT_LONG(_1, offset_y)) {
			ZEPHIR_OBS_NVAR(_2);
			zephir_read_property_this(&_2, this_ptr, SL("_height"), PH_NOISY_CC);
			offset_y = zephir_get_intval(_2);
		}
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	if ((width > ((zephir_get_numberval(_0) - offset_x)))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		width = (zephir_get_numberval(_1) - offset_x);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	if ((height > ((zephir_get_numberval(_0) - offset_y)))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		height = (zephir_get_numberval(_1) - offset_y);
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, width);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, height);
	zephir_call_method_p2_noret(this_ptr, "_crop", _3, _4);
	RETURN_THIS();

}

/**
 * Rotate the image by a given amount
 *
 * @param int degrees
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, rotate) {

	zval *degrees_param = NULL, *_0;
	int degrees;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);

		degrees = zephir_get_intval(degrees_param);


	if ((degrees > 180)) {
		degrees %= 360;
		if ((degrees > 180)) {
			degrees -= 360;
		}
	} else {
		while (1) {
			if (!((degrees < -180))) {
				break;
			}
			degrees += 360;
		}
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, degrees);
	zephir_call_method_p1_noret(this_ptr, "_rotate", _0);
	RETURN_THIS();

}

/**
 * Flip the image along the horizontal or vertical axis
 *
 * @param int direction
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, flip) {

	zval *direction_param = NULL, *_0;
	int direction;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

		direction = zephir_get_intval(direction_param);


	if (((direction != 11) && (direction != 12))) {
		direction = 11;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, direction);
	zephir_call_method_p1_noret(this_ptr, "_flip", _0);
	RETURN_THIS();

}

/**
 * Sharpen the image by a given amount
 *
 * @param int amount
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, sharpen) {

	zval *amount_param = NULL, *_0;
	int amount;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

		amount = zephir_get_intval(amount_param);


	if ((amount > 100)) {
		amount = 100;
	} else {
		if ((amount < 1)) {
			amount = 1;
		}
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, amount);
	zephir_call_method_p1_noret(this_ptr, "_sharpen", _0);
	RETURN_THIS();

}

/**
 * Add a reflection to an image
 *
 * @param int height
 * @param int opacity
 * @param boolean fade_in
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, reflection) {

	zend_bool fade_in;
	zval *height_param = NULL, *opacity_param = NULL, *fade_in_param = NULL, *_0, *_1, *_2, *_3;
	int height, opacity;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &height_param, &opacity_param, &fade_in_param);

		height = zephir_get_intval(height_param);
	if (!opacity_param) {
		opacity = 100;	} else {
		opacity = zephir_get_intval(opacity_param);
	}
	if (!fade_in_param) {
		fade_in = 0;
	} else {
		fade_in = zephir_get_boolval(fade_in_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	if (((height <= 0) || ZEPHIR_GT_LONG(_0, height))) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_this(&_1, this_ptr, SL("_height"), PH_NOISY_CC);
		height = zephir_get_intval(_1);
	}
	if ((opacity < 0)) {
		opacity = 0;
	} else {
		if ((opacity > 100)) {
			opacity = 100;
		}
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, height);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, opacity);
	zephir_call_method_p3_noret(this_ptr, "_reflection", _2, _3, (fade_in ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	RETURN_THIS();

}

/**
 * Add a watermark to an image with a specified opacity
 *
 * @param Phalcon\Image\Adapter watermark
 * @param int offset_x
 * @param int offset_y
 * @param int opacity
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, watermark) {

	int offset_x, offset_y, opacity, tmp;
	zval *watermark, *offset_x_param = NULL, *offset_y_param = NULL, *opacity_param = NULL, *_0, *_1, *_2, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &watermark, &offset_x_param, &offset_y_param, &opacity_param);

	if (!offset_x_param) {
		offset_x = 0;	} else {
		offset_x = zephir_get_intval(offset_x_param);
	}
	if (!offset_y_param) {
		offset_y = 0;	} else {
		offset_y = zephir_get_intval(offset_y_param);
	}
	if (!opacity_param) {
		opacity = 100;	} else {
		opacity = zephir_get_intval(opacity_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, watermark, "getwidth");
	ZEPHIR_INIT_VAR(_2);
	sub_function(_2, _0, _1 TSRMLS_CC);
	tmp = zephir_get_numberval(_2);
	if ((offset_x < 0)) {
		offset_x = 0;
	} else {
		if ((offset_x > tmp)) {
			offset_x = tmp;
		}
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_method(_1, watermark, "getheight");
	ZEPHIR_INIT_VAR(_3);
	sub_function(_3, _0, _1 TSRMLS_CC);
	tmp = zephir_get_numberval(_3);
	if ((offset_y < 0)) {
		offset_y = 0;
	} else {
		if ((offset_y > tmp)) {
			offset_y = tmp;
		}
	}
	if ((opacity < 0)) {
		opacity = 0;
	} else {
		if ((opacity > 100)) {
			opacity = 100;
		}
	}
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, offset_x);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, offset_y);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, opacity);
	zephir_call_method_p4_noret(this_ptr, "_watermark", watermark, _1, _4, _5);
	RETURN_THIS();

}

/**
 * Add a text to an image with a specified opacity
 *
 * @param string text
 * @param int offset_x
 * @param int offset_y
 * @param int opacity
 * @param string color
 * @param int size
 * @param string fontfile
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, text) {

	int offset_x, offset_y, opacity, size;
	zval *text_param = NULL, *offset_x_param = NULL, *offset_y_param = NULL, *opacity_param = NULL, *color_param = NULL, *size_param = NULL, *fontfile_param = NULL, *colors, _0 = zval_used_for_init, _1 = zval_used_for_init, *_2, *_3 = NULL, *_4, *_5, *_6, *_7, *_8, *_9, *_10;
	zval *text = NULL, *color = NULL, *fontfile = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &text_param, &offset_x_param, &offset_y_param, &opacity_param, &color_param, &size_param, &fontfile_param);

		zephir_get_strval(text, text_param);
	if (!offset_x_param) {
		offset_x = 0;	} else {
		offset_x = zephir_get_intval(offset_x_param);
	}
	if (!offset_y_param) {
		offset_y = 0;	} else {
		offset_y = zephir_get_intval(offset_y_param);
	}
	if (!opacity_param) {
		opacity = 100;	} else {
		opacity = zephir_get_intval(opacity_param);
	}
	if (!color_param) {
		ZEPHIR_INIT_VAR(color);
		ZVAL_STRING(color, "000000", 1);
	} else {
		zephir_get_strval(color, color_param);
	}
	if (!size_param) {
		size = 12;	} else {
		size = zephir_get_intval(size_param);
	}
	if (!fontfile_param) {
		ZEPHIR_INIT_VAR(fontfile);
		ZVAL_EMPTY_STRING(fontfile);
	} else {
		zephir_get_strval(fontfile, fontfile_param);
	}


	if ((opacity < 0)) {
		opacity = 0;
	} else {
		if ((opacity > 100)) {
			opacity = 100;
		}
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p3(_2, "substr", color, &_0, &_1);
	if (((zephir_fast_strlen_ev(color) > 1) && ZEPHIR_IS_STRING(_2, "#"))) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 1);
		ZEPHIR_INIT_VAR(_3);
		zephir_call_func_p2(_3, "substr", color, &_0);
		ZEPHIR_INIT_NVAR(color);
	}
	if ((zephir_fast_strlen_ev(color) == 3)) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "/./", 0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "$0$0", 0);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_func_p3(_3, "preg_replace", &_0, &_1, color);
		ZEPHIR_INIT_NVAR(color);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_func_p2(_3, "str_split", color, &_0);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "hexdec", 0);
	ZEPHIR_INIT_VAR(colors);
	zephir_call_func_p2(colors, "array_map", &_0, _3);
	zephir_array_fetch_long(&_4, colors, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_long(&_5, colors, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_long(&_6, colors, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, offset_x);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, offset_y);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, opacity);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_LONG(_10, size);
	zephir_call_method_p9_noret(this_ptr, "_text", text, _7, _8, _9, _4, _5, _6, _10, fontfile);
	RETURN_THIS();

}

/**
 * Composite one image onto another
 *
 * @param Phalcon\Image\Adapter watermark
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, mask) {

	zval *watermark;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &watermark);



	zephir_call_method_p1_noret(this_ptr, "_mask", watermark);
	RETURN_THIS();

}

/**
 * Set the background color of an image
 *
 * @param string color
 * @param int opacity
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, background) {

	int opacity;
	zval *color_param = NULL, *opacity_param = NULL, *colors, _0 = zval_used_for_init, _1 = zval_used_for_init, *_2, *_3 = NULL, *_4, *_5, *_6, *_7;
	zval *color = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &color_param, &opacity_param);

		zephir_get_strval(color, color_param);
	if (!opacity_param) {
		opacity = 100;	} else {
		opacity = zephir_get_intval(opacity_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p3(_2, "substr", color, &_0, &_1);
	if (((zephir_fast_strlen_ev(color) > 1) && ZEPHIR_IS_STRING(_2, "#"))) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 1);
		ZEPHIR_INIT_VAR(_3);
		zephir_call_func_p2(_3, "substr", color, &_0);
		ZEPHIR_INIT_NVAR(color);
	}
	if ((zephir_fast_strlen_ev(color) == 3)) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "/./", 0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "$0$0", 0);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_func_p3(_3, "preg_replace", &_0, &_1, color);
		ZEPHIR_INIT_NVAR(color);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_func_p2(_3, "str_split", color, &_0);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "hexdec", 0);
	ZEPHIR_INIT_VAR(colors);
	zephir_call_func_p2(colors, "array_map", &_0, _3);
	zephir_array_fetch_long(&_4, colors, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_long(&_5, colors, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_long(&_6, colors, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, opacity);
	zephir_call_method_p4_noret(this_ptr, "_background", _4, _5, _6, _7);
	RETURN_THIS();

}

/**
 * Blur image
 *
 * @param int radius
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, blur) {

	zval *radius_param = NULL, *_0;
	int radius;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);

		radius = zephir_get_intval(radius_param);


	if ((radius < 1)) {
		radius = 1;
	} else {
		if ((radius > 100)) {
			radius = 100;
		}
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, radius);
	zephir_call_method_p1_noret(this_ptr, "_blur", _0);
	RETURN_THIS();

}

/**
 * Pixelate image
 *
 * @param int amount
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, pixelate) {

	zval *amount_param = NULL, *_0;
	int amount;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

		amount = zephir_get_intval(amount_param);


	if ((amount < 2)) {
		amount = 2;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, amount);
	zephir_call_method_p1_noret(this_ptr, "_pixelate", _0);
	RETURN_THIS();

}

/**
 * Save the image
 *
 * @param string file
 * @param int quality
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, save) {

	int quality;
	zval *file_param = NULL, *quality_param = NULL, *_0, *_2;
	zval *file = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &file_param, &quality_param);

	if (!file_param) {
		ZEPHIR_INIT_VAR(file);
		ZVAL_EMPTY_STRING(file);
	} else {
		zephir_get_strval(file, file_param);
	}
	if (!quality_param) {
		quality = 100;	} else {
		quality = zephir_get_intval(quality_param);
	}


	if (!(file && Z_STRLEN_P(file))) {
		ZEPHIR_OBS_VAR(_0);
		zephir_read_property_this(&_0, this_ptr, SL("_realpath"), PH_NOISY_CC);
		zephir_get_strval(_1, _0);
		ZEPHIR_CPY_WRT(file, _1);
	}
	if ((quality < 1)) {
		quality = 1;
	} else {
		if ((quality > 100)) {
			quality = 100;
		}
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, quality);
	zephir_call_method_p2_noret(this_ptr, "_save", file, _2);
	RETURN_THIS();

}

/**
 * Render the image and return the binary string
 *
 * @param string ext
 * @param int quality
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, render) {

	int quality;
	zval *ext_param = NULL, *quality_param = NULL, *_0, _1, *_2 = NULL;
	zval *ext = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &ext_param, &quality_param);

	if (!ext_param) {
		ZEPHIR_INIT_VAR(ext);
		ZVAL_EMPTY_STRING(ext);
	} else {
		zephir_get_strval(ext, ext_param);
	}
	if (!quality_param) {
		quality = 100;	} else {
		quality = zephir_get_intval(quality_param);
	}


	if (!(ext && Z_STRLEN_P(ext))) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, 4);
		ZEPHIR_INIT_VAR(_2);
		zephir_call_func_p2(_2, "pathinfo", _0, &_1);
		zephir_get_strval(_3, _2);
		ZEPHIR_CPY_WRT(ext, _3);
	}
	if ((0 == 0)) {
		ZEPHIR_INIT_NVAR(ext);
		ZVAL_STRING(ext, "png", 1);
	}
	if ((quality < 1)) {
		quality = 1;
	} else {
		if ((quality > 100)) {
			quality = 100;
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, quality);
	zephir_call_method_p2_noret(this_ptr, "_render", ext, _2);
	RETURN_THIS();

}

