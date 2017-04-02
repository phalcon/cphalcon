
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Zephir Team (https://www.zephir-lang.com)      |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#include <php.h>
#include "php_ext.h"

#include <Zend/zend_API.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_execute.h>

#include "kernel/main.h"
#include "kernel/extended/fcall.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/backtrace.h"

static const unsigned char tolower_map[256] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
	0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
	0x40, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
	0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
	0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
	0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
	0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
	0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
	0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
	0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF
};

int zephir_has_constructor_ce(const zend_class_entry *ce)
{
	while (ce) {
		if (ce->constructor) {
			return 1;
		}
		ce = ce->parent;
	}
	return 0;
}

#if 0
static inline ulong zephir_update_hash(const char *arKey, uint nKeyLength, ulong hash)
{
	for (; nKeyLength >= 8; nKeyLength -= 8) {
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
	}

	switch (nKeyLength) {
		case 7:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 6:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 5:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 4:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 3:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 2:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 1:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		default: break;
	}

	return hash;
}
#endif

static char *zephir_fcall_possible_method(zend_class_entry *ce, const char *wrong_name TSRMLS_DC)
{
	HashTable *methods;
	HashPosition   pos;
	zend_function *method;
	char *possible_method = NULL;
	zval *left = NULL, *right = NULL, method_name;
	zval *params[1];
	int count;

	count = zend_hash_num_elements(&ce->function_table);
	if (count > 0) {

		ZEPHIR_SINIT_VAR(method_name);
		ZVAL_STRING(&method_name, wrong_name, 0);

		params[0] = &method_name;
		zephir_call_func_aparams(&right, SL("metaphone"), NULL, 0, 1, params TSRMLS_CC);

		methods = &ce->function_table;
		zend_hash_internal_pointer_reset_ex(methods, &pos);

		while (zend_hash_get_current_data_ex(methods, (void **) &method, &pos) == SUCCESS) {

			ZEPHIR_SINIT_VAR(method_name);
			ZVAL_STRING(&method_name, method->common.function_name, 0);

			if (left) {
				zephir_ptr_dtor(&left);
			}
			left = NULL;

			params[0] = &method_name;
			zephir_call_func_aparams(&left, SL("metaphone"), NULL, 0, 1, params TSRMLS_CC);

			if (zephir_is_equal(left, right TSRMLS_CC)) {
				possible_method = (char *) method->common.function_name;
				break;
			}

			zend_hash_move_forward_ex(methods, &pos);
		}

		if (left) {
			zephir_ptr_dtor(&left);
		}

		if (right) {
			zephir_ptr_dtor(&right);
		}
	}

	return possible_method;
}

/**
 * Creates a unique key to cache the current method/function call address for the current scope
 */
