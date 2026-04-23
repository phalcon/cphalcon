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

use Phalcon\Events\Manager as EventsManager;
use Phalcon\Mvc\View\Simple;
use Phalcon\Tests\AbstractUnitTestCase;

use function ob_end_clean;
use function ob_start;
use function supportDir;

class GetActiveRenderPathTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewSimpleGetActiveRenderPath(): void
    {
        $view = new Simple();
        $view->setViewsDir(supportDir('assets/views/'));
        $view->setEventsManager(new EventsManager());

        ob_start();
        $view->render('activerender/index');
        ob_end_clean();

        $this->assertSame('activerender/index', $view->getActiveRenderPath());
    }
}
