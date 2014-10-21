<?php
/**
 * TagTitleTest.php
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

class TagTitleTest extends Helper\TagBase
{

    /**
     * Tests setTitle
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitle()
    {
        $this->specify(
            "setTitle returns incorrect result",
            function () {

                PhTTag::resetInput();
                $value = 'This is my title';

                PhTTag::setTitle($value);

                $expected = "<title>{$value}</title>" . PHP_EOL;
                $actual   = PhTTag::getTitle();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests appendTitle
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testAppendTitle()
    {
        $this->specify(
            "appendTitle returns incorrect result",
            function () {

                PhTTag::resetInput();
                $value = 'This is my title';

                PhTTag::setTitle($value);

                $append = ' - Welcome!';

                PhTTag::appendTitle($append);

                $expected = "<title>{$value}{$append}</title>" . PHP_EOL;
                $actual   = PhTTag::getTitle();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests prependTitle
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testPrependTitle()
    {
        $this->specify(
            "prependTitle returns incorrect result",
            function () {

                PhTTag::resetInput();
                $value = 'This is my title';

                PhTTag::setTitle($value);

                $prepend = 'PhalconPHP -';

                PhTTag::prependTitle($prepend);

                $expected = "<title>{$prepend}{$value}</title>" . PHP_EOL;
                $actual   = PhTTag::getTitle();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests titleSeparator
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitleSeparator()
    {
        $this->specify(
            "titleSeparator returns incorrect result",
            function () {

                PhTTag::resetInput();
                PhTTag::setTitleSeparator('-');

                $expected = "-";
                $actual   = PhTTag::getTitleSeparator();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests titleSeparator with append
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitleSeparatorAppend()
    {
        $this->specify(
            "titleSeparator with append returns incorrect result",
            function () {

                PhTTag::resetInput();
                $value = 'This is my title';
                $addon = 'PhalconPHP';

                PhTTag::setTitle($value);
                PhTTag::setTitleSeparator('-');
                PhTTag::appendTitle($addon);

                $expected = "<title>{$value}-{$addon}</title>" . PHP_EOL;
                $actual   = PhTTag::getTitle();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests titleSeparator prepend
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitleSeparatorPrepend()
    {
        $this->specify(
            "titleSeparator prepend returns incorrect result",
            function () {

                PhTTag::resetInput();
                $value = 'This is my title';
                $addon = 'PhalconPHP';

                PhTTag::setTitle($value);
                PhTTag::setTitleSeparator('-');
                PhTTag::prependTitle($addon);

                $expected = "<title>{$addon}-{$value}</title>" . PHP_EOL;
                $actual   = PhTTag::getTitle();

                expect($actual)->equals($expected);
            }
        );
    }
}
