<?php
/**
 * TagFriendlyTitleTest.php
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

use \Phalcon\Tag\Exception as PhTagException;
use \PhalconTest\Tag as PhTTag;

class TagFriendlyTitleTest extends Helper\TagBase
{
    /**
     * Tests friendlyTitle with string as a parameter and no separator
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleStringParameterNoSeparator()
    {
        $this->specify(
            "friendlyTitle with string parameter and no separator returns incorrect text",
            function () {

                PhTTag::resetInput();
                $options  = 'This is a Test';
                $expected = 'this-is-a-test';
                $actual   = PhTTag::friendlyTitle($options);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests friendlyTitle with string as a parameter and a separator
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleStringParameterSeparator()
    {
        $this->specify(
            "friendlyTitle with string parameter and a separator returns incorrect text",
            function () {

                PhTTag::resetInput();
                $options  = 'This is a Test';
                $expected = 'this_is_a_test';
                $actual   = PhTTag::friendlyTitle($options, '_');

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests friendlyTitle with string as a parameter lowercase
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleStringParameterLowercase()
    {
        $this->specify(
            "friendlyTitle with string parameter lowercase returns incorrect text",
            function () {

                PhTTag::resetInput();
                $options  = 'This is a Test';
                $expected = 'this_is_a_test';
                $actual   = PhTTag::friendlyTitle($options, '_', true);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests friendlyTitle with string as a parameter uppercase
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleStringParameterUppercase()
    {
        $this->specify(
            "friendlyTitle with string parameter uppercase returns incorrect text",
            function () {

                PhTTag::resetInput();
                $options  = 'This is a Test';
                $expected = 'This_is_a_Test';
                $actual   = PhTTag::friendlyTitle($options, '_', false);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests friendlyTitle with string as a parameter with replace as string
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleStringParameterReplaceString()
    {
        $this->specify(
            "friendlyTitle with string parameter with replace returns incorrect text",
            function () {

                PhTTag::resetInput();
                $options  = 'This is a Test';
                $expected = 'th_s_s_a_test';
                $actual   = PhTTag::friendlyTitle($options, '_', true, 'i');

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests friendlyTitle with string as a parameter with replace as array
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleStringParameterReplaceArray()
    {
        $this->specify(
            "friendlyTitle with string parameter with replace array returns incorrect text",
            function () {

                PhTTag::resetInput();
                $options  = 'This is a Test';
                $expected = 't_s_s_a_test';
                $actual   = PhTTag::friendlyTitle(
                    $options,
                    '_',
                    true,
                    ['i', 'h']
                );

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests friendlyTitle with special characters and escaping
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleWithSpecialCharactersAndEscaping()
    {
        $this->specify(
            "friendlyTitle with special characters and escaping returns incorrect text",
            function () {

                PhTTag::resetInput();
                $options  = "Mess'd up --text-- just (to) stress /test/ ?our! "
                          . "`little` \\clean\\ url fun.ction!?-->";
                $expected = 'messd-up-text-just-to-stress-test-our-little-'
                          . 'clean-url-function';
                $actual   = PhTTag::friendlyTitle($options);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests friendlyTitle with accented characters and replace string
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleWithAccentedCharactersAndReplaceString()
    {
        $this->specify(
            "friendlyTitle with accented characters and replace string returns incorrect text",
            function () {

                PhTTag::resetInput();
                $options  = "Perché l'erba è verde?";
                $expected = 'perche-l-erba-e-verde';
                $actual   = PhTTag::friendlyTitle($options, "-", true, "'");

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests friendlyTitle with accented characters and replace array
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleWithAccentedCharactersAndReplaceArray()
    {
        $this->specify(
            "friendlyTitle with accented characters and replace array returns incorrect text",
            function () {

                PhTTag::resetInput();
                $options  = "Perché l'erba è verde?";
                $expected = 'P_rch_l_rb_v_rd';
                $actual   = PhTTag::friendlyTitle(
                    $options,
                    "_",
                    false,
                    ['e', 'a']
                );

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests friendlyTitle with string as a parameter with replace as boolean
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleStringParameterReplaceBoolean()
    {
        $this->specify(
            "friendlyTitle with string parameter with replace array returns incorrect text",
            function () {

                PhTTag::resetInput();
                $options  = 'This is a Test';
                $expected = 't_s_s_a_test';
                $actual   = PhTTag::friendlyTitle($options, '_', true, true);

                expect($actual)->equals($expected);
            },
            ['throws' => new PhTagException]
        );
    }
}
