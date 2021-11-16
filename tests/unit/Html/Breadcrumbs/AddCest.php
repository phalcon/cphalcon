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
 * Class AddCest
 *
 * @package Phalcon\Tests\Unit\Html\Breadcrumbs
 */
class AddCest
{
    /**
     * Tests Phalcon\Html\Breadcrumbs :: add()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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
