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
 * Class AddCest
 */
class AddCest
{
    /**
     * Tests Phalcon\Html\Breadcrumbs :: add()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlBreadcrumbsAdd(UnitTester $I)
    {
        $I->wantToTest('Html\Breadcrumbs - add()');
        $breadcrumbs = new Breadcrumbs();
        $breadcrumbs
            ->add('Home', '/');

        $expected = [
            '/' => 'Home',
        ];
        $actual   = $breadcrumbs->toArray();
        $I->assertEquals($expected, $actual);
    }
}
