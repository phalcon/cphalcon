<?php

/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Cache\Backend\Apc;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Di;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\Collection;
use Phalcon\Mvc\Model\Binder;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Test\Models\People;
use Phalcon\Test\Models\Robots;
use PHPUnit\Framework\SkippedTestError;

/**
 * Phalcon\Test\Integration\Mvc\Model\BindingCest
 * Tests the Phalcon\Mvc\Application component
 *
 * @package Phalcon\Test\Integration\Mvc\Model
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
     *
     * @param IntegrationTester $I
     */
    public function _before(IntegrationTester $I)
    {
        Di::setDefault($I->getApplication()->getDI());

        if (!extension_loaded('apc')) {
            throw new SkippedTestError(
                'Warning: apc extension is not loaded'
            );
        }

        if (!ini_get('apc.enabled') || (PHP_SAPI === 'cli' && !ini_get('apc.enable_cli'))) {
            throw new SkippedTestError(
                'Warning: apc.enable_cli must be set to "On"'
            );
        }

        if (extension_loaded('apcu') && version_compare(phpversion('apcu'), '5.1.6', '=')) {
            throw new SkippedTestError(
                'Warning: APCu v5.1.6 was broken. See: https://github.com/krakjoe/apcu/issues/203'
            );
        }

        $this->cache = new Apc(new Data(['lifetime' => 20]));
        $this->modelBinder = new Binder($this->cache);

        $this->modelsManager = $I->getApplication()->getDI()->getShared('modelsManager');
        $this->robot = Robots::findFirst();
        $this->people = People::findFirst();

        $I->haveServiceInDi(
            'modelsMetadata',
            function () {
                return new Memory;
            },
            true
        );
    }

    /**
     * Tests dispatcher and single model
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testDispatcherSingleBinding(IntegrationTester $I)
    {
        $dispatcher = $this->createDispatcher();
        $this->assertDispatcher($dispatcher, $I);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $this->returnDispatcherValueForAction(
                $dispatcher,
                'test10',
                'view',
                ['people' => $this->people->cedula]
            );
            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue);
            $I->assertEquals($this->people->cedula, $returnedValue->cedula);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                ],
                $this->cache->get('_PHMB_Test10Controller_viewAction')
            );
        }
    }

    /**
     * Tests dispatcher and multiple model
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testDispatcherMultiBinding(IntegrationTester $I)
    {
        $dispatcher = $this->createDispatcher();
        $this->assertDispatcher($dispatcher, $I);

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
            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue[0]);
            $I->assertInstanceOf('Phalcon\Test\Models\Robots', $returnedValue[1]);
            $I->assertEquals($this->people->cedula, $returnedValue[0]->cedula);
            $I->assertEquals($this->robot->id, $returnedValue[1]->id);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                    'robots' => 'Phalcon\\Test\\Models\\Robots',
                ],
                $this->cache->get('_PHMB_Test10Controller_multipleAction')
            );
        }
    }

    /**
     * Tests dispatcher and single model with interface
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testDispatcherSingleBindingWithInterface(IntegrationTester $I)
    {
        $dispatcher = $this->createDispatcher();
        $this->assertDispatcher($dispatcher, $I);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $this->returnDispatcherValueForAction(
                $dispatcher,
                'test11',
                'view',
                [
                    'people' => $this->people->cedula,
                ]
            );

            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue);
            $I->assertEquals($this->people->cedula, $returnedValue->cedula);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                ],
                $this->cache->get('_PHMB_Test11Controller_viewAction')
            );
        }
    }

    /**
     * Tests dispatcher and multi model with interface
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testDispatcherMultiBindingWithInterface(IntegrationTester $I)
    {
        $dispatcher = $this->createDispatcher();
        $this->assertDispatcher($dispatcher, $I);

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
            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue[0]);
            $I->assertInstanceOf('Phalcon\Test\Models\Robots', $returnedValue[1]);
            $I->assertEquals($this->people->cedula, $returnedValue[0]->cedula);
            $I->assertEquals($this->robot->id, $returnedValue[1]->id);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                    'robots' => 'Phalcon\\Test\\Models\\Robots',
                ],
                $this->cache->get('_PHMB_Test11Controller_multipleAction')
            );
        }
    }

    /**
     * Tests dispatcher and single binding exception
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testDispatcherSingleBindingException(IntegrationTester $I)
    {
        $dispatcher = $this->createDispatcher(false);
        $this->assertDispatcher($dispatcher, $I);
        $this->returnDispatcherValueForAction(
            $dispatcher,
            'test9',
            'view',
            ['people' => $this->people->cedula],
            false
        );

        try {
            $dispatcher->dispatch();

            $I->assertTrue(
                false,
                'Here must be the exception about passing non model to the controller action'
            );
        } catch (\Exception $e) {
            // PHP 5.x
            $I->assertEquals(
                'Argument 1 passed to Test9Controller::viewAction() must be an instance of Phalcon\Mvc\Model, string given',
                $e->getMessage()
            );
        } catch (\TypeError $e) {
            // PHP 7.x
            $I->assertEquals(
                'Argument 1 passed to Test9Controller::viewAction() must be an instance of Phalcon\Mvc\Model, string given',
                $e->getMessage()
            );
        }

        $dispatcher->setModelBinder($this->modelBinder);

        for ($i = 0; $i <= 1; $i++) {
            $dispatcher->dispatch();

            $returnedValue = $dispatcher->getReturnedValue();
            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue);
            $I->assertEquals($returnedValue->cedula, $this->people->cedula);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                ],
                $this->cache->get('_PHMB_Test9Controller_viewAction')
            );
        }
    }

    /**
     * Tests micro with handlers and model binder
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testMicroHandlerSingleBinding(IntegrationTester $I)
    {
        $micro = $this->createMicro($I);

        $micro->get(
            '/{people}',
            function (People $people) {
                return $people;
            }
        )->setName('people');

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/'.$this->people->cedula);

            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue);
            $I->assertEquals($this->people->cedula, $returnedValue->cedula);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                ],
                $this->cache->get('_PHMB_people')
            );
        }
    }

    /**
     * Tests micro with handler and multi binding
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testMicroHandlerMultiBinding(IntegrationTester $I)
    {
        $micro = $this->createMicro($I);
        $micro->get(
            '/{people}/robot/{robots}',
            function (People $people, Robots $robot) {
                return [$people, $robot];
            }
        );

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/'.$this->people->cedula.'/robot/'.$this->robot->id);

            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue[0]);
            $I->assertInstanceOf('Phalcon\Test\Models\Robots', $returnedValue[1]);
            $I->assertEquals($this->people->cedula, $returnedValue[0]->cedula);
            $I->assertEquals($this->robot->id, $returnedValue[1]->id);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                    'robots' => 'Phalcon\\Test\\Models\\Robots',
                ],
                $this->cache->get('_PHMB_/{people}/robot/{robots}')
            );
        }
    }

    /**
     * Tests micro with handler and single binding exception
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testMicroHandlerSingleBindingException(IntegrationTester $I)
    {
        $micro = $this->createMicro($I, false);
        $micro->get(
            '/{people}',
            function (People $people) {
                return $people;
            }
        );
        try {
            $micro->handle('/'.$this->people->cedula);

            $I->assertTrue(
                false,
                'Here must be the exception about passing non model to the micro handler'
            );
        } catch (\Exception $e) {
            // PHP 5.x
            $I->assertEquals(
                'Argument 1 passed to Phalcon\Test\Integration\Mvc\Model\BinderCest::Phalcon\Test\Integration\Mvc\Model\{closure}() must be an instance of Phalcon\Test\Models\People, string given',
                $e->getMessage()
            );
        } catch (\TypeError $e) {
            // PHP 7.x
            $I->assertEquals(
                'Argument 1 passed to Phalcon\Test\Integration\Mvc\Model\BinderCest::Phalcon\Test\Integration\Mvc\Model\{closure}() must be an instance of Phalcon\Test\Models\People, string given',
                $e->getMessage()
            );
        }

        $micro->setModelBinder($this->modelBinder);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/'.$this->people->cedula);

            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue);
            $I->assertEquals($this->people->cedula, $returnedValue->cedula);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                ],
                $this->cache->get('_PHMB_/{people}')
            );
        }
    }

    /**
     * Tests micro with controllers and model binder
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testMicroControllerSingleBinding(IntegrationTester $I)
    {
        $micro = $this->createMicro($I);

        $test10 = new Collection();
        $test10->setHandler(new \Test10Controller());
        $test10->get('/{people}', 'viewAction');
        $micro->mount($test10);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/'.$this->people->cedula);

            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue);
            $I->assertEquals($this->people->cedula, $returnedValue->cedula);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                ],
                $this->cache->get('_PHMB_Test10Controller_viewAction')
            );
        }
    }

    /**
     * Tests micro with controllers and model binder
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testMicroControllerMultiBinding(IntegrationTester $I)
    {
        $micro = $this->createMicro($I);

        $test10 = new Collection();
        $test10->setHandler(new \Test10Controller());
        $test10->get('/{people}/robot/{robots}', 'multipleAction');
        $micro->mount($test10);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/'.$this->people->cedula.'/robot/'.$this->robot->id);

            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue[0]);
            $I->assertInstanceOf('Phalcon\Test\Models\Robots', $returnedValue[1]);
            $I->assertEquals($this->people->cedula, $returnedValue[0]->cedula);
            $I->assertEquals($this->robot->id, $returnedValue[1]->id);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                    'robots' => 'Phalcon\\Test\\Models\\Robots',
                ],
                $this->cache->get('_PHMB_Test10Controller_multipleAction')
            );
        }
    }

    /**
     * Tests micro with controller and single binding using interface
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testMicroControllerSingleBindingWithInterface(IntegrationTester $I)
    {
        $micro = $this->createMicro($I);

        $test11 = new Collection();
        $test11->setHandler(new \Test11Controller());
        $test11->get('/{people}', 'viewAction');
        $micro->mount($test11);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/'.$this->people->cedula);
            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue);
            $I->assertEquals($this->people->cedula, $returnedValue->cedula);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                ],
                $this->cache->get('_PHMB_Test11Controller_viewAction')
            );
        }
    }

    /**
     * Tests micro with controller and multi binding using interface
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testMicroControllerMultiBindingWithInterface(IntegrationTester $I)
    {
        $micro = $this->createMicro($I);

        $test11 = new Collection();
        $test11->setHandler(new \Test11Controller());
        $test11->get('/{people}/robot/{robots}', 'multipleAction');
        $micro->mount($test11);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/'.$this->people->cedula.'/robot/'.$this->robot->id);

            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue[0]);
            $I->assertInstanceOf('Phalcon\Test\Models\Robots', $returnedValue[1]);
            $I->assertEquals($this->people->cedula, $returnedValue[0]->cedula);
            $I->assertEquals($this->robot->id, $returnedValue[1]->id);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                    'robots' => 'Phalcon\\Test\\Models\\Robots',
                ],
                $this->cache->get('_PHMB_Test11Controller_multipleAction')
            );
        }
    }

    /**
     * Tests micro with controller and single binding exception
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testMicroControllerSingleBindingException(IntegrationTester $I)
    {
        $micro = $this->createMicro($I, false);

        $test9 = new Collection();
        $test9->setHandler(new \Test9Controller());
        $test9->get('/{people}', 'viewAction');
        $micro->mount($test9);

        try {
            $micro->handle('/'.$this->people->cedula);

            $I->assertTrue(
                false,
                'Here must be the exception about passing non model to the micro handler'
            );
        } catch (\Exception $e) {
            // PHP 5.x
            $I->assertEquals(
                'Argument 1 passed to Test9Controller::viewAction() must be an instance of Phalcon\Mvc\Model, string given',
                $e->getMessage()
            );
        } catch (\TypeError $e) {
            // PHP 7.x
            $I->assertEquals(
                'Argument 1 passed to Test9Controller::viewAction() must be an instance of Phalcon\Mvc\Model, string given',
                $e->getMessage()
            );
        }

        $micro->setModelBinder($this->modelBinder);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/'.$this->people->cedula);

            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue);
            $I->assertEquals($this->people->cedula, $returnedValue->cedula);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                ],
                $this->cache->get('_PHMB_Test9Controller_viewAction')
            );
        }
    }

    /**
     * Tests micro with lazy controllers and model binder
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testMicroLazySingleBinding(IntegrationTester $I)
    {
        $micro = $this->createMicro($I);

        $test10 = new Collection();
        $test10->setHandler('Test10Controller', true);
        $test10->get('/{people}', 'viewAction');
        $micro->mount($test10);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/'.$this->people->cedula);

            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue);
            $I->assertEquals($this->people->cedula, $returnedValue->cedula);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                ],
                $this->cache->get('_PHMB_Test10Controller_viewAction')
            );
        }
    }

    /**
     * Tests micro with lazy controllers and model binder
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testMicroLazyMultiBinding(IntegrationTester $I)
    {
        $micro = $this->createMicro($I);

        $test10 = new Collection();
        $test10->setHandler('Test10Controller', true);
        $test10->get('/{people}/robot/{robots}', 'multipleAction');
        $micro->mount($test10);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/'.$this->people->cedula.'/robot/'.$this->robot->id);

            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue[0]);
            $I->assertInstanceOf('Phalcon\Test\Models\Robots', $returnedValue[1]);
            $I->assertEquals($this->people->cedula, $returnedValue[0]->cedula);
            $I->assertEquals($this->robot->id, $returnedValue[1]->id);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                    'robots' => 'Phalcon\\Test\\Models\\Robots',
                ],
                $this->cache->get('_PHMB_Test10Controller_multipleAction')
            );
        }
    }

    /**
     * Tests micro with lazy controllers and model binder
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testMicroLazySingleBindingWithInterface(IntegrationTester $I)
    {
        $micro = $this->createMicro($I);

        $test11 = new Collection();
        $test11->setHandler('Test11Controller', true);
        $test11->get('/{people}', 'viewAction');
        $micro->mount($test11);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/'.$this->people->cedula);

            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue);
            $I->assertEquals($this->people->cedula, $returnedValue->cedula);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                ],
                $this->cache->get('_PHMB_Test11Controller_viewAction')
            );
        }
    }

    /**
     * Tests micro with lazy controllers and model binder
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testMicroLazyMultiBindingWithInterface(IntegrationTester $I)
    {
        $micro = $this->createMicro($I);

        $test11 = new Collection();
        $test11->setHandler('Test11Controller', true);
        $test11->get('/{people}/robot/{robots}', 'multipleAction');
        $micro->mount($test11);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/'.$this->people->cedula.'/robot/'.$this->robot->id);

            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue[0]);
            $I->assertInstanceOf('Phalcon\Test\Models\Robots', $returnedValue[1]);
            $I->assertEquals($this->people->cedula, $returnedValue[0]->cedula);
            $I->assertEquals($this->robot->id, $returnedValue[1]->id);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                    'robots' => 'Phalcon\\Test\\Models\\Robots',
                ],
                $this->cache->get('_PHMB_Test11Controller_multipleAction')
            );
        }
    }

    /**
     * Tests micro with lazy controllers and model binder
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     *
     * @param IntegrationTester $I
     */
    public function testMicroLazySingleBindingException(IntegrationTester $I)
    {
        $micro = $this->createMicro($I, false);

        $test9 = new Collection();
        $test9->setHandler('Test9Controller', true);
        $test9->get('/{people}', 'viewAction');
        $micro->mount($test9);

        try {
            $micro->handle('/'.$this->people->cedula);

            $I->assertTrue(
                false,
                'Here must be the exception about passing non model to the micro handler'
            );
        } catch (\Exception $e) {
            // PHP 5.x
            $I->assertEquals(
                'Argument 1 passed to Test9Controller::viewAction() must be an instance of Phalcon\Mvc\Model, string given',
                $e->getMessage()
            );
        } catch (\TypeError $e) {
            // PHP 7.x
            $I->assertEquals(
                'Argument 1 passed to Test9Controller::viewAction() must be an instance of Phalcon\Mvc\Model, string given',
                $e->getMessage()
            );
        }

        $micro->setModelBinder($this->modelBinder);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $micro->handle('/'.$this->people->cedula);

            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue);
            $I->assertEquals($this->people->cedula, $returnedValue->cedula);
            $I->assertEquals(
                [
                    'people' => 'Phalcon\\Test\\Models\\People',
                ],
                $this->cache->get('_PHMB_Test9Controller_viewAction')
            );
        }
    }

    /**
     * Tests dispatcher and single model original values
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-19
     *
     * @param IntegrationTester $I
     */
    public function testDispatcherSingleBindingOriginalValues(IntegrationTester $I)
    {
        $dispatcher = $this->createDispatcher();
        $params = ['people' => $this->people->cedula];
        $this->assertDispatcher($dispatcher, $I);

        $returnedValue = $this->returnDispatcherValueForAction(
            $dispatcher,
            'test10',
            'view',
            $params
        );
        $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue);
        $I->assertEquals($this->people->cedula, $returnedValue->cedula);
        $I->assertEquals($params, $dispatcher->getModelBinder()->getOriginalValues());
    }

    /**
     * Tests dispatcher and single model without cache
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-24
     *
     * @param IntegrationTester $I
     */
    public function testDispatcherSingleBindingNoCache(IntegrationTester $I)
    {
        $dispatcher = $this->createDispatcher(false);
        $modelBinder = new Binder();
        $dispatcher->setModelBinder($modelBinder);
        $this->assertDispatcher($dispatcher, $I);

        for ($i = 0; $i <= 1; $i++) {
            $returnedValue = $this->returnDispatcherValueForAction(
                $dispatcher,
                'test10',
                'view',
                ['people' => $this->people->cedula]
            );
            $I->assertInstanceOf('Phalcon\Test\Models\People', $returnedValue);
            $I->assertEquals($this->people->cedula, $returnedValue->cedula);
        }
    }

    /**
     * @param bool $useModelBinder
     * @return Dispatcher
     */
    private function createDispatcher($useModelBinder = true)
    {
        $this->cache->flush();
        $dispatcher = new Dispatcher;
        if ($useModelBinder) {
            $dispatcher->setModelBinder($this->modelBinder);
        }
        $dispatcher->setDI(Di::getDefault());

        return $dispatcher;
    }

    /**
     * @param $dispatcher
     * @param IntegrationTester $I
     */
    private function assertDispatcher($dispatcher, IntegrationTester $I)
    {
        $I->assertInstanceOf('Phalcon\Di', $dispatcher->getDI());
        $I->haveServiceInDi('dispatcher', $dispatcher);
    }

    /**
     * @param Dispatcher $dispatcher
     * @param $controllerName
     * @param $actionName
     * @param $params
     * @param bool $returnValue
     * @return mixed
     */
    private function returnDispatcherValueForAction(
        Dispatcher $dispatcher,
        $controllerName,
        $actionName,
        $params,
        $returnValue = true
    ) {
        $dispatcher->setReturnedValue(null);
        $dispatcher->setControllerName($controllerName);
        $dispatcher->setActionName($actionName);
        $dispatcher->setParams($params);

        if ($returnValue) {
            $dispatcher->dispatch();

            return $dispatcher->getReturnedValue();
        }

        return null;
    }

    /**
     * @param IntegrationTester $I
     * @param bool $useModelBinder
     * @return Micro
     */
    private function createMicro(IntegrationTester $I, $useModelBinder = true)
    {
        $this->cache->flush();
        $micro = new Micro(Di::getDefault());

        if ($useModelBinder) {
            $micro->setModelBinder($this->modelBinder);
        }

        $I->assertInstanceOf('Phalcon\Di', $micro->getDI());

        return $micro;
    }
}
