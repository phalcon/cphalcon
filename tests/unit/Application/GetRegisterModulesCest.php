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

use Phalcon\Application\Exception;
use Phalcon\Tests\Fixtures\Application\ApplicationFixture;
use UnitTester;

/**
 * Class GetRegisterModulesCest
 *
 * @package Phalcon\Tests\Unit\Application
 */
class GetRegisterModulesCest
{
    /**
     * Tests Phalcon\Application\* :: registerModules()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function applicationRegisterModules(UnitTester $I)
    {
        $I->wantToTest('Application - registerModules');

        $application = new ApplicationFixture();

        $modules = [
            'admin'    => [1],
            'invoices' => [2],
        ];
        $application->registerModules($modules);

        $expected = $modules;
        $actual   = $application->getModules();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Acl\Role :: registerModules() - merge
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function applicationRegisterModulesMerge(UnitTester $I)
    {
        $I->wantToTest('Application - registerModules - merge');

        $application = new ApplicationFixture();

        $modules1 = [
            'admin'    => [1],
            'invoices' => [2],
        ];
        $application->registerModules($modules1);

        $modules2 = [
            'moderator' => [3],
            'posts'     => [4],
        ];
        $application->registerModules($modules2);

        $expected = $modules2;
        $actual   = $application->getModules();
        $I->assertEquals($expected, $actual);

        $application->registerModules($modules1, true);

        $expected = array_merge($modules2, $modules1);
        $actual   = $application->getModules();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Acl\Role :: getModule()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function applicationGetModule(UnitTester $I)
    {
        $I->wantToTest('Application - getModule');

        $application = new ApplicationFixture();

        $modules = [
            'admin'    => [1],
            'invoices' => [2],
        ];
        $application->registerModules($modules);

        $expected = [1];
        $actual   = $application->getModule('admin');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Acl\Role :: getModule() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function applicationGetModuleException(UnitTester $I)
    {
        $I->wantToTest('Application - getModule - exception');

        $I->expectThrowable(
            new Exception(
                "Module 'no-module' is not registered in the application container"
            ),
            function () {
                $application = new ApplicationFixture();

                $module = $application->getModule('no-module');
            }
        );
    }
}
