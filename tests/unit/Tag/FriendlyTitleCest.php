<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

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
     * @author Phalcon Team <team@phalcon.io>
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
     * @author Phalcon Team <team@phalcon.io>
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
     * @author Phalcon Team <team@phalcon.io>
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
     * @author Phalcon Team <team@phalcon.io>
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
     * @author Phalcon Team <team@phalcon.io>
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
     * @author Phalcon Team <team@phalcon.io>
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-11
     */
    public function testFriendlyTitleWithSpecialCharactersAndEscaping(UnitTester $I)
    {
        $options = "Mess'd up --text-- just (to) stress /test/ ?our! "
            . '`little` \\clean\\ url fun.ction!?-->';

        $I->assertEquals(
            'messd-up-text-just-to-stress-test-our-little-clean-url-function',
            Tag::friendlyTitle($options)
        );
    }

    /**
     * Tests Phalcon\Tag :: friendlyTitle() - accented characters and replace
     * string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-11
     */
    public function testFriendlyTitleWithAccentedCharactersAndReplaceString(UnitTester $I)
    {
        $options = "Perché l'erba è verde?";

        $I->assertEquals(
            'perche-l-erba-e-verde',
            Tag::friendlyTitle(
                $options,
                '-',
                true,
                "'"
            )
        );
    }

    /**
     * Tests Phalcon\Tag :: friendlyTitle() - accented characters and replace
     * array
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-11
     */
    public function testFriendlyTitleWithAccentedCharactersAndReplaceArray(UnitTester $I)
    {
        $options = "Perché l'erba è verde?";

        $I->assertEquals(
            'P_rch_l_rb_v_rd',
            Tag::friendlyTitle(
                $options,
                '_',
                false,
                ['e', 'a']
            )
        );
    }

    /**
     * Tests Phalcon\Tag :: friendlyTitle() - string as a parameter with
     * replace as boolean
     *
     * @author Phalcon Team <team@phalcon.io>
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

                $actual = Tag::friendlyTitle($options, '_', true, true);
            }
        );
    }
}
