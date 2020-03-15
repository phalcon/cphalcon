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

namespace Phalcon\Test\Fixtures\Traits;

use DirectoryIterator;
use Phalcon\Mvc\View;
use Phalcon\Mvc\ViewBaseInterface;

trait ViewTrait
{
    protected $level;

    /**
     * @var View
     */
    protected $view;

    /**
     * executed before each test
     */
    public function _before()
    {
        $this->level = ob_get_level();
        $this->view  = new View();
    }

    /**
     * executed after each test
     */
    public function _after()
    {
        while (ob_get_level() > $this->level) {
            ob_end_flush();
        }
    }

    protected function renderPartialBuffered(ViewBaseInterface $view, $partial, $expectedParams = null)
    {
        ob_start();

        $view->partial($partial, $expectedParams);

        ob_clean();
    }

    /**
     * Set params and check expected data after render view
     *
     * @param View $view
     */
    protected function setParamAndCheckData(string $errorMessage, array $params, $view)
    {
        foreach ($params as $param) {
            $view->setParamToView(
                $param['paramToView'][0],
                $param['paramToView'][1]
            );

            $view->start();

            $view->setRenderLevel(
                $param['renderLevel']
            );

            $view->render(
                $param['render'][0],
                $param['render'][1]
            );

            $view->finish();

            $this->assertSame(
                $param['expected'],
                $view->getContent(),
                $errorMessage
            );
        }
    }

    protected function clearCache()
    {
        if (!file_exists(env('PATH_CACHE'))) {
            mkdir(
                env('PATH_CACHE')
            );
        }

        $items = new DirectoryIterator(
            env('PATH_CACHE')
        );

        foreach ($items as $item) {
            if ($item->isDir()) {
                continue;
            }

            unlink(
                $item->getPathname()
            );
        }
    }
}
