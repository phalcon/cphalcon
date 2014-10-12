<?php
/**
 * Response.php
 * \PhalconTest\Http\Response
 *
 * Http Response proxy class
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

namespace PhalconTest\Http;

use Phalcon\Http\Response as PhResponse;

class Response
{
    private $response = null;
    
    public function __construct($content = null, $code = null, $status = null)
    {
        $this->response = new PhResponse($content, $code, $status);
    }

    public function __desctruct()
    {
        unset($this->response);
    }

    public function setDI($di)
	{
		$this->response->setDI($di);
	}

    public function getDI()
	{
        return $this->response->getDI();
	}

	public function setStatusCode($code, $message)
	{
        $this->response->setStatusCode($code, $message);
        return $this;
	}

	public function setHeaders($headers)
	{
        $this->response->setHeaders($headers);
        return $this;
	}

	public function getHeaders()
	{
        return $this->response->getHeaders();
	}

	public function setCookies($cookies)
	{
        $this->response->setCookies($cookies);
        return $this;
	}

	public function getCookies()
	{
        return $this->response->getCookies();
	}

	public function setHeader($name, $value)
	{
        $this->response->setHeader($name, $value);
        return $this;
	}

	public function setRawHeader($header)
	{
        $this->response->setRawHeader($header);
        return $this;
	}

	public function resetHeaders()
	{
        $this->response->resetHeaders();
        return $this;
	}

	public function setExpires($datetime)
	{
        $this->response->setExpires($datetime);
        return $this;
	}

	public function setNotModified()
	{
        $this->response->setNotModified();
        return $this;
	}

	public function setContentType($contentType, $charset = null)
	{
        $this->response->setContentType($contentType, $charset);
        return $this;
	}

	public function setEtag($etag)
	{
        $this->response->setEtag($etag);
		return $this;
	}

	public function redirect($location = null, $externalRedirect = false, $statusCode = 302)
	{
        $this->response->redirect($location, $externalRedirect, $statusCode);
		return $this;
	}

	public function setContent($content)
	{
        $this->response->setContent($content);
		return $this;
	}

	public function setJsonContent($content, $jsonOptions = 0)
	{
        $this->response->setJsonContent($content, $jsonOptions);
		return $this;
	}

	public function appendContent($content)
	{
        $this->response->appendContent($content);
		return $this;
	}

	public function getContent()
	{
        return $this->response->getContent();
	}

	public function isSent()
	{
        return $this->response->isSent();
	}

	public function sendHeaders()
	{
        $this->response->sendHeaders();
		return $this;
	}

	public function sendCookies()
	{
        $this->response->sendCookies();
		return $this;
	}

	public function send()
	{
        $this->response->send();
		return $this;
	}

	public function setFileToSend($filePath, $attachmentName = null, $attachment = true)
	{
        $this->response->setFileToSend($filePath, $attachmentName, $attachment);
		return $this;
	}
}
