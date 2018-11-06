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
 * \Phalcon\Test\Unit\Tag\TagJavascriptIncludeTest
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
class TagJavascriptIncludeTest extends TagBase
{
    /**
     * Tests iavascriptInclude with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeLocal(UnitTester $I)
    {
        $this->specify(
            "iavascriptInclude with string parameter local link returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $options  = 'js/phalcon.js';
                $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
                $actual   = Tag::javascriptInclude($options);

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests iavascriptInclude with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeWithArrayLocal(UnitTester $I)
    {
        $this->specify(
            "javascriptInclude with array parameter local link returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $options  = ['js/phalcon.js'];
                $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
                $actual   = Tag::javascriptInclude($options);

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests javascriptInclude with a string as the second parameter - local link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeWithStringAsSecondParameterLocal(UnitTester $I)
    {
        $this->specify(
            "javascriptInclude with a string as the second parameter local link returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $options  = ['js/phalcon.js'];
                $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
                $actual   = Tag::javascriptInclude($options, 'hello');

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests javascriptInclude for a remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeRemote(UnitTester $I)
    {
        $this->specify(
            "iavascriptInclude with a string parameter remote link returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $options  = 'http://my.local.com/js/phalcon.js';
                $expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
                $actual   = Tag::javascriptInclude($options, false);

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests javascriptInclude with array parameter for a remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeWithArrayRemote(UnitTester $I)
    {
        $this->specify(
            "iavascriptInclude with array second parameter remote link returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $options  = ['http://my.local.com/js/phalcon.js'];
                $expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
                $actual   = Tag::javascriptInclude($options, false);

                $I->assertEquals($expected, $actual);
            }
        );
    }
}
