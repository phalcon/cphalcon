
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Class Phalcon\Http\Link\Serializer\Header
 *
 * @phpstan-import-type link_collection from LinkTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_Serializer_Header)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Link\\Serializer, Header, phalcon, html_link_serializer_header, phalcon_html_link_serializer_header_method_entry, 0);

	zend_class_implements(phalcon_html_link_serializer_header_ce, 1, phalcon_html_link_serializer_serializerinterface_ce);
	return SUCCESS;
}

/**
 * Serializes all the passed links to a HTTP link header
 *
 * @phpstan-param link_collection $links
 */
PHP_METHOD(Phalcon_Html_Link_Serializer_Header, serialize)
{
	zval _13$$7, _18$$8, _21$$9, _29$$13, _34$$14, _37$$15, _56$$21, _61$$22, _64$$23, _72$$27, _77$$28, _80$$29;
	zend_string *_8$$3, *_51$$17;
	zend_ulong _7$$3, _50$$17;
	zend_bool _42, _24$$3, _16$$6, _32$$12, _67$$17, _59$$20, _75$$26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *links_param = NULL, attributes, key, link, rels, result, subValue, value, *_0, _41, _1$$3, _2$$3, _3$$3, *_4$$3, _5$$3, *_6$$3, _23$$3, _39$$3, _40$$3, *_9$$6, _10$$6, *_11$$6, _15$$6, _12$$7, _14$$7, _17$$8, _19$$8, _20$$9, _22$$9, *_25$$12, _26$$12, *_27$$12, _31$$12, _28$$13, _30$$13, _33$$14, _35$$14, _36$$15, _38$$15, _43$$17, _44$$17, _45$$17, _46$$17, *_47$$17, _48$$17, *_49$$17, _66$$17, _82$$17, _83$$17, *_52$$20, _53$$20, *_54$$20, _58$$20, _55$$21, _57$$21, _60$$22, _62$$22, _63$$23, _65$$23, *_68$$26, _69$$26, *_70$$26, _74$$26, _71$$27, _73$$27, _76$$28, _78$$28, _79$$29, _81$$29;
	zval links, elements, parts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&links);
	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&rels);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&subValue);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_39$$3);
	ZVAL_UNDEF(&_40$$3);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_28$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_33$$14);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_36$$15);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_43$$17);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_45$$17);
	ZVAL_UNDEF(&_46$$17);
	ZVAL_UNDEF(&_48$$17);
	ZVAL_UNDEF(&_66$$17);
	ZVAL_UNDEF(&_82$$17);
	ZVAL_UNDEF(&_83$$17);
	ZVAL_UNDEF(&_53$$20);
	ZVAL_UNDEF(&_58$$20);
	ZVAL_UNDEF(&_55$$21);
	ZVAL_UNDEF(&_57$$21);
	ZVAL_UNDEF(&_60$$22);
	ZVAL_UNDEF(&_62$$22);
	ZVAL_UNDEF(&_63$$23);
	ZVAL_UNDEF(&_65$$23);
	ZVAL_UNDEF(&_69$$26);
	ZVAL_UNDEF(&_74$$26);
	ZVAL_UNDEF(&_71$$27);
	ZVAL_UNDEF(&_73$$27);
	ZVAL_UNDEF(&_76$$28);
	ZVAL_UNDEF(&_78$$28);
	ZVAL_UNDEF(&_79$$29);
	ZVAL_UNDEF(&_81$$29);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_37$$15);
	ZVAL_UNDEF(&_56$$21);
	ZVAL_UNDEF(&_61$$22);
	ZVAL_UNDEF(&_64$$23);
	ZVAL_UNDEF(&_72$$27);
	ZVAL_UNDEF(&_77$$28);
	ZVAL_UNDEF(&_80$$29);
	ZEND_TLS zephir_method_cache _zephir_call_cache[50];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(links, links_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &links_param);
	zephir_get_arrval(&links, links_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_NULL(&result);
	ZEPHIR_INIT_VAR(&elements);
	array_init(&elements);
	zephir_is_iterable(&links, 0, "phalcon/Html/Link/Serializer/Header.zep", 76);
	if (Z_TYPE_P(&links) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&links), _0)
		{
			ZEPHIR_INIT_NVAR(&link);
			ZVAL_COPY(&link, _0);
			ZEPHIR_CALL_METHOD_CACHED(&_1$$3, &link, "isTemplated", &_zephir_call_cache[0]);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_1$$3)) {
				continue;
			}
			ZEPHIR_CALL_METHOD_CACHED(&attributes, &link, "getAttributes", &_zephir_call_cache[1]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&rels, &link, "getRels", &_zephir_call_cache[2]);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&parts);
			zephir_create_array(&parts, 2, 0);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "");
			zephir_array_fast_append(&parts, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_fast_join_str(&_2$$3, SL(" "), &rels);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZEPHIR_CONCAT_SVS(&_3$$3, "rel=\"", &_2$$3, "\"");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_fast_append(&parts, &_3$$3);
			if (Z_TYPE_P(&attributes) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_5$$3);
				zephir_string_to_char_array(&_5$$3, &attributes);
				_4$$3 = &_5$$3;
			} else {
				_4$$3 = &attributes;
			}
			zephir_is_iterable(_4$$3, 0, "phalcon/Html/Link/Serializer/Header.zep", 70);
			if (Z_TYPE_P(_4$$3) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4$$3), _7$$3, _8$$3, _6$$3)
				{
					ZEPHIR_INIT_NVAR(&key);
					if (_8$$3 != NULL) { 
						ZVAL_STR_COPY(&key, _8$$3);
					} else {
						ZVAL_LONG(&key, _7$$3);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _6$$3);
					if (Z_TYPE_P(&value) == IS_ARRAY) {
						if (Z_TYPE_P(&value) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_10$$6);
							zephir_string_to_char_array(&_10$$6, &value);
							_9$$6 = &_10$$6;
						} else {
							_9$$6 = &value;
						}
						zephir_is_iterable(_9$$6, 0, "phalcon/Html/Link/Serializer/Header.zep", 56);
						if (Z_TYPE_P(_9$$6) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9$$6), _11$$6)
							{
								ZEPHIR_INIT_NVAR(&subValue);
								ZVAL_COPY(&subValue, _11$$6);
								zephir_cast_to_string(&_13$$7, &subValue);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(&_12$$7, this_ptr, "quote", &_zephir_call_cache[3], &_13$$7);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_14$$7);
								ZEPHIR_CONCAT_VSVS(&_14$$7, &key, "=\"", &_12$$7, "\"");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&parts, &_14$$7, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$6, "rewind", &_zephir_call_cache[4]);
							zephir_check_call_status();
							_16$$6 = 1;
							while (1) {
								if (_16$$6) {
									_16$$6 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$6, "next", &_zephir_call_cache[5]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_15$$6, _9$$6, "valid", &_zephir_call_cache[6]);
								zephir_check_call_status();
								if (!zend_is_true(&_15$$6)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&subValue, _9$$6, "current", &_zephir_call_cache[7]);
								zephir_check_call_status();
									zephir_cast_to_string(&_18$$8, &subValue);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(&_17$$8, this_ptr, "quote", &_zephir_call_cache[8], &_18$$8);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_19$$8);
									ZEPHIR_CONCAT_VSVS(&_19$$8, &key, "=\"", &_17$$8, "\"");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&parts, &_19$$8, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
							}
						}
						ZEPHIR_INIT_NVAR(&subValue);
						continue;
					}
					if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
						zephir_cast_to_string(&_21$$9, &value);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(&_20$$9, this_ptr, "quote", &_zephir_call_cache[9], &_21$$9);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_22$$9);
						ZEPHIR_CONCAT_VSVS(&_22$$9, &key, "=\"", &_20$$9, "\"");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&parts, &_22$$9, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 60);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
						zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 65);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$3, "rewind", &_zephir_call_cache[10]);
				zephir_check_call_status();
				_24$$3 = 1;
				while (1) {
					if (_24$$3) {
						_24$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$3, "next", &_zephir_call_cache[11]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_23$$3, _4$$3, "valid", &_zephir_call_cache[12]);
					zephir_check_call_status();
					if (!zend_is_true(&_23$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&key, _4$$3, "key", &_zephir_call_cache[13]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&value, _4$$3, "current", &_zephir_call_cache[14]);
					zephir_check_call_status();
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							if (Z_TYPE_P(&value) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_26$$12);
								zephir_string_to_char_array(&_26$$12, &value);
								_25$$12 = &_26$$12;
							} else {
								_25$$12 = &value;
							}
							zephir_is_iterable(_25$$12, 0, "phalcon/Html/Link/Serializer/Header.zep", 56);
							if (Z_TYPE_P(_25$$12) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_25$$12), _27$$12)
								{
									ZEPHIR_INIT_NVAR(&subValue);
									ZVAL_COPY(&subValue, _27$$12);
									zephir_cast_to_string(&_29$$13, &subValue);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(&_28$$13, this_ptr, "quote", &_zephir_call_cache[15], &_29$$13);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_30$$13);
									ZEPHIR_CONCAT_VSVS(&_30$$13, &key, "=\"", &_28$$13, "\"");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&parts, &_30$$13, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _25$$12, "rewind", &_zephir_call_cache[16]);
								zephir_check_call_status();
								_32$$12 = 1;
								while (1) {
									if (_32$$12) {
										_32$$12 = 0;
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _25$$12, "next", &_zephir_call_cache[17]);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD_CACHED(&_31$$12, _25$$12, "valid", &_zephir_call_cache[18]);
									zephir_check_call_status();
									if (!zend_is_true(&_31$$12)) {
										break;
									}
									ZEPHIR_CALL_METHOD_CACHED(&subValue, _25$$12, "current", &_zephir_call_cache[19]);
									zephir_check_call_status();
										zephir_cast_to_string(&_34$$14, &subValue);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD_CACHED(&_33$$14, this_ptr, "quote", &_zephir_call_cache[20], &_34$$14);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_35$$14);
										ZEPHIR_CONCAT_VSVS(&_35$$14, &key, "=\"", &_33$$14, "\"");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&parts, &_35$$14, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
								}
							}
							ZEPHIR_INIT_NVAR(&subValue);
							continue;
						}
						if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
							zephir_cast_to_string(&_37$$15, &value);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD_CACHED(&_36$$15, this_ptr, "quote", &_zephir_call_cache[21], &_37$$15);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_38$$15);
							ZEPHIR_CONCAT_VSVS(&_38$$15, &key, "=\"", &_36$$15, "\"");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&parts, &_38$$15, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 60);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
						if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
							zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 65);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
			ZEPHIR_CALL_METHOD_CACHED(&_39$$3, &link, "getHref", &_zephir_call_cache[22]);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_40$$3);
			zephir_fast_join_str(&_40$$3, SL("; "), &parts);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZEPHIR_CONCAT_SVSV(&_3$$3, "<", &_39$$3, ">", &_40$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&elements, &_3$$3, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 73);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &links, "rewind", &_zephir_call_cache[23]);
		zephir_check_call_status();
		_42 = 1;
		while (1) {
			if (_42) {
				_42 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &links, "next", &_zephir_call_cache[24]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_41, &links, "valid", &_zephir_call_cache[25]);
			zephir_check_call_status();
			if (!zend_is_true(&_41)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&link, &links, "current", &_zephir_call_cache[26]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_43$$17, &link, "isTemplated", &_zephir_call_cache[27]);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_43$$17)) {
					continue;
				}
				ZEPHIR_CALL_METHOD_CACHED(&attributes, &link, "getAttributes", &_zephir_call_cache[28]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&rels, &link, "getRels", &_zephir_call_cache[29]);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_44$$17);
				zephir_create_array(&_44$$17, 2, 0);
				ZEPHIR_INIT_NVAR(&_45$$17);
				ZVAL_STRING(&_45$$17, "");
				zephir_array_fast_append(&_44$$17, &_45$$17);
				ZEPHIR_INIT_NVAR(&_45$$17);
				zephir_fast_join_str(&_45$$17, SL(" "), &rels);
				ZEPHIR_INIT_NVAR(&_46$$17);
				ZEPHIR_CONCAT_SVS(&_46$$17, "rel=\"", &_45$$17, "\"");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fast_append(&_44$$17, &_46$$17);
				ZEPHIR_CPY_WRT(&parts, &_44$$17);
				if (Z_TYPE_P(&attributes) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_48$$17);
					zephir_string_to_char_array(&_48$$17, &attributes);
					_47$$17 = &_48$$17;
				} else {
					_47$$17 = &attributes;
				}
				zephir_is_iterable(_47$$17, 0, "phalcon/Html/Link/Serializer/Header.zep", 70);
				if (Z_TYPE_P(_47$$17) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_47$$17), _50$$17, _51$$17, _49$$17)
					{
						ZEPHIR_INIT_NVAR(&key);
						if (_51$$17 != NULL) { 
							ZVAL_STR_COPY(&key, _51$$17);
						} else {
							ZVAL_LONG(&key, _50$$17);
						}
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_COPY(&value, _49$$17);
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							if (Z_TYPE_P(&value) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_53$$20);
								zephir_string_to_char_array(&_53$$20, &value);
								_52$$20 = &_53$$20;
							} else {
								_52$$20 = &value;
							}
							zephir_is_iterable(_52$$20, 0, "phalcon/Html/Link/Serializer/Header.zep", 56);
							if (Z_TYPE_P(_52$$20) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_52$$20), _54$$20)
								{
									ZEPHIR_INIT_NVAR(&subValue);
									ZVAL_COPY(&subValue, _54$$20);
									zephir_cast_to_string(&_56$$21, &subValue);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(&_55$$21, this_ptr, "quote", &_zephir_call_cache[30], &_56$$21);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_57$$21);
									ZEPHIR_CONCAT_VSVS(&_57$$21, &key, "=\"", &_55$$21, "\"");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&parts, &_57$$21, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _52$$20, "rewind", &_zephir_call_cache[31]);
								zephir_check_call_status();
								_59$$20 = 1;
								while (1) {
									if (_59$$20) {
										_59$$20 = 0;
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _52$$20, "next", &_zephir_call_cache[32]);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD_CACHED(&_58$$20, _52$$20, "valid", &_zephir_call_cache[33]);
									zephir_check_call_status();
									if (!zend_is_true(&_58$$20)) {
										break;
									}
									ZEPHIR_CALL_METHOD_CACHED(&subValue, _52$$20, "current", &_zephir_call_cache[34]);
									zephir_check_call_status();
										zephir_cast_to_string(&_61$$22, &subValue);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD_CACHED(&_60$$22, this_ptr, "quote", &_zephir_call_cache[35], &_61$$22);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_62$$22);
										ZEPHIR_CONCAT_VSVS(&_62$$22, &key, "=\"", &_60$$22, "\"");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&parts, &_62$$22, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
								}
							}
							ZEPHIR_INIT_NVAR(&subValue);
							continue;
						}
						if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
							zephir_cast_to_string(&_64$$23, &value);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD_CACHED(&_63$$23, this_ptr, "quote", &_zephir_call_cache[36], &_64$$23);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_65$$23);
							ZEPHIR_CONCAT_VSVS(&_65$$23, &key, "=\"", &_63$$23, "\"");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&parts, &_65$$23, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 60);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
						if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
							zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 65);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _47$$17, "rewind", &_zephir_call_cache[37]);
					zephir_check_call_status();
					_67$$17 = 1;
					while (1) {
						if (_67$$17) {
							_67$$17 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _47$$17, "next", &_zephir_call_cache[38]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_66$$17, _47$$17, "valid", &_zephir_call_cache[39]);
						zephir_check_call_status();
						if (!zend_is_true(&_66$$17)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&key, _47$$17, "key", &_zephir_call_cache[40]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&value, _47$$17, "current", &_zephir_call_cache[41]);
						zephir_check_call_status();
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								if (Z_TYPE_P(&value) == IS_STRING) {
									ZEPHIR_INIT_NVAR(&_69$$26);
									zephir_string_to_char_array(&_69$$26, &value);
									_68$$26 = &_69$$26;
								} else {
									_68$$26 = &value;
								}
								zephir_is_iterable(_68$$26, 0, "phalcon/Html/Link/Serializer/Header.zep", 56);
								if (Z_TYPE_P(_68$$26) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_68$$26), _70$$26)
									{
										ZEPHIR_INIT_NVAR(&subValue);
										ZVAL_COPY(&subValue, _70$$26);
										zephir_cast_to_string(&_72$$27, &subValue);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD_CACHED(&_71$$27, this_ptr, "quote", &_zephir_call_cache[42], &_72$$27);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_73$$27);
										ZEPHIR_CONCAT_VSVS(&_73$$27, &key, "=\"", &_71$$27, "\"");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&parts, &_73$$27, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _68$$26, "rewind", &_zephir_call_cache[43]);
									zephir_check_call_status();
									_75$$26 = 1;
									while (1) {
										if (_75$$26) {
											_75$$26 = 0;
										} else {
											ZEPHIR_CALL_METHOD_CACHED(NULL, _68$$26, "next", &_zephir_call_cache[44]);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD_CACHED(&_74$$26, _68$$26, "valid", &_zephir_call_cache[45]);
										zephir_check_call_status();
										if (!zend_is_true(&_74$$26)) {
											break;
										}
										ZEPHIR_CALL_METHOD_CACHED(&subValue, _68$$26, "current", &_zephir_call_cache[46]);
										zephir_check_call_status();
											zephir_cast_to_string(&_77$$28, &subValue);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_CALL_METHOD_CACHED(&_76$$28, this_ptr, "quote", &_zephir_call_cache[47], &_77$$28);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_78$$28);
											ZEPHIR_CONCAT_VSVS(&_78$$28, &key, "=\"", &_76$$28, "\"");
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&parts, &_78$$28, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
									}
								}
								ZEPHIR_INIT_NVAR(&subValue);
								continue;
							}
							if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
								zephir_cast_to_string(&_80$$29, &value);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(&_79$$29, this_ptr, "quote", &_zephir_call_cache[48], &_80$$29);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_81$$29);
								ZEPHIR_CONCAT_VSVS(&_81$$29, &key, "=\"", &_79$$29, "\"");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&parts, &_81$$29, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 60);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								continue;
							}
							if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
								zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 65);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								continue;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&value);
				ZEPHIR_INIT_NVAR(&key);
				ZEPHIR_CALL_METHOD_CACHED(&_82$$17, &link, "getHref", &_zephir_call_cache[49]);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_83$$17);
				zephir_fast_join_str(&_83$$17, SL("; "), &parts);
				ZEPHIR_INIT_NVAR(&_46$$17);
				ZEPHIR_CONCAT_SVSV(&_46$$17, "<", &_82$$17, ">", &_83$$17);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&elements, &_46$$17, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 73);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&link);
	if (!(ZEPHIR_IS_EMPTY(&elements))) {
		ZEPHIR_INIT_NVAR(&result);
		zephir_fast_join_str(&result, SL(","), &elements);
	}
	RETURN_CCTOR(&result);
}

/**
 * Escapes a quoted-string attribute value per RFC 8288 section 3: a
 * backslash and a double quote are each prefixed with a backslash so the
 * value cannot terminate or corrupt the header field.
 */
PHP_METHOD(Phalcon_Html_Link_Serializer_Header, quote)
{
	zval _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval value_zv, _1;
	zend_string *value = NULL;

	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\\");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "\"");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "\\\\");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "\\\"");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_fast_str_replace(&_1, &_0, &_2, &value_zv);
	RETURN_CCTOR(&_1);
}

