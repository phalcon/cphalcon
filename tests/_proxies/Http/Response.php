<?php

namespace Phalcon\Test\Proxy\Http;

use Phalcon\Http\Response as PhResponse;
use Phalcon\DiInterface;

/**
 * \Phalcon\Test\Proxy\Http\Response
 * Http Response proxy class for \Phalcon\Http\Response
 *
 * @copyright (c) 2011-2016 Phalcon Team
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
class Response extends PhResponse
{
    public function setDI(DiInterface $di)
    {
        parent::setDI($di);
    }

    public function getDI()
    {
        return parent::getDI();
    }

    public function setStatusCode($code, $message = null)
    {
        return parent::setStatusCode($code, $message);
    }

    public function setHeaders(PhResponse\HeadersInterface $headers)
    {
        return parent::setHeaders($headers);
    }

    public function getHeaders()
    {
        return parent::getHeaders();
    }

    public function setCookies(PhResponse\CookiesInterface $cookies)
    {
        return parent::setCookies($cookies);
    }

    public function getCookies()
    {
        return parent::getCookies();
    }

    public function setHeader($name, $value)
    {
        return parent::setHeader($name, $value);
    }

    public function setRawHeader($header)
    {
        return parent::setRawHeader($header);
    }

    public function resetHeaders()
    {
        return parent::resetHeaders();
    }

    public function setExpires(\Datetime $datetime)
    {
        return parent::setExpires($datetime);
    }

    public function setCache($minutes)
    {
        return parent::setCache($minutes);
    }

    public function setNotModified()
    {
        return parent::setNotModified();
    }

    public function setContentType($contentType, $charset = null)
    {
        return parent::setContentType($contentType, $charset);
    }

    public function setEtag($etag)
    {
        return parent::setEtag($etag);
    }

    public function redirect($location = null, $externalRedirect = false, $statusCode = 302)
    {
        return parent::redirect($location, $externalRedirect, $statusCode);
    }

    public function setContent($content)
    {
        return parent::setContent($content);
    }

    public function setJsonContent($content, $jsonOptions = 0)
    {
        return parent::setJsonContent($content, $jsonOptions);
    }

    public function appendContent($content)
    {
        return parent::appendContent($content);
    }

    public function getContent()
    {
        return parent::getContent();
    }

    public function isSent()
    {
        return parent::isSent();
    }

    public function sendHeaders()
    {
        return parent::sendHeaders();
    }

    public function sendCookies()
    {
        return parent::sendCookies();
    }

    public function send()
    {
        return parent::send();
    }

    public function setFileToSend($filePath, $attachmentName = null, $attachment = true)
    {
        return parent::setFileToSend($filePath, $attachmentName, $attachment);
    }
}
