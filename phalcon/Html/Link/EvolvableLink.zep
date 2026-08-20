
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Link;

use Phalcon\Contracts\Html\Link\LinkTypes;
use Phalcon\Html\Link\Interfaces\EvolvableLinkInterface;

/**
 * Class Phalcon\Html\Link\EvolvableLink
 *
 * @phpstan-import-type link_attribute_value from LinkTypes
 */
class EvolvableLink extends Link implements EvolvableLinkInterface
{
    /**
     * Returns an instance with the specified attribute added.
     *
     * If the specified attribute is already present, it will be overwritten
     * with the new value.
     *
     * @phpstan-param link_attribute_value $value
     */
    public function withAttribute(var attribute, var value) -> <static>
    {
        return this->doWithAttribute(attribute, value);
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
     */
    public function withHref(string href) -> <static>
    {
        return this->doWithHref(href);
    }

    /**
     * Returns an instance with the specified attribute excluded.
     *
     * If the specified attribute is not present, this method MUST return
     * normally without errors.
     */
    public function withoutAttribute(string attribute) -> <static>
    {
        return this->doWithoutAttribute(attribute);
    }

    /**
     * Returns an instance with the specified relationship excluded.
     *
     * If the specified rel is not present, this method MUST return
     * normally without errors.
     */
    public function withoutRel(string rel) -> <static>
    {
        return this->doWithoutRel(rel);
    }

    /**
     * Returns an instance with the specified relationship included.
     *
     * If the specified rel is already present, this method MUST return
     * normally without errors, but without adding the rel a second time.
     */
    public function withRel(string rel) -> <static>
    {
        return this->doWithRel(rel);
    }
}
