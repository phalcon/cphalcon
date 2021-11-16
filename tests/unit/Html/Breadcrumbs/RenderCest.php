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
 * Class RenderCest
 *
 * @package Phalcon\Tests\Unit\Html\Breadcrumbs
 */
class RenderCest
{
    /**
     * Tests Phalcon\Html\Breadcrumbs :: render()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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

    /**
     * Tests Phalcon\Html\Breadcrumbs :: render()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function htmlBreadcrumbsRenderHome(UnitTester $I)
    {
        $I->wantToTest('Html\Breadcrumbs - render() - home');

        $breadcrumbs = new Breadcrumbs();

        $breadcrumbs
            ->add('Home', '/')
        ;

        $expected = '<dl>'
            . '<dt><a href="/">Home</a></dt>'
            . '</dl>';

        $I->assertEquals(
            $expected,
            $breadcrumbs->render()
        );
    }
}
