<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Di;

use Closure;
use Phalcon\Di\Di;
use Phalcon\Di\Exception;
use Phalcon\Di\Service;
use Phalcon\Di\ServiceInterface;
use Phalcon\Html\Escaper;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Di\CallsComponent;
use Phalcon\Tests\Support\Traits\ErrorHandlerTrait;

use function spl_object_id;

final class GetTest extends AbstractUnitTestCase
{
    use ErrorHandlerTrait;

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

        $expected = spl_object_id(new Escaper());
        $actual   = spl_object_id($actual);
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

        $expected = spl_object_id($escaper);
        $actual   = spl_object_id($actual);
        $this->assertSame($expected, $actual);
    }

    /**
     * A shared service with a `calls` method that cannot be called gives a
     * warning and null, the same as cphalcon. Null is not kept, thus each
     * get() builds the service again.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/808
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-15
     */
    public function testDiGetSharedCallsNotCallable(): void
    {
        $container = new Di();
        $container->setShared(
            'calls',
            [
                'className' => CallsComponent::class,
                'calls'     => [
                    ['method' => 'missing'],
                ],
            ]
        );

        [$actual, $messages] = $this->collectErrors(
            static fn () => [$container->get('calls'), $container->get('calls')]
        );

        $message = 'class ' . CallsComponent::class . ' does not have a method "missing"';
        $this->assertSame([null, null], $actual);
        $this->assertSame([$message, $message], $messages);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-29
     */
    public function testDiGetSharedNullResolvesAgain(): void
    {
        $container = new Di();
        $count     = 0;

        $container->setShared(
            'nullService',
            function () use (&$count) {
                $count++;

                return null;
            }
        );

        $this->assertNull($container->get('nullService'));
        $this->assertNull($container->get('nullService'));
        $this->assertSame(2, $count);
    }

    /**
     * The container cannot bind a static closure. Then the closure cannot be
     * called: there is a warning and null, the same as cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testDiGetStaticClosure(): void
    {
        $container = new Di();
        $container->set('static', static fn () => 1);

        [$actual, $messages] = $this->collectErrors(
            static fn () => $container->get('static')
        );

        $this->assertNull($actual);
        $this->assertSame(
            [$this->getStaticClosureBindMessage(), 'no array or string given'],
            $messages
        );
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testDiGetStaticClosureParameters(): void
    {
        $container = new Di();
        $container->set('static', static fn ($value) => $value);

        [$actual, $messages] = $this->collectErrors(
            static fn () => $container->get('static', ['one'])
        );

        $this->assertNull($actual);
        $this->assertSame(
            [$this->getStaticClosureBindMessage(), 'no array or string given'],
            $messages
        );
    }

    /**
     * The warning of Closure::bind() for a static closure. The text changes
     * with the PHP version (a PHP 9 notice from 8.5.x), thus get it from PHP.
     */
    private function getStaticClosureBindMessage(): string
    {
        [, $messages] = $this->collectErrors(
            static fn () => Closure::bind(static fn () => 1, new Di())
        );

        return $messages[0];
    }
}
