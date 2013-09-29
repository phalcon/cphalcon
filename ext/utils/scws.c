
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  |          Vladimir Kolesnikov <vladimir@free-sevastopol.com>            |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "ext/standard/php_array.h"
#include "ext/pcre/php_pcre.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/file.h"

#include "utils/scws.h"
#include "utils/exception.h"
#include <scws.h>

#define	PHALCON_SCWS_OBJECT_TAG "scws handler"

static int le_scws;

struct php_scws
{
	scws_t s;
	zval *zt;
	char charset[8];
	int rsrc_id;
};

static ZEND_RSRC_DTOR_FUNC(php_scws_dtor)
{
	if (rsrc->ptr) 
	{
		struct php_scws *ps = (struct php_scws *) rsrc->ptr;

		scws_free(ps->s);
		
		if (ps->zt) {
			zval_ptr_dtor(&ps->zt);
			ps->zt = NULL;
		}
		efree(ps);
		rsrc->ptr = NULL;
	}
}

/**
 * Phalcon\Utils\Scws
 *
 * Phalcon\Utils\Scws is a simple Chinese word segmentation tool.
 */


/**
 * Phalcon\Utils\Scws initializer
 */
PHALCON_INIT_CLASS(Phalcon_Utils_Scws){

	PHALCON_REGISTER_CLASS(Phalcon\\Utils, Scws, utils_scws, phalcon_utils_scws_method_entry, 0);

	le_scws = zend_register_list_destructors_ex(php_scws_dtor, NULL, PHALCON_SCWS_OBJECT_TAG, module_number);
	zend_declare_property_null(phalcon_utils_scws_ce, SL("_scws"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

static void *phalcon_php_create_scws(zval *return_value, char* charset TSRMLS_DC)
{
	struct php_scws *ps;
	scws_t s;

	s = scws_new();
	if (s == NULL)			
		return NULL;	

	ps = (struct php_scws *)emalloc(sizeof(struct php_scws));
	ps->s = s;
	ps->zt = NULL;
	ps->charset[0] = '\0';
	ps->rsrc_id = ZEND_REGISTER_RESOURCE(return_value, ps, le_scws);
	if (charset) {	
		memset(ps->charset, 0, sizeof(ps->charset));
		strncpy(ps->charset, charset, sizeof(ps->charset)-1);		
		scws_set_charset(s, ps->charset);
	}

	return ((void *)ps);
}

/**
 * Phalcon\Utils\Scws constructor
 */
PHP_METHOD(Phalcon_Utils_Scws, __construct){

	zval *charset = NULL;
	struct php_scws *ps;
	char *str = NULL;

	phalcon_fetch_params(1, 0, 1, &charset);	

	if (charset) {
		str = Z_STRVAL_P(charset);
	}
	
	ps = (struct php_scws *)phalcon_php_create_scws(return_value, str TSRMLS_CC);
	if (ps == NULL) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_utils_exception_ce, "Can't create new scws object");
		return;
	}

	phalcon_update_property_this(this_ptr, SL("_scws"), return_value TSRMLS_CC);
}

/**
 * Phalcon\Utils\Scws destruct
 */
PHP_METHOD(Phalcon_Utils_Scws, __destruct){
	
	zval *scws;
	struct php_scws *ps;
	
	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHALCON_SCWS_OBJECT_TAG, le_scws);
	
	zend_list_delete(ps->rsrc_id);
}

/**
 * 设定分词词典、规则集、欲分文本字符串的字符集。
 *
 * @param string charset
 *
 * @return Phalcon\Utils\Scws
 */
PHP_METHOD(Phalcon_Utils_Scws, set_charset){
	
	zval *charset, *scws;
	struct php_scws *ps;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &charset);
	
	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHALCON_SCWS_OBJECT_TAG, le_scws);
	
	memset(ps->charset, 0, sizeof(ps->charset));
	strncpy(ps->charset, Z_STRVAL_P(charset), sizeof(ps->charset)-1);
	scws_set_charset(ps->s, ps->charset);

	PHALCON_MM_RESTORE();
}

/**
 * 添加分词所用的词典，新加入的优先查找。
 *
 * @param string $dict_path
 *
 * @return Phalcon\Utils\Scws
 */
PHP_METHOD(Phalcon_Utils_Scws, add_dict){
	
	zval *dict_path, *mode = NULL, *scws, *realpath;
	struct php_scws *ps;
	long xmode = 0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &dict_path, &mode);

	if (phalcon_file_exists(dict_path TSRMLS_CC) == FAILURE) {
		RETURN_MM_FALSE;
	}

	if (mode) {
		xmode = Z_LVAL_P(mode);
	}
	
	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHALCON_SCWS_OBJECT_TAG, le_scws);

	PHALCON_INIT_VAR(realpath);
	phalcon_realpath(realpath, dict_path TSRMLS_CC);
	
	if (php_check_open_basedir(Z_STRVAL_P(realpath) TSRMLS_CC)) {
		RETURN_MM_FALSE;
	}
	
	xmode = (int) scws_add_dict(ps->s, Z_STRVAL_P(realpath), xmode);

	if (xmode != 0) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Failed to add the dict file: No operation permissions");
		RETURN_MM_FALSE;
	}

	RETURN_MM_TRUE;
}

