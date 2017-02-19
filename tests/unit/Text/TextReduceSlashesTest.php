<?php

namespace Phalcon\Test\Unit\Text;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Proxy\Text;

/**
 * \Phalcon\Test\Unit\Text\TextReduceSlashesTest
 * Tests the \Phalcon\Text component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TextReduceSlashesTest extends UnitTest
{
    /**
     * Tests the reduce slashes function
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-05-11
     */
    public function testReduceSlashes()
    {
        $this->specify(
            "reduce slashes do not delete extra slashes",
            function () {
                expect(Text::reduceSlashes('app/controllers//IndexController'))->equals('app/controllers/IndexController');
                expect(Text::reduceSlashes('http://foo//bar/baz/buz'))->equals('http://foo/bar/baz/buz');
                expect(Text::reduceSlashes('php://memory'))->equals('php://memory');
                expect(Text::reduceSlashes('http//https'))->equals('http/https');
            }
        );
    }
}
