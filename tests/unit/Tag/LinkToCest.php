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

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

class LinkToCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: linkTo() - string as URL and name
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-29
     */
    public function tagLinkToWithStringAsURLAndName(UnitTester $I)
    {
        $I->wantToTest('Tag - linkTo() - string as URL and name');

        $url  = 'x_url';
        $name = 'x_name';

        $I->assertEquals(
            '<a href="/x_url">x_name</a>',
            Tag::linkTo($url, $name)
        );
    }

    /**
     * Tests Phalcon\Tag :: linkTo() - string as URL and name
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2002
     * @author Phalcon Team <team@phalcon.io>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-03-10
     */
    public function tagLinkToWithQueryParam(UnitTester $I)
    {
        $I->wantToTest('Tag - linkTo() - string as URL and name');

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

        $I->assertEquals(
            '<a href="/signup/register?from=github&amp;token=123456" class="btn-primary">Register Here!</a>',
            $actual
        );
    }

    /**
     * Tests Phalcon\Tag :: linkTo() - empty string as URL and string as name
     * parameter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-29
     */
    public function tagLinkToWithEmptyStringAsURLAndStringAsName(UnitTester $I)
    {
        $I->wantToTest('Tag - linkTo() - empty string as URL and string as name parameter');

        $url  = '';
        $name = 'x_name';

        $I->assertEquals(
            '<a href="/">x_name</a>',
            Tag::linkTo($url, $name)
        );
    }

    /**
     * Tests Phalcon\Tag :: linkTo() - array as a parameter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-29
     */
    public function tagLinkToArrayParameter(UnitTester $I)
    {
        $I->wantToTest('Tag - linkTo() - array as a parameter');

        $options = [
            'x_url',
            'x_name',
        ];

        $I->assertEquals(
            '<a href="/x_url">x_name</a>',
            Tag::linkTo($options)
        );
    }

    /**
     * Tests Phalcon\Tag :: linkTo() - named array as a parameter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-29
     */
    public function tagLinkToNamedArrayParameter(UnitTester $I)
    {
        $I->wantToTest('Tag - linkTo() - named array as a parameter');

        $options = [
            'action' => 'x_url',
            'text'   => 'x_name',
            'class'  => 'x_class',
        ];

        $I->assertEquals(
            '<a href="/x_url" class="x_class">x_name</a>',
            Tag::linkTo($options)
        );
    }

    /**
     * Tests Phalcon\Tag :: linkTo() - complex local URL
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1679
     * @author Phalcon Team <team@phalcon.io>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-29
     */
    public function tagLinkToWithComplexLocalUrl(UnitTester $I)
    {
        $I->wantToTest('Tag - linkTo() - complex local URL');

        Tag::resetInput();

        $url  = 'x_action/x_param';
        $name = 'x_name';

        $I->assertEquals(
            '<a href="/x_action/x_param">x_name</a>',
            Tag::linkTo($url, $name)
        );

        Tag::resetInput();

        $options = [
            'x_action/x_param',
            'x_name',
        ];

        $I->assertEquals(
            '<a href="/x_action/x_param">x_name</a>',
            Tag::linkTo($options)
        );

        Tag::resetInput();

        $options = [
            'x_action/x_param',
            'x_name',
            'class' => 'x_class',
        ];

        $I->assertEquals(
            '<a href="/x_action/x_param" class="x_class">x_name</a>',
            Tag::linkTo($options)
        );
    }

    /**
     * Tests Phalcon\Tag :: linkTo() - complex remote URL
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1679
     * @author Phalcon Team <team@phalcon.io>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-29
     */
    public function tagLinkToWithComplexRemoteUrl(UnitTester $I)
    {
        $I->wantToTest('Tag - linkTo() - complex remote URL');

        Tag::resetInput();

        $url  = 'http://phalcon.io/en/';
        $name = 'x_name';

        $I->assertEquals(
            '<a href="http://phalcon.io/en/">x_name</a>',
            Tag::linkTo($url, $name, false)
        );

        Tag::resetInput();

        $options = [
            'http://phalcon.io/en/',
            'x_name',
            false,
        ];

        $I->assertEquals(
            '<a href="http://phalcon.io/en/">x_name</a>',
            Tag::linkTo($options)
        );

        Tag::resetInput();

        $options = [
            'http://phalcon.io/en/',
            'text'  => 'x_name',
            'local' => false,
        ];

        $I->assertEquals(
            '<a href="http://phalcon.io/en/">x_name</a>',
            Tag::linkTo($options)
        );

        Tag::resetInput();

        $url  = 'mailto:someone@phalcon.io';
        $name = 'someone@phalcon.io';

        $I->assertEquals(
            '<a href="mailto:someone@phalcon.io">someone@phalcon.io</a>',
            Tag::linkTo($url, $name, false)
        );
    }
}
