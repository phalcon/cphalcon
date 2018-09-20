<?php

namespace Phalcon\Test\Unit;

use Phalcon\Debug\Dump;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Debug\ClassProperties;

/**
 * Phalcon\Test\Unit\Debug\DumpTest
 * Tests the Phalcon\Debug\Dump component
 *
 * @copyright (c) 2011-2018 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Debug
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class DumpTest extends UnitTest
{
    /**
     * Tests dump object properties.
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/13315
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2014-10-23
     */
    public function shouldDumpObjectProperties()
    {
        $this->specify(
            "The Dump::output doesn't work as expected",
            function () {
                $patient = new ClassProperties();
                $dump = new Dump(null, true);

                $actual = $this->tester->callProtectedMethod($dump, 'output', $patient);
                $expected = file_get_contents(PATH_FIXTURES . 'dump/class_properties.txt');

                // Test without HTML
                $actual = strip_tags($actual);

                // Remove a trailing newline
                $expected = trim($expected);

                expect($actual)->equals($expected);
            }
        );
    }
}
