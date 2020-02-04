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

namespace Phalcon\Test\Fixtures\Db;

class ProfilerListener
{
    protected $profiler;

    public function __construct()
    {
        $this->profiler = new Profiler();
    }

    public function beforeQuery($event, $connection)
    {
        $this->profiler->startProfile(
            $connection->getSQLStatement(),
            $connection->getSQLVariables(),
            $connection->getSQLBindTypes()
        );
    }

    public function afterQuery($event, $connection)
    {
        $this->profiler->stopProfile();
    }

    public function getProfiler()
    {
        return $this->profiler;
    }
}
