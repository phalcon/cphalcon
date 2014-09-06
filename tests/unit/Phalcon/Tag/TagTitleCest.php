<?php
/**
 * TagTitleCest.php
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

require_once ROOT_PATH . '/unit/Phalcon/Tag/TagBase.php';

use \CodeGuy;
use \Phalcon\Tag as PhTag;

class TagTitleCest extends TagBase
{

    /**
     * Tests setTitle
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     *
     * @param CodeGuy $I
     */
    public function testSetTitle(CodeGuy $I)
    {
        $value = 'This is my title';

        PhTag::setTitle($value);

        $expected = "<title>{$value}</title>" . PHP_EOL;
        $actual   = PhTag::getTitle();

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'setTitle')
        );
    }

    /**
     * Tests appendTitle
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     *
     * @param CodeGuy $I
     */
    public function testAppendTitle(CodeGuy $I)
    {
        $value = 'This is my title';

        PhTag::setTitle($value);

        $append = ' - Welcome!';

        PhTag::appendTitle($append);

        $expected = "<title>{$value}{$append}</title>" . PHP_EOL;
        $actual   = PhTag::getTitle();

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'appendTitle')
        );
    }

    /**
     * Tests prependTitle
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     *
     * @param CodeGuy $I
     */
    public function testPrependTitle(CodeGuy $I)
    {
        $value = 'This is my title';

        PhTag::setTitle($value);

        $prepend = 'PhalconPHP -';

        PhTag::prependTitle($prepend);

        $expected = "<title>{$prepend}{$value}</title>" . PHP_EOL;
        $actual   = PhTag::getTitle();

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'prependTitle')
        );
    }

    /**
     * Tests titleSeparator
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     *
     * @param CodeGuy $I
     */
    public function testSetTitleSeparator(CodeGuy $I)
    {
        PhTag::setTitleSeparator('-');

        $expected = "-";
        $actual   = PhTag::getTitleSeparator();

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'titleSeparator')
        );
    }

    /**
     * Tests titleSeparator with append
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     *
     * @param CodeGuy $I
     */
    public function testSetTitleSeparatorAppend(CodeGuy $I)
    {

        $value = 'This is my title';
        $addon = 'PhalconPHP';

        PhTag::setTitle($value);
        PhTag::setTitleSeparator('-');
        PhTag::appendTitle($addon);

        $expected = "<title>{$value}-{$addon}</title>" . PHP_EOL;
        $actual   = PhTag::getTitle();

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'titleSeparator append')
        );
    }

    /**
     * Tests titleSeparator prepend
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     *
     * @param CodeGuy $I
     */
    public function testSetTitleSeparatorPrepend(CodeGuy $I)
    {

        $value = 'This is my title';
        $addon = 'PhalconPHP';

        PhTag::setTitle($value);
        PhTag::setTitleSeparator('-');
        PhTag::prependTitle($addon);

        $expected = "<title>{$addon}-{$value}</title>" . PHP_EOL;
        $actual   = PhTag::getTitle();

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'titleSeparator prepend')
        );
    }
}
