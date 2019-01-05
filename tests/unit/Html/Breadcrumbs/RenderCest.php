<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Html\Breadcrumbs;

use Phalcon\Html\Breadcrumbs;
use UnitTester;

/**
 * Class RenderCest
 */
class RenderCest
{
    /**
     * Tests Phalcon\Html\Breadcrumbs :: render()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
        $actual   = $breadcrumbs->render();
        $I->assertEquals($expected, $actual);
    }
}
