<?php

namespace Phalcon\Test\Unit\Http\Helper;

use Phalcon\Di;
use Phalcon\Filter;
use Phalcon\Mvc\Url;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Http\Helper\HttpBase
 * Base class for \Phalcon\Http component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Http\Helper
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class HttpBase extends UnitTest
{
    /**
     * Initializes the response object and returns it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @return Response
     */
    protected function getResponseObject()
    {
        Di::reset();
        $di = new Di();

        $di->set('url', function () {
            $url = new Url();
            $url->setBaseUri('/');
            return $url;
        });

        $response = new Response();
        $response->setDI($di);

        return $response;
    }

    /**
     * Initializes the request object and returns it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @return Request
     */
    protected function getRequestObject()
    {
        Di::reset();
        $di = new Di();

        $di->set('filter', function () {
            return new Filter();
        });

        $request = new Request();
        $request->setDI($di);

        return $request;
    }

    /**
     * Checks the has functions on non defined variables
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string    $function
     */
    protected function hasEmpty($function)
    {
        $request = $this->getRequestObject();
        $actual  = $request->$function('test');

        expect($actual)->false();
    }

    /**
     * Checks the has functions on defined variables
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string    $function
     * @param string    $method
     */
    public function hasNotEmpty($function, $method)
    {
        $request  = $this->getRequestObject();
        $unMethod = "un{$method}";

        $this->$method('test', 1);
        $actual  = $request->$function('test');
        $this->$unMethod('test');

        expect($actual)->true();
    }

    /**
     * Checks the get functions on undefined variables
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string    $function
     */
    public function getEmpty($function)
    {
        $request = $this->getRequestObject();

        $actual  = $request->$function('test');

        expect($actual)->isEmpty();
    }

    /**
     * Checks the get functions on defined variables
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string    $function
     * @param string    $method
     */
    public function getNotEmpty($function, $method)
    {
        $request  = $this->getRequestObject();
        $unMethod = "un{$method}";

        $this->$method('test', 1);
        $expected = 1;
        $actual   = $request->$function('test');
        $this->$unMethod('test');

        expect($actual)->equals($expected);
    }

    /**
     * Checks the get functions for sanitized data
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string    $function
     * @param string    $method
     */
    public function getSanitized($function, $method)
    {
        $request  = $this->getRequestObject();
        $unMethod = "un{$method}";

        $this->$method('test', 'lol<');
        $expected = 'lol';
        $actual   = $request->$function('test', 'string');
        $this->$unMethod('test');

        expect($actual)->equals($expected);
    }

    /**
     * Checks the get functions for sanitized data (array filters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string    $function
     * @param array     $filter
     * @param string    $method
     */
    public function getSanitizedArrayFilter($function, $filter, $method)
    {
        $request  = $this->getRequestObject();
        $unMethod = "un{$method}";

        $this->$method('test', 'lol<');
        $expected = 'lol';
        $actual   = $request->$function('test', $filter);
        $this->$unMethod('test');

        expect($actual)->equals($expected);
    }

    /**
     * Sets a server variable ($_SERVER)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string    $var
     * @param mixed     $value
     */
    protected function setServerVar($var, $value)
    {
        $_SERVER[$var] = $value;
    }

    /**
     * Unsets a server variable ($_SERVER)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string    $var
     */
    protected function unsetServerVar($var)
    {
        unset($_SERVER[$var]);
    }

    /**
     * Sets a get variable ($_GET)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string    $var
     * @param mixed     $value
     */
    protected function setGetVar($var, $value)
    {
        $_GET[$var] = $value;
    }

    /**
     * Unsets a get variable ($_GET)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string    $var
     */
    protected function unsetGetVar($var)
    {
        unset($_GET[$var]);
    }

    /**
     * Sets a post variable ($_POST)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string    $var
     * @param mixed     $value
     */
    protected function setPostVar($var, $value)
    {
        $_POST[$var] = $value;
    }

    /**
     * Unsets a post variable ($_POST)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string    $var
     */
    protected function unsetPostVar($var)
    {
        unset($_POST[$var]);
    }

    /**
     * Sets a request variable ($_REQUEST)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string    $var
     * @param mixed     $value
     */
    protected function setRequestVar($var, $value)
    {
        $_REQUEST[$var] = $value;
    }

    /**
     * Unsets a request variable ($_REQUEST)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string    $var
     */
    protected function unsetRequestVar($var)
    {
        unset($_REQUEST[$var]);
    }
}
