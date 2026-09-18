
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
 * No padding adapter
 */
class Noop implements PadInterface
{
    public function pad(int paddingSize) -> string
    {
        return "";
    }

    public function unpad(string input, int blockSize) -> int
    {
        return 0;
    }
}
