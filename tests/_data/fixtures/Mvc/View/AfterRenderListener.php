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

namespace Phalcon\Tests\Fixtures\Mvc\View;

use Phalcon\Events\Event;
use Phalcon\Mvc\View;

/**
 * The View afterRenderView listener
 */
class AfterRenderListener
{
    /**
     * @var array
     */
    protected $levels = [];

    public function afterRenderView(Event $event, View $view): bool
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

    public function getLevels(): string
    {
        return join(',', $this->levels);
    }
}
