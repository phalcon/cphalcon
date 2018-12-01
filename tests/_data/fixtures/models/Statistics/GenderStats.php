<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Statistics;

use Phalcon\Mvc\Model;

class GenderStats extends Model
{
    public function getSource(): string
    {
        return 'stats';
    }

    public function getResultsetClass()
    {
        return 'Not\Existing\Resultset\Class';
    }
}
