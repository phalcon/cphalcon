
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Link\Interfaces;

use Phalcon\Contracts\Html\Link\LinkTypes;

/**
 * A link provider object.
 *
 * @phpstan-import-type link_collection from LinkTypes
 * @phpstan-import-type link_list from LinkTypes
 */
interface LinkProviderInterface
{
    /**
     * Returns an array of LinkInterface objects.
     *
     * @phpstan-return link_collection
     */
    public function getLinks() -> array;

    /**
     * Returns an array of LinkInterface objects that have a specific
     * relationship.
     *
     * @phpstan-return link_list
     */
    public function getLinksByRel(string rel) -> array;
}
