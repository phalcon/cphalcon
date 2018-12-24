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
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

class LinkToCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: linkTo() - string as URL and name
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function tagLinkToWithStringAsURLAndName(UnitTester $I)
    {
        $I->wantToTest("Tag - linkTo() - string as URL and name");
        $url  = 'x_url';
        $name = 'x_name';

        $expected = '<a href="/x_url">x_name</a>';
        $actual   = Tag::linkTo($url, $name);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: linkTo() - string as URL and name
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2002
     * @author Phalcon Team <team@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-03-10
     */
    public function tagLinkToWithQueryParam(UnitTester $I)
    {
        $I->wantToTest("Tag - linkTo() - string as URL and name");
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
     * Tests Phalcon\Tag :: linkTo() - empty string as URL and string as name
     * parameter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function tagLinkToWithEmptyStringAsURLAndStringAsName(UnitTester $I)
    {
        $I->wantToTest("Tag - linkTo() - empty string as URL and string as name parameter");
        $url  = '';
        $name = 'x_name';

        $expected = '<a href="/">x_name</a>';
        $actual   = Tag::linkTo($url, $name);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: linkTo() - array as a parameter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function tagLinkToArrayParameter(UnitTester $I)
    {
        $I->wantToTest("Tag - linkTo() - array as a parameter");
        $options  = [
            'x_url',
            'x_name',
        ];
        $expected = '<a href="/x_url">x_name</a>';
        $actual   = Tag::linkTo($options);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: linkTo() - named array as a parameter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function tagLinkToNamedArrayParameter(UnitTester $I)
    {
        $I->wantToTest("Tag - linkTo() - named array as a parameter");
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
     * Tests Phalcon\Tag :: linkTo() - complex local URL
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1679
     * @author Phalcon Team <team@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-29
     */
    public function tagLinkToWithComplexLocalUrl(UnitTester $I)
    {
        $I->wantToTest("Tag - linkTo() - complex local URL");
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
     * Tests Phalcon\Tag :: linkTo() - complex remote URL
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1679
     * @author Phalcon Team <team@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-29
     */
    public function tagLinkToWithComplexRemoteUrl(UnitTester $I)
    {
        $I->wantToTest("Tag - linkTo() - complex remote URL");
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
