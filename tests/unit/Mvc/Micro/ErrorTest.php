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

namespace Phalcon\Tests\Unit\Mvc\Micro;

use Exception;
use Phalcon\Http\Response;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\Exceptions\ErrorHandlerNotCallable;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

class ErrorTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-16
     */
    public function testMvcMicroError(): void
    {
        $app = new Micro();

        $response = new Response();

        $app->map(
            '/say/hello/{name}',
            function ($name) use ($response) {
                if (is_numeric($name)) {
                    throw new Exception(
                        'Not a human name.'
                    );
                }

                $response->setContent("Hello {$name}!");
            }
        );

        $app->error(
            function ($exception) use ($response) {
                $response->setContent(
                    'ERROR: ' . $exception->getMessage()
                );

                return false;
            }
        );

        $app->setResponseHandler(
            function () use ($response) {
                return $response->getContent();
            }
        );

        $this->assertEquals(
            'Hello sid!',
            $app->handle('/say/hello/sid')
        );

        $this->assertEquals(
            'ERROR: Not a human name.',
            $app->handle('/say/hello/123')
        );
    }

    /**
     * An error handler that cannot be called throws ErrorHandlerNotCallable,
     * the same as cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testMvcMicroErrorNotCallable(): void
    {
        $app = new Micro();

        $app->map(
            '/fail',
            function () {
                throw new Exception('Fail');
            }
        );

        $app->error('unknownErrorHandlerFunction');

        $this->expectException(ErrorHandlerNotCallable::class);
        $this->expectExceptionMessage('Error handler is not callable');

        $app->handle('/fail');
    }

    /**
     * An error handler that returns a response: handle() uses that response,
     * the same as cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/820
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-17
     */
    public function testMvcMicroErrorReturnsResponse(): void
    {
        $app      = new Micro();
        $response = new Response();

        $app->map(
            '/fail',
            function () {
                throw new Exception('Fail');
            }
        );

        $app->error(
            function () use ($response) {
                return $response->setContent('handled');
            }
        );

        $this->expectOutputString('handled');

        $actual = $app->handle('/fail');
        $this->assertSame($response, $actual);
    }
}
