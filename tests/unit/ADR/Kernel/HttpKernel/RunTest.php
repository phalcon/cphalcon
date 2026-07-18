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

namespace Phalcon\Tests\Unit\ADR\Kernel\HttpKernel;

use Phalcon\ADR\Kernel\AbstractHttpKernel;
use Phalcon\ADR\Kernel\HttpKernel;
use Phalcon\Container\Container;
use Phalcon\Contracts\ADR\Emitter\Emitter;
use Phalcon\Contracts\ADR\Kernel\Kernel;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use stdClass;

final class RunTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Kernel\HttpKernel :: implements Kernel
     */
    public function testAdrKernelHttpKernelIsKernel(): void
    {
        $kernel = new HttpKernel('/project/root');

        $this->assertInstanceOf(Kernel::class, $kernel);
        $this->assertInstanceOf(AbstractHttpKernel::class, $kernel);
    }

    /**
     * Unit Tests Phalcon\ADR\Kernel\HttpKernel :: run() - handles and emits
     */
    public function testAdrKernelHttpKernelRunEmitsHandledResponse(): void
    {
        $kernel = new class ('/project/root') extends AbstractHttpKernel {
            public ?ResponseInterface $emitted = null;

            protected function registerProviders(Container $container): void
            {
                $container->set('request', function ($c) {
                    return new stdClass();
                });

                $container->set('Phalcon\\ADR\\Application', function ($c) {
                    return new class {
                        public function handle($request): ResponseInterface
                        {
                            return (new Response())->setContent('kernel-body');
                        }
                    };
                });

                $kernel = $this;
                $container->set('Phalcon\\Contracts\\ADR\\Emitter\\Emitter', function ($c) use ($kernel) {
                    return new class ($kernel) implements Emitter {
                        private $kernel;

                        public function __construct($kernel)
                        {
                            $this->kernel = $kernel;
                        }

                        public function emit(ResponseInterface $response): void
                        {
                            $this->kernel->emitted = $response;
                        }
                    };
                });
            }
        };

        $code = $kernel->run();

        $this->assertSame(0, $code);
        $this->assertInstanceOf(Response::class, $kernel->emitted);
        $this->assertSame('kernel-body', $kernel->emitted->getContent());
    }

    /**
     * Unit Tests Phalcon\ADR\Kernel\HttpKernel :: run() - boot failure
     */
    public function testAdrKernelHttpKernelRunReturnsErrorCodeOnBootFailure(): void
    {
        $kernel = new class ('/project/root') extends AbstractHttpKernel {
            protected function buildContainer(): Container
            {
                throw new \RuntimeException('boot failed');
            }
        };

        ob_start();
        $code   = $kernel->run();
        $output = (string) ob_get_clean();

        $this->assertSame(1, $code);
        $this->assertStringContainsString('Internal Server Error', $output);
    }
}
