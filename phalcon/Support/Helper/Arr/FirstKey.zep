
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
 * Returns the key of the first element of the collection. If a callable
 * is passed, the element returned is the first that validates true
 */
class FirstKey extends AbstractArr
{
    /**
     * @param array         $collection
     * @param callable|null $method
     *
     * @return mixed
     */
    public function __invoke(array collection, var method = null) -> var
    {
        var filtered;

        let filtered = this->toFilter(collection, method);

        return array_key_first(filtered);
    }
}
