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

class GetSetViewsDirTest extends AbstractUnitTestCase
{
    use ViewTrait;

    /**
     * Tests Phalcon\Mvc\View :: getViewsDir() / setViewsDir()
     */
    public function testMvcViewGetSetViewsDir(): void
    {
        $view = new View();

        $view->setBasePath(Talon::settings()->dataPath() . '/');

        $view->setViewsDir('views/');

        $expected = 'views/';
        $actual   = $view->getViewsDir();
        $this->assertSame($expected, $actual);
    }
}
