
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Encryption\Crypt\Padding;

/**
 * Canonical contract for Phalcon\Encryption\Crypt\Padding strategies.
 *
 * The pad/unpad protocol operates on binary (8-bit) data. Implementations
 * must measure and slice the input with byte-true functions (`strlen`,
 * `substr`, or the `mb_*` family with the explicit `"8bit"` encoding); using
 * encoding-sensitive functions such as `mb_strlen()` on the padded plaintext
 * yields the wrong padding size whenever the bytes form valid multibyte
 * sequences.
 */
interface Pad
{
    /**
     * @param int $paddingSize
     *
     * @return string
     */
    public function pad(int paddingSize) -> string;

    /**
     * @param string $input
     * @param int    $blockSize
     *
     * @return int
     */
    public function unpad(string input, int blockSize) -> int;
}
