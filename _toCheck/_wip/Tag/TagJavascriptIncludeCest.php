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
use Phalcon\Test\Unit\Tag\Helper\TagHelper;
use UnitTester;

class TagJavascriptIncludeCest extends TagHelper
{
    /**
     * Tests iavascriptInclude with string as a parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeLocal(UnitTester $I)
    {
        Tag::resetInput();
        $options  = 'js/phalcon.js';
        $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = Tag::javascriptInclude($options);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests iavascriptInclude with string as a parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeWithArrayLocal(UnitTester $I)
    {
        Tag::resetInput();
        $options  = ['js/phalcon.js'];
        $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = Tag::javascriptInclude($options);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests javascriptInclude with a string as the second parameter - local
     * link
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeWithStringAsSecondParameterLocal(UnitTester $I)
    {
        Tag::resetInput();
        $options  = ['js/phalcon.js'];
        $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = Tag::javascriptInclude($options, 'hello');

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests javascriptInclude for a remote link
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeRemote(UnitTester $I)
    {
        Tag::resetInput();
        $options  = 'http://my.local.com/js/phalcon.js';
        $expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = Tag::javascriptInclude($options, false);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests javascriptInclude with array parameter for a remote link
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeWithArrayRemote(UnitTester $I)
    {
        Tag::resetInput();
        $options  = ['http://my.local.com/js/phalcon.js'];
        $expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = Tag::javascriptInclude($options, false);

        $I->assertEquals($expected, $actual);
    }
}