static ulong zephir_make_fcall_key(char **result, size_t *length, const zend_class_entry *obj_ce, zephir_call_type type, zval *function_name TSRMLS_DC)
{
	const zend_class_entry *calling_scope = EG(scope);
	char *buf = NULL, *c;
	size_t l = 0, len = 0;
	const size_t ppzce_size = sizeof(zend_class_entry**);
	ulong hash = 5381;

	*result = NULL;
	*length = 0;

	if (calling_scope && type == zephir_fcall_parent) {
		calling_scope = calling_scope->parent;
		if (UNEXPECTED(!calling_scope)) {
			return 0;
		}
	}
	else if (type == zephir_fcall_static) {
		calling_scope = EG(called_scope);
		if (UNEXPECTED(!calling_scope)) {
			return 0;
		}
	}

	if (
		    calling_scope
		 && obj_ce
		 && calling_scope != obj_ce
		 && !instanceof_function(obj_ce, calling_scope TSRMLS_CC)
		 && !instanceof_function(calling_scope, obj_ce TSRMLS_CC)
	) {
		calling_scope = NULL;
	}

	if (Z_TYPE_P(function_name) == IS_STRING) {
		l   = (size_t)(Z_STRLEN_P(function_name)) + 1;
		c   = Z_STRVAL_P(function_name);
		len = 2 * ppzce_size + l + 1;
		buf = emalloc(len);

		memcpy(buf,                  c,               l);
		memcpy(buf + l,              &calling_scope,  ppzce_size);
		memcpy(buf + l + ppzce_size, &obj_ce,         ppzce_size);
		buf[len - 1] = '\0';
	}
	else if (Z_TYPE_P(function_name) == IS_ARRAY) {
		zval **method;
		HashTable *function_hash = Z_ARRVAL_P(function_name);
		if (
			    function_hash->nNumOfElements == 2
			 && zend_hash_index_find(function_hash, 1, (void**)&method) == SUCCESS
			 && Z_TYPE_PP(method) == IS_STRING
		) {
			l   = (size_t)(Z_STRLEN_PP(method)) + 1;
			c   = Z_STRVAL_PP(method);
			len = 2 * ppzce_size + l + 1;
			buf = emalloc(len);

			memcpy(buf,                  c,               l);
			memcpy(buf + l,              &calling_scope,  ppzce_size);
			memcpy(buf + l + ppzce_size, &obj_ce,         ppzce_size);
			buf[len - 1] = '\0';
		}
	}

	if (EXPECTED(buf != NULL)) {
		size_t i;

		for (i = 0; i < l; ++i) {
			char c = buf[i];
			c = tolower_map[(unsigned char)c];

			buf[i] = c;
			hash   = (hash << 5) + hash + c;
		}

		for (i = l; i < len; ++i) {
			char c = buf[i];
			hash = (hash << 5) + hash + c;
		}
	}

	*result = buf;
	*length = len;
	return hash;
}

/**
 * Creates a unique key to cache the current method/function call address for the current scope
 */
static ulong zephir_make_fcall_info_key(char **result, size_t *length, const zend_class_entry *obj_ce, zephir_call_type type, zephir_fcall_info *info TSRMLS_DC)
{
	const zend_class_entry *calling_scope = EG(scope);
	char *buf = NULL, *c;
	size_t l = 0, len = 0;
	const size_t ppzce_size = sizeof(zend_class_entry**);
	ulong hash = 5381;

	*result = NULL;
	*length = 0;

	if (calling_scope && type == zephir_fcall_parent) {
		calling_scope = calling_scope->parent;
		if (UNEXPECTED(!calling_scope)) {
			return 0;
		}
	}
	else if (type == zephir_fcall_static) {
		calling_scope = EG(called_scope);
		if (UNEXPECTED(!calling_scope)) {
			return 0;
		}
	}

	if (
		    calling_scope
		 && obj_ce
		 && calling_scope != obj_ce
		 && !instanceof_function(obj_ce, calling_scope TSRMLS_CC)
		 && !instanceof_function(calling_scope, obj_ce TSRMLS_CC)
	) {
		calling_scope = NULL;
	}

	switch (info->type) {

		case ZEPHIR_FCALL_TYPE_FUNC:

			l   = (size_t)(info->func_length) + 1;
			c   = (char*) info->func_name;
			len = 2 * ppzce_size + l + 1;
			buf = emalloc(len);

			memcpy(buf,                  c,               l);
			memcpy(buf + l,              &calling_scope,  ppzce_size);
			memcpy(buf + l + ppzce_size, &obj_ce,         ppzce_size);
			buf[len - 1] = '\0';
			break;

		case ZEPHIR_FCALL_TYPE_CLASS_SELF_METHOD:
		case ZEPHIR_FCALL_TYPE_CLASS_STATIC_METHOD:
		case ZEPHIR_FCALL_TYPE_CLASS_PARENT_METHOD:
			l   = (size_t)(info->func_length) + 2; /* reserve 1 char for fcall-type */
			c   = (char*) info->func_name;
			len = 2 * ppzce_size + l + 1;
			buf = emalloc(len);

			buf[0] = info->type;
			memcpy(buf + 1,              c,               l - 1);
			memcpy(buf + l,              &calling_scope,  ppzce_size);
			memcpy(buf + l + ppzce_size, &obj_ce,         ppzce_size);
			buf[len - 1] = '\0';
			break;

		case ZEPHIR_FCALL_TYPE_CE_METHOD:
		case ZEPHIR_FCALL_TYPE_ZVAL_METHOD:
			l   = (size_t)(info->func_length) + 1;
			c   = (char*) info->func_name;
			len = 2 * ppzce_size + l + 1;
			buf = emalloc(len);

			memcpy(buf,                  c,               l);
			memcpy(buf + l,              &calling_scope,  ppzce_size);
			memcpy(buf + l + ppzce_size, &obj_ce,         ppzce_size);
			buf[len - 1] = '\0';
			break;
	}

	if (EXPECTED(buf != NULL)) {
		size_t i;

		for (i = 0; i < l; ++i) {
			char c = buf[i];
			c = tolower_map[(unsigned char)c];

			buf[i] = c;
			hash   = (hash << 5) + hash + c;
		}

		for (i = l; i < len; ++i) {
			char c = buf[i];
			hash = (hash << 5) + hash + c;
		}
	}

	*result = buf;
	*length = len;
	return hash;
}

