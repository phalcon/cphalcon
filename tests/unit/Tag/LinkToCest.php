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
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

class LinkToCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: linkTo()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testLinkTo(UnitTester $I, $scenario)
    {
        $scenario->incomplete("Need implementation");
    }

    /**
     * Tests linkTo with string as URL and name
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function testLinkToWithStringAsURLAndName(UnitTester $I)
    {
        $url  = 'x_url';
        $name = 'x_name';

        $expected = '<a href="/x_url">x_name</a>';
        $actual   = Tag::linkTo($url, $name);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests linkTo with string as URL and name
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2002
     * @author Phalcon Team <team@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-03-10
     */
    public function testLinkToWithQueryParam(UnitTester $I)
    {
        $actual = Tag::linkTo(
            [
                'signup/register',
                'Register Here!',
                'class' => 'btn-primary',
                'query' => [
                    'from'  => 'github',
                    'token' => '123456',
                ],
            ]
        );

        $expected = '<a href="/signup/register?from=github&amp;token=123456" class="btn-primary">Register Here!</a>';
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests linkTo with empty string as URL and string as name parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function testLinkToWithEmptyStringAsURLAndStringAsName(UnitTester $I)
    {
        $url  = '';
        $name = 'x_name';

        $expected = '<a href="/">x_name</a>';
        $actual   = Tag::linkTo($url, $name);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests linkTo with array as a parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function testLinkToArrayParameter(UnitTester $I)
    {
        $options  = [
            'x_url',
            'x_name',
        ];
        $expected = '<a href="/x_url">x_name</a>';
        $actual   = Tag::linkTo($options);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests linkTo with named array as a parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function testLinkToNamedArrayParameter(UnitTester $I)
    {
        $options  = [
            'action' => 'x_url',
            'text'   => 'x_name',
            'class'  => 'x_class',
        ];
        $expected = '<a href="/x_url" class="x_class">x_name</a>';
        $actual   = Tag::linkTo($options);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests linkTo with complex local URL
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1679
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-29
     */
    public function testLinkToWithComplexLocalUrl(UnitTester $I)
    {
        Tag::resetInput();
        $url      = "x_action/x_param";
        $name     = 'x_name';
        $actual   = Tag::linkTo($url, $name);
        $expected = '<a href="/x_action/x_param">x_name</a>';

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $options  = [
            "x_action/x_param",
            'x_name',
        ];
        $actual   = Tag::linkTo($options);
        $expected = '<a href="/x_action/x_param">x_name</a>';

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $options  = [
            "x_action/x_param",
            'x_name',
            'class' => 'x_class',
        ];
        $actual   = Tag::linkTo($options);
        $expected = '<a href="/x_action/x_param" class="x_class">x_name</a>';

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests linkTo with complex remote URL
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1679
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-29
     */
    public function testLinkToWithComplexRemoteUrl(UnitTester $I)
    {
        Tag::resetInput();
        $url      = "http://phalconphp.com/en/";
        $name     = 'x_name';
        $actual   = Tag::linkTo($url, $name, false);
        $expected = '<a href="http://phalconphp.com/en/">x_name</a>';

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $options  = [
            "http://phalconphp.com/en/",
            'x_name',
            false,
        ];
        $actual   = Tag::linkTo($options);
        $expected = '<a href="http://phalconphp.com/en/">x_name</a>';

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $options  = [
            "http://phalconphp.com/en/",
            'text'  => 'x_name',
            'local' => false,
        ];
        $actual   = Tag::linkTo($options);
        $expected = '<a href="http://phalconphp.com/en/">x_name</a>';

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $url      = "mailto:someone@phalconphp.com";
        $name     = 'someone@phalconphp.com';
        $actual   = Tag::linkTo($url, $name, false);
        $expected = '<a href="mailto:someone@phalconphp.com">someone@phalconphp.com</a>';

        $I->assertEquals($expected, $actual);
    }
}
