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

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use UnitTester;

class DynamicCest
{
    /**
     * Tests Phalcon\Text :: dynamic()
     *
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-07-01
     */
    public function textDynamic(UnitTester $I)
    {
        $I->wantToTest('Text - dynamic()');

        $actual = Text::dynamic('{Hi|Hello}, my name is a Bob!');

        $I->assertNotContains('{', $actual);
        $I->assertNotContains('}', $actual);

        $I->assertRegExp(
            '/^(Hi|Hello), my name is a Bob!$/',
            $actual
        );
    }

    /**
     * Tests Phalcon\Text :: dynamic() - custom delimiter
     *
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-07-01
     */
    public function textDynamicCustomDelimiter(UnitTester $I)
    {
        $I->wantToTest('Text - dynamic() - custom delimiter');

        $actual = Text::dynamic('(Hi|Hello), my name is a Bob!', '(', ')');

        $I->assertNotContains('{', $actual);
        $I->assertNotContains('}', $actual);

        $I->assertRegExp(
            '/^(Hi|Hello), my name is a Bob!$/',
            $actual
        );
    }

    /**
     * Tests Phalcon\Text :: dynamic() - custom separator
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11215
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-06-27
     */
    public function textDynamicCustomSeparator(UnitTester $I)
    {
        $I->wantToTest('Text - dynamic() - custom separator');



        $actual = Text::dynamic('{Hi=Hello}, my name is a Bob!', '{', '}', '=');

        $I->assertNotContains('{', $actual);
        $I->assertNotContains('}', $actual);
        $I->assertNotContains('=', $actual);

        $I->assertRegExp(
            '/^(Hi|Hello), my name is a Bob!$/',
            $actual
        );



        $actual = Text::dynamic("{Hi'Hello}, my name is a {Rob'Zyxep'Andres}!", '{', '}', "'");

        $I->assertNotContains('{', $actual);
        $I->assertNotContains('}', $actual);
        $I->assertNotContains("''", $actual);

        $I->assertRegExp(
            '/^(Hi|Hello), my name is a (Rob|Zyxep|Andres)!$/',
            $actual
        );



        $actual = Text::dynamic('{Hi/Hello}, my name is a {Stanislav/Nikos}!', '{', '}', '/');

        $I->assertNotContains('{', $actual);
        $I->assertNotContains('}', $actual);
        $I->assertNotContains('/', $actual);

        $I->assertRegExp(
            '/^(Hi|Hello), my name is a (Stanislav|Nikos)!$/',
            $actual
        );
    }
}
