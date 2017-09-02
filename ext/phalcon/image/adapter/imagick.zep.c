
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


/**
 * Phalcon\Image\Adapter\Imagick
 *
 * Image manipulation support. Allows images to be resized, cropped, etc.
 *
 *<code>
 * $image = new \Phalcon\Image\Adapter\Imagick("upload/test.jpg");
 *
 * $image->resize(200, 200)->rotate(90)->crop(100, 100);
 *
 * if ($image->save()) {
 *     echo "success";
 * }
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Imagick) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Imagick, phalcon, image_adapter_imagick, phalcon_image_adapter_ce, phalcon_image_adapter_imagick_method_entry, 0);

	zend_declare_property_long(phalcon_image_adapter_imagick_ce, SL("_version"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_bool(phalcon_image_adapter_imagick_ce, SL("_checked"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Checks if Imagick is enabled
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, check) {

	zval __$true, _0, _1, _2, _3, _6, _4$$5, _5$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, phalcon_image_adapter_imagick_ce, SL("_checked"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "imagick");
	if (!(zephir_class_exists(&_1, 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick is not installed, or the extension is not loaded", "phalcon/image/adapter/imagick.zep", 55);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Imagick::IMAGICK_EXTNUM");
	ZEPHIR_CALL_FUNCTION(&_3, "defined", NULL, 216, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "Imagick::IMAGICK_EXTNUM");
		ZEPHIR_CALL_FUNCTION(&_5$$5, "constant", NULL, 188, &_4$$5);
		zephir_check_call_status();
		zend_update_static_property(phalcon_image_adapter_imagick_ce, ZEND_STRL("_version"), &_5$$5);
	}
	zend_update_static_property(phalcon_image_adapter_imagick_ce, ZEND_STRL("_checked"), &__$true);
	zephir_read_static_property_ce(&_6, phalcon_image_adapter_imagick_ce, SL("_checked"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_6);

}

/**
 * \Phalcon\Image\Adapter\Imagick constructor
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __construct) {

	zend_bool _20$$8;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, image, _0, _1, _2, _30, _31, _32, _33, _34, _35, _36, _37, _38, _3$$4, _4$$4, _5$$4, _6$$4, _7$$4, _11$$4, _12$$4, _16$$4, _8$$5, _9$$5, _10$$5, _13$$6, _14$$6, _15$$6, _17$$7, _18$$7, _19$$7, _24$$8, _25$$8, _26$$8, _27$$8, _28$$8, _29$$8, _21$$9, _22$$9, _23$$9;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &file_param, &width_param, &height_param);

	if (UNEXPECTED(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(&file, file_param);
	} else {
		ZEPHIR_INIT_VAR(&file);
		ZVAL_EMPTY_STRING(&file);
	}
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


	zephir_read_static_property_ce(&_0, phalcon_image_adapter_imagick_ce, SL("_checked"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_SELF(NULL, "check", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("_file"), &file);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_image"), &_1);
	zephir_read_property(&_2, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
	if ((zephir_file_exists(&_2 TSRMLS_CC) == SUCCESS)) {
		zephir_read_property(&_3$$4, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_4$$4, "realpath", NULL, 59, &_3$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_realpath"), &_4$$4);
		zephir_read_property(&_5$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_7$$4, this_ptr, SL("_realpath"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_6$$4, &_5$$4, "readimage", NULL, 0, &_7$$4);
		zephir_check_call_status();
		if (!(zephir_is_true(&_6$$4))) {
			ZEPHIR_INIT_VAR(&_8$$5);
			object_init_ex(&_8$$5, phalcon_image_exception_ce);
			zephir_read_property(&_9$$5, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_10$$5);
			ZEPHIR_CONCAT_SVS(&_10$$5, "Imagick::readImage ", &_9$$5, " failed");
			ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", NULL, 4, &_10$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_8$$5, "phalcon/image/adapter/imagick.zep", 86 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_11$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_12$$4, &_11$$4, "getimagealphachannel", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_12$$4))) {
			zephir_read_property(&_13$$6, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_14$$6);
			ZVAL_STRING(&_14$$6, "Imagick::ALPHACHANNEL_SET");
			ZEPHIR_CALL_FUNCTION(&_15$$6, "constant", NULL, 188, &_14$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_13$$6, "setimagealphachannel", NULL, 0, &_15$$6);
			zephir_check_call_status();
		}
		zephir_read_property(&_16$$4, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_LONG(&_16$$4, 1)) {
			zephir_read_property(&_17$$7, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&image, &_17$$7, "coalesceimages", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_18$$7, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_18$$7, "clear", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_19$$7, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_19$$7, "destroy", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_image"), &image);
		}
	} else {
		_20$$8 = !width;
		if (!(_20$$8)) {
			_20$$8 = !height;
		}
		if (_20$$8) {
			ZEPHIR_INIT_VAR(&_21$$9);
			object_init_ex(&_21$$9, phalcon_image_exception_ce);
			zephir_read_property(&_22$$9, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_23$$9);
			ZEPHIR_CONCAT_SV(&_23$$9, "Failed to create image from file ", &_22$$9);
			ZEPHIR_CALL_METHOD(NULL, &_21$$9, "__construct", NULL, 4, &_23$$9);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_21$$9, "phalcon/image/adapter/imagick.zep", 102 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_24$$8, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_25$$8);
		object_init_ex(&_25$$8, zephir_get_internal_ce(SL("imagickpixel")));
		ZEPHIR_INIT_VAR(&_26$$8);
		ZVAL_STRING(&_26$$8, "transparent");
		ZEPHIR_CALL_METHOD(NULL, &_25$$8, "__construct", NULL, 0, &_26$$8);
		zephir_check_call_status();
		ZVAL_LONG(&_27$$8, width);
		ZVAL_LONG(&_28$$8, height);
		ZEPHIR_CALL_METHOD(NULL, &_24$$8, "newimage", NULL, 0, &_27$$8, &_28$$8, &_25$$8);
		zephir_check_call_status();
		zephir_read_property(&_27$$8, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_26$$8);
		ZVAL_STRING(&_26$$8, "png");
		ZEPHIR_CALL_METHOD(NULL, &_27$$8, "setformat", NULL, 0, &_26$$8);
		zephir_check_call_status();
		zephir_read_property(&_28$$8, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_26$$8);
		ZVAL_STRING(&_26$$8, "png");
		ZEPHIR_CALL_METHOD(NULL, &_28$$8, "setimageformat", NULL, 0, &_26$$8);
		zephir_check_call_status();
		zephir_read_property(&_29$$8, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("_realpath"), &_29$$8);
	}
	zephir_read_property(&_30, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_31, &_30, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_width"), &_31);
	zephir_read_property(&_32, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_33, &_32, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_height"), &_33);
	zephir_read_property(&_34, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_35, &_34, "getimagetype", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_type"), &_35);
	zephir_read_property(&_36, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_37, &_36, "getimageformat", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_38);
	ZEPHIR_CONCAT_SV(&_38, "image/", &_37);
	zephir_update_property_zval(this_ptr, SL("_mime"), &_38);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a resize.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _resize) {

	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	zval *width_param = NULL, *height_param = NULL, image, _0, _6, _7, _1$$3, _2$$3, _4$$3;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	ZEPHIR_OBS_VAR(&image);
	zephir_read_property(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, &image, "setiteratorindex", NULL, 0, &_0);
	zephir_check_call_status();
	while (1) {
		ZVAL_LONG(&_1$$3, width);
		ZVAL_LONG(&_2$$3, height);
		ZEPHIR_CALL_METHOD(NULL, &image, "scaleimage", &_3, 0, &_1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, &image, "nextimage", &_5, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_4$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(&_6, &image, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_width"), &_6);
	ZEPHIR_CALL_METHOD(&_7, &image, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_height"), &_7);
	ZEPHIR_MM_RESTORE();

}

/**
 * This method scales the images using liquid rescaling method. Only support Imagick
 *
 * @param int $width   new width
 * @param int $height  new height
 * @param int $deltaX How much the seam can traverse on x-axis. Passing 0 causes the seams to be straight.
 * @param int $rigidity Introduces a bias for non-straight seams. This parameter is typically 0.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _liquidRescale) {

	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	zval *width_param = NULL, *height_param = NULL, *deltaX_param = NULL, *rigidity_param = NULL, ret, image, _0, _8, _9, _1$$3, _2$$3, _3$$3, _4$$3, _6$$3;
	zend_long width, height, deltaX, rigidity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &deltaX_param, &rigidity_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	deltaX = zephir_get_intval(deltaX_param);
	rigidity = zephir_get_intval(rigidity_param);


	ZEPHIR_OBS_VAR(&image);
	zephir_read_property(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, &image, "setiteratorindex", NULL, 0, &_0);
	zephir_check_call_status();
	while (1) {
		ZVAL_LONG(&_1$$3, width);
		ZVAL_LONG(&_2$$3, height);
		ZVAL_LONG(&_3$$3, deltaX);
		ZVAL_LONG(&_4$$3, rigidity);
		ZEPHIR_CALL_METHOD(&ret, &image, "liquidrescaleimage", &_5, 0, &_1$$3, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::liquidRescale failed", "phalcon/image/adapter/imagick.zep", 157);
			return;
		}
		ZEPHIR_CALL_METHOD(&_6$$3, &image, "nextimage", &_7, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_6$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(&_8, &image, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_width"), &_8);
	ZEPHIR_CALL_METHOD(&_9, &image, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_height"), &_9);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a crop.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _crop) {

	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_8 = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, image, _0, _9, _10, _1$$3, _2$$3, _3$$3, _4$$3, _7$$3;
	zend_long width, height, offsetX, offsetY, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &offsetX_param, &offsetY_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);


	ZEPHIR_OBS_VAR(&image);
	zephir_read_property(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, &image, "setiteratorindex", NULL, 0, &_0);
	zephir_check_call_status();
	while (1) {
		ZVAL_LONG(&_1$$3, width);
		ZVAL_LONG(&_2$$3, height);
		ZVAL_LONG(&_3$$3, offsetX);
		ZVAL_LONG(&_4$$3, offsetY);
		ZEPHIR_CALL_METHOD(NULL, &image, "cropimage", &_5, 0, &_1$$3, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_1$$3, width);
		ZVAL_LONG(&_2$$3, height);
		ZVAL_LONG(&_3$$3, 0);
		ZVAL_LONG(&_4$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &image, "setimagepage", &_6, 0, &_1$$3, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$3, &image, "nextimage", &_8, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_7$$3))) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(&_9, &image, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_width"), &_9);
	ZEPHIR_CALL_METHOD(&_10, &image, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_height"), &_10);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a rotation.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _rotate) {

	zval *degrees_param = NULL, pixel, _0, _1, _9, _10, _11, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3;
	zend_long degrees, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pixel);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);

	degrees = zephir_get_intval(degrees_param);


	zephir_read_property(&_0, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setiteratorindex", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&pixel);
	object_init_ex(&pixel, zephir_get_internal_ce(SL("imagickpixel")));
	ZEPHIR_CALL_METHOD(NULL, &pixel, "__construct", NULL, 0);
	zephir_check_call_status();
	while (1) {
		zephir_read_property(&_2$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_3$$3, degrees);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "rotateimage", NULL, 0, &pixel, &_3$$3);
		zephir_check_call_status();
		zephir_read_property(&_3$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_4$$3, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_5$$3, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_6$$3, 0);
		ZVAL_LONG(&_7$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "setimagepage", NULL, 0, &_4$$3, &_5$$3, &_6$$3, &_7$$3);
		zephir_check_call_status();
		zephir_read_property(&_6$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_8$$3, &_6$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_8$$3)) {
			break;
		}
	}
	zephir_read_property(&_1, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_9, &_1, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_width"), &_9);
	zephir_read_property(&_10, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_11, &_10, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_height"), &_11);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a flip.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _flip) {

	zval *direction_param = NULL, func, _0, _1, _2$$4, _3$$4, _4$$4;
	zend_long direction, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&func);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

	direction = zephir_get_intval(direction_param);


	ZEPHIR_INIT_VAR(&func);
	ZVAL_STRING(&func, "flipImage");
	if (direction == 11) {
		ZEPHIR_INIT_NVAR(&func);
		ZVAL_STRING(&func, "flopImage");
	}
	zephir_read_property(&_0, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setiteratorindex", NULL, 0, &_1);
	zephir_check_call_status();
	while (1) {
		zephir_read_property(&_2$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, &_2$$4, &func, NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_3$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$4, &_3$$4, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_4$$4)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a sharpen.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _sharpen) {

	zval *amount_param = NULL, _0, _1, _2, _3$$3, _4$$3, _5$$3, _6$$3;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	ZEPHIR_INIT_VAR(&_0);
	if (amount < 5) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, 5);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, amount);
	}
	amount = zephir_get_numberval(&_0);
	amount = (long) (zephir_safe_div_long_long(((amount * 3.0)), 100 TSRMLS_CC));
	zephir_read_property(&_1, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setiteratorindex", NULL, 0, &_2);
	zephir_check_call_status();
	while (1) {
		zephir_read_property(&_3$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_4$$3, 0);
		ZVAL_LONG(&_5$$3, amount);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "sharpenimage", NULL, 0, &_4$$3, &_5$$3);
		zephir_check_call_status();
		zephir_read_property(&_4$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_6$$3, &_4$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_6$$3)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a reflection.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _reflection) {

	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_11 = NULL, *_13 = NULL, *_14 = NULL, *_16 = NULL, *_21 = NULL, *_24 = NULL, *_27 = NULL, *_29 = NULL, *_35 = NULL, *_38 = NULL, *_40 = NULL, *_43 = NULL, *_48 = NULL, *_55 = NULL;
	zend_bool fadeIn, _56$$13;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, reflection, fade, pseudo, image, pixel, ret, _0, _4, _17, _18, _30, _31, _32, _58, _59, _60, _61, _62, _1$$3, _2$$4, _3$$4, _6$$5, _8$$5, _9$$5, _10$$5, _12$$5, _15$$5, _19$$7, _20$$7, _22$$7, _23$$7, _25$$7, _26$$7, _28$$7, _33$$10, _34$$10, _36$$10, _37$$10, _39$$10, _41$$10, _42$$10, _44$$10, _45$$10, _46$$10, _47$$10, _49$$10, _50$$13, _51$$13, _52$$13, _53$$13, _54$$13, _57$$13;
	zend_long height, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&fade);
	ZVAL_UNDEF(&pseudo);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&pixel);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_58);
	ZVAL_UNDEF(&_59);
	ZVAL_UNDEF(&_60);
	ZVAL_UNDEF(&_61);
	ZVAL_UNDEF(&_62);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_33$$10);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_41$$10);
	ZVAL_UNDEF(&_42$$10);
	ZVAL_UNDEF(&_44$$10);
	ZVAL_UNDEF(&_45$$10);
	ZVAL_UNDEF(&_46$$10);
	ZVAL_UNDEF(&_47$$10);
	ZVAL_UNDEF(&_49$$10);
	ZVAL_UNDEF(&_50$$13);
	ZVAL_UNDEF(&_51$$13);
	ZVAL_UNDEF(&_52$$13);
	ZVAL_UNDEF(&_53$$13);
	ZVAL_UNDEF(&_54$$13);
	ZVAL_UNDEF(&_57$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &height_param, &opacity_param, &fadeIn_param);

	height = zephir_get_intval(height_param);
	opacity = zephir_get_intval(opacity_param);
	fadeIn = zephir_get_boolval(fadeIn_param);


	zephir_read_static_property_ce(&_0, phalcon_image_adapter_imagick_ce, SL("_version"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&reflection);
	if (ZEPHIR_GE_LONG(&_0, 30100)) {
		zephir_read_property(&_1$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		if (zephir_clone(&reflection, &_1$$3 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
	} else {
		zephir_read_property(&_2$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3$$4, &_2$$4, "clone", NULL, 0);
		zephir_check_call_status();
		if (zephir_clone(&reflection, &_3$$4 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
	}
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_METHOD(NULL, &reflection, "setiteratorindex", NULL, 0, &_4);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(NULL, &reflection, "flipimage", &_5, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$5, &reflection, "getimagewidth", &_7, 0);
		zephir_check_call_status();
		ZVAL_LONG(&_8$$5, height);
		ZVAL_LONG(&_9$$5, 0);
		ZVAL_LONG(&_10$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, &reflection, "cropimage", &_11, 0, &_6$$5, &_8$$5, &_9$$5, &_10$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_12$$5, &reflection, "getimagewidth", &_13, 0);
		zephir_check_call_status();
		ZVAL_LONG(&_8$$5, height);
		ZVAL_LONG(&_9$$5, 0);
		ZVAL_LONG(&_10$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, &reflection, "setimagepage", &_14, 0, &_12$$5, &_8$$5, &_9$$5, &_10$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_15$$5, &reflection, "nextimage", &_16, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_15$$5)) {
			break;
		}
	}
	if (fadeIn) {
		ZEPHIR_INIT_VAR(&pseudo);
		ZVAL_STRING(&pseudo, "gradient:black-transparent");
	} else {
		ZEPHIR_INIT_NVAR(&pseudo);
		ZVAL_STRING(&pseudo, "gradient:transparent-black");
	}
	ZEPHIR_INIT_VAR(&fade);
	object_init_ex(&fade, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &fade, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_17, &reflection, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_18, &reflection, "getimageheight", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &fade, "newpseudoimage", NULL, 0, &_17, &_18, &pseudo);
	zephir_check_call_status();
	opacity /= 100;
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_METHOD(NULL, &reflection, "setiteratorindex", NULL, 0, &_4);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_INIT_NVAR(&_19$$7);
		ZVAL_STRING(&_19$$7, "Imagick::COMPOSITE_DSTOUT");
		ZEPHIR_CALL_FUNCTION(&_20$$7, "constant", &_21, 188, &_19$$7);
		zephir_check_call_status();
		ZVAL_LONG(&_22$$7, 0);
		ZVAL_LONG(&_23$$7, 0);
		ZEPHIR_CALL_METHOD(&ret, &reflection, "compositeimage", &_24, 0, &fade, &_20$$7, &_22$$7, &_23$$7);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 292);
			return;
		}
		ZEPHIR_INIT_NVAR(&_19$$7);
		ZVAL_STRING(&_19$$7, "Imagick::EVALUATE_MULTIPLY");
		ZEPHIR_CALL_FUNCTION(&_25$$7, "constant", &_21, 188, &_19$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_19$$7);
		ZVAL_STRING(&_19$$7, "Imagick::CHANNEL_ALPHA");
		ZEPHIR_CALL_FUNCTION(&_26$$7, "constant", &_21, 188, &_19$$7);
		zephir_check_call_status();
		ZVAL_LONG(&_22$$7, opacity);
		ZEPHIR_CALL_METHOD(NULL, &reflection, "evaluateimage", &_27, 0, &_25$$7, &_22$$7, &_26$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_28$$7, &reflection, "nextimage", &_29, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_28$$7)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &fade, "destroy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&image);
	object_init_ex(&image, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &image, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&pixel);
	object_init_ex(&pixel, zephir_get_internal_ce(SL("imagickpixel")));
	ZEPHIR_CALL_METHOD(NULL, &pixel, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_30, &_4, "getimageheight", NULL, 0);
	zephir_check_call_status();
	height = (zephir_get_numberval(&_30) + height);
	zephir_read_property(&_31, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_32, 0);
	ZEPHIR_CALL_METHOD(NULL, &_31, "setiteratorindex", NULL, 0, &_32);
	zephir_check_call_status();
	while (1) {
		zephir_read_property(&_33$$10, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_34$$10, height);
		ZEPHIR_CALL_METHOD(NULL, &image, "newimage", &_35, 0, &_33$$10, &_34$$10, &pixel);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_36$$10);
		ZVAL_STRING(&_36$$10, "Imagick::ALPHACHANNEL_SET");
		ZEPHIR_CALL_FUNCTION(&_37$$10, "constant", &_21, 188, &_36$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &image, "setimagealphachannel", &_38, 0, &_37$$10);
		zephir_check_call_status();
		zephir_read_property(&_34$$10, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_39$$10, &_34$$10, "getcolorspace", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &image, "setcolorspace", &_40, 0, &_39$$10);
		zephir_check_call_status();
		zephir_read_property(&_41$$10, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_42$$10, &_41$$10, "getimagedelay", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &image, "setimagedelay", &_43, 0, &_42$$10);
		zephir_check_call_status();
		zephir_read_property(&_44$$10, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_36$$10);
		ZVAL_STRING(&_36$$10, "Imagick::COMPOSITE_SRC");
		ZEPHIR_CALL_FUNCTION(&_45$$10, "constant", &_21, 188, &_36$$10);
		zephir_check_call_status();
		ZVAL_LONG(&_46$$10, 0);
		ZVAL_LONG(&_47$$10, 0);
		ZEPHIR_CALL_METHOD(&ret, &image, "compositeimage", &_48, 0, &_44$$10, &_45$$10, &_46$$10, &_47$$10);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 317);
			return;
		}
		zephir_read_property(&_46$$10, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_49$$10, &_46$$10, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_49$$10)) {
			break;
		}
	}
	ZVAL_LONG(&_32, 0);
	ZEPHIR_CALL_METHOD(NULL, &image, "setiteratorindex", NULL, 0, &_32);
	zephir_check_call_status();
	ZVAL_LONG(&_32, 0);
	ZEPHIR_CALL_METHOD(NULL, &reflection, "setiteratorindex", NULL, 0, &_32);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_INIT_NVAR(&_50$$13);
		ZVAL_STRING(&_50$$13, "Imagick::COMPOSITE_OVER");
		ZEPHIR_CALL_FUNCTION(&_51$$13, "constant", &_21, 188, &_50$$13);
		zephir_check_call_status();
		zephir_read_property(&_52$$13, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_53$$13, 0);
		ZEPHIR_CALL_METHOD(&ret, &image, "compositeimage", &_48, 0, &reflection, &_51$$13, &_53$$13, &_52$$13);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 332);
			return;
		}
		ZEPHIR_CALL_METHOD(&_54$$13, &image, "nextimage", &_55, 0);
		zephir_check_call_status();
		_56$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_54$$13);
		if (!(_56$$13)) {
			ZEPHIR_CALL_METHOD(&_57$$13, &reflection, "nextimage", NULL, 0);
			zephir_check_call_status();
			_56$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_57$$13);
		}
		if (_56$$13) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &reflection, "destroy", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_32, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_32, "clear", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_58, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_58, "destroy", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_image"), &image);
	zephir_read_property(&_59, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_60, &_59, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_width"), &_60);
	zephir_read_property(&_61, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_62, &_61, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_height"), &_62);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a watermarking.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _watermark) {

	zephir_fcall_cache_entry *_7 = NULL;
	zend_long offsetX, offsetY, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *image, image_sub, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, watermark, ret, version, method, _1, _2, _3, _0$$3, _4$$5, _5$$5, _6$$5, _8$$5, _9$$5, _10$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image_sub);
	ZVAL_UNDEF(&watermark);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &image, &offsetX_param, &offsetY_param, &opacity_param);

	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);


	opacity = (long) (zephir_safe_div_long_long(opacity, 100 TSRMLS_CC));
	ZEPHIR_INIT_VAR(&watermark);
	object_init_ex(&watermark, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &watermark, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&method);
	ZVAL_STRING(&method, "setImageOpacity");
	if (EXPECTED((zephir_method_exists_ex(&watermark, SL("getversion") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_CALL_METHOD(&version, &watermark, "getversion", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_string(&_0$$3, &version, SL("versionNumber"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/imagick.zep", 365 TSRMLS_CC);
		if (ZEPHIR_GE_LONG(&_0$$3, 0x700)) {
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_STRING(&method, "setImageAlpha");
		}
	}
	ZEPHIR_CALL_METHOD(&_1, image, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &watermark, "readimageblob", NULL, 0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_2, opacity);
	ZEPHIR_CALL_METHOD_ZVAL(NULL, &watermark, &method, NULL, 0, &_2);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_CALL_METHOD(NULL, &_2, "setiteratorindex", NULL, 0, &_3);
	zephir_check_call_status();
	while (1) {
		zephir_read_property(&_4$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "Imagick::COMPOSITE_OVER");
		ZEPHIR_CALL_FUNCTION(&_6$$5, "constant", &_7, 188, &_5$$5);
		zephir_check_call_status();
		ZVAL_LONG(&_8$$5, offsetX);
		ZVAL_LONG(&_9$$5, offsetY);
		ZEPHIR_CALL_METHOD(&ret, &_4$$5, "compositeimage", NULL, 0, &watermark, &_6$$5, &_8$$5, &_9$$5);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 379);
			return;
		}
		zephir_read_property(&_8$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_10$$5, &_8$$5, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_10$$5)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &watermark, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &watermark, "destroy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a text
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _text) {

	zend_bool _6$$7;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long opacity, r, g, b, size, ZEPHIR_LAST_CALL_STATUS, x = 0, y = 0;
	zval *text_param = NULL, *offsetX = NULL, offsetX_sub, *offsetY = NULL, offsetY_sub, *opacity_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *size_param = NULL, *fontfile_param = NULL, draw, color, gravity, _0, _1, _2, _3, _4$$4, _5$$5, _7$$8, _9$$10, _10$$12, _11$$13, _12$$17, _13$$18, _14$$20, _15$$21, _16$$27, _17$$28, _18$$30, _19$$31, _20$$35, _21$$36, _22$$38, _23$$39, _24$$40, _25$$40, _26$$40;
	zval text, fontfile;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&fontfile);
	ZVAL_UNDEF(&offsetX_sub);
	ZVAL_UNDEF(&offsetY_sub);
	ZVAL_UNDEF(&draw);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&gravity);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&_13$$18);
	ZVAL_UNDEF(&_14$$20);
	ZVAL_UNDEF(&_15$$21);
	ZVAL_UNDEF(&_16$$27);
	ZVAL_UNDEF(&_17$$28);
	ZVAL_UNDEF(&_18$$30);
	ZVAL_UNDEF(&_19$$31);
	ZVAL_UNDEF(&_20$$35);
	ZVAL_UNDEF(&_21$$36);
	ZVAL_UNDEF(&_22$$38);
	ZVAL_UNDEF(&_23$$39);
	ZVAL_UNDEF(&_24$$40);
	ZVAL_UNDEF(&_25$$40);
	ZVAL_UNDEF(&_26$$40);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 9, 0, &text_param, &offsetX, &offsetY, &opacity_param, &r_param, &g_param, &b_param, &size_param, &fontfile_param);

	zephir_get_strval(&text, text_param);
	ZEPHIR_SEPARATE_PARAM(offsetX);
	ZEPHIR_SEPARATE_PARAM(offsetY);
	opacity = zephir_get_intval(opacity_param);
	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	size = zephir_get_intval(size_param);
	zephir_get_strval(&fontfile, fontfile_param);


	opacity = (long) (zephir_safe_div_long_long(opacity, 100 TSRMLS_CC));
	ZEPHIR_INIT_VAR(&draw);
	object_init_ex(&draw, zephir_get_internal_ce(SL("imagickdraw")));
	ZEPHIR_CALL_METHOD(NULL, &draw, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "rgb(%d, %d, %d)");
	ZVAL_LONG(&_1, r);
	ZVAL_LONG(&_2, g);
	ZVAL_LONG(&_3, b);
	ZEPHIR_CALL_FUNCTION(&color, "sprintf", NULL, 185, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("imagickpixel")));
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &color);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &draw, "setfillcolor", NULL, 0, &_0);
	zephir_check_call_status();
	if (!(Z_TYPE_P(&fontfile) == IS_UNDEF) && Z_STRLEN_P(&fontfile)) {
		ZEPHIR_CALL_METHOD(NULL, &draw, "setfont", NULL, 0, &fontfile);
		zephir_check_call_status();
	}
	if (size) {
		ZVAL_LONG(&_4$$4, size);
		ZEPHIR_CALL_METHOD(NULL, &draw, "setfontsize", NULL, 0, &_4$$4);
		zephir_check_call_status();
	}
	if (opacity) {
		ZVAL_LONG(&_5$$5, opacity);
		ZEPHIR_CALL_METHOD(NULL, &draw, "setfillopacity", NULL, 0, &_5$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&gravity);
	ZVAL_NULL(&gravity);
	if (((Z_TYPE_P(offsetX) == IS_TRUE || Z_TYPE_P(offsetX) == IS_FALSE) == 1)) {
		if (((Z_TYPE_P(offsetY) == IS_TRUE || Z_TYPE_P(offsetY) == IS_FALSE) == 1)) {
			ZEPHIR_INIT_NVAR(offsetX);
			ZVAL_LONG(offsetX, 0);
			ZEPHIR_INIT_NVAR(offsetY);
			ZVAL_LONG(offsetY, 0);
			_6$$7 = zephir_is_true(offsetX);
			if (_6$$7) {
				_6$$7 = zephir_is_true(offsetY);
			}
			if (_6$$7) {
				ZEPHIR_INIT_VAR(&_7$$8);
				ZVAL_STRING(&_7$$8, "Imagick::GRAVITY_SOUTHEAST");
				ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_7$$8);
				zephir_check_call_status();
			} else {
				if (zephir_is_true(offsetX)) {
					ZEPHIR_INIT_VAR(&_9$$10);
					ZVAL_STRING(&_9$$10, "Imagick::GRAVITY_EAST");
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_9$$10);
					zephir_check_call_status();
				} else {
					if (zephir_is_true(offsetY)) {
						ZEPHIR_INIT_VAR(&_10$$12);
						ZVAL_STRING(&_10$$12, "Imagick::GRAVITY_SOUTH");
						ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_10$$12);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_VAR(&_11$$13);
						ZVAL_STRING(&_11$$13, "Imagick::GRAVITY_CENTER");
						ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_11$$13);
						zephir_check_call_status();
					}
				}
			}
		} else {
			if (Z_TYPE_P(offsetY) == IS_LONG) {
				y = zephir_get_intval(offsetY);
				if (zephir_is_true(offsetX)) {
					ZEPHIR_INIT_NVAR(offsetX);
					if (y < 0) {
						ZVAL_LONG(offsetX, 0);
						ZEPHIR_INIT_NVAR(offsetY);
						ZVAL_LONG(offsetY, (y * -1));
						ZEPHIR_INIT_VAR(&_12$$17);
						ZVAL_STRING(&_12$$17, "Imagick::GRAVITY_SOUTHEAST");
						ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_12$$17);
						zephir_check_call_status();
					} else {
						ZVAL_LONG(offsetX, 0);
						ZEPHIR_INIT_VAR(&_13$$18);
						ZVAL_STRING(&_13$$18, "Imagick::GRAVITY_NORTHEAST");
						ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_13$$18);
						zephir_check_call_status();
					}
				} else {
					ZEPHIR_INIT_NVAR(offsetX);
					if (y < 0) {
						ZVAL_LONG(offsetX, 0);
						ZEPHIR_INIT_NVAR(offsetY);
						ZVAL_LONG(offsetY, (y * -1));
						ZEPHIR_INIT_VAR(&_14$$20);
						ZVAL_STRING(&_14$$20, "Imagick::GRAVITY_SOUTH");
						ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_14$$20);
						zephir_check_call_status();
					} else {
						ZVAL_LONG(offsetX, 0);
						ZEPHIR_INIT_VAR(&_15$$21);
						ZVAL_STRING(&_15$$21, "Imagick::GRAVITY_NORTH");
						ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_15$$21);
						zephir_check_call_status();
					}
				}
			}
		}
	} else {
		if (Z_TYPE_P(offsetX) == IS_LONG) {
			x = zephir_get_intval(offsetX);
			if (zephir_is_true(offsetX)) {
				if (((Z_TYPE_P(offsetY) == IS_TRUE || Z_TYPE_P(offsetY) == IS_FALSE) == 1)) {
					if (zephir_is_true(offsetY)) {
						ZEPHIR_INIT_NVAR(offsetY);
						if (x < 0) {
							ZEPHIR_INIT_NVAR(offsetX);
							ZVAL_LONG(offsetX, (x * -1));
							ZVAL_LONG(offsetY, 0);
							ZEPHIR_INIT_VAR(&_16$$27);
							ZVAL_STRING(&_16$$27, "Imagick::GRAVITY_SOUTHEAST");
							ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_16$$27);
							zephir_check_call_status();
						} else {
							ZVAL_LONG(offsetY, 0);
							ZEPHIR_INIT_VAR(&_17$$28);
							ZVAL_STRING(&_17$$28, "Imagick::GRAVITY_SOUTH");
							ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_17$$28);
							zephir_check_call_status();
						}
					} else {
						ZEPHIR_INIT_NVAR(offsetY);
						if (x < 0) {
							ZEPHIR_INIT_NVAR(offsetX);
							ZVAL_LONG(offsetX, (x * -1));
							ZVAL_LONG(offsetY, 0);
							ZEPHIR_INIT_VAR(&_18$$30);
							ZVAL_STRING(&_18$$30, "Imagick::GRAVITY_EAST");
							ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_18$$30);
							zephir_check_call_status();
						} else {
							ZVAL_LONG(offsetY, 0);
							ZEPHIR_INIT_VAR(&_19$$31);
							ZVAL_STRING(&_19$$31, "Imagick::GRAVITY_WEST");
							ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_19$$31);
							zephir_check_call_status();
						}
					}
				} else {
					if (Z_TYPE_P(offsetY) == IS_LONG) {
						x = zephir_get_intval(offsetX);
						y = zephir_get_intval(offsetY);
						if (x < 0) {
							ZEPHIR_INIT_NVAR(offsetX);
							if (y < 0) {
								ZVAL_LONG(offsetX, (x * -1));
								ZEPHIR_INIT_NVAR(offsetY);
								ZVAL_LONG(offsetY, (y * -1));
								ZEPHIR_INIT_VAR(&_20$$35);
								ZVAL_STRING(&_20$$35, "Imagick::GRAVITY_SOUTHEAST");
								ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_20$$35);
								zephir_check_call_status();
							} else {
								ZVAL_LONG(offsetX, (x * -1));
								ZEPHIR_INIT_VAR(&_21$$36);
								ZVAL_STRING(&_21$$36, "Imagick::GRAVITY_NORTHEAST");
								ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_21$$36);
								zephir_check_call_status();
							}
						} else {
							ZEPHIR_INIT_NVAR(offsetX);
							if (y < 0) {
								ZVAL_LONG(offsetX, 0);
								ZEPHIR_INIT_NVAR(offsetY);
								ZVAL_LONG(offsetY, (y * -1));
								ZEPHIR_INIT_VAR(&_22$$38);
								ZVAL_STRING(&_22$$38, "Imagick::GRAVITY_SOUTHWEST");
								ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_22$$38);
								zephir_check_call_status();
							} else {
								ZVAL_LONG(offsetX, 0);
								ZEPHIR_INIT_VAR(&_23$$39);
								ZVAL_STRING(&_23$$39, "Imagick::GRAVITY_NORTHWEST");
								ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_8, 188, &_23$$39);
								zephir_check_call_status();
							}
						}
					}
				}
			}
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &draw, "setgravity", NULL, 0, &gravity);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setiteratorindex", NULL, 0, &_2);
	zephir_check_call_status();
	while (1) {
		zephir_read_property(&_24$$40, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_25$$40, 0);
		ZEPHIR_CALL_METHOD(NULL, &_24$$40, "annotateimage", NULL, 0, &draw, offsetX, offsetY, &_25$$40, &text);
		zephir_check_call_status();
		zephir_read_property(&_25$$40, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_26$$40, &_25$$40, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_26$$40)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &draw, "destroy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Composite one image onto another
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _mask) {

	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *image, image_sub, mask, ret, _0, _1, _2, _3$$3, _4$$3, _5$$3, _6$$3, _8$$3, _9$$3, _10$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image_sub);
	ZVAL_UNDEF(&mask);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &image);



	ZEPHIR_INIT_VAR(&mask);
	object_init_ex(&mask, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &mask, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, image, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &mask, "readimageblob", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setiteratorindex", NULL, 0, &_2);
	zephir_check_call_status();
	while (1) {
		zephir_read_property(&_3$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_4$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "setimagematte", NULL, 0, &_4$$3);
		zephir_check_call_status();
		zephir_read_property(&_4$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "Imagick::COMPOSITE_DSTIN");
		ZEPHIR_CALL_FUNCTION(&_6$$3, "constant", &_7, 188, &_5$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_8$$3, 0);
		ZVAL_LONG(&_9$$3, 0);
		ZEPHIR_CALL_METHOD(&ret, &_4$$3, "compositeimage", NULL, 0, &mask, &_6$$3, &_8$$3, &_9$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 544);
			return;
		}
		zephir_read_property(&_8$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_10$$3, &_8$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_10$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &mask, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &mask, "destroy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a background.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _background) {

	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_18 = NULL, *_20 = NULL, *_25 = NULL;
	zval *r_param = NULL, *g_param = NULL, *b_param = NULL, *opacity_param = NULL, background, color, pixel1, pixel2, ret, _0, _1, _2, _3, _4$$3, _5$$3, _7$$3, _14$$3, _15$$3, _16$$3, _17$$3, _19$$3, _21$$3, _22$$3, _23$$3, _24$$3, _26$$3, _9$$4, _10$$4;
	zend_long r, g, b, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&background);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&pixel1);
	ZVAL_UNDEF(&pixel2);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_24$$3);
	ZVAL_UNDEF(&_26$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &r_param, &g_param, &b_param, &opacity_param);

	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	opacity = zephir_get_intval(opacity_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "rgb(%d, %d, %d)");
	ZVAL_LONG(&_1, r);
	ZVAL_LONG(&_2, g);
	ZVAL_LONG(&_3, b);
	ZEPHIR_CALL_FUNCTION(&color, "sprintf", NULL, 185, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&pixel1);
	object_init_ex(&pixel1, zephir_get_internal_ce(SL("imagickpixel")));
	ZEPHIR_CALL_METHOD(NULL, &pixel1, "__construct", NULL, 0, &color);
	zephir_check_call_status();
	opacity = (long) (zephir_safe_div_long_long(opacity, 100 TSRMLS_CC));
	ZEPHIR_INIT_VAR(&pixel2);
	object_init_ex(&pixel2, zephir_get_internal_ce(SL("imagickpixel")));
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "transparent");
	ZEPHIR_CALL_METHOD(NULL, &pixel2, "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&background);
	object_init_ex(&background, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &background, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setiteratorindex", NULL, 0, &_2);
	zephir_check_call_status();
	while (1) {
		zephir_read_property(&_4$$3, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_5$$3, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &background, "newimage", &_6, 0, &_4$$3, &_5$$3, &pixel1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$3, &background, "getimagealphachannel", &_8, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_7$$3))) {
			ZEPHIR_INIT_NVAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "Imagick::ALPHACHANNEL_SET");
			ZEPHIR_CALL_FUNCTION(&_10$$4, "constant", &_11, 188, &_9$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &background, "setimagealphachannel", &_12, 0, &_10$$4);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, &background, "setimagebackgroundcolor", &_13, 0, &pixel2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_14$$3);
		ZVAL_STRING(&_14$$3, "Imagick::EVALUATE_MULTIPLY");
		ZEPHIR_CALL_FUNCTION(&_15$$3, "constant", &_11, 188, &_14$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_14$$3);
		ZVAL_STRING(&_14$$3, "Imagick::CHANNEL_ALPHA");
		ZEPHIR_CALL_FUNCTION(&_16$$3, "constant", &_11, 188, &_14$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_17$$3, opacity);
		ZEPHIR_CALL_METHOD(NULL, &background, "evaluateimage", &_18, 0, &_15$$3, &_17$$3, &_16$$3);
		zephir_check_call_status();
		zephir_read_property(&_17$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_19$$3, &_17$$3, "getcolorspace", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &background, "setcolorspace", &_20, 0, &_19$$3);
		zephir_check_call_status();
		zephir_read_property(&_21$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_14$$3);
		ZVAL_STRING(&_14$$3, "Imagick::COMPOSITE_DISSOLVE");
		ZEPHIR_CALL_FUNCTION(&_22$$3, "constant", &_11, 188, &_14$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_23$$3, 0);
		ZVAL_LONG(&_24$$3, 0);
		ZEPHIR_CALL_METHOD(&ret, &background, "compositeimage", &_25, 0, &_21$$3, &_22$$3, &_23$$3, &_24$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 583);
			return;
		}
		zephir_read_property(&_23$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_26$$3, &_23$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_26$$3)) {
			break;
		}
	}
	zephir_read_property(&_2, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "clear", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "destroy", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_image"), &background);
	ZEPHIR_MM_RESTORE();

}

/**
 * Blur image
 *
 * @param int $radius Blur radius
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _blur) {

	zval *radius_param = NULL, _0, _1, _2$$3, _3$$3, _4$$3, _5$$3;
	zend_long radius, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);

	radius = zephir_get_intval(radius_param);


	zephir_read_property(&_0, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setiteratorindex", NULL, 0, &_1);
	zephir_check_call_status();
	while (1) {
		zephir_read_property(&_2$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_3$$3, radius);
		ZVAL_LONG(&_4$$3, 100);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "blurimage", NULL, 0, &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_read_property(&_3$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5$$3, &_3$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_5$$3)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Pixelate image
 *
 * @param int $amount amount to pixelate
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _pixelate) {

	zval *amount_param = NULL, _0, _1, _2, _3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS, width = 0, height = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	zephir_read_property(&_0, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
	width = (long) (zephir_safe_div_zval_long(&_0, amount TSRMLS_CC));
	zephir_read_property(&_1, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
	height = (long) (zephir_safe_div_zval_long(&_1, amount TSRMLS_CC));
	zephir_read_property(&_2, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_CALL_METHOD(NULL, &_2, "setiteratorindex", NULL, 0, &_3);
	zephir_check_call_status();
	while (1) {
		zephir_read_property(&_4$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_5$$3, width);
		ZVAL_LONG(&_6$$3, height);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "scaleimage", NULL, 0, &_5$$3, &_6$$3);
		zephir_check_call_status();
		zephir_read_property(&_5$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_6$$3, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_7$$3, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "scaleimage", NULL, 0, &_6$$3, &_7$$3);
		zephir_check_call_status();
		zephir_read_property(&_8$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_9$$3, &_8$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_9$$3)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a save.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _save) {

	zend_bool _15$$4;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality_param = NULL, ext, fp, _0, _1, _2, _3, _4, _5, _6, _7, _8, _10$$3, _11$$3, _12$$3, _13$$4, _14$$4, _16$$4, _22$$4, _17$$5, _18$$5, _19$$5, _20$$6, _21$$6;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&fp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &file_param, &quality_param);

	zephir_get_strval(&file, file_param);
	quality = zephir_get_intval(quality_param);


	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&ext, "pathinfo", NULL, 69, &file, &_0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setformat", NULL, 0, &ext);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setimageformat", NULL, 0, &ext);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "getimagetype", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_type"), &_3);
	zephir_read_property(&_4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_4, "getimageformat", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SV(&_6, "image/", &_5);
	zephir_update_property_zval(this_ptr, SL("_mime"), &_6);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "gif");
	ZEPHIR_CALL_FUNCTION(&_8, "strcasecmp", &_9, 11, &ext, &_7);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_8, 0)) {
		zephir_read_property(&_10$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_10$$3, "optimizeimagelayers", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_11$$3);
		ZVAL_STRING(&_11$$3, "w");
		ZEPHIR_CALL_FUNCTION(&fp, "fopen", NULL, 270, &file, &_11$$3);
		zephir_check_call_status();
		zephir_read_property(&_12$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_12$$3, "writeimagesfile", NULL, 0, &fp);
		zephir_check_call_status();
		zephir_fclose(&fp TSRMLS_CC);
		RETURN_MM_NULL();
	} else {
		ZEPHIR_INIT_VAR(&_13$$4);
		ZVAL_STRING(&_13$$4, "jpg");
		ZEPHIR_CALL_FUNCTION(&_14$$4, "strcasecmp", &_9, 11, &ext, &_13$$4);
		zephir_check_call_status();
		_15$$4 = ZEPHIR_IS_LONG(&_14$$4, 0);
		if (!(_15$$4)) {
			ZEPHIR_INIT_NVAR(&_13$$4);
			ZVAL_STRING(&_13$$4, "jpeg");
			ZEPHIR_CALL_FUNCTION(&_16$$4, "strcasecmp", &_9, 11, &ext, &_13$$4);
			zephir_check_call_status();
			_15$$4 = ZEPHIR_IS_LONG(&_16$$4, 0);
		}
		if (_15$$4) {
			zephir_read_property(&_17$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_18$$5);
			ZVAL_STRING(&_18$$5, "Imagick::COMPRESSION_JPEG");
			ZEPHIR_CALL_FUNCTION(&_19$$5, "constant", NULL, 188, &_18$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_17$$5, "setimagecompression", NULL, 0, &_19$$5);
			zephir_check_call_status();
		}
		if (quality >= 0) {
			if (quality < 1) {
				quality = 1;
			} else if (quality > 100) {
				quality = 100;
			}
			zephir_read_property(&_20$$6, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_21$$6, quality);
			ZEPHIR_CALL_METHOD(NULL, &_20$$6, "setimagecompressionquality", NULL, 0, &_21$$6);
			zephir_check_call_status();
		}
		zephir_read_property(&_22$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_22$$4, "writeimage", NULL, 0, &file);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a render.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _render) {

	zend_bool _8$$4;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *extension_param = NULL, *quality_param = NULL, image, _0, _1, _2, _3, _4, _6$$4, _7$$4, _9$$4, _12$$4, _10$$5, _11$$5;
	zval extension;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &extension_param, &quality_param);

	zephir_get_strval(&extension, extension_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_OBS_VAR(&image);
	zephir_read_property(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, &image, "setformat", NULL, 0, &extension);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &image, "setimageformat", NULL, 0, &extension);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &image, "stripimage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &image, "getimagetype", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_type"), &_0);
	ZEPHIR_CALL_METHOD(&_1, &image, "getimageformat", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "image/", &_1);
	zephir_update_property_zval(this_ptr, SL("_mime"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "gif");
	ZEPHIR_CALL_FUNCTION(&_4, "strcasecmp", &_5, 11, &extension, &_3);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(&_4, 0)) {
		ZEPHIR_CALL_METHOD(NULL, &image, "optimizeimagelayers", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "jpg");
		ZEPHIR_CALL_FUNCTION(&_7$$4, "strcasecmp", &_5, 11, &extension, &_6$$4);
		zephir_check_call_status();
		_8$$4 = ZEPHIR_IS_LONG_IDENTICAL(&_7$$4, 0);
		if (!(_8$$4)) {
			ZEPHIR_INIT_NVAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "jpeg");
			ZEPHIR_CALL_FUNCTION(&_9$$4, "strcasecmp", &_5, 11, &extension, &_6$$4);
			zephir_check_call_status();
			_8$$4 = ZEPHIR_IS_LONG_IDENTICAL(&_9$$4, 0);
		}
		if (_8$$4) {
			ZEPHIR_INIT_VAR(&_10$$5);
			ZVAL_STRING(&_10$$5, "Imagick::COMPRESSION_JPEG");
			ZEPHIR_CALL_FUNCTION(&_11$$5, "constant", NULL, 188, &_10$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &image, "setimagecompression", NULL, 0, &_11$$5);
			zephir_check_call_status();
		}
		ZVAL_LONG(&_12$$4, quality);
		ZEPHIR_CALL_METHOD(NULL, &image, "setimagecompressionquality", NULL, 0, &_12$$4);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(&image, "getimageblob", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Destroys the loaded image to free up resources.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __destruct) {

	zval _0, _1$$3, _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_image"), PH_NOISY_CC);
	if (zephir_instance_of_ev(&_0, zephir_get_internal_ce(SL("imagick")) TSRMLS_CC)) {
		zephir_read_property(&_1$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "clear", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "destroy", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get instance
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, getInternalImInstance) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_image");

}

/**
 * Sets the limit for a particular resource in megabytes
 *
 * @link http://php.net/manual/ru/imagick.constants.php#imagick.constants.resourcetypes
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, setResourceLimit) {

	zval *type_param = NULL, *limit_param = NULL, _0, _1, _2;
	zend_long type, limit, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &limit_param);

	type = zephir_get_intval(type_param);
	limit = zephir_get_intval(limit_param);


	zephir_read_property(&_0, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, type);
	ZVAL_LONG(&_2, limit);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setresourcelimit", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

