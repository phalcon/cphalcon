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

namespace Phalcon\Tests\Unit\Http\Response;

use Phalcon\Mvc\Micro;
use Phalcon\Tests\Support\Page\Http;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;
use Phalcon\Tests\Unit\Http\Response\Fake\FakeHttpResponseContentMiddleware;

use function ob_get_clean;
use function ob_start;
use function uniqid;
use function xdebug_get_headers;

final class GetSetStatusCodeTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-24
     */
    public function testHttpResponseGetSetStatusCode(): void
    {
        $code = Http::CODE_200;
        $response = $this->getResponseObject();
        $response->setStatusCode($code);

        $expected = $code;
        $actual   = $response->getStatusCode();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetStatusCode(): void
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setStatusCode(
            Http::CODE_404,
            Http::NOT_FOUND
        );

        $headers = $response->getHeaders();

        $actual = $headers->has(Http::HTTP_404_NOT_FOUND);
        $this->assertTrue($actual);

        $actual = $headers->get(Http::HTTP_404_NOT_FOUND);
        $this->assertNull($actual);

        $expected = Http::MESSAGE_404_NOT_FOUND;
        $actual   = $headers->get(Http::STATUS);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetStatusCodeSend(): void
    {
        $this->markTestSkipped('Skipping until I figure it out without xdebug');
        $response = $this->getResponseObject();

        $body = ['test' => 123];
        $response
            ->resetHeaders()
            ->setStatusCode(Http::CODE_404)
            ->setContentType(Http::CONTENT_TYPE_JSON, Http::UTF8)
            ->setJsonContent($body, JSON_NUMERIC_CHECK)
        ;

        ob_start();
        $response->send();
        $contents = ob_get_clean();

        $expected = [
            'Status: ' . Http::MESSAGE_404_NOT_FOUND,
            'Content-Type: ' . Http::CONTENT_TYPE_JSON,
        ];
        $actual   = xdebug_get_headers();
        $this->assertSame($expected, $actual);

        $expected = '{"test":123}';
        $actual   = $contents;
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetStatusCodeSendMicro(): void
    {
        $this->markTestSkipped('TODO: Enable with MVC');
        $application = new Micro($this->container);

        $application->before(new FakeHttpResponseContentMiddleware());
        $application->notFound(
            function () {
                return '404 - handler';
            }
        );
        $application->get(
            "/",
            function () {
                return '200 - "/"';
            }
        );

        ob_start();
        $application->handle("/");
        $contents = ob_get_clean();

        $expected = [
            "Status: 404 Not Found",
            "Content-Type: application/json",
        ];
        $actual   = xdebug_get_headers();
        $this->assertSame($expected, $actual);

        $expected = '{"test":123}';
        $actual   = $contents;
        $this->assertSame($expected, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/1892
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testMultipleHttpHeaders(): void
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();
        $response->setStatusCode(Http::CODE_200, Http::OK);
        $response->setStatusCode(Http::CODE_404, Http::NOT_FOUND);
        $response->setStatusCode(Http::CODE_409, Http::CONFLICT);

        $headers = $response->getHeaders();

        $actual = $headers->get(Http::HTTP_409_CONFLICT);
        $this->assertNull($actual);

        $expected = Http::MESSAGE_409_CONFLICT;
        $actual   = $headers->get(Http::STATUS);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testHttpResponseSetStatusCodeUnknownCodeThrows(): void
    {
        $response = $this->getResponseObject();

        $this->expectException(\Phalcon\Http\Response\Exception::class);
        $this->expectExceptionMessage('Non-standard status-code given without a message');
        $response->setStatusCode(999);
    }

    public function testSetStatusCodeDefaultMessage(): void
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();
        $response->setStatusCode(Http::CODE_103);

        $headers = $response->getHeaders();

        $actual = $headers->get(Http::HTTP_103_EARLY_HINTS);
        $this->assertNull($actual);

        $expected = Http::MESSAGE_103_EARLY_HINTS;
        $actual   = $headers->get(Http::STATUS);
        $this->assertSame($expected, $actual);

        /**
         * 200
         */
        $response->setStatusCode(Http::CODE_200);

        $headers = $response->getHeaders();

        $actual = $headers->get(Http::HTTP_200_OK);
        $this->assertNull($actual);

        $expected = Http::MESSAGE_200_OK;
        $actual   = $headers->get(Http::STATUS);
        $this->assertSame($expected, $actual);

        /**
         * 418
         */
        $response->setStatusCode(Http::CODE_418);

        $headers = $response->getHeaders();

        $actual = $headers->get(Http::HTTP_418_IM_A_TEAPOT);
        $this->assertNull($actual);

        $expected = Http::MESSAGE_418_IM_A_TEAPOT;
        $actual   = $headers->get(Http::STATUS);
        $this->assertSame($expected, $actual);

        /**
         * 418 Custom
         */
        $message = uniqid('mess-');
        $status  = '418 ' . $message;
        $name    = 'HTTP/1.1 ' . $status;
        $response->setStatusCode(Http::CODE_418, $message);

        $headers = $response->getHeaders();

        $actual = $headers->get($name);
        $this->assertNull($actual);

        $expected = $status;
        $actual   = $headers->get(Http::STATUS);
        $this->assertSame($expected, $actual);
    }
}
