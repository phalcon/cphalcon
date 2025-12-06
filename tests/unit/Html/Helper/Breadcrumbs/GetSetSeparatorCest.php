<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Breadcrumbs;

use Phalcon\Html\Helper\Breadcrumbs;
use Phalcon\Html\Escaper;
use UnitTester;

/**
 * Class GetSetSeparatorCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Breadcrumbs
 */
class GetSetSeparatorCest
{
    /**
     * Tests Phalcon\Html\Helper\Breadcrumbs :: getSeparator()/setSeparator()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-03-29
     */
    public function htmlHelperBreadcrumbsGetSetSeparator(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Breadcrumbs - getSeparator()/setSeparator()');
        $escaper     = new Escaper();
        $breadcrumbs = new Breadcrumbs($escaper);

        $expected = '<li>/</li>';
        $actual   = $breadcrumbs->getSeparator();
        $I->assertSame($expected, $actual);

        $separator = ' -:- ';

        $breadcrumbs->setSeparator($separator);

        $expected = $separator;
        $actual   = $breadcrumbs->getSeparator();
        $I->assertSame($expected, $actual);
    }
}
