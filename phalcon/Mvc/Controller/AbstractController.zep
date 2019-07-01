
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Controller;

use Phalcon\Di\Injectable;

/**
 * Every application controller should extend this class that encapsulates all
 * the controller functionality
 *
 * The controllers provide the “flow” between models and views. Controllers are
 * responsible for processing the incoming requests from the web browser,
 * interrogating the models for data, and passing that data on to the views for
 * presentation.
 *
 *```php
 * <?php
 *
 * class PeopleController extends \Phalcon\Mvc\Controller\AbstractController
 * {
 *     // This action will be executed by default
 *     public function indexAction()
 *     {
 *
 *     }
 *
 *     public function findAction()
 *     {
 *
 *     }
 *
 *     public function saveAction()
 *     {
 *         // Forwards flow to the index action
 *         return $this->dispatcher->forward(
 *             [
 *                 "controller" => "people",
 *                 "action"     => "index",
 *             ]
 *         );
 *     }
 * }
 *```
 */
abstract class AbstractController extends Injectable implements ControllerInterface
{
    /**
     * Phalcon\Mvc\Controller\AbstractController constructor
     */
    final public function __construct()
    {
        if method_exists(this, "onConstruct") {
            this->{"onConstruct"}();
        }
    }
}
