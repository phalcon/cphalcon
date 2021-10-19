
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
 * Class Ansi
 *
 * @package Phalcon\Crypt\Padding
 */
class Ansi implements PadInterface
{
    /**
     * @param int $paddingSize
     *
     * @return string
     */
    public function pad(int paddingSize) -> string
    {
        return str_repeat(chr(0), paddingSize - 1) . chr(paddingSize);
    }

    /**
     * @param string $input
     * @param int    $blockSize
     *
     * @return int
     */
    public function unpad(string input, int blockSize) -> int
    {
        var last, length, ord, padding, paddingSize, repeat;

        let paddingSize = 0,
            length      = strlen(input),
            last        = substr(input, length - 1, 1),
            ord         = ord(last);

        if ord <= blockSize {
            let paddingSize = ord,
                repeat      = "";

            if paddingSize > 1 {
                let repeat = str_repeat(chr(0), paddingSize - 1);
            }

            let padding = repeat . last;

            if substr(input, length - paddingSize) !== padding {
                let paddingSize = 0;
            }
        }

        return paddingSize;
    }
}
