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
 * Class GetSetClearAttributesCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Breadcrumbs
 */
class GetSetClearAttributesCest
{
    /**
     * Tests Phalcon\Html\Helper\Breadcrumbs :: getAttributes()/clearAttributes/setAttributes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-03-29
     */
    public function htmlHelperBreadcrumbsGetSetTemplate(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Breadcrumbs - getAttributes()/clearAttributes/setAttributes()');
        $escaper     = new Escaper();
        $breadcrumbs = new Breadcrumbs($escaper);

        $expected = [];
        $actual   = $breadcrumbs->getAttributes();
        $I->assertSame($expected, $actual);

        $attributes = [
            'class' => 'breadcrumb',
            'id'    => 'main-breadcrumb',
        ];
        $breadcrumbs->setAttributes($attributes);
        $actual = $breadcrumbs->getAttributes();
        $I->assertSame($attributes, $actual);

        $breadcrumbs->clearAttributes();

        $expected = [];
        $actual   = $breadcrumbs->getAttributes();
        $I->assertSame($expected, $actual);
    }
}
