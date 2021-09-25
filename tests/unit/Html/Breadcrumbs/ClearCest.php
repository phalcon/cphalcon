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

class ClearCest
{
    /**
     * Tests Phalcon\Html\Breadcrumbs :: clear()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function htmlBreadcrumbsClear(UnitTester $I)
    {
        $I->wantToTest('Html\Breadcrumbs - clear()');

        $breadcrumbs = new Breadcrumbs();

        $breadcrumbs
            ->add('Home', '/')
            ->add('Users', '/users')
            ->add('Phalcon Team')
        ;

        $I->assertEquals(
            [
                '/'      => 'Home',
                '/users' => 'Users',
                ''       => 'Phalcon Team',
            ],
            $breadcrumbs->toArray()
        );

        $breadcrumbs->clear();

        $I->assertEquals(
            [],
            $breadcrumbs->toArray()
        );
    }
}
