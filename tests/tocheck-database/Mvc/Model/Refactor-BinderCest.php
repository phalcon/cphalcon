<?php

namespace Phalcon\Tests\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Cache\Backend\Apc;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Di\Di;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\Collection;
use Phalcon\Mvc\Model\Binder;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Tests\Models\People;
use Phalcon\Tests\Models\Robots;
use Test10Controller;
use Test11Controller;
use Test9Controller;
use TypeError;

/**
 * \Phalcon\Tests\Integration\Mvc\Model\BindingCest
 * Tests the Phalcon\Mvc\Application component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link          http://www.phalcon.io
 * @author        Andres Gutierrez <andres@phalcon.io>
 * @author        Phalcon Team <team@phalcon.io>
 * @author        Wojciech Ślawski <jurigag@gmail.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalcon.io
 * so that we can send you a copy immediately.
 */
class BinderCest
{
    /**
     * @var Apc
     */
    private $cache;

    /**
     * @var Binder
     */
    private $modelBinder;

    /**
     * @var Manager
     */
    private $modelsManager;

    /**
     * @var Robots
     */
    private $robot;

    /**
     * @var People
     */
    private $people;

    /**
     * Executed before each test
     */
    public function _before(IntegrationTester $I)
    {
        $di = $I->getApplication()->getDI();

        Di::setDefault($di);

        $I->checkExtensionIsLoaded('apcu');

        if (
            !ini_get('apcu.enabled') ||
            (PHP_SAPI === 'cli' && !ini_get('apcu.enable_cli'))
        ) {
            $I->skipTest('Warning: apcu.enable_cli must be set to "On"');
        }

        if (
            extension_loaded('apcu') &&
            version_compare(phpversion('apcu'), '5.1.6', '=')
        ) {
            $I->skipError(
                'Warning: APCu v5.1.6 was broken. See: https://github.com/krakjoe/apcu/issues/203'
            );
        }

        $this->cache = new Apc(
            new Data(
                [
                    'lifetime' => 20,
                ]
            )
        );

        $this->modelBinder = new Binder($this->cache);

        $this->modelsManager = $di->getShared('modelsManager');
        $this->robot         = Robots::findFirst();
        $this->people        = People::findFirst();

        $I->addServiceToContainer(
            'modelsMetadata',
            function () {
                return new Memory();
            },
            true
        );
    }

