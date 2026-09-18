
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
 * Padding based on ISO10126
 */
class Iso10126 implements PadInterface
{
    public function pad(int paddingSize) -> string
    {
        var counter, padding;

        let padding = "";

        for counter in range(0, paddingSize - 2) {
            let padding .= random_bytes(1);
        }

        let padding .= chr(paddingSize);

        return padding;
    }

    public function unpad(string input, int blockSize) -> int
    {
        var last, length;

        let length = strlen(input),
            last   = substr(input, length - 1, 1);

        return ord(last);
    }
}