ZEPHIR_ATTR_NONNULL static void zephir_fcall_populate_fci_cache(zend_fcall_info_cache *fcic, zend_fcall_info *fci, zephir_call_type type TSRMLS_DC)
{
	switch (type) {
		case zephir_fcall_parent:
			if (EG(scope) && EG(scope)->parent) {
				fcic->calling_scope = EG(scope)->parent;
				fcic->called_scope  = EG(called_scope);
				fcic->object_ptr    = fci->object_ptr ? fci->object_ptr : EG(This);
				fcic->initialized   = 1;
			}

			break;

		case zephir_fcall_self:
			if (EG(scope)) {
				fcic->calling_scope = EG(scope);
				fcic->called_scope  = EG(called_scope);
				fcic->object_ptr    = fci->object_ptr ? fci->object_ptr : EG(This);
				fcic->initialized   = 1;
			}

			break;

		case zephir_fcall_static:
			if (EG(called_scope)) {
				fcic->calling_scope = EG(called_scope);
				fcic->called_scope  = EG(called_scope);
				fcic->object_ptr    = fci->object_ptr ? fci->object_ptr : EG(This);
				fcic->initialized   = 1;
			}

			break;

		case zephir_fcall_function:
			fcic->calling_scope = NULL;
			fcic->called_scope  = NULL;
			fcic->object_ptr    = NULL;
			fcic->initialized   = 1;
			break;

		case zephir_fcall_ce: {
			zend_class_entry *scope = EG(active_op_array) ? EG(active_op_array)->scope : NULL;

			fcic->initialized      = 1;
			fcic->calling_scope    = EG(scope);
			fcic->object_ptr       = NULL;

			if (scope && EG(This) && instanceof_function(Z_OBJCE_P(EG(This)), scope TSRMLS_CC) && instanceof_function(scope, fcic->calling_scope TSRMLS_CC)) {
				fcic->object_ptr   = EG(This);
				fcic->called_scope = Z_OBJCE_P(fcic->object_ptr);
			}
			else {
				fcic->called_scope = fcic->calling_scope;
			}

			break;
		}

		case zephir_fcall_method:
			fcic->initialized      = 1;
			fcic->calling_scope    = EG(scope);
			fcic->object_ptr       = fci->object_ptr;
			if (fci->object_ptr) {
				fcic->called_scope = Z_OBJCE_P(fci->object_ptr);
			}
			else if (EG(scope) && !(EG(called_scope) && instanceof_function(EG(called_scope), EG(scope) TSRMLS_CC))) {
				fcic->called_scope = EG(scope);
			}
			else {
				fcic->called_scope = EG(called_scope);
			}

			break;

		default:
#ifndef ZEPHIR_RELEASE
			fprintf(stderr, "%s: unknown call type (%d)\n", __func__, (int) type);
			abort();
#endif
			fcic->initialized = 0; /* not strictly necessary but just to be safe */
			break;
	}

}

/**
 * Calls a function/method in the PHP userland
 */
