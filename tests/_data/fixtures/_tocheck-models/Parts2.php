<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Models;

use Phalcon\Events\Manager;
use Phalcon\Mvc\Model;

class Parts2 extends Model
{
    public function initialize()
    {
        $eventsManager = new Manager();

        $eventsManager->attach(
            'model',
            function ($event, $robot) {
                return true;
            }
        );

        $this->setEventsManager($eventsManager);

        $this->setSource('parts');
    }
}
