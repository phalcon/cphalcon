<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Support\Modules\Backend\Tasks;

class MainTask extends \Phalcon\Cli\Task
{
    public function throwAction()
    {
        throw new \Exception('Task Run');
    }

    public function noopAction()
    {
        return;
    }
}
