<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Tasks;

class OnConstructTask extends \Phalcon\Cli\Task
{
    public $onConstructExecuted = false;

    public function onConstruct()
    {
        $this->onConstructExecuted = true;
    }
}
