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

namespace Phalcon\Test\Unit\Assets\Filters\None;

use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class FilterCest
 *
 * @package Phalcon\Test\Unit\Assets\Filters\None
 */
class FilterCest
{
    use DiTrait;

    /**
     * @param UnitTester $I
     */
    public function _before(UnitTester $I)
    {
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
     * @since  2018-11-13
     */
    public function assetsFiltersNoneFilter(UnitTester $I)
    {
        $I->wantToTest("Assets\Filters\None - filter()");
        $cssmin   = new None();
        $expected = ' ';
        $actual   = $cssmin->filter(' ');
        $I->assertEquals($expected, $actual);
    }
}
