<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Statistics;

use Phalcon\Mvc\Model;

class CityStats extends Model
{
    public function initialize()
    {
        $this->setSource('stats');
    }
}
