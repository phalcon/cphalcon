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

use Phalcon\Html\Tag;
use UnitTester;

/**
 * Class ConstantsCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class ConstantsCest
{
    /**
     * Tests Phalcon\Html\Tag :: constants
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagConstants(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - constants()');
        $I->assertEquals(1, Tag::HTML32);
        $I->assertEquals(2, Tag::HTML401_STRICT);
        $I->assertEquals(3, Tag::HTML401_TRANSITIONAL);
        $I->assertEquals(4, Tag::HTML401_FRAMESET);
        $I->assertEquals(5, Tag::HTML5);
        $I->assertEquals(6, Tag::XHTML10_STRICT);
        $I->assertEquals(7, Tag::XHTML10_TRANSITIONAL);
        $I->assertEquals(8, Tag::XHTML10_FRAMESET);
        $I->assertEquals(9, Tag::XHTML11);
        $I->assertEquals(10, Tag::XHTML20);
        $I->assertEquals(11, Tag::XHTML5);
    }
}
