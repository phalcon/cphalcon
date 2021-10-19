
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
 * Class Iso10126
 *
 * @package Phalcon\Crypt\Padding
 */
class Iso10126 implements PadInterface
{
    /**
     * @param string $input
     * @param int    $blockSize
     *
     * @return string
     */
    public function pad(int paddingSize) -> string
    {
        var counter, padding;

        let padding = "";

        for counter in range(0, paddingSize - 2) {
            let padding .= chr(rand());
        }

        let padding .= chr(paddingSize);

        return padding;
    }

    /**
     * @param string $input
     * @param int    $blockSize
     *
     * @return int
     */
    public function unpad(string input, int blockSize) -> int
    {
        var last, length;

        let length = strlen(input),
            last   = substr(input, length - 1, 1);

        return ord(last);
    }
}
