<?php

namespace Phalcon\Test\Proxy\Http;

use Phalcon\Http\Request as PhRequest;
use Phalcon\DiInterface;

/**
 * \Phalcon\Test\Proxy\Http\Request
 * Http Request proxy class for \Phalcon\Http\Request
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Http
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Request extends PhRequest
{
    public function setDI(DiInterface $di)
    {
        parent::setDI($di);
    }

    public function getDI()
    {
        return parent::getDI();
    }

    public function get($name = null, $filters = null, $defaultValue = null, $notAllowEmpty = false, $noRecursive = false)
    {
        return parent::get($name, $filters, $defaultValue, $notAllowEmpty, $noRecursive);
    }

    public function getPost($name = null, $filters = null, $defaultValue = null, $notAllowEmpty = false, $noRecursive = false)
    {
        return parent::getPost($name, $filters, $defaultValue, $notAllowEmpty, $noRecursive);
    }

    public function getQuery($name = null, $filters = null, $defaultValue = null, $notAllowEmpty = false, $noRecursive = false)
    {
        return parent::getQuery($name, $filters, $defaultValue, $notAllowEmpty, $noRecursive);
    }

    public function getServer($name)
    {
        return parent::getServer($name);
    }

    public function has($name)
    {
        return parent::has($name);
    }

    public function hasPost($name)
    {
        return parent::hasPost($name);
    }

    public function hasQuery($name)
    {
        return parent::hasQuery($name);
    }

    public function getScheme()
    {
        return parent::getScheme();
    }

    public function isAjax()
    {
        return parent::isAjax();
    }

    public function isSoapRequested()
    {
        return parent::isSoapRequested();
    }

    public function isSecureRequest()
    {
        return parent::isSecureRequest();
    }

    public function getRawBody()
    {
        return parent::getRawBody();
    }

    public function getJsonRawBody($associative = false)
    {
        return parent::getJsonRawBody($associative);
    }

    public function getServerAddress()
    {
        return parent::getServerAddress();
    }

    public function getServerName()
    {
        return parent::getServerName();
    }

    public function getHttpHost()
    {
        return parent::getHttpHost();
    }

    public function getPort()
    {
        return parent::getPort();
    }

    public function setStrictHostCheck($flag = true)
    {
        return parent::setStrictHostCheck($flag);
    }

    public function isStrictHostCheck()
    {
        return parent::isStrictHostCheck();
    }

    public function getClientAddress($trustForwardedHeader = false)
    {
        return parent::getClientAddress($trustForwardedHeader);
    }

    public function getUserAgent()
    {
        return parent::getUserAgent();
    }

    public function isMethod($methods, $strict = null)
    {
        return parent::isMethod($methods, $strict);
    }

    public function isPost()
    {
        return parent::isPost();
    }

    public function isGet()
    {
        return parent::isGet();
    }

    public function isPut()
    {
        return parent::isPut();
    }

    public function isPatch()
    {
        return parent::isPatch();
    }

    public function isHead()
    {
        return parent::isHead();
    }

    public function isDelete()
    {
        return parent::isDelete();
    }

    public function isOptions()
    {
        return parent::isOptions();
    }

    public function isConnect()
    {
        return parent::isConnect();
    }

    public function isTrace()
    {
        return parent::isTrace();
    }

    public function isPurge()
    {
        return parent::isPurge();
    }

    public function hasFiles($onlySuccessful = false)
    {
        return parent::hasFiles($onlySuccessful);
    }

    /**
     * @param bool $notErrored
     * @return \Phalcon\Http\Request\File[]
     */
    public function getUploadedFiles($notErrored = false)
    {
        return parent::getUploadedFiles($notErrored);
    }

    public function getHeaders()
    {
        return parent::getHeaders();
    }

    public function getHTTPReferer()
    {
        return parent::getHTTPReferer();
    }

    public function getAcceptableContent()
    {
        return parent::getAcceptableContent();
    }

    public function getBestAccept()
    {
        return parent::getBestAccept();
    }

    public function getClientCharsets()
    {
        return parent::getClientCharsets();
    }

    public function getBestCharset()
    {
        return parent::getBestCharset();
    }

    public function getLanguages()
    {
        return parent::getLanguages();
    }

    public function getBestLanguage()
    {
        return parent::getBestLanguage();
    }

    public function getBasicAuth()
    {
        return parent::getBasicAuth();
    }

    public function getDigestAuth()
    {
        return parent::getDigestAuth();
    }
}
