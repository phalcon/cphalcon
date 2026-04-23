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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Di\PropertiesComponent;
use Phalcon\Tests\Support\Di\ServiceComponent;

final class BuildTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildExceptionArgumentType(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Argument at position 0 must have a type'
        );

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

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildExceptionClassName(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Invalid service definition. Missing 'className' parameter"
        );

        $container = new Di();
        $builder   = new Builder();

        $builder->build($container, []);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildExceptionUknownServiceType(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Unknown service type in parameter on position 0'
        );

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

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildInstanceWithCallsException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Setter injection parameters must be an array'
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
            'calls'     => 1234,
        ];

        $builder->build($container, $definition);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildInstanceWithCallsExceptionMethodArguments(): void
    {
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
        $this->assertInstanceOf($class, $instance);

        $expected = 'one';
        $actual   = $instance->getName();
        $this->assertSame($expected, $actual);

        $expected = 444;
        $actual   = $instance->getType();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildInstanceWithCallsExceptionMethodArgumentsIsArray(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Call arguments must be an array on position 0'
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
                    'arguments' => 444,
                ],
            ],
        ];

        $builder->build($container, $definition);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildInstanceWithCallsExceptionMethodExists(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'The method name is required on position 0'
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
                    'methodName',
                ],
            ],
        ];

        $builder->build($container, $definition);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildInstanceWithCallsExceptionMethodNoArguments(): void
    {
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
        $this->assertInstanceOf($class, $instance);

        $expected = 'one';
        $actual   = $instance->getName();
        $this->assertSame($expected, $actual);

        $expected = 555;
        $actual   = $instance->getType();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildInstanceWithCallsExceptionMethodPosition(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Method call must be an array on position 0'
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
                0 => 'methodName',
            ],
        ];

        $builder->build($container, $definition);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildInstanceWithProperties(): void
    {
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
        $this->assertInstanceOf($class, $instance);

        $expected = 'one';
        $actual   = $instance->getName();
        $this->assertSame($expected, $actual);

        $expected = 2;
        $actual   = $instance->getType();
        $this->assertSame($expected, $actual);

        $expected = 'set-one';
        $actual   = $instance->propertyName;
        $this->assertSame($expected, $actual);

        $expected = 100;
        $actual   = $instance->propertyType;
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildInstanceWithPropertiesException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Setter injection parameters must be an array'
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
            'properties' => 1234,
        ];

        $builder->build($container, $definition);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildInstanceWithPropertiesExceptionPropertyIsArray(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Property must be an array on position 0'
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
                0 => 1,
            ],
        ];

        $builder->build($container, $definition);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildInstanceWithPropertiesExceptionPropertyNameExists(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'The property name is required on position 0'
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
                    'one' => 1,
                ],
            ],
        ];

        $builder->build($container, $definition);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildInstanceWithPropertiesExceptionPropertyValueExists(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'The property value is required on position 0'
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
                    'name' => 'propertyName',
                ],
            ],
        ];

        $builder->build($container, $definition);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildPassedParameters(): void
    {
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
        $this->assertInstanceOf($class, $component);

        $expected = 'one';
        $actual   = $component->getName();
        $this->assertSame($expected, $actual);

        $expected = 2;
        $actual   = $component->getType();
        $this->assertSame($expected, $actual);

        $actual = $component->getEscaper();
        $this->assertNull($actual);

        $actual = $component->getService();
        $this->assertNull($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildPassedParametersWithInstance(): void
    {
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
        $this->assertInstanceOf($class, $component);

        $expected = 'one';
        $actual   = $component->getName();
        $this->assertSame($expected, $actual);

        $expected = 2;
        $actual   = $component->getType();
        $this->assertSame($expected, $actual);

        $class  = Escaper::class;
        $actual = $component->getEscaper();
        $this->assertInstanceOf($class, $actual);

        $actual = $component->getService();
        $this->assertNull($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceBuilderBuildPassedParametersWithInstanceAndService(): void
    {
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
        $this->assertInstanceOf($class, $component);

        $expected = 'one';
        $actual   = $component->getName();
        $this->assertSame($expected, $actual);

        $expected = 2;
        $actual   = $component->getType();
        $this->assertSame($expected, $actual);

        $class  = Escaper::class;
        $actual = $component->getEscaper();
        $this->assertInstanceOf($class, $actual);

        $class   = ServiceComponent::class;
        $service = $component->getService();
        $this->assertInstanceOf($class, $service);

        $expected = 'two';
        $actual   = $service->getName();
        $this->assertSame($expected, $actual);

        $expected = 3;
        $actual   = $service->getType();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testDiServiceBuilderBuildMissingServiceParameterKey(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Service "value" is required in parameter on position 0'
        );

        $container  = new Di();
        $builder    = new Builder();
        $definition = [
            'className' => Escaper::class,
            'arguments' => [
                0 => [
                    'type' => 'parameter',
                    // 'value' key intentionally missing
                ],
            ],
        ];

        $builder->build($container, $definition);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testDiServiceBuilderBuildWithPassedParameters(): void
    {
        $container  = new Di();
        $builder    = new Builder();
        $definition = [
            'className' => PropertiesComponent::class,
        ];

        $instance = $builder->build($container, $definition, ['one', 2]);

        $class = PropertiesComponent::class;
        $this->assertInstanceOf($class, $instance);

        $expected = 'one';
        $actual   = $instance->getName();
        $this->assertSame($expected, $actual);

        $expected = 2;
        $actual   = $instance->getType();
        $this->assertSame($expected, $actual);
    }
}
