
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

/**
 * @property array $links
 */
abstract class AbstractLinkProvider
{
    /**
     * @var array
     */
    protected links = [];

    /**
     * LinkProvider constructor.
     *
     * @param array $links
     */
    public function __construct(array links = [])
    {
        var link;

        for link in links {
            if (
                true === is_a(link, "Phalcon\\Html\\Link\\Interfaces\\LinkInterface") ||
                true === is_a(link, "Psr\\Link\\LinkInterface")
            ) {
                let this->links[this->getKey(link)] = link;
            }
        }
    }

    /**
     * Returns an iterable of LinkInterface objects.
     *
     * The iterable may be an array or any PHP \Traversable object. If no links
     * are available, an empty array or \Traversable MUST be returned.
     *
     * @return array
     */
    protected function doGetLinks() -> array
    {
        return this->links;
    }

    /**
     * Returns an iterable of LinkInterface objects that have a specific
     * relationship.
     *
     * The iterable may be an array or any PHP \Traversable object. If no links
     * with that relationship are available, an empty array or \Traversable
     * MUST be returned.
     *
     * @return array
     */
    protected function doGetLinksByRel(string rel) -> array
    {
        var link, rels;
        array filtered;

        let filtered = [];
        for link in this->links {
            let rels = link->getRels();
            if (true === in_array(rel, rels)) {
                let filtered[] = link;
            }
        }

        return filtered;
    }

    /**
     * Returns an instance with the specified link included.
     *
     * If the specified link is already present, this method MUST return
     * normally without errors. The link is present if $link is === identical
     * to a link object already in the collection.
     *
     * @param mixed $link A link object that should be included in this
     *                    collection.
     *
     * @return $this
     */
    protected function doWithLink(link)
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
     * without errors. The link is present if $link is === identical to a link
     * object already in the collection.
     *
     * @param mixed $link The link to remove.
     *
     * @return $this
     */
    protected function doWithoutLink(link)
    {
        var key, newInstance;

        let key         = this->getKey(link),
            newInstance = clone this;

        unset(newInstance->links[key]);

        return newInstance;
    }

    /**
     * Returns the object hash key
     *
     * @param mixed link
     *
     * @return string
     */
    protected function getKey(link) -> string
    {
        return spl_object_hash(link);
    }
}
