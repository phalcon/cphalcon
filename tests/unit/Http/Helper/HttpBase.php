<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Http\Helper;

use Phalcon\Di\Di;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

class HttpBase
{
    use DiTrait;

    protected $store = [];

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $this->store["SERVER"]  = $_SERVER ?? [];
        $this->store["REQUEST"] = $_REQUEST ?? [];
        $this->store["GET"]     = $_GET ?? [];
        $this->store["POST"]    = $_POST ?? [];
        $this->store["COOKIE"]  = $_COOKIE ?? [];

        $_SERVER  = [];
        $_REQUEST = [];
        $_GET     = [];
        $_POST    = [];
        $_COOKIE  = [];

        $this->setNewFactoryDefault();
    }

    /**
     * executed after each test
     */
    public function _after(UnitTester $I)
    {
        $_SERVER  = $this->store["SERVER"];
        $_REQUEST = $this->store["REQUEST"];
        $_GET     = $this->store["GET"];
        $_POST    = $this->store["POST"];
        $_COOKIE  = $this->store["COOKIE"];
    }

    /**
     * Initializes the response object and returns it
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    protected function getResponseObject(): Response
    {
        return $this->container->get('response');
    }

    /**
     * Checks the has functions on non defined variables
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    protected function hasEmpty(UnitTester $I, string $function)
    {
        $request = $this->getRequestObject();

        $I->assertFalse(
            $request->$function('test')
        );
    }

    /**
     * Initializes the request object and returns it
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    protected function getRequestObject(): Request
    {
        return $this->container->get('request');
    }

    /**
     * Checks the has functions on defined variables
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    protected function hasNotEmpty(UnitTester $I, string $function, string $method)
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    protected function getEmpty(UnitTester $I, string $function)
    {
        $request = $this->getRequestObject();

        $I->assertEmpty(
            $request->$function('test')
        );
    }

    /**
     * Checks the get functions on defined variables
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    protected function getNotEmpty(UnitTester $I, string $function, string $method)
    {
        $request  = $this->getRequestObject();
        $unMethod = "un{$method}";

        $this->$method('test', 1);
        $actual = $request->$function('test');
        $this->$unMethod('test');

        $I->assertEquals(1, $actual);
    }

    /**
     * Checks the get functions for sanitized data
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    protected function getSanitized(UnitTester $I, string $function, string $method)
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
     * @param array $filter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    protected function getSanitizedArrayFilter(UnitTester $I, string $function, $filter, string $method)
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
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    protected function unsetServerVar($var)
    {
        unset($_SERVER[$var]);
    }

    /**
     * Sets a get variable ($_GET)
     *
     * @param string $var
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    protected function unsetGetVar($var)
    {
        unset($_GET[$var]);
    }

    /**
     * Sets a post variable ($_POST)
     *
     * @param string $var
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    protected function unsetPostVar($var)
    {
        unset($_POST[$var]);
    }

    /**
     * Sets a request variable ($_REQUEST)
     *
     * @param string $var
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    protected function unsetRequestVar($var)
    {
        unset($_REQUEST[$var]);
    }
}
