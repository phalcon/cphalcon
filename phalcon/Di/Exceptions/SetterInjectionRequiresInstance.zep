
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di\Exceptions;

use Phalcon\Di\Exception;

class SetterInjectionRequiresInstance extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "The definition has setter injection parameters but the constructor didn't return an instance"
        );
    }
}
