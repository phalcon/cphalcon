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
use Phalcon\Tag\Exception;
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

class FriendlyTitleCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: friendlyTitle() - string as a parameter and no
     * separator
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleStringParameterNoSeparator(UnitTester $I)
    {
        $options  = 'This is a Test';
        $expected = 'this-is-a-test';
        $actual   = Tag::friendlyTitle($options);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: friendlyTitle() - string as a parameter and a
     * separator
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleStringParameterSeparator(UnitTester $I)
    {
        $options  = 'This is a Test';
        $expected = 'this_is_a_test';
        $actual   = Tag::friendlyTitle($options, '_');

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: friendlyTitle() - string as a parameter lowercase
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleStringParameterLowercase(UnitTester $I)
    {
        $options  = 'This is a Test';
        $expected = 'this_is_a_test';
        $actual   = Tag::friendlyTitle($options, '_', true);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: friendlyTitle() - string as a parameter uppercase
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleStringParameterUppercase(UnitTester $I)
    {
        $options  = 'This is a Test';
        $expected = 'This_is_a_Test';
        $actual   = Tag::friendlyTitle($options, '_', false);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: friendlyTitle() - string as a parameter with
     * replace as string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleStringParameterReplaceString(UnitTester $I)
    {
        $options  = 'This is a Test';
        $expected = 'th_s_s_a_test';
        $actual   = Tag::friendlyTitle($options, '_', true, 'i');

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: friendlyTitle() - string as a parameter with
     * replace as array
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleStringParameterReplaceArray(UnitTester $I)
    {
        $options  = 'This is a Test';
        $expected = 't_s_s_a_test';
        $actual   = Tag::friendlyTitle(
            $options,
            '_',
            true,
            ['i', 'h']
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: friendlyTitle() - special characters and escaping
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleWithSpecialCharactersAndEscaping(UnitTester $I)
    {
        $options  = "Mess'd up --text-- just (to) stress /test/ ?our! "
            . "`little` \\clean\\ url fun.ction!?-->";
        $expected = 'messd-up-text-just-to-stress-test-our-little-'
            . 'clean-url-function';
        $actual   = Tag::friendlyTitle($options);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: friendlyTitle() - accented characters and replace
     * string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleWithAccentedCharactersAndReplaceString(UnitTester $I)
    {
        $options  = "Perché l'erba è verde?";
        $expected = 'perche-l-erba-e-verde';
        $actual   = Tag::friendlyTitle($options, "-", true, "'");

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: friendlyTitle() - accented characters and replace
     * array
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleWithAccentedCharactersAndReplaceArray(UnitTester $I)
    {
        $options  = "Perché l'erba è verde?";
        $expected = 'P_rch_l_rb_v_rd';
        $actual   = Tag::friendlyTitle(
            $options,
            "_",
            false,
            ['e', 'a']
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: friendlyTitle() - string as a parameter with
     * replace as boolean
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function testFriendlyTitleStringParameterReplaceBoolean(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception('Parameter replace must be an array or a string'),
            function () {
                Tag::resetInput();
                $options  = 'This is a Test';
                $expected = 't_s_s_a_test';
                $actual   = Tag::friendlyTitle($options, '_', true, true);
            }
        );
    }
}
