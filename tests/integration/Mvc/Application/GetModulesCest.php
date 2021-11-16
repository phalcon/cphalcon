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

namespace Phalcon\Tests\Integration\Mvc\Application;

use IntegrationTester;
use Phalcon\Mvc\Application;
use Phalcon\Tests\Modules\Frontend\Module;

class GetModulesCest
{
    /**
     * Tests Phalcon\Mvc\Application :: getModules() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function mvcApplicationGetModulesEmpty(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Application - getModules() - empty");

        $application = new Application();

        $I->assertEquals(
            [],
            $application->getModules()
        );
    }

    /**
     * Tests Phalcon\Mvc\Application :: getModules()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function mvcApplicationGetModules(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Application - getModules()");

        $application = new Application();

        $definition = [
            'frontend' => [
                'className' => Module::class,
                'path'      => dataDir('fixtures/modules/frontend/Module.php'),
            ],
            'backend'  => [
                'className' => \Phalcon\Tests\Modules\Backend\Module::class,
                'path'      => dataDir('fixtures/modules/backend/Module.php'),
            ],
        ];

        $application->registerModules($definition);

        $I->assertEquals(
            $definition,
            $application->getModules()
        );
    }
}
