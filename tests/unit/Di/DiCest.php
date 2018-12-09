<?php
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use Phalcon\Di\Exception;
use Phalcon\Di\Service;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use UnitTester;
use function dataFolder;

/**
 * Phalcon\Test\Unit\DiTest
 *
 * Tests the \Phalcon\Di component
 *
 * @package   Phalcon\Test\Unit
 */
class DiCest
{
    /**
     * @var \Phalcon\DiInterface
     */
    protected $phDi;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        require_once dataFolder('fixtures/Di/InjectableComponent.php');
        require_once dataFolder('fixtures/Di/SomeServiceProvider.php');
        require_once dataFolder('fixtures/Di/SimpleComponent.php');
        require_once dataFolder('fixtures/Di/SomeComponent.php');

        Di::reset();
        $this->phDi = new Di();
    }

    /**
     * Tests registering a service via string
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testSetString(UnitTester $I)
    {
        $this->phDi->set('request1', 'Phalcon\Http\Request');
        $I->assertEquals(get_class($this->phDi->get('request1')), 'Phalcon\Http\Request');
    }

    /**
     * Tests registering a service via anonymous function
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testSetAnonymousFunction(UnitTester $I)
    {
        $this->phDi->set('request2', function () {
            return new Request();
        });
        $I->assertEquals(get_class($this->phDi->get('request2')), 'Phalcon\Http\Request');
    }

    /**
     * Tests registering a service via array
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testSetArray(UnitTester $I)
    {
        $this->phDi->set('request3', [
            'className' => 'Phalcon\Http\Request',
        ]);
        $I->assertEquals(get_class($this->phDi->get('request3')), 'Phalcon\Http\Request');
    }

    /**
     * Tests registering a service in the services container via Di::attempt
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testAttempt(UnitTester $I)
    {
        $this->phDi->set('request4', function () {
            return new Request();
        });

        $this->phDi->attempt('request4', function () {
            return new \stdClass();
        });

        $this->phDi->attempt('request5', function () {
            return new \stdClass();
        });

        $I->assertEquals(get_class($this->phDi->get('request4')), 'Phalcon\Http\Request');
        $I->assertEquals(get_class($this->phDi->get('request5')), 'stdClass');
    }

    /**
     * Tests check a service in the services container via Di::has
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testHas(UnitTester $I)
    {
        $this->phDi->set('request6', function () {
            return new Request();
        });

        $I->assertTrue($this->phDi->has('request6'));
        $I->assertFalse($this->phDi->has('request7'));
    }

    /**
     * Tests resolving shared service
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testGetShared(UnitTester $I)
    {
        $this->phDi->set('dateObject', function () {
            $object       = new \stdClass();
            $object->date = microtime(true);
            return $object;
        });

        $dateObject = $this->phDi->getShared('dateObject');
        usleep(5000);
        $dateObject2 = $this->phDi->getShared('dateObject');

        $I->assertEquals($dateObject, $dateObject2);
        $I->assertEquals($dateObject->date, $dateObject2->date);
    }

    /**
     * Tests resolving service via magic __get
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testMagicGetCall(UnitTester $I)
    {
        $this->phDi->set('request8', 'Phalcon\Http\Request');
        $I->assertEquals(get_class($this->phDi->getRequest8()), 'Phalcon\Http\Request');
    }

    /**
     * Tests registering a service via magic __set
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testMagicSetCall(UnitTester $I)
    {
        $this->phDi->setRequest9('Phalcon\Http\Request');
        $I->assertEquals(get_class($this->phDi->get('request9')), 'Phalcon\Http\Request');
    }

    /**
     * Tests registering a service with parameters
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testSetParameters(UnitTester $I)
    {
        $this->phDi->set('someComponent1', function ($v) {
            return new \SomeComponent($v);
        });

        $this->phDi->set('someComponent2', 'SomeComponent');

        $someComponent1 = $this->phDi->get('someComponent1', [100]);
        $I->assertEquals($someComponent1->someProperty, 100);

        $someComponent2 = $this->phDi->get('someComponent2', [500]);
        $I->assertEquals($someComponent2->someProperty, 500);
    }

    /**
     * Tests getting services
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testGetServices(UnitTester $I)
    {
        $expectedServices = [
            'service1' => Service::__set_state([
                '_definition'     => 'some-service',
                '_shared'         => false,
                '_sharedInstance' => null,
            ]),
            'service2' => Service::__set_state([
                '_definition'     => 'some-other-service',
                '_shared'         => false,
                '_sharedInstance' => null,
            ]),
        ];

        $this->phDi->set('service1', 'some-service');
        $this->phDi->set('service2', 'some-other-service');

        $I->assertEquals($this->phDi->getServices(), $expectedServices);
    }

    /**
     * Tests getting raw services
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testGetRawService(UnitTester $I)
    {
        $this->phDi->set('service1', 'some-service');
        $I->assertEquals($this->phDi->getRaw('service1'), 'some-service');
    }

    /**
     * Tests registering a services via array access
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testRegisteringViaArrayAccess(UnitTester $I)
    {
        $this->phDi['simple'] = 'SimpleComponent';
        $I->assertEquals(get_class($this->phDi->get('simple')), 'SimpleComponent');
    }

    /**
     * Tests resolving a services via array access
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testResolvingViaArrayAccess(UnitTester $I)
    {
        $this->phDi->set('simple', 'SimpleComponent');
        $I->assertEquals(get_class($this->phDi['simple']), 'SimpleComponent');
    }

    /**
     * Tests getting non-existent service
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testGettingNonExistentService(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception("Service 'nonExistentService' wasn't found in the dependency injection container"),
            function () {
                $this->phDi->get('nonExistentService');
            }
        );
    }

    /**
     * Tests the latest DI created
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testGettingDiViaGetDefault(UnitTester $I)
    {
        $I->assertInstanceOf(Di::class, Di::getDefault());
        $I->assertEquals(Di::getDefault(), $this->phDi);
    }

    /**
     * Tests resolving a services via array access
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testComplexInjection(UnitTester $I)
    {
        $response = new Response();
        $this->phDi->set('response', $response);

        // Injection of parameters in the constructor
        $this->phDi->set(
            'simpleConstructor',
            [
                'className' => 'InjectableComponent',
                'arguments' => [
                    [
                        'type'  => 'parameter',
                        'value' => 'response',
                    ],
                ],
            ]
        );

        // Injection of simple setters
        $this->phDi->set(
            'simpleSetters',
            [
                'className' => 'InjectableComponent',
                'calls'     => [
                    [
                        'method'    => 'setResponse',
                        'arguments' => [
                            [
                                'type'  => 'parameter',
                                'value' => 'response',
                            ],
                        ],
                    ],
                ],
            ]
        );

        // Injection of properties
        $this->phDi->set(
            'simpleProperties',
            [
                'className'  => 'InjectableComponent',
                'properties' => [
                    [
                        'name'  => 'response',
                        'value' => [
                            'type'  => 'parameter',
                            'value' => 'response',
                        ],
                    ],
                ],
            ]
        );

        // Injection of parameters in the constructor resolving the service parameter
        $this->phDi->set(
            'complexConstructor',
            [
                'className' => 'InjectableComponent',
                'arguments' => [
                    [
                        'type' => 'service',
                        'name' => 'response',
                    ],
                ],
            ]
        );

        // Injection of simple setters resolving the service parameter
        $this->phDi->set(
            'complexSetters',
            [
                'className' => 'InjectableComponent',
                'calls'     => [
                    [
                        'method'    => 'setResponse',
                        'arguments' => [
                            [
                                'type' => 'service',
                                'name' => 'response',
                            ],
                        ],
                    ],
                ],
            ]
        );

        // Injection of properties resolving the service parameter
        $this->phDi->set(
            'complexProperties',
            [
                'className'  => 'InjectableComponent',
                'properties' => [
                    [
                        'name'  => 'response',
                        'value' => [
                            'type' => 'service',
                            'name' => 'response',
                        ],
                    ],
                ],
            ]
        );

        $component = $this->phDi->get('simpleConstructor');
        $I->assertTrue(is_string($component->getResponse()));
        $I->assertEquals($component->getResponse(), 'response');

        $component = $this->phDi->get('simpleSetters');
        $I->assertTrue(is_string($component->getResponse()));
        $I->assertEquals($component->getResponse(), 'response');

        $component = $this->phDi->get('simpleProperties');
        $I->assertTrue(is_string($component->getResponse()));
        $I->assertEquals($component->getResponse(), 'response');

        $component = $this->phDi->get('complexConstructor');
        $I->assertTrue(is_object($component->getResponse()));
        $I->assertEquals($component->getResponse(), $response);

        $component = $this->phDi->get('complexSetters');
        $I->assertTrue(is_object($component->getResponse()));
        $I->assertEquals($component->getResponse(), $response);

        $component = $this->phDi->get('complexProperties');
        $I->assertTrue(is_object($component->getResponse()));
        $I->assertEquals($component->getResponse(), $response);
    }

    /**
     * Register services using provider.
     *
     * @author Caio Almeida <caio.f.r.amd@gmail.com>
     * @since  2017-04-11
     */
    public function testRegistersServiceProvider(UnitTester $I)
    {
        $this->phDi->register(new \SomeServiceProvider());
        $I->assertEquals($this->phDi['foo'], 'bar');

        $service = $this->phDi->get('fooAction');
        $I->assertInstanceOf('\SomeComponent', $service);
    }

    /**
     * Tests loading services from yaml files.
     *
     * @author Gorka Guridi <gorka.guridi@gmail.com>
     * @since  2017-04-12
     */
    public function testYamlLoader(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('yaml');

        $this->phDi->loadFromYaml(dataFolder('fixtures/Di/services.yml'));

        $I->assertTrue($this->phDi->has('unit-test'));
        $I->assertFalse($this->phDi->getService('unit-test')->isShared());
        $I->assertTrue($this->phDi->has('config'));
        $I->assertTrue($this->phDi->getService('config')->isShared());
        $I->assertTrue($this->phDi->has('component'));
        $I->assertFalse($this->phDi->getService('component')->isShared());
        $I->assertInstanceOf('Phalcon\Config', $this->phDi->get('component')->someProperty);
    }

    /**
     * Tests loading services from php files.
     *
     * @author Gorka Guridi <gorka.guridi@gmail.com>
     * @since  2017-04-12
     */
    public function testPhpLoader(UnitTester $I)
    {
        $this->phDi->loadFromPhp(dataFolder('fixtures/Di/services.php'));

        $I->assertTrue($this->phDi->has('unit-test'));
        $I->assertFalse($this->phDi->getService('unit-test')->isShared());
        $I->assertTrue($this->phDi->has('config'));
        $I->assertTrue($this->phDi->getService('config')->isShared());
        $I->assertTrue($this->phDi->has('component'));
        $I->assertFalse($this->phDi->getService('component')->isShared());
        $I->assertInstanceOf('Phalcon\Config', $this->phDi->get('component')->someProperty);
    }
}
