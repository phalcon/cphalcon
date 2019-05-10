<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Debug\Dump;

use Phalcon\Debug\Dump;
use UnitTester;

class OneCest
{
    /**
     * Tests Phalcon\Debug\Dump :: one()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugDumpOne(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - one()');

        $test = 'value';

        $dump = new Dump();

        $expected = "<pre style='background-color:#f3f3f3; font-size:11px; "
            . "padding:10px; border:1px solid #ccc; text-align:left; "
            . "color:#333'><b style='color:teal'>String</b> "
            . "(<span style='color:teal'>5</span>) \""
            . "<span style='color:teal'>value</span>\"</pre>";

        $I->assertEquals(
            $expected,
            $dump->one($test)
        );
    }

    /**
     * Tests Phalcon\Debug\Dump :: one() - name
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugDumpOneName(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - one() - name');

        $test = 'value';

        $dump = new Dump();

        $expected = "<pre style='background-color:#f3f3f3; font-size:11px; "
            . "padding:10px; border:1px solid #ccc; text-align:left; "
            . "color:#333'>super <b style='color:teal'>String</b> "
            . "(<span style='color:teal'>5</span>) \""
            . "<span style='color:teal'>value</span>\"</pre>";

        $I->assertEquals(
            $expected,
            $dump->one($test, 'super')
        );
    }
}
