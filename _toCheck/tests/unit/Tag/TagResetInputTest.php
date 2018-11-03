<?php

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Module\UnitTest;

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
class TagResetInputTest extends UnitTest
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
    public function testResetInput()
    {
        $this->specify(
            'The resetInput does not work as expected',
            function () {
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
    public function testResetInputWithSetDefault()
    {
        $this->specify(
            "resetInput with setDefault returns invalid HTML Strict",
            function () {
                Tag::setDocType(Tag::XHTML10_STRICT);

                $options  = 'x_name';
                $expected = '<input type="text" id="x_name" name="x_name" value="x_other" />';
                Tag::setDefault('x_name', 'x_other');
                $actual   = Tag::textField($options);
                Tag::resetInput();

                expect($actual)->equals($expected);

                $expected = '<input type="text" id="x_name" name="x_name" />';
                $actual   = Tag::textField($options);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "resetInput with setDefault returns invalid HTML XHTML",
            function () {
                Tag::setDocType(Tag::HTML5);

                $options  = 'x_name';
                $expected = '<input type="text" id="x_name" '
                          . 'name="x_name" value="x_other">';
                Tag::setDefault('x_name', 'x_other');
                $actual   = Tag::textField($options);
                Tag::resetInput();

                expect($actual)->equals($expected);

                $expected = '<input type="text" id="x_name" name="x_name">';
                $actual   = Tag::textField($options);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests resetInput with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testResetInputWithDisplayTo()
    {
        $this->specify(
            "resetInput with displayTo returns invalid HTML Strict",
            function () {
                Tag::setDocType(Tag::XHTML10_STRICT);

                $options  = 'x_name';
                $expected = '<input type="text" id="x_name" name="x_name" '
                          . 'value="x_other" />';
                Tag::displayTo('x_name', 'x_other');
                $actual   = Tag::textField($options);
                Tag::resetInput();

                expect($actual)->equals($expected);

                $expected = '<input type="text" id="x_name" name="x_name" />';
                $actual   = Tag::textField($options);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "resetInput with displayTo returns invalid HTML XHTML",
            function () {
                Tag::setDocType(Tag::HTML5);

                $options  = 'x_name';
                $expected = '<input type="text" id="x_name" name="x_name" '
                          . 'value="x_other">';
                Tag::displayTo('x_name', 'x_other');
                $actual   = Tag::textField($options);
                Tag::resetInput();

                expect($actual)->equals($expected);

                $expected = '<input type="text" id="x_name" name="x_name">';
                $actual   = Tag::textField($options);

                expect($actual)->equals($expected);
            }
        );
    }
}
