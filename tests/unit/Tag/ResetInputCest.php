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

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use UnitTester;

/**
 * Class ResetInputCest
 *
 * @package Phalcon\Test\Unit\Tag
 */
class ResetInputCest
{
    /**
     * Tests Phalcon\Tag :: resetInput()
     *
     * Note: The Tag::resetInput should not clear $_POST data.
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11319
     * @issue  https://github.com/phalcon/cphalcon/issues/12099
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-20
     */
    public function tagResetInputShouldNotClearPOST(UnitTester $I)
    {
        $I->wantToTest("Tag - resetInput() - should not clear POST data");
        $_POST = ['a' => '1', 'b' => '2'];
        Tag::resetInput();
        $expected = ['a' => '1', 'b' => '2'];
        $actual   = $_POST;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: resetInput() - setDefault
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/53
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagResetInputSetDefault(UnitTester $I)
    {
        $I->wantToTest("Tag - resetInput() - setDefault()");
        Tag::setDocType(Tag::XHTML10_STRICT);
        $options  = 'x_name';
        $expected = '<input type="text" id="x_name" name="x_name" value="x_other" />';
        Tag::setDefault('x_name', 'x_other');
        $actual = Tag::textField($options);
        Tag::resetInput();
        $I->assertEquals($expected, $actual);
        $expected = '<input type="text" id="x_name" name="x_name" />';
        $actual   = Tag::textField($options);
        $I->assertEquals($expected, $actual);
        Tag::setDocType(Tag::HTML5);
        $options  = 'x_name';
        $expected = '<input type="text" id="x_name" '
            . 'name="x_name" value="x_other">';
        Tag::setDefault('x_name', 'x_other');
        $actual = Tag::textField($options);
        Tag::resetInput();
        $I->assertEquals($expected, $actual);
        $expected = '<input type="text" id="x_name" name="x_name">';
        $actual   = Tag::textField($options);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: resetInput() - displayTo
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagResetInputDisplayTo(UnitTester $I)
    {
        $I->wantToTest("Tag - resetInput() - displayTo()");
        Tag::setDocType(Tag::XHTML10_STRICT);
        $options  = 'x_name';
        $expected = '<input type="text" id="x_name" name="x_name" '
            . 'value="x_other" />';
        Tag::displayTo('x_name', 'x_other');
        $actual = Tag::textField($options);
        Tag::resetInput();
        $I->assertEquals($expected, $actual);
        $expected = '<input type="text" id="x_name" name="x_name" />';
        $actual   = Tag::textField($options);
        $I->assertEquals($expected, $actual);
        Tag::setDocType(Tag::HTML5);
        $options  = 'x_name';
        $expected = '<input type="text" id="x_name" name="x_name" '
            . 'value="x_other">';
        Tag::displayTo('x_name', 'x_other');
        $actual = Tag::textField($options);
        Tag::resetInput();
        $I->assertEquals($expected, $actual);
        $expected = '<input type="text" id="x_name" name="x_name">';
        $actual   = Tag::textField($options);
        $I->assertEquals($expected, $actual);
    }
}
