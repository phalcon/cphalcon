<?php
/**
 * TagJavascriptIncludeTest.php
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

class TagJavascriptIncludeTest extends Helper\TagBase
{
    /**
     * Tests iavascriptInclude with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeLocal()
    {
        $this->specify(
            "iavascriptInclude with string parameter local link returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $options  = 'js/phalcon.js';
                $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
                $actual   = PhTTag::javascriptInclude($options);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests iavascriptInclude with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeWithArrayLocal()
    {
        $this->specify(
            "javascriptInclude with array parameter local link returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $options  = ['js/phalcon.js'];
                $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
                $actual   = PhTTag::javascriptInclude($options);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests javascriptInclude with a string as the second parameter - local link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeWithStringAsSecondParameterLocal()
    {
        $this->specify(
            "javascriptInclude with a string as the second parameter local link returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $options  = ['js/phalcon.js'];
                $expected = '<script type="text/javascript" src="js/phalcon.js"></script>' . PHP_EOL;
                $actual   = PhTTag::javascriptInclude($options, 'hello');

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests javascriptInclude for a remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeRemote()
    {
        $this->specify(
            "iavascriptInclude with a string parameter remote link returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $options  = 'http://my.local.com/js/phalcon.js';
                $expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
                $actual   = PhTTag::javascriptInclude($options, false);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests javascriptInclude with array parameter for a remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeWithArrayRemote()
    {
        $this->specify(
            "iavascriptInclude with array second parameter remote link returns invalid HTML",
            function () {

                PhTTag::resetInput();
                $options  = ['http://my.local.com/js/phalcon.js'];
                $expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
                $actual   = PhTTag::javascriptInclude($options, false);

                expect($actual)->equals($expected);
            }
        );
    }
}
