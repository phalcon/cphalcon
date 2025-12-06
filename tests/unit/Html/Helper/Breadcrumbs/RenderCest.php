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
 * Class RenderCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Breadcrumbs
 */
class RenderCest
{
    /**
     * Tests Phalcon\Html\Helper\Breadcrumbs :: render()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-03-29
     */
    public function htmlHelperBreadcrumbsRender(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Breadcrumbs - render()');
        $escaper     = new Escaper();
        $breadcrumbs = new Breadcrumbs($escaper);

        $breadcrumbs
            ->setAttributes(
                [
                    'class' => 'breadcrumb',
                ]
            )
            ->add('Home', '/')
            ->add(
                'Invoices',
                '/invoices',
                '<i class="fa-solid fa-file-invoice"></i> '
            )
            ->add(
                'Customers',
                '/customers',
                '<i class="fa-solid fa-user"></i> ',
                [
                    'class'      => 'breadcrumb-item',
                    'aria-label' => 'breadcrumb',
                ]
            )
            ->add(
                'List',
                '/customers/list',
                '',
                [
                    'aria-current' => 'page',
                ]
            )
        ;

        $expected = "
<nav class=\"breadcrumb\">
    <ol>
    <li><a href=\"/\">Home</a></li>
    <li>/</li>
    <li><a href=\"/invoices\">" .
            "<i class=\"fa-solid fa-file-invoice\"></i> Invoices</a></li>
    <li>/</li>
    <li class=\"breadcrumb-item\" aria-label=\"breadcrumb\">" .
            "<a href=\"/customers\"><i class=\"fa-solid fa-user\"></i> Customers</a></li>
    <li>/</li>
    <li><span aria-current=\"page\">List</span></li>

    </ol>
</nav>";
        $actual   = $breadcrumbs->render();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Helper\Breadcrumbs :: render() with same href
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-03-29
     */
    public function htmlHelperBreadcrumbsRenderWithSameHref(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Breadcrumbs - render() with same href');
        $escaper     = new Escaper();
        $breadcrumbs = new Breadcrumbs($escaper);

        $breadcrumbs
            ->setAttributes(
                [
                    'class' => 'breadcrumb',
                ]
            )
            ->add('Home', '#')
            ->add('Invoices', '#')
            ->add('Customers', '#')
            ->add('List')
        ;

        $expected = "
<nav class=\"breadcrumb\">
    <ol>
    <li><a href=\"#\">Home</a></li>
    <li>/</li>
    <li><a href=\"#\">Invoices</a></li>
    <li>/</li>
    <li><a href=\"#\">Customers</a></li>
    <li>/</li>
    <li><span>List</span></li>

    </ol>
</nav>";
        $actual   = $breadcrumbs->render();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Helper\Breadcrumbs :: render() empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-03-29
     */
    public function htmlHelperBreadcrumbsRenderEmpty(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Breadcrumbs - render() with same href');
        $escaper     = new Escaper();
        $breadcrumbs = new Breadcrumbs($escaper);

        $expected = '';
        $actual   = $breadcrumbs->render();
        $I->assertSame($expected, $actual);
    }
}
