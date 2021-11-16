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
use Phalcon\Application\Exception;
use Phalcon\Mvc\Application;
use Phalcon\Tests\Modules\Frontend\Module;

class GetModuleCest
{
    /**
     * Tests Phalcon\Mvc\Application :: getModule()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function mvcApplicationGetModule(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Application - getModule()");

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
            $definition['frontend'],
            $application->getModule('frontend')
        );

        $I->assertEquals(
            $definition['backend'],
            $application->getModule('backend')
        );
    }

    /**
     * Tests Phalcon\Mvc\Application :: getModule() - non-existent
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function mvcApplicationGetModuleNonExistent(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Application - getModule() - non-existent");

        $application = new Application();

        $I->expectThrowable(
            new Exception(
                "Module 'foo' is not registered in the application container"
            ),
            function () use ($application) {
                $application->getModule('foo');
            }
        );
    }
}
