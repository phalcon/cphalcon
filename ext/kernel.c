
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
  +------------------------------------------------------------------------+
*/

#include "kernel.h"
#include "kernel/main.h"

/**
 * Phalcon\Kernel
 *
 * This class allows to change the internal behavior of the framework in runtime
 */
zend_class_entry *phalcon_kernel_ce;

PHP_METHOD(Phalcon_Kernel, preComputeHashKey);
PHP_METHOD(Phalcon_Kernel, preComputeHashKey32);
PHP_METHOD(Phalcon_Kernel, preComputeHashKey64);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_kernel_precomputehashkey, 0, 0, 1)
	ZEND_ARG_INFO(0, arrKey)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_kernel_method_entry[] = {
	PHP_ME(Phalcon_Kernel, preComputeHashKey,   arginfo_phalcon_kernel_precomputehashkey, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Kernel, preComputeHashKey32, arginfo_phalcon_kernel_precomputehashkey, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Kernel, preComputeHashKey64, arginfo_phalcon_kernel_precomputehashkey, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Kernel initializer
 */
PHALCON_INIT_CLASS(Phalcon_Kernel){

	PHALCON_REGISTER_CLASS(Phalcon, Kernel, kernel, phalcon_kernel_method_entry, 0);

	return SUCCESS;
}

/**
 * Produces a pre-computed hash key based on a string. This function produce different numbers in 32bit/64bit processors
 *
 * @param string $arrKey
 * @return string
 */
PHP_METHOD(Phalcon_Kernel, preComputeHashKey){

	char *arKey, *strKey;
	unsigned int nKeyLength;
	register ulong hash = 5381;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arKey, &nKeyLength) == FAILURE) {
		RETURN_NULL();
	}

	nKeyLength++;

	/* variant with the hash unrolled eight times */
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
		case 7: hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 6: hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 5: hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 4: hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 3: hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 2: hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 1: hash = ((hash << 5) + hash) + *arKey++; break;
	}

	strKey = emalloc(24);
	snprintf(strKey, 24, "%lu", hash);

	RETURN_STRING(strKey, 0);
}

/**
 * Produces a pre-computed hash key based on a string. This function produce a hash for a 32bits processor
 *
 * @param string $arrKey
 * @return string
 */
PHP_METHOD(Phalcon_Kernel, preComputeHashKey32){

	char *arKey, *strKey;
	unsigned int nKeyLength;
	ulong hash;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arKey, &nKeyLength) == FAILURE) {
		RETURN_NULL();
	}

	nKeyLength++;
	hash = zend_inline_hash_func(arKey, nKeyLength) & 0xFFFFFFFFul;
	strKey = emalloc(24);
	snprintf(strKey, 24, "%lu", hash);

	RETURN_STRING(strKey, 0);
}

/**
 * Produces a pre-computed hash key based on a string. This function produce a hash for a 64bits processor
 *
 * @param string $arrKey
 * @return string
 */
PHP_METHOD(Phalcon_Kernel, preComputeHashKey64){

	char *arKey, *strKey;
	unsigned int nKeyLength;
	register unsigned long long hash = 5381;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arKey, &nKeyLength) == FAILURE) {
		RETURN_NULL();
	}

	nKeyLength++;

	/* variant with the hash unrolled eight times */
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
		case 7: hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 6: hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 5: hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 4: hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 3: hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 2: hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 1: hash = ((hash << 5) + hash) + *arKey++; break;
	}

	strKey = emalloc(24);
	snprintf(strKey, 24, "%llu", hash);

	RETURN_STRING(strKey, 0);
}
