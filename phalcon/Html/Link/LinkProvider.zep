
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Link;

use Phalcon\Html\Link\Interfaces\LinkInterface;
use Phalcon\Html\Link\Interfaces\LinkProviderInterface;

/**
 * @property LinkInterface[] links
 */
class LinkProvider extends AbstractLinkProvider implements LinkProviderInterface
{
    /**
     * Returns an iterable of LinkInterface objects.
     *
     * The iterable may be an array or any PHP \Traversable object. If no links
     * are available, an empty array or \Traversable MUST be returned.
     *
     * @return LinkInterface[]|\Traversable
     */
    public function getLinks() -> array
    {
        return this->doGetLinks();
    }

    /**
     * Returns an iterable of LinkInterface objects that have a specific
     * relationship.
     *
     * The iterable may be an array or any PHP \Traversable object. If no links
     * with that relationship are available, an empty array or \Traversable
     * MUST be returned.
     *
     * @return LinkInterface[]|\Traversable
     */
    public function getLinksByRel(var rel) -> array
    {
        return this->doGetLinksByRel(rel);
    }
}
