<?php

namespace Helper;

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
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
trait ViewTrait
{
    protected $level;

    /**
     * executed before each test
     */
    protected function _before()
    {
        $this->level = ob_get_level();
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
}
