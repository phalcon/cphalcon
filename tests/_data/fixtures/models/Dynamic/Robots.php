<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Dynamic;

use Phalcon\Mvc\Model as PhalconModel;
use Phalcon\Test\Models\RobotsParts;

/**
 * @property int    $id
 * @property string $name
 * @property string $type
 * @property int    $year
 * @property string $datetime
 * @property string $deleted
 * @property string $text
 *
 * @method static Robots findFirst($parameters = null)
 * @method static Robots[] find($parameters = null)
 */
class Robots extends PhalconModel
{
    public $year;

    public function initialize()
    {
        $this->hasMany(
            'id',
            RobotsParts::class,
            'robots_id'
        );

        $this->useDynamicUpdate(true);
    }
}
