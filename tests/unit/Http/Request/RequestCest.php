<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http;

use Phalcon\DiInterface;
use Phalcon\Http\Request;
use Phalcon\Test\Fixtures\Http\PhpStream;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class RequestCest extends HttpBase
{
    /**
     * Tests the getDI
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-23
     */
    public function testHttpRequestGetDI(UnitTester $I)
    {
        $request   = $this->getRequestObject();
        $container = $request->getDI();
        $class     = DiInterface::class;
        $I->assertInstanceOf($class, $container);
    }

    /**
     * Tests the instance of the object
     */
    public function testHttpRequestInstanceOf(UnitTester $I)
    {
        $request = $this->getRequestObject();
        $class   = Request::class;
        $I->assertInstanceOf($class, $request);
    }

    /**
     * Tests getHeader empty
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestHeaderGetEmpty(UnitTester $I)
    {
        $request = $this->getRequestObject();
        $actual  = $request->getHeader('LOL');
        $I->assertEmpty($actual);
    }

    /**
     * Tests getHeader
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestHeaderGet(UnitTester $I)
    {
        $request = $this->getRequestObject();
        $this->setServerVar('HTTP_LOL', 'zup');
        $actual = $request->getHeader('LOL');
        $this->unsetServerVar('HTTP_LOL');

        $expected = 'zup';
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests getHeader
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2294
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-10-19
     */
    public function testHttpRequestCustomHeaderGet(UnitTester $I)
    {
        $_SERVER['HTTP_FOO']     = 'Bar';
        $_SERVER['HTTP_BLA_BLA'] = 'boo';
        $_SERVER['HTTP_AUTH']    = true;

        $request = $this->getRequestObject();

        $expected = [
            'Foo'     => 'Bar',
            'Bla-Bla' => 'boo',
            'Auth'    => 1,
        ];
        $actual   = $request->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests hasHeader
     *
     * @author limx <715557344@qq.com>
     * @since  2017-10-26
     */
    public function testHttpRequestCustomHeaderHas(UnitTester $I)
    {
        $_SERVER['HTTP_FOO']  = 'Bar';
        $_SERVER['HTTP_AUTH'] = true;

        $request = $this->getRequestObject();

        $actual = $request->hasHeader('HTTP_FOO');
        $I->assertTrue($actual);

        $actual = $request->hasHeader('AUTH');
        $I->assertTrue($actual);

        $actual = $request->hasHeader('HTTP_FOO');
        $I->assertTrue($actual);
    }

    /**
     * Tests isAjax default
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestIsAjaxDefault(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $actual = $request->isAjax();
        $I->assertFalse($actual);
    }

    /**
     * Tests isAjax
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestIsAjax(UnitTester $I)
    {
        $request = $this->getRequestObject();
        $this->setServerVar('HTTP_X_REQUESTED_WITH', 'XMLHttpRequest');
        $actual = $request->isAjax();
        $this->unsetServerVar('HTTP_X_REQUESTED_WITH');

        $I->assertTrue($actual);
    }

    /**
     * Tests getScheme default
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestGetSchemeDefault(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $expected = 'http';
        $actual   = $request->getScheme();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests getScheme with HTTPS
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestGetScheme(UnitTester $I)
    {
        $request = $this->getRequestObject();
        $this->setServerVar('HTTPS', 'on');
        $actual = $request->getScheme();
        $this->unsetServerVar('HTTPS');

        $expected = 'https';
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests isSecure default
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestIsSecureDefault(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $actual = $request->isSecure();
        $I->assertFalse($actual);
    }

    /**
     * Tests isSecure
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestIsSecure(UnitTester $I)
    {
        $request = $this->getRequestObject();
        $this->setServerVar('HTTPS', 'on');
        $actual = $request->isSecure();
        $this->unsetServerVar('HTTPS');

        $I->assertTrue($actual);
    }

    /**
     * Tests isSoap default
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-23
     */
    public function testHttpRequestIsSoapDefault(UnitTester $I)
    {
        $request = $this->getRequestObject();
        $actual  = $request->isSoap();

        $I->assertFalse($actual);
    }

    /**
     * Tests isSoapRequest
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestIsSoap(UnitTester $I)
    {
        $request = $this->getRequestObject();
        $this->setServerVar('CONTENT_TYPE', 'application/soap+xml');
        $actual = $request->isSoap();
        $this->unsetServerVar('CONTENT_TYPE');

        $I->assertTrue($actual);
    }

    /**
     * Tests getServerAddress default
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestGetServerAddressDefault(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $expected = '127.0.0.1';
        $actual   = $request->getServerAddress();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests getServerAddress
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestGetServerAddress(UnitTester $I)
    {
        $request = $this->getRequestObject();
        $this->setServerVar('SERVER_ADDR', '192.168.4.1');
        $actual = $request->getServerAddress();
        $this->unsetServerVar('SERVER_ADDR');

        $expected = '192.168.4.1';
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests getHttpHost
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestHttpHost(UnitTester $I)
    {
        $request = $this->getRequestObject();
        $this->setServerVar('HTTP_HOST', '');
        $this->setServerVar('SERVER_NAME', '');
        $this->setServerVar('SERVER_ADDR', '');

        $actual = is_string($request->getHttpHost());
        $I->assertTrue($actual);

        $expected = '';
        $actual   = $request->getHttpHost();
        $I->assertEquals($expected, $actual);

        $request = $this->getRequestObject();
        unset($_SERVER['HTTP_HOST'], $_SERVER['SERVER_NAME'], $_SERVER['SERVER_ADDR']);

        $expected = '';
        $actual   = $request->getHttpHost();
        $I->assertEquals($expected, $actual);

        $request = $this->getRequestObject();
        $this->setServerVar('SERVER_NAME', 'host@name');

        $expected = 'host@name';
        $actual   = $request->getHttpHost();
        $I->assertEquals($expected, $actual);

        $request = $this->getRequestObject();
        $this->setServerVar('HTTPS', 'off');
        $this->setServerVar('SERVER_NAME', 'localhost');
        $this->setServerVar('SERVER_PORT', 80);

        $expected = 'localhost';
        $actual   = $request->getHttpHost();
        $I->assertEquals($expected, $actual);

        $request = $this->getRequestObject();
        $this->setServerVar('HTTPS', 'on');
        $this->setServerVar('SERVER_NAME', 'localhost');
        $this->setServerVar('SERVER_PORT', 80);

        $expected = 'localhost';
        $actual   = $request->getHttpHost();
        $I->assertEquals($expected, $actual);

        $request = $this->getRequestObject();
        $this->setServerVar('HTTPS', 'on');
        $this->setServerVar('SERVER_NAME', 'localhost');
        $this->setServerVar('SERVER_PORT', 443);

        $expected = 'localhost';
        $actual   = $request->getHttpHost();
        $I->assertEquals($expected, $actual);

        $request = $this->getRequestObject();
        $this->setServerVar('HTTP_HOST', '');
        $this->setServerVar('SERVER_NAME', '');
        $this->setServerVar('SERVER_ADDR', '8.8.8.8');

        $expected = '8.8.8.8';
        $actual   = $request->getHttpHost();
        $I->assertEquals($expected, $actual);

        $request = $this->getRequestObject();
        $this->setServerVar('HTTP_HOST', '');
        $this->setServerVar('SERVER_NAME', 'some.domain');
        $this->setServerVar('SERVER_ADDR', '8.8.8.8');

        $expected = 'some.domain';
        $actual   = $request->getHttpHost();
        $I->assertEquals($expected, $actual);

        $request = $this->getRequestObject();
        $this->setServerVar('HTTP_HOST', 'example.com');
        $this->setServerVar('SERVER_NAME', 'some.domain');
        $this->setServerVar('SERVER_ADDR', '8.8.8.8');

        $expected = 'example.com';
        $actual   = $request->getHttpHost();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests strict host check
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-06-26
     */
    public function testHttpStrictHostCheck(UnitTester $I)
    {
        $request = $this->getRequestObject();
        $request->setStrictHostCheck(true);
        $this->setServerVar('SERVER_NAME', 'LOCALHOST:80');

        $expected = 'localhost';
        $actual   = $request->getHttpHost();
        $I->assertEquals($expected, $actual);

        $request = $this->getRequestObject();
        $request->setStrictHostCheck(false);
        $this->setServerVar('SERVER_NAME', 'LOCALHOST:80');

        $expected = 'LOCALHOST:80';
        $actual   = $request->getHttpHost();
        $I->assertEquals($expected, $actual);

        $request = $this->getRequestObject();

        $actual = $request->isStrictHostCheck();
        $I->assertFalse($actual);

        $request->setStrictHostCheck(true);
        $actual = $request->isStrictHostCheck();
        $I->assertTrue($actual);

        $request->setStrictHostCheck(false);
        $actual = $request->isStrictHostCheck();
        $I->assertFalse($actual);
    }

    /**
     * Tests Request::getPort
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-06-26
     */
    public function testHttpRequestPort(UnitTester $I)
    {
        $request = $this->getRequestObject();
        $this->setServerVar('HTTPS', 'on');
        $this->setServerVar('HTTP_HOST', 'example.com');

        $expected = 443;
        $actual   = $request->getPort();
        $I->assertEquals($expected, $actual);

        $request = $this->getRequestObject();
        $this->setServerVar('HTTPS', 'off');
        $this->setServerVar('HTTP_HOST', 'example.com');

        $expected = 80;
        $actual   = $request->getPort();
        $I->assertEquals($expected, $actual);

        $request = $this->getRequestObject();
        $this->setServerVar('HTTPS', 'off');
        $this->setServerVar('HTTP_HOST', 'example.com:8080');

        $expected = 8080;
        $actual   = $request->getPort();
        $I->assertEquals($expected, $actual);

        $this->setServerVar('HTTPS', 'on');
        $this->setServerVar('HTTP_HOST', 'example.com:8081');

        $expected = 8081;
        $actual   = $request->getPort();
        $I->assertEquals($expected, $actual);

        unset($_SERVER['HTTPS']);
        $this->setServerVar('HTTP_HOST', 'example.com:8082');

        $expected = 8082;
        $actual   = $request->getPort();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests getHttpHost by using invalid host
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-06-26
     *
     * @expectedException \UnexpectedValueException
     */
    public function testInvalidHttpRequestHttpHost(UnitTester $I)
    {
        $examples = [
            'foo±bar±baz',
            'foo~bar~baz',
            '<foo-bar-baz>',
            'foo=bar=baz',
            'foobar/baz',
            'foo@bar',
        ];

        foreach ($examples as $host) {
            $I->expectThrowable(
                new \UnexpectedValueException('Invalid host ' . $host),
                function () use ($host) {
                    $request = $this->getRequestObject();
                    $request->setStrictHostCheck(true);

                    $this->setServerVar('HTTP_HOST', $host);
                    $request->getHttpHost();
                }
            );
        }
    }

    /**
     * Tests POST functions
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestInputPost(UnitTester $I)
    {
        $this->hasEmpty($I, 'hasPost');
        $this->hasNotEmpty($I, 'hasPost', 'setPostVar');
        $this->getEmpty($I, 'getPost');
        $this->getNotEmpty($I, 'getPost', 'setPostVar');
        $this->getSanitized($I, 'getPost', 'setPostVar');
        $this->getSanitizedArrayFilter($I, 'getPost', ['string'], 'setPostVar');
    }

    /**
     * Tests getPut with json content type.
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/13418
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-06-03
     */
    public function shouldGetDataReceivedByPutMethod(UnitTester $I)
    {
        stream_wrapper_unregister('php');
        stream_wrapper_register('php', PhpStream::class);

        file_put_contents('php://input', 'fruit=orange&quantity=4');

        $_SERVER['REQUEST_METHOD'] = 'PUT';

        $request = new Request();

        $data     = file_get_contents('php://input');
        $expected = ['fruit' => 'orange', 'quantity' => '4'];

        parse_str($data, $actual);

        $I->assertEquals($expected, $actual);

        $actual = $request->getPut();
        $I->assertEquals($expected, $actual);

        stream_wrapper_restore('php');
    }

    /**
     * Tests getPut with json content type.
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/13418
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-06-03
     */
    public function shouldGetDataReceivedByPutMethodAndJsonType(UnitTester $I)
    {
        stream_wrapper_unregister('php');
        stream_wrapper_register('php', PhpStream::class);

        file_put_contents('php://input', '{"fruit": "orange", "quantity": "4"}');

        $_SERVER['REQUEST_METHOD'] = 'PUT';
        $_SERVER['CONTENT_TYPE']   = 'application/json';

        $request = new Request();

        $expected = ['fruit' => 'orange', 'quantity' => '4'];
        $actual   = json_decode(file_get_contents('php://input'), true);

        $I->assertEquals($expected, $actual);

        $actual = $request->getPut();
        $I->assertEquals($expected, $actual);

        stream_wrapper_restore('php');
    }

    /**
     * Tests GET functions
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestInputGet(UnitTester $I)
    {
        $this->hasEmpty($I, 'hasQuery');
        $this->hasNotEmpty($I, 'hasQuery', 'setGetVar');
        $this->getEmpty($I, 'getQuery');
        $this->getNotEmpty($I, 'getQuery', 'setGetVar');
        $this->getSanitized($I, 'getQuery', 'setGetVar');
        $this->getSanitizedArrayFilter($I, 'getQuery', ['string'], 'setGetVar');
    }

    /**
     * Tests REQUEST functions
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestInputRequest(UnitTester $I)
    {
        $this->hasEmpty($I, 'has');
        $this->hasNotEmpty($I, 'has', 'setRequestVar');
        $this->getEmpty($I, 'get');
        $this->getNotEmpty($I, 'get', 'setRequestVar');
        $this->getSanitized($I, 'get', 'setRequestVar');
        $this->getSanitizedArrayFilter($I, 'get', ['string'], 'setRequestVar');
    }

    public function testHttpRequestMethod(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $_SERVER['REQUEST_METHOD'] = 'POST';
        $I->assertEquals($request->getMethod(), 'POST');
        $I->assertTrue($request->isPost());
        $I->assertFalse($request->isGet());

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $I->assertEquals($request->getMethod(), 'GET');
        $I->assertTrue($request->isGet());
        $I->assertFalse($request->isPost());

        $_SERVER['REQUEST_METHOD'] = 'PUT';
        $I->assertEquals($request->getMethod(), 'PUT');
        $I->assertTrue($request->isPut());

        $_SERVER['REQUEST_METHOD'] = 'DELETE';
        $I->assertEquals($request->getMethod(), 'DELETE');
        $I->assertTrue($request->isDelete());

        $_SERVER['REQUEST_METHOD'] = 'OPTIONS';
        $I->assertEquals($request->getMethod(), 'OPTIONS');
        $I->assertTrue($request->isOptions());

        $_SERVER['REQUEST_METHOD'] = 'POST';
        $I->assertTrue($request->isMethod('POST'));
        $I->assertTrue($request->isMethod(['GET', 'POST']));

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $I->assertTrue($request->isMethod('GET'));
        $I->assertTrue($request->isMethod(['GET', 'POST']));

        $_SERVER['REQUEST_METHOD'] = 'CONNECT';
        $I->assertEquals($request->getMethod(), 'CONNECT');
        $I->assertTrue($request->isConnect());
        $I->assertFalse($request->isGet());

        $_SERVER['REQUEST_METHOD'] = 'TRACE';
        $I->assertEquals($request->getMethod(), 'TRACE');
        $I->assertTrue($request->isTrace());
        $I->assertFalse($request->isGet());

        $_SERVER['REQUEST_METHOD'] = 'PURGE';
        $I->assertEquals($request->getMethod(), 'PURGE');
        $I->assertTrue($request->isPurge());
        $I->assertFalse($request->isGet());
    }

    /**
     * Tests the ability to override the HTTP method
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12478
     * @author Serghei Iakovelv <serghei@phalconphp.com>
     * @since  2016-12-18
     */
    public function shouldOverrideHttpRequestMethod(UnitTester $I)
    {
        $examples = $this->overridenMethodProvider();
        foreach ($examples as $item) {
            $header   = $item[0];
            $method   = $item[1];
            $expected = $item[2];

            $_SERVER['REQUEST_METHOD'] = 'POST';
            $request                   = $this->getRequestObject();

            $_SERVER[$header] = $method;

            $actual = $request->getMethod();
            $I->assertEquals($expected, $actual);

            $_SERVER[$header] = strtolower($method);
            $actual           = $request->getMethod();
            $I->assertEquals($expected, $actual);

            $_SERVER[strtolower($header)] = $method;
            $actual                       = $request->getMethod();
            $I->assertEquals($expected, $actual);
        }
    }

    private function overridenMethodProvider()
    {
        return [
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'PUT', 'PUT'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'PAT', 'GET'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'GET', 'GET'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'GOT', 'GET'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'HEAD', 'HEAD'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'HED', 'GET'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'POST', 'POST'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'PAST', 'GET'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'DELETE', 'DELETE'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'DILETE', 'GET'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'OPTIONS', 'OPTIONS'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'OPTION', 'GET'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'PATCH', 'PATCH'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'PUTCH', 'GET'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'PURGE', 'PURGE'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'PURG', 'GET'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'TRACE', 'TRACE'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'RACE', 'GET'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'CONNECT', 'CONNECT'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'CONECT', 'GET'],
        ];
    }

    public function testHttpRequestContentType(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $this->setServerVar('CONTENT_TYPE', 'application/xhtml+xml');

        $expected = 'application/xhtml+xml';
        $actual   = $request->getContentType();
        $I->assertEquals($expected, $actual);

        $this->unsetServerVar('CONTENT_TYPE');

        $this->setServerVar('HTTP_CONTENT_TYPE', 'application/xhtml+xml');

        $expected = 'application/xhtml+xml';
        $actual   = $request->getContentType();
        $I->assertEquals($expected, $actual);
        $this->unsetServerVar('HTTP_CONTENT_TYPE');
    }

    public function testHttpRequestAcceptableContent(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $_SERVER['HTTP_ACCEPT'] = 'text/html,application/xhtml+xml,application/xml;'
            . 'q=0.9,*/*;q=0.8,application/json; level=2; q=0.7';
        $accept                 = $request->getAcceptableContent();
        $I->assertCount(5, $accept);

        $firstAccept = $accept[0];
        $I->assertEquals($firstAccept['accept'], 'text/html');
        $I->assertEquals($firstAccept['quality'], 1);

        $fourthAccept = $accept[3];
        $I->assertEquals($fourthAccept['accept'], '*/*');
        $I->assertEquals($fourthAccept['quality'], 0.8);

        $lastAccept = $accept[4];
        $I->assertEquals($lastAccept['accept'], 'application/json');
        $I->assertEquals($lastAccept['quality'], 0.7);
        $I->assertEquals($lastAccept['level'], 2);

        $I->assertEquals($request->getBestAccept(), 'text/html');
    }

    public function testHttpRequestAcceptableCharsets(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $_SERVER['HTTP_ACCEPT_CHARSET'] = 'iso-8859-5,unicode-1-1;q=0.8';
        $accept                         = $request->getClientCharsets();
        $I->assertCount(2, $accept);

        $firstAccept = $accept[0];
        $I->assertEquals($firstAccept['charset'], 'iso-8859-5');
        $I->assertEquals($firstAccept['quality'], 1);

        $lastAccept = $accept[1];
        $I->assertEquals($lastAccept['charset'], 'unicode-1-1');
        $I->assertEquals($lastAccept['quality'], 0.8);

        $I->assertEquals($request->getBestCharset(), 'iso-8859-5');
    }

    public function testHttpRequestAcceptableLanguage(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $_SERVER['HTTP_ACCEPT_LANGUAGE'] = 'es,es-ar;q=0.8,en;q=0.5,en-us;q=0.3,de-de; q=0.9';
        $accept                          = $request->getLanguages();
        $I->assertCount(5, $accept);

        $firstAccept = $accept[0];
        $I->assertEquals($firstAccept['language'], 'es');
        $I->assertEquals($firstAccept['quality'], 1);

        $fourthAccept = $accept[3];
        $I->assertEquals($fourthAccept['language'], 'en-us');
        $I->assertEquals($fourthAccept['quality'], 0.3);

        $lastAccept = $accept[4];
        $I->assertEquals($lastAccept['language'], 'de-de');
        $I->assertEquals($lastAccept['quality'], 0.9);

        $I->assertEquals($request->getBestLanguage(), 'es');
    }

    public function testHttpRequestClientAddress(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $_SERVER['REMOTE_ADDR']          = '192.168.0.1';
        $_SERVER['HTTP_X_FORWARDED_FOR'] = '192.168.7.21';
        $I->assertEquals($request->getClientAddress(), '192.168.0.1');
        $I->assertEquals($request->getClientAddress(true), '192.168.7.21');

        $_SERVER['REMOTE_ADDR'] = '86.45.89.47, 214.55.34.56';
        $I->assertEquals($request->getClientAddress(), '86.45.89.47');
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/1265
     */
    public function testRequestGetValueByUsingSeveralMethods(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $_REQUEST = $_GET = $_POST = [
            'string' => 'hello',
            'array'  => ['string' => 'world'],
        ];

        // get
        $I->assertEquals('hello', $request->get('string', 'string'));
        $I->assertEquals('hello', $request->get('string', 'string', null, true, true));

        $I->assertEquals(['string' => 'world'], $request->get('array', 'string'));
        $I->assertEquals(null, $request->get('array', 'string', null, true, true));

        // getQuery
        $I->assertEquals('hello', $request->getQuery('string', 'string'));
        $I->assertEquals('hello', $request->getQuery('string', 'string', null, true, true));

        $I->assertEquals(['string' => 'world'], $request->getQuery('array', 'string'));
        $I->assertEquals(null, $request->getQuery('array', 'string', null, true, true));

        // getPost
        $I->assertEquals('hello', $request->getPost('string', 'string'));
        $I->assertEquals('hello', $request->getPost('string', 'string', null, true, true));

        $I->assertEquals(['string' => 'world'], $request->getPost('array', 'string'));
        $I->assertEquals(null, $request->getPost('array', 'string', null, true, true));
    }

    public function testRequestGetQuery(UnitTester $I)
    {
        $_REQUEST = $_GET = $_POST = [
            'id'    => 1,
            'num'   => 'a1a',
            'age'   => 'aa',
            'phone' => '',
        ];

        $functions = ['get', 'getQuery', 'getPost'];
        foreach ($functions as $function) {
            $request = $this->getRequestObject();

            $I->assertEquals(1, $request->$function('id', 'int', 100));
            $I->assertEquals(1, $request->$function('num', 'int', 100));
            $I->assertEmpty($request->$function('age', 'int', 100));
            $I->assertEmpty($request->$function('phone', 'int', 100));
            $I->assertEquals(100, $request->$function('phone', 'int', 100, true));
        }
    }

    /**
     * Tests Request::hasFiles
     *
     * @author Serghei Iakovelv <serghei@phalconphp.com>
     * @since  2016-01-31
     */
    public function testRequestHasFiles(UnitTester $I)
    {
        $examples = $this->filesProvider();

        foreach ($examples as $item) {
            $files          = $item[0];
            $all            = $item[1];
            $onlySuccessful = $item[2];

            $request = $this->getRequestObject();
            $_FILES  = $files;

            $expected = $all;
            $actual   = $request->hasFiles(false);
            $I->assertEquals($expected, $actual);

            $expected = $onlySuccessful;
            $actual   = $request->hasFiles(true);
            $I->assertEquals($expected, $actual);
        }
    }

    private function filesProvider()
    {
        return [
            [
                [
                    'test' => [
                        'name'     => 'name',
                        'type'     => 'text/plain',
                        'size'     => 1,
                        'tmp_name' => 'tmp_name',
                        'error'    => 0,
                    ],
                ],
                1,
                1,
            ],
            [
                [
                    'test' => [
                        'name'     => ['name1', 'name2'],
                        'type'     => ['text/plain', 'text/plain'],
                        'size'     => [1, 1],
                        'tmp_name' => ['tmp_name1', 'tmp_name2'],
                        'error'    => [0, 0],
                    ],
                ],
                2,
                2,
            ],
            [
                [
                    'photo' => [
                        'name'     => [
                            0 => '',
                            1 => '',
                            2 => [0 => '', 1 => '', 2 => ''],
                            3 => [0 => ''],
                            4 => [0 => [0 => '']],
                            5 => [0 => [0 => [0 => [0 => '']]]],
                        ],
                        'type'     => [
                            0 => '',
                            1 => '',
                            2 => [0 => '', 1 => '', 2 => ''],
                            3 => [0 => ''],
                            4 => [0 => [0 => '']],
                            5 => [0 => [0 => [0 => [0 => '']]]],
                        ],
                        'tmp_name' => [
                            0 => '',
                            1 => '',
                            2 => [0 => '', 1 => '', 2 => ''],
                            3 => [0 => ''],
                            4 => [0 => [0 => '']],
                            5 => [0 => [0 => [0 => [0 => '']]]],
                        ],
                        'error'    => [
                            0 => 4,
                            1 => 4,
                            2 => [0 => 4, 1 => 4, 2 => 4],
                            3 => [0 => 4],
                            4 => [0 => [0 => 4]],
                            5 => [0 => [0 => [0 => [0 => 4]]]],
                        ],
                        'size'     => [
                            0 => '',
                            1 => '',
                            2 => [0 => '', 1 => '', 2 => ''],
                            3 => [0 => ''],
                            4 => [0 => [0 => '']],
                            5 => [0 => [0 => [0 => [0 => '']]]],
                        ],
                    ],
                    'test'  => [
                        'name'     => '',
                        'type'     => '',
                        'tmp_name' => '',
                        'error'    => 4,
                        'size'     => 0,
                    ],
                ],
                9,
                0,
            ],
        ];
    }

    /**
     * Tests uploaded files
     *
     * @author Serghei Iakovelv <serghei@phalconphp.com>
     * @since  2016-01-31
     */
    public function testGetUploadedFiles(UnitTester $I)
    {
        $request = $this->getRequestObject();
        $_FILES  = [
            'photo' => [
                'name'     => ['f0', 'f1', ['f2', 'f3'], [[[['f4']]]]],
                'type'     => ['text/plain', 'text/csv', ['image/png', 'image/gif'], [[[['application/octet-stream']]]]],
                'tmp_name' => ['t0', 't1', ['t2', 't3'], [[[['t4']]]]],
                'error'    => [0, 0, [0, 0], [[[[8]]]]],
                'size'     => [10, 20, [30, 40], [[[[50]]]]],
            ],
        ];

        $all        = $request->getUploadedFiles(false);
        $successful = $request->getUploadedFiles(true);

        $I->assertCount(5, $all);
        $I->assertCount(4, $successful);

        for ($i = 0; $i <= 4; ++$i) {
            $I->assertFalse($all[$i]->isUploadedFile());
        }

        $data = ['photo.0', 'photo.1', 'photo.2.0', 'photo.2.1', 'photo.3.0.0.0.0'];
        for ($i = 0; $i <= 4; ++$i) {
            $I->assertEquals($data[$i], $all[$i]->getKey());
        }

        $I->assertEquals('f0', $all[0]->getName());
        $I->assertEquals('f1', $all[1]->getName());
        $I->assertEquals('f2', $all[2]->getName());
        $I->assertEquals('f3', $all[3]->getName());
        $I->assertEquals('f4', $all[4]->getName());

        $I->assertEquals('t0', $all[0]->getTempName());
        $I->assertEquals('t1', $all[1]->getTempName());
        $I->assertEquals('t2', $all[2]->getTempName());
        $I->assertEquals('t3', $all[3]->getTempName());
        $I->assertEquals('t4', $all[4]->getTempName());

        $I->assertEquals('f0', $successful[0]->getName());
        $I->assertEquals('f1', $successful[1]->getName());
        $I->assertEquals('f2', $successful[2]->getName());
        $I->assertEquals('f3', $successful[3]->getName());

        $I->assertEquals('t0', $successful[0]->getTempName());
        $I->assertEquals('t1', $successful[1]->getTempName());
        $I->assertEquals('t2', $successful[2]->getTempName());
        $I->assertEquals('t3', $successful[3]->getTempName());
    }
}
