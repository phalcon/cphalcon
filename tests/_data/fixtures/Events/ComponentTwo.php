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

namespace Phalcon\Tests\Fixtures\Events;

use Phalcon\Events\AbstractEventsAware;

class ComponentTwo extends AbstractEventsAware
{
    public function doAction()
    {
        $this->eventsManager->fire('another:beforeAction', $this);
        $this->eventsManager->fire('another:afterAction', $this);
    }
}
