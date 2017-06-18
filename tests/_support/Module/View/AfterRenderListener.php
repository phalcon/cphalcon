<?php

namespace Phalcon\Test\Module\View;

use Phalcon\Mvc\View;
use Phalcon\Events\Event;

/**
 * \Phalcon\Test\Module\View\AfterRenderListener
 * The View afterRenderView listener
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Module\View
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class AfterRenderListener
{
    protected $levels = [];

    public function afterRenderView(Event $event, View $view)
    {
        if ('afterRenderView' == $event->getType()) {
            $this->levels[] = $view->getCurrentRenderLevel();
        }

        return true;
    }

    public function reset()
    {
        $this->levels = [];
    }

    public function getLevels()
    {
        return join(',', $this->levels);
    }
}
