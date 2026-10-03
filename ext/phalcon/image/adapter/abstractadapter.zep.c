
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/math.h"
#include "kernel/exception.h"
#include "kernel/string.h"


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
 *
 * @template TImage of object
 *
 * @phpstan-import-type image_channel from ImageTypes
 * @phpstan-import-type image_color_channels from ImageTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_AbstractAdapter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Image\\Adapter, AbstractAdapter, phalcon, image_adapter_abstractadapter, phalcon_image_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_image_adapter_abstractadapter_ce, SL("file"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_image_adapter_abstractadapter_ce, SL("height"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * The handle of the underlying backend. Every adapter assigns it in its
	 * constructor and releases it in its destructor.
	 *
	 * @var TImage|null
	 */
	zend_declare_property_null(phalcon_image_adapter_abstractadapter_ce, SL("image"), ZEND_ACC_PROTECTED);
	/**
	 * Maximum allowed pixel count (width * height) for a loaded image. Zero
	 * disables the check.
	 */
	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_image_adapter_abstractadapter_ce, SL("maxPixels"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_image_adapter_abstractadapter_ce, SL("mime"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_image_adapter_abstractadapter_ce, SL("realpath"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * Image type
	 *
	 * Driver dependent
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_image_adapter_abstractadapter_ce, SL("type"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * Image width
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_image_adapter_abstractadapter_ce, SL("width"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * Default cap on the pixel count (width * height) of a loaded image, used
	 * when the constructor is not given an explicit limit. Bounds the memory a
	 * crafted image (decompression bomb / pixel flood) can force the backend to
	 * allocate (CWE-409). Generous by default; override per instance.
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_image_adapter_abstractadapter_ce, SL("DEFAULT_MAX_PIXELS"), 50000000);

	zend_class_implements(phalcon_image_adapter_abstractadapter_ce, 1, phalcon_image_adapter_adapterinterface_ce);
	return SUCCESS;
}

/**
 * Set the background color of an image
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, background)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long opacity, ZEPHIR_LAST_CALL_STATUS;
	zval color_zv, *opacity_param = NULL, colors, _0, _1, _2, _3;
	zend_string *color = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&color_zv);
	ZVAL_UNDEF(&colors);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(color)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(opacity)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		opacity_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&color_zv);
	ZVAL_STR_COPY(&color_zv, color);
	if (!opacity_param) {
		opacity = 100;
	} else {
		}
	ZEPHIR_CALL_METHOD(&colors, this_ptr, "parseColor", NULL, 205, &color_zv);
	zephir_check_call_status();
	zephir_memory_observe(&_0);
	zephir_array_fetch_long(&_0, &colors, 0, PH_NOISY, "phalcon/Image/Adapter/AbstractAdapter.zep", 86);
	zephir_memory_observe(&_1);
	zephir_array_fetch_long(&_1, &colors, 1, PH_NOISY, "phalcon/Image/Adapter/AbstractAdapter.zep", 86);
	zephir_memory_observe(&_2);
	zephir_array_fetch_long(&_2, &colors, 2, PH_NOISY, "phalcon/Image/Adapter/AbstractAdapter.zep", 86);
	ZVAL_LONG(&_3, opacity);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processBackground", NULL, 0, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Blur image
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkHighLow", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	radius = zephir_get_intval(&_0);
	ZVAL_LONG(&_1, radius);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processBlur", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Crop an image to the given size
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, crop)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX = NULL, offsetX_sub, *offsetY = NULL, offsetY_sub, __$null, _2$$5, _3$$5, _4$$5, _5$$6, _6$$6, _7$$6, _8$$6, _9$$7, _10$$7, _11$$7, _12$$8, _13$$8, _14$$8, _15$$8, _16, _17, _20, _23, _18$$9, _19$$9, _21$$10, _22$$10;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS, _0$$3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offsetX_sub);
	ZVAL_UNDEF(&offsetY_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$10);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("width", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("height", 6, 1);
	}

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
		zephir_read_property_cached(&_2$$5, this_ptr, _zephir_prop_0, 231, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_LONG(&_3$$5, width);
		ZEPHIR_INIT_VAR(&_4$$5);
		zephir_sub_function(&_4$$5, &_2$$5, &_3$$5);
		ZEPHIR_INIT_NVAR(offsetX);
		zephir_div_zval_long(offsetX, &_4$$5, 2);
	} else {
		ZEPHIR_INIT_VAR(&_5$$6);
		if (ZEPHIR_LT_LONG(offsetX, 0)) {
			zephir_read_property_cached(&_6$$6, this_ptr, _zephir_prop_0, 231, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_7$$6);
			ZVAL_LONG(&_7$$6, width);
			ZEPHIR_INIT_VAR(&_8$$6);
			zephir_sub_function(&_8$$6, &_6$$6, &_7$$6);
			ZEPHIR_INIT_NVAR(&_5$$6);
			zephir_add_function(&_5$$6, &_8$$6, offsetX);
		} else {
			ZEPHIR_CPY_WRT(&_5$$6, offsetX);
		}
		ZEPHIR_CPY_WRT(offsetX, &_5$$6);
		ZEPHIR_INIT_NVAR(&_5$$6);
		zephir_read_property_cached(&_6$$6, this_ptr, _zephir_prop_0, 231, PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT(offsetX, &_6$$6)) {
			ZEPHIR_OBS_NVAR(&_5$$6);
			zephir_read_property_cached(&_5$$6, this_ptr, _zephir_prop_0, 231, PH_NOISY_CC);
		} else {
			ZEPHIR_CPY_WRT(&_5$$6, offsetX);
		}
		ZEPHIR_CPY_WRT(offsetX, &_5$$6);
	}
	if (Z_TYPE_P(offsetY) == IS_NULL) {
		zephir_read_property_cached(&_9$$7, this_ptr, _zephir_prop_1, 232, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_10$$7);
		ZVAL_LONG(&_10$$7, height);
		ZEPHIR_INIT_VAR(&_11$$7);
		zephir_sub_function(&_11$$7, &_9$$7, &_10$$7);
		ZEPHIR_INIT_NVAR(offsetY);
		zephir_div_zval_long(offsetY, &_11$$7, 2);
	} else {
		ZEPHIR_INIT_VAR(&_12$$8);
		if (ZEPHIR_LT_LONG(offsetY, 0)) {
			zephir_read_property_cached(&_13$$8, this_ptr, _zephir_prop_1, 232, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_14$$8);
			ZVAL_LONG(&_14$$8, height);
			ZEPHIR_INIT_VAR(&_15$$8);
			zephir_sub_function(&_15$$8, &_13$$8, &_14$$8);
			ZEPHIR_INIT_NVAR(&_12$$8);
			zephir_add_function(&_12$$8, &_15$$8, offsetY);
		} else {
			ZEPHIR_CPY_WRT(&_12$$8, offsetY);
		}
		ZEPHIR_CPY_WRT(offsetY, &_12$$8);
		ZEPHIR_INIT_NVAR(&_12$$8);
		zephir_read_property_cached(&_13$$8, this_ptr, _zephir_prop_1, 232, PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT(offsetY, &_13$$8)) {
			ZEPHIR_OBS_NVAR(&_12$$8);
			zephir_read_property_cached(&_12$$8, this_ptr, _zephir_prop_1, 232, PH_NOISY_CC);
		} else {
			ZEPHIR_CPY_WRT(&_12$$8, offsetY);
		}
		ZEPHIR_CPY_WRT(offsetY, &_12$$8);
	}
	zephir_read_property_cached(&_16, this_ptr, _zephir_prop_0, 231, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_17);
	zephir_sub_function(&_17, &_16, offsetX);
	if (ZEPHIR_LT_LONG(&_17, width)) {
		zephir_read_property_cached(&_18$$9, this_ptr, _zephir_prop_0, 231, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_19$$9);
		zephir_sub_function(&_19$$9, &_18$$9, offsetX);
		width = zephir_get_intval(&_19$$9);
	}
	zephir_read_property_cached(&_16, this_ptr, _zephir_prop_1, 232, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_20);
	zephir_sub_function(&_20, &_16, offsetY);
	if (ZEPHIR_LT_LONG(&_20, height)) {
		zephir_read_property_cached(&_21$$10, this_ptr, _zephir_prop_1, 232, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_22$$10);
		zephir_sub_function(&_22$$10, &_21$$10, offsetY);
		height = zephir_get_intval(&_22$$10);
	}
	ZVAL_LONG(&_16, width);
	ZVAL_LONG(&_23, height);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processCrop", NULL, 0, &_16, &_23, offsetX, offsetY);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processFlip", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getHeight)
{

	RETURN_MEMBER_TYPED(getThis(), "height", IS_LONG);
}

/**
 * @return TImage|null
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getImage)
{

	RETURN_MEMBER(getThis(), "image");
}

PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getMime)
{

	RETURN_MEMBER_TYPED(getThis(), "mime", IS_STRING);
}

PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getRealpath)
{

	RETURN_MEMBER_TYPED(getThis(), "realpath", IS_STRING);
}

PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getType)
{

	RETURN_MEMBER_TYPED(getThis(), "type", IS_LONG);
}

PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getWidth)
{

	RETURN_MEMBER_TYPED(getThis(), "width", IS_LONG);
}

/**
 * Composite one image onto another
 *
 * The mask is read through its public render() output rather than its
 * internal handle, so a mask created with a different backend composites
 * correctly. The cost is one encode/decode round trip per call, which is
 * worth knowing inside loops.
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processMask", NULL, 0, mask);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processPixelate", NULL, 0, &_0);
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
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, _1, _3, _4, _5, _6, _2$$3;
	zend_long height, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("height", 6, 1);
	}

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
		zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 232, PH_NOISY_CC | PH_READONLY);
		_0 = ZEPHIR_LT_LONG(&_1, height);
	}
	if (_0) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 232, PH_NOISY_CC | PH_READONLY);
		height = zephir_get_intval(&_2$$3);
	}
	ZVAL_LONG(&_4, opacity);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "checkHighLow", NULL, 0, &_4);
	zephir_check_call_status();
	opacity = zephir_get_intval(&_3);
	ZVAL_LONG(&_4, height);
	ZVAL_LONG(&_5, opacity);
	if (fadeIn) {
		ZVAL_BOOL(&_6, 1);
	} else {
		ZVAL_BOOL(&_6, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processReflection", NULL, 0, &_4, &_5, &_6);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Render the image and return the binary string
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, render)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *extension_param = NULL, *quality_param = NULL, rendered, _4, _5, _6, _0$$3, _1$$3, _2$$3;
	zval extension, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&rendered);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("file", 4, 1);
	}

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
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 233, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_1$$3, 4);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "pathinfo", NULL, 206, &_0$$3, &_1$$3);
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
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "checkHighLow", NULL, 0, &_5, &_6);
	zephir_check_call_status();
	quality = zephir_get_intval(&_4);
	ZVAL_LONG(&_5, quality);
	ZEPHIR_CALL_METHOD(&rendered, this_ptr, "processRender", NULL, 0, &extension, &_5);
	zephir_check_call_status();
	RETURN_CCTOR(&rendered);
}

/**
 * Resize the image to the given size
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, resize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *master_param = NULL, ratio, _0, _1, _2, _28, _29, _30, _31, _32, _3$$3, _4$$3, _5$$3, _6$$3, _7$$4, _8$$4, _9$$4, _10$$4, _11$$5, _12$$5, _13$$5, _14$$5, _15$$6, _16$$6, _17$$6, _18$$7, _19$$7, _20$$7, _21$$7, _22$$8, _23$$8, _24$$8, _25$$8, _26$$9, _27$$9;
	zend_long width, height, master, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ratio);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_27$$9);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("height", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("width", 5, 1);
	}

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
	ZVAL_LONG(&_0, width);
	ZVAL_LONG(&_1, height);
	ZVAL_LONG(&_2, master);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkResizeInput", NULL, 207, &_0, &_1, &_2);
	zephir_check_call_status();
	if (master != 7) {
		ZVAL_LONG(&_4$$3, width);
		ZVAL_LONG(&_5$$3, height);
		ZVAL_LONG(&_6$$3, master);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "checkResizeMaster", NULL, 208, &_4$$3, &_5$$3, &_6$$3);
		zephir_check_call_status();
		master = zephir_get_intval(&_3$$3);
		if (master == 2) { goto zephir_switch_0_clause_0; }
		if (master == 3) { goto zephir_switch_0_clause_1; }
		if (master == 6) { goto zephir_switch_0_clause_2; }
		if (master == 1) { goto zephir_switch_0_clause_3; }
		goto zephir_switch_0_end;
		zephir_switch_0_clause_0: ;
			ZEPHIR_INIT_VAR(&_7$$4);
			zephir_read_property_cached(&_8$$4, this_ptr, _zephir_prop_0, 232, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_9$$4);
			ZVAL_LONG(&_9$$4, width);
			ZEPHIR_INIT_VAR(&_10$$4);
			mul_function(&_10$$4, &_8$$4, &_9$$4);
			zephir_read_property_cached(&_8$$4, this_ptr, _zephir_prop_1, 231, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_9$$4);
			div_function(&_9$$4, &_10$$4, &_8$$4);
			zephir_round(&_7$$4, &_9$$4, NULL, NULL);
			height = zephir_get_intval(&_7$$4);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_1: ;
			ZEPHIR_INIT_VAR(&_11$$5);
			zephir_read_property_cached(&_12$$5, this_ptr, _zephir_prop_1, 231, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_13$$5);
			ZVAL_LONG(&_13$$5, height);
			ZEPHIR_INIT_VAR(&_14$$5);
			mul_function(&_14$$5, &_12$$5, &_13$$5);
			zephir_read_property_cached(&_12$$5, this_ptr, _zephir_prop_0, 232, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_13$$5);
			div_function(&_13$$5, &_14$$5, &_12$$5);
			zephir_round(&_11$$5, &_13$$5, NULL, NULL);
			width = zephir_get_intval(&_11$$5);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_2: ;
			zephir_read_property_cached(&_15$$6, this_ptr, _zephir_prop_1, 231, PH_NOISY_CC | PH_READONLY);
			zephir_read_property_cached(&_16$$6, this_ptr, _zephir_prop_0, 232, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&ratio);
			div_function(&ratio, &_15$$6, &_16$$6);
			ZEPHIR_INIT_VAR(&_17$$6);
			zephir_div_long_long(&_17$$6, width, height);
			if (ZEPHIR_GT(&_17$$6, &ratio)) {
				ZEPHIR_INIT_VAR(&_18$$7);
				zephir_read_property_cached(&_19$$7, this_ptr, _zephir_prop_0, 232, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_20$$7);
				ZVAL_LONG(&_20$$7, width);
				ZEPHIR_INIT_VAR(&_21$$7);
				mul_function(&_21$$7, &_19$$7, &_20$$7);
				zephir_read_property_cached(&_19$$7, this_ptr, _zephir_prop_1, 231, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_20$$7);
				div_function(&_20$$7, &_21$$7, &_19$$7);
				zephir_round(&_18$$7, &_20$$7, NULL, NULL);
				height = zephir_get_intval(&_18$$7);
			} else {
				ZEPHIR_INIT_VAR(&_22$$8);
				zephir_read_property_cached(&_23$$8, this_ptr, _zephir_prop_1, 231, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_24$$8);
				ZVAL_LONG(&_24$$8, height);
				ZEPHIR_INIT_VAR(&_25$$8);
				mul_function(&_25$$8, &_23$$8, &_24$$8);
				zephir_read_property_cached(&_23$$8, this_ptr, _zephir_prop_0, 232, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_24$$8);
				div_function(&_24$$8, &_25$$8, &_23$$8);
				zephir_round(&_22$$8, &_24$$8, NULL, NULL);
				width = zephir_get_intval(&_22$$8);
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_3: ;
			ZEPHIR_INIT_VAR(&_26$$9);
			if (0 == width) {
				ZEPHIR_OBS_NVAR(&_26$$9);
				zephir_read_property_cached(&_26$$9, this_ptr, _zephir_prop_1, 231, PH_NOISY_CC);
			} else {
				ZEPHIR_INIT_NVAR(&_26$$9);
				ZVAL_LONG(&_26$$9, width);
			}
			width = zephir_get_intval(&_26$$9);
			ZEPHIR_INIT_VAR(&_27$$9);
			if (0 == height) {
				ZEPHIR_OBS_NVAR(&_27$$9);
				zephir_read_property_cached(&_27$$9, this_ptr, _zephir_prop_0, 232, PH_NOISY_CC);
			} else {
				ZEPHIR_INIT_NVAR(&_27$$9);
				ZVAL_LONG(&_27$$9, height);
			}
			height = zephir_get_intval(&_27$$9);
			goto zephir_switch_0_end;
		zephir_switch_0_end: ;

	}
	ZEPHIR_INIT_VAR(&_28);
	ZVAL_LONG(&_0, width);
	zephir_round(&_28, &_0, NULL, NULL);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(&_29, "max", NULL, 209, &_28, &_1);
	zephir_check_call_status();
	width = zephir_get_intval(&_29);
	ZEPHIR_INIT_VAR(&_30);
	ZVAL_LONG(&_1, height);
	zephir_round(&_30, &_1, NULL, NULL);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_FUNCTION(&_31, "max", NULL, 209, &_30, &_2);
	zephir_check_call_status();
	height = zephir_get_intval(&_31);
	ZVAL_LONG(&_2, width);
	ZVAL_LONG(&_32, height);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processResize", NULL, 0, &_2, &_32);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(degrees)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &degrees_param);
	if (degrees > 180) {
		degrees = zephir_safe_mod_long_long(degrees, 360);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processRotate", NULL, 0, &_0);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("realpath", 8, 1);
	}

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
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 234, PH_NOISY_CC);
		zephir_cast_to_string(&_1$$3, &_0$$3);
		ZEPHIR_CPY_WRT(&file, &_1$$3);
	}
	ZVAL_LONG(&_2, quality);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processSave", NULL, 0, &file, &_2);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Sharpen the image by a given amount
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkHighLow", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	amount = zephir_get_intval(&_0);
	ZVAL_LONG(&_1, amount);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processSharpen", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Add a text to an image with a specified opacity
 *
 * The offsets accept `false` to centre the text on that axis, so they are
 * wider than the `int` the interface documents.
 *
 * @phpstan-param bool|int $offsetX
 * @phpstan-param bool|int $offsetY
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, text)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long opacity, size, ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, *offsetX = NULL, offsetX_sub, *offsetY = NULL, offsetY_sub, *opacity_param = NULL, color_zv, *size_param = NULL, fontFile_zv, __$false, colors, _0, _1, _2, _3, _4, _5;
	zend_string *text = NULL, *color = NULL, *fontFile = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&offsetX_sub);
	ZVAL_UNDEF(&offsetY_sub);
	ZVAL_UNDEF(&color_zv);
	ZVAL_UNDEF(&fontFile_zv);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&colors);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
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
	if (!color) {
		color = zend_string_init(ZEND_STRL("000000"), 0);
		zephir_memory_observe(&color_zv);
		ZVAL_STR(&color_zv, color);
	} else {
		zephir_memory_observe(&color_zv);
	ZVAL_STR_COPY(&color_zv, color);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkHighLow", NULL, 0, &_1);
	zephir_check_call_status();
	opacity = zephir_get_intval(&_0);
	ZEPHIR_CALL_METHOD(&colors, this_ptr, "parseColor", NULL, 205, &color_zv);
	zephir_check_call_status();
	zephir_memory_observe(&_2);
	zephir_array_fetch_long(&_2, &colors, 0, PH_NOISY, "phalcon/Image/Adapter/AbstractAdapter.zep", 397);
	zephir_memory_observe(&_3);
	zephir_array_fetch_long(&_3, &colors, 1, PH_NOISY, "phalcon/Image/Adapter/AbstractAdapter.zep", 398);
	zephir_memory_observe(&_4);
	zephir_array_fetch_long(&_4, &colors, 2, PH_NOISY, "phalcon/Image/Adapter/AbstractAdapter.zep", 399);
	ZVAL_LONG(&_1, opacity);
	ZVAL_LONG(&_5, size);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processText", NULL, 0, &text_zv, offsetX, offsetY, &_1, &_2, &_3, &_4, &_5, &fontFile_zv);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Add a watermark to an image with the specified opacity
 *
 * The watermark is read through its public render() output rather than its
 * internal handle, so a watermark created with a different backend
 * composites correctly. The cost is one encode/decode round trip per call,
 * which is worth knowing inside loops.
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("width", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("height", 6, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 231, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, watermark, "getWidth", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_sub_function(&_2, &_0, &_1);
	ZVAL_LONG(&_0, offsetX);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_CALL_METHOD(&x, this_ptr, "checkHighLow", NULL, 0, &_0, &_3, &_2);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 232, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, watermark, "getHeight", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_sub_function(&_4, &_0, &_1);
	ZVAL_LONG(&_0, offsetY);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_CALL_METHOD(&y, this_ptr, "checkHighLow", NULL, 0, &_0, &_3, &_4);
	zephir_check_call_status();
	ZVAL_LONG(&_0, opacity);
	ZEPHIR_CALL_METHOD(&op, this_ptr, "checkHighLow", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processWatermark", NULL, 0, watermark, &x, &y, &op);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Rejects an image whose pixel count exceeds the configured limit before
 * the backend allocates it, bounding decompression-bomb / pixel-flood
 * memory use (CWE-409). A zero limit disables the check.
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, assertPixelLimit)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, pixels, _0, _1, _2$$4, _3$$4;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pixels);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("maxPixels", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 235, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_LE_LONG(&_0, 0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&pixels);
	ZVAL_LONG(&pixels, (width * height));
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 235, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT(&pixels, &_1)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_image_exceptions_imagetoolarge_ce);
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 235, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 210, &pixels, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Image/Adapter/AbstractAdapter.zep", 457);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

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
	ZEPHIR_CALL_FUNCTION(&_2, "max", NULL, 209, &_0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_0, max);
	ZEPHIR_RETURN_CALL_FUNCTION("min", NULL, 211, &_0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Renders the supplied color onto the image as the background. Channels
 * are 0-255; the opacity is the validated 0-100 value.
 *
 * @phpstan-param image_channel $red
 * @phpstan-param image_channel $green
 * @phpstan-param image_channel $blue
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processBackground)
{
}

/**
 * Applies a blur. The radius is already clamped to 1-100.
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processBlur)
{
}

/**
 * Crops the image. Width, height and both offsets are already normalized
 * to fit within the current canvas.
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processCrop)
{
}

/**
 * Flips the image. The direction is already normalized to
 * Enum::HORIZONTAL or Enum::VERTICAL.
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processFlip)
{
}

/**
 * Composites the supplied image as a mask onto this one. The mask is read
 * through its public render() output, so it may be any adapter backend.
 *
 * @phpstan-return void
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processMask)
{
}

/**
 * Pixelates the image. The amount is already at least 2.
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processPixelate)
{
}

/**
 * Adds a reflection. The height is clamped to the image height and the
 * opacity to 0-100.
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processReflection)
{
}

/**
 * Renders the image to a binary string. The extension is non-empty and the
 * quality is already clamped to 1-100. Returns the encoded bytes.
 *
 * @phpstan-return false|string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processRender)
{
}

/**
 * Resizes the image. Width and height are already resolved to positive
 * integers per the requested resize mode.
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processResize)
{
}

/**
 * Rotates the image. The degrees value is already normalized to -180..180.
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processRotate)
{
}

/**
 * Saves the image to the supplied file path.
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processSave)
{
}

/**
 * Sharpens the image. The amount is already clamped to 1-100.
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processSharpen)
{
}

/**
 * Renders text onto the image. The opacity is clamped to 0-100 and the
 * colour is supplied as separate 0-255 channels.
 *
 * @phpstan-param bool|int $offsetX
 * @phpstan-param bool|int $offsetY
 * @phpstan-param image_channel $red
 * @phpstan-param image_channel $green
 * @phpstan-param image_channel $blue
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processText)
{
}

/**
 * Composites the supplied watermark onto this image. Offsets and opacity
 * are already clamped to the valid range; the watermark is read through
 * its public render() output, so it may be any adapter backend.
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processWatermark)
{
}

/**
 * Resize the image to the given size
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, checkResizeInput)
{
	zend_bool _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *master_param = NULL, _1$$4, _2$$6, _3$$8;
	zend_long width, height, master, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$8);
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
	if (master == 7) { goto zephir_switch_0_clause_0; }
	if (master == 4) { goto zephir_switch_0_clause_1; }
	if (master == 5) { goto zephir_switch_0_clause_2; }
	if (master == 6) { goto zephir_switch_0_clause_3; }
	if (master == 2) { goto zephir_switch_0_clause_4; }
	if (master == 3) { goto zephir_switch_0_clause_5; }
	goto zephir_switch_0_clause_6;
	zephir_switch_0_clause_0: ;
	zephir_switch_0_clause_1: ;
	zephir_switch_0_clause_2: ;
	zephir_switch_0_clause_3: ;
		_0$$3 = 0 == width;
		if (!(_0$$3)) {
			_0$$3 = 0 == height;
		}
		if (_0$$3) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_image_exceptions_missingdimensions_ce);
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 212);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Image/Adapter/AbstractAdapter.zep", 609);
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_4: ;
		if (0 == width) {
			ZEPHIR_INIT_VAR(&_2$$6);
			object_init_ex(&_2$$6, phalcon_image_exceptions_missingwidth_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$6, "__construct", NULL, 213);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$6, "phalcon/Image/Adapter/AbstractAdapter.zep", 614);
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_5: ;
		if (0 == height) {
			ZEPHIR_INIT_VAR(&_3$$8);
			object_init_ex(&_3$$8, phalcon_image_exceptions_missingheight_ce);
			ZEPHIR_CALL_METHOD(NULL, &_3$$8, "__construct", NULL, 214);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$8, "phalcon/Image/Adapter/AbstractAdapter.zep", 619);
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_6: ;
		goto zephir_switch_0_end;
	zephir_switch_0_end: ;

	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, checkResizeMaster)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *master_param = NULL, _0$$3, _1$$3, _2$$3, _3$$3, _4$$4, _5$$4, _6$$4, _7$$4;
	zend_long width, height, master;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("width", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("height", 6, 1);
	}

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
	if (master == 4) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 231, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_div_zval_long(&_2$$3, &_1$$3, width);
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 232, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_div_zval_long(&_3$$3, &_1$$3, height);
		if (ZEPHIR_GT(&_2$$3, &_3$$3)) {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_LONG(&_0$$3, 2);
		} else {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_LONG(&_0$$3, 3);
		}
		RETURN_CCTOR(&_0$$3);
	}
	if (master == 5) {
		ZEPHIR_INIT_VAR(&_4$$4);
		zephir_read_property_cached(&_5$$4, this_ptr, _zephir_prop_0, 231, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_6$$4);
		zephir_div_zval_long(&_6$$4, &_5$$4, width);
		zephir_read_property_cached(&_5$$4, this_ptr, _zephir_prop_1, 232, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_7$$4);
		zephir_div_zval_long(&_7$$4, &_5$$4, height);
		if (ZEPHIR_GT(&_6$$4, &_7$$4)) {
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_LONG(&_4$$4, 3);
		} else {
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_LONG(&_4$$4, 2);
		}
		RETURN_CCTOR(&_4$$4);
	}
	RETURN_MM_LONG(master);
}

/**
 * Parses a hex color ("#rgb", "rgb", "#rrggbb" or "rrggbb") into an array
 * of three integer channels [red, green, blue].
 *
 * @phpstan-return image_color_channels
 * @throws InvalidColor
 */
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, parseColor)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *color_param = NULL, channels, _1, _2, _3, _10, _11, _12, _13, _15, _16, _17, _4$$3, _5$$3, _6$$4, _7$$4, _8$$4, _14$$5;
	zval color, _9$$4;

	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&channels);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_14$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(color_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &color_param);
	zephir_get_strval(&color, color_param);
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
		ZEPHIR_CALL_FUNCTION(&_8$$4, "preg_replace", NULL, 6, &_6$$4, &_7$$4, &color);
		zephir_check_call_status();
		zephir_cast_to_string(&_9$$4, &_8$$4);
		ZEPHIR_CPY_WRT(&color, &_9$$4);
	}
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "/^[0-9a-fA-F]{6}$/");
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "/^[0-9a-fA-F]{6}$/");
	zephir_preg_match(&_12, &_13, &color, &_10, 0, 0 , 0 );
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_12, 1)) {
		ZEPHIR_INIT_VAR(&_14$$5);
		object_init_ex(&_14$$5, phalcon_image_exceptions_invalidcolor_ce);
		ZEPHIR_CALL_METHOD(NULL, &_14$$5, "__construct", NULL, 215, &color);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_14$$5, "phalcon/Image/Adapter/AbstractAdapter.zep", 670);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_LONG(&_15, 2);
	ZEPHIR_CALL_FUNCTION(&_16, "str_split", NULL, 216, &color, &_15);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_17);
	ZVAL_STRING(&_17, "hexdec");
	ZEPHIR_CALL_FUNCTION(&channels, "array_map", NULL, 20, &_17, &_16);
	zephir_check_call_status();
	RETURN_CCTOR(&channels);
}

