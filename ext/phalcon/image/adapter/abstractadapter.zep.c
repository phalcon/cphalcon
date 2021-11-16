
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/math.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Image\Adapter
 *
 * All image adapters must use this class
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_AbstractAdapter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Image\\Adapter, AbstractAdapter, phalcon, image_adapter_abstractadapter, phalcon_image_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_image_adapter_abstractadapter_ce, SL("checked"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_image_adapter_abstractadapter_ce, SL("file"), ZEND_ACC_PROTECTED);
	/**
	 * Image height
	 *
	 * @var int
	 */
	zend_declare_property_null(phalcon_image_adapter_abstractadapter_ce, SL("height"), ZEND_ACC_PROTECTED);
	/**
	 * @var object|null
	 */
	zend_declare_property_null(phalcon_image_adapter_abstractadapter_ce, SL("image"), ZEND_ACC_PROTECTED);
	/**
	 * Image mime type
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_image_adapter_abstractadapter_ce, SL("mime"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_image_adapter_abstractadapter_ce, SL("realpath"), ZEND_ACC_PROTECTED);
	/**
	 * Image type
	 *
	 * Driver dependent
	 *
	 * @var int
	 */
	zend_declare_property_null(phalcon_image_adapter_abstractadapter_ce, SL("type"), ZEND_ACC_PROTECTED);
	/**
	 * Image width
	 *
	 * @var int
	 */
	zend_declare_property_null(phalcon_image_adapter_abstractadapter_ce, SL("width"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_image_adapter_abstractadapter_ce, 1, phalcon_image_adapter_adapterinterface_ce);
	return SUCCESS;
}

