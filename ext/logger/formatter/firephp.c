
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "ext/standard/php_smart_str.h"

#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"

#include "logger/formatter/firephp.h"

/**
 * Phalcon\Logger\Formatter\Firephp
 *
 * Formats messages so that they can be sent to FirePHP
 */

/**
 * Phalcon\Logger\Formatter\Firephp initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Formatter_Firephp){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Firephp, logger_formatter_firephp, "phalcon\\logger\\formatter", phalcon_logger_formatter_firephp_method_entry, 0);

	zend_class_implements(phalcon_logger_formatter_firephp_ce TSRMLS_CC, 1, phalcon_logger_formatterinterface_ce);

	return SUCCESS;
}

/**
 * Returns the string meaning of a logger constant
 *
 * @param  integer $type
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getTypeString) {

	static const char* lut[10] = {
		"ERROR", "ERROR", "WARN", "ERROR", "WARN",
		"INFO",  "INFO",  "LOG",  "INFO",  "LOG"
	};

	zval *type;
	int itype;

	phalcon_fetch_params(0, 1, 0, &type);

	itype = phalcon_get_intval(type);
	if (itype > 0 && itype < 10) {
		RETURN_STRING(lut[itype], 1);
	}

	RETURN_STRING("CUSTOM", 1);
}

/**
 * Applies a format to a message before sending it to the log
 *
 * @param string $message
 * @param int $type
 * @param int $timestamp
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, format) {

	zval *message, *type, *type_str, *timestamp;
	zval *payload, *backtrace, *meta, *encoded;
	smart_str result = { NULL, 0, 0 };
	int i;
	Bucket *p;

	phalcon_fetch_params(0, 3, 0, &message, &type, &timestamp);

	/**
	 * We intentionally do not use Phalcon's MM for better performance.
	 * All variables allocated with PHALCON_ALLOC_ZVAL() will have
	 * their reference count set to 1 and therefore they can be nicely
	 * put into the result array; when that array will be destroyed,
	 * all inserted variables will be automatically destroyed, too
	 * and we will just save some time by not using Z_ADDREF_P and Z_DELREF_P
	 */

	PHALCON_ALLOC_ZVAL(type_str);
	phalcon_call_method_p1(type_str, this_ptr, "gettypestring", type);

	/**
	 * Get the backtrace. This differs for differemt PHP versions.
	 * 5.3.6+ allows us to skip the function arguments which will save some memory
	 * For 5.4+ there is an extra argument.
	 */
	PHALCON_ALLOC_ZVAL(backtrace);
#if PHP_VERSION_ID < 50306
	zend_fetch_debug_backtrace(backtrace, 1, 0 TSRMLS_CC);
#elif PHP_VERSION_ID < 50400
	zend_fetch_debug_backtrace(backtrace, 1, DEBUG_BACKTRACE_IGNORE_ARGS TSRMLS_CC);
#else
	zend_fetch_debug_backtrace(backtrace, 1, DEBUG_BACKTRACE_IGNORE_ARGS, 0 TSRMLS_CC);
#endif

	if (Z_TYPE_P(backtrace) == IS_ARRAY) {
		HashPosition pos;
		HashTable *ht = Z_ARRVAL_P(backtrace);
		zval **ppzval;
		int found = 0;
		ulong idx;
		char *key;
		uint key_len;

		/**
		 * At this point we know that the backtrace is the array.
		 * Again, we intentionally do not use Phalcon's API because we know
		 * that we are working with the array / hash table and thus we can
		 * save some time by omitting Z_TYPE_P(x) == IS_ARRAY checks
		 */

		for (
			zend_hash_internal_pointer_reset_ex(ht, &pos);
			zend_hash_has_more_elements_ex(ht, &pos) == SUCCESS;
		) {
			zend_hash_get_current_data_ex(ht, (void**)&ppzval, &pos);
			zend_hash_get_current_key_ex(ht, &key, &key_len, &idx, 0, &pos);
			zend_hash_move_forward_ex(ht, &pos);

			if (Z_TYPE_PP(ppzval) == IS_ARRAY) {
				/**
				 * Here we need to skip the latest calls into Phalcon's core.
				 * Calls to Zend internal functions will have "file" index not set.
				 * We remove these entries from the array.
				 */
				if (!found && !zend_hash_exists(Z_ARRVAL_PP(ppzval), SS("file"))) {
					zend_hash_index_del(ht, idx);
				}
				else {
					/**
					 * Remove args and object indices. They usually give
					 * too much information; this is not suitable to send
					 * in the HTTP headers
					 */
					zend_hash_del(Z_ARRVAL_PP(ppzval), "args", sizeof("args"));
					zend_hash_del(Z_ARRVAL_PP(ppzval), "object", sizeof("object"));
					found = 1;
				}
			}
		}

		/**
		 * Now we need to renumber the hash table because we removed several
		 * heading elements. If we don't do this, json_encode() will convert
		 * this array to a JavaScript object which is an unwanted side effect
		 */
		p = ht->pListHead;
		i = 0;
		while (p != NULL) {
			p->nKeyLength = 0;
			p->h = i++;
			p = p->pListNext;
		}

		ht->nNextFreeElement = i;
 		zend_hash_rehash(ht);
	}

	/**
	 * The result will looks like this:
	 *
	 * array(
	 *     array('type' => 'message type', 'backtrace' => array(backtrace goes here)),
	 *     message
	 * )
	 */
	PHALCON_ALLOC_ZVAL(payload);
	array_init_size(payload, 2);

	PHALCON_ALLOC_ZVAL(meta);
	array_init_size(meta, 2);
	add_assoc_zval(meta, "type", type_str);
	add_assoc_zval(meta, "backtrace", backtrace);

	add_next_index_zval(payload, meta);
	add_next_index_zval(payload, message);

	/**
	 * Convert everything to JSON
	 */
	ALLOC_INIT_ZVAL(encoded);
	phalcon_json_encode(encoded, payload, 0 TSRMLS_CC);

	/**
	 * As promised, kill the payload and all associated elements
	 */
	zval_ptr_dtor(&payload);

	/**
	 * We don't want to use Phalcon's concatenation API because it
	 * requires the memory manager. Therefore we fall back to using smart strings.
	 * smart_str_alloc4() will allocate all required memory amount (plus some more)
	 * in one go and this allows us to avoid performance penalties due to
	 * memory reallocations.
	 */
	smart_str_alloc4(&result, Z_STRLEN_P(encoded) + 2 + 5, 0, i);

	/**
	 * The format is:
	 *
	 * <size>|[meta,body]|
	 *
	 * Meta and body are contained in encoded inside the array, as required
	 * by the protocol specification
	 * @see http://www.firephp.org/Wiki/Reference/Protocol
	 */
	smart_str_append_long(&result, Z_STRLEN_P(encoded));
	smart_str_appendc(&result, '|');
	smart_str_appendl(&result, Z_STRVAL_P(encoded), Z_STRLEN_P(encoded));
	smart_str_appendc(&result, '|');
	smart_str_0(&result);

	/* We don't need the JSON message anymore */
	zval_ptr_dtor(&encoded);
	/* Do not free the samrt string because we steal its data for zval */
	RETURN_STRINGL(result.c, result.len, 0);
}
