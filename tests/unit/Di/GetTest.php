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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di\Di;
use Phalcon\Di\Exception;
use Phalcon\Di\Service;
use Phalcon\Di\ServiceInterface;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

use function spl_object_hash;

final class GetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiGet(): void
    {
        // setup
        $container = new Di();

        // set a service and get it to check
        $service = $container->set('escaper', Escaper::class);

        $class = ServiceInterface::class;
        $this->assertInstanceOf($class, $service);

        $class = Service::class;
        $this->assertInstanceOf($class, $service);

        $actual = $service->isShared();
        $this->assertFalse($actual);

        // get escaper service
        $actual = $container->get('escaper');

        $class = Escaper::class;
        $this->assertInstanceOf($class, $actual);

        $expected = spl_object_hash(new Escaper());
        $actual   = spl_object_hash($actual);
        $this->assertNotEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testDiGetClosureWithParameters(): void
    {
        $container = new Di();
        $container->set(
            'greet',
            function (string $name): string {
                return 'Hello ' . $name;
            }
        );

        $actual = $container->get('greet', ['World']);
        $this->assertSame('Hello World', $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiGetException(): void
    {
        // setup
        $container = new Di();

        // non exists service
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Service 'non-exists' is not registered in the container"
        );

        $container->get('non-exists');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testDiGetServiceResolutionException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Service 'broken' cannot be resolved");

        $container = new Di();
        $container->set('broken', 42);
        $container->get('broken');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiGetShared(): void
    {
        // setup
        $container = new Di();

        $escaper = new Escaper();
        $service = $container->set('escaper', $escaper, true);

        $actual = $service->isShared();
        $this->assertTrue($actual);

        // get escaper service - twice to cache it
        $actual = $container->get('escaper');
        $actual = $container->get('escaper');

        $expected = spl_object_hash($escaper);
        $actual   = spl_object_hash($actual);
        $this->assertSame($expected, $actual);
    }
}