int zephir_call_user_function(zval **object_pp, zend_class_entry *obj_ce, zephir_call_type type,
	zval *function_name, zval **retval_ptr_ptr, zephir_fcall_cache_entry **cache_entry, int cache_slot, zend_uint param_count,
	zval *params[], zephir_fcall_info *info TSRMLS_DC)
{
	zval ***params_ptr, ***params_array = NULL;
	zval **static_params_array[10];
	zval *local_retval_ptr = NULL;
	int status;
	zend_fcall_info fci;
	zend_fcall_info_cache fcic /* , clone */;
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;
	char *fcall_key = NULL;
	size_t fcall_key_len;
	ulong fcall_key_hash;
	zephir_fcall_cache_entry **temp_cache_entry = NULL;
	zend_class_entry *old_scope = EG(scope);
	int reload_cache = 1;

	assert(obj_ce || !object_pp);

	if (retval_ptr_ptr && *retval_ptr_ptr) {
		zval_ptr_dtor(retval_ptr_ptr);
		*retval_ptr_ptr = NULL;
	}

	++zephir_globals_ptr->recursive_lock;

	if (UNEXPECTED(zephir_globals_ptr->recursive_lock > 2048)) {
		zend_error(E_ERROR, "Maximum recursion depth exceeded");
		return FAILURE;
	}

	if (param_count) {
		zend_uint i;

		if (UNEXPECTED(param_count > 10)) {
			params_array = (zval***) emalloc(param_count * sizeof(zval**));
			params_ptr   = params_array;
			for (i = 0; i < param_count; ++i) {
				params_array[i] = &params[i];
			}
		} else {
			params_ptr = static_params_array;
			for (i = 0; i < param_count; ++i) {
				static_params_array[i] = &params[i];
			}
		}
	}
	else {
		params_ptr = NULL;
	}

	if (type != zephir_fcall_function && !object_pp) {
		object_pp = EG(This) ? &EG(This) : NULL;
		if (!obj_ce && object_pp) {
			obj_ce = Z_OBJCE_PP(object_pp);
		}
	}

	if (obj_ce) {
		EG(scope) = obj_ce;
	}

	if (!cache_entry || !*cache_entry) {
		if (zephir_globals_ptr->cache_enabled) {

			if (cache_slot > 0) {
				if (zephir_globals_ptr->scache[cache_slot]) {
					reload_cache = 0;
					temp_cache_entry = &zephir_globals_ptr->scache[cache_slot];
					if (cache_entry) {
						*cache_entry = *temp_cache_entry;
					}
				}
			}

			if (reload_cache) {
				if (info) {
					fcall_key_hash = zephir_make_fcall_info_key(&fcall_key, &fcall_key_len, (object_pp && type != zephir_fcall_ce ? Z_OBJCE_PP(object_pp) : obj_ce), type, info TSRMLS_CC);
				} else {
					fcall_key_hash = zephir_make_fcall_key(&fcall_key, &fcall_key_len, (object_pp && type != zephir_fcall_ce ? Z_OBJCE_PP(object_pp) : obj_ce), type, function_name TSRMLS_CC);
				}
			}
		}
	}

	fci.size           = sizeof(fci);
	fci.function_table = obj_ce ? &obj_ce->function_table : EG(function_table);
	fci.object_ptr     = object_pp ? *object_pp : NULL;
	fci.function_name  = function_name;
	fci.retval_ptr_ptr = retval_ptr_ptr ? retval_ptr_ptr : &local_retval_ptr;
	fci.param_count    = param_count;
	fci.params         = params_ptr;
	fci.no_separation  = 1;
	fci.symbol_table   = NULL;

	fcic.initialized = 0;
	fcic.function_handler = NULL;
	fcic.calling_scope = NULL;
	fcic.called_scope = NULL;
	if (!cache_entry || !*cache_entry) {
		if (fcall_key && zend_hash_quick_find(zephir_globals_ptr->fcache, fcall_key, fcall_key_len, fcall_key_hash, (void**)&temp_cache_entry) != FAILURE) {
			zephir_fcall_populate_fci_cache(&fcic, &fci, type TSRMLS_CC);

#ifndef ZEPHIR_RELEASE
			fcic.function_handler = (*temp_cache_entry)->f;
			++(*temp_cache_entry)->times;
#else
			fcic.function_handler = *temp_cache_entry;
#endif
			/*memcpy(&clone, &fcic, sizeof(clone));*/
		}
	} else {
		zephir_fcall_populate_fci_cache(&fcic, &fci, type TSRMLS_CC);
#ifndef ZEPHIR_RELEASE
		fcic.function_handler = (*cache_entry)->f;
		++(*cache_entry)->times;
#else
		fcic.function_handler = *cache_entry;
#endif
	}

	/* Xdebug fix */
	//if (fcic.function_handler && fcic.function_handler->type == ZEND_INTERNAL_FUNCTION && fcic.function_handler->op_array) {
	//	fcic.function_handler->op_array.filename = "?";
	//	fcic.function_handler->op_array.line_start = 0;
	//	fcic.function_handler->op_array.line_end = 0;
	//}

	/* fcic.initialized = 0; */
#if PHP_VERSION_ID >= 50600
	status = ZEPHIR_ZEND_CALL_FUNCTION_WRAPPER(&fci, &fcic, info TSRMLS_CC);
#else
	status = ZEPHIR_ZEND_CALL_FUNCTION_WRAPPER(&fci, &fcic TSRMLS_CC);
#endif

/*
	if (fcic.initialized && cache_entry) {
		if (fcic.called_scope != clone.called_scope) {
			fprintf(stderr, "real called_scope: %s (%p)\n", fcic.called_scope->name, fcic.called_scope);
			fprintf(stderr, "my   called_scope: %s (%p)\n", clone.called_scope->name, clone.called_scope);
			fprintf(stderr, "type: %d\n", (int)type);
		}

		if (fcic.calling_scope != clone.calling_scope) {
			fprintf(stderr, "real calling_scope: %s (%p)\n", fcic.calling_scope->name, fcic.calling_scope);
			fprintf(stderr, "my   calling_scope: %s (%p)\n", clone.calling_scope->name, clone.calling_scope);
			fprintf(stderr, "type: %d\n", (int)type);
		}

		if (fcic.object_ptr != clone.object_ptr) {
			fprintf(stderr, "real object_ptr: %s (%p)\n", (fcic.object_ptr ? Z_OBJCE_P(fcic.object_ptr)->name : ""), fcic.object_ptr);
			fprintf(stderr, "my   object_ptr: %s (%p)\n", (clone.object_ptr ? Z_OBJCE_P(clone.object_ptr)->name : ""), clone.object_ptr);
			fprintf(stderr, "type: %d\n", (int)type);
		}

		if (fcic.function_handler != clone.function_handler) {
			fprintf(stderr, "real handler: %p (%s::%s)\n", fcic.function_handler, (fcic.function_handler->common.scope ? fcic.function_handler->common.scope->name : ""), fcic.function_handler->common.function_name);
			fprintf(stderr, "my   handler: %p (%s::%s)\n", clone.function_handler, (clone.function_handler->common.scope ? clone.function_handler->common.scope->name : ""), clone.function_handler->common.function_name);
			fprintf(stderr, "type: %d\n", (int)type);
		}
	}
*/
	EG(scope) = old_scope;

	if (!cache_entry || !*cache_entry) {
		if (EXPECTED(status != FAILURE) && fcall_key && !temp_cache_entry && fcic.initialized) {
#ifndef ZEPHIR_RELEASE
			zephir_fcall_cache_entry *cache_entry_temp = malloc(sizeof(zephir_fcall_cache_entry));
			cache_entry_temp->f     = fcic.function_handler;
			cache_entry_temp->times = 0;
#else
			zephir_fcall_cache_entry *cache_entry_temp = fcic.function_handler;
#endif
			if (FAILURE == zend_hash_quick_add(zephir_globals_ptr->fcache, fcall_key, fcall_key_len, fcall_key_hash, &cache_entry_temp, sizeof(zephir_fcall_cache_entry*), NULL)) {
#ifndef ZEPHIR_RELEASE
				free(temp_cache_entry);
#endif
			} else {
				if (cache_entry) {
					*cache_entry = cache_entry_temp;
					if (cache_slot > 0) {
						zephir_globals_ptr->scache[cache_slot] = *cache_entry;
					}
				}
			}
		}
	}

	if (fcall_key) {
		efree(fcall_key);
	}

	if (UNEXPECTED(params_array != NULL)) {
		efree(params_array);
	}

	if (!retval_ptr_ptr) {
		if (local_retval_ptr) {
			zval_ptr_dtor(&local_retval_ptr);
		}
	}

	--zephir_globals_ptr->recursive_lock;
	return status;
}

