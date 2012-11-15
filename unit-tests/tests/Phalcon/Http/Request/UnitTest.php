<?php
/**
 * UnitTest.php
 * Http_Request_UnitTest
 *
 * Tests the \Phalcon\Http\Request component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

use \Phalcon\Http\Request as Request;

class Http_Request_UnitTest extends Phalcon_Test_UnitTestCase
{
    private $_request;

    public function setUp()
    {
        parent::setUp();

        $this->_di->set(
            'filter',
            function ()
            {
                return new \Phalcon\Filter();
            }
        );

        $this->_request = new Request();
        $this->_request->setDI($this->_di);
    }

    /**
     * Tests the instance of the object
     */
    public function testInstanceOf()
    {
        $expected = 'Phalcon\Http\Request';

        $this->assertInstanceOf(
            $expected,
            $this->_request,
            'The new object is not of the correct class'
        );
    }

    /**
     * Tests getHeader empty
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testHeaderGetEmpty()
    {
        $expected = '';
        $actual   = $this->_request->getHeader('LOL');

        $this->assertEquals(
            $expected,
            $actual,
            'Empty header does not contain correct data'
        );
    }

    /**
     * Tests getHeader
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testHeaderGet()
    {
        $this->_setServerVar('HTTP_LOL', 'zup');

        $expected = 'zup';
        $actual   = $this->_request->getHeader('LOL');

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
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testIsAjaxDefault()
    {
        $actual = $this->_request->isAjax();

        $this->assertFalse(
            $actual,
            'Default request is Ajax'
        );
    }

    /**
     * Tests isAjax
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testIsAjax()
    {
        $this->_setServerVar('HTTP_X_REQUESTED_WITH', 'XMLHttpRequest');

        $actual = $this->_request->isAjax();

        $this->_unsetServerVar('HTTP_X_REQUESTED_WITH');

        $this->assertTrue(
            $actual,
            'Request is not Ajax'
        );

    }

    /**
     * Tests getScheme default
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testGetSchemeDefault()
    {
        $expected = 'http';
        $actual   = $this->_request->getScheme();

        $this->assertEquals(
            $expected,
            $actual,
            'Default scheme is not http'
        );
    }

    /**
     * Tests getScheme
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testGetScheme()
    {
        $this->_setServerVar('HTTP_HTTPS', 'on');

        $expected = 'https';
        $actual   = $this->_request->getScheme();

        $this->_unsetServerVar('HTTP_HTTPS');

        $this->assertEquals(
            $expected,
            $actual,
            'Scheme is not https'
        );
    }

    /**
     * Tests isSecureRequest default
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testIsSecureRequestDefault()
    {
        $actual = $this->_request->isSecureRequest();

        $this->assertFalse(
            $actual,
            'IsSecureRequest is true'
        );
    }

    /**
     * Tests isSecureRequest
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testIsSecureRequest()
    {
        $this->_setServerVar('HTTP_HTTPS', 'on');

        $actual = $this->_request->isSecureRequest();

        $this->_unsetServerVar('HTTP_HTTPS');

        $this->assertTrue(
            $actual,
            'IsSecureRequest is not true'
        );
    }

    /**
     * Tests getServerAddress default
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testGetServerAddressDefault()
    {
        $expected = '127.0.0.1';
        $actual   = $this->_request->getServerAddress();

        $this->assertEquals(
            $expected,
            $actual,
            'Default server address is not 127.0.0.1'
        );
    }

    /**
     * Tests getServerAddress
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testGetServerAddress()
    {
        $this->_setServerVar('SERVER_ADDR', '192.168.4.1');

        $expected = '192.168.4.1';
        $actual   = $this->_request->getServerAddress();

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
        $this->assertFalse($this->_request->hasPost('test'));

        $value = $this->_request->getPost('test');
        $this->assertEquals($value, '');

        $_POST['test'] = 1;
        $value = $this->_request->getPost('test');
        $this->assertEquals($value, 1);

        $_POST['test'] = "lol<";
        $value = $this->_request->getPost('test', 'string');
        $this->assertEquals($value, 'lol');

        $_POST['test'] = "lol<";
        $value = $this->_request->getPost('test', array('string'));
        $this->assertEquals($value, 'lol');

        $this->assertTrue($this->_request->hasPost('test'));

        /** GET */
        $this->assertFalse($this->_request->hasQuery('test'));

        $value = $this->_request->getQuery('test');
        $this->assertEquals($value, '');

        $_GET['test'] = 1;
        $value = $this->_request->getQuery('test');
        $this->assertEquals($value, 1);

        $_GET['test'] = "lol<";
        $value = $this->_request->getQuery('test', 'string');
        $this->assertEquals($value, 'lol');

        $_GET['test'] = "lol<";
        $value = $this->_request->getQuery('test', array('string'));
        $this->assertEquals($value, 'lol');

        $this->assertTrue($this->_request->hasQuery('test'));

        /** REQUEST */
        $this->assertFalse($this->_request->has('test'));

        $value = $this->_request->get('lol');
        $this->assertEquals($value, '');

        $_REQUEST['test'] = 1;
        $value = $this->_request->get('test');
        $this->assertEquals($value, 1);

        $_REQUEST['test'] = "lol<";
        $value = $this->_request->get('test', 'string');
        $this->assertEquals($value, 'lol');

        $_REQUEST['test'] = "lol<";
        $value = $this->_request->get('test', array('string'));
        $this->assertEquals($value, 'lol');

        $this->assertTrue($this->_request->has('test'));
    }

    public function testHttpHost()
    {
        $this->markTestSkipped('Skipped until fixed');

        $_SERVER['HTTP_HTTPS'] = 'off';
        $_SERVER['HTTP_SERVER_NAME'] = 'localhost';
        $_SERVER['HTTP_SERVER_PORT'] = 80;
        $this->assertEquals($this->_request->getHttpHost(), 'localhost');

        $_SERVER['HTTP_HTTPS'] = 'on';
        $_SERVER['HTTP_SERVER_NAME'] = 'localhost';
        $_SERVER['HTTP_SERVER_PORT'] = 80;
        $this->assertEquals($this->_request->getHttpHost(), 'localhost:80');

        $_SERVER['HTTP_HTTPS'] = 'on';
        $_SERVER['HTTP_SERVER_NAME'] = 'localhost';
        $_SERVER['HTTP_SERVER_PORT'] = 443;
        $this->assertEquals($this->_request->getHttpHost(), 'localhost');

    }

    public function testMethod()
    {

        $_SERVER['REQUEST_METHOD'] = 'POST';
        $this->assertEquals($this->_request->getMethod(), 'POST');
        $this->assertTrue($this->_request->isPost());
        $this->assertFalse($this->_request->isGet());

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $this->assertEquals($this->_request->getMethod(), 'GET');
        $this->assertTrue($this->_request->isGet());
        $this->assertFalse($this->_request->isPost());

        $_SERVER['REQUEST_METHOD'] = 'PUT';
        $this->assertEquals($this->_request->getMethod(), 'PUT');
        $this->assertTrue($this->_request->isPut());

        $_SERVER['REQUEST_METHOD'] = 'DELETE';
        $this->assertEquals($this->_request->getMethod(), 'DELETE');
        $this->assertTrue($this->_request->isDelete());

        $_SERVER['REQUEST_METHOD'] = 'OPTIONS';
        $this->assertEquals($this->_request->getMethod(), 'OPTIONS');
        $this->assertTrue($this->_request->isOptions());

        $_SERVER['REQUEST_METHOD'] = 'POST';
        $this->assertTrue($this->_request->isMethod('POST'));
        $this->assertTrue($this->_request->isMethod(array('GET', 'POST')));

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $this->assertTrue($this->_request->isMethod('GET'));
        $this->assertTrue($this->_request->isMethod(array('GET', 'POST')));

    }

    public function testAcceptableContent()
    {

        $_SERVER['HTTP_ACCEPT'] = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8';
        $accept = $this->_request->getAcceptableContent();
        $this->assertEquals(count($accept), 4);

        $firstAccept = $accept[0];
        $this->assertEquals($firstAccept['accept'], 'text/html');
        $this->assertEquals($firstAccept['quality'], 1);

        $lastAccept = $accept[3];
        $this->assertEquals($lastAccept['accept'], '*/*');
        $this->assertEquals($lastAccept['quality'], 0.8);

        $this->assertEquals($this->_request->getBestAccept(), 'text/html');

    }

    public function testAcceptableCharsets()
    {

        $_SERVER['HTTP_ACCEPT_CHARSET'] = 'iso-8859-5,unicode-1-1;q=0.8';
        $accept = $this->_request->getClientCharsets();
        $this->assertEquals(count($accept), 2);

        $firstAccept = $accept[0];
        $this->assertEquals($firstAccept['charset'], 'iso-8859-5');
        $this->assertEquals($firstAccept['quality'], 1);

        $lastAccept = $accept[1];
        $this->assertEquals($lastAccept['charset'], 'unicode-1-1');
        $this->assertEquals($lastAccept['quality'], 0.8);

        $this->assertEquals($this->_request->getBestCharset(), 'iso-8859-5');

    }

    public function testAcceptableLanguage()
    {

        $_SERVER['HTTP_ACCEPT_LANGUAGE'] = 'es,es-ar;q=0.8,en;q=0.5,en-us;q=0.3';
        $accept = $this->_request->getLanguages();
        $this->assertEquals(count($accept), 4);

        $firstAccept = $accept[0];
        $this->assertEquals($firstAccept['language'], 'es');
        $this->assertEquals($firstAccept['quality'], 1);

        $lastAccept = $accept[3];
        $this->assertEquals($lastAccept['language'], 'en-us');
        $this->assertEquals($lastAccept['quality'], 0.3);

        $this->assertEquals($this->_request->getBestLanguage(), 'es');

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