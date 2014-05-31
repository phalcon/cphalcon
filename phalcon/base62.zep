/**
 * Base62 encoder/decoder
 *
 * This is an example of a practical encoder and decoder for base-62 data in PHP
 * It differs from the majority of examples in that it's fast enough for moderate
 * data sizes, unlike multiprecision converters. To be practical, base-62 encoding
 * needs to use internal chunking and padding because base-62 does not fit exactly
 * into any integral number of bits. This means the output is not quite compatible
 * with multiprecision conversions, but the encoded data retains all the desirable
 * properties of base-62, so (unlike any base-64 encoding) it's URL, DNS, email
 * address and pathname safe
 *
 * $data = '';
 * //Make a nice 1M chunk of randomish binary data
 * for ($q = 0; $q < 64000; $q++) {
 *     $data .= md5($q, true);
 * }
 * echo "data size: " . strlen($data) . "\n";
 * $zz = microtime(true);
 * $encoded = base62encode($data);
 * echo "enc = " . (microtime(true) - $zz) . "sec\n";
 * $zz = microtime(true);
 * $decoded = base62decode($encoded);
 * echo "dec = " . (microtime(true) - $zz) . "sec\n";
 * echo ($data == $decoded) ? "match\n" : "fail\n";
 *
 * @package \Phalcon
 * @copyright 2011 Marcus Bointon
 * @author Marcus Bointon <marcus@synchromedia.co.uk>
 * @author Brandon Lamb <brandon@brandonlamb.com>
 * @license http://www.opensource.org/licenses/mit-license.html MIT License
 */

namespace Phalcon;

class Base62
{
	/**
	 * Encode arbitrary data into base-62
	 * Note that because base-62 encodes slightly less than 6 bits per character
	 * (actually 5.95419631038688), there is some wastage. In order to make this
	 * practical, we chunk in groups of up to 8 input chars, which give up to 11
	 * output chars with a wastage of up to 4 bits per chunk, so while the output
	 * is not quite as space efficient as a true multiprecision conversion, it's
	 * orders of magnitude faster. Note that the output of this function is not
	 * compatible with that of a multiprecision conversion, but it's a practical
	 * encoding implementation. The encoding overhead tends towards 37.5% with
	 * this chunk size; bigger chunk sizes can be slightly more space efficient,
	 * but may be slower. Base-64 doesn't suffer this problem because it fits
	 * into exactly 6 bits, so it generates the same results as a multiprecision
	 * conversion.
	 * Requires PHP 5.3.2 and gmp 4.2.0
	 *
	 * @param string data Binary data to encode
	 * @return string Base-62 encoded text (not chunked or split)
	 */
	public function encode(string data) -> string
	{
		var outstring;
		var len;
		var i;
		var chunk;
		var outlen;
		var x;
		var w;
		var pad;

		let outstring = "";
		let len = strlen(data);
		let i = 0;

		while (i < len) {
			let chunk = substr(data, i, 8);

			// 8bit/char in, 6bits/char out, round up
			let outlen = ceil((strlen(chunk) * 8) / 6);

			// gmp won't convert from binary, so go via hex
			let x = bin2hex(chunk);

			// gmp doesn't like leading 0s
			let w = gmp_strval(gmp_init(ltrim(x, "0"), 16), 62);

			let pad = str_pad(w, outlen, "0", STR_PAD_LEFT);
			let outstring .= pad;

			let i += 8;
		}

		return outstring;
	}

	/**
	 * Decode base-62 encoded text into binary
	 * Note that because base-62 encodes slightly less than 6 bits per character
	 * (actually 5.95419631038688), there is some wastage. In order to make this
	 * practical, we chunk in groups of up to 11 input chars, which give up to 8
	 * output chars with a wastage of up to 4 bits per chunk, so while the output
	 * is not quite as space efficient as a true multiprecision conversion, it's
	 * orders of magnitude faster. Note that the input of this function is not
	 * compatible with that of a multiprecision conversion, but it's a practical
	 * encoding implementation. The encoding overhead tends towards 37.5% with
	 * this chunk size; bigger chunk sizes can be slightly more space efficient,
	 * but may be slower. Base-64 doesn't suffer this problem because it fits
	 * into exactly 6 bits, so it generates the same results as a multiprecision
	 * conversion.
	 * Requires PHP 5.3.2 and gmp 4.2.0
	 *
	 * @param string data Base-62 encoded text (not chunked or split)
	 * @return string Decoded binary data
	 */
	public function decode(string! data) -> string
	{
		var outstring;
		var len;
		var i;
		var chunk;
		var outlen;
		var y;
		var pad;

		let outstring = "";
		let len = strlen(data);
		let i = 0;

		while (i < len) {
			let chunk = substr(data, i, 11);

			// 6bit/char in, 8bits/char out, round down
			let outlen = floor((strlen(chunk) * 6) / 8);

			// gmp doesn't like leading 0s
			let y = gmp_strval(gmp_init(ltrim(chunk, "0"), 62), 16);

			// double output length as as we're going via hex (4bits/char)
			let pad = str_pad(y, outlen * 2, "0", STR_PAD_LEFT);

			// same as hex2bin
			let outstring .= pack("H*", pad);

			let i += 11;
		}

		return outstring;
	}
}
