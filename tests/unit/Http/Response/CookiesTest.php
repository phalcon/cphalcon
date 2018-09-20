<?php

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Http\Response\Cookies;
use Phalcon\Test\Unit\Http\Helper\HttpBase;

/**
 * Phalcon\Test\Unit\Http\Response\Http\CookiesTest
 * Tests the Phalcon\Http\Response\Cookies component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Http\Response
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CookiesTest extends HttpBase
{
    /**
     * Tests the internal cookies property.
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12978
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-09-02
     */
    public function shouldWorkWithoutInitializeInternalCookiesProperty()
    {
        $this->specify(
            "The internal cookies property is not initialized or iterable",
            function () {
                expect((new Cookies())->send())->true();
            }
        );
    }
}
