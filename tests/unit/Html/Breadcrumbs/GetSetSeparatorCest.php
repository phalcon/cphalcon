<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Breadcrumbs;

use Phalcon\Html\Breadcrumbs;
use UnitTester;

/**
 * Class GetSetSeparatorCest
 *
 * @package Phalcon\Tests\Unit\Html\Breadcrumbs
 */
class GetSetSeparatorCest
{
    /**
     * Tests Phalcon\Html\Breadcrumbs :: getSeparator()/setSeparator()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function htmlBreadcrumbsGetSetSeparator(UnitTester $I)
    {
        $I->wantToTest('Html\Breadcrumbs - getSeparator()/setSeparator()');

        $breadcrumbs = new Breadcrumbs();

        $expected = ' -:- ';

        $breadcrumbs->setSeparator($expected);

        $I->assertEquals(
            $expected,
            $breadcrumbs->getSeparator()
        );
    }
}