int zephir_call_func_aparams(zval **return_value_ptr, const char *func_name, uint func_length,
	zephir_fcall_cache_entry **cache_entry, int cache_slot,
	uint param_count, zval **params TSRMLS_DC)
{
	int status;
	zval *rv = NULL, **rvp = return_value_ptr ? return_value_ptr : &rv;
	zval *func = NULL;
#if PHP_VERSION_ID >= 50600
	zephir_fcall_info info;
#endif

#ifndef ZEPHIR_RELEASE
	if (return_value_ptr && *return_value_ptr) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

#if PHP_VERSION_ID >= 50600

	info.type = ZEPHIR_FCALL_TYPE_FUNC;
	info.class_name = NULL;
	info.func_name = func_name;
	info.func_length = func_length;

	status = zephir_call_user_function(NULL, NULL, zephir_fcall_function, func, rvp, cache_entry, cache_slot, param_count, params, &info TSRMLS_CC);

#else

	ALLOC_INIT_ZVAL(func);
	ZVAL_STRINGL(func, func_name, func_length, 0);

	status = zephir_call_user_function(NULL, NULL, zephir_fcall_function, func, rvp, cache_entry, 0, param_count, params, NULL TSRMLS_CC);

#endif

	if (status == FAILURE && !EG(exception)) {
		zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined function %s()", func_name);
		if (return_value_ptr) {
			*return_value_ptr = NULL;
		}
	} else {
		if (EG(exception)) {
			status = FAILURE;
			if (return_value_ptr) {
				*return_value_ptr = NULL;
			}
		}
	}

	if (rv) {
		zval_ptr_dtor(&rv);
	}

#if PHP_VERSION_ID < 50600
	if (Z_REFCOUNT_P(func) > 1) {
		zval_copy_ctor(func);
	} else {
		ZVAL_NULL(func);
	}
	zval_ptr_dtor(&func);
#endif

	return status;
}

