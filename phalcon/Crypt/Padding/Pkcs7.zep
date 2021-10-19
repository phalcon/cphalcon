
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Crypt\Padding;

/**
 * Class Pkcs7
 *
 * @package Phalcon\Crypt\Padding
 */
class Pkcs7 implements PadInterface
{
    /**
     * @param int $paddingSize
     *
     * @return string
     */
    public function pad(int paddingSize) -> string
    {
        return str_repeat(chr(paddingSize), paddingSize);
    }

    /**
     * @param string $input
     * @param int    $blockSize
     *
     * @return int
     */
    public function unpad(string input, int blockSize) -> int
    {
        var last, length, ord, padding, paddingSize;

        let length = mb_strlen(input),
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
