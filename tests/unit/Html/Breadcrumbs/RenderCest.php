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

class RenderCest
{
    /**
     * Tests Phalcon\Html\Breadcrumbs :: render()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function htmlBreadcrumbsRender(UnitTester $I)
    {
        $I->wantToTest('Html\Breadcrumbs - render()');

        $breadcrumbs = new Breadcrumbs();

        $breadcrumbs
            ->add('Home', '/')
            ->add('Phalcon Team')
        ;

        $expected = '<dl>'
            . '<dt><a href="/">Home</a></dt>'
            . '<dt> / </dt>'
            . '<dt>Phalcon Team</dt>'
            . '</dl>';

        $I->assertEquals(
            $expected,
            $breadcrumbs->render()
        );
    }
}
