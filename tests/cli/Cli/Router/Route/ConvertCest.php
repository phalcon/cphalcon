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

namespace Phalcon\Tests\Cli\Cli\Router\Route;

use CliTester;
use Codeception\Example;
use Phalcon\Cli\Router;
use Phalcon\Cli\Router\Route;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class ConvertCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    /**
     * @dataProvider getExamplesConverters
     */
    public function testConverters(CliTester $I, Example $example)
    {
        $route = $example['route'];
        $paths = $example['paths'];

        Route::reset();

        $router = new Router();

        $route1 = $router
            ->add('{task:[a-z\-]+} {action:[a-z\-]+} this-is-a-country');

        $taskConverter   = function ($task) {
            return str_replace('-', '', $task);
        };
        $actionConverter = function ($action) {
            return str_replace('-', '', $action);
        };

        $route1
            ->convert('task', $taskConverter)
            ->convert('action', $actionConverter)
        ;

        $router
            ->add(
                '([A-Z]+) ([0-9]+)',
                [
                    'task'   => 1,
                    'action' => 'default',
                    'id'     => 2,
                ]
            )
            ->convert(
                'task',
                function ($task) {
                    return strtolower($task);
                }
            )
            ->convert(
                'action',
                function ($action) {
                    if ($action == 'default') {
                        return 'index';
                    }

                    return $action;
                }
            )
            ->convert(
                'id',
                function ($id) {
                    return strrev($id);
                }
            )
        ;

        $router->handle($route);

        $I->assertTrue(
            $router->wasMatched()
        );

        $I->assertEquals(
            $paths['task'],
            $router->getTaskName()
        );

        $I->assertEquals(
            $paths['action'],
            $router->getActionName()
        );

        $expected = [
            'task'   => $taskConverter,
            'action' => $actionConverter,
        ];
        $I->assertEquals(
            $expected,
            $route1->getConverters()
        );
    }

    private function getExamplesConverters(): array
    {
        return [
            [
                'route' => 'some-controller my-action-name this-is-a-country',
                'paths' => [
                    'task'   => 'somecontroller',
                    'action' => 'myactionname',
                    'params' => ['this-is-a-country'],
                ],
            ],
            [
                'route' => 'BINARY 1101',
                'paths' => [
                    'task'   => 'binary',
                    'action' => 'index',
                    'params' => [1011],
                ],
            ],
        ];
    }
}
