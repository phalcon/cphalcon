<?php

namespace Phalcon\Test\Unit;

use Phalcon\Debug;
use Phalcon\Version;
use Phalcon\Debug\Dump;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\DebugTest
 * Tests the \Phalcon\Debug component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class DebugTest extends UnitTest
{
    /**
     * Tests the Debug::getVersion
     *
     * @issue  12215
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-25
     */
    public function testShouldGetVersion()
    {
        $this->specify(
            "The getVersion doesn't work as expected",
            function () {
                $debug = new Debug;

                $target = '"_new"';
                $uri = '"https://docs.phalconphp.com/en/' . Version::getPart(Version::VERSION_MAJOR) . '.0.0/"';
                $version = Version::get();

                expect($debug->getVersion())->equals(
                    "<div class='version'>Phalcon Framework <a href={$uri} target={$target}>{$version}</a></div>"
                );
            }
        );
    }

    /**
     * Tests function variable for object does not throw a exception
     *
     * @author limx <715557344@qq.com>
     * @link   #13315
     * @since  2018-03-08
     */
    public function testVariableForObjectNotThrowException()
    {
        $this->specify(
            "Function variable for object not work expect",
            function () {
                // Test dump string
                $string = (new Dump(null, true))->variable('xxx');
                expect(strip_tags($string))->equals('String (3) "xxx"');

                // Test dump integer
                $string = (new Dump(null, true))->variable(111);
                expect(strip_tags($string))->equals('Integer (111)');

                // Test dump array
                $string = (new Dump(null, true))->variable([1, 2, 3]);
                expect(strip_tags($string))->equals('Array (3) (
  [0] => Integer (1)
  [1] => Integer (2)
  [2] => Integer (3)
)');

                // Test dump object
                $obj = new \stdClass();
                $obj->test = 'value';
                $string = (new Dump(null, true))->variable($obj);
                expect(strip_tags($string))->equals('Object stdClass (
  ->test (public) = String (5) "value"
  stdClass methods: (0) (
  )
)');
            }
        );
    }
}
