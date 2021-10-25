
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
 * Black list filter by key: exclude elements of an array
 * by the keys obtained from the elements of a blacklist
 */
class Blacklist extends AbstractArr
{
    /**
     * @param array $collection
     * @param array $blackList
     *
     * @return array
     */
    public function __invoke(array collection, array blackList) -> array
    {
        var blackListed;

        let blackListed = this->toFilter(
            blackList,
            function (element) {
                return typeof element === "int" || typeof element === "string";
            }
        );

        return array_diff_key(collection, array_flip(blackListed));
    }
}
