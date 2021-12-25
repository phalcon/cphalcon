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

namespace Phalcon\Tests\Unit\Di\Service\Builder;

use Phalcon\Di\Di;
use Phalcon\Di\Exception;
use Phalcon\Di\Service\Builder;
use Phalcon\Html\Escaper;
use Phalcon\Tests\Fixtures\Di\PropertiesComponent;
use Phalcon\Tests\Fixtures\Di\ServiceComponent;
use UnitTester;

/**
 * Class BuildCest
 *
 * @package Phalcon\Tests\Unit\Di\Service\Builder
 */
class BuildCest
{
    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - exception className
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildExceptionClassName(UnitTester $I)
    {
        $I->wantToTest('Di\Service\Builder - build() - exception className');

        $I->expectThrowable(
            new Exception(
                "Invalid service definition. Missing 'className' parameter"
            ),
            function () {
                $container = new Di();
                $builder   = new Builder();

                $builder->build($container, []);
            }
        );
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - exception argument
     * type
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildExceptionArgumentType(UnitTester $I)
    {
        $I->wantToTest('Di\Service\Builder - build() - exception argument type');

        $I->expectThrowable(
            new Exception(
                'Argument at position 0 must have a type'
            ),
            function () {
                $container  = new Di();
                $builder    = new Builder();
                $definition = [
                    'className' => Escaper::class,
                    'arguments' => [
                        0 => ['one'],
                    ],
                ];

                $builder->build($container, $definition);
            }
        );
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - exception unknown
     * service type
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildExceptionUknownServiceType(UnitTester $I)
    {
        $I->wantToTest('Di\Service\Builder - build() - exception unknown service type');

        $I->expectThrowable(
            new Exception(
                'Unknown service type in parameter on position 0'
            ),
            function () {
                $container  = new Di();
                $builder    = new Builder();
                $definition = [
                    'className' => Escaper::class,
                    'arguments' => [
                        0 => [
                            'type'  => 'unknown',
                            'value' => 'one',
                        ],
                    ],
                ];

                $builder->build($container, $definition);
            }
        );
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - passed parameters
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildPassedParameters(UnitTester $I)
    {
        $I->wantToTest('Di\Service\Builder - build() - passed parameters');

        $container  = new Di();
        $builder    = new Builder();
        $definition = [
            'className' => PropertiesComponent::class,
            'arguments' => [
                [
                    'type'  => 'parameter',
                    'value' => 'one',
                ],
                [
                    'type'  => 'parameter',
                    'value' => 2,
                ],
            ],
        ];

        $class     = PropertiesComponent::class;
        $component = $builder->build($container, $definition);
        $I->assertInstanceOf($class, $component);

        $expected = 'one';
        $actual   = $component->getName();
        $I->assertEquals($expected, $actual);

        $expected = 2;
        $actual   = $component->getType();
        $I->assertEquals($expected, $actual);

        $actual = $component->getEscaper();
        $I->assertNull($actual);

        $actual = $component->getService();
        $I->assertNull($actual);
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - passed parameters
     * with instance
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildPassedParametersWithInstance(UnitTester $I)
    {
        $I->wantToTest('Di\Service\Builder - build() - passed parameters with instance');

        $container  = new Di();
        $builder    = new Builder();
        $definition = [
            'className' => PropertiesComponent::class,
            'arguments' => [
                [
                    'type'  => 'parameter',
                    'value' => 'one',
                ],
                [
                    'type'  => 'parameter',
                    'value' => 2,
                ],
                [
                    'type'      => 'instance',
                    'className' => Escaper::class,
                ],
            ],
        ];

        $class     = PropertiesComponent::class;
        $component = $builder->build($container, $definition);
        $I->assertInstanceOf($class, $component);

        $expected = 'one';
        $actual   = $component->getName();
        $I->assertEquals($expected, $actual);

        $expected = 2;
        $actual   = $component->getType();
        $I->assertEquals($expected, $actual);

        $class  = Escaper::class;
        $actual = $component->getEscaper();
        $I->assertInstanceOf($class, $actual);

        $actual = $component->getService();
        $I->assertNull($actual);
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - passed parameters
     * with instance and service
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildPassedParametersWithInstanceAndService(UnitTester $I)
    {
        $I->wantToTest(
            'Di\Service\Builder - build() - passed parameters with instance and service'
        );

        $container = new Di();
        $builder   = new Builder();
        $service   = new ServiceComponent('two', 3);
        $container->set('newService', $service, true);

        $definition = [
            'className' => PropertiesComponent::class,
            'arguments' => [
                [
                    'type'  => 'parameter',
                    'value' => 'one',
                ],
                [
                    'type'  => 'parameter',
                    'value' => 2,
                ],
                [
                    'type'      => 'instance',
                    'className' => Escaper::class,
                ],
                [
                    'type' => 'service',
                    'name' => 'newService',
                ],
            ],
        ];

        $class     = PropertiesComponent::class;
        $component = $builder->build($container, $definition);
        $I->assertInstanceOf($class, $component);

        $expected = 'one';
        $actual   = $component->getName();
        $I->assertEquals($expected, $actual);

        $expected = 2;
        $actual   = $component->getType();
        $I->assertEquals($expected, $actual);

        $class  = Escaper::class;
        $actual = $component->getEscaper();
        $I->assertInstanceOf($class, $actual);

        $class   = ServiceComponent::class;
        $service = $component->getService();
        $I->assertInstanceOf($class, $service);

        $expected = 'two';
        $actual   = $service->getName();
        $I->assertEquals($expected, $actual);

        $expected = 3;
        $actual   = $service->getType();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - instance with
     * properties
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildInstanceWithPropertiesException(UnitTester $I)
    {
        $I->wantToTest(
            'Di\Service\Builder - build() - instance with properties exception'
        );

        $I->expectThrowable(
            new Exception(
                'Setter injection parameters must be an array'
            ),
            function () {
                $container = new Di();
                $builder   = new Builder();

                $definition = [
                    'className'  => PropertiesComponent::class,
                    'arguments'  => [
                        [
                            'type'  => 'parameter',
                            'value' => 'one',
                        ],
                        [
                            'type'  => 'parameter',
                            'value' => 2,
                        ],
                    ],
                    'properties' => 1234,
                ];

                $builder->build($container, $definition);
            }
        );
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - instance with
     * properties exception property is array
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildInstanceWithPropertiesExceptionPropertyIsArray(UnitTester $I)
    {
        $I->wantToTest(
            'Di\Service\Builder - build() - instance with properties exception property is array'
        );

        $I->expectThrowable(
            new Exception(
                'Property must be an array on position 0'
            ),
            function () {
                $container = new Di();
                $builder   = new Builder();

                $definition = [
                    'className'  => PropertiesComponent::class,
                    'arguments'  => [
                        [
                            'type'  => 'parameter',
                            'value' => 'one',
                        ],
                        [
                            'type'  => 'parameter',
                            'value' => 2,
                        ],
                    ],
                    'properties' => [
                        0 => 1,
                    ],
                ];

                $builder->build($container, $definition);
            }
        );
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - instance with
     * properties exception property name exists
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildInstanceWithPropertiesExceptionPropertyNameExists(UnitTester $I)
    {
        $I->wantToTest(
            'Di\Service\Builder - build() - instance with properties exception property name exists'
        );

        $I->expectThrowable(
            new Exception(
                'The property name is required on position 0'
            ),
            function () {
                $container = new Di();
                $builder   = new Builder();

                $definition = [
                    'className'  => PropertiesComponent::class,
                    'arguments'  => [
                        [
                            'type'  => 'parameter',
                            'value' => 'one',
                        ],
                        [
                            'type'  => 'parameter',
                            'value' => 2,
                        ],
                    ],
                    'properties' => [
                        0 => [
                            'one' => 1,
                        ],
                    ],
                ];

                $builder->build($container, $definition);
            }
        );
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - instance with
     * properties exception property value exists
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildInstanceWithPropertiesExceptionPropertyValueExists(UnitTester $I)
    {
        $I->wantToTest(
            'Di\Service\Builder - build() - instance with properties exception property value exists'
        );

        $I->expectThrowable(
            new Exception(
                'The property value is required on position 0'
            ),
            function () {
                $container = new Di();
                $builder   = new Builder();

                $definition = [
                    'className'  => PropertiesComponent::class,
                    'arguments'  => [
                        [
                            'type'  => 'parameter',
                            'value' => 'one',
                        ],
                        [
                            'type'  => 'parameter',
                            'value' => 2,
                        ],
                    ],
                    'properties' => [
                        0 => [
                            'name' => 'propertyName',
                        ],
                    ],
                ];

                $builder->build($container, $definition);
            }
        );
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - instance with
     * properties
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildInstanceWithProperties(UnitTester $I)
    {
        $I->wantToTest(
            'Di\Service\Builder - build() - instance with properties'
        );

        $container = new Di();
        $builder   = new Builder();

        $definition = [
            'className'  => PropertiesComponent::class,
            'arguments'  => [
                [
                    'type'  => 'parameter',
                    'value' => 'one',
                ],
                [
                    'type'  => 'parameter',
                    'value' => 2,
                ],
            ],
            'properties' => [
                0 => [
                    'name'  => 'propertyName',
                    'value' => [
                        'type'  => 'parameter',
                        'value' => 'set-one',
                    ],
                ],
                1 => [
                    'name'  => 'propertyType',
                    'value' => [
                        'type'  => 'parameter',
                        'value' => 100,
                    ],
                ],
            ],
        ];

        $instance = $builder->build($container, $definition);

        $class = PropertiesComponent::class;
        $I->assertInstanceOf($class, $instance);

        $expected = 'one';
        $actual   = $instance->getName();
        $I->assertEquals($expected, $actual);

        $expected = 2;
        $actual   = $instance->getType();
        $I->assertEquals($expected, $actual);

        $expected = 'set-one';
        $actual   = $instance->propertyName;
        $I->assertEquals($expected, $actual);

        $expected = 100;
        $actual   = $instance->propertyType;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - instance with calls
     * exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildInstanceWithCallsException(UnitTester $I)
    {
        $I->wantToTest(
            'Di\Service\Builder - build() - instance with calls exception'
        );

        $I->expectThrowable(
            new Exception(
                'Setter injection parameters must be an array'
            ),
            function () {
                $container = new Di();
                $builder   = new Builder();

                $definition = [
                    'className' => PropertiesComponent::class,
                    'arguments' => [
                        [
                            'type'  => 'parameter',
                            'value' => 'one',
                        ],
                        [
                            'type'  => 'parameter',
                            'value' => 2,
                        ],
                    ],
                    'calls'     => 1234,
                ];

                $builder->build($container, $definition);
            }
        );
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - instance with calls
     * exception method position
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildInstanceWithCallsExceptionMethodPosition(UnitTester $I)
    {
        $I->wantToTest(
            'Di\Service\Builder - build() - instance with calls exception method position'
        );

        $I->expectThrowable(
            new Exception(
                'Method call must be an array on position 0'
            ),
            function () {
                $container = new Di();
                $builder   = new Builder();

                $definition = [
                    'className' => PropertiesComponent::class,
                    'arguments' => [
                        [
                            'type'  => 'parameter',
                            'value' => 'one',
                        ],
                        [
                            'type'  => 'parameter',
                            'value' => 2,
                        ],
                    ],
                    'calls'     => [
                        0 => 'methodName',
                    ],
                ];

                $builder->build($container, $definition);
            }
        );
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - instance with calls
     * exception method exists
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildInstanceWithCallsExceptionMethodExists(UnitTester $I)
    {
        $I->wantToTest(
            'Di\Service\Builder - build() - instance with calls exception method exists'
        );

        $I->expectThrowable(
            new Exception(
                'The method name is required on position 0'
            ),
            function () {
                $container = new Di();
                $builder   = new Builder();

                $definition = [
                    'className' => PropertiesComponent::class,
                    'arguments' => [
                        [
                            'type'  => 'parameter',
                            'value' => 'one',
                        ],
                        [
                            'type'  => 'parameter',
                            'value' => 2,
                        ],
                    ],
                    'calls'     => [
                        0 => [
                            'methodName',
                        ],
                    ],
                ];

                $builder->build($container, $definition);
            }
        );
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - instance with calls
     * exception method arguments is array
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildInstanceWithCallsExceptionMethodArgumentsIsArray(UnitTester $I)
    {
        $I->wantToTest(
            'Di\Service\Builder - build() - instance with calls exception method arguments is array'
        );

        $I->expectThrowable(
            new Exception(
                'Call arguments must be an array on position 0'
            ),
            function () {
                $container = new Di();
                $builder   = new Builder();

                $definition = [
                    'className' => PropertiesComponent::class,
                    'arguments' => [
                        [
                            'type'  => 'parameter',
                            'value' => 'one',
                        ],
                        [
                            'type'  => 'parameter',
                            'value' => 2,
                        ],
                    ],
                    'calls'     => [
                        0 => [
                            'method'    => 'transform',
                            'arguments' => 444,
                        ],
                    ],
                ];

                $builder->build($container, $definition);
            }
        );
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - instance with calls
     * exception method arguments
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildInstanceWithCallsExceptionMethodArguments(UnitTester $I)
    {
        $I->wantToTest(
            'Di\Service\Builder - build() - instance with calls exception method arguments'
        );

        $container = new Di();
        $builder   = new Builder();

        $definition = [
            'className' => PropertiesComponent::class,
            'arguments' => [
                [
                    'type'  => 'parameter',
                    'value' => 'one',
                ],
                [
                    'type'  => 'parameter',
                    'value' => 2,
                ],
            ],
            'calls'     => [
                0 => [
                    'method'    => 'transform',
                    'arguments' => [
                        [
                            'type'  => 'parameter',
                            'value' => 444,
                        ],
                    ],
                ],
            ],
        ];

        $instance = $builder->build($container, $definition);

        $class = PropertiesComponent::class;
        $I->assertInstanceOf($class, $instance);

        $expected = 'one';
        $actual   = $instance->getName();
        $I->assertEquals($expected, $actual);

        $expected = 444;
        $actual   = $instance->getType();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Unit Tests Phalcon\Di\Service\Builder :: build() - instance with calls
     * exception method no arguments
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceBuilderBuildInstanceWithCallsExceptionMethodNoArguments(UnitTester $I)
    {
        $I->wantToTest(
            'Di\Service\Builder - build() - instance with calls exception method no arguments'
        );

        $container = new Di();
        $builder   = new Builder();

        $definition = [
            'className' => PropertiesComponent::class,
            'arguments' => [
                [
                    'type'  => 'parameter',
                    'value' => 'one',
                ],
                [
                    'type'  => 'parameter',
                    'value' => 2,
                ],
            ],
            'calls'     => [
                0 => [
                    'method' => 'calculate',
                ],
            ],
        ];

        $instance = $builder->build($container, $definition);

        $class = PropertiesComponent::class;
        $I->assertInstanceOf($class, $instance);

        $expected = 'one';
        $actual   = $instance->getName();
        $I->assertEquals($expected, $actual);

        $expected = 555;
        $actual   = $instance->getType();
        $I->assertEquals($expected, $actual);
    }
}
