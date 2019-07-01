
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Controller;

/**
 *Interface for Phalcon\Mvc\Controller\BindModel
 */
interface BindModelInterface
{
    /**
     * Return the model name associated with this controller
     */
    public static function getModelName() -> string;
}
