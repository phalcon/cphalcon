
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
 * Class Noop
 *
 * @package Phalcon\Encryption\Crypt\Padding
 */
class Noop implements PadInterface
{
    /**
     * @param int $paddingSize
     *
     * @return string
     */
    public function pad(int paddingSize) -> string
    {
        return "";
    }

    /**
     * @param string $input
     * @param int    $blockSize
     *
     * @return int
     */
    public function unpad(string input, int blockSize) -> int
    {
        return 0;
    }
}
