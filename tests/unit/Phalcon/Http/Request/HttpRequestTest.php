<?php
/**
 * HttpRequestTest.php
 * \Phalcon\Http\Request\HttpRequestTest
 *
 * Tests the Phalcon\Http\Request component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Http;

class HttpRequestTest extends Helper\HttpBase
{
    /**
     * Tests the getDI
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-23
     *
     * @return PhTResponse
     */
    public function testHttpRequestGetDI()
    {
        $request = $this->getRequestObject();

        $actual = $request->getDI();

        expect($actual instanceof \Phalcon\DIInterface)->true();
    }

    /**
     * Tests the instance of the object
     */
    public function testHttpRequestInstanceOf()
    {
        $this->specify(
            "The new object is not the correct class",
            function () {

                $request = $this->getRequestObject();

                expect($request instanceof \PhalconTest\Http\Request)->true();
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
                $actual  = $request->getHeader('LOL');

                expect($actual)->isEmpty();
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
                $expected = 'zup';
                $actual   = $request->getHeader('LOL');
                $this->unsetServerVar('HTTP_LOL');

                expect($actual)->equals($expected);
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
                $actual = $request->isAjax();

                expect($actual)->false();
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

                $expected = 'http';
                $actual   = $request->getScheme();

                expect($actual)->equals($expected);
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
                $expected = 'https';
                $actual   = $request->getScheme();
                $this->unsetServerVar('HTTPS');

                expect($actual)->equals($expected);
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

                $actual = $request->isSecureRequest();
                expect($actual)->false();
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

                $actual = $request->isSoapRequested();
                expect($actual)->false();
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

                $request  = $this->getRequestObject();
                $expected = '127.0.0.1';
                $actual   = $request->getServerAddress();

                expect($actual)->equals($expected);

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
                $expected = '192.168.4.1';
                $actual   = $request->getServerAddress();
                $this->unsetServerVar('SERVER_ADDR');

                expect($actual)->equals($expected);
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
            "http host without http does not contain correct data",
            function () {

                $request = $this->getRequestObject();

                $this->setServerVar('HTTPS', 'off');
                $this->setServerVar('SERVER_NAME', 'localhost');
                $this->setServerVar('SERVER_PORT', 80);

                $expected = 'localhost';
                $actual   = $request->getHttpHost();

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "http host with http does not contain correct data",
            function () {

                $request = $this->getRequestObject();

                $this->setServerVar('HTTPS', 'on');
                $this->setServerVar('SERVER_NAME', 'localhost');
                $this->setServerVar('SERVER_PORT', 80);

                $expected = 'localhost:80';
                $actual   = $request->getHttpHost();

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "http host with https and 443 port does not contain correct data",
            function () {

                $request = $this->getRequestObject();

                $this->setServerVar('HTTPS', 'on');
                $this->setServerVar('SERVER_NAME', 'localhost');
                $this->setServerVar('SERVER_PORT', 443);

                $expected = 'localhost';
                $actual   = $request->getHttpHost();

                expect($actual)->equals($expected);
            }
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
        $this->assertTrue($request->isMethod(array('GET', 'POST')));

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $this->assertTrue($request->isMethod('GET'));
        $this->assertTrue($request->isMethod(array('GET', 'POST')));

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
}
