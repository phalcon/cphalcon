<?php

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
use Phalcon\Test\Unit\Tag\Helper\TagBase;
use UnitTester;

/**
 * \Phalcon\Test\Unit\Tag\TagResetInputTest
 * Tests the \Phalcon\Tag component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Tag
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TagResetInputTest extends TagBase
{
    /**
     * Tests Tag::resetInput
     *
     * Note: The Tag::resetInput should not clear $_POST data.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11319
     * @issue  https://github.com/phalcon/cphalcon/issues/12099
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-20
     */
    public function testResetInput(UnitTester $I)
    {
        $this->specify(
            'The resetInput does not work as expected',
            function (UnitTester $I) {
                $_POST = ['a' => '1', 'b' => '2'];
                Tag::resetInput();
                expect($_POST)->equals(['a' => '1', 'b' => '2']);
            }
        );
    }

    /**
     * Tests resetInput with setDefault
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/53
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testResetInputWithSetDefault(UnitTester $I)
    {
        $this->specify(
            "resetInput with setDefault returns invalid HTML Strict",
            function (UnitTester $I) {
                Tag::setDocType(Tag::XHTML10_STRICT);

                $options  = 'x_name';
                $expected = '<input type="text" id="x_name" name="x_name" value="x_other" />';
                Tag::setDefault('x_name', 'x_other');
                $actual   = Tag::textField($options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);

                $expected = '<input type="text" id="x_name" name="x_name" />';
                $actual   = Tag::textField($options);

                $I->assertEquals($expected, $actual);
            }
        );

        $this->specify(
            "resetInput with setDefault returns invalid HTML XHTML",
            function (UnitTester $I) {
                Tag::setDocType(Tag::HTML5);

                $options  = 'x_name';
                $expected = '<input type="text" id="x_name" '
                          . 'name="x_name" value="x_other">';
                Tag::setDefault('x_name', 'x_other');
                $actual   = Tag::textField($options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);

                $expected = '<input type="text" id="x_name" name="x_name">';
                $actual   = Tag::textField($options);

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests resetInput with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testResetInputWithDisplayTo(UnitTester $I)
    {
        $this->specify(
            "resetInput with displayTo returns invalid HTML Strict",
            function (UnitTester $I) {
                Tag::setDocType(Tag::XHTML10_STRICT);

                $options  = 'x_name';
                $expected = '<input type="text" id="x_name" name="x_name" '
                          . 'value="x_other" />';
                Tag::displayTo('x_name', 'x_other');
                $actual   = Tag::textField($options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);

                $expected = '<input type="text" id="x_name" name="x_name" />';
                $actual   = Tag::textField($options);

                $I->assertEquals($expected, $actual);
            }
        );

        $this->specify(
            "resetInput with displayTo returns invalid HTML XHTML",
            function (UnitTester $I) {
                Tag::setDocType(Tag::HTML5);

                $options  = 'x_name';
                $expected = '<input type="text" id="x_name" name="x_name" '
                          . 'value="x_other">';
                Tag::displayTo('x_name', 'x_other');
                $actual   = Tag::textField($options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);

                $expected = '<input type="text" id="x_name" name="x_name">';
                $actual   = Tag::textField($options);

                $I->assertEquals($expected, $actual);
            }
        );
    }
}
