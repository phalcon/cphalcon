<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Db;

use Phalcon\Db\Profiler as PhalconProfiler;

class Profiler extends PhalconProfiler
{

    private $points = 0;

    public function beforeStartProfile($profile)
    {
        $this->points++;
    }

    public function afterEndProfile($profile)
    {
        $this->points--;
    }

    public function getPoints()
    {
        return $this->points;
    }
}
