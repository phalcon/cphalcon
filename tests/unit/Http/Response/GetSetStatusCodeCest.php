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
use Phalcon\Tests\Fixtures\Micro\HttpResponseContentMiddleware;
use Phalcon\Tests\Unit\Http\Helper\HttpBase;
use UnitTester;

use function headers_list;
use function ob_clean;
use function ob_end_flush;
use function ob_get_clean;
use function ob_start;
use function xdebug_get_headers;

class GetSetStatusCodeCest extends HttpBase
{
    /**
     * Tests Phalcon\Http\Response :: getStatusCode() / setStatusCode()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-24
     */
    public function httpResponseGetSetStatusCode(UnitTester $I)
    {
        $I->wantToTest('Http\Response - getStatusCode() / setStatusCode()');

        $code     = 200;
        $response = $this->getResponseObject();
        $response->setStatusCode($code);

        $expected = $code;
        $actual   = $response->getStatusCode();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests the setStatusCode
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetStatusCode(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setStatusCode(404, 'Not Found');
        $actual = $response->getHeaders();

        $I->assertEquals(
            '',
            $actual->get('HTTP/1.1 404 Not Found')
        );
        $I->assertEquals(
            '404 Not Found',
            $actual->get('Status')
        );
    }

    /**
     * Tests the Multiple Status Codes
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1892
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testMultipleHttpHeaders(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setStatusCode(200, 'OK');
        $response->setStatusCode(404, 'Not Found');
        $response->setStatusCode(409, 'Conflict');
        $actual = $response->getHeaders();

        $I->assertEquals(
            '',
            $actual->get('HTTP/1.1 409 Conflict')
        );
        $I->assertEquals(
            '409 Conflict',
            $actual->get('Status')
        );
    }

    public function testSetStatusCodeDefaultMessage(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setStatusCode(103);
        $actual = $response->getHeaders();
        $I->assertEquals(
            '',
            $actual->get('HTTP/1.1 103 Early Hints')
        );
        $I->assertEquals(
            '103 Early Hints',
            $actual->get('Status')
        );
        $response->setStatusCode(200);
        $actual = $response->getHeaders();
        $I->assertEquals(
            '',
            $actual->get('HTTP/1.1 200 OK')
        );
        $I->assertEquals(
            '200 OK',
            $actual->get('Status')
        );
        $response->setStatusCode(418);
        $actual = $response->getHeaders();
        $I->assertEquals(
            '',
            $actual->get("HTTP/1.1 418 I'm a teapot")
        );
        $I->assertEquals(
            "418 I'm a teapot",
            $actual->get('Status')
        );
        $response->setStatusCode(418, 'My own message');
        $actual = $response->getHeaders();
        $I->assertEquals(
            '',
            $actual->get('HTTP/1.1 418 My own message')
        );
        $I->assertEquals(
            '418 My own message',
            $actual->get('Status')
        );
    }

    /**
     * Tests the setStatusCode after send
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetStatusCodeSend(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $body = ['test' => 123];
        $response
            ->resetHeaders()
            ->setStatusCode(404)
            ->setContentType('application/json', 'UTF-8')
            ->setJsonContent($body, JSON_NUMERIC_CHECK)
        ;

        ob_start();
        $response->send();
        $contents = ob_get_clean();

        $expected = [
            "Status: 404 Not Found",
            "Content-Type: application/json"
        ];
        $actual   = xdebug_get_headers();
        $I->assertSame($expected, $actual);

        $expected = '{"test":123}';
        $actual   = $contents;
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests the setStatusCode after send
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetStatusCodeSendMicro(UnitTester $I)
    {
        $application = new Micro($this->container);

        $application->before(new HttpResponseContentMiddleware());
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
            "Content-Type: application/json"
        ];
        $actual   = xdebug_get_headers();
        $I->assertSame($expected, $actual);

        $expected = '{"test":123}';
        $actual   = $contents;
        $I->assertSame($expected, $actual);
    }
}
