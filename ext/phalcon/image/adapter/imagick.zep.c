
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

	zval *_0, _1, _2, *_3 = NULL, *_6, _4$$5, *_5$$5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked") TSRMLS_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "imagick", 0);
	if (!(zephir_class_exists(&_1, 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick is not installed, or the extension is not loaded", "phalcon/image/adapter/imagick.zep", 55);
		return;
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "Imagick::IMAGICK_EXTNUM", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "defined", NULL, 37, &_2);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_SINIT_VAR(_4$$5);
		ZVAL_STRING(&_4$$5, "Imagick::IMAGICK_EXTNUM", 0);
		ZEPHIR_CALL_FUNCTION(&_5$$5, "constant", NULL, 38, &_4$$5);
		zephir_check_call_status();
		zephir_update_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_version"), &_5$$5 TSRMLS_CC);
	}
	zephir_update_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	_6 = zephir_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked") TSRMLS_CC);
	RETURN_CTOR(_6);

}

/**
 * \Phalcon\Image\Adapter\Imagick constructor
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __construct) {

	zend_bool _20$$8;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, *image = NULL, *_0, *_1, *_2, *_31, *_32 = NULL, *_33, *_34 = NULL, *_35, *_36 = NULL, *_37, *_38 = NULL, *_39, *_3$$4, *_4$$4 = NULL, *_5$$4, *_6$$4 = NULL, *_7$$4, *_11$$4, *_12$$4 = NULL, *_16$$4, *_8$$5, *_9$$5, *_10$$5, *_13$$6, _14$$6, *_15$$6 = NULL, *_17$$7, *_18$$7, *_19$$7, *_24$$8, *_25$$8, *_26$$8 = NULL, *_27$$8, *_28$$8, *_29$$8, *_30$$8, *_21$$9, *_22$$9, *_23$$9;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &file_param, &width_param, &height_param);

	if (UNEXPECTED(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(file, file_param);
	} else {
		ZEPHIR_INIT_VAR(file);
		ZVAL_EMPTY_STRING(file);
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


	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked") TSRMLS_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_SELF(NULL, "check", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(getThis(), SL("_file"), file TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_image"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
	if ((zephir_file_exists(_2 TSRMLS_CC) == SUCCESS)) {
		_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_4$$4, "realpath", NULL, 67, _3$$4);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_realpath"), _4$$4 TSRMLS_CC);
		_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_7$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_realpath"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_6$$4, _5$$4, "readimage", NULL, 0, _7$$4);
		zephir_check_call_status();
		if (!(zephir_is_true(_6$$4))) {
			ZEPHIR_INIT_VAR(_8$$5);
			object_init_ex(_8$$5, phalcon_image_exception_ce);
			_9$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_10$$5);
			ZEPHIR_CONCAT_SVS(_10$$5, "Imagick::readImage ", _9$$5, " failed");
			ZEPHIR_CALL_METHOD(NULL, _8$$5, "__construct", NULL, 9, _10$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_8$$5, "phalcon/image/adapter/imagick.zep", 86 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_11$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_12$$4, _11$$4, "getimagealphachannel", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_12$$4))) {
			_13$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_14$$6);
			ZVAL_STRING(&_14$$6, "Imagick::ALPHACHANNEL_SET", 0);
			ZEPHIR_CALL_FUNCTION(&_15$$6, "constant", NULL, 38, &_14$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _13$$6, "setimagealphachannel", NULL, 0, _15$$6);
			zephir_check_call_status();
		}
		_16$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		if (ZEPHIR_IS_LONG(_16$$4, 1)) {
			_17$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&image, _17$$7, "coalesceimages", NULL, 0);
			zephir_check_call_status();
			_18$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _18$$7, "clear", NULL, 0);
			zephir_check_call_status();
			_19$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _19$$7, "destroy", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_this(getThis(), SL("_image"), image TSRMLS_CC);
		}
	} else {
		_20$$8 = !width;
		if (!(_20$$8)) {
			_20$$8 = !height;
		}
		if (_20$$8) {
			ZEPHIR_INIT_VAR(_21$$9);
			object_init_ex(_21$$9, phalcon_image_exception_ce);
			_22$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_23$$9);
			ZEPHIR_CONCAT_SV(_23$$9, "Failed to create image from file ", _22$$9);
			ZEPHIR_CALL_METHOD(NULL, _21$$9, "__construct", NULL, 9, _23$$9);
			zephir_check_call_status();
			zephir_throw_exception_debug(_21$$9, "phalcon/image/adapter/imagick.zep", 102 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_24$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_25$$8);
		object_init_ex(_25$$8, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_26$$8);
		ZVAL_STRING(_26$$8, "transparent", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _25$$8, "__construct", NULL, 0, _26$$8);
		zephir_check_temp_parameter(_26$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_26$$8);
		ZVAL_LONG(_26$$8, width);
		ZEPHIR_INIT_VAR(_27$$8);
		ZVAL_LONG(_27$$8, height);
		ZEPHIR_CALL_METHOD(NULL, _24$$8, "newimage", NULL, 0, _26$$8, _27$$8, _25$$8);
		zephir_check_call_status();
		_28$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_26$$8);
		ZVAL_STRING(_26$$8, "png", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _28$$8, "setformat", NULL, 0, _26$$8);
		zephir_check_temp_parameter(_26$$8);
		zephir_check_call_status();
		_29$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_26$$8);
		ZVAL_STRING(_26$$8, "png", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _29$$8, "setimageformat", NULL, 0, _26$$8);
		zephir_check_temp_parameter(_26$$8);
		zephir_check_call_status();
		_30$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		zephir_update_property_this(getThis(), SL("_realpath"), _30$$8 TSRMLS_CC);
	}
	_31 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_32, _31, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_width"), _32 TSRMLS_CC);
	_33 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_34, _33, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_height"), _34 TSRMLS_CC);
	_35 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_36, _35, "getimagetype", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_type"), _36 TSRMLS_CC);
	_37 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_38, _37, "getimageformat", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_39);
	ZEPHIR_CONCAT_SV(_39, "image/", _38);
	zephir_update_property_this(getThis(), SL("_mime"), _39 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a resize.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _resize) {

	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	zval *width_param = NULL, *height_param = NULL, *image = NULL, *_0, *_6 = NULL, *_7 = NULL, *_1$$3 = NULL, *_2$$3 = NULL, *_4$$3 = NULL;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	ZEPHIR_OBS_VAR(image);
	zephir_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_CALL_METHOD(NULL, image, "setiteratorindex", NULL, 0, _0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_LONG(_1$$3, width);
		ZEPHIR_INIT_NVAR(_2$$3);
		ZVAL_LONG(_2$$3, height);
		ZEPHIR_CALL_METHOD(NULL, image, "scaleimage", &_3, 0, _1$$3, _2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, image, "nextimage", &_5, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_4$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(&_6, image, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_width"), _6 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_7, image, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_height"), _7 TSRMLS_CC);
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
	zval *width_param = NULL, *height_param = NULL, *deltaX_param = NULL, *rigidity_param = NULL, *ret = NULL, *image = NULL, *_0, *_8 = NULL, *_9 = NULL, *_1$$3 = NULL, *_2$$3 = NULL, *_3$$3 = NULL, *_4$$3 = NULL, *_6$$3 = NULL;
	zend_long width, height, deltaX, rigidity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &deltaX_param, &rigidity_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	deltaX = zephir_get_intval(deltaX_param);
	rigidity = zephir_get_intval(rigidity_param);


	ZEPHIR_OBS_VAR(image);
	zephir_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_CALL_METHOD(NULL, image, "setiteratorindex", NULL, 0, _0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_LONG(_1$$3, width);
		ZEPHIR_INIT_NVAR(_2$$3);
		ZVAL_LONG(_2$$3, height);
		ZEPHIR_INIT_NVAR(_3$$3);
		ZVAL_LONG(_3$$3, deltaX);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_LONG(_4$$3, rigidity);
		ZEPHIR_CALL_METHOD(&ret, image, "liquidrescaleimage", &_5, 0, _1$$3, _2$$3, _3$$3, _4$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::liquidRescale failed", "phalcon/image/adapter/imagick.zep", 157);
			return;
		}
		ZEPHIR_CALL_METHOD(&_6$$3, image, "nextimage", &_7, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_6$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(&_8, image, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_width"), _8 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_9, image, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_height"), _9 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a crop.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _crop) {

	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_8 = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, *image = NULL, *_0, *_9 = NULL, *_10 = NULL, *_1$$3 = NULL, *_2$$3 = NULL, *_3$$3 = NULL, *_4$$3 = NULL, *_7$$3 = NULL;
	zend_long width, height, offsetX, offsetY, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &offsetX_param, &offsetY_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);


	ZEPHIR_OBS_VAR(image);
	zephir_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_CALL_METHOD(NULL, image, "setiteratorindex", NULL, 0, _0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_LONG(_1$$3, width);
		ZEPHIR_INIT_NVAR(_2$$3);
		ZVAL_LONG(_2$$3, height);
		ZEPHIR_INIT_NVAR(_3$$3);
		ZVAL_LONG(_3$$3, offsetX);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_LONG(_4$$3, offsetY);
		ZEPHIR_CALL_METHOD(NULL, image, "cropimage", &_5, 0, _1$$3, _2$$3, _3$$3, _4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_LONG(_1$$3, width);
		ZEPHIR_INIT_NVAR(_2$$3);
		ZVAL_LONG(_2$$3, height);
		ZEPHIR_INIT_NVAR(_3$$3);
		ZVAL_LONG(_3$$3, 0);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_LONG(_4$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, image, "setimagepage", &_6, 0, _1$$3, _2$$3, _3$$3, _4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$3, image, "nextimage", &_8, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_7$$3))) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(&_9, image, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_width"), _9 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_10, image, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_height"), _10 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a rotation.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _rotate) {

	zval *degrees_param = NULL, *pixel = NULL, *_0, *_1, *_10, *_11 = NULL, *_12, *_13 = NULL, *_2$$3, *_3$$3 = NULL, *_4$$3, *_5$$3, *_6$$3, *_7$$3 = NULL, *_8$$3, *_9$$3 = NULL;
	zend_long degrees, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);

	degrees = zephir_get_intval(degrees_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, _0, "setiteratorindex", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(pixel);
	object_init_ex(pixel, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, pixel, "__construct", NULL, 0);
	zephir_check_call_status();
	while (1) {
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3$$3);
		ZVAL_LONG(_3$$3, degrees);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "rotateimage", NULL, 0, pixel, _3$$3);
		zephir_check_call_status();
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_6$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3$$3);
		ZVAL_LONG(_3$$3, 0);
		ZEPHIR_INIT_NVAR(_7$$3);
		ZVAL_LONG(_7$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "setimagepage", NULL, 0, _5$$3, _6$$3, _3$$3, _7$$3);
		zephir_check_call_status();
		_8$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_9$$3, _8$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_9$$3)) {
			break;
		}
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_11, _10, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_width"), _11 TSRMLS_CC);
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_13, _12, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_height"), _13 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a flip.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _flip) {

	zval *direction_param = NULL, *func = NULL, *_0, *_1, *_2$$4, *_3$$4, *_4$$4 = NULL;
	zend_long direction, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

	direction = zephir_get_intval(direction_param);


	ZEPHIR_INIT_VAR(func);
	ZVAL_STRING(func, "flipImage", 1);
	if (direction == 11) {
		ZEPHIR_INIT_NVAR(func);
		ZVAL_STRING(func, "flopImage", 1);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, _0, "setiteratorindex", NULL, 0, _1);
	zephir_check_call_status();
	while (1) {
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, _2$$4, func, NULL, 0);
		zephir_check_call_status();
		_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_4$$4, _3$$4, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_4$$4)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a sharpen.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _sharpen) {

	zval *amount_param = NULL, *_0 = NULL, *_1, *_2, *_3$$3, *_4$$3 = NULL, *_5$$3 = NULL, *_6$$3, *_7$$3 = NULL;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	ZEPHIR_INIT_VAR(_0);
	if (amount < 5) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 5);
	} else {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, amount);
	}
	amount = zephir_get_numberval(_0);
	amount = (long) (zephir_safe_div_long_long(((amount * 3.0)), 100 TSRMLS_CC));
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "setiteratorindex", NULL, 0, _2);
	zephir_check_call_status();
	while (1) {
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_LONG(_4$$3, 0);
		ZEPHIR_INIT_NVAR(_5$$3);
		ZVAL_LONG(_5$$3, amount);
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "sharpenimage", NULL, 0, _4$$3, _5$$3);
		zephir_check_call_status();
		_6$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_7$$3, _6$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_7$$3)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a reflection.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _reflection) {

	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_11 = NULL, *_13 = NULL, *_14 = NULL, *_16 = NULL, *_21 = NULL, *_24 = NULL, *_27 = NULL, *_29 = NULL, *_35 = NULL, *_38 = NULL, *_41 = NULL, *_44 = NULL, *_48 = NULL, *_56 = NULL;
	zend_bool fadeIn, _57$$13;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, *reflection = NULL, *fade = NULL, *pseudo = NULL, *image = NULL, *pixel = NULL, *ret = NULL, *_0, *_4 = NULL, *_17 = NULL, *_18 = NULL, *_30, *_31 = NULL, *_32, *_59, *_60, *_61, *_62 = NULL, *_63, *_64 = NULL, *_1$$3, *_2$$4, *_3$$4 = NULL, *_6$$5 = NULL, *_8$$5 = NULL, *_9$$5 = NULL, *_10$$5 = NULL, *_12$$5 = NULL, *_15$$5 = NULL, _19$$7 = zval_used_for_init, *_20$$7 = NULL, *_22$$7 = NULL, *_23$$7 = NULL, *_25$$7 = NULL, *_26$$7 = NULL, *_28$$7 = NULL, *_33$$10, *_34$$10 = NULL, _36$$10 = zval_used_for_init, *_37$$10 = NULL, *_39$$10, *_40$$10 = NULL, *_42$$10, *_43$$10 = NULL, *_45$$10, *_46$$10 = NULL, *_47$$10 = NULL, *_49$$10, *_50$$10 = NULL, _51$$13 = zval_used_for_init, *_52$$13 = NULL, *_53$$13, *_54$$13 = NULL, *_55$$13 = NULL, *_58$$13 = NULL;
	zend_long height, opacity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &height_param, &opacity_param, &fadeIn_param);

	height = zephir_get_intval(height_param);
	opacity = zephir_get_intval(opacity_param);
	fadeIn = zephir_get_boolval(fadeIn_param);


	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_version") TSRMLS_CC);
	ZEPHIR_INIT_VAR(reflection);
	if (ZEPHIR_GE_LONG(_0, 30100)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		if (zephir_clone(reflection, _1$$3 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
	} else {
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_3$$4, _2$$4, "clone", NULL, 0);
		zephir_check_call_status();
		if (zephir_clone(reflection, _3$$4 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, 0);
	ZEPHIR_CALL_METHOD(NULL, reflection, "setiteratorindex", NULL, 0, _4);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(NULL, reflection, "flipimage", &_5, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$5, reflection, "getimagewidth", &_7, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_8$$5);
		ZVAL_LONG(_8$$5, height);
		ZEPHIR_INIT_NVAR(_9$$5);
		ZVAL_LONG(_9$$5, 0);
		ZEPHIR_INIT_NVAR(_10$$5);
		ZVAL_LONG(_10$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, reflection, "cropimage", &_11, 0, _6$$5, _8$$5, _9$$5, _10$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_12$$5, reflection, "getimagewidth", &_13, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_8$$5);
		ZVAL_LONG(_8$$5, height);
		ZEPHIR_INIT_NVAR(_9$$5);
		ZVAL_LONG(_9$$5, 0);
		ZEPHIR_INIT_NVAR(_10$$5);
		ZVAL_LONG(_10$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, reflection, "setimagepage", &_14, 0, _12$$5, _8$$5, _9$$5, _10$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_15$$5, reflection, "nextimage", &_16, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_15$$5)) {
			break;
		}
	}
	if (fadeIn) {
		ZEPHIR_INIT_VAR(pseudo);
		ZVAL_STRING(pseudo, "gradient:black-transparent", 1);
	} else {
		ZEPHIR_INIT_NVAR(pseudo);
		ZVAL_STRING(pseudo, "gradient:transparent-black", 1);
	}
	ZEPHIR_INIT_VAR(fade);
	object_init_ex(fade, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, fade, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_17, reflection, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_18, reflection, "getimageheight", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, fade, "newpseudoimage", NULL, 0, _17, _18, pseudo);
	zephir_check_call_status();
	opacity /= 100;
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 0);
	ZEPHIR_CALL_METHOD(NULL, reflection, "setiteratorindex", NULL, 0, _4);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_SINIT_NVAR(_19$$7);
		ZVAL_STRING(&_19$$7, "Imagick::COMPOSITE_DSTOUT", 0);
		ZEPHIR_CALL_FUNCTION(&_20$$7, "constant", &_21, 38, &_19$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_22$$7);
		ZVAL_LONG(_22$$7, 0);
		ZEPHIR_INIT_NVAR(_23$$7);
		ZVAL_LONG(_23$$7, 0);
		ZEPHIR_CALL_METHOD(&ret, reflection, "compositeimage", &_24, 0, fade, _20$$7, _22$$7, _23$$7);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 292);
			return;
		}
		ZEPHIR_SINIT_NVAR(_19$$7);
		ZVAL_STRING(&_19$$7, "Imagick::EVALUATE_MULTIPLY", 0);
		ZEPHIR_CALL_FUNCTION(&_25$$7, "constant", &_21, 38, &_19$$7);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_19$$7);
		ZVAL_STRING(&_19$$7, "Imagick::CHANNEL_ALPHA", 0);
		ZEPHIR_CALL_FUNCTION(&_26$$7, "constant", &_21, 38, &_19$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_22$$7);
		ZVAL_LONG(_22$$7, opacity);
		ZEPHIR_CALL_METHOD(NULL, reflection, "evaluateimage", &_27, 0, _25$$7, _22$$7, _26$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_28$$7, reflection, "nextimage", &_29, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_28$$7)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, fade, "destroy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(image);
	object_init_ex(image, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, image, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(pixel);
	object_init_ex(pixel, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, pixel, "__construct", NULL, 0);
	zephir_check_call_status();
	_30 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_31, _30, "getimageheight", NULL, 0);
	zephir_check_call_status();
	height = (zephir_get_numberval(_31) + height);
	_32 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 0);
	ZEPHIR_CALL_METHOD(NULL, _32, "setiteratorindex", NULL, 0, _4);
	zephir_check_call_status();
	while (1) {
		_33$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_34$$10);
		ZVAL_LONG(_34$$10, height);
		ZEPHIR_CALL_METHOD(NULL, image, "newimage", &_35, 0, _33$$10, _34$$10, pixel);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_36$$10);
		ZVAL_STRING(&_36$$10, "Imagick::ALPHACHANNEL_SET", 0);
		ZEPHIR_CALL_FUNCTION(&_37$$10, "constant", &_21, 38, &_36$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, image, "setimagealphachannel", &_38, 0, _37$$10);
		zephir_check_call_status();
		_39$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_40$$10, _39$$10, "getcolorspace", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, image, "setcolorspace", &_41, 0, _40$$10);
		zephir_check_call_status();
		_42$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_43$$10, _42$$10, "getimagedelay", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, image, "setimagedelay", &_44, 0, _43$$10);
		zephir_check_call_status();
		_45$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_36$$10);
		ZVAL_STRING(&_36$$10, "Imagick::COMPOSITE_SRC", 0);
		ZEPHIR_CALL_FUNCTION(&_46$$10, "constant", &_21, 38, &_36$$10);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_34$$10);
		ZVAL_LONG(_34$$10, 0);
		ZEPHIR_INIT_NVAR(_47$$10);
		ZVAL_LONG(_47$$10, 0);
		ZEPHIR_CALL_METHOD(&ret, image, "compositeimage", &_48, 0, _45$$10, _46$$10, _34$$10, _47$$10);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 317);
			return;
		}
		_49$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_50$$10, _49$$10, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_50$$10)) {
			break;
		}
	}
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 0);
	ZEPHIR_CALL_METHOD(NULL, image, "setiteratorindex", NULL, 0, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 0);
	ZEPHIR_CALL_METHOD(NULL, reflection, "setiteratorindex", NULL, 0, _4);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_SINIT_NVAR(_51$$13);
		ZVAL_STRING(&_51$$13, "Imagick::COMPOSITE_OVER", 0);
		ZEPHIR_CALL_FUNCTION(&_52$$13, "constant", &_21, 38, &_51$$13);
		zephir_check_call_status();
		_53$$13 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_54$$13);
		ZVAL_LONG(_54$$13, 0);
		ZEPHIR_CALL_METHOD(&ret, image, "compositeimage", &_48, 0, reflection, _52$$13, _54$$13, _53$$13);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 332);
			return;
		}
		ZEPHIR_CALL_METHOD(&_55$$13, image, "nextimage", &_56, 0);
		zephir_check_call_status();
		_57$$13 = ZEPHIR_IS_FALSE_IDENTICAL(_55$$13);
		if (!(_57$$13)) {
			ZEPHIR_CALL_METHOD(&_58$$13, reflection, "nextimage", NULL, 0);
			zephir_check_call_status();
			_57$$13 = ZEPHIR_IS_FALSE_IDENTICAL(_58$$13);
		}
		if (_57$$13) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, reflection, "destroy", NULL, 0);
	zephir_check_call_status();
	_59 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _59, "clear", NULL, 0);
	zephir_check_call_status();
	_60 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _60, "destroy", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_image"), image TSRMLS_CC);
	_61 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_62, _61, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_width"), _62 TSRMLS_CC);
	_63 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_64, _63, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_height"), _64 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a watermarking.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _watermark) {

	zephir_fcall_cache_entry *_7 = NULL;
	zend_long offsetX, offsetY, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *image, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, *watermark = NULL, *ret = NULL, *version = NULL, *method = NULL, *_1 = NULL, *_2 = NULL, *_3, *_0$$3, *_4$$5, _5$$5 = zval_used_for_init, *_6$$5 = NULL, *_8$$5 = NULL, *_9$$5 = NULL, *_10$$5, *_11$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &image, &offsetX_param, &offsetY_param, &opacity_param);

	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);


	opacity = (long) (zephir_safe_div_long_long(opacity, 100 TSRMLS_CC));
	ZEPHIR_INIT_VAR(watermark);
	object_init_ex(watermark, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, watermark, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(method);
	ZVAL_STRING(method, "setImageOpacity", 1);
	if (EXPECTED((zephir_method_exists_ex(watermark, SS("getversion") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_CALL_METHOD(&version, watermark, "getversion", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_string(&_0$$3, version, SL("versionNumber"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/imagick.zep", 365 TSRMLS_CC);
		if (ZEPHIR_GE_LONG(_0$$3, 0x700)) {
			ZEPHIR_INIT_NVAR(method);
			ZVAL_STRING(method, "setImageAlpha", 1);
		}
	}
	ZEPHIR_CALL_METHOD(&_1, image, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, watermark, "readimageblob", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, opacity);
	ZEPHIR_CALL_METHOD_ZVAL(NULL, watermark, method, NULL, 0, _2);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_METHOD(NULL, _3, "setiteratorindex", NULL, 0, _2);
	zephir_check_call_status();
	while (1) {
		_4$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_5$$5);
		ZVAL_STRING(&_5$$5, "Imagick::COMPOSITE_OVER", 0);
		ZEPHIR_CALL_FUNCTION(&_6$$5, "constant", &_7, 38, &_5$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_8$$5);
		ZVAL_LONG(_8$$5, offsetX);
		ZEPHIR_INIT_NVAR(_9$$5);
		ZVAL_LONG(_9$$5, offsetY);
		ZEPHIR_CALL_METHOD(&ret, _4$$5, "compositeimage", NULL, 0, watermark, _6$$5, _8$$5, _9$$5);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 379);
			return;
		}
		_10$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_11$$5, _10$$5, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_11$$5)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, watermark, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, watermark, "destroy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a text
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _text) {

	zend_bool _7$$7;
	zend_long opacity, r, g, b, size, ZEPHIR_LAST_CALL_STATUS, x = 0, y = 0;
	zval *text_param = NULL, *offsetX = NULL, *offsetY = NULL, *opacity_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *size_param = NULL, *fontfile_param = NULL, *draw = NULL, *color = NULL, *gravity = NULL, _0, _1, _2, _3, *_4, *_24, *_25, *_5$$4, *_6$$5, _8$$8, _9$$10, _10$$12, _11$$13, _12$$17, _13$$18, _14$$20, _15$$21, _16$$27, _17$$28, _18$$30, _19$$31, _20$$35, _21$$36, _22$$38, _23$$39, *_26$$40, *_27$$40 = NULL, *_28$$40, *_29$$40 = NULL;
	zval *text = NULL, *fontfile = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 9, 0, &text_param, &offsetX, &offsetY, &opacity_param, &r_param, &g_param, &b_param, &size_param, &fontfile_param);

	zephir_get_strval(text, text_param);
	ZEPHIR_SEPARATE_PARAM(offsetX);
	ZEPHIR_SEPARATE_PARAM(offsetY);
	opacity = zephir_get_intval(opacity_param);
	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	size = zephir_get_intval(size_param);
	zephir_get_strval(fontfile, fontfile_param);


	opacity = (long) (zephir_safe_div_long_long(opacity, 100 TSRMLS_CC));
	ZEPHIR_INIT_VAR(draw);
	object_init_ex(draw, zephir_get_internal_ce(SS("imagickdraw") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, draw, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "rgb(%d, %d, %d)", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, r);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, g);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, b);
	ZEPHIR_CALL_FUNCTION(&color, "sprintf", NULL, 164, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	object_init_ex(_4, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 0, color);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, draw, "setfillcolor", NULL, 0, _4);
	zephir_check_call_status();
	if (!(!fontfile) && Z_STRLEN_P(fontfile)) {
		ZEPHIR_CALL_METHOD(NULL, draw, "setfont", NULL, 0, fontfile);
		zephir_check_call_status();
	}
	if (size) {
		ZEPHIR_INIT_VAR(_5$$4);
		ZVAL_LONG(_5$$4, size);
		ZEPHIR_CALL_METHOD(NULL, draw, "setfontsize", NULL, 0, _5$$4);
		zephir_check_call_status();
	}
	if (opacity) {
		ZEPHIR_INIT_VAR(_6$$5);
		ZVAL_LONG(_6$$5, opacity);
		ZEPHIR_CALL_METHOD(NULL, draw, "setfillopacity", NULL, 0, _6$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(gravity);
	ZVAL_NULL(gravity);
	if (Z_TYPE_P(offsetX) == IS_BOOL) {
		if (Z_TYPE_P(offsetY) == IS_BOOL) {
			ZEPHIR_INIT_NVAR(offsetX);
			ZVAL_LONG(offsetX, 0);
			ZEPHIR_INIT_NVAR(offsetY);
			ZVAL_LONG(offsetY, 0);
			_7$$7 = zephir_is_true(offsetX);
			if (_7$$7) {
				_7$$7 = zephir_is_true(offsetY);
			}
			if (_7$$7) {
				ZEPHIR_SINIT_VAR(_8$$8);
				ZVAL_STRING(&_8$$8, "Imagick::GRAVITY_SOUTHEAST", 0);
				ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_8$$8);
				zephir_check_call_status();
			} else {
				if (zephir_is_true(offsetX)) {
					ZEPHIR_SINIT_VAR(_9$$10);
					ZVAL_STRING(&_9$$10, "Imagick::GRAVITY_EAST", 0);
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_9$$10);
					zephir_check_call_status();
				} else {
					if (zephir_is_true(offsetY)) {
						ZEPHIR_SINIT_VAR(_10$$12);
						ZVAL_STRING(&_10$$12, "Imagick::GRAVITY_SOUTH", 0);
						ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_10$$12);
						zephir_check_call_status();
					} else {
						ZEPHIR_SINIT_VAR(_11$$13);
						ZVAL_STRING(&_11$$13, "Imagick::GRAVITY_CENTER", 0);
						ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_11$$13);
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
						ZEPHIR_SINIT_VAR(_12$$17);
						ZVAL_STRING(&_12$$17, "Imagick::GRAVITY_SOUTHEAST", 0);
						ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_12$$17);
						zephir_check_call_status();
					} else {
						ZVAL_LONG(offsetX, 0);
						ZEPHIR_SINIT_VAR(_13$$18);
						ZVAL_STRING(&_13$$18, "Imagick::GRAVITY_NORTHEAST", 0);
						ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_13$$18);
						zephir_check_call_status();
					}
				} else {
					ZEPHIR_INIT_NVAR(offsetX);
					if (y < 0) {
						ZVAL_LONG(offsetX, 0);
						ZEPHIR_INIT_NVAR(offsetY);
						ZVAL_LONG(offsetY, (y * -1));
						ZEPHIR_SINIT_VAR(_14$$20);
						ZVAL_STRING(&_14$$20, "Imagick::GRAVITY_SOUTH", 0);
						ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_14$$20);
						zephir_check_call_status();
					} else {
						ZVAL_LONG(offsetX, 0);
						ZEPHIR_SINIT_VAR(_15$$21);
						ZVAL_STRING(&_15$$21, "Imagick::GRAVITY_NORTH", 0);
						ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_15$$21);
						zephir_check_call_status();
					}
				}
			}
		}
	} else {
		if (Z_TYPE_P(offsetX) == IS_LONG) {
			x = zephir_get_intval(offsetX);
			if (zephir_is_true(offsetX)) {
				if (Z_TYPE_P(offsetY) == IS_BOOL) {
					if (zephir_is_true(offsetY)) {
						ZEPHIR_INIT_NVAR(offsetY);
						if (x < 0) {
							ZEPHIR_INIT_NVAR(offsetX);
							ZVAL_LONG(offsetX, (x * -1));
							ZVAL_LONG(offsetY, 0);
							ZEPHIR_SINIT_VAR(_16$$27);
							ZVAL_STRING(&_16$$27, "Imagick::GRAVITY_SOUTHEAST", 0);
							ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_16$$27);
							zephir_check_call_status();
						} else {
							ZVAL_LONG(offsetY, 0);
							ZEPHIR_SINIT_VAR(_17$$28);
							ZVAL_STRING(&_17$$28, "Imagick::GRAVITY_SOUTH", 0);
							ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_17$$28);
							zephir_check_call_status();
						}
					} else {
						ZEPHIR_INIT_NVAR(offsetY);
						if (x < 0) {
							ZEPHIR_INIT_NVAR(offsetX);
							ZVAL_LONG(offsetX, (x * -1));
							ZVAL_LONG(offsetY, 0);
							ZEPHIR_SINIT_VAR(_18$$30);
							ZVAL_STRING(&_18$$30, "Imagick::GRAVITY_EAST", 0);
							ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_18$$30);
							zephir_check_call_status();
						} else {
							ZVAL_LONG(offsetY, 0);
							ZEPHIR_SINIT_VAR(_19$$31);
							ZVAL_STRING(&_19$$31, "Imagick::GRAVITY_WEST", 0);
							ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_19$$31);
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
								ZEPHIR_SINIT_VAR(_20$$35);
								ZVAL_STRING(&_20$$35, "Imagick::GRAVITY_SOUTHEAST", 0);
								ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_20$$35);
								zephir_check_call_status();
							} else {
								ZVAL_LONG(offsetX, (x * -1));
								ZEPHIR_SINIT_VAR(_21$$36);
								ZVAL_STRING(&_21$$36, "Imagick::GRAVITY_NORTHEAST", 0);
								ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_21$$36);
								zephir_check_call_status();
							}
						} else {
							ZEPHIR_INIT_NVAR(offsetX);
							if (y < 0) {
								ZVAL_LONG(offsetX, 0);
								ZEPHIR_INIT_NVAR(offsetY);
								ZVAL_LONG(offsetY, (y * -1));
								ZEPHIR_SINIT_VAR(_22$$38);
								ZVAL_STRING(&_22$$38, "Imagick::GRAVITY_SOUTHWEST", 0);
								ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_22$$38);
								zephir_check_call_status();
							} else {
								ZVAL_LONG(offsetX, 0);
								ZEPHIR_SINIT_VAR(_23$$39);
								ZVAL_STRING(&_23$$39, "Imagick::GRAVITY_NORTHWEST", 0);
								ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 38, &_23$$39);
								zephir_check_call_status();
							}
						}
					}
				}
			}
		}
	}
	ZEPHIR_CALL_METHOD(NULL, draw, "setgravity", NULL, 0, gravity);
	zephir_check_call_status();
	_24 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_25);
	ZVAL_LONG(_25, 0);
	ZEPHIR_CALL_METHOD(NULL, _24, "setiteratorindex", NULL, 0, _25);
	zephir_check_call_status();
	while (1) {
		_26$$40 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_27$$40);
		ZVAL_LONG(_27$$40, 0);
		ZEPHIR_CALL_METHOD(NULL, _26$$40, "annotateimage", NULL, 0, draw, offsetX, offsetY, _27$$40, text);
		zephir_check_call_status();
		_28$$40 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_29$$40, _28$$40, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_29$$40)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, draw, "destroy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Composite one image onto another
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _mask) {

	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *image, *mask = NULL, *ret = NULL, *_0 = NULL, *_1, *_2, *_3$$3, *_4$$3 = NULL, *_5$$3, _6$$3 = zval_used_for_init, *_7$$3 = NULL, *_9$$3 = NULL, *_10$$3, *_11$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &image);



	ZEPHIR_INIT_VAR(mask);
	object_init_ex(mask, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, mask, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, image, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, mask, "readimageblob", NULL, 0, _0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "setiteratorindex", NULL, 0, _2);
	zephir_check_call_status();
	while (1) {
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_LONG(_4$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "setimagematte", NULL, 0, _4$$3);
		zephir_check_call_status();
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_6$$3);
		ZVAL_STRING(&_6$$3, "Imagick::COMPOSITE_DSTIN", 0);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "constant", &_8, 38, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_LONG(_4$$3, 0);
		ZEPHIR_INIT_NVAR(_9$$3);
		ZVAL_LONG(_9$$3, 0);
		ZEPHIR_CALL_METHOD(&ret, _5$$3, "compositeimage", NULL, 0, mask, _7$$3, _4$$3, _9$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 544);
			return;
		}
		_10$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_11$$3, _10$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_11$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, mask, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, mask, "destroy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a background.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _background) {

	zephir_fcall_cache_entry *_8 = NULL, *_10 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_20 = NULL, *_23 = NULL, *_27 = NULL;
	zval *r_param = NULL, *g_param = NULL, *b_param = NULL, *opacity_param = NULL, *background = NULL, *color = NULL, *pixel1 = NULL, *pixel2 = NULL, *ret = NULL, _0, _1, _2, _3, *_4 = NULL, *_5, *_30, *_31, *_6$$3, *_7$$3, *_9$$3 = NULL, _16$$3 = zval_used_for_init, *_17$$3 = NULL, *_18$$3 = NULL, *_19$$3 = NULL, *_21$$3, *_22$$3 = NULL, *_24$$3, *_25$$3 = NULL, *_26$$3 = NULL, *_28$$3, *_29$$3 = NULL, _11$$4 = zval_used_for_init, *_12$$4 = NULL;
	zend_long r, g, b, opacity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &r_param, &g_param, &b_param, &opacity_param);

	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	opacity = zephir_get_intval(opacity_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "rgb(%d, %d, %d)", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, r);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, g);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, b);
	ZEPHIR_CALL_FUNCTION(&color, "sprintf", NULL, 164, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(pixel1);
	object_init_ex(pixel1, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, pixel1, "__construct", NULL, 0, color);
	zephir_check_call_status();
	opacity = (long) (zephir_safe_div_long_long(opacity, 100 TSRMLS_CC));
	ZEPHIR_INIT_VAR(pixel2);
	object_init_ex(pixel2, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "transparent", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, pixel2, "__construct", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(background);
	object_init_ex(background, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, background, "__construct", NULL, 0);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 0);
	ZEPHIR_CALL_METHOD(NULL, _5, "setiteratorindex", NULL, 0, _4);
	zephir_check_call_status();
	while (1) {
		_6$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_7$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, background, "newimage", &_8, 0, _6$$3, _7$$3, pixel1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_9$$3, background, "getimagealphachannel", &_10, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_9$$3))) {
			ZEPHIR_SINIT_NVAR(_11$$4);
			ZVAL_STRING(&_11$$4, "Imagick::ALPHACHANNEL_SET", 0);
			ZEPHIR_CALL_FUNCTION(&_12$$4, "constant", &_13, 38, &_11$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, background, "setimagealphachannel", &_14, 0, _12$$4);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, background, "setimagebackgroundcolor", &_15, 0, pixel2);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_16$$3);
		ZVAL_STRING(&_16$$3, "Imagick::EVALUATE_MULTIPLY", 0);
		ZEPHIR_CALL_FUNCTION(&_17$$3, "constant", &_13, 38, &_16$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_16$$3);
		ZVAL_STRING(&_16$$3, "Imagick::CHANNEL_ALPHA", 0);
		ZEPHIR_CALL_FUNCTION(&_18$$3, "constant", &_13, 38, &_16$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_19$$3);
		ZVAL_LONG(_19$$3, opacity);
		ZEPHIR_CALL_METHOD(NULL, background, "evaluateimage", &_20, 0, _17$$3, _19$$3, _18$$3);
		zephir_check_call_status();
		_21$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_22$$3, _21$$3, "getcolorspace", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, background, "setcolorspace", &_23, 0, _22$$3);
		zephir_check_call_status();
		_24$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_16$$3);
		ZVAL_STRING(&_16$$3, "Imagick::COMPOSITE_DISSOLVE", 0);
		ZEPHIR_CALL_FUNCTION(&_25$$3, "constant", &_13, 38, &_16$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_19$$3);
		ZVAL_LONG(_19$$3, 0);
		ZEPHIR_INIT_NVAR(_26$$3);
		ZVAL_LONG(_26$$3, 0);
		ZEPHIR_CALL_METHOD(&ret, background, "compositeimage", &_27, 0, _24$$3, _25$$3, _19$$3, _26$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 583);
			return;
		}
		_28$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_29$$3, _28$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_29$$3)) {
			break;
		}
	}
	_30 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _30, "clear", NULL, 0);
	zephir_check_call_status();
	_31 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _31, "destroy", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_image"), background TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Blur image
 *
 * @param int $radius Blur radius
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _blur) {

	zval *radius_param = NULL, *_0, *_1, *_2$$3, *_3$$3 = NULL, *_4$$3 = NULL, *_5$$3, *_6$$3 = NULL;
	zend_long radius, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);

	radius = zephir_get_intval(radius_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, _0, "setiteratorindex", NULL, 0, _1);
	zephir_check_call_status();
	while (1) {
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3$$3);
		ZVAL_LONG(_3$$3, radius);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_LONG(_4$$3, 100);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "blurimage", NULL, 0, _3$$3, _4$$3);
		zephir_check_call_status();
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_6$$3, _5$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_6$$3)) {
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

	zval *amount_param = NULL, *_0, *_1, *_2, *_3, *_4$$3, *_5$$3 = NULL, *_6$$3 = NULL, *_7$$3, *_8$$3, *_9$$3, *_10$$3, *_11$$3 = NULL;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS, width = 0, height = 0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	width = (long) (zephir_safe_div_zval_long(_0, amount TSRMLS_CC));
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	height = (long) (zephir_safe_div_zval_long(_1, amount TSRMLS_CC));
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(NULL, _2, "setiteratorindex", NULL, 0, _3);
	zephir_check_call_status();
	while (1) {
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_5$$3);
		ZVAL_LONG(_5$$3, width);
		ZEPHIR_INIT_NVAR(_6$$3);
		ZVAL_LONG(_6$$3, height);
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "scaleimage", NULL, 0, _5$$3, _6$$3);
		zephir_check_call_status();
		_7$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_8$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_9$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _7$$3, "scaleimage", NULL, 0, _8$$3, _9$$3);
		zephir_check_call_status();
		_10$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_11$$3, _10$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_11$$3)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a save.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _save) {

	zend_bool _14$$4;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality_param = NULL, *ext = NULL, *fp = NULL, _0 = zval_used_for_init, *_1, *_2, *_3, *_4 = NULL, *_5, *_6 = NULL, *_7, *_8 = NULL, *_9$$3, _10$$3, *_11$$3, _12$$4 = zval_used_for_init, *_13$$4 = NULL, *_15$$4 = NULL, *_21$$4, *_16$$5, _17$$5, *_18$$5 = NULL, *_19$$6, *_20$$6;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &file_param, &quality_param);

	zephir_get_strval(file, file_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&ext, "pathinfo", NULL, 78, file, &_0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "setformat", NULL, 0, ext);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "setimageformat", NULL, 0, ext);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_4, _3, "getimagetype", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_type"), _4 TSRMLS_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_6, _5, "getimageformat", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SV(_7, "image/", _6);
	zephir_update_property_this(getThis(), SL("_mime"), _7 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "gif", 0);
	ZEPHIR_CALL_FUNCTION(&_8, "strcasecmp", NULL, 16, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_8, 0)) {
		_9$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _9$$3, "optimizeimagelayers", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_10$$3);
		ZVAL_STRING(&_10$$3, "w", 0);
		ZEPHIR_CALL_FUNCTION(&fp, "fopen", NULL, 308, file, &_10$$3);
		zephir_check_call_status();
		_11$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _11$$3, "writeimagesfile", NULL, 0, fp);
		zephir_check_call_status();
		zephir_fclose(fp TSRMLS_CC);
		RETURN_MM_NULL();
	} else {
		ZEPHIR_SINIT_VAR(_12$$4);
		ZVAL_STRING(&_12$$4, "jpg", 0);
		ZEPHIR_CALL_FUNCTION(&_13$$4, "strcasecmp", NULL, 16, ext, &_12$$4);
		zephir_check_call_status();
		_14$$4 = ZEPHIR_IS_LONG(_13$$4, 0);
		if (!(_14$$4)) {
			ZEPHIR_SINIT_NVAR(_12$$4);
			ZVAL_STRING(&_12$$4, "jpeg", 0);
			ZEPHIR_CALL_FUNCTION(&_15$$4, "strcasecmp", NULL, 16, ext, &_12$$4);
			zephir_check_call_status();
			_14$$4 = ZEPHIR_IS_LONG(_15$$4, 0);
		}
		if (_14$$4) {
			_16$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_17$$5);
			ZVAL_STRING(&_17$$5, "Imagick::COMPRESSION_JPEG", 0);
			ZEPHIR_CALL_FUNCTION(&_18$$5, "constant", NULL, 38, &_17$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _16$$5, "setimagecompression", NULL, 0, _18$$5);
			zephir_check_call_status();
		}
		if (quality >= 0) {
			if (quality < 1) {
				quality = 1;
			} else if (quality > 100) {
				quality = 100;
			}
			_19$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_20$$6);
			ZVAL_LONG(_20$$6, quality);
			ZEPHIR_CALL_METHOD(NULL, _19$$6, "setimagecompressionquality", NULL, 0, _20$$6);
			zephir_check_call_status();
		}
		_21$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _21$$4, "writeimage", NULL, 0, file);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a render.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _render) {

	zend_bool _7$$4;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *extension_param = NULL, *quality_param = NULL, *image = NULL, *_0 = NULL, *_1 = NULL, *_2, _3, *_4 = NULL, _5$$4 = zval_used_for_init, *_6$$4 = NULL, *_8$$4 = NULL, *_11$$4, _9$$5, *_10$$5 = NULL;
	zval *extension = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &extension_param, &quality_param);

	zephir_get_strval(extension, extension_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_OBS_VAR(image);
	zephir_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, image, "setformat", NULL, 0, extension);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, image, "setimageformat", NULL, 0, extension);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, image, "stripimage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, image, "getimagetype", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_type"), _0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, image, "getimageformat", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "image/", _1);
	zephir_update_property_this(getThis(), SL("_mime"), _2 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "gif", 0);
	ZEPHIR_CALL_FUNCTION(&_4, "strcasecmp", NULL, 16, extension, &_3);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(_4, 0)) {
		ZEPHIR_CALL_METHOD(NULL, image, "optimizeimagelayers", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_VAR(_5$$4);
		ZVAL_STRING(&_5$$4, "jpg", 0);
		ZEPHIR_CALL_FUNCTION(&_6$$4, "strcasecmp", NULL, 16, extension, &_5$$4);
		zephir_check_call_status();
		_7$$4 = ZEPHIR_IS_LONG_IDENTICAL(_6$$4, 0);
		if (!(_7$$4)) {
			ZEPHIR_SINIT_NVAR(_5$$4);
			ZVAL_STRING(&_5$$4, "jpeg", 0);
			ZEPHIR_CALL_FUNCTION(&_8$$4, "strcasecmp", NULL, 16, extension, &_5$$4);
			zephir_check_call_status();
			_7$$4 = ZEPHIR_IS_LONG_IDENTICAL(_8$$4, 0);
		}
		if (_7$$4) {
			ZEPHIR_SINIT_VAR(_9$$5);
			ZVAL_STRING(&_9$$5, "Imagick::COMPRESSION_JPEG", 0);
			ZEPHIR_CALL_FUNCTION(&_10$$5, "constant", NULL, 38, &_9$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, image, "setimagecompression", NULL, 0, _10$$5);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_11$$4);
		ZVAL_LONG(_11$$4, quality);
		ZEPHIR_CALL_METHOD(NULL, image, "setimagecompressionquality", NULL, 0, _11$$4);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(image, "getimageblob", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Destroys the loaded image to free up resources.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __destruct) {

	zval *_0, *_1$$3, *_2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_image"), PH_NOISY_CC);
	if (zephir_instance_of_ev(_0, zephir_get_internal_ce(SS("imagick") TSRMLS_CC) TSRMLS_CC)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "clear", NULL, 0);
		zephir_check_call_status();
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "destroy", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get instance
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, getInternalImInstance) {

	

	RETURN_MEMBER(getThis(), "_image");

}

/**
 * Sets the limit for a particular resource in megabytes
 *
 * @link http://php.net/manual/ru/imagick.constants.php#imagick.constants.resourcetypes
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, setResourceLimit) {

	zval *type_param = NULL, *limit_param = NULL, *_0, *_1, *_2;
	zend_long type, limit, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &limit_param);

	type = zephir_get_intval(type_param);
	limit = zephir_get_intval(limit_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, type);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, limit);
	ZEPHIR_CALL_METHOD(NULL, _0, "setresourcelimit", NULL, 0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

