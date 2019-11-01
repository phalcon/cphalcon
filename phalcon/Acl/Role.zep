
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
     * Role name
     *
     * @var string
     */
    private name { get, __toString };

    /**
     * Role description
     *
     * @var string
     */
    private description { get };

    /**
     * Phalcon\Acl\Role constructor
     */
    public function __construct(string! name, string description = null)
    {
        if unlikely name == "*" {
            throw new Exception("Role name cannot be '*'");
        }

        let this->name = name,
            this->description = description;
    }
}
