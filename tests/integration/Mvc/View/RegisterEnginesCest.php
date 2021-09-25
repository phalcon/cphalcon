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

namespace Phalcon\Tests\Integration\Mvc\View;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class RegisterEnginesCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiService('view');
    }

    /**
     * Tests the View::registerEngines
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function mvcViewRegisterEngines(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - registerEngines()');

        $engines = $this->getViewRegisterEngines();

        $view = $this->getService('view');

        $view->registerEngines($engines);

        $I->assertEquals(
            $engines,
            $view->getRegisteredEngines()
        );
    }

    private function getViewRegisterEngines(): array
    {
        return [
            '.mhtml' => MustacheEngine::class,
            '.phtml' => PhpEngine::class,
            '.twig'  => TwigEngine::class,
            '.volt'  => VoltEngine::class,
        ];
    }
}
