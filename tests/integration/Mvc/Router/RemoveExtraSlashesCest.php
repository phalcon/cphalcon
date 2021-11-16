<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Mvc\Router;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\RouterTrait;

class RemoveExtraSlashesCest
{
    use RouterTrait;

    /**
     * Tests removing extra slashes
     *
     * @author       Andy Gutierrez <andres.gutierrez@phalcon.io>
     * @since        2012-12-16
     *
     * @dataProvider getMatchingWithExtraSlashes
     */
    public function testRemovingExtraSlashes(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Mvc\Router - removeExtraSlashes()');

        $route  = $example[0];
        $params = $example[1];

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
