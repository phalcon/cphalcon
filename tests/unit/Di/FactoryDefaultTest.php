<?php

namespace Phalcon\Test\Unit\Di;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Proxy\Di\FactoryDefault;

/**
 * \Phalcon\Test\Unit\Di\FactoryDefaultTest
 * Tests the \Phalcon\Di\FactoryDefault component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Di
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FactoryDefaultTest extends UnitTest
{
    /**
     * Tests FactoryDefault
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testFactoryDefault()
    {
        $this->specify(
            "FactoryDefault does not contains the expected services",
            function ($name, $class) {
                $params = null;
                $factoryDefault = new FactoryDefault();

                if ('sessionBag' === $name) {
                    $params = ['someName'];
                }

                expect(get_class($factoryDefault->get($name, $params)))->equals($class);
            },
            ['examples' => [
                ['router', 'Phalcon\Mvc\Router'],
                ['dispatcher', 'Phalcon\Mvc\Dispatcher'],
                ['url', 'Phalcon\Mvc\Url'],
                ['modelsManager', 'Phalcon\Mvc\Model\Manager'],
                ['modelsMetadata', 'Phalcon\Mvc\Model\MetaData\Memory'],
                ['response', 'Phalcon\Http\Response'],
                ['cookies', 'Phalcon\Http\Response\Cookies'],
                ['request', 'Phalcon\Http\Request'],
                ['filter', 'Phalcon\Filter'],
                ['escaper', 'Phalcon\Escaper'],
                ['security', 'Phalcon\Security'],
                ['crypt', 'Phalcon\Crypt'],
                ['annotations', 'Phalcon\Annotations\Adapter\Memory'],
                ['flash', 'Phalcon\Flash\Direct'],
                ['flashSession', 'Phalcon\Flash\Session'],
                ['tag', 'Phalcon\Tag'],
                ['session', 'Phalcon\Session\Adapter\Files'],
                ['sessionBag', 'Phalcon\Session\Bag'],
                ['eventsManager', 'Phalcon\Events\Manager'],
                ['transactionManager', 'Phalcon\Mvc\Model\Transaction\Manager'],
                ['assets', 'Phalcon\Assets\Manager'],
            ]]
        );
    }

    public function testInject15Services()
    {
        require_once __DIR__ . DIRECTORY_SEPARATOR . '../../_data/di/ManyServices.php';
        
        $this->specify(
            "FactoryDefault can injext 15 services to another service",
            function () {
                $params = null;
                $factoryDefault = new FactoryDefault();

                $factoryDefault->setShared('AService', [
                    'className' => 'AService',
                ]);

                $factoryDefault->setShared('BService', [
                    'className' => 'BService',
                ]);

                $factoryDefault->setShared('CService', [
                    'className' => 'CService',
                ]);

                $factoryDefault->setShared('DService', [
                    'className' => 'DService',
                ]);

                $factoryDefault->setShared('EService', [
                    'className' => 'EService',
                ]);

                $factoryDefault->setShared('FService', [
                    'className' => 'FService',
                ]);

                $factoryDefault->setShared('GService', [
                    'className' => 'GService',
                ]);

                $factoryDefault->setShared('HService', [
                    'className' => 'HService',
                ]);

                $factoryDefault->setShared('IService', [
                    'className' => 'IService',
                ]);

                $factoryDefault->setShared('JService', [
                    'className' => 'JService',
                ]);

                $factoryDefault->setShared('KService', [
                    'className' => 'KService',
                ]);

                $factoryDefault->setShared('LService', [
                    'className' => 'LService',
                ]);

                $factoryDefault->setShared('MService', [
                    'className' => 'MService',
                ]);

                $factoryDefault->setShared('NService', [
                    'className' => 'NService',
                ]);

                $factoryDefault->setShared('OService', [
                    'className' => 'OService',
                ]);
                
                $factoryDefault->setShared('ExampleService', [
                    'className' => 'ExampleService',
                    'arguments' => [
                        [
                            'type' => 'service',
                            'name' => 'AService',
                        ],
                        [
                            'type' => 'service',
                            'name' => 'BService',
                        ],
                        [
                            'type' => 'service',
                            'name' => 'CService',
                        ],
                        [
                            'type' => 'service',
                            'name' => 'DService',
                        ],
                        [
                            'type' => 'service',
                            'name' => 'EService',
                        ],
                        [
                            'type' => 'service',
                            'name' => 'FService',
                        ],
                        [
                            'type' => 'service',
                            'name' => 'GService',
                        ],
                        [
                            'type' => 'service',
                            'name' => 'HService',
                        ],
                        [
                            'type' => 'service',
                            'name' => 'IService',
                        ],
                        [
                            'type' => 'service',
                            'name' => 'JService',
                        ],
                        [
                            'type' => 'service',
                            'name' => 'KService',
                        ],
                        [
                            'type' => 'service',
                            'name' => 'LService',
                        ],
                        [
                            'type' => 'service',
                            'name' => 'MService',
                        ],
                        [
                            'type' => 'service',
                            'name' => 'NService',
                        ],
                        [
                            'type' => 'service',
                            'name' => 'OService',
                        ]
                    ]
                ]);

                expect($factoryDefault->get('ExampleService')->get())->isInstanceOf('ExampleService');
            }
        );
    }
}
