<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Debug;

use Phalcon\Debug\Dump;
use Phalcon\Test\Unit\Debug\Helper\ClassProperties;
use UnitTester;

class DumpCest
{
    /**
     * Tests dump object properties.
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/13315
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-23
     */
    public function shouldDumpObjectProperties(UnitTester $I)
    {
        $patient = new ClassProperties();
        $dump    = new Dump([], true);

        $actual   = $I->callProtectedMethod($dump, 'output', $patient);
        $expected = file_get_contents(PATH_DATA . 'fixtures/Dump/class_properties.txt');

        // Test without HTML
        $actual = strip_tags($actual);

        // Remove a trailing newline
        $expected = trim($expected);
        $I->assertEquals($expected, $actual);
    }
}
