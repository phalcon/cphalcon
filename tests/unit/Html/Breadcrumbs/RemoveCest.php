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
 * Class RemoveCest
 */
class RemoveCest
{
    /**
     * Tests Phalcon\Html\Breadcrumbs :: remove()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlBreadcrumbsRemove(UnitTester $I)
    {
        $I->wantToTest('Html\Breadcrumbs - remove()');
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
        $actual   = $breadcrumbs->toArray();
        $I->assertEquals($expected, $actual);

        $breadcrumbs->remove('/');
        $expected = [
            '/users' => 'Users',
            ''       => 'Phalcon Team',
        ];
        $actual   = $breadcrumbs->toArray();
        $I->assertEquals($expected, $actual);
    }
}
