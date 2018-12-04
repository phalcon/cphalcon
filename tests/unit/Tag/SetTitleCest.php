<?php

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
use UnitTester;

class SetTitleCest
{
    /**
     * Tests Phalcon\Tag :: setTitle()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testSetTitle(UnitTester $I)
    {
        $I->wantToTest("Tag - setTitle()");
        Tag::resetInput();
        $value = 'This is my title';
        Tag::setTitle($value);

        $expected = "<title>{$value}</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);

        $expected = "{$value}";
        $actual   = Tag::getTitle();
        $I->assertEquals($expected, $actual);
    }
}
