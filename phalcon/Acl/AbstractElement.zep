
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl;

/**
 * Shared base for ACL Role and Component entities: a name and an optional
 * description.
 */
abstract class AbstractElement
{
    /**
     * Element description
     *
     * @var string | null
     */
    protected description;

    /**
     * Element name
     *
     * @var string
     */
    protected name;

    public function __toString() -> string
    {
        return this->name;
    }

    public function getDescription() -> string | null
    {
        return this->description;
    }

    public function getName() -> string
    {
        return this->name;
    }
}
