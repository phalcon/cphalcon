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

class JavascriptIncludeCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: javascriptInclude() - string as a parameter local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function tagJavascriptIncludeLocal(UnitTester $I)
    {
        $I->wantToTest("Tag - javascriptInclude() - string as a parameter local");
        $options  = 'js/phalcon.js';
        $expected = '<script src="/js/phalcon.js"></script>' . PHP_EOL;
        Tag::setDocType(Tag::HTML5);
        $actual = Tag::javascriptInclude($options);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: javascriptInclude() - array as a parameter local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function tagJavascriptIncludeWithArrayLocal(UnitTester $I)
    {
        $I->wantToTest("Tag - javascriptInclude()");
        $options  = ['js/phalcon.js'];
        $expected = '<script src="/js/phalcon.js"></script>' . PHP_EOL;
        Tag::setDocType(Tag::HTML5);
        $actual = Tag::javascriptInclude($options);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: javascriptInclude() - remote link
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function tagJavascriptIncludeRemote(UnitTester $I)
    {
        $I->wantToTest("Tag - javascriptInclude() - remote link");
        $options  = 'http://my.local.com/js/phalcon.js';
        $expected = '<script src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
        Tag::setDocType(Tag::HTML5);
        $actual = Tag::javascriptInclude($options, false);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: javascriptInclude() - array parameter for a remote
     * link
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function tagJavascriptIncludeWithArrayRemote(UnitTester $I)
    {
        $I->wantToTest("Tag - javascriptInclude() - array parameter for a remote");
        $options  = ['http://my.local.com/js/phalcon.js'];
        $expected = '<script src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
        Tag::setDocType(Tag::HTML5);
        $actual = Tag::javascriptInclude($options, false);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: javascriptInclude() - HTML5
     *
     * @param UnitTester $I
     *
     * @issue https://github.com/phalcon/cphalcon/issues/13341
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-12-22
     */
    public function tagJavascriptIncludeHtml5(UnitTester $I)
    {
        $I->wantToTest("Tag - javascript() - HTML5");

        $url      = 'js/phalcon.js';
        $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
        Tag::setDocType(Tag::HTML32);
        $actual = Tag::javascriptInclude($url);
        $I->assertEquals($expected, $actual);
    }
}
