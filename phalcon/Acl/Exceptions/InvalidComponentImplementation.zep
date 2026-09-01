
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl\Exceptions;

use Phalcon\Acl\Exception;

class InvalidComponentImplementation extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "Object passed as componentName must implement " .
            "Phalcon\\Acl\\ComponentAwareInterface or Phalcon\\Acl\\ComponentInterface"
        );
    }
}
