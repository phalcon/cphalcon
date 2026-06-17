
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
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_Serializer_Header)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Link\\Serializer, Header, phalcon, html_link_serializer_header, phalcon_html_link_serializer_header_method_entry, 0);

	zend_class_implements(phalcon_html_link_serializer_header_ce, 1, phalcon_html_link_serializer_serializerinterface_ce);
	return SUCCESS;
}

/**
 * Serializes all the passed links to a HTTP link header
 */
PHP_METHOD(Phalcon_Html_Link_Serializer_Header, serialize)
{
	zval _9$$7, _15$$8, _18$$9, _24$$13, _29$$14, _32$$15, _47$$21, _52$$22, _55$$23, _61$$27, _66$$28, _69$$29;
	zend_string *_6$$3, *_44$$17;
	zend_ulong _5$$3, _43$$17;
	zend_bool _37, _21$$3, _13$$6, _27$$12, _58$$17, _50$$20, _64$$26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *links_param = NULL, attributes, key, link, rels, result, subValue, value, *_0, _36, _1$$3, _2$$3, _3$$3, *_4$$3, _20$$3, _34$$3, _35$$3, *_7$$6, _12$$6, _8$$7, _11$$7, _14$$8, _16$$8, _17$$9, _19$$9, *_22$$12, _26$$12, _23$$13, _25$$13, _28$$14, _30$$14, _31$$15, _33$$15, _38$$17, _39$$17, _40$$17, _41$$17, *_42$$17, _57$$17, _71$$17, _72$$17, *_45$$20, _49$$20, _46$$21, _48$$21, _51$$22, _53$$22, _54$$23, _56$$23, *_59$$26, _63$$26, _60$$27, _62$$27, _65$$28, _67$$28, _68$$29, _70$$29;
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
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_34$$3);
	ZVAL_UNDEF(&_35$$3);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_31$$15);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_40$$17);
	ZVAL_UNDEF(&_41$$17);
	ZVAL_UNDEF(&_57$$17);
	ZVAL_UNDEF(&_71$$17);
	ZVAL_UNDEF(&_72$$17);
	ZVAL_UNDEF(&_49$$20);
	ZVAL_UNDEF(&_46$$21);
	ZVAL_UNDEF(&_48$$21);
	ZVAL_UNDEF(&_51$$22);
	ZVAL_UNDEF(&_53$$22);
	ZVAL_UNDEF(&_54$$23);
	ZVAL_UNDEF(&_56$$23);
	ZVAL_UNDEF(&_63$$26);
	ZVAL_UNDEF(&_60$$27);
	ZVAL_UNDEF(&_62$$27);
	ZVAL_UNDEF(&_65$$28);
	ZVAL_UNDEF(&_67$$28);
	ZVAL_UNDEF(&_68$$29);
	ZVAL_UNDEF(&_70$$29);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_29$$14);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_47$$21);
	ZVAL_UNDEF(&_52$$22);
	ZVAL_UNDEF(&_55$$23);
	ZVAL_UNDEF(&_61$$27);
	ZVAL_UNDEF(&_66$$28);
	ZVAL_UNDEF(&_69$$29);
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
	zephir_is_iterable(&links, 0, "phalcon/Html/Link/Serializer/Header.zep", 70);
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
			zephir_is_iterable(&attributes, 0, "phalcon/Html/Link/Serializer/Header.zep", 64);
			if (Z_TYPE_P(&attributes) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _5$$3, _6$$3, _4$$3)
				{
					ZEPHIR_INIT_NVAR(&key);
					if (_6$$3 != NULL) { 
						ZVAL_STR_COPY(&key, _6$$3);
					} else {
						ZVAL_LONG(&key, _5$$3);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _4$$3);
					if (Z_TYPE_P(&value) == IS_ARRAY) {
						zephir_is_iterable(&value, 0, "phalcon/Html/Link/Serializer/Header.zep", 50);
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&value), _7$$6)
							{
								ZEPHIR_INIT_NVAR(&subValue);
								ZVAL_COPY(&subValue, _7$$6);
								zephir_cast_to_string(&_9$$7, &subValue);
								ZEPHIR_CALL_METHOD(&_8$$7, this_ptr, "quote", &_10, 0, &_9$$7);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_11$$7);
								ZEPHIR_CONCAT_VSVS(&_11$$7, &key, "=\"", &_8$$7, "\"");
								zephir_array_append(&parts, &_11$$7, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
							zephir_check_call_status();
							_13$$6 = 1;
							while (1) {
								if (_13$$6) {
									_13$$6 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_12$$6, &value, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_12$$6)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&subValue, &value, "current", NULL, 0);
								zephir_check_call_status();
									zephir_cast_to_string(&_15$$8, &subValue);
									ZEPHIR_CALL_METHOD(&_14$$8, this_ptr, "quote", &_10, 0, &_15$$8);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_16$$8);
									ZEPHIR_CONCAT_VSVS(&_16$$8, &key, "=\"", &_14$$8, "\"");
									zephir_array_append(&parts, &_16$$8, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
							}
						}
						ZEPHIR_INIT_NVAR(&subValue);
						continue;
					}
					if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
						zephir_cast_to_string(&_18$$9, &value);
						ZEPHIR_CALL_METHOD(&_17$$9, this_ptr, "quote", &_10, 0, &_18$$9);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_19$$9);
						ZEPHIR_CONCAT_VSVS(&_19$$9, &key, "=\"", &_17$$9, "\"");
						zephir_array_append(&parts, &_19$$9, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
						continue;
					}
					if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
						zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 59);
						continue;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
				zephir_check_call_status();
				_21$$3 = 1;
				while (1) {
					if (_21$$3) {
						_21$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_20$$3, &attributes, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_20$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&value, &attributes, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							zephir_is_iterable(&value, 0, "phalcon/Html/Link/Serializer/Header.zep", 50);
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&value), _22$$12)
								{
									ZEPHIR_INIT_NVAR(&subValue);
									ZVAL_COPY(&subValue, _22$$12);
									zephir_cast_to_string(&_24$$13, &subValue);
									ZEPHIR_CALL_METHOD(&_23$$13, this_ptr, "quote", &_10, 0, &_24$$13);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_25$$13);
									ZEPHIR_CONCAT_VSVS(&_25$$13, &key, "=\"", &_23$$13, "\"");
									zephir_array_append(&parts, &_25$$13, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
								zephir_check_call_status();
								_27$$12 = 1;
								while (1) {
									if (_27$$12) {
										_27$$12 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_26$$12, &value, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_26$$12)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&subValue, &value, "current", NULL, 0);
									zephir_check_call_status();
										zephir_cast_to_string(&_29$$14, &subValue);
										ZEPHIR_CALL_METHOD(&_28$$14, this_ptr, "quote", &_10, 0, &_29$$14);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_30$$14);
										ZEPHIR_CONCAT_VSVS(&_30$$14, &key, "=\"", &_28$$14, "\"");
										zephir_array_append(&parts, &_30$$14, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
								}
							}
							ZEPHIR_INIT_NVAR(&subValue);
							continue;
						}
						if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
							zephir_cast_to_string(&_32$$15, &value);
							ZEPHIR_CALL_METHOD(&_31$$15, this_ptr, "quote", &_10, 0, &_32$$15);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_33$$15);
							ZEPHIR_CONCAT_VSVS(&_33$$15, &key, "=\"", &_31$$15, "\"");
							zephir_array_append(&parts, &_33$$15, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
							continue;
						}
						if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
							zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 59);
							continue;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
			ZEPHIR_CALL_METHOD(&_34$$3, &link, "gethref", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_35$$3);
			zephir_fast_join_str(&_35$$3, SL("; "), &parts);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZEPHIR_CONCAT_SVSV(&_3$$3, "<", &_34$$3, ">", &_35$$3);
			zephir_array_append(&elements, &_3$$3, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 67);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &links, "rewind", NULL, 0);
		zephir_check_call_status();
		_37 = 1;
		while (1) {
			if (_37) {
				_37 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &links, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_36, &links, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_36)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&link, &links, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_38$$17, &link, "istemplated", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_38$$17)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&attributes, &link, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&rels, &link, "getrels", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_39$$17);
				zephir_create_array(&_39$$17, 2, 0);
				ZEPHIR_INIT_NVAR(&_40$$17);
				ZVAL_STRING(&_40$$17, "");
				zephir_array_fast_append(&_39$$17, &_40$$17);
				ZEPHIR_INIT_NVAR(&_40$$17);
				zephir_fast_join_str(&_40$$17, SL(" "), &rels);
				ZEPHIR_INIT_NVAR(&_41$$17);
				ZEPHIR_CONCAT_SVS(&_41$$17, "rel=\"", &_40$$17, "\"");
				zephir_array_fast_append(&_39$$17, &_41$$17);
				ZEPHIR_CPY_WRT(&parts, &_39$$17);
				zephir_is_iterable(&attributes, 0, "phalcon/Html/Link/Serializer/Header.zep", 64);
				if (Z_TYPE_P(&attributes) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _43$$17, _44$$17, _42$$17)
					{
						ZEPHIR_INIT_NVAR(&key);
						if (_44$$17 != NULL) { 
							ZVAL_STR_COPY(&key, _44$$17);
						} else {
							ZVAL_LONG(&key, _43$$17);
						}
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_COPY(&value, _42$$17);
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							zephir_is_iterable(&value, 0, "phalcon/Html/Link/Serializer/Header.zep", 50);
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&value), _45$$20)
								{
									ZEPHIR_INIT_NVAR(&subValue);
									ZVAL_COPY(&subValue, _45$$20);
									zephir_cast_to_string(&_47$$21, &subValue);
									ZEPHIR_CALL_METHOD(&_46$$21, this_ptr, "quote", &_10, 0, &_47$$21);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_48$$21);
									ZEPHIR_CONCAT_VSVS(&_48$$21, &key, "=\"", &_46$$21, "\"");
									zephir_array_append(&parts, &_48$$21, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
								zephir_check_call_status();
								_50$$20 = 1;
								while (1) {
									if (_50$$20) {
										_50$$20 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_49$$20, &value, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_49$$20)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&subValue, &value, "current", NULL, 0);
									zephir_check_call_status();
										zephir_cast_to_string(&_52$$22, &subValue);
										ZEPHIR_CALL_METHOD(&_51$$22, this_ptr, "quote", &_10, 0, &_52$$22);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_53$$22);
										ZEPHIR_CONCAT_VSVS(&_53$$22, &key, "=\"", &_51$$22, "\"");
										zephir_array_append(&parts, &_53$$22, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
								}
							}
							ZEPHIR_INIT_NVAR(&subValue);
							continue;
						}
						if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
							zephir_cast_to_string(&_55$$23, &value);
							ZEPHIR_CALL_METHOD(&_54$$23, this_ptr, "quote", &_10, 0, &_55$$23);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_56$$23);
							ZEPHIR_CONCAT_VSVS(&_56$$23, &key, "=\"", &_54$$23, "\"");
							zephir_array_append(&parts, &_56$$23, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
							continue;
						}
						if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
							zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 59);
							continue;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
					zephir_check_call_status();
					_58$$17 = 1;
					while (1) {
						if (_58$$17) {
							_58$$17 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_57$$17, &attributes, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_57$$17)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&value, &attributes, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								zephir_is_iterable(&value, 0, "phalcon/Html/Link/Serializer/Header.zep", 50);
								if (Z_TYPE_P(&value) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&value), _59$$26)
									{
										ZEPHIR_INIT_NVAR(&subValue);
										ZVAL_COPY(&subValue, _59$$26);
										zephir_cast_to_string(&_61$$27, &subValue);
										ZEPHIR_CALL_METHOD(&_60$$27, this_ptr, "quote", &_10, 0, &_61$$27);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_62$$27);
										ZEPHIR_CONCAT_VSVS(&_62$$27, &key, "=\"", &_60$$27, "\"");
										zephir_array_append(&parts, &_62$$27, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
									zephir_check_call_status();
									_64$$26 = 1;
									while (1) {
										if (_64$$26) {
											_64$$26 = 0;
										} else {
											ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(&_63$$26, &value, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_63$$26)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&subValue, &value, "current", NULL, 0);
										zephir_check_call_status();
											zephir_cast_to_string(&_66$$28, &subValue);
											ZEPHIR_CALL_METHOD(&_65$$28, this_ptr, "quote", &_10, 0, &_66$$28);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_67$$28);
											ZEPHIR_CONCAT_VSVS(&_67$$28, &key, "=\"", &_65$$28, "\"");
											zephir_array_append(&parts, &_67$$28, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
									}
								}
								ZEPHIR_INIT_NVAR(&subValue);
								continue;
							}
							if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
								zephir_cast_to_string(&_69$$29, &value);
								ZEPHIR_CALL_METHOD(&_68$$29, this_ptr, "quote", &_10, 0, &_69$$29);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_70$$29);
								ZEPHIR_CONCAT_VSVS(&_70$$29, &key, "=\"", &_68$$29, "\"");
								zephir_array_append(&parts, &_70$$29, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
								continue;
							}
							if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
								zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 59);
								continue;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&value);
				ZEPHIR_INIT_NVAR(&key);
				ZEPHIR_CALL_METHOD(&_71$$17, &link, "gethref", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_72$$17);
				zephir_fast_join_str(&_72$$17, SL("; "), &parts);
				ZEPHIR_INIT_NVAR(&_41$$17);
				ZEPHIR_CONCAT_SVSV(&_41$$17, "<", &_71$$17, ">", &_72$$17);
				zephir_array_append(&elements, &_41$$17, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 67);
		}
	}
	ZEPHIR_INIT_NVAR(&link);
	if (zephir_fast_count_int(&elements) > 0) {
		ZEPHIR_INIT_NVAR(&result);
		zephir_fast_join_str(&result, SL(","), &elements);
	}
	RETURN_CCTOR(&result);
}

/**
 * Escapes a quoted-string attribute value per RFC 8288 section 3: a
 * backslash and a double quote are each prefixed with a backslash so the
 * value cannot terminate or corrupt the header field.
 *
 * @param string $value
 *
 * @return string
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

