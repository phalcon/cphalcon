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

use Phalcon\Http\Cookie;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Page\Http;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Unit\Http\Fake\FakePhpStream;

use function header_remove;
use function stream_wrapper_register;
use function stream_wrapper_restore;
use function stream_wrapper_unregister;
use function time;

abstract class AbstractHttpBase extends AbstractUnitTestCase
{
    use DiTrait;

    protected $store = [];

    /**
     * executed after each test
     */
    public function tearDown(): void
    {
        $_SERVER  = $this->store['SERVER'];
        $_REQUEST = $this->store['REQUEST'];
        $_GET     = $this->store['GET'];
        $_POST    = $this->store['POST'];
        $_COOKIE  = $this->store['COOKIE'];
        $_FILES   = $this->store['FILES'];
    }

    /**
     * executed before each test
     */
    public function setUp(): void
    {
        $this->store['SERVER']  = $_SERVER ?? [];
        $this->store['REQUEST'] = $_REQUEST ?? [];
        $this->store['GET']     = $_GET ?? [];
        $this->store['POST']    = $_POST ?? [];
        $this->store['COOKIE']  = $_COOKIE ?? [];
        $this->store['FILES']   = $_FILES ?? [];

        $time     = $_SERVER['REQUEST_TIME_FLOAT'] ?? time();
        $_SERVER  = [
            'REQUEST_TIME_FLOAT' => $time,
        ];
        $_REQUEST = [];
        $_GET     = [];
        $_POST    = [];
        $_COOKIE  = [];
        $_FILES   = [];

        header_remove();

        $this->setNewFactoryDefault();
    }

    protected function getCookieObject(): Cookie
    {
        $name     = 'test';
        $value    = "phalcon";
        $expire   = time() - 100;
        $path     = "/";
        $secure   = true;
        $domain   = "phalcon.ld";
        $httpOnly = true;
        $options  = ["samesite" => "Lax"];

        $cookie = new Cookie(
            $name,
            $value,
            $expire,
            $path,
            $secure,
            $domain,
            $httpOnly,
            $options
        );

        $cookie->setDI($this->container);

        return $cookie;
    }


    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    protected function getRequestObject(): Request
    {
        return $this->container->get('request');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    protected function getResponseObject(): Response
    {
        return $this->container->get('response');
    }

    /**
     * @return void
     */
    protected function registerStream(): void
    {
        stream_wrapper_unregister(Http::STREAM_NAME);
        stream_wrapper_register(Http::STREAM_NAME, FakePhpStream::class);
    }

    /**
     * @return void
     */
    protected function unregisterStream(): void
    {
        stream_wrapper_restore(Http::STREAM_NAME);
    }
}
