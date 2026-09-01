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

namespace Phalcon\Tests\Unit\ADR\Front\HttpFront;

use Phalcon\ADR\Front\AbstractHttpFront;
use Phalcon\ADR\Front\HttpFront;
use Phalcon\Container\Container;
use Phalcon\Contracts\ADR\Application as ApplicationInterface;
use Phalcon\Contracts\ADR\Emitter\Emitter;
use Phalcon\Contracts\Front\FrontController;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use stdClass;

final class RunTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Front\HttpFront :: implements FrontController
     */
    public function testAdrFrontHttpFrontIsFrontController(): void
    {
        $front = new HttpFront('/project/root');

        $this->assertInstanceOf(FrontController::class, $front);
        $this->assertInstanceOf(AbstractHttpFront::class, $front);
    }

    /**
     * Unit Tests Phalcon\ADR\Front\HttpFront :: run() - handles and emits
     */
    public function testAdrFrontHttpFrontRunEmitsHandledResponse(): void
    {
        $front = new class ('/project/root') extends AbstractHttpFront {
            public ?ResponseInterface $emitted = null;

            protected function getApplication(Container $container): ApplicationInterface
            {
                return new class implements ApplicationInterface {
                    public function handle($request): ResponseInterface
                    {
                        return (new Response())->setContent('front-body');
                    }
                };
            }

            protected function registerProviders(Container $container): void
            {
                $container->set('Phalcon\\Contracts\\Http\\AttributeRequest', function ($c) {
                    return new stdClass();
                });

                $front = $this;
                $container->set('Phalcon\\Contracts\\ADR\\Emitter\\Emitter', function ($c) use ($front) {
                    return new class ($front) implements Emitter {
                        private $front;

                        public function __construct($front)
                        {
                            $this->front = $front;
                        }

                        public function emit(ResponseInterface $response): void
                        {
                            $this->front->emitted = $response;
                        }
                    };
                });
            }
        };

        $code = $front->run();

        $this->assertSame(0, $code);
        $this->assertInstanceOf(Response::class, $front->emitted);
        $this->assertSame('front-body', $front->emitted->getContent());
    }

    /**
     * Unit Tests Phalcon\ADR\Front\HttpFront :: run() - boot failure
     */
    public function testAdrFrontHttpFrontRunReturnsErrorCodeOnBootFailure(): void
    {
        $front = new class ('/project/root') extends AbstractHttpFront {
            protected function buildContainer(): Container
            {
                throw new \RuntimeException('boot failed');
            }
        };

        ob_start();
        $code   = $front->run();
        $output = (string) ob_get_clean();

        $this->assertSame(1, $code);
        $this->assertStringContainsString('Internal Server Error', $output);
    }
}
