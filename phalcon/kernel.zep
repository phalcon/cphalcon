
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	 * Produces a pre-computed hash key based on a string. This function
	 * produces different numbers in 32bit/64bit processors
	 *
	 * @return string
	 */
	public static function preComputeHashKey(string! key)
	{
		%{

		{

#if PHP_VERSION_ID < 70000
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
#else
		RETURN_MM_NULL();
#endif

		}

		}%
	}
}
