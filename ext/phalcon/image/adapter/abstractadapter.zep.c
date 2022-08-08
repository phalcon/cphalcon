
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
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
 * All image adapters must use this class
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_AbstractAdapter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Image\\Adapter, AbstractAdapter, phalcon, image_adapter_abstractadapter, phalcon_image_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

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
	 * @var mixed|null
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
 * Set the background color of an image
 *
 * @param string $color
 * @param int    $opacity
 *
 * @return AdapterInterface
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
		ZEPHIR_CALL_FUNCTION(&_8$$4, "preg_replace", NULL, 37, &_6$$4, &_7$$4, &color);
		zephir_check_call_status();
		zephir_get_strval(&color, &_8$$4);
	}
	ZVAL_LONG(&_9, 2);
	ZEPHIR_CALL_FUNCTION(&_10, "str_split", NULL, 84, &color, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "hexdec");
	ZEPHIR_CALL_FUNCTION(&colors, "array_map", NULL, 66, &_11, &_10);
	zephir_check_call_status();
	zephir_array_fetch_long(&_12, &colors, 0, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 96);
	zephir_array_fetch_long(&_13, &colors, 1, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 96);
	zephir_array_fetch_long(&_14, &colors, 2, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 96);
	ZVAL_LONG(&_9, opacity);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processbackground", NULL, 0, &_12, &_13, &_14, &_9);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Blur image
 *
 * @param int $radius
 *
 * @return AdapterInterface
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, blur)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *radius_param = NULL, _0, _1, _2;
	zend_long radius, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(radius)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);
	radius = zephir_get_intval(radius_param);


	ZVAL_LONG(&_1, radius);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkhighlow", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	radius = zephir_get_numberval(&_0);
	ZVAL_LONG(&_1, radius);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processblur", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Crop an image to the given size
 *
 * @param int      $width
 * @param int      $height
 * @param int|null $offsetX
 * @param int|null $offsetY
 *
 * @return AdapterInterface
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, crop)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, _0$$3, _1$$4, _2$$4, _3$$4, _4$$4, _5$$5, _6$$6, _7$$6, _8$$6, _9$$6, _10, _12, _14, _15, _16, _17, _11$$7, _13$$8;
	zend_long width, height, offsetX, offsetY, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$8);
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


	if (0 == offsetX) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		offsetX = (long) ((zephir_safe_div_long_long(((zephir_get_numberval(&_0$$3) - width)), 2)));
	} else {
		ZEPHIR_INIT_VAR(&_1$$4);
		if (offsetX < 0) {
			zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_1$$4);
			ZVAL_LONG(&_1$$4, ((zephir_get_numberval(&_2$$4) - width) + offsetX));
		} else {
			ZEPHIR_INIT_NVAR(&_1$$4);
			ZVAL_LONG(&_1$$4, offsetX);
		}
		offsetX = zephir_get_numberval(&_1$$4);
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_LT_LONG(&_4$$4, offsetX)) {
			ZEPHIR_OBS_NVAR(&_3$$4);
			zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("width"), PH_NOISY_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_3$$4);
			ZVAL_LONG(&_3$$4, offsetX);
		}
		offsetX = zephir_get_numberval(&_3$$4);
	}
	if (0 == offsetY) {
		zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		offsetY = (long) ((zephir_safe_div_long_long(((zephir_get_numberval(&_5$$5) - height)), 2)));
	} else {
		ZEPHIR_INIT_VAR(&_6$$6);
		if (offsetY < 0) {
			zephir_read_property(&_7$$6, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_6$$6);
			ZVAL_LONG(&_6$$6, ((zephir_get_numberval(&_7$$6) - height) + offsetY));
		} else {
			ZEPHIR_INIT_NVAR(&_6$$6);
			ZVAL_LONG(&_6$$6, offsetY);
		}
		offsetY = zephir_get_numberval(&_6$$6);
		ZEPHIR_INIT_VAR(&_8$$6);
		zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_LT_LONG(&_9$$6, offsetY)) {
			ZEPHIR_OBS_NVAR(&_8$$6);
			zephir_read_property(&_8$$6, this_ptr, ZEND_STRL("height"), PH_NOISY_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_8$$6);
			ZVAL_LONG(&_8$$6, offsetY);
		}
		offsetY = zephir_get_numberval(&_8$$6);
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	if (width > ((zephir_get_numberval(&_10) - offsetX))) {
		zephir_read_property(&_11$$7, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		width = (zephir_get_numberval(&_11$$7) - offsetX);
	}
	zephir_read_property(&_12, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	if (height > ((zephir_get_numberval(&_12) - offsetY))) {
		zephir_read_property(&_13$$8, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		height = (zephir_get_numberval(&_13$$8) - offsetY);
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
 *
 * @param int $direction
 *
 * @return AdapterInterface
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
 * @return int
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getHeight)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "height");
}

/**
 * @return object|null
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getImage)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "image");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getMime)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "mime");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getRealpath)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "realpath");
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getType)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "type");
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getWidth)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "width");
}

/**
 * Composite one image onto another
 *
 * @param AdapterInterface $mask
 *
 * @return AdapterInterface
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, mask)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mask, mask_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mask_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(mask, phalcon_image_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mask);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processmask", NULL, 0, mask);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Pixelate image
 *
 * @param int $amount
 *
 * @return AdapterInterface
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
 *
 * @param int  $height
 * @param int  $opacity
 * @param bool $fadeIn
 *
 * @return AdapterInterface
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, reflection)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool fadeIn, _0;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, _1, _3, _4, _5, _6, _2$$3;
	zend_long height, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
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
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		height = zephir_get_numberval(&_2$$3);
	}
	ZVAL_LONG(&_4, opacity);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "checkhighlow", NULL, 0, &_4);
	zephir_check_call_status();
	opacity = zephir_get_numberval(&_3);
	ZVAL_LONG(&_4, height);
	ZVAL_LONG(&_5, opacity);
	if (fadeIn) {
		ZVAL_BOOL(&_6, 1);
	} else {
		ZVAL_BOOL(&_6, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processreflection", NULL, 0, &_4, &_5, &_6);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Render the image and return the binary string
 *
 * @param string|null $extension
 * @param int         $quality
 *
 * @return string
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, render)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *extension_param = NULL, *quality_param = NULL, _0$$3, _1$$3, _2$$3, _4, _5, _6;
	zval extension, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(extension)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &extension_param, &quality_param);
	if (!extension_param) {
		ZEPHIR_INIT_VAR(&extension);
	} else {
		zephir_get_strval(&extension, extension_param);
	}
	if (!quality_param) {
		quality = 100;
	} else {
		quality = zephir_get_intval(quality_param);
	}


	if (Z_TYPE_P(&extension) == IS_NULL) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_1$$3, 4);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "pathinfo", NULL, 85, &_0$$3, &_1$$3);
		zephir_check_call_status();
		zephir_cast_to_string(&_3$$3, &_2$$3);
		ZEPHIR_CPY_WRT(&extension, &_3$$3);
	}
	if (1 == ZEPHIR_IS_EMPTY(&extension)) {
		ZEPHIR_INIT_NVAR(&extension);
		ZVAL_STRING(&extension, "png");
	}
	ZVAL_LONG(&_5, quality);
	ZVAL_LONG(&_6, 1);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "checkhighlow", NULL, 0, &_5, &_6);
	zephir_check_call_status();
	quality = zephir_get_numberval(&_4);
	ZVAL_LONG(&_5, quality);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processrender", NULL, 0, &extension, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resize the image to the given size
 *
 * @param int|null $width
 * @param int|null $height
 * @param int      $master
 *
 * @return AdapterInterface
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, resize)
{
	zend_bool _0$$3;
	double ratio = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *master_param = NULL, _20, _21, _22, _23, _24, _25, _26, _27, _1$$10, _2$$10, _3$$10, _4$$11, _5$$11, _6$$11, _7$$12, _8$$12, _9$$13, _10$$13, _11$$14, _12$$14, _13$$14, _14$$15, _15$$15, _16$$16, _17$$16, _18$$17, _19$$17;
	zend_long width, height, master, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_1$$10);
	ZVAL_UNDEF(&_2$$10);
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$17);
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


	do {
		if (master == 7 || master == 4 || master == 5 || master == 6) {
			_0$$3 = 0 == width;
			if (!(_0$$3)) {
				_0$$3 = 0 == height;
			}
			if (_0$$3) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width and height must be specified", "phalcon/Image/Adapter/AbstractAdapter.zep", 329);
				return;
			}
			break;
		}
		if (master == 2) {
			if (0 == width) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width must be specified", "phalcon/Image/Adapter/AbstractAdapter.zep", 334);
				return;
			}
			break;
		}
		if (master == 3) {
			if (0 == height) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "height must be specified", "phalcon/Image/Adapter/AbstractAdapter.zep", 339);
				return;
			}
			break;
		}
	} while(0);

	if (master != 7) {
		if (master == 4) {
			ZEPHIR_INIT_VAR(&_1$$10);
			zephir_read_property(&_2$$10, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_3$$10, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			if ((zephir_safe_div_zval_long(&_2$$10, width)) > (int) (zephir_safe_div_zval_long(&_3$$10, height))) {
				ZEPHIR_INIT_NVAR(&_1$$10);
				ZVAL_LONG(&_1$$10, 2);
			} else {
				ZEPHIR_INIT_NVAR(&_1$$10);
				ZVAL_LONG(&_1$$10, 3);
			}
			master = zephir_get_numberval(&_1$$10);
		}
		if (master == 5) {
			ZEPHIR_INIT_VAR(&_4$$11);
			zephir_read_property(&_5$$11, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_6$$11, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			if ((zephir_safe_div_zval_long(&_5$$11, width)) > (int) (zephir_safe_div_zval_long(&_6$$11, height))) {
				ZEPHIR_INIT_NVAR(&_4$$11);
				ZVAL_LONG(&_4$$11, 3);
			} else {
				ZEPHIR_INIT_NVAR(&_4$$11);
				ZVAL_LONG(&_4$$11, 2);
			}
			master = zephir_get_numberval(&_4$$11);
		}
		do {
			if (master == 2) {
				zephir_read_property(&_7$$12, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_8$$12, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
				height = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_7$$12) * width), &_8$$12));
				break;
			}
			if (master == 3) {
				zephir_read_property(&_9$$13, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_10$$13, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
				width = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_9$$13) * height), &_10$$13));
				break;
			}
			if (master == 6) {
				zephir_read_property(&_11$$14, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_12$$14, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_13$$14);
				div_function(&_13$$14, &_11$$14, &_12$$14);
				ratio = zephir_get_numberval(&_13$$14);
				if ((zephir_safe_div_long_long(width, height)) > ratio) {
					zephir_read_property(&_14$$15, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_15$$15, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
					height = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_14$$15) * width), &_15$$15));
				} else {
					zephir_read_property(&_16$$16, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_17$$16, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
					width = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_16$$16) * height), &_17$$16));
				}
				break;
			}
			if (master == 1) {
				ZEPHIR_INIT_VAR(&_18$$17);
				if (0 == width) {
					ZEPHIR_OBS_NVAR(&_18$$17);
					zephir_read_property(&_18$$17, this_ptr, ZEND_STRL("width"), PH_NOISY_CC);
				} else {
					ZEPHIR_INIT_NVAR(&_18$$17);
					ZVAL_LONG(&_18$$17, width);
				}
				width = zephir_get_numberval(&_18$$17);
				ZEPHIR_INIT_VAR(&_19$$17);
				if (0 == height) {
					ZEPHIR_OBS_NVAR(&_19$$17);
					zephir_read_property(&_19$$17, this_ptr, ZEND_STRL("height"), PH_NOISY_CC);
				} else {
					ZEPHIR_INIT_NVAR(&_19$$17);
					ZVAL_LONG(&_19$$17, height);
				}
				height = zephir_get_numberval(&_19$$17);
				break;
			}
		} while(0);

	}
	ZEPHIR_INIT_VAR(&_20);
	ZVAL_LONG(&_21, width);
	zephir_round(&_20, &_21, NULL, NULL);
	ZVAL_LONG(&_22, 1);
	ZEPHIR_CALL_FUNCTION(&_23, "max", NULL, 86, &_20, &_22);
	zephir_check_call_status();
	width = zephir_get_intval(&_23);
	ZEPHIR_INIT_VAR(&_24);
	ZVAL_LONG(&_22, height);
	zephir_round(&_24, &_22, NULL, NULL);
	ZVAL_LONG(&_25, 1);
	ZEPHIR_CALL_FUNCTION(&_26, "max", NULL, 86, &_24, &_25);
	zephir_check_call_status();
	height = zephir_get_intval(&_26);
	ZVAL_LONG(&_25, width);
	ZVAL_LONG(&_27, height);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processresize", NULL, 0, &_25, &_27);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Rotate the image by a given amount
 *
 * @param int $degrees
 *
 * @return AdapterInterface
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
 *
 * @param string|null $file
 * @param int         $quality
 *
 * @return AdapterInterface
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


	if (Z_TYPE_P(&file) == IS_NULL) {
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
 *
 * @param int $amount
 *
 * @return AdapterInterface
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, sharpen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *amount_param = NULL, _0, _1, _2;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(amount)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);
	amount = zephir_get_intval(amount_param);


	ZVAL_LONG(&_1, amount);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkhighlow", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	amount = zephir_get_numberval(&_0);
	ZVAL_LONG(&_1, amount);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processsharpen", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Add a text to an image with a specified opacity
 *
 * @param string      $text
 * @param mixed       $offsetX
 * @param mixed       $offsetY
 * @param int         $opacity
 * @param string      $color
 * @param int         $size
 * @param string|null $fontFile
 *
 * @return AdapterInterface
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, text)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long opacity, size, ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *offsetX = NULL, offsetX_sub, *offsetY = NULL, offsetY_sub, *opacity_param = NULL, *color_param = NULL, *size_param = NULL, *fontFile_param = NULL, __$false, colors, _0, _1, _3, _4, _10, _11, _12, _13, _14, _15, _16, _5$$3, _6$$3, _7$$4, _8$$4, _9$$4;
	zval text, color, fontFile;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&fontFile);
	ZVAL_UNDEF(&offsetX_sub);
	ZVAL_UNDEF(&offsetY_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&colors);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
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
		Z_PARAM_STR_OR_NULL(fontFile)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &text_param, &offsetX, &offsetY, &opacity_param, &color_param, &size_param, &fontFile_param);
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
	if (!fontFile_param) {
		ZEPHIR_INIT_VAR(&fontFile);
	} else {
		zephir_get_strval(&fontFile, fontFile_param);
	}


	ZVAL_LONG(&_1, opacity);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkhighlow", NULL, 0, &_1);
	zephir_check_call_status();
	opacity = zephir_get_numberval(&_0);
	_2 = zephir_fast_strlen_ev(&color) > 1;
	if (_2) {
		ZVAL_LONG(&_1, 0);
		ZVAL_LONG(&_3, 1);
		ZEPHIR_INIT_VAR(&_4);
		zephir_substr(&_4, &color, 0 , 1 , 0);
		_2 = ZEPHIR_IS_STRING_IDENTICAL(&_4, "#");
	}
	if (_2) {
		ZVAL_LONG(&_5$$3, 1);
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_substr(&_6$$3, &color, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_get_strval(&color, &_6$$3);
	}
	if (zephir_fast_strlen_ev(&color) == 3) {
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "/./");
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "$0$0");
		ZEPHIR_CALL_FUNCTION(&_9$$4, "preg_replace", NULL, 37, &_7$$4, &_8$$4, &color);
		zephir_check_call_status();
		zephir_get_strval(&color, &_9$$4);
	}
	ZVAL_LONG(&_10, 2);
	ZEPHIR_CALL_FUNCTION(&_11, "str_split", NULL, 84, &color, &_10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "hexdec");
	ZEPHIR_CALL_FUNCTION(&colors, "array_map", NULL, 66, &_12, &_11);
	zephir_check_call_status();
	zephir_array_fetch_long(&_13, &colors, 0, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 495);
	zephir_array_fetch_long(&_14, &colors, 1, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 496);
	zephir_array_fetch_long(&_15, &colors, 2, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 497);
	ZVAL_LONG(&_10, opacity);
	ZVAL_LONG(&_16, size);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processtext", NULL, 0, &text, offsetX, offsetY, &_10, &_13, &_14, &_15, &_16, &fontFile);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Add a watermark to an image with the specified opacity
 *
 * @param AdapterInterface $watermark
 * @param int              $offsetX
 * @param int              $offsetY
 * @param int              $opacity
 *
 * @return AdapterInterface
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, watermark)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offsetX, offsetY, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *watermark, watermark_sub, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, op, x, y, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&watermark_sub);
	ZVAL_UNDEF(&op);
	ZVAL_UNDEF(&x);
	ZVAL_UNDEF(&y);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
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
	ZVAL_LONG(&_0, offsetX);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_CALL_METHOD(&x, this_ptr, "checkhighlow", NULL, 0, &_0, &_3, &_2);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, watermark, "getheight", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_sub_function(&_4, &_0, &_1);
	ZVAL_LONG(&_0, offsetX);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_CALL_METHOD(&y, this_ptr, "checkhighlow", NULL, 0, &_0, &_3, &_4);
	zephir_check_call_status();
	ZVAL_LONG(&_0, opacity);
	ZEPHIR_CALL_METHOD(&op, this_ptr, "checkhighlow", NULL, 0, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, opacity);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processwatermark", NULL, 0, watermark, &x, &y, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * @param int $value
 * @param int $min
 * @param int $max
 *
 * @return int
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, checkHighLow)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *value_param = NULL, *min_param = NULL, *max_param = NULL, _0, _1, _2;
	zend_long value, min, max, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_LONG(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(min)
		Z_PARAM_LONG(max)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value_param, &min_param, &max_param);
	value = zephir_get_intval(value_param);
	if (!min_param) {
		min = 0;
	} else {
		min = zephir_get_intval(min_param);
	}
	if (!max_param) {
		max = 100;
	} else {
		max = zephir_get_intval(max_param);
	}


	ZVAL_LONG(&_0, value);
	ZVAL_LONG(&_1, min);
	ZEPHIR_CALL_FUNCTION(&_2, "max", NULL, 86, &_0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_0, max);
	ZEPHIR_RETURN_CALL_FUNCTION("min", NULL, 87, &_0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

