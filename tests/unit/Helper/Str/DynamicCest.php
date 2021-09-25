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

namespace Phalcon\Tests\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

class DynamicCest
{
    /**
     * Tests Phalcon\Helper\Str :: dynamic()
     *
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-07-01
     */
    public function helperStrDynamic(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - dynamic()');

        $actual = Str::dynamic('{Hi|Hello}, my name is a Bob!');

        $I->assertNotContains('{', $actual);
        $I->assertNotContains('}', $actual);

        $I->assertRegExp(
            '/^(Hi|Hello), my name is a Bob!$/',
            $actual
        );
    }

    /**
     * Tests Phalcon\Helper\Str :: dynamic() - custom delimiter
     *
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-07-01
     */
    public function helperStrDynamicCustomDelimiter(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - dynamic() - custom delimiter');

        $actual = Str::dynamic('(Hi|Hello), my name is a Bob!', '(', ')');

        $I->assertNotContains('{', $actual);
        $I->assertNotContains('}', $actual);

        $I->assertRegExp(
            '/^(Hi|Hello), my name is a Bob!$/',
            $actual
        );
    }

    /**
     * Tests Phalcon\Helper\Str :: dynamic() - custom separator
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11215
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-06-27
     */
    public function helperStrDynamicCustomSeparator(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - dynamic() - custom separator');


        $actual = Str::dynamic('{Hi=Hello}, my name is a Bob!', '{', '}', '=');

        $I->assertNotContains('{', $actual);
        $I->assertNotContains('}', $actual);
        $I->assertNotContains('=', $actual);

        $I->assertRegExp(
            '/^(Hi|Hello), my name is a Bob!$/',
            $actual
        );


        $actual = Str::dynamic("{Hi'Hello}, my name is a {Rob'Zyxep'Andres}!", '{', '}', "'");

        $I->assertNotContains('{', $actual);
        $I->assertNotContains('}', $actual);
        $I->assertNotContains("''", $actual);

        $I->assertRegExp(
            '/^(Hi|Hello), my name is a (Rob|Zyxep|Andres)!$/',
            $actual
        );


        $actual = Str::dynamic('{Hi/Hello}, my name is a {Stanislav/Nikos}!', '{', '}', '/');

        $I->assertNotContains('{', $actual);
        $I->assertNotContains('}', $actual);
        $I->assertNotContains('/', $actual);

        $I->assertRegExp(
            '/^(Hi|Hello), my name is a (Stanislav|Nikos)!$/',
            $actual
        );
    }
}
