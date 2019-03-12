<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Helper;

use Phalcon\Di;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class HttpBase
{
    use DiTrait;

    protected $server = [];

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $this->server = $_SERVER;
        $_SERVER      = [];
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiUrl();
        $this->setDiFilter();
        $this->setDiEventsManager();
        $this->setDiRequest();
        $this->setDiResponse();
    }

    /**
     * executed after each test
     */
    public function _after(UnitTester $I)
    {
        $_SERVER = $this->server;
    }

    /**
     * Initializes the response object and returns it
     *
     * @return Response
     * @since  2014-10-05
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    protected function getResponseObject()
    {
        $container = Di::getDefault();

        return $container->get('response');
    }

    /**
     * Checks the has functions on non defined variables
     *
     * @param UnitTester $I
     * @param string     $function
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     */
    protected function hasEmpty(UnitTester $I, $function)
    {
        $request = $this->getRequestObject();
        $actual  = $request->$function('test');

        $I->assertFalse($actual);
    }

    /**
     * Initializes the request object and returns it
     *
     * @return Request
     * @since  2014-10-05
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    protected function getRequestObject()
    {
        $container = Di::getDefault();

        return $container->get('request');
    }

    /**
     * Checks the has functions on defined variables
     *
     * @param UnitTester $I
     * @param string     $function
     * @param string     $method
     *
     * @since  2014-10-05
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    protected function hasNotEmpty(UnitTester $I, $function, $method)
    {
        $request  = $this->getRequestObject();
        $unMethod = "un{$method}";

        $this->$method('test', 1);
        $actual = $request->$function('test');
        $this->$unMethod('test');

        $I->assertTrue($actual);
    }

    /**
     * Checks the get functions on undefined variables
     *
     * @param UnitTester $I
     * @param string     $function
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     */
    protected function getEmpty(UnitTester $I, $function)
    {
        $request = $this->getRequestObject();

        $actual = $request->$function('test');

        $I->assertEmpty($actual);
    }

    /**
     * Checks the get functions on defined variables
     *
     * @param UnitTester $I
     * @param string     $function
     * @param string     $method
     *
     * @since  2014-10-05
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    protected function getNotEmpty(UnitTester $I, $function, $method)
    {
        $request  = $this->getRequestObject();
        $unMethod = "un{$method}";

        $this->$method('test', 1);
        $expected = 1;
        $actual   = $request->$function('test');
        $this->$unMethod('test');

        $I->assertEquals($expected, $actual);
    }

    /**
     * Checks the get functions for sanitized data
     *
     * @param UnitTester $I
     * @param string     $function
     * @param string     $method
     *
     * @since  2014-10-05
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    protected function getSanitized(UnitTester $I, $function, $method)
    {
        $request  = $this->getRequestObject();
        $unMethod = "un{$method}";

        $this->$method('test', 'lol<');
        $expected = 'lol';
        $actual   = $request->$function('test', 'string');
        $this->$unMethod('test');

        $I->assertEquals($expected, $actual);
    }

    /**
     * Checks the get functions for sanitized data (array filters)
     *
     * @param UnitTester $I
     * @param string     $function
     * @param array      $filter
     * @param string     $method
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     */
    protected function getSanitizedArrayFilter(UnitTester $I, $function, $filter, $method)
    {
        $request  = $this->getRequestObject();
        $unMethod = "un{$method}";

        $this->$method('test', 'lol<');
        $expected = 'lol';
        $actual   = $request->$function('test', $filter);
        $this->$unMethod('test');

        $I->assertEquals($expected, $actual);
    }

    /**
     * Sets a server variable ($_SERVER)
     *
     * @param string $var
     * @param mixed  $value
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     */
    protected function setServerVar($var, $value)
    {
        $_SERVER[$var] = $value;
    }

    /**
     * Unsets a server variable ($_SERVER)
     *
     * @param string $var
     *
     * @since  2014-10-05
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    protected function unsetServerVar($var)
    {
        unset($_SERVER[$var]);
    }

    /**
     * Sets a get variable ($_GET)
     *
     * @param string $var
     * @param mixed  $value
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     */
    protected function setGetVar($var, $value)
    {
        $_GET[$var] = $value;
    }

    /**
     * Unsets a get variable ($_GET)
     *
     * @param string $var
     *
     * @since  2014-10-05
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    protected function unsetGetVar($var)
    {
        unset($_GET[$var]);
    }

    /**
     * Sets a post variable ($_POST)
     *
     * @param string $var
     * @param mixed  $value
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     */
    protected function setPostVar($var, $value)
    {
        $_POST[$var] = $value;
    }

    /**
     * Unsets a post variable ($_POST)
     *
     * @param string $var
     *
     * @since  2014-10-05
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    protected function unsetPostVar($var)
    {
        unset($_POST[$var]);
    }

    /**
     * Sets a request variable ($_REQUEST)
     *
     * @param string $var
     * @param mixed  $value
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     */
    protected function setRequestVar($var, $value)
    {
        $_REQUEST[$var] = $value;
    }

    /**
     * Unsets a request variable ($_REQUEST)
     *
     * @param string $var
     *
     * @since  2014-10-05
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    protected function unsetRequestVar($var)
    {
        unset($_REQUEST[$var]);
    }
}