/**
 * 设定分词所用的词典并清除已存在的词典列表。
 *
 * @param string $dict_path
 *
 * @return Phalcon\Utils\Scws
 */
PHP_METHOD(Phalcon_Utils_Scws, set_dict){
	
	zval *dict_path, *mode = NULL, *scws, *realpath;
	struct php_scws *ps;
	long xmode = 0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &dict_path, &mode);

	if (phalcon_file_exists(dict_path TSRMLS_CC) == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "File does not exist ");
		RETURN_MM_FALSE;
	}

	if (mode) {
		xmode = Z_LVAL_P(mode);
	}
	
	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHALCON_SCWS_OBJECT_TAG, le_scws);

	PHALCON_INIT_VAR(realpath);
	phalcon_realpath(realpath, dict_path TSRMLS_CC);
	
	if (php_check_open_basedir(Z_STRVAL_P(realpath) TSRMLS_CC)) {
		RETURN_MM_FALSE;
	}
	
	xmode = (int) scws_set_dict(ps->s, Z_STRVAL_P(realpath), xmode);

	if (xmode != 0) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Failed to set the dict file: No operation permissions");
		RETURN_MM_FALSE;
	}

	RETURN_MM_TRUE;
}

/**
 * 设定分词所用的新词识别规则集（用于人名、地名、数字时间年代等识别）。
 *
 * @param string $rule_path
 *
 * @return Phalcon\Utils\Scws
 */
PHP_METHOD(Phalcon_Utils_Scws, set_rule){
	
	zval *rule_path, *scws, *realpath;
	struct php_scws *ps;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &rule_path);

	if (phalcon_file_exists(rule_path TSRMLS_CC) == FAILURE) {
		RETURN_MM_FALSE;
	}
	
	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHALCON_SCWS_OBJECT_TAG, le_scws);

	PHALCON_INIT_VAR(realpath);
	phalcon_realpath(realpath, rule_path TSRMLS_CC);
	
	if (php_check_open_basedir(Z_STRVAL_P(realpath) TSRMLS_CC)) {
		RETURN_MM_FALSE;
	}

	scws_set_rule(ps->s, Z_STRVAL_P(realpath));

	if (ps->s->r == NULL) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Failed to load the ruleset file: No operation permissions");
		RETURN_MM_FALSE;
	}

	RETURN_MM_TRUE;
}

/**
 * 设定分词返回结果时是否去除一些特殊的标点符号之类。
 *
 * @param bool $ignore
 *
 * @return Phalcon\Utils\Scws
 */
PHP_METHOD(Phalcon_Utils_Scws, set_ignore){
	
	zval *ignore, *scws;
	struct php_scws *ps;

	phalcon_fetch_params(0, 1, 0, &ignore);
	
	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHALCON_SCWS_OBJECT_TAG, le_scws);

	scws_set_ignore(ps->s, zend_is_true(ignore) ? SCWS_YEA : SCWS_NA);

	RETURN_TRUE;
}

/**
 * 设定分词返回结果时是否去除一些特殊的标点符号之类。
 *
 * @param int $mode
 *
 * @return Phalcon\Utils\Scws
 */
PHP_METHOD(Phalcon_Utils_Scws, set_multi){
	
	zval *mode, *scws;
	struct php_scws *ps;
	long multi = 0;

	phalcon_fetch_params(0, 1, 0, &mode);

	if (Z_TYPE_P(mode) == IS_LONG) {
		multi = Z_LVAL_P(mode);
	} else {
		multi = phalcon_get_intval(mode);
	}
	
	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHALCON_SCWS_OBJECT_TAG, le_scws);

	if (multi < 0 || (multi & 0x10))
		RETURN_FALSE;

	scws_set_multi(ps->s, (multi<<12));

	RETURN_TRUE;
}

/**
 * 设定是否将闲散文字自动以二字分词法聚合。
 *
 * @param bool $duality
 *
 * @return Phalcon\Utils\Scws
 */
PHP_METHOD(Phalcon_Utils_Scws, set_duality){
	
	zval *duality, *scws;
	struct php_scws *ps;

	phalcon_fetch_params(0, 1, 0, &duality);
	
	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHALCON_SCWS_OBJECT_TAG, le_scws);

	scws_set_duality(ps->s, zend_is_true(duality) ? SCWS_YEA : SCWS_NA);

	RETURN_TRUE;
}

/**
 * 发送设定分词所要切割的文本。
 *
 * @param string $text
 *
 * @return Phalcon\Utils\Scws
 */
PHP_METHOD(Phalcon_Utils_Scws, send_text){
	
	zval *text, *scws;
	struct php_scws *ps;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &text);

	if (Z_TYPE_P(text) != IS_STRING) {
		PHALCON_SEPARATE_PARAM(text);
		convert_to_string_ex(&text);
	}
	
	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHALCON_SCWS_OBJECT_TAG, le_scws);

	if (ps->zt) {
		zval_ptr_dtor(&ps->zt);
	}

	ALLOC_INIT_ZVAL(ps->zt);
	ZVAL_ZVAL(ps->zt, text, 1, 0);

	scws_send_text(ps->s, Z_STRVAL_P(ps->zt), Z_STRLEN_P(ps->zt));

	RETURN_MM_TRUE;
}

