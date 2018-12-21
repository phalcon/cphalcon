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

namespace Phalcon\Test\Unit\Html\Tag;

use Phalcon\Html\Exception;
use Phalcon\Html\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\TagSetupTrait;
use UnitTester;

/**
 * Class FriendlyTitleCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class FriendlyTitleCest
{
    use DiTrait;
    use TagSetupTrait;

    /**
     * Tests Phalcon\Html\Tag :: friendlyTitle()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function htmlTagFriendlyTitle(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - friendlyTitle()');
        $tag = new Tag();

        $text     = 'This is a Test';
        $expected = 'this-is-a-test';
        $actual   = $tag->friendlyTitle($text);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: friendlyTitle() - separator
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function htmlTagFriendlyTitleSeparator(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - friendlyTitle() - separator');
        $tag = new Tag();

        $text     = 'This is a Test';
        $options  = [
            'separator' => '_',
        ];
        $expected = 'this_is_a_test';
        $actual   = $tag->friendlyTitle($text, $options);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: friendlyTitle() - lowercase
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function htmlTagFriendlyTitleLowercase(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - friendlyTitle() - lowercase');
        $tag = new Tag();

        $text     = 'This is a Test';
        $options  = [
            'lowercase' => false,
        ];
        $expected = 'This-is-a-Test';
        $actual   = $tag->friendlyTitle($text, $options);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: friendlyTitle() - replace string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function htmlTagFriendlyTitleReplaceString(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - friendlyTitle() - replace string');
        $tag = new Tag();

        $text     = 'This is a Test';
        $options  = [
            'replace' => 'i',
        ];
        $expected = 'ths-s-a-test';
        $actual   = $tag->friendlyTitle($text, $options);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: friendlyTitle() - replace array
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function htmlTagFriendlyTitleReplaceArray(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - friendlyTitle() - replace array');
        $tag = new Tag();

        $text     = 'This is a Test';
        $options  = [
            'replace' => ['i', 'h'],
        ];
        $expected = 't-s-s-a-test';
        $actual   = $tag->friendlyTitle($text, $options);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: friendlyTitle() - special characters and
     * escaping
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function htmlTagFriendlyTitleSpecialCharacters(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - friendlyTitle() - special characters and escaping');
        $tag = new Tag();

        $text     = "Mess'd up --text-- just (to) stress /test/ ?our! "
            . "`little` \\clean\\ url fun.ction!?-->";
        $expected = 'messd-up-text-just-to-stress-test-our-little-'
            . 'clean-url-function';
        $actual   = $tag->friendlyTitle($text);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: friendlyTitle() - accented characters replace
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function htmlTagFriendlyTitleAccentedCharactersReplace(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - friendlyTitle() - accented characters replace');
        $tag = new Tag();

        $text     = "Perché l'erba è verde?";
        $expected = 'perche-lerba-e-verde';
        $options  = [
            'replace' => "'",
        ];
        $actual   = $tag->friendlyTitle($text, $options);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: friendlyTitle() - accented characters replace
     * array
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function htmlTagFriendlyTitleAccentedCharactersReplaceArray(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - friendlyTitle() - accented characters replace array');
        $tag = new Tag();

        $text     = "Perché l'erba è verde?";
        $expected = 'p-rch-l-rb-v-rd';
        $options  = [
            'replace' => ['e', 'a'],
        ];
        $actual   = $tag->friendlyTitle($text, $options);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: friendlyTitle() - replace exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-11
     */
    public function htmlTagFriendlyTitleReplaceException(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - friendlyTitle() - replace exception');
        $I->expectThrowable(
            new Exception('Parameter replace must be an array or a string'),
            function () {
                $tag     = new Tag();
                $options = ['replace' => true];
                $tag->friendlyTitle('test', $options);
            }
        );
    }
}
