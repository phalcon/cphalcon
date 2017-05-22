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

namespace Phalcon\Test\Unit;

use Phalcon\Di;
use Phalcon\Di\Service;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Test\Module\UnitTest;

/**
 * Phalcon\Test\Unit\DiTest
 *
 * Tests the \Phalcon\Di component
 *
 * @package   Phalcon\Test\Unit
 */
class DiTest extends UnitTest
{
    /**
     * @var \Phalcon\DiInterface
     */
    protected $phDi;

    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        require_once PATH_DATA . 'di/InjectableComponent.php';
        require_once PATH_DATA . 'di/SomeServiceProvider.php';
        require_once PATH_DATA . 'di/SimpleComponent.php';
        require_once PATH_DATA . 'di/SomeComponent.php';

        Di::reset();
        $this->phDi = new Di();
    }

    /**
     * Tests registering a service via string
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testSetString()
    {
        $this->specify(
            "Registering a service via string does now work correctly",
            function () {
                $this->phDi->set('request1', 'Phalcon\Http\Request');
                expect(get_class($this->phDi->get('request1')))->equals('Phalcon\Http\Request');
            }
        );
    }

    /**
     * Tests registering a service via anonymous function
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testSetAnonymousFunction()
    {
        $this->specify(
            "Registering a service via anonymous function does now work correctly",
            function () {
                $this->phDi->set('request2', function () {
                    return new Request();
                });
                expect(get_class($this->phDi->get('request2')))->equals('Phalcon\Http\Request');
            }
        );
    }

    /**
     * Tests registering a service via array
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testSetArray()
    {
        $this->specify(
            "Registering a service via array does now work correctly",
            function () {
                $this->phDi->set('request3', [
                    'className' => 'Phalcon\Http\Request'
                ]);
                expect(get_class($this->phDi->get('request3')))->equals('Phalcon\Http\Request');
            }
        );
    }

    /**
     * Tests registering a service in the services container via Di::attempt
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testAttempt()
    {
        $this->specify(
            "Registering a service in the services container via Di::attempt does now work correctly",
            function () {
                $this->phDi->set('request4', function () {
                    return new Request();
                });

                $this->phDi->attempt('request4', function () {
                    return new \stdClass();
                });

                $this->phDi->attempt('request5', function () {
                    return new \stdClass();
                });

                expect(get_class($this->phDi->get('request4')))->equals('Phalcon\Http\Request');
                expect(get_class($this->phDi->get('request5')))->equals('stdClass');
            }
        );
    }

    /**
     * Tests check a service in the services container via Di::has
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testHas()
    {
        $this->specify(
            "Check a service in the services container via Di::attempt does now work correctly",
            function () {
                $this->phDi->set('request6', function () {
                    return new Request();
                });

                expect($this->phDi->has('request6'))->true();
                expect($this->phDi->has('request7'))->false();
            }
        );
    }

    /**
     * Tests resolving shared service
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testGetShared()
    {
        $this->specify(
            "Resolving shared service does now work correctly",
            function () {
                $this->phDi->set('dateObject', function () {
                    $object = new \stdClass();
                    $object->date = microtime(true);
                    return $object;
                });

                $dateObject = $this->phDi->getShared('dateObject');
                usleep(5000);
                $dateObject2 = $this->phDi->getShared('dateObject');

                expect($dateObject)->equals($dateObject2);
                expect($dateObject->date)->equals($dateObject2->date);
            }
        );
    }

    /**
     * Tests resolving service via magic __get
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testMagicGetCall()
    {
        $this->specify(
            "Resolving service via magic __get does now work correctly",
            function () {
                $this->phDi->set('request8', 'Phalcon\Http\Request');
                expect(get_class($this->phDi->getRequest8()))->equals('Phalcon\Http\Request');
            }
        );
    }

    /**
     * Tests registering a service via magic __set
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testMagicSetCall()
    {
        $this->specify(
            "Registering a service via magic __set does now work correctly",
            function () {
                $this->phDi->setRequest9('Phalcon\Http\Request');
                expect(get_class($this->phDi->get('request9')))->equals('Phalcon\Http\Request');
            }
        );
    }

    /**
     * Tests registering a service with parameters
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testSetParameters()
    {
        $this->specify(
            "Registering a service with parameters does now work correctly",
            function () {
                $this->phDi->set('someComponent1', function ($v) {
                    return new \SomeComponent($v);
                });

                $this->phDi->set('someComponent2', 'SomeComponent');

                $someComponent1 = $this->phDi->get('someComponent1', [100]);
                expect($someComponent1->someProperty)->equals(100);

                $someComponent2 = $this->phDi->get('someComponent2', [500]);
                expect($someComponent2->someProperty)->equals(500);
            }
        );
    }

    /**
     * Tests getting services
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testGetServices()
    {
        $this->specify(
            "Getting services does now work correctly",
            function () {
                $expectedServices = [
                    'service1' => Service::__set_state([
                        '_name'           => 'service1',
                        '_definition'     => 'some-service',
                        '_shared'         => false,
                        '_sharedInstance' => null,
                    ]),
                    'service2' => Service::__set_state([
                        '_name'           => 'service2',
                        '_definition'     => 'some-other-service',
                        '_shared'         => false,
                        '_sharedInstance' => null,
                    ])
                ];

                $this->phDi->set('service1', 'some-service');
                $this->phDi->set('service2', 'some-other-service');

                expect($this->phDi->getServices())->equals($expectedServices);
            }
        );
    }

    /**
     * Tests getting raw services
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testGetRawService()
    {
        $this->specify(
            "Getting raw services does now work correctly",
            function () {
                $this->phDi->set('service1', 'some-service');
                expect($this->phDi->getRaw('service1'))->equals('some-service');
            }
        );
    }

    /**
     * Tests registering a services via array access
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testRegisteringViaArrayAccess()
    {
        $this->specify(
            "Registering a services via array access does now work correctly",
            function () {
                $this->phDi['simple'] = 'SimpleComponent';
                expect(get_class($this->phDi->get('simple')))->equals('SimpleComponent');
            }
        );
    }

    /**
     * Tests resolving a services via array access
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testResolvingViaArrayAccess()
    {
        $this->specify(
            "Resolving a services via array access does now work correctly",
            function () {
                $this->phDi->set('simple', 'SimpleComponent');
                expect(get_class($this->phDi['simple']))->equals('SimpleComponent');
            }
        );
    }

    /**
     * Tests getting non-existent service
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testGettingNonExistentService()
    {
        $this->specify(
            "Getting non-existent service does not throws exception with expected message",
            function () {
                $this->phDi->get('nonExistentService');
            },
            [
                'throws' => [
                    'Phalcon\Di\Exception',
                    "Service 'nonExistentService' wasn't found in the dependency injection container"
                ]
            ]
        );
    }

    /**
     * Tests the latest DI created
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testGettingDiViaGetDefault()
    {
        $this->specify(
            "Di::getDefault does not return the latest DI created",
            function () {
                expect(Di::getDefault())->isInstanceOf('Phalcon\Di');
                expect(Di::getDefault())->equals($this->phDi);
            }
        );
    }

    /**
     * Tests resolving a services via array access
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testComplexInjection()
    {
        $this->specify(
            "Resolving a services via array access does now work correctly",
            function () {
                $response = new Response();
                $this->phDi->set('response', $response);

                // Injection of parameters in the constructor
                $this->phDi->set(
                    'simpleConstructor',
                    [
                        'className' => 'InjectableComponent',
                        'arguments' => [
                            [
                                'type' => 'parameter',
                                'value' => 'response'
                            ],
                        ]
                    ]
                );

                // Injection of simple setters
                $this->phDi->set(
                    'simpleSetters',
                    [
                        'className' => 'InjectableComponent',
                        'calls' => [
                            [
                                'method' => 'setResponse',
                                'arguments' => [
                                    [
                                        'type' => 'parameter',
                                        'value' => 'response'
                                    ],
                                ]
                            ],
                        ]
                    ]
                );

                // Injection of properties
                $this->phDi->set(
                    'simpleProperties',
                    [
                        'className' => 'InjectableComponent',
                        'properties' => [
                            [
                                'name' => 'response',
                                'value' => [
                                    'type' => 'parameter',
                                    'value' => 'response'
                                ]
                            ],
                        ]
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
                                'name' => 'response'
                            ]
                        ]
                    ]
                );

                // Injection of simple setters resolving the service parameter
                $this->phDi->set(
                    'complexSetters',
                    [
                        'className' => 'InjectableComponent',
                        'calls' => [
                            [
                                'method' => 'setResponse',
                                'arguments' => [
                                    [
                                        'type' => 'service',
                                        'name' => 'response',
                                    ]
                                ]
                            ],
                        ]
                    ]
                );

                // Injection of properties resolving the service parameter
                $this->phDi->set(
                    'complexProperties',
                    [
                        'className' => 'InjectableComponent',
                        'properties' => [
                            [
                                'name' => 'response',
                                'value' => [
                                    'type' => 'service',
                                    'name' => 'response',
                                ]
                            ],
                        ]
                    ]
                );

                $component = $this->phDi->get('simpleConstructor');
                expect(is_string($component->getResponse()))->true();
                expect($component->getResponse())->equals('response');

                $component = $this->phDi->get('simpleSetters');
                expect(is_string($component->getResponse()))->true();
                expect($component->getResponse())->equals('response');

                $component = $this->phDi->get('simpleProperties');
                expect(is_string($component->getResponse()))->true();
                expect($component->getResponse())->equals('response');

                $component = $this->phDi->get('complexConstructor');
                expect(is_object($component->getResponse()))->true();
                expect($component->getResponse())->equals($response);

                $component = $this->phDi->get('complexSetters');
                expect(is_object($component->getResponse()))->true();
                expect($component->getResponse())->equals($response);

                $component = $this->phDi->get('complexProperties');
                expect(is_object($component->getResponse()))->true();
                expect($component->getResponse())->equals($response);
            }
        );
    }

    /**
     * Register services using provider.
     *
     * @author Caio Almeida <caio.f.r.amd@gmail.com>
     * @since  2017-04-11
     */
    public function testRegistersServiceProvider()
    {
        $this->specify(
            'Registering services by using service provider does not work as expected',
            function () {
                $this->phDi->register(new \SomeServiceProvider());
                expect($this->phDi['foo'])->equals('bar');

                $service = $this->phDi->get('fooAction');
                expect($service)->isInstanceOf('\SomeComponent');
            }
        );
    }

    /**
     * Tests loading services from yaml files.
     *
     * @author Gorka Guridi <gorka.guridi@gmail.com>
     * @since  2017-04-12
     */
    public function testYamlLoader()
    {
        if (!extension_loaded('yaml')) {
            $this->markTestSkipped('Warning: yaml extension is not loaded');
        }

        $this->specify(
            '"Di does not load services from yaml files properly',
            function () {
                $this->phDi->loadFromYaml(PATH_DATA . 'di/services.yml');

                expect($this->phDi->has('unit-test'))->true();
                expect($this->phDi->getService('unit-test')->isShared())->false();
                expect($this->phDi->has('config'))->true();
                expect($this->phDi->getService('config')->isShared())->true();
                expect($this->phDi->has('component'))->true();
                expect($this->phDi->getService('component')->isShared())->false();
                expect($this->phDi->get('component')->someProperty)->isInstanceOf('Phalcon\Config');
            }
        );
    }

    /**
     * Tests loading services from php files.
     *
     * @author Gorka Guridi <gorka.guridi@gmail.com>
     * @since  2017-04-12
     */
    public function testPhpLoader()
    {
        $this->specify(
            'Di does not load services from php files properly',
            function () {
                $this->phDi->loadFromPhp(PATH_DATA . 'di/services.php');

                expect($this->phDi->has('unit-test'))->true();
                expect($this->phDi->getService('unit-test')->isShared())->false();
                expect($this->phDi->has('config'))->true();
                expect($this->phDi->getService('config')->isShared())->true();
                expect($this->phDi->has('component'))->true();
                expect($this->phDi->getService('component')->isShared())->false();
                expect($this->phDi->get('component')->someProperty)->isInstanceOf('Phalcon\Config');
            }
        );
    }
}
