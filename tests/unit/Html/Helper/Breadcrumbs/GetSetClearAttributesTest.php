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
use Phalcon\Html\Helper\Breadcrumbs;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetClearAttributesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testHtmlHelperBreadcrumbsGetSetTemplate(): void
    {
        $escaper     = new Escaper();
        $breadcrumbs = new Breadcrumbs($escaper);

        $expected = [];
        $actual   = $breadcrumbs->getAttributes();
        $this->assertSame($expected, $actual);

        $attributes = [
            'class' => 'breadcrumb',
            'id'    => 'main-breadcrumb',
        ];
        $breadcrumbs->setAttributes($attributes);
        $actual = $breadcrumbs->getAttributes();
        $this->assertSame($attributes, $actual);

        $breadcrumbs->clearAttributes();

        $expected = [];
        $actual   = $breadcrumbs->getAttributes();
        $this->assertSame($expected, $actual);
    }
}
