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

namespace Phalcon\Test\Unit\Html\Breadcrumbs;

use Phalcon\Html\Breadcrumbs;
use UnitTester;

class AddCest
{
    /**
     * Tests Phalcon\Html\Breadcrumbs :: add()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function htmlBreadcrumbsAdd(UnitTester $I)
    {
        $I->wantToTest('Html\Breadcrumbs - add()');

        $breadcrumbs = new Breadcrumbs();

        $breadcrumbs->add('Home', '/');

        $I->assertEquals(
            [
                '/' => 'Home',
            ],
            $breadcrumbs->toArray()
        );
    }
}
