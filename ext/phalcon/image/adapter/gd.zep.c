
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/math.h"


ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Gd) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Gd, phalcon, image_adapter_gd, phalcon_image_adapter_ce, phalcon_image_adapter_gd_method_entry, 0);

	zend_declare_property_bool(phalcon_image_adapter_gd_ce, SL("_checked"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(phalcon_image_adapter_gd_ce TSRMLS_CC, 1, phalcon_image_adapterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, check) {

	zval *version = NULL, *info = NULL, *matches = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, _6, *_7 = NULL, *_10, *_3$$6, *_4$$6, _5$$6, *_8$$8, *_9$$8;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_BOOL(1);
	}
	if (!((zephir_function_exists_ex(SS("gd_info") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "GD is either not installed or not enabled, check your configuration", "phalcon/image/adapter/gd.zep", 39);
		return;
	}
	ZEPHIR_INIT_VAR(version);
	ZVAL_NULL(version);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "GD_VERSION", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "defined", NULL, 236, &_1);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_NVAR(version);
		ZEPHIR_GET_CONSTANT(version, "GD_VERSION");
	} else {
		ZEPHIR_CALL_FUNCTION(&info, "gd_info", NULL, 246);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(_3$$6);
		zephir_array_fetch_string(&_4$$6, info, SL("GD Version"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 47 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_5$$6);
		ZVAL_STRING(&_5$$6, "/\\d+\\.\\d+(?:\\.\\d+)?/", 0);
		zephir_preg_match(_3$$6, &_5$$6, _4$$6, matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(_3$$6)) {
			ZEPHIR_OBS_NVAR(version);
			zephir_array_fetch_long(&version, matches, 0, PH_NOISY, "phalcon/image/adapter/gd.zep", 48 TSRMLS_CC);
		}
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "2.0.1", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, ">=", 0);
	ZEPHIR_CALL_FUNCTION(&_7, "version_compare", NULL, 247, version, &_1, &_6);
	zephir_check_call_status();
	if (!(zephir_is_true(_7))) {
		ZEPHIR_INIT_VAR(_8$$8);
		object_init_ex(_8$$8, phalcon_image_exception_ce);
		ZEPHIR_INIT_VAR(_9$$8);
		ZEPHIR_CONCAT_SV(_9$$8, "Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have ", version);
		ZEPHIR_CALL_METHOD(NULL, _8$$8, "__construct", NULL, 9, _9$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8$$8, "phalcon/image/adapter/gd.zep", 53 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	_10 = zephir_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);
	RETURN_CTOR(_10);

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, __construct) {

	zend_bool _26$$14;
	zephir_fcall_cache_entry *_25 = NULL;
	int width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, *imageinfo = NULL, *_0, *_1, *_2$$4, *_3$$4 = NULL, *_4$$4, *_9$$4, *_24$$4, *_5$$5, *_6$$5, *_7$$5, *_8$$5, *_10$$6, *_11$$6 = NULL, *_12$$7, *_13$$7 = NULL, *_14$$8, *_15$$8 = NULL, *_16$$9, *_17$$9 = NULL, *_18$$10, *_19$$10 = NULL, *_20$$11, *_21$$12, *_22$$12, *_23$$12, _30$$14, _31$$14, *_32$$14 = NULL, *_33$$14, *_34$$14, *_35$$14, *_36$$14, *_27$$15, *_28$$15, *_29$$15;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &file_param, &width_param, &height_param);

	if (unlikely(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(file_param) == IS_STRING)) {
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


	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_SELF(NULL, "check", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
	if ((zephir_file_exists(_1 TSRMLS_CC) == SUCCESS)) {
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_3$$4, "realpath", NULL, 64, _2$$4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_realpath"), _3$$4 TSRMLS_CC);
		_4$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&imageinfo, "getimagesize", NULL, 248, _4$$4);
		zephir_check_call_status();
		if (zephir_is_true(imageinfo)) {
			zephir_array_fetch_long(&_5$$5, imageinfo, 0, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 77 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_width"), _5$$5 TSRMLS_CC);
			zephir_array_fetch_long(&_6$$5, imageinfo, 1, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 78 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_height"), _6$$5 TSRMLS_CC);
			zephir_array_fetch_long(&_7$$5, imageinfo, 2, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 79 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_type"), _7$$5 TSRMLS_CC);
			zephir_array_fetch_string(&_8$$5, imageinfo, SL("mime"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 80 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_mime"), _8$$5 TSRMLS_CC);
		}
		_9$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		do {
			if (ZEPHIR_IS_LONG(_9$$4, 1)) {
				_10$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_11$$6, "imagecreatefromgif", NULL, 249, _10$$6);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), _11$$6 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_9$$4, 2)) {
				_12$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_13$$7, "imagecreatefromjpeg", NULL, 250, _12$$7);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), _13$$7 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_9$$4, 3)) {
				_14$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_15$$8, "imagecreatefrompng", NULL, 251, _14$$8);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), _15$$8 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_9$$4, 15)) {
				_16$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_17$$9, "imagecreatefromwbmp", NULL, 252, _16$$9);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), _17$$9 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_9$$4, 16)) {
				_18$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_19$$10, "imagecreatefromxbm", NULL, 253, _18$$10);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), _19$$10 TSRMLS_CC);
				break;
			}
			_20$$11 = zephir_fetch_nproperty_this(this_ptr, SL("_mime"), PH_NOISY_CC);
			if (zephir_is_true(_20$$11)) {
				ZEPHIR_INIT_VAR(_21$$12);
				object_init_ex(_21$$12, phalcon_image_exception_ce);
				_22$$12 = zephir_fetch_nproperty_this(this_ptr, SL("_mime"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_23$$12);
				ZEPHIR_CONCAT_SVS(_23$$12, "Installed GD does not support ", _22$$12, " images");
				ZEPHIR_CALL_METHOD(NULL, _21$$12, "__construct", NULL, 9, _23$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(_21$$12, "phalcon/image/adapter/gd.zep", 101 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Installed GD does not support such images", "phalcon/image/adapter/gd.zep", 103);
				return;
			}
			break;
		} while(0);

		_24$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_25, 254, _24$$4, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
	} else {
		_26$$14 = !width;
		if (!(_26$$14)) {
			_26$$14 = !height;
		}
		if (_26$$14) {
			ZEPHIR_INIT_VAR(_27$$15);
			object_init_ex(_27$$15, phalcon_image_exception_ce);
			_28$$15 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_29$$15);
			ZEPHIR_CONCAT_SV(_29$$15, "Failed to create image from file ", _28$$15);
			ZEPHIR_CALL_METHOD(NULL, _27$$15, "__construct", NULL, 9, _29$$15);
			zephir_check_call_status();
			zephir_throw_exception_debug(_27$$15, "phalcon/image/adapter/gd.zep", 112 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_SINIT_VAR(_30$$14);
		ZVAL_LONG(&_30$$14, width);
		ZEPHIR_SINIT_VAR(_31$$14);
		ZVAL_LONG(&_31$$14, height);
		ZEPHIR_CALL_FUNCTION(&_32$$14, "imagecreatetruecolor", NULL, 255, &_30$$14, &_31$$14);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), _32$$14 TSRMLS_CC);
		_33$$14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 256, _33$$14, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		_34$$14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_25, 254, _34$$14, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		_35$$14 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_realpath"), _35$$14 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_36$$14);
		ZVAL_LONG(_36$$14, width);
		zephir_update_property_this(this_ptr, SL("_width"), _36$$14 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_36$$14);
		ZVAL_LONG(_36$$14, height);
		zephir_update_property_this(this_ptr, SL("_height"), _36$$14 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_36$$14);
		ZVAL_LONG(_36$$14, 3);
		zephir_update_property_this(this_ptr, SL("_type"), _36$$14 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_36$$14);
		ZVAL_STRING(_36$$14, "image/png", 1);
		zephir_update_property_this(this_ptr, SL("_mime"), _36$$14 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _resize) {

	zend_bool _4$$3, _8$$4;
	zephir_fcall_cache_entry *_9 = NULL, *_19 = NULL, *_32 = NULL, *_34 = NULL;
	zval *width_param = NULL, *height_param = NULL, *image = NULL, *pre_width = NULL, *pre_height = NULL, *reduction_width = NULL, *reduction_height = NULL, *_0, _1, *_2 = NULL, *_3$$3, *_5$$3, *_20$$3, *_21$$3, *_22$$3, _23$$3, _24$$3, _25$$3, _26$$3, _27$$3, _28$$3, *_29$$3 = NULL, _6$$4, _7$$4, *_10$$4, *_11$$4, *_12$$4, _13$$4, _14$$4, _15$$4, _16$$4, *_17$$4 = NULL, *_18$$6, *_30$$7, *_31$$7 = NULL, *_33$$7 = NULL, *_35$$8, _36$$8, _37$$8, *_38$$8, *_39$$8 = NULL, *_40$$8 = NULL;
	int width, height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_VERSION");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "5.5.0", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", NULL, 247, _0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(_2, 0)) {
		ZEPHIR_OBS_VAR(pre_width);
		zephir_read_property_this(&pre_width, this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(pre_height);
		zephir_read_property_this(&pre_height, this_ptr, SL("_height"), PH_NOISY_CC);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_4$$3 = width > (zephir_safe_div_zval_long(_3$$3, 2 TSRMLS_CC));
		if (_4$$3) {
			_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			_4$$3 = height > (zephir_safe_div_zval_long(_5$$3, 2 TSRMLS_CC));
		}
		if (_4$$3) {
			ZEPHIR_SINIT_VAR(_6$$4);
			ZVAL_LONG(&_6$$4, (width * 1.1));
			ZEPHIR_INIT_VAR(reduction_width);
			zephir_round(reduction_width, &_6$$4, NULL, NULL TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_7$$4);
			ZVAL_LONG(&_7$$4, (height * 1.1));
			ZEPHIR_INIT_VAR(reduction_height);
			zephir_round(reduction_height, &_7$$4, NULL, NULL TSRMLS_CC);
			while (1) {
				_8$$4 = ZEPHIR_LT_LONG(reduction_width, zephir_safe_div_zval_long(pre_width, 2 TSRMLS_CC));
				if (_8$$4) {
					_8$$4 = ZEPHIR_LT_LONG(reduction_height, zephir_safe_div_zval_long(pre_height, 2 TSRMLS_CC));
				}
				if (!(_8$$4)) {
					break;
				}
				ZEPHIR_INIT_NVAR(pre_width);
				ZVAL_DOUBLE(pre_width, 2);
				ZEPHIR_INIT_NVAR(pre_height);
				ZVAL_DOUBLE(pre_height, 2);
			}
			ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", &_9, 0, pre_width, pre_height);
			zephir_check_call_status();
			_10$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			_11$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			_12$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_13$$4);
			ZVAL_LONG(&_13$$4, 0);
			ZEPHIR_SINIT_VAR(_14$$4);
			ZVAL_LONG(&_14$$4, 0);
			ZEPHIR_SINIT_VAR(_15$$4);
			ZVAL_LONG(&_15$$4, 0);
			ZEPHIR_SINIT_VAR(_16$$4);
			ZVAL_LONG(&_16$$4, 0);
			ZEPHIR_CALL_FUNCTION(&_17$$4, "imagecopyresized", NULL, 257, image, _10$$4, &_13$$4, &_14$$4, &_15$$4, &_16$$4, pre_width, pre_height, _11$$4, _12$$4);
			zephir_check_call_status();
			if (zephir_is_true(_17$$4)) {
				_18$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_19, 258, _18$$6);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			}
		}
		ZEPHIR_INIT_VAR(_20$$3);
		ZVAL_LONG(_20$$3, width);
		ZEPHIR_INIT_VAR(_21$$3);
		ZVAL_LONG(_21$$3, height);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", &_9, 0, _20$$3, _21$$3);
		zephir_check_call_status();
		_22$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_23$$3);
		ZVAL_LONG(&_23$$3, 0);
		ZEPHIR_SINIT_VAR(_24$$3);
		ZVAL_LONG(&_24$$3, 0);
		ZEPHIR_SINIT_VAR(_25$$3);
		ZVAL_LONG(&_25$$3, 0);
		ZEPHIR_SINIT_VAR(_26$$3);
		ZVAL_LONG(&_26$$3, 0);
		ZEPHIR_SINIT_VAR(_27$$3);
		ZVAL_LONG(&_27$$3, width);
		ZEPHIR_SINIT_VAR(_28$$3);
		ZVAL_LONG(&_28$$3, height);
		ZEPHIR_CALL_FUNCTION(&_29$$3, "imagecopyresampled", NULL, 259, image, _22$$3, &_23$$3, &_24$$3, &_25$$3, &_26$$3, &_27$$3, &_28$$3, pre_width, pre_height);
		zephir_check_call_status();
		if (zephir_is_true(_29$$3)) {
			_30$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_19, 258, _30$$7);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_31$$7, "imagesx", &_32, 260, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_width"), _31$$7 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_33$$7, "imagesy", &_34, 261, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_height"), _33$$7 TSRMLS_CC);
		}
	} else {
		_35$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_36$$8);
		ZVAL_LONG(&_36$$8, width);
		ZEPHIR_SINIT_VAR(_37$$8);
		ZVAL_LONG(&_37$$8, height);
		ZEPHIR_CALL_FUNCTION(&image, "imagescale", NULL, 262, _35$$8, &_36$$8, &_37$$8);
		zephir_check_call_status();
		_38$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_19, 258, _38$$8);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_39$$8, "imagesx", &_32, 260, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_width"), _39$$8 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_40$$8, "imagesy", &_34, 261, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_height"), _40$$8 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _crop) {

	zephir_fcall_cache_entry *_16 = NULL, *_18 = NULL, *_20 = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, *image = NULL, *rect = NULL, *_0, _1, *_2 = NULL, *_3$$3, *_4$$3, *_5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, _12$$3, _13$$3, *_14$$3 = NULL, *_15$$4, *_17$$4 = NULL, *_19$$4 = NULL, *_21$$5 = NULL, *_22$$5, *_23$$5, *_24$$5 = NULL, *_25$$5 = NULL;
	int width, height, offsetX, offsetY, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &offsetX_param, &offsetY_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_VERSION");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "5.5.0", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", NULL, 247, _0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(_2, 0)) {
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_LONG(_3$$3, width);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_LONG(_4$$3, height);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", NULL, 0, _3$$3, _4$$3);
		zephir_check_call_status();
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_6$$3);
		ZVAL_LONG(&_6$$3, 0);
		ZEPHIR_SINIT_VAR(_7$$3);
		ZVAL_LONG(&_7$$3, 0);
		ZEPHIR_SINIT_VAR(_8$$3);
		ZVAL_LONG(&_8$$3, offsetX);
		ZEPHIR_SINIT_VAR(_9$$3);
		ZVAL_LONG(&_9$$3, offsetY);
		ZEPHIR_SINIT_VAR(_10$$3);
		ZVAL_LONG(&_10$$3, width);
		ZEPHIR_SINIT_VAR(_11$$3);
		ZVAL_LONG(&_11$$3, height);
		ZEPHIR_SINIT_VAR(_12$$3);
		ZVAL_LONG(&_12$$3, width);
		ZEPHIR_SINIT_VAR(_13$$3);
		ZVAL_LONG(&_13$$3, height);
		ZEPHIR_CALL_FUNCTION(&_14$$3, "imagecopyresampled", NULL, 259, image, _5$$3, &_6$$3, &_7$$3, &_8$$3, &_9$$3, &_10$$3, &_11$$3, &_12$$3, &_13$$3);
		zephir_check_call_status();
		if (zephir_is_true(_14$$3)) {
			_15$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_16, 258, _15$$4);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_17$$4, "imagesx", &_18, 260, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_width"), _17$$4 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_19$$4, "imagesy", &_20, 261, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_height"), _19$$4 TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_VAR(rect);
		zephir_create_array(rect, 4, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_21$$5);
		ZVAL_LONG(_21$$5, offsetX);
		zephir_array_update_string(&rect, SL("x"), &_21$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_21$$5);
		ZVAL_LONG(_21$$5, offsetY);
		zephir_array_update_string(&rect, SL("y"), &_21$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_21$$5);
		ZVAL_LONG(_21$$5, width);
		zephir_array_update_string(&rect, SL("width"), &_21$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_21$$5);
		ZVAL_LONG(_21$$5, height);
		zephir_array_update_string(&rect, SL("height"), &_21$$5, PH_COPY | PH_SEPARATE);
		_22$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&image, "imagecrop", NULL, 263, _22$$5, rect);
		zephir_check_call_status();
		_23$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_16, 258, _23$$5);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_24$$5, "imagesx", &_18, 260, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_width"), _24$$5 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_25$$5, "imagesy", &_20, 261, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_height"), _25$$5 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _rotate) {

	zval *degrees_param = NULL, *image = NULL, *transparent = NULL, *width = NULL, *height = NULL, *_0, _1 = zval_used_for_init, _2 = zval_used_for_init, _3 = zval_used_for_init, _4 = zval_used_for_init, *_5, *_6, _7, *_8 = NULL, *_9$$3;
	int degrees, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);

	degrees = zephir_get_intval(degrees_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 127);
	ZEPHIR_CALL_FUNCTION(&transparent, "imagecolorallocatealpha", NULL, 264, _0, &_1, &_2, &_3, &_4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, (360 - degrees));
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_FUNCTION(&image, "imagerotate", NULL, 265, _5, &_1, transparent, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 254, image, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&width, "imagesx", NULL, 260, image);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&height, "imagesy", NULL, 261, image);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 100);
	ZEPHIR_CALL_FUNCTION(&_8, "imagecopymerge", NULL, 266, _6, image, &_1, &_2, &_3, &_4, width, height, &_7);
	zephir_check_call_status();
	if (zephir_is_true(_8)) {
		_9$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 258, _9$$3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _flip) {

	zephir_fcall_cache_entry *_14 = NULL, *_29 = NULL;
	zval *direction_param = NULL, *image = NULL, *_0, _1, *_2 = NULL, *_3$$3, *_4$$3, *_24$$3, *_25$$3 = NULL, *_26$$3 = NULL, *_5$$4, *_6$$5, *_7$$5, *_8$$5, _9$$5 = zval_used_for_init, _10$$5 = zval_used_for_init, _11$$5 = zval_used_for_init, _12$$5 = zval_used_for_init, _13$$5 = zval_used_for_init, *_15$$6, *_16$$7, *_17$$7, *_18$$7, _19$$7 = zval_used_for_init, _20$$7 = zval_used_for_init, _21$$7 = zval_used_for_init, _22$$7 = zval_used_for_init, _23$$7 = zval_used_for_init, *_27$$9, _28$$9, *_30$$10, _31$$10;
	int direction, ZEPHIR_LAST_CALL_STATUS, x = 0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

	direction = zephir_get_intval(direction_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_VERSION");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "5.5.0", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", NULL, 247, _0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(_2, 0)) {
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", NULL, 0, _3$$3, _4$$3);
		zephir_check_call_status();
		if (direction == 11) {
			x = 0;
			while (1) {
				_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				if (!(ZEPHIR_GT_LONG(_5$$4, x))) {
					break;
				}
				x++;
				_6$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				_7$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				_8$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				ZEPHIR_SINIT_NVAR(_9$$5);
				ZVAL_LONG(&_9$$5, x);
				ZEPHIR_SINIT_NVAR(_10$$5);
				ZVAL_LONG(&_10$$5, 0);
				ZEPHIR_SINIT_NVAR(_11$$5);
				ZVAL_LONG(&_11$$5, ((zephir_get_numberval(_7$$5) - x) - 1));
				ZEPHIR_SINIT_NVAR(_12$$5);
				ZVAL_LONG(&_12$$5, 0);
				ZEPHIR_SINIT_NVAR(_13$$5);
				ZVAL_LONG(&_13$$5, 1);
				ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_14, 267, image, _6$$5, &_9$$5, &_10$$5, &_11$$5, &_12$$5, &_13$$5, _8$$5);
				zephir_check_call_status();
			}
		} else {
			x = 0;
			while (1) {
				_15$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				if (!(ZEPHIR_GT_LONG(_15$$6, x))) {
					break;
				}
				x++;
				_16$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				_17$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				_18$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				ZEPHIR_SINIT_NVAR(_19$$7);
				ZVAL_LONG(&_19$$7, 0);
				ZEPHIR_SINIT_NVAR(_20$$7);
				ZVAL_LONG(&_20$$7, x);
				ZEPHIR_SINIT_NVAR(_21$$7);
				ZVAL_LONG(&_21$$7, 0);
				ZEPHIR_SINIT_NVAR(_22$$7);
				ZVAL_LONG(&_22$$7, ((zephir_get_numberval(_17$$7) - x) - 1));
				ZEPHIR_SINIT_NVAR(_23$$7);
				ZVAL_LONG(&_23$$7, 1);
				ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_14, 267, image, _16$$7, &_19$$7, &_20$$7, &_21$$7, &_22$$7, _18$$7, &_23$$7);
				zephir_check_call_status();
			}
		}
		_24$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 258, _24$$3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_25$$3, "imagesx", NULL, 260, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_width"), _25$$3 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_26$$3, "imagesy", NULL, 261, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_height"), _26$$3 TSRMLS_CC);
	} else {
		if (direction == 11) {
			_27$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_28$$9);
			ZVAL_LONG(&_28$$9, 1);
			ZEPHIR_CALL_FUNCTION(NULL, "imageflip", &_29, 268, _27$$9, &_28$$9);
			zephir_check_call_status();
		} else {
			_30$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_31$$10);
			ZVAL_LONG(&_31$$10, 2);
			ZEPHIR_CALL_FUNCTION(NULL, "imageflip", &_29, 268, _30$$10, &_31$$10);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _sharpen) {

	zval *_3 = NULL;
	zval *amount_param = NULL, *matrix = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, *_4 = NULL, *_5, _6, _7, *_8 = NULL, *_9$$3, *_10$$3 = NULL, *_11$$3, *_12$$3 = NULL;
	int amount, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, (-18 + ((amount * 0.08))));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 198, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 2);
	zephir_round(_0, _2, &_1, NULL TSRMLS_CC);
	amount = zephir_get_intval(_0);
	ZEPHIR_INIT_VAR(matrix);
	zephir_create_array(matrix, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	zephir_array_fast_append(matrix, _3);
	ZEPHIR_INIT_NVAR(_3);
	zephir_create_array(_3, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, amount);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	zephir_array_fast_append(matrix, _3);
	ZEPHIR_INIT_NVAR(_3);
	zephir_create_array(_3, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	zephir_array_fast_append(matrix, _3);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, (amount - 8));
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(&_8, "imageconvolution", NULL, 269, _5, matrix, &_6, &_7);
	zephir_check_call_status();
	if (zephir_is_true(_8)) {
		_9$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_10$$3, "imagesx", NULL, 260, _9$$3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_width"), _10$$3 TSRMLS_CC);
		_11$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_12$$3, "imagesy", NULL, 261, _11$$3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_height"), _12$$3 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _reflection) {

	zephir_fcall_cache_entry *_6 = NULL, *_13 = NULL, *_29 = NULL;
	zend_bool fadeIn;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, *reflection = NULL, *line = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, *_3, *_4, *_5, *_7, *_8, *_9, _10, _11, _12, *_31, *_32 = NULL, *_33 = NULL, *_14$$5, *_15$$5, *_20$$5, *_21$$5 = NULL, *_22$$5, *_23$$5, _24$$5 = zval_used_for_init, _25$$5 = zval_used_for_init, _26$$5 = zval_used_for_init, _27$$5 = zval_used_for_init, _28$$5 = zval_used_for_init, *_30$$5, *_16$$6 = NULL, _17$$6 = zval_used_for_init, *_18$$7 = NULL, _19$$7 = zval_used_for_init;
	int height, opacity, ZEPHIR_LAST_CALL_STATUS, stepping = 0, offset = 0, src_y = 0, dst_y = 0, dst_opacity = 0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &height_param, &opacity_param, &fadeIn_param);

	height = zephir_get_intval(height_param);
	opacity = zephir_get_intval(opacity_param);
	fadeIn = zephir_get_boolval(fadeIn_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_DOUBLE(&_1, ((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 198, &_1);
	zephir_check_call_status();
	zephir_round(_0, _2, NULL, NULL TSRMLS_CC);
	opacity = zephir_get_intval(_0);
	if (opacity < 127) {
		stepping = (long) (zephir_safe_div_long_long(((127 - opacity)), height TSRMLS_CC));
	} else {
		stepping = (long) (zephir_safe_div_long_long(127, height TSRMLS_CC));
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, (zephir_get_numberval(_4) + height));
	ZEPHIR_CALL_METHOD(&reflection, this_ptr, "_create", &_6, 0, _3, _5);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, 0);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, 0);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_13, 267, reflection, _7, &_1, &_10, &_11, &_12, _8, _9);
	zephir_check_call_status();
	offset = 0;
	while (1) {
		if (!(height >= offset)) {
			break;
		}
		_14$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		src_y = ((zephir_get_numberval(_14$$5) - offset) - 1);
		_15$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		dst_y = (zephir_get_numberval(_15$$5) + offset);
		if (fadeIn) {
			ZEPHIR_INIT_NVAR(_16$$6);
			ZEPHIR_SINIT_NVAR(_17$$6);
			ZVAL_LONG(&_17$$6, (opacity + ((stepping * ((height - offset))))));
			zephir_round(_16$$6, &_17$$6, NULL, NULL TSRMLS_CC);
			dst_opacity = zephir_get_intval(_16$$6);
		} else {
			ZEPHIR_INIT_NVAR(_18$$7);
			ZEPHIR_SINIT_NVAR(_19$$7);
			ZVAL_LONG(&_19$$7, (opacity + ((stepping * offset))));
			zephir_round(_18$$7, &_19$$7, NULL, NULL TSRMLS_CC);
			dst_opacity = zephir_get_intval(_18$$7);
		}
		_20$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_21$$5);
		ZVAL_LONG(_21$$5, 1);
		ZEPHIR_CALL_METHOD(&line, this_ptr, "_create", &_6, 0, _20$$5, _21$$5);
		zephir_check_call_status();
		_22$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_23$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_24$$5);
		ZVAL_LONG(&_24$$5, 0);
		ZEPHIR_SINIT_NVAR(_25$$5);
		ZVAL_LONG(&_25$$5, 0);
		ZEPHIR_SINIT_NVAR(_26$$5);
		ZVAL_LONG(&_26$$5, 0);
		ZEPHIR_SINIT_NVAR(_27$$5);
		ZVAL_LONG(&_27$$5, src_y);
		ZEPHIR_SINIT_NVAR(_28$$5);
		ZVAL_LONG(&_28$$5, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_13, 267, line, _22$$5, &_24$$5, &_25$$5, &_26$$5, &_27$$5, _23$$5, &_28$$5);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_24$$5);
		ZVAL_LONG(&_24$$5, 4);
		ZEPHIR_SINIT_NVAR(_25$$5);
		ZVAL_LONG(&_25$$5, 0);
		ZEPHIR_SINIT_NVAR(_26$$5);
		ZVAL_LONG(&_26$$5, 0);
		ZEPHIR_SINIT_NVAR(_27$$5);
		ZVAL_LONG(&_27$$5, 0);
		ZEPHIR_SINIT_NVAR(_28$$5);
		ZVAL_LONG(&_28$$5, dst_opacity);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", &_29, 270, line, &_24$$5, &_25$$5, &_26$$5, &_27$$5, &_28$$5);
		zephir_check_call_status();
		_30$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_24$$5);
		ZVAL_LONG(&_24$$5, 0);
		ZEPHIR_SINIT_NVAR(_25$$5);
		ZVAL_LONG(&_25$$5, dst_y);
		ZEPHIR_SINIT_NVAR(_26$$5);
		ZVAL_LONG(&_26$$5, 0);
		ZEPHIR_SINIT_NVAR(_27$$5);
		ZVAL_LONG(&_27$$5, 0);
		ZEPHIR_SINIT_NVAR(_28$$5);
		ZVAL_LONG(&_28$$5, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_13, 267, reflection, line, &_24$$5, &_25$$5, &_26$$5, &_27$$5, _30$$5, &_28$$5);
		zephir_check_call_status();
		offset++;
	}
	_31 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 258, _31);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_image"), reflection TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_32, "imagesx", NULL, 260, reflection);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _32 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_33, "imagesy", NULL, 261, reflection);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _33 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _watermark) {

	int offsetX, offsetY, opacity, ZEPHIR_LAST_CALL_STATUS, width = 0, height = 0;
	zval *watermark, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, *overlay = NULL, *color = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_9, *_10, _11, _12, _13, _14, _15, _16, *_17 = NULL, *_3$$3, _4$$3 = zval_used_for_init, *_5$$3 = NULL, _6$$3 = zval_used_for_init, _7$$3 = zval_used_for_init, _8$$3 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &watermark, &offsetX_param, &offsetY_param, &opacity_param);

	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);


	ZEPHIR_CALL_METHOD(&_0, watermark, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&overlay, "imagecreatefromstring", NULL, 271, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 254, overlay, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, 260, overlay);
	zephir_check_call_status();
	width = zephir_get_intval(_1);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, 261, overlay);
	zephir_check_call_status();
	height = zephir_get_intval(_2);
	if (opacity < 100) {
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_DOUBLE(&_4$$3, ((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
		ZEPHIR_CALL_FUNCTION(&_5$$3, "abs", NULL, 198, &_4$$3);
		zephir_check_call_status();
		zephir_round(_3$$3, _5$$3, NULL, NULL TSRMLS_CC);
		opacity = zephir_get_intval(_3$$3);
		ZEPHIR_SINIT_NVAR(_4$$3);
		ZVAL_LONG(&_4$$3, 127);
		ZEPHIR_SINIT_VAR(_6$$3);
		ZVAL_LONG(&_6$$3, 127);
		ZEPHIR_SINIT_VAR(_7$$3);
		ZVAL_LONG(&_7$$3, 127);
		ZEPHIR_SINIT_VAR(_8$$3);
		ZVAL_LONG(&_8$$3, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 264, overlay, &_4$$3, &_6$$3, &_7$$3, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4$$3);
		ZVAL_LONG(&_4$$3, 3);
		ZEPHIR_CALL_FUNCTION(NULL, "imagelayereffect", NULL, 272, overlay, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4$$3);
		ZVAL_LONG(&_4$$3, 0);
		ZEPHIR_SINIT_NVAR(_6$$3);
		ZVAL_LONG(&_6$$3, 0);
		ZEPHIR_SINIT_NVAR(_7$$3);
		ZVAL_LONG(&_7$$3, width);
		ZEPHIR_SINIT_NVAR(_8$$3);
		ZVAL_LONG(&_8$$3, height);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", NULL, 273, overlay, &_4$$3, &_6$$3, &_7$$3, &_8$$3, color);
		zephir_check_call_status();
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 256, _9, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, offsetX);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, offsetY);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_LONG(&_13, 0);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_LONG(&_14, 0);
	ZEPHIR_SINIT_VAR(_15);
	ZVAL_LONG(&_15, width);
	ZEPHIR_SINIT_VAR(_16);
	ZVAL_LONG(&_16, height);
	ZEPHIR_CALL_FUNCTION(&_17, "imagecopy", NULL, 267, _10, overlay, &_11, &_12, &_13, &_14, &_15, &_16);
	zephir_check_call_status();
	if (zephir_is_true(_17)) {
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 258, overlay);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _text) {

	zend_bool _10$$3, _11$$3, _12$$3;
	zephir_fcall_cache_entry *_3 = NULL, *_20 = NULL;
	int offsetX, offsetY, opacity, r, g, b, size, ZEPHIR_LAST_CALL_STATUS, angle = 0, s0, s1, s4, s5, width = 0, height = 0;
	zval *text_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *size_param = NULL, *fontfile_param = NULL, *space = NULL, *color = NULL, *_0, _1, *_2 = NULL, _4$$3 = zval_used_for_init, _5$$3 = zval_used_for_init, *_13$$3 = NULL, *_14$$3 = NULL, *_17$$3, _18$$3 = zval_used_for_init, _19$$3 = zval_used_for_init, *_21$$3, *_6$$4, *_7$$4, *_8$$4, *_9$$4, *_15$$6, *_16$$7, _22$$8 = zval_used_for_init, *_23$$8 = NULL, *_24$$8 = NULL, *_27$$8, _28$$8 = zval_used_for_init, _29$$8 = zval_used_for_init, _30$$8, *_31$$8, *_25$$9, *_26$$10;
	zval *text = NULL, *fontfile = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 9, 0, &text_param, &offsetX_param, &offsetY_param, &opacity_param, &r_param, &g_param, &b_param, &size_param, &fontfile_param);

	zephir_get_strval(text, text_param);
	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);
	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	size = zephir_get_intval(size_param);
	zephir_get_strval(fontfile, fontfile_param);


	s0 = 0;
	s1 = 0;
	s4 = 0;
	s5 = 0;
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_DOUBLE(&_1, ((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", &_3, 198, &_1);
	zephir_check_call_status();
	zephir_round(_0, _2, NULL, NULL TSRMLS_CC);
	opacity = zephir_get_intval(_0);
	if (!(!fontfile) && Z_STRLEN_P(fontfile)) {
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_LONG(&_4$$3, size);
		ZEPHIR_SINIT_VAR(_5$$3);
		ZVAL_LONG(&_5$$3, 0);
		ZEPHIR_CALL_FUNCTION(&space, "imagettfbbox", NULL, 274, &_4$$3, &_5$$3, fontfile, text);
		zephir_check_call_status();
		if (zephir_array_isset_long(space, 0)) {
			ZEPHIR_OBS_VAR(_6$$4);
			zephir_array_fetch_long(&_6$$4, space, 0, PH_NOISY, "phalcon/image/adapter/gd.zep", 351 TSRMLS_CC);
			s0 = zephir_get_intval(_6$$4);
			ZEPHIR_OBS_VAR(_7$$4);
			zephir_array_fetch_long(&_7$$4, space, 1, PH_NOISY, "phalcon/image/adapter/gd.zep", 352 TSRMLS_CC);
			s1 = zephir_get_intval(_7$$4);
			ZEPHIR_OBS_VAR(_8$$4);
			zephir_array_fetch_long(&_8$$4, space, 4, PH_NOISY, "phalcon/image/adapter/gd.zep", 353 TSRMLS_CC);
			s4 = zephir_get_intval(_8$$4);
			ZEPHIR_OBS_VAR(_9$$4);
			zephir_array_fetch_long(&_9$$4, space, 5, PH_NOISY, "phalcon/image/adapter/gd.zep", 354 TSRMLS_CC);
			s5 = zephir_get_intval(_9$$4);
		}
		_10$$3 = !s0;
		if (!(_10$$3)) {
			_10$$3 = !s1;
		}
		_11$$3 = _10$$3;
		if (!(_11$$3)) {
			_11$$3 = !s4;
		}
		_12$$3 = _11$$3;
		if (!(_12$$3)) {
			_12$$3 = !s5;
		}
		if (_12$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Call to imagettfbbox() failed", "phalcon/image/adapter/gd.zep", 358);
			return;
		}
		ZEPHIR_SINIT_NVAR(_4$$3);
		ZVAL_LONG(&_4$$3, (s4 - s0));
		ZEPHIR_CALL_FUNCTION(&_13$$3, "abs", &_3, 198, &_4$$3);
		zephir_check_call_status();
		width = (zephir_get_numberval(_13$$3) + 10);
		ZEPHIR_SINIT_NVAR(_4$$3);
		ZVAL_LONG(&_4$$3, (s5 - s1));
		ZEPHIR_CALL_FUNCTION(&_14$$3, "abs", &_3, 198, &_4$$3);
		zephir_check_call_status();
		height = (zephir_get_numberval(_14$$3) + 10);
		if (offsetX < 0) {
			_15$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			offsetX = ((zephir_get_numberval(_15$$6) - width) + offsetX);
		}
		if (offsetY < 0) {
			_16$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			offsetY = ((zephir_get_numberval(_16$$7) - height) + offsetY);
		}
		_17$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_4$$3);
		ZVAL_LONG(&_4$$3, r);
		ZEPHIR_SINIT_NVAR(_5$$3);
		ZVAL_LONG(&_5$$3, g);
		ZEPHIR_SINIT_VAR(_18$$3);
		ZVAL_LONG(&_18$$3, b);
		ZEPHIR_SINIT_VAR(_19$$3);
		ZVAL_LONG(&_19$$3, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_20, 264, _17$$3, &_4$$3, &_5$$3, &_18$$3, &_19$$3);
		zephir_check_call_status();
		angle = 0;
		_21$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_4$$3);
		ZVAL_LONG(&_4$$3, size);
		ZEPHIR_SINIT_NVAR(_5$$3);
		ZVAL_LONG(&_5$$3, angle);
		ZEPHIR_SINIT_NVAR(_18$$3);
		ZVAL_LONG(&_18$$3, offsetX);
		ZEPHIR_SINIT_NVAR(_19$$3);
		ZVAL_LONG(&_19$$3, offsetY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", NULL, 275, _21$$3, &_4$$3, &_5$$3, &_18$$3, &_19$$3, color, fontfile, text);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_VAR(_22$$8);
		ZVAL_LONG(&_22$$8, size);
		ZEPHIR_CALL_FUNCTION(&_23$$8, "imagefontwidth", NULL, 276, &_22$$8);
		zephir_check_call_status();
		width = (zephir_get_intval(_23$$8) * zephir_fast_strlen_ev(text));
		ZEPHIR_SINIT_NVAR(_22$$8);
		ZVAL_LONG(&_22$$8, size);
		ZEPHIR_CALL_FUNCTION(&_24$$8, "imagefontheight", NULL, 277, &_22$$8);
		zephir_check_call_status();
		height = zephir_get_intval(_24$$8);
		if (offsetX < 0) {
			_25$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			offsetX = ((zephir_get_numberval(_25$$9) - width) + offsetX);
		}
		if (offsetY < 0) {
			_26$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			offsetY = ((zephir_get_numberval(_26$$10) - height) + offsetY);
		}
		_27$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_22$$8);
		ZVAL_LONG(&_22$$8, r);
		ZEPHIR_SINIT_VAR(_28$$8);
		ZVAL_LONG(&_28$$8, g);
		ZEPHIR_SINIT_VAR(_29$$8);
		ZVAL_LONG(&_29$$8, b);
		ZEPHIR_SINIT_VAR(_30$$8);
		ZVAL_LONG(&_30$$8, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_20, 264, _27$$8, &_22$$8, &_28$$8, &_29$$8, &_30$$8);
		zephir_check_call_status();
		_31$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_22$$8);
		ZVAL_LONG(&_22$$8, size);
		ZEPHIR_SINIT_NVAR(_28$$8);
		ZVAL_LONG(&_28$$8, offsetX);
		ZEPHIR_SINIT_NVAR(_29$$8);
		ZVAL_LONG(&_29$$8, offsetY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagestring", NULL, 278, _31$$8, &_22$$8, &_28$$8, &_29$$8, text, color);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _mask) {

	zend_bool _12;
	zephir_fcall_cache_entry *_3 = NULL, *_10 = NULL, *_24 = NULL, *_29 = NULL, *_30 = NULL, *_35 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, mask_width = 0, mask_height = 0, x = 0, y = 0, alpha = 0;
	zval *mask, *maskImage = NULL, *newimage = NULL, *tempImage = NULL, *color = NULL, *index = NULL, *r = NULL, *g = NULL, *b = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_4, *_5, _6 = zval_used_for_init, _7 = zval_used_for_init, _8, _9, *_11, *_13, *_25, *_36, *_14$$3, *_15$$3, *_16$$3, *_17$$3, _18$$3, _19$$3, _20$$3, _21$$3, _22$$3, _23$$3, *_26$$4, _27$$5 = zval_used_for_init, _28$$5 = zval_used_for_init, *_33$$5, *_34$$5, *_31$$6, _32$$6 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mask);



	ZEPHIR_CALL_METHOD(&_0, mask, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&maskImage, "imagecreatefromstring", NULL, 271, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, 260, maskImage);
	zephir_check_call_status();
	mask_width = zephir_get_intval(_1);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, 261, maskImage);
	zephir_check_call_status();
	mask_height = zephir_get_intval(_2);
	alpha = 127;
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_3, 254, maskImage, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&newimage, this_ptr, "_create", NULL, 0, _4, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_3, 254, newimage, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, alpha);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_10, 264, newimage, &_6, &_7, &_8, &_9);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagefill", NULL, 279, newimage, &_6, &_7, color);
	zephir_check_call_status();
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_12 = !ZEPHIR_IS_LONG(_11, mask_width);
	if (!(_12)) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		_12 = !ZEPHIR_IS_LONG(_13, mask_height);
	}
	if (_12) {
		_14$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_15$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&tempImage, "imagecreatetruecolor", NULL, 255, _14$$3, _15$$3);
		zephir_check_call_status();
		_16$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_17$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_18$$3);
		ZVAL_LONG(&_18$$3, 0);
		ZEPHIR_SINIT_VAR(_19$$3);
		ZVAL_LONG(&_19$$3, 0);
		ZEPHIR_SINIT_VAR(_20$$3);
		ZVAL_LONG(&_20$$3, 0);
		ZEPHIR_SINIT_VAR(_21$$3);
		ZVAL_LONG(&_21$$3, 0);
		ZEPHIR_SINIT_VAR(_22$$3);
		ZVAL_LONG(&_22$$3, mask_width);
		ZEPHIR_SINIT_VAR(_23$$3);
		ZVAL_LONG(&_23$$3, mask_height);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopyresampled", NULL, 259, tempImage, maskImage, &_18$$3, &_19$$3, &_20$$3, &_21$$3, _16$$3, _17$$3, &_22$$3, &_23$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_24, 258, maskImage);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(maskImage, tempImage);
	}
	x = 0;
	while (1) {
		_25 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		if (!(ZEPHIR_GT_LONG(_25, x))) {
			break;
		}
		y = 0;
		while (1) {
			_26$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			if (!(ZEPHIR_GT_LONG(_26$$4, y))) {
				break;
			}
			ZEPHIR_SINIT_NVAR(_27$$5);
			ZVAL_LONG(&_27$$5, x);
			ZEPHIR_SINIT_NVAR(_28$$5);
			ZVAL_LONG(&_28$$5, y);
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_29, 280, maskImage, &_27$$5, &_28$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_30, 281, maskImage, index);
			zephir_check_call_status();
			if (zephir_array_isset_string(color, SS("red"))) {
				zephir_array_fetch_string(&_31$$6, color, SL("red"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 431 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_32$$6);
				ZVAL_DOUBLE(&_32$$6, zephir_safe_div_zval_long(_31$$6, 2 TSRMLS_CC));
				alpha = (127 - zephir_get_intval(&_32$$6));
			}
			_33$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_27$$5);
			ZVAL_LONG(&_27$$5, x);
			ZEPHIR_SINIT_NVAR(_28$$5);
			ZVAL_LONG(&_28$$5, y);
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_29, 280, _33$$5, &_27$$5, &_28$$5);
			zephir_check_call_status();
			_34$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_30, 281, _34$$5, index);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(r);
			zephir_array_fetch_string(&r, color, SL("red"), PH_NOISY, "phalcon/image/adapter/gd.zep", 436 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(g);
			zephir_array_fetch_string(&g, color, SL("green"), PH_NOISY, "phalcon/image/adapter/gd.zep", 436 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(b);
			zephir_array_fetch_string(&b, color, SL("blue"), PH_NOISY, "phalcon/image/adapter/gd.zep", 436 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_27$$5);
			ZVAL_LONG(&_27$$5, alpha);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_10, 264, newimage, r, g, b, &_27$$5);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_27$$5);
			ZVAL_LONG(&_27$$5, x);
			ZEPHIR_SINIT_NVAR(_28$$5);
			ZVAL_LONG(&_28$$5, y);
			ZEPHIR_CALL_FUNCTION(NULL, "imagesetpixel", &_35, 282, newimage, &_27$$5, &_28$$5, color);
			zephir_check_call_status();
			y++;
		}
		x++;
	}
	_36 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_24, 258, _36);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_24, 258, maskImage);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_image"), newimage TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _background) {

	zval *r_param = NULL, *g_param = NULL, *b_param = NULL, *opacity_param = NULL, *background = NULL, *color = NULL, *_0, *_1, _2 = zval_used_for_init, _3 = zval_used_for_init, _4 = zval_used_for_init, _5 = zval_used_for_init, *_6, *_7, *_8, *_9 = NULL, *_10$$3;
	int r, g, b, opacity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &r_param, &g_param, &b_param, &opacity_param);

	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	opacity = zephir_get_intval(opacity_param);


	opacity = (long) (((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&background, this_ptr, "_create", NULL, 0, _0, _1);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, r);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, g);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, b);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, opacity);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 264, background, &_2, &_3, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 256, background, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 0);
	ZEPHIR_CALL_FUNCTION(&_9, "imagecopy", NULL, 267, background, _6, &_2, &_3, &_4, &_5, _7, _8);
	zephir_check_call_status();
	if (zephir_is_true(_9)) {
		_10$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 258, _10$$3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), background TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _blur) {

	zephir_fcall_cache_entry *_2 = NULL;
	zval *radius_param = NULL, *_0$$3, _1$$3 = zval_used_for_init;
	int radius, ZEPHIR_LAST_CALL_STATUS, i = 0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);

	radius = zephir_get_intval(radius_param);


	i = 0;
	while (1) {
		if (!(i < radius)) {
			break;
		}
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_1$$3);
		ZVAL_LONG(&_1$$3, 7);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", &_2, 270, _0$$3, &_1$$3);
		zephir_check_call_status();
		i++;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _pixelate) {

	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	zval *amount_param = NULL, *color = NULL, *_0, *_1$$3, *_2$$4, _3$$4 = zval_used_for_init, _4$$4 = zval_used_for_init, *_6$$4, _7$$4 = zval_used_for_init, _8$$4 = zval_used_for_init;
	int amount, ZEPHIR_LAST_CALL_STATUS, x = 0, y = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	x = 0;
	while (1) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		if (!(ZEPHIR_GT_LONG(_0, x))) {
			break;
		}
		y = 0;
		while (1) {
			_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			if (!(ZEPHIR_GT_LONG(_1$$3, y))) {
				break;
			}
			x1 = (x + zephir_safe_div_long_long(amount, 2 TSRMLS_CC));
			y1 = (y + zephir_safe_div_long_long(amount, 2 TSRMLS_CC));
			_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_3$$4);
			ZVAL_LONG(&_3$$4, x1);
			ZEPHIR_SINIT_NVAR(_4$$4);
			ZVAL_LONG(&_4$$4, y1);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorat", &_5, 280, _2$$4, &_3$$4, &_4$$4);
			zephir_check_call_status();
			x2 = (x + amount);
			y2 = (y + amount);
			_6$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_3$$4);
			ZVAL_LONG(&_3$$4, x);
			ZEPHIR_SINIT_NVAR(_4$$4);
			ZVAL_LONG(&_4$$4, y);
			ZEPHIR_SINIT_NVAR(_7$$4);
			ZVAL_LONG(&_7$$4, x2);
			ZEPHIR_SINIT_NVAR(_8$$4);
			ZVAL_LONG(&_8$$4, y2);
			ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", &_9, 273, _6$$4, &_3$$4, &_4$$4, &_7$$4, &_8$$4, color);
			zephir_check_call_status();
			y += amount;
		}
		x += amount;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _save) {

	zend_bool _10;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_16 = NULL;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality_param = NULL, *ext = NULL, _0 = zval_used_for_init, *_2 = NULL, *_3 = NULL, *_9 = NULL, *_11 = NULL, *_18 = NULL, *_22 = NULL, *_26 = NULL, *_30, *_1$$3, *_5$$4, *_6$$4 = NULL, *_8$$4, *_12$$5, *_13$$5 = NULL, *_14$$6, _15$$6, *_17$$9, *_19$$10, *_20$$10 = NULL, *_21$$10, *_23$$11, *_24$$11 = NULL, *_25$$11, *_27$$12, *_28$$12 = NULL, *_29$$12;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &file_param, &quality_param);

	zephir_get_strval(file, file_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&ext, "pathinfo", NULL, 76, file, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(ext))) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&ext, "image_type_to_extension", NULL, 283, _1$$3, ZEPHIR_GLOBAL(global_false));
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_strtolower(_2, ext);
	ZEPHIR_CPY_WRT(ext, _2);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "gif", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "strcmp", &_4, 284, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_3, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_5$$4);
		ZVAL_LONG(_5$$4, 1);
		zephir_update_property_this(this_ptr, SL("_type"), _5$$4 TSRMLS_CC);
		_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_6$$4, "image_type_to_mime_type", &_7, 285, _5$$4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _6$$4 TSRMLS_CC);
		_8$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, 286, _8$$4, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "jpg", 0);
	ZEPHIR_CALL_FUNCTION(&_9, "strcmp", &_4, 284, ext, &_0);
	zephir_check_call_status();
	_10 = ZEPHIR_IS_LONG(_9, 0);
	if (!(_10)) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "jpeg", 0);
		ZEPHIR_CALL_FUNCTION(&_11, "strcmp", &_4, 284, ext, &_0);
		zephir_check_call_status();
		_10 = ZEPHIR_IS_LONG(_11, 0);
	}
	if (_10) {
		ZEPHIR_INIT_ZVAL_NREF(_12$$5);
		ZVAL_LONG(_12$$5, 2);
		zephir_update_property_this(this_ptr, SL("_type"), _12$$5 TSRMLS_CC);
		_12$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_13$$5, "image_type_to_mime_type", &_7, 285, _12$$5);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _13$$5 TSRMLS_CC);
		if (quality >= 0) {
			if (quality < 1) {
				quality = 1;
			} else if (quality > 100) {
				quality = 100;
			}
			_14$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_15$$6);
			ZVAL_LONG(&_15$$6, quality);
			ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", &_16, 287, _14$$6, file, &_15$$6);
			zephir_check_call_status();
		} else {
			_17$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", &_16, 287, _17$$9, file);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "png", 0);
	ZEPHIR_CALL_FUNCTION(&_18, "strcmp", &_4, 284, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_18, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_19$$10);
		ZVAL_LONG(_19$$10, 3);
		zephir_update_property_this(this_ptr, SL("_type"), _19$$10 TSRMLS_CC);
		_19$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_20$$10, "image_type_to_mime_type", &_7, 285, _19$$10);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _20$$10 TSRMLS_CC);
		_21$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagepng", NULL, 288, _21$$10, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "wbmp", 0);
	ZEPHIR_CALL_FUNCTION(&_22, "strcmp", &_4, 284, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_22, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_23$$11);
		ZVAL_LONG(_23$$11, 15);
		zephir_update_property_this(this_ptr, SL("_type"), _23$$11 TSRMLS_CC);
		_23$$11 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_24$$11, "image_type_to_mime_type", &_7, 285, _23$$11);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _24$$11 TSRMLS_CC);
		_25$$11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, 289, _25$$11, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "xbm", 0);
	ZEPHIR_CALL_FUNCTION(&_26, "strcmp", &_4, 284, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_26, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_27$$12);
		ZVAL_LONG(_27$$12, 16);
		zephir_update_property_this(this_ptr, SL("_type"), _27$$12 TSRMLS_CC);
		_27$$12 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_28$$12, "image_type_to_mime_type", &_7, 285, _27$$12);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _28$$12 TSRMLS_CC);
		_29$$12 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, 290, _29$$12, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(_30);
	ZEPHIR_CONCAT_SVS(_30, "Installed GD does not support '", ext, "' images");
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 9, _30);
	zephir_check_call_status();
	zephir_throw_exception_debug(_2, "phalcon/image/adapter/gd.zep", 555 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _render) {

	zend_bool _7;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *ext_param = NULL, *quality_param = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, *_6 = NULL, *_8 = NULL, *_11 = NULL, *_13 = NULL, *_15 = NULL, *_17, *_4$$3, *_9$$4, _10$$4, *_12$$5, *_14$$6, *_16$$7;
	zval *ext = NULL, *_18;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ext_param, &quality_param);

	zephir_get_strval(ext, ext_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, ext);
	zephir_get_strval(ext, _0);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 127);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "gif", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "strcmp", &_3, 284, ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_2, 0)) {
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, 286, _4$$3);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5, 291);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "jpg", 0);
	ZEPHIR_CALL_FUNCTION(&_6, "strcmp", &_3, 284, ext, &_1);
	zephir_check_call_status();
	_7 = ZEPHIR_IS_LONG(_6, 0);
	if (!(_7)) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "jpeg", 0);
		ZEPHIR_CALL_FUNCTION(&_8, "strcmp", &_3, 284, ext, &_1);
		zephir_check_call_status();
		_7 = ZEPHIR_IS_LONG(_8, 0);
	}
	if (_7) {
		_9$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_10$$4);
		ZVAL_LONG(&_10$$4, quality);
		ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, 287, _9$$4, ZEPHIR_GLOBAL(global_null), &_10$$4);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5, 291);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "png", 0);
	ZEPHIR_CALL_FUNCTION(&_11, "strcmp", &_3, 284, ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_11, 0)) {
		_12$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagepng", NULL, 288, _12$$5);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5, 291);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "wbmp", 0);
	ZEPHIR_CALL_FUNCTION(&_13, "strcmp", &_3, 284, ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_13, 0)) {
		_14$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, 289, _14$$6);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5, 291);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "xbm", 0);
	ZEPHIR_CALL_FUNCTION(&_15, "strcmp", &_3, 284, ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_15, 0)) {
		_16$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, 290, _16$$7, ZEPHIR_GLOBAL(global_null));
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5, 291);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_17);
	object_init_ex(_17, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(_18);
	ZEPHIR_CONCAT_SVS(_18, "Installed GD does not support '", ext, "' images");
	ZEPHIR_CALL_METHOD(NULL, _17, "__construct", NULL, 9, _18);
	zephir_check_call_status();
	zephir_throw_exception_debug(_17, "phalcon/image/adapter/gd.zep", 583 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _create) {

	zval *width_param = NULL, *height_param = NULL, *image = NULL, _0, _1;
	int width, height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, width);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, height);
	ZEPHIR_CALL_FUNCTION(&image, "imagecreatetruecolor", NULL, 255, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 256, image, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 254, image, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_CCTOR(image);

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, __destruct) {

	zval *image = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(image);
	zephir_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	if (Z_TYPE_P(image) == IS_RESOURCE) {
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 258, image);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

