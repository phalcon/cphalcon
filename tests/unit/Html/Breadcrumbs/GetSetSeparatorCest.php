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

namespace Phalcon\Test\Unit\Html\Breadcrumbs;

use Phalcon\Html\Breadcrumbs;
use UnitTester;

/**
 * Class GetSetSeparatorCest
 */
class GetSetSeparatorCest
{
    /**
     * Tests Phalcon\Html\Breadcrumbs :: getSeparator()/setSeparator()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlBreadcrumbsGetSetSeparator(UnitTester $I)
    {
        $I->wantToTest('Html\Breadcrumbs - getSeparator()/setSeparator()');
        $breadcrumbs = new Breadcrumbs();

        $expected = ' -:- ';
        $breadcrumbs->setSeparator($expected);
        $actual = $breadcrumbs->getSeparator();
        $I->assertEquals($expected, $actual);
    }
}
