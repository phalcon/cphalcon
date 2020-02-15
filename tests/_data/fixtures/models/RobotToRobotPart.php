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
 * Class RobotToRobotPart
 *
 * @property int    $robot_id;
 * @property string $robot_part_id;
 */
class RobotToRobotPart extends Model
{
    public $robot_id;
    public $robot_part_id;

    public function initialize()
    {
        $this->setSchema('app');
        $this->setSource('robot_to_robot_part');
    }
}
