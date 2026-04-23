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

namespace Phalcon\Tests\Unit\Html\Helper\Breadcrumbs;

use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class RenderTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testHtmlHelperBreadcrumbsRender(): void
    {
        $escaper     = new Escaper();
        $helper      = new TagFactory($escaper);
        $breadcrumbs = $helper->breadcrumbs();

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
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testHtmlHelperBreadcrumbsRenderWithSameHref(): void
    {
        $escaper     = new Escaper();
        $helper      = new TagFactory($escaper);
        $breadcrumbs = $helper->breadcrumbs();

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
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testHtmlHelperBreadcrumbsRenderEmpty(): void
    {
        $escaper     = new Escaper();
        $helper      = new TagFactory($escaper);
        $breadcrumbs = $helper->breadcrumbs();

        $expected = '';
        $actual   = $breadcrumbs->render();
        $this->assertSame($expected, $actual);
    }
}
