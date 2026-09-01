
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

class ViewNotFound extends Exception
{
    public function __construct(string viewPath)
    {
        parent::__construct(
            "View '" . viewPath . "' was not found in any of the views directory"
        );
    }
}
