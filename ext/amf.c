/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
  |          Nikolaos Dimopoulos <nikos@phalconphp.com>                    |
  +------------------------------------------------------------------------+
*/

#include "amf.h"

#include "ext/standard/php_smart_str.h"

#include "kernel/main.h"
#include "kernel/operators.h"

/**
 * Phalcon\Amf
 *
 * Phalcon\Amf is designed to simplify building of HTML amfs.
 * It provides a set of helpers to generate HTML in a dynamic way.
 * This component is an abstract class that you can extend to add more helpers.
 */
zend_class_entry *phalcon_amf_ce;

PHP_METHOD(Phalcon_Amf, encode);
PHP_METHOD(Phalcon_Amf, decode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_amf_encode, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_amf_decode, 0, 0, 1)
	ZEND_ARG_INFO(0, amf3)
	ZEND_ARG_INFO(0, postion)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_amf_method_entry[] = {
	PHP_ME(Phalcon_Amf, encode, arginfo_phalcon_amf_encode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Amf, decode, arginfo_phalcon_amf_decode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Amf initializer
 */
PHALCON_INIT_CLASS(Phalcon_Amf){

	PHALCON_REGISTER_CLASS(Phalcon, Amf, amf, phalcon_amf_method_entry, 0);

	zend_declare_class_constant_stringl(phalcon_amf_ce, SL("CLIENT_SUCCESS_METHOD"), SL(PHALCON_AMF3_CLIENT_SUCCESS_METHOD) TSRMLS_CC);
	zend_declare_class_constant_stringl(phalcon_amf_ce, SL("CLIENT_FAILURE_METHOD"), SL(PHALCON_AMF3_CLIENT_FAILURE_METHOD) TSRMLS_CC);
	zend_declare_class_constant_stringl(phalcon_amf_ce, SL("DEFAULT_REQUEST_RESPONSE_URI"), SL(PHALCON_AMF3_DEFAULT_REQUEST_RESPONSE_URI) TSRMLS_CC);
	zend_declare_class_constant_stringl(phalcon_amf_ce, SL("CONTENT_TYPE"), SL(PHALCON_AMF3_CONTENT_TYPE) TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_amf_ce, SL("OPTION_FORCE_OBJECT"), PHALCON_AMF3_OPTION_FORCE_OBJECT TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_amf_ce, SL("OPTION_CLASS_MAP"), PHALCON_AMF3_OPTION_CLASS_AUTOLOAD TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_amf_ce, SL("OPTION_CLASS_AUTOLOAD"), PHALCON_AMF3_OPTION_CLASS_AUTOLOAD TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_amf_ce, SL("OPTION_CLASS_CONSTRUCT"), PHALCON_AMF3_OPTION_CLASS_CONSTRUCT TSRMLS_CC);

	return SUCCESS;
}

static void phalcon_amf_encode_value(smart_str *ss, zval *val, int opts, HashTable *sht, HashTable *oht, HashTable *tht TSRMLS_DC);
static int phalcon_amf_decode_value(zval **val, const char *buf, int pos, int size, int opts, HashTable *sht, HashTable *oht, HashTable *tht TSRMLS_DC);

static void phalcon_amf_encode_u29(smart_str *ss, int val) {
	char buf[4];
	int size;
	val &= 0x1fffffff;
	if (val <= 0x7f) {
		buf[0] = val;
		size = 1;
	} else if (val <= 0x3fff) {
		buf[1] = val & 0x7f;
		val >>= 7;
		buf[0] = val | 0x80;
		size = 2;
	} else if (val <= 0x1fffff) {
		buf[2] = val & 0x7f;
		val >>= 7;
		buf[1] = val | 0x80;
		val >>= 7;
		buf[0] = val | 0x80;
		size = 3;
	} else {
		buf[3] = val;
		val >>= 8;
		buf[2] = val | 0x80;
		val >>= 7;
		buf[1] = val | 0x80;
		val >>= 7;
		buf[0] = val | 0x80;
		size = 4;
	}
	smart_str_appendl(ss, buf, size);
}

static void phalcon_amf_encode_double(smart_str *ss, double val) {
	union { int i; char c; } t;
	union { double d; char c[8]; } u;
	char buf[8];
	t.i = 1;
	u.d = val;
	if (!t.c) memcpy(buf, u.c, 8);
	else { /* little-endian machine */
		int i;
		for (i = 0; i < 8; ++i) buf[7 - i] = u.c[i];
	}
	smart_str_appendl(ss, buf, 8);
}

static void phalcon_amf_encode_str(smart_str *ss, const char *str, int len, HashTable *ht TSRMLS_DC) {
	if (len > PHALCON_AMF3_MAX_INT) len = PHALCON_AMF3_MAX_INT;
	if (len) { /* empty string is never sent by reference */
		int *oidx, nidx;
		if (zend_hash_find(ht, str, len, (void **)&oidx) == SUCCESS) {
			phalcon_amf_encode_u29(ss, *oidx << 1);
			return;
		}
		nidx = zend_hash_num_elements(ht);
		if (nidx <= PHALCON_AMF3_MAX_INT) zend_hash_add(ht, str, len, &nidx, sizeof(nidx), NULL);
	}
	phalcon_amf_encode_u29(ss, (len << 1) | 1);
	smart_str_appendl(ss, str, len);
}

static int phalcon_amf_encode_ref(smart_str *ss, zval *val, HashTable *ht TSRMLS_DC) {
	int *oidx, nidx;
	if (zend_hash_find(ht, (char *)&val, sizeof(val), (void **)&oidx) == SUCCESS) {
		phalcon_amf_encode_u29(ss, *oidx << 1);
		return 1;
	}
	nidx = zend_hash_num_elements(ht);
	if (nidx <= PHALCON_AMF3_MAX_INT) zend_hash_add(ht, (char *)&val, sizeof(val), &nidx, sizeof(nidx), NULL);
	return 0;
}

static void phalcon_amf_encode_hash(smart_str *ss, HashTable *ht, int opts, int prv, HashTable *sht, HashTable *oht, HashTable *tht TSRMLS_DC) {
	HashPosition hp;
	zval **hv;
	char *key, kbuf[22];
	uint klen;
	ulong idx;
	for (zend_hash_internal_pointer_reset_ex(ht, &hp) ;; zend_hash_move_forward_ex(ht, &hp)) {
		if (zend_hash_get_current_data_ex(ht, (void **)&hv, &hp) != SUCCESS) break;
		switch (zend_hash_get_current_key_ex(ht, &key, &klen, &idx, 0, &hp)) {
			case HASH_KEY_IS_STRING:
				if (klen <= 1) continue; /* empty key can't be represented in PHALCON_AMF3 */
				if (prv && !key[0]) continue; /* skip private/protected property */
				phalcon_amf_encode_str(ss, key, klen - 1, sht TSRMLS_CC);
				break;
			case HASH_KEY_IS_LONG:
				phalcon_amf_encode_str(ss, kbuf, sprintf(kbuf, "%ld", idx), sht TSRMLS_CC);
				break;
		}
		phalcon_amf_encode_value(ss, *hv, opts, sht, oht, tht TSRMLS_CC);
	}
	smart_str_appendc(ss, 0x01);
}

static int phalcon_amf_get_hash_len(HashTable *ht) {
	HashPosition hp;
	char *key;
	uint klen;
	ulong idx;
	int ktype, len = 0;
	for (zend_hash_internal_pointer_reset_ex(ht, &hp) ;; zend_hash_move_forward_ex(ht, &hp)) {
		ktype = zend_hash_get_current_key_ex(ht, &key, &klen, &idx, 0, &hp);
		if (ktype == HASH_KEY_NON_EXISTANT) break;
		if ((ktype != HASH_KEY_IS_LONG) || (idx != len)) return -1;
		++len;
	}
	return len;
}

static void phalcon_amf_encode_array(smart_str *ss, zval *val, int opts, HashTable *sht, HashTable *oht, HashTable *tht TSRMLS_DC) {
	HashTable *ht = Z_ARRVAL_P(val);
	HashPosition hp;
	zval **hv;
	int len;
	if (phalcon_amf_encode_ref(ss, val, oht TSRMLS_CC)) return;
	len = phalcon_amf_get_hash_len(ht);
	if (len >= 0) { /* encode as dense array */
		if (len > PHALCON_AMF3_MAX_INT) len = PHALCON_AMF3_MAX_INT;
		phalcon_amf_encode_u29(ss, (len << 1) | 1);
		smart_str_appendc(ss, 0x01);
		for (zend_hash_internal_pointer_reset_ex(ht, &hp) ;; zend_hash_move_forward_ex(ht, &hp)) {
			if (zend_hash_get_current_data_ex(ht, (void **)&hv, &hp) != SUCCESS) break;
			if (!len--) break;
			phalcon_amf_encode_value(ss, *hv, opts, sht, oht, tht TSRMLS_CC);
		}
	} else { /* encode as associative array */
		smart_str_appendc(ss, 0x01);
		phalcon_amf_encode_hash(ss, ht, opts, 0, sht, oht, tht TSRMLS_CC);
	}
}

static void phalcon_amf_encode_object(smart_str *ss, zval *val, int opts, HashTable *sht, HashTable *oht, HashTable *tht TSRMLS_DC) {
	zend_class_entry *ce = Z_TYPE_P(val) == IS_OBJECT ? Z_OBJCE_P(val) : zend_standard_class_def;
	int *oidx, nidx;
	if (phalcon_amf_encode_ref(ss, val, oht TSRMLS_CC)) return;
	if (zend_hash_find(tht, (char *)&ce, sizeof(ce), (void **)&oidx) == SUCCESS) phalcon_amf_encode_u29(ss, (*oidx << 2) | 1);
	else {
		nidx = zend_hash_num_elements(tht);
		if (nidx <= PHALCON_AMF3_MAX_INT) zend_hash_add(tht, (char *)&ce, sizeof(ce), &nidx, sizeof(nidx), NULL);
		smart_str_appendc(ss, 0x0b);
		if (ce == zend_standard_class_def) smart_str_appendc(ss, 0x01); /* anonymous object */
		else phalcon_amf_encode_str(ss, ce->name, ce->name_length, sht TSRMLS_CC); /* typed object */
	}
	phalcon_amf_encode_hash(ss, HASH_OF(val), opts, 1, sht, oht, tht TSRMLS_CC);
}

static void phalcon_amf_encode_value(smart_str *ss, zval *val, int opts, HashTable *sht, HashTable *oht, HashTable *tht TSRMLS_DC) {
	switch (Z_TYPE_P(val)) {
		default:
			smart_str_appendc(ss, PHALCON_AMF3_UNDEFINED);
			break;
		case IS_NULL:
			smart_str_appendc(ss, PHALCON_AMF3_NULL);
			break;
		case IS_BOOL:
			smart_str_appendc(ss, Z_LVAL_P(val) ? PHALCON_AMF3_TRUE : PHALCON_AMF3_FALSE);
			break;
		case IS_LONG: {
			int i = Z_LVAL_P(val);
			if ((i >= PHALCON_AMF3_MIN_INT) && (i <= PHALCON_AMF3_MAX_INT)) {
				smart_str_appendc(ss, PHALCON_AMF3_INTEGER);
				phalcon_amf_encode_u29(ss, i);
			} else {
				smart_str_appendc(ss, PHALCON_AMF3_DOUBLE);
				phalcon_amf_encode_double(ss, i);
			}
			break;
		}
		case IS_DOUBLE:
			smart_str_appendc(ss, PHALCON_AMF3_DOUBLE);
			phalcon_amf_encode_double(ss, Z_DVAL_P(val));
			break;
		case IS_STRING:
			smart_str_appendc(ss, PHALCON_AMF3_STRING);
			phalcon_amf_encode_str(ss, Z_STRVAL_P(val), Z_STRLEN_P(val), sht TSRMLS_CC);
			break;
		case IS_ARRAY:
			if (!(opts & PHALCON_AMF3_OPTION_FORCE_OBJECT) || (phalcon_amf_get_hash_len(Z_ARRVAL_P(val)) >= 0)) {
				smart_str_appendc(ss, PHALCON_AMF3_ARRAY);
				phalcon_amf_encode_array(ss, val, opts, sht, oht, tht TSRMLS_CC);
				break;
			}
		case IS_OBJECT:
			smart_str_appendc(ss, PHALCON_AMF3_OBJECT);
			phalcon_amf_encode_object(ss, val, opts, sht, oht, tht TSRMLS_CC);
			break;
	}
}

/*
 * decode
 */

typedef struct {
	int fmt, cnt;
	char *cls;
	int clen;
	char **fld;
	int *flen;
} PhalconAmfTraits;

static int phalcon_amf_decode_u29(int *val, const char *buf, int pos, int size TSRMLS_DC) {
	int ofs = 0, res = 0, tmp;
	buf += pos;
	do {
		if ((pos + ofs) >= size) {
			php_error(E_WARNING, "Insufficient integer data at position %d", pos);
			return -1;
		}
		tmp = buf[ofs];
		if (ofs == 3) {
			res <<= 8;
			res |= tmp & 0xff;
		} else {
			res <<= 7;
			res |= tmp & 0x7f;
		}
	} while ((++ofs < 4) && (tmp & 0x80));
	*val = res;
	return ofs;
}

static int phalcon_amf_decode_double(double *val, const char *buf, int pos, int size TSRMLS_DC) {
	union { int i; char c; } t;
	union { double d; char c[8]; } u;
	if ((pos + 8) > size) {
		php_error(E_WARNING, "Insufficient number data at position %d", pos);
		return -1;
	}
	buf += pos;
	t.i = 1;
	if (!t.c) memcpy(u.c, buf, 8);
	else { /* little-endian machine */
		int i;
		for (i = 0; i < 8; ++i) u.c[i] = buf[7 - i];
	}
	*val = u.d;
	return 8;
}

static int phalcon_amf_decode_str(const char **str, int *len, zval **val, const char *buf, int pos, int size, int loose, HashTable *ht TSRMLS_DC) {
	int old = pos, ofs, pfx, def;
	ofs = phalcon_amf_decode_u29(&pfx, buf, pos, size TSRMLS_CC);
	if (ofs < 0) return -1;
	pos += ofs;
	def = pfx & 1;
	pfx >>= 1;
	if (def) {
		if ((pos + pfx) > size) {
			php_error(E_WARNING, "Insufficient data of length %d at position %d", pfx, pos);
			return -1;
		}
		buf += pos;
		pos += pfx;
		if (str && len) {
			*str = buf;
			*len = pfx;
		} else if (val) {
			ZVAL_RESET(*val);
			ZVAL_STRINGL(*val, buf, pfx, 1);
		}
		if (loose || pfx) { /* empty string is never sent by reference */
			zval *hv;
			if (val) {
				hv = *val;
				Z_ADDREF_P(hv);
			} else {
				ALLOC_INIT_ZVAL(hv);
				ZVAL_STRINGL(hv, buf, pfx, 1);
			}
			zend_hash_index_update(ht, zend_hash_num_elements(ht), &hv, sizeof(hv), NULL);
		}
	} else {
		zval **hv;
		if (zend_hash_index_find(ht, pfx, (void **)&hv) == FAILURE) {
			php_error(E_WARNING, "Missing string reference #%d at position %d", pfx, pos);
			return -1;
		}
		if (str && len) {
			*str = Z_STRVAL_PP(hv);
			*len = Z_STRLEN_PP(hv);
		} else if (val) {
			*val = *hv;
			Z_ADDREF_PP(hv);
		}
	}
	return pos - old;
}

static int phalcon_amf_decode_ref(int *len, zval **val, const char *buf, int pos, int size, HashTable *ht TSRMLS_DC) {
	int ofs, pfx, def;
	ofs = phalcon_amf_decode_u29(&pfx, buf, pos, size TSRMLS_CC);
	if (ofs < 0) return -1;
	pos += ofs;
	def = pfx & 1;
	pfx >>= 1;
	if (def) *len = pfx;
	else {
		zval **hv;
		if (zend_hash_index_find(ht, pfx, (void **)&hv) == FAILURE) {
			php_error(E_WARNING, "Missing object reference #%d at position %d", pfx, pos);
			return -1;
		}
		*len = -1;
		*val = *hv;
		Z_ADDREF_PP(hv);
	}
	return ofs;
}

static void phalcon_amf_store_ref(zval *val, HashTable *ht) {
	Z_ADDREF_P(val);
	zend_hash_index_update(ht, zend_hash_num_elements(ht), &val, sizeof(val), NULL);
}

static int phalcon_amf_decode_date(zval **val, const char *buf, int pos, int size, HashTable *ht TSRMLS_DC) {
	int old = pos, ofs, pfx;
	ofs = phalcon_amf_decode_ref(&pfx, val, buf, pos, size, ht TSRMLS_CC);
	if (ofs < 0) return -1;
	pos += ofs;
	if (pfx >= 0) {
		double d;
		ofs = phalcon_amf_decode_double(&d, buf, pos, size TSRMLS_CC);
		if (ofs < 0) return -1;
		pos += ofs;
		ZVAL_RESET(*val);
		ZVAL_DOUBLE(*val, d);
		phalcon_amf_store_ref(*val, ht);
	}
	return pos - old;
}

static int phalcon_amf_decode_array(zval **val, const char *buf, int pos, int size, int opts, HashTable *sht, HashTable *oht, HashTable *tht TSRMLS_DC) {
	int old = pos, ofs, len;
	ofs = phalcon_amf_decode_ref(&len, val, buf, pos, size, oht TSRMLS_CC);
	if (ofs < 0) return -1;
	pos += ofs;
	if (len >= 0) {
		zval *hv;
		const char *key;
		char kbuf[64];
		int klen;
		ZVAL_RESET(*val);
		array_init(*val);
		phalcon_amf_store_ref(*val, oht);
		for ( ;; ) { /* associative portion */
			ofs = phalcon_amf_decode_str(&key, &klen, 0, buf, pos, size, 0, sht TSRMLS_CC);
			if (ofs < 0) return -1;
			pos += ofs;
			if (!klen) break;
			hv = 0;
			ofs = phalcon_amf_decode_value(&hv, buf, pos, size, opts, sht, oht, tht TSRMLS_CC);
			if (hv) { /* need a trailing \0 in the key string for a proper call to 'add_assoc_zval_ex' */
				if (klen < sizeof(kbuf)) {
					memcpy(kbuf, key, klen);
					kbuf[klen] = 0;
					add_assoc_zval_ex(*val, kbuf, klen + 1, hv);
				} else {
					char *tbuf = emalloc(klen + 1);
					memcpy(tbuf, key, klen);
					tbuf[klen] = 0;
					add_assoc_zval_ex(*val, tbuf, klen + 1, hv);
					efree(tbuf);
				}
			}
			if (ofs < 0) return -1;
			pos += ofs;
		}
		while (len--) { /* dense portion */
			hv = 0;
			ofs = phalcon_amf_decode_value(&hv, buf, pos, size, opts, sht, oht, tht TSRMLS_CC);
			if (hv) add_next_index_zval(*val, hv);
			if (ofs < 0) return -1;
			pos += ofs;
		}
	}
	return pos - old;
}

static int phalcon_amf_decode_object(zval **val, const char *buf, int pos, int size, int opts, HashTable *sht, HashTable *oht, HashTable *tht TSRMLS_DC) {
	int old = pos, ofs, pfx;
	ofs = phalcon_amf_decode_ref(&pfx, val, buf, pos, size, oht TSRMLS_CC);
	if (ofs < 0) return -1;
	pos += ofs;
	if (pfx >= 0) {
		int map = opts & PHALCON_AMF3_OPTION_CLASS_MAP;
		zend_class_entry *ce = 0;
		PhalconAmfTraits *tr;
		zval *hv;
		const char *key;
		char kbuf[64];
		int klen;
		int def = pfx & 1;
		pfx >>= 1;
		if (def) { /* new class definition */
			int i, n = pfx >> 2;
			const char *cls;
			int clen;
			char **fld = NULL;
			int *flen = NULL;
			ofs = phalcon_amf_decode_str(&cls, &clen, 0, buf, pos, size, 0, sht TSRMLS_CC);
			if (ofs < 0) return -1;
			pos += ofs;
			if (n > 0) {
				if ((pos + n * 2) > size) { /* rough security check */
					php_error(E_WARNING, "Inappropriate number of declared class members at position %d", pos);
					return -1;
				}
				fld = emalloc(sizeof(*fld) * n);
				flen = emalloc(sizeof(*flen) * n);
				for (i = 0; i < n; ++i) { /* static member names */
					ofs = phalcon_amf_decode_str(&key, &klen, 0, buf, pos, size, 0, sht TSRMLS_CC);
					if (ofs < 0) {
						n = -1;
						break;
					}
					pos += ofs;
					if (!klen || !key[0]) {
						php_error(E_WARNING, "Inappropriate class member name at position %d", pos);
						n = -1;
						break;
					}
					fld[i] = estrndup(key, klen); /* a trailing \0 is needed later for a key string */
					flen[i] = klen + 1;
				}
				if (n < 0) {
					while (i--) efree(fld[i]);
					efree(fld);
					efree(flen);
					return -1;
				}
			}
			tr = emalloc(sizeof(PhalconAmfTraits));
			tr->fmt = pfx & 0x03;
			tr->cnt = n;
			tr->cls = estrndup(cls, clen);
			tr->clen = clen;
			tr->fld = fld;
			tr->flen = flen;
			zend_hash_index_update(tht, zend_hash_num_elements(tht), &tr, sizeof(tr), NULL);
		} else { /* existing class definition */
			PhalconAmfTraits **trp;
			if (zend_hash_index_find(tht, pfx, (void **)&trp) == FAILURE) {
				php_error(E_WARNING, "Missing class definition #%d at position %d", pfx, pos);
				return -1;
			}
			tr = *trp;
		}
		ZVAL_RESET(*val);
		if (!map) array_init(*val);
		else {
			if (!tr->clen) object_init(*val);
			else {
				int mode = ZEND_FETCH_CLASS_DEFAULT | ZEND_FETCH_CLASS_SILENT;
				if (!(opts & PHALCON_AMF3_OPTION_CLASS_AUTOLOAD)) mode |= ZEND_FETCH_CLASS_NO_AUTOLOAD;
				ce = zend_fetch_class(tr->cls, tr->clen, mode TSRMLS_CC);
				if (!ce) {
					php_error(E_WARNING, "Class '%s' not found at position %d", tr->cls, pos);
					return -1;
				}
				object_init_ex(*val, ce);
			}
		}
		phalcon_amf_store_ref(*val, oht);
		if (tr->fmt & 1) { /* externalizable */
			hv = 0;
			ofs = phalcon_amf_decode_value(&hv, buf, pos, size, opts, sht, oht, tht TSRMLS_CC);
			if (hv) {
				if (!map) add_assoc_zval(*val, "_data", hv);
				else {
					add_property_zval(*val, "_data", hv);
					Z_DELREF_P(hv);
				}
			}
			if (ofs < 0) return -1;
			pos += ofs;
		} else {
			int i;
			for (i = 0; i < tr->cnt; ++i) {
				hv = 0;
				ofs = phalcon_amf_decode_value(&hv, buf, pos, size, opts, sht, oht, tht TSRMLS_CC);
				if (hv) {
					if (!map) add_assoc_zval_ex(*val, tr->fld[i], tr->flen[i], hv);
					else {
						add_property_zval_ex(*val, tr->fld[i], tr->flen[i], hv TSRMLS_CC);
						Z_DELREF_P(hv);
					}
				}
				if (ofs < 0) return -1;
				pos += ofs;
			}
			if (tr->fmt & 2) { /* dynamic */
				for ( ;; ) {
					ofs = phalcon_amf_decode_str(&key, &klen, 0, buf, pos, size, 0, sht TSRMLS_CC);
					if (ofs < 0) return -1;
					pos += ofs;
					if (!klen) break;
					if (map && !key[0]) {
						php_error(E_WARNING, "Inappropriate class member name at position %d", pos);
						return -1;
					}
					hv = 0;
					ofs = phalcon_amf_decode_value(&hv, buf, pos, size, opts, sht, oht, tht TSRMLS_CC);
					if (hv) { /* need a trailing \0 in the key string for a proper call to 'add_property_zval_ex' */
						if (klen < sizeof(kbuf)) {
							memcpy(kbuf, key, klen);
							kbuf[klen] = 0;
							if (!map) add_assoc_zval_ex(*val, kbuf, klen + 1, hv);
							else {
								add_property_zval_ex(*val, kbuf, klen + 1, hv TSRMLS_CC);
								Z_DELREF_P(hv);
							}
						} else {
							char *tbuf = emalloc(klen + 1);
							memcpy(tbuf, key, klen);
							tbuf[klen] = 0;
							if (!map) add_assoc_zval_ex(*val, tbuf, klen + 1, hv);
							else {
								add_property_zval_ex(*val, tbuf, klen + 1, hv TSRMLS_CC);
								Z_DELREF_P(hv);
							}
							efree(tbuf);
						}
					}
					if (ofs < 0) return -1;
					pos += ofs;
				}
			}
		}
		if (!map && tr->clen) add_assoc_stringl(*val, "_class", tr->cls, tr->clen, 1);
		else if (ce && (opts & PHALCON_AMF3_OPTION_CLASS_CONSTRUCT)) { /* call the constructor */
			zend_call_method_with_0_params(val, ce, &ce->constructor, NULL, NULL);
			if (EG(exception)) return -1;
		}
	}
	return pos - old;
}

static int phalcon_amf_decode_value(zval **val, const char *buf, int pos, int size, int opts, HashTable *sht, HashTable *oht, HashTable *tht TSRMLS_DC) {
	int old = pos, ofs;
	if (pos >= size) {
		php_error(E_WARNING, "Insufficient type data at position %d", pos);
		return -1;
	}

	int type = buf[pos++];
	switch (type) {
		case PHALCON_AMF3_UNDEFINED:
		case PHALCON_AMF3_NULL:
			ZVAL_RESET(*val);
			ZVAL_NULL(*val);
			break;
		case PHALCON_AMF3_FALSE:
			ZVAL_RESET(*val);
			ZVAL_FALSE(*val);
			break;
		case PHALCON_AMF3_TRUE:
			ZVAL_RESET(*val);
			ZVAL_TRUE(*val);
			break;
		case PHALCON_AMF3_INTEGER: {
			int i;
			ofs = phalcon_amf_decode_u29(&i, buf, pos, size TSRMLS_CC);
			if (ofs < 0) return -1;
			pos += ofs;
			if (i & 0x10000000) i -= 0x20000000;
			ZVAL_RESET(*val);
			ZVAL_LONG(*val, i);
			break;
		}
		case PHALCON_AMF3_DOUBLE: {
			double d;
			ofs = phalcon_amf_decode_double(&d, buf, pos, size TSRMLS_CC);
			if (ofs < 0) return -1;
			pos += ofs;
			ZVAL_RESET(*val);
			ZVAL_DOUBLE(*val, d);
			break;
		}
		case PHALCON_AMF3_STRING:
			ofs = phalcon_amf_decode_str(0, 0, val, buf, pos, size, 0, sht TSRMLS_CC);
			if (ofs < 0) return -1;
			pos += ofs;
			break;
		case PHALCON_AMF3_XML:
		case PHALCON_AMF3_XMLDOC:
		case PHALCON_AMF3_BYTEARRAY:
			ofs = phalcon_amf_decode_str(0, 0, val, buf, pos, size, 1, oht TSRMLS_CC);
			if (ofs < 0) return -1;
			pos += ofs;
			break;
		case PHALCON_AMF3_DATE:
			ofs = phalcon_amf_decode_date(val, buf, pos, size, oht TSRMLS_CC);
			if (ofs < 0) return -1;
			pos += ofs;
			break;
		case PHALCON_AMF3_ARRAY:
			ofs = phalcon_amf_decode_array(val, buf, pos, size, opts, sht, oht, tht TSRMLS_CC);
			if (ofs < 0) return -1;
			pos += ofs;
			break;
		case PHALCON_AMF3_OBJECT:
			ofs = phalcon_amf_decode_object(val, buf, pos, size, opts, sht, oht, tht TSRMLS_CC);
			if (ofs < 0) return -1;
			pos += ofs;
			break;
		default:
			php_error(E_WARNING, "Unsupported value type %d at position %d", buf[pos - 1], pos - 1);
			return -1;
	}
	return pos - old;
}

static void phalcon_amf_traits_ptr_dtor(void *p) {
	PhalconAmfTraits *tr = *((PhalconAmfTraits **)p);
	int n = tr->cnt;
	if (n > 0) {
		while (n--) efree(tr->fld[n]);
		efree(tr->fld);
		efree(tr->flen);
	}
	efree(tr->cls);
	efree(tr);
}

/**
 *
 *<code>
 *	$amf = Phalcon\Amf::encode('hello world!', true)
 *</code>
 *
 * @param mixed $value
 * @param boolean $option
 * @return mixed
 */
PHP_METHOD(Phalcon_Amf, encode){

	zval *value, *option = NULL;
	smart_str ss = { 0 };
	HashTable sht, oht, tht;
	long opts;

	phalcon_fetch_params(0, 1, 1, &value, &option);

	opts = option ? phalcon_get_intval(option) : 0;

	zend_hash_init(&sht, 0, NULL, NULL, 0);
	zend_hash_init(&oht, 0, NULL, NULL, 0);
	zend_hash_init(&tht, 0, NULL, NULL, 0);

	phalcon_amf_encode_value(&ss, value, opts, &sht, &oht, &tht TSRMLS_CC);

	zend_hash_destroy(&sht);
	zend_hash_destroy(&oht);
	zend_hash_destroy(&tht);
	
	RETVAL_STRINGL(ss.c, ss.len, 1);
	smart_str_free(&ss);
}

/**
 *
 *<code>
 *	$amf = Phalcon\Amf::encode('hello world!');
 *	$data = Phalcon\Amf::decode($amf);
 *</code>
 *
 * @param mixed $value
 * @param boolean $option
 * @return mixed
 */
PHP_METHOD(Phalcon_Amf, decode){

	zval *value, *postion = NULL, *option = NULL;
	HashTable sht, oht, tht;
	int ofs;
	long pos, opts;

	phalcon_fetch_params(0, 1, 2, &value, &postion, &option);

	pos = postion ? phalcon_get_intval(postion) : 0;
	opts = option ? phalcon_get_intval(option) : 0;

	zend_hash_init(&sht, 0, NULL, ZVAL_PTR_DTOR, 0);
	zend_hash_init(&oht, 0, NULL, ZVAL_PTR_DTOR, 0);
	zend_hash_init(&tht, 0, NULL, phalcon_amf_traits_ptr_dtor, 0);

	ofs = phalcon_amf_decode_value(&return_value, value->value.str.val, pos, Z_STRLEN_P(value), opts, &sht, &oht, &tht TSRMLS_CC);

	zend_hash_destroy(&sht);
	zend_hash_destroy(&oht);
	zend_hash_destroy(&tht);

	if (ofs < 0) {
		zval_dtor(return_value);
		ZVAL_NULL(return_value);
	}
}
