
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Arr;

/**
 * Chunks an array into smaller arrays of a specified size.
 */
class Chunk
{
    /**
     * @param array $collection
     * @param int   $size
     * @param bool  $preserveKeys
     *
     * @return array<int|string,mixed>
     */
    public function __invoke(
        array collection,
        int size,
        bool preserveKeys = false
    ) -> array {
        return array_chunk(collection, size, preserveKeys);
    }
}