int zephir_call_zval_func_aparams(zval **return_value_ptr, zval *func_name,
	zephir_fcall_cache_entry **cache_entry, int cache_slot,
	uint param_count, zval **params TSRMLS_DC)
{
	int status;
	zval *rv = NULL, **rvp = return_value_ptr ? return_value_ptr : &rv;

#ifndef ZEPHIR_RELEASE
	if (return_value_ptr && *return_value_ptr) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	status = zephir_call_user_function(NULL, NULL, zephir_fcall_function, func_name, rvp, cache_entry, cache_slot, param_count, params, NULL TSRMLS_CC);

	if (status == FAILURE && !EG(exception)) {
		zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined function %s()", Z_TYPE_P(func_name) ? Z_STRVAL_P(func_name) : "undefined");
		if (return_value_ptr) {
			*return_value_ptr = NULL;
		}
	} else {
		if (EG(exception)) {
			status = FAILURE;
			if (return_value_ptr) {
				*return_value_ptr = NULL;
			}
		}
	}

	if (rv) {
		zval_ptr_dtor(&rv);
	}

	return status;
}

int zephir_call_class_method_aparams(zval **return_value_ptr, zend_class_entry *ce, zephir_call_type type, zval *object,
	const char *method_name, uint method_len,
	zephir_fcall_cache_entry **cache_entry, int cache_slot,
	uint param_count, zval **params TSRMLS_DC)
{
	zval *rv = NULL, **rvp = return_value_ptr ? return_value_ptr : &rv;
	zval *fn = NULL;
#if PHP_VERSION_ID < 50600
	zval *mn;
#endif
	int status;
#if PHP_VERSION_ID >= 50600
	zephir_fcall_info info;
#endif

#ifndef ZEPHIR_RELEASE
	if (return_value_ptr && *return_value_ptr) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	if (object) {
		if (Z_TYPE_P(object) != IS_OBJECT) {
			zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Trying to call method %s on a non-object", method_name);
			if (return_value_ptr) {
				*return_value_ptr = NULL;
			}
			return FAILURE;
		}
	}

#if PHP_VERSION_ID >= 50600

	if (!cache_entry || !*cache_entry) {

		switch (type) {

			case zephir_fcall_parent:
				info.type = ZEPHIR_FCALL_TYPE_CLASS_PARENT_METHOD;
				break;

			case zephir_fcall_self:
				assert(!ce);
				info.type = ZEPHIR_FCALL_TYPE_CLASS_SELF_METHOD;
				break;

			case zephir_fcall_static:
				assert(!ce);
				info.type = ZEPHIR_FCALL_TYPE_CLASS_STATIC_METHOD;
				break;

			case zephir_fcall_ce:
				assert(ce != NULL);
				info.type = ZEPHIR_FCALL_TYPE_CE_METHOD;
				info.ce = ce;
				break;

			case zephir_fcall_method:
			default:
				assert(object != NULL);
				info.type = ZEPHIR_FCALL_TYPE_ZVAL_METHOD;
				info.object_ptr = object;
				info.ce = ce;
				break;
		}

		info.func_name = method_name;
		info.func_length = method_len;
	}

	status = zephir_call_user_function(object ? &object : NULL, ce, type, fn, rvp, cache_entry, cache_slot, param_count, params, &info TSRMLS_CC);

#else

	ALLOC_INIT_ZVAL(fn);
	if (!cache_entry || !*cache_entry) {

		array_init_size(fn, 2);
		switch (type) {
			case zephir_fcall_parent: add_next_index_stringl(fn, ZEND_STRL("parent"), 1); break;
			case zephir_fcall_self:   assert(!ce); add_next_index_stringl(fn, ZEND_STRL("self"), 1); break;
			case zephir_fcall_static: assert(!ce); add_next_index_stringl(fn, ZEND_STRL("static"), 1); break;

			case zephir_fcall_ce:
				assert(ce != NULL);
				add_next_index_stringl(fn, ce->name, ce->name_length, 1);
				break;

			case zephir_fcall_method:
			default:
				assert(object != NULL);
				Z_ADDREF_P(object);
				add_next_index_zval(fn, object);
				break;
		}

		ALLOC_INIT_ZVAL(mn);
		ZVAL_STRINGL(mn, method_name, method_len, 1);
		add_next_index_zval(fn, mn);

	} else {
		ZVAL_STRINGL(fn, "undefined", sizeof("undefined")-1, 1);
	}

	status = zephir_call_user_function(object ? &object : NULL, ce, type, fn, rvp, cache_entry, cache_slot, param_count, params, NULL TSRMLS_CC);

#endif

	if (status == FAILURE && !EG(exception)) {
		switch (type) {
			case zephir_fcall_parent:
				zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined method parent::%s()", method_name);
				break;

			case zephir_fcall_self:
				zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined method self::%s()", method_name);
				break;

			case zephir_fcall_static:
				zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined method static::%s()", method_name);
				break;

			case zephir_fcall_ce:
				zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined method %s::%s()", ce->name, method_name);
				break;

			case zephir_fcall_method:
				zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined method %s::%s()", ce->name, method_name);
				break;

			default:
				zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined method ?::%s()", method_name);
		}

		if (return_value_ptr) {
			*return_value_ptr = NULL;
		}
	} else {
		if (EG(exception)) {
			status = FAILURE;
			if (return_value_ptr) {
				*return_value_ptr = NULL;
			}
		}
	}

	if (rv) {
		zval_ptr_dtor(&rv);
	}

#if PHP_VERSION_ID < 50600
	zval_ptr_dtor(&fn);
#endif

	return status;
}

