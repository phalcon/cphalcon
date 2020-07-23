
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc;

use Phalcon\Di\Injectable;
use Phalcon\Di\AutowireInterface;

/**
 * Phalcon\Mvc\Controller
 *
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
 * class PeopleController extends \Phalcon\Mvc\Controller
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
abstract class Controller extends Injectable implements ControllerInterface
{
    /**
     * Phalcon\Mvc\Controller constructor
     */
    final public function __construct()
    {
        var autowire, container;

        if method_exists(this, "onConstruct") {

            let container = this->getDI();

            if method_exists(container, "getAutowire") {
                let autowire = container->getAutowire();
            }

            if autowire && autowire instanceof AutowireInterface {
                autowire->resolveMethod(container, this, "onConstruct");
            } else {
                this->{"onConstruct"}();
            }
        }
    }
}
