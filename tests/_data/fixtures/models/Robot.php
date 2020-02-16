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

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

/**
 * Class Robot
 *
 * @property int    $robot_id;
 * @property string $robot_name;
 */
class Robot extends Model
{
    public $robot_id;
    public $robot_name;

    public function initialize()
    {
        $this->setSchema('public');
        $this->setSource('robot');

        $this->hasManyToMany(
            'robot_id',
            RobotToRobotPart::class,
            'robot_id',
            'robot_part_id',
            RobotPart::class,
            'robot_part_id'
        );
    }
}
