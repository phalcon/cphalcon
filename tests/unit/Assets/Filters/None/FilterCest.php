<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Filters\None;

use Phalcon\Assets\Filters\None;
use Phalcon\Assets\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class FilterCest
{
    use DiTrait;

    public function _before(UnitTester $I)
    {
        $this->resetDi();
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiUrl();
    }

    /**
     * Tests Phalcon\Assets\Filters\None :: filter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsFilterNone(UnitTester $I)
    {
        $I->wantToTest("Assets\Filters\None - filter()");
        $cssmin   = new None();
        $expected = ' ';
        $actual   = $cssmin->filter(' ');
        $I->assertEquals($expected, $actual);
    }
}
