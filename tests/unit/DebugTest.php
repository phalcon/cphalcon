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
                try {
                    (new Dump(null, true))->variable('xxx');
                    (new Dump(null, true))->variable(111);
                    (new Dump(null, true))->variable([1, 2, 3]);

                    $obj = new \stdClass();
                    $obj->test = 'value';
                    (new Dump(null, true))->variable($obj);

                    expect(true)->true();
                } catch (\Exception $ex) {
                    expect(false)->true();
                }
            }
        );
    }
}
