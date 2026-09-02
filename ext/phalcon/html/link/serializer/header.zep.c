
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
 * For the full copyright and license information, please view the LICENSE.txt
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
	zval _13$$7, _19$$8, _22$$9, _30$$13, _35$$14, _38$$15, _57$$21, _62$$22, _65$$23, _73$$27, _78$$28, _81$$29;
	zend_string *_8$$3, *_52$$17;
	zend_ulong _7$$3, _51$$17;
	zend_bool _43, _25$$3, _17$$6, _33$$12, _68$$17, _60$$20, _76$$26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *links_param = NULL, attributes, key, link, rels, result, subValue, value, *_0, _42, _1$$3, _2$$3, _3$$3, *_4$$3, _5$$3, *_6$$3, _24$$3, _40$$3, _41$$3, *_9$$6, _10$$6, *_11$$6, _16$$6, _12$$7, _15$$7, _18$$8, _20$$8, _21$$9, _23$$9, *_26$$12, _27$$12, *_28$$12, _32$$12, _29$$13, _31$$13, _34$$14, _36$$14, _37$$15, _39$$15, _44$$17, _45$$17, _46$$17, _47$$17, *_48$$17, _49$$17, *_50$$17, _67$$17, _83$$17, _84$$17, *_53$$20, _54$$20, *_55$$20, _59$$20, _56$$21, _58$$21, _61$$22, _63$$22, _64$$23, _66$$23, *_69$$26, _70$$26, *_71$$26, _75$$26, _72$$27, _74$$27, _77$$28, _79$$28, _80$$29, _82$$29;
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
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_24$$3);
	ZVAL_UNDEF(&_40$$3);
	ZVAL_UNDEF(&_41$$3);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_36$$14);
	ZVAL_UNDEF(&_37$$15);
	ZVAL_UNDEF(&_39$$15);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_45$$17);
	ZVAL_UNDEF(&_46$$17);
	ZVAL_UNDEF(&_47$$17);
	ZVAL_UNDEF(&_49$$17);
	ZVAL_UNDEF(&_67$$17);
	ZVAL_UNDEF(&_83$$17);
	ZVAL_UNDEF(&_84$$17);
	ZVAL_UNDEF(&_54$$20);
	ZVAL_UNDEF(&_59$$20);
	ZVAL_UNDEF(&_56$$21);
	ZVAL_UNDEF(&_58$$21);
	ZVAL_UNDEF(&_61$$22);
	ZVAL_UNDEF(&_63$$22);
	ZVAL_UNDEF(&_64$$23);
	ZVAL_UNDEF(&_66$$23);
	ZVAL_UNDEF(&_70$$26);
	ZVAL_UNDEF(&_75$$26);
	ZVAL_UNDEF(&_72$$27);
	ZVAL_UNDEF(&_74$$27);
	ZVAL_UNDEF(&_77$$28);
	ZVAL_UNDEF(&_79$$28);
	ZVAL_UNDEF(&_80$$29);
	ZVAL_UNDEF(&_82$$29);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_57$$21);
	ZVAL_UNDEF(&_62$$22);
	ZVAL_UNDEF(&_65$$23);
	ZVAL_UNDEF(&_73$$27);
	ZVAL_UNDEF(&_78$$28);
	ZVAL_UNDEF(&_81$$29);
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
			ZEPHIR_CALL_METHOD(&_1$$3, &link, "istemplated", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_1$$3)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&attributes, &link, "getattributes", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&rels, &link, "getrels", NULL, 0);
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
								ZEPHIR_CALL_METHOD(&_12$$7, this_ptr, "quote", &_14, 0, &_13$$7);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_15$$7);
								ZEPHIR_CONCAT_VSVS(&_15$$7, &key, "=\"", &_12$$7, "\"");
								zephir_array_append(&parts, &_15$$7, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _9$$6, "rewind", NULL, 0);
							zephir_check_call_status();
							_17$$6 = 1;
							while (1) {
								if (_17$$6) {
									_17$$6 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _9$$6, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_16$$6, _9$$6, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_16$$6)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&subValue, _9$$6, "current", NULL, 0);
								zephir_check_call_status();
									zephir_cast_to_string(&_19$$8, &subValue);
									ZEPHIR_CALL_METHOD(&_18$$8, this_ptr, "quote", &_14, 0, &_19$$8);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_20$$8);
									ZEPHIR_CONCAT_VSVS(&_20$$8, &key, "=\"", &_18$$8, "\"");
									zephir_array_append(&parts, &_20$$8, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
							}
						}
						ZEPHIR_INIT_NVAR(&subValue);
						continue;
					}
					if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
						zephir_cast_to_string(&_22$$9, &value);
						ZEPHIR_CALL_METHOD(&_21$$9, this_ptr, "quote", &_14, 0, &_22$$9);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_23$$9);
						ZEPHIR_CONCAT_VSVS(&_23$$9, &key, "=\"", &_21$$9, "\"");
						zephir_array_append(&parts, &_23$$9, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 60);
						continue;
					}
					if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
						zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 65);
						continue;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4$$3, "rewind", NULL, 0);
				zephir_check_call_status();
				_25$$3 = 1;
				while (1) {
					if (_25$$3) {
						_25$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _4$$3, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_24$$3, _4$$3, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_24$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&key, _4$$3, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&value, _4$$3, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							if (Z_TYPE_P(&value) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_27$$12);
								zephir_string_to_char_array(&_27$$12, &value);
								_26$$12 = &_27$$12;
							} else {
								_26$$12 = &value;
							}
							zephir_is_iterable(_26$$12, 0, "phalcon/Html/Link/Serializer/Header.zep", 56);
							if (Z_TYPE_P(_26$$12) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_26$$12), _28$$12)
								{
									ZEPHIR_INIT_NVAR(&subValue);
									ZVAL_COPY(&subValue, _28$$12);
									zephir_cast_to_string(&_30$$13, &subValue);
									ZEPHIR_CALL_METHOD(&_29$$13, this_ptr, "quote", &_14, 0, &_30$$13);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_31$$13);
									ZEPHIR_CONCAT_VSVS(&_31$$13, &key, "=\"", &_29$$13, "\"");
									zephir_array_append(&parts, &_31$$13, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _26$$12, "rewind", NULL, 0);
								zephir_check_call_status();
								_33$$12 = 1;
								while (1) {
									if (_33$$12) {
										_33$$12 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _26$$12, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_32$$12, _26$$12, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_32$$12)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&subValue, _26$$12, "current", NULL, 0);
									zephir_check_call_status();
										zephir_cast_to_string(&_35$$14, &subValue);
										ZEPHIR_CALL_METHOD(&_34$$14, this_ptr, "quote", &_14, 0, &_35$$14);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_36$$14);
										ZEPHIR_CONCAT_VSVS(&_36$$14, &key, "=\"", &_34$$14, "\"");
										zephir_array_append(&parts, &_36$$14, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
								}
							}
							ZEPHIR_INIT_NVAR(&subValue);
							continue;
						}
						if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
							zephir_cast_to_string(&_38$$15, &value);
							ZEPHIR_CALL_METHOD(&_37$$15, this_ptr, "quote", &_14, 0, &_38$$15);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_39$$15);
							ZEPHIR_CONCAT_VSVS(&_39$$15, &key, "=\"", &_37$$15, "\"");
							zephir_array_append(&parts, &_39$$15, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 60);
							continue;
						}
						if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
							zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 65);
							continue;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
			ZEPHIR_CALL_METHOD(&_40$$3, &link, "gethref", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_41$$3);
			zephir_fast_join_str(&_41$$3, SL("; "), &parts);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZEPHIR_CONCAT_SVSV(&_3$$3, "<", &_40$$3, ">", &_41$$3);
			zephir_array_append(&elements, &_3$$3, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 73);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &links, "rewind", NULL, 0);
		zephir_check_call_status();
		_43 = 1;
		while (1) {
			if (_43) {
				_43 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &links, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_42, &links, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_42)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&link, &links, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_44$$17, &link, "istemplated", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_44$$17)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&attributes, &link, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&rels, &link, "getrels", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_45$$17);
				zephir_create_array(&_45$$17, 2, 0);
				ZEPHIR_INIT_NVAR(&_46$$17);
				ZVAL_STRING(&_46$$17, "");
				zephir_array_fast_append(&_45$$17, &_46$$17);
				ZEPHIR_INIT_NVAR(&_46$$17);
				zephir_fast_join_str(&_46$$17, SL(" "), &rels);
				ZEPHIR_INIT_NVAR(&_47$$17);
				ZEPHIR_CONCAT_SVS(&_47$$17, "rel=\"", &_46$$17, "\"");
				zephir_array_fast_append(&_45$$17, &_47$$17);
				ZEPHIR_CPY_WRT(&parts, &_45$$17);
				if (Z_TYPE_P(&attributes) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_49$$17);
					zephir_string_to_char_array(&_49$$17, &attributes);
					_48$$17 = &_49$$17;
				} else {
					_48$$17 = &attributes;
				}
				zephir_is_iterable(_48$$17, 0, "phalcon/Html/Link/Serializer/Header.zep", 70);
				if (Z_TYPE_P(_48$$17) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_48$$17), _51$$17, _52$$17, _50$$17)
					{
						ZEPHIR_INIT_NVAR(&key);
						if (_52$$17 != NULL) { 
							ZVAL_STR_COPY(&key, _52$$17);
						} else {
							ZVAL_LONG(&key, _51$$17);
						}
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_COPY(&value, _50$$17);
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							if (Z_TYPE_P(&value) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_54$$20);
								zephir_string_to_char_array(&_54$$20, &value);
								_53$$20 = &_54$$20;
							} else {
								_53$$20 = &value;
							}
							zephir_is_iterable(_53$$20, 0, "phalcon/Html/Link/Serializer/Header.zep", 56);
							if (Z_TYPE_P(_53$$20) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_53$$20), _55$$20)
								{
									ZEPHIR_INIT_NVAR(&subValue);
									ZVAL_COPY(&subValue, _55$$20);
									zephir_cast_to_string(&_57$$21, &subValue);
									ZEPHIR_CALL_METHOD(&_56$$21, this_ptr, "quote", &_14, 0, &_57$$21);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_58$$21);
									ZEPHIR_CONCAT_VSVS(&_58$$21, &key, "=\"", &_56$$21, "\"");
									zephir_array_append(&parts, &_58$$21, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _53$$20, "rewind", NULL, 0);
								zephir_check_call_status();
								_60$$20 = 1;
								while (1) {
									if (_60$$20) {
										_60$$20 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _53$$20, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_59$$20, _53$$20, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_59$$20)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&subValue, _53$$20, "current", NULL, 0);
									zephir_check_call_status();
										zephir_cast_to_string(&_62$$22, &subValue);
										ZEPHIR_CALL_METHOD(&_61$$22, this_ptr, "quote", &_14, 0, &_62$$22);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_63$$22);
										ZEPHIR_CONCAT_VSVS(&_63$$22, &key, "=\"", &_61$$22, "\"");
										zephir_array_append(&parts, &_63$$22, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
								}
							}
							ZEPHIR_INIT_NVAR(&subValue);
							continue;
						}
						if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
							zephir_cast_to_string(&_65$$23, &value);
							ZEPHIR_CALL_METHOD(&_64$$23, this_ptr, "quote", &_14, 0, &_65$$23);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_66$$23);
							ZEPHIR_CONCAT_VSVS(&_66$$23, &key, "=\"", &_64$$23, "\"");
							zephir_array_append(&parts, &_66$$23, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 60);
							continue;
						}
						if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
							zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 65);
							continue;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _48$$17, "rewind", NULL, 0);
					zephir_check_call_status();
					_68$$17 = 1;
					while (1) {
						if (_68$$17) {
							_68$$17 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _48$$17, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_67$$17, _48$$17, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_67$$17)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&key, _48$$17, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&value, _48$$17, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								if (Z_TYPE_P(&value) == IS_STRING) {
									ZEPHIR_INIT_NVAR(&_70$$26);
									zephir_string_to_char_array(&_70$$26, &value);
									_69$$26 = &_70$$26;
								} else {
									_69$$26 = &value;
								}
								zephir_is_iterable(_69$$26, 0, "phalcon/Html/Link/Serializer/Header.zep", 56);
								if (Z_TYPE_P(_69$$26) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_69$$26), _71$$26)
									{
										ZEPHIR_INIT_NVAR(&subValue);
										ZVAL_COPY(&subValue, _71$$26);
										zephir_cast_to_string(&_73$$27, &subValue);
										ZEPHIR_CALL_METHOD(&_72$$27, this_ptr, "quote", &_14, 0, &_73$$27);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_74$$27);
										ZEPHIR_CONCAT_VSVS(&_74$$27, &key, "=\"", &_72$$27, "\"");
										zephir_array_append(&parts, &_74$$27, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, _69$$26, "rewind", NULL, 0);
									zephir_check_call_status();
									_76$$26 = 1;
									while (1) {
										if (_76$$26) {
											_76$$26 = 0;
										} else {
											ZEPHIR_CALL_METHOD(NULL, _69$$26, "next", NULL, 0);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(&_75$$26, _69$$26, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_75$$26)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&subValue, _69$$26, "current", NULL, 0);
										zephir_check_call_status();
											zephir_cast_to_string(&_78$$28, &subValue);
											ZEPHIR_CALL_METHOD(&_77$$28, this_ptr, "quote", &_14, 0, &_78$$28);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_79$$28);
											ZEPHIR_CONCAT_VSVS(&_79$$28, &key, "=\"", &_77$$28, "\"");
											zephir_array_append(&parts, &_79$$28, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
									}
								}
								ZEPHIR_INIT_NVAR(&subValue);
								continue;
							}
							if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
								zephir_cast_to_string(&_81$$29, &value);
								ZEPHIR_CALL_METHOD(&_80$$29, this_ptr, "quote", &_14, 0, &_81$$29);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_82$$29);
								ZEPHIR_CONCAT_VSVS(&_82$$29, &key, "=\"", &_80$$29, "\"");
								zephir_array_append(&parts, &_82$$29, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 60);
								continue;
							}
							if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
								zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 65);
								continue;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&value);
				ZEPHIR_INIT_NVAR(&key);
				ZEPHIR_CALL_METHOD(&_83$$17, &link, "gethref", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_84$$17);
				zephir_fast_join_str(&_84$$17, SL("; "), &parts);
				ZEPHIR_INIT_NVAR(&_47$$17);
				ZEPHIR_CONCAT_SVSV(&_47$$17, "<", &_83$$17, ">", &_84$$17);
				zephir_array_append(&elements, &_47$$17, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 73);
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

