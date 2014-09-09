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

namespace Phalcon\Tests\unit\Phalcon\Tag;

use \CodeGuy;
use \Phalcon\Tag as PhTag;

class TagResetInputCest extends TagBase
{
    /**
     * Tests resetInput (after a displayTo)
     *
     * @issue 53
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-08
     *
     * @param CodeGuy $I
     */
    public function testResetInputDisplayTo(CodeGuy $I)
    {
        $this->resetInput($I, 'displayTo', false);
    }

    /**
     * Tests resetInput (after a displayTo) XHTML
     *
     * @issue 53
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-08
     *
     * @param CodeGuy $I
     */
    public function testResetInputDisplayToXHTML(CodeGuy $I)
    {
        $this->resetInput($I, 'displayTo', true);
    }

    /**
     * Tests resetInput (after a setDefault)
     *
     * @issue 53
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-08
     *
     * @param CodeGuy $I
     */
    public function testResetInputSetDefault(CodeGuy $I)
    {
        $this->resetInput($I, 'setDefault', false);
    }

    /**
     * Tests resetInput (after a setDefault) XHTML
     *
     * @issue 53
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-08
     *
     * @param CodeGuy $I
     */
    public function testResetInputSetDefaultXHTML(CodeGuy $I)
    {
        $this->resetInput($I, 'setDefault', true);
    }

    /**
     * Runs tests with resetInput for displayTo/setDefault for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param string  $function
     * @param boolean $xhtml
     */
    private function resetInput(CodeGuy $I, $function, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDoctype(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType(PhTag::HTML5);
        }

        $suffix  = ($xhtml) ? ' />'    : ">";
        $message = ($xhtml) ? ' XHTML' : '';
        $message = $function . ' for displayTo' . $message;

        $options  = 'some_field_name';
        $expected = '<input type="text" id="some_field_name" '
                  . 'name="some_field_name" value="Wall-E"'
                  . $suffix;
        PhTag::$function('some_field_name', 'Wall-E');
        $actual   = PhTag::textField($options);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, $message . ' before')
        );
        PhTag::resetInput();

        $expected = '<input type="text" id="some_field_name" '
                  . 'name="some_field_name"'
                  . $suffix;
        $actual   = PhTag::textField($options);
        PhTag::setDoctype(PhTag::HTML5);
        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, $message . ' after')
        );
    }
}
