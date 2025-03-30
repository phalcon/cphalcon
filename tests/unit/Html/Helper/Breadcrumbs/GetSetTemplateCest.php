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
 * Class GetSetTemplateCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Breadcrumbs
 */
class GetSetTemplateCest
{
    /**
     * Tests Phalcon\Html\Helper\Breadcrumbs :: getTemplate()/setTemplate()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-03-29
     */
    public function htmlHelperBreadcrumbsGetSetTemplate(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Breadcrumbs - getTemplate()/setTemplate()');
        $escaper     = new Escaper();
        $breadcrumbs = new Breadcrumbs($escaper);

        $expected = [
            'main' => "
<nav%attributes%>
    <ol>
%items%
    </ol>
</nav>",
            'line' => '<li%attributes%><a href="%link%">%icon%%text%</a></li>',
            'last' => '<li><span%attributes%>%text%</span></li>',
        ];
        $actual   = $breadcrumbs->getTemplate();
        $I->assertSame($expected, $actual);

        $main = '<nav><ol>%items%</ol></nav>';
        $line = '<li><a href="%link%">%text%</a></li>';
        $last = '<li>%text%</li>';
        $breadcrumbs->setTemplate($main, $line, $last);

        $expected = [
            'main' => $main,
            'line' => $line,
            'last' => $last,
        ];
        $actual   = $breadcrumbs->getTemplate();
        $I->assertSame($expected, $actual);
    }
}
