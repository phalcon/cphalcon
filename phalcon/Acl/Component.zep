
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
 * This class defines component entity and its description
 */
class Component implements ComponentInterface
{
    /**
     * Component description
     *
     * @var string
     */
    private description { get };

    /**
     * Component name
     *
     * @var string
     */
    private name { get, __toString };

    /**
     * Phalcon\Acl\Component constructor
     */
    public function __construct(string! name, string description = null)
    {
        if unlikely name == "*" {
            throw new Exception("Component name cannot be '*'");
        }

        let this->name = name,
            this->description = description;
    }
}
