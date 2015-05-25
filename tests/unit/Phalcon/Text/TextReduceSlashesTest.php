<?php
/**
 * TextReduceSlashesTest.php
 * \Phalcon\Text\TextReduceSlashesTest
 *
 * Tests the Phalcon\Text component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
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

namespace Phalcon\Tests\unit\Phalcon\Text;

use \PhalconTest\Text as PhTText;

class TextReduceSlashesTest extends Helper\TextBase
{
    /**
     * Tests the reduce slashes function
     *
     * @author Serghei Iakovlev <sadhooklay@gmail.com>
     * @since  2015-05-11
     */
    public function testReduceSlashes()
    {
        $this->specify(
            "reduce slashes do not delete extra slashes",
            function () {
                expect(PhTText::reduceSlashes('app/controllers//IndexController'))->equals('app/controllers/IndexController');
                expect(PhTText::reduceSlashes('http://foo//bar/baz/buz'))->equals('http://foo/bar/baz/buz');
                expect(PhTText::reduceSlashes('php://memory'))->equals('php://memory');
                expect(PhTText::reduceSlashes('http//https'))->equals('http/https');
            }
        );
    }
}
