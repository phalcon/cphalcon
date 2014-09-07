<?php
/**
 * TagStylesheetlinkCest.php
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
use Phalcon\DI\FactoryDefault as PhDI;
use \Phalcon\Tag as PhTag;

class TagStylesheetlinkCest
{
    private $message = "%s does not return proper html element";
    
    public function _before()
    {
        $di = new PhDI();
        $di->getshared('url')
           ->setBaseUri('/');
        PhTag::setDI($di);
    }

    /**
     * Tests stylesheetLink for a local link
     *
     * @issue  1486
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testStylesheetLinkLocal(CodeGuy $I)
    {
        PhTag::setDoctype(PhTag::HTML5);
        $options  = 'css/phalcon.css';
        $expected = '<link rel="stylesheet" type="text/css" href="/css/phalcon.css">' . PHP_EOL;
        $actual   = PhTag::stylesheetLink($options);
        PhTag::setDoctype('');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'StylesheetLink local')
        );
    }


    /**
     * Tests stylesheetLink with an array passed for a local link
     *
     * @issue  1486
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testStylesheetLinkWithArrayLocal(CodeGuy $I)
    {
        PhTag::setDoctype('');
        $options  = array('css/phalcon.css');
        $expected = '<link rel="stylesheet" type="text/css" href="/css/phalcon.css">' . PHP_EOL;
        $actual   = PhTag::stylesheetLink($options);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'StylesheetLink local with Array')
        );
    }

    /**
     * Tests stylesheetLink with a string as the second parameter - local link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testStylesheetLinkWithStringAsSecondParameterLocal(CodeGuy $I)
    {
        PhTag::setDoctype('');
        $options  = array('css/phalcon.css');
        $expected = '<link rel="stylesheet" type="text/css" href="/css/phalcon.css">' . PHP_EOL;
        $actual   = PhTag::stylesheetLink($options, 'hello');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'StylesheetLink local with string as second parameter'
            )
        );
    }

    /**
     * Tests stylesheetLink for a remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testStylesheetLinkRemote(CodeGuy $I)
    {
        PhTag::setDoctype('');
        $options  = 'http://fonts.googleapis.com/css?family=Rosario';
        $expected = '<link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Rosario">' . PHP_EOL;
        $actual   = PhTag::stylesheetLink($options, false);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'StylesheetLink remote')
        );
    }

    /**
     * Tests stylesheetLink with an array passed for a remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testStylesheetLinkWithArrayRemote(CodeGuy $I)
    {
        PhTag::setDoctype('');
        $options  = array('http://fonts.googleapis.com/css?family=Rosario');
        $expected = '<link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Rosario">' . PHP_EOL;
        $actual   = PhTag::stylesheetLink($options, false);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'StylesheetLink remote with Array')
        );
    }

    /**
     * Tests stylesheetLink with a string as the second parameter - remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testStylesheetLinkWithStringAsSecondParameterRemote(CodeGuy $I)
    {
        PhTag::setDoctype('');
        $options  = 'http://fonts.googleapis.com/css?family=Rosario';
        $expected = '<link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Rosario">' . PHP_EOL;
        $actual   = PhTag::stylesheetLink($options, '0');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'StylesheetLink remote with string as second parameter'
            )
        );
    }

    /**
     * Tests stylesheetLink for a local link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testStylesheetLinkLocalXHTML(CodeGuy $I)
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options  = 'css/phalcon.css';
        $expected = '<link rel="stylesheet" type="text/css" href="/css/phalcon.css" />' . PHP_EOL;
        $actual   = PhTag::stylesheetLink($options);
        PhTag::setDoctype('');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML StylesheetLink local')
        );
    }

    /**
     * Tests stylesheetLink with an array passed for a local link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testStylesheetLinkWithArrayLocalXHTML(CodeGuy $I)
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options  = array('css/phalcon.css');
        $expected = '<link rel="stylesheet" type="text/css" href="/css/phalcon.css" />' . PHP_EOL;
        $actual   = PhTag::stylesheetLink($options);
        PhTag::setDoctype('');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML StylesheetLink local with Array')
        );
    }

    /**
     * Tests stylesheetLink with a string as the second parameter - local link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testStylesheetLinkWithStringAsSecondParameterLocalXHTML(CodeGuy $I)
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options  = array('css/phalcon.css');
        $expected = '<link rel="stylesheet" type="text/css" href="/css/phalcon.css" />' . PHP_EOL;
        $actual   = PhTag::stylesheetLink($options, 'hello');
        PhTag::setDoctype('');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'StylesheetLink local with string as second parameter'
            )
        );
    }

    /**
     * Tests stylesheetLink for a remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testStylesheetLinkRemoteXHTML(CodeGuy $I)
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options  = 'http://fonts.googleapis.com/css?family=Rosario';
        $expected = '<link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Rosario" />' . PHP_EOL;
        $actual   = PhTag::stylesheetLink($options, FALSE);
        PhTag::setDoctype('');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML StylesheetLink remote')
        );
    }

    /**
     * Tests stylesheetLink with an array passed for a remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testStylesheetLinkWithArrayRemoteXHTML(CodeGuy $I)
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options  = array('http://fonts.googleapis.com/css?family=Rosario');
        $expected = '<link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Rosario" />' . PHP_EOL;
        $actual   = PhTag::stylesheetLink($options, FALSE);
        PhTag::setDoctype('');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML StylesheetLink remote with Array')
        );
    }

    /**
     * Tests stylesheetLink with a string as the second parameter - remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testStylesheetLinkWithStringAsSecondParameterRemoteXHTML(CodeGuy $I)
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options  = 'http://fonts.googleapis.com/css?family=Rosario';
        $expected = '<link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Rosario" />' . PHP_EOL;
        $actual   = PhTag::stylesheetLink($options, '0');
        PhTag::setDoctype('');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'StylesheetLink remote with string as second parameter'
            )
        );
    }

    /**
     * Tests stylesheetLink overriding the rel link
     *
     * @issue  2142
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testStylesheetLinkOverrideRelLink(CodeGuy $I)
    {
        PhTag::setDoctype('');
        $options  = array('css/phalcon.css', 'rel' => 'stylesheet/less');
        $expected = '<link rel="stylesheet/less" type="text/css" href="/css/phalcon.css">' . PHP_EOL;
        $actual   = PhTag::stylesheetLink($options);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'StylesheetLink overriding rel link'
            )
        );
    }

    /**
     * Tests stylesheetLink overriding the rel link XHTML
     *
     * @issue  2142
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testStylesheetLinkOverrideRelLinkXHTML(CodeGuy $I)
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options  = array('css/phalcon.css', 'rel' => 'stylesheet/less');
        $expected = '<link rel="stylesheet/less" type="text/css" href="/css/phalcon.css" />' . PHP_EOL;
        $actual   = PhTag::stylesheetLink($options);
        PhTag::setDoctype('');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'StylesheetLink overriding rel link'
            )
        );
    }
}
