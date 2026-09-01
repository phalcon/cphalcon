
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
use Phalcon\Support\Collection;

/**
 * @phpstan-import-type link_attribute_value from LinkTypes
 * @phpstan-import-type link_attributes from LinkTypes
 * @phpstan-import-type link_rels from LinkTypes
 */
abstract class AbstractLink
{
    /**
     * @phpstan-var Collection<link_attribute_value>
     */
    protected <Collection> attributes;
    protected string href = "";
    /**
     * @phpstan-var Collection<bool>
     */
    protected <Collection> rels;
    protected bool templated = false;

    /**
     * Link constructor.
     *
     * @phpstan-param link_attributes $attributes
     */
    public function __construct(
        string rel = "",
        string href = "",
        array attributes = []
    ) {
        let this->attributes = new Collection(attributes),
            this->rels       = new Collection(),
            this->href       = href,
            this->templated  = this->hrefIsTemplated(href);

        if (true !== empty(rel)) {
            this->rels->set(rel, true);
        }
    }

    /**
     * Returns a list of attributes that describe the target URI.
     *
     * A key-value list of attributes, where the key is a string and the value
     * is either a PHP primitive or an array of PHP strings. If no values are
     * found an empty array MUST be returned.
     *
     * @phpstan-return link_attributes
     */
    protected function doGetAttributes() -> array
    {
        return this->attributes->toArray();
    }

    /**
     * Returns the target of the link.
     *
     * The target link must be one of:
     * - An absolute URI, as defined by RFC 5988.
     * - A relative URI, as defined by RFC 5988. The base of the relative link
     *     is assumed to be known based on context by the client.
     * - A URI template as defined by RFC 6570.
     *
     * If a URI template is returned, isTemplated() MUST return True.
     */
    protected function doGetHref() -> string
    {
        return this->href;
    }

    /**
     * Returns the relationship type(s) of the link.
     *
     * This method returns 0 or more relationship types for a link, expressed
     * as an array of strings.
     *
     * @phpstan-return link_rels
     */
    protected function doGetRels() -> array
    {
        return this->rels->keys(false);
    }

    /**
     * Returns whether this is a templated link. True if this link object is
     * templated, False otherwise.
     */
    protected function doIsTemplated() -> bool
    {
        return this->templated;
    }

    /**
     * @phpstan-param link_attribute_value $value
     */
    protected function doWithAttribute(string key, var value) -> <static>
    {
        var newInstance;

        let newInstance = clone this;

        newInstance->attributes->set(key, value);

        return newInstance;
    }

    protected function doWithHref(string href) -> <static>
    {
        var newInstance;

        let newInstance = clone this;

        let newInstance->href      = href,
            newInstance->templated = this->hrefIsTemplated(href);

        return newInstance;
    }

    protected function doWithoutAttribute(string key) -> <static>
    {
        var newInstance;

        let newInstance = clone this;

        newInstance->attributes->remove(key);

        return newInstance;
    }

    protected function doWithoutRel(string key) -> <static>
    {
        var newInstance;

        let newInstance = clone this;

        newInstance->rels->remove(key);

        return newInstance;
    }

    protected function doWithRel(string key) -> <static>
    {
        var newInstance;

        let newInstance = clone this;

        newInstance->rels->set(key, true);

        return newInstance;
    }

    /**
     * Determines if a href is a templated link or not.
     *
     * @see https://tools.ietf.org/html/rfc6570
     */
    protected function hrefIsTemplated(string href) -> bool
    {
        return (
            false !== mb_strpos(href, "{") &&
            false !== mb_strpos(href, "}")
        );
    }
}
