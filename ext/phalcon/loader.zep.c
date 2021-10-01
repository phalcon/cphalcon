
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/require.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This component helps to load your project classes automatically based on some
 * conventions
 *
 *```php
 * use Phalcon\Loader;
 *
 * // Creates the autoloader
 * $loader = new Loader();
 *
 * // Register some namespaces
 * $loader->registerNamespaces(
 *     [
 *         "Example\\Base"    => "vendor/example/base/",
 *         "Example\\Adapter" => "vendor/example/adapter/",
 *         "Example"          => "vendor/example/",
 *     ]
 * );
 *
 * // Register autoloader
 * $loader->register();
 *
 * // Requiring this class will automatically include file vendor/example/adapter/Some.php
 * $adapter = new \Example\Adapter\Some();
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Loader)
{
	ZEPHIR_REGISTER_CLASS(Phalcon, Loader, phalcon, loader, phalcon_loader_method_entry, 0);

	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_loader_ce, SL("checkedPath"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_loader_ce, SL("classes"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_loader_ce, SL("directories"), ZEND_ACC_PROTECTED);
	/**
	 * @var ManagerInterface|null
	 */
	zend_declare_property_null(phalcon_loader_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_loader_ce, SL("extensions"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_loader_ce, SL("fileCheckingCallback"), "is_file", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_loader_ce, SL("files"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_loader_ce, SL("foundPath"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_loader_ce, SL("namespaces"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_loader_ce, SL("registered"), 0, ZEND_ACC_PROTECTED);
	phalcon_loader_ce->create_object = zephir_init_properties_Phalcon_Loader;

	zend_class_implements(phalcon_loader_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;
}

/**
 * Autoloads the registered classes
 */
PHP_METHOD(Phalcon_Loader, autoLoad)
{
	zend_string *_6;
	zend_ulong _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_16 = NULL, *_18 = NULL, *_20 = NULL, *_22 = NULL, *_25 = NULL, *_30 = NULL, *_33 = NULL, *_35 = NULL, *_38 = NULL, *_48 = NULL, *_51 = NULL, *_53 = NULL, *_56 = NULL, *_61 = NULL, *_64 = NULL, *_66 = NULL, *_69 = NULL, *_76 = NULL, *_79 = NULL, *_81 = NULL, *_84 = NULL, *_89 = NULL, *_92 = NULL, *_94 = NULL, *_97 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, eventsManager, classes, extensions, filePath, ds, fixedDirectory, directories, ns, namespaces, nsPrefix, directory, fileName, extension, nsClassName, fileCheckingCallback, _0, *_3, _4, *_70, _71, _1$$3, _2$$5, _7$$6, _8$$6, _9$$6, *_10$$6, _11$$6, _12$$9, *_13$$9, _14$$9, _15$$11, _17$$10, _19$$13, _21$$15, _23$$14, _24$$17, _26$$18, *_27$$18, _28$$18, _29$$20, _31$$19, _32$$22, _34$$24, _36$$23, _37$$26, _39$$27, _40$$27, _41$$27, *_42$$27, _43$$27, _44$$30, *_45$$30, _46$$30, _47$$32, _49$$31, _50$$34, _52$$36, _54$$35, _55$$38, _57$$39, *_58$$39, _59$$39, _60$$41, _62$$40, _63$$43, _65$$45, _67$$44, _68$$47, _72$$48, *_73$$48, _74$$48, _75$$50, _77$$49, _78$$52, _80$$54, _82$$53, _83$$56, _85$$57, *_86$$57, _87$$57, _88$$59, _90$$58, _91$$61, _93$$63, _95$$62, _96$$65, _98$$66;
	zval className;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&ds);
	ZVAL_UNDEF(&fixedDirectory);
	ZVAL_UNDEF(&directories);
	ZVAL_UNDEF(&ns);
	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&nsPrefix);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&fileName);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&nsClassName);
	ZVAL_UNDEF(&fileCheckingCallback);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_71);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_29$$20);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_32$$22);
	ZVAL_UNDEF(&_34$$24);
	ZVAL_UNDEF(&_36$$23);
	ZVAL_UNDEF(&_37$$26);
	ZVAL_UNDEF(&_39$$27);
	ZVAL_UNDEF(&_40$$27);
	ZVAL_UNDEF(&_41$$27);
	ZVAL_UNDEF(&_43$$27);
	ZVAL_UNDEF(&_44$$30);
	ZVAL_UNDEF(&_46$$30);
	ZVAL_UNDEF(&_47$$32);
	ZVAL_UNDEF(&_49$$31);
	ZVAL_UNDEF(&_50$$34);
	ZVAL_UNDEF(&_52$$36);
	ZVAL_UNDEF(&_54$$35);
	ZVAL_UNDEF(&_55$$38);
	ZVAL_UNDEF(&_57$$39);
	ZVAL_UNDEF(&_59$$39);
	ZVAL_UNDEF(&_60$$41);
	ZVAL_UNDEF(&_62$$40);
	ZVAL_UNDEF(&_63$$43);
	ZVAL_UNDEF(&_65$$45);
	ZVAL_UNDEF(&_67$$44);
	ZVAL_UNDEF(&_68$$47);
	ZVAL_UNDEF(&_72$$48);
	ZVAL_UNDEF(&_74$$48);
	ZVAL_UNDEF(&_75$$50);
	ZVAL_UNDEF(&_77$$49);
	ZVAL_UNDEF(&_78$$52);
	ZVAL_UNDEF(&_80$$54);
	ZVAL_UNDEF(&_82$$53);
	ZVAL_UNDEF(&_83$$56);
	ZVAL_UNDEF(&_85$$57);
	ZVAL_UNDEF(&_87$$57);
	ZVAL_UNDEF(&_88$$59);
	ZVAL_UNDEF(&_90$$58);
	ZVAL_UNDEF(&_91$$61);
	ZVAL_UNDEF(&_93$$63);
	ZVAL_UNDEF(&_95$$62);
	ZVAL_UNDEF(&_96$$65);
	ZVAL_UNDEF(&_98$$66);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);
	if (UNEXPECTED(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(className_param) == IS_STRING)) {
		zephir_get_strval(&className, className_param);
	} else {
		ZEPHIR_INIT_VAR(&className);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "loader:beforeCheckClass");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_1$$3, this_ptr, &className);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("classes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&classes, &_0);
	ZEPHIR_OBS_VAR(&filePath);
	if (zephir_array_isset_fetch(&filePath, &classes, &className, 0)) {
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &filePath);
			ZEPHIR_INIT_VAR(&_2$$5);
			ZVAL_STRING(&_2$$5, "loader:pathFound");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_2$$5, this_ptr, &filePath);
			zephir_check_call_status();
		}
		if (zephir_require_once_zval(&filePath) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("extensions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&extensions, &_0);
	ZEPHIR_INIT_VAR(&ds);
	ZVAL_STRING(&ds, "/");
	ZEPHIR_INIT_VAR(&ns);
	ZVAL_STRING(&ns, "\\");
	zephir_read_property(&_0, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&namespaces, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("fileCheckingCallback"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&fileCheckingCallback, &_0);
	zephir_is_iterable(&namespaces, 0, "phalcon/Loader.zep", 208);
	if (Z_TYPE_P(&namespaces) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&namespaces), _5, _6, _3)
		{
			ZEPHIR_INIT_NVAR(&nsPrefix);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&nsPrefix, _6);
			} else {
				ZVAL_LONG(&nsPrefix, _5);
			}
			ZEPHIR_INIT_NVAR(&directories);
			ZVAL_COPY(&directories, _3);
			if (!(zephir_start_with(&className, &nsPrefix, NULL))) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_7$$6);
			ZEPHIR_CONCAT_VV(&_7$$6, &nsPrefix, &ns);
			ZVAL_LONG(&_8$$6, zephir_fast_strlen_ev(&_7$$6));
			ZEPHIR_INIT_NVAR(&fileName);
			zephir_substr(&fileName, &className, zephir_get_intval(&_8$$6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			if (!(zephir_is_true(&fileName))) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_9$$6);
			zephir_fast_str_replace(&_9$$6, &ns, &ds, &fileName);
			ZEPHIR_CPY_WRT(&fileName, &_9$$6);
			zephir_is_iterable(&directories, 0, "phalcon/Loader.zep", 203);
			if (Z_TYPE_P(&directories) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&directories), _10$$6)
				{
					ZEPHIR_INIT_NVAR(&directory);
					ZVAL_COPY(&directory, _10$$6);
					ZEPHIR_INIT_NVAR(&_12$$9);
					zephir_fast_trim(&_12$$9, &directory, &ds, ZEPHIR_TRIM_RIGHT);
					ZEPHIR_INIT_NVAR(&fixedDirectory);
					ZEPHIR_CONCAT_VV(&fixedDirectory, &_12$$9, &ds);
					zephir_is_iterable(&extensions, 0, "phalcon/Loader.zep", 202);
					if (Z_TYPE_P(&extensions) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _13$$9)
						{
							ZEPHIR_INIT_NVAR(&extension);
							ZVAL_COPY(&extension, _13$$9);
							ZEPHIR_INIT_NVAR(&filePath);
							ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &fileName, ".", &extension);
							if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
								zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
								ZEPHIR_INIT_NVAR(&_15$$11);
								ZVAL_STRING(&_15$$11, "loader:beforeCheckPath");
								ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_16, 0, &_15$$11, this_ptr);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_FUNCTION(&_17$$10, "call_user_func", &_18, 257, &fileCheckingCallback, &filePath);
							zephir_check_call_status();
							if (zephir_is_true(&_17$$10)) {
								if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
									zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &filePath);
									ZEPHIR_INIT_NVAR(&_19$$13);
									ZVAL_STRING(&_19$$13, "loader:pathFound");
									ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_20, 0, &_19$$13, this_ptr, &filePath);
									zephir_check_call_status();
								}
								if (zephir_require_once_zval(&filePath) == FAILURE) {
									RETURN_MM_NULL();
								}
								RETURN_MM_BOOL(1);
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &extensions, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_14$$9, &extensions, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_14$$9)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&extension, &extensions, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&filePath);
								ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &fileName, ".", &extension);
								if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
									zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
									ZEPHIR_INIT_NVAR(&_21$$15);
									ZVAL_STRING(&_21$$15, "loader:beforeCheckPath");
									ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_22, 0, &_21$$15, this_ptr);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_FUNCTION(&_23$$14, "call_user_func", &_18, 257, &fileCheckingCallback, &filePath);
								zephir_check_call_status();
								if (zephir_is_true(&_23$$14)) {
									if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
										zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &filePath);
										ZEPHIR_INIT_NVAR(&_24$$17);
										ZVAL_STRING(&_24$$17, "loader:pathFound");
										ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_25, 0, &_24$$17, this_ptr, &filePath);
										zephir_check_call_status();
									}
									if (zephir_require_once_zval(&filePath) == FAILURE) {
										RETURN_MM_NULL();
									}
									RETURN_MM_BOOL(1);
								}
							ZEPHIR_CALL_METHOD(NULL, &extensions, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&extension);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &directories, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_11$$6, &directories, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_11$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&directory, &directories, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_26$$18);
						zephir_fast_trim(&_26$$18, &directory, &ds, ZEPHIR_TRIM_RIGHT);
						ZEPHIR_INIT_NVAR(&fixedDirectory);
						ZEPHIR_CONCAT_VV(&fixedDirectory, &_26$$18, &ds);
						zephir_is_iterable(&extensions, 0, "phalcon/Loader.zep", 202);
						if (Z_TYPE_P(&extensions) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _27$$18)
							{
								ZEPHIR_INIT_NVAR(&extension);
								ZVAL_COPY(&extension, _27$$18);
								ZEPHIR_INIT_NVAR(&filePath);
								ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &fileName, ".", &extension);
								if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
									zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
									ZEPHIR_INIT_NVAR(&_29$$20);
									ZVAL_STRING(&_29$$20, "loader:beforeCheckPath");
									ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_30, 0, &_29$$20, this_ptr);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_FUNCTION(&_31$$19, "call_user_func", &_18, 257, &fileCheckingCallback, &filePath);
								zephir_check_call_status();
								if (zephir_is_true(&_31$$19)) {
									if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
										zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &filePath);
										ZEPHIR_INIT_NVAR(&_32$$22);
										ZVAL_STRING(&_32$$22, "loader:pathFound");
										ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_33, 0, &_32$$22, this_ptr, &filePath);
										zephir_check_call_status();
									}
									if (zephir_require_once_zval(&filePath) == FAILURE) {
										RETURN_MM_NULL();
									}
									RETURN_MM_BOOL(1);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &extensions, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_28$$18, &extensions, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_28$$18)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&extension, &extensions, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&filePath);
									ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &fileName, ".", &extension);
									if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
										zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
										ZEPHIR_INIT_NVAR(&_34$$24);
										ZVAL_STRING(&_34$$24, "loader:beforeCheckPath");
										ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_35, 0, &_34$$24, this_ptr);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_FUNCTION(&_36$$23, "call_user_func", &_18, 257, &fileCheckingCallback, &filePath);
									zephir_check_call_status();
									if (zephir_is_true(&_36$$23)) {
										if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
											zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &filePath);
											ZEPHIR_INIT_NVAR(&_37$$26);
											ZVAL_STRING(&_37$$26, "loader:pathFound");
											ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_38, 0, &_37$$26, this_ptr, &filePath);
											zephir_check_call_status();
										}
										if (zephir_require_once_zval(&filePath) == FAILURE) {
											RETURN_MM_NULL();
										}
										RETURN_MM_BOOL(1);
									}
								ZEPHIR_CALL_METHOD(NULL, &extensions, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&extension);
					ZEPHIR_CALL_METHOD(NULL, &directories, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&directory);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &namespaces, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &namespaces, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&nsPrefix, &namespaces, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&directories, &namespaces, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_start_with(&className, &nsPrefix, NULL))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_39$$27);
				ZEPHIR_CONCAT_VV(&_39$$27, &nsPrefix, &ns);
				ZVAL_LONG(&_40$$27, zephir_fast_strlen_ev(&_39$$27));
				ZEPHIR_INIT_NVAR(&fileName);
				zephir_substr(&fileName, &className, zephir_get_intval(&_40$$27), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				if (!(zephir_is_true(&fileName))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_41$$27);
				zephir_fast_str_replace(&_41$$27, &ns, &ds, &fileName);
				ZEPHIR_CPY_WRT(&fileName, &_41$$27);
				zephir_is_iterable(&directories, 0, "phalcon/Loader.zep", 203);
				if (Z_TYPE_P(&directories) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&directories), _42$$27)
					{
						ZEPHIR_INIT_NVAR(&directory);
						ZVAL_COPY(&directory, _42$$27);
						ZEPHIR_INIT_NVAR(&_44$$30);
						zephir_fast_trim(&_44$$30, &directory, &ds, ZEPHIR_TRIM_RIGHT);
						ZEPHIR_INIT_NVAR(&fixedDirectory);
						ZEPHIR_CONCAT_VV(&fixedDirectory, &_44$$30, &ds);
						zephir_is_iterable(&extensions, 0, "phalcon/Loader.zep", 202);
						if (Z_TYPE_P(&extensions) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _45$$30)
							{
								ZEPHIR_INIT_NVAR(&extension);
								ZVAL_COPY(&extension, _45$$30);
								ZEPHIR_INIT_NVAR(&filePath);
								ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &fileName, ".", &extension);
								if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
									zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
									ZEPHIR_INIT_NVAR(&_47$$32);
									ZVAL_STRING(&_47$$32, "loader:beforeCheckPath");
									ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_48, 0, &_47$$32, this_ptr);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_FUNCTION(&_49$$31, "call_user_func", &_18, 257, &fileCheckingCallback, &filePath);
								zephir_check_call_status();
								if (zephir_is_true(&_49$$31)) {
									if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
										zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &filePath);
										ZEPHIR_INIT_NVAR(&_50$$34);
										ZVAL_STRING(&_50$$34, "loader:pathFound");
										ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_51, 0, &_50$$34, this_ptr, &filePath);
										zephir_check_call_status();
									}
									if (zephir_require_once_zval(&filePath) == FAILURE) {
										RETURN_MM_NULL();
									}
									RETURN_MM_BOOL(1);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &extensions, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_46$$30, &extensions, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_46$$30)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&extension, &extensions, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&filePath);
									ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &fileName, ".", &extension);
									if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
										zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
										ZEPHIR_INIT_NVAR(&_52$$36);
										ZVAL_STRING(&_52$$36, "loader:beforeCheckPath");
										ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_53, 0, &_52$$36, this_ptr);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_FUNCTION(&_54$$35, "call_user_func", &_18, 257, &fileCheckingCallback, &filePath);
									zephir_check_call_status();
									if (zephir_is_true(&_54$$35)) {
										if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
											zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &filePath);
											ZEPHIR_INIT_NVAR(&_55$$38);
											ZVAL_STRING(&_55$$38, "loader:pathFound");
											ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_56, 0, &_55$$38, this_ptr, &filePath);
											zephir_check_call_status();
										}
										if (zephir_require_once_zval(&filePath) == FAILURE) {
											RETURN_MM_NULL();
										}
										RETURN_MM_BOOL(1);
									}
								ZEPHIR_CALL_METHOD(NULL, &extensions, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&extension);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &directories, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_43$$27, &directories, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_43$$27)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&directory, &directories, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_57$$39);
							zephir_fast_trim(&_57$$39, &directory, &ds, ZEPHIR_TRIM_RIGHT);
							ZEPHIR_INIT_NVAR(&fixedDirectory);
							ZEPHIR_CONCAT_VV(&fixedDirectory, &_57$$39, &ds);
							zephir_is_iterable(&extensions, 0, "phalcon/Loader.zep", 202);
							if (Z_TYPE_P(&extensions) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _58$$39)
								{
									ZEPHIR_INIT_NVAR(&extension);
									ZVAL_COPY(&extension, _58$$39);
									ZEPHIR_INIT_NVAR(&filePath);
									ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &fileName, ".", &extension);
									if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
										zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
										ZEPHIR_INIT_NVAR(&_60$$41);
										ZVAL_STRING(&_60$$41, "loader:beforeCheckPath");
										ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_61, 0, &_60$$41, this_ptr);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_FUNCTION(&_62$$40, "call_user_func", &_18, 257, &fileCheckingCallback, &filePath);
									zephir_check_call_status();
									if (zephir_is_true(&_62$$40)) {
										if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
											zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &filePath);
											ZEPHIR_INIT_NVAR(&_63$$43);
											ZVAL_STRING(&_63$$43, "loader:pathFound");
											ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_64, 0, &_63$$43, this_ptr, &filePath);
											zephir_check_call_status();
										}
										if (zephir_require_once_zval(&filePath) == FAILURE) {
											RETURN_MM_NULL();
										}
										RETURN_MM_BOOL(1);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &extensions, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_59$$39, &extensions, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_59$$39)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&extension, &extensions, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&filePath);
										ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &fileName, ".", &extension);
										if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
											zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
											ZEPHIR_INIT_NVAR(&_65$$45);
											ZVAL_STRING(&_65$$45, "loader:beforeCheckPath");
											ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_66, 0, &_65$$45, this_ptr);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_FUNCTION(&_67$$44, "call_user_func", &_18, 257, &fileCheckingCallback, &filePath);
										zephir_check_call_status();
										if (zephir_is_true(&_67$$44)) {
											if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
												zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &filePath);
												ZEPHIR_INIT_NVAR(&_68$$47);
												ZVAL_STRING(&_68$$47, "loader:pathFound");
												ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_69, 0, &_68$$47, this_ptr, &filePath);
												zephir_check_call_status();
											}
											if (zephir_require_once_zval(&filePath) == FAILURE) {
												RETURN_MM_NULL();
											}
											RETURN_MM_BOOL(1);
										}
									ZEPHIR_CALL_METHOD(NULL, &extensions, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&extension);
						ZEPHIR_CALL_METHOD(NULL, &directories, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&directory);
			ZEPHIR_CALL_METHOD(NULL, &namespaces, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&directories);
	ZEPHIR_INIT_NVAR(&nsPrefix);
	ZEPHIR_INIT_VAR(&nsClassName);
	zephir_fast_str_replace(&nsClassName, &ns, &ds, &className);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("directories"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&directories, &_0);
	zephir_is_iterable(&directories, 0, "phalcon/Loader.zep", 266);
	if (Z_TYPE_P(&directories) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&directories), _70)
		{
			ZEPHIR_INIT_NVAR(&directory);
			ZVAL_COPY(&directory, _70);
			ZEPHIR_INIT_NVAR(&_72$$48);
			zephir_fast_trim(&_72$$48, &directory, &ds, ZEPHIR_TRIM_RIGHT);
			ZEPHIR_INIT_NVAR(&fixedDirectory);
			ZEPHIR_CONCAT_VV(&fixedDirectory, &_72$$48, &ds);
			zephir_is_iterable(&extensions, 0, "phalcon/Loader.zep", 261);
			if (Z_TYPE_P(&extensions) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _73$$48)
				{
					ZEPHIR_INIT_NVAR(&extension);
					ZVAL_COPY(&extension, _73$$48);
					ZEPHIR_INIT_NVAR(&filePath);
					ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &nsClassName, ".", &extension);
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
						ZEPHIR_INIT_NVAR(&_75$$50);
						ZVAL_STRING(&_75$$50, "loader:beforeCheckPath");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_76, 0, &_75$$50, this_ptr, &filePath);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_FUNCTION(&_77$$49, "call_user_func", &_18, 257, &fileCheckingCallback, &filePath);
					zephir_check_call_status();
					if (zephir_is_true(&_77$$49)) {
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &filePath);
							ZEPHIR_INIT_NVAR(&_78$$52);
							ZVAL_STRING(&_78$$52, "loader:pathFound");
							ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_79, 0, &_78$$52, this_ptr, &filePath);
							zephir_check_call_status();
						}
						if (zephir_require_once_zval(&filePath) == FAILURE) {
							RETURN_MM_NULL();
						}
						RETURN_MM_BOOL(1);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &extensions, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_74$$48, &extensions, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_74$$48)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&extension, &extensions, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&filePath);
						ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &nsClassName, ".", &extension);
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
							ZEPHIR_INIT_NVAR(&_80$$54);
							ZVAL_STRING(&_80$$54, "loader:beforeCheckPath");
							ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_81, 0, &_80$$54, this_ptr, &filePath);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_FUNCTION(&_82$$53, "call_user_func", &_18, 257, &fileCheckingCallback, &filePath);
						zephir_check_call_status();
						if (zephir_is_true(&_82$$53)) {
							if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
								zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &filePath);
								ZEPHIR_INIT_NVAR(&_83$$56);
								ZVAL_STRING(&_83$$56, "loader:pathFound");
								ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_84, 0, &_83$$56, this_ptr, &filePath);
								zephir_check_call_status();
							}
							if (zephir_require_once_zval(&filePath) == FAILURE) {
								RETURN_MM_NULL();
							}
							RETURN_MM_BOOL(1);
						}
					ZEPHIR_CALL_METHOD(NULL, &extensions, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&extension);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &directories, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_71, &directories, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_71)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&directory, &directories, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_85$$57);
				zephir_fast_trim(&_85$$57, &directory, &ds, ZEPHIR_TRIM_RIGHT);
				ZEPHIR_INIT_NVAR(&fixedDirectory);
				ZEPHIR_CONCAT_VV(&fixedDirectory, &_85$$57, &ds);
				zephir_is_iterable(&extensions, 0, "phalcon/Loader.zep", 261);
				if (Z_TYPE_P(&extensions) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _86$$57)
					{
						ZEPHIR_INIT_NVAR(&extension);
						ZVAL_COPY(&extension, _86$$57);
						ZEPHIR_INIT_NVAR(&filePath);
						ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &nsClassName, ".", &extension);
						if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
							zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
							ZEPHIR_INIT_NVAR(&_88$$59);
							ZVAL_STRING(&_88$$59, "loader:beforeCheckPath");
							ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_89, 0, &_88$$59, this_ptr, &filePath);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_FUNCTION(&_90$$58, "call_user_func", &_18, 257, &fileCheckingCallback, &filePath);
						zephir_check_call_status();
						if (zephir_is_true(&_90$$58)) {
							if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
								zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &filePath);
								ZEPHIR_INIT_NVAR(&_91$$61);
								ZVAL_STRING(&_91$$61, "loader:pathFound");
								ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_92, 0, &_91$$61, this_ptr, &filePath);
								zephir_check_call_status();
							}
							if (zephir_require_once_zval(&filePath) == FAILURE) {
								RETURN_MM_NULL();
							}
							RETURN_MM_BOOL(1);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &extensions, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_87$$57, &extensions, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_87$$57)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&extension, &extensions, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&filePath);
							ZEPHIR_CONCAT_VVSV(&filePath, &fixedDirectory, &nsClassName, ".", &extension);
							if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
								zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
								ZEPHIR_INIT_NVAR(&_93$$63);
								ZVAL_STRING(&_93$$63, "loader:beforeCheckPath");
								ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_94, 0, &_93$$63, this_ptr, &filePath);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_FUNCTION(&_95$$62, "call_user_func", &_18, 257, &fileCheckingCallback, &filePath);
							zephir_check_call_status();
							if (zephir_is_true(&_95$$62)) {
								if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
									zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &filePath);
									ZEPHIR_INIT_NVAR(&_96$$65);
									ZVAL_STRING(&_96$$65, "loader:pathFound");
									ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_97, 0, &_96$$65, this_ptr, &filePath);
									zephir_check_call_status();
								}
								if (zephir_require_once_zval(&filePath) == FAILURE) {
									RETURN_MM_NULL();
								}
								RETURN_MM_BOOL(1);
							}
						ZEPHIR_CALL_METHOD(NULL, &extensions, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&extension);
			ZEPHIR_CALL_METHOD(NULL, &directories, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&directory);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_98$$66);
		ZVAL_STRING(&_98$$66, "loader:afterCheckClass");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_98$$66, this_ptr, &className);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(0);
}

/**
 * Get the path the loader is checking for a path
 */
PHP_METHOD(Phalcon_Loader, getCheckedPath)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "checkedPath");
}

/**
 * Returns the class-map currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getClasses)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "classes");
}

/**
 * Returns the directories currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getDirs)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "directories");
}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Loader, getEventsManager)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Returns the file extensions registered in the loader
 */
PHP_METHOD(Phalcon_Loader, getExtensions)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "extensions");
}

/**
 * Returns the files currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getFiles)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "files");
}

/**
 * Get the path when a class was found
 */
PHP_METHOD(Phalcon_Loader, getFoundPath)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "foundPath");
}

/**
 * Returns the namespaces currently registered in the autoloader
 */
PHP_METHOD(Phalcon_Loader, getNamespaces)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "namespaces");
}

/**
 * Checks if a file exists and then adds the file by doing virtual require
 */
PHP_METHOD(Phalcon_Loader, loadFiles)
{
	zval filePath, fileCheckingCallback, _0, *_1, _2, _3$$3, _6$$3, _4$$4, _5$$4, _8$$5, _9$$6, _10$$6, _11$$7, _14$$7, _12$$8, _13$$8, _15$$9, _16$$10, _17$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&fileCheckingCallback);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("fileCheckingCallback"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&fileCheckingCallback, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("files"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Loader.zep", 381);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&filePath);
			ZVAL_COPY(&filePath, _1);
			ZEPHIR_OBS_NVAR(&_3$$3);
			zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC);
			if (Z_TYPE_P(&_3$$3) == IS_OBJECT) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
				zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZVAL_STRING(&_5$$4, "loader:beforeCheckPath");
				ZEPHIR_CALL_METHOD(NULL, &_4$$4, "fire", NULL, 0, &_5$$4, this_ptr, &filePath);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_FUNCTION(&_6$$3, "call_user_func", &_7, 257, &fileCheckingCallback, &filePath);
			zephir_check_call_status();
			if (zephir_is_true(&_6$$3)) {
				ZEPHIR_OBS_NVAR(&_8$$5);
				zephir_read_property(&_8$$5, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC);
				if (Z_TYPE_P(&_8$$5) == IS_OBJECT) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &filePath);
					zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_10$$6);
					ZVAL_STRING(&_10$$6, "loader:pathFound");
					ZEPHIR_CALL_METHOD(NULL, &_9$$6, "fire", NULL, 0, &_10$$6, this_ptr, &filePath);
					zephir_check_call_status();
				}
				if (zephir_require_once_zval(&filePath) == FAILURE) {
					RETURN_MM_NULL();
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&filePath, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_11$$7);
				zephir_read_property(&_11$$7, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC);
				if (Z_TYPE_P(&_11$$7) == IS_OBJECT) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("checkedPath"), &filePath);
					zephir_read_property(&_12$$8, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_13$$8);
					ZVAL_STRING(&_13$$8, "loader:beforeCheckPath");
					ZEPHIR_CALL_METHOD(NULL, &_12$$8, "fire", NULL, 0, &_13$$8, this_ptr, &filePath);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_FUNCTION(&_14$$7, "call_user_func", &_7, 257, &fileCheckingCallback, &filePath);
				zephir_check_call_status();
				if (zephir_is_true(&_14$$7)) {
					ZEPHIR_OBS_NVAR(&_15$$9);
					zephir_read_property(&_15$$9, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC);
					if (Z_TYPE_P(&_15$$9) == IS_OBJECT) {
						zephir_update_property_zval(this_ptr, ZEND_STRL("foundPath"), &filePath);
						zephir_read_property(&_16$$10, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&_17$$10);
						ZVAL_STRING(&_17$$10, "loader:pathFound");
						ZEPHIR_CALL_METHOD(NULL, &_16$$10, "fire", NULL, 0, &_17$$10, this_ptr, &filePath);
						zephir_check_call_status();
					}
					if (zephir_require_once_zval(&filePath) == FAILURE) {
						RETURN_MM_NULL();
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&filePath);
	ZEPHIR_MM_RESTORE();
}

/**
 * Register the autoload method
 */
PHP_METHOD(Phalcon_Loader, register)
{
	zval _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prepend_param = NULL, __$true, __$false, _0, _2$$3, _3$$3;
	zend_bool prepend;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(prepend)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prepend_param);
	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("registered"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadfiles", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0);
		zephir_array_fast_append(&_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "autoLoad");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZVAL_BOOL(&_3$$3, (prepend ? 1 : 0));
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 410, &_1$$3, &__$true, &_3$$3);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("registered"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("registered"), &__$false);
		}
	}
	RETURN_THIS();
}

/**
 * Register classes and their locations
 */
PHP_METHOD(Phalcon_Loader, registerClasses)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool merge;
	zval *classes_param = NULL, *merge_param = NULL, _0$$3, _1$$3;
	zval classes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(classes)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &classes_param, &merge_param);
	ZEPHIR_OBS_COPY_OR_DUP(&classes, classes_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("classes"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, &classes);
		zephir_update_property_zval(this_ptr, ZEND_STRL("classes"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("classes"), &classes);
	}
	RETURN_THIS();
}

/**
 * Register directories in which "not found" classes could be found
 */
PHP_METHOD(Phalcon_Loader, registerDirs)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool merge;
	zval *directories_param = NULL, *merge_param = NULL, _0$$3, _1$$3;
	zval directories;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directories);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(directories)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &directories_param, &merge_param);
	ZEPHIR_OBS_COPY_OR_DUP(&directories, directories_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("directories"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, &directories);
		zephir_update_property_zval(this_ptr, ZEND_STRL("directories"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("directories"), &directories);
	}
	RETURN_THIS();
}

/**
 * Registers files that are "non-classes" hence need a "require". This is
 * very useful for including files that only have functions
 */
PHP_METHOD(Phalcon_Loader, registerFiles)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool merge;
	zval *files_param = NULL, *merge_param = NULL, _0$$3, _1$$3;
	zval files;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(files)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &files_param, &merge_param);
	ZEPHIR_OBS_COPY_OR_DUP(&files, files_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("files"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, &files);
		zephir_update_property_zval(this_ptr, ZEND_STRL("files"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("files"), &files);
	}
	RETURN_THIS();
}

/**
 * Register namespaces and their related directories
 */
PHP_METHOD(Phalcon_Loader, registerNamespaces)
{
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge;
	zval *namespaces_param = NULL, *merge_param = NULL, preparedNamespaces, name, paths, *_0$$3, _1$$3, _4$$4, _6$$4, _7$$4, _8$$4, _5$$5, _9$$6, _11$$6, _12$$6, _13$$6, _10$$7;
	zval namespaces;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&preparedNamespaces);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_10$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(namespaces)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &namespaces_param, &merge_param);
	ZEPHIR_OBS_COPY_OR_DUP(&namespaces, namespaces_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	ZEPHIR_CALL_METHOD(&preparedNamespaces, this_ptr, "preparenamespace", NULL, 0, &namespaces);
	zephir_check_call_status();
	if (merge) {
		zephir_is_iterable(&preparedNamespaces, 0, "phalcon/Loader.zep", 472);
		if (Z_TYPE_P(&preparedNamespaces) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&preparedNamespaces), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&name);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&name, _3$$3);
				} else {
					ZVAL_LONG(&name, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&paths);
				ZVAL_COPY(&paths, _0$$3);
				zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset(&_4$$4, &name))) {
					ZEPHIR_INIT_NVAR(&_5$$5);
					array_init(&_5$$5);
					zephir_update_property_array(this_ptr, SL("namespaces"), &name, &_5$$5);
				}
				ZEPHIR_INIT_NVAR(&_6$$4);
				zephir_read_property(&_7$$4, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_8$$4, &_7$$4, &name, PH_NOISY | PH_READONLY, "phalcon/Loader.zep", 468);
				zephir_fast_array_merge(&_6$$4, &_8$$4, &paths);
				zephir_update_property_array(this_ptr, SL("namespaces"), &name, &_6$$4);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &preparedNamespaces, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &preparedNamespaces, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&name, &preparedNamespaces, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&paths, &preparedNamespaces, "current", NULL, 0);
				zephir_check_call_status();
					zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
					if (!(zephir_array_isset(&_9$$6, &name))) {
						ZEPHIR_INIT_NVAR(&_10$$7);
						array_init(&_10$$7);
						zephir_update_property_array(this_ptr, SL("namespaces"), &name, &_10$$7);
					}
					ZEPHIR_INIT_NVAR(&_11$$6);
					zephir_read_property(&_12$$6, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_13$$6, &_12$$6, &name, PH_NOISY | PH_READONLY, "phalcon/Loader.zep", 468);
					zephir_fast_array_merge(&_11$$6, &_13$$6, &paths);
					zephir_update_property_array(this_ptr, SL("namespaces"), &name, &_11$$6);
				ZEPHIR_CALL_METHOD(NULL, &preparedNamespaces, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&paths);
		ZEPHIR_INIT_NVAR(&name);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("namespaces"), &preparedNamespaces);
	}
	RETURN_THIS();
}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Loader, setEventsManager)
{
	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);


	zephir_update_property_zval(this_ptr, ZEND_STRL("eventsManager"), eventsManager);
}

/**
 * Sets an array of file extensions that the loader must try in each attempt
 * to locate the file
 */
PHP_METHOD(Phalcon_Loader, setExtensions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *extensions_param = NULL;
	zval extensions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extensions);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(extensions)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &extensions_param);
	ZEPHIR_OBS_COPY_OR_DUP(&extensions, extensions_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("extensions"), &extensions);
	RETURN_THIS();
}

/**
 * Sets the file check callback.
 *
 * ```php
 * // Default behavior.
 * $loader->setFileCheckingCallback("is_file");
 *
 * // Faster than `is_file()`, but implies some issues if
 * // the file is removed from the filesystem.
 * $loader->setFileCheckingCallback("stream_resolve_include_path");
 *
 * // Do not check file existence.
 * $loader->setFileCheckingCallback(null);
 * ```
 */
PHP_METHOD(Phalcon_Loader, setFileCheckingCallback)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *callback = NULL, callback_sub, __$null, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(callback)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &callback);
	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
	}


	if (EXPECTED(zephir_is_callable(callback))) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("fileCheckingCallback"), callback);
	} else if (Z_TYPE_P(callback) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_INIT_NVAR(&_0$$4);
		zephir_create_closure_ex(&_0$$4, NULL, phalcon_8__closure_ce, SL("__invoke"));
		zephir_update_property_zval(this_ptr, ZEND_STRL("fileCheckingCallback"), &_0$$4);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_loader_exception_ce, "The 'callback' parameter must be either a callable or NULL.", "phalcon/Loader.zep", 524);
		return;
	}
	RETURN_THIS();
}

/**
 * Unregister the autoload method
 */
PHP_METHOD(Phalcon_Loader, unregister)
{
	zval _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0, _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("registered"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0);
		zephir_array_fast_append(&_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "autoLoad");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, 411, &_1$$3);
		zephir_check_call_status();
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("registered"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("registered"), &__$false);
		}
	}
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Loader, prepareNamespace)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *namespaceName_param = NULL, localPaths, name, paths, prepared, *_0, _1, _4$$7;
	zval namespaceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&localPaths);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&prepared);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(namespaceName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceName_param);
	ZEPHIR_OBS_COPY_OR_DUP(&namespaceName, namespaceName_param);


	ZEPHIR_INIT_VAR(&prepared);
	array_init(&prepared);
	zephir_is_iterable(&namespaceName, 0, "phalcon/Loader.zep", 565);
	if (Z_TYPE_P(&namespaceName) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&namespaceName), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&paths);
			ZVAL_COPY(&paths, _0);
			if (Z_TYPE_P(&paths) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&localPaths);
				zephir_create_array(&localPaths, 1, 0);
				zephir_array_fast_append(&localPaths, &paths);
			} else {
				ZEPHIR_CPY_WRT(&localPaths, &paths);
			}
			zephir_array_update_zval(&prepared, &name, &localPaths, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &namespaceName, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &namespaceName, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &namespaceName, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&paths, &namespaceName, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&paths) != IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_4$$7);
					zephir_create_array(&_4$$7, 1, 0);
					zephir_array_fast_append(&_4$$7, &paths);
					ZEPHIR_CPY_WRT(&localPaths, &_4$$7);
				} else {
					ZEPHIR_CPY_WRT(&localPaths, &paths);
				}
				zephir_array_update_zval(&prepared, &name, &localPaths, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &namespaceName, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&paths);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&prepared);
}

zend_object *zephir_init_properties_Phalcon_Loader(zend_class_entry *class_type)
{
		zval _5$$5;
	zval _0, _2, _4, _7, _9, _1$$3, _3$$4, _6$$5, _8$$6, _10$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_5$$5);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("namespaces"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("files"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("files"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("extensions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_create_array(&_5$$5, 1, 0);
			ZEPHIR_INIT_VAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "php");
			zephir_array_fast_append(&_5$$5, &_6$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("extensions"), &_5$$5);
		}
		zephir_read_property_ex(&_7, this_ptr, ZEND_STRL("directories"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_7) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_8$$6);
			array_init(&_8$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("directories"), &_8$$6);
		}
		zephir_read_property_ex(&_9, this_ptr, ZEND_STRL("classes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_9) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_10$$7);
			array_init(&_10$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("classes"), &_10$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

