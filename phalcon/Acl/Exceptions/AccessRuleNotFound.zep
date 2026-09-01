
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

class AccessRuleNotFound extends Exception
{
    public function __construct(string accessName, string componentName)
    {
        parent::__construct(
            "Access '" . accessName . "' does not exist in component '" . componentName . "'"
        );
    }
}
