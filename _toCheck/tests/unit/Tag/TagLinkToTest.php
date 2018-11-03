<?php

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Tag\TagLinkToTest
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
class TagLinkToTest extends UnitTest
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
                Tag::resetInput();
                $url  = 'x_url';
                $name = 'x_name';

                $expected = '<a href="/x_url">x_name</a>';
                $actual   = Tag::linkTo($url, $name);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests linkTo with string as URL and name
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2002
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-03-10
     */
    public function testLinkToWithQueryParam()
    {
        $this->specify(
            "linkTo with query param name returns invalid HTML",
            function () {
                $actual = Tag::linkTo([
                    'signup/register',
                    'Register Here!',
                    'class' => 'btn-primary',
                    'query' => ['from' => 'github', 'token' => '123456']
                ]);

                expect($actual)->equals('<a href="/signup/register?from=github&amp;token=123456" class="btn-primary">Register Here!</a>');
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
                Tag::resetInput();
                $url  = '';
                $name = 'x_name';

                $expected = '<a href="/">x_name</a>';
                $actual   = Tag::linkTo($url, $name);

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
                Tag::resetInput();
                $options = [
                    'x_url',
                    'x_name',
                ];
                $expected = '<a href="/x_url">x_name</a>';
                $actual   = Tag::linkTo($options);

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
                Tag::resetInput();
                $options = [
                    'action' => 'x_url',
                    'text'   => 'x_name',
                    'class'  => 'x_class',
                ];
                $expected = '<a href="/x_url" class="x_class">x_name</a>';
                $actual   = Tag::linkTo($options);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests linkTo with complex local URL
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1679
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
                Tag::resetInput();
                $url      = "x_action/x_param";
                $name     = 'x_name';
                $actual   = Tag::linkTo($url, $name);
                $expected = '<a href="/x_action/x_param">x_name</a>';

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "linkTo with complex local URL array parameter returns invalid HTML",
            function () {
                Tag::resetInput();
                $options  = [
                    "x_action/x_param",
                    'x_name',
                ];
                $actual   = Tag::linkTo($options);
                $expected = '<a href="/x_action/x_param">x_name</a>';

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "linkTo with complex local URL array named parameter returns invalid HTML",
            function () {
                Tag::resetInput();
                $options  = [
                    "x_action/x_param",
                    'x_name',
                    'class' => 'x_class'
                ];
                $actual   = Tag::linkTo($options);
                $expected = '<a href="/x_action/x_param" class="x_class">x_name</a>';

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests linkTo with complex remote URL
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1679
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
                Tag::resetInput();
                $url      = "http://phalconphp.com/en/";
                $name     = 'x_name';
                $actual   = Tag::linkTo($url, $name, false);
                $expected = '<a href="http://phalconphp.com/en/">x_name</a>';

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "linkTo with complex remote URL array parameter returns invalid HTML",
            function () {
                Tag::resetInput();
                $options  = [
                    "http://phalconphp.com/en/",
                    'x_name',
                    false,
                ];
                $actual   = Tag::linkTo($options);
                $expected = '<a href="http://phalconphp.com/en/">x_name</a>';

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "linkTo with complex remote URL array named parameter returns invalid HTML",
            function () {
                Tag::resetInput();
                $options  = [
                    "http://phalconphp.com/en/",
                    'text'  => 'x_name',
                    'local' => false,
                ];
                $actual   = Tag::linkTo($options);
                $expected = '<a href="http://phalconphp.com/en/">x_name</a>';

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "linkTo with mailto URL string parameter returns invalid HTML",
            function () {
                Tag::resetInput();
                $url  = "mailto:someone@phalconphp.com";
                $name = 'someone@phalconphp.com';
                $actual   = Tag::linkTo($url, $name, false);
                $expected = '<a href="mailto:someone@phalconphp.com">someone@phalconphp.com</a>';

                expect($actual)->equals($expected);
            }
        );
    }
}
