
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Crypt\Padding;

/**
 * Padding based on Pkcs7
 */
class Pkcs7 implements PadInterface
{
    public function pad(int paddingSize) -> string
    {
        return str_repeat(chr(paddingSize), paddingSize);
    }

    public function unpad(string input, int blockSize) -> int
    {
        var length, ord, padding,
            paddingSize = 0,
            last        = "";

        let length = strlen(input),
            last   = substr(input, length - 1, 1),
            ord    = ord(last);

        if ord <= blockSize {
            let paddingSize = ord,
                padding     = str_repeat(chr(paddingSize), paddingSize);

            if substr(input, length - paddingSize) !== padding {
                let paddingSize = 0;
            }
        }

        return paddingSize;
    }
}
