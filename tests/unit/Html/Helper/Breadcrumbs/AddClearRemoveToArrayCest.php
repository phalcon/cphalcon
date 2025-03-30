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
 * Class AddClearRemoveToArrayCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Breadcrumbs
 */
class AddClearRemoveToArrayCest
{
    /**
     * Tests Phalcon\Html\Helper\Breadcrumbs :: add()/clear()/remove()/toArray()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-03-29
     */
    public function htmlHelperBreadcrumbsAddClearRemoveToArray(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Breadcrumbs - add()/clear()/remove()/toArray()');
        $escaper     = new Escaper();
        $breadcrumbs = new Breadcrumbs($escaper);

        /**
         * add()/toArray()
         */
        $breadcrumbs->add('Home', '/');

        $expected = [
            1 => [
                'attributes' => [],
                'icon'       => '',
                'link'       => '/',
                'text'       => 'Home',
            ],
        ];
        $actual   = $breadcrumbs->toArray();
        $I->assertSame($expected, $actual);

        $breadcrumbs->add(
            'Invoices',
            '/invoices',
            '<i class="fa-solid fa-file-invoice"></i>'
        );

        $expected = [
            1 => [
                'attributes' => [],
                'icon'       => '',
                'link'       => '/',
                'text'       => 'Home',
            ],
            2 => [
                'attributes' => [],
                'icon'       => '<i class="fa-solid fa-file-invoice"></i>',
                'link'       => '/invoices',
                'text'       => 'Invoices',
            ],
        ];
        $actual   = $breadcrumbs->toArray();
        $I->assertSame($expected, $actual);

        $breadcrumbs->add(
            'Customers',
            '/customers',
            '<i class="fa-solid fa-user"></i>',
            [
                'class'      => 'breadcrumb-item',
                'aria-label' => 'breadcrumb',
            ]
        );

        $expected = [
            1 => [
                'attributes' => [],
                'icon'       => '',
                'link'       => '/',
                'text'       => 'Home',
            ],
            2 => [
                'attributes' => [],
                'icon'       => '<i class="fa-solid fa-file-invoice"></i>',
                'link'       => '/invoices',
                'text'       => 'Invoices',
            ],
            3 => [
                'attributes' => [
                    'class'      => 'breadcrumb-item',
                    'aria-label' => 'breadcrumb',
                ],
                'icon'       => '<i class="fa-solid fa-user"></i>',
                'link'       => '/customers',
                'text'       => 'Customers',
            ],
        ];
        $actual   = $breadcrumbs->toArray();
        $I->assertSame($expected, $actual);

        /**
         * remove()
         */
        $breadcrumbs->remove(2);
        $expected = [
            1 => [
                'attributes' => [],
                'icon'       => '',
                'link'       => '/',
                'text'       => 'Home',
            ],
            3 => [
                'attributes' => [
                    'class'      => 'breadcrumb-item',
                    'aria-label' => 'breadcrumb',
                ],
                'icon'       => '<i class="fa-solid fa-user"></i>',
                'link'       => '/customers',
                'text'       => 'Customers',
            ],
        ];
        $actual   = $breadcrumbs->toArray();
        $I->assertSame($expected, $actual);

        /**
         * clear()
         */
        $breadcrumbs->clear();

        $expected = [];
        $actual   = $breadcrumbs->toArray();
        $I->assertSame($expected, $actual);
    }
}