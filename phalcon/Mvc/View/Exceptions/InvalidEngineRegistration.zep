
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\View\Exceptions;

use Phalcon\Mvc\View\Exception;

class InvalidEngineRegistration extends Exception
{
    public function __construct(string extension)
    {
        parent::__construct(
            "Invalid template engine registration for extension: " . extension
        );
    }
}
