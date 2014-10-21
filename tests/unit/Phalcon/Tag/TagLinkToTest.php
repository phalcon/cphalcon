<?php
/**
 * TagLinkToTest.php
 * \Phalcon\Tag
 *
 * Tests the \Phalcon\Tag component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Tag;

use \PhalconTest\Tag as PhTTag;

class TagLinkToTest extends Helper\TagBase
{
    /**
     * Tests linkTo with string as URL and name
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testLinkToWithStringAsURLAndName()
    {
        $this->specify(
            "linkTo with string as URL and name returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $url  = 'x_url';
                $name = 'x_name';

                $expected = '<a href="/x_url">x_name</a>';
                $actual   = PhTTag::linkTo($url, $name);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests linkTo with empty string as URL and string as name parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testLinkToWithEmptyStringAsURLAndStringAsName()
    {
        $this->specify(
            "linkTo with empty string as URL and string as name parameter returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $url  = '';
                $name = 'x_name';

                $expected = '<a href="/">x_name</a>';
                $actual   = PhTTag::linkTo($url, $name);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests linkTo with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testLinkToArrayParameter()
    {
        $this->specify(
            "linkTo with array parameter returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $options = [
                    'x_url',
                    'x_name',
                ];
                $expected = '<a href="/x_url">x_name</a>';
                $actual   = PhTTag::linkTo($options);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests linkTo with named array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testLinkToNamedArrayParameter()
    {
        $this->specify(
            "linkTo with named array parameter returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $options = [
                    'action' => 'x_url',
                    'text'   => 'x_name',
                    'class'  => 'x_class',
                ];
                $expected = '<a href="/x_url" class="x_class">x_name</a>';
                $actual   = PhTTag::linkTo($options);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests linkTo with complex local URL
     *
     * @issue  1679
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-29
     */
    public function testLinkToWithComplexLocalUrl()
    {
        $this->specify(
            "linkTo with complex local URL string parameter returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $url      = "x_action/x_param";
                $name     = 'x_name';
                $actual   = PhTTag::linkTo($url, $name);
                $expected = '<a href="/x_action/x_param">x_name</a>';

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "linkTo with complex local URL array parameter returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $options  = [
                    "x_action/x_param",
                    'x_name',
                ];
                $actual   = PhTTag::linkTo($options);
                $expected = '<a href="/x_action/x_param">x_name</a>';

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "linkTo with complex local URL array named parameter returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $options  = [
                    "x_action/x_param",
                    'x_name',
                    'class' => 'x_class'
                ];
                $actual   = PhTTag::linkTo($options);
                $expected = '<a href="/x_action/x_param" class="x_class">x_name</a>';

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests linkTo with complex remote URL
     *
     * @issue  1679
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-29
     */
    public function testLinkToWithComplexRemoteUrl()
    {
        $this->specify(
            "linkTo with complex remote URL string parameter returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $url      = "http://phalconphp.com/en/";
                $name     = 'x_name';
                $actual   = PhTTag::linkTo($url, $name, false);
                $expected = '<a href="http://phalconphp.com/en/">x_name</a>';

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "linkTo with complex remote URL array parameter returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $options  = [
                    "http://phalconphp.com/en/",
                    'x_name',
                    false,
                ];
                $actual   = PhTTag::linkTo($options);
                $expected = '<a href="http://phalconphp.com/en/">x_name</a>';

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "linkTo with complex remote URL array named parameter returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $options  = [
                    "http://phalconphp.com/en/",
                    'text'  => 'x_name',
                    'local' => false,
                ];
                $actual   = PhTTag::linkTo($options);
                $expected = '<a href="http://phalconphp.com/en/">x_name</a>';

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "linkTo with mailto URL string parameter returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $url  = "mailto:someone@phalconphp.com";
                $name = 'someone@phalconphp.com';
                $actual   = PhTTag::linkTo($url, $name, false);
                $expected = '<a href="mailto:someone@phalconphp.com">someone@phalconphp.com</a>';

                expect($actual)->equals($expected);
            }
        );
    }
}
