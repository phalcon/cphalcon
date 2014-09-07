<?php
/**
 * TagCest.php
 * \Phalcon\Tag
 *
 * Tests the \Phalcon\Tag component
 *
 * PhalconPHP Framework
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

use \CodeGuy;
use \Phalcon\Tag as PhTag;

class TagCest
{
    /**
     * Tests the get
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testGet(CodeGuy $I)
    {
        $actual = Version::get();

        $I->assertTrue(
            is_string($actual),
            'get() does not return a string'
        );
    }
    // -------------------------------------------------------------------------
    // javascriptInclude
    // -------------------------------------------------------------------------
    /**
     * Tests javascriptInclude for a local link
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testJavascriptIncludeLocal()
    {
        $options  = 'js/phalcon.js';
        $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = \Phalcon\Tag::javascriptInclude($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'JavascriptInclude local')
        );
    }

    /**
     * Tests javascriptInclude with an array passed for a local link
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testJavascriptIncludeWithArrayLocal()
    {
        $options  = array('js/phalcon.js');
        $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = \Phalcon\Tag::javascriptInclude($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'JavascriptInclude local with Array')
        );
    }

    /**
     * Tests javascriptInclude with a string as the second parameter - local link
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testJavascriptIncludeWithStringAsSecondParameterLocal()
    {
        $options  = 'js/phalcon.js';
        $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = \Phalcon\Tag::javascriptInclude($options, 'hello');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'JavascriptInclude local with string as second parameter'
            )
        );
    }

    /**
     * Tests javascriptInclude for a remote link
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testJavascriptIncludeRemote()
    {
        $options  = 'http://my.local.com/js/phalcon.js';
        $expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = \Phalcon\Tag::javascriptInclude($options, false);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'JavascriptInclude remote')
        );
    }

    /**
     * Tests javascriptInclude with an array passed for a remote link
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testJavascriptIncludeWithArrayRemote()
    {
        $options  = array('http://my.local.com/js/phalcon.js');
        $expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = \Phalcon\Tag::javascriptInclude($options, false);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'JavascriptInclude remote with Array')
        );
    }

    /**
     * Tests javascriptInclude with a string as the second parameter - remote link
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testJavascriptIncludeWithStringAsSecondParameterRemote()
    {
        $options  = 'http://my.local.com/js/phalcon.js';
        $expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = \Phalcon\Tag::javascriptInclude($options, '0');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'JavascriptInclude remote with string as second parameter'
            )
        );
    }

    /**
     * Tests javascriptInclude for a local link
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testJavascriptIncludeLocalXHTML()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options  = 'js/phalcon.js';
        $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = \Phalcon\Tag::javascriptInclude($options);
        \Phalcon\Tag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML JavascriptInclude local')
        );
    }

    /**
     * Tests javascriptInclude with an array passed for a local link
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testJavascriptIncludeWithArrayLocalXHTML()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options  = array('js/phalcon.js');
        $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = \Phalcon\Tag::javascriptInclude($options);
        \Phalcon\Tag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML JavascriptInclude local with Array')
        );
    }

    /**
     * Tests javascriptInclude with a string as the second parameter - local link
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testJavascriptIncludeWithStringAsSecondParameterLocalXHTML()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options  = 'js/phalcon.js';
        $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = \Phalcon\Tag::javascriptInclude($options, 'hello');
        \Phalcon\Tag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'xhtml JavascriptInclude local with string as second parameter'
            )
        );
    }

    /**
     * Tests javascriptInclude for a remote link
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testJavascriptIncludeRemoteXHTML()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options  = 'http://my.local.com/js/phalcon.js';
        $expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = \Phalcon\Tag::javascriptInclude($options, false);
        \Phalcon\Tag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML JavascriptInclude remote')
        );
    }

    /**
     * Tests javascriptInclude with an array passed for a remote link
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testJavascriptIncludeWithArrayRemoteXHTML()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options  = array('http://my.local.com/js/phalcon.js');
        $expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = \Phalcon\Tag::javascriptInclude($options, false);
        \Phalcon\Tag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML JavascriptInclude remote with Array')
        );
    }

    /**
     * Tests javascriptInclude with a string as the second parameter - remote link
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testJavascriptIncludeWithStringAsSecondParameterRemoteXHTML()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options  = 'http://my.local.com/js/phalcon.js';
        $expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = \Phalcon\Tag::javascriptInclude($options, '0');
        \Phalcon\Tag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'JavascriptInclude remote with string as second parameter'
            )
        );
    }
}
