<?php
/**
 * UnitTest.php
 * Http_Request_UnitTest
 *
 * Tests the \Phalcon\Http\Request component
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

namespace Phalcon\Test\Http\Request;

use \Phalcon\Test\UnitTestCase as PhTestUnitTestCase;

use \Phalcon\Http\Request as PhRequest;

class UnitTest extends PhTestUnitTestCase
{
    private $request;

    public function setUp()
    {
        parent::setUp();

        $this->di->set(
            'filter',
            function () {
                return new \Phalcon\Filter();
            }
        );

        $this->request = new PhRequest();
        $this->request->setDI($this->di);
    }

    /**
     * Tests the instance of the object
     */
    public function testInstanceOf()
    {
        $expected = 'Phalcon\Http\Request';

        $this->assertInstanceOf(
            $expected,
            $this->request,
            'The new object is not of the correct class'
        );
    }

    /**
     * Tests getHeader empty
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testHeaderGetEmpty()
    {
        $expected = '';
        $actual   = $this->request->getHeader('LOL');

        $this->assertEquals(
            $expected,
            $actual,
            'Empty header does not contain correct data'
        );
    }

    /**
     * Tests getHeader
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testHeaderGet()
    {
        $this->_setServerVar('HTTP_LOL', 'zup');

        $expected = 'zup';
        $actual   = $this->request->getHeader('LOL');

        $this->_unsetServerVar('HTTP_LOL');

        $this->assertEquals(
            $expected,
            $actual,
            'Header does not contain correct data'
        );
    }

    /**
     * Tests isAjax default
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testIsAjaxDefault()
    {
        $actual = $this->request->isAjax();

        $this->assertFalse(
            $actual,
            'Default request is Ajax'
        );
    }

    /**
     * Tests isAjax
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testIsAjax()
    {
        $this->_setServerVar('HTTP_X_REQUESTED_WITH', 'XMLHttpRequest');

        $actual = $this->request->isAjax();

        $this->_unsetServerVar('HTTP_X_REQUESTED_WITH');

        $this->assertTrue(
            $actual,
            'Request is not Ajax'
        );

    }

    /**
     * Tests getScheme default
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testGetSchemeDefault()
    {
        $expected = 'http';
        $actual   = $this->request->getScheme();

        $this->assertEquals(
            $expected,
            $actual,
            'Default scheme is not http'
        );
    }

    /**
     * Tests getScheme
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testGetScheme()
    {
        $this->_setServerVar('HTTPS', 'on');

        $expected = 'https';
        $actual   = $this->request->getScheme();

        $this->_unsetServerVar('HTTPS');

        $this->assertEquals(
            $expected,
            $actual,
            'Scheme is not https'
        );
    }

    /**
     * Tests isSecureRequest default
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testIsSecureRequestDefault()
    {
        $actual = $this->request->isSecureRequest();

        $this->assertFalse(
            $actual,
            'IsSecureRequest is true'
        );
    }

    /**
     * Tests isSecureRequest
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testIsSecureRequest()
    {
        $this->_setServerVar('HTTPS', 'on');

        $actual = $this->request->isSecureRequest();

        $this->_unsetServerVar('HTTPS');

        $this->assertTrue(
            $actual,
            'IsSecureRequest is not true'
        );
    }

    /**
     * Tests getServerAddress default
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testGetServerAddressDefault()
    {
        $expected = '127.0.0.1';
        $actual   = $this->request->getServerAddress();

        $this->assertEquals(
            $expected,
            $actual,
            'Default server address is not 127.0.0.1'
        );
    }

    /**
     * Tests getServerAddress
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testGetServerAddress()
    {
        $this->_setServerVar('SERVER_ADDR', '192.168.4.1');

        $expected = '192.168.4.1';
        $actual   = $this->request->getServerAddress();

        $this->_unsetServerVar('SERVER_ADDR');

        $this->assertEquals(
            $expected,
            $actual,
            'Server address is not correct'
        );
    }

    public function testInput()
    {

        /** POST */
        $this->assertFalse($this->request->hasPost('test'));

        $value = $this->request->getPost('test');
        $this->assertEquals($value, '');

        $_POST['test'] = 1;
        $value = $this->request->getPost('test');
        $this->assertEquals($value, 1);

        $_POST['test'] = "lol<";
        $value = $this->request->getPost('test', 'string');
        $this->assertEquals($value, 'lol');

        $_POST['test'] = "lol<";
        $value = $this->request->getPost('test', array('string'));
        $this->assertEquals($value, 'lol');

        $this->assertTrue($this->request->hasPost('test'));

        /** GET */
        $this->assertFalse($this->request->hasQuery('test'));

        $value = $this->request->getQuery('test');
        $this->assertEquals($value, '');

        $_GET['test'] = 1;
        $value = $this->request->getQuery('test');
        $this->assertEquals($value, 1);

        $_GET['test'] = "lol<";
        $value = $this->request->getQuery('test', 'string');
        $this->assertEquals($value, 'lol');

        $_GET['test'] = "lol<";
        $value = $this->request->getQuery('test', array('string'));
        $this->assertEquals($value, 'lol');

        $this->assertTrue($this->request->hasQuery('test'));

        /** REQUEST */
        $this->assertFalse($this->request->has('test'));

        $value = $this->request->get('lol');
        $this->assertEquals($value, '');

        $_REQUEST['test'] = 1;
        $value = $this->request->get('test');
        $this->assertEquals($value, 1);

        $_REQUEST['test'] = "lol<";
        $value = $this->request->get('test', 'string');
        $this->assertEquals($value, 'lol');

        $_REQUEST['test'] = "lol<";
        $value = $this->request->get('test', array('string'));
        $this->assertEquals($value, 'lol');

        $this->assertTrue($this->request->has('test'));
    }

    public function testHttpHost()
    {
        $_SERVER['HTTPS'] = 'off';
        $_SERVER['SERVER_NAME'] = 'localhost';
        $_SERVER['SERVER_PORT'] = 80;
        $this->assertEquals($this->request->getHttpHost(), 'localhost');

        $_SERVER['HTTPS'] = 'on';
        $_SERVER['SERVER_NAME'] = 'localhost';
        $_SERVER['SERVER_PORT'] = 80;
        $this->assertEquals($this->request->getHttpHost(), 'localhost:80');

        $_SERVER['HTTPS'] = 'on';
        $_SERVER['SERVER_NAME'] = 'localhost';
        $_SERVER['SERVER_PORT'] = 443;
        $this->assertEquals($this->request->getHttpHost(), 'localhost');

    }

    public function testMethod()
    {

        $_SERVER['REQUEST_METHOD'] = 'POST';
        $this->assertEquals($this->request->getMethod(), 'POST');
        $this->assertTrue($this->request->isPost());
        $this->assertFalse($this->request->isGet());

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $this->assertEquals($this->request->getMethod(), 'GET');
        $this->assertTrue($this->request->isGet());
        $this->assertFalse($this->request->isPost());

        $_SERVER['REQUEST_METHOD'] = 'PUT';
        $this->assertEquals($this->request->getMethod(), 'PUT');
        $this->assertTrue($this->request->isPut());

        $_SERVER['REQUEST_METHOD'] = 'DELETE';
        $this->assertEquals($this->request->getMethod(), 'DELETE');
        $this->assertTrue($this->request->isDelete());

        $_SERVER['REQUEST_METHOD'] = 'OPTIONS';
        $this->assertEquals($this->request->getMethod(), 'OPTIONS');
        $this->assertTrue($this->request->isOptions());

        $_SERVER['REQUEST_METHOD'] = 'POST';
        $this->assertTrue($this->request->isMethod('POST'));
        $this->assertTrue($this->request->isMethod(array('GET', 'POST')));

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $this->assertTrue($this->request->isMethod('GET'));
        $this->assertTrue($this->request->isMethod(array('GET', 'POST')));

    }

    public function testAcceptableContent()
    {

        $_SERVER['HTTP_ACCEPT'] = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8';
        $accept = $this->request->getAcceptableContent();
        $this->assertEquals(count($accept), 4);

        $firstAccept = $accept[0];
        $this->assertEquals($firstAccept['accept'], 'text/html');
        $this->assertEquals($firstAccept['quality'], 1);

        $lastAccept = $accept[3];
        $this->assertEquals($lastAccept['accept'], '*/*');
        $this->assertEquals($lastAccept['quality'], 0.8);

        $this->assertEquals($this->request->getBestAccept(), 'text/html');

    }

    public function testAcceptableCharsets()
    {

        $_SERVER['HTTP_ACCEPT_CHARSET'] = 'iso-8859-5,unicode-1-1;q=0.8';
        $accept = $this->request->getClientCharsets();
        $this->assertEquals(count($accept), 2);

        $firstAccept = $accept[0];
        $this->assertEquals($firstAccept['charset'], 'iso-8859-5');
        $this->assertEquals($firstAccept['quality'], 1);

        $lastAccept = $accept[1];
        $this->assertEquals($lastAccept['charset'], 'unicode-1-1');
        $this->assertEquals($lastAccept['quality'], 0.8);

        $this->assertEquals($this->request->getBestCharset(), 'iso-8859-5');

    }

    public function testAcceptableLanguage()
    {

        $_SERVER['HTTP_ACCEPT_LANGUAGE'] = 'es,es-ar;q=0.8,en;q=0.5,en-us;q=0.3';
        $accept = $this->request->getLanguages();
        $this->assertEquals(count($accept), 4);

        $firstAccept = $accept[0];
        $this->assertEquals($firstAccept['language'], 'es');
        $this->assertEquals($firstAccept['quality'], 1);

        $lastAccept = $accept[3];
        $this->assertEquals($lastAccept['language'], 'en-us');
        $this->assertEquals($lastAccept['quality'], 0.3);

        $this->assertEquals($this->request->getBestLanguage(), 'es');

    }

    public function testClientAddress()
    {
        $_SERVER['REMOTE_ADDR'] = '192.168.0.1';
        $_SERVER['HTTP_X_FORWARDED_FOR'] = '192.168.7.21';
        $this->assertEquals($this->request->getClientAddress(), '192.168.0.1');
        $this->assertEquals($this->request->getClientAddress(true), '192.168.7.21');

        $_SERVER['REMOTE_ADDR'] = '86.45.89.47, 214.55.34.56';
        $this->assertEquals($this->request->getClientAddress(), '86.45.89.47');
    }

    private function _setServerVar($var, $value)
    {
        $_SERVER[$var] = $value;
    }

    private function _unsetServerVar($var)
    {
        unset($_SERVER[$var]);
    }

}