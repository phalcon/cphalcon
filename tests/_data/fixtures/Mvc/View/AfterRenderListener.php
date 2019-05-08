<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Mvc\View;

use Phalcon\Mvc\View;
use Phalcon\Events\Event;

/**
 * The View afterRenderView listener
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