/**
 * Image height
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getHeight)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "height");
}

/**
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getImage)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "image");
}

/**
 * Image mime type
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getMime)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "mime");
}

/**
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getRealpath)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "realpath");
}

/**
 * Image type
 *
 *
 * Driver dependent
 *
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getType)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "type");
}

/**
 * Image width
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getWidth)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "width");
}

/**
 * Set the background color of an image
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, background)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *color_param = NULL, *opacity_param = NULL, colors, _1, _2, _3, _9, _10, _11, _12, _13, _14, _4$$3, _5$$3, _6$$4, _7$$4, _8$$4;
	zval color;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&colors);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(color)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(opacity)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &color_param, &opacity_param);
	zephir_get_strval(&color, color_param);
	if (!opacity_param) {
		opacity = 100;
	} else {
		opacity = zephir_get_intval(opacity_param);
	}


	_0 = zephir_fast_strlen_ev(&color) > 1;
	if (_0) {
		ZVAL_LONG(&_1, 0);
		ZVAL_LONG(&_2, 1);
		ZEPHIR_INIT_VAR(&_3);
		zephir_substr(&_3, &color, 0 , 1 , 0);
		_0 = ZEPHIR_IS_STRING_IDENTICAL(&_3, "#");
	}
	if (_0) {
		ZVAL_LONG(&_4$$3, 1);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_substr(&_5$$3, &color, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_get_strval(&color, &_5$$3);
	}
	if (zephir_fast_strlen_ev(&color) == 3) {
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "/./");
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "$0$0");
		ZEPHIR_CALL_FUNCTION(&_8$$4, "preg_replace", NULL, 49, &_6$$4, &_7$$4, &color);
		zephir_check_call_status();
		zephir_get_strval(&color, &_8$$4);
	}
	ZVAL_LONG(&_9, 2);
	ZEPHIR_CALL_FUNCTION(&_10, "str_split", NULL, 114, &color, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "hexdec");
	ZEPHIR_CALL_FUNCTION(&colors, "array_map", NULL, 107, &_11, &_10);
	zephir_check_call_status();
	zephir_array_fetch_long(&_12, &colors, 0, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 93);
	zephir_array_fetch_long(&_13, &colors, 1, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 93);
	zephir_array_fetch_long(&_14, &colors, 2, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 93);
	ZVAL_LONG(&_9, opacity);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processbackground", NULL, 0, &_12, &_13, &_14, &_9);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Blur image
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, blur)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *radius_param = NULL, _0;
	zend_long radius, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(radius)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);
	radius = zephir_get_intval(radius_param);


	if (radius < 1) {
		radius = 1;
	} else if (radius > 100) {
		radius = 100;
	}
	ZVAL_LONG(&_0, radius);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processblur", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Crop an image to the given size
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, crop)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, _0, _5, _10, _12, _14, _15, _16, _17, _1$$3, _2$$5, _3$$4, _4$$6, _6$$7, _7$$9, _8$$8, _9$$10, _11$$11, _13$$12;
	zend_long width, height, offsetX, offsetY, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_13$$12);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(offsetX, is_null_true)
		Z_PARAM_LONG_OR_NULL(offsetY, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &width_param, &height_param, &offsetX_param, &offsetY_param);
	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	if (!offsetX_param) {
		offsetX = 0;
	} else {
		offsetX = zephir_get_intval(offsetX_param);
	}
	if (!offsetY_param) {
		offsetY = 0;
	} else {
		offsetY = zephir_get_intval(offsetY_param);
	}


	ZVAL_LONG(&_0, offsetX);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		offsetX = (long) ((zephir_safe_div_long_long(((zephir_get_numberval(&_1$$3) - width)), 2)));
	} else {
		if (offsetX < 0) {
			zephir_read_property(&_2$$5, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			offsetX = ((zephir_get_numberval(&_2$$5) - width) + offsetX);
		}
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_LT_LONG(&_3$$4, offsetX)) {
			ZEPHIR_OBS_VAR(&_4$$6);
			zephir_read_property(&_4$$6, this_ptr, ZEND_STRL("width"), PH_NOISY_CC);
			offsetX = zephir_get_intval(&_4$$6);
		}
	}
	ZVAL_LONG(&_5, offsetY);
	if (Z_TYPE_P(&_5) == IS_NULL) {
		zephir_read_property(&_6$$7, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		offsetY = (long) ((zephir_safe_div_long_long(((zephir_get_numberval(&_6$$7) - height)), 2)));
	} else {
		if (offsetY < 0) {
			zephir_read_property(&_7$$9, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			offsetY = ((zephir_get_numberval(&_7$$9) - height) + offsetY);
		}
		zephir_read_property(&_8$$8, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_LT_LONG(&_8$$8, offsetY)) {
			ZEPHIR_OBS_VAR(&_9$$10);
			zephir_read_property(&_9$$10, this_ptr, ZEND_STRL("height"), PH_NOISY_CC);
			offsetY = zephir_get_intval(&_9$$10);
		}
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	if (width > ((zephir_get_numberval(&_10) - offsetX))) {
		zephir_read_property(&_11$$11, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		width = (zephir_get_numberval(&_11$$11) - offsetX);
	}
	zephir_read_property(&_12, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	if (height > ((zephir_get_numberval(&_12) - offsetY))) {
		zephir_read_property(&_13$$12, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		height = (zephir_get_numberval(&_13$$12) - offsetY);
	}
	ZVAL_LONG(&_14, width);
	ZVAL_LONG(&_15, height);
	ZVAL_LONG(&_16, offsetX);
	ZVAL_LONG(&_17, offsetY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcrop", NULL, 0, &_14, &_15, &_16, &_17);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Flip the image along the horizontal or vertical axis
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, flip)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *direction_param = NULL, _1;
	zend_long direction, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(direction)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);
	direction = zephir_get_intval(direction_param);


	_0 = direction != 11;
	if (_0) {
		_0 = direction != 12;
	}
	if (_0) {
		direction = 11;
	}
	ZVAL_LONG(&_1, direction);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processflip", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * This method scales the images using liquid rescaling method. Only support
 * Imagick
 *
 * @param int $width   new width
 * @param int $height  new height
 * @param int $deltaX How much the seam can traverse on x-axis. Passing 0 causes the seams to be straight.
 * @param int $rigidity Introduces a bias for non-straight seams. This parameter is typically 0.
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, liquidRescale)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *deltaX_param = NULL, *rigidity_param = NULL, _0, _1, _2, _3;
	zend_long width, height, deltaX, rigidity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(deltaX)
		Z_PARAM_LONG(rigidity)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &width_param, &height_param, &deltaX_param, &rigidity_param);
	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	if (!deltaX_param) {
		deltaX = 0;
	} else {
		deltaX = zephir_get_intval(deltaX_param);
	}
	if (!rigidity_param) {
		rigidity = 0;
	} else {
		rigidity = zephir_get_intval(rigidity_param);
	}


	ZVAL_LONG(&_0, width);
	ZVAL_LONG(&_1, height);
	ZVAL_LONG(&_2, deltaX);
	ZVAL_LONG(&_3, rigidity);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processliquidrescale", NULL, 0, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Composite one image onto another
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, mask)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *watermark, watermark_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&watermark_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(watermark, phalcon_image_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &watermark);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processmask", NULL, 0, watermark);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Pixelate image
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, pixelate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *amount_param = NULL, _0;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(amount)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);
	amount = zephir_get_intval(amount_param);


	if (amount < 2) {
		amount = 2;
	}
	ZVAL_LONG(&_0, amount);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processpixelate", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Add a reflection to an image
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, reflection)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool fadeIn, _0;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, _1, _3, _4, _5, _2$$3;
	zend_long height, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_LONG(height)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(opacity)
		Z_PARAM_BOOL(fadeIn)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &height_param, &opacity_param, &fadeIn_param);
	height = zephir_get_intval(height_param);
	if (!opacity_param) {
		opacity = 100;
	} else {
		opacity = zephir_get_intval(opacity_param);
	}
	if (!fadeIn_param) {
		fadeIn = 0;
	} else {
		fadeIn = zephir_get_boolval(fadeIn_param);
	}


	_0 = height <= 0;
	if (!(_0)) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		_0 = ZEPHIR_LT_LONG(&_1, height);
	}
	if (_0) {
		ZEPHIR_OBS_VAR(&_2$$3);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("height"), PH_NOISY_CC);
		height = zephir_get_intval(&_2$$3);
	}
	if (opacity < 0) {
		opacity = 0;
	} else if (opacity > 100) {
		opacity = 100;
	}
	ZVAL_LONG(&_3, height);
	ZVAL_LONG(&_4, opacity);
	if (fadeIn) {
		ZVAL_BOOL(&_5, 1);
	} else {
		ZVAL_BOOL(&_5, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processreflection", NULL, 0, &_3, &_4, &_5);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Render the image and return the binary string
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, render)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *ext_param = NULL, *quality_param = NULL, _0$$3, _1$$3, _2$$3, _4;
	zval ext, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(ext)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &ext_param, &quality_param);
	if (!ext_param) {
		ZEPHIR_INIT_VAR(&ext);
	} else {
		zephir_get_strval(&ext, ext_param);
	}
	if (!quality_param) {
		quality = 100;
	} else {
		quality = zephir_get_intval(quality_param);
	}


	if (ZEPHIR_IS_EMPTY(&ext)) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_1$$3, 4);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "pathinfo", NULL, 115, &_0$$3, &_1$$3);
		zephir_check_call_status();
		zephir_cast_to_string(&_3$$3, &_2$$3);
		ZEPHIR_CPY_WRT(&ext, &_3$$3);
	}
	if (ZEPHIR_IS_EMPTY(&ext)) {
		ZEPHIR_INIT_NVAR(&ext);
		ZVAL_STRING(&ext, "png");
	}
	if (quality < 1) {
		quality = 1;
	} else if (quality > 100) {
		quality = 100;
	}
	ZVAL_LONG(&_4, quality);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processrender", NULL, 0, &ext, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resize the image to the given size
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, resize)
{
	zend_bool _0$$3, _1$$6, _5$$8, _13$$14;
	double ratio = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *master_param = NULL, _23, _24, _25, _26, _27, _28, _29, _30, _2$$6, _3$$6, _4$$6, _6$$8, _7$$8, _8$$8, _9$$10, _10$$10, _11$$12, _12$$12, _14$$14, _15$$14, _16$$14, _17$$16, _18$$16, _19$$17, _20$$17, _21$$19, _22$$20;
	zend_long width, height, master, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_22$$20);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(width, is_null_true)
		Z_PARAM_LONG_OR_NULL(height, is_null_true)
		Z_PARAM_LONG(master)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
		master = 4;
	} else {
		master = zephir_get_intval(master_param);
	}


	if (master == 7) {
		_0$$3 = !width;
		if (!(_0$$3)) {
			_0$$3 = !height;
		}
		if (UNEXPECTED(_0$$3)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width and height must be specified", "phalcon/Image/Adapter/AbstractAdapter.zep", 277);
			return;
		}
	} else {
		if (master == 4) {
			_1$$6 = !width;
			if (!(_1$$6)) {
				_1$$6 = !height;
			}
			if (UNEXPECTED(_1$$6)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width and height must be specified", "phalcon/Image/Adapter/AbstractAdapter.zep", 284);
				return;
			}
			ZEPHIR_INIT_VAR(&_2$$6);
			zephir_read_property(&_3$$6, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_4$$6, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			if ((zephir_safe_div_zval_long(&_3$$6, width)) > (int) (zephir_safe_div_zval_long(&_4$$6, height))) {
				ZEPHIR_INIT_NVAR(&_2$$6);
				ZVAL_LONG(&_2$$6, 2);
			} else {
				ZEPHIR_INIT_NVAR(&_2$$6);
				ZVAL_LONG(&_2$$6, 3);
			}
			master = zephir_get_numberval(&_2$$6);
		}
		if (master == 5) {
			_5$$8 = !width;
			if (!(_5$$8)) {
				_5$$8 = !height;
			}
			if (UNEXPECTED(_5$$8)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width and height must be specified", "phalcon/Image/Adapter/AbstractAdapter.zep", 293);
				return;
			}
			ZEPHIR_INIT_VAR(&_6$$8);
			zephir_read_property(&_7$$8, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_8$$8, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			if ((zephir_safe_div_zval_long(&_7$$8, width)) > (int) (zephir_safe_div_zval_long(&_8$$8, height))) {
				ZEPHIR_INIT_NVAR(&_6$$8);
				ZVAL_LONG(&_6$$8, 3);
			} else {
				ZEPHIR_INIT_NVAR(&_6$$8);
				ZVAL_LONG(&_6$$8, 2);
			}
			master = zephir_get_numberval(&_6$$8);
		}
		do {
			if (master == 2) {
				if (UNEXPECTED(!width)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width must be specified", "phalcon/Image/Adapter/AbstractAdapter.zep", 303);
					return;
				}
				zephir_read_property(&_9$$10, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_10$$10, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
				height = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_9$$10) * width), &_10$$10));
				break;
			}
			if (master == 3) {
				if (UNEXPECTED(!height)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "height must be specified", "phalcon/Image/Adapter/AbstractAdapter.zep", 312);
					return;
				}
				zephir_read_property(&_11$$12, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_12$$12, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
				width = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_11$$12) * height), &_12$$12));
				break;
			}
			if (master == 6) {
				_13$$14 = !width;
				if (!(_13$$14)) {
					_13$$14 = !height;
				}
				if (UNEXPECTED(_13$$14)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width and height must be specified", "phalcon/Image/Adapter/AbstractAdapter.zep", 323);
					return;
				}
				zephir_read_property(&_14$$14, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_15$$14, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_16$$14);
				div_function(&_16$$14, &_14$$14, &_15$$14);
				ratio = zephir_get_numberval(&_16$$14);
				if ((zephir_safe_div_long_long(width, height)) > ratio) {
					zephir_read_property(&_17$$16, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_18$$16, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
					height = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_17$$16) * width), &_18$$16));
				} else {
					zephir_read_property(&_19$$17, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_20$$17, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
					width = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_19$$17) * height), &_20$$17));
				}
				break;
			}
			if (master == 1) {
				if (!(width)) {
					ZEPHIR_OBS_VAR(&_21$$19);
					zephir_read_property(&_21$$19, this_ptr, ZEND_STRL("width"), PH_NOISY_CC);
					width = zephir_get_intval(&_21$$19);
				}
				if (!(height)) {
					ZEPHIR_OBS_VAR(&_22$$20);
					zephir_read_property(&_22$$20, this_ptr, ZEND_STRL("height"), PH_NOISY_CC);
					width = zephir_get_intval(&_22$$20);
				}
				break;
			}
		} while(0);

	}
	ZEPHIR_INIT_VAR(&_23);
	ZVAL_LONG(&_24, width);
	zephir_round(&_23, &_24, NULL, NULL);
	ZVAL_LONG(&_25, 1);
	ZEPHIR_CALL_FUNCTION(&_26, "max", NULL, 116, &_23, &_25);
	zephir_check_call_status();
	width = zephir_get_intval(&_26);
	ZEPHIR_INIT_VAR(&_27);
	ZVAL_LONG(&_25, height);
	zephir_round(&_27, &_25, NULL, NULL);
	ZVAL_LONG(&_28, 1);
	ZEPHIR_CALL_FUNCTION(&_29, "max", NULL, 116, &_27, &_28);
	zephir_check_call_status();
	height = zephir_get_intval(&_29);
	ZVAL_LONG(&_28, width);
	ZVAL_LONG(&_30, height);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processresize", NULL, 0, &_28, &_30);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Rotate the image by a given amount
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, rotate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *degrees_param = NULL, _0;
	zend_long degrees, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(degrees)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);
	degrees = zephir_get_intval(degrees_param);


	if (degrees > 180) {
		degrees %= 360;
		if (degrees > 180) {
			degrees -= 360;
		}
	} else {
		while (1) {
			if (!(degrees < -180)) {
				break;
			}
			degrees += 360;
		}
	}
	ZVAL_LONG(&_0, degrees);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processrotate", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Save the image
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, save)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality_param = NULL, _0$$3, _2;
	zval file, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(file)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &file_param, &quality_param);
	if (!file_param) {
		ZEPHIR_INIT_VAR(&file);
	} else {
		zephir_get_strval(&file, file_param);
	}
	if (!quality_param) {
		quality = -1;
	} else {
		quality = zephir_get_intval(quality_param);
	}


	if (!(!(ZEPHIR_IS_EMPTY(&file)))) {
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("realpath"), PH_NOISY_CC);
		zephir_cast_to_string(&_1$$3, &_0$$3);
		ZEPHIR_CPY_WRT(&file, &_1$$3);
	}
	ZVAL_LONG(&_2, quality);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processsave", NULL, 0, &file, &_2);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Sharpen the image by a given amount
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, sharpen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *amount_param = NULL, _0;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(amount)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);
	amount = zephir_get_intval(amount_param);


	if (amount > 100) {
		amount = 100;
	} else if (amount < 1) {
		amount = 1;
	}
	ZVAL_LONG(&_0, amount);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processsharpen", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Add a text to an image with a specified opacity
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, text)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long opacity, size, ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *offsetX = NULL, offsetX_sub, *offsetY = NULL, offsetY_sub, *opacity_param = NULL, *color_param = NULL, *size_param = NULL, *fontfile_param = NULL, __$false, colors, _1, _2, _3, _9, _10, _11, _12, _13, _14, _15, _4$$6, _5$$6, _6$$7, _7$$7, _8$$7;
	zval text, color, fontfile;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&fontfile);
	ZVAL_UNDEF(&offsetX_sub);
	ZVAL_UNDEF(&offsetY_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&colors);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 7)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(offsetX)
		Z_PARAM_ZVAL(offsetY)
		Z_PARAM_LONG(opacity)
		Z_PARAM_STR(color)
		Z_PARAM_LONG(size)
		Z_PARAM_STR_OR_NULL(fontfile)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &text_param, &offsetX, &offsetY, &opacity_param, &color_param, &size_param, &fontfile_param);
	zephir_get_strval(&text, text_param);
	if (!offsetX) {
		offsetX = &offsetX_sub;
		offsetX = &__$false;
	}
	if (!offsetY) {
		offsetY = &offsetY_sub;
		offsetY = &__$false;
	}
	if (!opacity_param) {
		opacity = 100;
	} else {
		opacity = zephir_get_intval(opacity_param);
	}
	if (!color_param) {
		ZEPHIR_INIT_VAR(&color);
		ZVAL_STRING(&color, "000000");
	} else {
		zephir_get_strval(&color, color_param);
	}
	if (!size_param) {
		size = 12;
	} else {
		size = zephir_get_intval(size_param);
	}
	if (!fontfile_param) {
		ZEPHIR_INIT_VAR(&fontfile);
	} else {
		zephir_get_strval(&fontfile, fontfile_param);
	}


	if (opacity < 0) {
		opacity = 0;
	} else {
		if (opacity > 100) {
			opacity = 100;
		}
	}
	_0 = zephir_fast_strlen_ev(&color) > 1;
	if (_0) {
		ZVAL_LONG(&_1, 0);
		ZVAL_LONG(&_2, 1);
		ZEPHIR_INIT_VAR(&_3);
		zephir_substr(&_3, &color, 0 , 1 , 0);
		_0 = ZEPHIR_IS_STRING_IDENTICAL(&_3, "#");
	}
	if (_0) {
		ZVAL_LONG(&_4$$6, 1);
		ZEPHIR_INIT_VAR(&_5$$6);
		zephir_substr(&_5$$6, &color, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_get_strval(&color, &_5$$6);
	}
	if (zephir_fast_strlen_ev(&color) == 3) {
		ZEPHIR_INIT_VAR(&_6$$7);
		ZVAL_STRING(&_6$$7, "/./");
		ZEPHIR_INIT_VAR(&_7$$7);
		ZVAL_STRING(&_7$$7, "$0$0");
		ZEPHIR_CALL_FUNCTION(&_8$$7, "preg_replace", NULL, 49, &_6$$7, &_7$$7, &color);
		zephir_check_call_status();
		zephir_get_strval(&color, &_8$$7);
	}
	ZVAL_LONG(&_9, 2);
	ZEPHIR_CALL_FUNCTION(&_10, "str_split", NULL, 114, &color, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "hexdec");
	ZEPHIR_CALL_FUNCTION(&colors, "array_map", NULL, 107, &_11, &_10);
	zephir_check_call_status();
	zephir_array_fetch_long(&_12, &colors, 0, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 449);
	zephir_array_fetch_long(&_13, &colors, 1, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 450);
	zephir_array_fetch_long(&_14, &colors, 2, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 451);
	ZVAL_LONG(&_9, opacity);
	ZVAL_LONG(&_15, size);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processtext", NULL, 0, &text, offsetX, offsetY, &_9, &_12, &_13, &_14, &_15, &fontfile);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Add a watermark to an image with the specified opacity
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, watermark)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offsetX, offsetY, opacity, ZEPHIR_LAST_CALL_STATUS, tmp = 0;
	zval *watermark, watermark_sub, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&watermark_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_OBJECT_OF_CLASS(watermark, phalcon_image_adapter_adapterinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(offsetX)
		Z_PARAM_LONG(offsetY)
		Z_PARAM_LONG(opacity)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &watermark, &offsetX_param, &offsetY_param, &opacity_param);
	if (!offsetX_param) {
		offsetX = 0;
	} else {
		offsetX = zephir_get_intval(offsetX_param);
	}
	if (!offsetY_param) {
		offsetY = 0;
	} else {
		offsetY = zephir_get_intval(offsetY_param);
	}
	if (!opacity_param) {
		opacity = 100;
	} else {
		opacity = zephir_get_intval(opacity_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, watermark, "getwidth", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_sub_function(&_2, &_0, &_1);
	tmp = zephir_get_numberval(&_2);
	if (offsetX < 0) {
		offsetX = 0;
	} else if (offsetX > tmp) {
		offsetX = tmp;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, watermark, "getheight", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_sub_function(&_3, &_0, &_1);
	tmp = zephir_get_numberval(&_3);
	if (offsetY < 0) {
		offsetY = 0;
	} else if (offsetY > tmp) {
		offsetY = tmp;
	}
	if (opacity < 0) {
		opacity = 0;
	} else if (opacity > 100) {
		opacity = 100;
	}
	ZVAL_LONG(&_0, offsetX);
	ZVAL_LONG(&_4, offsetY);
	ZVAL_LONG(&_5, opacity);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processwatermark", NULL, 0, watermark, &_0, &_4, &_5);
	zephir_check_call_status();
	RETURN_THIS();
}

