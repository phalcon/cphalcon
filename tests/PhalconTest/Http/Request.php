<?php
/**
 * Request.php
 * \PhalconTest\Http\Request
 *
 * Http Request proxy class
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

use \Phalcon\Http\Request as PhRequest;

class Request
{
    private $request = null;
    
    public function __construct()
    {
        $this->request = new PhRequest();
    }

    public function __desctruct()
    {
        unset($this->request);
    }

    public function setDI($di)
	{
        $this->request->setDI($di);
	}

    public function getDI()
	{
        return $this->request->getDI();
	}

	public function get($name = null, $filters = null, $defaultValue = null, $notAllowEmpty = false, $noRecursive = false)
	{
        return $this->request->get($name, $filters, $defaultValue, $notAllowEmpty, $noRecursive);
	}

	public function getPost($name = null, $filters = null, $defaultValue = null, $notAllowEmpty = false, $noRecursive = false)
	{
        return $this->request->getPost($name, $filters, $defaultValue, $notAllowEmpty, $noRecursive);
	}

	public function getQuery($name = null, $filters = null, $defaultValue = null, $notAllowEmpty = false, $noRecursive = false)
	{
        return $this->request->getQuery($name, $filters, $defaultValue, $notAllowEmpty, $noRecursive);
	}

	public function getServer($name)
	{
        return $this->request->getServer($name);
	}

	public function has($name)
	{
        return $this->request->has($name);
	}

	public function hasPost($name)
	{
        return $this->request->hasPost($name);
	}

	public function hasQuery($name)
	{
        return $this->request->hasQuery($name);
	}

	public final function hasServer($name)
	{
        return $this->request->hasServer($name);
	}

	public final function getHeader($header)
	{
        return $this->request->getHeader($header);
	}

	public function getScheme()
	{
        return $this->request->getScheme();
	}

	public function isAjax()
	{
        return $this->request->isAjax();
	}

	public function isSoapRequested()
	{
        return $this->request->isSoapRequest();
	}

	public function isSecureRequest()
	{
        return $this->request->isSecureRequest();
	}

	public function getRawBody()
	{
        return $this->request->getRawBody();
	}

	public function getJsonRawBody()
    {
        return $this->request->getJsonRawBody();
	}

	public function getServerAddress()
	{
        return $this->request->getServerAddress();
	}

	public function getServerName()
	{
        return $this->request->getServerName();
	}

	public function getHttpHost()
	{
        return $this->request->getHttpHost();
	}

	public function getClientAddress($trustForwardedHeader = false)
	{
        return $this->request->getClientAddress($trustForwardedHeader);
	}

	public final function getMethod()
	{
        return $this->request->getMethod();
	}

	public function getUserAgent()
	{
        return $this->request->getUserAgent();
	}

	public function isMethod($methods)
	{
        return $this->request->isMethod($methods);
	}

	public function isPost()
	{
        return $this->request->isPost();
	}

	public function isGet()
	{
        return $this->request->isGet();
	}

	public function isPut()
	{
        return $this->request->isPut();
	}

	public function isPatch()
	{
        return $this->request->isPatch();
	}

	public function isHead()
	{
        return $this->request->isHead();
	}

	public function isDelete()
	{
        return $this->request->isDelete();
	}

	public function isOptions()
	{
        return $this->request->isOptions();
	}

	public function hasFiles($onlySuccessful = false)
	{
        return $this->request->hasFiles($onlySuccessful);
	}

	private function hasFileHelper($data, $onlySuccessful)
	{
        return $this->request->hasFileHeader($data, $onlySuccessful);
	}

	public function getUploadedFiles($notErrored = false)
	{
        return $this->request->getUploadedFiles($notErrored);
	}

	public function getHeaders()
	{
        return $this->request->getHeaders();
	}

	public function getHTTPReferer()
	{
        return $this->request->getHTTPReferer();
	}

	public function getAcceptableContent()
    {
        return $this->request->getAcceptableContent();
	}

	public function getBestAccept()
	{
        return $this->request->getBestAccept();
	}

	public function getClientCharsets()
    {
        return $this->request->getClientCharsets();
	}

	public function getBestCharset()
	{
        return $this->request->getBestCharset();
	}

	public function getLanguages()
	{
        return $this->request->getLanguages();
	}

	public function getBestLanguage()
	{
        return $this->request->getBestLanguage();
	}


	public function getBasicAuth()
    {
        return $this->request->getBasicAuth();
	}

	public function getDigestAuth()
	{
        return $this->request->getDigestAuth();
	}
}