/**
 * Replaces call_user_func_array avoiding function lookup
 * This function does not return FAILURE if an exception has ocurred
 */
int zephir_call_user_func_array_noex(zval *return_value, zval *handler, zval *params TSRMLS_DC){

	zval *retval_ptr = NULL;
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;
	char *is_callable_error = NULL;
	int status = FAILURE;

	if (params && Z_TYPE_P(params) != IS_ARRAY) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for zephir_call_user_func_array_noex()");
		return FAILURE;
	}

	if (zend_fcall_info_init(handler, 0, &fci, &fci_cache, NULL, &is_callable_error TSRMLS_CC) == SUCCESS) {
		if (is_callable_error) {
			zend_error(E_STRICT, "%s", is_callable_error);
			efree(is_callable_error);
		}
		status = SUCCESS;
	} else {
		if (is_callable_error) {
			zend_error(E_WARNING, "%s", is_callable_error);
			efree(is_callable_error);
		} else {
			status = SUCCESS;
		}
	}

	if (status == SUCCESS) {

		zend_fcall_info_args(&fci, params TSRMLS_CC);
		fci.retval_ptr_ptr = &retval_ptr;

		if (zend_call_function(&fci, &fci_cache TSRMLS_CC) == SUCCESS && fci.retval_ptr_ptr && *fci.retval_ptr_ptr) {
			COPY_PZVAL_TO_ZVAL(*return_value, *fci.retval_ptr_ptr);
		}

		if (fci.params) {
			efree(fci.params);
		}
	}

	if (EG(exception)) {
		status = SUCCESS;
	}

	return status;
}

