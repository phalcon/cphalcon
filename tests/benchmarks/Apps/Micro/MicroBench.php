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

namespace Phalcon\Tests\Benchmarks\Apps\Micro;

use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Micro;
use PhpBench\Attributes\BeforeMethods;
use PhpBench\Attributes\Revs;
use RuntimeException;

/**
 * Reference app: Micro "hello world". Each call is one request.
 */
#[BeforeMethods('setUp')]
#[Revs(100)]
final class MicroBench
{
    private const EXPECTED = 'Hello World';

    public function setUp(): void
    {
        $_SERVER['REQUEST_METHOD'] = 'GET';
        $_SERVER['REQUEST_URI']    = '/hello';
    }

    public function benchHello(): void
    {
        /**
         * A new request: php-fpm clears the default container at the end of each request.
         */
        Di::reset();

        $application = new Micro(new FactoryDefault());
        /**
         * Micro binds the handler to the application. A static closure cannot be bound.
         */
        $application->get(
            '/hello',
            function (): string {
                return 'Hello World';
            }
        );

        ob_start();
        $application->handle('/hello');
        $body = ob_get_clean();

        if (self::EXPECTED !== $body) {
            throw new RuntimeException(sprintf('Unexpected body: "%s"', $body));
        }
    }
}
