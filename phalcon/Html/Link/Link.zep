
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
use Phalcon\Html\Link\Interfaces\LinkInterface;

/**
 * Class Phalcon\Html\Link\Link
 *
 * @phpstan-import-type link_attributes from LinkTypes
 * @phpstan-import-type link_rels from LinkTypes
 */
class Link extends AbstractLink implements LinkInterface
{
    /**
     * Returns a list of attributes that describe the target URI.
     *
     * A key-value list of attributes, where the key is a string and the value
     * is either a PHP primitive or an array of PHP strings. If no values are
     * found an empty array MUST be returned.
     *
     * @phpstan-return link_attributes
     */
    public function getAttributes() -> array
    {
        return this->doGetAttributes();
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
    public function getHref() -> string
    {
        return this->doGetHref();
    }

    /**
     * Returns the relationship type(s) of the link.
     *
     * This method returns 0 or more relationship types for a link, expressed
     * as an array of strings.
     *
     * @phpstan-return link_rels
     */
    public function getRels() -> array
    {
        return this->doGetRels();
    }

    /**
     * Returns whether this is a templated link.
     */
    public function isTemplated() -> bool
    {
        return this->doIsTemplated();
    }
}
