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

namespace Phalcon\Test\Unit\Html\Tag;

use Phalcon\Html\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\TagSetupTrait;
use UnitTester;

/**
 * Class LinkCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class LinkCest
{
    use DiTrait;
    use TagSetupTrait;

    /**
     * Tests Phalcon\Html\Tag :: link()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function htmlTagLink(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - link()');
        $tag = new Tag();
        $tag->setDI($this->container);

        $url  = 'x_url';
        $name = 'x_name';

        $expected = '<a href="/x_url">x_name</a>';
        $actual   = $tag->link($url, $name);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: link() - params with query
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2002
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-03-10
     */
    public function htmlTagLinkParamsWithQuery(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - link() - params with query');
        $tag = new Tag();
        $tag->setDI($this->container);

        $url    = 'signup/register';
        $name   = 'Register Here!';
        $params = [
            'class' => 'btn-primary',
            'query' => [
                'from'  => 'github',
                'token' => '123456',
            ],
        ];

        $expected = '<a href="/signup/register?from=github&amp;token=123456" '
            . 'class="btn-primary">Register Here!</a>';
        $actual   = $tag->link($url, $name, $params);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: link() - empty url
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function htmlTagLinkEmptyUrl(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - link() - empty url');
        $tag = new Tag();
        $tag->setDI($this->container);

        $url  = '';
        $name = 'x_name';

        $expected = '<a href="/">x_name</a>';
        $actual   = $tag->link($url, $name);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: link() - named array as a parameter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function htmlTagLinkNamedParameters(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - link() - named array as a parameter');
        $tag = new Tag();
        $tag->setDI($this->container);

        $url    = '';
        $name   = '';
        $params = [
            'url'   => 'x_url',
            'text'  => 'x_name',
            'class' => 'x_class',
        ];

        $expected = '<a href="/x_url" class="x_class">x_name</a>';
        $actual   = $tag->link($url, $name, $params);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: link() - complex url local
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1679
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-29
     */
    public function htmlTagLinkComplexUrlLocal(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - link() - complex url local');
        $tag = new Tag();
        $tag->setDI($this->container);

        $url      = "x_action/x_param";
        $name     = 'x_name';
        $params   = [
            'class' => 'x_class',
        ];
        $expected = '<a href="/x_action/x_param" class="x_class">x_name</a>';
        $actual   = $tag->link($url, $name, $params);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: link() - complex url remote
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1679
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-29
     */
    public function htmlTagLinkComplexUrlRemote(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - link() - complex url remote');
        $tag = new Tag();
        $tag->setDI($this->container);

        $url      = "http://phalconphp.com/en/";
        $name     = 'x_name';
        $params   = [
            'local' => false,
            'class' => 'x_class',
        ];
        $expected = '<a href="http://phalconphp.com/en/" class="x_class">x_name</a>';
        $actual   = $tag->link($url, $name, $params);
        $I->assertEquals($expected, $actual);

        $url      = "http://phalconphp.com/en/";
        $name     = 'x_name';
        $params   = [
            'local' => false,
            'class' => 'x_class',
            'text'  => 'Website',
        ];
        $expected = '<a href="http://phalconphp.com/en/" class="x_class">Website</a>';
        $actual   = $tag->link($url, $name, $params);
        $I->assertEquals($expected, $actual);

        $url      = "mailto:someone@phalconphp.com";
        $name     = 'someone@phalconphp.com';
        $params   = [
            'local' => false,
        ];
        $expected = '<a href="mailto:someone@phalconphp.com">someone@phalconphp.com</a>';
        $actual   = $tag->link($url, $name, $params);
        $I->assertEquals($expected, $actual);
    }
}
