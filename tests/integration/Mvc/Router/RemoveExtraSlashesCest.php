<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Router;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\RouterTrait;

/**
 * Class RemoveExtraSlashesCest
 */
class RemoveExtraSlashesCest
{
    use RouterTrait;

    /**
     * Tests removing extra slashes
     *
     * @param IntegrationTester $I
     *
     * @author Andy Gutierrez <andres.gutierrez@phalconphp.com>
     * @since  2012-12-16
     */
    public function testRemovingExtraSlashes(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - removeExtraSlashes()');

        $examples = $this->getMatchingWithExtraSlashes();

        foreach ($examples as $item) {
            $route  = $item[0];
            $params = $item[1];

            $router = $this->getRouter();

            $router->removeExtraSlashes(true);

            $router->handle($route);



            $I->assertTrue(
                $router->wasMatched()
            );

            $I->assertEquals(
                $params['controller'],
                $router->getControllerName()
            );

            $I->assertEquals(
                $params['action'],
                $router->getActionName()
            );
        }
    }

    private function getMatchingWithExtraSlashes(): array
    {
        return [
            [
                '/index/',
                [
                    'controller' => 'index',
                    'action'     => '',
                ],
            ],
            [
                '/session/start/',
                [
                    'controller' => 'session',
                    'action'     => 'start',
                ],
            ],
            [
                '/users/edit/100/',
                [
                    'controller' => 'users',
                    'action'     => 'edit',
                ],
            ],
        ];
    }
}
