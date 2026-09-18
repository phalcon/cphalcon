
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter;

use Phalcon\Contracts\Filter\FilterTypes;
use Phalcon\Filter\Filter;

/**
 * Class FilterFactory
 *
 * @package Phalcon\Filter
 *
 * @phpstan-import-type filter_mapper from FilterTypes
 */
class FilterFactory
{
    /**
     * Returns a Locator object with all the helpers defined in anonymous
     * functions
     *
     * @return FilterInterface
     */
    public function newInstance() -> <FilterInterface>
    {
        return new Filter(this->getServices());
    }

    /**
     * Returns the available adapters
     *
     * @return string[]
     *
     * @phpstan-return filter_mapper
     */
    protected function getServices() -> array
    {
        return Filter::getDefaultMapper();
    }
}