/**
 * If a retval_ptr is specified, PHP's implementation of zend_eval_stringl
 * simply prepends a "return " which causes only the first statement to be executed
 */
void zephir_eval_php(zval *str, zval *retval_ptr, char *context TSRMLS_DC)
{
	zend_op_array *new_op_array = NULL;
	zend_uint original_compiler_options;
	zend_op_array *original_active_op_array = EG(active_op_array);

	original_compiler_options = CG(compiler_options);
	CG(compiler_options) = ZEND_COMPILE_DEFAULT_FOR_EVAL;
	new_op_array = zend_compile_string(str, context TSRMLS_CC);
	CG(compiler_options) = original_compiler_options;

	if (new_op_array)
	{
		zval *local_retval_ptr = NULL;
		zval **original_return_value_ptr_ptr = EG(return_value_ptr_ptr);
		zend_op **original_opline_ptr = EG(opline_ptr);
		int orig_interactive = CG(interactive);

		EG(return_value_ptr_ptr) = &local_retval_ptr;
		EG(active_op_array) = new_op_array;
		EG(no_extensions) = 1;
		if (!EG(active_symbol_table)) {
			zend_rebuild_symbol_table(TSRMLS_C);
		}
		CG(interactive) = 0;

		zend_try {
			zend_execute(new_op_array TSRMLS_CC);
		} zend_catch {
			destroy_op_array(new_op_array TSRMLS_CC);
			efree(new_op_array);
			zend_bailout();
		} zend_end_try();

		CG(interactive) = orig_interactive;
		if (local_retval_ptr) {
			if (retval_ptr) {
				COPY_PZVAL_TO_ZVAL(*retval_ptr, local_retval_ptr);
			} else {
				zval_ptr_dtor(&local_retval_ptr);
			}
		} else if (retval_ptr) {
			INIT_ZVAL(*retval_ptr);
		}

		EG(no_extensions) = 0;
		EG(opline_ptr) = original_opline_ptr;
		EG(active_op_array) = original_active_op_array;
		destroy_op_array(new_op_array TSRMLS_CC);
		efree(new_op_array);
		EG(return_value_ptr_ptr) = original_return_value_ptr_ptr;
	}
}
