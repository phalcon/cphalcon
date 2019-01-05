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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @return Response
     */
    protected function getResponseObject()
    {
        $container = Di::getDefault();

        return $container->get('response');
    }

    /**
     * Checks the has functions on non defined variables
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @param UnitTester $I
     * @param string     $function
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @return Request
     */
    protected function getRequestObject()
    {
        $container = Di::getDefault();

        return $container->get('request');
    }

    /**
     * Checks the has functions on defined variables
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @param UnitTester $I
     * @param string     $function
     * @param string     $method
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @param UnitTester $I
     * @param string     $function
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @param UnitTester $I
     * @param string     $function
     * @param string     $method
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @param UnitTester $I
     * @param string     $function
     * @param string     $method
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @param UnitTester $I
     * @param string     $function
     * @param array      $filter
     * @param string     $method
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string $var
     * @param mixed  $value
     */
    protected function setServerVar($var, $value)
    {
        $_SERVER[$var] = $value;
    }

    /**
     * Unsets a server variable ($_SERVER)
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string $var
     */
    protected function unsetServerVar($var)
    {
        unset($_SERVER[$var]);
    }

    /**
     * Sets a get variable ($_GET)
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string $var
     * @param mixed  $value
     */
    protected function setGetVar($var, $value)
    {
        $_GET[$var] = $value;
    }

    /**
     * Unsets a get variable ($_GET)
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string $var
     */
    protected function unsetGetVar($var)
    {
        unset($_GET[$var]);
    }

    /**
     * Sets a post variable ($_POST)
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string $var
     * @param mixed  $value
     */
    protected function setPostVar($var, $value)
    {
        $_POST[$var] = $value;
    }

    /**
     * Unsets a post variable ($_POST)
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string $var
     */
    protected function unsetPostVar($var)
    {
        unset($_POST[$var]);
    }

    /**
     * Sets a request variable ($_REQUEST)
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string $var
     * @param mixed  $value
     */
    protected function setRequestVar($var, $value)
    {
        $_REQUEST[$var] = $value;
    }

    /**
     * Unsets a request variable ($_REQUEST)
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string $var
     */
    protected function unsetRequestVar($var)
    {
        unset($_REQUEST[$var]);
    }
}
