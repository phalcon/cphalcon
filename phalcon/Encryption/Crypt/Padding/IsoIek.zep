
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
 * Class IsoIek
 *
 * @package Phalcon\Encryption\Crypt\Padding
 */
class IsoIek implements PadInterface
{
    /**
     * @param int $paddingSize
     *
     * @return string
     */
    public function pad(int paddingSize) -> string
    {
        return chr(0x80) . str_repeat(chr(0), paddingSize - 1);
    }

    /**
     * @param string $input
     * @param int    $blockSize
     *
     * @return int
     */
    public function unpad(string input, int blockSize) -> int
    {
        var length, inputArray, zero;
        int counter, paddingSize;

        let paddingSize = 0,
            zero        = chr(0),
            length      = strlen(input),
            inputArray  = str_split(input),
            counter     = length - 1;

        while (
            counter > 0 &&
            inputArray[counter] === zero &&
            paddingSize < blockSize
        ) {
            let paddingSize++,
                counter--;
        }

        if inputArray[counter] == chr(0x80) {
            let paddingSize++;
        } else {
            let paddingSize = 0;
        }

        return paddingSize;
    }
}
