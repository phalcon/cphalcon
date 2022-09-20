
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
 * This class defines role entity and its description
 */
class Role implements RoleInterface
{
    /**
     * Role description
     *
     * @var string
     */
    private description;

    /**
     * Role name
     *
     * @var string
     */
    private name;

    /**
     * Phalcon\Acl\Role constructor
     */
    public function __construct(string! name, string description = null)
    {
        if unlikely name === "*" {
            throw new Exception("Role name cannot be '*'");
        }

        let this->name = name,
            this->description = description;
    }

    public function __toString() -> string
    {
        return this->name;
    }

    public function getDescription() -> string
    {
        return this->description;
    }

    public function getName() -> string
    {
        return this->name;
    }
}
