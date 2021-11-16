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

namespace Phalcon\Tests\Fixtures\Tasks;

use Phalcon\Cli\Task;

class Issue787Task extends Task
{
    public static $output = '';

    public function beforeExecuteRoute()
    {
        $this->dispatcher;
        $this->dispatcher;

        self::$output .= 'beforeExecuteRoute' . PHP_EOL;

        return true;
    }

    public function initialize()
    {
        self::$output .= 'initialize' . PHP_EOL;
    }

    public function mainAction()
    {
    }
}
