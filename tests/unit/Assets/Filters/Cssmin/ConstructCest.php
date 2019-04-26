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

namespace Phalcon\Test\Unit\Assets\Filters\Cssmin;

use Phalcon\Assets\Filters\Cssmin;
use UnitTester;

/**
 * Class FilterCest
 *
 * @package Phalcon\Test\Unit\Assets\Filters\Cssmin
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Filters\Cssmin :: __construct() - no string
     * exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function assetsFiltersCssminConstructNonString(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Cssmin - filter() - no string exception');
        $I->skipTest('Need Phalcon implementation');
        $I->expectThrowable(
            new \TypeError(
                'Argument 1 passed to Phalcon\Assets\Filters\Cssmin::filter() ' .
                'must be of the type string, object given'
            ),
            function () {
                $jsmin = new Cssmin();
                $jsmin->filter(new \stdClass());
            }
        );
    }
}
