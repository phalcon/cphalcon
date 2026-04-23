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

namespace Phalcon\Tests\Unit\Mvc\View\Simple;

use Phalcon\Mvc\View\Simple;
use Phalcon\Tests\AbstractUnitTestCase;

use function dataDir;

use const DIRECTORY_SEPARATOR;

class GetSetViewsDirTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewSimpleGetSetViewsDir(): void
    {
        $view = new Simple();

        $view->setViewsDir(
            dataDir('views' . DIRECTORY_SEPARATOR)
        );

        $this->assertEquals(
            dataDir('views' . DIRECTORY_SEPARATOR),
            $view->getViewsDir()
        );
    }
}
