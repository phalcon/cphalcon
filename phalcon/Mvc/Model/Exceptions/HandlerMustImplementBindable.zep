
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Exceptions;

use Phalcon\Mvc\Model\Exception;

class HandlerMustImplementBindable extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "Handler must implement Phalcon\\Mvc\\Model\\Binder\\BindableInterface in order to use Phalcon\\Mvc\\Model as parameter"
        );
    }
}
