<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

class FractalDates extends Model
{
    public $id;
    public $ftime;
    public $fdatetime;
    public $ftimestamp;

    public function initialize()
    {
        $this->setSource('fractal_dates');
    }
}
