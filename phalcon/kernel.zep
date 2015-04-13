
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon;

/**
 * Phalcon\Kernel
 *
 * This class allows to change the internal behavior of the framework in runtime
 */
class Kernel
{
	/**
	 * Produces a pre-computed hash key based on a string. This function produces different numbers in 32bit/64bit processors
	 *
	 * @param string key
	 * @return string
	 */
	public static function preComputeHashKey(string! key)
	{
		%{

		{

		char *arKey = Z_STRVAL_P(key), *strKey;
		int nKeyLength = strlen(arKey);
		register ulong hash = 5381;

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

		RETURN_MM_STRING(strKey, 0);

		}

		}%
	}
}