<?php

namespace Phalcon\Test\Unit\Http;

use Phalcon\DiInterface;
use Phalcon\Http\Request;
use Helper\Http\PhpStream;
use Phalcon\Test\Unit\Http\Helper\HttpBase;

/**
 * \Phalcon\Test\Unit\Http\RequestTest
 * Tests the \Phalcon\Http\Request component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Http
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class RequestTest extends HttpBase
{
    /**
     * Tests the getDI
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-23
     */
    public function testHttpRequestGetDI()
    {
        $request = $this->getRequestObject();

        expect($request->getDI() instanceof DiInterface)->true();
    }

    /**
     * Tests the instance of the object
     */
    public function testHttpRequestInstanceOf()
    {
        $this->specify(
            "The new object is not the correct class",
            function () {
                expect($this->getRequestObject() instanceof Request)->true();
            }
        );
    }

    /**
     * Tests getHeader empty
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestHeaderGetEmpty()
    {
        $this->specify(
            "Empty header does not contain correct data",
            function () {
                $request = $this->getRequestObject();

                expect($request->getHeader('LOL'))->isEmpty();
            }
        );
    }

    /**
     * Tests getHeader
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestHeaderGet()
    {
        $this->specify(
            "Empty header does not contain correct data",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('HTTP_LOL', 'zup');
                $actual = $request->getHeader('LOL');
                $this->unsetServerVar('HTTP_LOL');

                expect($actual)->equals('zup');
            }
        );
    }

    /**
     * Tests getHeader
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2294
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-10-19
     */
    public function testHttpRequestCustomHeaderGet()
    {
        $this->specify(
            "getHeaders does not returns correct header values",
            function () {
                $_SERVER['HTTP_FOO'] = 'Bar';
                $_SERVER['HTTP_BLA_BLA'] = 'boo';
                $_SERVER['HTTP_AUTH'] = true;

                $request = $this->getRequestObject();

                expect($request->getHeaders())->equals(['Foo' => 'Bar', 'Bla-Bla' => 'boo', 'Auth' => 1]);
            }
        );
    }

    /**
     * Tests hasHeader
     *
     * @author limx <715557344@qq.com>
     * @since  2017-10-26
     */
    public function testHttpRequestCustomHeaderHas()
    {
        $this->specify(
            "hasHeader does not returns correct result",
            function () {
                $_SERVER['HTTP_FOO'] = 'Bar';
                $_SERVER['HTTP_AUTH'] = true;

                $request = $this->getRequestObject();

                expect($request->hasHeader('HTTP_FOO'))->true();
                expect($request->hasHeader('AUTH'))->true();
                expect($request->hasHeader('HTTP_FOO'))->true();
            }
        );
    }

    /**
     * Tests isAjax default
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestIsAjaxDefault()
    {
        $this->specify(
            "Default request is Ajax",
            function () {
                $request = $this->getRequestObject();

                expect($request->isAjax())->false();
            }
        );
    }

    /**
     * Tests isAjax
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestIsAjax()
    {
        $this->specify(
            "Request is not Ajax",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('HTTP_X_REQUESTED_WITH', 'XMLHttpRequest');
                $actual = $request->isAjax();
                $this->unsetServerVar('HTTP_X_REQUESTED_WITH');

                expect($actual)->true();
            }
        );
    }

    /**
     * Tests getScheme default
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestGetSchemeDefault()
    {
        $this->specify(
            "Default scheme is not http",
            function () {
                $request = $this->getRequestObject();

                expect($request->getScheme())->equals('http');
            }
        );
    }

    /**
     * Tests getScheme with HTTPS
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestGetScheme()
    {
        $this->specify(
            "Scheme is not https",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('HTTPS', 'on');
                $actual = $request->getScheme();
                $this->unsetServerVar('HTTPS');

                expect($actual)->equals('https');
            }
        );
    }

    /**
     * Tests isSecureRequest default
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestIsSecureRequestDefault()
    {
        $this->specify(
            "Default isSecureRequest is true",
            function () {
                $request = $this->getRequestObject();

                expect($request->isSecureRequest())->false();
            }
        );
    }

    /**
     * Tests isSecureRequest
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestIsSecureRequest()
    {
        $this->specify(
            "isSecureRequest is not true",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('HTTPS', 'on');
                $actual = $request->isSecureRequest();
                $this->unsetServerVar('HTTPS');

                expect($actual)->true();
            }
        );
    }

    /**
     * Tests isSoapRequested default
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-23
     */
    public function testHttpRequestIsSoapRequestedDefault()
    {
        $this->specify(
            "Default isSoapRequest is true",
            function () {
                $request = $this->getRequestObject();

                expect($request->isSoapRequested())->false();
            }
        );
    }

    /**
     * Tests isSoapRequest
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestIsSoapRequested()
    {
        $this->specify(
            "isSoapRequest is not true",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('CONTENT_TYPE', 'application/soap+xml');
                $actual = $request->isSoapRequested();
                $this->unsetServerVar('CONTENT_TYPE');

                expect($actual)->true();
            }
        );
    }

    /**
     * Tests getServerAddress default
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestGetServerAddressDefault()
    {
        $this->specify(
            "default server address is not 127.0.0.1",
            function () {
                $request = $this->getRequestObject();

                expect($request->getServerAddress())->equals('127.0.0.1');
            }
        );
    }

    /**
     * Tests getServerAddress
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestGetServerAddress()
    {
        $this->specify(
            "server address does not contain correct IP",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('SERVER_ADDR', '192.168.4.1');
                $actual = $request->getServerAddress();
                $this->unsetServerVar('SERVER_ADDR');

                expect($actual)->equals('192.168.4.1');
            }
        );
    }

    /**
     * Tests getHttpHost
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestHttpHost()
    {
        $this->specify(
            "http host with empty server values does not return empty string",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('HTTP_HOST', '');
                $this->setServerVar('SERVER_NAME', '');
                $this->setServerVar('SERVER_ADDR', '');

                expect(is_string($request->getHttpHost()))->true();
                expect($request->getHttpHost())->equals('');
            }
        );

        $this->specify(
            "http host without required server values does not return empty string",
            function () {
                $request = $this->getRequestObject();
                unset($_SERVER['HTTP_HOST'], $_SERVER['SERVER_NAME'], $_SERVER['SERVER_ADDR']);

                expect(is_string($request->getHttpHost()))->true();
                expect($request->getHttpHost())->equals('');
            }
        );

        $this->specify(
            "The Request::getHttpHost without strict validation does not return expected host",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('SERVER_NAME', 'host@name');

                expect($request->getHttpHost())->equals('host@name');
            }
        );

        $this->specify(
            "http host without http does not contain correct data",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('HTTPS', 'off');
                $this->setServerVar('SERVER_NAME', 'localhost');
                $this->setServerVar('SERVER_PORT', 80);

                expect($request->getHttpHost())->equals('localhost');
            }
        );

        $this->specify(
            "http host with http does not contain correct data",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('HTTPS', 'on');
                $this->setServerVar('SERVER_NAME', 'localhost');
                $this->setServerVar('SERVER_PORT', 80);

                expect($request->getHttpHost())->equals('localhost');
            }
        );

        $this->specify(
            "http host with https and 443 port does not contain correct data",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('HTTPS', 'on');
                $this->setServerVar('SERVER_NAME', 'localhost');
                $this->setServerVar('SERVER_PORT', 443);

                expect($request->getHttpHost())->equals('localhost');
            }
        );

        $this->specify(
            "http host with SERVER_ADDR value does not return expected host name",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('HTTP_HOST', '');
                $this->setServerVar('SERVER_NAME', '');
                $this->setServerVar('SERVER_ADDR', '8.8.8.8');

                expect($request->getHttpHost())->equals('8.8.8.8');
            }
        );

        $this->specify(
            "http host with SERVER_NAME value does not return expected host name",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('HTTP_HOST', '');
                $this->setServerVar('SERVER_NAME', 'some.domain');
                $this->setServerVar('SERVER_ADDR', '8.8.8.8');

                expect($request->getHttpHost())->equals('some.domain');
            }
        );

        $this->specify(
            "http host with HTTP_HOST value does not return expected host name",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('HTTP_HOST', 'example.com');
                $this->setServerVar('SERVER_NAME', 'some.domain');
                $this->setServerVar('SERVER_ADDR', '8.8.8.8');

                expect($request->getHttpHost())->equals('example.com');
            }
        );
    }

    /**
     * Tests strict host check
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-26
     */
    public function testHttpStrictHostCheck()
    {
        $this->specify(
            "http host with strict param does not return does not return valid host name",
            function () {
                $request = $this->getRequestObject();
                $request->setStrictHostCheck(true);
                $this->setServerVar('SERVER_NAME', 'LOCALHOST:80');

                expect($request->getHttpHost())->equals('localhost');
            }
        );

        $this->specify(
            "http host with strict param does not return does not return valid host name",
            function () {
                $request = $this->getRequestObject();
                $request->setStrictHostCheck(false);
                $this->setServerVar('SERVER_NAME', 'LOCALHOST:80');

                expect($request->getHttpHost())->equals('LOCALHOST:80');
            }
        );

        $this->specify(
            "The Request::isStrictHostCheck does not return expected value",
            function () {
                $request = $this->getRequestObject();

                expect($request->isStrictHostCheck())->false();

                $request->setStrictHostCheck(true);
                expect($request->isStrictHostCheck())->true();

                $request->setStrictHostCheck(false);
                expect($request->isStrictHostCheck())->false();
            }
        );
    }

    /**
     * Tests Request::getPort
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-26
     */
    public function testHttpRequestPort()
    {
        $this->specify(
            "http host with https on does not return expected port",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('HTTPS', 'on');
                $this->setServerVar('HTTP_HOST', 'example.com');

                expect($request->getPort())->equals(443);
            }
        );

        $this->specify(
            "http host with https off does not return expected port",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('HTTPS', 'off');
                $this->setServerVar('HTTP_HOST', 'example.com');

                expect($request->getPort())->equals(80);
            }
        );

        $this->specify(
            "http host with port on HTTP_HOST does not return expected port",
            function () {
                $request = $this->getRequestObject();
                $this->setServerVar('HTTPS', 'off');
                $this->setServerVar('HTTP_HOST', 'example.com:8080');

                expect($request->getPort())->equals(8080);

                $this->setServerVar('HTTPS', 'on');
                $this->setServerVar('HTTP_HOST', 'example.com:8081');

                expect($request->getPort())->equals(8081);

                unset($_SERVER['HTTPS']);
                $this->setServerVar('HTTP_HOST', 'example.com:8082');

                expect($request->getPort())->equals(8082);
            }
        );
    }

    /**
     * Tests getHttpHost by using invalid host
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-26
     */
    public function testInvalidHttpRequestHttpHost()
    {
        $this->specify(
            "The Request::getHttpHost does not throws exception on strict host validation",
            function ($host) {
                $request = $this->getRequestObject();
                $request->setStrictHostCheck(true);

                $this->setServerVar('HTTP_HOST', $host);
                $request->getHttpHost();
            },
            [
                'throws' => 'UnexpectedValueException',
                'examples' => [
                    ['foo±bar±baz'],
                    ['foo~bar~baz'],
                    ['<foo-bar-baz>'],
                    ['foo=bar=baz'],
                    ['foobar/baz'],
                    ['foo@bar'],
                ]
            ]
        );
    }

    /**
     * Tests POST functions
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestInputPost()
    {
        $this->specify(
            "hasPost for empty element returns incorrect results",
            function () {
                $this->hasEmpty('hasPost');
            }
        );

        $this->specify(
            "hasPost for set element returns incorrect results",
            function () {
                $this->hasNotEmpty('hasPost', 'setPostVar');
            }
        );

        $this->specify(
            "getPost for empty element returns incorrect results",
            function () {
                $this->getEmpty('getPost');
            }
        );

        $this->specify(
            "getPost returns incorrect results",
            function () {
                $this->getNotEmpty('getPost', 'setPostVar');
            }
        );

        $this->specify(
            "getPost does not return sanitized data",
            function () {
                $this->getSanitized('getPost', 'setPostVar');
            }
        );

        $this->specify(
            "getPost with array as filter does not return sanitized data",
            function () {
                $this->getSanitizedArrayFilter('getPost', ['string'], 'setPostVar');
            }
        );
    }

    /**
     * Tests getPut with json content type.
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/13418
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-06-03
     */
    public function shouldGetDataReceivedByPutMethod()
    {
        $this->specify(
            'The getPuth method does not owrk as expected',
            function () {
                stream_wrapper_unregister('php');
                stream_wrapper_register('php', PhpStream::class);

                file_put_contents('php://input', 'fruit=orange&quantity=4');

                $_SERVER['REQUEST_METHOD'] = 'PUT';

                $request = new Request();

                $data = file_get_contents('php://input');
                $expected = ['fruit' => 'orange', 'quantity' => '4'];

                parse_str($data, $actual);

                expect($actual)->equals($expected);
                expect($request->getPut())->equals($expected);

                stream_wrapper_restore('php');
            }
        );
    }

    /**
     * Tests getPut with json content type.
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/13418
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-06-03
     */
    public function shouldGetDataReceivedByPutMethodAndJsonType()
    {
        $this->specify(
            'The getPuth method does not owrk as expected with json content type',
            function () {
                stream_wrapper_unregister('php');
                stream_wrapper_register('php', PhpStream::class);

                file_put_contents('php://input', '{"fruit": "orange", "quantity": "4"}');

                $_SERVER['REQUEST_METHOD'] = 'PUT';
                $_SERVER['CONTENT_TYPE'] = 'application/json';

                $request = new Request();

                $data = json_decode(file_get_contents('php://input'), true);
                $expected = ['fruit' => 'orange', 'quantity' => '4'];

                expect($data)->equals($expected);
                expect($request->getPut())->equals($expected);

                stream_wrapper_restore('php');
            }
        );
    }

    /**
     * Tests GET functions
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestInputGet()
    {
        $this->specify(
            "hasQuery for empty element returns incorrect results",
            function () {
                $this->hasEmpty('hasQuery');
            }
        );

        $this->specify(
            "hasQuery for set element returns incorrect results",
            function () {
                $this->hasNotEmpty('hasQuery', 'setGetVar');
            }
        );

        $this->specify(
            "getQuery for empty element returns incorrect results",
            function () {
                $this->getEmpty('getQuery');
            }
        );

        $this->specify(
            "getQuery returns incorrect results",
            function () {
                $this->getNotEmpty('getQuery', 'setGetVar');
            }
        );

        $this->specify(
            "getQuery does not return sanitized data",
            function () {
                $this->getSanitized('getQuery', 'setGetVar');
            }
        );

        $this->specify(
            "getQuery with array as filter does not return sanitized data",
            function () {
                $this->getSanitizedArrayFilter('getQuery', ['string'], 'setGetVar');
            }
        );
    }

    /**
     * Tests REQUEST functions
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestInputRequest()
    {
        $this->specify(
            "has for empty element returns incorrect results",
            function () {
                $this->hasEmpty('has');
            }
        );

        $this->specify(
            "has for set element returns incorrect results",
            function () {
                $this->hasNotEmpty('has', 'setRequestVar');
            }
        );

        $this->specify(
            "get for empty element returns incorrect results",
            function () {
                $this->getEmpty('get');
            }
        );

        $this->specify(
            "get returns incorrect results",
            function () {
                $this->getNotEmpty('get', 'setRequestVar');
            }
        );

        $this->specify(
            "get does not return sanitized data",
            function () {
                $this->getSanitized('get', 'setRequestVar');
            }
        );

        $this->specify(
            "get with array as filter does not return sanitized data",
            function () {
                $this->getSanitizedArrayFilter('get', ['string'], 'setRequestVar');
            }
        );
    }

    public function testHttpRequestMethod()
    {
        $request = $this->getRequestObject();

        $_SERVER['REQUEST_METHOD'] = 'POST';
        $this->assertEquals($request->getMethod(), 'POST');
        $this->assertTrue($request->isPost());
        $this->assertFalse($request->isGet());

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $this->assertEquals($request->getMethod(), 'GET');
        $this->assertTrue($request->isGet());
        $this->assertFalse($request->isPost());

        $_SERVER['REQUEST_METHOD'] = 'PUT';
        $this->assertEquals($request->getMethod(), 'PUT');
        $this->assertTrue($request->isPut());

        $_SERVER['REQUEST_METHOD'] = 'DELETE';
        $this->assertEquals($request->getMethod(), 'DELETE');
        $this->assertTrue($request->isDelete());

        $_SERVER['REQUEST_METHOD'] = 'OPTIONS';
        $this->assertEquals($request->getMethod(), 'OPTIONS');
        $this->assertTrue($request->isOptions());

        $_SERVER['REQUEST_METHOD'] = 'POST';
        $this->assertTrue($request->isMethod('POST'));
        $this->assertTrue($request->isMethod(['GET', 'POST']));

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $this->assertTrue($request->isMethod('GET'));
        $this->assertTrue($request->isMethod(['GET', 'POST']));

        $_SERVER['REQUEST_METHOD'] = 'CONNECT';
        $this->assertEquals($request->getMethod(), 'CONNECT');
        $this->assertTrue($request->isConnect());
        $this->assertFalse($request->isGet());

        $_SERVER['REQUEST_METHOD'] = 'TRACE';
        $this->assertEquals($request->getMethod(), 'TRACE');
        $this->assertTrue($request->isTrace());
        $this->assertFalse($request->isGet());

        $_SERVER['REQUEST_METHOD'] = 'PURGE';
        $this->assertEquals($request->getMethod(), 'PURGE');
        $this->assertTrue($request->isPurge());
        $this->assertFalse($request->isGet());
    }

    /**
     * Tests the ability to override the HTTP method
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12478
     * @author Serghei Iakovelv <serghei@phalconphp.com>
     * @since  2016-12-18
     */
    public function shouldOverrideHttpRequestMethod()
    {
        $this->specify(
            'The request object gets http method incorrectly',
            function ($header, $method, $expected) {
                $_SERVER['REQUEST_METHOD'] = 'POST';
                $request = $this->getRequestObject();

                $_SERVER[$header] = $method;
                expect($request->getMethod())->equals($expected);

                $_SERVER[$header] = strtolower($method);
                expect($request->getMethod())->equals($expected);

                $_SERVER[strtolower($header)] = $method;
                expect($request->getMethod())->equals($expected);
            },
            ['examples' => $this->overridedMethodProvider()]
        );
    }

    protected function overridedMethodProvider()
    {
        return [
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'PUT',     'PUT'    ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'PAT',     'GET'    ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'GET',     'GET'    ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'GOT',     'GET'    ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'HEAD',    'HEAD'   ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'HED',     'GET'    ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'POST',    'POST'   ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'PAST',    'GET'    ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'DELETE',  'DELETE' ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'DILETE',  'GET'    ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'OPTIONS', 'OPTIONS'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'OPTION',  'GET'    ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'PATCH',   'PATCH'  ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'PUTCH',   'GET'    ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'PURGE',   'PURGE'  ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'PURG',    'GET'    ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'TRACE',   'TRACE'  ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'RACE',    'GET'    ],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'CONNECT', 'CONNECT'],
            ['HTTP_X_HTTP_METHOD_OVERRIDE', 'CONECT',  'GET'    ],
        ];
    }

    public function testHttpRequestContentType()
    {
        $request = $this->getRequestObject();

        $this->setServerVar('CONTENT_TYPE', 'application/xhtml+xml');
        $contentType = $request->getContentType();
        $this->assertEquals($contentType, 'application/xhtml+xml');
        $this->unsetServerVar('CONTENT_TYPE');

        $this->setServerVar('HTTP_CONTENT_TYPE', 'application/xhtml+xml');
        $contentType = $request->getContentType();
        $this->assertEquals($contentType, 'application/xhtml+xml');
        $this->unsetServerVar('HTTP_CONTENT_TYPE');
    }

    public function testHttpRequestAcceptableContent()
    {
        $request = $this->getRequestObject();

        $_SERVER['HTTP_ACCEPT'] = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8,application/json; level=2; q=0.7';
        $accept = $request->getAcceptableContent();
        $this->assertEquals(count($accept), 5);

        $firstAccept = $accept[0];
        $this->assertEquals($firstAccept['accept'], 'text/html');
        $this->assertEquals($firstAccept['quality'], 1);

        $fourthAccept = $accept[3];
        $this->assertEquals($fourthAccept['accept'], '*/*');
        $this->assertEquals($fourthAccept['quality'], 0.8);

        $lastAccept = $accept[4];
        $this->assertEquals($lastAccept['accept'], 'application/json');
        $this->assertEquals($lastAccept['quality'], 0.7);
        $this->assertEquals($lastAccept['level'], 2);

        $this->assertEquals($request->getBestAccept(), 'text/html');
    }

    public function testHttpRequestAcceptableCharsets()
    {
        $request = $this->getRequestObject();

        $_SERVER['HTTP_ACCEPT_CHARSET'] = 'iso-8859-5,unicode-1-1;q=0.8';
        $accept = $request->getClientCharsets();
        $this->assertEquals(count($accept), 2);

        $firstAccept = $accept[0];
        $this->assertEquals($firstAccept['charset'], 'iso-8859-5');
        $this->assertEquals($firstAccept['quality'], 1);

        $lastAccept = $accept[1];
        $this->assertEquals($lastAccept['charset'], 'unicode-1-1');
        $this->assertEquals($lastAccept['quality'], 0.8);

        $this->assertEquals($request->getBestCharset(), 'iso-8859-5');
    }

    public function testHttpRequestAcceptableLanguage()
    {
        $request = $this->getRequestObject();

        $_SERVER['HTTP_ACCEPT_LANGUAGE'] = 'es,es-ar;q=0.8,en;q=0.5,en-us;q=0.3,de-de; q=0.9';
        $accept = $request->getLanguages();
        $this->assertEquals(count($accept), 5);

        $firstAccept = $accept[0];
        $this->assertEquals($firstAccept['language'], 'es');
        $this->assertEquals($firstAccept['quality'], 1);

        $fourthAccept = $accept[3];
        $this->assertEquals($fourthAccept['language'], 'en-us');
        $this->assertEquals($fourthAccept['quality'], 0.3);

        $lastAccept = $accept[4];
        $this->assertEquals($lastAccept['language'], 'de-de');
        $this->assertEquals($lastAccept['quality'], 0.9);

        $this->assertEquals($request->getBestLanguage(), 'es');
    }

    public function testHttpRequestClientAddress()
    {
        $request = $this->getRequestObject();

        $_SERVER['REMOTE_ADDR'] = '192.168.0.1';
        $_SERVER['HTTP_X_FORWARDED_FOR'] = '192.168.7.21';
        $this->assertEquals($request->getClientAddress(), '192.168.0.1');
        $this->assertEquals($request->getClientAddress(true), '192.168.7.21');

        $_SERVER['REMOTE_ADDR'] = '86.45.89.47, 214.55.34.56';
        $this->assertEquals($request->getClientAddress(), '86.45.89.47');
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/1265
     */
    public function testRequestGetValueByUsingSeveralMethods()
    {
        $request = $this->getRequestObject();

        $_REQUEST = $_GET = $_POST = [
            'string' => 'hello',
            'array' => ['string' => 'world']
        ];

        // get
        $this->assertEquals('hello', $request->get('string', 'string'));
        $this->assertEquals('hello', $request->get('string', 'string', null, true, true));

        $this->assertEquals(['string' => 'world'], $request->get('array', 'string'));
        $this->assertEquals(null, $request->get('array', 'string', null, true, true));

        // getQuery
        $this->assertEquals('hello', $request->getQuery('string', 'string'));
        $this->assertEquals('hello', $request->getQuery('string', 'string', null, true, true));

        $this->assertEquals(['string' => 'world'], $request->getQuery('array', 'string'));
        $this->assertEquals(null, $request->getQuery('array', 'string', null, true, true));

        // getPost
        $this->assertEquals('hello', $request->getPost('string', 'string'));
        $this->assertEquals('hello', $request->getPost('string', 'string', null, true, true));

        $this->assertEquals(['string' => 'world'], $request->getPost('array', 'string'));
        $this->assertEquals(null, $request->getPost('array', 'string', null, true, true));
    }

    public function testRequestGetQuery()
    {
        $_REQUEST = $_GET = $_POST = [
            'id'    => 1,
            'num'   => 'a1a',
            'age'   => 'aa',
            'phone' => ''
        ];

        $this->specify(
            "Request::getQuery does not return correct result",
            function ($function) {
                $request = $this->getRequestObject();

                expect($request->$function('id', 'int', 100))->equals(1);
                expect($request->$function('num', 'int', 100))->equals(1);
                expect($request->$function('age', 'int', 100))->isEmpty();
                expect($request->$function('phone', 'int', 100))->isEmpty();
                expect($request->$function('phone', 'int', 100, true))->equals(100);
            },
            ['examples' => [
                ['get', 'getQuery', 'getPost']
            ]]
        );
    }

    /**
     * Tests Request::hasFiles
     *
     * @author Serghei Iakovelv <serghei@phalconphp.com>
     * @since  2016-01-31
     */
    public function testRequestHasFiles()
    {
        $this->specify(
            "Request::hasFiles does not return correct result",
            function ($files, $all, $onlySuccessful) {
                $request = $this->getRequestObject();

                $_FILES = $files;

                expect($request->hasFiles(false))->equals($all);
                expect($request->hasFiles(true))->equals($onlySuccessful);
            },
            ['examples' => $this->filesProvider()]
        );
    }

    /**
     * Tests uploaded files
     *
     * @author Serghei Iakovelv <serghei@phalconphp.com>
     * @since  2016-01-31
     */
    public function testGetUploadedFiles()
    {
        $this->specify(
            "Request does not handle uploaded files correctly",
            function () {
                $request = $this->getRequestObject();

                $_FILES = [
                    'photo' => [
                        'name'     => ['f0',         'f1',       ['f2',        'f3'],        [[[['f4']]]]],
                        'type'     => ['text/plain', 'text/csv', ['image/png', 'image/gif'], [[[['application/octet-stream']]]]],
                        'tmp_name' => ['t0',         't1',       ['t2',        't3'],        [[[['t4']]]]],
                        'error'    => [0,            0,          [0,           0],           [[[[8]]]]],
                        'size'     => [10,           20,         [30,          40],          [[[[50]]]]],
                    ],
                ];

                $all        = $request->getUploadedFiles(false);
                $successful = $request->getUploadedFiles(true);

                expect($all)->count(5);
                expect($successful)->count(4);

                for ($i=0; $i<=4; ++$i) {
                    expect($all[$i]->isUploadedFile())->false();
                }

                $data = ['photo.0', 'photo.1', 'photo.2.0', 'photo.2.1', 'photo.3.0.0.0.0'];
                for ($i=0; $i<=4; ++$i) {
                    expect($all[$i]->getKey())->equals($data[$i]);
                }

                expect($all[0]->getName())->equals('f0');
                expect($all[1]->getName())->equals('f1');
                expect($all[2]->getName())->equals('f2');
                expect($all[3]->getName())->equals('f3');
                expect($all[4]->getName())->equals('f4');

                expect($all[0]->getTempName())->equals('t0');
                expect($all[1]->getTempName())->equals('t1');
                expect($all[2]->getTempName())->equals('t2');
                expect($all[3]->getTempName())->equals('t3');
                expect($all[4]->getTempName())->equals('t4');

                expect($successful[0]->getName())->equals('f0');
                expect($successful[1]->getName())->equals('f1');
                expect($successful[2]->getName())->equals('f2');
                expect($successful[3]->getName())->equals('f3');

                expect($successful[0]->getTempName())->equals('t0');
                expect($successful[1]->getTempName())->equals('t1');
                expect($successful[2]->getTempName())->equals('t2');
                expect($successful[3]->getTempName())->equals('t3');
            }
        );
    }

    protected function filesProvider()
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
                    ]
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
                    ]
                ],
                2,
                2,
            ],
            [
                [
                    'photo' => [
                        'name' => [
                            0 => '',
                            1 => '',
                            2 => [0 => '', 1 => '', 2 => ''],
                            3 => [0 => ''],
                            4 => [0 => [0 => '']],
                            5 => [0 => [0 => [0 => [0 => '']]]],
                        ],
                        'type' => [
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
                        'error' => [
                            0 => 4,
                            1 => 4,
                            2 => [0 => 4, 1 => 4, 2 => 4],
                            3 => [0 => 4],
                            4 => [0 => [0 => 4]],
                            5 => [0 => [0 => [0 => [0 => 4]]]],
                        ],
                        'size' => [
                            0 => '',
                            1 => '',
                            2 => [0 => '', 1 => '', 2 => ''],
                            3 => [0 => ''],
                            4 => [0 => [0 => '']],
                            5 => [0 => [0 => [0 => [0 => '']]]],
                        ],
                    ],
                    'test' => [
                        'name'     => '',
                        'type'     => '',
                        'tmp_name' => '',
                        'error'    => 4,
                        'size'     => 0,
                    ],
                ],
                9,
                0,
            ]
        ];
    }
}
