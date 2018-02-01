<?php

namespace Helper;

use Phalcon\Mvc\View;
use DirectoryIterator;
use Phalcon\Mvc\ViewBaseInterface;

/**
 * \Helper\ViewTrait
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Helper
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
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
    protected function _before()
    {
        $this->level = ob_get_level();

        $this->view = new View;
    }

    /**
     * executed after each test
     */
    protected function _after()
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
     * @param string $errorMessage
     * @param array $params
     * @param View $view
     */
    protected function setParamAndCheckData($errorMessage, $params, $view)
    {
        foreach ($params as $param) {
            $view->setParamToView($param['paramToView'][0], $param['paramToView'][1]);

            $view->start();
            $view->setRenderLevel($param['renderLevel']);
            $view->render($param['render'][0], $param['render'][1]);
            $view->finish();

            $this->assertEquals(
                $view->getContent(),
                $param['expected'],
                $errorMessage
            );
        }
    }

    protected function clearCache()
    {
        if (!file_exists(PATH_CACHE)) {
            mkdir(PATH_CACHE);
        }

        foreach (new DirectoryIterator(PATH_CACHE) as $item) {
            if ($item->isDir()) {
                continue;
            }

            unlink($item->getPathname());
        }
    }
}
