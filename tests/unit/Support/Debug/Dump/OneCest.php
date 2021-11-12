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

namespace Phalcon\Tests\Unit\Support\Debug\Dump;

use Phalcon\Support\Debug\Dump;
use UnitTester;

/**
 * Class OneCest
 *
 * @package Phalcon\Tests\Unit\Support\Debug\Dump
 */
class OneCest
{
    /**
     * Tests Phalcon\Support\Debug\Dump :: one()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportDebugDumpOne(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - one()');

        $test = 'value';
        $dump = new Dump();

        $expected = '<pre style="background-color:#f3f3f3; font-size:11px; '
            . 'padding:10px; border:1px solid #ccc; text-align:left; '
            . 'color:#333"><b style="color:teal">String</b> '
            . '(<span style="color:teal">5</span>) "'
            . '<span style="color:teal">value</span>"</pre>';
        $actual   = $dump->one($test);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Debug\Dump :: one() - name
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportDebugDumpOneName(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - one() - name');

        $test = 'value';
        $dump = new Dump();

        $expected = '<pre style="background-color:#f3f3f3; font-size:11px; '
            . 'padding:10px; border:1px solid #ccc; text-align:left; '
            . 'color:#333">super <b style="color:teal">String</b> '
            . '(<span style="color:teal">5</span>) "'
            . '<span style="color:teal">value</span>"</pre>';
        $actual   = $dump->one($test, 'super');
        $I->assertEquals($expected, $actual);
    }
}
