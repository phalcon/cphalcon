
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Arr;

/**
 * Class ToObject
 *
 * @package Phalcon\Support\Arr
 */
class ToObject
{
    /**
     * Returns the passed array as an object
     *
     * @param array $collection
     *
     * @return object
     */
    public function __invoke(array collection) -> object
    {
        return (object) collection;
    }
}
