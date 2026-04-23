<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Http\Response;

use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Http\Message\ResponseStatusCodeInterface;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Page\Http;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-08
     */
    public function testHttpResponseConstruct(): void
    {
        $response = new Response();

        $class = Response::class;
        $this->assertInstanceOf($class, $response);
        $class = ResponseInterface::class;
        $this->assertInstanceOf($class, $response);
        $class = InjectionAwareInterface::class;
        $this->assertInstanceOf($class, $response);
        $class = EventsAwareInterface::class;
        $this->assertInstanceOf($class, $response);
        $class = ResponseStatusCodeInterface::class;
        $this->assertInstanceOf($class, $response);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-08
     */
    public function testHttpResponseConstructWithContent(): void
    {
        $content  = Http::TEST_CONTENT;
        $response = new Response($content);

        $expected = $content;
        $actual   = $response->getContent();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-08
     */
    public function testHttpResponseConstructWithContentCode(): void
    {
        $content = Http::TEST_CONTENT;
        $code    = Http::CODE_200;

        $response = new Response($content, $code);

        $expected = $content;
        $actual   = $response->getContent();
        $this->assertSame($expected, $actual);

        $expected = $code;
        $actual   = $response->getStatusCode();
        $this->assertSame($expected, $actual);

        // Check Status message
        $expected = Http::MESSAGE_200_OK;
        $actual   = $response->getHeaders()->get(Http::STATUS);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-08
     */
    public function testHttpResponseConstructWithContentCodeStatus(): void
    {
        $content = Http::TEST_CONTENT;
        $code    = Http::CODE_200;

        $response = new Response($content, $code, 'Success');

        $expected = $content;
        $actual   = $response->getContent();
        $this->assertSame($expected, $actual);

        $expected = $code;
        $actual   = $response->getStatusCode();
        $this->assertSame($expected, $actual);

        // Check Status message
        $expected = Http::MESSAGE_200_SUCCESS;
        $actual   = $response->getHeaders()->get(Http::STATUS);
        $this->assertSame($expected, $actual);
    }
}
