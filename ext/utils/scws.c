
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


#include "utils/scws.h"

/**
 * Phalcon\Utils\Scws
 *
 * Phalcon\Utils\Scws is a simple Chinese word segmentation tool.
 */
static int le_scws;

static void *phalcon_php_create_scws(char * charset TSRMLS_D)
{
	struct php_scws *ps;
	char *ini_cs;
	scws_t s;

	s = scws_new();
	if (s == NULL)			
		return NULL;	

	ps = (struct php_scws *)emalloc(sizeof(struct php_scws));
	ps->s = s;
	ps->zt = NULL;
	ps->charset[0] = '\0';
	ps->rsrc_id = ZEND_REGISTER_RESOURCE(NULL, ps, le_scws);
	if (charset) {	
		memset(ps->charset, 0, sizeof(ps->charset));
		strncpy(ps->charset, charset, sizeof(ps->charset)-1);		
		scws_set_charset(s, ps->charset);
	}

	return ((void *)ps);
}


/**
 * Phalcon\Utils\Scws initializer
 */
PHALCON_INIT_CLASS(Phalcon_Utils_Scws){

	PHALCON_REGISTER_CLASS(Phalcon\\Utils, Scws, utils_scws, phalcon_utils_scws_method_entry, 0);

	le_scws = zend_register_list_destructors_ex(php_scws_dtor, NULL, PHP_SCWS_OBJECT_TAG, module_number);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_scws"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
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
	
	ps = (struct php_scws *)phalcon_php_create_scws(str TSRMLS_C);
	if (ps == NULL) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_utils_exception_ce, "Can't create new scws object");
		return;
	}
	
	phalcon_update_property_long(this_ptr, SL("_scws"), ps->rsrc_id TSRMLS_CC);
}

/**
 * Phalcon\Utils\Scws destruct
 */
PHP_METHOD(Phalcon_Utils_Scws, __destruct){
	
	zval *scws;
	struct php_scws *ps;
	
	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHP_SCWS_OBJECT_TAG, le_scws);
	
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
	int cs_len;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &charset);
	
	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHP_SCWS_OBJECT_TAG, le_scws);
	
	memset(ps->charset, 0, sizeof(ps->charset));
	strncpy(ps->charset, Z_STRVAL_P(charset), sizeof(ps->charset)-1);
	scws_set_charset(ps->s, ps->charset);

	PHALCON_MM_RESTORE();
}

/**
 * 添加分词所用的词典，新加入的优先查找。
 *
 * @param string dict_path
 *
 * @return Phalcon\Utils\Scws
 */
PHP_METHOD(Phalcon_Utils_Scws, add_dict){
	
	zval *dict_path, *mode = NULL, *scws, *realpath;
	struct php_scws *ps;
	long xmode = 0;
	int cs_len;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &dict_path, &mode);

	if (phalcon_file_exists(file TSRMLS_CC) == FAILURE) {
		RETURN_MM_FALSE;
	}

	if (mode) {
		xmode = Z_LVAL_P(mode);
	}
	
	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHP_SCWS_OBJECT_TAG, le_scws);

	PHALCON_INIT_VAR(realpath);
	phalcon_realpath(realpath, dict_path TSRMLS_CC);
	
	xmode = (int) scws_add_dict(ps->s, Z_STRVAL_P(realpath), xmode);

	if (xmode != 0) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Failed to add the dict file");
		RETURN_MM_FALSE;
	}

	RETURN_MM_TRUE;
}

/**
 * 设定分词所用的词典并清除已存在的词典列表。
 *
 * @param string dict_path
 *
 * @return Phalcon\Utils\Scws
 */
PHP_METHOD(Phalcon_Utils_Scws, set_dict){
	
	zval *dict_path, *mode = NULL, *scws, *realpath;
	struct php_scws *ps;
	long xmode = 0;
	int cs_len;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &dict_path, &mode);

	if (phalcon_file_exists(file TSRMLS_CC) == FAILURE) {
		RETURN_MM_FALSE;
	}

	if (mode) {
		xmode = Z_LVAL_P(mode);
	}
	
	scws  = phalcon_fetch_nproperty_this(this_ptr, SL("_scws"), PH_NOISY_CC);

	ZEND_FETCH_RESOURCE(ps, struct php_scws *, &scws, -1, PHP_SCWS_OBJECT_TAG, le_scws);

	PHALCON_INIT_VAR(realpath);
	phalcon_realpath(realpath, dict_path TSRMLS_CC);
	
	xmode = (int) scws_set_dict(ps->s, Z_STRVAL_P(realpath), xmode);

	if (xmode != 0) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Failed to set the dict file");
		RETURN_MM_FALSE;
	}

	RETURN_MM_TRUE;
}

