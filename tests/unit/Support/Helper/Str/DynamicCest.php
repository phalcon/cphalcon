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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Phalcon\Support\Helper\Str\Dynamic;
use RuntimeException;
use UnitTester;

/**
 * Class DynamicCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class DynamicCest
{
    /**
     * Tests Phalcon\Text :: dynamic()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrDynamic(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - dynamic()');

        $object = new Dynamic();
        $actual = $object->__invoke('{Hi|Hello}, my name is Bob!');

        $I->assertStringNotContainsString('{', $actual);
        $I->assertStringNotContainsString('}', $actual);

        $I->assertRegExp(
            '/^(Hi|Hello), my name is Bob!$/',
            $actual
        );
    }

    /**
     * Tests Phalcon\Text :: dynamic() - custom delimiter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrDynamicCustomDelimiter(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - dynamic() - custom delimiter');
        $object = new Dynamic();
        $actual = $object->__invoke('(Hi|Hello), my name is Bob!', '(', ')');

        $I->assertStringNotContainsString('{', $actual);
        $I->assertStringNotContainsString('}', $actual);

        $I->assertRegExp(
            '/^(Hi|Hello), my name is Bob!$/',
            $actual
        );
    }

    /**
     * Tests Phalcon\Text :: dynamic() - custom separator
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrDynamicCustomSeparator(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - dynamic() - custom separator');

        $object = new Dynamic();
        $actual = $object->__invoke('{Hi=Hello}, my name is Bob!', '{', '}', '=');

        $I->assertStringNotContainsString('{', $actual);
        $I->assertStringNotContainsString('}', $actual);
        $I->assertStringNotContainsString('=', $actual);

        $I->assertRegExp(
            '/^(Hi|Hello), my name is Bob!$/',
            $actual
        );

        $actual = $object->__invoke("{Hi'Hello}, my name is {Rob'Zyxep'Andres}!", '{', '}', "'");

        $I->assertStringNotContainsString('{', $actual);
        $I->assertStringNotContainsString('}', $actual);
        $I->assertStringNotContainsString("''", $actual);

        $I->assertRegExp(
            '/^(Hi|Hello), my name is (Rob|Zyxep|Andres)!$/',
            $actual
        );

        $actual = $object->__invoke('{Hi/Hello}, my name is {Stanislav/Nikos}!', '{', '}', '/');

        $I->assertStringNotContainsString('{', $actual);
        $I->assertStringNotContainsString('}', $actual);
        $I->assertStringNotContainsString('/', $actual);

        $I->assertRegExp(
            '/^(Hi|Hello), my name is (Stanislav|Nikos)!$/',
            $actual
        );
    }

    /**
     * Tests Phalcon\Text :: dynamic() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrDynamicException(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - dynamic() - exception');

        $I->expectThrowable(
            new RuntimeException("Syntax error in string '{{Hi/Hello}'"),
            function () {
                $object = new Dynamic();
                $actual = $object->__invoke('{{Hi/Hello}');
            }
        );
    }
}
