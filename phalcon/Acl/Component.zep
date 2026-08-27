
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl;

use Phalcon\Acl\Exceptions\ForbiddenDelimiter;
use Phalcon\Acl\Exceptions\ForbiddenWildcard;

/**
 * This class defines component entity and its description
 */
class Component extends AbstractElement implements ComponentInterface
{
    /**
     * Component constructor.
     */
    public function __construct( string name, string description = null)
    {
        if unlikely name === "*" {
            throw new ForbiddenWildcard("component");
        }

        if unlikely memstr(name, "!") {
            throw new ForbiddenDelimiter("component");
        }

        let this->name = name,
            this->description = description;
    }
}
