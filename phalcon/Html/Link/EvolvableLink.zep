
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Link;

use Psr\Link\EvolvableLinkInterface;

/**
 * Class Phalcon\Http\Link\EvolvableLink
 *
 * @property array  attributes
 * @property string href
 * @property array  rels
 * @property bool   templated
 */
class EvolvableLink extends Link implements EvolvableLinkInterface
{
    /**
     * Returns an instance with the specified attribute added.
     *
     * If the specified attribute is already present, it will be overwritten
     * with the new value.
     *
     * @param string attribute The attribute to include.
     * @param string value     The value of the attribute to set.
     *
     * @return static
     */
    public function withAttribute(var attribute, var value)
    {
        var newInstance;

        let newInstance = clone this;

        newInstance->attributes->set(attribute, value);

        return newInstance;
    }

    /**
     * Returns an instance with the specified href.
     *
     * @param string href
     *       The href value to include.  It must be one of:
     *       - An absolute URI, as defined by RFC 5988.
     *       - A relative URI, as defined by RFC 5988. The base of the relative
     *       link is assumed to be known based on context by the client.
     *       - A URI template as defined by RFC 6570.
     *       - An object implementing __toString() that produces one of the
     *       above values.
     *
     * An implementing library SHOULD evaluate a passed object to a string
     * immediately rather than waiting for it to be returned later.
     *
     * @return static
     */
    public function withHref(var href)
    {
        var newInstance;

        let newInstance            = clone this,
            newInstance->href      = href,
            newInstance->templated = this->hrefIsTemplated(href);

        return newInstance;
    }

    /**
     * Returns an instance with the specified relationship included.
     *
     * If the specified rel is already present, this method MUST return
     * normally without errors, but without adding the rel a second time.
     *
     * @param string rel
     *   The relationship value to add.
     *
     * @return static
     */
    public function withRel(var rel)
    {
        var newInstance;

        let newInstance = clone this;

        newInstance->rels->set(rel, true);

        return newInstance;
    }

    /**
     * Returns an instance with the specified attribute excluded.
     *
     * If the specified attribute is not present, this method MUST return
     * normally without errors.
     *
     * @param string attribute
     *   The attribute to remove.
     *
     * @return static
     */
    public function withoutAttribute(var attribute)
    {
        var newInstance;

        let newInstance = clone this;

        newInstance->attributes->remove(attribute);

        return newInstance;
    }

    /**
     * Returns an instance with the specified relationship excluded.
     *
     * If the specified rel is not present, this method MUST return
     * normally without errors.
     *
     * @param string rel
     *   The relationship value to exclude.
     *
     * @return static
     */
    public function withoutRel(var rel)
    {
        var newInstance;

        let newInstance = clone this;

        newInstance->rels->remove(rel);

        return newInstance;
    }
}
