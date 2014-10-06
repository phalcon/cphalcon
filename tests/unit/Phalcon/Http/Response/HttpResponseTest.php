<?php
/**
 * HttpResponseTest.php
 * \Phalcon\Http\Request\HttpResponseTest
 *
 * Tests the Phalcon\Http\Response component
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

use \Phalcon\Http\Response\Headers as PhResponseHeaders;

class HttpResponseTest extends Helper\HttpBase
{
    /**
     * Tests the instance of the object
     */
    public function testHttpRequestInstanceOf()
    {
        $this->specify(
            "The new object is not the correct class",
            function () {

                $response = $this->getResponseObject();

                expect($response instanceof \Phalcon\Http\Response)->true();
            }
        );
    }

	public function testSetHeader()
	{
        $this->markTestIncomplete('To be checked');
        $response = $this->getResponseObject();
        
		$response->resetHeaders();

		$response->setHeader('Content-Type', 'text/html');

		$this->assertEquals(PhResponseHeaders::__set_state(array(
			'_headers' => array(
				'Content-Type' => 'text/html',
			)
		)), $response->getHeaders());

		$response->setHeader('Content-Length', '1234');

		$this->assertEquals(PhResponseHeaders::__set_state(array(
			'_headers' => array(
				'Content-Type' => 'text/html',
				'Content-Length' => '1234'
			)
		)), $response->getHeaders());

	}

	public function testSetStatusHeader()
	{
        $this->markTestIncomplete('To be checked');
        $response = $this->getResponseObject();

		$response->resetHeaders();

		$response->setStatusCode(404, "Not Found");

		$this->assertEquals(PhResponseHeaders::__set_state(array(
			'_headers' => array(
				'HTTP/1.1 404 Not Found' => '',
				'Status' => '404 Not Found'
			)
		)), $response->getHeaders());

	}

	public function testSetRawHeader()
	{
        $this->markTestIncomplete('To be checked');
        $response = $this->getResponseObject();

		$response->resetHeaders();

		$response->setRawHeader("HTTP/1.1 404 Not Found");

		$this->assertEquals(PhResponseHeaders::__set_state(array(
			'_headers' => array(
				'HTTP/1.1 404 Not Found' => '',
			)
		)), $response->getHeaders());

	}
	
	public function testToArrayHeader()
	{
        $this->markTestIncomplete('To be checked');
        $response = $this->getResponseObject();

		$response->resetHeaders();

		$response->setHeader('Content-Type', 'text/html');
		$response->setHeader('Content-Length', '1234');
		
		$headers = $response->getHeaders();
		$headersArray = $headers->toArray();
		
		$this->assertArrayHasKey('Content-Type', $headersArray);
		$this->assertArrayHasKey('Content-Length', $headersArray);
		$this->assertEquals('text/html', $headersArray['Content-Type']);
		$this->assertEquals('1234', $headersArray['Content-Length']);
	}

	public function testSetContentType()
	{
        $this->markTestIncomplete('To be checked');
        $response = $this->getResponseObject();

		//Without charset
		$response->resetHeaders();

		$response->setContentType('application/json');

		$this->assertEquals(PhResponseHeaders::__set_state(array(
			'_headers' => array(
				'Content-Type' => 'application/json'
			)
		)), $response->getHeaders());

		//With charset
		$response->resetHeaders();

		$response->setContentType('application/json', 'utf-8');

		$this->assertEquals(PhResponseHeaders::__set_state(array(
			'_headers' => array(
				'Content-Type' => 'application/json; charset=utf-8'
			)
		)), $response->getHeaders());
	}

	public function testNotModifiedHeader()
	{
        $this->markTestIncomplete('To be checked');
        $response = $this->getResponseObject();

		$response->resetHeaders();

		$response->setNotModified();

		$this->assertEquals(PhResponseHeaders::__set_state(array(
			'_headers' => array(
				'HTTP/1.1 304 Not modified' => false,
				'Status' => '304 Not modified'
			)
		)), $response->getHeaders());

	}

	public function testRedirect()
	{
        $this->markTestIncomplete('To be checked');
        $response = $this->getResponseObject();

		//local URI
		$response->resetHeaders();

		$response->redirect("some/local/uri");

		$this->assertEquals(PhResponseHeaders::__set_state(array(
			'_headers' => array(
				'HTTP/1.1 302 Redirect' => false,
				'Status' => '302 Redirect',
				'Location' => '/some/local/uri'
			)
		)), $response->getHeaders());

		//Full URL
		$response->resetHeaders();

		$response->redirect("http://google.com", true);

		$this->assertEquals(PhResponseHeaders::__set_state(array(
			'_headers' => array(
				'HTTP/1.1 302 Redirect' => false,
				'Status' => '302 Redirect',
				'Location' => 'http://google.com'
			)
		)), $response->getHeaders());

		//HTTP code
		$response->resetHeaders();

		$response->redirect("http://google.com", true, 301);

		$this->assertEquals(PhResponseHeaders::__set_state(array(
			'_headers' => array(
				'HTTP/1.1 301 Redirect' => false,
				'Status' => '301 Redirect',
				'Location' => 'http://google.com'
			)
		)), $response->getHeaders());

	}

	public function testContent()
	{
        $this->markTestIncomplete('To be checked');
        $response = $this->getResponseObject();

		$response->setContent('<h1>Hello');
		$this->assertEquals($response->getContent(), '<h1>Hello');

		$response->appendContent('</h1>');
		$this->assertEquals($response->getContent(), '<h1>Hello</h1>');

	}

	public function testSetFileToSend()
	{
        $this->markTestIncomplete('To be checked');
        $response = $this->getResponseObject();

		$filename = __FILE__;
		$response->setFileToSend($filename);
		ob_start();
		$response->send();
		$actual   = ob_get_clean();
		$expected = file_get_contents($filename);
		$this->assertEquals($actual, $expected);
		$this->assertEquals($response->isSent(), true);
	}
}