/**
 * 发送设定分词所要切割的文本。
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Utils_Scws, get_result){
	
	zval *row = NULL, *scws;
	struct php_scws *ps;
	scws_res_t res, cur;

	PHALCON_MM_GROW();

	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHALCON_SCWS_OBJECT_TAG, le_scws);

	cur = res = scws_get_result(ps->s);
	if (res == NULL)		
		RETURN_FALSE;
	
	array_init(return_value);
	while (cur != NULL) {
		PHALCON_INIT_NVAR(row);
		array_init(row);

		phalcon_array_update_string_string(&row, SL("word"), (char*)(ps->s->txt + cur->off), cur->len, PH_COPY);
		phalcon_array_update_string_long(&row, SL("off"), cur->off, 0);
		phalcon_array_update_string_long(&row, SL("len"), cur->len, 0);
		phalcon_array_update_string_double(&row, SL("idf"), (double) cur->idf, 0);
		phalcon_array_update_string_string(&row, SL("attr"), SL(cur->attr), PH_COPY);

		phalcon_array_append(&return_value, row, 0);
		
		cur = cur->next;
	}
	scws_free_result(res);

	PHALCON_MM_RESTORE();
}

/**
 * 根据 send_text 设定的文本内容，返回系统计算出来最主要的词汇列表。
 *
 * @param int $limit
 * @param string $option
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Utils_Scws, get_tops){
	
	zval *limit, *options = NULL, *scws, *row;
	struct php_scws *ps;
	scws_top_t top, cur;
	long num = 10;
	char *attr = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &limit, &options);

	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHALCON_SCWS_OBJECT_TAG, le_scws);

	if (options) {
		if (Z_TYPE_P(options) != IS_STRING) {
			PHALCON_SEPARATE_PARAM(options);
			convert_to_string_ex(&options);
		}

		attr = Z_STRVAL_P(options);
	}

	if (Z_TYPE_P(limit) == IS_LONG && Z_LVAL_P(limit) > 0) {
		num = Z_LVAL_P(limit);
	}
	
	cur = top = scws_get_tops(ps->s, num, attr);
	array_init(return_value);
	while (cur != NULL)
	{
		PHALCON_INIT_NVAR(row);
		array_init(row);

		phalcon_array_update_string_string(&row, SL("word"), SL(cur->word), PH_COPY);
		phalcon_array_update_string_long(&row, SL("times"), cur->times, 0);
		phalcon_array_update_string_double(&row, SL("weight"), (double) cur->weight, 0);
		phalcon_array_update_string_string(&row, SL("attr"), SL(cur->attr), PH_COPY);

		phalcon_array_append(&return_value, row, 0);
		
		cur = cur->next;
	}
	scws_free_tops(top);

	PHALCON_MM_RESTORE();
}

/**
 * 根据 send_text 设定的文本内容，返回系统中是否包括符合词性要求的关键词。
 *
 * @param string $option
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Utils_Scws, has_word){
	
	zval *options, *scws;
	struct php_scws *ps;
	char *attr = NULL;

	phalcon_fetch_params(0, 1, 0, &options);

	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHALCON_SCWS_OBJECT_TAG, le_scws);

	if (Z_TYPE_P(options) != IS_STRING) {
		PHALCON_SEPARATE_PARAM(options);
		convert_to_string_ex(&options);
	}

	attr = Z_STRVAL_P(options);

	if (scws_has_word(ps->s, attr) == 0) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}

/**
 * 根据 send_text 设定的文本内容，返回系统中词性符合要求的关键词汇。
 *
 * @param string $option
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Utils_Scws, get_words){
	
	zval *options, *scws, *row;
	struct php_scws *ps;
	scws_top_t top, cur;
	char *attr = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &options);

	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHALCON_SCWS_OBJECT_TAG, le_scws);

	if (Z_TYPE_P(options) != IS_STRING) {
		PHALCON_SEPARATE_PARAM(options);
		convert_to_string_ex(&options);
	}

	attr = Z_STRVAL_P(options);

	array_init(return_value);
	cur = top = scws_get_words(ps->s, attr);
	while (cur != NULL)
	{
		PHALCON_INIT_NVAR(row);
		array_init(row);

		phalcon_array_update_string_string(&row, SL("word"), SL(cur->word), PH_COPY);
		phalcon_array_update_string_long(&row, SL("times"), cur->times, 0);
		phalcon_array_update_string_double(&row, SL("weight"), (double) cur->weight, 0);
		phalcon_array_update_string_string(&row, SL("attr"), SL(cur->attr), PH_COPY);

		phalcon_array_append(&return_value, row, 0);

		cur = cur->next;
	}
	scws_free_tops(top);

	PHALCON_MM_RESTORE();
}

