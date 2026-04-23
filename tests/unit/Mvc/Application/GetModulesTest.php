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

namespace Phalcon\Tests\Unit\Mvc\Application;

use Phalcon\Mvc\Application;
use Phalcon\Tests\Support\Modules\Frontend\Module;
use Phalcon\Tests\AbstractUnitTestCase;

class GetModulesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-11-13
     * @since  2018-12-26
     */
    public function testMvcApplicationGetModules(): void
    {
        $application = new Application();

        $definition = [
            'frontend' => [
                'className' => Module::class,
                'path'      => supportDir('Modules/Frontend/Module.php'),
            ],
            'backend'  => [
                'className' => \Phalcon\Tests\Support\Modules\Backend\Module::class,
                'path'      => supportDir('Modules/Backend/Module.php'),
            ],
        ];

        $application->registerModules($definition);

        $this->assertEquals(
            $definition,
            $application->getModules()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-11-13
     * @since  2018-12-26
     */
    public function testMvcApplicationGetModulesEmpty(): void
    {
        $application = new Application();

        $this->assertEquals(
            [],
            $application->getModules()
        );
    }
}
