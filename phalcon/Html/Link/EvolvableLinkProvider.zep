
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Link;

use PsrExt\Link\EvolvableLinkProviderInterface;
use PsrExt\Link\LinkInterface;

/**
 * Class Phalcon\Http\Link\LinkProvider
 *
 * @property LinkInterface[] links
 */
class EvolvableLinkProvider extends LinkProvider implements EvolvableLinkProviderInterface
{
    /**
     * Returns an instance with the specified link included.
     *
     * If the specified link is already present, this method MUST return
     * normally without errors. The link is present if link is === identical
     * to a link object already in the collection.
     *
     * @param \Psr\Link\LinkInterface link
     *   A link object that should be included in this collection.
     *
     * @return static
     */
    public function withLink(<LinkInterface> link)
    {
        var key, newInstance;

        let key         = this->getKey(link),
            newInstance = clone this;

        let newInstance->links[key] = link;

        return newInstance;
    }

    /**
     * Returns an instance with the specified link removed.
     *
     * If the specified link is not present, this method MUST return normally
     * without errors. The link is present if link is === identical to a link
     * object already in the collection.
     *
     * @param LinkInterface link
     *   The link to remove.
     *
     * @return static
     */
    public function withoutLink(<LinkInterface> link)
    {
        var key, links, newInstance;

        let key         = this->getKey(link),
            newInstance = clone this,
            links       = this->links;

        unset links[key];

        let newInstance->links = links;

        return newInstance;
    }
}
