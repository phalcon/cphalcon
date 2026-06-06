
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
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(color_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(opacity)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &color_param, &opacity_param);
	zephir_get_strval(&color, color_param);
	if (!opacity_param) {
		opacity = 100;
	} else {
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
		ZEPHIR_CALL_FUNCTION(&_8$$4, "preg_replace", NULL, 76, &_6$$4, &_7$$4, &color);
		zephir_check_call_status();
		zephir_get_strval(&color, &_8$$4);
	}
	ZVAL_LONG(&_9, 2);
	ZEPHIR_CALL_FUNCTION(&_10, "str_split", NULL, 166, &color, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "hexdec");
	ZEPHIR_CALL_FUNCTION(&colors, "array_map", NULL, 20, &_11, &_10);
	zephir_check_call_status();
	zephir_array_fetch_long(&_12, &colors, 0, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 99);
	zephir_array_fetch_long(&_13, &colors, 1, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 99);
	zephir_array_fetch_long(&_14, &colors, 2, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 99);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(radius)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &radius_param);
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
	zval *width_param = NULL, *height_param = NULL, *offsetX = NULL, offsetX_sub, *offsetY = NULL, offsetY_sub, __$null, _2$$5, _3$$6, _4$$6, _5$$6, _6$$7, _7$$8, _8$$8, _9$$8, _10, _11, _14, _17, _12$$9, _13$$9, _15$$10, _16$$10;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS, _0$$3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offsetX_sub);
	ZVAL_UNDEF(&offsetY_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$10);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(offsetX)
		Z_PARAM_ZVAL_OR_NULL(offsetY)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 2, &width_param, &height_param, &offsetX, &offsetY);
	if (!offsetX) {
		offsetX = &offsetX_sub;
		ZEPHIR_CPY_WRT(offsetX, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(offsetX);
	}
	if (!offsetY) {
		offsetY = &offsetY_sub;
		ZEPHIR_CPY_WRT(offsetY, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(offsetY);
	}
	if (Z_TYPE_P(offsetX) != IS_NULL) {
		_0$$3 = zephir_get_intval(offsetX);
		ZEPHIR_INIT_NVAR(offsetX);
		ZVAL_LONG(offsetX, _0$$3);
	}
	if (Z_TYPE_P(offsetY) != IS_NULL) {
		_1$$4 = zephir_get_intval(offsetY);
		ZEPHIR_INIT_NVAR(offsetY);
		ZVAL_LONG(offsetY, _1$$4);
	}
	if (Z_TYPE_P(offsetX) == IS_NULL) {
		zephir_read_property(&_2$$5, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(offsetX);
		ZVAL_DOUBLE(offsetX, (zephir_safe_div_long_long(((zephir_get_numberval(&_2$$5) - width)), 2)));
	} else {
		ZEPHIR_INIT_VAR(&_3$$6);
		if (ZEPHIR_LT_LONG(offsetX, 0)) {
			zephir_read_property(&_4$$6, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_3$$6);
			ZVAL_LONG(&_3$$6, ((zephir_get_numberval(&_4$$6) - width) + (zend_long) zephir_get_numberval(offsetX)));
		} else {
			ZEPHIR_CPY_WRT(&_3$$6, offsetX);
		}
		ZEPHIR_CPY_WRT(offsetX, &_3$$6);
		ZEPHIR_INIT_NVAR(&_3$$6);
		zephir_read_property(&_5$$6, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT(offsetX, &_5$$6)) {
			ZEPHIR_OBS_NVAR(&_3$$6);
			zephir_read_property(&_3$$6, this_ptr, ZEND_STRL("width"), PH_NOISY_CC);
		} else {
			ZEPHIR_CPY_WRT(&_3$$6, offsetX);
		}
		ZEPHIR_CPY_WRT(offsetX, &_3$$6);
	}
	if (Z_TYPE_P(offsetY) == IS_NULL) {
		zephir_read_property(&_6$$7, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(offsetY);
		ZVAL_DOUBLE(offsetY, (zephir_safe_div_long_long(((zephir_get_numberval(&_6$$7) - height)), 2)));
	} else {
		ZEPHIR_INIT_VAR(&_7$$8);
		if (ZEPHIR_LT_LONG(offsetY, 0)) {
			zephir_read_property(&_8$$8, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_7$$8);
			ZVAL_LONG(&_7$$8, ((zephir_get_numberval(&_8$$8) - height) + (zend_long) zephir_get_numberval(offsetY)));
		} else {
			ZEPHIR_CPY_WRT(&_7$$8, offsetY);
		}
		ZEPHIR_CPY_WRT(offsetY, &_7$$8);
		ZEPHIR_INIT_NVAR(&_7$$8);
		zephir_read_property(&_9$$8, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT(offsetY, &_9$$8)) {
			ZEPHIR_OBS_NVAR(&_7$$8);
			zephir_read_property(&_7$$8, this_ptr, ZEND_STRL("height"), PH_NOISY_CC);
		} else {
			ZEPHIR_CPY_WRT(&_7$$8, offsetY);
		}
		ZEPHIR_CPY_WRT(offsetY, &_7$$8);
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_11);
	zephir_sub_function(&_11, &_10, offsetX);
	if (ZEPHIR_LT_LONG(&_11, width)) {
		zephir_read_property(&_12$$9, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_13$$9);
		zephir_sub_function(&_13$$9, &_12$$9, offsetX);
		width = zephir_get_numberval(&_13$$9);
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_14);
	zephir_sub_function(&_14, &_10, offsetY);
	if (ZEPHIR_LT_LONG(&_14, height)) {
		zephir_read_property(&_15$$10, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_16$$10);
		zephir_sub_function(&_16$$10, &_15$$10, offsetY);
		height = zephir_get_numberval(&_16$$10);
	}
	ZVAL_LONG(&_10, width);
	ZVAL_LONG(&_17, height);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcrop", NULL, 0, &_10, &_17, offsetX, offsetY);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(direction)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &direction_param);
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

	RETURN_MEMBER_TYPED(getThis(), "height", IS_LONG);
}

/**
 * @return object|null
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getImage)
{

	RETURN_MEMBER(getThis(), "image");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getMime)
{

	RETURN_MEMBER_TYPED(getThis(), "mime", IS_STRING);
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getRealpath)
{

	RETURN_MEMBER_TYPED(getThis(), "realpath", IS_STRING);
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getType)
{

	RETURN_MEMBER_TYPED(getThis(), "type", IS_LONG);
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getWidth)
{

	RETURN_MEMBER_TYPED(getThis(), "width", IS_LONG);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(mask, phalcon_image_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(amount)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &amount_param);
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
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_LONG(height)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(opacity)
		Z_PARAM_BOOL(fadeIn)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &height_param, &opacity_param, &fadeIn_param);
	if (!opacity_param) {
		opacity = 100;
	} else {
		}
	if (!fadeIn_param) {
		fadeIn = 0;
	} else {
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
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(extension_param)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &extension_param, &quality_param);
	if (!extension_param) {
		ZEPHIR_INIT_VAR(&extension);
	} else {
		zephir_get_strval(&extension, extension_param);
	}
	if (!quality_param) {
		quality = 100;
	} else {
		}
	if (Z_TYPE_P(&extension) == IS_NULL) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_1$$3, 4);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "pathinfo", NULL, 167, &_0$$3, &_1$$3);
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
	zval *width_param = NULL, *height_param = NULL, *master_param = NULL, _23, _24, _25, _26, _27, _28, _29, _30, _1$$4, _2$$6, _3$$8, _4$$10, _5$$10, _6$$10, _7$$11, _8$$11, _9$$11, _10$$12, _11$$12, _12$$13, _13$$13, _14$$14, _15$$14, _16$$14, _17$$15, _18$$15, _19$$16, _20$$16, _21$$17, _22$$17;
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
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_22$$17);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(width, is_null_true)
		Z_PARAM_LONG_OR_NULL(height, is_null_true)
		Z_PARAM_LONG(master)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 3, &width_param, &height_param, &master_param);
	if (!width_param) {
		width = 0;
	} else {
		}
	if (!height_param) {
		height = 0;
	} else {
		}
	if (!master_param) {
		master = 4;
	} else {
		}
	do {
		if (master == 7 || master == 4 || master == 5 || master == 6) {
			_0$$3 = 0 == width;
			if (!(_0$$3)) {
				_0$$3 = 0 == height;
			}
			if (_0$$3) {
				ZEPHIR_INIT_VAR(&_1$$4);
				object_init_ex(&_1$$4, phalcon_image_exceptions_missingdimensions_ce);
				ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 168);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_1$$4, "phalcon/Image/Adapter/AbstractAdapter.zep", 340);
				ZEPHIR_MM_RESTORE();
				return;
			}
			break;
		}
		if (master == 2) {
			if (0 == width) {
				ZEPHIR_INIT_VAR(&_2$$6);
				object_init_ex(&_2$$6, phalcon_image_exceptions_missingwidth_ce);
				ZEPHIR_CALL_METHOD(NULL, &_2$$6, "__construct", NULL, 169);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_2$$6, "phalcon/Image/Adapter/AbstractAdapter.zep", 345);
				ZEPHIR_MM_RESTORE();
				return;
			}
			break;
		}
		if (master == 3) {
			if (0 == height) {
				ZEPHIR_INIT_VAR(&_3$$8);
				object_init_ex(&_3$$8, phalcon_image_exceptions_missingheight_ce);
				ZEPHIR_CALL_METHOD(NULL, &_3$$8, "__construct", NULL, 170);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$8, "phalcon/Image/Adapter/AbstractAdapter.zep", 350);
				ZEPHIR_MM_RESTORE();
				return;
			}
			break;
		}
	} while(0);

	if (master != 7) {
		if (master == 4) {
			ZEPHIR_INIT_VAR(&_4$$10);
			zephir_read_property(&_5$$10, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_6$$10, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			if ((zephir_safe_div_zval_long(&_5$$10, width)) > (int) (zephir_safe_div_zval_long(&_6$$10, height))) {
				ZEPHIR_INIT_NVAR(&_4$$10);
				ZVAL_LONG(&_4$$10, 2);
			} else {
				ZEPHIR_INIT_NVAR(&_4$$10);
				ZVAL_LONG(&_4$$10, 3);
			}
			master = zephir_get_numberval(&_4$$10);
		}
		if (master == 5) {
			ZEPHIR_INIT_VAR(&_7$$11);
			zephir_read_property(&_8$$11, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_9$$11, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			if ((zephir_safe_div_zval_long(&_8$$11, width)) > (int) (zephir_safe_div_zval_long(&_9$$11, height))) {
				ZEPHIR_INIT_NVAR(&_7$$11);
				ZVAL_LONG(&_7$$11, 3);
			} else {
				ZEPHIR_INIT_NVAR(&_7$$11);
				ZVAL_LONG(&_7$$11, 2);
			}
			master = zephir_get_numberval(&_7$$11);
		}
		do {
			if (master == 2) {
				zephir_read_property(&_10$$12, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_11$$12, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
				height = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_10$$12) * width), &_11$$12));
				break;
			}
			if (master == 3) {
				zephir_read_property(&_12$$13, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_13$$13, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
				width = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_12$$13) * height), &_13$$13));
				break;
			}
			if (master == 6) {
				zephir_read_property(&_14$$14, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_15$$14, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_16$$14);
				div_function(&_16$$14, &_14$$14, &_15$$14);
				ratio = zephir_get_numberval(&_16$$14);
				if ((zephir_safe_div_long_long(width, height)) > ratio) {
					zephir_read_property(&_17$$15, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_18$$15, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
					height = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_17$$15) * width), &_18$$15));
				} else {
					zephir_read_property(&_19$$16, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_20$$16, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
					width = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_19$$16) * height), &_20$$16));
				}
				break;
			}
			if (master == 1) {
				ZEPHIR_INIT_VAR(&_21$$17);
				if (0 == width) {
					ZEPHIR_OBS_NVAR(&_21$$17);
					zephir_read_property(&_21$$17, this_ptr, ZEND_STRL("width"), PH_NOISY_CC);
				} else {
					ZEPHIR_INIT_NVAR(&_21$$17);
					ZVAL_LONG(&_21$$17, width);
				}
				width = zephir_get_numberval(&_21$$17);
				ZEPHIR_INIT_VAR(&_22$$17);
				if (0 == height) {
					ZEPHIR_OBS_NVAR(&_22$$17);
					zephir_read_property(&_22$$17, this_ptr, ZEND_STRL("height"), PH_NOISY_CC);
				} else {
					ZEPHIR_INIT_NVAR(&_22$$17);
					ZVAL_LONG(&_22$$17, height);
				}
				height = zephir_get_numberval(&_22$$17);
				break;
			}
		} while(0);

	}
	ZEPHIR_INIT_VAR(&_23);
	ZVAL_LONG(&_24, width);
	zephir_round(&_23, &_24, NULL, NULL);
	ZVAL_LONG(&_25, 1);
	ZEPHIR_CALL_FUNCTION(&_26, "max", NULL, 171, &_23, &_25);
	zephir_check_call_status();
	width = zephir_get_intval(&_26);
	ZEPHIR_INIT_VAR(&_27);
	ZVAL_LONG(&_25, height);
	zephir_round(&_27, &_25, NULL, NULL);
	ZVAL_LONG(&_28, 1);
	ZEPHIR_CALL_FUNCTION(&_29, "max", NULL, 171, &_27, &_28);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(degrees)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &degrees_param);
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
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(file_param)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &file_param, &quality_param);
	if (!file_param) {
		ZEPHIR_INIT_VAR(&file);
	} else {
		zephir_get_strval(&file, file_param);
	}
	if (!quality_param) {
		quality = -1;
	} else {
		}
	if (Z_TYPE_P(&file) == IS_NULL) {
		zephir_memory_observe(&_0$$3);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(amount)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &amount_param);
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
	zval color;
	zend_long opacity, size, ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, *offsetX = NULL, offsetX_sub, *offsetY = NULL, offsetY_sub, *opacity_param = NULL, *color_param = NULL, *size_param = NULL, fontFile_zv, __$false, colors, _0, _1, _3, _4, _10, _11, _12, _13, _14, _15, _16, _5$$3, _6$$3, _7$$4, _8$$4, _9$$4;
	zend_string *text = NULL, *fontFile = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&offsetX_sub);
	ZVAL_UNDEF(&offsetY_sub);
	ZVAL_UNDEF(&fontFile_zv);
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
	ZVAL_UNDEF(&color);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 7)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(offsetX)
		Z_PARAM_ZVAL(offsetY)
		Z_PARAM_LONG(opacity)
		Z_PARAM_ZVAL(color_param)
		Z_PARAM_LONG(size)
		Z_PARAM_STR_OR_NULL(fontFile)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		offsetX = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		offsetY = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		opacity_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		color_param = ZEND_CALL_ARG(execute_data, 5);
	}
	if (ZEND_NUM_ARGS() > 5) {
		size_param = ZEND_CALL_ARG(execute_data, 6);
	}
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
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
		}
	if (!fontFile) {
		ZEPHIR_INIT_VAR(&fontFile_zv);
	} else {
		zephir_memory_observe(&fontFile_zv);
	ZVAL_STR_COPY(&fontFile_zv, fontFile);
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
		ZEPHIR_CALL_FUNCTION(&_9$$4, "preg_replace", NULL, 76, &_7$$4, &_8$$4, &color);
		zephir_check_call_status();
		zephir_get_strval(&color, &_9$$4);
	}
	ZVAL_LONG(&_10, 2);
	ZEPHIR_CALL_FUNCTION(&_11, "str_split", NULL, 166, &color, &_10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "hexdec");
	ZEPHIR_CALL_FUNCTION(&colors, "array_map", NULL, 20, &_12, &_11);
	zephir_check_call_status();
	zephir_array_fetch_long(&_13, &colors, 0, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 506);
	zephir_array_fetch_long(&_14, &colors, 1, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 507);
	zephir_array_fetch_long(&_15, &colors, 2, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/AbstractAdapter.zep", 508);
	ZVAL_LONG(&_10, opacity);
	ZVAL_LONG(&_16, size);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processtext", NULL, 0, &text_zv, offsetX, offsetY, &_10, &_13, &_14, &_15, &_16, &fontFile_zv);
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
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_OBJECT_OF_CLASS(watermark, phalcon_image_adapter_adapterinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(offsetX)
		Z_PARAM_LONG(offsetY)
		Z_PARAM_LONG(opacity)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 3, &watermark, &offsetX_param, &offsetY_param, &opacity_param);
	if (!offsetX_param) {
		offsetX = 0;
	} else {
		}
	if (!offsetY_param) {
		offsetY = 0;
	} else {
		}
	if (!opacity_param) {
		opacity = 100;
	} else {
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
	ZVAL_LONG(&_0, offsetY);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_CALL_METHOD(&y, this_ptr, "checkhighlow", NULL, 0, &_0, &_3, &_4);
	zephir_check_call_status();
	ZVAL_LONG(&_0, opacity);
	ZEPHIR_CALL_METHOD(&op, this_ptr, "checkhighlow", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processwatermark", NULL, 0, watermark, &x, &y, &op);
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

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_LONG(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(min)
		Z_PARAM_LONG(max)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &value_param, &min_param, &max_param);
	if (!min_param) {
		min = 0;
	} else {
		}
	if (!max_param) {
		max = 100;
	} else {
		}
	ZVAL_LONG(&_0, value);
	ZVAL_LONG(&_1, min);
	ZEPHIR_CALL_FUNCTION(&_2, "max", NULL, 171, &_0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_0, max);
	ZEPHIR_RETURN_CALL_FUNCTION("min", NULL, 172, &_0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

