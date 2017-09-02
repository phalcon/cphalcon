
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

	return SUCCESS;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, check) {

	zval __$true, version, info, matches, _0, _1, _2, _6, _7, _10, _3$$6, _4$$6, _5$$6, _8$$8, _9$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, phalcon_image_adapter_gd_ce, SL("_checked"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	if (!((zephir_function_exists_ex(SL("gd_info") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "GD is either not installed or not enabled, check your configuration", "phalcon/image/adapter/gd.zep", 38);
		return;
	}
	ZEPHIR_INIT_VAR(&version);
	ZVAL_NULL(&version);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "GD_VERSION");
	ZEPHIR_CALL_FUNCTION(&_2, "defined", NULL, 216, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_NVAR(&version);
		ZEPHIR_GET_CONSTANT(&version, "GD_VERSION");
	} else {
		ZEPHIR_CALL_FUNCTION(&info, "gd_info", NULL, 226);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&matches);
		ZVAL_NULL(&matches);
		ZEPHIR_INIT_VAR(&_3$$6);
		zephir_array_fetch_string(&_4$$6, &info, SL("GD Version"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 46 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_5$$6);
		ZVAL_STRING(&_5$$6, "/\\d+\\.\\d+(?:\\.\\d+)?/");
		zephir_preg_match(&_3$$6, &_5$$6, &_4$$6, &matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(&_3$$6)) {
			ZEPHIR_OBS_NVAR(&version);
			zephir_array_fetch_long(&version, &matches, 0, PH_NOISY, "phalcon/image/adapter/gd.zep", 47 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "2.0.1");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, ">=");
	ZEPHIR_CALL_FUNCTION(&_7, "version_compare", NULL, 227, &version, &_1, &_6);
	zephir_check_call_status();
	if (!(zephir_is_true(&_7))) {
		ZEPHIR_INIT_VAR(&_8$$8);
		object_init_ex(&_8$$8, phalcon_image_exception_ce);
		ZEPHIR_INIT_VAR(&_9$$8);
		ZEPHIR_CONCAT_SV(&_9$$8, "Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have ", &version);
		ZEPHIR_CALL_METHOD(NULL, &_8$$8, "__construct", NULL, 4, &_9$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$8, "phalcon/image/adapter/gd.zep", 52 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zend_update_static_property(phalcon_image_adapter_gd_ce, ZEND_STRL("_checked"), &__$true);
	zephir_read_static_property_ce(&_10, phalcon_image_adapter_gd_ce, SL("_checked"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_10);

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, __construct) {

	zend_bool _26$$14;
	zephir_fcall_cache_entry *_25 = NULL;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, __$true, imageinfo, _0, _1, _2$$4, _3$$4, _4$$4, _9$$4, _24$$4, _5$$5, _6$$5, _7$$5, _8$$5, _10$$6, _11$$6, _12$$7, _13$$7, _14$$8, _15$$8, _16$$9, _17$$9, _18$$10, _19$$10, _20$$11, _21$$12, _22$$12, _23$$12, _30$$14, _31$$14, _32$$14, _33$$14, _34$$14, _35$$14, _27$$15, _28$$15, _29$$15;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&imageinfo);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_24$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_33$$14);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$15);

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


	zephir_read_static_property_ce(&_0, phalcon_image_adapter_gd_ce, SL("_checked"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_SELF(NULL, "check", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("_file"), &file);
	zephir_read_property(&_1, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
	if ((zephir_file_exists(&_1 TSRMLS_CC) == SUCCESS)) {
		zephir_read_property(&_2$$4, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_3$$4, "realpath", NULL, 59, &_2$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_realpath"), &_3$$4);
		zephir_read_property(&_4$$4, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&imageinfo, "getimagesize", NULL, 228, &_4$$4);
		zephir_check_call_status();
		if (zephir_is_true(&imageinfo)) {
			zephir_array_fetch_long(&_5$$5, &imageinfo, 0, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 76 TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("_width"), &_5$$5);
			zephir_array_fetch_long(&_6$$5, &imageinfo, 1, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 77 TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("_height"), &_6$$5);
			zephir_array_fetch_long(&_7$$5, &imageinfo, 2, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 78 TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("_type"), &_7$$5);
			zephir_array_fetch_string(&_8$$5, &imageinfo, SL("mime"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 79 TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("_mime"), &_8$$5);
		}
		zephir_read_property(&_9$$4, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
		do {
			if (ZEPHIR_IS_LONG(&_9$$4, 1)) {
				zephir_read_property(&_10$$6, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_11$$6, "imagecreatefromgif", NULL, 229, &_10$$6);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("_image"), &_11$$6);
				break;
			}
			if (ZEPHIR_IS_LONG(&_9$$4, 2)) {
				zephir_read_property(&_12$$7, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_13$$7, "imagecreatefromjpeg", NULL, 230, &_12$$7);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("_image"), &_13$$7);
				break;
			}
			if (ZEPHIR_IS_LONG(&_9$$4, 3)) {
				zephir_read_property(&_14$$8, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_15$$8, "imagecreatefrompng", NULL, 231, &_14$$8);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("_image"), &_15$$8);
				break;
			}
			if (ZEPHIR_IS_LONG(&_9$$4, 15)) {
				zephir_read_property(&_16$$9, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_17$$9, "imagecreatefromwbmp", NULL, 232, &_16$$9);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("_image"), &_17$$9);
				break;
			}
			if (ZEPHIR_IS_LONG(&_9$$4, 16)) {
				zephir_read_property(&_18$$10, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_19$$10, "imagecreatefromxbm", NULL, 233, &_18$$10);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("_image"), &_19$$10);
				break;
			}
			zephir_read_property(&_20$$11, this_ptr, SL("_mime"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_20$$11)) {
				ZEPHIR_INIT_VAR(&_21$$12);
				object_init_ex(&_21$$12, phalcon_image_exception_ce);
				zephir_read_property(&_22$$12, this_ptr, SL("_mime"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_23$$12);
				ZEPHIR_CONCAT_SVS(&_23$$12, "Installed GD does not support ", &_22$$12, " images");
				ZEPHIR_CALL_METHOD(NULL, &_21$$12, "__construct", NULL, 4, &_23$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_21$$12, "phalcon/image/adapter/gd.zep", 100 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Installed GD does not support such images", "phalcon/image/adapter/gd.zep", 102);
				return;
			}
			break;
		} while(0);

		zephir_read_property(&_24$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_25, 234, &_24$$4, &__$true);
		zephir_check_call_status();
	} else {
		_26$$14 = !width;
		if (!(_26$$14)) {
			_26$$14 = !height;
		}
		if (_26$$14) {
			ZEPHIR_INIT_VAR(&_27$$15);
			object_init_ex(&_27$$15, phalcon_image_exception_ce);
			zephir_read_property(&_28$$15, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_29$$15);
			ZEPHIR_CONCAT_SV(&_29$$15, "Failed to create image from file ", &_28$$15);
			ZEPHIR_CALL_METHOD(NULL, &_27$$15, "__construct", NULL, 4, &_29$$15);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_27$$15, "phalcon/image/adapter/gd.zep", 111 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_30$$14, width);
		ZVAL_LONG(&_31$$14, height);
		ZEPHIR_CALL_FUNCTION(&_32$$14, "imagecreatetruecolor", NULL, 235, &_30$$14, &_31$$14);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_image"), &_32$$14);
		zephir_read_property(&_30$$14, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 236, &_30$$14, &__$true);
		zephir_check_call_status();
		zephir_read_property(&_31$$14, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_25, 234, &_31$$14, &__$true);
		zephir_check_call_status();
		zephir_read_property(&_33$$14, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("_realpath"), &_33$$14);
		ZEPHIR_INIT_ZVAL_NREF(_34$$14);
		ZVAL_LONG(&_34$$14, width);
		zephir_update_property_zval(this_ptr, SL("_width"), &_34$$14);
		ZEPHIR_INIT_ZVAL_NREF(_34$$14);
		ZVAL_LONG(&_34$$14, height);
		zephir_update_property_zval(this_ptr, SL("_height"), &_34$$14);
		ZEPHIR_INIT_ZVAL_NREF(_34$$14);
		ZVAL_LONG(&_34$$14, 3);
		zephir_update_property_zval(this_ptr, SL("_type"), &_34$$14);
		ZEPHIR_INIT_VAR(&_35$$14);
		ZEPHIR_INIT_NVAR(&_35$$14);
		ZVAL_STRING(&_35$$14, "image/png");
		zephir_update_property_zval(this_ptr, SL("_mime"), &_35$$14);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _resize) {

	zend_bool _4$$3, _8$$4;
	zephir_fcall_cache_entry *_9 = NULL, *_19 = NULL, *_30 = NULL, *_32 = NULL;
	zval *width_param = NULL, *height_param = NULL, image, pre_width, pre_height, reduction_width, reduction_height, _0, _1, _2, _3$$3, _5$$3, _20$$3, _21$$3, _22$$3, _23$$3, _24$$3, _25$$3, _26$$3, _27$$3, _6$$4, _7$$4, _10$$4, _11$$4, _12$$4, _13$$4, _14$$4, _15$$4, _16$$4, _17$$4, _18$$6, _28$$7, _29$$7, _31$$7, _33$$8, _34$$8, _35$$8, _36$$8, _37$$8;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&pre_width);
	ZVAL_UNDEF(&pre_height);
	ZVAL_UNDEF(&reduction_width);
	ZVAL_UNDEF(&reduction_height);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_24$$3);
	ZVAL_UNDEF(&_25$$3);
	ZVAL_UNDEF(&_26$$3);
	ZVAL_UNDEF(&_27$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_35$$8);
	ZVAL_UNDEF(&_36$$8);
	ZVAL_UNDEF(&_37$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_VERSION");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "5.5.0");
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", NULL, 227, &_0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(&_2, 0)) {
		ZEPHIR_OBS_VAR(&pre_width);
		zephir_read_property(&pre_width, this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&pre_height);
		zephir_read_property(&pre_height, this_ptr, SL("_height"), PH_NOISY_CC);
		zephir_read_property(&_3$$3, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		_4$$3 = width > (zephir_safe_div_zval_long(&_3$$3, 2 TSRMLS_CC));
		if (_4$$3) {
			zephir_read_property(&_5$$3, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
			_4$$3 = height > (zephir_safe_div_zval_long(&_5$$3, 2 TSRMLS_CC));
		}
		if (_4$$3) {
			ZVAL_LONG(&_6$$4, (width * 1.1));
			ZEPHIR_INIT_VAR(&reduction_width);
			zephir_round(&reduction_width, &_6$$4, NULL, NULL TSRMLS_CC);
			ZVAL_LONG(&_7$$4, (height * 1.1));
			ZEPHIR_INIT_VAR(&reduction_height);
			zephir_round(&reduction_height, &_7$$4, NULL, NULL TSRMLS_CC);
			while (1) {
				_8$$4 = ZEPHIR_LT_LONG(&reduction_width, zephir_safe_div_zval_long(&pre_width, 2 TSRMLS_CC));
				if (_8$$4) {
					_8$$4 = ZEPHIR_LT_LONG(&reduction_height, zephir_safe_div_zval_long(&pre_height, 2 TSRMLS_CC));
				}
				if (!(_8$$4)) {
					break;
				}
				ZEPHIR_INIT_NVAR(&pre_width);
				ZVAL_DOUBLE(&pre_width, 2);
				ZEPHIR_INIT_NVAR(&pre_height);
				ZVAL_DOUBLE(&pre_height, 2);
			}
			ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", &_9, 0, &pre_width, &pre_height);
			zephir_check_call_status();
			zephir_read_property(&_10$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_11$$4, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_12$$4, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_13$$4, 0);
			ZVAL_LONG(&_14$$4, 0);
			ZVAL_LONG(&_15$$4, 0);
			ZVAL_LONG(&_16$$4, 0);
			ZEPHIR_CALL_FUNCTION(&_17$$4, "imagecopyresized", NULL, 237, &image, &_10$$4, &_13$$4, &_14$$4, &_15$$4, &_16$$4, &pre_width, &pre_height, &_11$$4, &_12$$4);
			zephir_check_call_status();
			if (zephir_is_true(&_17$$4)) {
				zephir_read_property(&_18$$6, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_19, 238, &_18$$6);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("_image"), &image);
			}
		}
		ZVAL_LONG(&_20$$3, width);
		ZVAL_LONG(&_21$$3, height);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", &_9, 0, &_20$$3, &_21$$3);
		zephir_check_call_status();
		zephir_read_property(&_20$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_21$$3, 0);
		ZVAL_LONG(&_22$$3, 0);
		ZVAL_LONG(&_23$$3, 0);
		ZVAL_LONG(&_24$$3, 0);
		ZVAL_LONG(&_25$$3, width);
		ZVAL_LONG(&_26$$3, height);
		ZEPHIR_CALL_FUNCTION(&_27$$3, "imagecopyresampled", NULL, 239, &image, &_20$$3, &_21$$3, &_22$$3, &_23$$3, &_24$$3, &_25$$3, &_26$$3, &pre_width, &pre_height);
		zephir_check_call_status();
		if (zephir_is_true(&_27$$3)) {
			zephir_read_property(&_28$$7, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_19, 238, &_28$$7);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_image"), &image);
			ZEPHIR_CALL_FUNCTION(&_29$$7, "imagesx", &_30, 240, &image);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_width"), &_29$$7);
			ZEPHIR_CALL_FUNCTION(&_31$$7, "imagesy", &_32, 241, &image);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_height"), &_31$$7);
		}
	} else {
		zephir_read_property(&_33$$8, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_34$$8, width);
		ZVAL_LONG(&_35$$8, height);
		ZEPHIR_CALL_FUNCTION(&image, "imagescale", NULL, 242, &_33$$8, &_34$$8, &_35$$8);
		zephir_check_call_status();
		zephir_read_property(&_34$$8, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_19, 238, &_34$$8);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_image"), &image);
		ZEPHIR_CALL_FUNCTION(&_36$$8, "imagesx", &_30, 240, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_width"), &_36$$8);
		ZEPHIR_CALL_FUNCTION(&_37$$8, "imagesy", &_32, 241, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_height"), &_37$$8);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _crop) {

	zephir_fcall_cache_entry *_14 = NULL, *_16 = NULL, *_18 = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, image, rect, _0, _1, _2, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, _12$$3, _13$$4, _15$$4, _17$$4, _19$$5, _20$$5, _21$$5, _22$$5, _23$$5;
	zend_long width, height, offsetX, offsetY, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&rect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_23$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &offsetX_param, &offsetY_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_VERSION");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "5.5.0");
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", NULL, 227, &_0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(&_2, 0)) {
		ZVAL_LONG(&_3$$3, width);
		ZVAL_LONG(&_4$$3, height);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", NULL, 0, &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_read_property(&_3$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_4$$3, 0);
		ZVAL_LONG(&_5$$3, 0);
		ZVAL_LONG(&_6$$3, offsetX);
		ZVAL_LONG(&_7$$3, offsetY);
		ZVAL_LONG(&_8$$3, width);
		ZVAL_LONG(&_9$$3, height);
		ZVAL_LONG(&_10$$3, width);
		ZVAL_LONG(&_11$$3, height);
		ZEPHIR_CALL_FUNCTION(&_12$$3, "imagecopyresampled", NULL, 239, &image, &_3$$3, &_4$$3, &_5$$3, &_6$$3, &_7$$3, &_8$$3, &_9$$3, &_10$$3, &_11$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_12$$3)) {
			zephir_read_property(&_13$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_14, 238, &_13$$4);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_image"), &image);
			ZEPHIR_CALL_FUNCTION(&_15$$4, "imagesx", &_16, 240, &image);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_width"), &_15$$4);
			ZEPHIR_CALL_FUNCTION(&_17$$4, "imagesy", &_18, 241, &image);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_height"), &_17$$4);
		}
	} else {
		ZEPHIR_INIT_VAR(&rect);
		zephir_create_array(&rect, 4, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_19$$5);
		ZVAL_LONG(&_19$$5, offsetX);
		zephir_array_update_string(&rect, SL("x"), &_19$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_19$$5);
		ZVAL_LONG(&_19$$5, offsetY);
		zephir_array_update_string(&rect, SL("y"), &_19$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_19$$5);
		ZVAL_LONG(&_19$$5, width);
		zephir_array_update_string(&rect, SL("width"), &_19$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_19$$5);
		ZVAL_LONG(&_19$$5, height);
		zephir_array_update_string(&rect, SL("height"), &_19$$5, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_20$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&image, "imagecrop", NULL, 243, &_20$$5, &rect);
		zephir_check_call_status();
		zephir_read_property(&_21$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_14, 238, &_21$$5);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_image"), &image);
		ZEPHIR_CALL_FUNCTION(&_22$$5, "imagesx", &_16, 240, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_width"), &_22$$5);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "imagesy", &_18, 241, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_height"), &_23$$5);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _rotate) {

	zval *degrees_param = NULL, __$true, image, transparent, width, height, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9$$3;
	zend_long degrees, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&transparent);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);

	degrees = zephir_get_intval(degrees_param);


	zephir_read_property(&_0, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 0);
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 127);
	ZEPHIR_CALL_FUNCTION(&transparent, "imagecolorallocatealpha", NULL, 244, &_0, &_1, &_2, &_3, &_4);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, (360 - degrees));
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&image, "imagerotate", NULL, 245, &_1, &_2, &transparent, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 234, &image, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&width, "imagesx", NULL, 240, &image);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&height, "imagesy", NULL, 241, &image);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 0);
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 0);
	ZVAL_LONG(&_7, 100);
	ZEPHIR_CALL_FUNCTION(&_8, "imagecopymerge", NULL, 246, &_2, &image, &_3, &_4, &_5, &_6, &width, &height, &_7);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		zephir_read_property(&_9$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 238, &_9$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_image"), &image);
		zephir_update_property_zval(this_ptr, SL("_width"), &width);
		zephir_update_property_zval(this_ptr, SL("_height"), &height);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _flip) {

	zephir_fcall_cache_entry *_14 = NULL, *_29 = NULL;
	zval *direction_param = NULL, image, _0, _1, _2, _3$$3, _4$$3, _24$$3, _25$$3, _26$$3, _5$$4, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _11$$5, _12$$5, _13$$5, _15$$6, _16$$7, _17$$7, _18$$7, _19$$7, _20$$7, _21$$7, _22$$7, _23$$7, _27$$9, _28$$9, _30$$10, _31$$10;
	zend_long direction, ZEPHIR_LAST_CALL_STATUS, x = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_24$$3);
	ZVAL_UNDEF(&_25$$3);
	ZVAL_UNDEF(&_26$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_30$$10);
	ZVAL_UNDEF(&_31$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

	direction = zephir_get_intval(direction_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_VERSION");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "5.5.0");
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", NULL, 227, &_0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(&_2, 0)) {
		zephir_read_property(&_3$$3, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_4$$3, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", NULL, 0, &_3$$3, &_4$$3);
		zephir_check_call_status();
		if (direction == 11) {
			x = 0;
			while (1) {
				zephir_read_property(&_5$$4, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
				if (!(ZEPHIR_GT_LONG(&_5$$4, x))) {
					break;
				}
				x++;
				zephir_read_property(&_6$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_7$$5, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_8$$5, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_9$$5, x);
				ZVAL_LONG(&_10$$5, 0);
				ZVAL_LONG(&_11$$5, ((zephir_get_numberval(&_7$$5) - x) - 1));
				ZVAL_LONG(&_12$$5, 0);
				ZVAL_LONG(&_13$$5, 1);
				ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_14, 247, &image, &_6$$5, &_9$$5, &_10$$5, &_11$$5, &_12$$5, &_13$$5, &_8$$5);
				zephir_check_call_status();
			}
		} else {
			x = 0;
			while (1) {
				zephir_read_property(&_15$$6, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
				if (!(ZEPHIR_GT_LONG(&_15$$6, x))) {
					break;
				}
				x++;
				zephir_read_property(&_16$$7, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_17$$7, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_18$$7, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_19$$7, 0);
				ZVAL_LONG(&_20$$7, x);
				ZVAL_LONG(&_21$$7, 0);
				ZVAL_LONG(&_22$$7, ((zephir_get_numberval(&_17$$7) - x) - 1));
				ZVAL_LONG(&_23$$7, 1);
				ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_14, 247, &image, &_16$$7, &_19$$7, &_20$$7, &_21$$7, &_22$$7, &_18$$7, &_23$$7);
				zephir_check_call_status();
			}
		}
		zephir_read_property(&_24$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 238, &_24$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_image"), &image);
		ZEPHIR_CALL_FUNCTION(&_25$$3, "imagesx", NULL, 240, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_width"), &_25$$3);
		ZEPHIR_CALL_FUNCTION(&_26$$3, "imagesy", NULL, 241, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_height"), &_26$$3);
	} else {
		if (direction == 11) {
			zephir_read_property(&_27$$9, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_28$$9, 1);
			ZEPHIR_CALL_FUNCTION(NULL, "imageflip", &_29, 248, &_27$$9, &_28$$9);
			zephir_check_call_status();
		} else {
			zephir_read_property(&_30$$10, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_31$$10, 2);
			ZEPHIR_CALL_FUNCTION(NULL, "imageflip", &_29, 248, &_30$$10, &_31$$10);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _sharpen) {

	zval _3;
	zval *amount_param = NULL, matrix, _0, _1, _2, _4, _5, _6, _7, _8, _9$$3, _10$$3, _11$$3, _12$$3;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matrix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_1, (-18 + ((amount * 0.08))));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 190, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 2);
	zephir_round(&_0, &_2, &_1, NULL TSRMLS_CC);
	amount = zephir_get_intval(&_0);
	ZEPHIR_INIT_VAR(&matrix);
	zephir_create_array(&matrix, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	zephir_array_fast_append(&matrix, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_create_array(&_3, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, amount);
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	zephir_array_fast_append(&matrix, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_create_array(&_3, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	zephir_array_fast_append(&matrix, &_3);
	zephir_read_property(&_5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_6, (amount - 8));
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(&_8, "imageconvolution", NULL, 249, &_5, &matrix, &_6, &_7);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		zephir_read_property(&_9$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_10$$3, "imagesx", NULL, 240, &_9$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_width"), &_10$$3);
		zephir_read_property(&_11$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_12$$3, "imagesy", NULL, 241, &_11$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_height"), &_12$$3);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _reflection) {

	zephir_fcall_cache_entry *_5 = NULL, *_12 = NULL, *_27 = NULL;
	zend_bool fadeIn;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, reflection, line, _0, _1, _2, _3, _4, _6, _7, _8, _9, _10, _11, _29, _30, _13$$5, _14$$5, _19$$5, _20$$5, _21$$5, _22$$5, _23$$5, _24$$5, _25$$5, _26$$5, _28$$5, _15$$6, _16$$6, _17$$7, _18$$7;
	zend_long height, opacity, ZEPHIR_LAST_CALL_STATUS, stepping = 0, offset = 0, src_y = 0, dst_y = 0, dst_opacity = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_28$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &height_param, &opacity_param, &fadeIn_param);

	height = zephir_get_intval(height_param);
	opacity = zephir_get_intval(opacity_param);
	fadeIn = zephir_get_boolval(fadeIn_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_DOUBLE(&_1, ((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 190, &_1);
	zephir_check_call_status();
	zephir_round(&_0, &_2, NULL, NULL TSRMLS_CC);
	opacity = zephir_get_intval(&_0);
	if (opacity < 127) {
		stepping = (long) (zephir_safe_div_long_long(((127 - opacity)), height TSRMLS_CC));
	} else {
		stepping = (long) (zephir_safe_div_long_long(127, height TSRMLS_CC));
	}
	zephir_read_property(&_1, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, (zephir_get_numberval(&_3) + height));
	ZEPHIR_CALL_METHOD(&reflection, this_ptr, "_create", &_5, 0, &_1, &_4);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_6, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_7, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 0);
	ZVAL_LONG(&_10, 0);
	ZVAL_LONG(&_11, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_12, 247, &reflection, &_4, &_8, &_9, &_10, &_11, &_6, &_7);
	zephir_check_call_status();
	offset = 0;
	while (1) {
		if (!(height >= offset)) {
			break;
		}
		zephir_read_property(&_13$$5, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		src_y = ((zephir_get_numberval(&_13$$5) - offset) - 1);
		zephir_read_property(&_14$$5, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		dst_y = (zephir_get_numberval(&_14$$5) + offset);
		if (fadeIn) {
			ZEPHIR_INIT_NVAR(&_15$$6);
			ZVAL_LONG(&_16$$6, (opacity + ((stepping * ((height - offset))))));
			zephir_round(&_15$$6, &_16$$6, NULL, NULL TSRMLS_CC);
			dst_opacity = zephir_get_intval(&_15$$6);
		} else {
			ZEPHIR_INIT_NVAR(&_17$$7);
			ZVAL_LONG(&_18$$7, (opacity + ((stepping * offset))));
			zephir_round(&_17$$7, &_18$$7, NULL, NULL TSRMLS_CC);
			dst_opacity = zephir_get_intval(&_17$$7);
		}
		zephir_read_property(&_19$$5, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_20$$5, 1);
		ZEPHIR_CALL_METHOD(&line, this_ptr, "_create", &_5, 0, &_19$$5, &_20$$5);
		zephir_check_call_status();
		zephir_read_property(&_20$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_21$$5, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_22$$5, 0);
		ZVAL_LONG(&_23$$5, 0);
		ZVAL_LONG(&_24$$5, 0);
		ZVAL_LONG(&_25$$5, src_y);
		ZVAL_LONG(&_26$$5, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_12, 247, &line, &_20$$5, &_22$$5, &_23$$5, &_24$$5, &_25$$5, &_21$$5, &_26$$5);
		zephir_check_call_status();
		ZVAL_LONG(&_22$$5, 4);
		ZVAL_LONG(&_23$$5, 0);
		ZVAL_LONG(&_24$$5, 0);
		ZVAL_LONG(&_25$$5, 0);
		ZVAL_LONG(&_26$$5, dst_opacity);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", &_27, 250, &line, &_22$$5, &_23$$5, &_24$$5, &_25$$5, &_26$$5);
		zephir_check_call_status();
		zephir_read_property(&_22$$5, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_23$$5, 0);
		ZVAL_LONG(&_24$$5, dst_y);
		ZVAL_LONG(&_25$$5, 0);
		ZVAL_LONG(&_26$$5, 0);
		ZVAL_LONG(&_28$$5, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_12, 247, &reflection, &line, &_23$$5, &_24$$5, &_25$$5, &_26$$5, &_22$$5, &_28$$5);
		zephir_check_call_status();
		offset++;
	}
	zephir_read_property(&_8, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 238, &_8);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_image"), &reflection);
	ZEPHIR_CALL_FUNCTION(&_29, "imagesx", NULL, 240, &reflection);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_width"), &_29);
	ZEPHIR_CALL_FUNCTION(&_30, "imagesy", NULL, 241, &reflection);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_height"), &_30);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _watermark) {

	zend_long offsetX, offsetY, opacity, ZEPHIR_LAST_CALL_STATUS, width = 0, height = 0;
	zval *watermark, watermark_sub, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, __$true, overlay, color, _0, _1, _2, _9, _10, _11, _12, _13, _14, _15, _16, _17, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&watermark_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&overlay);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &watermark, &offsetX_param, &offsetY_param, &opacity_param);

	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);


	ZEPHIR_CALL_METHOD(&_0, watermark, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&overlay, "imagecreatefromstring", NULL, 251, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 234, &overlay, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, 240, &overlay);
	zephir_check_call_status();
	width = zephir_get_intval(&_1);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, 241, &overlay);
	zephir_check_call_status();
	height = zephir_get_intval(&_2);
	if (opacity < 100) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_DOUBLE(&_4$$3, ((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
		ZEPHIR_CALL_FUNCTION(&_5$$3, "abs", NULL, 190, &_4$$3);
		zephir_check_call_status();
		zephir_round(&_3$$3, &_5$$3, NULL, NULL TSRMLS_CC);
		opacity = zephir_get_intval(&_3$$3);
		ZVAL_LONG(&_4$$3, 127);
		ZVAL_LONG(&_6$$3, 127);
		ZVAL_LONG(&_7$$3, 127);
		ZVAL_LONG(&_8$$3, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 244, &overlay, &_4$$3, &_6$$3, &_7$$3, &_8$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, 3);
		ZEPHIR_CALL_FUNCTION(NULL, "imagelayereffect", NULL, 252, &overlay, &_4$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, 0);
		ZVAL_LONG(&_6$$3, 0);
		ZVAL_LONG(&_7$$3, width);
		ZVAL_LONG(&_8$$3, height);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", NULL, 253, &overlay, &_4$$3, &_6$$3, &_7$$3, &_8$$3, &color);
		zephir_check_call_status();
	}
	zephir_read_property(&_9, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 236, &_9, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_10, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_11, offsetX);
	ZVAL_LONG(&_12, offsetY);
	ZVAL_LONG(&_13, 0);
	ZVAL_LONG(&_14, 0);
	ZVAL_LONG(&_15, width);
	ZVAL_LONG(&_16, height);
	ZEPHIR_CALL_FUNCTION(&_17, "imagecopy", NULL, 247, &_10, &overlay, &_11, &_12, &_13, &_14, &_15, &_16);
	zephir_check_call_status();
	if (zephir_is_true(&_17)) {
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 238, &overlay);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _text) {

	zend_bool _10$$3, _11$$3, _12$$3;
	zephir_fcall_cache_entry *_3 = NULL, *_20 = NULL;
	zend_long offsetX, offsetY, opacity, r, g, b, size, ZEPHIR_LAST_CALL_STATUS, angle = 0, s0, s1, s4, s5, width = 0, height = 0;
	zval *text_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *size_param = NULL, *fontfile_param = NULL, space, color, _0, _1, _2, _4$$3, _5$$3, _13$$3, _14$$3, _17$$3, _18$$3, _19$$3, _21$$3, _6$$4, _7$$4, _8$$4, _9$$4, _15$$6, _16$$7, _22$$8, _23$$8, _24$$8, _27$$8, _28$$8, _29$$8, _30$$8, _25$$9, _26$$10;
	zval text, fontfile;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&fontfile);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 9, 0, &text_param, &offsetX_param, &offsetY_param, &opacity_param, &r_param, &g_param, &b_param, &size_param, &fontfile_param);

	zephir_get_strval(&text, text_param);
	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);
	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	size = zephir_get_intval(size_param);
	zephir_get_strval(&fontfile, fontfile_param);


	s0 = 0;
	s1 = 0;
	s4 = 0;
	s5 = 0;
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_DOUBLE(&_1, ((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", &_3, 190, &_1);
	zephir_check_call_status();
	zephir_round(&_0, &_2, NULL, NULL TSRMLS_CC);
	opacity = zephir_get_intval(&_0);
	if (!(Z_TYPE_P(&fontfile) == IS_UNDEF) && Z_STRLEN_P(&fontfile)) {
		ZVAL_LONG(&_4$$3, size);
		ZVAL_LONG(&_5$$3, 0);
		ZEPHIR_CALL_FUNCTION(&space, "imagettfbbox", NULL, 0, &_4$$3, &_5$$3, &fontfile, &text);
		zephir_check_call_status();
		if (zephir_array_isset_long(&space, 0)) {
			ZEPHIR_OBS_VAR(&_6$$4);
			zephir_array_fetch_long(&_6$$4, &space, 0, PH_NOISY, "phalcon/image/adapter/gd.zep", 350 TSRMLS_CC);
			s0 = zephir_get_intval(&_6$$4);
			ZEPHIR_OBS_VAR(&_7$$4);
			zephir_array_fetch_long(&_7$$4, &space, 1, PH_NOISY, "phalcon/image/adapter/gd.zep", 351 TSRMLS_CC);
			s1 = zephir_get_intval(&_7$$4);
			ZEPHIR_OBS_VAR(&_8$$4);
			zephir_array_fetch_long(&_8$$4, &space, 4, PH_NOISY, "phalcon/image/adapter/gd.zep", 352 TSRMLS_CC);
			s4 = zephir_get_intval(&_8$$4);
			ZEPHIR_OBS_VAR(&_9$$4);
			zephir_array_fetch_long(&_9$$4, &space, 5, PH_NOISY, "phalcon/image/adapter/gd.zep", 353 TSRMLS_CC);
			s5 = zephir_get_intval(&_9$$4);
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Call to imagettfbbox() failed", "phalcon/image/adapter/gd.zep", 357);
			return;
		}
		ZVAL_LONG(&_4$$3, (s4 - s0));
		ZEPHIR_CALL_FUNCTION(&_13$$3, "abs", &_3, 190, &_4$$3);
		zephir_check_call_status();
		width = (zephir_get_numberval(&_13$$3) + 10);
		ZVAL_LONG(&_4$$3, (s5 - s1));
		ZEPHIR_CALL_FUNCTION(&_14$$3, "abs", &_3, 190, &_4$$3);
		zephir_check_call_status();
		height = (zephir_get_numberval(&_14$$3) + 10);
		if (offsetX < 0) {
			zephir_read_property(&_15$$6, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
			offsetX = ((zephir_get_numberval(&_15$$6) - width) + offsetX);
		}
		if (offsetY < 0) {
			zephir_read_property(&_16$$7, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
			offsetY = ((zephir_get_numberval(&_16$$7) - height) + offsetY);
		}
		zephir_read_property(&_4$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_5$$3, r);
		ZVAL_LONG(&_17$$3, g);
		ZVAL_LONG(&_18$$3, b);
		ZVAL_LONG(&_19$$3, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_20, 244, &_4$$3, &_5$$3, &_17$$3, &_18$$3, &_19$$3);
		zephir_check_call_status();
		angle = 0;
		zephir_read_property(&_5$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_17$$3, size);
		ZVAL_LONG(&_18$$3, angle);
		ZVAL_LONG(&_19$$3, offsetX);
		ZVAL_LONG(&_21$$3, offsetY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", NULL, 0, &_5$$3, &_17$$3, &_18$$3, &_19$$3, &_21$$3, &color, &fontfile, &text);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_22$$8, size);
		ZEPHIR_CALL_FUNCTION(&_23$$8, "imagefontwidth", NULL, 254, &_22$$8);
		zephir_check_call_status();
		width = (zephir_get_intval(&_23$$8) * zephir_fast_strlen_ev(&text));
		ZVAL_LONG(&_22$$8, size);
		ZEPHIR_CALL_FUNCTION(&_24$$8, "imagefontheight", NULL, 255, &_22$$8);
		zephir_check_call_status();
		height = zephir_get_intval(&_24$$8);
		if (offsetX < 0) {
			zephir_read_property(&_25$$9, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
			offsetX = ((zephir_get_numberval(&_25$$9) - width) + offsetX);
		}
		if (offsetY < 0) {
			zephir_read_property(&_26$$10, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
			offsetY = ((zephir_get_numberval(&_26$$10) - height) + offsetY);
		}
		zephir_read_property(&_22$$8, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_27$$8, r);
		ZVAL_LONG(&_28$$8, g);
		ZVAL_LONG(&_29$$8, b);
		ZVAL_LONG(&_30$$8, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_20, 244, &_22$$8, &_27$$8, &_28$$8, &_29$$8, &_30$$8);
		zephir_check_call_status();
		zephir_read_property(&_27$$8, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_28$$8, size);
		ZVAL_LONG(&_29$$8, offsetX);
		ZVAL_LONG(&_30$$8, offsetY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagestring", NULL, 256, &_27$$8, &_28$$8, &_29$$8, &_30$$8, &text, &color);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _mask) {

	zend_bool _11;
	zephir_fcall_cache_entry *_3 = NULL, *_10 = NULL, *_22 = NULL, *_26 = NULL, *_27 = NULL, *_32 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, mask_width = 0, mask_height = 0, x = 0, y = 0, alpha = 0;
	zval *mask, mask_sub, __$true, maskImage, newimage, tempImage, color, index, r, g, b, _0, _1, _2, _4, _5, _6, _7, _8, _9, _12$$3, _13$$3, _14$$3, _15$$3, _16$$3, _17$$3, _18$$3, _19$$3, _20$$3, _21$$3, _23$$4, _24$$5, _25$$5, _30$$5, _31$$5, _28$$6, _29$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mask_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&maskImage);
	ZVAL_UNDEF(&newimage);
	ZVAL_UNDEF(&tempImage);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&r);
	ZVAL_UNDEF(&g);
	ZVAL_UNDEF(&b);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_23$$4);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_30$$5);
	ZVAL_UNDEF(&_31$$5);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_29$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mask);



	ZEPHIR_CALL_METHOD(&_0, mask, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&maskImage, "imagecreatefromstring", NULL, 251, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, 240, &maskImage);
	zephir_check_call_status();
	mask_width = zephir_get_intval(&_1);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, 241, &maskImage);
	zephir_check_call_status();
	mask_height = zephir_get_intval(&_2);
	alpha = 127;
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_3, 234, &maskImage, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&newimage, this_ptr, "_create", NULL, 0, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_3, 234, &newimage, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_6, 0);
	ZVAL_LONG(&_7, 0);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, alpha);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_10, 244, &newimage, &_6, &_7, &_8, &_9);
	zephir_check_call_status();
	ZVAL_LONG(&_6, 0);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagefill", NULL, 257, &newimage, &_6, &_7, &color);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
	_11 = !ZEPHIR_IS_LONG(&_6, mask_width);
	if (!(_11)) {
		zephir_read_property(&_7, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		_11 = !ZEPHIR_IS_LONG(&_7, mask_height);
	}
	if (_11) {
		zephir_read_property(&_12$$3, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_13$$3, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&tempImage, "imagecreatetruecolor", NULL, 235, &_12$$3, &_13$$3);
		zephir_check_call_status();
		zephir_read_property(&_14$$3, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_15$$3, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_16$$3, 0);
		ZVAL_LONG(&_17$$3, 0);
		ZVAL_LONG(&_18$$3, 0);
		ZVAL_LONG(&_19$$3, 0);
		ZVAL_LONG(&_20$$3, mask_width);
		ZVAL_LONG(&_21$$3, mask_height);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopyresampled", NULL, 239, &tempImage, &maskImage, &_16$$3, &_17$$3, &_18$$3, &_19$$3, &_14$$3, &_15$$3, &_20$$3, &_21$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_22, 238, &maskImage);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&maskImage, &tempImage);
	}
	x = 0;
	while (1) {
		zephir_read_property(&_8, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		if (!(ZEPHIR_GT_LONG(&_8, x))) {
			break;
		}
		y = 0;
		while (1) {
			zephir_read_property(&_23$$4, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
			if (!(ZEPHIR_GT_LONG(&_23$$4, y))) {
				break;
			}
			ZVAL_LONG(&_24$$5, x);
			ZVAL_LONG(&_25$$5, y);
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_26, 258, &maskImage, &_24$$5, &_25$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_27, 259, &maskImage, &index);
			zephir_check_call_status();
			if (zephir_array_isset_string(&color, SL("red"))) {
				zephir_array_fetch_string(&_28$$6, &color, SL("red"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 430 TSRMLS_CC);
				ZVAL_DOUBLE(&_29$$6, zephir_safe_div_zval_long(&_28$$6, 2 TSRMLS_CC));
				alpha = (127 - zephir_get_intval(&_29$$6));
			}
			zephir_read_property(&_24$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_25$$5, x);
			ZVAL_LONG(&_30$$5, y);
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_26, 258, &_24$$5, &_25$$5, &_30$$5);
			zephir_check_call_status();
			zephir_read_property(&_25$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_27, 259, &_25$$5, &index);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&r);
			zephir_array_fetch_string(&r, &color, SL("red"), PH_NOISY, "phalcon/image/adapter/gd.zep", 435 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&g);
			zephir_array_fetch_string(&g, &color, SL("green"), PH_NOISY, "phalcon/image/adapter/gd.zep", 435 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&b);
			zephir_array_fetch_string(&b, &color, SL("blue"), PH_NOISY, "phalcon/image/adapter/gd.zep", 435 TSRMLS_CC);
			ZVAL_LONG(&_30$$5, alpha);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_10, 244, &newimage, &r, &g, &b, &_30$$5);
			zephir_check_call_status();
			ZVAL_LONG(&_30$$5, x);
			ZVAL_LONG(&_31$$5, y);
			ZEPHIR_CALL_FUNCTION(NULL, "imagesetpixel", &_32, 260, &newimage, &_30$$5, &_31$$5, &color);
			zephir_check_call_status();
			y++;
		}
		x++;
	}
	zephir_read_property(&_9, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_22, 238, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_22, 238, &maskImage);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_image"), &newimage);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _background) {

	zval *r_param = NULL, *g_param = NULL, *b_param = NULL, *opacity_param = NULL, __$true, background, color, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10$$3;
	zend_long r, g, b, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&background);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &r_param, &g_param, &b_param, &opacity_param);

	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	opacity = zephir_get_intval(opacity_param);


	opacity = (long) (((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
	zephir_read_property(&_0, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&background, this_ptr, "_create", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_2, r);
	ZVAL_LONG(&_3, g);
	ZVAL_LONG(&_4, b);
	ZVAL_LONG(&_5, opacity);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 244, &background, &_2, &_3, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 236, &background, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 0);
	ZVAL_LONG(&_7, 0);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_CALL_FUNCTION(&_9, "imagecopy", NULL, 247, &background, &_2, &_5, &_6, &_7, &_8, &_3, &_4);
	zephir_check_call_status();
	if (zephir_is_true(&_9)) {
		zephir_read_property(&_10$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 238, &_10$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_image"), &background);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _blur) {

	zephir_fcall_cache_entry *_2 = NULL;
	zval *radius_param = NULL, _0$$3, _1$$3;
	zend_long radius, ZEPHIR_LAST_CALL_STATUS, i = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);

	radius = zephir_get_intval(radius_param);


	i = 0;
	while (1) {
		if (!(i < radius)) {
			break;
		}
		zephir_read_property(&_0$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_1$$3, 7);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", &_2, 250, &_0$$3, &_1$$3);
		zephir_check_call_status();
		i++;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _pixelate) {

	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	zval *amount_param = NULL, color, _0, _1$$3, _2$$4, _3$$4, _4$$4, _6$$4, _7$$4, _8$$4;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS, x = 0, y = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	x = 0;
	while (1) {
		zephir_read_property(&_0, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		if (!(ZEPHIR_GT_LONG(&_0, x))) {
			break;
		}
		y = 0;
		while (1) {
			zephir_read_property(&_1$$3, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
			if (!(ZEPHIR_GT_LONG(&_1$$3, y))) {
				break;
			}
			x1 = (x + zephir_safe_div_long_long(amount, 2 TSRMLS_CC));
			y1 = (y + zephir_safe_div_long_long(amount, 2 TSRMLS_CC));
			zephir_read_property(&_2$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_3$$4, x1);
			ZVAL_LONG(&_4$$4, y1);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorat", &_5, 258, &_2$$4, &_3$$4, &_4$$4);
			zephir_check_call_status();
			x2 = (x + amount);
			y2 = (y + amount);
			zephir_read_property(&_3$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_4$$4, x);
			ZVAL_LONG(&_6$$4, y);
			ZVAL_LONG(&_7$$4, x2);
			ZVAL_LONG(&_8$$4, y2);
			ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", &_9, 253, &_3$$4, &_4$$4, &_6$$4, &_7$$4, &_8$$4, &color);
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
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality_param = NULL, __$false, ext, _0, _2, _3, _9, _11, _18, _22, _26, _30, _1$$3, _5$$4, _6$$4, _8$$4, _12$$5, _13$$5, _14$$6, _15$$6, _17$$9, _19$$10, _20$$10, _21$$10, _23$$11, _24$$11, _25$$11, _27$$12, _28$$12, _29$$12;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &file_param, &quality_param);

	zephir_get_strval(&file, file_param);
	quality = zephir_get_intval(quality_param);


	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&ext, "pathinfo", NULL, 69, &file, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&ext))) {
		zephir_read_property(&_1$$3, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&ext, "image_type_to_extension", NULL, 261, &_1$$3, &__$false);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strtolower(&_2, &ext);
	ZEPHIR_CPY_WRT(&ext, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "gif");
	ZEPHIR_CALL_FUNCTION(&_3, "strcmp", &_4, 262, &ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_3, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_5$$4);
		ZVAL_LONG(&_5$$4, 1);
		zephir_update_property_zval(this_ptr, SL("_type"), &_5$$4);
		zephir_read_property(&_5$$4, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_6$$4, "image_type_to_mime_type", &_7, 263, &_5$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_mime"), &_6$$4);
		zephir_read_property(&_8$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, 264, &_8$$4, &file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "jpg");
	ZEPHIR_CALL_FUNCTION(&_9, "strcmp", &_4, 262, &ext, &_2);
	zephir_check_call_status();
	_10 = ZEPHIR_IS_LONG(&_9, 0);
	if (!(_10)) {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "jpeg");
		ZEPHIR_CALL_FUNCTION(&_11, "strcmp", &_4, 262, &ext, &_2);
		zephir_check_call_status();
		_10 = ZEPHIR_IS_LONG(&_11, 0);
	}
	if (_10) {
		ZEPHIR_INIT_ZVAL_NREF(_12$$5);
		ZVAL_LONG(&_12$$5, 2);
		zephir_update_property_zval(this_ptr, SL("_type"), &_12$$5);
		zephir_read_property(&_12$$5, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_13$$5, "image_type_to_mime_type", &_7, 263, &_12$$5);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_mime"), &_13$$5);
		if (quality >= 0) {
			if (quality < 1) {
				quality = 1;
			} else if (quality > 100) {
				quality = 100;
			}
			zephir_read_property(&_14$$6, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_15$$6, quality);
			ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", &_16, 265, &_14$$6, &file, &_15$$6);
			zephir_check_call_status();
		} else {
			zephir_read_property(&_17$$9, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", &_16, 265, &_17$$9, &file);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "png");
	ZEPHIR_CALL_FUNCTION(&_18, "strcmp", &_4, 262, &ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_18, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_19$$10);
		ZVAL_LONG(&_19$$10, 3);
		zephir_update_property_zval(this_ptr, SL("_type"), &_19$$10);
		zephir_read_property(&_19$$10, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_20$$10, "image_type_to_mime_type", &_7, 263, &_19$$10);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_mime"), &_20$$10);
		zephir_read_property(&_21$$10, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagepng", NULL, 266, &_21$$10, &file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "wbmp");
	ZEPHIR_CALL_FUNCTION(&_22, "strcmp", &_4, 262, &ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_22, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_23$$11);
		ZVAL_LONG(&_23$$11, 15);
		zephir_update_property_zval(this_ptr, SL("_type"), &_23$$11);
		zephir_read_property(&_23$$11, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_24$$11, "image_type_to_mime_type", &_7, 263, &_23$$11);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_mime"), &_24$$11);
		zephir_read_property(&_25$$11, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, 267, &_25$$11, &file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "xbm");
	ZEPHIR_CALL_FUNCTION(&_26, "strcmp", &_4, 262, &ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_26, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_27$$12);
		ZVAL_LONG(&_27$$12, 16);
		zephir_update_property_zval(this_ptr, SL("_type"), &_27$$12);
		zephir_read_property(&_27$$12, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_28$$12, "image_type_to_mime_type", &_7, 263, &_27$$12);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_mime"), &_28$$12);
		zephir_read_property(&_29$$12, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, 268, &_29$$12, &file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(&_30);
	ZEPHIR_CONCAT_SVS(&_30, "Installed GD does not support '", &ext, "' images");
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 4, &_30);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_2, "phalcon/image/adapter/gd.zep", 554 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _render) {

	zend_bool _7;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *ext_param = NULL, *quality_param = NULL, __$null, _0, _1, _2, _6, _8, _11, _13, _15, _4$$3, _9$$4, _10$$4, _12$$5, _14$$6, _16$$7;
	zval ext, _17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&_17);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_16$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ext_param, &quality_param);

	zephir_get_strval(&ext, ext_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &ext);
	zephir_get_strval(&ext, &_0);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 125);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "gif");
	ZEPHIR_CALL_FUNCTION(&_2, "strcmp", &_3, 262, &ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_2, 0)) {
		zephir_read_property(&_4$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, 264, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5, 269);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "jpg");
	ZEPHIR_CALL_FUNCTION(&_6, "strcmp", &_3, 262, &ext, &_1);
	zephir_check_call_status();
	_7 = ZEPHIR_IS_LONG(&_6, 0);
	if (!(_7)) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "jpeg");
		ZEPHIR_CALL_FUNCTION(&_8, "strcmp", &_3, 262, &ext, &_1);
		zephir_check_call_status();
		_7 = ZEPHIR_IS_LONG(&_8, 0);
	}
	if (_7) {
		zephir_read_property(&_9$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_10$$4, quality);
		ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, 265, &_9$$4, &__$null, &_10$$4);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5, 269);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "png");
	ZEPHIR_CALL_FUNCTION(&_11, "strcmp", &_3, 262, &ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_11, 0)) {
		zephir_read_property(&_12$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagepng", NULL, 266, &_12$$5);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5, 269);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "wbmp");
	ZEPHIR_CALL_FUNCTION(&_13, "strcmp", &_3, 262, &ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_13, 0)) {
		zephir_read_property(&_14$$6, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, 267, &_14$$6);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5, 269);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "xbm");
	ZEPHIR_CALL_FUNCTION(&_15, "strcmp", &_3, 262, &ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_15, 0)) {
		zephir_read_property(&_16$$7, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, 268, &_16$$7, &__$null);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5, 269);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(&_17);
	ZEPHIR_CONCAT_SVS(&_17, "Installed GD does not support '", &ext, "' images");
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 4, &_17);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "phalcon/image/adapter/gd.zep", 582 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _create) {

	zval *width_param = NULL, *height_param = NULL, __$false, __$true, image, _0, _1;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	ZVAL_LONG(&_0, width);
	ZVAL_LONG(&_1, height);
	ZEPHIR_CALL_FUNCTION(&image, "imagecreatetruecolor", NULL, 235, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 236, &image, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 234, &image, &__$true);
	zephir_check_call_status();
	RETURN_CCTOR(&image);

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, __destruct) {

	zval image;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&image);
	zephir_read_property(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	if (Z_TYPE_P(&image) == IS_RESOURCE) {
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 238, &image);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

