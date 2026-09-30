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

namespace Phalcon\Tests\Unit\Di\FactoryDefault\Cli;

use Phalcon\Di\FactoryDefault\Cli;
use Phalcon\Filter\Filter;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Di\Fake\CliTrait;
use PHPUnit\Framework\Attributes\DataProvider;

final class ConstructTest extends AbstractUnitTestCase
{
    use CliTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiFactoryDefaultCliConstruct(): void
    {
        $container = new Cli();
        $services  = $this->getServices();

        $expected = count($services);
        $actual   = count($container->getServices());
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-29
     */
    public function testDiFactoryDefaultCliConstructFilterHasDefaultMapper(): void
    {
        $container = new Cli();
        $filter    = $container->getShared('filter');

        $this->assertInstanceOf(Filter::class, $filter);
        $this->assertSame($filter, $container->getShared('filter'));

        foreach (array_keys(Filter::getDefaultMapper()) as $name) {
            $this->assertTrue($filter->has($name));
        }

        $this->assertSame('hello', $filter->sanitize('  hello  ', 'trim'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-29
     */
    public function testDiFactoryDefaultCliConstructFilterIsLazy(): void
    {
        $container = new Cli();

        $expected = [
            'className' => Filter::class,
            'arguments' => [
                [
                    'type'  => 'parameter',
                    'value' => Filter::getDefaultMapper(),
                ],
            ],
        ];
        $actual   = $container->getService('filter')->getDefinition();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    #[DataProvider('getServices')]
    public function testDiFactoryDefaultCliConstructServices(
        string $service,
        string $class
    ): void {
        $container = new Cli();

        if ('sessionBag' === $service) {
            $params = ['someName'];
        } else {
            $params = null;
        }

        $actual = $container->get($service, $params);
        $this->assertInstanceOf($class, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    #[DataProvider('getServices')]
    public function testDiFactoryDefaultCliConstructServicesShared(
        string $service,
        string $class
    ): void {
        $container = new Cli();

        $this->assertTrue($container->getService($service)->isShared());
    }
}