    /**
     * Tests dispatcher and single model
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testDispatcherSingleBinding(IntegrationTester $I)
    {
        $dispatcher = $this->createDispatcher();

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $this->returnDispatcherValueForAction(
                $dispatcher,
                'test10',
                'view',
                [
                    'people' => $this->people->cedula,
                ]
            );

            $I->assertInstanceOf(People::class, $returnedValue);

            $I->assertEquals($this->people->cedula, $returnedValue->cedula);

            $I->assertEquals(
                [
                    'people' => People::class,
                ],
                $this->cache->get('_PHMB_Test10Controller_viewAction')
            );
        }
    }

    private function createDispatcher(bool $useModelBinder = true): Dispatcher
    {
        $this->cache->flush();

        $dispatcher = new Dispatcher();

        if ($useModelBinder) {
            $dispatcher->setModelBinder($this->modelBinder);
        }

        $dispatcher->setDI(
            Di::getDefault()
        );

        return $dispatcher;
    }

    private function returnDispatcherValueForAction(
        Dispatcher $dispatcher,
        $controllerName,
        $actionName,
        $params,
        bool $returnValue = true
    ) {
        $dispatcher->setReturnedValue(null);
        $dispatcher->setControllerName($controllerName);
        $dispatcher->setActionName($actionName);
        $dispatcher->setParams($params);

        if (!$returnValue) {
            return null;
        }

        $dispatcher->dispatch();

        return $dispatcher->getReturnedValue();
    }

    /**
     * Tests dispatcher and multiple model
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testDispatcherMultiBinding(IntegrationTester $I)
    {
        $dispatcher = $this->createDispatcher();

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $this->returnDispatcherValueForAction(
                $dispatcher,
                'test10',
                'multiple',
                [
                    'people' => $this->people->cedula,
                    'robots' => $this->robot->id,
                ]
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue[0]
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\Robots::class,
                $returnedValue[1]
            );

            $I->assertEquals($this->people->cedula, $returnedValue[0]->cedula);
            $I->assertEquals($this->robot->id, $returnedValue[1]->id);

            $I->assertEquals(
                [
                    'people' => People::class,
                    'robots' => Robots::class,
                ],
                $this->cache->get('_PHMB_Test10Controller_multipleAction')
            );
        }
    }

    /**
     * Tests dispatcher and single model with interface
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testDispatcherSingleBindingWithInterface(IntegrationTester $I)
    {
        $dispatcher = $this->createDispatcher();

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $this->returnDispatcherValueForAction(
                $dispatcher,
                'test11',
                'view',
                [
                    'people' => $this->people->cedula,
                ]
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue
            );

            $I->assertEquals($this->people->cedula, $returnedValue->cedula);

            $I->assertEquals(
                [
                    'people' => People::class,
                ],
                $this->cache->get('_PHMB_Test11Controller_viewAction')
            );
        }
    }

    /**
     * Tests dispatcher and multi model with interface
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testDispatcherMultiBindingWithInterface(IntegrationTester $I)
    {
        $dispatcher = $this->createDispatcher();

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $this->returnDispatcherValueForAction(
                $dispatcher,
                'test11',
                'multiple',
                [
                    'people' => $this->people->cedula,
                    'robots' => $this->robot->id,
                ]
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue[0]
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\Robots::class,
                $returnedValue[1]
            );

            $I->assertEquals($this->people->cedula, $returnedValue[0]->cedula);
            $I->assertEquals($this->robot->id, $returnedValue[1]->id);

            $I->assertEquals(
                [
                    'people' => People::class,
                    'robots' => Robots::class,
                ],
                $this->cache->get('_PHMB_Test11Controller_multipleAction')
            );
        }
    }

    /**
     * Tests dispatcher and single binding exception
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testDispatcherSingleBindingException(IntegrationTester $I)
    {
        $dispatcher = $this->createDispatcher(false);

        $this->returnDispatcherValueForAction(
            $dispatcher,
            'test9',
            'view',
            [
                'people' => $this->people->cedula,
            ],
            false
        );

        $I->expectThrowable(
            new TypeError(
                'Argument 1 passed to Test9Controller::viewAction() must be an ' .
                'instance of Phalcon\Mvc\Model, string given'
            ),
            function () use ($dispatcher) {
                $dispatcher->dispatch();
            }
        );

        $dispatcher->setModelBinder($this->modelBinder);

        for ($i = 0; $i <= 1; $i++) {
            $dispatcher->dispatch();

            $returnedValue = $dispatcher->getReturnedValue();

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue
            );

            $I->assertEquals($returnedValue->cedula, $this->people->cedula);

            $I->assertEquals(
                [
                    'people' => People::class,
                ],
                $this->cache->get('_PHMB_Test9Controller_viewAction')
            );
        }
    }

    /**
     * Tests micro with handlers and model binder
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testMicroHandlerSingleBinding(IntegrationTester $I)
    {
        $micro = $this->createMicro();

        $micro->get(
            '/{people}',
            function (People $people) {
                return $people;
            }
        )->setName('people')
        ;

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle(
                '/' . $this->people->cedula
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue
            );

            $I->assertEquals($this->people->cedula, $returnedValue->cedula);

            $I->assertEquals(
                [
                    'people' => People::class,
                ],
                $this->cache->get('_PHMB_people')
            );
        }
    }

    private function createMicro(bool $useModelBinder = true): Micro
    {
        $this->cache->flush();

        $micro = new Micro(
            Di::getDefault()
        );

        if ($useModelBinder) {
            $micro->setModelBinder($this->modelBinder);
        }

        return $micro;
    }

    /**
     * Tests micro with handler and multi binding
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testMicroHandlerMultiBinding(IntegrationTester $I)
    {
        $micro = $this->createMicro();

        $micro->get(
            '/{people}/robot/{robots}',
            function (People $people, Robots $robot) {
                return [$people, $robot];
            }
        );

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle(
                '/' . $this->people->cedula . '/robot/' . $this->robot->id
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue[0]
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\Robots::class,
                $returnedValue[1]
            );

            $I->assertEquals($this->people->cedula, $returnedValue[0]->cedula);
            $I->assertEquals($this->robot->id, $returnedValue[1]->id);

            $I->assertEquals(
                [
                    'people' => People::class,
                    'robots' => Robots::class,
                ],
                $this->cache->get('_PHMB_/{people}/robot/{robots}')
            );
        }
    }

    /**
     * Tests micro with handler and single binding exception
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testMicroHandlerSingleBindingException(IntegrationTester $I)
    {
        $micro = $this->createMicro(false);

        $micro->get(
            '/{people}',
            function (People $people) {
                return $people;
            }
        );

        $I->expectThrowable(
            new TypeError(
                'Argument 1 passed to Phalcon\Tests\Integration\Mvc\Model\BinderCest::' .
                'Phalcon\Tests\Integration\Mvc\Model\{closure}() must be an instance ' .
                'of Phalcon\Tests\Models\People, string given'
            ),
            function () use ($micro) {
                $micro->handle(
                    '/' . $this->people->cedula
                );
            }
        );

        $micro->setModelBinder($this->modelBinder);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle(
                '/' . $this->people->cedula
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue
            );

            $I->assertEquals($this->people->cedula, $returnedValue->cedula);

            $I->assertEquals(
                [
                    'people' => People::class,
                ],
                $this->cache->get('_PHMB_/{people}')
            );
        }
    }

    /**
     * Tests micro with controllers and model binder
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testMicroControllerSingleBinding(IntegrationTester $I)
    {
        $micro = $this->createMicro();

        $test10 = new Collection();

        $test10->setHandler(
            new Test10Controller()
        );

        $test10->get('/{people}', 'viewAction');

        $micro->mount($test10);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle(
                '/' . $this->people->cedula
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue
            );

            $I->assertEquals($this->people->cedula, $returnedValue->cedula);

            $I->assertEquals(
                [
                    'people' => People::class,
                ],
                $this->cache->get('_PHMB_Test10Controller_viewAction')
            );
        }
    }

    /**
     * Tests micro with controllers and model binder
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testMicroControllerMultiBinding(IntegrationTester $I)
    {
        $micro = $this->createMicro();

        $test10 = new Collection();

        $test10->setHandler(
            new Test10Controller()
        );

        $test10->get('/{people}/robot/{robots}', 'multipleAction');

        $micro->mount($test10);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle(
                '/' . $this->people->cedula . '/robot/' . $this->robot->id
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue[0]
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\Robots::class,
                $returnedValue[1]
            );

            $I->assertEquals($this->people->cedula, $returnedValue[0]->cedula);
            $I->assertEquals($this->robot->id, $returnedValue[1]->id);

            $I->assertEquals(
                [
                    'people' => People::class,
                    'robots' => Robots::class,
                ],
                $this->cache->get('_PHMB_Test10Controller_multipleAction')
            );
        }
    }

    /**
     * Tests micro with controller and single binding using interface
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testMicroControllerSingleBindingWithInterface(IntegrationTester $I)
    {
        $micro = $this->createMicro();

        $test11 = new Collection();

        $test11->setHandler(
            new Test11Controller()
        );

        $test11->get('/{people}', 'viewAction');

        $micro->mount($test11);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/' . $this->people->cedula);

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue
            );

            $I->assertEquals($this->people->cedula, $returnedValue->cedula);

            $I->assertEquals(
                [
                    'people' => People::class,
                ],
                $this->cache->get('_PHMB_Test11Controller_viewAction')
            );
        }
    }

    /**
     * Tests micro with controller and multi binding using interface
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testMicroControllerMultiBindingWithInterface(IntegrationTester $I)
    {
        $micro = $this->createMicro();

        $test11 = new Collection();

        $test11->setHandler(
            new Test11Controller()
        );

        $test11->get('/{people}/robot/{robots}', 'multipleAction');

        $micro->mount($test11);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle(
                '/' . $this->people->cedula . '/robot/' . $this->robot->id
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue[0]
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\Robots::class,
                $returnedValue[1]
            );

            $I->assertEquals($this->people->cedula, $returnedValue[0]->cedula);
            $I->assertEquals($this->robot->id, $returnedValue[1]->id);

            $I->assertEquals(
                [
                    'people' => People::class,
                    'robots' => Robots::class,
                ],
                $this->cache->get('_PHMB_Test11Controller_multipleAction')
            );
        }
    }

    /**
     * Tests micro with controller and single binding exception
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testMicroControllerSingleBindingException(IntegrationTester $I)
    {
        $micro = $this->createMicro(false);

        $test9 = new Collection();

        $test9->setHandler(
            new Test9Controller()
        );

        $test9->get('/{people}', 'viewAction');

        $micro->mount($test9);


        $I->expectThrowable(
            new TypeError(
                'Argument 1 passed to Test9Controller::viewAction() must be an ' .
                'instance of Phalcon\Mvc\Model, string given'
            ),
            function () use ($micro) {
                $micro->handle(
                    '/' . $this->people->cedula
                );
            }
        );

        $micro->setModelBinder($this->modelBinder);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/' . $this->people->cedula);

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue
            );

            $I->assertEquals($this->people->cedula, $returnedValue->cedula);

            $I->assertEquals(
                [
                    'people' => People::class,
                ],
                $this->cache->get('_PHMB_Test9Controller_viewAction')
            );
        }
    }

    /**
     * Tests micro with lazy controllers and model binder
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testMicroLazySingleBinding(IntegrationTester $I)
    {
        $micro = $this->createMicro();

        $test10 = new Collection();

        $test10->setHandler(
            \Test10Controller::class,
            true
        );

        $test10->get('/{people}', 'viewAction');

        $micro->mount($test10);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/' . $this->people->cedula);

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue
            );

            $I->assertEquals($this->people->cedula, $returnedValue->cedula);

            $I->assertEquals(
                [
                    'people' => People::class,
                ],
                $this->cache->get('_PHMB_Test10Controller_viewAction')
            );
        }
    }

    /**
     * Tests micro with lazy controllers and model binder
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testMicroLazyMultiBinding(IntegrationTester $I)
    {
        $micro = $this->createMicro();

        $test10 = new Collection();

        $test10->setHandler(
            \Test10Controller::class,
            true
        );

        $test10->get('/{people}/robot/{robots}', 'multipleAction');

        $micro->mount($test10);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle(
                '/' . $this->people->cedula . '/robot/' . $this->robot->id
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue[0]
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\Robots::class,
                $returnedValue[1]
            );

            $I->assertEquals($this->people->cedula, $returnedValue[0]->cedula);
            $I->assertEquals($this->robot->id, $returnedValue[1]->id);

            $I->assertEquals(
                [
                    'people' => People::class,
                    'robots' => Robots::class,
                ],
                $this->cache->get('_PHMB_Test10Controller_multipleAction')
            );
        }
    }

    /**
     * Tests micro with lazy controllers and model binder
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testMicroLazySingleBindingWithInterface(IntegrationTester $I)
    {
        $micro = $this->createMicro();

        $test11 = new Collection();

        $test11->setHandler(
            \Test11Controller::class,
            true
        );

        $test11->get('/{people}', 'viewAction');

        $micro->mount($test11);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/' . $this->people->cedula);

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue
            );

            $I->assertEquals($this->people->cedula, $returnedValue->cedula);

            $I->assertEquals(
                [
                    'people' => People::class,
                ],
                $this->cache->get('_PHMB_Test11Controller_viewAction')
            );
        }
    }

    /**
     * Tests micro with lazy controllers and model binder
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testMicroLazyMultiBindingWithInterface(IntegrationTester $I)
    {
        $micro = $this->createMicro();

        $test11 = new Collection();

        $test11->setHandler(
            \Test11Controller::class,
            true
        );

        $test11->get('/{people}/robot/{robots}', 'multipleAction');

        $micro->mount($test11);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle(
                '/' . $this->people->cedula . '/robot/' . $this->robot->id
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue[0]
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\Robots::class,
                $returnedValue[1]
            );

            $I->assertEquals($this->people->cedula, $returnedValue[0]->cedula);
            $I->assertEquals($this->robot->id, $returnedValue[1]->id);

            $I->assertEquals(
                [
                    'people' => People::class,
                    'robots' => Robots::class,
                ],
                $this->cache->get('_PHMB_Test11Controller_multipleAction')
            );
        }
    }

    /**
     * Tests micro with lazy controllers and model binder
     *
     * @since  2016-10-29
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testMicroLazySingleBindingException(IntegrationTester $I)
    {
        $micro = $this->createMicro(false);

        $test9 = new Collection();

        $test9->setHandler(
            \Test9Controller::class,
            true
        );

        $test9->get('/{people}', 'viewAction');

        $micro->mount($test9);


        $I->expectThrowable(
            new TypeError(
                'Argument 1 passed to Test9Controller::viewAction() must be an ' .
                'instance of Phalcon\Mvc\Model, string given'
            ),
            function () use ($micro) {
                $micro->handle(
                    '/' . $this->people->cedula
                );
            }
        );

        $micro->setModelBinder($this->modelBinder);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/' . $this->people->cedula);

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue
            );

            $I->assertEquals($this->people->cedula, $returnedValue->cedula);

            $I->assertEquals(
                [
                    'people' => People::class,
                ],
                $this->cache->get('_PHMB_Test9Controller_viewAction')
            );
        }
    }

    /**
     * Tests dispatcher and single model original values
     *
     * @since  2017-01-19
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testDispatcherSingleBindingOriginalValues(IntegrationTester $I)
    {
        $dispatcher = $this->createDispatcher();

        $params = [
            'people' => $this->people->cedula,
        ];

        $returnedValue = $this->returnDispatcherValueForAction(
            $dispatcher,
            'test10',
            'view',
            $params
        );

        $I->assertInstanceOf(
            \Phalcon\Tests\Models\People::class,
            $returnedValue
        );

        $I->assertEquals($this->people->cedula, $returnedValue->cedula);

        $I->assertEquals(
            $params,
            $dispatcher->getModelBinder()->getOriginalValues()
        );
    }

    /**
     * Tests dispatcher and single model without cache
     *
     * @since  2017-01-24
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     */
    public function testDispatcherSingleBindingNoCache(IntegrationTester $I)
    {
        $dispatcher = $this->createDispatcher(false);

        $modelBinder = new Binder();

        $dispatcher->setModelBinder($modelBinder);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $this->returnDispatcherValueForAction(
                $dispatcher,
                'test10',
                'view',
                [
                    'people' => $this->people->cedula,
                ]
            );

            $I->assertInstanceOf(
                \Phalcon\Tests\Models\People::class,
                $returnedValue
            );

            $I->assertEquals($this->people->cedula, $returnedValue->cedula);
        }
    }
}
