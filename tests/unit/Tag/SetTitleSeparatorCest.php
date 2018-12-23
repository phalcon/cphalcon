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
use UnitTester;

/**
 * Class SetTitleSeparatorCest
 */
class SetTitleSeparatorCest
{
    /**
     * Tests Phalcon\Tag :: setTitleSeparator()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     * @since  2018-11-13
     */
    public function tagSetTitleSeparator(UnitTester $I)
    {
        $I->wantToTest("Tag - setTitleSeparator()");
        Tag::resetInput();
        Tag::setTitleSeparator('-');

        $expected = "-";
        $actual   = Tag::getTitleSeparator();
        $I->assertEquals($expected, $actual);
    }
}
