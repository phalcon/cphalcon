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

namespace Phalcon\Tests\Unit\Application;

use Phalcon\Di\FactoryDefault;
use Phalcon\Tests\Fixtures\Application\ApplicationFixture;
use UnitTester;

use function spl_object_hash;

/**
 * Class GetSetDICest
 *
 * @package Phalcon\Tests\Unit\Application
 */
class GetSetDICest
{
    /**
     * Tests Phalcon\Application\* :: getDI()/setDI() - construct
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function applicationGetSetDiConstruct(UnitTester $I)
    {
        $I->wantToTest('Application - getDI()/setDI() - construct');

        $container   = new FactoryDefault();
        $application = new ApplicationFixture($container);

        $actual = $application->getDI();
        $I->assertEquals(spl_object_hash($container), spl_object_hash($actual));
    }

    /**
     * Tests Phalcon\Acl\Role :: getDI()/setDI()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function applicationGetSetDi(UnitTester $I)
    {
        $I->wantToTest('Application - getDI()/setDI() - construct');

        $container   = new FactoryDefault();
        $application = new ApplicationFixture();

        $application->setDI($container);
        $actual = $application->getDI();
        $I->assertEquals(spl_object_hash($container), spl_object_hash($actual));
    }
}
