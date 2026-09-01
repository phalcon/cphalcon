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

namespace Phalcon\Tests\Unit\Mvc\View;

use Phalcon\Mvc\View;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Unit\Mvc\Fake\ViewTrait;

class GetSetPartialsDirTest extends AbstractUnitTestCase
{
    use ViewTrait;

    /**
     * Tests Phalcon\Mvc\View :: getPartialsDir() / setPartialsDir()
     */
    public function testMvcViewGetSetPartialsDir(): void
    {
        $view = new View();

        $view->setBasePath(
            Talon::settings()->dataPath() . '/'
        );

        $view->setPartialsDir('views/partials/');

        $this->assertEquals(
            'views/partials/',
            $view->getPartialsDir()
        );
    }
}
