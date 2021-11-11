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
 * Class ToArrayCest
 *
 * @package Phalcon\Tests\Unit\Html\Breadcrumbs
 */
class ToArrayCest
{
    /**
     * Tests Phalcon\Html\Breadcrumbs :: toArray()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function htmlBreadcrumbsToArray(UnitTester $I)
    {
        $I->wantToTest('Html\Breadcrumbs - toArray()');

        $breadcrumbs = new Breadcrumbs();

        $breadcrumbs
            ->add('Home', '/')
            ->add('Users', '/users')
            ->add('Phalcon Team')
        ;

        $expected = [
            '/'      => 'Home',
            '/users' => 'Users',
            ''       => 'Phalcon Team',
        ];

        $I->assertEquals(
            $expected,
            $breadcrumbs->toArray()
        );
    }
}
